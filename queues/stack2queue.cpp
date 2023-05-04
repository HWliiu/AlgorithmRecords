#include <iostream>
using namespace std;

class Stack
{
    int *data;
    int max_size;

public:
    int top;
    Stack(int max_size)
    {
        top = -1;
        this->max_size = max_size;
        data = new int[max_size];
    }
    ~Stack() { delete[] data; }
    void Init() { top = -1; }
    bool IsEmpty() { return top < 0; }
    bool IsFull() { return top >= max_size; }
    bool Push(int value)
    {
        if (IsFull())
            return false;
        data[++top] = value;
        return true;
    }
    bool Pop(int &value)
    {
        if (IsEmpty())
            return false;
        value = data[top--];
        return true;
    }
};

// 用两个栈模拟队列
class Queue
{
    Stack s1, s2;

public:
    Queue(int max_size) : s1(max_size), s2(max_size)
    {
    }
    bool IsEmpty() { return s1.IsEmpty() && s2.IsEmpty(); }
    bool Enqueue(int value)
    {
        if (s1.IsFull()) // 这里可以加一步判断s2为空的时，可以将s1的数据转到s2
            return false;
        s1.Push(value);
        return true;
    }
    bool Dequeue(int &value)
    {
        if (IsEmpty())
            return false;
        if (s2.IsEmpty()) // 只有s2为空时才能将s1的数据转到s2, 这样才不会破坏队列顺序
        {
            while (s1.Pop(value))
                s2.Push(value);
        }
        s2.Pop(value);
        return true;
    }
};

int main()
{
    Queue queue(5);
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