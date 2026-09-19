class MedianFinder {
public:
    MedianFinder() {
        
    }
    vector<int>v;
    void addNum(int num) {
        v.push_back(num);
        sort(v.begin(), v.end());
    }
    
    double findMedian() {
        int n = v.size();

        if(n%2 == 1){
            return v[n/2];
        }

        return (v[n/2] + v[(n/2)-1])/2.0;
    }
};
