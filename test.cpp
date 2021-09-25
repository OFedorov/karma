#include <iostream>
#include <vector>

#include "karma.h"

using namespace std;

int main(){
    int k;
    int karma;
    int max_karma;
    vector<pair<int,bool>> contests;

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // k=2, {4,true},{2,true},{6,false}
    // karma == 12
    k = 2;
    karma = 12;
    contests.clear();
    contests.push_back(pair<int,bool>(4,true));
    contests.push_back(pair<int,bool>(2,true));
    contests.push_back(pair<int,bool>(6,false));
    max_karma = maxKarma(k, contests);
    cout << "k=2, {4,true},{2,true},{6,false}" << endl;
    cout << "expected: " << karma << " result: " << max_karma << (karma == max_karma ? " true " : " false ") << endl;
    if (karma != max_karma){
        cerr << "Failed" << endl;
        return -1;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl; 
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // k=1, {4,true},{2,true},{6,false}
    // karma == 8
    k = 1;
    karma = 8;
    contests.clear();
    contests.push_back(pair<int,bool>(4,true));
    contests.push_back(pair<int,bool>(2,true));
    contests.push_back(pair<int,bool>(6,false));
    max_karma = maxKarma(k, contests);
    cout << "k=2, {4,true},{2,true},{6,false}" << endl;
    cout << "expected: " << karma << " result: " << max_karma << (karma == max_karma ? " true " : " false ") << endl;
    if (karma != max_karma){
        cerr << "Failed" << endl;
        return -1;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl; 
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // k=1, {4,true},{2,true},{6,true}{10000,true}
    // karma == 9988 
    k = 1;
    karma = 9988;
    contests.clear();
    contests.push_back(pair<int,bool>(4,true));
    contests.push_back(pair<int,bool>(2,true));
    contests.push_back(pair<int,bool>(6,true));
    contests.push_back(pair<int,bool>(10000,true));
    max_karma = maxKarma(k, contests);
    cout << "k=1, {4,true},{2,true},{6,false}{10000,true}" << endl;
    cout << "expected: " << karma << " result: " << max_karma << (karma == max_karma ? " true " : " false ") << endl;
    if (karma != max_karma){
        cerr << "Failed" << endl;
        return -1;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl; 
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // k=0, ...
    // karma == 0
    k = 0;
    karma = 0;
    contests.clear();
    max_karma = maxKarma(k, contests);
    cout << "k=0, ..." << endl;
    cout << "expected: " << karma << " result: " << max_karma << (karma == max_karma ? " true " : " false ") << endl;
    if (karma != max_karma){
        cerr << "Failed" << endl;
        return -1;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl; 
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // k=1, {4,false},{2,false},{6,false}{10000,false}
    // karma == 10012 
    k = 4;
    karma = 10012;
    contests.clear();
    contests.push_back(pair<int,bool>(4,false));
    contests.push_back(pair<int,bool>(2,false));
    contests.push_back(pair<int,bool>(6,false));
    contests.push_back(pair<int,bool>(10000,false));
    max_karma = maxKarma(k, contests);
    cout << "k=1, {4,false},{2,false},{6,false}{10000,false}" << endl;
    cout << "expected: " << karma << " result: " << max_karma << (karma == max_karma ? " true " : " false ") << endl;
    if (karma != max_karma){
        cerr << "Failed" << endl;
        return -1;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << endl; 
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    // k=0, {10000,false} * (2 147 48 + 1) (overflow test)
    // karma == 8
    k = 0;
    karma = -1;
    contests.clear();
    for (int i = 0; i < 214749; i++){
        contests.push_back(pair<int,bool>(10000,false));
    }
    max_karma = maxKarma(k, contests);
    cout << "k=0, {10000,false} * (2 147 48 + 1) (overflow test)" << endl;
    cout << "expected: 2147490000" << " result: " << max_karma << endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////
 
    return 0;
}

