#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *lchild, *rchild;
    bool lflag, rflag;
    Node(char data)
    {
        this->data = data;
        lchild = rchild = nullptr;
        lflag = rflag = false;
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

void inTheard(Node *&p, Node *&pre)
{
    if (p)
    {
        inTheard(p->lchild, pre);
        if (p->lchild == nullptr)
        {
            p->lchild = pre;
            p->lflag = true;
        }
        if (pre && pre->rchild == nullptr)
        {
            pre->rchild = p;
            pre->rflag = true;
        }
        pre = p;
        inTheard(p->rchild, pre);
    }
}

void createInTheard(Node *&t)
{
    if (t)
    {
        Node *pre = nullptr;
        inTheard(t, pre);      // 注意第二个参数必须是引用参数
        pre->rchild = nullptr; // 此时pre的右子树一定为空, 因为pre->rchild=p，而p==nullptr
        pre->rflag = true;
    }
}

Node *firstNode(Node *t)
{
    while (!t->lflag)
        t = t->lchild;
    return t;
}

Node *nextNode(Node *t)
{
    if (t->rflag)
        return t->rchild;
    return firstNode(t->rchild);
}

void inOrder(Node *t)
{
    for (Node *p = firstNode(t); p; p = nextNode(p))
        cout << p->data << " ";
    cout << endl;
}

int main()
{
    Node *t = buildTree();
    createInTheard(t);
    inOrder(t);
}