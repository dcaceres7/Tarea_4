#include "Test.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <sstream>
using namespace std;
#define MAX_TREE_HT 100
typedef map<char,string> result;
result res;
struct QueueNode
{
    char data;
    unsigned freq;
    struct QueueNode *left, *right;
};

struct Queue
{
    int front, rear;
    int capacity;
    struct QueueNode **array;
};

struct QueueNode* newNode(char data, unsigned freq)
{
    struct QueueNode* temp =(struct QueueNode*) malloc(sizeof(struct QueueNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;
    queue->array =
      (struct QueueNode**) malloc(queue->capacity * sizeof(struct QueueNode*));
    return queue;
}

int isSizeOne(struct Queue* queue)
{
    return queue->front == queue->rear && queue->front != -1;
}

int isEmpty(struct Queue* queue)
{
    return queue->front == -1;
}

int isFull(struct Queue* queue)
{
    return queue->rear == queue->capacity - 1;
}

void enQueue(struct Queue* queue, struct QueueNode* item)
{
    if (isFull(queue))
        return;
    queue->array[++queue->rear] = item;
    if (queue->front == -1)
        ++queue->front;
}

struct QueueNode* deQueue(struct Queue* queue)
{
    if (isEmpty(queue))
        return NULL;
    struct QueueNode* temp = queue->array[queue->front];
    if (queue->front == queue->rear)          queue->front = queue->rear = -1;
    else
        ++queue->front;
    return temp;
}

struct QueueNode* getFront(struct Queue* queue)
{
    if (isEmpty(queue))
        return NULL;
    return queue->array[queue->front];
}

/* A function to get minimum item from two queues */
struct QueueNode* findMin(struct Queue* firstQueue, struct Queue* secondQueue)
{
        if (isEmpty(firstQueue))
        return deQueue(secondQueue);

        if (isEmpty(secondQueue))
        return deQueue(firstQueue);

        if (getFront(firstQueue)->freq < getFront(secondQueue)->freq)
        return deQueue(firstQueue);

    return deQueue(secondQueue);
}

int isLeaf(struct QueueNode* root)
{
    return !(root->left) && !(root->right) ;
}



struct QueueNode* buildHuffmanTree(vector<char> data, vector<int> freq, int size)
{
    struct QueueNode *left, *right, *top;

    struct Queue* firstQueue  = createQueue(size);
    struct Queue* secondQueue = createQueue(size);

    for (int i = 0; i < size; ++i)
        enQueue(firstQueue, newNode(data[i], freq[i]));

    while (!(isEmpty(firstQueue) && isSizeOne(secondQueue)))
    {
        left = findMin(firstQueue, secondQueue);
        right = findMin(firstQueue, secondQueue);

        top = newNode('$' , left->freq + right->freq);
        top->left = left;
        top->right = right;
        enQueue(secondQueue, top);
    }

    return deQueue(secondQueue);
}

void printCodes(struct QueueNode* root, vector<int> arr, int top)
{
        if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

        if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

            if (isLeaf(root))
    {

                int i;
        string temp="";
        for (i = 0; i < top; ++i)
            temp += static_cast<std::ostringstream*>(&(std::ostringstream() << arr[i]))->str();;
        res[root->data] = temp;
            }
}


void HuffmanCodes(vector<char> data, vector<int> freq, int size)
{
      struct QueueNode* root = buildHuffmanTree(data, freq, size);

      int arr[MAX_TREE_HT];
   vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
   int top = 0;
   printCodes(root, vec, top);
}



map<char,string> getHuffman(vector<char> characters, vector<int> frequencies)
{
    HuffmanCodes(characters, frequencies, characters.size());
    result::iterator pos;
    return res;
}

int main ()
{
    test();
    return 0;
}
