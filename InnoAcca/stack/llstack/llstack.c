#include "stack.h"

LinkedStack* createLinkedStack(int max)
{
	LinkedStack *stack;

	stack = malloc(sizeof(LinkedStack));
	stack->maxElementCount = max;
	stack->currentElementCount = 0;
	stack->pTopElement = createLinkedList();
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	if (!pStack)
		return -1;
	if (isLinkedStackFull(pStack))
		return -1;
	addLLElement(pStack->pTopElement, 0, element);
	pStack->currentElementCount++;
}

StackNode* popLS(LinkedStack* pStack)
{
	if (!pStack)
		return -1;
	if (isLinkedStackEmpty(pStack))
		return -1;
	pStack->currentElementCount--;
	return (getLLElement(pStack->pTopElement, 0));
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (!pStack)
		return -1;
	if (isLinkedStackEmpty(pStack))
		return -1;
	return (getLLElement(pStack->pTopElement, 0));
}

void deleteLinkedStack(LinkedStack* pStack)
{
	deleteLinkedList(pStack->pTopElement);
	free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack)
{
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	return (pStack->currentElementCount == 0);
}

int checkBracketMatching(char *pSource)
{
	LinkedStack *LS;
	ListNode *element;
	ListNode *curr;

	if (!pSource)
		return -1;
	LS = createLinkedStack(strlen(pSource));
	for (int i = 0; pSource[i], i++)
	{
		if (pSource[i] == '(')
		{
			element = malloc(sizeof(ListNode));
			pushAS(LS, element);
		}
		else if (pSource[i] == ')')
		{
			if (!(element = popLS(LS)))
			{
				deleteLinkedStack(LS);
				return 0;
			}
			else
				free(element);
		}
	}

}
