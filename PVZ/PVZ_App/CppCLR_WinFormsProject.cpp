#include "C:/Users/user/Project_PVZ_Ozon/Project_PVZ_Ozon/PVZ/PVZ_App/pch.h"
//  Copyright 2025 Shcherbakova Olesya

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "Form1.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::Form1());
  return 0;
}