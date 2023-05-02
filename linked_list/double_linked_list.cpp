#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next, *pre;
    Node(int x)
    {
        data = x;
        next = pre = nullptr;
    }
};

void createListF(Node *&h)
{
    int x;
    cout << "输入序列:" << endl;
    while (cin >> x)
    {
        Node *n = new Node(x);
        if (h == nullptr)
            h = n;
        else
        {
            h->pre = n;
            n->next = h;
            h = n;
        }
    }
}

void createListR(Node *&h)
{
    int x;
    Node *r;
    cout << "输入序列:" << endl;
    while (cin >> x)
    {
        Node *n = new Node(x);
        if (h == nullptr)
            h = r = n;
        else
        {
            r->next = n;
            n->pre = r;
            r = n;
        }
    }
}

void insertListR(Node *&h, int index, int value)
{
    // TODO: 获取链表长度， 判断 index 范围
    Node *n = new Node(value), *p = h;
    for (int i = 0; p->next && i < index; i++)
        p = p->next;
    if (index < 0)
    {
        n->next = p;
        p->pre = n;
        h = n;
    }
    else
    {
        Node *pn = p->next;
        if (pn)
        {
            pn->pre = n;
            n->next = pn;
        }
        p->next = n;
        n->pre = p;
    }
}

void deleteList(Node *&h, int index)
{
    Node *p = h, *pre;
    for (int i = 0; p->next && i < index; i++)
    {
        pre = p;
        p = p->next;
    }
    if (index <= 0)
    {
        h = p->next;
        h->pre = nullptr;
    }
    else
    {
        Node *pn = p->next;
        if (pn)
            pn->pre = pre;
        pre->next = pn;
    }
    delete p;
}

void display(Node *&h, bool skipF = false)
{
    Node *p = skipF ? h->next : h;
    cout << "输出序列：" << endl;
    while (p->next)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << p->data << endl;
    while (p->pre)
    {
        cout << p->data << " ";
        p = p->pre;
    }
    cout << p->data << endl;
}

int main()
{
    Node *h = nullptr;
    createListR(h);
    deleteList(h, 10);
    display(h, false);
}