//
// 12adi45@gmail.com
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SquareMat.h"

using namespace matrix;

// פונקציית עזר ליצירת מטריצה עם ערכים מ-1 עד size^2
SquareMat createSequentialMat(int size) {
    SquareMat m(size);
    int val = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            m[i][j] = val++;
        }
    }
    return m;
}

// בדיקת בנאי תקין ומקרי קצה לא חוקיים
TEST_CASE("Matrix constructor and invalid cases") {
    CHECK_THROWS(SquareMat(0)); // גודל לא חוקי
    CHECK_THROWS(SquareMat(-3));
    SquareMat m(1);
    CHECK(m.size == 1);
    CHECK(m[0][0] == 0.0); // אתחול לאפס
}

// בדיקת בנאי העתקה והשמה
TEST_CASE("Copy constructor and assignment") {
    SquareMat a = createSequentialMat(3);
    SquareMat b(a);
    CHECK(a == b); // בדיקת שוויון לאחר העתקה

    SquareMat c(3);
    c = a;
    CHECK(c == a); // בדיקת שוויון לאחר השמה

    SquareMat d(2);
    CHECK_NOTHROW(d = a); // בדיקת שינוי גודל בעת השמה
    CHECK(d == a);
}

// בדיקת חיבור, חיסור, והיפוך סימן מטריצות
TEST_CASE("Addition, subtraction, negation") {
    SquareMat a = createSequentialMat(2);
    SquareMat b = createSequentialMat(2);
    SquareMat c = a + b;
    CHECK(c[0][0] == 2);
    CHECK((a - b)[1][1] == 0);
    SquareMat d = -a;
    CHECK(d[0][0] == -1);
}

// בדיקת פעולת כפל מטריצות
TEST_CASE("Matrix multiplication") {
    SquareMat a = createSequentialMat(2); // מטריצה 2x2
    SquareMat b = createSequentialMat(2);
    SquareMat result = a * b;
    CHECK(result[0][0] == 7);
    CHECK(result[1][1] == 22);
    CHECK_THROWS(a * SquareMat(3)); // גדלים שונים
}

// בדיקת כפל וחילוק בסקלר
TEST_CASE("Scalar operations") {
    SquareMat a = createSequentialMat(2);
    CHECK((a * 2)[0][0] == 2);
    CHECK((2 * a)[1][1] == 8);
    CHECK((a / 2)[1][0] == 1.5);
    CHECK_THROWS(a / 0); // חלוקה באפס
}

// בדיקות מודולו עם סקלר ומטריצה
TEST_CASE("Modulo operations") {
    SquareMat a = createSequentialMat(2); // 1-4
    CHECK((a % 2)[0][0] == 1);
    CHECK((a % 2)[1][0] == 1);
    CHECK_THROWS(a % 0); // מודולו באפס

    SquareMat b = createSequentialMat(2);
    CHECK((a % b)[0][0] == 1);
    CHECK_THROWS(a % SquareMat(3));
}

// בדיקות הגדלה והקטנה
TEST_CASE("Increment and decrement") {
    SquareMat a = createSequentialMat(2);
    SquareMat b = a++;
    CHECK(b[0][0] == 1);
    CHECK(a[0][0] == 2);
    SquareMat c = --a;
    CHECK(c[0][0] == 1);
}

// בדיקת טרנספוזיציה
TEST_CASE("Transpose") {
    SquareMat a = createSequentialMat(2);
    SquareMat b = ~a;
    CHECK(b[0][1] == a[1][0]);
    CHECK(b[1][0] == a[0][1]);
}

// בדיקות השוואה בין מטריצות
TEST_CASE("Comparison operators") {
    SquareMat a = createSequentialMat(2);
    SquareMat b = createSequentialMat(2);
    CHECK(a == b);
    b[0][0] = 99;
    CHECK(a != b);
    CHECK(b > a);
    CHECK(b >= a);
    CHECK(!(a > b));
    CHECK(a <= b);
}

// בדיקת אופרטור חזקת מטריצה ^
TEST_CASE("Power operator ^") {
    SquareMat a(2);
    a[0][0] = 2; a[0][1] = 0;
    a[1][0] = 0; a[1][1] = 2;
    SquareMat b = a ^ 3;
    CHECK(b[0][0] == 8);
    CHECK_THROWS(a ^ -1); // חזקות שליליות
}

// בדיקת דטרמיננטה
TEST_CASE("Determinant ! operator") {
    SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;
    CHECK((!a) == doctest::Approx(-2.0));
}

// בדיקת חיתוך מינור
TEST_CASE("Minor extraction") {
    SquareMat a = createSequentialMat(3);
    SquareMat m = a.getMinor(0, 0);
    CHECK(m.size == 2);
    CHECK(m[0][0] == 5);
    CHECK_THROWS(a.getMinor(3, 0)); // חריגה מהאינדקס
}

// בדיקות השמה מצטברת
TEST_CASE("Compound assignment operators") {
    SquareMat a = createSequentialMat(2);
    SquareMat b = createSequentialMat(2);
    SquareMat c = a;
    c += b;
    CHECK(c[0][0] == 2);
    c -= b;
    CHECK(c[0][0] == 1);
    c *= b;
    CHECK(c[0][0] == 7);
    c %= 3;
    CHECK(c[0][0] == 1);
    c /= 1.0;
    CHECK(c[0][0] == 1);
}

// בדיקות גישה לאינדקסים וחריגה
TEST_CASE("Index access and out-of-bounds") {
    SquareMat a = createSequentialMat(2);
    CHECK(a[0][1] == 2);
    CHECK_THROWS(a[-1]);
    CHECK_THROWS(a[2]);
}

// בדיקות על מטריצות גדולות
TEST_CASE("Large matrix operations (size=100)") {
    int N = 100;
    SquareMat a(N);
    SquareMat b(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = i + j;
            b[i][j] = i - j;
        }
    }

    SquareMat c = a + b;
    CHECK(c[0][0] == 0);
    CHECK(c[N-1][N-1] == 2 * (N - 1));
}

TEST_CASE("Very large matrix (size=300) multiplication timing and result spot check") {
    int N = 300;
    SquareMat a(N);
    SquareMat b(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = 1;
            b[i][j] = 1;
        }
    }

    SquareMat c = a * b;
    CHECK(c[0][0] == doctest::Approx(N));
    CHECK(c[N-1][N-1] == doctest::Approx(N));
}
