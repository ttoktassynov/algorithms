#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void printArray(const vector<int>& numbers) const {
        for(const auto& number: numbers) {
            cout << number << " ";
        }
        cout << endl;
    }
    void insertionSort(vector<int>& numbers) {
        for (size_t i = 1; i < numbers.size(); i++) {
            int j = i;
            while (j >= 0 && numbers[j] < numbers[j - 1]) {
                swap(numbers[j - 1], numbers[j]);
                j--;
            }
        }
    }
};
int main() {
    vector<int> numbers = {1,1,1,1,1,0};
    Solution solution;
    solution.printArray(numbers);
    solution.insertionSort(numbers);
    solution.printArray(numbers);
}