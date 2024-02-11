#pragma once

#include "Point.h"
#include "Node.h"

class KDTree {
public:
	KDTree();
	KDTree(const point2D_t& point);
	KDTree(const KDTree& other);
	virtual ~KDTree();


	void Insert(const point2D_t& point);
	node_t* InsertRecursive(node_t* node, const point2D_t& point, const size_t depth);

	node_t* NeareastSearchOrNull(const point2D_t& point);

	void PrintByDFS(void) const;
	void PrintByBFS(void) const;

private:
	static const size_t k;
	node_t* mRoot;

	void ClearKDTreeRecursive(node_t* node);

	node_t* DeepCopyRecursive(node_t* node);
};