#pragma once

#include <stdexcept>
#include <iostream>

std::invalid_argument out_of_range("Index out of range");

template <typename T>
struct LinkedNode
{
    LinkedNode(T const& data) : data{data}, next(0) {}
    T data;
    LinkedNode<T>* next;

};

template <typename T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();

        void insertFirst(T const& data);

        void insert(int index, T const& data);

        void removeFirst();

        void remove(int index);

        void clear();
        
        auto getFirst();

        auto get(int index);

        bool const contains(T const& data);

        template <typename U>
        friend std::ostream& operator<<(std::ostream &os, LinkedList<U>& list);

        private:
            LinkedNode<T>* head;
};

template <typename U>
std::ostream& operator<<(std::ostream& os, LinkedList<U>& list)
{
    LinkedNode<U>* root = list.head;
    if (root)
    {
        for (;;)
        {
            os << root->data << ' ';
            
            if (root->next)
            {
                root = root->next;
            }else
            {
                return os;
            }
        }
    }

    return os;
}

template <typename T>
LinkedList<T>::LinkedList()
{
    head = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
void LinkedList<T>::clear()
{
    LinkedNode<T>* oHead = nullptr;
    while (head)
    {
        oHead = head;
        if (head->next)
        {
            head = head->next;
        }
        delete oHead;
    }
    oHead = nullptr;
}

template <typename T>
void LinkedList<T>::insertFirst(T const& data)
{
    LinkedNode<T>* temp = new LinkedNode<T>(data);
    if (head)
    {
        temp->next = head;
        head = temp;
    }else
    {
        head = temp;
    }

    temp = nullptr;
}

template<typename T>
void LinkedList<T>::insert(int index, T const& data)
{
    if (index == 0)
    {
        insertFirst(data);
    }else
    {
        if (head)
        {
        LinkedNode<T>* temp = new LinkedNode<T>(data);
        LinkedNode<T>* root = head;

        for (int i = 0; i < (index - 1); i++)
        {
            if (root->next)
            {
                root = root->next;
            }else
            {
                throw out_of_range;
            }
        }

        if (root->next)
        {
            temp->next = root->next;
        }

        root->next = temp;
        root = nullptr;
        }else
        {
            throw out_of_range;
        }
    }

    
}

template<typename T>
void LinkedList<T>::removeFirst()
{
    if (head)
    {
        LinkedNode<T>* oHead = head;
        if (head->next)
        {
            head = head->next;
        }
        delete oHead;
        oHead = nullptr;
    }
}

template<typename T>
void LinkedList<T>::remove(int index)
{
    if (index == 0)
    {
        removeFirst();
    }else
    {
        if (head)
        {
            LinkedNode<T>* root = head;

            for (int i = 0; i < (index - 1); i++)
            {
                if (root->next)
                {
                    root = root->next;
                }else
                {
                    throw out_of_range;
                }
            }

            if (root->next)
            {
                LinkedNode<T>* lead = root;
                root = root->next;

                if (root->next)
                {
                    LinkedNode<T>* oPointer = lead->next;
                    lead->next = oPointer->next;
                    delete oPointer;
                    oPointer = nullptr;
                }else
                {
                    LinkedNode<T>* oPointer = lead->next;
                    delete oPointer;
                    oPointer = nullptr;
                }
                root = nullptr;
            }
            root = nullptr;
        }else
        {
            throw out_of_range;
        }
    }
}

template<typename T>
auto LinkedList<T>::getFirst()
{
    if (head)
    {
        return head->data;
    }else
    {
        throw out_of_range;
    }
}

template<typename T>
auto LinkedList<T>::get(int index)
{
    if (index == 0)
    {
        return getFirst();
    }else
    {
        if (head)
        {
            LinkedNode<T>* root = head;

            for (int i = 0; i < index; i++)
            {
                if (root->next)
                {
                    root = root->next;
                }else
                {
                    throw out_of_range;
                }
            }
            return root->data;
        }else
        {
            throw out_of_range;
        }
    }
}

template<typename T>
bool const LinkedList<T>::contains(T const& data)
{
    if (head)
    {
        LinkedNode<T>* root = head;
        for (;;)
        {
            if (root->data == data)
            {
                return true;
            }

            if (root->next)
            {
                root = root->next;
            }else
            {
                return false;
            }
        }

    }else
    {
        return false;
    }
}