class Solution {
public:
    int countCommas(int n) {
        int comma = 0;

        for (int i = 1000; i <= n; i++) {
            comma++;
        }

        return comma;
    }
};