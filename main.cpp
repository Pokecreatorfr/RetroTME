#include "pch.h"
#include "main_window.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;


[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Core core;
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	RetroTME::main_window form(&core);
	Application::Run(% form);
}
