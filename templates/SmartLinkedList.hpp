#pragma once

#include <memory>
#include <stdexcept>
#include <iostream>

std::invalid_argument out_of_range("Index out of range");

template <typename T>
struct LinkedNode
{
    T data;
    std::unique_ptr<LinkedNode> next;
    LinkedNode(T data) : data{data}, next{nullptr} {}
};

template <typename T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();

        /**
         * Inserts the specified element at the beginning of the list.
         * 
         * @param data element to be entered.
        */
        void insertFirst(T data);

        /**
         * Inserts the specified element at the specified position in the list.
         * 
         * @param index Index to insert element at.
         * @param data element to be entered.
        */
        void insert(int index, T data);

        /**
         * Removes the head (first element) of the list.
        */
        void removeFirst();

        /**
         * Removes the element at the specified position in this list.
         * 
         * @param index Index of element to be deleted.
        */
        void remove(int index);

        /**
         * Removes all of the elements from this list.
        */
        void clear();

        /**
         * Get the data at the specified element position in this list.
         * 
         * @param index Index of element to retrieved.
        */
        auto get(int index);

        /**
         * Get the data at the first element in this list.
        */
        auto getFirst();


        /**
         * Checks if LinkedList contains an element with given data.
         * Linear search O(n)
         * 
         * @param data data to check
        */
        bool contains(T data);

    template <typename U>
    friend std::ostream& operator<<(std::ostream &os, const LinkedList<U> &list);

    private:
        std::unique_ptr<LinkedNode<T>> head;
};

template <typename U>
std::ostream& operator<<(std::ostream &os, const LinkedList<U> &list) 
{
    LinkedNode<U> *head = list.head.get();
    while(head) 
    {
        os << head->data << ' ';
        head = head->next.get();
    }
    return os;
}

template <typename T>
LinkedList<T>::LinkedList()
{
    
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
void LinkedList<T>::clear()
{
    while(head)
    {
        head = std::move(head->next);
    }
}

template <typename T>
void LinkedList<T>::insertFirst(T data)
{
    auto temp{std::make_unique<LinkedNode<T>>(data)};

    if (head)
    {
        temp->next = std::move(head);
        head = std::move(temp);
    }else
    {
        head = std::move(temp);
    }
}

template<typename T>
void LinkedList<T>::insert(int index, T data)
{
    if (head)
    {
        if (index == 0)
        {
            insertFirst(data);
        }else
        {
            auto temp{std::make_unique<LinkedNode<T>>(data)};
            auto* root = head.get();

            for (int i = 0; i < (index - 1); i++)
            {
                if (root->next)
                {
                    root = root->next.get();
                }else
                {
                    throw out_of_range;
                }
            }
            
            if (root->next)
            {
                temp->next = std::move(root->next);
            }

            root->next = std::move(temp);
            root = nullptr;
        }
    }else
    {
        throw out_of_range;
    }
}

template<typename T>
void LinkedList<T>::removeFirst()
{
    if (head.get()->next)
    {
        auto* oldHead = head.release();
        head = std::move(oldHead->next);
        delete oldHead;
    }else
    {
        head.reset();
    }
}

template<typename T>
void LinkedList<T>::remove(int index)
{
    //check if list exists
    if (head)
    {
        if (index == 0)
        {
            removeFirst();
        }else
        {
            auto* root = head.get();

            for (int i = 0; i < (index - 1); i++)
            {
                if (root->next)
                {
                    root = root->next.get();
                }else
                {
                    throw out_of_range;
                }
            }

            if (root->next)
            {
                auto* lead = root;
                root = root->next.get(); //move root to index of target node

                //targeted node has next node
                if (root->next)
                {
                    auto* oldPointer = lead->next.release();
                    lead->next = std::move(root->next);
                    delete oldPointer;
                }else
                {
                    auto* oldPointer = lead->next.release();
                    delete oldPointer;
                }
                lead = nullptr;
            }
            root = nullptr;
        }
    }else
    {
        throw out_of_range;
    }


}

template<typename T>
auto LinkedList<T>::getFirst()
{
    if (head)
    {
        return head.get()->data;
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
            auto* root = head.get();

            for (int i = 0; i < index; i++)
            {
                if (root->next)
                {
                    root = root->next.get();
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
bool LinkedList<T>::contains(T data)
{
    if (head)
    {
        auto* root = head.get();

        for (;;)
        {
            if (root->data == data)
            {
                return true;
            }

            if (root->next)
            {
                root = root->next.get();
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