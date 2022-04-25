#include <iostream>
#include <vector>
using namespace std;

class Sorting{
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
    void countingSort(vector<int>& numbers) {
        int maxel = *max_element(begin(numbers), end(numbers));
        vector<int> counts(maxel + 1);
        for (const auto num: numbers) {
            counts[num]++;
        }
        for (int i = 1; i < (int) counts.size(); ++i) {
            counts[i] += counts[i - 1];
        }
        vector<int> output(numbers.size());
        for (const auto num: numbers){
            output[counts[num] - 1] = num;
            counts[num]--;
        }
        numbers = output;
    }

    void countingSort(vector<int>& numbers, int base) {
        vector<int> counts(10);
        for (auto num: numbers) {
            counts[(num / base) % 10]++;
        }
        for (int i = 1; i < (int) counts.size(); ++i) {
            counts[i] += counts[i - 1];
        }
        vector<int> output(numbers.size());
        for (int i = (int) numbers.size() - 1; i >= 0; --i){
            output[counts[(numbers[i] / base) % 10] - 1] = numbers[i];
            counts[(numbers[i] / base) % 10]--;
        }
        numbers = output;
    }

    void heapSort(vector<int>& numbers) {
        make_heap(begin(numbers), end(numbers));
        for (auto it = end(numbers); it != begin(numbers); --it) {
            pop_heap(begin(numbers), it);
        }
    }

    void quickSort(vector<int>& numbers) {
        int left = 0, right = (int) numbers.size() - 1;
        quickSort(numbers, left, right);
    }

    void quickSort(vector<int>& numbers, int left, int right) {
        if (left >=0 && left < right && right >=0) {
            int p = lomato_partition(numbers, left, right);
            quickSort(numbers, left, p - 1);
            quickSort(numbers, p + 1, right);
        }
    }
/*
nums = [4,9,2,0,3,7,8,1] -> [0,1,2,3,4,7,8,9]
i = 0
j = 7
if (nums[i]>nums[p]) {
    swap
}
while (i < j) {
    if ()
}
*/
    int hoare_partition(vector<int>& numbers, int left, int right) {
        int i = left - 1, j = right + 1; 
        int p = numbers[left + (right - left)/ 2];
        while (true) {
            do {i++;} while (numbers[i] < p);
            do {j--;} while (numbers[j] > p);
            if (j <= i) {
                return j;
            }
            swap(numbers[i], numbers[j]);
        }
        return 0;
    }

    int lomato_partition(vector<int>& numbers, int lo, int hi) {
        int i = lo - 1;
        int p = numbers[hi];
        for (int j = lo; j <= hi - 1; ++j) {
            if (numbers[j] <= p) {
                i++;
                swap(numbers[i], numbers[j]);
            }
        }
        i++;
        swap(numbers[i], numbers[hi]);
        return i;
    }
  
    void radixSort(vector<int>& numbers){
        int maxel = *max_element(begin(numbers), end(numbers));
        int base = 1;
        while (maxel > 0) {
            countingSort(numbers, base);
            base *= 10;
            maxel /= 10;
        }
    }
   
};
int main() {
    vector<int> numbers = {121, 432, 564, 23, 1, 45, 788};
    Sorting solution;
    solution.printArray(numbers);
    solution.quickSort(numbers);
    solution.printArray(numbers);
}