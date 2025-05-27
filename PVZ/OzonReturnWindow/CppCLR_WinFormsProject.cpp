#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "ReturnWindow.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::ReturnWindow());
  return 0;
}