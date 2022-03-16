#ifndef cint0_class_hpp
#define cint0_class_hpp

#include "CIntN.hpp"

class CIntN0 : public CIntN{
public:
    using CIntN::CIntN;
    CIntN0() : CIntN() {
    }
    using CIntN::operator=;
    CIntN0(const CIntN& A) : CIntN(A) {};
    
    void print(){
        std::ofstream out(file_name, std::ios_base::app); //открываем и печатаем в конец
        if(!out){
            std::cout << "Error! Cannot open file!\n";
            exit(-1);
        }

        //out << lenght_number << " " << sign << " ";
        if (sign=='-')
            out<<sign<<" ";
        for(int64_t i = 0; i < lenght_number-1; ++i){
            out << number[i]<<" ";
        }
        out << number[lenght_number-1];
        out << "\n";
        out.close();
    }
    
};

#endif 
