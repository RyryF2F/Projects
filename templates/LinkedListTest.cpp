#include <iostream>
#include <string>
#include "LinkedList.hpp"

typedef std::string T; //will not verify if datatype is valid for this particular test

int getIndex();
T getData();

int main()
{
    LinkedList<T> list;

    int option = 0;

    do
    {  
        std::cout << std::endl;
        std::cout << " Linked List Manager " << std::endl
                  << " -------------------" << std::endl
                  << " 1 - Insert First" << std::endl
                  << " 2 - Insert (index)" << std::endl
                  << " 3 - Remove First" << std::endl
                  << " 4 - Remove (index)" << std::endl
                  << " 5 - Get First" << std::endl
                  << " 6 - Get (index)" << std::endl
                  << " 7 - Contains" << std::endl
                  << " 8 - Print List" << std::endl
                  << " 9 - clear (reset list)" << std::endl
                  << " 0 - EXIT" << std::endl
                  << "Enter Command: ";
        std::cin >> option;
        
        switch(option)
        {
            case 0:
                break;

            case 1:
            {
                T data = getData();
                list.insertFirst(data);
                break;
            }
            case 2:
            {
                int ind = getIndex();
                T data = getData();
                list.insert(ind,data);
                break;
            }
            case 3:
            {
                list.removeFirst();
                break;
            }
            case 4:
            {
                int ind = getIndex();
                list.remove(ind);
                break;
            }
            case 5:
            {
                std::cout << list.getFirst() << std::endl;
                break;
            }
            case 6:
            {
                int ind = getIndex();
                std::cout << list.get(ind) << std::endl;
                break;
            }
            case 7:
            {
                T data = getData();
                bool contains = list.contains(data);
                std::string out = (contains) ? "Data found." : "Data not found.";
                std::cout << out << std::endl;
                break;
            }
            case 8:
            {
                std::cout << list << std::endl;
                break;
            }
            case 9:
            {
                list.clear();
                break;
            }
            default:
            {
                std::cout << "Invalid command, try again!" << std::endl;
                option = 999;
                break;
            }
        }

    } while (option > 0);
    

    return 0;
}

int getIndex()
{
    int ind;
    std::cout << "Enter Index: ";
    std::cin >> ind;
    return ind;
}

T getData()
{
    T data;
    std::cout << "Enter Data: ";
    std::cin >> data;
    return data;
}