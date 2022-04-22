#pragma once
#include <exception>
using namespace std;

template<class T>
class DynamicLinkedList
{
private:
    class LinkedListNode
    {
        friend class DynamicLinkedList;
        T value;
        LinkedListNode* next;

        LinkedListNode(T value, LinkedListNode* next)
        {
            this->value = value;
            this->next = next;
        }
    };

    struct InvalidIndex : public exception
    {
        const char* what() const throw()
        {
            return "The provided index is out of bounds.";
        }
    };

    LinkedListNode* first;
public:
    DynamicLinkedList()
    {
        first = nullptr;
    }

    ~DynamicLinkedList()
    {
        clear();
    }

    void add(T value);
    void remove(T value);
    void clear();
    T get(int index);
    bool isEmpty() const;
    int size();
};



template<class T>
void DynamicLinkedList<T>::add(T value)
{
    LinkedListNode* nodeToAdd = new LinkedListNode(value, nullptr);

    if (first == nullptr)
    {
        first - nodeToAdd;
    }
    else
    {
        LinkedListNode* temp = first;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nodeToAdd;
    }
}

template<class T>
void DynamicLinkedList<T>::remove(T value)
{
    if (first != nullptr && first->value == value)
    {
        LinkedListNode* next = first->next;
        delete first;
        first = next;
    }
    else
    {
        LinkedListNode* temp = first;
        LinkedListNode* prevNode = nullptr;
        while (temp != nullptr)
        {
            if (temp->value == value)
            {
                prevNode->next = temp->next;
                delete prevNode;
            }

            prevNode = temp;
            temp = temp->next;
        }
    }
}

template<class T>
void DynamicLinkedList<T>::clear()
{
    LinkedListNode* currNode = first;
    LinkedListNode* temp;
    while (currNode != nullptr)
    {
        temp = currNode->next;
        delete currNode;
        currNode = temp;
    }
}

template<class T>
T DynamicLinkedList<T>::get(int index)
{
    int listSize = size();
    if (index < 0 || index >= listSize)
    {
        throw InvalidIndex();
    }
    int currIndex = 0;
    LinkedListNode* temp = first;
    for (int i = 1; i <= index; i++)
    {
        temp = temp->next;
    }
    return temp->value;
}

template<class T>
bool DynamicLinkedList<T>::isEmpty() const
{
    return first == nullptr;
}

template<class T>
int DynamicLinkedList<T>::size()
{
    int size = 0;

    LinkedListNode* temp = first;
    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }

    return size;
}
