#ifndef NODE_H
# define NODE_H

# include <stdint.h>

typedef struct s_node {
	uint32_t id;
	int32_t value;
} node;

int32_t node_get_value(node* node);
void node_set_value(node* node, int32_t value);

#endif
