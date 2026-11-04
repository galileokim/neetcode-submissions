class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;

        for (int p : piles) {
            maxPile = max(maxPile, p);
        }

        int l = 1;
        int r = maxPile;
        int k = maxPile;
        bool run = true;

        while (run) {
            double middle = (r + l)/2;

            int hSum = 0;
            for (int p : piles) {
                hSum += static_cast<int>(ceil(p/middle));
            }

            if (l >= r) {
                run = false;
            }

            if (hSum > h) {
                l = middle + 1;
            } else {
                r = middle;
                k = min(k, static_cast<int>(middle));
            }
        }

        return k;

    }
};
