/*
 * Teodor-Constantin Popescu <teodor.popescu0710@gmail.com>
 */

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int kMaxEdges = 1000000;

void GIVE_VERDICT(float points, const char *msg, ...) {
	va_list ap;
	va_start(ap, msg);

	FILE *f;

	f = fopen("score.verif", "wt");
	fprintf(f, "%.2f", points);
	fclose(f);

	f = fopen("output.verif", "wt");
	vfprintf(f, msg, ap);
	fclose(f);

	va_end(ap);

	exit(0);
}

vector<vector<int> > readGraph(FILE *file, int n_vertices, int n_edges) {
	vector<vector<int> > G(n_vertices + 1);
	for (int i = 0; i < n_edges; ++i) {
		int x, y;
		fscanf(file, "%d %d", &x, &y);
		if (x > n_vertices || y > n_vertices || x <= 0 || y <= 0) {
			GIVE_VERDICT(0, "WA");
		}
		G[x].push_back(y);
		G[y].push_back(x);
	}
	return std::move(G);
}

vector<int> computeDistances(vector<vector<int> > &graph, int x) {
	int n_vertices = graph.size() - 1;
	vector<int> D(n_vertices + 1, -1);
	queue<int> Q;
	Q.push(x);
	D[x] = 0;
	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		for (int y : graph[x]) {
			if (D[y] != -1) continue;
			D[y] = D[x] + 1;
			Q.push(y);
		}
	}
	return std::move(D);
}

vector<int> readDistances(FILE *file, int n_vertices) {
	vector<int> D(n_vertices + 1);
	for (int i = 1; i <= n_vertices; ++i) {
		fscanf(file, "%d", &D[i]);
	}
	return std::move(D);
}

int main(int argc, char **argv) {
	if(argc != 5) {
		GIVE_VERDICT(0, "Usage ./verif input_file output_file ref_file points");
	}
	float points = atof(argv[4]);

	// Open all the needed files
	FILE *file_in = fopen(argv[1], "rt");
	FILE *file_out = fopen(argv[2], "rt");
	FILE *file_ref = fopen(argv[3], "rt");
	if (file_in == NULL) {
		GIVE_VERDICT(0, "Nu exista fisier de intrare.");
	}
	if (file_out == NULL) {
		GIVE_VERDICT(0, "Nu exista fisier de output.");
	}
	if (file_ref == NULL) {
		GIVE_VERDICT(0, "Nu exista fisier de referinta.");
	}

	// Check if an answer should exist or not
	int does_answer_exist;
	fscanf(file_ref, "%d", &does_answer_exist);

	// Read basic informations regardint the graph
	int n_edges, n_vertices;
	fscanf(file_out, "%d", &n_edges);
	if (!does_answer_exist) {
		if (n_edges == -1) GIVE_VERDICT(points, "OK");
		else GIVE_VERDICT(0, "WA");
	}
	if (n_edges < 0) {
		GIVE_VERDICT(0, "WA");
	}
	if (n_edges > kMaxEdges) {
		GIVE_VERDICT(0, "Numar prea mare de muchii.");
	}
	fscanf(file_in, "%d", &n_vertices);

	// Read the graph and what the distances from vertex 1 should be
	auto graph = readGraph(file_out, n_vertices, n_edges);
	auto correct_distances = readDistances(file_in, n_vertices);
	auto given_distances = computeDistances(graph, 1);

	for (int i = 1; i <= n_vertices; ++i) {
		if (correct_distances[i] != given_distances[i]) {
			GIVE_VERDICT(0, "Distanta obtinuta pana la %d este %d "
			             "(corect ar fi %d).", i, given_distances[i],
						 correct_distances[i]);
		}
	}

	GIVE_VERDICT(points, "OK");

	return 0;
}
