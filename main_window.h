#pragma once
#include "world.h"
#include "map.h"
#include "Tileset.h"
#include "start_page.h"
#include "Core.h"

namespace RetroTME {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de main_window
	/// </summary>
	public ref class main_window : public System::Windows::Forms::Form
	{
	public:
		main_window(Core* core)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			this->core = core;
			this->world = gcnew RetroTME::world();
			this->map = gcnew RetroTME::map();
			this->tileset = gcnew RetroTME::Tileset(core);
		}

	private:
		Core* core;
		RetroTME::world^ world;
		RetroTME::map^ map;
		RetroTME::Tileset^ tileset;


	private: System::Windows::Forms::Button^ Tileset_button;


		   
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~main_window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button_;
	private: System::Windows::Forms::Button^ Map_button;

	private: System::Windows::Forms::Button^ World_button;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main_window::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Tileset_button = (gcnew System::Windows::Forms::Button());
			this->Map_button = (gcnew System::Windows::Forms::Button());
			this->World_button = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button_ = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->panel1->Controls->Add(this->Tileset_button);
			this->panel1->Controls->Add(this->Map_button);
			this->panel1->Controls->Add(this->World_button);
			this->panel1->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(64, 580);
			this->panel1->TabIndex = 0;
			// 
			// Tileset_button
			// 
			this->Tileset_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->Tileset_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Tileset_button.BackgroundImage")));
			this->Tileset_button->Dock = System::Windows::Forms::DockStyle::Top;
			this->Tileset_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Tileset_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->Tileset_button->Location = System::Drawing::Point(0, 128);
			this->Tileset_button->Name = L"Tileset_button";
			this->Tileset_button->Size = System::Drawing::Size(64, 64);
			this->Tileset_button->TabIndex = 2;
			this->Tileset_button->UseVisualStyleBackColor = false;
			this->Tileset_button->Click += gcnew System::EventHandler(this, &main_window::button1_Click_1);
			// 
			// Map_button
			// 
			this->Map_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->Map_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Map_button.BackgroundImage")));
			this->Map_button->Dock = System::Windows::Forms::DockStyle::Top;
			this->Map_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Map_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->Map_button->Location = System::Drawing::Point(0, 64);
			this->Map_button->Name = L"Map_button";
			this->Map_button->Size = System::Drawing::Size(64, 64);
			this->Map_button->TabIndex = 1;
			this->Map_button->UseVisualStyleBackColor = false;
			this->Map_button->Click += gcnew System::EventHandler(this, &main_window::button2_Click);
			// 
			// World_button
			// 
			this->World_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->World_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"World_button.BackgroundImage")));
			this->World_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->World_button->Dock = System::Windows::Forms::DockStyle::Top;
			this->World_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->World_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(82)), static_cast<System::Int32>(static_cast<System::Byte>(82)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->World_button->Location = System::Drawing::Point(0, 0);
			this->World_button->Name = L"World_button";
			this->World_button->Size = System::Drawing::Size(64, 64);
			this->World_button->TabIndex = 0;
			this->World_button->UseVisualStyleBackColor = false;
			this->World_button->Click += gcnew System::EventHandler(this, &main_window::button1_Click);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel2->Location = System::Drawing::Point(64, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1091, 580);
			this->panel2->TabIndex = 1;
			// 
			// button_
			// 
			this->button_->Dock = System::Windows::Forms::DockStyle::Top;
			this->button_->Location = System::Drawing::Point(0, 0);
			this->button_->Name = L"button_";
			this->button_->Size = System::Drawing::Size(64, 64);
			this->button_->TabIndex = 0;
			this->button_->Text = L"button1";
			this->button_->UseVisualStyleBackColor = true;
			// 
			// main_window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1155, 580);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"main_window";
			this->Text = L"RetroTME";
			this->Load += gcnew System::EventHandler(this, &main_window::main_window_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void main_window_Load(System::Object^ sender, System::EventArgs^ e) {
		// display start_page on panel2
		RetroTME::start_page^ start_page = gcnew RetroTME::start_page(core);
		start_page->TopLevel = false;
		start_page->Dock = DockStyle::Fill;
		this->panel2->Controls->Add(start_page);
		start_page->Show();

		// while start_page is displayed desable buttons
		this->World_button->Enabled = false;
		this->Map_button->Enabled = false;
		this->Tileset_button->Enabled = false;

		// activate buttons when start_page is closed
		start_page->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &main_window::start_page_closed);


	}
	private: System::Void start_page_closed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		this->World_button->Enabled = true;
		this->Map_button->Enabled = true;
		this->Tileset_button->Enabled = true;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// if other page is displayed, remove it
		if(this->panel2->Controls->Count > 0)
			this->panel2->Controls->RemoveAt(0);
		// display world on panel2
		world->TopLevel = false;
		world->Dock = DockStyle::Fill;
		this->panel2->Controls->Add(world);
		world->Show();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// if other page is displayed, remove it
		if (this->panel2->Controls->Count > 0)
			this->panel2->Controls->RemoveAt(0);
		// display map on panel2
		map->TopLevel = false;
		map->Dock = DockStyle::Fill;
		this->panel2->Controls->Add(map);
		map->Show();
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		// if other page is displayed, remove it
		tileset->update_image_list();
		if (this->panel2->Controls->Count > 0)
			this->panel2->Controls->RemoveAt(0);
		// display tileset on panel2
		tileset->TopLevel = false;
		tileset->Dock = DockStyle::Fill;
		this->panel2->Controls->Add(tileset);
		tileset->Show();
		}
};
}
