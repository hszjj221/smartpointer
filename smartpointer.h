#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_

template<typename T>
class SmartPointer {
private:
	T *pointer_;
public:
	SmartPointer():pointer_(nullptr) {}
	SmartPointer(T *p):pointer_(p) {}
	~SmartPointer() {
		if (pointer_) {
			delete pointer_;
		}
	}
};

#endif // !_SMARTPOINTER_H_

