#include <iostream>
using namespace std;
bool isEditDistanceOne(const string& a, const string& b) {
    int a_size = a.size();
    int b_size = b.size();

    if (abs(max(a_size, b_size) - min(a_size, b_size)) > 1) {
        return false;
    }
    int i = 0, j = 0, editCounter = 0;

    while (i < a_size && j < b_size) {
        if (a[i] != b[j]) {
            if (editCounter == 1) {
                return false;
            }
            editCounter++;
            if (a_size > b_size){
                i++;
            }
            else if(b_size > a_size) {
                j++;
            }
            else {
                i++;
                j++;
            }
        }
        else {
            i++;
            j++;
        }
    }

    return true;
}
int main(){
    string a,b;
    cin >> a >> b;
    cout << isEditDistanceOne(a,b) << endl;
}