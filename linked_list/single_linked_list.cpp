#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// 头插法建立无头节点的链表
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
            n->next = h;
            h = n;
        }
    }
}

// 头插法建立有头节点的链表
void createListHF(Node *&h)
{
    int x;
    h = new Node(0);
    cout << "输入序列:" << endl;
    while (cin >> x)
    {
        Node *n = new Node(x);
        n->next = h->next;
        h->next = n;
    }
}

// 尾插法建立无头节点的链表
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
            n->next = r->next;
            r->next = n;
            r = n;
        }
    }
}

// 尾插法建立有头节点的链表
void createListHR(Node *&h)
{
    int x;
    h = new Node(0);
    Node *r = h;
    cout << "输入序列:" << endl;
    if (cin.rdstate())
    {
        cin.clear();
        // cin.sync();
        cin.ignore();
    }
    while (cin >> x)
    {
        Node *n = new Node(x);
        n->next = r->next;
        r->next = n;
        r = n;
    }
}

// 在index后插入节点
void insertListR(Node *&h, int index, int value)
{
    // TODO: 获取链表长度， 判断 index 范围
    Node *n = new Node(value), *p = h;
    for (int i = 0; p->next && i < index; i++)
        p = p->next;
    if (index < 0)
    {
        n->next = h;
        h = n;
    }
    else
    {
        n->next = p->next;
        p->next = n;
    }
}

// 在index前插入节点
void insertListF(Node *&h, int index, int value)
{
    // TODO: 获取链表长度， 判断 index 范围
    Node *n = new Node(value), *p = h;
    for (int i = 0; p->next && i < index - 1; i++)
        p = p->next;
    if (index <= 0)
    {
        n->next = h;
        h = n;
    }
    else
    {
        n->next = p->next;
        p->next = n;
    }
}

// 删除index处的节点
void deleteList(Node *&h, int index)
{
    // TODO: 获取链表长度， 判断 index 范围
    Node *p = h, *pre;
    for (int i = 0; p->next && i < index; i++)
    {
        pre = p;
        p = p->next;
    }
    if (index <= 0)
        h = p->next;
    else
        pre->next = p->next;
    delete p;
}

// 删除所有值为x的节点
void deleteAllXRecur(Node *&h, int x) // h 为不带头节点的链表
{
    if (h)
    {
        if (h->data == x)
        {
            Node *p = h;
            h = h->next;
            // 这里直接删除 p 不会断链，因为 h 是引用，
            // h = h->next; 实际上将上一次调用的 h->next 指向了当前函数的 h->next，
            // 如有 pre -> p -> pn，即上一次调用的h（pre） -> 本次h的后继（pn）
            delete p;
            deleteAllXRecur(h, x);
        }
        else
        {
            deleteAllXRecur(h->next, x);
        }
    }
}

// 反转链表
void reverse(Node *&h) // h为带头节点的链表
{
    Node *p = h->next, *pn;
    h->next = nullptr;
    while (p)
    {
        pn = p->next;
        p->next = h->next;
        h->next = p;
        p = pn;
    }
}

// 排序链表
void insert_sort(Node *&h) // h为带头节点的链表
{
    if (h->next == nullptr)
        return;
    Node *pi = h->next, *prei, *p = h->next->next, *pn;
    pi->next = nullptr;
    while (p)
    {
        pn = p->next;
        for (prei = h, pi = h->next; pi && (pi->data) < (p->data); prei = pi, pi = pi->next)
            ;
        p->next = pi;
        prei->next = p;
        p = pn;
    }
}

// 求交集，在 h1 上原地操作
void intersection(Node *&h1, Node *&h2) // h1,h2为带头节点的有序链表
{
    Node *p1 = h1->next, *p2 = h2->next, *pre = h1, *q;
    while (p1 && p2)
    {
        if (p1->data == p2->data)
        {
            pre = p1;
            p1 = p1->next;
            q = p2;
            p2 = p2->next;
            delete q;
        }
        else if (p1->data < p2->data)
        {
            pre->next = p1->next;
            q = p1;
            p1 = p1->next;
            delete q;
        }
        else
        {
            q = p2;
            p2 = p2->next;
            delete q;
        }
    }

    while (p1)
    {
        pre->next = nullptr; // 此时pre是链表的最后一个节点
        q = p1;
        p1 = p1->next;
        delete q;
    }
    while (p2)
    {
        q = p2;
        p2 = p2->next;
        delete q;
    }
}

// 判断h2是不是h1的子串
bool is_substring(Node *&h1, Node *&h2) // h1,h2为带头节点的有序链表
{
    Node *p1 = h1->next, *p2 = h2->next, *pre = p1;
    while (p1 && p2)
    {
        if (p1->data == p2->data)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        else
        {
            pre = pre->next;
            p1 = pre;
            p2 = h2->next;
        }
    }
    if (p2 == nullptr)
        return true;
    return false;
}

void display(Node *&h, bool skipF = false)
{
    cout << "输出序列：" << endl;
    for (Node *p = skipF ? h->next : h; p; p = p->next)
        cout << p->data << " ";
    cout << endl;
}

int main()
{
    Node *h = nullptr;
    createListHR(h);
    Node *h2 = nullptr;
    createListHR(h2);
    intersection(h, h2);
    display(h, true);
}