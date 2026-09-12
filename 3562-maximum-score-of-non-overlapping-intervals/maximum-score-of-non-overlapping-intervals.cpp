class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };

    bool lexSmaller(const vector<int>& a, const vector<int>& b) {
        return lexicographical_compare(
            a.begin(), a.end(),
            b.begin(), b.end()
        );
    }

    Node better(const Node& a, const Node& b) {
        if (a.score != b.score)
            return (a.score > b.score) ? a : b;

        return lexSmaller(a.ids, b.ids) ? a : b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {left, right, weight, original index}
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by ending point
        sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
            if (x[1] != y[1])
                return x[1] < y[1];

            return x[0] < y[0];
        });

        vector<long long> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        // prev[i] = number of intervals before i
        // whose ending point is strictly less than a[i].left
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] =
                lower_bound(
                    ends.begin(),
                    ends.begin() + i,
                    a[i][0]
                ) - ends.begin();
        }

        // dp[k][i]:
        // best answer using first i intervals
        // and at most k intervals
        vector<vector<Node>> dp(
            5,
            vector<Node>(n + 1, {0, {}})
        );

        for (int k = 1; k <= 4; k++) {

            for (int i = 1; i <= n; i++) {

                // Don't take current interval
                Node skip = dp[k][i - 1];

                // Take current interval
                Node take = dp[k - 1][prev[i - 1]];

                take.score += a[i - 1][2];

                // Add original index
                take.ids.push_back((int)a[i - 1][3]);

                // Keep indices sorted because final answer
                // must be lexicographically compared.
                sort(take.ids.begin(), take.ids.end());

                dp[k][i] = better(skip, take);
            }
        }

        return dp[4][n].ids;
    }
};