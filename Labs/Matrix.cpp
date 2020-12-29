#include "Matrix.h"
// Переменная для создания уникального id
unsigned int Matrix::idCounter = 0;

Matrix::Matrix(int columnsCount, int rowsCount)
{
	id = idCounter;
	idCounter++;

	this->columnsCount = columnsCount;
	this->rowsCount = rowsCount;

	// Выделяем память для строк
	data = new int* [rowsCount];
	for (int i = 0; i < rowsCount; i++)
	{
		// Выделяем память для элементов строк
		data[i] = new int[columnsCount];

		// Заполняем нулями вновь созданные элементы строк
		for (int j = 0; j < columnsCount; j++)
			data[i][j] = 0;
	}
}



Matrix::Matrix() : Matrix::Matrix(3, 3) /* Вызываем конструктор матрицы 3х3*/ {}

Matrix::Matrix(const Matrix& obj)
{
	// Как конструктор с параметрами, только данные берём из переданного объкта
	id = idCounter;
	idCounter++;

	columnsCount = obj.columnsCount;
	rowsCount = obj.rowsCount;

	data = new int* [rowsCount];
	for (int i = 0; i < rowsCount; i++)
	{
		data[i] = new int[columnsCount];
		for (int j = 0; j < columnsCount; j++)
			data[i][j] = obj.data[i][j];
	}
}

Matrix::~Matrix()
{
	// очищаем память выделенную для элементов строк
	for (int i = 0; i < rowsCount; i++)
		delete[] data[i];
	// очищаем память выделенную под строки
	delete[] data;
}

int Matrix::RowsCount()
{
	return rowsCount;
}

int Matrix::ColumnsCount()
{
	return columnsCount;
}

int Matrix::GetValue(int column, int row)
{
	return data[row][column];
}

bool Matrix::SetValue(int column, int row, int value)
{
	data[row][column] = value;
	return true;
}

std::string Matrix::ToString()
{
	std::string str = "";
	for (int i = 0; i < rowsCount; i++)
	{
		for (int j = 0; j < columnsCount; j++)
		{
			str += std::to_string(data[i][j]) + " ";
		}
		str += "\n";
	}
	str += "\0";
	return str;
}

void Matrix::SortRow(int row)
{
	// Сортируем пузырьком data[row]
	int temp = 0;
	for (int i = 0; i < columnsCount - 1; i++) 
		for (int j = 0; j < columnsCount - i - 1; j++)
			if (data[row][j] > data[row][j + 1]) 
			{
				temp = data[row][j];
				data[row][j] = data[row][j + 1];
				data[row][j + 1] = temp;
			}
}

void Matrix::SortColumn(int column)
{
	int temp = 0;
	// Сортируем пузырьком data[][column]
	for (int i = 0; i < rowsCount - 1; i++)
		for (int j = 0; j < rowsCount - i - 1; j++)
			if (data[j][column] > data[j + 1][column])
			{
				temp = data[j][column];
				data[j][column] = data[j + 1][column];
				data[j + 1][column] = temp;
			}
}

int Matrix::Id()
{
	return id;
}

Matrix& Matrix::operator=(const Matrix& obj)
{
	if (this == &obj)
		return *this;

	// Освобождаем память
	for (int i = 0; i < rowsCount; i++)
		delete[] data[i];
	delete[] data;


	columnsCount = obj.columnsCount;
	rowsCount = obj.rowsCount;

	// Выделяем память заного под новую матрицу и заполняем её
	data = new int* [rowsCount];
	for (int i = 0; i < rowsCount; i++)
	{
		data[i] = new int[columnsCount];
		for (int j = 0; j < columnsCount; j++)
			data[i][j] = obj.data[i][j];
	}
	return *this;
}

int& Matrix::operator[](int i)
{
	int col = i % columnsCount;
	int row = i / rowsCount;
	return data[row][col];
}

bool Matrix::operator()(int column, int row, int value)
{
	return SetValue(column, row, value);
}

bool Matrix::serialize(const char* path)
{
	std::ofstream f;
	try
	{
		f.open(path, std::ios::binary | std::ios::out);
	}
	catch (const std::exception&)
	{
		return false;
	}

	f.write((char*)&columnsCount, sizeof(columnsCount));
	f.write((char*)&rowsCount, sizeof(rowsCount));

	for (int i = 0; i < columnsCount; i++)
		for (int j = 0; j < rowsCount; j++)
			f.write((char*)&(data[i][j]), sizeof(data[i][j]));
	f.close();
	return true;
}

bool Matrix::deserialize(const char* path)
{
	std::ifstream f;
	Matrix* temp = nullptr;
	try
	{
		f.open(path, std::ios::binary | std::ios::in);
		int cc = 0;
		int rc = 0;
		f.read((char*)&cc, sizeof(columnsCount));
		f.read((char*)&rc, sizeof(rowsCount));
		temp = new Matrix(cc, rc);
		for (int i = 0; i < cc; i++)
			for (int j = 0; j < rc; j++)
			{
				int t = 0;
				f.read((char*)&(t), sizeof(t));
				temp->data[i][j] = t;
			}
		f.close();
	}
	catch (const std::exception&)
	{
		return false;
	}

	this->operator=(*temp);
	delete temp;
	return true;
}

Matrix operator+(const Matrix& obj1, const Matrix& obj2)
{
	// Сравниваем размерности
	if (obj1.columnsCount != obj2.columnsCount || obj1.rowsCount != obj2.rowsCount)
		return Matrix();

	// Создаём копию первой матрицы
	Matrix m(obj1);
	// Добавляем значения второй
	for (int i = 0; i < m.rowsCount; i++)
		for (int j = 0; j < m.columnsCount; j++)
			m.data[i][j] = m.data[i][j] + obj2.data[i][j];

	return m;
}

Matrix operator-(const Matrix& obj1, const Matrix& obj2)
{
	// Сравниваем размерности
	if (obj1.columnsCount != obj2.columnsCount || obj1.rowsCount != obj2.rowsCount)
		return Matrix();

	// Создаём копию первой матрицы
	Matrix m(obj1);
	// Отнимаем значения второй
	for (int i = 0; i < m.rowsCount; i++)
		for (int j = 0; j < m.columnsCount; j++)
			m.data[i][j] = m.data[i][j] - obj2.data[i][j];

	return m;
}

std::ostream& operator<<(std::ostream& os, const Matrix& obj)
{
	os << obj.columnsCount << " " << obj.rowsCount << "\n";
	for (int i = 0; i < obj.columnsCount; i++)
	{
		for (int j = 0; j < obj.rowsCount; j++)
			os << obj.data[i][j] << " ";
		os << "\n";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Matrix& obj)
{
	// Освобождаем память
	for (int i = 0; i < obj.rowsCount; i++)
		delete[] obj.data[i];
	delete[] obj.data;

	is >> obj.columnsCount >> obj.rowsCount;

	// Выделяем память заного под новую матрицу и заполняем её
	obj.data = new int* [obj.rowsCount];
	for (int i = 0; i < obj.rowsCount; i++)
	{
		obj.data[i] = new int[obj.columnsCount];
		for (int j = 0; j < obj.columnsCount; j++)
			is >> obj.data[i][j];
	}
	return is;
}

std::ofstream& operator<<(std::ofstream& ofs, const Matrix& obj)
{
	ofs << obj.columnsCount << " " << obj.rowsCount << "\n";
	for (int i = 0; i < obj.columnsCount; i++)
	{
		for (int j = 0; j < obj.rowsCount; j++)
			ofs << obj.data[i][j] << " ";
		ofs << "\n";
	}
	return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, Matrix& obj)
{
	// Освобождаем память
	for (int i = 0; i < obj.rowsCount; i++)
		delete[] obj.data[i];
	delete[] obj.data;

	ifs >> obj.columnsCount >> obj.rowsCount;

	// Выделяем память заного под новую матрицу и заполняем её
	obj.data = new int* [obj.rowsCount];
	for (int i = 0; i < obj.rowsCount; i++)
	{
		obj.data[i] = new int[obj.columnsCount];
		for (int j = 0; j < obj.columnsCount; j++)
			ifs >> obj.data[i][j];
	}
	return ifs;
}
