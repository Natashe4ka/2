#include "CIntN.hpp"
#include <string>

CIntN::CIntN (int N) {
    lenght_number = N;
    number.resize(N);
    for (int i=0; i<N; i++) {
        number [i] = 0;
    }
    sign = '+';
}
    
CIntN::CIntN (int N, std::string x) {
        lenght_number = N;
        number.resize(N);
    
        
        if (x[0]=='-') {
            sign = '-';
            x.erase (0,1);
        }
    
        else sign = '+';
  //  std::cout << x<<"\n";
    
        for (int i=0; i<N; i++) {
            //number [i] = stoi(x.substr(i, 1));
            number[i]=static_cast<int>(x[i])-48;
        }
    }
    
    void CIntN::printf (){
        if (sign != '+') std::cout << sign;
        for (int i=0; i<lenght_number; i++){
            std::cout <<number[i];
        }
        std::cout << std::endl;
    }
    
    void CIntN::print(){
        std::ofstream out(file_name, std::ios_base::app);
        if(!out){
            std::cout << "Error! Cannot open file!\n";
            exit(-1);
        }

        out << lenght_number << " " << sign << " ";
        for(int64_t i = 0; i < lenght_number; ++i){
            out << number[i];
        }
        out << "\n";
    }

CIntN::CIntN () {
        sign = '+';
        lenght_number = 0;
    }
    
    char CIntN::get_sign () const{
        return sign;
    }
    int CIntN::get_lenght () const{
        return lenght_number;
    }
    std::vector<int> CIntN::get_number () const {
        return number;
    }

    void CIntN::new_file_name (const std::string& FileName) {
    
        file_name = FileName;
    }

    
    void CIntN::new_sign (char _sign) {
        sign= _sign;
    }
    
    void CIntN::new_number (const int lenght, const std::vector<int>& num){
            if( lenght <= 0 ){
                std::cout << "Error! array's lenght is not correct." << std::endl;
                exit(-1);
            }
            if(!number.empty()) number.clear();
            lenght_number= lenght;
            number.resize(lenght);
            for(int i = 0; i < lenght; i++){
                number[i] = num[i];
            }
        }
    
    void CIntN::new_number (std::string num){
            if(num[0] == '-'){
                sign = '-';
                num.erase(0, 1);
            }
            else sign = '+';
            lenght_number = int (num.size());
            if (!number.empty()) number.clear();
            number.resize(lenght_number);
            
            for(int i = 0; i < lenght_number; i++){
                number[i] = stoi(num.substr(i, 1));
            }
        }
    
CIntN::CIntN(const CIntN& w) {   //оператор копирования (автоматически)
        lenght_number = w.lenght_number;
        sign = w.sign;
        number.resize(lenght_number);
        for (int i = 0; i < lenght_number; i++) {
            number[i] = w.number[i];
        }
      }
    
CIntN::~CIntN () {}
    
    
    void CIntN::set_lenght(const int lenght){
        lenght_number = lenght;
        if(!number.empty()) number.clear();
        number.resize(lenght_number);
        for (int i = 0; i < lenght_number; i++) {
            number[i] = 0;
        }
    }
 
CIntN& CIntN::operator=(const CIntN& X) {
        if (this == &X) return *this;
        sign = X.sign;
        lenght_number = X.lenght_number;
        if (!number.empty()) number.clear();
        number.resize(lenght_number);
        for (int i = 0; i<lenght_number; i++) {
            number [i]= X.number [i];
        }
        return *this;
    }

