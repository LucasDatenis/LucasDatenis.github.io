#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "cCentro_Testeo.h"
#include "Enum.h"


using namespace std;


int main()
{
    cPaciente* Paciente1 = new cPaciente("Lucas", "Datenis", 44710445, "2162-7883", false, false, false, false, true, false);
    cPaciente* Paciente2 = new cPaciente("Julio", "Conte", 12345678, "", true, false, false, true, false, true);
    cPaciente* Paciente3 = new cPaciente("Ezequiel", "Stanganelli", 32344853, "3365-5585", false, true, false, true, true, false);
    cPaciente* Paciente4 = new cPaciente("Hernan", "Valero", 35667878, "2765-5765", true, false, false, true, true, false);


    Paciente1->to_stringdni(Paciente1->getdni());
    Paciente2->to_stringdni(Paciente2->getdni());
    Paciente3->to_stringdni(Paciente3->getdni());
    Paciente4->to_stringdni(Paciente4->getdni());

    cout << "Pacientes" << endl;
    Paciente1->imprimirPaciente();
    Paciente2->imprimirPaciente();
    Paciente3->imprimirPaciente();
    Paciente4->imprimirPaciente();

    CentroDeTesteo* centro1 = new CentroDeTesteo(1, "Lomas de Zamora", "Gandulfo");
    CentroDeTesteo* centro2 = new CentroDeTesteo(2, "Temperley", "Juncal");

    cLaboratorio* labo1 = new cLaboratorio(1, "Laboratorio Gonzalez", "Templery");
    cLaboratorio* labo2 = new cLaboratorio(2, "Laboratorio Martinez", "Lomas de Zamora");

    centro1->to_stringid(centro1->getid());
    centro2->to_stringid(centro2->getid());
    labo1->to_stringid(labo1->getid());
    labo2->to_stringid(labo2->getid());

    cout << "Centros" << endl;
    centro1->imprimircentro();
    centro2->imprimircentro();
    cout << "Laboratorios" << endl;
    labo1->imprimirlaboratorio();
    labo2->imprimirlaboratorio();

    //Asociacion de laboratorios
    centro1->Asociar_Laboratorio(labo1);
    centro2->Asociar_Laboratorio(labo2);


    //Alta de Pacientes en el primer centro
    
    centro1->altapaciente(Paciente1);
    centro1->altapaciente(Paciente2);
    centro2->altapaciente(Paciente3);
    centro2->altapaciente(Paciente4);
    



    //Muestras ya en laboratorio de Pacientes
    //En el centro 1
    //Paciente 1 y 2
    
    centro1->Mandar_Testeo(Paciente1, labo1);
    centro1->Mandar_Testeo(Paciente2, labo1);
    labo1->RecibirMuestra();
    labo1->RecibirMuestra();
    labo1->AnalisisMuestra();
    labo1->avisarpaciente();
    centro1->bajapaciente();
    
    
    //En el centro 2
    //Paciente 3 y 4
    
    centro2->Mandar_Testeo(Paciente3, labo2);
    centro2->Mandar_Testeo(Paciente4, labo2);
    labo2->RecibirMuestra();
    labo2->RecibirMuestra();
    labo2->AnalisisMuestra();
    labo2->avisarpaciente();
    centro2->bajapaciente();
    //Damos de baja el paciente


    //Desasociamos el labroatorio
    centro1->Desasociar_Laboratorio();
    centro2->Desasociar_Laboratorio();
    

    //Liberamos memoria

    
    delete centro1;
    delete centro2;
    delete labo1;
    delete labo2;
    delete Paciente1;
    delete Paciente2;
    delete Paciente3;
    delete Paciente4;
    return 0;
}

