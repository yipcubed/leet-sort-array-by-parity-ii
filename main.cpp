#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/sort-array-by-parity-ii/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    int nextOdd(vector<int> &A, int start) {
        while (start < A.size() && A[start] % 2 == 0)
            ++start;
        return start;
    }

    int nextEven(vector<int> &A, int start) {
        while (start < A.size() && A[start] % 2 == 1)
            ++start;
        return start;
    }


    vector<int> sortArrayByParityII(vector<int> &A) {
        if (A.empty()) return A;
        int even = -1;
        int odd = -1;
        int i = 0;
        bool flip = true;
        while (i < A.size()) {
            if (flip && A[i] % 2 == 1) {
                even = nextEven(A, max(even, i + 1));
                if (even == A.size()) return A;
                swap(A[i], A[even]);
            } else if (!flip && A[i] % 2 == 0) {
                odd = nextOdd(A, max(odd, i + 1));
                if (odd == A.size()) return A;
                swap(A[i], A[odd]);
            }
            flip = !flip;
            ++i;
        }
        return A;
    }
};

void test1() {
    vector<int> v1{4, 2, 5, 7};

    cout << "[4, 5, 2, 7] ? " << Solution().sortArrayByParityII(v1) << endl;
}

void test2() {

}

void test3() {

}