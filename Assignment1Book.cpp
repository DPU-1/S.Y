#include <iostream>
using namespace std;
struct node
{
    /* data */
    char labels[10];
    int sect_count;
     node *child[10];

} *root;
class BST
{
public:
    BST()
    {
        root = NULL;
    }

    void create_tree()
    {
        int nchapters;
        root = new node;
        cout << "\n Enter the Name of Book :";
        cin >> root->labels;
        cout << "\n Enter the number of Chapters :";
        cin >> root->sect_count;
        for (int i = 0; i < root->sect_count; i++)
        {
            root->child[i] = new node;
            cout << "\n Enter the chapter name :";
            cin >> root->child[i]->labels;
            cout << "\n Enter the number of sections in  :  " << root->child[i]->labels << " :";
            cin >> root->child[i]->sect_count;
            for (int j = 0; j < root->child[i]->sect_count; j++)
            {
                root->child[i]->child[j] = new node;
                cout << "\n Enter the name of Section for Chapter :" << root->child[i]->labels << " :";
                cin >> root->child[i]->child[j]->labels;

                cout << "\n Enter the number of subsections for Section :" << root->child[i]->child[j]->labels << " :";
                cin >> root->child[i]->child[j]->sect_count;
                for (int k = 0; k < root->child[i]->child[j]->sect_count; k++)
                {
                    root->child[i]->child[j]->child[k] = new node;
                    cout << "Enter the name of Subsections in Section :" << root->child[i]->child[j]->labels << " :";
                    cin >> root->child[i]->child[j]->child[k]->labels;
                }
            }
        }
    }

    void display(node *r1)
    {
        if (r1 != NULL)
        {
            cout << "\n Book Tree \n";
            cout << "\n Book Name :" << r1->labels;
            
            for (int i = 0; i < r1->sect_count; i++)
            {
                cout << "\n Chapter Name :";
                cout << r1->child[i]->labels;
               
                for (int j = 0; j < r1->child[i]->sect_count; j++)
                {
                     cout << "\n Sections :";
                    cout << r1->child[i]->child[j]->labels;
                    for (int k = 0; k < r1->child[i]->child[j]->sect_count; k++)
                    {
                                            cout << "\n Sub-Sections :";

                        cout << r1->child[i]->child[j]->child[k]->labels<<endl;
                    }
                }
            }
        }
    }
};

int main()
{
    BST b1;
    b1.create_tree();
    
    b1.display(root);

    return 0;
}
