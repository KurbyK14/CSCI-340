#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> diamondsequence(vector<vector<int>> &m)
{
    int n = m.size();
    vector<int> result;

    if(n % 2 == 0 || n <= 2)
    {
        return result;
    }
    
    int mid = n / 2;
    result.push_back(m[mid][mid]);

    int layer = 1;

    while(layer <= mid)
    {
        result.insert(result.end(), m[mid - layer].begin() + mid - layer, m[mid - layer].begin() + mid + layer + 1);

        for(int i = mid - layer + 1; i <= mid + layer - 1; i++)
        {
            result.push_back(m[i][mid + layer]);
        }

        reverse(m[mid + layer].begin() + mid - layer, m[mid + layer].begin() + mid + layer + 1);
        result.insert(result.end(), m[mid + layer].begin() + mid - layer, m[mid + layer].begin() + mid + layer + 1);

        reverse(m[mid + layer].begin() + mid - layer, m[mid + layer].begin() + mid + layer + 1);

        for(int i = mid + layer - 1; i >= mid - layer + 1; i--)
        {
            result.push_back(m[i][mid - layer]);
        }

        layer++;
    }

    return result;
}