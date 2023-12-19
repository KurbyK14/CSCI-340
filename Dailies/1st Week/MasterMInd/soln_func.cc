#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int mm_score(string k, string g, int &b, int &w)
{
    vector<int> k_pos;
    vector<int> g_pos;

    int score = 0, B_points = 0, W_points = 0;

    for (unsigned int i = 0; i < k.length(); i++)
     {
        if (k[i] == g[i])
        {
            B_points++;
            k_pos.push_back(i);
            g_pos.push_back(i);
        }
    }

    for (unsigned int i = 0; i < k.length(); i++)
    {
        for (unsigned int j = 0; j < g.length(); j++)
        {
            if (k[i] == g[j])
             {
                if (find(k_pos.begin(), k_pos.end(), i) == k_pos.end() && find(g_pos.begin(), g_pos.end(), j) == g_pos.end())
                {
                    W_points++;
                    k_pos.push_back(i);
                    g_pos.push_back(j);
                }
            }
        }
    }

    b = B_points;
    w =W_points;

    score = (B_points * 10) + W_points;
    return score;
}