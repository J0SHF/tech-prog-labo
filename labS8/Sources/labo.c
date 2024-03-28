#include "labo.h"
#include <assert.h>
#include <stdint.h>

static long long Cache[256];

long long fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	if (Cache[n] == 0)
	{
		Cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	
	return Cache[n];
}



TreeNode* tree_create_node(void* data) {
	TreeNode* newNode = allocate(sizeof(TreeNode));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

/*
* Ajouter le noeud  node dans la propriete left ou right qui est NULL de root. On priorise de gauche a droite. Si right et left son NULL on le met dans left.
* Si jamais aucun des noeuds est NULL, ajouter rien.
*/
void tree_add_node(TreeNode* root, TreeNode* node) {
	if (root->left == NULL)
	{
		root->left = node;
	}
	else if (node->right == NULL)
	{
		root->right = node;
	}
}

/*
* Programmer l'algorithme de depth first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une pile/stack, ca definition est fourni.
*/

Stack s;

int dfs(TreeNode* root, void* key) {
	if (s.max != 32)
	{
		s = stack_init(32);
	}
	if (root->data == key)
	{
		return 1;
	}
	if (root->right != NULL)
	{
		stack_push(&s, root->right);
	}
	if (root->left != NULL)
	{
		stack_push(&s, root->left);
	}
	TreeNode* temp;
	temp = stack_pop(&s);
	return 1 + dfs(temp, key);
}

/*
* Programmer l'algorithme de breath first search afin de trouver la cle. Pour programmer cet algorithme, vous avez besoins d'une file/queue, ca definition est fourni.
*/

Queue* q;
int bfs(TreeNode* root, void* key) {
	if (q == NULL) {
		q = allocate(sizeof(Queue));
		queue_init(q);
	}
	if (root->data == key)
	{
		return 1;
	}
	if (root->left != NULL)
	{
		queue_push(q, root->left);
	}
	if (root->right != NULL)
	{
		queue_push(q, root->right);
	}
	TreeNode* temp;
	temp = queue_pop(q);
	return 1 + bfs(temp, key);
}