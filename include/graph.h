#ifndef GRAPH_H
# define GRAPH_H

# include <stdint.h>

// Forward Declarations //
typedef struct s_node node;
// -------------------- //

typedef struct s_graph {
	node** nodes;
	uint32_t node_size;
	uint32_t node_count;

	uint8_t** adjacency_matrix;
} graph;

typedef struct s_node_collection {
	node* nodes;
	uint32_t node_size;
	uint32_t node_count;
} node_collection;

void print_graph(graph* graph);

graph* initialize_graph();

uint32_t graph_add_node(graph* graph, int32_t value);
int graph_remove_node(graph* graph, uint32_t node_id);

int graph_add_edge(graph* graph, uint32_t node_id_a, uint32_t node_id_b);
int graph_remove_edge(graph* graph, uint32_t node_id_a, uint32_t node_id_b);

int graph_adjacent(graph* graph, uint32_t node_id_a, uint32_t node_id_b);

node_collection* get_neighbors(graph* graph, uint32_t node_id);

graph* graph_get_subgraph(graph* graph, uint32_t node_id);

void destroy_graph(graph* graph);

#endif
