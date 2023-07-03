class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Adjacency List in the form of a map:
        unordered_map <int, list<pair<int,int>>> adj;
        for(int i=0; i<times.size(); i++) {
            int source = times[i][0];
            int target = times[i][1];
            int time = times[i][2];
            adj[source].push_back({target,time});
        }

        // Dijkstra's Algorithm:

        // Create a minHeap
        priority_queue <
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
            > minHeap;

        // Create a vector for distance
        vector<int> distance(n+1, INT_MAX);
        distance[0] = 0;

        minHeap.push({0,k});
        distance[k] = 0;

         
        while (!minHeap.empty()) {

            // Iterate over each node on the minHeap
            auto iteration = minHeap.top();
            minHeap.pop();
            int dist = iteration.first;
            int node = iteration.second;
            
            // iterate over each element
            for(auto iteration : adj[node]){
                int adjNode = iteration.first;
                int wt = iteration.second;
                
                int curr = wt + dist;
                
                if(curr < distance[adjNode]){
                    distance[adjNode] = curr;
                    minHeap.push({curr,adjNode});
                }
            }
        }

        int max = -1;
        for(int i=0; i<n+1; i++)  {
            if(distance[i]==INT_MAX)    {
                return -1;
            }
            max = max(distance[i],max);
        }
        
        return max;

    }
};
