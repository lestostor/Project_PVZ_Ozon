//  Copyright 2025 Shcherbakova Olesya
#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "TVector.h"
#include "FIO.h"
#include "Worker.h"
#include "Address.h"
#include "Date.h"
#include "Product.h"
#include "Cell.h"

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
    public ref class ReturnWindow : public System::Windows::Forms::Form {
    public:
        ReturnWindow(void) {
            InitializeComponent();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ReturnWindow() {
            if (components) {
                delete components;
            }
        }
    private: System::Windows::Forms::GroupBox^ groupBox2;
    protected:
    private: System::Windows::Forms::Label^ give_label;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ return_label;
    private: System::Windows::Forms::VScrollBar^ vScrollBar1;
    private: System::Windows::Forms::Button^ _return_btn;

    private: System::Windows::Forms::CheckedListBox^ _list;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ _code;
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
        void InitializeComponent(void) {
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->give_label = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->return_label = (gcnew System::Windows::Forms::Label());
            this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
            this->_return_btn = (gcnew System::Windows::Forms::Button());
            this->_list = (gcnew System::Windows::Forms::CheckedListBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->_code = (gcnew System::Windows::Forms::TextBox());
            this->groupBox2->SuspendLayout();
            this->SuspendLayout();

            this->groupBox2->BackColor = System::Drawing::Color::Blue;
            this->groupBox2->Controls->Add(this->give_label);
            this->groupBox2->Controls->Add(this->label5);
            this->groupBox2->Controls->Add(this->return_label);
            this->groupBox2->Location = System::Drawing::Point(0, -13);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(286, 630);
            this->groupBox2->TabIndex = 9;

            this->give_label->AutoSize = true;
            this->give_label->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 21.75F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->give_label->ForeColor = System::Drawing::Color::White;
            this->give_label->Location = System::Drawing::Point(6, 152);
            this->give_label->Name = L"give_label";
            this->give_label->Size = System::Drawing::Size(279, 39);
            this->give_label->TabIndex = 8;
            this->give_label->Text = L"Give out products";
            this->give_label->Click += gcnew System::EventHandler
            (this, &ReturnWindow::give_label_Click);
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 21.75F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label5->ForeColor = System::Drawing::Color::White;
            this->label5->Location = System::Drawing::Point(12, 25);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(114, 39);
            this->label5->TabIndex = 7;
            this->label5->Text = L"Profile";

            this->return_label->AutoSize = true;
            this->return_label->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 21.75F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->return_label->ForeColor = System::Drawing::Color::White;
            this->return_label->Location = System::Drawing::Point(12, 217);
            this->return_label->Name = L"return_label";
            this->return_label->Size = System::Drawing::Size(254, 39);
            this->return_label->TabIndex = 6;
            this->return_label->Text = L"Return products";
            this->vScrollBar1->Location = System::Drawing::Point(1166, 87);
            this->vScrollBar1->Name = L"vScrollBar1";
            this->vScrollBar1->Size = System::Drawing::Size(35, 439);
            this->vScrollBar1->TabIndex = 14;

            this->_return_btn->BackColor = System::Drawing::Color::Blue;
            this->_return_btn->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 21.75F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->_return_btn->ForeColor = System::Drawing::Color::White;
            this->_return_btn->Location = System::Drawing::Point(629, 535);
            this->_return_btn->Name = L"_return_btn";
            this->_return_btn->Size = System::Drawing::Size(173, 47);
            this->_return_btn->TabIndex = 13;
            this->_return_btn->Text = L"Return";
            this->_return_btn->UseVisualStyleBackColor = false;

            this->_list->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 15.75F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->_list->FormattingEnabled = true;
            this->_list->Location = System::Drawing::Point(291, 87);
            this->_list->Name = L"_list";
            this->_list->Size = System::Drawing::Size(910, 439);
            this->_list->TabIndex = 12;

            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->Location = System::Drawing::Point(290, 10);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(82, 35);
            this->label1->TabIndex = 11;
            this->label1->Text = L"Code";

            this->_code->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->_code->Location = System::Drawing::Point(378, 10);
            this->_code->Name = L"_code";
            this->_code->Size = System::Drawing::Size(424, 42);
            this->_code->TabIndex = 10;

            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1214, 617);
            this->Controls->Add(this->vScrollBar1);
            this->Controls->Add(this->_return_btn);
            this->Controls->Add(this->_list);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->_code);
            this->Controls->Add(this->groupBox2);
            this->Name = L"ReturnWindow";
            this->StartPosition = System::Windows::Forms::FormStartPosition::
                CenterScreen;
            this->Text = L"Ozon";
            this->FormClosed += gcnew System::Windows::Forms::
        FormClosedEventHandler(this, &ReturnWindow::ReturnWindow_FormClosed);
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    private: System::Void give_label_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        Form^ form = this->Owner;
        form->Show();
    }
private: System::Void ReturnWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
    Application::Exit();
}
};
}
