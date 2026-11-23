class Solution {
public:
    double distance(int x, int y) {
        return sqrt(x*x+y*y);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, vector<int>>> e;
        for (int i = 0; i < points.size(); i++) {
            double d = distance(points[i][0], points[i][1]);

            if (e.size() == 0) {
                e.push_back({d, points[i]});
            } else {
                int beg = 0;
                int end = e.size();
                int mid = 0;

                while (beg < end) {
                    mid = (beg + end) / 2;
                    if (e[mid].first > d) {
                        end = mid;
                    } else {
                        beg = mid + 1;
                    }

                }

                e.insert(e.begin() + beg, {d, points[i]});
                if (e.size() > k) {
                    e.pop_back();
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
