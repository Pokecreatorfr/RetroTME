#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "Core.h"

#include <msclr/marshal_cppstd.h>

using namespace std;

namespace RetroTME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Configuration;
	using namespace System::IO;

	/// <summary>
	/// Description résumée de start_page
	/// </summary>
	public ref class start_page : public System::Windows::Forms::Form
	{
	public:
		start_page(Core* core)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			
			// check if the config file exists
			this->core = core;
			core->config_manager.load_config();
			if (core->config_manager.get_last_oppened_path() != "")
			{
				// change the button text
				this->button1->Text = gcnew String(core->config_manager.get_last_oppened_path().c_str());
				if (core->config_manager.get_last_oppened_path1() != "")
				{
					this->button2->Text = gcnew String(core->config_manager.get_last_oppened_path1().c_str());
					if (core->config_manager.get_last_oppened_path2() != "")
					{
						this->button3->Text = gcnew String(core->config_manager.get_last_oppened_path2().c_str());
					}
					else
					{
						this->button3->Text = "";
					}
				}
				else
				{
					this->button2->Text = "";
					this->button3->Text = "";
				}
				
			}
			else
			{
				this->button1->Text = "";
				this->button2->Text = "";
				this->button3->Text = "";
			}
		}
	private: 
		Core* core;

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~start_page()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel2;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(511, 498);
			this->panel1->TabIndex = 0;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(0, 166);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(511, 77);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &start_page::button3_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(0, 83);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(511, 77);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &start_page::button2_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(511, 77);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &start_page::button1_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button4->Location = System::Drawing::Point(167, 11);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(185, 28);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Ouvrir";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &start_page::button4_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button5->Location = System::Drawing::Point(167, 49);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(185, 28);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Nouveau";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &start_page::button5_Click);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->panel2->Controls->Add(this->button5);
			this->panel2->Controls->Add(this->button4);
			this->panel2->Location = System::Drawing::Point(509, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(363, 498);
			this->panel2->TabIndex = 3;
			// 
			// start_page
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->ClientSize = System::Drawing::Size(873, 501);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"start_page";
			this->Text = L"start_page";
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		// chose folder dialog and set current path
		FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();
		if (fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// check if project.ini exist in the folder
			if (!std::ifstream(msclr::interop::marshal_as<std::string>(fbd->SelectedPath) + "\\project.ini"))
			{
				MessageBox::Show("Le fichier project.ini n'existe pas dans le dossier selectionné", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			// set last oppened path
			core->config_manager.set_last_oppened_path2(core->config_manager.get_last_oppened_path1());
			core->config_manager.set_last_oppened_path1(core->config_manager.get_last_oppened_path());
			// set current path
			core->config_manager.set_last_oppened_path(msclr::interop::marshal_as<std::string>(fbd->SelectedPath));
			core->config_manager.save_config();
			// load project
			core->project_manager.load_project(msclr::interop::marshal_as<std::string>(fbd->SelectedPath));
			core->openned_project_path = msclr::interop::marshal_as<std::string>(fbd->SelectedPath);
			// close start page
			this->Close();
		}
		
	}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();
	if (fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		// check if project.ini exist in the folder
		if (std::ifstream(msclr::interop::marshal_as<std::string>(fbd->SelectedPath) + "\\project.ini"))
		{
			MessageBox::Show("Le fichier project.ini existe déjà dans le dossier selectionné", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// create project.ini
		core->project_manager.create_project(msclr::interop::marshal_as<std::string>(fbd->SelectedPath));
		// set current path
		core->config_manager.set_last_oppened_path2(core->config_manager.get_last_oppened_path1());
		core->config_manager.set_last_oppened_path1(core->config_manager.get_last_oppened_path());
		// set current path
		core->config_manager.set_last_oppened_path(msclr::interop::marshal_as<std::string>(fbd->SelectedPath));
		core->config_manager.save_config();
		// load project
		core->project_manager.load_project(msclr::interop::marshal_as<std::string>(fbd->SelectedPath));
		core->openned_project_path = msclr::interop::marshal_as<std::string>(fbd->SelectedPath);
		// close start page
		this->Close();
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!std::ifstream(msclr::interop::marshal_as<std::string>(button1->Text) + "\\project.ini"))
	{
		MessageBox::Show("Le fichier project.ini n'existe pas dans le dossier selectionné", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	// set last oppened path
	core->config_manager.set_last_oppened_path2(core->config_manager.get_last_oppened_path1());
	core->config_manager.set_last_oppened_path1(core->config_manager.get_last_oppened_path());
	// set current path
	core->config_manager.set_last_oppened_path(msclr::interop::marshal_as<std::string>(button1->Text));
	core->config_manager.save_config();
	// load project
	core->project_manager.load_project(msclr::interop::marshal_as<std::string>(button1->Text));
	core->openned_project_path = msclr::interop::marshal_as<std::string>(button1->Text);
	// close start page
	this->Close();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!std::ifstream(msclr::interop::marshal_as<std::string>(button2->Text) + "\\project.ini"))
	{
		MessageBox::Show("Le fichier project.ini n'existe pas dans le dossier selectionné", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	// set last oppened path
	core->config_manager.set_last_oppened_path2(core->config_manager.get_last_oppened_path1());
	core->config_manager.set_last_oppened_path1(core->config_manager.get_last_oppened_path());
	// set current path
	core->config_manager.set_last_oppened_path(msclr::interop::marshal_as<std::string>(button2->Text));
	core->config_manager.save_config();
	// load project
	core->project_manager.load_project(msclr::interop::marshal_as<std::string>(button2->Text));
	core->openned_project_path = msclr::interop::marshal_as<std::string>(button2->Text);
	// close start page
	this->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!std::ifstream(msclr::interop::marshal_as<std::string>(button3->Text) + "\\project.ini"))
	{
		MessageBox::Show("Le fichier project.ini n'existe pas dans le dossier selectionné", "Erreur", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	// set last oppened path
	core->config_manager.set_last_oppened_path2(core->config_manager.get_last_oppened_path1());
	core->config_manager.set_last_oppened_path1(core->config_manager.get_last_oppened_path());
	// set current path
	core->config_manager.set_last_oppened_path(msclr::interop::marshal_as<std::string>(button3->Text));
	core->config_manager.save_config();
	// load project
	core->project_manager.load_project(msclr::interop::marshal_as<std::string>(button3->Text));
	core->openned_project_path = msclr::interop::marshal_as<std::string>(button3->Text);
	// close start page
	this->Close();
}
};
}
