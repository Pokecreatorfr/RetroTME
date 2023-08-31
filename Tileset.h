#pragma once
#include "Core.h"
#include "new_tileset.h"

namespace RetroTME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Tileset
	/// </summary>
	public ref class Tileset : public System::Windows::Forms::Form
	{
	public:
		Tileset(Core* core)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			this->core = core;
		}

	public : 
		void update_image_list() {
			std::vector<std::string> img_list = core->project_manager.get_image_manager()->get_image_list();
			for (int i = 0; i < img_list.size(); i++) {
				// ne garder que le nom du fichier
				img_list[i] = img_list[i].substr(img_list[i].find_last_of("\\") + 1);
				listBox1->Items->Add(gcnew String(img_list[i].c_str()));
			}
		}
	private: System::Windows::Forms::Button^ Nouveau;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TextBox^ textBox5;
	public:

	private:
		Core* core;

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Tileset()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::VScrollBar^ vScrollBar1;
	private: System::Windows::Forms::HScrollBar^ hScrollBar1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown1;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->vScrollBar1 = (gcnew System::Windows::Forms::VScrollBar());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->Nouveau = (gcnew System::Windows::Forms::Button());
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->vScrollBar1);
			this->panel1->Controls->Add(this->hScrollBar1);
			this->panel1->Location = System::Drawing::Point(1, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(410, 617);
			this->panel1->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(389, 594);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// vScrollBar1
			// 
			this->vScrollBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->vScrollBar1->Location = System::Drawing::Point(389, 0);
			this->vScrollBar1->Name = L"vScrollBar1";
			this->vScrollBar1->Size = System::Drawing::Size(20, 595);
			this->vScrollBar1->TabIndex = 1;
			// 
			// hScrollBar1
			// 
			this->hScrollBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->hScrollBar1->Location = System::Drawing::Point(0, 595);
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->Size = System::Drawing::Size(410, 20);
			this->hScrollBar1->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->Controls->Add(this->textBox5);
			this->panel2->Controls->Add(this->listBox1);
			this->panel2->Controls->Add(this->Nouveau);
			this->panel2->Controls->Add(this->domainUpDown1);
			this->panel2->Location = System::Drawing::Point(413, -1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(826, 617);
			this->panel2->TabIndex = 1;
			// 
			// textBox5
			// 
			this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox5->ForeColor = System::Drawing::SystemColors::Menu;
			this->textBox5->Location = System::Drawing::Point(552, 32);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->ShortcutsEnabled = false;
			this->textBox5->Size = System::Drawing::Size(56, 13);
			this->textBox5->TabIndex = 11;
			this->textBox5->Text = L"Image:";
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(552, 50);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(271, 95);
			this->listBox1->TabIndex = 10;
			// 
			// Nouveau
			// 
			this->Nouveau->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Nouveau->Location = System::Drawing::Point(552, 3);
			this->Nouveau->Name = L"Nouveau";
			this->Nouveau->Size = System::Drawing::Size(271, 23);
			this->Nouveau->TabIndex = 1;
			this->Nouveau->Text = L"Nouveau";
			this->Nouveau->UseVisualStyleBackColor = true;
			// 
			// domainUpDown1
			// 
			this->domainUpDown1->Location = System::Drawing::Point(4, 3);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->Size = System::Drawing::Size(120, 20);
			this->domainUpDown1->TabIndex = 0;
			this->domainUpDown1->Text = L"domainUpDown1";
			this->domainUpDown1->SelectedItemChanged += gcnew System::EventHandler(this, &Tileset::domainUpDown1_SelectedItemChanged);
			// 
			// Tileset
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->ClientSize = System::Drawing::Size(1240, 616);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Tileset";
			this->Text = L"Tileset";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void domainUpDown1_SelectedItemChanged(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
