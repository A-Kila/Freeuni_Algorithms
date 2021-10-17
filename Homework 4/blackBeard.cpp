#include <bits/stdc++.h>
using namespace std;

char tMap[50][50];
int pathTime[50][50];
bool color[50][50];
short indexes[50][50];
pair<int, int> *dest;
int graph[50][50];

int w, h, numTres;
int startI, startJ;

int makeGraph(int hPos, int wPos, int indx) {
	queue<pair<int, int>> queue;
	queue.push({ hPos, wPos });

	memset(color, 0, h * 50);
	pathTime[hPos][wPos] = 0;

	graph[indx][indx] = 0;

	int destFound = 0;
	while (queue.size()) {
		pair<int, int> pos = queue.front();
		queue.pop();

		color[pos.first][pos.second] = true;

		bool cont = false;                                         // skip if next to natives  
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++)
				if (pos.first + i >= 0 && pos.first + i < h && 
                    pos.second + j >= 0 && pos.second + j < w)
                    {
                        if (tMap[pos.first + i][pos.second + j] == '*') {
                            cont = true;
                            break;
                        }
                    }
            if (cont) break;
        }
        if (cont) continue;

        if (numTres == 0) return 0;


		if (hPos != pos.first || wPos != pos.second) {
			if (tMap[pos.first][pos.second] == '@' || tMap[pos.first][pos.second] == '!') {
				destFound++;

				if (indx == 0) { 
					dest[destFound] = {pos.first, pos.second}; 
					indexes[pos.first][pos.second] = destFound;
				}

				graph[indx][indexes[pos.first][pos.second]] = pathTime[pos.first][pos.second];

				if (destFound == numTres) {
					if (indx == numTres) return 1;
					indx++;
					return (makeGraph(dest[indx].first, dest[indx].second, indx));
				}
			}
		}


		for (int i = -1; i <= 1; i++) {                             // add next node
			for (int j = -1; j <= 1; j++) {
                if ((i == 0 || j == 0) &&
                    pos.first + i >= 0 && pos.first + i < h &&
                    pos.second + j >= 0 && pos.second + j < w) 
                { 
                    char next = tMap[pos.first + i][pos.second + j];
                    bool col = color[pos.first + i][pos.second + j];
                    if (!col && next != '~' && next != '#') {
                        color[pos.first + i][pos.second + j] = true;
                        pathTime[pos.first + i][pos.second + j] = pathTime[pos.first][pos.second] + 1;
                        queue.push({ pos.first + i, pos.second + j });
                    }
                }
            }
        }
	}

	return -1;
}

int *indxLeft;

int getTime(int size, int atIndx) {
	if (size == 0) return graph[atIndx][0];
	int minSize = INT_MAX;
	for (int i = 0; i < size; i++) {
		int roadToPoint = graph[atIndx][indxLeft[i]];
		swap(indxLeft[i], indxLeft[size - 1]);
		int roadSize = getTime(size - 1, indxLeft[size - 1]) + roadToPoint;
		swap(indxLeft[i], indxLeft[size - 1]);
		minSize = (roadSize < minSize) ? roadSize : minSize;
	}
	return minSize;
}

int countHours() {
	pair<int, int> tresPos[numTres + 1];
	dest = tresPos;
	dest[0] = {startI, startJ};
    int err = makeGraph(startI, startJ, 0);
	if (err <= 0) return err;
	int tresIndxes[numTres];
	for (int i = 0; i < numTres; i++)
		tresIndxes[i] = i + 1;
	indxLeft = tresIndxes;
    return getTime(numTres, 0);
}

int main() {
	while (true) {
		cin >> h >> w;
		if (w == 0 && h == 0) break;

		numTres = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				cin >> tMap[i][j];
				if (tMap[i][j] == '@') {
					startI = i;
					startJ = j;
				}
				if (tMap[i][j] == '!') numTres++;
			}

		cout << countHours() << endl;
	}
}