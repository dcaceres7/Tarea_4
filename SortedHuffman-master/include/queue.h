#ifndef QUEUE_H
#define QUEUE_H

typedef int QueueItemType;

struct QueueNode
          {
                 QueueItemType item;
                 QueueNode *leftCursor;
                 QueueNode *rightCursor;
                 QueueNode *next;
          };

class queue
{
public:
        queue();
        ~queue();

        bool isEmpty() const;
        QueueItemType front();
        QueueItemType back();
        QueueItemType dequeue();
        QueueNode *frontNode();
        QueueNode *backNode();

        //void sortQueue(Queue& q)  throw(QueueException);
        void dequeue(QueueItemType& queueFront);
        void enqueue(const QueueItemType& newItem);
        void setCursor(QueueNode *l, QueueNode *r);

private:
          QueueNode *backPtr;
          QueueNode *frontPtr;
};
#endif // QUEUE_H
