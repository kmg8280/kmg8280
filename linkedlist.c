#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct listNode *listPointer;
typedef struct listNode{
	int data;
	listPointer link;
};
void insert_in_order(listPointer *first, int item)
{
	listPointer new_node = malloc(sizeof(listPointer));
	new_node->data = item;
	new_node->link = NULL;
	if (*first == NULL){
		(*first) = new_node;
	}
	else
	{
		listPointer now_node = (*first);
		while (now_node != NULL){
			if (now_node->link == NULL)
			{
				now_node->link = new_node;
				break;
			}
			if (now_node->link->data > item)
			{
				listPointer temp = malloc(sizeof(listPointer));
				temp = now_node->link;
				now_node->link = new_node;
				new_node->link = temp;
				break;
			}
			else
			{
				now_node = now_node->link;
			}
		}
	}
	printf("저장이 완료되었습니다\n\n");
	return;
}
void delete_node(listPointer *first, int item)
{
	listPointer temp = first;
	listPointer next_node = NULL;
	if (*first == NULL)
	{
		printf("링크드 리스트가 비어있습니다!\n\n");
		return;
	}
	if ((*first)->data == item)
	{
		printf("삭제가 완료되었습니다.\n\n");
		(*first) = (*first)->link;
		free(temp);
		return;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->data == item)
			{
				next_node->link = temp->link;
				free(temp);
				printf("삭제가 완료되었습니다.\n\n");
				return;
			}
		}
		next_node = temp;
		temp = temp->link;
	}
	printf("삭제할려는 값이 링크드리스트에 존재하지 않습니다.\n\n");
}
void print_linked_list(listPointer *first, int type)
{ // type에 따라서 역방향인지 정방향인지 판단.
	int p[10000];
	int index = 0;
	if (first == NULL)
	{
		printf("링크드리스트가 비었습니다.\n\n");
		return;
	}
	listPointer check = *first;
	while (check != NULL)
	{
		p[index++] = check->data;
		check = check->link;
	}
	if (type == 3) // 정
	{
		for (int i = 0; i < index; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else if (type == 4) // 역
	{
		for (int i = index-1; i >= 0; i--)
			printf("%d ", p[i]);
		printf("\n");
	}
}
int main()
{
	listPointer first = NULL;
	int type, x;
	while (1){
		printf("다음 기능 중에 선택하세요.\n");
		printf("1.추가 2.삭제 3.출력 4.역순출력 5.종료\n입력 : ");
		scanf("%d", &type);
		if (1 <= type <= 5)
		{
			switch(type)
			{
			case 1:
				printf("추가 할 숫자를 입력해 주세요 : ");
				scanf("%d", &x);
				insert_in_order(&first, x);
				break;
			case 2:
				printf("삭제 할 숫자를 입력해 주세요 : ");
				scanf("%d", &x);
				delete_node(&first, x);
				break;
			case 3:
				print_linked_list(&first, 3);
				break;
			case 4:
				print_linked_list(&first, 4);
				break;
			case 5:
				printf("프로그램을 종료합니다.\n");
				break;
			default:
				break;
			}
		}
		else
		{
			printf("기능에 명시된 번호만 입력해주세요!\n");
			continue;
		}
	}
	return 0;
}
