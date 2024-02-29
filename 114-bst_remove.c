#include "binary_trees.h"

/**
 * find_min - Finds the minimum value in a binary search tree.
 * @node: A pointer to the root node of the tree.
 *
 * Return: A pointer to the node with the minimum value.
 */

bst_t *find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the tree where
 * @value: The value to remove in the tree
 * Return: A pointer to the new root node of the tree after deletion.
*/

bst_t *bst_remove(bst_t *root, int value)
{
	/*Value not found in the tree*/
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/*Node with the value to be removed found*/

		/*Case 1: Node with only one child or no child*/
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		/*Case 2: Node with two children*/
		/*Get the in-order successor (smallest in the right subtree)*/
		bst_t *temp = find_min(root->right);

		/*Copy the in-order successor's value to this node*/
		root->n = temp->n;

		/*Delete the in-order successor*/
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}

