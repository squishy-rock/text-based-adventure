#pragma once
#include "BranchChoice.h"
class BranchChoiceLinkedList
{
private:
	class LinkedListNode
	{
		friend class BranchChoiceLinkedList;
		BranchChoice value;
		LinkedListNode* next;

		LinkedListNode(BranchChoice value, LinkedListNode* next = nullptr)
		{
			this->value = value;
			this->next = next;
		}
	};

	LinkedListNode* first;
public:
	BranchChoiceLinkedList()
	{
		first = nullptr;
	}
	void add(BranchChoice item);
	void remove(BranchChoice item);
	BranchChoice get(int index);  //this command gets the item from the list, i.e. if u put 0 you get the first one 
	bool isEmpty() const;
	int size();

	//TODO finish implmenting linked list, replace vector in branch room with the new linked list, finish designing the game (files), maybe help function for user experince
};