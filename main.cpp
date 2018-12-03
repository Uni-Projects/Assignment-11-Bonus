/*
Assignment 11 Bonus
Paolo Scattolin s1023775
Johan Urban s1024726
*/
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int i = 0 ;
bool flag = false ;

string pattern_simp (string pattern)
{
    //preconditions:
    assert(pattern.length() > 0);
    //postconditions: the function simplifies the different patterns following the assignment rules.

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
    //preconditions:
    assert(pattern.length() > 0 && source.length());
    //postconditions: the function returns true if pattern matches source exactly, following the wild-card char rules.

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
        if (pattern.find("*") == -1)
            return false ;
        else
        {
            pattern.erase(pattern.find("*"),1);
            return match_pattern(pattern,source);
        }
    }

    if (pattern.length() < source.length())
    {

        if ((pattern[i] == source[i]) || (pattern[i] == '.' ))
        {
            flag = false;
            i++;
            return match_pattern(pattern,source);
        }
        else if ( pattern[i] == '*')
        {
            flag = true ;
            i++;
        }
        if (flag)
        {
            source.erase(i,1);
            return match_pattern(pattern,source);
        }
        else
            return false ;

    }
}

int main()
{
    //preconditions:
    assert(true);
    //postconditions: the function simplifies all the wild-card char and then it call match pattern.

    string pattern = "...*";
    string source =  "snflsnfskjfnskdjfnskjvjdbf";

    pattern = pattern_simp(pattern) ;

    if (match_pattern(pattern,source))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0 ;
}
