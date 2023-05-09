#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left = nullptr;
    struct node *right = nullptr;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == NULL)
        return;

    traverseInOrder(root -> left);
    cout << root -> key << " ";
    traverseInOrder(root -> right);

}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == nullptr) {
        //if the BST is empty add the newNode to the BST as root
        node = new struct node;
        node->key=key;
    } else {
        if (node -> key >= key) {
            node->left=insertNode(node -> left, key);
        } else {
            node->right=insertNode(node -> right, key);
        }
    }
    return node;
}

int minValueLSubtree(struct node *root) {
    while (root -> left != NULL) {      // find the minimum key in the left subtree
        root = root -> left;
    }
    int keyR = root -> key;
    return keyR;
}


//Deleting a node

struct node *deleteNode(struct node *root, int key) {
    if (root == nullptr) return nullptr;

    else if (root -> key < key) {
        root -> right = deleteNode(root->right, key);
    }

    else if (root -> key > key){
        root->left=deleteNode(root -> left, key);
    }

    else {

        if( root->left== nullptr && root->right== nullptr ){
            delete root;
            return nullptr;
        }

        else if (root -> right == nullptr) {
            auto temp = root -> left;
            free(root);
            return temp;

        } else if (root -> left == nullptr) {
            auto temp = root -> right;
            free(root);
            return temp;


        } else{
            auto temp = root->right;
            while(temp->left != nullptr)
                temp=temp->left;
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
