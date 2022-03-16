#include "head.hpp"
#include "AT.hpp"
#include "factory.hpp"
#include "map"

int main(){
    
   if (!AutoTest() ) {
        std::cout << "Autotests failed!\n";
        return 0;
    }
    
    std::string file;
    std::cout <<"Enter File Name:\n";
    std::cin >> file;
    
    std::ifstream inp(file);
    if(!inp){
        std::cout << "Error! Cannot open file!\n";
        return -1;
    }

    size_t count = 0; //кол-во строк в файле

    std::string line;
    while(getline(inp, line)) ++count;
    inp.close();
    
    
    std::map<std::string, Creator*> factory;
    factory["Hori"] = new ConcreteCreator0;
    factory["Vert"] = new ConcreteCreator1;
    auto m_it0 = factory.begin();
   // auto m_it1 = m_it0++;
    
    
    //std::vector<std::string> file_names; //имена файлов для вывода
    //CIntN** arr = new CIntN*[count]; //массив указателей класса
    std::vector<CIntN*> arr; //iiiiii
   // auto v_it = arr.begin();
    
    inp.open(file);
    size_t i = 0;
    while(!inp.eof()){
        std::string I;
        inp >> I;
        std::string FileName;
        inp >> FileName;
        std::string num;
        inp >> num;
        /*if(I == "Hori"){
            if (i < count) {
                int l =static_cast<int>(num.size());
                if (num[0]=='-') l--;
                arr[i] = (*m_it1).second->factoryMethod(l, num);
                (*v_it)->new_file_name(FileName);
                ++v_it;
            }
        }
        else
        {
            if (i < count) {
                int l =static_cast<int>(num.size());
                if (num[0]=='-') l--;
                arr[i] = (*m_it0).second->factoryMethod(l, num);
                (*v_it)->new_file_name(FileName);
                ++v_it;
            }
        }*/
       // file_names.push_back(FileName);
        
        int l =static_cast<int>(num.size());
        auto curCreator = factory.find(I);
        if (curCreator == factory.end()) {
            std::cerr << "Error! Wrong number type!\n";
            return 1;
        }
        arr.push_back(curCreator->second->factoryMethod(l, num));
        
        arr[arr.size()-1]->new_file_name(FileName);
        
        if (i < arr.size()) ++i;
        
    }
    inp.close();


    
    for(std::vector<CIntN*>::iterator it = arr.begin(); it != arr.end(); ++it){
        (*it)->print();
    }
    
    for(std::vector<CIntN*>::iterator it = arr.begin(); it != arr.end(); ++it){
        delete (*it);
    }
    

    return 0;
}
