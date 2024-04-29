#pragma once
#include <cstring>

template <class T_1, class T_2> struct Pair {
    T_1 key;
    T_2 value;
    int index;
};

template <class T_1, class T_2> class Map {
private:
    Pair<T_1, T_2>* data;
    int size;
    int capacity;
    int index = 0;

public:
    Map();
    ~Map();
    T_2& operator[](T_1 key);
    Pair<T_1, T_2>* begin();
    Pair<T_1, T_2>* end();
    void set(T_1 key, T_2 value);
    bool get(const T_1& key, T_2& value);
    int count();
    void clear();
    bool del(const T_1& key);
    bool includes(const Map<T_1, T_2>& other);
};

template <class T_1, class T_2> Map<T_1, T_2>::Map() : size(0), capacity(2) {
    data = new Pair<T_1, T_2>[capacity];
}

template <class T_1, class T_2> Map<T_1, T_2>::~Map() { delete[] data; }

template <class T_1, class T_2> T_2& Map<T_1, T_2>::operator[](T_1 key) {
    for (int i = 0; i < size; i++)
        if (data[i].key == key) {
            return data[i].value;
        }
    if (size == capacity) {
        Pair<T_1, T_2>* temp = new Pair<T_1, T_2>[capacity * 2];
        // for (int i = 0; i < size; i++) {
        //   temp[i] = data[i];
        // }
        memcpy(temp, data, sizeof(Pair<T_1, T_2>) * size);
        delete[] data;
        data = temp;
        capacity *= 2;
    }
    data[size].key = key;
    data[size].index = index++;
    return data[size++].value;
}

template <class T_1, class T_2> void Map<T_1, T_2>::set(T_1 key, T_2 value) {
    for (int i = 0; i < size; i++)
        if (data[i].key == key) {
            data[i].value = value;
            return;
        }
    if (size == capacity) {
        Pair<T_1, T_2>* temp = new Pair<T_1, T_2>[capacity * 2];
        // for (int i = 0; i < size; i++) {
        //   temp[i] = data[i];
        // }
        memcpy(temp, data, sizeof(Pair<T_1, T_2>) * size);
        delete[] data;
        data = temp;
        capacity *= 2;
    }
    data[size].key = key;
    data[size].value = value;
    data[size].index = index++;
    size++;
}

template <class T_1, class T_2> bool Map<T_1, T_2>::get(const T_1& key, T_2& value) {
    for (int i = 0; i < size; i++)
        if (data[i].key == key) {
            value = data[i].value;
            return true;
        }
    return false;
}

template <class T_1, class T_2> int Map<T_1, T_2>::count() { return size; }

template <class T_1, class T_2> void Map<T_1, T_2>::clear() {
    delete[] data;
    capacity = 2;
    data = new Pair<T_1, T_2>[capacity];
    size = 0;
    index = 0;
}

template <class T_1, class T_2> Pair<T_1, T_2>* Map<T_1, T_2>::begin() {
    return data;
}

template <class T_1, class T_2> Pair<T_1, T_2>* Map<T_1, T_2>::end() {
    return data + size;
}

template <class T_1, class T_2> bool Map<T_1, T_2>::del(const T_1& key) {
    for (int i = 0; i < size; i++)
        if (data[i].key == key) {
            // for (int j = i; j < size - 1; j++) {
            //   data[j] = data[j + 1];
            // }
            memcpy(data + i, data + i + 1, sizeof(Pair<T_1, T_2>) * (size - i - 1));
            memcpy(data + size - 1, data + size, sizeof(Pair<T_1, T_2>) * 1);
            size--;
            return true;
        }
    return false;
}

template <class T_1, class T_2>
bool Map<T_1, T_2>::includes(const Map<T_1, T_2>& other) {
    for (int i = 0; i < other.size; i++) {
        for (int j = 0; j < size; j++) {
            const char* temp;
            if (!this->get(other.data[i].key, temp)) {
                return false;
            }
            if (strcmp(temp, other.data[i].value) != 0) {
                return false;
            }
        }
    }
    return true;
}