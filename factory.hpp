#ifndef factory_hpp
#define factory_hpp

#include "CIntN.hpp"
#include "CIntN0.hpp"
#include "CIntN1.hpp"

class Creator{
public:
    virtual CIntN* factoryMethod() = 0;
    virtual CIntN* factoryMethod(int N, std::string x) = 0;
};

struct ConcreteCreator0: public Creator{
public:
    CIntN* factoryMethod(){return new CIntN0();}
    CIntN* factoryMethod(int N, std::string x){return new CIntN0(N, x);}
};

struct ConcreteCreator1: public Creator{
public:
  CIntN* factoryMethod(){return new CIntN1();}
  CIntN* factoryMethod(int N, std::string x){return new CIntN1(N, x);}
};


#endif /* factory_hpp */
