class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjlist(n+1) ; 
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq ;
        for (auto &u : times) {
            adjlist[u[0]].push_back({u[1] , u[2]}) ; 
        }
        vector<int> distance(n+1 , INT_MAX) ; 
        distance[0] = 0;
        distance[k] = 0 ; 
        pq.push({0,k});
        while (!pq.empty()) {
            auto [dist , node] = pq.top() ; 
            pq.pop() ; 
            if (dist > distance[node]) continue ; 
            for (auto &u : adjlist[node]) {
                if (dist + u.second >= distance[u.first]) continue ; 
                else {
                    distance[u.first] = dist + u.second ; 
                    pq.push({dist+u.second , u.first}) ; 
                }
            }
        }
        int ans = 0 ; 
        for (auto &u : distance) {
            if (u == INT_MAX) return -1 ;
            else ans = max(ans , u) ; 
        }
        return ans ;   
        
    }
};
