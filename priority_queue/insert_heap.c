#include "./heap.h"

int		insert_heap(heap_t *heap, int data)
{
	int		i;
	int		parent_i;

	if (!heap)
		return (-1);
	if (heap->size == heap->capacity)
	{
		if (resize_heap(heap) == -1)
			return (-1);
	}
	heap->size++;
	i = heap->size - 1;
	parent_i = heap_parent_index(heap, i);
	while (heap->arr[i] > heap->arr[parent_i])
	{
		heap->arr[parent_i] = heap->arr[i];
		i = parent_i;
	}
	heap->arr[i] = data;
	return (1);
}

int		resize_heap(heap_t *heap)
{
	int		new_capacity;
	int		*new_arr;
	int		i;

	new_capacity = heap->capacity * 2;
	if (!(new_arr = malloc(sizeof(int) * new_capacity)))
		return (-1);
	for (i = 0; i < heap->size; i++)
		new_arr[i] = heap->arr[i];
	free(heap->arr);
	heap->arr = new_arr;
	heap->capacity = new_capacity;
	return (1);
}
