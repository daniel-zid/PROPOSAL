#include "gtest/gtest.h"
#include "PROPOSAL/RootFinder.h"
#include <iostream>
#include <string>
#include <cmath>

double Exp(double r){
    return exp(r) - exp(0);
}

double DiffExp(double r){
    return exp(r);
}

double Polynom(double r){
    return r*r;
}

double DiffPolynom(double r){
    return 2*r;
}

double Polynom2(double r){
    return r*r -4;
}

double DiffPolynom2(double r){
    return 2*r;
}

double Polynom3(double r){
    return -r*r;
}

double DiffPolynom3(double r){
    return -2*r;
}

TEST(RootFinder , e_to_x_minus_e ) {
    RootFinder *finder = new RootFinder();
    ASSERT_NEAR(finder->FindRoot(-2,2,1, Exp, DiffExp,0.0) ,0, 1E-10);
    delete finder;
}

TEST(RootFinder , x_times_x_intersection_with_4 ) {
    RootFinder *finder = new RootFinder();
    ASSERT_NEAR(finder->FindRoot(-2,2,1, Polynom, DiffPolynom,4.0) ,-2., 1E-6*0);
    delete finder;
}

TEST(RootFinder , x_times_x_minus_4 ) {
    RootFinder *finder = new RootFinder();
    ASSERT_NEAR(finder->FindRoot(-3,3,1, Polynom2, DiffPolynom2,0.0) ,-2, 0.);
    delete finder;
}

TEST(RootFinder , minus_x_times_x_intersection_with_minus4 ) {
    RootFinder *finder = new RootFinder();
    ASSERT_NEAR(finder->FindRoot(-2,2,0, Polynom3, DiffPolynom3,-4.0) ,-2., 1E-6*0);
    delete finder;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

//TEST(IntegralValue, EqualBorders) {
//    Integral* Int = new Integral();

//    EXPECT_EQ(Int->Integrate(3,3,Testfkt,1),0);

//    delete Int;
//}

//TEST(IntegralValue, SmallError) {
//    Integral* Int = new Integral();

//    ASSERT_NEAR(   Int->Integrate(0,3,Testexp,1),exp(3)-1
//                            ,(exp(3)-1)*1.e-6);

//    delete Int;
//}

//TEST(IntegralValue, FloatEqual) {
//    Integral* Int = new Integral();
//    //Last 4 digits can differ. relError<1E-4
//    ASSERT_FLOAT_EQ(Int->Integrate(0,3,Testexp,1),exp(3)-1);

//    delete Int;
//}