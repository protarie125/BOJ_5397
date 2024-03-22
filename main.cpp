#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using vii = vector<pii>;
using vll = vector<pll>;
using vs = vector<string>;

using vvb = vector<vb>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

ll t;
string s;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> t;
  while (0 < (t--)) {
    cin >> s;

    auto dq = deque<char>{};
    auto dq2 = stack<char>{};

    for (const auto& x : s) {
      if ('<' == x) {
        if (dq.empty()) {
          continue;
        }

        auto y = dq.back();
        dq.pop_back();
        dq2.push(y);
      } else if ('>' == x) {
        if (dq2.empty()) {
          continue;
        }

        auto y = dq2.top();
        dq2.pop();
        dq.push_back(y);
      } else if ('-' == x) {
        if (dq.empty()) {
          continue;
        }

        dq.pop_back();
      } else {
        dq.push_back(x);
      }
    }

    while (!dq2.empty()) {
      dq.push_back(dq2.top());
      dq2.pop();
    }

    while (!dq.empty()) {
      cout << dq.front();
      dq.pop_front();
    }
    cout << '\n';
  }

  return 0;
}