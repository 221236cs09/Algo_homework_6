#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    TreeNode* root;

    TreeNode* insertNode(TreeNode* root, int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        } else if (value <= root->data) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
        return root;
    }

    TreeNode* findMinValueNode(TreeNode* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int value) {
        if (root == nullptr) {
            return root;
        } else if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            // Node found, perform deletion
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* minValueNode = findMinValueNode(root->right);
                root->data = minValueNode->data;
                root->right = deleteNode(root->right, minValueNode->data);
            }
        }
        return root;
    }

    TreeNode* searchNode(TreeNode* root, int value) {
        if (root == nullptr || root->data == value) {
            return root;
        } else if (value < root->data) {
            return searchNode(root->left, value);
        } else {
            return searchNode(root->right, value);
        }
    }

    void inorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            std::cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    void preorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            std::cout << root->data << " ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }

    void postorderTraversal(TreeNode* root) {
        if (root != nullptr) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            std::cout << root->data << " ";
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    bool search(int value) {
        TreeNode* node = searchNode(root, value);
        return (node != nullptr);
    }

    void inorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }

    void preorder() {
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorder() {
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;

    bst.insert(4);
    bst.insert(7);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.insert(8);
    bst.insert(10);
    bst.insert(14);
    bst.insert(13);

    std::cout << "Inorder Traversal: ";
    bst.inorder();
    std::cout << "Preorder Traversal: ";
    bst.preorder(); 
    std::cout << "Postorder Traversal: ";
    bst.postorder();
    std::cout << "Searching for value 1: " << (bst.search(1) ? "Found" : "Not found") << std::endl;
    std::cout << "Searching for value 3: " << (bst.search(3) ? "Found" : "Not found") << std::endl;
    bst.remove(14);
    std::cout << "Inorder Traversal after deleting 14: ";
    bst.inorder();

    return 0;
}