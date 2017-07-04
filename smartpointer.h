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

	SmartPointer(const SmartPointer& sp) {
		pointer_ = sp.pointer_;
	}
	SmartPointer& operator = (const SmartPointer& sp) {
		if (this == &sp)
			return *pointer_;
		if (pointer_)
			delete pointer_;
		pointer_ = sp.pointer_;
		return *this;
	}
};

#endif // !_SMARTPOINTER_H_

