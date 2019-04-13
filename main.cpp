#include <iostream>

#include "kdTree.cpp"
//test sample
int main() {
	vector<Point> points = {{1,2,30}, {2,3,14}, {3,4,66}, {4,5,26}, {1,12,33}, {1,52,73}};
	kdTree kd;
	if(kd.buildKdTree(points))
	{
		kd.addNode({100,-100,32});
		kd.deleteNode({1, 52, 73});
		kd.printKdTree();
		auto node1 = kd.findMin(kd.getKdTreeRoot(), 0, 0);
		auto node2 = kd.findNearestNode({3, -1000});
		auto cluster = kd.findNearestNodeCluster({4, 5, 0}, 30);
		return 1;
	}
	else
	{
		cout << "something wrong" << endl;
		return -1;
	}
	
	return 0;
}
