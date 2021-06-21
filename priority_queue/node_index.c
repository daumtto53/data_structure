#include "./heap.h"

int		heap_parent_index(heap_t *heap, int child)
{
	int		parent_i;

	if (!heap)
		return (-1);
	parent_i = (child - 1) / 2;
	if (parent_i < 0)
		return (-1);
	return (parent_i);
}

int		heap_left_child_index(heap_t *heap, int parent)
{
	int		child_i;

	if (!heap)
		return (-1);
	child_i = parent * 2 + 1;
	if (child_i > heap->size - 1)
		return (-1);
	return (child_i);
}

int		heap_right_child_index(heap_t *heap, int parent)
{
	int		child_i;

	if (!heap)
		return (-1);
	child_i = parent * 2 + 2;
	if (child_i > heap->size - 1)
		return (-1);
	return (child_i);
}
