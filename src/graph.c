#include "graph.h"
#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_graph(graph* graph) {
	printf("Node Usage: %u/%u\n", graph->node_count, graph->node_size);
	printf("-- Nodes --\n");
	for (uint32_t i = 0; i < graph->node_count; i++) {
		printf("\t[%.2u] - ID: %.3u - Value: %d\n", i, graph->nodes[i]->id, graph->nodes[i]->value);
	}
	printf("\n");

	printf("-- Adjacency Matrix --\n");
	for (uint32_t i = 0; i < graph->node_count; i++) {
		for (uint32_t j = 0; j < graph->node_count; j++) {
			printf("%u ", graph->adjacency_matrix[i][j]);
		}
		printf("\n");
	}
}

graph* initialize_graph() {
	graph* g = malloc(sizeof(graph));

	g->node_size = 16;
	g->node_count = 0;
	g->nodes = (node **) calloc(g->node_size, sizeof(node *));
	for (uint32_t i = 0; i < g->node_size; i++) {
		g->nodes[i] = (node *) calloc(g->node_size, sizeof(node));
	}

	g->adjacency_matrix = (uint8_t **) calloc(g->node_size, sizeof(uint8_t *));
	for (uint32_t i = 0; i < g->node_size; i++) {
		g->adjacency_matrix[i] = (uint8_t *) calloc(g->node_size, sizeof(uint8_t));
	}

	return (g);
}

// TODO definitely going to have to use a hash table or something

// returns node_id (array index?)
// TODO definitely refactor because if you make and remove 100 nodes suddenly it's wasting memory
int _graph_add_node(graph* graph, uint32_t id, int32_t value) {
	if (graph->node_count >= graph->node_size) {
		// TODO resize nodes and adjacency matrix
	}

	graph->nodes[graph->node_count]->id = id;
	graph->nodes[graph->node_count]->value = value;
	graph->nodes[graph->node_count]->id = value;
	graph->node_count += 1;

	graph_add_edge(graph, id, id);

	return (0);
}
uint32_t graph_add_node(graph* graph, int32_t value) {
	uint32_t id = graph->node_count;

	_graph_add_node(graph, id, value);

	return (id);
}

uint32_t _get_node_index(graph* graph, uint32_t id) {
	for (uint32_t i = 0; i < graph->node_count; i++) {
		if (graph->nodes[i]->id == id) {
			return (i);
		}
	}

	return (graph->node_count);
}

// if we accept an array for nodes, we can swap the last one with the one we're removing and then it should work fine
// O(n) all day baby
// nah eventually I'll do it properly with my hash table
int graph_remove_node(graph* graph, uint32_t node_id) {
	uint32_t node_i = _get_node_index(graph, node_id);
	if (node_i == graph->node_count) {
		// TODO error
		return (-1);
	}

	// Swap the one we're removing with the last one in the array
	node* tmp = graph->nodes[node_i];
	graph->nodes[node_i] = graph->nodes[graph->node_count - 1];
	graph->nodes[graph->node_count - 1] = tmp;
	// TODO handle adjacency matrix
	// fuck me this is going to require a total rewrite

	graph->node_count -= 1;

	return (0);
}

// -1	error
// 0	success
// 1	already exists
int graph_add_edge(graph* graph, uint32_t node_id_a, uint32_t node_id_b) {
	if (graph_adjacent(graph, node_id_a, node_id_b) == 1) {
		return (1);
	}

	graph->adjacency_matrix[node_id_a][node_id_b] = 1;
	graph->adjacency_matrix[node_id_b][node_id_a] = 1;

	return (0);
}

int graph_remove_edge(graph* graph, uint32_t node_id_a, uint32_t node_id_b) {
	if (graph_adjacent(graph, node_id_a, node_id_b) == 0) {
		return (1);
	}

	graph->adjacency_matrix[node_id_a][node_id_b] = 0;
	graph->adjacency_matrix[node_id_b][node_id_a] = 0;

	return (0);
}

int graph_adjacent(graph* graph, uint32_t node_id_a, uint32_t node_id_b) {
	if (graph->adjacency_matrix[node_id_a][node_id_b] == 0) {
		return (0);
	}
	return (1);
}

// TODO
node_collection* get_neighbors(graph* graph, uint32_t node_id) {
	// TODO initialize collection
	// node_collection *neighbors = (node_collection *) malloc(sizeof(node_collection));

	for (uint32_t i = 0; i < graph->node_count; i++) {
		if (graph_adjacent(graph, node_id, i) == 1) {
			// TODO add to collection
		}
	}

	return (NULL);
}

// TODO
graph* graph_get_subgraph(graph* graph, uint32_t node_id);

void destroy_graph(graph* graph) {
	for (uint32_t i = 0; i < graph->node_count; i++) {
		free(graph->nodes[i]);
	}
	free(graph->nodes);

	for (uint32_t i = 0; i < graph->node_count; i++) {
		free(graph->adjacency_matrix[i]);
	}
	free(graph->adjacency_matrix);

	free(graph);
}
