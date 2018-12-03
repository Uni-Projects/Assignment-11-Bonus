#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int i = 0 ;
bool flag = false ;

string pattern_simp (string pattern)
{
    assert(pattern.length() > 0);

    if (pattern.find("**") != -1)
       {
           pattern.replace(pattern.find("**"),2,"*");
           return pattern_simp(pattern);
       }
    if (pattern.find("*.") != -1)
       {
           pattern.replace(pattern.find("*."),2,".*");
           return pattern_simp(pattern);
       }

    return pattern;
}
bool match_pattern (string pattern, string source)
{
    if (pattern.length() == source.length())
    {
        if (i == pattern.length())
            return true;

        if ((pattern[i] == source[i]) || (pattern[i] == '.' || pattern[i] == '*'))
        {
            i++;
            return match_pattern(pattern,source);
        }
        else
            return false ;

    }
    if (pattern.length() > source.length())
    {
        if (pattern.find("*")== -1)
            return false ;
        else
        {
            pattern.erase(pattern.find("*"),1);
            return match_pattern(pattern,source);
        }
    }
    if (pattern.length() < source.length())


}

int main()
{
    string pattern = "c*.*o";
    string source = "cio";

    pattern = pattern_simp(pattern);

    if (match_pattern(pattern,source))
        cout << "yes" <<endl;
    else
        cout << "no" <<endl;

    return 0;
}
