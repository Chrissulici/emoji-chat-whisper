///search:
void initsystemSetting()

///add before:
PyObject * systemIsHideEmojiInfo(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsHideEmojiInfo());
}

PyObject * systemSetHideEmojiInfo(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();

	CPythonSystem::Instance().SetHideEmojiInfo(iFlag);

	return Py_BuildNone();
}

///search:
		{ NULL,							NULL,							NULL }

///add before:
		{ "IsHideEmojiInfo",			systemIsHideEmojiInfo,			METH_VARARGS },
		{ "SetHideEmojiInfo",			systemSetHideEmojiInfo,			METH_VARARGS },