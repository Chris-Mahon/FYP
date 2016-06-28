#include "stdafx.h"
#include "Controller.h"

Controller::Controller()
{
	A = 0;
	B = 0;
	X = 0;
	Y = 0;
	Up = 0;
	Down = 0;
	Left = 0;
	Right = 0;
	Start = 0;
	Select = 0;
	demoMode = true;
}


Controller::~Controller()
{
}

void Controller::Update()
{
	char *retString = NULL;
	if (demoMode == false)
	{
		retString = Connect();
	}
	else
	{
		al_rest(0.05);
		retString = "110000010000";
	}
	if (retString != NULL)
	{
		if (int(retString[0])-int('0') == 1)
		{
			A = 1;
		}
		else
		{
			A = 0;
		}
		if (int(retString[1])-int('0') == 1)
		{
			B = 1;
		}
		else
		{
			B = 0;
		}
		if (int(retString[6]) - int('0') == 1)
		{
			Left = -1;
		}
		else
		{
			Left = 0;
		}
		if (int(retString[7]) - int('0') == 1)
		{
			Right = 1;
		}
		else
		{
			Right = 0;
		}
		if (int(retString[10]) - int('0') == 1)
		{
			Start = 1;
		}
		else
		{
			Start = 0;
		}
	}
}

char* Controller::Connect()
{
	Py_SetProgramName((wchar_t*)"Controller");
	Py_Initialize();
	PyRun_SimpleString("import sys\n");
	PyRun_SimpleString("sys.path.append(\".\")");
	//PyRun_SimpleString("print(sys.path)");
	pValue = NULL;
	pFunc = NULL;
	pModule = NULL;
	pName = PyUnicode_FromString("Controller");
	pModule = PyImport_Import(pName);
	char *returnVal = "000000000000";
	if (pModule != NULL)
	{
		pFunc = PyObject_GetAttrString(pModule, (char*)"controller");
	}
	else
	{
		demoMode = true;
		return returnVal;
	}
	if (pFunc != NULL)
	{
		pValue = PyObject_CallObject(pFunc, NULL);
		if (pValue != NULL)
		{

			//returnVal = PyUnicode_AsUTF8(pValue);
			PyObject *pTemp = PyUnicode_AsASCIIString(pValue);
			if (pTemp != NULL)
			{
				returnVal = PyBytes_AsString(pTemp);
			}
			cout << returnVal;
		}
		else
		{
			demoMode = true;
			return returnVal;
		}
	}
	else
	{
		demoMode = true;
		return returnVal;
	}
	
	Py_Finalize();
	return returnVal;
}