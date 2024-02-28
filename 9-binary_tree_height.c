#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	else
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree_height(tree->left);
		right_height = tree_height(tree->right);
		if (left_height >= right_height)
			return (left_height + 1);
		else
			return (right_height + 1);
	}
}
