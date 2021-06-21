#include "./heap.h"

int		heap_delete_max(heap_t *heap)
{
	int		ret_value;

	if (!heap || heap->size == 0)
		return (-1);
	ret_value = heap->arr[0];
	heap->arr[0] = heap->arr[heap->size - 1];
	heap->size--;
	percolate_down(heap, 0);
	return (ret_value);
}

void	percolate_down(heap_t *heap, int i)
{
	int		temp;
	int		max_i;
	int		left_i;
	int		right_i;

	if (!heap)
		return ;
	left_i = heap_left_child_index(heap, i);
	right_i = heap_right_child_index(heap, i);
	if (left_i != -1 && heap->arr[left_i] > heap->arr[i])
		max_i = left_i;
	else
		max_i = i;
	if (right_i != -1 && heap->arr[right_i] > heap->arr[max_i])
		max_i = right_i;
	if (max_i == i)		//do nothing when heap is in right order
		return ;
	temp = heap->arr[max_i]; heap->arr[max_i] = heap->arr[i]; heap->arr[i] = temp;	//swap parent with max_index
	percolate_down(heap, max_i);	//percolate_down until heap property is fulfilled
	return ;
}

void	delete_heap(heap_t *heap)
{
	free(heap->arr);
	free(heap);
}
