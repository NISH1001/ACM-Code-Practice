#include <iostream>
#include <vector>
#include <algorithm>

// helper print for vector
template <class T>
std::ostream & operator << (std::ostream & out, const std::vector< std::vector<T> > & vec)
{
    for(auto v : vec)
    {
        for(auto x : v)
        {
            out << x << " ";
        }
        out << std::endl;
    }
    return out;
}

// Longest Common Sequence length calculator
int LCS(std::string & s1, std::string s2)
{
    int M = s1.length();
    int N = s2.length();

    // c[M,N] -> for memoization
    std::vector< std::vector<int> > c(M, std::vector<int>(N));

    // iterate from the second character
    for(int i=1; i<M; ++i)
    {
        for(int j=1; j<N; ++j)
        {
            // if current characters of
            // both strings are same
            // just incremtn the what it was before
            if( s1[i] == s2[j])
            {
                c[i][j] = c[i-1][j-1] + 1;
            }

            else
            {
                c[i][j] = std::max( c[i-1][j], c[i][j-1]);
            }
        }
    }

    // last elemtn is the LCS-1
    return c[M-1][N-1]+1;
}

int main()
{
    std::string s1("TAGCTAG");
    std::string s2("ATCATG");

    std::string s3("GGATGCTACA");
    std::string s4("TCTACCGTA");

    // lcs is lcs
    int lcs = LCS(s3,s4);
    
    // so for minimum dna sequence we remove 
    // such common sequence from total of both
    int minseq = s3.length() + s4.length() - lcs;

    std::cout << "LCS : " << lcs << std::endl;
    std::cout << "Minimum length sequence : " << minseq << std::endl;
    return 0;
}

