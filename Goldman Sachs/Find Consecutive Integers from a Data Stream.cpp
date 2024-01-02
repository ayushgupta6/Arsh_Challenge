//link: https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/
class DataStream {
public:
    int val, K, count;
    DataStream(int value, int k) {
        val = value;
        K = k;
        count = 0;
    }
    
    bool consec(int num) {
        if (num == val) count++;
        else count = 0;
        return count >= K;
    }
};
