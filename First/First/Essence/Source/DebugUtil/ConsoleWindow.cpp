#include "../../Header/DebugUtil/ConsoleWindow.h"
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

using namespace essence::debug;

int CConsoleWindow::m_hConsoleId = 0;

void CConsoleWindow::Open() {

	::AllocConsole();
	m_hConsoleId = ::_open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	*stdout = *::_fdopen(m_hConsoleId, "w");
	setvbuf(stdout, NULL, _IONBF, 0);

	return;
}

void CConsoleWindow::Close() {

	if (m_hConsoleId)
	{
		::_close(m_hConsoleId);
	}
	return;
}