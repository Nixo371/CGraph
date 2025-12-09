#include "graph.h"

int main() {
	graph* graph = initialize_graph();

	for (int i = 0; i < 10; i++) {
		graph_add_node(graph, i);
	}

	graph_add_edge(graph, 0, 3);
	graph_add_edge(graph, 8, 2);
	graph_add_edge(graph, 1, 4);
	graph_add_edge(graph, 1, 3);
	graph_add_edge(graph, 6, 5);
	graph_add_edge(graph, 0, 1);

	print_graph(graph);

	destroy_graph(graph);
}
