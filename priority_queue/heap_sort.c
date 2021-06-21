#include "./heap.h"

void	heap_sort(int *arr, int n)
{
	heap_t	*heap;
	int		i;
	int		temp;
	int		k;

	heap = create_heap(n, MAX_HEAP);
	if (!heap)
		return ;
	build_heap(heap, arr, n);
	k = heap->size;
	for (i = 0; i < n; i++)
	{
		temp = heap->arr[i];
		heap->arr[i] = heap->arr[heap->size - 1];
		heap->arr[heap->size - 1] = temp;
		heap->size--;
		percolate_down(heap, 0);
	}
	heap->size = k;
}
