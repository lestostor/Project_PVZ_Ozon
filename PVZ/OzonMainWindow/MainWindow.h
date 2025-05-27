//  Copyright 2025 Shcherbakova Olesya
#pragma once
#include "TVector.h"
#include "FIO.h"
#include "Worker.h"
#include "Address.h"
#include "Date.h"
#include "Product.h"
#include "Cell.h"
#include "../OzonReturnWindow/ReturnWindow.h"
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
    public ref class MainWindow : public System::Windows::Forms::Form {
        TVector<Cell>* all_cells;
    public:
        String^ worker;
        String^ mail;
    private: System::Windows::Forms::Button^ _give_out_btn;
    private: System::Windows::Forms::VScrollBar^ vScrollBar1;
    private: System::Windows::Forms::GroupBox^ groupBox2;
    private: System::Windows::Forms::Label^ give_label;

    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ return_label;

    public:
        String^ address;
        MainWindow(void) {
            InitializeComponent();
            all_cells = new TVector<Cell>(100);
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MainWindow() {
            if (components) {
                delete components;
            }
            delete all_cells;
        }

    private: System::Windows::Forms::TextBox^ _code;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::CheckedListBox^ _list;
    protected:
    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void) {
            this->_code = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->_list = (gcnew System::Windows::Forms::CheckedListBox());
            this->_give_out_btn = (gcnew System::Windows::Forms::Button());
            this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->give_label = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->return_label = (gcnew System::Windows::Forms::Label());
            this->groupBox2->SuspendLayout();
            this->SuspendLayout();

            this->_code->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->_code->Location = System::Drawing::Point(378, 10);
            this->_code->Name = L"_code";
            this->_code->Size = System::Drawing::Size(424, 42);
            this->_code->TabIndex = 1;
            this->_code->KeyDown += gcnew System::Windows::Forms::
                KeyEventHandler(this, &MainWindow::code_KeyDown);

            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 20.25F, System::Drawing::FontStyle::
                Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->Location = System::Drawing::Point(290, 10);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(82, 35);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Code";

            this->_list->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 15.75F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->_list->FormattingEnabled = true;
            this->_list->Location = System::Drawing::Point(291, 87);
            this->_list->Name = L"_list";
            this->_list->Size = System::Drawing::Size(910, 439);
            this->_list->TabIndex = 3;

            this->_give_out_btn->BackColor = System::Drawing::Color::Blue;
            this->_give_out_btn->Font = (gcnew System::Drawing::Font
            (L"Microsoft YaHei UI", 21.75F, System::Drawing::FontStyle::Bold,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->_give_out_btn->ForeColor = System::Drawing::Color::White;
            this->_give_out_btn->Location = System::Drawing::Point(629, 535);
            this->_give_out_btn->Name = L"_give_out_btn";
            this->_give_out_btn->Size = System::Drawing::Size(173, 47);
            this->_give_out_btn->TabIndex = 4;
            this->_give_out_btn->Text = L"Give out";
            this->_give_out_btn->UseVisualStyleBackColor = false;
            this->_give_out_btn->Click += gcnew System::EventHandler
            (this, &MainWindow::_give_out_btn_Click);

            this->vScrollBar1->Location = System::Drawing::Point(1166, 87);
            this->vScrollBar1->Name = L"vScrollBar1";
            this->vScrollBar1->Size = System::Drawing::Size(35, 439);
            this->vScrollBar1->TabIndex = 5;

            this->groupBox2->BackColor = System::Drawing::Color::Blue;
            this->groupBox2->Controls->Add(this->give_label);
            this->groupBox2->Controls->Add(this->label5);
            this->groupBox2->Controls->Add(this->return_label);
            this->groupBox2->Location = System::Drawing::Point(0, -13);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(286, 630);
            this->groupBox2->TabIndex = 8;
            this->groupBox2->TabStop = false;

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
            this->return_label->Click += gcnew System::EventHandler
            (this, &MainWindow::return_label_Click);

            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->ClientSize = System::Drawing::Size(1214, 617);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->vScrollBar1);
            this->Controls->Add(this->_give_out_btn);
            this->Controls->Add(this->_list);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->_code);
            this->Name = L"MainWindow";
            this->StartPosition = System::Windows::Forms::FormStartPosition::
                CenterScreen;
            this->Text = L"Ozon";
            this->FormClosed += gcnew System::Windows::Forms::
            FormClosedEventHandler(this, &MainWindow::MainWindow_FormClosed);
            this->groupBox2->ResumeLayout(false);
            this->groupBox2->PerformLayout();
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
               file.close();

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
                   Date date(products[i][6], "DD.MM.YYYY");
                   Product product(code, price, prepay, limit,
                       returnability, date);

                   cells[cell_num - 1].add_new_product(product);
               }
           }

           TVector<Cell> read_cells() {
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
               if (returnability)
                   new_product += "Returnability: yes";
               else
                   new_product += "Returnability: no";

               return new_product;
           }

    private: System::Void code_KeyDown(System::Object^ sender,
        System::Windows::Forms::KeyEventArgs^ e) {
        if (_code->Text == "") return;
        if (e->KeyCode == Keys::Enter) {
            *all_cells = read_cells();
            int64_t code = System::Convert::ToInt64(_code->Text);
            try {
                TVector<Product> products = 
                    get_products_by_code(*all_cells, code);
                _list->Items->Clear();

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

            void delete_row(std::string file_name, int code) {
                TVector<TVector<std::string>> table = read(file_name);

                std::ofstream file(file_name);
                for (int i = 0; i < table.size(); i++) {
                    if (find(table[i], std::to_string(code)) != -1)  // found
                        continue;
                    std::string row = "";
                    for (int j = 0; j < table[i].size(); j++) {
                        if (j == table[i].size() - 1)
                            row += table[i][j] + "\n";
                        else row += table[i][j] + ";";
                    }

                    file << row;
                }
                file.close();
            }

    private: System::Void _give_out_btn_Click(System::Object^ sender,
        System::EventArgs^ e) {
        if (_list->Items->Count == 0) return;
        int64_t code = System::Convert::ToInt64(_code->Text);
        TVector<Product> all_products =
            get_products_by_code(*all_cells, code);
        TVector<Product> products;
        TVector<Product> returned_products;

        for (int i = 0; i < _list->Items->Count; i++) {
            if (_list->GetItemChecked(i))
                products.push_back(all_products[i]);
            else returned_products.push_back(all_products[i]);
        }

        int number = code % 1000;
        char today[10];
        _strdate_s(today);
        Date date(today, "MM/DD/YY");
        for (int i = 0; i < all_products.size(); i++) {
            delete_row(
        "C:/Users/user/Project_PVZ_Ozon/Project_PVZ_Ozon/source/Products.csv",
                all_products[i].get_code());
        }
        give_products((*all_cells)[number - 1], products, 123, date);
        return_products((*all_cells)[number - 1], returned_products);
        _list->Items->Clear();
    }

private: System::Void return_label_Click(System::Object^ sender,
    System::EventArgs^ e) {
    ReturnWindow^ window = gcnew ReturnWindow();
    window->Owner = this;
    this->Hide();
    window->ShowDialog(this);
}
};
}  // namespace CppCLRWinFormsProject
