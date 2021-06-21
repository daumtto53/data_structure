#include "./heap.h"

heap_t	*create_heap(int heap_size, int heap_type)
{
	int		n;
	heap_t	*heap;

	n = heap_size;
	heap = (heap_t *)malloc(sizeof(heap_t));
	if (!heap)
		return (-1);
	heap->arr = (int *)malloc(sizeof(int) * n);
	if (!(heap->arr))
	{
		free(heap);
		return (-1);
	}
	heap->capacity = n;
	heap->size = 0;
	heap->heap_type = heap_type;
}
