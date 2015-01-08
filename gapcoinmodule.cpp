#include <Python.h>
#include "BlockHeader.h"

uint64_t GapcoinDifficulty(const char *input)
{
    uint64_t difficulty = getPowDifficulty((const char *)input);
    return difficulty;
}

static PyObject *gapcoin_getpowdiff(PyObject *self, PyObject *args)
{
    uint64_t difficulty = 0;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);

#if PY_MAJOR_VERSION >= 3
    difficulty = GapcoinDifficulty((char *)PyBytes_AsString((PyObject*) input));
#else
    difficulty = GapcoinDifficulty((char *)PyString_AsString((PyObject*) input));
#endif
    Py_DECREF(input);
    return (PyObject *) PyLong_FromLong((long int)difficulty);
}

static PyMethodDef GapcoinMethods[] = {
    { "getpowdiff", gapcoin_getpowdiff, METH_VARARGS, "Returns the gapcoin pow difficulty" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef GapcoinModule = {
    PyModuleDef_HEAD_INIT,
    "gapcoin_hash",
    "...",
    -1,
    GapcoinMethods
};

PyMODINIT_FUNC PyInit_gapcoin_hash(void) {
    return PyModule_Create(&GapcoinModule);
}

#else

PyMODINIT_FUNC initgapcoin_hash(void) {
    (void) Py_InitModule("gapcoin_hash", GapcoinMethods);
}
#endif
