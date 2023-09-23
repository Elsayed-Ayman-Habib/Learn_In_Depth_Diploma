/*
 * main.c
 *
 *  Created on: 11 Aug 2023
 *      Author: Elsayed Ayman Habib
 */

#include "Linked_List.h"

extern struct SStudent* gPFirstStudent;

int main(void)
{

	char temp_text[40];
	int index;
	int EndIndex;
	int length;
	while(1)
	{
		DPRINTF("\n=========================");
		DPRINTF("\n\t Choose on of the following Options \n");
		DPRINTF("\n 1: AddStudent: ");
		DPRINTF("\n 2: Delete_Student: ");
		DPRINTF("\n 3: view_students: ");
		DPRINTF("\n 4: DeleteAll: ");
		DPRINTF("\n 5: GetNth: ");
		DPRINTF("\n 6: Length of the linked list: ");
		DPRINTF("\n 7: Length of the linked list with Recursive: ");
		DPRINTF("\n 8: GetNthFromEnd: ");
		DPRINTF("\n 9: GetNthFromEndTwoPointers: ");
		DPRINTF("\n 10: Middel_Node: ");
		DPRINTF("\n 11: MiddelNode_Length: ");
		DPRINTF("\n 12: reverse a linked: ");
		DPRINTF("\n Enter Option Number: ");

		gets (temp_text);
		DPRINTF("\n=========================");
		switch (atoi(temp_text))
		{
		case 1:
			AddStudent();
			break;
		case 2:
			DeleteStudent();
			break;
		case 3:
			viewStudents();
			break;
		case 4:
			DeletAll();
			break;
		case 5:
			DPRINTF("\n Enter the index:");
			fflush(stdin); fflush(stdout);
			scanf("%d",&index);
			GetNth(index);
			break;
		case 6:
			Length();
			break;
		case 7:
			struct SStudent* PCurrentStudent = gPFirstStudent;
			length = Length_Recursive(PCurrentStudent);
			DPRINTF("\n Length of the This Linked List: %d" ,length);
			break;
		case 8:
			DPRINTF("\n Enter the index from end:");
			fflush(stdin); fflush(stdout);
			scanf("%d",&EndIndex);
			NthFromEnd(EndIndex);
			break;
		case 9:
			DPRINTF("\n Enter the index from end:");
			fflush(stdin); fflush(stdout);
			scanf("%d",&EndIndex);
			NthFromEndTwoPointers(EndIndex);
			break;
		case 10:
			MiddleNode();
			break;
		case 11:
			MiddleNode_Length();
			break;
		case 12:
			ReverseLinked();
			break;

		default:
			DPRINTF("\n wrong option ");
			break;
		}
	}
	return 0;
}
