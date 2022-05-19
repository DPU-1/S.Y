#include <iostream>
#include <cstring>
using namespace std;
int cnt = 0;
class Node
{
public:
   string word;
   string mean;
   Node *left;
   Node *right;

   Node(string word, string mean)
   {
      this->word = word;
      this->mean = mean;
      left = NULL;
      right = NULL;
   }
};

class Tree
{
public:
   Node *insertNode(Node *root, string word, string mean)
   {

      if (root == NULL)
      {
         return new Node(word, mean);
      }
      else if (word <= root->word)
      {
         root->left = insertNode(root->left, word, mean);
      }
      else if (word > root->word)
      {
         root->right = insertNode(root->right, word, mean);
      }
      return root;
   }
   // ascdending inorder
   void display(Node *root)
   {

      if (root == NULL)
      {
         return;
      }
      display(root->left);
      cout << root->word << "  :-  " << root->mean << endl;
      display(root->right);
   }

   // display descending
   void display_deced(Node *root)
   {

      if (root == NULL)
      {
         return;
      }
      display_deced(root->right);
      cout << root->word << "  :-  " << root->mean << endl;
      display_deced(root->left);
   }

   int heightoftree(Node *root)
   {

      if (root == NULL)
      {
         return 0;
      }

      int lh = heightoftree(root->left);
      int rh = heightoftree(root->right);

      return 1 + max(lh, rh);
   }

   //     // function to serach a key in tree
   bool searchNode(Node *root, string word)
   {

      if (root == NULL)
      {
         return false;
      }
      if (root->word == word)
      {
         return true;
      }
      if (word < root->word)
      {
         cnt++;
         return searchNode(root->left, word);
      }
      cnt++;
      return searchNode(root->right, word);
   }

   Node *minValueNode(Node *node)
   {
      Node *current = node;

      /* loop down to find the leftmost leaf */
      while (current && current->left != NULL)
      {
         current = current->right;
      }

      return current;
   }
   Node *deleteNode(Node *root, string word)
   {
      if (root == NULL)
         return root;

      if (word < root->word)
         root->left = deleteNode(root->left, word);

      else if (word > root->word)
         root->right = deleteNode(root->right, word);

      else
      {
         // node has no child
         if (root->left == NULL and root->right == NULL)
            return NULL;

         // node with only one child or no child
         else if (root->left == NULL)
         {
            Node *temp = root->right;
            free(root);
            return temp;
         }
         else if (root->right == NULL)
         {
            Node *temp = root->right;
            free(root);
            return temp;
         }

         // (smallest in the right subtree)
         Node *temp = minValueNode(root->right);

         root->word = temp->word;
         root->mean = temp->mean;

         root->right = deleteNode(root->right, temp->word);
      }
      return root;
   }

   Node *update(Node *root, string word)
   {
      if (root != NULL)
      {
         if (root->word == word)
         {

            cout << "Enter new meaning:-" << endl;
            cin >> root->mean;
         }
         else if (word < root->word)
         {
            root->left = update(root->left, word);
         }
         else if (word > root->word)
         {
            root->right = update(root->right, word);
         }
      }
      else
      {
         cout << "Word not Found" << endl;
      }
      return root;
   }
};

int main()
{

   Tree obj;
   Node *root = NULL;

   int choice;
   string wr, wrd, str, st;

   do
   {
      cout << "\n1.Insert\n2.Display Ascending\n3.Display Desecnding\n4.Delete in a Dictonary\n5.Update in Dictonary\n6.Search in Dictionry\n"
           << endl;
      cout << "\nEnter Your choice:- " << endl;
      cin >> choice;

      switch (choice)
      {
      case 1:
         cout << "\n Enter How Many words You want to insert in Dictionary:- " << endl;
         int n;
         cin >> n;
         while (n--)
         {
            cout << "\nEnter the word:- " << endl;
            string wrd;
            cin >> wrd;
            cout << "\n Enter the meaning:- " << endl;
            string men;
            cin >> men;
            root = obj.insertNode(root, wrd, men);
         }
         break;
      case 2:
         cout << "\nDisplay in Ascending order:- " << endl;
         obj.display(root);
         break;

      case 3:
         cout << "\n Display in Descending order:- " << endl;
         obj.display_deced(root);
         break;
      case 4:

         cout << "\n Enter the word you want to delete:- " << endl;

         cin >> wr;
         root = obj.deleteNode(root, wr);
         cout << "\n Word Deleted succesfully" << endl;
         break;

      case 5:
         cout << "\n Enter the word You want to update:- " << endl;

         cin >> str;
         root = obj.update(root, str);
         cout << "Word Updated Succesfully" << endl;
         break;

      case 6:
         cout << "\n Enter the word you want to search:- " << endl;

         cin >> st;
         if (obj.searchNode(root, st))
         {
            cout << "\nYour word is found " << endl;
            cout << "\n And require  " << cnt << " searches " << endl;
         }
         else
         {
            cout << "\nWord Not found" << endl;
         }
         break;

      default:
         break;
      }

   } while (choice < 7);
}