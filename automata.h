#ifndef AUTOMATA_H
#define AUTOMATA_H

#include"libs.h"

typedef int t;

class AFD{
  public:
      AFD(int estados, int estado_inicial, std::set<int> estados_finales): estado_inicial(estado_inicial), estados_finales(estados_finales){
        std::vector<std::vector<std::pair<int, bool>>> vect(estados);
    
        afd = vect; 
        std::vector<std::vector<bool>> vect2(afd.size(), std::vector<bool>(afd.size(), true));
        equivalencia = vect2; 
      }
      ~AFD(){}
      void insertar_transicion(int estado_partida, int estado_llegada, bool transicion){
        afd[estado_partida].emplace_back(std::make_pair(estado_llegada, transicion));  
      }
      void print_afd(){
        std::cout<<afd.size()<<" "<<estado_inicial<<" "<<estados_finales.size()<<" ";
        for(auto j: estados_finales)
          std::cout<<j<<" ";
        
        std::cout<<std::endl;
        for(size_t i = 0; i < afd.size(); i++)
            for(auto it: afd[i])
              std::cout<<i<<" "<<it.second<<" "<<it.first<<std::endl;
      }
      void brzozowksi(){
      
      }
      void equivalentes(){
          for(size_t i = 0; i < afd.size();i++){
            for(size_t j = 0; j < afd.size(); j++){
              if(i == j)
                  continue;
              equivalencia[i][j] = check(i, j);
              equivalencia[j][i] = equivalencia[i][j];
            }
          } 
          
          std::cout<<" ";
          for(size_t i = 0; i < afd.size(); i++)
             std::cout<<" "<<i;
          std::cout<<std::endl; 
          for(size_t i= 0; i < afd.size(); i++){
            std::cout<<i<<" "; 
            for(auto j: equivalencia[i])
              std::cout<<j<<" ";
            std::cout<<std::endl;    
          }  
      }
  private:
      std::vector<std::vector<std::pair<int, bool>>> afd;
      int estado_inicial;
      std::set<int> estados_finales;
      std::vector<std::vector<bool>> equivalencia;
      

      bool secheck(int p, int q){
        auto pt = estados_finales.find(p);
        auto qt = estados_finales.find(q);
        bool p_is_final = pt != estados_finales.end();
        bool q_is_final = qt != estados_finales.end();
 
        if(p_is_final^ q_is_final){
          return false;
        }
        return true;
      }
      bool check(int p, int q){
        auto pt = estados_finales.find(p);
        auto qt = estados_finales.find(q);
        bool p_is_final = pt != estados_finales.end();
        bool q_is_final = qt != estados_finales.end();

        if(p_is_final^ q_is_final){
          return false;
        }
       
        if(!equivalencia[afd[p][0].first][afd[q][0].first] || !equivalencia[afd[p][1].first][afd[q][1].first]){
          return false;
        }
        else{
            
            return secheck(afd[p][0].first, afd[q][0].first) && secheck(afd[p][1].first, afd[q][1].first);
        }
       
      }
};

class AFN{
  public:
    AFN(){}
    ~AFN(){}

  private:
    std::vector<std::vector<std::pair<int, t>>> adj;
    int estado_inicial;
    std::set<int> estados_finales;

};

#endif
