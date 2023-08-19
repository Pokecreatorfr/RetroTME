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
	/// Description résumée de img_to_c
	/// </summary>
	public ref class img_to_c : public System::Windows::Forms::Form
	{
	public:
		img_to_c(Core* core)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			this->core = core;
			update_image_list();

		}
		void update_image_list()
		{
			// delete all items
			listBox1->Items->Clear();

			// add all items
			std::vector<std::string> name_list = core->project_manager.get_image_manager()->get_image_names();
			for (int i = 0; i < name_list.size(); i++)
			{
				listBox1->Items->Add(gcnew String(name_list[i].c_str()));
			}
		}
	private:
		Bitmap^ bmp;
		Bitmap^ imported_bmp;
		Bitmap^ bitmap_view;
	private: System::Windows::Forms::ListBox^ listBox1;
		   


	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
		   Core* core;
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~img_to_c()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->richTextBox1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(440, 579);
			this->panel1->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(312, 11);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(121, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Générer";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &img_to_c::button2_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox3->ForeColor = System::Drawing::SystemColors::Menu;
			this->textBox3->Location = System::Drawing::Point(74, 102);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->ShortcutsEnabled = false;
			this->textBox3->Size = System::Drawing::Size(51, 13);
			this->textBox3->TabIndex = 5;
			this->textBox3->Text = L"Y:";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox2->ForeColor = System::Drawing::SystemColors::Menu;
			this->textBox2->Location = System::Drawing::Point(12, 102);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ShortcutsEnabled = false;
			this->textBox2->Size = System::Drawing::Size(56, 13);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"X:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(152, 11);
			this->richTextBox1->Multiline = false;
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(142, 23);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &img_to_c::richTextBox1_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox1->ForeColor = System::Drawing::SystemColors::Menu;
			this->textBox1->Location = System::Drawing::Point(118, 16);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(28, 13);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Nom:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Location = System::Drawing::Point(12, 121);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(421, 455);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Charger";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &img_to_c::button1_Click);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->Controls->Add(this->listBox1);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->textBox5);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Location = System::Drawing::Point(439, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(732, 578);
			this->panel2->TabIndex = 1;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(501, 3);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(228, 95);
			this->listBox1->TabIndex = 9;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &img_to_c::listBox1_SelectedIndexChanged);
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox4->ForeColor = System::Drawing::SystemColors::Menu;
			this->textBox4->Location = System::Drawing::Point(68, 158);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->ShortcutsEnabled = false;
			this->textBox4->Size = System::Drawing::Size(51, 13);
			this->textBox4->TabIndex = 7;
			this->textBox4->Text = L"Y:";
			// 
			// textBox5
			// 
			this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox5->ForeColor = System::Drawing::SystemColors::Menu;
			this->textBox5->Location = System::Drawing::Point(7, 158);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->ShortcutsEnabled = false;
			this->textBox5->Size = System::Drawing::Size(56, 13);
			this->textBox5->TabIndex = 6;
			this->textBox5->Text = L"X:";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->Location = System::Drawing::Point(3, 177);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(728, 398);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// img_to_c
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(65)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->ClientSize = System::Drawing::Size(1170, 579);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"img_to_c";
			this->Text = L"img_to_c";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Open a file dialog to select an image file
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "Image Files|*.png;*.jpg;*.bmp";
		openFileDialog1->Title = "Select an Image File";

		// Process input if the user clicked OK.
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			delete imported_bmp;
			delete bmp;
			// Load the image file into a Bitmap object.
			imported_bmp = gcnew Bitmap(openFileDialog1->FileName);
			bmp = imported_bmp;
			// resize image to fit the picturebox size (if needed) but keep the aspect ratio
			if (imported_bmp->Width > pictureBox1->Width || imported_bmp->Height > pictureBox1->Height)
			{
				if (imported_bmp->Width > imported_bmp->Height)
					imported_bmp = (Bitmap^)bmp->GetThumbnailImage(pictureBox1->Width, bmp->Height * pictureBox1->Width / bmp->Width, nullptr, IntPtr::Zero);
				else
					imported_bmp = (Bitmap^)bmp->GetThumbnailImage(bmp->Width * pictureBox1->Height / bmp->Height, pictureBox1->Height, nullptr, IntPtr::Zero);
				
			}

			// Display the image in the PictureBox.
			pictureBox1->Image = imported_bmp;
			pictureBox1->SizeMode = PictureBoxSizeMode::CenterImage;

			// x and y on textbox2 and textbox3
			this->textBox2->Text = "X: " + bmp->Width;
			this->textBox3->Text = "Y: " + bmp->Height;

		}
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		// If one character is not allowed, remove it
		// allowed characters: a-z, A-Z, 0-9 , but it can't start with a number
		// get the current cursor position
		int cursor_position = this->richTextBox1->SelectionStart;
		// remove all characters that are not allowed
		this->richTextBox1->Text = System::Text::RegularExpressions::Regex::Replace(this->richTextBox1->Text, "[^a-zA-Z0-9]", "");

		// if the first character is a number, remove it
		if (this->richTextBox1->Text != "" && this->richTextBox1->Text[0] >= '0' && this->richTextBox1->Text[0] <= '9')
		{ 
			this->richTextBox1->Text = this->richTextBox1->Text->Remove(0, 1);
			cursor_position--;
		}

		// set the cursor position to the previous position
		this->richTextBox1->SelectionStart = cursor_position;
		this->richTextBox1->SelectionLength = 0;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// if richTextBox1 is empty, return an error
		if (this->richTextBox1->Text == "")
		{
			MessageBox::Show("Please enter a name for the image", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// if bmp is null, return an error
		if (bmp == nullptr)
		{
			MessageBox::Show("Please select an image", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		// if the name already exists, return an error
		std::vector<std::string> names = core->project_manager.get_image_manager()->get_image_names();
		for (int i = 0; i < names.size(); i++)
		{
			if (names[i] == msclr::interop::marshal_as<std::string>(this->richTextBox1->Text))
			{
				MessageBox::Show("The name already exists", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		// create the image
		std::string name = msclr::interop::marshal_as<std::string>(this->richTextBox1->Text);
		core->project_manager.get_image_manager()->create_image(bmp, name);
		this->update_image_list();
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// if no image is selected, return
		if (this->listBox1->SelectedIndex == -1)
			return;
		// get the selected image
		delete bitmap_view;
		std::string name = msclr::interop::marshal_as<std::string>(this->listBox1->SelectedItem->ToString());
		bitmap_view = core->project_manager.get_image_manager()->get_bitmap(name);
		// display the image in the picturebox2
		pictureBox2->Image = bitmap_view;
		pictureBox2->SizeMode = PictureBoxSizeMode::CenterImage;
		// display the image size in the textbox4 and textbox5
		this->textBox4->Text = "X: " + bitmap_view->Width;
		this->textBox5->Text = "Y: " + bitmap_view->Height;
	}
};
}
