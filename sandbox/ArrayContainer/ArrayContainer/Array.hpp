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

struct ConArray 
{
private:
	int* m_region;
	size_t m_size;
	int length_;
public:
	ConArray()
		: m_region{ nullptr }
		, m_size{ 0 }
		, length_{ 0 }
	{
	}

	~ConArray() {
		if (m_region) {
			delete[] m_region;
		}
	}

	void push_back(int value) {
		int* new_region = new int[m_size + 1]; // новая область памяти
		for (size_t i = 0; i < m_size; ++i) {
			new_region[i] = m_region[i]; // копирование элементов
		}
		new_region[m_size] = value; // добавление нового элемента
		delete[] m_region; // удаление старой области

		//! Выделенная расширенная память используем дальше
		m_region = new_region; // сохранение новой в мембер
		//! Увеличиваем размер в самом конце, чтобы при исключениях в new не получался m_size вводящий в заблуждение.
		m_size += 1; // обновление информации о размере
	}

	// void insert(int pos, int value);
	// void erase();

	size_t size() {
		return m_size;
	}

	int& operator [](int idx) {
		return m_region[idx];
	}

	int operator [](int idx) const {
		return m_region[idx];
	}
};

