#ifndef KARMA_H
#define KARMA_H

#include <vector>
#include <algorithm>
#include <unordered_map>

// 0 <= k <= contests.size()
// 1 <= L <= 10^4
//
const uint MAX_L = 10000;
const uint MIN_L = 1;

int maxKarma(int k, const std::vector<std::pair<int,bool>> &contests)
{
    std::unordered_multimap<int,bool> mcontests;
    mcontests.insert(contests.begin(), contests.end());
    int karma = 0;
    for (uint i = MAX_L; i >= MIN_L; i--){
        auto range = mcontests.equal_range(i);
        for_each (
                range.first,
                range.second,
                [&k, &karma](std::pair<int,bool> item){
                    if (item.second && k == 0){
                        karma -= item.first;
                    } else {
                        karma += item.first;
                        k -= (int)item.second;
                    }
                }
        );
    }
    return karma; // linear complexity 
}

int maxKarma2(int k, std::vector<std::pair<int, bool>> contests)
{
    int karma = 0;
    std::sort( contests.begin( ), contests.end( ), [ ]( const auto& lhs, const auto& rhs ) // O(N·log(N))
    {
        return lhs.first > rhs.first;
    });    
    for ( auto &item : contests){ // O(N)
        if (item.second && k == 0){
            karma -= item.first;
        } else {
            karma += item.first;
            k -= (int)item.second;
        }
    }
    return karma;
}

#endif // KARMA_H
