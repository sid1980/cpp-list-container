#pragma once

//! ���������������� ��������� 
/*
- �����/� (����� ���� ���������) ���������� ��������� � ����� ���������� ( push_back )
-����� / � ������� ��������� � ������������ �������(insert)
- ����� / � �������� ��������� �� ����������(erase)
- ����� ��������� �������� ������� ����������(size)
- ����� / � ��������� ������� �� �������(operator[])
��������� �������� � ������ ��������������� ������ � ���������������� �����,
��������������� �� ����������.
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
		int* new_region = new int[m_size + 1]; // ����� ������� ������
		for (size_t i = 0; i < m_size; ++i) {
			new_region[i] = m_region[i]; // ����������� ���������
		}
		new_region[m_size] = value; // ���������� ������ ��������
		delete[] m_region; // �������� ������ �������

		//! ���������� ����������� ������ ���������� ������
		m_region = new_region; // ���������� ����� � ������
		//! ����������� ������ � ����� �����, ����� ��� ����������� � new �� ��������� m_size �������� � �����������.
		m_size += 1; // ���������� ���������� � �������
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

