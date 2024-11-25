#include <pthread.h>
#include <iostream>
#include <vector>
using namespace std;
struct ThreadData {
    vector<int>& arr;
    int start;
    int end;
    int sum;
};
void* calculate_sum(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    data->sum = 0;
    for (int i = data->start; i < data->end; ++i) {
        data->sum += data->arr[i];
    }
    pthread_exit(nullptr);
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];}
    int mid = n / 2;
    ThreadData data1 = {arr, 0, mid, 0};
    ThreadData data2 = {arr, mid, n, 0};
    pthread_t thread1, thread2;
    pthread_create(&thread1, nullptr, calculate_sum, static_cast<void*>(&data1));
    pthread_create(&thread2, nullptr, calculate_sum, static_cast<void*>(&data2));
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
    int total_sum = data1.sum + data2.sum;
    cout << "The sum of the numbers is: " << total_sum << endl;
    return 0;}
