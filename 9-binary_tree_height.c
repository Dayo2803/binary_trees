#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		if (tree->left != NULL)
			left_height = 1 + binary_tree_height(tree->left);
		else
			left_height = 0;
		if (tree->right != NULL)
			right_height = 1 + binary_tree_height(tree->right);
		else
			right_height = 0;
		if (left_height >= right_height)
			return (left_height);
		else
			return (right_height);
	}
}
