#ifndef ESSENCE_DEBUGUTILITY_CONSOLEWINDOW_H
#define ESSENCE_DEBUGUTILITY_CONSOLEWINDOW_H

namespace essence{namespace debug{
class CConsoleWindow
{
public:
	CConsoleWindow() = delete;
	CConsoleWindow(const CConsoleWindow&) = delete;
	CConsoleWindow(CConsoleWindow&&) = delete;
	~CConsoleWindow() = default;
	static void Open();
	static void Close();
private:
	static int m_hConsoleId;
};

}}
#endif