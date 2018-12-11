#pragma once
#include <math.h>

struct sistema {
	double u;
	double du;
	sistema(const double u_ = 0, const double du_ = 0) {
		u = u_;
		du = du_;
	}
	sistema(const sistema &z) {
		u = z.u;
		du = z.du;
	}
	sistema& operator=(const sistema &z) {
		u = z.u;
		du = z.du;
		return *this;
	}
	sistema operator+(const sistema &z) const {
		return (sistema(u + z.u, du + z.du));
	}
	sistema operator-(const sistema &z) const {
		return (sistema(u - z.u, du - z.du));
	}
	sistema operator*(const double x) const {
		return (sistema(u * x, du * x));
	}
	sistema operator/(const double x) const {
		return (sistema(u / x, du / x));
	}
};
sistema operator*(const double x, const sistema &z) {
	return (z * x);
}

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
	private: System::Windows::Forms::TabControl^  tabControl2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: System::Windows::Forms::TabPage^  tabPage7;
	private: System::Windows::Forms::TabPage^  tabPage8;
	private: System::Windows::Forms::DataGridView^  dataGridView3;









private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::Label^  label40;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::Label^  label38;
private: System::Windows::Forms::Label^  label37;
private: ZedGraph::ZedGraphControl^  zedGraphControl2;
private: ZedGraph::ZedGraphControl^  zedGraphControl3;
private: ZedGraph::ZedGraphControl^  zedGraphControl4;
private: ZedGraph::ZedGraphControl^  zedGraphControl5;
private: System::Windows::Forms::CheckBox^  checkBox4;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::TextBox^  textBox7;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::TextBox^  textBox8;








private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::TextBox^  textBox9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column12;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column13;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column14;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column15;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column16;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn9;

















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
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl2 = (gcnew ZedGraph::ZedGraphControl());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl3 = (gcnew ZedGraph::ZedGraphControl());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl4 = (gcnew ZedGraph::ZedGraphControl());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl5 = (gcnew ZedGraph::ZedGraphControl());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->tabControl2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->SuspendLayout();
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(0, 0);
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
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(283, 452);
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
			this->dataGridView1->Size = System::Drawing::Size(961, 377);
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
			this->label3->Location = System::Drawing::Point(33, 378);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(168, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Начальная значение u0";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(210, 375);
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
			this->dataGridView2->Size = System::Drawing::Size(965, 377);
			this->dataGridView2->TabIndex = 12;
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
			this->label10->Location = System::Drawing::Point(15, 85);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(254, 17);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Основная задача №1 имеет вид:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(691, 456);
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
			this->tabControl1->Controls->Add(this->tabPage8);
			this->tabControl1->Location = System::Drawing::Point(955, 21);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(969, 529);
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
			this->tabPage1->Size = System::Drawing::Size(961, 500);
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
			this->tabPage2->Size = System::Drawing::Size(961, 500);
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
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->label43);
			this->tabPage8->Controls->Add(this->label42);
			this->tabPage8->Controls->Add(this->label41);
			this->tabPage8->Controls->Add(this->label40);
			this->tabPage8->Controls->Add(this->label39);
			this->tabPage8->Controls->Add(this->label38);
			this->tabPage8->Controls->Add(this->label37);
			this->tabPage8->Controls->Add(this->dataGridView3);
			this->tabPage8->Location = System::Drawing::Point(4, 25);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(961, 500);
			this->tabPage8->TabIndex = 2;
			this->tabPage8->Text = L"Основная задача №2";
			this->tabPage8->UseVisualStyleBackColor = true;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(303, 431);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(32, 17);
			this->label43->TabIndex = 34;
			this->label43->Text = L"n = ";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(303, 414);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(59, 17);
			this->label42->TabIndex = 33;
			this->label42->Text = L"b - xn = ";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(303, 396);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(50, 17);
			this->label41->TabIndex = 31;
			this->label41->Text = L"Min h: ";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(303, 379);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(53, 17);
			this->label40->TabIndex = 30;
			this->label40->Text = L"Max h: ";
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(6, 420);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(66, 17);
			this->label39->TabIndex = 29;
			this->label39->Text = L"Num C2: ";
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(6, 403);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(66, 17);
			this->label38->TabIndex = 28;
			this->label38->Text = L"Num C1: ";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(6, 381);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(73, 17);
			this->label37->TabIndex = 27;
			this->label37->Text = L"Max OLP: ";
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn6,
					this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9
			});
			this->dataGridView3->Location = System::Drawing::Point(0, 0);
			this->dataGridView3->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersVisible = false;
			this->dataGridView3->Size = System::Drawing::Size(965, 377);
			this->dataGridView3->TabIndex = 3;
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
			this->label19->Location = System::Drawing::Point(33, 102);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(230, 17);
			this->label19->TabIndex = 27;
			this->label19->Text = L"du/dx = f(x)*u*u + u - u*u*u*sin(10x)";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(80, 119);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(105, 17);
			this->label20->TabIndex = 28;
			this->label20->Text = L"f(x) = x/(1 + x*x)";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(98, 136);
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
			this->checkBox2->Location = System::Drawing::Point(465, 452);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(143, 21);
			this->checkBox2->TabIndex = 33;
			this->checkBox2->Text = L"Тестовая задача";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(465, 482);
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
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage3);
			this->tabControl2->Controls->Add(this->tabPage4);
			this->tabControl2->Controls->Add(this->tabPage5);
			this->tabControl2->Controls->Add(this->tabPage6);
			this->tabControl2->Controls->Add(this->tabPage7);
			this->tabControl2->Location = System::Drawing::Point(275, 14);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(677, 432);
			this->tabControl2->TabIndex = 36;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->zedGraphControl1);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(669, 403);
			this->tabPage3->TabIndex = 0;
			this->tabPage3->Text = L"Тестовая задача";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->zedGraphControl2);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(669, 403);
			this->tabPage4->TabIndex = 1;
			this->tabPage4->Text = L"Основная задача №1";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl2
			// 
			this->zedGraphControl2->Location = System::Drawing::Point(0, 0);
			this->zedGraphControl2->Margin = System::Windows::Forms::Padding(5);
			this->zedGraphControl2->Name = L"zedGraphControl2";
			this->zedGraphControl2->ScrollGrace = 0;
			this->zedGraphControl2->ScrollMaxX = 0;
			this->zedGraphControl2->ScrollMaxY = 0;
			this->zedGraphControl2->ScrollMaxY2 = 0;
			this->zedGraphControl2->ScrollMinX = 0;
			this->zedGraphControl2->ScrollMinY = 0;
			this->zedGraphControl2->ScrollMinY2 = 0;
			this->zedGraphControl2->Size = System::Drawing::Size(668, 402);
			this->zedGraphControl2->TabIndex = 1;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->zedGraphControl3);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(669, 403);
			this->tabPage5->TabIndex = 2;
			this->tabPage5->Text = L"Основная задача №2 Часть 1";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl3
			// 
			this->zedGraphControl3->Location = System::Drawing::Point(0, 0);
			this->zedGraphControl3->Margin = System::Windows::Forms::Padding(5);
			this->zedGraphControl3->Name = L"zedGraphControl3";
			this->zedGraphControl3->ScrollGrace = 0;
			this->zedGraphControl3->ScrollMaxX = 0;
			this->zedGraphControl3->ScrollMaxY = 0;
			this->zedGraphControl3->ScrollMaxY2 = 0;
			this->zedGraphControl3->ScrollMinX = 0;
			this->zedGraphControl3->ScrollMinY = 0;
			this->zedGraphControl3->ScrollMinY2 = 0;
			this->zedGraphControl3->Size = System::Drawing::Size(668, 402);
			this->zedGraphControl3->TabIndex = 1;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->zedGraphControl4);
			this->tabPage6->Location = System::Drawing::Point(4, 25);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(669, 403);
			this->tabPage6->TabIndex = 3;
			this->tabPage6->Text = L"Основная задача №2 Часть 2";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl4
			// 
			this->zedGraphControl4->Location = System::Drawing::Point(0, 0);
			this->zedGraphControl4->Margin = System::Windows::Forms::Padding(5);
			this->zedGraphControl4->Name = L"zedGraphControl4";
			this->zedGraphControl4->ScrollGrace = 0;
			this->zedGraphControl4->ScrollMaxX = 0;
			this->zedGraphControl4->ScrollMaxY = 0;
			this->zedGraphControl4->ScrollMaxY2 = 0;
			this->zedGraphControl4->ScrollMinX = 0;
			this->zedGraphControl4->ScrollMinY = 0;
			this->zedGraphControl4->ScrollMinY2 = 0;
			this->zedGraphControl4->Size = System::Drawing::Size(668, 402);
			this->zedGraphControl4->TabIndex = 1;
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->zedGraphControl5);
			this->tabPage7->Location = System::Drawing::Point(4, 25);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(669, 403);
			this->tabPage7->TabIndex = 4;
			this->tabPage7->Text = L"Основная задача №2 Часть 3";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl5
			// 
			this->zedGraphControl5->Location = System::Drawing::Point(0, 0);
			this->zedGraphControl5->Margin = System::Windows::Forms::Padding(5);
			this->zedGraphControl5->Name = L"zedGraphControl5";
			this->zedGraphControl5->ScrollGrace = 0;
			this->zedGraphControl5->ScrollMaxX = 0;
			this->zedGraphControl5->ScrollMaxY = 0;
			this->zedGraphControl5->ScrollMaxY2 = 0;
			this->zedGraphControl5->ScrollMinX = 0;
			this->zedGraphControl5->ScrollMinY = 0;
			this->zedGraphControl5->ScrollMinY2 = 0;
			this->zedGraphControl5->Size = System::Drawing::Size(668, 402);
			this->zedGraphControl5->TabIndex = 1;
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(465, 509);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(172, 21);
			this->checkBox4->TabIndex = 37;
			this->checkBox4->Text = L"Основная задача №2";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(9, 165);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(254, 17);
			this->label11->TabIndex = 38;
			this->label11->Text = L"Основная задача №2 имеет вид:";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(59, 182);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(157, 17);
			this->label22->TabIndex = 39;
			this->label22->Text = L"d2u/dx2 + g(x, u, u\') = 0";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(33, 199);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(208, 17);
			this->label23->TabIndex = 40;
			this->label23->Text = L"g(x, u, u\') = a*a*sin(u) + b*sin(x)";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(63, 216);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(138, 17);
			this->label24->TabIndex = 41;
			this->label24->Text = L"u(0) = u0, u\'(0) = u0\'";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(33, 254);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(86, 17);
			this->label35->TabIndex = 42;
			this->label35->Text = L"Параметр a";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(33, 282);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(86, 17);
			this->label36->TabIndex = 43;
			this->label36->Text = L"Параметр b";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(210, 251);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(60, 22);
			this->textBox1->TabIndex = 44;
			this->textBox1->Text = L"1";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(210, 279);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(60, 22);
			this->textBox7->TabIndex = 45;
			this->textBox7->Text = L"1";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(33, 510);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(146, 34);
			this->label44->TabIndex = 46;
			this->label44->Text = L"Погрешность выхода\r\nна правую границу x";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(210, 522);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(60, 22);
			this->textBox8->TabIndex = 47;
			this->textBox8->Text = L"0,1";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(33, 314);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(171, 17);
			this->label45->TabIndex = 48;
			this->label45->Text = L"Начальное значение u\'0";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(210, 309);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(60, 22);
			this->textBox9->TabIndex = 49;
			this->textBox9->Text = L"0";
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
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"i";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 50;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Xi";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Vi";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"V\'i";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 558);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->label45);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label44);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label36);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->tabControl2);
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
			this->tabPage8->ResumeLayout(false);
			this->tabPage8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->tabControl2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			this->tabPage7->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion 

		double du_test(double x, double u) {
			return u;
		}
		double f(double x) {
			return (x / (1 + x * x));
		}
		double g(double x, double u) {
			double a = Convert::ToDouble(textBox1->Text);
			double b = Convert::ToDouble(textBox7->Text);
			return (a * a * sin(u) + b * sin(x));
		}
		double du_1(double x, double u) {
			return (f(x) * u * u + u - u * u * u * sin(10 * x));
		}
		sistema du_2(double x, sistema z) {
			return (sistema(z.du, -1 * g(x, z.u)));
		}
		double RK_7_du_test(double x, double u, double h) {
			double k1 = du_test(x, u);
			double k2 = du_test(x + h / 2, u + (h / 2) * k1);
			double k3 = du_test(x + h / 2, u + (h / 2) * k2);
			double k4 = du_test(x + h, u + h * k3);
			return (u + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4));
		}
		double RK_7_du_1(double x, double u, double h) {
			double k1 = du_1(x, u);
			double k2 = du_1(x + h / 2, u + (h / 2) * k1);
			double k3 = du_1(x + h / 2, u + (h / 2) * k2);
			double k4 = du_1(x + h, u + h * k3);
			return (u + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4));
		}
		sistema RK_7_du_2(double x, sistema z, double h) {
			sistema k1 = du_2(x, z);
			sistema k2 = du_2(x + h / 2, z + (h / 2) * k1);
			sistema k3 = du_2(x + h / 2, z + (h / 2) * k2);
			sistema k4 = du_2(x + h, z + h * k3);
			return (z + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4));
		}
		void print_du_tab(int k, double x, double v, double v2, double s, double h, int c1, int c2) {
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
		}
		void print_du_tab2(int k, double x, sistema v, double s, double h, int c1, int c2) {
			dataGridView3->Rows->Add();
			dataGridView3->Rows[k]->Cells[0]->Value = k;
			dataGridView3->Rows[k]->Cells[1]->Value = x;
			dataGridView3->Rows[k]->Cells[2]->Value = v.u;
			dataGridView3->Rows[k]->Cells[3]->Value = v.du;
			dataGridView3->Rows[k]->Cells[4]->Value = s;
			dataGridView3->Rows[k]->Cells[5]->Value = h;
			dataGridView3->Rows[k]->Cells[6]->Value = c1;
			dataGridView3->Rows[k]->Cells[7]->Value = c2;
		}
		void print_du_test_tab(int k, double x, double v, double v2, double s, double h, int c1, int c2, double u) {
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
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {	
		dataGridView1->Rows->Clear();
		dataGridView2->Rows->Clear();
		GraphPane^ panel = zedGraphControl1->GraphPane;
		panel->CurveList->Clear();
		GraphPane^ panel2 = zedGraphControl2->GraphPane;
		panel2->CurveList->Clear();
		GraphPane^ panel3 = zedGraphControl3->GraphPane;
		panel3->CurveList->Clear();
		GraphPane^ panel4 = zedGraphControl4->GraphPane;
		panel4->CurveList->Clear();
		GraphPane^ panel5 = zedGraphControl5->GraphPane;
		panel5->CurveList->Clear();
		PointPairList^ du_test_t_list = gcnew ZedGraph::PointPairList();
		PointPairList^ du_test_list = gcnew ZedGraph::PointPairList();
		PointPairList^ du_1_list = gcnew ZedGraph::PointPairList();
		PointPairList^ du_2_v_list = gcnew ZedGraph::PointPairList();
		PointPairList^ du_2_dv_list = gcnew ZedGraph::PointPairList();
		PointPairList^ du_2_vdv_list = gcnew ZedGraph::PointPairList();
		double b = Convert::ToDouble(textBox2->Text);
		double u0 = Convert::ToDouble(textBox3->Text);
		double du0 = Convert::ToDouble(textBox9->Text);
		double h0 = Convert::ToDouble(textBox4->Text);
		int n = Convert::ToInt32(textBox5->Text);
		double ee = Convert::ToDouble(textBox6->Text);
		double ex = Convert::ToDouble(textBox8->Text);
		double x0 = 0.0;
		if (checkBox2->Checked) {
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
			int i = 0;
			if (checkBox1->Checked) {
				print_du_test_tab(0, x, v, v2, s, h, c1, c2, u);
				du_test_t_list->Add(x, u);
				du_test_list->Add(x, v);
				for (i = 0; (i < n) && (x + h < b); i++) {
					double x12 = x + h / 2.0;
					double v12 = RK_7_du_test(x, v, h / 2.0);
					double vn = RK_7_du_test(x, v, h);
					s = (RK_7_du_test(x12, v12, h / 2.0) - vn) / 15.0;
					if ((ee / 32.0) > fabs(s)) {
						v2 = RK_7_du_test(x, v, h / 2.0);
						x = x + h;
						c2++;
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
						print_du_test_tab(k, x, v, v2, s, h, c1, c2, u);
						du_test_t_list->Add(x, u);
						du_test_list->Add(x, v);
						h = h * 2.0;
					} else
						if (fabs(s) > ee) {
							h = h / 2.0;
							c1++;
						} else {
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
							print_du_test_tab(k, x, v, v2, s, h, c1, c2, u);
							du_test_t_list->Add(x, u);
							du_test_list->Add(x, v);
						}
				}
				while ((i < n) && (fabs(b - x) > ex)) {
					if (x + h > b) {
						h = h / 2;
						c1++;
					} else {
						v = RK_7_du_test(x, v, h);
						v2 = RK_7_du_test(x, v, h / 2.0);
						x = x + h;
						u = u0 * exp(x);
						k++;
						if (minh > h)
							minh = h;
						print_du_test_tab(k, x, v, v2, s, h, c1, c2, u);
						du_test_t_list->Add(x, u);
						du_test_list->Add(x, v);
					}
					i++;
				}
			} else {
				print_du_test_tab(0, x, v, v2, s, h, c1, c2, u);
				du_test_t_list->Add(x, u);
				du_test_list->Add(x, v);
				for (i = 0; (i < n) && (x + h < b); i++) {
					v2 = RK_7_du_test(x, v, h / 2.0);
					v = RK_7_du_test(x, v, h);
					x = x + h;
					u = u0 * exp(x);
					k++;
					if (maxee < fabs(u - v))
						maxee = fabs(u - v);
					print_du_test_tab(k, x, v, v2, s, h, c1, c2, u);
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
		if (checkBox3->Checked) {
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
			int i = 0;
			if (checkBox1->Checked) {
				print_du_tab(0, x, v, v2, s, h, c1, c2);
				du_1_list->Add(x, v);
				for (i = 0; (i < n) && (x + h < b); i++) {
					double x12 = x + h / 2.0;
					double v12 = RK_7_du_1(x, v, h / 2.0);
					double vn = RK_7_du_1(x, v, h);
					s = (RK_7_du_1(x12, v12, h / 2.0) - vn) / 15.0;
					if ((ee / 32.0) > fabs(s)) {
						v2 = RK_7_du_1(x, v, h / 2.0);
						x = x + h;
						c2++;
						v = vn;
						k++;
						if (maxs < fabs(s))
							maxs = fabs(s);
						if (maxh < h)
							maxh = h;
						if (minh > h)
							minh = h;
						print_du_tab(k, x, v, v2, s, h, c1, c2);
						du_1_list->Add(x, v);
						h = h * 2.0;
					} else
						if (fabs(s) > ee) {
							h = h / 2.0;
							c1++;
						} else {
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
							print_du_tab(k, x, v, v2, s, h, c1, c2);
							du_1_list->Add(x, v);
						}
				}
				while ((i < n) && (fabs(b - x) > ex)) {
					if (x + h > b) {
						h = h / 2;
						c1++;
					} else {
						v = RK_7_du_1(x, v, h);
						v2 = RK_7_du_1(x, v, h / 2.0);
						x = x + h;
						k++;
						if (minh > h)
							minh = h;
						print_du_tab(k, x, v, v2, s, h, c1, c2);
						du_1_list->Add(x, v);
					}
					i++;
				}
			} else {
				print_du_tab(0, x, v, v2, s, h, c1, c2);
				du_1_list->Add(x, v);
				for (i = 0; (i < n) && (x + h < b); i++) {
					v2 = RK_7_du_1(x, v, h / 2.0);
					v = RK_7_du_1(x, v, h);
					x = x + h;
					k++;
					print_du_tab(k, x, v, v2, s, h, c1, c2);
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
			LineItem Curve3 = panel2->AddCurve("du_1", du_1_list, Color::Green, SymbolType::Star);
		}
		if (checkBox4->Checked) {
			double x = x0;
			double h = h0;
			sistema v(u0, du0);
			double s = 0.0;
			int c1 = 0;
			int c2 = 0;
			double maxs = s;
			double maxh = h;
			double minh = h;
			int k = 0;
			int i = 0;
			if (checkBox1->Checked) {
				print_du_tab2(0, x, v, s, h, c1, c2);
				du_2_v_list->Add(x, v.u);
				du_2_dv_list->Add(x, v.du);
				du_2_vdv_list->Add(v.u, v.du);
				for (i = 0; (i < n) && (x + h < b); i++) {
					double x12 = x + h / 2.0;
					sistema v12 = RK_7_du_2(x, v, h / 2.0);
					sistema vn = RK_7_du_2(x, v, h);
					sistema ss = (RK_7_du_2(x12, v12, h / 2.0) - vn) / 15.0;
					s = sqrt(ss.u * ss.u + ss.du * ss.du);
					if ((ee / 32.0) > fabs(s)) {
						x = x + h;
						c2++;
						v = vn;
						k++;
						if (maxs < fabs(s))
							maxs = fabs(s);
						if (maxh < h)
							maxh = h;
						if (minh > h)
							minh = h;
						print_du_tab2(k, x, v, s, h, c1, c2);
						du_2_v_list->Add(x, v.u);
						du_2_dv_list->Add(x, v.du);
						du_2_vdv_list->Add(v.u, v.du);
						h = h * 2.0;
					} else
						if (fabs(s) > ee) {
							h = h / 2.0;
							c1++;
						} else {
							x = x + h;
							v = vn;
							k++;
							if (maxs < fabs(s))
								maxs = fabs(s);
							if (maxh < h)
								maxh = h;
							if (minh > h)
								minh = h;
							print_du_tab2(k, x, v, s, h, c1, c2);
							du_2_v_list->Add(x, v.u);
							du_2_dv_list->Add(x, v.du);
							du_2_vdv_list->Add(v.u, v.du);
						}
				}
			} else {
				print_du_tab2(0, x, v, s, h, c1, c2);
				du_2_v_list->Add(x, v.u);
				du_2_dv_list->Add(x, v.du);
				du_2_vdv_list->Add(v.u, v.du);
				for (i = 0; (i < n) && (x + h < b); i++) {
					v = RK_7_du_2(x, v, h);
					x = x + h;
					k++;
					print_du_tab2(k, x, v, s, h, c1, c2);
					du_2_v_list->Add(x, v.u);
					du_2_dv_list->Add(x, v.du);
					du_2_vdv_list->Add(v.u, v.du);
				}
			}
			label37->Text = "Max OLP: " + Convert::ToString(maxs);
			label38->Text = "Num C1: " + Convert::ToString(c1);
			label39->Text = "Num C2: " + Convert::ToString(c2);
			label40->Text = "Max h: " + Convert::ToString(maxh);
			label41->Text = "Min h: " + Convert::ToString(minh);
			label43->Text = "n = " + Convert::ToString(k);
			label42->Text = "b - xn = " + Convert::ToString(b - x);
			LineItem Curve4 = panel3->AddCurve("du_2_v", du_2_v_list, Color::Green, SymbolType::None);
			LineItem Curve5 = panel4->AddCurve("du_2_dv", du_2_dv_list, Color::Green, SymbolType::None);
			LineItem Curve6 = panel5->AddCurve("du_2_vdv", du_2_vdv_list, Color::Green, SymbolType::None);
		}
		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
		zedGraphControl2->AxisChange();
		zedGraphControl2->Invalidate();
		zedGraphControl3->AxisChange();
		zedGraphControl3->Invalidate();
		zedGraphControl4->AxisChange();
		zedGraphControl4->Invalidate();
		zedGraphControl5->AxisChange();
		zedGraphControl5->Invalidate();
	}
};
}