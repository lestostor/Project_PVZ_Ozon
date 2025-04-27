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

    void clear();

    //  add element
    void push_back(const T&);
    void push_front(const T&);
    void insert(int*, const T&);

    //  find
    int find(const T&);

    // delete element
    void pop_back();
    void pop_front();
    void erase(int*);

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
        int i = 0;
        for (i; _status[i] != Status::Busy; i++)
            continue;
        return _vec + i;
    }

    inline T* end() const noexcept {
        return _vec + _size;
    }

    inline T& front() const noexcept {
        return *(begin());
    }

    inline T& back() const noexcept {
        return *(end() - 1);
    }

    inline bool is_empty() const noexcept {
        for (int i = 0; i < _size; i++) {
            if (_status[i] == Status::Busy) return false;
        }
        return true;
    }

 private:
    T* reset_memory(int);
    T* reset_memory_for_deleted(int, int);
    int count_deleted();
    int count_right_pos(int*);
    inline bool is_full() const noexcept {
        return !is_empty();
    }
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
void TVector<T>::push_back(const T& value) {
    _vec = reset_memory(++_size);
    _vec[_size - 1] = value;
    _status[_size - 1] = Status::Busy;
}

template <class T>
void TVector<T>::push_front(const T& value) {
    _vec = reset_memory(++_size);
    for (int i = _size - 1; i > 0; i--) {
        _vec[i] = _vec[i - 1];
    }
    _vec[0] = value;
    _status[0] = Status::Busy;
}

template <class T>
void TVector<T>::insert(int* pos, const T& value) {
    int right_pos = count_right_pos(pos);
    _vec = reset_memory(++_size);
    int i = _size + count_deleted() - 1;
    for (i; i > right_pos; i--) {
        _vec[i] = _vec[i - 1];
    }
    _vec[i] = value;
}

template <class T>
int TVector<T>::find(const T& value) {
    int deleted = 0;
    for (int i = 0; i < _size; i++) {
        if (_status[i] != Status::Busy) deleted++;
        if (_vec[i] == value && _status[i] == Status::Busy)
            return i - deleted;
    }
    return -1;
}

template <class T>
void TVector<T>::pop_back() {
    _status[_size - 1] = Status::Empty;
    _vec = reset_memory_for_deleted(_size - 1, count_deleted());
}

template <class T>
void TVector<T>::pop_front() {
    int first_not_deleted = 0;
    while (_status[first_not_deleted] == Status::Deleted) first_not_deleted++;
    _status[first_not_deleted] = Status::Deleted;
    _vec = reset_memory_for_deleted(_size - 1, count_deleted());
}

template <class T>
void TVector<T>::erase(int* pos) {
    int right_pos = count_right_pos(pos);
    _status[right_pos] = Status::Deleted;
    _vec = reset_memory_for_deleted(_size - 1, count_deleted());
}

template <class T>
T* TVector<T>::reset_memory(int new_size) {
    if (new_size >= _capacity) {
        _capacity = (new_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
        T* new_vec = new T[_capacity];

        for (int i = 0; i < _size; i++)
            if (_status[i] == Status::Busy) new_vec[i] = _vec[i];
        _size = new_size;
        delete[] _vec;
        return new_vec;
    }
    return _vec;
}

template <class T>
T* TVector<T>::reset_memory_for_deleted(int new_size, int deleted_count) {
    if (deleted_count >= 0.1 * _size) {
        _capacity = (new_size / STEP_OF_CAPACITY + 1) * STEP_OF_CAPACITY;
        T* new_vec = new T[_capacity];
        for (int i = 0, j = 0; i < _size; i++) {
            if (_status[i] == Status::Busy) {
                new_vec[j] = _vec[i];
                _status[j] = Status::Busy;
                j++;
            }
        }
        delete[] _vec;
        _size = new_size;
        return new_vec;
    }
    _size = new_size;
    return _vec;
}

template <class T>
int TVector<T>::count_deleted() {
    int count = 0;
    for (int i = 0; i < _size; i++) {
        if (_status[i] == Status::Deleted ||
            _status[i] == Status::Empty)
            count++;
    }

    return count;
}

template <class T>
int TVector<T>::count_right_pos(int* pos) {
    int* correct = begin(), i;
    for (i = 0; i < _size; i++) {
        if (_status[i] != Status::Deleted) correct++;
        if (correct == pos + 1) break;
    }
    return i;
}

template <class T>
TVector<T>::~TVector() {
    delete[] _vec;
    delete[] _status;
}
