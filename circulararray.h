#include <iostream>
using namespace std;

template <class T>
class CircularArray{
private:
    T *array;
    int capacity;
    int back, front;
    int sizeofarray;


public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data);
    void push_back(T data);
    void set_front_back();
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void display();
    void clear();
    T &operator[](int);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");

private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray(){
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity){
    this->capacity = _capacity;
    this->front = this->back = -1;
    this->array = new T[_capacity];
    this->sizeofarray = 0;
}

template <class T>
CircularArray<T>::~CircularArray(){
    delete[] array;
}

template <class T>
void CircularArray<T>::set_front_back(){
    front = 0;
    back = size()-1;
}

template <class T>
void CircularArray<T>::push_front(T data){
    T* new_array = nullptr;
    if(size()==capacity){ 
        new_array = new T[capacity+1];
        capacity++; }
    else new_array = new T[size()+1];

    new_array[0] = data;
    for(int i=0;i<size();i++){
        new_array[i+1] = array[i]; 
    }
    delete[] array;
    array = new_array;
    sizeofarray++;
    set_front_back();
    
}

template <class T>
void CircularArray<T>::push_back(T data){
    if(size()==capacity){
        T* new_array = new T[capacity+1];
        for(int i=0;i<size();i++)
            new_array[i] = array[i];
        delete [] array;
        array = new_array;
        capacity++; 
    }
    
    array[size()] = data;
    sizeofarray++;
    set_front_back();

}

template <class T>
void CircularArray<T>::insert(T data, int pos){
    T* new_array = nullptr;
    if(size()==capacity){ 
        new_array = new T[capacity+1];
        capacity++; }
    else new_array = new T[size()+1];

    for(int i=size()+1;i>=pos;i--)
        new_array[i] = array[i-1]; 
    for(int i=0;i<pos;i++)
        new_array[i] = array[i]; 
    new_array[pos-1] = data;
    delete[] array;
    array = new_array;
    sizeofarray++;
    set_front_back();

}

template <class T>
T CircularArray<T>::pop_front(){
    if(size()==0)
        return -1;
    T* new_array = new T[size()-1];
    int value = array[0];
    for(int i=0;i<size();i++)
        new_array[i] = array[i+1]; 
    delete[] array;
    array = new_array;
    sizeofarray--;
    set_front_back();

    return value;
}

template <class T>
T CircularArray<T>::pop_back(){
    if(size()==0)
        return -1;
    T* new_array = new T[size()-1];
    int value = array[size()-1];
    for(int i=0;i<size()-1;i++)
        new_array[i] = array[i]; 
    delete[] array;
    array = new_array;
    sizeofarray--;
    set_front_back();
    return value;
}

template <class T>
bool CircularArray<T>::is_full()
{
    return front == next(back) && !is_empty();
}

template <class T>
bool CircularArray<T>::is_empty(){
    return front == -1;
}

template <class T>
int CircularArray<T>::size(){
    return sizeofarray;
}


template <class T>
void CircularArray<T>::display(){
    for (int i = 0; i < size(); i++)
        cout << (*this)[i] << " ";
    cout << endl;
}

template <class T>
void CircularArray<T>::clear(){
    /* ACL: Bien */
    for(int erase = 0;erase<size();erase++){
      array[erase] = '\0';
    }
    set_front_back();

}

template <class T>
T &CircularArray<T>::operator[](int pos){
    return array[pos];
}

template <class T>
void CircularArray<T>::sort(){
    int temp;
    //Bubble sort
    for(int i=0;i<size();i++){		
		for(int j=i+1;j<size();j++){
			if(array[i]>array[j]){
				temp  =array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
    set_front_back();

}

template <class T>
bool CircularArray<T>::is_sorted(){
    bool sorted=true;
    if (size()==0) return false;
    /*ACL: Un array vacío si está ordenado por default*/
    for(int i=0;i<size()-1;i++)
        if(array[i] > array[i+1]) return false;
    return sorted;
    
}

template <class T>
int CircularArray<T>::prev(int index){
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index){
    return (index + 1) % capacity;
}

template <class T>
void CircularArray<T>::reverse(){
    int start=0, end=size()-1;
    while (start < end){
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}


template <class T>
string CircularArray<T>::to_string(string sep){
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}
