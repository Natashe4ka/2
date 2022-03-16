#ifndef cint1_class_hpp
#define cint1_class_hpp

#include "CIntN.hpp"

class CIntN1 : public CIntN{
public:
    using CIntN::CIntN;
    using CIntN::operator=;
    CIntN1() : CIntN() {
    }
    CIntN1(const CIntN& A) : CIntN(A) {};
    
    void print(){
        std::ofstream out(file_name, std::ios_base::app);
        if(!out){
            std::cout << "Error! Cannot open file!\n";
            exit(-1);
        }

        //out << lenght_number << "\n" << sign << "\n";
        if (sign=='-')
            out<<sign;
        for(int64_t i = 0; i < lenght_number; ++i){
            out << number[i]<<"\n";
        }
        //out << number[lenght_number];
       // out << "\n";
        out.close();
    }
};

#endif
