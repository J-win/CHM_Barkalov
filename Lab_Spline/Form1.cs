using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ZedGraph;

namespace Spline
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int n = Convert.ToInt32(textBox1.Text);
            int k = Convert.ToInt32(textBox2.Text);

            if (radioButton1.Checked)
            {
                Task t = new Task1(n, k * n);
                Task tt = new Task1(200, 600);

                t.addSplineDGV(dataGridView1);
                t.addResSplineDGV(dataGridView2);

                tt.addFSGraph(zedGraphControl1);
                t.addFpSpGraph(zedGraphControl2);
                t.addFppSppGraph(zedGraphControl3);

                t.addRGraph(zedGraphControl4);
                t.addRpGraph(zedGraphControl5);
                t.addRppGraph(zedGraphControl6);

                label2.Text = Convert.ToString(n);
                label4.Text = Convert.ToString(k * n);
                label6.Text = Convert.ToString(t.maxr);
                label8.Text = Convert.ToString(t.maxrx);
                label11.Text = Convert.ToString(t.maxrp);
                label15.Text = Convert.ToString(t.maxrpx);
                label12.Text = Convert.ToString(t.maxrpp);
                label16.Text = Convert.ToString(t.maxrppx);
            }

            if (radioButton2.Checked)
            {
                Task t = new Task2(n, k * n, radioButton7.Checked);
                Task tt = new Task2(200, 600, radioButton7.Checked);

                t.addSplineDGV(dataGridView1);
                t.addResSplineDGV(dataGridView2);

                tt.addFSGraph(zedGraphControl1);
                t.addFpSpGraph(zedGraphControl2);
                t.addFppSppGraph(zedGraphControl3);

                t.addRGraph(zedGraphControl4);
                t.addRpGraph(zedGraphControl5);
                t.addRppGraph(zedGraphControl6);

                label2.Text = Convert.ToString(n);
                label4.Text = Convert.ToString(k * n);
                label6.Text = Convert.ToString(t.maxr);
                label8.Text = Convert.ToString(t.maxrx);
                label11.Text = Convert.ToString(t.maxrp);
                label15.Text = Convert.ToString(t.maxrpx);
                label12.Text = Convert.ToString(t.maxrpp);
                label16.Text = Convert.ToString(t.maxrppx);
            }

            if (radioButton3.Checked)
            {
                Task t = new Task3(n, k * n, radioButton7.Checked);
                Task tt = new Task3(200, 600, radioButton7.Checked);

                t.addSplineDGV(dataGridView1);
                t.addResSplineDGV(dataGridView2);

                tt.addFSGraph(zedGraphControl1);
                t.addFpSpGraph(zedGraphControl2);
                t.addFppSppGraph(zedGraphControl3);

                t.addRGraph(zedGraphControl4);
                t.addRpGraph(zedGraphControl5);
                t.addRppGraph(zedGraphControl6);

                label2.Text = Convert.ToString(n);
                label4.Text = Convert.ToString(k * n);
                label6.Text = Convert.ToString(t.maxr);
                label8.Text = Convert.ToString(t.maxrx);
                label11.Text = Convert.ToString(t.maxrp);
                label15.Text = Convert.ToString(t.maxrpx);
                label12.Text = Convert.ToString(t.maxrpp);
                label16.Text = Convert.ToString(t.maxrppx);
            }

            if (radioButton4.Checked)
            {
                Task t = new Task4(n, k * n, radioButton7.Checked);
                Task tt = new Task4(200, 600, radioButton7.Checked);

                t.addSplineDGV(dataGridView1);
                t.addResSplineDGV(dataGridView2);

                tt.addFSGraph(zedGraphControl1);
                t.addFpSpGraph(zedGraphControl2);
                t.addFppSppGraph(zedGraphControl3);

                t.addRGraph(zedGraphControl4);
                t.addRpGraph(zedGraphControl5);
                t.addRppGraph(zedGraphControl6);

                label2.Text = Convert.ToString(n);
                label4.Text = Convert.ToString(k * n);
                label6.Text = Convert.ToString(t.maxr);
                label8.Text = Convert.ToString(t.maxrx);
                label11.Text = Convert.ToString(t.maxrp);
                label15.Text = Convert.ToString(t.maxrpx);
                label12.Text = Convert.ToString(t.maxrpp);
                label16.Text = Convert.ToString(t.maxrppx);
            }
        }
    }
}
