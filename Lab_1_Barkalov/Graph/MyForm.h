#pragma once
#include <math.h>

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  F_1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  F_2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  V2i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;



	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column13;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column14;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column15;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column16;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;





	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->X = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->F_1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->F_2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->V2i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(279, 21);
			this->zedGraphControl1->Margin = System::Windows::Forms::Padding(5);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(668, 402);
			this->zedGraphControl1->TabIndex = 0;
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(169, 346);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(60, 100);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {
				this->X, this->F_1,
					this->F_2, this->V2i, this->Column1, this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7
			});
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(536, 377);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// X
			// 
			this->X->HeaderText = L"i";
			this->X->Name = L"X";
			this->X->ReadOnly = true;
			this->X->Width = 50;
			// 
			// F_1
			// 
			this->F_1->HeaderText = L"Xi";
			this->F_1->Name = L"F_1";
			this->F_1->ReadOnly = true;
			// 
			// F_2
			// 
			this->F_2->HeaderText = L"Vi";
			this->F_2->Name = L"F_2";
			this->F_2->ReadOnly = true;
			// 
			// V2i
			// 
			this->V2i->HeaderText = L"V2i";
			this->V2i->Name = L"V2i";
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Vi-V2i";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"ОЛП";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"hi";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"C1";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"C2";
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Ui";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"|Ui-Vi|";
			this->Column7->Name = L"Column7";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 312);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"a";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(57, 309);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(60, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 346);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(16, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"b";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(57, 346);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(60, 22);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(33, 381);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"u0";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(57, 381);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(60, 22);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"1";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->Column8,
					this->Column9, this->Column10, this->Column11, this->Column12, this->Column13, this->Column14, this->Column15, this->Column16
			});
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(536, 377);
			this->dataGridView2->TabIndex = 12;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"i";
			this->Column8->Name = L"Column8";
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Xi";
			this->Column9->Name = L"Column9";
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"Vi";
			this->Column10->Name = L"Column10";
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"V2i";
			this->Column11->Name = L"Column11";
			// 
			// Column12
			// 
			this->Column12->HeaderText = L"Vi-V2i";
			this->Column12->Name = L"Column12";
			// 
			// Column13
			// 
			this->Column13->HeaderText = L"ОЛП";
			this->Column13->Name = L"Column13";
			// 
			// Column14
			// 
			this->Column14->HeaderText = L"hi";
			this->Column14->Name = L"Column14";
			// 
			// Column15
			// 
			this->Column15->HeaderText = L"C1";
			this->Column15->Name = L"Column15";
			// 
			// Column16
			// 
			this->Column16->HeaderText = L"C2";
			this->Column16->Name = L"Column16";
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5,
					this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9
			});
			this->dataGridView3->Location = System::Drawing::Point(0, 0);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(536, 377);
			this->dataGridView3->TabIndex = 13;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"i";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Xi";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Vi";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"V2i";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Vi-V2i";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"ОЛП";
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"hi";
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->HeaderText = L"C1";
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->HeaderText = L"C2";
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(33, 418);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 17);
			this->label7->TabIndex = 14;
			this->label7->Text = L"h";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(57, 418);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(60, 22);
			this->textBox4->TabIndex = 15;
			this->textBox4->Text = L"0,1";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(33, 453);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(16, 17);
			this->label8->TabIndex = 16;
			this->label8->Text = L"n";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(57, 453);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(60, 22);
			this->textBox5->TabIndex = 17;
			this->textBox5->Text = L"100";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(33, 21);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(196, 17);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Тестовая задача имеет вид:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(24, 84);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(225, 17);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Основная задача №1 имеет вид:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(24, 181);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(225, 17);
			this->label11->TabIndex = 20;
			this->label11->Text = L"Основная задача №2 имеет вид:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(279, 449);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(129, 21);
			this->checkBox1->TabIndex = 21;
			this->checkBox1->Text = L"Контроль шага";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(33, 485);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(16, 17);
			this->label12->TabIndex = 22;
			this->label12->Text = L"e";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(56, 485);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(60, 22);
			this->textBox6->TabIndex = 23;
			this->textBox6->Text = L"0,001";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 383);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(105, 17);
			this->label13->TabIndex = 24;
			this->label13->Text = L"Max uncorrect: \r\n";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(955, 21);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(544, 529);
			this->tabControl1->TabIndex = 25;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(536, 500);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Тестовая задача";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(536, 500);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Основная задача №1";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView3);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(536, 500);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Основная задача №2";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 403);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 17);
			this->label4->TabIndex = 25;
			this->label4->Text = L"Max OLP: ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 420);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 17);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Summ C1: ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 437);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(76, 17);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Summ C2: ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(298, 383);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(53, 17);
			this->label14->TabIndex = 28;
			this->label14->Text = L"Max h: ";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(298, 403);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(50, 17);
			this->label15->TabIndex = 29;
			this->label15->Text = L"Min h: ";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(298, 437);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(32, 17);
			this->label16->TabIndex = 30;
			this->label16->Text = L"n = ";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(298, 420);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(59, 17);
			this->label17->TabIndex = 31;
			this->label17->Text = L"b - xn = ";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(85, 46);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(66, 17);
			this->label18->TabIndex = 26;
			this->label18->Text = L"du/dx = u";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(24, 111);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(230, 17);
			this->label19->TabIndex = 27;
			this->label19->Text = L"du/dx = f(x)*u*u + u - u*u*u*sin(10x)";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(72, 137);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(105, 17);
			this->label20->TabIndex = 28;
			this->label20->Text = L"f(x) = x/(1 + x*x)";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(163, 309);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(66, 17);
			this->label21->TabIndex = 29;
			this->label21->Text = L"u(0) = u0";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(54, 208);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(157, 17);
			this->label22->TabIndex = 30;
			this->label22->Text = L"d2u/dx2 + g(x, u, u\') = 0";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(85, 225);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(72, 17);
			this->label23->TabIndex = 31;
			this->label23->Text = L"u\'(0) = uo\'";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(33, 242);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(208, 17);
			this->label24->TabIndex = 32;
			this->label24->Text = L"g(x, u, u\') = a*a*sin(u) + b*sin(x)";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1506, 558);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zedGraphControl1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Численное решение задачи Коши для ОДУ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion 

		double du_test(double x, double u)
		{
			return u;
		}

		double f(double x)
		{
			return (x / (1 + x * x));
		}

		/*double g(double x, double u, double dudx)
		{
			double a = Convert::ToDouble(textBox1->Text);
			double b = Convert::ToDouble(textBox2->Text);
			return (a * a * sin(u) + b * sin(x));
		}*/

		double du_1(double x, double u)
		{
			return (f(x) * u * u + u - u * u * u * sin(10 * x));
		}

		/*double du_2(double x, double u)
		{

		}*/

		double RK_7_du_test(double x, double u, double h)
		{
			double k1 = du_test(x, u);
			double k2 = du_test(x + h / 2, u + (h / 2) * k1);
			double k3 = du_test(x + h / 2, u + (h / 2) * k2);
			double k4 = du_test(x + h, u + h * k3);
			return (u + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4));
		}

		double RK_7_du_1(double x, double u, double h)
		{
			double k1 = du_1(x, u);
			double k2 = du_1(x + h / 2, u + (h / 2) * k1);
			double k3 = du_1(x + h / 2, u + (h / 2) * k2);
			double k4 = du_1(x + h, u + h * k3);
			return (u + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4));
		}

		/*double RK_7_du_2(double x, double u, double h)
		{
			double k1 = du_2(x, u);
			double k2 = du_2(x + h / 2, u + (h / 2) * k1);
			double k3 = du_2(x + h / 2, u + (h / 2) * k2);
			double k4 = du_2(x + h, u + h * k3);
			return (u + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4));
		}*/

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		/*GraphPane^ panel = zedGraphControl1->GraphPane;
		panel->CurveList->Clear();
		PointPairList^ du_test_t_list = gcnew ZedGraph::PointPairList();
		PointPairList^ du_test_list = gcnew ZedGraph::PointPairList();
		PointPairList^ du_1_list = gcnew ZedGraph::PointPairList();

		double h = Convert::ToDouble(textBox4->Text);
		double b = Convert::ToDouble(textBox2->Text);
		double ee = Convert::ToDouble(textBox6->Text);
		int n = Convert::ToInt32(textBox5->Text);
		double u0 = Convert::ToDouble(textBox3->Text);
		double v_du_test = u0;
		double v_du_1 = u0;
		double v_du_test_p = u0;
		double x = 0.0;
		double max = 0.0;
		double s = 0.0;
		int c1 = 0;
		int c2 = 0;
		double u = u0 * exp(x);
		bool l = true;
		for (int i = 0; (i < n) && (x < b); i++)
		{	
			if (l)
			{
				dataGridView1->Rows->Add();
				dataGridView1->Rows[i]->Cells[0]->Value = i;
				dataGridView1->Rows[i]->Cells[1]->Value = x;
				dataGridView1->Rows[i]->Cells[2]->Value = v_du_test;
				dataGridView1->Rows[i]->Cells[5]->Value = s;
				dataGridView1->Rows[i]->Cells[6]->Value = h;
				dataGridView1->Rows[i]->Cells[7]->Value = c1;
				dataGridView1->Rows[i]->Cells[8]->Value = c2;
				dataGridView1->Rows[i]->Cells[9]->Value = u;
				dataGridView1->Rows[i]->Cells[10]->Value = fabs(u - v_du_test);
			}
			l = true;
			dataGridView2->Rows->Add();
			dataGridView2->Rows[i]->Cells[0]->Value = i;
			dataGridView2->Rows[i]->Cells[1]->Value = x;
			dataGridView2->Rows[i]->Cells[2]->Value = v_du_1;
			du_test_list->Add(x, v_du_test);
			du_1_list->Add(x, v_du_1);
			
			du_test_t_list->Add(x, u); 
			v_du_test = RK_7_du_test(x, v_du_test, h);
			v_du_1 = RK_7_du_1(x, v_du_1, h);

			x = x + h;	
			u = u0 * exp(x);
			if (checkBox1->Checked)
			{
				double x2 = x + h / 2.0;
				double v2 = RK_7_du_test(x, v_du_test, h / 2.0);
				s = (RK_7_du_test(x2, v2, h / 2.0) - v_du_test) / 15.0;
				if ((ee / 32.0) > fabs(s))
				{
					h = h * 2.0;
					c1++;
				}
				else
					if (fabs(s) > ee)
					{
						l = false;
						h = h / 2.0;
						c2++;
					}
			}


			if (max < fabs(u - v_du_test))
				max = fabs(u - v_du_test);
		}
		label13->Text = "Max uncorrect: " + Convert::ToString(max);
		LineItem Curve1 = panel->AddCurve("du_test", du_test_list, Color::Red, SymbolType::Plus);
		LineItem Curve2 = panel->AddCurve("du_1", du_1_list, Color::Blue, SymbolType::None);
		LineItem Curve4 = panel->AddCurve("du_t_test", du_test_t_list, Color::Green, SymbolType::Circle);
		
		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
*/
		dataGridView1->Rows->Clear();
		GraphPane^ panel = zedGraphControl1->GraphPane;
		panel->CurveList->Clear();
		PointPairList^ du_test_t_list = gcnew ZedGraph::PointPairList();
		PointPairList^ du_test_list = gcnew ZedGraph::PointPairList();

		double b = Convert::ToDouble(textBox2->Text);
		double u0 = Convert::ToDouble(textBox3->Text);
		double h = Convert::ToDouble(textBox4->Text);
		int n = Convert::ToInt32(textBox5->Text);
		double ee = Convert::ToDouble(textBox6->Text);

		double x = 0.0;
		double u = u0 * exp(x);
		double v_test = u0;
		double v2_test = u0;
		double s = 0.0;
		int c1 = 0;
		int c2 = 0;
		int i = 0;
		double maxee = 0.0;
		double maxs = s;
		double maxh = h;
		double minh = h;
		int k = 0;
		
		if (checkBox1->Checked)
		{
			dataGridView1->Rows->Add();
			dataGridView1->Rows[0]->Cells[0]->Value = 0;
			dataGridView1->Rows[0]->Cells[1]->Value = x;
			dataGridView1->Rows[0]->Cells[2]->Value = v_test;
			dataGridView1->Rows[0]->Cells[3]->Value = v2_test;
			dataGridView1->Rows[0]->Cells[4]->Value = fabs(v_test - v2_test);
			dataGridView1->Rows[0]->Cells[5]->Value = s;
			dataGridView1->Rows[0]->Cells[6]->Value = h;
			dataGridView1->Rows[0]->Cells[7]->Value = c1;
			dataGridView1->Rows[0]->Cells[8]->Value = c2;
			dataGridView1->Rows[0]->Cells[9]->Value = u;
			dataGridView1->Rows[0]->Cells[10]->Value = fabs(u - v_test);

			du_test_t_list->Add(x, u);
			du_test_list->Add(x, v_test);

			for (i = 0; (i < n) && (x < b); i++)
			{
				double x2 = x + h / 2.0;
				double v2 = RK_7_du_test(x, v_test, h / 2.0);
				double vn = RK_7_du_test(x, v_test, h);
				s = (RK_7_du_test(x2, v2, h / 2.0) - vn) / 15.0;
				if ((ee / 32.0) > fabs(s))
				{
					v2_test = RK_7_du_test(x, v_test, h / 2.0);
					x = x + h;
					c1++;
					v_test = vn;
					k++;
					u = u0 * exp(x);

					if (maxee < fabs(u - v_test))
						maxee = fabs(u - v_test);
					if (maxs < s)
						maxs = s;
					if (maxh < h)
						maxh = h;
					if (minh > h)
						minh = h;

					dataGridView1->Rows->Add();
					dataGridView1->Rows[k]->Cells[0]->Value = k;
					dataGridView1->Rows[k]->Cells[1]->Value = x;
					dataGridView1->Rows[k]->Cells[2]->Value = v_test;
					dataGridView1->Rows[k]->Cells[3]->Value = v2_test;
					dataGridView1->Rows[k]->Cells[4]->Value = fabs(v_test - v2_test);
					dataGridView1->Rows[k]->Cells[5]->Value = s;
					dataGridView1->Rows[k]->Cells[6]->Value = h;
					dataGridView1->Rows[k]->Cells[7]->Value = c1;
					dataGridView1->Rows[k]->Cells[8]->Value = c2;
					dataGridView1->Rows[k]->Cells[9]->Value = u;
					dataGridView1->Rows[k]->Cells[10]->Value = fabs(u - v_test);

					du_test_t_list->Add(x, u);
					du_test_list->Add(x, v_test);

					h = h * 2.0;
				}
				else
					if (fabs(s) > ee)
					{
						h = h / 2.0;
						c2++;
					}
					else
					{
						v2_test = RK_7_du_test(x, v_test, h / 2.0);
						x = x + h;
						v_test = vn;
						k++;
						u = u0 * exp(x);

						if (maxee < fabs(u - v_test))
							maxee = fabs(u - v_test);
						if (maxs < s)
							maxs = s;
						if (maxh < h)
							maxh = h;
						if (minh > h)
							minh = h;

						dataGridView1->Rows->Add();
						dataGridView1->Rows[k]->Cells[0]->Value = k;
						dataGridView1->Rows[k]->Cells[1]->Value = x;
						dataGridView1->Rows[k]->Cells[2]->Value = v_test;
						dataGridView1->Rows[k]->Cells[3]->Value = v2_test;
						dataGridView1->Rows[k]->Cells[4]->Value = fabs(v_test - v2_test);
						dataGridView1->Rows[k]->Cells[5]->Value = s;
						dataGridView1->Rows[k]->Cells[6]->Value = h;
						dataGridView1->Rows[k]->Cells[7]->Value = c1;
						dataGridView1->Rows[k]->Cells[8]->Value = c2;
						dataGridView1->Rows[k]->Cells[9]->Value = u;
						dataGridView1->Rows[k]->Cells[10]->Value = fabs(u - v_test);

						du_test_t_list->Add(x, u);
						du_test_list->Add(x, v_test);
					}
			}
		}
		else
		{
			dataGridView1->Rows->Add();
			dataGridView1->Rows[0]->Cells[0]->Value = 0;
			dataGridView1->Rows[0]->Cells[1]->Value = x;
			dataGridView1->Rows[0]->Cells[2]->Value = v_test;
			dataGridView1->Rows[0]->Cells[3]->Value = v2_test;
			dataGridView1->Rows[0]->Cells[4]->Value = fabs(v_test - v2_test);
			dataGridView1->Rows[0]->Cells[5]->Value = s;
			dataGridView1->Rows[0]->Cells[6]->Value = h;
			dataGridView1->Rows[0]->Cells[7]->Value = c1;
			dataGridView1->Rows[0]->Cells[8]->Value = c2;
			dataGridView1->Rows[0]->Cells[9]->Value = u;
			dataGridView1->Rows[0]->Cells[10]->Value = fabs(u - v_test);

			du_test_t_list->Add(x, u);
			du_test_list->Add(x, v_test);

			for (i = 0; (i < n) && (x < b); i++)
			{
				v2_test = RK_7_du_test(x, v_test, h / 2.0);
				v_test = RK_7_du_test(x, v_test, h);

				x = x + h;
				u = u0 * exp(x);
				k++;

				if (maxee < fabs(u - v_test))
					maxee = fabs(u - v_test);

				dataGridView1->Rows->Add();
				dataGridView1->Rows[k]->Cells[0]->Value = k;
				dataGridView1->Rows[k]->Cells[1]->Value = x;
				dataGridView1->Rows[k]->Cells[2]->Value = v_test;
				dataGridView1->Rows[k]->Cells[3]->Value = v2_test;
				dataGridView1->Rows[k]->Cells[4]->Value = fabs(v_test - v2_test);
				dataGridView1->Rows[k]->Cells[5]->Value = s;
				dataGridView1->Rows[k]->Cells[6]->Value = h;
				dataGridView1->Rows[k]->Cells[7]->Value = c1;
				dataGridView1->Rows[k]->Cells[8]->Value = c2;
				dataGridView1->Rows[k]->Cells[9]->Value = u;
				dataGridView1->Rows[k]->Cells[10]->Value = fabs(u - v_test);

				du_test_t_list->Add(x, u);
				du_test_list->Add(x, v_test);
			}
		}

		label13->Text = "Max uncorrect: " + Convert::ToString(maxee);
		label4->Text = "Max OLP: " + Convert::ToString(maxs);
		label5->Text = "Summ C1: " + Convert::ToString(c1);
		label6->Text = "Summ C2: " + Convert::ToString(c2);
		label14->Text = "Max h: " + Convert::ToString(maxh);
		label15->Text = "Min h: " + Convert::ToString(minh);
		label16->Text = "n = " + Convert::ToString(k);
		label17->Text = "b - xn = " + Convert::ToString(b - x);

		LineItem Curve1 = panel->AddCurve("du_t_test", du_test_t_list, Color::Red, SymbolType::Plus);
		LineItem Curve2 = panel->AddCurve("du_test", du_test_list, Color::Blue, SymbolType::Circle);

		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
	}

private: System::Void zedGraphControl1_Load(System::Object^  sender, System::EventArgs^  e) {}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {}
};
}