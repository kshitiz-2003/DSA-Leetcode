class Solution {
private:
    static const long long MOD = 1000000007;

    long long Power(long long x, long long y) {
        if (y == 0) {
            return 1;
        }

        long long half = Power(x, y / 2);

        long long ans = (half * half) % MOD;

        if (y % 2 == 1) {
            ans = (ans * x) % MOD;
        }

        return ans;
    }


public:
    int countGoodNumbers(long long n) {
        // Use chatgpt
        // https://www.youtube.com/watch?v=CctVpEGgNf0

        // Code
        long long odd = n / 2;
        long long even = (n + 1) / 2;

        long long evenWays = Power(5, even);
        long long oddWays = Power(4, odd);

        return (evenWays * oddWays) % MOD;
    }
};