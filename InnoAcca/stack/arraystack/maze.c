#include "stack.h"
#include <stdio.h>

int map[8][8] = {{0,  0,  1,  1,  1,  1,  1,  1},
	{1, 0,  0,  0,  0,  0,  0,  1},
	{1,  1,  1,  0,  1,  1,  1,  1},
	{1, 1,  1,  0,  1,  1,  1,  1},
	{1,  0,  0,  0,  0,  0,  0,  1},
	{1,  0,  1,  1,  1,  1,  1,  1},
	{1,  0,  0,  0,  0,  0,  0,  0},
	{1,  1,  1,  1,  1,  1,  1,  0}};

int offset[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int	is_in_boundary(int x, int y)
{
	return ((0 <= x && x < 8) && (0 <= y && y < 8));
}

int	is_visited(int map[][8], int x, int y)
{
	return (map[y][x]);
}

void print_map(int map[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}

int main()
{
	StackNode	*x_node;
	StackNode	*y_node;

	ArrayStack	*x_stack = createArrayStack(8 * 8);
	ArrayStack	*y_stack = createArrayStack(8 * 8);

	int x, y;
	int nextx, nexty;
	int	step;
	int	flag;

	x_node = malloc(sizeof(StackNode));
	y_node = malloc(sizeof(StackNode));
	x = 0;	y = 0;
	x_node->data = x;	y_node->data = y;
	pushAS(x_stack, x_node);	pushAS(y_stack, y_node);
	while (!isArrayStackEmpty(x_stack) && !isArrayStackEmpty(y_stack))
	{
		flag = 0;
		x = popAS(x_stack)->data;		y = popAS(y_stack)->data;
		printf("%d %d -> ", x, y);
		map[y][x] = -1;
		if (x == 7 && y == 7)
			break;
		for (int i = 0; i < 4; i++)
		{
			nextx = x + offset[i][0];
			nexty = y + offset[i][1];
			if (is_in_boundary(nextx, nexty) && !is_visited(map, nextx, nexty))
			{
				x_node = malloc(sizeof(StackNode));		y_node = malloc(sizeof(StackNode));
				x_node->data = nextx;					y_node->data = nexty;
				pushAS(x_stack, x_node);				pushAS(y_stack, y_node);
				flag++;
			}
		}
	}
	printf("%d %d\n", x, y);
	if (x != 7 && y != 7)
		printf("\n----------NO Route--------\n");
	else
		printf("\n-------Found Route------\n");

	print_map(map);
	exit(0);
}
