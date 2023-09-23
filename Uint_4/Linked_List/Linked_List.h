/*
 * Linked_List.h
 *
 *  Created on: 12 Sept 2023
 *      Author: Elsayed Ayman Habib
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

#define DPRINTF(...)   {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin); }

/* Data in node*/
struct Sdata
{
	int  ID;
	char name[40];
	float hight;
};

struct SStudent
{
	struct Sdata Student;
	struct SStudent* PNextStudent;
};

void AddStudent();
void DeleteStudent();
void viewStudents();
void DeletAll();
void GetNth(int index);
void Length();
int Length_Recursive(struct SStudent* PCurrentStudent);
void NthFromEnd(int EndIndex);
void NthFromEndTwoPointers(int EndIndex);
void MiddleNode();
void MiddleNode_Length();
void ReverseLinked();

#endif /* LINKED_LIST_H_ */
