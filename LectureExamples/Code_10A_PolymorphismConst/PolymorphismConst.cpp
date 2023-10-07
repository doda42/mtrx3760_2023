// example of initialising a base class const from a derived class specialised value
// See PolymorphismHardCoded.cpp for motivating scenario

#include <iostream>

//---Base class, needs to be initialised with a pointer to string (const char*)---
class CBase
{
  public:
    CBase( const char* apStr )
      : mBaseStr( apStr )
    { }
    void Report()
    {
      std::cout << mBaseStr << std::endl;
    }
  private:
    const char* mBaseStr;
};

//---Derived class sets up the base class pointer---
// The string content is a static const char* that gets initialised at instantiation 
class CDerived: public CBase
{
  public:
    CDerived() 
      : CBase( mStr )
    { }
  private:
    static const char* mStr;
};
const char* CDerived::mStr = "hi";

//---Another derived class---
// Follows the same pattern as the above, but with a different string
class CAnother: public CBase
{
  public:
    CAnother() 
      : CBase( mStr )
    { }
  private:
    static const char* mStr;
};
const char* CAnother::mStr = "allo";


//---
int main()
{
  CDerived Bob;
  CAnother Collette;

  Bob.Report();
  Collette.Report(); 
  
  //CBase Phil;    // this won't work, CBase constructor needs a char* argument
};

