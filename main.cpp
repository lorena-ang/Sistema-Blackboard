#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iterator>
#include "Usuario.h"
#include "Maestro.h"
#include "Alumno.h"
#include "Assignment.h"
#include "Administrador.h"
using namespace std;

map<string, string> mapAdmin;
map<string, string> mapMaes;
map<string, string> mapAlum;
map<string, string>::iterator itrAdmin;
map<string, string>::iterator itrMaes;
map<string, string>::iterator itrAlum;

int autentificacion(string sCuenta, string sContrasena)
{
  int iNivel;

  itrAdmin = mapAdmin.find(sCuenta);
  itrMaes = mapMaes.find(sCuenta);
  itrAlum = mapAlum.find(sCuenta);

  if (itrAdmin != mapAdmin.end())
  {
    if (itrAdmin->second == sContrasena)
    {
      iNivel = 1;
    }
    else
    {
      iNivel = -1;
    }
  }
  else if (itrMaes != mapMaes.end())
  {
    if (itrMaes->second == sContrasena)
    {
      iNivel = 2;
    }
    else
    {
      iNivel = -1;
    }
  }
  else if (itrAlum != mapAlum.end())
  {
    if (itrAlum->second == sContrasena)
    {
      iNivel = 3;
    }
    else
    {
      iNivel = -1;
    }
  }
  else
  {
    iNivel = -1;
  }
  return iNivel;
}

int main() 
{
  string sCuenta, sContrasena, sTitulo, sMaestro;
  int iOpcion, iOpcion1, iOpcion2, iNivel;
  string s1, s2, s3, cuenta, contra, carrera, mat, nomArch, oficina;
  int edad, semestre;
  char genero;
  vector<Alumno> alumnos;
  vector<Maestro> maestros;
  vector<Administrador> admin;
  vector<Materia> materias;
  Alumno a1;
  Maestro m1;
  Administrador adm;
  ifstream archivo;
  
  // Registrar primer usuario - administrador
  mapAdmin.emplace("L01234567", "contra1");

  do {
    cout << "\nBlackboard\n";
    cout << "Seleciona 1 para entrar o 0 para salir: \n";
    cin >> iOpcion;

    if (iOpcion == 1)
    {
      do {
        do {
          cout << "\nUsuario: ";
          cin >> sCuenta;
          cout << "Contraseña: ";
          cin >> sContrasena;
          cout << "Selecciona 1 para iniciar sesión o 2 para corregir tus datos: ";
          cin >> iOpcion1;
        } while (iOpcion1 != 1);

        iNivel = autentificacion(sCuenta, sContrasena);

        if (iNivel == -1)
        {
          cout << "Error, usuario o contraseña incorrectos. Intenta de nuevo.\n";
        }
      } while (iNivel != 1 && iNivel != 2 && iNivel != 3);
      
      cout << "\n¡Bienvenido!\n";
      
      // MENU DE ADMINISTRADOR
      if (iNivel == 1)
      {
        do {
          cout << "\nMenú de opciones:\n";
          cout << "0. Cerrar sesión \n1. Registrar alumnos \n2. Registrar maestros \n3. Registrar administradores \n4. Asignar cursos \n5. Ver todos los cursos \n6. Ver todos los alumnos \n7. Ver todos los maestros \n8. Ver todos los administradores\n";
          cout << "Ingresa tu opción: ";
          cin >> iOpcion2;

          switch (iOpcion2)
          {
            case 0:
              cout << "\n¡Hasta luego!\n";
              break;

            case 1:
              cout << "\nRegistro de alumnos\n";
              cout << "Teclea el nombre del archivo con extension: ";
              cin >> nomArch;
              archivo.open(nomArch.c_str());
              while(!archivo.eof())
              {
                archivo >> mat >> contra >> carrera >> semestre >> s1 >> s2 >> s3 >> edad >> genero;
                s1 += " " + s2 + " " + s3;
                a1.setMatricula(mat);
                a1.setContrasena(contra);
                a1.setCarrera(carrera);
                a1.setSemestre(semestre);
                a1.setEdad(edad);
                a1.setNombre(s1);
                a1.setGenero(genero);
                alumnos.emplace_back(a1);
                mapAlum.emplace(mat, contra);
              }
              archivo.close();
              cout << "Registro exitoso\n";
              break;
            
            case 2:
              cout << "\nRegistro de maestros\n";
              cout << "Teclea el nombre del archivo con extension: ";
              cin >> nomArch;
              archivo.open(nomArch.c_str());
              while(!archivo.eof())
              { 
                archivo >> mat >> contra >> carrera >> oficina >>s1 >> s2 >> s3 >> edad >> genero;
                s1 += " " + s2 + " " + s3;
                m1.setNomina(mat);
                m1.setContrasena(contra);
                m1.setDepartamento(carrera);
                m1.setOficina(oficina);
                m1.setEdad(edad);
                m1.setNombre(s1);
                m1.setGenero(genero);
                maestros.emplace_back(m1);
                mapMaes.emplace(mat, contra); 
              }
              archivo.close();
              cout << "Registro exitoso\n";
              break;

            case 3:
              cout << "\nRegistro de administradores\n";
              cout << "Teclea nombre de archivo con extension: ";
              cin >> nomArch;
              archivo.open(nomArch.c_str());
              while(!archivo.eof())
              {
                archivo >> mat >> contra >> carrera >> semestre >>s1 >> s2 >> s3 >> edad >> genero;
                s1 += " " + s2 + " " + s3;
                adm.setCodigo(mat);
                adm.setContrasena(contra);
                adm.setCargo(carrera);
                adm.setNivel(semestre);
                adm.setEdad(edad);
                adm.setNombre(s1);
                adm.setGenero(genero);
                admin.emplace_back(adm);
                mapAdmin.emplace(mat, contra);
              }
              archivo.close();
              cout << "Registro exitoso\n";
              break;

            case 4:
              {
                cout << "\nAsignar cursos\n\n";
                cout << "Elige un maestro de los ya registrados" << endl;
                int x;
                for(int i=0; i<maestros.size(); i++){
                  cout << i <<" "<< maestros[i].getNomina()<< endl;
                }
                cout << "Maestro con índice: ";
                cin >> x;
                Materia materia = adm.crearMateria(maestros[x].getNomina());
                x = 0;
                cout << "\nEscribe el indice de los alumnos que quieras inscribir. Escribe -1 cuando termines." << endl;
                for(int i = 0; i < alumnos.size(); i++)
                {
                  cout << i << " " << alumnos[i].getMatricula() << endl;
                }
                cout << "índice: ";
                cin >> x;
                while (x != -1)
                {
                  adm.asignarAlumnos(materia, alumnos[x].getMatricula());
                  cout << "Alumno asignado.\n";
                  cout << "índice: ";
                  cin >> x;
                }
                materias.emplace_back(materia);
                cout << "Asignación exitosa\n";
              }
              break;

            case 5:
              cout << "\nCursos existentes:\n";
              for (int i = 0; i < materias.size(); i++)
              {
                cout << "Materia: " << materias[i].getTitulo() << "   Maestro: " << materias[i].getMaestro() << endl;
              }
              break;

            case 6:
              cout << "\nAlumnos registrados:\n";
              adm.consultarInfoAlumnos(alumnos);
              break;

            case 7:
              cout << "\nMaestros registrados:\n";
              adm.consultarInfoMaestros(maestros);
              break;
            
            case 8:
              cout << "\nAdministradores registrados:\n";
              adm.consultarInfoAdmin(admin);
              break;
            
            default:
              cout << "Error, ingresa un valor válido.\n";
              break;
          }
        } while (iOpcion2 != 0);
      }
      // MENU DE MAESTRO
      else if (iNivel == 2)
      {
          int x;
          int y;
          int z;
          for (int i = 0; i < maestros.size(); i++)
          {
            if (sCuenta == maestros[i].getNomina())
            {
              x = i;
              break;
            }
          }
          for(int i = 0; i < materias.size(); i++)
          {
            if (materias[i].getMaestro() == maestros[x].getNomina())
            {
              cout << i << " " << materias[i].getTitulo() << endl;
            }
          }
          cout << "Elige una materia: ";
          cin >> y;
        do {
          cout << "\nMenú de opciones:\n";
          cout << "0. Cerrar sesión \n1. Visualizar perfil \n2. Editar perfil \n3. Elegir curso \n4. Editar información del curso \n5. Crear un assignment \n6. Ver assignments \n7. Calificar un assignment \n8. Crear un quiz \n9. Visualizar calificaciones\n";
          cout << "Ingresa tu opción: ";
          cin >> iOpcion2;
          
          switch (iOpcion2)
          {
            case 0:
              cout << "\n¡Hasta luego!\n";
              break;

            case 1:
              {
                cout << "\nDatos del perfil\n";
                for (int i = 0; i < maestros.size(); i++){
                  if (sCuenta == maestros[i].getNomina()){
                  cout << "Nombre: " << maestros[i].getNombre() << endl;
                  cout << "Género (F/M): " << maestros[i].getGenero() << endl;
                  cout << "Departamento: " << maestros[i].getDepartamento() << endl;
                  cout << "Oficina: " << maestros[i].getOficina() << endl;
                  break;
                  }
                }
              }
              break;

            case 2:
              {
                cout << "\nEditar perfil\n";
                for (int i = 0; i < maestros.size(); i++){
                  if (sCuenta == maestros[i].getNomina()){
                    cout << "Nombre: ";
                    cin.ignore();
                    getline (cin, cuenta);
                    maestros[i].setNombre(cuenta);
                    cout << "Género (F/M): ";
                    cin >> genero;
                    maestros[i].setGenero(genero);
                    cout << "Departamento: ";
                    cin >> carrera;
                    maestros[i].setDepartamento(carrera);
                    cout << "Oficina: ";
                    cin >> oficina;
                    maestros[i].setOficina(oficina);
                    break;
                  }
                }
              }
              break;

            case 3:
              {
                cout << "\nElegir curso\n";
                for(int i = 0; i < materias.size(); i++)
                {
                  if (materias[i].getMaestro() == maestros[x].getNomina())
                  {
                    cout << i << " " << materias[i].getTitulo() << endl;
                  }
                }
                cout << "Elige una materia: ";
                cin >> y;
              }
              break;

            case 4:
              {
                cout << "\nEditar curso\n";
                for(int i = 0; i < materias.size(); i++)
                {
                  if (materias[i].getMaestro() == maestros[x].getNomina())
                  {
                    cout << "Título: ";
                    cin >> sTitulo;
                    materias[i].setTitulo(sTitulo);
                    cout << "Datos editados exitosamente.\n";
                  }
                }
              }
              break;

            case 5:
              {
                cout << "\nCrear un assignment\n";
                Assignment tarea;
                tarea=maestros[x].crearAssignment();
                materias[y].addTarea(tarea);
              }
              break;

            case 6:
              {
                cout << "\nAssignments\n";
                vector<Assignment>tareas=materias[y].getTareas();
                for(int i=0; i<tareas.size(); i++){
                  cout << i << " "<< tareas[i].getTitulo()<<endl;
                }
              }
              break;

            case 7:
              {
                cout << "\nCalificar un assignment\n";
                vector<Assignment>tareas=materias[y].getTareas();
                for(int i=0; i<tareas.size(); i++){
                  cout << i << " "<< tareas[i].getTitulo()<<endl;
                }
                cin >> z;
                maestros[x].calificarAssignment(materias[y].getTareas()[z]);
              }
              break;

            case 8:
              {
                cout << "\nCrear un quiz\n";
                Quiz quiz;
                quiz=maestros[x].crearQuiz();
                materias[y].addQuiz(quiz);
              }
              break;
            
            case 9:
              {
                cout << "\nVer calificaciones\n";
                //vector<Quiz> quizes;
                vector<Assignment> tareas;
                //quizes=materias[y].getQuizes();
                tareas=materias[y].getTareas();
                vector<string> matriculas = materias[y].getAlumnos();
                for(int i=0; i < materias[y].getAlumnos().size(); i++){
                  cout << materias[y].getAlumnos()[i]<<endl;
                  for(int j=0; j<materias[y].getQuizes().size(); j++){
                    cout << materias[y].getQuizes()[j].getTitulo()<<": ";
                    //if(quizes[j].yaContesto(matriculas[i])){
                      cout << materias[y].getQuizes()[j].getCalif(materias[y].getAlumnos()[i])<<endl;
                    //}else{
                    //  cout << 0 << endl;
                    //}
                  }
                  for(int j=0; j<tareas.size(); j++){
                    cout << tareas[j].getTitulo()<<": ";
                    if(tareas[j].alumnoEntrego(matriculas[i])){
                      cout << tareas[j].getCalif(matriculas[i])<<endl;
                    }else{
                      cout << 0 << endl;
                    }
                  }
                }
              }
              break;
            
            default:
              cout << "Error, ingresa un valor válido.\n";
              break;
          }
        } while (iOpcion2 != 0);
      }
      // MENU DE ALUMNO
      else if (iNivel == 3)
      {
        int x, y, z;
        for (int i = 0; i < alumnos.size(); i++)
          {
            if (sCuenta == alumnos[i].getMatricula())
            {
              x = i;
              break;
            }
          }
          for(int i = 0; i < materias.size(); i++)
          { 
            vector<string> mats=materias[i].getAlumnos();
            for(int j=0; j<mats.size(); j++){
              if(mats[j]==sCuenta){
                cout << i << " " << materias[i].getTitulo()<<endl;
                j=mats.size();
              }
            }
          }
          cout << "Elige una materia: ";
          cin >> y;

        do {
        
          cout << "\nMenú de opciones:\n";
          cout << "0. Cerrar sesión \n1. Visualizar perfil \n2. Editar perfil \n3. Ver cursos en los que estoy inscrito\n4. Ver quizzes disponibles \n5. Ver assignments disponibles \n6. Contestar un quiz \n7. Enviar un assignment\n";
          cout << "Ingresa tu opción: ";
          cin >> iOpcion2;

          switch (iOpcion2)
          {
            case 0:
              cout << "\n¡Hasta luego!\n";
              break;

            case 1:
              cout << "\nDatos del perfil\n";
              for (int i = 0; i < alumnos.size(); i++){
                if (sCuenta == alumnos[i].getMatricula()){
                cout << "Nombre: " << alumnos[i].getNombre() << endl;
                cout << "Genero (F/M): " << alumnos[i].getGenero() << endl;
                cout << "Carrera: " << alumnos[i].getCarrera() << endl;
                cout << "Semestre: " << alumnos[i].getSemestre() << endl;
                break;
                }
              }
              break;

            case 2:
              cout << "\nEditar perfil\n";
               for (int i = 0; i < alumnos.size(); i++)
               {
                 if (sCuenta == alumnos[i].getMatricula()){
                  cout << "Nuevo nombre: ";
                  cin.ignore();
                  getline (cin, cuenta);
                  alumnos[i].setNombre(cuenta);
                  cout << "Nuevo género: ";
                  cin>> genero;
                  alumnos[i].setGenero(genero);
                  cout << "Nueva carrera: ";
                  cin >> carrera;
                  alumnos[i].setCarrera(carrera);
                  cout << "Nuevo semestre: ";
                  cin >> semestre;
                  alumnos[i].setSemestre(semestre);
                  break;
                 }
                }
              break;

            case 3:
              cout << "\nVer cursos\n";
              for(int i = 0; i < materias.size(); i++)
              { 
              vector<string> mats=materias[i].getAlumnos();
              for(int j=0; j<mats.size(); j++){
                if(mats[j]==sCuenta){
                  cout << i << " " << materias[i].getTitulo()<<endl;
                  j=mats.size();
                }
              }
              }
              cout << "Elige una materia: ";
              cin >> y;
              // case
              break;

            case 4:
              {
                cout << "\nQuizzes\n";
                vector<Quiz>quizes2=materias[y].getQuizes();
                for(int i=0; i<quizes2.size(); i++){
                  cout << i << " "<< quizes2[i].getTitulo()<<endl;
                }
              }
              break;

            case 5:
              {
                cout << "\nAssignments: \n";
                vector<Assignment>tareas=materias[y].getTareas();
                for(int i=0; i<tareas.size(); i++){
                  cout << i << " "<< tareas[i].getTitulo()<<endl;
                }
              }
              break;

            case 6:
              {
                cout << "\nContestar un quiz\n";
                vector<Quiz>quizes=materias[y].getQuizes();
                for(int i=0; i<quizes.size(); i++){
                  cout << i << " "<< quizes[i].getTitulo()<<endl;
                }
                cout << "Elige el indice de un quiz: ";
                cin >> z;
                materias[y].getQuizes()[z]=alumnos[x].contestarQuiz(materias[y].getQuizes()[z]);
                int c= materias[y].getQuizes()[z].getCalif(alumnos[x].getMatricula());
                materias[y].accessQuiz(z, c, alumnos[x].getMatricula());
              }
              break;

            case 7:
              {
                cout << "\nEnviar assignment\n";

                vector<Assignment>tareas2=materias[y].getTareas();
                for(int i=0; i<tareas2.size(); i++){
                  cout << i << " "<< tareas2[i].getTitulo()<<endl;
                }
                cout << "Elige el indice de un assignment: ";
                cin >> z;
                alumnos[x].contestarAssignment(materias[y].getTareas()[z]);
              }
              break;
            
            default:
              cout << "Error, ingresa un valor válido.\n";
              break;
          }
        } while (iOpcion2 != 0);
      }
    }
    else if (iOpcion == 0)
    {
      cout << "\n¡Gracias por usar Blackboard!\n";
    }
    else
    {
      cout << "Error, ingresa un dato válido.\n";
    }
  } while (iOpcion != 0);
  


  
  Quiz quiz;
  Assignment tarea;
  string t;
  int s;
  Maestro maestro;
  Alumno alumno;
  alumno.setMatricula("A01114487");
  tarea=maestro.crearAssignment();
  maestro.consultarAssignment(tarea);
  alumno.consultarAssignment(tarea);
  alumno.contestarAssignment(tarea);
  alumno.consultarAssignment(tarea);

  /*quiz=maestro.crearQuiz();
  alumno.contestarQuiz(quiz);
  alumno.consultarQuiz(quiz);*/

}