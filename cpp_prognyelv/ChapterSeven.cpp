#include "ChapterSeven.h"

using namespace std;

// 1. 

void Function(char* ch, int &i) {
	cout << ch << " " << i << endl;
}

typedef void (*FP)(char*, int&);

void FuncParamFunc(char* ch, int &i, FP fp) {
	(fp)(ch, i);
}

FP RetFunPointer() {
	char* arr = "alma";
	int i = 1;
	return Function;
}

void Using() {
	char arr[] = "alma";
	int i = 1;
	Function(arr, i);

	FuncParamFunc(arr, i, Function);

	FP p = RetFunPointer();
	(p)(arr, i);
}

// 2. 

typedef int(&rifii) (int, int);

// 3.

void HelloParam(int argc, char *argv[]) {
	//cout << "Hello " << argv[1] << endl;

	for (int i = 1; i < argc; i++) {
		cout << "Hello " << argv[i] << endl;
	}
}

// 4. 

void ReadFileFromParam(int argc, char *argv[]) {
	string line;
	ifstream myfile;
	for (int i = 1; i < argc; i++) {
		myfile.open(argv[i]);
		if (myfile.is_open()) {
			while (getline(myfile, line))
			{
				cout << line << '\n';
			}
			myfile.close();
		}
	}
}

// 5. 

// #include <stdio.h>   /* Link section */
// int total = 0;       /* Global declaration, definition section */
// int sum(int, int);  /* Function declaration section */
// int main()          /* Main function */
// {
// 	printf("This is a C basic program \n");
// 	total = sum(1, 1);
//	printf("Sum of two numbers : %d \n", total);
//	return 0;
// }

// int sum(int a, int b) /* User defined function */
// {
// 	return a + b;      /* definition section */
// }

int sum(int a, int b) {
	return a + b;
}

void FromCToCpp() {
	int total = 0;
	total = sum(5, 10);
	cout << "total: " << total << endl;
}

// 6. 

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

void QuickerSort() {
	int n;
	qsort(values, 6, sizeof(int), compare);
	for (n = 0; n < 6; n++) {
		cout << values[n] << endl;
	}
}

// 7.

struct Tnode {
	string word;
	int count;
	Tnode* left;
	Tnode* right;
	Tnode()
	{
		count = 0;
		left = NULL;
		right = NULL;
	}
	~Tnode() {}
} root;

Tnode* rootNode = &root;

Tnode* getLastTnode(Tnode* node) {
	Tnode* left = NULL;
	Tnode* right = NULL;
	int max = 0;

	if (node->left != NULL)
		left = getLastTnode(node->left);

	if (node->right != NULL)
		right = getLastTnode(node->right);

	if (node->left == NULL && node->right == NULL)
		return node;

	if (left != NULL)
		if (right != NULL)
			if (left->count > right->count)
				return left;
			else
				return right;
		else
			return left;
	else
		return right;

}

int getRow(int num) {

	for (int i = 1; i <= num + 1; i++) {
		if (pow(2, i - 1) - 2 < num && pow(2, i) - 2 >= num) {
			return i;
		}
	}
}

Tnode* getNode(Tnode* node, int count) {
	Tnode* localNode = node;
	int localCount = count;

	if (node->count == count)
		return node;
		
	for (int i = 0; i < count; i++) {
		if (localNode->left->count == count)
			return localNode->left;
		if (localNode->right->count == count)
			return localNode->right;
		for (int j = 0; j < count; j++) {
			int root = (localCount - 1) / 2;
			if (localNode->left->count == root)
				localNode = localNode->left;
			if (localNode->right->count == root)
				localNode = localNode->right;
			localCount = root;
		}
		localCount = count;
	}
}

Tnode* findNode(Tnode* node) {
	//cout << node->count << endl;
	int num = node->count;
	int row = getRow(num);

	if (num == pow(2, row) - 2) {
		if (num == 0)
			return node;
		else {
			int length = pow(2, row - 1);
			int last = num - (length - 1);
			return getNode(rootNode, last);
		}
	}
	else if (num < pow(2, row) - 2) {
		return getNode(rootNode, floor(num/2));
	}
	else
		cout << "error!" << endl;

	return node;
}

void AddElemToTnode(string newString) {
	//  cout << "count: " << root.count << " word: " << root.word << endl;
	//  if (root.left == NULL) cout << "left is null" << endl;
	//  else cout << "left is not null" << endl;
	//  if (root.right == NULL) cout << "rigth is null" << endl;
	//  else cout << "rigth is not null" << endl;
	//  Tnode* newNode = new Tnode();
	//  delete newNode;

	Tnode* newNode = new Tnode();
	newNode->word = newString;

	Tnode* lastNode;
	lastNode = getLastTnode(rootNode);
	cout << "last node: " << lastNode->count << endl;
	newNode->count = (lastNode->count)+1;
	lastNode = findNode(lastNode);

	if (lastNode->left == NULL)
		lastNode->left = newNode;
	else
		lastNode->right = newNode;

	//cout << getLastTnode(rootNode)->count << endl;

}

void DeledeteNode(Tnode* node) {
	delete node;
}

// 8.