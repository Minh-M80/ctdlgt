Note about stack

struct Stack{
	NodePtr top;
	int size;
};

printData(Data data){
	
}

void initialize(Stack &s){
	s.top=NULL;
	s.size=0;
}

bool isEmpty(Stack s){
	return s.top=NULL;
}
int sizeOfStack(Stack s){
	return s.size;
}
NodePtr createNode(Data data){
	NodePtr p=new Node;
	if(p=NULL) return NULL;
	p->next=NULL;
	p->data=data;
	return p;
}

void push(Stack &s,Data x){
	NodePtr p=createNode(x);
	if(p==NULL){
		cout<<"Khong them duoc vao stack do khong cap phat bo nho dong";
		return;
	}
	p->next=s.top;
	s.top=p;
	s.size++;
}


void pop(Stack &s,Data &x){
	if(isEmpty(s)) cout<<"Ngan xep rong"<<endl;
	else{
		NodePtr p=s.top;
		x=p->data;
		s.top=s.top->next;
		s.top->next=NULL;
		s.size--;
		delete p;
	}
}

void traverse(Stack s){
	if(isEmpty(s)) cout<<"Ngan xep rong"
	else{
		NodePtr q=s.top;
		while(q!=NULL){
			printData(q->data);
			q=q->next;
		}
	}
}




















