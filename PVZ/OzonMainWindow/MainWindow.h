#pragma once

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
            this->SuspendLayout();
            // 
            // MainWindow
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1214, 617);
            this->Name = L"MainWindow";
            this->Text = L"Form1";
            this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainWindow::MainWindow_FormClosed);
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void MainWindow_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
        Application::Exit();
    }
    };
}
