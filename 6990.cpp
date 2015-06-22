#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    for(int i=0; i<N; ++i)
    {
        int K;
        cin >> K; 
        vector<int> child;
        vector<int> pencil;
        cout << "child-------" << endl;
        for(int j=0; j<K; ++j)
        {
            int data;
            cin >> data;
            child.push_back(data);
        }
        cout << "pencil -------" << endl;
        for(int j=0; j<K; ++j)
        {
            int data;
            cin >> data;
            pencil.push_back(data);
        }

        std::sort(child.begin(), child.end());
        std::sort(pencil.begin(), pencil.end());

        int sum=0;
        for(int j = 0; j<K; ++j)
        {
            sum += std::abs(child[j] - pencil[j]);
        }
        cout << sum;
    }
    return 0;
}

