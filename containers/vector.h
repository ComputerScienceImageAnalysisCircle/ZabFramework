/**
 *
 * Implementation fo the vector
 *
 * Author: Patryk Zabkiewicz, April 2015
 *
*/


#ifndef VECT_SPC
#define VECT_SPC 4
#endif


template <typename T>
struct vector {
	int capacity;
	int size;
	T *obj;
	
	vector() {
		this->size = 0;
		this->capacity = 4;
		this->obj = new T[VECT_SPC];
	}
}


template <typename T>
T pop_back(vector *v) {
	T tmp = v->obj[v->size];
	v->size--;
	if(v->size == v->capacity-VECT_SPC) {
		v->capacity -= VECT_SPC;
		
	}
	return tmp;
}

template <typename T>
void push_back(vector *v, T nobj) {

	int tmp_capacity;

	v->size++;
	if( v->size == v->capacity) {
		tmp_capacity = v->capacity;
		v->capacity += VECT_SPC;
		T *nspace = new T[v->capacity];

		for(int i=0; i < tmp_capacity; i++) {
			nspace[i] = v->obj[i];
		}
		delete v->obj;
		v->obj = nspace;
	}
	else {
		v->obj[v->size] = nobj;
	}
}

