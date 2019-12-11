#include <iostream>
#include <string>
using namespace std;

#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
  private:
    string sNombre;
    int iEdad;
    char cGenero;
    string sContrasena;

  public:
    Usuario();
    string getNombre();
    void setNombre(string sNombre);
    int getEdad();
    void setEdad(int iEdad);
    char getGenero();
    void setGenero(char cGenero);
    string getContrasena();
    void setContrasena(string sContrasena);
};

Usuario::Usuario()
{
  sNombre = "";
  iEdad = -1;
  cGenero = ' ';
  sContrasena = "";
}

string Usuario::getNombre()
{
  return sNombre;
}

void Usuario::setNombre(string sNombre)
{
  this -> sNombre = sNombre;
}

int Usuario::getEdad()
{
  return iEdad;
}

void Usuario::setEdad(int iEdad)
{
  this -> iEdad = iEdad;
}

char Usuario::getGenero()
{
  return cGenero;
}

void Usuario::setGenero(char cGenero)
{
  this -> cGenero = cGenero;
}

string Usuario::getContrasena()
{
  return sContrasena;
}

void Usuario::setContrasena(string sContrasena)
{
  this -> sContrasena = sContrasena;
}

#endif