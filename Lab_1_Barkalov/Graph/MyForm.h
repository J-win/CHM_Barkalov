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
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
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
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Label^  label1;
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
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
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
			this->zedGraphControl1->GraphPane->XAxis->Title->Text = "x";
			this->zedGraphControl1->GraphPane->YAxis->Title->Text = "u";
			this->zedGraphControl1->GraphPane->Title->Text = "Графики задач";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(277, 452);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 60);
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 346);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(152, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Правая граница для х";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(210, 343);
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
			this->label3->Size = System::Drawing::Size(168, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Начальная значение u0";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(210, 376);
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
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(33, 418);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(131, 17);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Начальный шаг h0";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(210, 413);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(60, 22);
			this->textBox4->TabIndex = 15;
			this->textBox4->Text = L"0,1";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(33, 452);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(45, 17);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Max n";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(210, 449);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(60, 22);
			this->textBox5->TabIndex = 17;
			this->textBox5->Text = L"100";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(33, 21);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(222, 17);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Тестовая задача имеет вид:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::Control;
			this->label10->Cursor = System::Windows::Forms::Cursors::Default;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label10->Location = System::Drawing::Point(17, 110);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(254, 17);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Основная задача №1 имеет вид:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(279, 431);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(129, 21);
			this->checkBox1->TabIndex = 21;
			this->checkBox1->Text = L"Контроль шага";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(33, 488);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(107, 17);
			this->label12->TabIndex = 22;
			this->label12->Text = L"Погрешность e";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(210, 485);
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
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(298, 420);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(59, 17);
			this->label17->TabIndex = 31;
			this->label17->Text = L"b - xn = ";
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
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(298, 403);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(50, 17);
			this->label15->TabIndex = 29;
			this->label15->Text = L"Min h: ";
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
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 437);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(66, 17);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Num C2: ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 420);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(66, 17);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Num C1: ";
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
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label34);
			this->tabPage2->Controls->Add(this->label33);
			this->tabPage2->Controls->Add(this->label32);
			this->tabPage2->Controls->Add(this->label31);
			this->tabPage2->Controls->Add(this->label30);
			this->tabPage2->Controls->Add(this->label29);
			this->tabPage2->Controls->Add(this->label28);
			this->tabPage2->Controls->Add(this->label27);
			this->tabPage2->Controls->Add(this->label26);
			this->tabPage2->Controls->Add(this->label25);
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(536, 500);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Основная задача №1";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(274, 439);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(32, 17);
			this->label34->TabIndex = 33;
			this->label34->Text = L"n = ";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(274, 421);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(59, 17);
			this->label33->TabIndex = 32;
			this->label33->Text = L"b - xn = ";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(274, 403);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(50, 17);
			this->label32->TabIndex = 30;
			this->label32->Text = L"Min h: ";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(274, 384);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(53, 17);
			this->label31->TabIndex = 29;
			this->label31->Text = L"Max h: ";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(3, 421);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(66, 17);
			this->label30->TabIndex = 28;
			this->label30->Text = L"Num C2: ";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(3, 403);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(66, 17);
			this->label29->TabIndex = 27;
			this->label29->Text = L"Num C1: ";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(3, 383);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(73, 17);
			this->label28->TabIndex = 26;
			this->label28->Text = L"Max OLP: ";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(247, 383);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(0, 17);
			this->label27->TabIndex = 15;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(29, 421);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(0, 17);
			this->label26->TabIndex = 14;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(26, 384);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(0, 17);
			this->label25->TabIndex = 13;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(98, 38);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(66, 17);
			this->label18->TabIndex = 26;
			this->label18->Text = L"du/dx = u";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(33, 127);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(230, 17);
			this->label19->TabIndex = 27;
			this->label19->Text = L"du/dx = f(x)*u*u + u - u*u*u*sin(10x)";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(80, 144);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(105, 17);
			this->label20->TabIndex = 28;
			this->label20->Text = L"f(x) = x/(1 + x*x)";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(98, 161);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(66, 17);
			this->label21->TabIndex = 29;
			this->label21->Text = L"u(0) = u0";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Checked = true;
			this->checkBox2->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox2->Location = System::Drawing::Point(465, 431);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(143, 21);
			this->checkBox2->TabIndex = 33;
			this->checkBox2->Text = L"Тестовая задача";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(465, 458);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(172, 21);
			this->checkBox3->TabIndex = 34;
			this->checkBox3->Text = L"Основная задача №1";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(98, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 17);
			this->label1->TabIndex = 35;
			this->label1->Text = L"u(0) = u0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1506, 558);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->checkBox1);
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
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zedGraphControl1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Численное решение задачи Коши для ОДУ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
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

		double du_1(double x, double u)
		{
			return (f(x) * u * u + u - u * u * u * sin(10 * x));
		}

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

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {	

		dataGridView1->Rows->Clear();
		dataGridView2->Rows->Clear();
		GraphPane^ panel = zedGraphControl1->GraphPane;
		panel->XAxis->Title->Text = "x";
		panel->YAxis->Title->Text = "u";
		panel->Title->Text = "Графики задач";
		panel->CurveList->Clear();
		PointPairList^ du_test_t_list = gcnew ZedGraph::PointPairList();
		PointPairList^ du_test_list = gcnew ZedGraph::PointPairList();
		PointPairList^ du_1_list = gcnew ZedGraph::PointPairList();

		double b = Convert::ToDouble(textBox2->Text);
		double u0 = Convert::ToDouble(textBox3->Text);
		double h0 = Convert::ToDouble(textBox4->Text);
		int n = Convert::ToInt32(textBox5->Text);
		double ee = Convert::ToDouble(textBox6->Text);
		double x0 = 0.0;

		if (checkBox2->Checked)
		{
			double x = x0;
			double h = h0;
			double u = u0 * exp(x);
			double v = u0;
			double v2 = u0;
			double s = 0.0;
			int c1 = 0;
			int c2 = 0;
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
				dataGridView1->Rows[0]->Cells[2]->Value = v;
				dataGridView1->Rows[0]->Cells[3]->Value = v2;
				dataGridView1->Rows[0]->Cells[4]->Value = fabs(v - v2);
				dataGridView1->Rows[0]->Cells[5]->Value = s;
				dataGridView1->Rows[0]->Cells[6]->Value = h;
				dataGridView1->Rows[0]->Cells[7]->Value = c1;
				dataGridView1->Rows[0]->Cells[8]->Value = c2;
				dataGridView1->Rows[0]->Cells[9]->Value = u;
				dataGridView1->Rows[0]->Cells[10]->Value = fabs(u - v);

				du_test_t_list->Add(x, u);
				du_test_list->Add(x, v);

				for (int i = 0; (i < n) && (x + h < b); i++)
				{
					double x12 = x + h / 2.0;
					double v12 = RK_7_du_test(x, v, h / 2.0);
					double vn = RK_7_du_test(x, v, h);
					s = (RK_7_du_test(x12, v12, h / 2.0) - vn) / 15.0;
					if ((ee / 32.0) > fabs(s))
					{
						v2 = RK_7_du_test(x, v, h / 2.0);
						x = x + h;
						c1++;
						v = vn;
						k++;
						u = u0 * exp(x);

						if (maxee < fabs(u - v))
							maxee = fabs(u - v);
						if (maxs < fabs(s))
							maxs = fabs(s);
						if (maxh < h)
							maxh = h;
						if (minh > h)
							minh = h;

						dataGridView1->Rows->Add();
						dataGridView1->Rows[k]->Cells[0]->Value = k;
						dataGridView1->Rows[k]->Cells[1]->Value = x;
						dataGridView1->Rows[k]->Cells[2]->Value = v;
						dataGridView1->Rows[k]->Cells[3]->Value = v2;
						dataGridView1->Rows[k]->Cells[4]->Value = fabs(v - v2);
						dataGridView1->Rows[k]->Cells[5]->Value = s;
						dataGridView1->Rows[k]->Cells[6]->Value = h;
						dataGridView1->Rows[k]->Cells[7]->Value = c1;
						dataGridView1->Rows[k]->Cells[8]->Value = c2;
						dataGridView1->Rows[k]->Cells[9]->Value = u;
						dataGridView1->Rows[k]->Cells[10]->Value = fabs(u - v);

						du_test_t_list->Add(x, u);
						du_test_list->Add(x, v);

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
							v2 = RK_7_du_test(x, v, h / 2.0);
							x = x + h;
							v = vn;
							k++;
							u = u0 * exp(x);

							if (maxee < fabs(u - v))
								maxee = fabs(u - v);
							if (maxs < fabs(s))
								maxs = fabs(s);
							if (maxh < h)
								maxh = h;
							if (minh > h)
								minh = h;

							dataGridView1->Rows->Add();
							dataGridView1->Rows[k]->Cells[0]->Value = k;
							dataGridView1->Rows[k]->Cells[1]->Value = x;
							dataGridView1->Rows[k]->Cells[2]->Value = v;
							dataGridView1->Rows[k]->Cells[3]->Value = v2;
							dataGridView1->Rows[k]->Cells[4]->Value = fabs(v - v2);
							dataGridView1->Rows[k]->Cells[5]->Value = s;
							dataGridView1->Rows[k]->Cells[6]->Value = h;
							dataGridView1->Rows[k]->Cells[7]->Value = c1;
							dataGridView1->Rows[k]->Cells[8]->Value = c2;
							dataGridView1->Rows[k]->Cells[9]->Value = u;
							dataGridView1->Rows[k]->Cells[10]->Value = fabs(u - v);

							du_test_t_list->Add(x, u);
							du_test_list->Add(x, v);
						}
				}
			}
			else
			{
				dataGridView1->Rows->Add();
				dataGridView1->Rows[0]->Cells[0]->Value = 0;
				dataGridView1->Rows[0]->Cells[1]->Value = x;
				dataGridView1->Rows[0]->Cells[2]->Value = v;
				dataGridView1->Rows[0]->Cells[3]->Value = v2;
				dataGridView1->Rows[0]->Cells[4]->Value = fabs(v - v2);
				dataGridView1->Rows[0]->Cells[5]->Value = s;
				dataGridView1->Rows[0]->Cells[6]->Value = h;
				dataGridView1->Rows[0]->Cells[7]->Value = c1;
				dataGridView1->Rows[0]->Cells[8]->Value = c2;
				dataGridView1->Rows[0]->Cells[9]->Value = u;
				dataGridView1->Rows[0]->Cells[10]->Value = fabs(u - v);

				du_test_t_list->Add(x, u);
				du_test_list->Add(x, v);

				for (int i = 0; (i < n) && (x + h < b); i++)
				{
					v2 = RK_7_du_test(x, v, h / 2.0);
					v = RK_7_du_test(x, v, h);

					x = x + h;
					u = u0 * exp(x);
					k++;

					if (maxee < fabs(u - v))
						maxee = fabs(u - v);

					dataGridView1->Rows->Add();
					dataGridView1->Rows[k]->Cells[0]->Value = k;
					dataGridView1->Rows[k]->Cells[1]->Value = x;
					dataGridView1->Rows[k]->Cells[2]->Value = v;
					dataGridView1->Rows[k]->Cells[3]->Value = v2;
					dataGridView1->Rows[k]->Cells[4]->Value = fabs(v - v2);
					dataGridView1->Rows[k]->Cells[5]->Value = s;
					dataGridView1->Rows[k]->Cells[6]->Value = h;
					dataGridView1->Rows[k]->Cells[7]->Value = c1;
					dataGridView1->Rows[k]->Cells[8]->Value = c2;
					dataGridView1->Rows[k]->Cells[9]->Value = u;
					dataGridView1->Rows[k]->Cells[10]->Value = fabs(u - v);

					du_test_t_list->Add(x, u);
					du_test_list->Add(x, v);
				}
			}

			label13->Text = "Max uncorrect: " + Convert::ToString(maxee);
			label4->Text = "Max OLP: " + Convert::ToString(maxs);
			label5->Text = "Num C1: " + Convert::ToString(c1);
			label6->Text = "Num C2: " + Convert::ToString(c2);
			label14->Text = "Max h: " + Convert::ToString(maxh);
			label15->Text = "Min h: " + Convert::ToString(minh);
			label16->Text = "n = " + Convert::ToString(k);
			label17->Text = "b - xn = " + Convert::ToString(b - x);

			LineItem Curve1 = panel->AddCurve("du_t_test", du_test_t_list, Color::Red, SymbolType::Plus);
			LineItem Curve2 = panel->AddCurve("du_test", du_test_list, Color::Blue, SymbolType::Circle);
		}

		if (checkBox3->Checked)
		{
			double x = x0;
			double h = h0;
			double v = u0;
			double v2 = u0;
			double s = 0.0;
			int c1 = 0;
			int c2 = 0;
			double maxs = s;
			double maxh = h;
			double minh = h;
			int k = 0;

			if (checkBox1->Checked)
			{
				dataGridView2->Rows->Add();
				dataGridView2->Rows[0]->Cells[0]->Value = 0;
				dataGridView2->Rows[0]->Cells[1]->Value = x;
				dataGridView2->Rows[0]->Cells[2]->Value = v;
				dataGridView2->Rows[0]->Cells[3]->Value = v2;
				dataGridView2->Rows[0]->Cells[4]->Value = fabs(v - v2);
				dataGridView2->Rows[0]->Cells[5]->Value = s;
				dataGridView2->Rows[0]->Cells[6]->Value = h;
				dataGridView2->Rows[0]->Cells[7]->Value = c1;
				dataGridView2->Rows[0]->Cells[8]->Value = c2;

				du_1_list->Add(x, v);

				for (int i = 0; (i < n) && (x + h < b); i++)
				{
					double x12 = x + h / 2.0;
					double v12 = RK_7_du_1(x, v, h / 2.0);
					double vn = RK_7_du_1(x, v, h);
					s = (RK_7_du_1(x12, v12, h / 2.0) - vn) / 15.0;
					if ((ee / 32.0) > fabs(s))
					{
						v2 = RK_7_du_1(x, v, h / 2.0);
						x = x + h;
						c1++;
						v = vn;
						k++;

						if (maxs < fabs(s))
							maxs = fabs(s);
						if (maxh < h)
							maxh = h;
						if (minh > h)
							minh = h;

						dataGridView2->Rows->Add();
						dataGridView2->Rows[k]->Cells[0]->Value = k;
						dataGridView2->Rows[k]->Cells[1]->Value = x;
						dataGridView2->Rows[k]->Cells[2]->Value = v;
						dataGridView2->Rows[k]->Cells[3]->Value = v2;
						dataGridView2->Rows[k]->Cells[4]->Value = fabs(v - v2);
						dataGridView2->Rows[k]->Cells[5]->Value = s;
						dataGridView2->Rows[k]->Cells[6]->Value = h;
						dataGridView2->Rows[k]->Cells[7]->Value = c1;
						dataGridView2->Rows[k]->Cells[8]->Value = c2;

						du_1_list->Add(x, v);

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
							v2 = RK_7_du_1(x, v, h / 2.0);
							x = x + h;
							v = vn;
							k++;

							if (maxs < fabs(s))
								maxs = fabs(s);
							if (maxh < h)
								maxh = h;
							if (minh > h)
								minh = h;

							dataGridView2->Rows->Add();
							dataGridView2->Rows[k]->Cells[0]->Value = k;
							dataGridView2->Rows[k]->Cells[1]->Value = x;
							dataGridView2->Rows[k]->Cells[2]->Value = v;
							dataGridView2->Rows[k]->Cells[3]->Value = v2;
							dataGridView2->Rows[k]->Cells[4]->Value = fabs(v - v2);
							dataGridView2->Rows[k]->Cells[5]->Value = s;
							dataGridView2->Rows[k]->Cells[6]->Value = h;
							dataGridView2->Rows[k]->Cells[7]->Value = c1;
							dataGridView2->Rows[k]->Cells[8]->Value = c2;

							du_1_list->Add(x, v);
						}
				}
			}
			else
			{
				dataGridView2->Rows->Add();
				dataGridView2->Rows[0]->Cells[0]->Value = 0;
				dataGridView2->Rows[0]->Cells[1]->Value = x;
				dataGridView2->Rows[0]->Cells[2]->Value = v;
				dataGridView2->Rows[0]->Cells[3]->Value = v2;
				dataGridView2->Rows[0]->Cells[4]->Value = fabs(v - v2);
				dataGridView2->Rows[0]->Cells[5]->Value = s;
				dataGridView2->Rows[0]->Cells[6]->Value = h;
				dataGridView2->Rows[0]->Cells[7]->Value = c1;
				dataGridView2->Rows[0]->Cells[8]->Value = c2;

				du_1_list->Add(x, v);

				for (int i = 0; (i < n) && (x + h < b); i++)
				{
					v2 = RK_7_du_1(x, v, h / 2.0);
					v = RK_7_du_1(x, v, h);

					x = x + h;
					k++;

					dataGridView2->Rows->Add();
					dataGridView2->Rows[k]->Cells[0]->Value = k;
					dataGridView2->Rows[k]->Cells[1]->Value = x;
					dataGridView2->Rows[k]->Cells[2]->Value = v;
					dataGridView2->Rows[k]->Cells[3]->Value = v2;
					dataGridView2->Rows[k]->Cells[4]->Value = fabs(v - v2);
					dataGridView2->Rows[k]->Cells[5]->Value = s;
					dataGridView2->Rows[k]->Cells[6]->Value = h;
					dataGridView2->Rows[k]->Cells[7]->Value = c1;
					dataGridView2->Rows[k]->Cells[8]->Value = c2;

					du_1_list->Add(x, v);
				}
			}

			label28->Text = "Max OLP: " + Convert::ToString(maxs);
			label29->Text = "Num C1: " + Convert::ToString(c1);
			label30->Text = "Num C2: " + Convert::ToString(c2);
			label31->Text = "Max h: " + Convert::ToString(maxh);
			label32->Text = "Min h: " + Convert::ToString(minh);
			label34->Text = "n = " + Convert::ToString(k);
			label33->Text = "b - xn = " + Convert::ToString(b - x);

			LineItem Curve3 = panel->AddCurve("du_1", du_1_list, Color::Green, SymbolType::Star);
		}

		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
	}
};
}