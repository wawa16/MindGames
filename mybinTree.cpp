#include <iostream>
#include <cstdlib>
#include <sstream> 
using namespace std;

struct node {                   //node structure
  int key;
  node* left;
  node* right; 
  node(int key_ = 0){           //node init func
      this->key = key_;
      left = NULL; right = NULL;
  }
};

void buildTree(string input[], int &size);       //higherLvl user-interface func to build Tree

//scans tree lvl by lvl and prints keys in sequence = Left child first then root then right:
void leftChildSort(node* Ptr);   

//local functions utilized by buildTree():
node* addLeftChild(node* root);               
node* addRightChild(node* root);

node* root;

void leftChildSort(node* Ptr){
    if(Ptr!=NULL){
        if(Ptr->left != NULL){
            leftChildSort(Ptr->left);
        }
        cout << Ptr->key << " ";
        if(Ptr->right != NULL){
            leftChildSort(Ptr->right);
        }
    } else {
        cout << "No nodes in tree\n";
    }
}

node* addLeftChild(node* root){
    if(root->left == NULL){
       root->left = new node();
    }
      return root->left;
}

node* addRightChild(node* root){
    if(root->right == NULL){
       root->right = new node();
    }
      return root->right;
}

void buildTree(string input[], int &size){

    int key_arr[size];             //array to hold node keys specified by user
    node* arr_[size];              //array to hold node ptrs
    
     for(int i=0; i<size; i++){      //loops through user-input data
        
         if(root == NULL){
             int root_key = input[i][0] - '0';   //first user-value is root
             root = new node(root_key);
             arr_[i] = root;
         } else {
             bool Lcount = false;
             bool Rcount = false;
             int count = 0; int key_ = 0;
             node *ptr = root;
             while(count < input[i].length()){       //dissect data to organize tree in user-defined order
                if (input[i][count] == 'L') {
                        if(Lcount || Rcount){
                            arr_[i] = addLeftChild(arr_[i]);
                        } else {
                            arr_[i] = addLeftChild(arr_[count]);                
                        }
                        Lcount = true;
                } else if (input[i][count] == 'R') {
                        if(Rcount || Lcount){
                            arr_[i] = addRightChild(arr_[i]);
                        } else {
                            arr_[i] = addRightChild(arr_[count]);                 
                        }
                        Rcount = true;
                }
                else {
                  key_ = (key_*10) + (input[i][count] - '0'); 
                }
                count++;
             }
             key_arr[i] = key_;
         }
     }
     for(int i=1; i<size; i++){
         arr_[i]->key = key_arr[i];      //assign key values to proper nodes
     }
     
     
     leftChildSort(arr_[0]);             //run leftSort func with user's root input             

}


int main() {
    // int size;
    // cout << "Enter total number of elements (nodes&children including root node):" << endl;
    // cin >> size;
    // cout << "Enter Root value first then Enter Children of Tree in proper sequence\n(e.g. LLR2 is left->left->right=2 with respect to root)" << endl;
    // cout << "(Press Enter after each entry):" << endl;
    // string tree_input[size];
    // for(int i=0; i<size; i++){
    //     cin >> tree_input[i];
    // }
    // buildTree(tree_input, size);
    
////To use USER-DEFINED data, uncomment code above then comment code lines below (till before return 0 line)
  
    node* root = new node(1);             //Sample tree
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(5);
    root->left->right = new node(4);
    root->left->right->left = new node(6);
    root->left->right->right = new node(8);
    root->right->left = new node(7);
    root->right->right = new node(8);
    leftChildSort(root);
    
    return 0;
}
