#pragma once

namespace DataVaksin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	
	public ref class Menu_Utama : public System::Windows::Forms::Form
	{

		MySqlConnection ^sqlConn = gcnew MySqlConnection();
		MySqlCommand ^sqlCmd = gcnew MySqlCommand();
		DataTable ^sqlDt = gcnew DataTable();
		MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter();
		MySqlDataReader^ sqlRd;

	public:
		Menu_Utama(void)
		{
			InitializeComponent();
			
			VaksinasiMh();
		}

	protected:
		~Menu_Utama()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;




	private: System::Windows::Forms::Button^ tambah;
	private: System::Windows::Forms::Button^ Hapus;
	private: System::Windows::Forms::Panel^ panel_input;

	private: System::Windows::Forms::Panel^ panel2;


	private: System::Windows::Forms::Label^ Dosis;
	private: System::Windows::Forms::TextBox^ tb_Nim;

	private: System::Windows::Forms::Label^ Nim;
	private: System::Windows::Forms::TextBox^ tb_Nama;

	private: System::Windows::Forms::Label^ Nama;
	private: System::Windows::Forms::Panel^ panel_tabel;
	private: System::Windows::Forms::DataGridView^ data_output;
	private: System::Windows::Forms::ComboBox^ cb_Vaksin;









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
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tambah = (gcnew System::Windows::Forms::Button());
			this->Hapus = (gcnew System::Windows::Forms::Button());
			this->panel_input = (gcnew System::Windows::Forms::Panel());
			this->cb_Vaksin = (gcnew System::Windows::Forms::ComboBox());
			this->Dosis = (gcnew System::Windows::Forms::Label());
			this->tb_Nim = (gcnew System::Windows::Forms::TextBox());
			this->Nim = (gcnew System::Windows::Forms::Label());
			this->tb_Nama = (gcnew System::Windows::Forms::TextBox());
			this->Nama = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel_tabel = (gcnew System::Windows::Forms::Panel());
			this->data_output = (gcnew System::Windows::Forms::DataGridView());
			this->panel_input->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel_tabel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_output))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label1->Location = System::Drawing::Point(202, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(253, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Data Vaksinasi Mahasiswa";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// tambah
			// 
			this->tambah->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->tambah->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->tambah->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tambah->Location = System::Drawing::Point(3, 3);
			this->tambah->Name = L"tambah";
			this->tambah->Size = System::Drawing::Size(88, 32);
			this->tambah->TabIndex = 2;
			this->tambah->Text = L"Tambah";
			this->tambah->UseVisualStyleBackColor = false;
			this->tambah->Click += gcnew System::EventHandler(this, &Menu_Utama::tambah_Click);
			// 
			// Hapus
			// 
			this->Hapus->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->Hapus->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Hapus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Hapus->Location = System::Drawing::Point(93, 3);
			this->Hapus->Name = L"Hapus";
			this->Hapus->Size = System::Drawing::Size(88, 32);
			this->Hapus->TabIndex = 3;
			this->Hapus->Text = L"Hapus";
			this->Hapus->UseVisualStyleBackColor = false;
			this->Hapus->Click += gcnew System::EventHandler(this, &Menu_Utama::Hapus_Click);
			// 
			// panel_input
			// 
			this->panel_input->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_input->Controls->Add(this->cb_Vaksin);
			this->panel_input->Controls->Add(this->Dosis);
			this->panel_input->Controls->Add(this->tb_Nim);
			this->panel_input->Controls->Add(this->Nim);
			this->panel_input->Controls->Add(this->tb_Nama);
			this->panel_input->Controls->Add(this->Nama);
			this->panel_input->Location = System::Drawing::Point(12, 36);
			this->panel_input->Name = L"panel_input";
			this->panel_input->Size = System::Drawing::Size(688, 106);
			this->panel_input->TabIndex = 4;
			this->panel_input->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Menu_Utama::panel_input_Paint);
			// 
			// cb_Vaksin
			// 
			this->cb_Vaksin->BackColor = System::Drawing::SystemColors::Info;
			this->cb_Vaksin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->cb_Vaksin->ForeColor = System::Drawing::SystemColors::WindowText;
			this->cb_Vaksin->FormattingEnabled = true;
			this->cb_Vaksin->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"1", L"2", L"3" });
			this->cb_Vaksin->Location = System::Drawing::Point(365, 34);
			this->cb_Vaksin->Name = L"cb_Vaksin";
			this->cb_Vaksin->Size = System::Drawing::Size(226, 28);
			this->cb_Vaksin->TabIndex = 7;
			// 
			// Dosis
			// 
			this->Dosis->AutoSize = true;
			this->Dosis->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->Dosis->Location = System::Drawing::Point(361, 6);
			this->Dosis->Name = L"Dosis";
			this->Dosis->Size = System::Drawing::Size(140, 24);
			this->Dosis->TabIndex = 6;
			this->Dosis->Text = L"Dosis Vaksinasi";
			// 
			// tb_Nim
			// 
			this->tb_Nim->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tb_Nim->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->tb_Nim->Location = System::Drawing::Point(70, 59);
			this->tb_Nim->Name = L"tb_Nim";
			this->tb_Nim->Size = System::Drawing::Size(234, 26);
			this->tb_Nim->TabIndex = 3;
			// 
			// Nim
			// 
			this->Nim->AutoSize = true;
			this->Nim->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->Nim->Location = System::Drawing::Point(4, 59);
			this->Nim->Name = L"Nim";
			this->Nim->Size = System::Drawing::Size(44, 24);
			this->Nim->TabIndex = 2;
			this->Nim->Text = L"NIM";
			// 
			// tb_Nama
			// 
			this->tb_Nama->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tb_Nama->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->tb_Nama->Location = System::Drawing::Point(70, 13);
			this->tb_Nama->Name = L"tb_Nama";
			this->tb_Nama->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->tb_Nama->Size = System::Drawing::Size(234, 26);
			this->tb_Nama->TabIndex = 1;
			this->tb_Nama->TextChanged += gcnew System::EventHandler(this, &Menu_Utama::tb_Nama_TextChanged);
			// 
			// Nama
			// 
			this->Nama->AutoSize = true;
			this->Nama->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->Nama->Location = System::Drawing::Point(4, 13);
			this->Nama->Name = L"Nama";
			this->Nama->Size = System::Drawing::Size(60, 24);
			this->Nama->TabIndex = 0;
			this->Nama->Text = L"Nama";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->Hapus);
			this->panel2->Controls->Add(this->tambah);
			this->panel2->Location = System::Drawing::Point(512, 148);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(188, 42);
			this->panel2->TabIndex = 5;
			// 
			// panel_tabel
			// 
			this->panel_tabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_tabel->Controls->Add(this->data_output);
			this->panel_tabel->Location = System::Drawing::Point(12, 196);
			this->panel_tabel->Name = L"panel_tabel";
			this->panel_tabel->Size = System::Drawing::Size(688, 176);
			this->panel_tabel->TabIndex = 6;
			// 
			// data_output
			// 
			this->data_output->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->data_output->Location = System::Drawing::Point(3, 4);
			this->data_output->Name = L"data_output";
			this->data_output->Size = System::Drawing::Size(678, 165);
			this->data_output->TabIndex = 0;
			this->data_output->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Menu_Utama::data_output_CellContentClick);
			// 
			// Menu_Utama
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(712, 381);
			this->Controls->Add(this->panel_tabel);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel_input);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"Menu_Utama";
			this->StartPosition = System::Windows::Forms::FormStartPosition::WindowsDefaultBounds;
			this->Text = L"Data Vaksin";
			this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
			this->Load += gcnew System::EventHandler(this, &Menu_Utama::Menu_Utama_Load);
			this->panel_input->ResumeLayout(false);
			this->panel_input->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel_tabel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->data_output))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void VaksinasiMh() {
		sqlConn->ConnectionString = "datasource = localhost;port = 3306; username=root;password=Lostsaga02=;database=vaksin";
		sqlConn->Open();

		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText = "select * from vaksin";
		sqlRd = sqlCmd->ExecuteReader();
		sqlDt->Load(sqlRd);
		sqlRd->Close();
		sqlConn->Close();
		data_output->DataSource = sqlDt;

	}

	private: System::Void refresh_data() {

		try {
			sqlConn->ConnectionString = "datasource = localhost;port = 3306; username=root;password=Lostsaga02=;database=vaksin";
			sqlCmd->Connection = sqlConn;

			MySqlDataAdapter^ sqlDtA = gcnew MySqlDataAdapter("select * from vaksin", sqlConn);
			DataTable^ sqlDt = gcnew DataTable();
			sqlDtA->Fill(sqlDt);
			data_output->DataSource = sqlDt;
		}
		catch(Exception^ ex) {
			MessageBox::Show(ex->Message, "info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	}
		
	private: System::Void reset_data() {
		try {
			tb_Nim->Text = "";
			tb_Nama->Text = "";
			cb_Vaksin->Text = "";
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}

	private: System::Void Menu_Utama_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tb_Nama_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void data_output_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		tb_Nim->Text = data_output->SelectedRows[0]->Cells[0]->Value->ToString();
		tb_Nama->Text = data_output->SelectedRows[0]->Cells[1]->Value->ToString();
		cb_Vaksin->Text = data_output->SelectedRows[0]->Cells[2]->Value->ToString();
	}
	private: System::Void panel_input_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void tambah_Click(System::Object^ sender, System::EventArgs^ e) {

		try {
			sqlConn->ConnectionString = "datasource = localhost;port = 3306; username=root;password=Lostsaga02=;database=vaksin";
			sqlConn->Open();

			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "insert into vaksin(NIM,Nama,Vaksin)""values('"+tb_Nim->Text +"','" + tb_Nama->Text + "','" + cb_Vaksin->Text + "')";
			MessageBox::Show("Data Telah Masuk","info", MessageBoxButtons::OK, MessageBoxIcon::Information);
			sqlCmd->ExecuteNonQuery();
			sqlConn->Close();
		
			refresh_data();
			reset_data();

		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	}
	private: System::Void Hapus_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			sqlConn->ConnectionString = "datasource = localhost;port = 3306; username=root;password=Lostsaga02=;database=vaksin";
			sqlCmd->Connection = sqlConn;

			String^ ID = tb_Nim->Text;
			MySqlCommand^ sqlCmd = gcnew MySqlCommand("delete from vaksin where NIM = " + ID + "", sqlConn);
			sqlConn->Open();

			sqlRd = sqlCmd->ExecuteReader();
			MessageBox::Show("Data Telah Dihapus", "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			sqlConn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		refresh_data();
	}
};
}
