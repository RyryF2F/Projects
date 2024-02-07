CXX = g++
CXXFLAGS = -std=c++20 -Wall -g
# Targets needed to bring the executable up to date

all: linkedlist

linkedlist: build/linkedlist.o
	$(CXX) $(CXXFLAGS) -o LinkedList build/linkedlist.o
# The main.o target can be written more simply

build/linkedlist.o: LinkedListTest.cpp LinkedList.hpp
	$(CXX) $(CXXFLAGS) -c LinkedListTest.cpp -o $@
	
#build/doublelinkedlist.o: DoubleLinkedListTest.hpp DoubleLinkedList.hpp
#	$(CXX) $(CXXFLAGS) -c DoubleLinkedListTest.cpp -o $@

#build/avltree.o: avltree.hpp AvlTreeTest.cpp
#	$(CXX) $(CXXFLAGS) -c AvlTreeTest.cpp -o $@