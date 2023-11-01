#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node to the right of a parent node
 * @parent: The parent of the new tree node.
 * @value: The value to be inserted.
 *
 * Return: A ponter to the created node or NULL otherwise
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = NULL;

	if (parent != NULL)
	{
		newNode = malloc(sizeof(binary_tree_t));
		if (newNode != NULL)
		{
			newNode->left = NULL;
			newNode->right = parent->right;
			newNode->parent = parent;
			newNode->n = value;
			if (parent->right != NULL)
			{
				parent->right->parent = newNode;
			}
			parent->right = newNode;
		}
	}
	return (newNode);
}
