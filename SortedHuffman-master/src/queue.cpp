#include "queue.h"

queue::queue()
{
    //ctor
}

queue::~queue()
{
    //dtor
}

void queue::HuffmanEncoding (Queue& q1, Queue& q2)
{/*
input - an initial sorted queue q1 of the frequencies of each character
output - a sorted list q2 composed where every node is the sum of two elements
         in q1 and has cursors in each one of these.
*/

QueueNode *leftChild, *rightChild, *tempNode;

q1.enqueue(q1.dequeue());
q2.enqueue(q1.front()+q1.back());
rightChild = q1.backNode();
q1.enqueue(q1.dequeue());
leftChild = q1.backNode();

q2.setCursor(leftChild, rightChild);


while (q1.back() <= q1.front())
{//@pre: q1 has all the elements sorted
//@post: all elements in q1 will be back in place with each of them referenced
//       by elements in q2
	q2.enqueue( q1.front()+q2.front() );
	tempNode = q2.backNode();
	q2.enqueue(q2.dequeue());
	tempNode->rightCursor = q2.backNode();

	q1.enqueue(q1.dequeue());
	tempNode->leftCursor = q1.backNode();

	while( q2.frontNode() != tempNode)
		q2.enqueue(q2.dequeue());
	tempNode = NULL;
}

}
