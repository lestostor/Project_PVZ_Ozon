#include "pch.h"
//  Copyright 2025 Shcherbakova Olesya

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "LoginWindow.h"

using namespace System::Windows::Forms;

[STAThread]
int main() {
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);
  Application::Run(gcnew CppCLRWinFormsProject::Form1());
  return 0;
}
