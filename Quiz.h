#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;

#ifndef QUIZ_H
#define QUIZ_H

class Quiz{
  private:
    vector<string> preguntas;
    vector<vector<string>>opciones;
    vector<int> correctas;
    int size;
    string titulo;
    map<string, int> calificaciones;
    map<string, vector<int>> respuestas;
    string autor;
  public:
    Quiz();
    void addPregunta();
    void addRespuestas(int, int);
    void setTitulo(string);
    string getTitulo();
    void setAutor(string);
    void verQuiz();
    void verQuizMaestro();
    void verQuizResuelto(string);
    void contestarQuiz(string);
    int calificarQuiz(string);
    int getCalif(string);
    void setCalif(string, int);
    bool yaContesto(string);
};
Quiz::Quiz(){
  vector<string> vacio1;
  vector<vector<string>> vacio2;
  vector<int> vacio3;
  map<string, int> mapaVacio;
  map<string, vector<int>> mapaVacioVectores;
  preguntas=vacio1;
  opciones=vacio2;
  correctas=vacio3;
  size=0;
  titulo="NA";
  calificaciones=mapaVacio;
  respuestas=mapaVacioVectores;
  autor="NA";
}
void Quiz::setTitulo(string titulo){
  this->titulo=titulo;
}
string Quiz::getTitulo(){
  return titulo;
}
void Quiz::setAutor(string autor){
  this->autor=autor;
}
void Quiz::addPregunta(){
  string pregunta;
  int sizeRespuestas;
  string respuesta;
  size++;
  cin.ignore(256, '\n');
  cout << "Pregunta " << size<<": ";
  getline(cin, pregunta);
  preguntas.push_back(pregunta);
  cout << "Numero de respuestas: ";
  cin >> sizeRespuestas;
  correctas.push_back(0);
  addRespuestas(size-1, sizeRespuestas);
}
void Quiz::addRespuestas(int indice, int sizeRespuestas){
  int num;
  string respuesta;
  vector <string> vacio;
  cin.ignore(256, '\n');
  for(int i=0; i<sizeRespuestas; i++){
    cout << i+1 << " ";
    getline(cin, respuesta);
    vacio.push_back(respuesta);
  }
  opciones.push_back(vacio);
  cout << "Ingresa el numero de la respuesta correcta: ";
  cin >> num;
  correctas.push_back(num-1);
}
void Quiz::verQuiz(){
  cout << titulo << endl;
  for(int i=0; i<size; i++){
    cout << i+1 << " " << preguntas[i]<< endl;
    for(int j=0; j<opciones[i].size(); j++){
      cout << " " <<j+1 << " " << opciones[i][j];
      cout << endl;
    }
    cout << endl;
  }
}
void Quiz::verQuizMaestro(){
  cout << titulo << endl;
  for(int i=0; i<size; i++){
    cout << i+1 << " " << preguntas[i]<< endl;
    for(int j=0; j<opciones[i].size(); j++){
      cout << " " <<j+1 << " " << opciones[i][j];
      if(j==correctas[i])
        cout << " <-- respuesta correcta";
      cout << endl;
    }
    cout << endl;
  }
}
void Quiz::verQuizResuelto(string matricula){
  if(calificaciones.find(matricula)==calificaciones.end()){
    verQuiz();
    return;
  }
  cout << titulo<<endl;
  cout << "Matricula: " << matricula << endl;
  for(int i=0; i<size; i++){
    cout << i+1 << " " << preguntas[i]<< endl;
    for(int j=0; j<opciones[i].size(); j++){
      cout << " " << j+1 << " " << opciones[i][j];
      if(respuestas[matricula][i]==j)cout << "<-- tu respuesta";
      cout << endl;
    }
    if(respuestas[matricula][i]==correctas[i])
      cout << "Respuesta correcta.";
    else
      cout << "Respuesta incorrecta. La respuesta correcta es: "<<correctas[i]+1<<" "<<opciones[i][correctas[i]];
    cout << endl;
  }
  cout << "Tu calificacion es: "<< calificaciones[matricula]<<endl;
}
void Quiz::contestarQuiz(string matricula){
  vector<int> vacio;
  int resp;
  for(int i=0; i<size; i++){
    cout << i+1 << " " << preguntas[i]<< endl;
    for(int j=0; j<opciones[i].size(); j++){
      cout << " " << j+1 << " " << opciones[i][j] << endl;
    }
    cout << "Tu respuesta: ";
    cin >> resp;
    vacio.push_back(resp-1);
    cout << endl;
  }
  respuestas[matricula]=vacio;
}
int Quiz::calificarQuiz(string matricula){
  vector<int>respuestasAlumno=respuestas[matricula];
  double calif=0;
  int iCalif=0;
  double incremento=100/size;
  for(int i=0; i<size; i++){
    if(respuestasAlumno[i]==correctas[i])calif+=incremento;
  }
  iCalif=calif+1;
  if(iCalif>100)iCalif=100;
  calificaciones[matricula]=iCalif;
  return iCalif;
}
int Quiz::getCalif(string matricula){
  return calificaciones[matricula];
}
bool Quiz::yaContesto(string matricula){
  if(calificaciones.find(matricula)!=calificaciones.end())return true;
  return false;
}
void Quiz::setCalif(string matricula, int calif){
  calificaciones[matricula]=calif;
}
#endif