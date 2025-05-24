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
    public ref class MainWindow : public System::Windows::Forms::Form {
    public:
        MainWindow(void) {
            InitializeComponent();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MainWindow() {
            if (components) {
                delete components;
            }
        }
    private: System::Windows::Forms::GroupBox^ groupBox1;
    private: System::Windows::Forms::TextBox^ _code;

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::CheckedListBox^ _list;

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
        void InitializeComponent(void) {
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->_code = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->_list = (gcnew System::Windows::Forms::CheckedListBox());
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
            // _code
            //
            this->_code->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->_code->Location = System::Drawing::Point(357, 9);
            this->_code->Name = L"_code";
            this->_code->Size = System::Drawing::Size(424, 42);
            this->_code->TabIndex = 1;
            this->_code->KeyDown += gcnew System::Windows::Forms::
                KeyEventHandler(this, &MainWindow::code_KeyDown);
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->Location = System::Drawing::Point(269, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(82, 35);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Ñode";
            //
            // _list
            //
            this->_list->Font = (gcnew System::Drawing::Font
            (L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->_list->FormattingEnabled = true;
            this->_list->Location = System::Drawing::Point(275, 89);
            this->_list->Name = L"_list";
            this->_list->Size = System::Drawing::Size(927, 498);
            this->_list->TabIndex = 3;
            //
            // MainWindow
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->ClientSize = System::Drawing::Size(1214, 617);
            this->Controls->Add(this->_list);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->_code);
            this->Controls->Add(this->groupBox1);
            this->Name = L"MainWindow";
            this->StartPosition = System::Windows::Forms::FormStartPosition::
                CenterScreen;
            this->Text = L"Ozon";
            this->FormClosed += gcnew System::Windows::Forms::
                FormClosedEventHandler(this, &MainWindow::
                    MainWindow_FormClosed);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void MainWindow_FormClosed(System::Object^ sender,
        System::Windows::Forms::FormClosedEventArgs^ e) {
        Application::Exit();
    }

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

           void add_products(TVector<Cell>& cells,
               TVector<TVector<std::string>> products) {
               for (int i = 0; i < products.size(); i++) {
                   int cell_num = std::atoi(products[i][0].c_str());
                   int code = std::atoi(products[i][1].c_str());
                   int price = std::atoi(products[i][2].c_str());
                   bool prepay = std::atoi(products[i][3].c_str());
                   int limit = std::atoi(products[i][4].c_str());
                   bool returnability = std::atoi(products[i][5].c_str());
                   Date date(products[i][6]);
                   Product product(code, price, prepay, limit,
                       returnability, date);

                   cells[cell_num - 1].add_new_product(product);
               }
           }

           TVector<Cell> create_cells() {
               TVector<Cell> cells(100);
               TVector<TVector<std::string>> products = read(
"C:/Users/user/Project_PVZ_Ozon/Project_PVZ_Ozon/source/Products.csv");

               for (int i = 0; i < cells.size(); i++) {
                   Cell cell(i + 1, {});
                   cells[i] = cell;
               }

               add_products(cells, products);
               return cells;
           }

           String^ add_product_to_list(Product product) {
               String^ new_product = gcnew String("");
               new_product += "Code: " +
                   Convert::ToString(product.get_code()) + "   ";

               new_product += "Price: " +
                   Convert::ToString(product.get_price()) + "   ";

               int age_limit = product.get_age_limit();
               if (age_limit == 0)
                   new_product += "Age limit: No   ";
               else new_product += "Age limit:   " +
                   Convert::ToString(age_limit) + "   ";

               bool prepay = product.get_prepay();
               if (prepay)
                   new_product += "Paid: yes   ";
               else 
                   new_product += "Paid: no   ";

               bool returnability = product.get_returnability();
               if (prepay)
                   new_product += "Returnability: yes";
               else
                   new_product += "Returnability: no";

               return new_product;
           }

private: System::Void code_KeyDown(System::Object^ sender,
    System::Windows::Forms::KeyEventArgs^ e) {

    if (e->KeyCode == Keys::Enter) {
        _list->Items->Clear();
        TVector<Cell> cells = create_cells();
        long long int code = System::Convert::ToInt64(_code->Text);
        try {
            TVector<Product> products = get_products_by_code(cells, code);

            for (int i = 0; i < products.size(); i++) {
                String^ characteristics = add_product_to_list(products[i]);
                _list->Items->Add(characteristics);
            }
        }
        catch (std::exception& ex) {
            String^ error = gcnew String(ex.what());
            MessageBox::Show(error, "Error");
            return;
        }
    }
}
};
}  // namespace CppCLRWinFormsProject
