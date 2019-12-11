#include "Usuario.h"
#include "Assignment.h"
#include "Quiz.h"
#include <vector>

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno: public Usuario {
  private:
    string sMatricula;
    string sCarrera;
    int iSemestre;
    
  public:
    Alumno();
    string getMatricula();
    void setMatricula(string sMatricula);
    string getCarrera();
    void setCarrera(string sCarrera);
    int getSemestre();
    void setSemestre(int iSemestre);
    void consultarQuiz(Quiz);
    void consultarAssignment(Assignment);
    Quiz contestarQuiz(Quiz&);
    Assignment contestarAssignment(Assignment&);
    int getCalif(Quiz);
    int getCalif(Assignment);
};

Alumno::Alumno()
{
  sMatricula="NA";
  sCarrera="NA";
  iSemestre=1;
}

void Alumno::setMatricula(string sMatricula)
{
  this->sMatricula=sMatricula;
}

Quiz Alumno::contestarQuiz(Quiz &quiz)
{
  cout << "metodo contestar quiz alumno"<<endl;
  quiz.contestarQuiz(sMatricula);
  quiz.calificarQuiz(sMatricula);
  quiz.verQuizResuelto(sMatricula);
  return quiz;
}

void Alumno::consultarQuiz(Quiz quiz)
{
  quiz.verQuizResuelto(sMatricula);
}

string Alumno::getMatricula()
{
  return sMatricula;
}

string Alumno::getCarrera()
{
  return sCarrera;
}

void Alumno::setCarrera(string sCarrera)
{
  this->sCarrera=sCarrera;
}

int Alumno::getSemestre()
{
  return iSemestre;
}

void Alumno::setSemestre(int iSemestre)
{
  this->iSemestre=iSemestre;
}

void Alumno::consultarAssignment(Assignment assignment)
{
  assignment.viewInstrucciones();
  assignment.viewSubmission(sMatricula);
  if(assignment.alumnoEntrego(sMatricula))
  {
    assignment.viewSubmission(sMatricula);
  }
}

Assignment Alumno::contestarAssignment(Assignment &assignment)
{
  assignment.submitAssignment(sMatricula);
  return assignment;
}

int Alumno::getCalif(Quiz quiz)
{
  return quiz.getCalif(sMatricula);
}

int Alumno::getCalif(Assignment tarea)
{
  return tarea.getCalif(sMatricula);
}

#endif