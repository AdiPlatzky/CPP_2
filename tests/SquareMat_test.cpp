//
// 12adi45@gmail.com
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../SquareMat.h"
using namespace matrix;

TEST_SUITE("Square Matrix Advanced Test")
{
  TEST_CASE("Create Square Matrix")
  {
    matrix::SquareMat matrix(3);
    CHECK(matrix.size == 3);
  }
}
