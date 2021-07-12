 #include<iostream>
using namespace std;
struct node {
	int info;
	node* llink;
	node* rlink;
};
class Bst {
private:
	//int height(int);     //why these functions are in private?
	void in_order(node*);  //why we are passing arguments in class?
	void Delete(node*&);
	node* first, * newnode;
public:
//	Bst():first(NULL),newnode(NULL){}      // constructor?
 Bst()
 {
 	first=NULL;
 	newnode=NULL;
 }

	//void height_tree();
	void Deletetree(int);
	void inorder();
	void insert(int);
};
void Bst::Deletetree(int var) {
	if (first == NULL) {
		cout << "Tree is empty ! " << endl;
		exit(1);
	}
	else {
		bool found = false;
		node* current = first;
		node* trailcurrent = NULL;
		while (current != NULL && !found) {
			
			if (current->info == var)
				found = true;
			else {
				trailcurrent = current;
			if (current->info > var)
			current = current->llink;
			else
			current = current->rlink;
			}
		}
		if (trailcurrent->info > var && found)
			Delete(trailcurrent->llink);
		else if (trailcurrent->info < var && found)
			Delete(trailcurrent->rlink);
		else
			if (!found) {
				cout << "The item doesnot found in the tree! ";
				exit(1);
			}
	}
}
void Bst::Delete(node*& p) {
	node* temp = NULL;
	if (p->llink == NULL && p->rlink == NULL) {
		temp = p;
		p = NULL;
		delete temp;
	}
	else if (p->llink == NULL) {
		temp = p;
		p = temp->rlink;
		delete temp;
	}
	else if (p->rlink == NULL) {
		temp = p;
		p = temp->llink;
		delete temp;
	}
	else {
		node* current = p->rlink;
		//node* trailcurrent = current;
		while (current->llink != NULL) {
			current = current->llink;
		}
		current->llink = p->llink;
		temp = p;
		p = p->rlink;
		delete temp;
	}
}
void Bst::insert(int var) {
	newnode = new node;
	newnode -> info = var;
	newnode->llink = NULL;
	newnode->rlink = NULL;
	if (first == NULL)
		first = newnode;
	else {
		node* current = first;
		node* trailcurrent = NULL;
		while (current != NULL) {
			trailcurrent = current;
			if (current->info > var)
				current = current->llink;
			else
				current = current->rlink;
		}
		if (trailcurrent->info > var)
			trailcurrent->llink = newnode;
		else
			trailcurrent->rlink = newnode;
	}
}
void Bst::inorder(){
	in_order(first);
}
void Bst::in_order(node* p){
	if (p != NULL) {
		in_order(p->llink);
		cout << "Entered value is : " << p->info << endl;
		in_order(p->rlink);
}
}
int main() {
	Bst b1;
	b1.insert(5);
	b1.insert(8);
	b1.insert(3);
	b1.insert(12);
	b1.insert(9);
	cout << endl;
	b1.inorder();
	cout << endl;
	//b1.Deletetree(201);
//	b1.Deletetree(111);
	b1.Deletetree(12);
	b1.inorder();
	return 0;
}
