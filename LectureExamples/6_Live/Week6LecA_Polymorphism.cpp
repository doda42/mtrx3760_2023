// This is the code written interactively during the first lecture of Week 6
// Exploring polymorphism in Lab 2 (and 4)
// Not a good solution for Lab 2 as it uses vectors, etc
// This is however a good example of using polymorphism... adding a new gate requires zero changes
// to existing code, and effectively reuses the common parts of logic gates requiring only that 
// the gate-specific parts be reimplemented

#include <iostream>
#include <vector>

class CWire
{

};

class CGate
{
  public:
    virtual ~CGate(){ std::cout << "CGate DTor" << std::endl; }
    virtual void Report() = 0;
    
};

class CAndGate: public CGate
{
  public:
    CAndGate(){ std::cout << "CAndGate CTOR" << std::endl; }
    ~CAndGate(){ std::cout << "CAndGate DTOR" << std::endl; }
    void Report() { std::cout << "CAndGate reporting in" << std::endl; }
};
class CXorGate: public CGate
{
  public:
    CXorGate(){ std::cout << "CXorGate CTOR" << std::endl; }
    ~CXorGate(){ std::cout << "CXorGate DTOR" << std::endl; }
    void Report() { std::cout << "CXorGate reporting in" << std::endl; }
};



class CCircuit
{
  public:
    CCircuit()
    {
      CGate* pAndGate = new CAndGate;
      mGates.push_back( pAndGate );
 
      CGate* pXorGate = new CXorGate;
      mGates.push_back( pXorGate );
    }
    ~CCircuit()
    {
      std::cout << "CCircuit DTor" << std::endl;
      for( int i=0; i<mGates.size(); ++i )
      {
        CGate* pGate = mGates[i];
        if( pGate != NULL )
          delete pGate;
      }
    }
    
    void ReportAll() 
    {
      for( int i=0; i<mGates.size(); ++i )
//      for( auto pGate: mGates )
      {
        if( pGate != NULL )
          pGate->Report();
      }      
    }

  private:
    std::vector<CWire*> mWires;
    std::vector<CGate*> mGates;
};



int main()
{
  CCircuit MyCircuit;
  MyCircuit.ReportAll();
  return 0;
}

