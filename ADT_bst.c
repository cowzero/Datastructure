#include "ADT_bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
BST_TREE* create_bst(){
	BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));

	if(tree) {
	tree -> root = NULL;
	tree -> count = 0;

	return tree;
	}
	return NULL;
}
T_NODE* add_bst(T_NODE* root, int data){
	if(root == NULL){
	T_NODE* newPtr=(T_NODE*)malloc(sizeof(T_NODE));
	newPtr -> left = NULL;
	newPtr -> right = NULL;
	newPtr -> data = data;

	return newPtr;
	} // if there is no root
	if(data<(root->data)){
		root -> left = add_bst(root->left, data);
		
		return root;
	}//case1
	else {
		root -> right = add_bst(root->right, data);
		return root;
	}//case2

}
bool BST_insert(BST_TREE* tree, int data){
	T_NODE* newRoot;
	newRoot = add_bst(tree-> root, data);

	if(newRoot == NULL){
	return false;
	}
	else {
	tree -> root = newRoot;
	(tree->count)++;
	return true;
	}	
}

bool BST_delete(BST_TREE* tree, int data) {
	bool success;
	T_NODE* new_root;
	new_root = delete_bst(tree->root, data, &success);
	//there is two return value
	if(success){
		tree -> root = new_root;
		tree -> count --;
		if(tree->count ==0)
			tree -> root = NULL;
	}
	return success;
}

T_NODE* delete_bst(T_NODE* root, int data, bool* success){
	T_NODE* new_root;
	T_NODE* deleted_node;
	T_NODE* search;

	if(root==NULL){
	*success = false;
	return NULL;
	}
	//traverse
	if(data<(root->data)){// exist at left somewhere
		root->left = delete_bst(root->left, data, success);
	} else if (data>(root->data)){//exist at right somewhere
		root->right = delete_bst(root->right, data, success);
	} else{//matched
		deleted_node = root;
		if(root->left == NULL){
			new_root = root->right;
			free(deleted_node);
			*success = true;
			return new_root;
		}	else{
			//case (2)
			if(root->right ==NULL){
				new_root = root-> left;
				free(deleted_node);
				*success = true;
				return new_root;
			} else {//case(3) : have two slaves
				search = root->left;
				while(search->right!=NULL)
					search = search->right;
				root -> data  = search -> data;//promote to new boss
				root -> left  = delete_bst(root->left, search->data,success);
			}
		}
	}

	return NULL;
}

void traverse_preorder (T_NODE* root) {
	if(root != NULL) {
		printf("%d,",root -> data);
		traverse_preorder(root->left);
		traverse_preorder(root->right);
	}
}

void traverse_postorder (T_NODE* root) {
	if(root != NULL) {
		traverse_postorder(root->left);
		traverse_postorder(root->right);
		printf("%d,",root -> data);
	}
}
void traverse_inorder (T_NODE* root) {
	if(root != NULL) {
		traverse_inorder(root->left);
		printf("%d,",root -> data);
		traverse_inorder(root->right);
	}
}
BST_TREE* copy_tree	(BST_TREE* tree) {
	BST_TREE* c_tree = create_bst();

	copy_traverse(c_tree, tree->root);
	return c_tree;
}

void copy_traverse (BST_TREE* copy,T_NODE* root){
	if(root != NULL){
		BST_insert(copy, root->data)
		copy_traverse(copy, root->left);
		copy_traverse(copy, root->right);
	}
}
