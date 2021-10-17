#include <bits/stdc++.h>
using namespace std;


struct Road {
    int to;
    bool money;
    int time, height, ind;
};

struct Path {
    Road *curRoad = NULL;
    int timeSpent = 0, moneySpent = 0, height = 0, numRoadsUsed = 0;
    string roadIndexes = "";
    bool operator < (const Path& other) const {
        return height > other.height; // inverse so the priority queue returns the min element
    }
};

int z = sizeof(Road);
int j = sizeof(Path);

int n, m, s, e, b, t;
map<int, vector<Road>> graph;

bool stringContains(string &strIndx, string &indx) {
    size_t indxLoc = strIndx.find(indx);
    if (strIndx.find(indx) == string::npos) return false;
    if ((indxLoc == 0 || strIndx[indxLoc - 1] == ' ') && strIndx[indxLoc + indx.length()] == ' ')
        return true;
    return false;
}

void getResult() {
    priority_queue<Path> que;
    Road startNode = { s, 0, 0, 0, 0 };
    que.push({ &startNode });

    bool found = false;
    Path result;
    while (que.size()) {
        Path node = que.top();
        que.pop();

        if (node.timeSpent > t || node.moneySpent > b || node.moneySpent > 101)
            continue;

        int city = node.curRoad->to;
        if (city == e) { 
            found = true;
            result = node;
            break; 
        }

        vector<Road>& roads = graph[city];
        for (int i = 0; i < roads.size(); i++) {
            int toCity = roads[i].to;

            string roadIndex = to_string(roads[i].ind);
            size_t subStrAt = node.roadIndexes.find(roadIndex);
            if (stringContains(node.roadIndexes, roadIndex)) continue;
            roadIndex += " ";

            Path nextPath = {
                &roads[i],
                node.timeSpent + roads[i].time,
                node.moneySpent + roads[i].money,
                (roads[i].height > node.height) ? roads[i].height : node.height,
                node.numRoadsUsed + 1,
                node.roadIndexes + roadIndex
            };
            que.push(nextPath);
        }
    }

    if (!found) {
        cout << "-1" << endl;
        return;
    }

    cout << result.height << endl << result.numRoadsUsed << endl << result.roadIndexes << endl;
}

int main() {
    cin >> n >> m >> s >> e >> b >> t;
    for (int i = 0; i < m; i++) {
        int u, v, c, t, h;
        cin >> u >> v >> c >> t >> h;
        graph[u].push_back({ v, (bool)c, t, h, i + 1 });
    }

    getResult();
}