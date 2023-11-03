#include "binary_trees.h"

/**
 * binary_trees_ancestor - this function finds the lowest common ancestor
 * of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node
 * NULL if no common ancestor is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ances_1, *ances_2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	ances_1 = first->parent, ances_2 = second->parent;
	if (first == ances_2 || !ances_1 || (!ances_1->parent && ances_2))
		return (binary_trees_ancestor(first, ances_2));
	else if (ances_1 == second || !ances_2 || (!ances_2->parent && ances_1))
		return (binary_trees_ancestor(ances_1, second));
	return (binary_trees_ancestor(ances_1, ances_2));
}
