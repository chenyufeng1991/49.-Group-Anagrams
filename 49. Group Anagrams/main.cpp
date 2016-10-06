//
//  main.cpp
//  49. Group Anagrams
//
//  Created by chenyufeng on 10/6/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 *  For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
 Return:

 [
 ["ate", "eat","tea"],
 ["nat","tan"],
 ["bat"]
 ]
 *
 */
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> result;
    vector<string> row1;
    row1.push_back(strs[0]); // 第一个放入
    result.push_back(row1);

    for (int i = 1; i < strs.size(); i++)
    {
        string tempS = strs[i];
        sort(tempS.begin(), tempS.end());
        for (int j = 0; j < result.size(); j++)
        {
            vector<string> tempV = result[j];
            string tempStr = tempV[0];
            sort(tempStr.begin(), tempStr.end());
            if (tempStr == tempS)
            {
                result[j].push_back(strs[i]);
                break;
            }
            else
            {
                if (j == result.size() - 1)
                {
                    vector<string> insert;
                    insert.push_back(strs[i]);
                    result.push_back(insert);
                    break;
                }
            }
        }
    }

    return result;
}
/**
 *  [
 ["ate", "eat","tea"],
 ["nat","tan"],
 ["bat"]
 ]
 *
 */
int main(int argc, const char * argv[])
{

    vector<string> vv;
    /**
     *  ["eat", "tea", "tan", "ate", "nat", "bat"]
     */
    vv.push_back("eat");
    vv.push_back("tea");
    vv.push_back("tan");
    vv.push_back("ate");
    vv.push_back("nat");
    vv.push_back("bat");

    groupAnagrams(vv);

    return 0;
}










