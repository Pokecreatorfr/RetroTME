#pragma once
#include "Core.h"
#include <msclr/marshal_cppstd.h>

namespace RetroTME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de new_tileset
	/// </summary>
	public ref class new_tileset : public System::Windows::Forms::Form
	{
	public:
		new_tileset(Core* core)
		{
			InitializeComponent();
			this->core = core;
		}
	public:
		void update_image_list() {
			std::vector<std::string> img_list = core->project_manager.get_image_manager()->get_image_list();
			for (int i = 0; i < img_list.size(); i++) {
				img_list[i] = img_list[i].substr(img_list[i].find_last_of("\\") + 1);
				listBox1->Items->Add(gcnew String(img_list[i].c_str()));
			}
		}

	private:
		Core* core;
		String^ name = "";
		String^ selected_image = "";
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~new_tileset()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(8, 31);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(271, 186);
			this->listBox1->TabIndex = 11;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &new_tileset::listBox1_SelectedIndexChanged);
			// 
			// textBox5
			// 
			this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox5->ForeColor = System::Drawing::SystemColors::Menu;
			this->textBox5->Location = System::Drawing::Point(8, 12);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->ShortcutsEnabled = false;
			this->textBox5->Size = System::Drawing::Size(56, 13);
			this->textBox5->TabIndex = 12;
			this->textBox5->Text = L"Image:";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &new_tileset::textBox5_TextChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(8, 251);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(271, 31);
			this->richTextBox1->TabIndex = 13;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &new_tileset::richTextBox1_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox1->ForeColor = System::Drawing::SystemColors::Menu;
			this->textBox1->Location = System::Drawing::Point(8, 232);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ShortcutsEnabled = false;
			this->textBox1->Size = System::Drawing::Size(56, 13);
			this->textBox1->TabIndex = 14;
			this->textBox1->Text = L"Nom :";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(8, 304);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(271, 38);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Confirmer";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &new_tileset::button1_Click);
			// 
			// new_tileset
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->ClientSize = System::Drawing::Size(291, 355);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->listBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"new_tileset";
			this->Text = L"new_tileset";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		int cursorPosition = richTextBox1->SelectionStart;
		// delete space
		if (richTextBox1->Text->Contains(" "))
		{
			richTextBox1->Text = richTextBox1->Text->Replace(" ", "");
			cursorPosition--;
		}
		// delete special char
		richTextBox1->Text = System::Text::RegularExpressions::Regex::Replace(richTextBox1->Text, "[^a-zA-Z0-9_]+", "");
		// delete number at the beginning
		richTextBox1->Text = System::Text::RegularExpressions::Regex::Replace(richTextBox1->Text, "^[0-9]+", "");

		richTextBox1->SelectionStart = cursorPosition;
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		selected_image = listBox1->Text;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// check if name is not empty
		if (richTextBox1->Text->Length == 0)
		{
			MessageBox::Show("Le nom ne peut pas etre vide");
			return;
		}
		// check if name is not already taken
		vector<string> name_list = core->project_manager.get_tileset_manager()->get_tileset_list();
		// chech if name is not already taken
		for (int i = 0; i < name_list.size(); i++)
		{
			if (name_list[i] == msclr::interop::marshal_as<std::string>(richTextBox1->Text))
			{
				MessageBox::Show("Le nom est deja pris");
				return;
			}
		}
		// check if image is selected
		if (selected_image == "")
		{
			MessageBox::Show("Aucune image selectionnee");
			return;
		}
		// create tileset
		core->project_manager.get_tileset_manager()->new_tileset(msclr::interop::marshal_as<std::string>(richTextBox1->Text));	
		// add image to tileset
	}
};
}
