#include <robo_hardware2.h> 
#include <Servo.h>

#define DIV 50

float Dir;
float Esq;
float MaisDir;
float MaisEsq;

inline bool bbbb() {return (MaisEsq>DIV && Esq>DIV && Dir>DIV && MaisDir>DIV);}
inline bool bbbp() {return (MaisEsq>DIV && Esq>DIV && Dir>DIV && MaisDir<DIV);}
inline bool bbpb() {return (MaisEsq>DIV && Esq>DIV && Dir<DIV && MaisDir>DIV);}
inline bool bpbb() {return (MaisEsq>DIV && Esq<DIV && Dir>DIV && MaisDir>DIV);}
inline bool pbbb() {return (MaisEsq<DIV && Esq>DIV && Dir>DIV && MaisDir>DIV);}
inline bool ppbb() {return (MaisEsq<DIV && Esq<DIV && Dir>DIV && MaisDir>DIV);}
inline bool pppb() {return (MaisEsq<DIV && Esq<DIV && Dir<DIV && MaisDir>DIV);}
inline bool bbpp() {return (MaisEsq>DIV && Esq>DIV && Dir<DIV && MaisDir<DIV);}
inline bool bppp() {return (MaisEsq>DIV && Esq<DIV && Dir<DIV && MaisDir<DIV);}
inline bool bppb() {return (MaisEsq>DIV && Esq<DIV && Dir<DIV && MaisDir>DIV);}
inline bool pbpp() {return (MaisEsq<DIV && Esq>DIV && Dir<DIV && MaisDir<DIV);}
inline bool ppbp() {return (MaisEsq<DIV && Esq<DIV && Dir>DIV && MaisDir<DIV);}
inline bool pppp() {return (MaisEsq<DIV && Esq<DIV && Dir<DIV && MaisDir<DIV);}

inline bool   Frente(){return (bbbb() || bppb() );}
inline bool  Direita(){return (bbbp() || bbpb() || bbpp() || bppp() || ppbp());}
inline bool Esquerda(){return (pbbb() || bpbb() || ppbb() || pppb() || pbpp());}


void setup(){
  
  robo.configurar(false);
  
}


void loop(){

  Esq = robo.lerSensorLinhaEsq();
  Dir = robo.lerSensorLinhaDir(); 
  MaisEsq = robo.lerSensorLinhaMaisEsq();
  MaisDir = robo.lerSensorLinhaMaisDir(); 
  
  if(Frente()){
    robo.acionarMotores(50,50);
    }
  else if(Direita()){
    robo.acionarMotores(-50,50);
    }
  else if(Esquerda()){
    robo.acionarMotores(50,-50);
    }  
  else{
    robo.acionarMotores(0,0);
    }
} 
