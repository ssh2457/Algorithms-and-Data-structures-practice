#include "include/KDTree.h"

#include <memory>
#include <iostream>
#include <stack>
#include <queue>

const size_t KDTree::k = 2;

static const size_t X = 0;
static const size_t Y = 1;

KDTree::KDTree() : mRoot(nullptr)
{

}

KDTree::KDTree(const point2D_t& point) : mRoot(nullptr)
{
	mRoot = static_cast<node_t*>(malloc(sizeof(node_t)));
	memset(mRoot, 0, sizeof(node_t));
	mRoot->point.coords[X] = point.coords[X];
	mRoot->point.coords[Y] = point.coords[Y];
	mRoot->depth = 0;
}

KDTree::KDTree(const KDTree& other) : mRoot(nullptr)
{
	mRoot = DeepCopyRecursive(other.mRoot);
}

node_t* KDTree::DeepCopyRecursive(node_t* node)
{
	if (node == nullptr) {
		return nullptr;
	}

	node_t* newNode = static_cast<node_t*>(malloc(sizeof(node_t)));
	newNode->point.coords[X] = node->point.coords[X];
	newNode->point.coords[Y] = node->point.coords[Y];
	newNode->depth = node->depth;
	newNode->left = DeepCopyRecursive(node->left);
	newNode->right = DeepCopyRecursive(node->right);

	return newNode;
}

KDTree::~KDTree()
{
	ClearKDTreeRecursive(mRoot);
	mRoot = nullptr;
}

void KDTree::ClearKDTreeRecursive(node_t* node)
{
	if (node == nullptr) {
		return;
	}

	if (node->left == nullptr && node->right == nullptr) {
		// memset(node, 0, sizeof(node_t));
		free(node);
		node = nullptr;
		return;
	}

	ClearKDTreeRecursive(node->left);
	ClearKDTreeRecursive(node->right);
	node->left = nullptr;
	node->right = nullptr;
	ClearKDTreeRecursive(node);
}

void KDTree::Insert(const point2D_t& point)
{
	if (mRoot == nullptr) {
		mRoot = static_cast<node_t*>(malloc(sizeof(node_t)));
		memset(mRoot, 0, sizeof(node_t));
		mRoot->point.coords[X] = point.coords[X];
		mRoot->point.coords[Y] = point.coords[Y];
		mRoot->depth = 0;
		return;
	}

	InsertRecursive(mRoot, point, 0);
}

node_t* KDTree::InsertRecursive(node_t* node, const point2D_t& point, const size_t depth)
{
	if (node == nullptr) {
		node = static_cast<node_t*>(malloc(sizeof(node_t)));
		memset(node, 0, sizeof(node_t));

		node->point.coords[X] = point.coords[X];
		node->point.coords[Y] = point.coords[Y];
		node->depth = depth;
		return node;
	}

	size_t cd = depth % k;
	if (point.coords[cd] < node->point.coords[cd]) {
		node->left = InsertRecursive(node->left, point, depth + 1);
	}
	else {
		node->right = InsertRecursive(node->right, point, depth + 1);
	}

	return node;
}

node_t* KDTree::NeareastSearchOrNull(const point2D_t& point)
{
	return nullptr;
}

void KDTree::PrintByDFS(void) const
{
	if (mRoot == nullptr) {
		return;
	}

	std::cout << "Print by DFS" << std::endl;
	std::stack<node_t*> nodeStack;
	nodeStack.push(mRoot);
	while (!nodeStack.empty()) {
		node_t* next = nodeStack.top();
		nodeStack.pop();

		for (int i = 0; i < next->depth; ++i) {
			std::cout << ' ';
		}

		std::cout << '-' << "point[x, y]: "  << next->point.coords[X] << ", " << next->point.coords[Y] << '\n';

		if (next->left != nullptr) {
			nodeStack.push(next->left);
		}

		if (next->right != nullptr) {
			nodeStack.push(next->right);
		}
	}

	std::cout << "Print by DFS end\n";
}

void KDTree::PrintByBFS(void) const
{
	if (mRoot == nullptr) {
		return;
	}

	std::cout << "Print by BFS" << std::endl;
	std::queue<node_t*> nodeQueue;
	nodeQueue.push(mRoot);
	while (!nodeQueue.empty()) {
		node_t* next = nodeQueue.front();
		nodeQueue.pop();

		for (int i = 0; i < next->depth; ++i) {
			std::cout << ' ';
		}

		std::cout << '-' << "point[x, y]: " << next->point.coords[X] << ", " << next->point.coords[Y] << '\n';

		if (next->left != nullptr) {
			nodeQueue.push(next->left);
		}

		if (next->right != nullptr) {
			nodeQueue.push(next->right);
		}
	}

	std::cout << "Print by BFS end\n";
}
