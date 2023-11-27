class Solution {
public:
    unordered_map<int,unordered_set<int>> ulist;
    unordered_set<int> visited; // save visited nodes when bfs from 'source'
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // build adjcency list       
        int L = edges.size();
        for(int i = 0; i < L; i++){
            ulist[edges[i][0]].insert(edges[i][1]);
            ulist[edges[i][1]].insert(edges[i][0]);
        }

        // bfs   
        visited.insert(source);
        // where to put queue and how to update queue ? no need queue 
        for(auto i : ulist[source])
            bfs(i);
        
        return visited.find(destination) != visited.end(); 
    }
    void bfs(int sou){
        visited.insert(sou);
        for(auto i : ulist[sou]){
            if(visited.find(i) == visited.end())
                bfs(i);
        }
    }
};
/*
    bài này dễ mà, bfs cơ bản thôi 
    từ source lưu hết các nodes source bfs tới được 
    nếu destination nằm trong các nodes đó thì trả về true,
    không thì trả về false
*/