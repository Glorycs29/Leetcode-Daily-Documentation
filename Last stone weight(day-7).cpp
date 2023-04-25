// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         // we'll use priority queue
//         priority_queue<int> pq;

//         for(int i=0;i<stones.size();i++){
//             pq.push(stones[i]);
//         }

//         while(pq.size()>1){
//             int heavy1 = pq.top();
//             pq.pop();
//             int heavy2= pq.top();
//             pq.pop();

//             if(heavy1!=heavy2){
//                 pq.push(abs(heavy1-heavy2));
//             }
//         }

//         if(pq.size()<1){
//             return 0;
//         }else{
//             return pq.top();
//         }
//     }
// };


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> max_heap;
        for (auto stone : stones) {
            max_heap.push(stone);
        }
        while (max_heap.size() != 1) {
            int stone1 = max_heap.top();
            max_heap.pop();
            int stone2 = max_heap.top();
            max_heap.pop();
            max_heap.push(max(stone1, stone2) - min(stone1, stone2));
        }
        return max_heap.top();
    }
};
