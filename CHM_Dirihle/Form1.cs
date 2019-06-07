using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CHM_Dirihle
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        void printdgv(DataGridView data, double[,] xx, int n, int m, string s)
        {
            data.Columns.Clear();

            data.Columns.Add("cc0", s);
            data.Columns.Add("cc1", "i");

            for (int i = 0; i < n + 1; i++)
            {
                data.Columns.Add("c" + i.ToString(), i.ToString());
            }

            for (int j = m; j >= 0; j--)
            {
                data.Rows.Add();
            }

            data.Rows[0].Cells[0].Value = "j";

            double h = 2.0 / (double)n;
            double k = 2.0 / (double)m;

            for (int i = 2; i < n + 3; i++)
            {
                data.Rows[0].Cells[i].Value = -1 + (i - 2) * h;
            }

            for (int j = 1; j < m + 2; j++)
            {
                data.Rows[j].Cells[1].Value = -1 + (m + 1 - j) * k;
            }

            data.Rows[0].Cells[1].Value = "Y \\ X";

            for (int j = 1; j < m + 2; j++)
            {
                data.Rows[j].Cells[0].Value = m + 1 - j;
            }

            for (int i = 2; i < n + 3; i++)
                for (int j = 1; j < m + 2; j++)
                {
                    data.Rows[j].Cells[i].Value = xx[i - 2, m - j + 1];
                }
        }

        double[,] zeidel(double[,] xx, double[,] b, int n, int m, double h, double k, NE ne)
        {
            int s = 0;
            int x = 0, y = 0;
            double es = 100;
            double h2 = 1.0 / (h * h);
            double k2 = 1.0 / (k * k);

            while ((s < ne.nn) && (es > ne.ee))
            {
                es = 0;
                for (int i = 1; i < n; i++)
                    for (int j = 1; j < m; j++)
                    {
                        double vs = xx[i, j];
                        double htmp = h2 * (xx[i - 1, j] + xx[i + 1, j]);
                        double ktmp = k2 * (xx[i, j - 1] + xx[i, j + 1]);

                        xx[i, j] = (-b[i, j] + htmp + ktmp) / (2 * (h2 + k2));

                        if (es < Math.Abs(xx[i, j] - vs))
                        {
                            es = Math.Abs(xx[i, j] - vs);
                            x = i;
                            y = j;
                        }
                    }
                s++;
            }
            ne.nn = s;
            ne.ee = es;
            ne.x = x;
            ne.y = y;

            return xx;
        }

        double[,] zeidel(double[,] xx, double[,] b, int n, int m, double h, double k, NE ne, int n1, int m1)
        {
            int s = 0;
            int x = 0, y = 0;
            double es = 100;
            double h2 = 1.0 / (h * h);
            double k2 = 1.0 / (k * k);

            while ((s < ne.nn) && (es > ne.ee))
            {
                es = 0;
                for (int i = 1; i < n1; i++)
                    for (int j = 1; j < m; j++)
                    {
                        double vs = xx[i, j];
                        double htmp = h2 * (xx[i - 1, j] + xx[i + 1, j]);
                        double ktmp = k2 * (xx[i, j - 1] + xx[i, j + 1]);

                        xx[i, j] = (-b[i, j] + htmp + ktmp) / (2 * (h2 + k2));

                        if (es < Math.Abs(xx[i, j] - vs))
                        {
                            es = Math.Abs(xx[i, j] - vs);
                            x = i;
                            y = j;
                        }
                    }
                for (int i = n1; i < n; i++)
                    for (int j = 1; j < m1; j++)
                    {
                        double vs = xx[i, j];
                        double htmp = h2 * (xx[i - 1, j] + xx[i + 1, j]);
                        double ktmp = k2 * (xx[i, j - 1] + xx[i, j + 1]);

                        xx[i, j] = (-b[i, j] + htmp + ktmp) / (2 * (h2 + k2));

                        if (es < Math.Abs(xx[i, j] - vs))
                        {
                            es = Math.Abs(xx[i, j] - vs);
                            x = i;
                            y = j;
                        }
                    }
             s++;
            }
            ne.nn = s;
            ne.ee = es;
            ne.x = x;
            ne.y = y;

            return xx;
        }

        double[,] discrepancy(double[,] axx, double[,] xx, double[,] b, int n, int m, double h2, double k2)
        {
            double[,] r = new double[n + 1, m + 1];
            for (int i = 1; i < n; i++)
                for (int j = 1; j < m; j++)
                    r[i, j] = axx[i, j] - b[i, j];
            return r;
        }


        double[,] ax(double[,] xx, int n, int m, double h2, double k2)
        {
            double[,] axx = new double[n + 1, m + 1];
            for (int i = 1; i < n; i++)
                for (int j = 1; j < m; j++)
                {
                    double htmp = h2 * (xx[i - 1, j] + xx[i + 1, j]);
                    double ktmp = k2 * (xx[i, j - 1] + xx[i, j + 1]);

                    axx[i, j] = -2 * (h2 + k2) * xx[i, j] + htmp + ktmp;
                }
            return axx;
        }

        double[,] ax(double[,] xx, int n, int m, double h2, double k2, int n1, int m1)
        {
            double[,] axx = new double[n + 1, m + 1];
            for (int i = 1; i < n1; i++)
                for (int j = 1; j < m; j++)
                {
                    double htmp = h2 * (xx[i - 1, j] + xx[i + 1, j]);
                    double ktmp = k2 * (xx[i, j - 1] + xx[i, j + 1]);

                    axx[i, j] = -2 * (h2 + k2) * xx[i, j] + htmp + ktmp;
                }
            for (int i = n1; i < n; i++)
                for (int j = 1; j < m1; j++)
                {
                    double htmp = h2 * (xx[i - 1, j] + xx[i + 1, j]);
                    double ktmp = k2 * (xx[i, j - 1] + xx[i, j + 1]);

                    axx[i, j] = -2 * (h2 + k2) * xx[i, j] + htmp + ktmp;
                }
            return axx;
        }

        double skalar(double[,] a, double[,] b, int n, int m)
        {
            double res = 0.0;
            for (int i = 1; i < n; i++)
                for (int j = 1; j < m; j++)
                    res += a[i, j] * b[i, j];
            return res;
        }

        double[,] mult(double[,] a, double k, int n, int m)
        {
            double[,] res = new double[n + 1, m + 1];
            for (int i = 1; i < n; i++)
                for (int j = 1; j < m; j++)
                    res[i, j] = k * a[i, j];
            return res;
        }

        double[,] divv(double[,] a, double[,] b, int n, int m)
        {
            double[,] res = new double[n + 1, m + 1];
            for (int i = 1; i < n; i++)
                for (int j = 1; j < m; j++)
                    res[i, j] = a[i, j] - b[i, j];
            return res;
        }

        double minee(double[,] a, double[,] b, int n, int m, NE ne)
        {
            double es = 0.0;
            int x = 0, y = 0;
            for (int i = 1; i < n; i++)
                for (int j = 1; j < m; j++)
                    if (es < Math.Abs(a[i, j] - b[i, j]))
                    {
                        es = Math.Abs(a[i, j] - b[i, j]);
                        x = i;
                        y = j;
                    }
            ne.x = x;
            ne.y = y;
            return es;
        }

        double minee(double[,] a, double[,] b, int n, int m, NE ne, int n1, int m1)
        {
            double es = 0.0;
            int x = 0, y = 0;
            for (int i = 1; i < n1; i++)
                for (int j = 1; j < m; j++)
                    if (es < Math.Abs(a[i, j] - b[i, j]))
                    {
                        es = Math.Abs(a[i, j] - b[i, j]);
                        x = i;
                        y = j;
                    }
            for (int i = n1; i < n; i++)
                for (int j = 1; j < m1; j++)
                    if (es < Math.Abs(a[i, j] - b[i, j]))
                    {
                        es = Math.Abs(a[i, j] - b[i, j]);
                        x = i;
                        y = j;
                    }
            ne.x = x;
            ne.y = y;
            return es;
        }

        double[,] min_discrepancy(double[,] xx, double[,] b, int n, int m, double h, double k, NE ne)
        {
            int s = 0;
            double es = 100;
            double h2 = 1.0 / (h * h);
            double k2 = 1.0 / (k * k);

            double[,] r = new double[n + 1, m + 1];
            double[,] ar = new double[n + 1, m + 1];
            double[,] vs = new double[n + 1, m + 1];
            double[,] axx = new double[n + 1, m + 1];

            while ((s < ne.nn) && (es > ne.ee))
            {
                vs = xx;
                axx = ax(xx, n, m, h2, k2);
                r = discrepancy(axx, xx, b, n, m, h2, k2);
                ar = ax(r, n, m, h2, k2);
                double tau = skalar(r, ar, n, m) / skalar(ar, ar, n, m);
                xx = divv(xx, mult(r, tau, n, m), n, m);
                es = minee(xx, vs, n, m, ne);
                s++;
            }

            ne.nn = s;
            ne.ee = es;

            return xx;
        }

        double[,] min_discrepancy(double[,] xx, double[,] b, int n, int m, double h, double k, NE ne, int n1, int m1)
        {
            int s = 0;
            double es = 100;
            double h2 = 1.0 / (h * h);
            double k2 = 1.0 / (k * k);

            double[,] r = new double[n + 1, m + 1];
            double[,] ar = new double[n + 1, m + 1];
            double[,] vs = new double[n + 1, m + 1];
            double[,] axx = new double[n + 1, m + 1];

            while ((s < ne.nn) && (es > ne.ee))
            {
                vs = xx;
                axx = ax(xx, n, m, h2, k2, n1, m1);
                r = discrepancy(axx, xx, b, n, m, h2, k2);
                ar = ax(r, n, m, h2, k2);
                double tau = skalar(r, ar, n, m) / skalar(ar, ar, n, m);
                xx = divv(xx, mult(r, tau, n, m), n, m);
                es = minee(xx, vs, n, m, ne, n1, m1);
                s++;
            }

            ne.nn = s;
            ne.ee = es;

            return xx;
        }

        double enuc(double[,] xx, double[,] xx2, int n, int m)
        {
            double z = 0;
            for (int i = 1; i < n; i++)
                for (int j = 1; j < m; j++)
                    if (z < Math.Abs(xx[i, j] - xx2[2 * i, 2 * j]))
                        z = Math.Abs(xx[i, j] - xx2[2 * i, 2 * j]);
            return z;
        }

        double enuc(double[,] xx, double[,] xx2, int n, int m, int n1, int m1)
        {
            double z = 0;
            for (int i = 1; i < n1; i++)
                for (int j = 1; j < m; j++)
                    if (z < Math.Abs(xx[i, j] - xx2[2 * i, 2 * j]))
                        z = Math.Abs(xx[i, j] - xx2[2 * i, 2 * j]);
            for (int i = n1; i < n; i++)
                for (int j = 1; j < m1; j++)
                    if (z < Math.Abs(xx[i, j] - xx2[2 * i, 2 * j]))
                        z = Math.Abs(xx[i, j] - xx2[2 * i, 2 * j]);
            return z;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int n = Convert.ToInt32(textBox1.Text);
            int m = Convert.ToInt32(textBox2.Text);
            double ee = Convert.ToDouble(textBox3.Text);
            int nn = Convert.ToInt32(textBox4.Text);

            if (radioButton1.Checked)
            {
                if (!checkBox1.Checked)
                {
                    TestTask task = new TestTask(n, m, nn, ee, zeidel);
                    printdgv(dataGridView1, task.xx, n, m, "Test_num");
                    printdgv(dataGridView2, task.xr, n, m, "Test_ex");

                    label6.Text = Convert.ToString(task.ne.nn);
                    label8.Text = Convert.ToString(task.ne.ee);
                    label10.Text = Convert.ToString(task.z);
                    label22.Text = "x = " + Convert.ToString(task.ne.x);
                    label23.Text = "y = " + Convert.ToString(task.ne.y);
                }
                else
                {
                    Task_3a task = new Task_3a(n, m, nn, ee, zeidel);
                    printdgv(dataGridView1, task.xx, n, m, "Test_3a_num");
                    printdgv(dataGridView2, task.xr, n, m, "Тest_3a_ex");

                    label6.Text = Convert.ToString(task.ne.nn);
                    label8.Text = Convert.ToString(task.ne.ee);
                    label10.Text = Convert.ToString(task.z);
                    label22.Text = "x = " + Convert.ToString(task.ne.x);
                    label23.Text = "y = " + Convert.ToString(task.ne.y);
                }
            }
            else
            {
                if (!checkBox1.Checked)
                {
                    TestTask task = new TestTask(n, m, nn, ee, min_discrepancy);
                    printdgv(dataGridView1, task.xx, n, m, "Test_num");
                    printdgv(dataGridView2, task.xr, n, m, "Test_ex");

                    label6.Text = Convert.ToString(task.ne.nn);
                    label8.Text = Convert.ToString(task.ne.ee);
                    label10.Text = Convert.ToString(task.z);
                    label22.Text = "x = " + Convert.ToString(task.ne.x);
                    label23.Text = "y = " + Convert.ToString(task.ne.y);
                }
                else
                {
                    Task_3a task = new Task_3a(n, m, nn, ee, min_discrepancy);
                    printdgv(dataGridView1, task.xx, n, m, "Test_3a_num");
                    printdgv(dataGridView2, task.xr, n, m, "Test_3a_ex");

                    label6.Text = Convert.ToString(task.ne.nn);
                    label8.Text = Convert.ToString(task.ne.ee);
                    label10.Text = Convert.ToString(task.z);
                    label22.Text = "x = " + Convert.ToString(task.ne.x);
                    label23.Text = "y = " + Convert.ToString(task.ne.y);
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int n = Convert.ToInt32(textBox1.Text);
            int m = Convert.ToInt32(textBox2.Text);
            double ee = Convert.ToDouble(textBox3.Text);
            int nn = Convert.ToInt32(textBox4.Text);

            if (radioButton1.Checked)
            {
                BasicTask task = new BasicTask(n, m, nn, ee, zeidel);
                BasicTask task2 = new BasicTask(2 * n, 2 * m, nn, ee, zeidel);
                printdgv(dataGridView4, task.xx, n, m, "Basic_num");
                printdgv(dataGridView3, task2.xx, n, m, "Basic_ex");
                double z = enuc(task.xx, task2.xx, n, m);

                label15.Text = Convert.ToString(task.ne.nn);
                label13.Text = Convert.ToString(task.ne.ee);
                label18.Text = Convert.ToString(task2.ne.nn);
                label11.Text = Convert.ToString(task2.ne.ee);
                label21.Text = Convert.ToString(z);
                label25.Text = "x = " + Convert.ToString(task.ne.x);
                label24.Text = "y = " + Convert.ToString(task.ne.y);
            }
            else
            {
                BasicTask task = new BasicTask(n, m, nn, ee, min_discrepancy);
                BasicTask task2 = new BasicTask(2 * n, 2 * m, nn, ee, min_discrepancy);
                printdgv(dataGridView4, task.xx, n, m, "Basic_num");
                printdgv(dataGridView3, task2.xx, n, m, "Basic_ex");
                double z = enuc(task.xx, task2.xx, n, m);

                label15.Text = Convert.ToString(task.ne.nn);
                label13.Text = Convert.ToString(task.ne.ee);
                label18.Text = Convert.ToString(task2.ne.nn);
                label11.Text = Convert.ToString(task2.ne.ee);
                label21.Text = Convert.ToString(z);
                label25.Text = "x = " + Convert.ToString(task.ne.x);
                label24.Text = "y = " + Convert.ToString(task.ne.y);
            }
        }
    }
}
