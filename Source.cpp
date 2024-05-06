#include <iostream>
#include "TreeNode-1.h"


//using namespace std;


int main()
{
	MySpace::DataStructs::Trees::TreeNode<int>* root = new MySpace::DataStructs::Trees::TreeNode<int>(8);

	//1st depth
	root->left = new MySpace::DataStructs::Trees::TreeNode<int>(6);
	root->right = new MySpace::DataStructs::Trees::TreeNode<int>(7);

	//2nd depth
	root->left->left = new MySpace::DataStructs::Trees::TreeNode<int>(5);
	root->left->right = new MySpace::DataStructs::Trees::TreeNode<int>(3);
	root->right->left = new MySpace::DataStructs::Trees::TreeNode<int>(0);
	root->right->right = new MySpace::DataStructs::Trees::TreeNode<int>(9);

	//insertBSTNode(root, 8);

	levelOrderTraverse(root);

	cout << endl << endl;
	
	inorderTraverse(root);

	cout << endl << endl;

	cout << "Total Leafs: " << getLeafCount(root) << endl;

	cout << "Node Level: " << getNodeLevel(root, 11, 2);


	return 0;
}
		
	

