#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int findmiddle(vector<vector<int>> &vecs, int &p)
{
    std::vector<int> V;

    int sum = 0;

    if(vecs.size() <= 0)
    {
        return 0;
    }

    for (const auto &i : vecs)
    {
        sum += i.size();

        for (const auto &j : i)
        {
            V.push_back(j);
        }
    }

    if(sum % 2 == 0 || sum <= 0)
    {
        return 0;
    }
    else
    {
        std::sort(V.begin(), V.end());
        return p = V[V.size() / 2];
    }

    return 1;
}