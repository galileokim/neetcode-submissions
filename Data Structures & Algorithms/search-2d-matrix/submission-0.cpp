class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();

        return searchForRow(matrix, target, 0, size-1);
    }

    bool searchForRow(vector<vector<int>>& m, int target, int lowRange, int highRange) {
        if (lowRange > highRange) {
            return false; 
        }

        int mid = (lowRange + highRange)/2;
        
        if (target < m[mid][0]) {
            return searchForRow(m, target, lowRange, mid-1);
        } else if (target > m[mid].back()) {
            return searchForRow(m, target, mid+1, highRange);
        } else {
            return searchRow(m[mid], target, 0, m[mid].size() - 1);
        }

        return false;
    }

    bool searchRow(vector<int>& m, int target, int lowRange, int highRange) {
        if (lowRange > highRange) {
            return false; 
        }

        int mid = (lowRange + highRange)/2;
        
        if (target == m[mid]) {
            return true;
        } else if (target < m[mid]) {
            return searchRow(m, target, lowRange, mid-1);
        } else {
            return searchRow(m, target, mid+1, highRange);
        }

        return false;
    }
};
