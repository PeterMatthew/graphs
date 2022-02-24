#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dijkstra(vii adj_list[], int s, int n) {
	priority_queue<ii, vii, greater<ii>> queue_p;

	vector<int> dist;
	vector<bool> visited_list;
	ii u;

  dist.assign(n, INT_MAX);
	visited_list.assign(n, false);
	dist[s] = 0;
	queue_p.push(make_pair(dist[s], s));

	while(!queue_p.empty()) {
		int v = queue_p.top().second;
		queue_p.pop();

		if(visited_list[v])continue;
		visited_list[v] = true;

		for(int i = 0; i < adj_list[v].size(); i++) {
			u = adj_list[v][i];

			if(dist[v]+u.second < dist[u.first]) {
				dist[u.first] = dist[v]+u.second;
				queue_p.push(make_pair(dist[u.first], u.first));
			}
		}
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
		dist = dijkstra(adj_list, begin_vertex, v+1);
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
