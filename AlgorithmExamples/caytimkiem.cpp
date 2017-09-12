#include <iostream>
using namespace std;
typedef int keytype;
struct Node
{
	keytype key;
	Node* left;
	Node* right;
	Node* parent; //cay cha
	Node (keytype k,Node* l = NULL,Node* r=NULL,Node* p=NULL)
		:key (k), left (l),right (r),parent (p) {};
};
struct BST
{
	Node* root; // cai goc
};
void initialize (BST& T)
{
	T.root = NULL;
}
bool isEmpty (const BST& T)
{
	if (T.root == NULL)
		return true;
	return false;
}

void insert (BST& T,keytype k)
{
	Node* z = new Node (k,NULL,NULL);
	Node* y = NULL; //con tro y di theo vet cua x
	Node* x = T.root; 
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent= y;
	if ( y == NULL)
		T.root = z;
	else if (z->key < y->key)
		y->left =z;
	else
		y->right =z;
}
void inorder (Node* x)
{
	if (x!=NULL)
	{
		inorder (x ->left);
		cout <<x->key<<" ";
		inorder (x->right);
	}
}
Node* search_min (Node* x)
{
	while (x->left !=NULL)
		x=x->left;
	return x;
}
Node* search_max (Node* x)
{
	while (x->right !=NULL)
		x=x->right;
	return x;
}
Node* search (BST& T,keytype k)
{
	Node* x =T.root;
	while (x!=NULL && x->key != k)
	{
		if (k < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}
Node* ptudisau (Node* x)
{
	if (x->right !=NULL)
		return search_min(x->right);
	Node* y =x->parent;
	while (y!=NULL && x==y->right)
	{
		x=y;
		y=y->parent;
	}
	return y;
}
void transplant(BST &T, Node* u, Node* v)
{
	if (u->parent == NULL)
		T.root = v;
	else if (u = u->parent->left)
		u->parent->left = v;
	else u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
}
void delete_tree(BST &T, Node* z)
{
	Node* y = NULL;
	if (z->left == NULL)
		transplant(T, z, z->right);
	else if (z->right == NULL)
		transplant(T, z, z->left);
	else y = search_min(z->right);
	if (y->parent != z)
	{
		transplant(T, y, y->right);
		y->right = z->right;
		y->right->parent = y;
	}
	transplant(T, z, y);
	y->left = z->left;
	y->left->parent = y;
}
int main ()
{
	BST t;
	initialize (t);
	int k;
	cout <<"Nhap gia tri khoa >0 (nhap so am de ket thuc): ";
	while (cin>>k && k>0)
	{
		cout <<"Nhap gia tri khoa >0 (nhap so am de ket thuc): ";
		insert (t,k);
	}
	if (isEmpty(t))
		cout <<"Ham rong \n";
	else
		cout <<"Ham ko rong \n";
	inorder(t.root);
	Node* x= search_min (t.root);//tao node de xuat vi tri min
	cout <<"Khoa nho nhat: "<<x->key<<endl;
	Node* y =search_max (t.root);
	cout <<"Khoa lon nhat: "<<y->key<<endl;
	cout <<"Nhap khoa can tim: ";
	cin >> k;
	Node* s = search (t,k);
	if (s!=NULL) {
		cout <<"Tim thay! \n";
		Node* z = ptudisau (s);
		cout <<"Phan tu di sau: "<<z->key;
	}
	else
		cout <<"Khong tim thay! \n";
	return 0;                                           
}