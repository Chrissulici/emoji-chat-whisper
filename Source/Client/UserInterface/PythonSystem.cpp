///search:
	m_Config.bShowSalesText				= true;

///add:
	m_Config.bHideEmojiInfo 			= false;

///search:
void CPythonSystem::SetSoftwareTiling(bool isEnable)
{
	if (isEnable)
		m_Config.bSoftwareTiling=1;
	else
		m_Config.bSoftwareTiling=2;
}

///add:
bool CPythonSystem::IsHideEmojiInfo()
{
	return m_Config.bHideEmojiInfo;
}

void CPythonSystem::SetHideEmojiInfo(int iFlag)
{
	m_Config.bHideEmojiInfo = iFlag == 1 ? true : false;
}

///search:
		else if (!stricmp(command, "SHOW_SALESTEXT"))
			m_Config.bShowSalesText = atoi(value) == 1 ? true : false;

///add:
		else if (!stricmp(command, "HIDE_EMOJI_INFO"))
			m_Config.bHideEmojiInfo = atoi(value) == 1 ? true : false;

///search:
	if (m_Config.bShowSalesText == 0)
		fprintf(fp, "SHOW_SALESTEXT			%d\n", m_Config.bShowSalesText);

///add:
	fprintf(fp, "HIDE_EMOJI_INFO			%d\n", m_Config.bHideEmojiInfo);

