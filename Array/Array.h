//template class that takes in generic items (elements) of a defined size
template<class T>
class GenericArray {
public:
	GenericArray(int s) {};
	~GenericArray();
private:
	T *elements;
	int size;
};

//intialization-- requires input of size
GenericArray::GenericArray(int s){
	size = s;
	elements = new T[size];
};

//garbage collection-- requires implementation
GenericArray::~GenericArray(){
	delete[] elements;
};
