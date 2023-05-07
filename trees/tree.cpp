#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    char data;
    Node *lchild, *rchild;
    Node(char data) : data(data)
    {
        lchild = rchild = nullptr;
    }
};

/*
    A
   / \
  B  C
  \   \
  D   F
 /   /
E   G
*/
Node *buildTree()
{
    Node *a = new Node('A');
    Node *b = new Node('B');
    Node *c = new Node('C');
    Node *d = new Node('D');
    Node *e = new Node('E');
    Node *f = new Node('F');
    Node *g = new Node('G');
    a->lchild = b;
    a->rchild = c;
    b->rchild = d;
    d->lchild = e;
    c->rchild = f;
    f->lchild = g;
    return a;
}

void preOrder(Node *t)
{
    if (t)
    {
        cout << t->data << " ";
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}

void inOrder(Node *t)
{
    if (t)
    {
        inOrder(t->lchild);
        cout << t->data << " ";
        inOrder(t->rchild);
    }
}

void postOrder(Node *t)
{
    if (t)
    {
        postOrder(t->lchild);
        postOrder(t->rchild);
        cout << t->data << " ";
    }
}

void preOrder2(Node *t)
{
    stack<Node *> stk;
    while (t || !stk.empty())
    {
        if (t)
        {
            cout << t->data << " ";
            stk.push(t);
            t = t->lchild;
        }
        else
        {
            t = stk.top();
            stk.pop();
            t = t->rchild;
        }
    }
}

void inOrder2(Node *t)
{
    stack<Node *> stk;
    while (t || !stk.empty())
    {
        if (t)
        {
            stk.push(t);
            t = t->lchild;
        }
        else
        {
            t = stk.top();
            stk.pop();
            cout << t->data << " ";
            t = t->rchild;
        }
    }
}

void postOrder2(Node *t)
{
    stack<Node *> stk;
    Node *r = nullptr; // 记录上一次被访问的结点
    while (t || !stk.empty())
    {
        if (t)
        {
            stk.push(t);
            t = t->lchild;
        }
        else
        {
            t = stk.top();
            if (t->rchild && t->rchild != r)
                t = t->rchild;
            else
            {
                cout << t->data << " ";
                r = t;
                stk.pop();
                t = nullptr;
            }
        }
    }
}

void levelOrder(Node *t)
{
    queue<Node *> queue;
    queue.push(t);
    while (!queue.empty())
    {
        t = queue.front();
        queue.pop();
        cout << t->data << " ";
        if (t->lchild)
            queue.push(t->lchild);
        if (t->rchild)
            queue.push(t->rchild);
    }
}

int main()
{
    Node *t = buildTree();
    inOrder(t);
    cout << endl;
    inOrder2(t);
}