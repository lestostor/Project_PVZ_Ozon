#pragma once
#include "TVector.h"
#include "FIO.h"
#include "Worker.h"
#include "Address.h"
#include "Date.h"
#include "Product.h"
#include "Cell.h"
#include <fstream>
#include <string>
#include <sstream>
//  Copyright 2025 Shcherbakova Olesya

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for Form1
    /// </summary>
    public ref class MainWindow : public System::Windows::Forms::Form
    {
    public:
        MainWindow(void)
        {
            InitializeComponent();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MainWindow()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::GroupBox^ groupBox1;
    private: System::Windows::Forms::TextBox^ code;
    private: System::Windows::Forms::Label^ label1;
    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->code = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // groupBox1
            // 
            this->groupBox1->BackColor = System::Drawing::Color::Blue;
            this->groupBox1->Location = System::Drawing::Point(0, -13);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(263, 630);
            this->groupBox1->TabIndex = 0;
            this->groupBox1->TabStop = false;
            // 
            // code
            // 
            this->code->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->code->Location = System::Drawing::Point(563, 199);
            this->code->Name = L"code";
            this->code->Size = System::Drawing::Size(424, 42);
            this->code->TabIndex = 1;
            this->code->TextChanged += gcnew System::EventHandler
            (this, &MainWindow::code_TextChanged);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->Location = System::Drawing::Point(335, 202);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(208, 35);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Product\'s code";
            // 
            // MainWindow
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->ClientSize = System::Drawing::Size(1214, 617);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->code);
            this->Controls->Add(this->groupBox1);
            this->Name = L"MainWindow";
            this->StartPosition = System::Windows::Forms::FormStartPosition::
                CenterScreen;
            this->Text = L"Ozon";
            this->FormClosed += gcnew System::Windows::Forms::
                FormClosedEventHandler(this, &MainWindow::MainWindow_FormClosed);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void MainWindow_FormClosed(System::Object^ sender,
        System::Windows::Forms::FormClosedEventArgs^ e) {
        Application::Exit();
    }


    private: System::Void code_TextChanged(System::Object^ sender,
        System::EventArgs^ e) {

    }
    };
}
