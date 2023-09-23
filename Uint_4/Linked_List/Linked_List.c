/*
 * Linked_List.c
 *
 *  Created on: 12 Sept 2023
 *      Author: Elsayed Ayman Habib
 */

#include "Linked_List.h"

struct SStudent* gPFirstStudent = NULL;

void AddStudent()
{
	struct SStudent* PnewStudent;
	struct SStudent* PlastStudent;
	char temp[40];
	/* Check list is empty */

	if (gPFirstStudent == NULL)
	{
		PnewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));
		gPFirstStudent = PnewStudent;
	}
	/* list contains records */
	else
	{
		/* navigate until reach to the last record*/
		PlastStudent = gPFirstStudent ;
		while(PlastStudent->PNextStudent)
		{
			PlastStudent = PlastStudent->PNextStudent;
		}
		PnewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));
		if(PnewStudent)
		{
			PlastStudent->PNextStudent = PnewStudent ;

		}
	}
	/* fill new record */
	DPRINTF("\n Enter the ID");
	gets(temp);
	PnewStudent->Student.ID = atoi(temp);

	DPRINTF("\n Enter the studet full name");
	gets(PnewStudent->Student.name);

	DPRINTF("\n Enter the hight");
	gets(temp);
	PnewStudent->Student.hight = atof(temp);

	/* set the next pointer is null */
	PnewStudent->PNextStudent = NULL;

}

void DeleteStudent()
{

	char temp[40];
	int selected_id;

	DPRINTF("\n Enter the ID to be deleted: ");
	gets(temp);
	selected_id= atoi(temp);

	/* list is not empty */

	if(gPFirstStudent )
	{
		struct SStudent* PSelectedStudent = gPFirstStudent;
		struct SStudent* PPrevStudent = NULL;

		/* loop on all records */
		while(PSelectedStudent)
		{
			if (PSelectedStudent->Student.ID == selected_id)
			{
				if (PPrevStudent) /* the first student is not the selected line */
				{
					PPrevStudent->PNextStudent = PSelectedStudent->PNextStudent;
				}
				else /* the first one is match with id */
				{
					gPFirstStudent = PSelectedStudent->PNextStudent;
				}
				free(PSelectedStudent);
			}
			PPrevStudent = PSelectedStudent;
			PSelectedStudent = PSelectedStudent->PNextStudent;
		}
		DPRINTF("\n cant't find the student id");
	}
}

void viewStudents()
{
	struct SStudent* PCurrentStudent = gPFirstStudent;
	int i = 1;
	if (gPFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		while (PCurrentStudent)
		{
			DPRINTF("\n ID of the %d student: %d",i ,PCurrentStudent->Student.ID );
			DPRINTF("\n the name of the %d student: %s" ,i ,PCurrentStudent->Student.name);
			DPRINTF("\n the hight of the %d student: %f" ,i ,PCurrentStudent->Student.hight);
			PCurrentStudent = PCurrentStudent->PNextStudent;
			i++;
		}
	}
}

void DeletAll()
{
	struct SStudent* PCurrentStudent = gPFirstStudent;
	if (gPFirstStudent == NULL)
	{
		DPRINTF("\n Empty list");
	}
	else
	{
		while (PCurrentStudent )
		{
			struct SStudent* PtempStudent = PCurrentStudent ;
			PCurrentStudent = PCurrentStudent->PNextStudent;
			free(PtempStudent);
		}
		gPFirstStudent = NULL;
	}
}

void GetNth(int index)
{
	int count = 0;
	struct SStudent* PCurrentStudent = gPFirstStudent;
	while(PCurrentStudent)
	{
		if (count == index)
		{
			DPRINTF("\n ID of the %d student: %d",count ,PCurrentStudent->Student.ID );
			DPRINTF("\n the name of the %d student: %s" ,count ,PCurrentStudent->Student.name);
			DPRINTF("\n the hight of the %d student: %f" ,count ,PCurrentStudent->Student.hight);
			break;
		}
		else
		{
			count++;
			PCurrentStudent = PCurrentStudent->PNextStudent;
		}
	}
}

void Length()
{
	int count = 0;
	struct SStudent* PCurrentStudent = gPFirstStudent;
	while(PCurrentStudent)
	{
		count++;
		PCurrentStudent = PCurrentStudent->PNextStudent;
	}
	DPRINTF("\n Length of the This Linked List: %d" ,count);
}

int Length_Recursive(struct SStudent* PCurrentStudent)
{
	if(PCurrentStudent)
	{
		return (1 + Length_Recursive(PCurrentStudent->PNextStudent));
	}
	else
	{
		return 0;
	}
	DPRINTF("\n Length of the This Linked List: %d" ,Length_Recursive(PCurrentStudent->PNextStudent));
}

void NthFromEnd(int EndIndex)
{
	int length;
	int count = 0;
	struct SStudent* PCurrentStudent = gPFirstStudent;
	length = Length_Recursive(PCurrentStudent);
	while((length - EndIndex) != count)
	{
		count++;
		PCurrentStudent = PCurrentStudent->PNextStudent;
	}
	DPRINTF("\n ID of the %d student: %d",count ,PCurrentStudent->Student.ID );
	DPRINTF("\n the name of the %d student: %s" ,count ,PCurrentStudent->Student.name);
	DPRINTF("\n the hight of the %d student: %f" ,count ,PCurrentStudent->Student.hight);
}

void NthFromEndTwoPointers(int EndIndex)
{
	int count1 = 0;
	int count2 = 0;
	struct SStudent* PCurrentStudent = gPFirstStudent;
	struct SStudent* PTempStudent = gPFirstStudent;
	while(PCurrentStudent)
	{
		count1++;
		PCurrentStudent = PCurrentStudent->PNextStudent;
	}
	while(count2 != (count1 - EndIndex))
	{
		count2++;
		PTempStudent = PTempStudent->PNextStudent;
	}
	DPRINTF("\n ID of the %d student: %d",(count1 - EndIndex) ,PTempStudent->Student.ID );
	DPRINTF("\n the name of the %d student: %s" ,(count1 - EndIndex) ,PTempStudent->Student.name);
	DPRINTF("\n the hight of the %d student: %f" ,(count1 - EndIndex) ,PTempStudent->Student.hight);
}

/* feha mo4kela an el plus bta3 el even m4 mazbot */
void MiddleNode()
{
	int count=0;
	struct SStudent* PSlowStudent = gPFirstStudent;
	struct SStudent* PFastStudent = gPFirstStudent;

	while(PFastStudent)
	{
		count++;
		PSlowStudent = PSlowStudent->PNextStudent;
		PFastStudent = PFastStudent->PNextStudent;
		if (PFastStudent != NULL)
		{
			PFastStudent = PFastStudent->PNextStudent;
		}
	}
	DPRINTF("\n ID of the %d student: %d",count ,PSlowStudent->Student.ID );
	DPRINTF("\n the name of the %d student: %s" ,count ,PSlowStudent->Student.name);
	DPRINTF("\n the hight of the %d student: %f" ,count ,PSlowStudent->Student.hight);
}

void MiddleNode_Length()
{
	int length;
	int count = 0;
	struct SStudent* PCurrentStudent = gPFirstStudent;
	length = Length_Recursive(PCurrentStudent);
	if ((length %2) == 0)
	{
		length++;
	}
	while((length /2) != count)
	{
		count++;
		PCurrentStudent = PCurrentStudent->PNextStudent;
	}
	DPRINTF("\n ID of the %d student: %d",count ,PCurrentStudent->Student.ID );
	DPRINTF("\n the name of the %d student: %s" ,count ,PCurrentStudent->Student.name);
	DPRINTF("\n the hight of the %d student: %f" ,count ,PCurrentStudent->Student.hight);
}

void ReverseLinked()
{
	struct SStudent* PHeadStudent = NULL;
	struct SStudent* PLastStudent = gPFirstStudent;
	struct SStudent* PCurrentStudent = gPFirstStudent;
	while(PCurrentStudent)
	{
		PLastStudent = PCurrentStudent->PNextStudent;
		PCurrentStudent->PNextStudent = PHeadStudent;
		PHeadStudent = PCurrentStudent;
		PCurrentStudent = PLastStudent;
	}
	gPFirstStudent = PHeadStudent;
	viewStudents();
}
