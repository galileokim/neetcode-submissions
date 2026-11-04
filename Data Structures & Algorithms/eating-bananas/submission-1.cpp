class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // h >= piles.size()
        // upper bound: k <= the largest pile size

        // range we are eating bananas in is [1, k] where k <= largest pile size
        // do bin search in this range
        // if we cannot finish the bananas in the middle of the range, shift to the 
        // middle of the second half
        // likewise if we finish the bananas early and have some hours remaining
        // do the search in the middle of the first half

        // have a variable min rate: if h >= 0 and piles is empty, set 
        // minRate = min(minRate k)

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

            if (l == r) {
                run = false;
            }

            if (hSum > h) {
                l = middle + 1;
            } else {
                r = middle - 1;
                k = min(k, static_cast<int>(middle));
            }
        }

        return k;

    }
};
