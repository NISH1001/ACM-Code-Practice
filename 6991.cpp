#include <iostream>
#include <vector>
#include <algorithm>

int GetMinimum(const std::string & str1, const std::string & str2)
{

    std::string s1 = str1, s2=str2;
    if(s1 == s2) return s1.length();
    if(s1.length() < s2.length())
        std::swap(s1,s2);

    int i1=0,i2=0,count=0;

    char c = s2[i2];
    while(i1!=s1.length())
    {
        ++i1;
        if(s1[i1] == c)
        {
            ++i2;
            count = i1+1;
            c = s2[i2];
            std::cout << c << std::endl;
        }
    }
    return count + s2.length() - i2;
}

int main()
{
    std::string s1("TAGCTAG");
    std::string s2("ATCATG");
    //std::string s1("abcd");
    //std::string s2("cabc");

    int count = GetMinimum(s1,s2);
    std::cout << count  << std::endl;
    return 0;
}

