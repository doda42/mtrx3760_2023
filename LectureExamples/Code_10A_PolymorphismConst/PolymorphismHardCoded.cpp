// Motivating example for PolymorphismConst.cpp
// hard-coded strings inside functions that are specialised for each derived class
// this might be undesirable because:
//    Repeats code; what if Report were more complex?
//    Hard-coded constants inside functions, better to define as consts and/or static consts

#include <iostream>

//---Base class---
class CBase
{
  public:
    virtual void Report() = 0;
};

//---Derived class uses specialised function with hard-coded string---
class CDerived: public CBase
{
  public:
    void Report() { std::cout << "hi" << std::endl; }
};

//---Another derived class---
// Follows the same pattern as the above, but with a different string
class CAnother: public CBase
{
  public:
    void Report() { std::cout << "allo" << std::endl; }
};


//---
int main()
{
  CDerived Bob;
  CAnother Collette;

  Bob.Report();
  Collette.Report(); 
  
  //CBase Phil;    // this won't work, CBase is an abstract base class
};

