#include <iostream>
#include <vector>
#include <algorithm>

bool Hatred(const std::vector< std::vector<int> > & graph, int i1, int i2)
{
    --i1; 
    for(auto elem : graph[i1])
    {
        if(elem == i2) return true;
    }
    return false;
}


template <class T>
std::ostream & operator << (std::ostream & out , const std::vector<T> & vec)
{
    for(auto a : vec)
    {
        out << a << " ";
    }
    return out;
}

int main()
{
    std::vector<std::vector<int>> graph1 = { {2,4},
                                        {1,3},
                                        {2,4},
                                        {1,3}
                                    };

    std::vector<std::vector<int>> graph2 = { {2},
                                        {1,3, 4},
                                        {2,5},
                                        {2},
                                        {3},
                                        {7,8,9},
                                        {6},
                                        {6},
                                        {6}
                                    };
    std::vector<std::vector<int>> graph3 = {
                                            {2,3,5},
                                            {1,3,4},
                                            {1,2,4,5},
                                            {2,3},
                                            {1,3}
                                        };
    std::vector<int> table1, table2;


    /*
    for(int i=0; i<graph.size(); ++i)
    {
        for(int j=0; j<graph[i].size(); ++j)
        {
            if( !Hatred(graph, i+1, j+1) )
            {
                if( i+1 != j+1)
                {
                    table1.push_back(i+1);
                    table1.push_back(j+1);
                }
            }
        }
    }
    */

    auto graph = graph3;
    int k = graph.size();
    for(int i=1; i<=k; ++i)
    {
        bool canbe = true;

        for(int j=0; j<table1.size(); ++j)
        {
            if( Hatred(graph, i, table1[j]) )
            {
                canbe = false;
                break;
            }
        }
        if (canbe)
        {
            table1.push_back(i);
        }
    }

    for(int i=1; i<=k; ++i)
    {
        auto n = std::find(table1.begin(), table1.end(), i);
        if( n == table1.end())
            table2.push_back(i);
    }

    std::cout << table1 << std::endl;
    std::cout << table2 << std::endl;
    return 0;
}







