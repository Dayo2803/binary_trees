#include "binary_trees.h"
#include <stdio.h>


/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: a pointer to the node to check
 * Return: 1 or 0
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height of
 *
 * Return: the height of the tree. If tree is NULL, return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree)
	{
		left_height = binary_tree_height(tree->left);
	    right_height = binary_tree_height(tree->right);

		return ((left_height >= right_height) ? 1 + left_height : 1 + right_height);
	}

	return (0);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (1);
	left = tree->left;
	right = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (left == NULL || right == NULL)
		return (0);
	if (binary_tree_height(left) == binary_tree_height(right))
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_perfect(right))
			return (1);
	}
	return (0);
}
/**
 * binary_tree_is_complete -  checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	left = tree->left;
	right = tree->right;
	l_height = binary_tree_height(left);
	r_height = binary_tree_height(right);
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_complete(right))
			return (1);
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(left) && binary_tree_is_perfect(right))
			return (1);
	}
	return (0);
}
