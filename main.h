#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

template <class TypeArray>

class array
{
public:
    array(int size);
    ~array();
	void generate();
	array<TypeArray> operator + (const TypeArray&);
	array operator - (const TypeArray&);
	array operator * (const TypeArray&);
	array operator / (const TypeArray&);
	array operator + (const array&);
    array operator - (const array&);
	array operator * (const array&);
    array operator / (const array&);
	array operator = (const TypeArray&);
	friend ostream &operator<< <TypeArray>(ostream &, const array<TypeArray>&);
	friend istream &operator>> <TypeArray>(istream &, const array<TypeArray>&);
	
private:
    TypeArray *arr;
    int size;
};

template <class TypeArray>

void array <TypeArray>::generate()
{
	if (typeid(TypeArray) == typeid(int))
	for (int i = 0; i < size; i++)
		arr[i]= rand() % 10 + 1;
	else
		if (typeid(TypeArray) == typeid(double) || typeid(TypeArray) == typeid(float))
			for (int i = 0; i < size; i++)
				arr[i] = (rand() % 10 + 1)/1.219;
}

template <class TypeArray>
array <TypeArray>::array(int size)
{
	this->size = size;
	arr = new TypeArray[size];
}

template <class TypeArray>
array<TypeArray>::~array()
{
   // delete arr;
}

template <class TypeArray>
ostream &operator<<(ostream &output, const array<TypeArray> &rhs)
{
	for (int i = 0; i < rhs.size; i++)
	{
		output << rhs.arr[i] << " ";
	}
	return output;
}

template <class TypeArray>
istream &operator>>(istream &input, const array<TypeArray> &rhs)
{
	for (int i = 0; i < rhs.size; i++)
	{
		input >> rhs.arr[i];
	}
	return input;
}




template <class TypeArray>
array<TypeArray> array<TypeArray>::operator+(const TypeArray &rhs)
{
	array<TypeArray> result(size);
	for (int i = 0; i < size; i++)
	{
		result.arr[i] = arr[i] + rhs;
	}
	return result;
}

template <class TypeArray>
array<TypeArray> array<TypeArray>::operator-(const TypeArray &rhs)
{
	array<TypeArray> result(size);
	for (int i = 0; i < size; i++)
	{
		result.arr[i] = arr[i] - rhs;
	}
	return result;
}

template <class TypeArray>
array<TypeArray> array<TypeArray>::operator*(const TypeArray &rhs)
{
	array<TypeArray> result(size);
	for (int i = 0; i < size; i++)
	{
		result.arr[i] = arr[i] * rhs;
	}
	return result;
}

template <class TypeArray>
array<TypeArray> array<TypeArray>::operator/(const TypeArray &rhs)
{
	array<TypeArray> result(size);
	for (int i = 0; i < size; i++)
	{
		try
		{
			if (rhs == 0) throw "\n\n������� �� ����!\n";
			else
			result.arr[i] = arr[i] / rhs;
		}
		catch(char *v)
		{
			cout<<v;
			system("pause");
			exit(0);
		}
	}
	return result;
}
 
template <class TypeArray>
array<TypeArray> array<TypeArray>::operator+(const array<TypeArray> &rhs)
{
	if (size < rhs.size)
	{
		array<TypeArray> result(rhs.size);
		for (int i = 0; i < size; i++)
		{
			result.arr[i] = arr[i] + rhs.arr[i];
		}

		for (int i = size; i < rhs.size; i++)
		{
			result.arr[i] = rhs.arr[i];
		}
		return result;
	}
	else
		if (size > rhs.size)
		{
			array<TypeArray> result(size);
			for (int i = 0; i < rhs.size; i++)
			{
				result.arr[i] = arr[i] + rhs.arr[i];
			}

			for (int i = rhs.size; i < size; i++)
			{
				result.arr[i] = arr[i];
			}
			return result;
		}
		else
		{
			array<TypeArray> result(size);
			for (int i = 0; i < size; ++i)
			{
				result.arr[i] = arr[i] + rhs.arr[i];
			}
		    return result;
		}
}

template <class TypeArray>
array<TypeArray> array<TypeArray>::operator-(const array<TypeArray> &rhs)
{
	if (size < rhs.size)
	{
		array<TypeArray> result(rhs.size);
		for (int i = 0; i < size; i++)
		{
			result.arr[i] = arr[i] - rhs.arr[i];
		}

		for (int i = size; i < rhs.size; i++)
		{
			result.arr[i] = rhs.arr[i];
		}
		return result;
	}
	else
		if (size > rhs.size)
		{
			array<TypeArray> result(size);
			for (int i = 0; i < rhs.size; i++)
			{
				result.arr[i] = arr[i] - rhs.arr[i];
			}

			for (int i = rhs.size; i < size; i++)
			{
				result.arr[i] = arr[i];
			}
			return result;
		}
		else
		{
			array<TypeArray> result(size);
			for (int i = 0; i < size; ++i)
			{
				result.arr[i] = arr[i] - rhs.arr[i];
			}
		    return result;
		}
}

template <class TypeArray>
array<TypeArray> array<TypeArray>::operator*(const array<TypeArray> &rhs)
{
	if (size < rhs.size)
	{
		array<TypeArray> result(rhs.size);
		for (int i = 0; i < size; i++)
		{
			result.arr[i] = arr[i] * rhs.arr[i];
		}

		for (int i = size; i < rhs.size; i++)
		{
			result.arr[i] = rhs.arr[i];
		}
		return result;
	}
	else
		if (size > rhs.size)
		{
			array<TypeArray> result(size);
			for (int i = 0; i < rhs.size; i++)
			{
				result.arr[i] = arr[i] * rhs.arr[i];
			}

			for (int i = rhs.size; i < size; i++)
			{
				result.arr[i] = arr[i];
			}
			return result;
		}
		else
		{
			array<TypeArray> result(size);
			for (int i = 0; i < size; ++i)
			{
				result.arr[i] = arr[i] * rhs.arr[i];
			}
		    return result;
		}
}
 
template <class TypeArray>
array<TypeArray> array<TypeArray>::operator/(const array<TypeArray> &rhs)
{
	if (size < rhs.size)
	{
		array<TypeArray> result(rhs.size);
		for (int i = 0; i < size; i++)
		{
			try
				{
					if (rhs.arr[i] == 0) throw "\n\n������� �� ����! �� ��� ��������� ���������� ����������\n";
					else
					result.arr[i] = arr[i] / rhs.arr[i];
				}
				catch(char *v)
				{
					cout<<v;
					break;
				}
		}

		for (int i = size; i < rhs.size; i++)
		{
			result.arr[i] = rhs.arr[i];
		}
		return result;
	}
	else
		if (size > rhs.size)
		{
			array<TypeArray> result(size);
			for (int i = 0; i < rhs.size; i++)
			{
				try
				{
					if (rhs.arr[i] == 0) throw "\n\n������� �� ����! �� ��� ��������� ���������� ����������\n";
					else
					result.arr[i] = arr[i] / rhs.arr[i];
				}
				catch(char *v)
				{
					cout<<v;
					break;
				}
			}

			for (int i = rhs.size; i < size; i++)
			{
				result.arr[i] = arr[i];
			}
			return result;
		}
		else
		{
			array<TypeArray> result(size);
			for (int i = 0; i < size; ++i)
			{
				try
				{
					if (rhs.arr[i] == 0) throw "\n\n������� �� ����! �� ��� ��������� ���������� ����������\n";
					else
					result.arr[i] = arr[i] / rhs.arr[i];
				}
				catch(char *v)
				{
					cout<<v;
					break;
				}
			}
		    return result;
		}
}
