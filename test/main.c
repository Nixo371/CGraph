#include "graph.h"

int main() {
	graph* graph = initialize_graph();

	for (int i = 0; i < 10; i++) {
		graph_add_node(graph, i);
	}
	for (int i = 3; i < 6; i++) {
		graph_remove_node(graph, i);
	}

	graph_add_edge(graph, 0, 2);
	graph_add_edge(graph, 8, 2);
	graph_add_edge(graph, 1, 8);
	graph_add_edge(graph, 1, 9);
	graph_add_edge(graph, 0, 1);

	print_graph(graph);

	destroy_graph(graph);
}
