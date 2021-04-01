#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Knapsack{
private:
    int m_capacity;
    vector<int> m_w;
    vector<int> m_v;
    vector<vector<int>> m_results;
public:
    Knapsack(int x, vector<int>& w, vector<int>& v)
        :m_capacity(x), m_w(w), m_v(v)
        {
            
        }
    
    const int GetCapacity(){
        return m_capacity;
    }
    const int GetMaxValue(vector<int>& w, vector<int>& v){
        int n = w.size();
        vector<vector<int>> res(n+1);
        for (int i = 0; i <= n; i++){
            res[i] = vector<int> (m_capacity + 1, 0);
            for (int j = 0; j <= m_capacity; j++){
                if ( i == 0 || j == 0){
                    res[i][j] = 0;
                }
                else{
                    if (w[i - 1] <= j){
                        res[i][j] = max(res[i - 1][j], res[i - 1][j - w[i - 1]] + v[i - 1]);
                    }
                    else{
                        res[i][j] = res[i - 1][j];
                    }
                }
            }
        }
        return res[n][m_capacity];
    }

    int KS(int n, int C){
        int result = 0;
        if (n == 0 || C == 0)
            return 0;
        if (m_w[n] > C)
            result =  KS(n-1, C);
        else{
            result =  max(KS(n - 1, C), m_v[n] + KS(n - 1, C - m_w[n]));
        }
        return result;
    }
};