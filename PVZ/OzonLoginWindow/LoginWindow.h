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
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ mail;
	private: System::Windows::Forms::TextBox^ password;
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
		void InitializeComponent(void)
		{
			this->mail = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->login_btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// mail
			// 
			this->mail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->mail->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mail->Location = System::Drawing::Point(180, 180);
			this->mail->Name = L"mail";
			this->mail->Size = System::Drawing::Size(236, 42);
			this->mail->TabIndex = 0;
			// 
			// password
			// 
			this->password->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->password->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->password->Location = System::Drawing::Point(180, 289);
			this->password->Name = L"password";
			this->password->Size = System::Drawing::Size(236, 42);
			this->password->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
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
			this->login_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->login_btn->Location = System::Drawing::Point(226, 367);
			this->login_btn->Name = L"login_btn";
			this->login_btn->Size = System::Drawing::Size(136, 47);
			this->login_btn->TabIndex = 5;
			this->login_btn->Text = L"Login";
			this->login_btn->UseVisualStyleBackColor = true;
			this->login_btn->Click += gcnew System::EventHandler(this, &Form1::login_btn_Click);
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
			this->Controls->Add(this->password);
			this->Controls->Add(this->mail);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void login_btn_Click(System::Object^ sender, System::EventArgs^ e) {
	std::ifstream log{ "C:/Users/user/Project_PVZ_Ozon/Project_PVZ_Ozon/source/Test.csv" };
	std::string line, colname, s;
	if (log.good())
	{
		std::getline(log, line);
		std::stringstream ss(line);
		System::String^ managedString = gcnew System::String(line.c_str());
		mail->Text = managedString;
	}

}
};
}
