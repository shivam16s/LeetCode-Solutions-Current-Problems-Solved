class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int k = 0;
        res.push_back(intervals[0]);
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0] <= res[k][1]){
                if( res[k][1] < intervals[i][1]){
                    res[k][1] = intervals[i][1];

                }
            }
            else{
                res.push_back(intervals[i]);
                k++;
            }
        }
        return res;
    }
};