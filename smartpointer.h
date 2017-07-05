#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_

template<typename T>
class BasePointer {
private:
	T *pointer_;
	int ref_count_;
public:
	BasePointer(T *p) : pointer_(p), ref_count_(0) {}
	void IncCount() {
		++ref_count_;
	}
	void DecCount() {
		--ref_count_;
	}
	int GetCount() {
		return ref_count_;
	}
	virtual ~BasePointer() {
		delete pointer_;
	}
};

template<typename T>
class SmartPointer {
private:
	BasePointer *pointer_;
public:
	SmartPointer():pointer_(nullptr) {}
	SmartPointer(T *p):pointer_(p) {
		if (pointer_)
			pointer_->IncCount();
	}
	~SmartPointer() {
		pointer_->DecCount();
		if (pointer_->GetCount() == 0) {
			delete pointer_;
		}
	}

	SmartPointer(const SmartPointer& sp) {
		pointer_ = sp.pointer_;
		pointer_->IncCount();
	}
	SmartPointer& operator = (const SmartPointer& sp) {
		if (this == &sp)
			return *pointer_;
		sp.pointer_->IncCount();
		pointer_->DecCount();
		if (pointer_->GetCount() == 0)
			delete pointer_;
		pointer_ = sp.pointer_;
		return *this;
	}
};

#endif // !_SMARTPOINTER_H_

