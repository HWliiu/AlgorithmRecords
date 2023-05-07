#include <iostream>
using namespace std;

class Queue
{
    int max_size;
    int *data;

public:
    int front, rear;
    Queue(int max_size) : front(0), rear(0), max_size(max_size)
    {
        data = new int[this->max_size]{0};
    }
    ~Queue() { delete[] data; }
    void init()
    {
        front = rear = 0;
    }
    bool IsEmpty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }
    int Size()
    {
        return (rear + max_size - front) % max_size;
    }
    bool IsFull()
    {
        if (((rear + 1) % max_size) == front) // 牺牲一个单元来区分队空和队满
            return true;
        else
            return false;
    }
    bool Enqueue(int value)
    {
        if (IsFull())
            return false;
        this->data[rear] = value;
        rear = (rear + 1) % max_size;
        return true;
    }
    bool Dequeue(int &value)
    {
        if (IsEmpty())
            return false;
        value = this->data[front];
        front = (front + 1) % max_size;
        return true;
    }
};

class QueueWTag
{
    int max_size;
    int *data;
    bool tag; // 用tag区分队满和队空

public:
    int front, rear;
    QueueWTag(int size) : front(0), rear(0), max_size(size)
    {
        data = new int[this->max_size]{0};
    }
    ~QueueWTag() { delete[] data; }
    void init()
    {
        front = rear = 0;
        tag = false;
    }
    int Size()
    {
        return (rear + max_size - front) % max_size;
    }
    bool IsEmpty()
    {
        if (front == rear && tag == 0)
            return true;
        else
            return false;
    }
    bool IsFull()
    {
        if (front == rear && tag == 1)
            return true;
        else
            return false;
    }
    bool Enqueue(int value)
    {
        if (IsFull())
            return false;
        this->data[rear] = value;
        rear = (rear + 1) % max_size;
        tag = 1; // 只有执行了入队操作才可能队满
        return true;
    }
    bool Dequeue(int &value)
    {
        if (IsEmpty())
            return false;
        value = this->data[front];
        front = (front + 1) % max_size;
        tag = 0; // 只有执行了出队操作才可能队空
        return true;
    }
};

int main()
{
    QueueWTag queue(5);
    int value;
    queue.Enqueue(0);
    queue.Dequeue(value);
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Dequeue(value);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Dequeue(value);
    queue.Dequeue(value);
    queue.Dequeue(value);
    queue.Enqueue(5);
    queue.Enqueue(6);

    while (queue.Dequeue(value))
        cout << value << " ";
    cout << endl;
}