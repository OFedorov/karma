#ifndef KARMA_H
#define KARMA_H

#include <vector>
#include <algorithm>

// 0 <= k <= contests.size()
// 1 <= L <= 10^4
//
int maxKarma(int k, std::vector<std::pair<int, bool>> contests)
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
