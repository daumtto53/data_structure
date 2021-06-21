#include "./heap.h"

void	build_heap(heap_t *heap, int arr[], int n)
{
	int		i;

	if (!heap)
		return ;
	if (heap->capacity < n)
		resize_heap(heap);
	for (i = 0; i < n; i++)
		heap->arr[i] = arr[i];
	heap->size = n;
	for (i = (heap->size - 1) / 2; i >= 0; i--)
		percolate_down(heap, i);
	return ;
}
