#include <iostream>
using namespace std;
#define MAX 10

// Node for queue
class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
// queue implementation for BFS
class Queue
{
    Node *head = NULL;

public:
    

    void push(int ele)
    {
        Node *n = new Node(ele);
        if (head == NULL)
        {
            n->next = head;
            head = n;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    void pop()
    {
        if (head != NULL)
        {
            head = head->next;
        }
        else
        {
            cout << "Queue is underflow()" << endl;
        }
    }

    int front()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
        }
        return (head->data);
    }

    bool empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
 
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};

// node for graph
class node
{
public:
    int vertex;
    node *next;

    node(int vertex)
    {
        this->vertex = vertex;
        next = NULL;
    }
};

// Graph class
class graph
{
private:
    node *head[MAX];
    int visited[MAX];

public:
    graph()
    {

        for (int i = 0; i < MAX; i++)
        {
            visited[i] = 0;
            head[i] = NULL;
        }

       
    }
    void create()
    {
        int v1, v2;
        char ans;
        node *N, *first;
        cout << "Enter the vertices number beginning with 0 : ";
        do
        {
            cout << "\nEnter the Edge of a graph : \n";
            cin >> v1 >> v2;
            if (v1 >= MAX || v2 >= MAX)
            {
                cout << "Invalid Vertex Value!!\n";
            }
            else
            {
                N = new node(v2);
                if (N == NULL)
                {
                    cout << "Insufficient Memory!!\n";
                }
                first = head[v1];
                if (first == NULL)
                {
                    head[v1] = N;
                }

                else
                {
                    while (first->next != NULL)
                    {
                        first = first->next;
                    }

                    first->next = N;
                }

                N = new node(v1);
                if (N == NULL)
                {
                    cout << "Insufficient Memory!!\n";
                }

                first = head[v2];
                if (first == NULL)
                {
                    head[v2] = N;
                }
                else
                {
                    while (first->next != NULL)
                    {
                        first = first->next;
                    }

                    first->next = N;
                }
            }
            cout << "\n Want to add more edges?(y/n) : ";
            cin >> ans;
        } while (ans == 'y');
    }

    void dfs(int v1)
    {
        node *first;
        cout << endl
             << v1;
        visited[v1] = 1;
        first = head[v1];
        while (first != NULL)
            if (visited[first->vertex] == 0)
            {
                dfs(first->vertex);
            }
            else
            {
                first = first->next;
            }
    }

    void bfs(int v1)
    {

        visited[v1] = 1;

        Queue q;
        q.push(v1);

        while (!q.empty())
        {

            int ft = q.front();
            q.pop();
            node *f = head[ft];
            cout << ft << " ";

            while (f != NULL)
            {
                if (visited[f->vertex] == 0)
                {
                    q.push(f->vertex);
                    visited[f->vertex] = 1;
                }
                f = f->next;
            }
        }
    }
};

int main()
{
    int v1;
    graph g;
    char ans;
    g.create();
    cout << endl
         << "Enter the vertex from where you want to traverse : ";
    cin >> v1;

    cout << "Enter B for bfs and D for dfs:- " << endl;
    cin >> ans;

    if (v1 >= MAX)
        cout << "Invalid Vertex!!\n";
    else
    {
        if (ans == 'B')
        {
            g.bfs(v1);
        }
        else if (ans == 'D')
        {
            g.dfs(v1);
        }
    }

    return 0;
}