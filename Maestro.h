#include "Usuario.h"
#include "Assignment.h"
#include "Quiz.h"
using namespace std;

#ifndef MAESTRO_H
#define MAESTRO_H

class Maestro: public Usuario 
{
  private:
    string nomina;
    string oficina;
    string departamento;
  public:
    Maestro();
    string getNomina();
    void setNomina(string);
    string getOficina();
    void setOficina(string);
    string getDepartamento();
    void setDepartamento(string);
    Quiz crearQuiz();
    Assignment crearAssignment();
    void consultarAssignment(Assignment);
    void calificarAssignment(Assignment&);
};

Maestro:: Maestro()
{
  nomina="NA";
  oficina= "NA";
  departamento="NA";
}

string Maestro::getNomina()
{
  return nomina;
}

void Maestro::setNomina(string nomina)
{
  this->nomina=nomina;
}

string Maestro::getOficina()
{
  return oficina;
}

void Maestro::setOficina(string oficina)
{
  this->oficina=oficina;
}

string Maestro::getDepartamento()
{
  return departamento;
}

void Maestro::setDepartamento(string departamento)
{
  this->departamento=departamento;
}

Quiz Maestro::crearQuiz()
{
  Quiz quiz;
  string titulo;
  int iPreguntas;
  cout << "Titulo del quiz: ";
  //cin.ignore(256, '\n');
  getline(cin, titulo);
  quiz.setTitulo(titulo);
  quiz.setAutor(nomina);
  cout << "Numero de preguntas: ";
  cin >> iPreguntas;
  for(int i=0; i<iPreguntas; i++){
    quiz.addPregunta();
  }
  cout << "Quiz " << titulo << " creado."<<endl;
  quiz.verQuizMaestro();
  return quiz;
}

Assignment Maestro::crearAssignment()
{
  Assignment assignment;
  string title, doc;
  cout << "Ingrese el título de la tarea: ";
  cin.ignore();
  getline(cin, title);
  assignment.setTitulo(doc);
  cout << "Ingresa el nombre del archivo con las instrucciones de la tarea (incluyendo .txt): ";
  cin >> doc;
  assignment.setInstrucciones(doc);
  cout << "Tarea creada."<<endl;
  consultarAssignment(assignment);
  return assignment;
}

void Maestro::consultarAssignment(Assignment assignment)
{
  assignment.viewInstrucciones();
}

void Maestro::calificarAssignment(Assignment &assignment){
  assignment.calificarAssignments();
}

#endif