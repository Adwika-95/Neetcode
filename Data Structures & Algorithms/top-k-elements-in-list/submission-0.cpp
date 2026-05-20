class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        
        // Step 1: Frequency count
        for (int num : nums) {
            freq[num]++;
        }
        
        // Min-heap: {frequency, number}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        // Step 2: Keep top k elements in heap
        for (auto it : freq) {
            pq.push({it.second, it.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // Step 3: Extract result
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};