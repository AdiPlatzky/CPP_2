//
// Created by 12adi on 09/06/2025.
//

#include "SquareMat.h"
#include <stdexcept>

namespace matrix
{
SquareMat::SquareMat(int size): size(size)
{
  if (size <= 0){
    throw std::invalid_argument("Size must be greater than 0");
  }
  matrix = new double*[size];
  for (int i = 0; i < size; i++){
    matrix[i] = new double[size];
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      matrix[i][j] = 0;
    }
  }
}

SquareMat::~SquareMat()
{
  for (int i = 0; i < size; i++)
  {
    delete[] matrix[i];
  }
  delete [] matrix;
}

SquareMat::SquareMat(const SquareMat &other): size(other.size)
{
  matrix = new double*[size];
  for (int i = 0; i < size; i++)
  {
    matrix[i] = new double[size];
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      matrix[i][j] = other.matrix[i][j];
    }
  }
}

SquareMat &SquareMat::operator=(const SquareMat &other)
{
  if (this != &other)
  {
    if (this->size != other.size)
    {
      for (int i = 0; i < size; i++)
      {
        delete[] matrix[i];
      }
      delete [] matrix;
      size = other.size;
      matrix = new double*[size];
      for (int i = 0; i < size; i++)
      {
        matrix[i] = new double[size];
      }
    }
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        matrix[i][j] = other.matrix[i][j];
      }
    }
  }
  return *this;
}

  // חיבור וחיסור מטריצות בגדלים זהים
SquareMat SquareMat::operator+(const SquareMat& m) const
{
  if (this->size != m.size)
  {
    throw std::invalid_argument("Matrixs size must be same");
  }

  SquareMat result = SquareMat(this->size);
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result.matrix[i][j] = this->matrix[i][j] + m.matrix[i][j];
    }
  }
  return result;
}

SquareMat SquareMat::operator-(const SquareMat& m) const
{
  if (this->size != m.size)
  {
    throw std::invalid_argument("Matrixs size must be same");
  }

  SquareMat result = SquareMat(this->size);
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result.matrix[i][j] = this->matrix[i][j] - m.matrix[i][j];
    }
  }
  return result;
}

  // שינוי הסימן של מקדם המטריצה
SquareMat SquareMat::operator-() const
{
  SquareMat result = SquareMat(this->size);
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result.matrix[i][j] = -(this->matrix[i][j]);
    }
  }
  return result;
}

  //הכפלה בין 2 מטריצות
SquareMat SquareMat::operator*(const SquareMat& m) const
{
  if (this->size != m.size)
  {
    throw std::invalid_argument("Matrixs size must be same");
  }

  SquareMat result = SquareMat(this->size);
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      for (int k = 0; k < size; k++)
      {
        result.matrix[i][j] += this->matrix[i][k] * m.matrix[k][j];
      }
    }
  }
  return result;
}

  // הכפלת מטריצה בסקלר
SquareMat operator*(double scalar, const SquareMat& m)
{
  SquareMat result = SquareMat(m.size);
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result.matrix[i][j] = scalar * m.matrix[i][j];
    }
  }
}

SquareMat SquareMat::operator*(double scalar) const
{
  SquareMat result = SquareMat(this->size);
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result.matrix[i][j] = scalar * this->matrix[i][j];
    }
  }
  return result;
}

  // הכפלה בין 2 מטריצות בצורה לא רגילה - כלומר ההכפלה תעשה איבר במיקום ה i,j עם האיבר במיקום ה i,j מהמטריצה השניה
SquareMat SquareMat::operator%(const SquareMat& m) const
{
  if (this->size != m.size)
  {
    throw std::invalid_argument("Matrixs size must be same");
  }

  SquareMat result = SquareMat(this->size);
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result.matrix[i][j] = this->matrix[i][j] * m.matrix[i][j];
    }
  }
  return result;
}

  // מבצע פעולה של מודולו על כל איבר במטריצה עם מספר שלם נתון
SquareMat SquareMa::operator%(double scalar) const
{
  if(scalar <= 0)
  {
    throw std::invalid_argument("Number must be greater than 0");
  }
  SquareMat result = SquareMat(this->size);
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result.matrix[i][j] = std::fmod(this->matrix[i][j], scalar);
    }
  }
  return result;
}

  // מחלק כל איבר במטריצה במספר סקלרי
SquareMat SquareMat::operator/(double scalar) const
{
  if (scalar == 0)
  {
    throw std::invalid_argument("Number must be different than 0");
  }
  SquareMat result = SquareMat(this->size);
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      result.matrix[i][j] = this->matrix[i][j] / scalar;
    }
  }
  return result;
}

  // אופרטור חזקה
SquareMat SquareMat::operator^(int exponent) const
{
  SquareMat result(size);
  for (int i = 0; i < size; i++)
  {
    result.matrix[i][i] = 1;
  }
  SquareMat current(*this);
  if (exponent == 0)
  {
    return result;
  }
  else if (exponent < 0)
  {
    exponent = -exponent;
    while (exponent > 0)
    {
      if(exponent % 2 == 1)
      {
        result = result * current;
      }
      current = current * current;
      exponent = exponent / 2;
    }
    return 1/result;
  }

  else
  {
    while (exponent > 0)
    {
      if(exponent % 2 == 1)
      {
        result = result * current;
      }
      current = current * current;
      exponent = exponent / 2;
    }
  }
  return result;
}

  // אופרטורי הגדלה והקטנה ב-1
SquareMat &SquareMat::operator++()
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      this->matrix[i][j] += 1;
    }
  }
  return *this;
} // prefix
SquareMat &SquareMat::operator++(int)
{
  SquareMat result = this->matrix;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      this->matrix[i][j] += 1;
    }
  }
  return *result;
} // postfix
  SquareMat &SquareMat::operator--()
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      this->matrix[i][j] -= 1;
    }
  }
  return *this;
} // prefix
  SquareMat &SquareMat::operator--(int)
{
  SquareMat result = this->matrix;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      this->matrix[i][j] -= 1;
    }
  }
  return *result;
} // postfix

  //מחליף את השורות בעמודות של המטריצה
SquareMat SquareMat::operator~() const
{
  SquareMat result(size);
  for (int i = 0; i < size; i++)
  {
     for (int j = 0; j < size; j++)
    {
       result.matrix[i][j] = this->matrix[j][i];
    }
  }
  return result;
}

  // אופרטור גישה לאיברים באמצעות אינדקס
double* SquareMat::operator[](int i)
{
  if (i < 0 || i >= size)
  {
    throw std::invalid_argument("Index out of bounds");
  }
  return matrix[i];
}

const double* SquareMat::operator[](int i) const
{
  if (i < 0 || i >= size)
  {
    throw std::invalid_argument("Index out of bounds");
  }
  return matrix[i];
}

  //אופרטורי שוויון ואי-שוויון
bool SquareMat::operator==(const SquareMat& m) const
{
  double sumThis = 0;
  double sumM = 0;

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      sumThis += this->matrix[i][j];
      sumM += m.matrix[i][j];
    }
  }
  return sumThis == sumM;
}
bool SquareMat::operator!=(const SquareMat& m) const
{
  return !(*this == m);
}

  //אופרטורי השוואה
bool SquareMat::operator<(const SquareMat& m) const
{
  {
    double sumThis = 0;
    double sumM = 0;

    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        sumThis += this->matrix[i][j];
        sumM += m.matrix[i][j];
      }
    }
    return sumThis < sumM;
  }

}
bool SquareMat::operator>=(const SquareMat& m) const
{
  return !(*this < m);
}
bool SquareMat::operator>(const SquareMat& m) const
{
  return (m < *this);
}
bool SquareMat::operator<=(const SquareMat& m) const
{
  return !(m < *this);
}

  //מחשב את הדטרמיננטה של המטריצה
double SquareMat::operator!() const
{

}

  //אופרטורי השמה משולבים
SquareMat &SquareMat::operator+=(const SquareMat& m){}
SquareMat &SquareMat::operator-=(const SquareMat& m){}
SquareMat &SquareMat::operator*=(const SquareMat& m){}
SquareMat &SquareMat::operator%=(const SquareMat& m){}
SquareMat &SquareMat::operator/=(const SquareMat& m){}

  // מדפיס את המטריצה בצורה הגיונית
  friend std::ostream& operator<<(std::ostream& os, const SquareMat& m);


} // matrix