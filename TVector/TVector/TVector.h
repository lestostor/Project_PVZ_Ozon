#pragma once
#include <iterator>
//  Copyright 2025 Shcherbakova Olesya

#define STEP_OF_CAPACITY 15

enum Status { Busy, Deleted, Empty };
template <class T>

class TVector {
    T* _vec;
    Status* _status;
    size_t _size;
    size_t _capacity;

 public:
    //  constructors
    explicit TVector();
    explicit TVector(int);  //  empty vector
    TVector(std::initializer_list<T>);  //  convert list to vector
    TVector(const TVector<T>&);  //  copy
    ~TVector();  //  destructor

    //  getters
    inline size_t size() const noexcept {
        return this->_size;
    }

    inline size_t capacity() const noexcept {
        return this->_capacity;
    }

    inline T* data() const noexcept {
        return _vec;
    }

    inline T* begin() const noexcept {
        return _vec;
    }

    inline T* end() const noexcept {
        return _vec + _size;
    }

    inline T& front() const noexcept {
        return *_vec;
    }

    inline T& back() const noexcept {
        return *(_vec + _size - 1);
    }

    inline bool is_empty() const noexcept {
        for (int i = 0; i < _size; i++) {
            if (_status[i] == Status::Busy) return false;
        }
        return true;
    }

    void clear();
    void push_back(const T& value);

 private:
    T* reset_memory(int new_size);
};

template <class T>
TVector<T>::TVector() {
    _size = 0;
    _capacity = 0;
    _vec = nullptr;
    _status = nullptr;
}

template <class T>
TVector<T>::TVector(int size) {
    _size = size;
    _capacity = (_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    _vec = new T[_capacity];
    _status = new Status[_capacity];

    for (int i = 0; i < _capacity; i++)
        _status[i] = Status::Empty;
}

template <class T>
TVector<T>::TVector(std::initializer_list<T> mass) {
    _size = mass.size();
    _capacity = (_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
    _vec = new T[_capacity];
    _status = new Status[_capacity];

    auto it = mass.begin();
    for (int i = 0; i < _capacity; i++, it++) {
        if (i < _size) {
            _vec[i] = *it;
            _status[i] = Status::Busy;
        }
        else _status[i] = Status::Empty;
    }
}

template <class T>
TVector<T>::TVector(const TVector& other) {
    _size = other._size;
    _capacity = _size / STEP_OF_CAPACITY * STEP_OF_CAPACITY + STEP_OF_CAPACITY;
    _vec = new T[other._capacity];
    _status = new Status[_capacity];

    for (int i = 0; i < _capacity; i++) {
        if (i < other._size) {
            _vec[i] = other._vec[i];
            _status[i] = Status::Busy;
        }
        else _status[i] = Status::Empty;
    }
}

template <class T>
void TVector<T>::clear() {
    for (int i = 0; i < _size; i++)
        _status[i] = Status::Empty;
}

template <class T>
T* TVector<T>::reset_memory(int new_size) {
    if (new_size >= _capacity) {
        _capacity = (new_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
        T* new_vec = new T[_capacity];

        for (int i = 0; i < _size; i++)
            if (_status[i] != Status::Empty
                && _status[i] != Status::Deleted) new_vec[i] = _vec[i];
        _size = new_size;
        delete[] _vec;
        return new_vec;
    }
    else return _vec;
}

template <class T>
void TVector<T>::push_back(const T& value) {
    _vec = reset_memory(++_size);
    _vec[_size - 1] = value;
    _status[_size - 1] = Status::Busy;
}

template <class T>
TVector<T>::~TVector() {
    delete[] _vec;
    delete[] _status;
}
