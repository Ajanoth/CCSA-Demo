#pragma once
//#include <string>
#include <msclr\marshal_cppstd.h>
#include "CCSA_Functions.h"

namespace CCodeSecurityAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace std;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
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
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(13, 13);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(559, 507);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"C Code Security Analyzer:\n \
===========================================================================================\n \
Checks C (.c) programs for security errors\n \
including:\n \
Memory Leaks\n \
Buffer Overflow\n \
===========================================================================================\n \
Instructions:\n \
1) Click \"Browse...\" and select a valid C (.c) file.\n \
2) Click \"Run Tests!\" to run tests on your code.\n \
===========================================================================================\n \
Reset: Resets all fields.\n \
Close: Exits the application.";
			this->richTextBox1->ReadOnly = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(175, 528);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(235, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 526);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Run Tests!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GUI::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(94, 526);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Reset";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GUI::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(416, 526);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Browse...";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GUI::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(497, 526);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Close";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &GUI::button4_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"";
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Name = L"GUI";
			this->Text = L"C Code Security Analyzer";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//Run Tests! Button
		std::string filePath = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string output;
		if (filePath.compare("") != 0) {
			output = CCSA_Functions::MyCCSA_Functions::Run_Tests(filePath);
			richTextBox1->Text = msclr::interop::marshal_as<String ^>(output);
		}
		else {
			richTextBox1->Text = "Invalid File.\nPlease Select a valid C (.c) file.";
		}
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		//Reset Button
		textBox1->Text = "";
		richTextBox1->Text = "C Code Security Analyzer:\n \
===========================================================================================\n \
Checks C (.c) programs for security errors\n \
including:\n \
Memory Leaks\n \
Buffer Overflow\n \
===========================================================================================\n \
Instructions:\n \
1) Click \"Browse...\" and select a valid C (.c) file.\n \
2) Click \"Run Tests!\" to run tests on your code.\n \
===========================================================================================\n \
Reset: Resets all fields.\n \
Close: Exits the application.";
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		//Browse... Button
		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->RestoreDirectory = true;
		openFileDialog1->Filter = "C files (*.c)|*.c";
		openFileDialog1->FilterIndex = 1;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			textBox1->Text = openFileDialog1->FileName;
		}
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		//Close Button
		Application::Exit();
	}
};
}
