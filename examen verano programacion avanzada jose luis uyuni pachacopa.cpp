//examen de programacion avanzada 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Ejercicio {
private:
	string nombre;
	string descripcion;
	string grupoMuscular;
	int dificultad;
	string imagen;
	string video;	
public:
	Ejercicio(string nom, string desc, string grupo, int dif, string img, string vid)
	: nombre(nom), descripcion(desc), grupoMuscular(grupo), dificultad(dif), imagen(img), video(vid) {}
	string getNombre() { return nombre; }
	string getDescripcion() { return descripcion; }
	string getGrupoMuscular() { return grupoMuscular; }
	int getDificultad() { return dificultad; }
	string getImagen() { return imagen; }
	string getVideo() { return video; }
	//funciones 
	void setNombre(string nom) { nombre = nom; }
	void setDescripcion(string desc) { descripcion = desc; }
	void setGrupoMuscular(string grupo) { grupoMuscular = grupo; }
	void setDificultad(int dif) { dificultad = dif; }
	void setImagen(string img) { imagen = img; }
	void setVideo(string vid) { video = vid; }
};
//nuevo clase Rutina
class Rutina {
private:
	string nombre;
	vector<Ejercicio> ejercicios;
	int tiempoDescanso;
public:
	Rutina(string nom, int descanso)
	: nombre(nom), tiempoDescanso(descanso) {}
	
	void agregarEjercicio(Ejercicio ejercicio) {
    ejercicios.push_back(ejercicio);
	}
	string getNombre() { return nombre; }
	vector<Ejercicio> getEjercicios() { return ejercicios; }
	int getTiempoDescanso() { return tiempoDescanso; }
	//funcion dell ejercicio
	void setNombre(string nom) { nombre = nom; }
	void setTiempoDescanso(int descanso) { tiempoDescanso = descanso; }
};
// Clase Usuario
class Usuario {
private:
	string nombre;
	int nivel;
	string objetivo;
	vector<RutinaCompletada> historialRutinas;
	
public:
	Usuario(string nom, int niv, string obj)
		: nombre(nom), nivel(niv), objetivo(obj) {}
	
	void agregarRutinaCompletada(RutinaCompletada rutinaCompletada) {
		historialRutinas.push_back(rutinaCompletada);
	}
	
	// Getters
	string getNombre() { return nombre; }
	int getNivel() { return nivel; }
	string getObjetivo() { return objetivo; }
	vector<RutinaCompletada> getHistorialRutinas() { return historialRutinas; }
};
