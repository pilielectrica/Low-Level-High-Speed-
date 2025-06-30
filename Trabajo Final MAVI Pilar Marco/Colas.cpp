#include "Colas.h"

Colas::Colas()
{
	EnemigoEnEsperaPlat1 = new Enemigo(180, 0, 0, 0, -1);
	EnemigoEnEsperaPlat3 = new Enemigo(430, 0, 0, 0, -1);
	EnemigoEnEsperaPlat5 = new Enemigo(555, 0, 0, 0, 1);
	EnemigoEnEsperaPlat6 = new Enemigo(300, 0, 0, 0,1);
	EnemigoEnEsperaPlat1 = NULL;
	EnemigoEnEsperaPlat3 = NULL;
	EnemigoEnEsperaPlat5 = NULL;
	EnemigoEnEsperaPlat6 = NULL;
	enemigoRemovidoPlat1 = NULL;
	enemigoRemovidoPlat3 = NULL;
	enemigoRemovidoPlat5 = NULL;
	enemigoRemovidoPlat6 = NULL;
	primerEnemigoPlat1 = NULL;
	primerEnemigoPlat3 = NULL;
	primerEnemigoPlat5 = NULL;
	primerEnemigoPlat6 = NULL;
	ultimoEnemigoPlat1 = NULL;
	ultimoEnemigoPlat3 = NULL;
	ultimoEnemigoPlat5 = NULL;
	ultimoEnemigoPlat6 = NULL;

}
void Colas::InsertEnemigo(int x, int y, int indice, Enemigo*& newEnemigo, Enemigo*& primerEnemigo, Enemigo*& ultimoEnemigo, float velocidadenemigo, int direccionY)
{
	newEnemigo = new Enemigo(x, y, indice, velocidadenemigo, direccionY);
	newEnemigo->nextEnemigo = NULL;
	if (primerEnemigo == NULL)
	{
		primerEnemigo = newEnemigo;
	}
	else
	{
		ultimoEnemigo->nextEnemigo = newEnemigo;
	}
	ultimoEnemigo = newEnemigo;
}
void Colas::LoadColas()
{
	LoadCola();
	LoadCola2();
	LoadCola3();
	LoadCola4();
		
}
void Colas::LoadColas2()
{
	LoadCola5();
	LoadCola6();
	LoadCola7();
	LoadCola8();
}
void Colas::LoadCola()
{
	InsertEnemigo(-100, 0, 0, NewEnemigoPlat1, primerEnemigoPlat1, ultimoEnemigoPlat1, 50, -1);//pos. x, pos. y(plataforma 1), indice de sprite, Nodo
	InsertEnemigo(180, 0, 1, NewEnemigoPlat1, primerEnemigoPlat1, ultimoEnemigoPlat1, 70, -1);
	InsertEnemigo(180, 0, 2, NewEnemigoPlat1, primerEnemigoPlat1, ultimoEnemigoPlat1, 100, -1);
	InsertEnemigo(180, 0, 3, NewEnemigoPlat1, primerEnemigoPlat1, ultimoEnemigoPlat1, 100, -1);
	
}
void Colas::LoadCola2()
{
	InsertEnemigo(430, 0, 1, NewEnemigoPlat3, primerEnemigoPlat3, ultimoEnemigoPlat3, 100, 1);
	InsertEnemigo(-100, 0, 2, NewEnemigoPlat3, primerEnemigoPlat3, ultimoEnemigoPlat3, 50, 1);
	InsertEnemigo(430, 0, 3, NewEnemigoPlat3, primerEnemigoPlat3, ultimoEnemigoPlat3, 50, 1);
	InsertEnemigo(430, 0, 0, NewEnemigoPlat3, primerEnemigoPlat3, ultimoEnemigoPlat3, 70, 1);

}
void Colas::LoadCola3()
{
	InsertEnemigo(555, 0, 2, NewEnemigoPlat5, primerEnemigoPlat5, ultimoEnemigoPlat5, 100, 1);
	InsertEnemigo(555, 0, 3, NewEnemigoPlat5, primerEnemigoPlat5, ultimoEnemigoPlat5, 60, 1);
	InsertEnemigo(-100, 0, 0, NewEnemigoPlat5, primerEnemigoPlat5, ultimoEnemigoPlat5, 80, 1);
	InsertEnemigo(555, 0, 1, NewEnemigoPlat5, primerEnemigoPlat5, ultimoEnemigoPlat5, 90, 1);
}
void Colas::LoadCola4()
{
	InsertEnemigo(300, 0, 3, NewEnemigoPlat6, primerEnemigoPlat6, ultimoEnemigoPlat6, 100, -1);
	InsertEnemigo(300, 0, 2, NewEnemigoPlat6, primerEnemigoPlat6, ultimoEnemigoPlat6, 80, -1);
	InsertEnemigo(300, 0, 0, NewEnemigoPlat6, primerEnemigoPlat6, ultimoEnemigoPlat6, 70, -1);
	InsertEnemigo(-100, 0, 1, NewEnemigoPlat6, primerEnemigoPlat6, ultimoEnemigoPlat6, 50, -1);
}
void Colas::LoadCola5()
{
	InsertEnemigo(-100, 0, 0, NewEnemigoPlat1, primerEnemigoPlat1, ultimoEnemigoPlat1, 150, -1);//pos. x, pos. y(plataforma 1), indice de sprite, Nodo
	InsertEnemigo(180, 0, 1, NewEnemigoPlat1, primerEnemigoPlat1, ultimoEnemigoPlat1, 100, -1);
	InsertEnemigo(180, 0, 2, NewEnemigoPlat1, primerEnemigoPlat1, ultimoEnemigoPlat1, 120, -1);
	InsertEnemigo(180, 0, 3, NewEnemigoPlat1, primerEnemigoPlat1, ultimoEnemigoPlat1, 150, -1);

}
void Colas::LoadCola6()
{
	InsertEnemigo(430, 0, 1, NewEnemigoPlat3, primerEnemigoPlat3, ultimoEnemigoPlat3, 70, 1);
	InsertEnemigo(-100, 0, 2, NewEnemigoPlat3, primerEnemigoPlat3, ultimoEnemigoPlat3, 120, 1);
	InsertEnemigo(430, 0, 3, NewEnemigoPlat3, primerEnemigoPlat3, ultimoEnemigoPlat3, 110, 1);
	InsertEnemigo(430, 0, 0, NewEnemigoPlat3, primerEnemigoPlat3, ultimoEnemigoPlat3, 140, 1);

}
void Colas::LoadCola7()
{
	InsertEnemigo(555, 0, 2, NewEnemigoPlat5, primerEnemigoPlat5, ultimoEnemigoPlat5, 150, 1);
	InsertEnemigo(555, 0, 3, NewEnemigoPlat5, primerEnemigoPlat5, ultimoEnemigoPlat5, 100, 1);
	InsertEnemigo(-100, 0, 0, NewEnemigoPlat5, primerEnemigoPlat5, ultimoEnemigoPlat5, 150, 1);
	InsertEnemigo(555, 0, 1, NewEnemigoPlat5, primerEnemigoPlat5, ultimoEnemigoPlat5, 150, 1);
}
void Colas::LoadCola8()
{
	InsertEnemigo(300, 0, 3, NewEnemigoPlat6, primerEnemigoPlat6, ultimoEnemigoPlat6, 100, -1);
	InsertEnemigo(300, 0, 2, NewEnemigoPlat6, primerEnemigoPlat6, ultimoEnemigoPlat6, 150, -1);
	InsertEnemigo(300, 0, 0, NewEnemigoPlat6, primerEnemigoPlat6, ultimoEnemigoPlat6, 150, -1);
	InsertEnemigo(-100, 0, 1, NewEnemigoPlat6, primerEnemigoPlat6, ultimoEnemigoPlat6, 150, -1);
}
void Colas::RemoveEnemigo(Enemigo*& primerEnemigo, Enemigo*& ultimoEnemigo, Sprite*& enemigoRemovido)
{
	enemigoRemovido = primerEnemigo->s;
	if (primerEnemigo == primerEnemigoPlat1) velocidadRemovidaPlat1 = primerEnemigo->velocidadenemigo;
	if (primerEnemigo == primerEnemigoPlat3) velocidadRemovidaPlat3 = primerEnemigo->velocidadenemigo;
	if (primerEnemigo == primerEnemigoPlat5) velocidadRemovidaPlat5 = primerEnemigo->velocidadenemigo;
	if (primerEnemigo == primerEnemigoPlat6) velocidadRemovidaPlat6 = primerEnemigo->velocidadenemigo;
	Enemigo* aux = primerEnemigo;
	if (primerEnemigo == ultimoEnemigo)
	{
		primerEnemigo = NULL;
		ultimoEnemigo = NULL;
	}
	else
	{
		primerEnemigo = primerEnemigo->nextEnemigo;
	}
	delete aux;
}

void Colas::UpdateCola(Enemigo*& primerEnemigo, Sprite*& enemigoRemovido, Enemigo*& ultimoEnemigo, Enemigo*& enemigoEnEspera, int x, float deltaTime, float velocity, float veloplayer, int direccionY)

{
	
	if (enemigoRemovido == NULL && primerEnemigo != NULL)
	{
		RemoveEnemigo(primerEnemigo, ultimoEnemigo, enemigoRemovido);
		//OrdenarEnemigosEnEspera(y, enemigoEnEspera, primerEnemigo);//funcion para los demás sprites
		
	}
	else if (enemigoRemovido != NULL && enemigoRemovido->getPosition().y < 600)
	{
		if (enemigoRemovido == enemigoRemovidoPlat1) velocity = velocidadRemovidaPlat1;
		else if (enemigoRemovido == enemigoRemovidoPlat3) velocity = velocidadRemovidaPlat3;
		else if (enemigoRemovido == enemigoRemovidoPlat5) velocity = velocidadRemovidaPlat5;
		else if (enemigoRemovido == enemigoRemovidoPlat6) velocity = velocidadRemovidaPlat6;
		if (veloplayer != 0 && direccionY == 1)
		{
			float position_y = enemigoRemovido->getPosition().y + velocity * deltaTime * (-veloplayer/ 1.5 ) *direccionY;
			enemigoRemovido->setPosition(enemigoRemovido->getPosition().x, position_y);
		}
		else
		{
			float position_y = enemigoRemovido->getPosition().y + velocity * deltaTime * -direccionY;
			enemigoRemovido->setPosition(enemigoRemovido->getPosition().x, position_y);
		}
		if (veloplayer != 0 && direccionY == -1)
		{
			float position_y = enemigoRemovido->getPosition().y + velocity * deltaTime * direccionY * veloplayer;
			enemigoRemovido->setPosition(enemigoRemovido->getPosition().x, position_y);
		}
		else
		{
			float position_y = enemigoRemovido->getPosition().y + velocity * deltaTime * -direccionY;
			enemigoRemovido->setPosition(enemigoRemovido->getPosition().x, position_y);
		}
		
	}

	if (enemigoRemovido != NULL && enemigoRemovido->getPosition().y >= 600)
	{
		enemigoRemovido->setPosition(x, 0);
		enemigoRemovido = NULL;
	}


}
void Colas::OrdenarEnemigosEnEspera(int y, Enemigo* EnemigoEnEspera, Enemigo* primerEnemigo)
{
	int afuera = -50; int primero = 40; int segundo = 70; int tercero = 100;//posiciones en x para cada enemigo en espera

	if (primerEnemigo->indice == 1)//si el indice es 1 sale el amarillo
	{
		EnemigoEnEspera->enemigoEnEspera[0]->setPosition(afuera, y);//amarillo afuera
		EnemigoEnEspera->enemigoEnEspera[1]->setPosition(tercero, y);//azul tercero
		EnemigoEnEspera->enemigoEnEspera[2]->setPosition(segundo, y);//rojo segundo
		EnemigoEnEspera->enemigoEnEspera[3]->setPosition(primero, y);//verde primero
	}
	if (primerEnemigo->indice == 2)//y asi sucesivamente
	{
		EnemigoEnEspera->enemigoEnEspera[0]->setPosition(primero, y);
		EnemigoEnEspera->enemigoEnEspera[1]->setPosition(afuera, y);
		EnemigoEnEspera->enemigoEnEspera[2]->setPosition(tercero, y);
		EnemigoEnEspera->enemigoEnEspera[3]->setPosition(segundo, y);
	}
	if (primerEnemigo->indice == 3)
	{
		EnemigoEnEspera->enemigoEnEspera[0]->setPosition(segundo, y);
		EnemigoEnEspera->enemigoEnEspera[1]->setPosition(primero, y);
		EnemigoEnEspera->enemigoEnEspera[2]->setPosition(afuera, y);
		EnemigoEnEspera->enemigoEnEspera[3]->setPosition(tercero, y);
	}
	if (primerEnemigo->indice == 0)
	{
		EnemigoEnEspera->enemigoEnEspera[0]->setPosition(tercero, y);
		EnemigoEnEspera->enemigoEnEspera[1]->setPosition(segundo, y);
		EnemigoEnEspera->enemigoEnEspera[2]->setPosition(primero, y);
		EnemigoEnEspera->enemigoEnEspera[3]->setPosition(afuera, y);
	}

}
void Colas::resetColas() {
	// Liberar memoria de todas las listas enlazadas (si no ya fueron borradas)
	vaciarCola(primerEnemigoPlat1);
	vaciarCola(primerEnemigoPlat3);
	vaciarCola(primerEnemigoPlat5);
	vaciarCola(primerEnemigoPlat6);

	// Resetear los punteros a NULL
	enemigoRemovidoPlat1 = NULL;
	enemigoRemovidoPlat3 = NULL;
	enemigoRemovidoPlat5 = NULL;
	enemigoRemovidoPlat6 = NULL;

	primerEnemigoPlat1 = NULL;
	primerEnemigoPlat3 = NULL;
	primerEnemigoPlat5 = NULL;
	primerEnemigoPlat6 = NULL;

	ultimoEnemigoPlat1 = NULL;
	ultimoEnemigoPlat3 = NULL;
	ultimoEnemigoPlat5 = NULL;
	ultimoEnemigoPlat6 = NULL;

	EnemigoEnEsperaPlat1 = NULL;
	EnemigoEnEsperaPlat3 = NULL;
	EnemigoEnEsperaPlat5 = NULL;
	EnemigoEnEsperaPlat6 = NULL;
}
