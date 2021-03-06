#include "stdafx.h"
#include "Circles_func.cpp"
#include "main_circle.h"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------------
// ------------------Checking the behavior of the program----------------------
// ----------------------------------------------------------------------------
// Test description:
// Checking the behavior of the program when the file is missing according to 
// the path specified in the argument.
// Expected result: false - file is not open.
// ----------------------------------------------------------------------------
TEST(ReadFile, NotFile) {
	vector<Сircle> vec;
	EXPECT_TRUE(file_read("123.txt", vec) == false);
}

// ----------------------------------------------------------------------------
// Test description:
// Checking the behavior of the program with an empty file according to the 
// path specified in the argument.
// Expected result: false - file is empty.
// ----------------------------------------------------------------------------
TEST(ReadFile, EmptyFile) {
	vector<Сircle> vec;
	char *filename = "..\\..\\test_files\\empty_file.txt";
	EXPECT_TRUE(file_read(filename, vec) == false);
}

// ----------------------------------------------------------------------------
// Test description:
// Сhecking the behavior of the program with the correct file according to  
// the path specified in the argument.
// Expected result: true - file is correct.
// ----------------------------------------------------------------------------
TEST(ReadFile, CorrectFile) {
	vector<Сircle> vec;
	char *filename = "..\\..\\test_files\\test_1.txt";
	EXPECT_TRUE(file_read(filename, vec) == true);
	EXPECT_TRUE(vec.size() == 1);
	EXPECT_TRUE(vec[0].id == 1);
	EXPECT_TRUE(vec[0].x == 0);
	EXPECT_TRUE(vec[0].y == 0);
	EXPECT_TRUE(vec[0].radius == 2);
}

// ----------------------------------------------------------------------------
// Test description: сircle with negative radius.
// Expected result: true - incorrect circle will be missed.
// ----------------------------------------------------------------------------
TEST(ReadFile, IncorrectCircle) {
	vector<Сircle> vec;
	char *filename = "..\\..\\test_files\\test_2.txt";
	EXPECT_TRUE(file_read(filename, vec) == true);
	EXPECT_TRUE(vec.size() == 3); // in the file 4 circles
}


// ----------------------------------------------------------------------------
// ---------------Checking for the intersection of two circles-----------------
// ----------------------------------------------------------------------------
// Block description:
// Checking for the intersection of two circles. The output - true, if the 
// circles intersect, and false, if they do not intersect.
// ----------------------------------------------------------------------------
// Test description: сircle in a circle, without intersections, one center.
// Expected result: false
// ----------------------------------------------------------------------------
TEST(IntersectionCheck, Test1) {
	bool answer;
	Сircle A(1, 0.0, 0.0, 2.0);
	Сircle B(2, 0.0, 0.0, 1.0);
	answer = intersect(A, B);
	EXPECT_FALSE(answer);
}

// ----------------------------------------------------------------------------
// Test description: circle in a circle, one touch point.
// Expected result: true
// ----------------------------------------------------------------------------
TEST(IntersectionCheck, Test2) {
	bool answer;
	Сircle A(1, 0.0, 0.0, 2.0);
	Сircle B(2, 0.0, 1.0, 1.0);
	answer = intersect(A, B);
	EXPECT_TRUE(answer);
}

// ----------------------------------------------------------------------------
// Test description: circles coincide.
// Expected result: true
// ----------------------------------------------------------------------------
TEST(IntersectionCheck, Test3) {
	bool answer;
	Сircle A(1, 5.67, 5.67, 3.0);
	Сircle B(2, 5.67, 5.67, 3.0);
	answer = intersect(A, B);
	EXPECT_TRUE(answer);
}

// ----------------------------------------------------------------------------
// Test description: circles nearby, one touch point.
// Expected result: true
// ----------------------------------------------------------------------------
TEST(IntersectionCheck, Test4) {
	bool answer;
	Сircle A(1, 2.0, 2.0, 2.0);
	Сircle B(2, 5.0, 2.0, 1.0);
	answer = intersect(A, B);
	EXPECT_TRUE(answer);
}

// ----------------------------------------------------------------------------
// Test description: circles intersect at two points.
// Expected result: true
// ----------------------------------------------------------------------------
TEST(IntersectionCheck, Test5) {
	bool answer;
	Сircle A(1, 0, 0, 2);
	Сircle B(2, 2, 0, 1);
	answer = intersect(A, B);
	EXPECT_TRUE(answer);
}

// ----------------------------------------------------------------------------
// Test description: circles do not intersect.
// Expected result: false
// ----------------------------------------------------------------------------
TEST(IntersectionCheck, Test6) {
	bool answer;
	Сircle A(1, 3.5, 4.5, 5.5);
	Сircle B(2, 20.0, 6.0, 1.0);
	answer = intersect(A, B);
	EXPECT_FALSE(answer);
}

// ----------------------------------------------------------------------------
// Test description: сircle in a circle, without intersections, 
// different center, close to each other.
// Expected result: false
// ----------------------------------------------------------------------------
TEST(IntersectionCheck, Test7) {
	bool answer;
	Сircle A(1, 0.0, 0.0, 2.0);
	Сircle B(2, 1.0, 0.0, 0.99);
	answer = intersect(A, B);
	EXPECT_FALSE(answer);
}

// ----------------------------------------------------------------------------
// Test description: circles nearby, not intersect.
// Expected result: false
// ----------------------------------------------------------------------------
TEST(IntersectionCheck, Test8) {
	bool answer;
	Сircle A(1, 2.0, 2.0, 2.0);
	Сircle B(2, 5.0, 2.0, 0.99);
	answer = intersect(A, B);
	EXPECT_FALSE(answer);
}

// ----------------------------------------------------------------------------
// Test description: circles almost coincide, not intersect.
// Expected result: false
// ----------------------------------------------------------------------------
TEST(IntersectionCheck, Test9) {
	bool answer;
	Сircle A(1, 5.67, 5.67, 3.0);
	Сircle B(2, 5.67, 5.67, 2.99);
	answer = intersect(A, B);
	EXPECT_FALSE(answer);
}

// ----------------------------------------------------------------------------
// --------------------------Comparison of circles-----------------------------
// ----------------------------------------------------------------------------
// Test description: one circle is much smaller than the other, one center.
// Expected result: true
// ----------------------------------------------------------------------------
TEST(Comparison, Test1) {
	bool answer;
	Сircle A(1, 0, 0, 1);
	Сircle B(2, 0, 0, 5);
	EXPECT_TRUE(A < B);
}

// ----------------------------------------------------------------------------
// Test description: one circle is much smaller than the other, 
// different centers.
// Expected result: true
// ----------------------------------------------------------------------------
TEST(Comparison, Test2) {
	bool answer;
	Сircle A(1, 2.22, 2.22, 10);
	Сircle B(2, 5.55, 5.55, 50);
	EXPECT_TRUE(A < B);
}

// ----------------------------------------------------------------------------
// Test description: circles are almost equal.
// Expected result: true
// ----------------------------------------------------------------------------
TEST(Comparison, Test3) {
	bool answer;
	Сircle A(1, 0, 0, 5);
	Сircle B(2, 0, 0, 4.998);
	EXPECT_TRUE(B < A);
}

// ----------------------------------------------------------------------------
// Test description: circles are equal.
// Expected result: false
// ----------------------------------------------------------------------------
TEST(Comparison, Test4) {
	bool answer;
	Сircle A(1, 0, 0, 5);
	Сircle B(2, 0, 0, 5);
	EXPECT_FALSE(B < A);
	EXPECT_FALSE(A < B);
}