#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi bellman_ford(vii adj_list[], int s, int n) {
	vector<int> dist;
	ii u;

	dist.assign(n, INT_MAX);
	dist[s] = 0;

	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < n; j++) {
			for(int m = 0; m < adj_list[j].size(); m++) {
				u = adj_list[j][m];
				dist[u.first] = min(dist[u.first], dist[j] + u.second);
			}
		}
	}
	bool hasNegativeCycle = false;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < adj_list[i].size(); j++) {
			u = adj_list[i][j];
			if(dist[u.first] > dist[i] + u.second) hasNegativeCycle = true;
		}
	}
	if(hasNegativeCycle) {
		cout << "tem ciclo negativo\n";
	}else {
		cout << "nao tem ciclo negativo\n";
	}

	return dist;
}

int main(int argc, char **argv) {
	string begin_vertex_command = "-i";
	string end_vertex_command = "-l";

	int begin_vertex = -1;
	int end_vertex = -1;

  if(argc > 1) {
    for(int i = 0; i < argc; i++) {
			if(argv[i] == begin_vertex_command) {
				begin_vertex = stoi(argv[i+1]);
				i++;
			}
			if(argv[i] == end_vertex_command) {
				end_vertex = stoi(argv[i+1]);
				i++;
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
	
	vi dist;

	if(begin_vertex == -1) {
		cout << "parametro -i obrigatorio\n";
	}else {
		dist = bellman_ford(adj_list, begin_vertex, v+1);
		if(end_vertex == -1) {
			for(int i = 1; i <= v; i++) {
				cout << i << ":" << dist[i] << " ";
			}
			cout << "\n";
		}else {
			cout << dist[end_vertex] << "\n";
		}
	}

  return 0;
}
