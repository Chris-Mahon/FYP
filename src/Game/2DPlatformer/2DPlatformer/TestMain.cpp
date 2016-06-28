#include "stdafx.h"
//#include "Headers\TestMain.h"
//#include "Headers\Obstacle.h"
//#include "Headers\Vector2.h"
#include "Controller.h"
#include <Python.h>

int main2()
{
	Controller controls = Controller();
	controls.Update();
	getchar();
	/*PyObject *pName, *pModule, *pDict, *pFunc;
	PyObject *pValue;
	pFunc = NULL;
	pValue = NULL;
	Py_SetProgramName((wchar_t*)"Testing");
	Py_Initialize();
	PyRun_SimpleString("from time import time,ctime\n"
		"print('Today is', ctime(time()))\n");
	PyRun_SimpleString("import sys\n");

	PyRun_SimpleString("sys.path.append(\".\")");
	PyRun_SimpleString("print(sys.path)\n");
	//getchar();
	pName = PyUnicode_FromString("Controller");
	printf("%s\n", "Beginning");
	pModule = PyImport_Import(pName);
	if (pModule == NULL)
	{
		printf("%s", (char*)"Nope");

	}
	else
	{
		pFunc = PyObject_GetAttrString(pModule, (char*)"controller");
		if (pFunc == NULL)
		{
			printf("pFunc returned NULL\n");
		}
		else
		{
			//_flushall();
			getchar();

			pValue = PyObject_CallObject(pFunc, NULL);
			printf("%s", PyUnicode_AsUTF8(pValue));

		}
	}
	Py_XDECREF(pName);
	Py_XDECREF(pModule);
	Py_XDECREF(pFunc);
	Py_XDECREF(pValue);
	Py_Finalize();
	_flushall();
	getchar();
	return 0;*/
}
