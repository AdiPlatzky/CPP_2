//
// Created by 12adi on 08/06/2025.
//

#ifndef SQUAREMAT_H
#define SQUAREMAT_H

namespace matrix {

class SquareMat {
  Matrix Addition/SubtractionOperator(matrix a, matrix b, string action); // חיבור וחיסור מטריצות בגדלים זהים
  void MinusOneOperator(matrix a); // שינוי הסימן של מקדם המטריצה
  Matrix MultiplicationOperator(matrix a, matrix b); //הכפלה בין 2 מטריצות
  void ScalarMultiplication(matrix a, int b); // הכפלת מטריצה בסקלר ממשי!!
  Matrix MultiplicationOfOrgans(); //
  Matrix ModuluWithScalar(matrix a, int num); // מבצע פעולה של מודולו על כל איבר במטריצה עם מספר שלם נתון
  Matrix ScalarDivision(matrix a, int num); // מחלק כל איבר במטריצה במספר סקלרי
  Matrix StrongOperator(matrix a, int hezka); // אופרטור חזקה
  void plossAndMinusByOneOperator(matrix a); // אופרטורי הגדלה והקטנה ב-1
  void TransposeOperator(matrix a); //מחליף את השורות בעמודות של המטריצה
  void IndexOperator(matrix a, int row, int column); // אופרטור גישה לאיברים באמצעות אינדקס
  void EqualityAndInequalityOperator(matrix a, matrix b); //אופרטורי שוויון ואי-שוויון
  void ComparisonOperator(matrix a, matrix b); //אופרטורי השוואה
  void DeterminantOperator(matrix a); //מחשב את הדטרמיננטה של המטריצה
  void CombinedPlacementOperators(matrix a, matrix b); //אופרטורי השמה משולבים
  void OutputOperator(matrix a); // מדפיס את המטריצה בצורה הגיונית
};

} // matrix

#endif //SQUAREMAT_H
