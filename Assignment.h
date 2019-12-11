#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <fstream>
#include <iterator>
#include <iostream>
using namespace std;

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

class Assignment{
  private:
    string titulo;
    string instrucciones;
    string nominaMaestro;
    map<string, string> submissions;
    map<string, int> calificaciones;
  public:
    Assignment();
    void setTitulo(string);
    string getTitulo();
    void setInstrucciones(string);
    void submitAssignment(string);
    void viewSubmission(string);
    void calificarAssignments();
    void viewInstrucciones();
    bool alumnoEntrego(string);
    int getCalif(string);
};

Assignment::Assignment(){
  titulo="NA";
  instrucciones="NA";
  nominaMaestro="NA";
  map<string, string> empty;
  map<string, int> emptyInt;
  submissions=empty;
  calificaciones=emptyInt;
}

string Assignment::getTitulo()
{
  return titulo;
}

void Assignment::setTitulo(string titulo){
  this->titulo=titulo;
}

void Assignment::setInstrucciones(string instrucciones){
  this->instrucciones=instrucciones;
}

void Assignment::submitAssignment(string matricula){
  string s;
  cout << "Escribe el nombre del archivo de texto de tu tarea (con el txt) ";
  cin >> s;
  submissions[matricula]=s;
  cout << submissions[matricula]<<endl;
}

void Assignment::viewSubmission(string matricula){
  string str=submissions[matricula];
  string line;
  ifstream file;
  file.open(str); 
  while(file){
    getline(file, line);
    cout << line << endl;
  }
}

void Assignment::calificarAssignments(){
  map<string, string>::iterator it;
  int iCalif;
  for(it=submissions.begin(); it!=submissions.end(); it++){
    cout << "hola";
    viewSubmission(it->first);
    cout << "Calificación (del 1 al 100): ";
    cin >> iCalif;
    calificaciones[it->first]=iCalif;
  }
  cout << "holaaa" << endl;
  //el mapa esta vacio, no mete nada
}

void Assignment::viewInstrucciones(){
  string line;
  ifstream file;
  file.open(instrucciones); 
  while(file){
    getline(file, line);
    cout << line << endl;
  } 
}

bool Assignment::alumnoEntrego(string matricula){
  if(submissions.find(matricula)!=submissions.end())return true;
  return false;
}

int Assignment::getCalif(string matricula){
  return calificaciones[matricula];
}

#endif