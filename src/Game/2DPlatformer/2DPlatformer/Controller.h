#pragma once
#include "stdafx.h"
#include <Python.h>

class Controller
{
public:
	Controller();
	~Controller();
	void Update();
	char* Connect();
	int A, B, X, Y, Up, Down, Left, Right, Start, Select;
	PyObject *pName, *pModule, *pDict, *pFunc;
	PyObject *pValue;
	PyObject *pDev;
	bool demoMode;

};

