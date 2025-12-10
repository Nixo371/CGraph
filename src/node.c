#include "node.h"

int32_t node_get_value(node* node) {
	return (node->value);
}

void node_set_value(node* node, int32_t value) {
	node->value = value;
}
