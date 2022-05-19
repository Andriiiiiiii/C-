#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

struct Node 
{
public:
    char name[20];
    Node *next;
    Node *pre;
};

struct List 
{
public:
    Node* head;

    List(int N) 
    {
        head = new Node;
        head->next = head;
        head->pre = head;
        cin >> head->name;
        Node *now = head;
        for (int i = 0; i < (N - 1); i++) 
        {
            Node* x = new Node;
            x->next = head;
            x->pre = now;
            now->next = x;
            head->pre = x;
            cin >> x->name;
            now = now->next;
        }
    }

    void off(int n) 
    {
        Node* now = head;
        for (int i = 1; i < n; i++)
            now = now->next;
        head = now->next;
        (now->pre)->next = now->next;
        (now->next)->pre = now->pre;
    }


    Node* pN(int n) 
    {
        while ((head->next) != head) 
        {
            off(n);
        }
        return (head);
    }
};

int main() 
{
    int N;
    cin >> N;
    List People(N);
    int n;
    cin >> n;
    Node* last = People.pN(n);
    cout << last->name;
    return 0;
}