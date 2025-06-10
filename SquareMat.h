//
// 12adi45@gmail.com
//

#ifndef SQUAREMAT_H
#define SQUAREMAT_H
#include <cstdio>

namespace matrix {

class SquareMat {
    public:
      double** matrix;
      int size;//cols&rows

      SquareMat(int size); // copy constructor - העתקת אובייקט (בנאי)
      ~SquareMat(); //destructor - לשחרור זיכרון
      SquareMat(const SquareMat& other);
      SquareMat& operator=(const SquareMat& mat); // copy assignment operation - השוואה בין שני אובייקטים קיימים

      // חיבור וחיסור מטריצות בגדלים זהים
      SquareMat operator+(const SquareMat& m) const;
      SquareMat operator-(const SquareMat& m) const;

      // שינוי הסימן של מקדם המטריצה
      SquareMat operator-() const;

      //הכפלה בין 2 מטריצות
      SquareMat operator*(const SquareMat& m) const;

      // הכפלת מטריצה בסקלר
      friend SquareMat operator*(double scalar, const SquareMat& m);
      SquareMat operator*(double scalar) const;

      // הכפלה בין 2 מטריצות בצורה לא רגילה - כלומר ההכפלה תעשה איבר במיקום ה i,j עם האיבר במיקום ה i,j מהמטריצה השניה
      SquareMat operator%(const SquareMat& m) const;

      // מבצע פעולה של מודולו על כל איבר במטריצה עם מספר שלם נתון
      SquareMat operator%(int scalar) const;

       // מחלק כל איבר במטריצה במספר סקלרי
  	  SquareMat operator/(double scalar) const;

      // אופרטור חזקה
   	  SquareMat operator^(int exponent) const;

      // אופרטורי הגדלה והקטנה ב-1
      SquareMat& operator++(); // prefix
      SquareMat& operator++(int); // postfix
      SquareMat& operator--(); // prefix
      SquareMat& operator--(int); // postfix

      //מחליף את השורות בעמודות של המטריצה
  	  SquareMat operator~() const;

      // אופרטור גישה לאיברים באמצעות אינדקס
  	  double* operator[](int i);
      const double* operator[](int i) const;

      //אופרטורי שוויון ואי-שוויון
  	  bool operator==(const SquareMat& m) const;
  	  bool operator!=(const SquareMat& m) const;

      //אופרטורי השוואה
      bool operator>(const SquareMat& m) const;
      bool operator>=(const SquareMat& m) const;
      bool operator<(const SquareMat& m) const;
      bool operator<=(const SquareMat& m) const;

      //מחשב את הדטרמיננטה של המטריצה
  	  double operator!() const;

      //אופרטורי השמה משולבים
  	  SquareMat& operator+=(const SquareMat& m);
      SquareMat& operator-=(const SquareMat& m);
      SquareMat& operator*=(const SquareMat& m);
	  SquareMat& operator*=(double scalar);
	  SquareMat& operator%=(const SquareMat& m);
      SquareMat& operator%=(int scalar);
      SquareMat& operator/=(double scalar);

      // מדפיס את המטריצה בצורה הגיונית
  	  friend std::ostream& operator<<(std::ostream& os, const SquareMat& m) const;
	};
} // matrix

#endif //SQUAREMAT_H
