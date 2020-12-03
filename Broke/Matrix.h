#pragma once
#include <list>
#include <iostream>

using namespace std;

template<class T>
class Matrix
{
public:
	Matrix();
	~Matrix();

	friend ostream& operator<<(ostream &out, Matrix &matrix)
	{
		if (matrix.getWidth() != -1 && matrix.getHeight() != -1 && (*matrix.getMatrix()) != nullptr)
		{
			out << matrix.getWidth() << " " << matrix.getHeight() << endl;
			for (int y = 0; y < matrix.getHeight(); y++) 
			{
				for (int x = 0; x < matrix.getWidth(); x++)
				{
					out << matrix.getElement(x, y) << " ";
				}
				out << endl;
			}
		}
		return out;
	}
	friend istream& operator>>(istream &in, Matrix &matrix)
	{
		int w, h;
		T temp;
		in >> w >> h;
		matrix.setDimensions(w, h);
		for (int y = 0; y < matrix.getHeight(); y++)
		{
			for (int x = 0; x < matrix.getWidth(); x++)
			{
				in >> temp;
				matrix.setElement(x, y, temp);
			}
		}

		return in;
	}

	void setDimensions(int width, int height);
	void getDimensions(int &width, int& height);

	int getWidth();
	int getHeight();

	void setWidth(int width);
	void setHeight(int height);

	T **getMatrix();
	T & getElement(int x, int y);
	T & getElement(int n);

	void setElement(int x, int y, T element);
	void setElement(int n, T element);

	list<int> *getAllCoordinatesOfElement(T element);

private:
	int width, height;
	T *matrix;
};

template<class T>
inline Matrix<T>::Matrix()
{
	matrix = nullptr;
	width = -1;
	height = -1;
}

template<class T>
inline Matrix<T>::~Matrix()
{
}

template<class T>
inline void Matrix<T>::setDimensions(int width, int height)
{
	
	if ((width != this->width || this->height != this->height) && width != -1 && height != -1) {
		T *newmatrix = new T[width * height];
		if (matrix != nullptr) {
			for (int y = 0; y < height && y < this->height; y++) {
				for (int x = 0; x < width && x < this->width; x++) {
					newmatrix[x + y * width] = matrix[x + y * this->width];
				}
			}
		}
		matrix = newmatrix;
	}
	this->width = width;
	this->height = height;
}

template<class T>
inline void Matrix<T>::getDimensions(int & width, int & height)
{
	width = this->width;
	height = this->height;

}

template<class T>
inline int Matrix<T>::getWidth()
{
	return width;
}

template<class T>
inline int Matrix<T>::getHeight()
{
	return height;
}

template<class T>
inline void Matrix<T>::setWidth(int width)
{
	if (width != this->width && width != -1 && height != -1) {
		T *newmatrix = new T[width * height];
		if (matrix != null) {
			for (int y = 0; y < height && y < this->height; y++) {
				for (int x = 0; x < width && x < this->width; x++) {
					newmatrix[x + y * width] = matrix[x + y * this->width];
				}
			}
		}
		matrix = newmatrix
	}
	this->width = width;
}

template<class T>
inline void Matrix<T>::setHeight(int height)
{
	if (height != this->height && width != -1 && height != -1) {
		T *newmatrix = new T[width * height];
		if (matrix != null) {
			for (int y = 0; y < height && y < this->height; y++) {
				for (int x = 0; x < width && x < this->width; x++) {
					newmatrix[x + y * width] = matrix[x + y * this->width];
				}
			}
		}
		matrix = newmatrix
	}
	this->height = height;
}

template<class T>
inline T ** Matrix<T>::getMatrix()
{
	return &matrix;
}

template<class T>
inline T & Matrix<T>::getElement(int x, int y)
{
	return matrix[x + y * width];
}

template<class T>
inline T & Matrix<T>::getElement(int n)
{
	return matrix[n];
}

template<class T>
inline void Matrix<T>::setElement(int x, int y, T element)
{
	matrix[x + y * width] = element;
}

template<class T>
inline void Matrix<T>::setElement(int n, T element)
{
	matrix[n] = element;
}

template<class T>
inline list<int>* Matrix<T>::getAllCoordinatesOfElement(T element)
{
	list<int> *listint = new list<int>();
	int max = width * height;
	for (int i = 0; i < max; i++) {
		if (matrix[i] == element) {
			listint->push_back(i);
		}
	}
	return listint;
}
