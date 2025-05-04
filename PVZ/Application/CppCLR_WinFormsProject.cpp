#include "C:/Users/user/Project_PVZ_Ozon/Project_PVZ_Ozon/PVZ/Application/pch.h"
//  Copyright 2025 Shcherbakova Olesya

#pragma warning(disable : 4644)
using namespace System;
#pragma warning(default : 4644)

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "Form1.h"

#pragma warning(disable : 4644)
using namespace System::Windows::Forms;
#pragma warning(default : 4644)

[STAThread]
int main() {
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::Form1());
  return 0;
}
