#pragma once

#include <iostream>

#include <queue>

#include<stack>

#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
//a

namespace MySpace
{
	namespace DataStructs
	{
		namespace Trees
		{



			/// <summary>
			/// This is a class for N-ARY trees
			/// </summary>
			/// <typeparam name="T"></typeparam>
			template<typename T>
			class nAryTreeNode
			{
			public:
				//member vars
				T nodeValue;
				std::vector<nAryTreeNode<T>*> childrenLinks;
				//dynamic array (vector) allows arbitrary number of children

				//constructors:
				nAryTreeNode() {};
				nAryTreeNode(T nodeValue)
					:nodeValue(nodeValue)
				{
				};

			};

			/// <summary>
			/// This is a class for BINARY trees.
			/// </summary>
			template<typename T>
			class TreeNode
			{
			public:
				//member vars:
				T nodeValue;
				TreeNode<T>* left, * right;
				//left = nullptr; 
				//right = nullptr; 

				//constructors:
				TreeNode() {};// leaving empty for now

				TreeNode(const T& nodeValue)
				{
					this->nodeValue = nodeValue;
				};

				bool isLeaf()
				{
					if (left == nullptr && right == nullptr)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
			}; //end TreeNode class def.


			template<typename T>
			int getNodeLevel(TreeNode<T>* root, T targetValue, int level)
			{
				if (root == nullptr)
				{
					return -1;
				}

				if (root->nodeValue == targetValue)
				{
					return level;
				}
				//function def. concludes next slide	

				//if (root->left != nullptr)
				//{ 
				//	cout << root->left->nodeValue << endl;
				//}
				int leftLevel = getNodeLevel(root->left, targetValue, level + 1);
				int rightLevel = getNodeLevel(root->right, targetValue, level + 1);


				if (leftLevel == -1)
				{
					return rightLevel;
				}

				else
				{
					return leftLevel;
				}
			} //end getNodeLevel() def.

			template <typename T>
			void levelOrderTraverse(TreeNode<T>* root)
			{
				std::queue<TreeNode<T>*> treeNodeQueue;
				//queue to the res-queue(rescue)

				treeNodeQueue.push(root);

				int nodeCount = 1; //optional (root is first node)  

				while (!treeNodeQueue.empty())
				{
					TreeNode<T>* current;
					current = treeNodeQueue.front();

					treeNodeQueue.pop();

					//int level = getNodeLevel(root, current->nodeValue, 0);
					////for indenting children ...
					//for (int tabCount = 0; tabCount < level; tabCount++)
					//{
					//	cout << "\t";
					//}

					cout << current->nodeValue << " at level "
						<< getNodeLevel(root, current->nodeValue, 0) << endl;

					//cout << "\n";

					if (current->left != nullptr)
					{
						nodeCount++;
						treeNodeQueue.push(current->left);
					}

					if (current->right != nullptr)
					{
						nodeCount++;
						treeNodeQueue.push(current->right);
					} //switch left and right, if desired 
				}//end while

				cout << "\nTotal number of nodes: " << nodeCount << endl;
			} //end levelOrderTraverse

			/// <summary>
			/// In as in "in between"
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="root"></param>
			template <typename T>
			void inorderTraverse(TreeNode<T>* root)
			{
				if (root != nullptr) //base case for this recursive algorithm is root == nullptr 
				{
					inorderTraverse(root->left); //recursion!
					cout << root->nodeValue << " "; //add endl depending on tree contents 
					inorderTraverse(root->right);
				}
			}

			template<typename T>
			int getLeafCount(TreeNode<T>* root)
			{
				if (root == nullptr)
				{
					return 0;
				}

				int leafCount = 0;

				//not using a queue (as we did for the levelOrderTraverse) 
				std::stack<TreeNode<T>*>  nodeStack;
				nodeStack.push(root);

				while (!nodeStack.empty())
				{
					TreeNode<T>* current = nodeStack.top();
					nodeStack.pop();

					if (current->left != nullptr)
					{
						nodeStack.push(current->left);
					}

					if (current->right != nullptr)
					{
						nodeStack.push(current->right);
					}

					if (current->isLeaf())
					{
						leafCount++;
					}
				} //end while not empty stack

				return leafCount;
			} //end getLeafCount()

			template<typename T>
			TreeNode<T>* insertBSTNode(TreeNode<T>* root, T insertedValue)
			{
				if (root == nullptr) //the base case
				{
					root = new TreeNode<T>(insertedValue);
				}

				else if (insertedValue < root->nodeValue)
				{
					//recursive call:
					root->left = insertBSTNode(root->left, insertedValue);
				}

				else //means insertedValue is either EQUAL TO or GREATER THAN root->nodeValue 
				{
					root->right = insertBSTNode(root->right, insertedValue);
				}

				return root;
			} //end insertBSTNode() def


			/// <summary>
			/// Assumes a BST is passed 
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="root">root MUST be the root of a BST </param>
			/// <returns></returns>
			template <typename T>
			T findMin(TreeNode<T>* root)
			{

				TreeNode<T>* current = root;

				while (current->left != nullptr)
				{
					current = current->left;
				}

				return current->nodeValue;
			}


			/// <summary>
			/// ASSUMES a binary search tree
			/// </summary>
			/// <typeparam name="T"></typeparam>
			/// <param name="root">this MUST be a BST root!</param>
			/// <returns></returns>
			template <class T>
			T findMax(TreeNode<T>* root)
			{
				TreeNode<T>* current = root;

				while (root->right != nullptr)
				{
					root = root->right;
				}

				return root->nodeValue;
			}

			/*template<typename T>
			int gGetNodeLevel(TreeNode<T>* root, T targetValue)
			{

				int level = 0;

				if (root == nullptr)
				{
					return -1;
				}
				if (root->nodeValue == targetValue)
				{
					return level;
				}

			}*/ //end Tree namespace 
		}
	}
}
