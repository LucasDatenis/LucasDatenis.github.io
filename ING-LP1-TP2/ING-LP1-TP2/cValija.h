#pragma once
#include<iostream>
using namespace std;
class cValija
{
private:
	float peso;
public:
	cValija();
	cValija(float peso);
	~cValija();
	float getPeso() { return peso; };
};

