//examen segundo parcial de programacion avanzada 
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
// Clase Tiempo
class Tiempo {
public:
	int Hora;
	int Minuto;
	
	Tiempo(int hora = 0, int minuto = 0) : Hora(hora), Minuto(minuto) {}
	
	Tiempo SumarHoras(int horas) const {
		Tiempo nuevaHora = *this;
		nuevaHora.Hora += horas;
		nuevaHora.Hora %= 24;
		return nuevaHora;
	}
	
	int ConvertirAMinutos() const {
		return Hora * 60 + Minuto;
	}
	
	bool operator==(const Tiempo& t) const {
		return Hora == t.Hora && Minuto == t.Minuto;
	}
};

// Clase Alarma
class Alarma {
public:
	Tiempo Hora;
	int Tolerancia;
	bool fueApagadaEnHora;
	
	Alarma(Tiempo hora, int tolerancia) : Hora(hora), Tolerancia(tolerancia), fueApagadaEnHora(false) {}
	
	Tiempo SumarHoras(int horas) const {
		return Hora.SumarHoras(horas);
	}
	
	int ConvertirAMinutos() const {
		return Hora.ConvertirAMinutos();
	}
	
	bool RevisarHora(Tiempo t) {
		int minutosAlarma = Hora.ConvertirAMinutos();
		int minutosT = t.ConvertirAMinutos();
		if (abs(minutosAlarma - minutosT) <= Tolerancia) {
			fueApagadaEnHora = true;
			return true;
		}
		return false;
	}
};

// Clase Medicamento
class Medicamento {
public:
	char Tipo;
	int Cantidad;
	int FrecuenciaHoras;
	
	Medicamento(char tipo, int cantidad) : Tipo(tipo), Cantidad(cantidad), FrecuenciaHoras(0) {}
	
	void CalcularFrecuencia(int NroDias) {
		if (Tipo == 'T') {  // Tableta
			FrecuenciaHoras = (24 * NroDias) / Cantidad;
		} else if (Tipo == 'J') {  // Jarabe
			FrecuenciaHoras = (24 * NroDias) / (Cantidad / 25);
		}
	}
};

// Clase Cronograma
class Cronograma {
public:
	Tiempo HoraInicioTratamiento;
	int NroDia;
	Medicamento medicamento;
	vector<Alarma> alarmas;
	vector<Tiempo> listaHoras;
	int NroAlarmas;
	int PosicionAlarma;
	
	Cronograma(Tiempo inicio, int dia, Medicamento med)
		: HoraInicioTratamiento(inicio), NroDia(dia), medicamento(med), NroAlarmas(0), PosicionAlarma(0) {}
	
	void CrearAlarmas() {
		medicamento.CalcularFrecuencia(NroDia);
		Tiempo horaActual = HoraInicioTratamiento;
		for (int i = 0; i < (24 * NroDia) / medicamento.FrecuenciaHoras; ++i) {
			alarmas.push_back(Alarma(horaActual, 5));  // Tolerancia de 5 minutos por ejemplo
			horaActual = horaActual.SumarHoras(medicamento.FrecuenciaHoras);
		}
		NroAlarmas = alarmas.size();
	}
	
	void ImprimirRutina() const {
		std::string dias[] = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo"};
		for (int i = 0; i < NroAlarmas; ++i) {
			cout << "Día " << dias[(NroDia - 1 + i / (24 / medicamento.FrecuenciaHoras)) % 7] << ": "
				<< alarmas[i].Hora.Hora << ":" << alarmas[i].Hora.Minuto << "\n";
		}
	}
	
	void VerHistorial() const {
		for (size_t i = 0; i < listaHoras.size(); ++i) {
			cout << "Alarma " << i + 1 << ": ";
			if (listaHoras[i].Hora == -1 && listaHoras[i].Minuto == -1) {
				cout << "No se atendió\n";
			} else {
				cout << "Apagada a las " << listaHoras[i].Hora << ":" << listaHoras[i].Minuto << "\n";
			}
		}
	}
	
	bool CumplioTratamiento() const {
		return all_of(listaHoras.begin(), listaHoras.end(), [](Tiempo t) { return !(t.Hora == -1 && t.Minuto == -1); });
	}
	
	void AtenderAlarma(Tiempo hora) {
		if (PosicionAlarma < NroAlarmas && alarmas[PosicionAlarma].RevisarHora(hora)) {
			listaHoras.push_back(hora);
		} else {
			listaHoras.push_back(Tiempo(-1, -1));  // No se atendió
		}
		++PosicionAlarma;
	}
};

int main() {
	// Ejemplo de uso
	Tiempo inicio(9, 0); // 09:00 AM
	Medicamento med('T', 12); // Tipo Tableta, 12 tabletas
	
	Cronograma cronograma(inicio, 4, med); // Empieza en miércoles, tratamiento de 4 días
	cronograma.CrearAlarmas();
	
	cronograma.ImprimirRutina();
	cronograma.AtenderAlarma(Tiempo(9, 5)); // Atender la primera alarma a las 09:05 AM
	cronograma.VerHistorial();
	
	if (cronograma.CumplioTratamiento()) {
		cout << "Se cumplió estrictamente el tratamiento\n";
	} else {
		cout << "No se cumplió estrictamente el tratamiento\n";
	}
	
	return 0;
}
