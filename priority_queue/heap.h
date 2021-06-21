#ifndef HEAP_H
# define HEAP_H

# define MAX_HEAP	0
# define MIN_HEAP	1

typedef struct	heap_s
{
	int		heap_type;
	int		size;
	int		capacity;
	int		*arr;
}				heap_t;

heap_t	*create_heap(int heap_size, int heap_type);

int		heap_parent_index(heap_t *heap, int child);
int		heap_left_child_index(heap_t *heap, int parent);
int		heap_right_child_index(heap_t *heap, int parent);

int		heap_delete_max(heap_t *heap);
void	percolate_down(heap_t *heap, int i);
void	delete_heap(heap_t *heap);

int		insert_heap(heap_t *heap, int data);
int		resize_heap(heap_t *heap);

void	build_heap(heap_t *heap, int arr[], int n);

#endif
