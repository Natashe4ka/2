#include "head.hpp"

//const CIntN operator-(CIntN, CIntN);

 CIntN0 operator+(const CIntN& A, const CIntN& B) {
    CIntN0 X = A;
    CIntN0 Y = B;
    CIntN0 sum;
    int i=X.get_lenght() -1;
    int j=Y.get_lenght() -1;
    int k;
    
    if (X.get_sign()=='-' && Y.get_sign()=='-') {
       sum.new_sign('-');
    }
    else if (X.get_sign() == '-' && Y.get_sign() == '+') {
        CIntN0 f_h;
        f_h = X;
        f_h.new_sign('+');
        sum = Y-f_h;
        return sum;
    }
    else if (X.get_sign() == '+' && Y.get_sign() == '-') {
        CIntN0 f_h;
        f_h = Y;
        f_h.new_sign('+');
        sum = X-f_h;
        return sum;
    }
    if(i < j){
        CIntN0 H;
        H = X;
        X = Y;
        Y = H;
        i=X.get_lenght() -1;
        j=Y.get_lenght() -1;
        sum.set_lenght(j+2);
        k=i;
    }
    else {
        sum.set_lenght(i+2);
        k=i;
    }
    int size =  k+2;
     std::vector<int> help_sum(size, 0);
        
    while (i!=-1 && j!=-1) {
       int first_sum =help_sum[k+1]+ X.get_number()[i] + Y.get_number()[j];
        help_sum [k+1] = (help_sum[k+1]+ X.get_number()[i] + Y.get_number()[j]) % 10;
   
       
        if (first_sum / 10 !=0) {
            help_sum[k]++;
        }
        k--;
        i--;
        j--;
              
    }
    if (j!=-1) {
        for(int q=j; q>-1; q--) {
            help_sum[k+1] += Y.get_number()[q] ;
            if (help_sum[k+1] / 10 !=0) {
                help_sum[k+1] = help_sum[k+1] % 10;
                help_sum[k]++;
            }
            k--;
        }
    }
    else if (i!=-1) {
        for(int q=i; q>-1; q--) {
            help_sum[k+1] += X.get_number()[q] ;
            if (help_sum[k+1] / 10 !=0) {
                help_sum[k+1] = help_sum[k+1] % 10;
                help_sum[k]++;
            }
            k--;
        }
    
    }
     std::vector<int> w;
    if (help_sum[0]==0) {
        w.resize(size-1);
        for (int q=0; q<size-1; q++) {
            w[q]=help_sum [q+1];
        }
        sum.new_number(size-1, w);
    }
    else sum.new_number(size, help_sum);

    if (!w.empty()) w.clear();
    
    return sum;
}

 CIntN0 operator-(const CIntN& A, const CIntN& B) {
     CIntN0 X = A;
     CIntN0 Y = B;
    CIntN0 dif;
    int i=X.get_lenght() -1;
    int j=Y.get_lenght() -1;
    int k=0;
    
    if(X.get_sign() == '+' && Y.get_sign() == '-') {
        CIntN0 tmp; tmp = Y; tmp.new_sign('+');
        dif = X + tmp;
        return dif;
      }
      if (X.get_sign() == '-' && Y.get_sign() == '+') {
        CIntN0 tmp = Y; tmp.new_sign('-');
        dif = X + tmp;
        return dif;
      }
      if (X.get_sign() == '-' && Y.get_sign() == '-') {
        CIntN0 tmp = X; tmp.new_sign('+');
        X = Y; X.new_sign('+');
        Y = tmp;
      }

    
    
    if (i==j) {
        bool er = 1;
        for(int i = 0; i < X.get_lenght(); i++){
            if(X.get_number()[i] > Y.get_number()[i]) break;
            if(X.get_number()[i] < Y.get_number()[i]){
                    er = 0;
                    break;
                    }
            }
        if(er == 0){
            CIntN0 fh;
            fh = X;
            X = Y;
            Y =fh;
            dif.new_sign('-');
            }
     }
        
     else if(i < j){
        CIntN0 H;
        H = X;
        X = Y;
        Y = H;
        i=X.get_lenght() -1;
        j=Y.get_lenght() -1;
        dif.set_lenght(j+1);
        k=i;
         dif.new_sign('-');
     }
     else {
        dif.set_lenght(i+1);
        k=i;
     }
    

    std::vector<int> help_dif(i+1, 0);
    
    std::vector<int> x(X.get_lenght());
    std::vector<int> y(Y.get_lenght());
    
    
    for (int q=0; q<X.get_lenght(); q++){
        x[q]=X.get_number()[q];
    }
    for (int q=0; q<Y.get_lenght(); q++){
        y[q]=Y.get_number()[q];
    }
    
    while (j >= 0) {
        if (x[i] >= y[j]) {
          help_dif[i] = x[i] - y[j];
            //std::cout << "qqqqqqqqq" << std::endl;
        }
        else {
          int e = i - 1;
          while (true) {
            if (x[e] == 0) x[e] = 9;
            else {
              x[e]--;
              help_dif[i] = x[i] + 10 - y[j];
              break;
            }
            e--;
          }
        }
        i--; j--;
      }


      while (i >= 0) {
        help_dif[i] = x[i];
        i--;
      }

    
    if (X.get_lenght()==1 && help_dif[0] ==0) {
        dif.new_number(1, help_dif);
        return  dif;
    }
    
    int first_nulls = 0;
    while (help_dif[first_nulls] == 0) first_nulls++;
    
    
     std::vector<int> f(X.get_lenght() - first_nulls);
     for(int q = 0; q < X.get_lenght() - first_nulls; q++) {
       f[q] = help_dif[q + first_nulls];
     }
     
     dif.new_number(X.get_lenght()-first_nulls, f);
        
    return dif;
}
