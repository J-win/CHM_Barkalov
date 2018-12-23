#pragma once
#include <math.h>

struct polinom {
	double a, b, c;
	polinom(double a_ = 0.0, double b_ = 0.0, double c_ = 0.0) {
		a = a_;
		b = b_;
		c = c_;
	}
	polinom(const polinom &p) {
		a = p.a;
		b = p.b;
		c = p.c;
	}
	~polinom() {}
	double solution(const double x) {
		return (a * x * x + b * x + c);
	}
	polinom& operator=(const polinom &p) {
		a = p.a;
		b = p.b;
		c = p.c;
		return *this;
	}
	polinom operator+(const polinom &p) const {
		return polinom(a + p.a, b + p.b, c + p.c);
	}
	polinom operator-(const polinom &p) const {
		return polinom(a - p.a, b - p.b, c - p.c);
	}
	polinom operator*(const double q) const {
		return polinom(a * q, b * q, c * q);
	}
	polinom operator+(const double r) const {
		return polinom(a, b, c + r);
	}
	polinom operator-(const double r) const {
		return polinom(a, b, c - r);
	}
};
polinom operator*(const double q, const polinom &p) {
	return p * q;
}
polinom operator+(const double r, const polinom &p) {
	return p + r;
}
polinom operator-(const double r, const polinom &p) {
	return p - r;
}

class task {
	double *alpha;
	double *beta;
	double *gamma;
public:
	int n;
	double xL;
	double xR;
	double *x;
	double  h;
	double kappa1;
	double kappa2;
	double mu1;
	double mu2;
	double *v;
	double *u;
	double *A;
	double *C;
	double *B;
	double *F;
	void create() {
		beta = new double[n];
		alpha = new double[n];
		alpha[0] = kappa1;
		beta[0] = mu1;
		for (int i = 0; i < n - 1; i++) {
			alpha[i + 1] = B[i] / (C[i] - alpha[i] * A[i]);
			beta[i + 1] = (F[i] + beta[i] * A[i]) / (C[i] - alpha[i] * A[i]);
		}
		v[n] = (mu2 + beta[n - 1] * kappa2) / (1 - alpha[n - 1] * kappa2);
		for (int i = n - 1; i >= 0; i--)
			v[i] = alpha[i] * v[i + 1] + beta[i];
	}
	void max_uncorrect(double &maxee, double &xee) {
		maxee = 0.0;
		xee = x[0];
		for (int i = 1; i < n; i++) {
			if (maxee < fabs(u[i] - v[i])) {
				maxee = fabs(u[i] - v[i]);
				xee = x[i];
			}
		}
	}
	~task() {
		delete[] beta;
		delete[] alpha;
		delete[] A;
		delete[] B;
		delete[] C;
		delete[] F;
		delete[] u;
		delete[] v;
		delete[] x;
	}
};

class test1 : public task {
public:
	test1(int _n, double _k, double _q, polinom p) {
		xL = 0;
		xR = 1;
		h = (xR - xL) / static_cast<double>(_n);
		n = _n;
		A = new double[n - 1];
		C = new double[n - 1];
		B = new double[n - 1];
		F = new double[n - 1];
		kappa1 = 0;
		kappa2 = 0;
		mu1 = p.solution(0);
		mu2 = p.solution(1);
		x = new double[n + 1];
		u = new double[n + 1];
		v = new double[n + 1];
		x[0] = xL;
		x[n] = xR;
		polinom f;
		f = 2 * _k * p.a - _q * p;
		for (int i = 1; i < n; i++) {
			x[i] = x[i - 1] + h;
			A[i - 1] = _k / (h * h);
			C[i - 1] = (2 * _k) / (h * h) + _q;
			B[i - 1] = _k / (h*h);
			F[i - 1] = f.solution(x[i]);
			u[i] = p.solution(x[i]);
		}
		u[0] = mu1;
		u[n] = mu2;
	}
};

class test2 : public task {
public:
	double ksi;
	inline double k(double x) {
		double k1 = exp(-1 * ((x - h + ksi) / 2) * ((x - h + ksi) / 2));
		double k2 = (x + ksi) / 2 + 1;
		if (x <= ksi)
			return exp(-1 * ksi * ksi);
		else if (x - h >= ksi)
			return ksi + 1;
		else
			return ((h * k1 * k2) / ((ksi - x + h) * k2 + (x - ksi) * k1));
	}
	inline double q(double x) {
		double q1 = ((x - h / 2 + ksi) / 2) * ((x - h / 2 + ksi) / 2) + 1;
		double q2 = ((x + h / 2 + ksi) / 2) * ((x + h / 2 + ksi) / 2);
		if (x + h / 2 <= ksi)
			return ksi * ksi + 1;
		else if (x - h / 2 >= ksi)
			return ksi * ksi;
		else
			return (q1 * (ksi - x + h / 2) + q2 * (x + h / 2 - ksi)) / h;
	}
	inline double f(double x) {
		double f1 = sin((x - h / 2 + ksi) / 2);
		double f2 = cos((x + h / 2 + ksi) / 2);
		if (x + h / 2 <= ksi)
			return sin(ksi);
		else if (x - h / 2 >= ksi)
			return cos(ksi);
		else
			return ((ksi - x + h / 2) * f1 + (x + h / 2 - ksi) * f2) / h;

	}
	inline double U(double x) {
		double k1 = exp(-1 * ksi * ksi);
		double k2 = ksi + 1;
		double q1 = ksi * ksi + 1;
		double q2 = ksi * ksi;
		double f1 = sin(ksi);
		double f2 = cos(ksi);
		double c1 = 0.35545273185055836773;
		double c2 = -0.74836836510782278609;
		double c3 = -0.31311455373328339613;
		double c4 = -2.5402166996809869559;
		if (x <= ksi)
			return (c1 * exp(sqrt(q1 / k1) * x) + c2 * exp(-1 * sqrt(q1 / k1) * x) + (f1 / q1));
		else
			return (c3 * exp(sqrt(q2 / k2) * x) + c4 * exp(-1 * sqrt(q2 / k2) * x) + (f2 / q2));
	}
	test2(int _n, double _ksi) {
		xL = 0;
		xR = 1;
		h = (xR - xL) / static_cast<double>(_n);
		n = _n;
		A = new double[n - 1];
		C = new double[n - 1];
		B = new double[n - 1];
		F = new double[n - 1];
		kappa1 = 0;
		kappa2 = 0;
		mu1 = 0;
		mu2 = 1;
		ksi = _ksi;
		x = new double[n + 1];
		u = new double[n + 1];
		v = new double[n + 1];
		x[0] = xL;
		x[n] = xR;
		u[0] = U(xL);
		u[n] = U(xR);
		for (int i = 1; i < n; i++)
			x[i] = x[i - 1] + h;
		for (int i = 1; i < n; i++) {
			A[i - 1] = k(x[i]) / (h * h);
			C[i - 1] = (k(x[i + 1]) + k(x[i])) / (h * h) + q(x[i]);
			B[i - 1] = k(x[i + 1]) / (h * h);
			F[i - 1] = f(x[i]);
			u[i] = U(x[i]);
		}
	}
};

class osn : public task {
public:
	double ksi;
	inline double k(double x) {
		double k1 = exp(-1 * ((x - h + ksi) / 2) * ((x - h + ksi) / 2));
		double k2 = (x + ksi) / 2 + 1;
		if (x <= ksi)
			return exp(-1 * x * x);
		else if (x - h >= ksi)
			return x + 1;
		else
			return ((h * k1 * k2) / ((ksi - x + h) * k2 + (x - ksi) * k1));
	}
	inline double q(double x) {
		double q1 = ((x - h / 2 + ksi) / 2) * ((x - h / 2 + ksi) / 2) + 1;
		double q2 = ((x + h / 2 + ksi) / 2) * ((x + h / 2 + ksi) / 2);
		if (x + h / 2 <= ksi)
			return x * x + 1;
		else if (x - h / 2 >= ksi)
			return x * x;
		else
			return (q1 * (ksi - x + h / 2) + q2 * (x + h / 2 - ksi)) / h;
	}
	inline double f(double x) {
		double f1 = sin((x - h / 2 + ksi) / 2);
		double f2 = cos((x + h / 2 + ksi) / 2);
		if (x + h / 2 <= ksi)
			return sin(x);
		else if (x - h / 2 >= ksi)
			return cos(x);
		else
			return ((ksi - x + h / 2) * f1 + (x + h / 2 - ksi) * f2) / h;
	}
	inline osn(int _n, double _ksi) {
		xL = 0;
		xR = 1;
		h = (xR - xL) / static_cast<double>(_n);
		n = _n;
		A = new double[n - 1];
		C = new double[n - 1];
		B = new double[n - 1];
		F = new double[n - 1];
		kappa1 = 0;
		kappa2 = 0;
		mu1 = 0;
		mu2 = 1;
		ksi = _ksi;
		x = new double[n + 1];
		u = new double[n + 1];
		v = new double[n + 1];
		x[0] = xL;
		x[n] = xR;
		for (int i = 1; i < n; i++)
			x[i] = x[i - 1] + h;
		for (int i = 1; i < n; i++) {
			A[i - 1] = k(x[i]) / (h * h);
			C[i - 1] = (k(x[i + 1]) + k(x[i])) / (h * h) + q(x[i]);
			B[i - 1] = k(x[i + 1]) / (h * h);
			F[i - 1] = f(x[i]);
		}
	}
};

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
	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		MyForm(void) {
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::TabControl^  tabControl2;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::TabPage^  tabPage5;
	private: ZedGraph::ZedGraphControl^  zedGraphControl2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::TabControl^  tabControl3;
	private: System::Windows::Forms::TabPage^  tabPage6;
	private: ZedGraph::ZedGraphControl^  zedGraphControl3;
	private: System::Windows::Forms::TabPage^  tabPage7;
	private: ZedGraph::ZedGraphControl^  zedGraphControl4;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::ListView^  listView2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn10;
	private: System::Windows::Forms::TabControl^  tabControl4;
	private: System::Windows::Forms::TabPage^  tabPage8;
	private: ZedGraph::ZedGraphControl^  zedGraphControl5;
	private: System::Windows::Forms::TabPage^  tabPage9;
	private: ZedGraph::ZedGraphControl^  zedGraphControl6;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::ListView^  listView3;
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
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl2 = (gcnew ZedGraph::ZedGraphControl());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl3 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl3 = (gcnew ZedGraph::ZedGraphControl());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl4 = (gcnew ZedGraph::ZedGraphControl());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->listView2 = (gcnew System::Windows::Forms::ListView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->tabControl4 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage8 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl5 = (gcnew ZedGraph::ZedGraphControl());
			this->tabPage9 = (gcnew System::Windows::Forms::TabPage());
			this->zedGraphControl6 = (gcnew ZedGraph::ZedGraphControl());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->listView3 = (gcnew System::Windows::Forms::ListView());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabControl2->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabControl3->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->tabControl4->SuspendLayout();
			this->tabPage8->SuspendLayout();
			this->tabPage9->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(-1, 1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1243, 912);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->textBox8);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->textBox6);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->groupBox3);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->tabControl2);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1235, 883);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Тестовая задача №1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(28, 514);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(16, 17);
			this->label17->TabIndex = 18;
			this->label17->Text = L"e";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(50, 511);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(60, 22);
			this->textBox8->TabIndex = 17;
			this->textBox8->Text = L"0,01";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(160, 423);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 110);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(50, 483);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(60, 22);
			this->textBox6->TabIndex = 13;
			this->textBox6->Text = L"10";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(28, 486);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(16, 17);
			this->label7->TabIndex = 12;
			this->label7->Text = L"n";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Location = System::Drawing::Point(15, 179);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(432, 235);
			this->groupBox3->TabIndex = 11;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Справка";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(6, 211);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(30, 17);
			this->label15->TabIndex = 7;
			this->label15->Text = L"x = ";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(1, 177);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(322, 34);
			this->label14->TabIndex = 6;
			this->label14->Text = L"Максимальное отклонение точного и\r\nприближенного решений наблюдается в точке ";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 141);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(40, 17);
			this->label13->TabIndex = 5;
			this->label13->Text = L"e1 = ";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(1, 124);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(261, 17);
			this->label12->TabIndex = 4;
			this->label12->Text = L"Тестовая задача решена с точностью";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 94);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(32, 17);
			this->label11->TabIndex = 3;
			this->label11->Text = L"e = ";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(1, 77);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(323, 17);
			this->label10->TabIndex = 2;
			this->label10->Text = L"Требуемая точность решения тестовой задачи";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(216, 47);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(32, 17);
			this->label9->TabIndex = 1;
			this->label9->Text = L"n = ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(1, 30);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(309, 34);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Для решения тестовой задачи использована\r\nсетка с числом разбиений по x";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(566, 453);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(650, 400);
			this->dataGridView1->TabIndex = 10;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"№ узла";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"xi";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"u(xi)";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"v(xi)";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"u(xi)-v(xi)";
			this->Column5->Name = L"Column5";
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage4);
			this->tabControl2->Controls->Add(this->tabPage5);
			this->tabControl2->Location = System::Drawing::Point(562, 6);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(667, 441);
			this->tabControl2->TabIndex = 9;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->zedGraphControl1);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(659, 412);
			this->tabPage4->TabIndex = 0;
			this->tabPage4->Text = L"Графики точного и численного решения";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(0, 0);
			this->zedGraphControl1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(650, 402);
			this->zedGraphControl1->TabIndex = 8;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->zedGraphControl2);
			this->tabPage5->Location = System::Drawing::Point(4, 25);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(659, 412);
			this->tabPage5->TabIndex = 1;
			this->tabPage5->Text = L"График разности точного и численного решения";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl2
			// 
			this->zedGraphControl2->Location = System::Drawing::Point(0, 1);
			this->zedGraphControl2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->zedGraphControl2->Name = L"zedGraphControl2";
			this->zedGraphControl2->ScrollGrace = 0;
			this->zedGraphControl2->ScrollMaxX = 0;
			this->zedGraphControl2->ScrollMaxY = 0;
			this->zedGraphControl2->ScrollMaxY2 = 0;
			this->zedGraphControl2->ScrollMinX = 0;
			this->zedGraphControl2->ScrollMinY = 0;
			this->zedGraphControl2->ScrollMinY2 = 0;
			this->zedGraphControl2->Size = System::Drawing::Size(650, 400);
			this->zedGraphControl2->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(24, 458);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(21, 17);
			this->label6->TabIndex = 7;
			this->label6->Text = L"q*";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(50, 455);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(60, 22);
			this->textBox5->TabIndex = 6;
			this->textBox5->Text = L"1";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(460, 189);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(100, 131);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Полином";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(27, 99);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(60, 22);
			this->textBox4->TabIndex = 6;
			this->textBox4->Text = L"1";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(27, 71);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(60, 22);
			this->textBox3->TabIndex = 5;
			this->textBox3->Text = L"1";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(27, 43);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(60, 22);
			this->textBox2->TabIndex = 4;
			this->textBox2->Text = L"1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 102);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(15, 17);
			this->label5->TabIndex = 3;
			this->label5->Text = L"c";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 74);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(16, 17);
			this->label4->TabIndex = 2;
			this->label4->Text = L"b";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(5, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(16, 17);
			this->label3->TabIndex = 1;
			this->label3->Text = L"a";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 18);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 17);
			this->label2->TabIndex = 0;
			this->label2->Text = L"ax^2 + bx + c";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(50, 425);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(60, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 428);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"k*";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->listView1);
			this->groupBox1->Location = System::Drawing::Point(9, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(547, 151);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Задание";
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::SystemColors::Window;
			this->listView1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"listView1.BackgroundImage")));
			this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listView1->ForeColor = System::Drawing::SystemColors::WindowText;
			this->listView1->Location = System::Drawing::Point(8, 21);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(526, 124);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Controls->Add(this->textBox7);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->textBox9);
			this->tabPage2->Controls->Add(this->label18);
			this->tabPage2->Controls->Add(this->groupBox4);
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Controls->Add(this->tabControl3);
			this->tabPage2->Controls->Add(this->label27);
			this->tabPage2->Controls->Add(this->textBox10);
			this->tabPage2->Controls->Add(this->groupBox6);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1235, 883);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Тестовая задача №2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(463, 254);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(16, 17);
			this->label16->TabIndex = 32;
			this->label16->Text = L"e";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(485, 251);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(60, 22);
			this->textBox7->TabIndex = 31;
			this->textBox7->Text = L"0,00000005";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(451, 292);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 110);
			this->button2->TabIndex = 30;
			this->button2->Text = L"Вычислить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(485, 223);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(60, 22);
			this->textBox9->TabIndex = 29;
			this->textBox9->Text = L"10";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(463, 226);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(16, 17);
			this->label18->TabIndex = 28;
			this->label18->Text = L"n";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->label19);
			this->groupBox4->Controls->Add(this->label20);
			this->groupBox4->Controls->Add(this->label21);
			this->groupBox4->Controls->Add(this->label22);
			this->groupBox4->Controls->Add(this->label23);
			this->groupBox4->Controls->Add(this->label24);
			this->groupBox4->Controls->Add(this->label25);
			this->groupBox4->Controls->Add(this->label26);
			this->groupBox4->Location = System::Drawing::Point(13, 191);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(432, 235);
			this->groupBox4->TabIndex = 27;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Справка";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 211);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(30, 17);
			this->label19->TabIndex = 7;
			this->label19->Text = L"x = ";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(1, 177);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(322, 34);
			this->label20->TabIndex = 6;
			this->label20->Text = L"Максимальное отклонение точного и\r\nприближенного решений наблюдается в точке ";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(6, 141);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(40, 17);
			this->label21->TabIndex = 5;
			this->label21->Text = L"e1 = ";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(1, 124);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(261, 17);
			this->label22->TabIndex = 4;
			this->label22->Text = L"Тестовая задача решена с точностью";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(6, 94);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(32, 17);
			this->label23->TabIndex = 3;
			this->label23->Text = L"e = ";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(1, 77);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(323, 17);
			this->label24->TabIndex = 2;
			this->label24->Text = L"Требуемая точность решения тестовой задачи";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(216, 47);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(32, 17);
			this->label25->TabIndex = 1;
			this->label25->Text = L"n = ";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(1, 30);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(309, 34);
			this->label26->TabIndex = 0;
			this->label26->Text = L"Для решения тестовой задачи использована\r\nсетка с числом разбиений по x";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			});
			this->dataGridView2->Location = System::Drawing::Point(564, 465);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(650, 400);
			this->dataGridView2->TabIndex = 26;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"№ узла";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"xi";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"u(xi)";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"v(xi)";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"u(xi)-v(xi)";
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// tabControl3
			// 
			this->tabControl3->Controls->Add(this->tabPage6);
			this->tabControl3->Controls->Add(this->tabPage7);
			this->tabControl3->Location = System::Drawing::Point(560, 18);
			this->tabControl3->Name = L"tabControl3";
			this->tabControl3->SelectedIndex = 0;
			this->tabControl3->Size = System::Drawing::Size(667, 441);
			this->tabControl3->TabIndex = 25;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->zedGraphControl3);
			this->tabPage6->Location = System::Drawing::Point(4, 25);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(659, 412);
			this->tabPage6->TabIndex = 0;
			this->tabPage6->Text = L"Графики точного и численного решения";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl3
			// 
			this->zedGraphControl3->Location = System::Drawing::Point(0, 0);
			this->zedGraphControl3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->zedGraphControl3->Name = L"zedGraphControl3";
			this->zedGraphControl3->ScrollGrace = 0;
			this->zedGraphControl3->ScrollMaxX = 0;
			this->zedGraphControl3->ScrollMaxY = 0;
			this->zedGraphControl3->ScrollMaxY2 = 0;
			this->zedGraphControl3->ScrollMinX = 0;
			this->zedGraphControl3->ScrollMinY = 0;
			this->zedGraphControl3->ScrollMinY2 = 0;
			this->zedGraphControl3->Size = System::Drawing::Size(650, 402);
			this->zedGraphControl3->TabIndex = 8;
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->zedGraphControl4);
			this->tabPage7->Location = System::Drawing::Point(4, 25);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(659, 412);
			this->tabPage7->TabIndex = 1;
			this->tabPage7->Text = L"График разности точного и численного решения";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl4
			// 
			this->zedGraphControl4->Location = System::Drawing::Point(0, 1);
			this->zedGraphControl4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->zedGraphControl4->Name = L"zedGraphControl4";
			this->zedGraphControl4->ScrollGrace = 0;
			this->zedGraphControl4->ScrollMaxX = 0;
			this->zedGraphControl4->ScrollMaxY = 0;
			this->zedGraphControl4->ScrollMaxY2 = 0;
			this->zedGraphControl4->ScrollMinX = 0;
			this->zedGraphControl4->ScrollMinY = 0;
			this->zedGraphControl4->ScrollMinY2 = 0;
			this->zedGraphControl4->Size = System::Drawing::Size(650, 400);
			this->zedGraphControl4->TabIndex = 9;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(459, 198);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(25, 17);
			this->label27->TabIndex = 24;
			this->label27->Text = L"ksi";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(485, 195);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(60, 22);
			this->textBox10->TabIndex = 23;
			this->textBox10->Text = L"0,525";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->listView2);
			this->groupBox6->Location = System::Drawing::Point(7, 18);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(538, 151);
			this->groupBox6->TabIndex = 19;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Задание";
			// 
			// listView2
			// 
			this->listView2->BackColor = System::Drawing::SystemColors::Window;
			this->listView2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"listView2.BackgroundImage")));
			this->listView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listView2->ForeColor = System::Drawing::SystemColors::WindowText;
			this->listView2->Location = System::Drawing::Point(8, 21);
			this->listView2->Name = L"listView2";
			this->listView2->Size = System::Drawing::Size(524, 124);
			this->listView2->TabIndex = 1;
			this->listView2->UseCompatibleStateImageBehavior = false;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button3);
			this->tabPage3->Controls->Add(this->textBox12);
			this->tabPage3->Controls->Add(this->label29);
			this->tabPage3->Controls->Add(this->groupBox5);
			this->tabPage3->Controls->Add(this->dataGridView3);
			this->tabPage3->Controls->Add(this->tabControl4);
			this->tabPage3->Controls->Add(this->label38);
			this->tabPage3->Controls->Add(this->textBox13);
			this->tabPage3->Controls->Add(this->groupBox7);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1235, 883);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Основная задача";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(451, 292);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(103, 110);
			this->button3->TabIndex = 41;
			this->button3->Text = L"Вычислить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(485, 223);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(60, 22);
			this->textBox12->TabIndex = 40;
			this->textBox12->Text = L"10";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(463, 226);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(16, 17);
			this->label29->TabIndex = 39;
			this->label29->Text = L"n";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label30);
			this->groupBox5->Controls->Add(this->label31);
			this->groupBox5->Controls->Add(this->label32);
			this->groupBox5->Controls->Add(this->label35);
			this->groupBox5->Controls->Add(this->label36);
			this->groupBox5->Controls->Add(this->label37);
			this->groupBox5->Location = System::Drawing::Point(13, 191);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(432, 235);
			this->groupBox5->TabIndex = 38;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Справка";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(164, 148);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(30, 17);
			this->label30->TabIndex = 7;
			this->label30->Text = L"x = ";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(6, 148);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(152, 17);
			this->label31->TabIndex = 6;
			this->label31->Text = L"и соответствует узлу ";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(6, 117);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(40, 17);
			this->label32->TabIndex = 5;
			this->label32->Text = L"e2 = ";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(1, 73);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(398, 34);
			this->label35->TabIndex = 2;
			this->label35->Text = L"при пересчете задачи с половинным шагом максимальная\r\nразность приближенных решен"
				L"ий составила ";
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(216, 47);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(32, 17);
			this->label36->TabIndex = 1;
			this->label36->Text = L"n = ";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(1, 30);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(311, 34);
			this->label37->TabIndex = 0;
			this->label37->Text = L"Для решения основной задачи использована\r\nсетка с числом разбиений по x";
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn6,
					this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, this->dataGridViewTextBoxColumn9, this->dataGridViewTextBoxColumn10
			});
			this->dataGridView3->Location = System::Drawing::Point(564, 465);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersVisible = false;
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(650, 400);
			this->dataGridView3->TabIndex = 37;
			// 
			// tabControl4
			// 
			this->tabControl4->Controls->Add(this->tabPage8);
			this->tabControl4->Controls->Add(this->tabPage9);
			this->tabControl4->Location = System::Drawing::Point(560, 18);
			this->tabControl4->Name = L"tabControl4";
			this->tabControl4->SelectedIndex = 0;
			this->tabControl4->Size = System::Drawing::Size(667, 441);
			this->tabControl4->TabIndex = 36;
			// 
			// tabPage8
			// 
			this->tabPage8->Controls->Add(this->zedGraphControl5);
			this->tabPage8->Location = System::Drawing::Point(4, 25);
			this->tabPage8->Name = L"tabPage8";
			this->tabPage8->Padding = System::Windows::Forms::Padding(3);
			this->tabPage8->Size = System::Drawing::Size(659, 412);
			this->tabPage8->TabIndex = 0;
			this->tabPage8->Text = L"Графики точного и численного решения";
			this->tabPage8->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl5
			// 
			this->zedGraphControl5->Location = System::Drawing::Point(0, 0);
			this->zedGraphControl5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->zedGraphControl5->Name = L"zedGraphControl5";
			this->zedGraphControl5->ScrollGrace = 0;
			this->zedGraphControl5->ScrollMaxX = 0;
			this->zedGraphControl5->ScrollMaxY = 0;
			this->zedGraphControl5->ScrollMaxY2 = 0;
			this->zedGraphControl5->ScrollMinX = 0;
			this->zedGraphControl5->ScrollMinY = 0;
			this->zedGraphControl5->ScrollMinY2 = 0;
			this->zedGraphControl5->Size = System::Drawing::Size(650, 402);
			this->zedGraphControl5->TabIndex = 8;
			// 
			// tabPage9
			// 
			this->tabPage9->Controls->Add(this->zedGraphControl6);
			this->tabPage9->Location = System::Drawing::Point(4, 25);
			this->tabPage9->Name = L"tabPage9";
			this->tabPage9->Padding = System::Windows::Forms::Padding(3);
			this->tabPage9->Size = System::Drawing::Size(659, 412);
			this->tabPage9->TabIndex = 1;
			this->tabPage9->Text = L"График разности точного и численного решения";
			this->tabPage9->UseVisualStyleBackColor = true;
			// 
			// zedGraphControl6
			// 
			this->zedGraphControl6->Location = System::Drawing::Point(0, 1);
			this->zedGraphControl6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->zedGraphControl6->Name = L"zedGraphControl6";
			this->zedGraphControl6->ScrollGrace = 0;
			this->zedGraphControl6->ScrollMaxX = 0;
			this->zedGraphControl6->ScrollMaxY = 0;
			this->zedGraphControl6->ScrollMaxY2 = 0;
			this->zedGraphControl6->ScrollMinX = 0;
			this->zedGraphControl6->ScrollMinY = 0;
			this->zedGraphControl6->ScrollMinY2 = 0;
			this->zedGraphControl6->Size = System::Drawing::Size(650, 400);
			this->zedGraphControl6->TabIndex = 9;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(459, 198);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(25, 17);
			this->label38->TabIndex = 35;
			this->label38->Text = L"ksi";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(485, 195);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(60, 22);
			this->textBox13->TabIndex = 34;
			this->textBox13->Text = L"0,525";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->listView3);
			this->groupBox7->Location = System::Drawing::Point(7, 18);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(538, 151);
			this->groupBox7->TabIndex = 33;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Задание";
			// 
			// listView3
			// 
			this->listView3->BackColor = System::Drawing::SystemColors::Window;
			this->listView3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"listView3.BackgroundImage")));
			this->listView3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listView3->ForeColor = System::Drawing::SystemColors::WindowText;
			this->listView3->Location = System::Drawing::Point(8, 21);
			this->listView3->Name = L"listView3";
			this->listView3->Size = System::Drawing::Size(524, 124);
			this->listView3->TabIndex = 1;
			this->listView3->UseCompatibleStateImageBehavior = false;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"№ узла";
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"xi";
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->HeaderText = L"v2(xi)";
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->HeaderText = L"v(xi)";
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			// 
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->HeaderText = L"v2(xi)-v(xi)";
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1248, 953);
			this->Controls->Add(this->tabControl1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Первая краевая задача для стационарного уравнения теплопроводности";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabControl2->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabControl3->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			this->tabPage7->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->tabControl4->ResumeLayout(false);
			this->tabPage8->ResumeLayout(false);
			this->tabPage9->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion 
		void print_test1(test1 &t) {
			for (int i = 0; i < t.n + 1; i++) {
				dataGridView1->Rows->Add();
				dataGridView1->Rows[i]->Cells[0]->Value = i;
				dataGridView1->Rows[i]->Cells[1]->Value = t.x[i];
				dataGridView1->Rows[i]->Cells[2]->Value = t.u[i];
				dataGridView1->Rows[i]->Cells[3]->Value = t.v[i];
				dataGridView1->Rows[i]->Cells[4]->Value = t.u[i] - t.v[i];
			}
		}
		void print_test2(test2 &t) {
			for (int i = 0; i < t.n + 1; i++) {
				dataGridView2->Rows->Add();
				dataGridView2->Rows[i]->Cells[0]->Value = i;
				dataGridView2->Rows[i]->Cells[1]->Value = t.x[i];
				dataGridView2->Rows[i]->Cells[2]->Value = t.u[i];
				dataGridView2->Rows[i]->Cells[3]->Value = t.v[i];
				dataGridView2->Rows[i]->Cells[4]->Value = t.u[i] - t.v[i];
			}
		}
		void print_osn(osn &t) {
			for (int i = 0; i < t.n + 1; i++) {
				dataGridView3->Rows->Add();
				dataGridView3->Rows[i]->Cells[0]->Value = i;
				dataGridView3->Rows[i]->Cells[1]->Value = t.x[i];
				dataGridView3->Rows[i]->Cells[2]->Value = t.u[i];
				dataGridView3->Rows[i]->Cells[3]->Value = t.v[i];
				dataGridView3->Rows[i]->Cells[4]->Value = t.u[i] - t.v[i];
			}
		}

		void art_graph_test1(test1 &t) {
			PointPairList^ u_t1_list = gcnew ZedGraph::PointPairList();
			PointPairList^ v_t1_list = gcnew ZedGraph::PointPairList();
			PointPairList^ uv_t1_list = gcnew ZedGraph::PointPairList();
			for (int i = 0; i < t.n + 1; i++) {
				u_t1_list->Add(t.x[i], t.u[i]);
				v_t1_list->Add(t.x[i], t.v[i]);
				uv_t1_list->Add(t.x[i], t.u[i] - t.v[i]);
			}
			LineItem Curve1 = zedGraphControl1->GraphPane->AddCurve("точное", u_t1_list, Color::Green, SymbolType::None);
			LineItem Curve2 = zedGraphControl1->GraphPane->AddCurve("численное", v_t1_list, Color::Blue, SymbolType::None);
			LineItem Curve3 = zedGraphControl2->GraphPane->AddCurve("разность", uv_t1_list, Color::Gray, SymbolType::None);
			zedGraphControl1->AxisChange();
			zedGraphControl1->Invalidate();
			zedGraphControl2->AxisChange();
			zedGraphControl2->Invalidate();
		}
		void art_graph_test2(test2 &t) {
			PointPairList^ u_t2_list = gcnew ZedGraph::PointPairList();
			PointPairList^ v_t2_list = gcnew ZedGraph::PointPairList();
			PointPairList^ uv_t2_list = gcnew ZedGraph::PointPairList();
			for (int i = 0; i < t.n + 1; i++) {
				u_t2_list->Add(t.x[i], t.u[i]);
				v_t2_list->Add(t.x[i], t.v[i]);
				uv_t2_list->Add(t.x[i], t.u[i] - t.v[i]);
			}
			LineItem Curve4 = zedGraphControl3->GraphPane->AddCurve("точное", u_t2_list, Color::Green, SymbolType::None);
			LineItem Curve5 = zedGraphControl3->GraphPane->AddCurve("численное", v_t2_list, Color::Blue, SymbolType::None);
			LineItem Curve6 = zedGraphControl4->GraphPane->AddCurve("разность", uv_t2_list, Color::Gray, SymbolType::None);
			zedGraphControl3->AxisChange();
			zedGraphControl3->Invalidate();
			zedGraphControl4->AxisChange();
			zedGraphControl4->Invalidate();
		}
		void art_graph_osn(osn &t) {
			PointPairList^ u_list = gcnew ZedGraph::PointPairList();
			PointPairList^ v_list = gcnew ZedGraph::PointPairList();
			PointPairList^ uv_list = gcnew ZedGraph::PointPairList();
			for (int i = 0; i < t.n + 1; i++) {
				u_list->Add(t.x[i], t.u[i]);
				v_list->Add(t.x[i], t.v[i]);
				uv_list->Add(t.x[i], t.u[i] - t.v[i]);
			}
			LineItem Curve7 = zedGraphControl5->GraphPane->AddCurve("численное с h/2", u_list, Color::Green, SymbolType::None);
			LineItem Curve8 = zedGraphControl5->GraphPane->AddCurve("численное с h", v_list, Color::Blue, SymbolType::None);
			LineItem Curve9 = zedGraphControl6->GraphPane->AddCurve("разность", uv_list, Color::Gray, SymbolType::None);
			zedGraphControl5->AxisChange();
			zedGraphControl5->Invalidate();
			zedGraphControl6->AxisChange();
			zedGraphControl6->Invalidate();
		}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	polinom p(Convert::ToDouble(textBox2->Text), Convert::ToDouble(textBox3->Text), Convert::ToDouble(textBox4->Text));
	double k = Convert::ToDouble(textBox1->Text);
	double q = Convert::ToDouble(textBox5->Text);
	double ee = Convert::ToDouble(textBox8->Text);
	int n = Convert::ToInt32(textBox6->Text);
	double maxee, xee;
	dataGridView1->Rows->Clear();
	zedGraphControl1->GraphPane->CurveList->Clear();
	zedGraphControl2->GraphPane->CurveList->Clear();
	test1 tt(n, k, q, p);
	tt.create();
	tt.max_uncorrect(maxee, xee);
	print_test1(tt);
	art_graph_test1(tt);
	label9->Text = "n = " + Convert::ToString(n);
	label11->Text = "e = " + Convert::ToString(ee);
	label13->Text = "e1 = " + Convert::ToString(maxee);
	label15->Text = "x = " + Convert::ToString(xee);
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	double ee = Convert::ToDouble(textBox7->Text);
	double ksi = Convert::ToDouble(textBox10->Text);
	int n = Convert::ToInt32(textBox9->Text);
	double maxee, xee;
	dataGridView2->Rows->Clear();
	zedGraphControl3->GraphPane->CurveList->Clear();
	zedGraphControl4->GraphPane->CurveList->Clear();
	test2 tt(n, ksi);
	tt.create();
	tt.max_uncorrect(maxee, xee);
	print_test2(tt);
	art_graph_test2(tt);
	label25->Text = "n = " + Convert::ToString(n);
	label23->Text = "e = " + Convert::ToString(ee);
	label21->Text = "e1 = " + Convert::ToString(maxee);
	label19->Text = "x = " + Convert::ToString(xee);
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	double ksi = Convert::ToDouble(textBox13->Text);
	int n = Convert::ToInt32(textBox12->Text);
	double maxee, xee;
	dataGridView3->Rows->Clear();
	zedGraphControl5->GraphPane->CurveList->Clear();
	zedGraphControl6->GraphPane->CurveList->Clear();
	osn tt(n, ksi);
	osn t2(n * 2, ksi);
	tt.create();
	t2.create();
	for (int i = 0; i < n + 1; i++) {
		tt.u[i] = t2.v[2 * i];
	}
	tt.max_uncorrect(maxee, xee);
	print_osn(tt);
	art_graph_osn(tt);
	label36->Text = "n = " + Convert::ToString(n);
	label32->Text = "e2 = " + Convert::ToString(maxee);
	label30->Text = "x = " + Convert::ToString(xee);
}
};
}