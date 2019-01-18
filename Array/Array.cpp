template<class T>
class GenericArray {
public:
	GenericArray(int s) {};
	~GenericArray();
private:
	T *elements;
	int size;
};

GenericArray::GenericArray(int s){
	size = s;
	elements = new T[size];
};

GenericArray::~GenericArray(){
	delete[] elements;
};