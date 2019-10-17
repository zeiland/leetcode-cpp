#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int>> arcs(N, vector<int>(N, INT_MAX));
        for(const auto& time: times){
            arcs[time[0] - 1][time[1] - 1] = time[2];
        }
        vector<bool> visited(N,false);
        visited[K-1] = true;
        vector<int> dist(arcs[K-1]);
        dist[K-1] = 0;
        for(int i = 1; i < N; ++i){
            int min_dist = INT_MAX;
            int min_node = -1;
            for(int j = 0; j < N; ++j){
                if(!visited[j] && dist[j] < min_dist){
                    min_dist = dist[j];
                    min_node = j;
                }
            }
            if(min_node == -1){
                break;
            }
            visited[min_node] = true;
            for(int j = 0; j < N; ++j){
                if(!visited[j] && arcs[min_node][j] < INT_MAX &&arcs[min_node][j] + min_dist < dist[j]){
                    dist[j] = arcs[min_node][j] + min_dist;
                }
            }
        }
        for(const auto& flag:visited){
            if(!flag){
                return -1;
            }
        }
        return *max_element(dist.begin(),dist.end());
    }
};