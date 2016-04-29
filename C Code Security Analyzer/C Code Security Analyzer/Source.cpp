#include "GUI.h"

using namespace CCodeSecurityAnalyzer;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CCodeSecurityAnalyzer::GUI gui;
	Application::Run(%gui);
}