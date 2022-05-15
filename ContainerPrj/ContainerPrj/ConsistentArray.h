#pragma once

//! последовательный контейнер 
/*
- метод/ы (может быть несколько) добавления элементов в конец контейнера ( push_back )
-метод / ы вставки элементов в произвольную позицию(insert)
- метод / ы удаления элементов из контейнера(erase)
- метод получения текущего размера контейнера(size)
- метод / ы получения доступа по индексу(operator[])
Допустимо добавить и другие вспомогательные методы с пользовательским кодом,
демонстрирующим их назначение.
*/

#include <iostream>
#include <new>
#include <stddef.h>
#include <stdint.h>

struct ConArray {
private:
	int* data_;
	size_t size_;
	int length_;
public:
	ConArray() 
		: data_{ nullptr }
		, size_{0}
		, length_{0}
	{
	}

    ~ConArray() {
		if (data_) { 
			delete[] data_;
		}
	}

	void push_back(int value) {
		if (size_ == 0) {
			length_ = 2;
			data_ = new int[length_];
			size_ += 1;
			data_[size_] = value;
			std::cout << size_ << " " << length_ << " " << value << std::endl;
			return;
		} 

		if (size_ < length_) {
				size_ += 1;
				data_[size_] = value;
				std::cout << size_ << " " << length_ << " " << value << std::endl;
		}
		else {
			length_ = size_ * 2;
			std::cout << size_ << " " << length_ << " " << value << std::endl;
			///delete[] data_;
			int* tmp = new int[size_];
			for (int i = 0; i < size_; ++i) {
				tmp[i] = data_[i];
			}
			std::cout << size_ << " " << length_ << " " << value << std::endl;

			delete[] data_;
			data_ = new int[length_];
			for (int i = 0; i < size_; ++i) {
				data_[i] = tmp[i];
			}
			size_ += 1;
			data_[size_] = value;
			std::cout << size_ << " " << length_ << " " << value << std::endl ;

			delete[] tmp;
		}
	}

	// void insert(int pos, int value);
	// void erase();

	size_t size() {
		return size_;
	}

	int& operator [](int idx) {
		return data_[idx];
	}

	int operator [](int idx) const {
		return data_[idx];
	}
};

