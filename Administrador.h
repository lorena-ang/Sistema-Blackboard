#include "Usuario.h"
#include "Assignment.h"
#include "Quiz.h"
#include "Materia.h"
#include <vector>
#include <map>

#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
using namespace std;

class Administrador: public Usuario 
{
  private:
    string sCodigo;
    string sCargo;
    int iNivel;

  public:
    Administrador();
    string getCodigo();
    void setCodigo(string sCodigo);
    string getCargo();
    void setCargo(string sCargo);
    int getNivel();
    void setNivel(int iNivel);
    void consultarInfoAlumnos(vector<Alumno> alumnos);
    void consultarInfoMaestros(vector<Maestro> maestros);
    void consultarInfoAdmin(vector<Administrador> admin);
    void consultarInfoCursos(vector<Materia> materias);
    void asignarCursos(Usuario);
    Materia crearMateria(string nomina);
    void asignarAlumnos(Materia &materia, string matricula);
};

Administrador::Administrador()
{
  sCodigo = "";
  sCargo = "";
  iNivel = 1;
}

string Administrador::getCodigo()
{
  return sCodigo;
}

void Administrador::setCodigo(string sCodigo)
{
  this -> sCodigo = sCodigo;
}

string Administrador::getCargo()
{
  return sCargo;
}

void Administrador::setCargo(string sCargo)
{
  this -> sCargo = sCargo;
}

int Administrador::getNivel()
{
  return iNivel;
}

void Administrador::setNivel(int iNivel)
{
  this -> iNivel = iNivel;
}

void Administrador::consultarInfoAlumnos(vector<Alumno> alumnos)
{
  for (int i = 0; i < alumnos.size(); i++)
  {
    cout << "\nNombre: " << alumnos[i].getNombre() << endl;
    cout << "Matrícula: " << alumnos[i].getMatricula() << endl;
    cout << "Carrera: " << alumnos[i].getCarrera() << "   Semestre: " << alumnos[i].getSemestre() << endl;
  }
}

void Administrador::consultarInfoMaestros(vector<Maestro> maestros)
{
  for (int i = 0; i < maestros.size(); i++)
  {
    cout << "\nNombre: " << maestros[i].getNombre() << endl;
    cout << "Nómina: " << maestros[i].getNomina() << endl;
    cout << "Departamento: " << maestros[i].getDepartamento() << "   Oficina: " << maestros[i].getOficina() << endl;
  }
}

void Administrador::consultarInfoAdmin(vector<Administrador> admin)
{
  for (int i = 0; i < admin.size(); i++)
  {
    cout << "\nNombre: " << admin[i].getNombre() << endl;
    cout << "Nómina: " << admin[i].getCodigo() << endl;
    cout << "Cargo: " << admin[i].getCargo() << "   Nivel: " << admin[i].getNivel() << endl;
  }
}

void Administrador::consultarInfoCursos(vector<Materia> materias)
{
  for (int i=0; i<materias.size(); i++){
    cout << "Nombre de materia: " << materias[i].getTitulo() << endl;
    cout << "Maestro: " << materias[i].getMaestro()<< endl;
  }
}

void Administrador::asignarCursos(Usuario)
{

}

Materia Administrador::crearMateria(string nomina){
  Materia materia;
  string str;
  materia.setMaestro(nomina);
  cout << "Titulo de la materia: ";
  cin >> str;
  materia.setTitulo(str);
  return materia;
}

void Administrador::asignarAlumnos(Materia &materia, string matricula){
  materia.addAlumno(matricula);
}

#endif