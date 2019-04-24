#include <iostream>

#include "KdTree.cpp"

using namespace kdtree;
//test sample
int main() {
	vector<Point> points = {{1,2,30}, {2,3,14}, {3,4,66}, {4,5,26}, {1,12,33}, {1,52,73}};
	KdTree kd;
	if(kd.buildKdTree(points))
	{
		kd.addNode({100,-100,32});
		kd.deleteNode({1, 52, 73});
		kd.printKdTree();
		auto node1 = kd.findMin(kd.getKdTreeRoot(), 0, 0);
		auto node2 = kd.findNearestNode({3, -1000});
		auto cluster = kd.findNearestNodeCluster({4, 5, 0}, 30);
		auto node3 = kd.getNode({20, 3, 14});
		if(node3 == nullptr)
			cout << "no node found" << endl;
		else
			cout << "node found:" << node3->val[0] << "," << node3->val[1] << "," << node3->val[2] << endl;
		return 1;
	}
	else
	{
		cout << "something wrong" << endl;
		return -1;
	}
	
	return 0;
}
