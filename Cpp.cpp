#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define debug(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
inline ll Mod(ll x, ll mod) { return x % mod >= 0 ? x % mod : x % mod + mod; }

ll mod = 1000 * 1000 * 1000 + 7;

vector<vector<ll>> matrix(const vector<vector<ll>> &A, const vector<vector<ll>> &B)
{
    vector<vector<ll>> ans = {{0, 0}, {0, 0}};
    ans[0][0] = (A[0][0] * B[0][0] % mod + A[0][1] * B[1][0] % mod) % mod;
    ans[0][1] = (A[0][0] * B[0][1] % mod + A[0][1] * B[1][1] % mod) % mod;
    ans[1][0] = (A[1][0] * B[0][0] % mod + A[1][1] * B[1][0] % mod) % mod;
    ans[1][1] = (A[1][0] * B[0][1] % mod + A[1][1] * B[1][1] % mod) % mod;
    return ans;
}

ll fibbonacci(ll fib0, ll fib1, ll n)
{
    vector<vector<ll>> ans = {{1, 0}, {0, 1}}, p = {{0, 1}, {1, 1}};
    while (n)
    {
        if (n & 1)
            ans = matrix(ans, p);
        p = matrix(p, p);
        n >>= 1;
    }
    return (fib0 * ans[0][0] % mod + fib1 * ans[1][0] % mod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
