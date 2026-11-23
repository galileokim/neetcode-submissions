class Solution {
public:
    int distance(int x, int y) {
        return sqrt(x^2+y^2);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> e;
        for (int i = 0; i < points.size(); i++) {
            int d = distance(points[i][0], points[i][1]);

            if (e.size() == 0) {
                e.push_back({d, points[i]});
            } else {
                int beg = 0;
                int end = e.size() - 1;
                int mid = 0;

                while (beg <= end) {
                    mid = (beg + end) / 2;
                    if (e[mid].first > d) {
                        end = mid - 1;
                    } else if (e[mid].first < d) {
                        beg = mid + 1;
                    } else {
                        break;
                    }
                }

                if (e.size() < k) {
                    if (d < e[mid].first) {
                        e.insert(e.begin() + mid, {d, points[i]});
                    } else {
                        e.insert(e.begin() + mid + 1, {d, points[i]});
                    }
                } else {
                    if (d < e[mid].first) {
                        e.insert(e.begin() + mid, {d, points[i]});
                        e.pop_back();
                    } else {
                        if (mid < k - 1) {
                            e.insert(e.begin() + mid + 1, {d, points[i]});
                            e.pop_back();
                        }
                    }
                }
            }
        }

        vector<vector<int>> out;

        for (int i = 0; i < e.size(); i++) {
            out.push_back(e[i].second);
        }

        return out;
    }
};
