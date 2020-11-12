
#include"automata.h"

int main(){
  int va;
  AFD* automata = nullptr;
  bool flag= true;
  while(flag){
    std::cout<<"----------Menu----------- "<<std::endl;
    std::cout<<"1) Automata generado aleatoriamente"<<std::endl
            <<"2) Automata personalizado"<<std::endl
            <<"3) Brzozowski's del automata"<<std::endl
            <<"4) quivalencia de estados del automata"<<std::endl
            <<"0) Cancelar"<<std::endl;
    std::cin>>va;
    switch(va){
      case 1:{
              srand(time(nullptr));

              size_t estados, estado_inicial, c_estados_finales;

              estados = rand() % 10 + 1;
              estado_inicial = rand() % estados;
              c_estados_finales = rand() % estados + 1;
              std::set<int> temp;
              while(temp.size() != c_estados_finales){
                temp.insert(rand() %estados);
              }
              automata = new AFD(estados, estado_inicial, temp);
              for(size_t i = 0; i< estados; i++){
                automata->insertar_transicion(i,rand()%estados, 0);
                automata->insertar_transicion(i, rand()%estados, 1);
              }
              std::cout<<"Este es el automata: "<<std::endl;
              automata->print_afd();
              break;
             }
      case 2:{
              int estados, estado_inicial, c_estados_finales, estado_final_i;
              int estado_ac_i, estado_ac_f, trans;
              std::cin>>estados>> estado_inicial>>c_estados_finales;
              std::set<int> estados_finales;
              for(int i = 0; i < c_estados_finales; i++){
                std::cin>>estado_final_i;
                estados_finales.emplace(estado_final_i);
              }
              automata = new AFD(estados, estado_inicial, estados_finales);
              for(int i = 0; i <estados; i++){
                std::cin>>estado_ac_i>> trans>> estado_ac_f;
                automata->insertar_transicion(estado_ac_i, estado_ac_f, trans);
                std::cin>>estado_ac_i>> trans>> estado_ac_f;
                automata->insertar_transicion(estado_ac_i, estado_ac_f, trans);
              }
              std::cout<<"Este es el automata: "<<std::endl;
              automata->print_afd();
              break;
             }
      case 3:{
              if(!automata){
                std::cout<<"Generar un automata porfavor"<<std::endl;
                break;
              }
              break;
             }
      case 4:{
              if(!automata){
                std::cout<<"Generar un automata porfavor"<<std::endl;
                break;
              }
              automata->equivalentes();
              break;
             }
      case 0:
          flag = false;
          break;
    }
  }
  
  return 0;
}
