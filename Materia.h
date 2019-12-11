#ifndef MATERIA_H
#define MATERIA_H
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include "Quiz.h"
#include "Assignment.h"
using namespace std;

class Materia
{
  private:
    string titulo;
    string maestro;
    vector<string> alumnos;
    vector<Quiz> quizes;
    vector<Assignment> tareas;

  public:
    Materia();
    void setTitulo(string);
    string getTitulo();
    void setMaestro(string);
    string getMaestro();
    void addAlumno(string);
    void addQuiz(Quiz);
    void addTarea(Assignment);
    vector<string> getAlumnos();
    vector<Quiz> getQuizes();
    vector<Assignment> getTareas();
    void accessQuiz(int, int, string);
};

Materia::Materia()
{
  vector<string> vacioalumnos;
  vector<Quiz> vacioquiz;
  vector<Assignment> vaciotarea;
  titulo="NA";
  maestro="NA";
  alumnos=vacioalumnos;
  quizes=vacioquiz;
  tareas=vaciotarea;
}

void Materia::setMaestro(string nomina)
{
  maestro=nomina;
}

string Materia::getMaestro()
{
  return maestro;
}

void Materia::setTitulo(string titulo)
{
  this->titulo=titulo;
}

string Materia::getTitulo()
{
  return titulo;
}

void Materia::addAlumno(string alumno)
{
  alumnos.emplace_back(alumno);
}

//hola
void Materia::addQuiz(Quiz quiz)
{
  quizes.emplace_back(quiz);
}

void Materia::addTarea(Assignment tarea)
{
  tareas.emplace_back(tarea);
}

vector<string> Materia::getAlumnos()
{
  return alumnos;
}

vector<Quiz> Materia::getQuizes()
{
  return quizes;
}

vector<Assignment> Materia::getTareas(){
  return tareas;
}

void Materia::accessQuiz(int i, int calif, string mat){
  quizes[i].setCalif(mat, calif);
}

#endif