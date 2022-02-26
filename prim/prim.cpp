#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii prim(vii adj_list[], int s, int n) {
	priority_queue<ii, vii, greater<ii>> queue_p;

	int parent[n];
	vector<bool> visited_list;
	ii u;
	vii mst;
	
	visited_list.assign(n, false);
	parent[s] = -1;

	queue_p.push(make_pair(0, s));

	while(!queue_p.empty()) {
		int v = queue_p.top().second;
		queue_p.pop();

		if(visited_list[v])continue;
		visited_list[v] = true;

		if(parent[v] != -1) {
			mst.push_back(make_pair(min(v, parent[v]), max(v, parent[v])));
		}

		for(int i = 0; i < adj_list[v].size(); i++) {
			u = adj_list[v][i];
			parent[u.first] = v;
	
			queue_p.push(make_pair(u.second, u.first));
		}
	}

	return mst;
}

int main(int argc, char **argv) {
	string begin_vertex_command = "-i";
	string solution_command = "-s";

	int begin_vertex = -1;
	bool solution = false;

  if(argc > 1) {
    for(int i = 0; i < argc; i++) {
			if(argv[i] == begin_vertex_command) {
				begin_vertex = stoi(argv[i+1]);
				i++;
			}
			if(argv[i] == solution_command) {
				solution = true;
			}
    }
  }

	int v, e, e1, e2, w, temp;

	cin >> v >> e;
	vii adj_list[v+1];

	for(int i = 0; i < e; i++) {
		cin >> e1 >> e2;

		temp = cin.get();
		w = 1;
		if(temp == ' ') cin >> w;
		
		adj_list[e1].push_back(ii(e2, w));
		adj_list[e2].push_back(ii(e1, w));
	}
	
	vii mst;
	
	if(begin_vertex == -1) {
		cout << "parametro -i obrigatorio\n";
	}else {
		mst = prim(adj_list, begin_vertex, v+1);
		sort(mst.begin(), mst.end());
		
		if(solution) {
			for(int i = 0; i < mst.size(); i++) {
				cout << "(" << mst[i].first << "," << mst[i].second << ") ";
			}
			cout << "\n";
		}else {
			int cost = 0;
			
			for(int i = 0; i < mst.size(); i++) {
				for(int j = 0; j < adj_list[mst[i].first].size(); j++) {
					if(mst[i].second == adj_list[mst[i].first][j].first) {
						cost += adj_list[mst[i].first][j].second;
					}
				}
			}
			cout << cost << "\n";
		}
	}
	
  return 0;
}
