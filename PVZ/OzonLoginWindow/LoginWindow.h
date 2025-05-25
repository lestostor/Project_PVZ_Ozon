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
#include "../OzonMainWindow/MainWindow.h"
// Copyright 2025 Shcherbakova Olesya

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace msclr::interop;

    /// <summary>
    /// Summary for Form1
    /// </summary>
    public ref class Form1 : public System::Windows::Forms::Form {
    public:
        Form1(void) {
            InitializeComponent();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Form1() {
            if (components) {
                delete components;
            }
        }
    private: System::Windows::Forms::TextBox^ _mail;
    private: System::Windows::Forms::TextBox^ _password;
    protected:
    protected:
    protected:
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Button^ login_btn;
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
            this->_mail = (gcnew System::Windows::Forms::TextBox());
            this->_password = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->login_btn = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            //
            // _mail
            //
            this->_mail->BorderStyle = System::Windows::Forms::BorderStyle::
                FixedSingle;
            this->_mail->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->_mail->Location = System::Drawing::Point(180, 180);
            this->_mail->Name = L"_mail";
            this->_mail->Size = System::Drawing::Size(236, 42);
            this->_mail->TabIndex = 0;
            //
            // _password
            //
            this->_password->BorderStyle = System::Windows::Forms::
                BorderStyle::FixedSingle;
            this->_password->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->_password->Location = System::Drawing::Point(180, 289);
            this->_password->Name = L"_password";
            this->_password->Size = System::Drawing::Size(236, 42);
            this->_password->TabIndex = 1;
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 36, System::Drawing::FontStyle::
                Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(200, 67);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(177, 64);
            this->label1->TabIndex = 2;
            this->label1->Text = L"OZON";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label2->ForeColor = System::Drawing::Color::White;
            this->label2->Location = System::Drawing::Point(29, 186);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(75, 36);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Mail";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label3->ForeColor = System::Drawing::Color::White;
            this->label3->Location = System::Drawing::Point(29, 295);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(145, 36);
            this->label3->TabIndex = 4;
            this->label3->Text = L"Password";
            //
            // login_btn
            //
            this->login_btn->Font = (gcnew System::Drawing::Font
            (L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::
                Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->login_btn->Location = System::Drawing::Point(226, 367);
            this->login_btn->Name = L"login_btn";
            this->login_btn->Size = System::Drawing::Size(136, 47);
            this->login_btn->TabIndex = 5;
            this->login_btn->Text = L"Login";
            this->login_btn->UseVisualStyleBackColor = true;
            this->login_btn->Click += gcnew System::EventHandler
            (this, &Form1::login_btn_Click);
            //
            // Form1
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::Blue;
            this->ClientSize = System::Drawing::Size(575, 469);
            this->Controls->Add(this->login_btn);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->_password);
            this->Controls->Add(this->_mail);
            this->Name = L"Form1";
            this->StartPosition = System::Windows::Forms::FormStartPosition::
                CenterScreen;
            this->Text = L"Form1";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
        TVector<TVector<std::string>> read(std::string file_name) {
            std::ifstream file{ file_name };
            if (!file.is_open())
                throw std::runtime_error("File isn't open");

            std::string line;
            std::getline(file, line);
            int i = 0, j = 0;
            TVector<TVector<std::string>> table;
            while (std::getline(file, line)) {
                TVector<std::string> row;
                std::string cell;
                std::stringstream lineStream(line);

                while (std::getline(lineStream, cell, ';')) {
                    row.push_back(cell);
                }
                table.push_back(row);
                i++;
            }

            return table;
        }

        bool check_account(std::string mail, std::string password,
        TVector<std::string> workers) {
            if (mail == workers[3] && password == workers[9])
                return true;
            return false;
        }

        String^ convert_fio(TVector<std::string> worker) {
            String^ surname = gcnew String(worker[0].c_str());
            String^ name = gcnew String(worker[1].c_str());
            String^ patronymic = gcnew String(worker[2].c_str());

            String^ fio = surname + " " + name + " " + patronymic;
            return fio;
        }

        String^ convert_address(TVector<std::string> worker) {
            String^ area = gcnew String(worker[4].c_str());
            String^ region = gcnew String(worker[5].c_str());
            String^ city = gcnew String(worker[6].c_str());
            String^ street = gcnew String(worker[7].c_str());
            String^ building = gcnew String(worker[8].c_str());
            
            String^ address = area + " " + region + " " + city + " " + street +
                " " + building;
            return address;
        }

private: System::Void login_btn_Click(System::Object^ sender,
    System::EventArgs^ e) {
    TVector<TVector<std::string>> workers =
    read("C:/Users/user/Project_PVZ_Ozon/Project_PVZ_Ozon/source/Workers.csv");

    std::string mail = marshal_as<std::string>(_mail->Text);
    std::string password = marshal_as<std::string>(_password->Text);
    if (mail == "" || password == "") {
        MessageBox::Show("Enter mail and password");
        return;
    }

    int i = 0;
    for (i; i < workers.size(); i++) {
        if (!check_account(mail, password, workers[i])) {
            MessageBox::Show("Wrong mail or password");
            return;
        }
        else break;
    }

    this->Hide();
    MainWindow^ window = gcnew MainWindow();
    String^ worker = convert_fio(workers[i]);
    String^ address = convert_address(workers[i]);

    window->worker = worker;
    window->address = address;
    window->mail = _mail->Text;
    window->ShowDialog(this);
}
};
}  // namespace CppCLRWinFormsProject
