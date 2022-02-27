#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int cost = 0;

int root(int parent[], int v) {
	if(parent[v] < 0) {
		return v;
	}else {
		parent[v] = root(parent, parent[v]);
		return parent[v];
	}
}

bool is_same_set(int parent[], int v, int u) {
	return root(parent, v) == root(parent, u);
}

void merge(int parent[], int v, int u) {
	v = root(parent, v);
	u = root(parent, u);
	if(v == u) return;

	if(parent[u] < parent[v]) {
		int temp = parent[u];
		parent[u] = parent[v];
		parent[v] = temp;
	}

	parent[v] += parent[u];
	parent[u] = v;
}

vii kruskal(vector<pair<int, ii>> edges, int n) {
	priority_queue<ii, vii, greater<ii>> queue_p;

	int parent[n];
	pair<int, ii> u;
	vii mst;
	
	memset(parent, -1, sizeof(parent));
	sort(edges.begin(), edges.end());

	for(int i = 0; i < edges.size(); i++) {
		u = edges[i];
		int v1 = u.second.first;
		int v2 = u.second.second;

		if(!is_same_set(parent, v1, v2)) {
			cost += u.first;
			mst.push_back(make_pair(v1, v2));
			merge(parent, v1, v2);
		}
	}

	return mst;
}

int main(int argc, char **argv) {
	string solution_command = "-s";

	bool solution = false;

  if(argc > 1) {
    for(int i = 0; i < argc; i++) {
			if(argv[i] == solution_command) {
				solution = true;
			}
    }
  }

	int v, e, e1, e2, w, temp;

	cin >> v >> e;
	vector<pair<int, ii>> edges;

	for(int i = 0; i < e; i++) {
		cin >> e1 >> e2;

		temp = cin.get();
		w = 1;
		if(temp == ' ') cin >> w;
		
		edges.push_back(make_pair(w, ii(e1, e2)));
	}
	
	vii mst;
	
	mst = kruskal(edges, v+1);
	sort(mst.begin(), mst.end());
	
	if(solution) {
		for(int i = 0; i < mst.size(); i++) {
			cout << "(" << mst[i].first << "," << mst[i].second << ") ";
		}
		cout << "\n";
	}else {
		cout << cost << "\n";
	}
	
  return 0;
}
