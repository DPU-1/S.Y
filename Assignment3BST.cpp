    #include<iostream>
    using namespace std;
    class Node
    {
        public :
        int key;
        Node *ln,*rn;
    };

    class Tree
    {
        public:
        Node* root;
        Node* createTree(int key)
        {
            root = new Node();
            root->key = key;
            root->ln = NULL;
            root->rn = NULL;
            return root;
        }

        void insertNode(int key,Node* root)
        {
            Node* node = new Node();
            node->key = key;
            //checking leftside
            if(key <= root->key)
            {
                root->ln = node;
            }
            else
            {
                //if right is null insert in right
                if(root->rn == NULL)
                {
                    root->rn = node;
                }
                else
                {
                    //move to next right
                    insertNode(key,root->rn);
                }
            }
        }

        //display in inorder
        void display(Node *root)
        {   
          
            if(root != NULL)
            {
                display(root->ln);
                cout<<root->key<<" ";
                display(root->rn);
                //recursive format to display inorder
            }
        }

     //finding the minimum value in the tree
        void findmin(Node *root)
        {
        
            while (root->ln!=NULL)
            {
                root =root->ln;
            }
            cout<<"\n Minimum :"<<root->key<<endl;
            
        }

     // function delete node
     
  
      //function to calucalte the height of the tree
        int heightoftree(Node *temp)
        {
            Node *p = temp;
            if (p == NULL)
                return 0;
            else
            {
                
                int left_side = heightoftree(p->ln);
                int right_side = heightoftree(p->rn);
                if (left_side > right_side) // if left side is greater or right one
                {
                    return left_side + 1;
                }
                else
                    return right_side + 1;
            }
        }

      // mirroring the tree
        void mirror(Node *temp)
        {
            Node *p = temp;
            if (p == NULL)
                return;
            else
            {
                Node *swap;

                // do the subtrees 
                mirror(p->ln);
                mirror(p->rn);

                // swap the pointers in this p 
                swap = p->ln;
                p->ln = p->rn;
                p->rn = swap;
            }
        }

          //function to serach a key in tree
        bool searchNode(Node *root,int keytosearch)
        {
            
            if(keytosearch < root->key)
            {
                if(root->ln==NULL && root->rn==NULL)
                {
                    cout <<"\n Number not found";
                    return false;
                }
                else
                {
                    searchNode(root->ln,keytosearch);
                }
            }
            else if(keytosearch > root->key)
            {
                if(root->ln==NULL && root->rn==NULL)
                {
                    cout <<"\n Number not found";
                    return false;
                }
                else
                {
                    searchNode(root->rn,keytosearch);
                }
            }
            else if(keytosearch == root->key)
            {
                
                cout << "\n Number Found \n";
                return true;
            }
            return false;
        }
    };
     Node* minValueNode(Node* node)
{
     Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->ln != NULL)
        current = current->ln;
    
    return current;
}
    Node* deleteNode( Node* root, int key)
{
    if (root == NULL)
        return root;
 
   
    if (key < root->key)
        root->ln = deleteNode(root->ln, key);
 
   
    else if (key > root->key)
        root->rn = deleteNode(root->rn, key);
 
   
    else {
        // node has no child
        if (root->ln==NULL and root->rn==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->ln == NULL) {
             Node* temp = root->rn;
            free(root);
            return temp;
        }
        else if (root->rn == NULL) {
             Node* temp = root->ln;
            free(root);
            return temp;
        }
 
        // (smallest in the right subtree)
         Node* temp = minValueNode(root->rn);
 
        root->key = temp->key;
 
        root->rn = deleteNode(root->rn, temp->key);
    }
    return root;
}
     int main()
        {
            int choice,flag = 0;
            int key,keytosearch;
            Tree t1;
            Node* root;
            do
            {
                cout<<"\n 1.Insert a number \n 2.Display \n 3.Search a key \n 4.Find Minimum  \n 5.Display Height \n 6.Mirror Tree \n 7.Delete a Node \n 8.Exit \n";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    cout<<"\n Enter the number to insert : ";
                    cin >> key;
                    if(flag == 0)
                    {
                        root = t1.createTree(key);
                        flag = 1;
                    }
                    else
                    {
                        t1.insertNode(key,root);
                    }
                    break;

                case 2:
                    cout<<"Inorder Tree : ";
                    t1.display(root);
                    break;


                case 3:
                    cout<<"\n Enter the key to search :";
                    cin>>keytosearch;
                    t1.searchNode(root,keytosearch);
                    break;


                case 4:
                    t1.findmin(root);
                    break;

                case 5:
                        cout<<"\n Height of Tree : "<< t1.heightoftree(root)<<endl;
                        
                    break;

                 case 6:
                        cout<<"\n--- Tree Before Mirror ---\n";
                        t1.display(root);
                        t1.mirror(root);
                        cout<<"\n--- Tree After Mirror ---\n";
                        t1.display(root);
                        break;


                case 7:
                    cout<<"\n Enter the data to delete \n";
                    cin>>key;
                    root = deleteNode(root,key);
                    t1.display(root);
                    break;

                case 8:
                  break;
                }
                
                
            } while (choice != 6);
            
            
        }