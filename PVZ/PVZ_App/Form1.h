#pragma once
//  Copyright 2025 Shcherbakova Olesya

namespace CppCLRWinFormsProject {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace Microsoft::Office::Interop::Excel;
    ///  <summary>
    ///  Summary for Form1
    ///  </summary>
    public ref class Form1 : public System::Windows::Forms::Form {
    public:
        Form1(void) {
            InitializeComponent();
            ApplicationClass^ table = gcnew ApplicationClass();
            Workbook^ book = table->Workbooks->Open("C:/Users/user/Desktop/Test.xlsx",
                0,
                false,
                5,
                "",
                "",
                true,
                XlPlatform::xlWindows,
                "\t",
                false,
                false,
                0,
                true,
                1,
                0);
            book->Close(false, "C:/Users/user/Desktop/Test.xlsx", nullptr);
        }
    protected:
        ///  <summary>
        ///  Clean up any resources being used.
        ///  </summary>
        ~Form1() {
            if (components) {
                delete components;
            }
        }
    private:
        ///  <summary>
        ///  Required designer variable.
        ///  </summary>
        System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
        ///  <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void) {
            this->SuspendLayout();
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1031, 559);
            this->Name = L"Form1";
            this->Text = L"Ozon";
            this->ResumeLayout(false);

        }
#pragma endregion
    };
}  // namespace CppCLRWinFormsProject
