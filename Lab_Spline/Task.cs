using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ZedGraph;

namespace Spline
{
    abstract class Task
    {
        protected double[] a;
        protected double[] b;
        protected double[] c;
        protected double[] d;

        protected double[] s;
        protected double[] sp;
        protected double[] spp;

        protected double[] f;
        protected double[] fp;
        protected double[] fpp;

        protected double[] r;
        protected double[] rp;
        protected double[] rpp;

        protected double[] x;
        protected double[] xk;

        protected int n;
        protected int nk;

        protected double a0;
        protected double b0;

        protected double h;
        protected double hk;

        protected double nu1;
        protected double nu2;

        protected double a_;
        protected double b_;

        public double maxr = 0.0;
        public double maxrp = 0.0;
        public double maxrpp = 0.0;
        public double maxrx = 0.0;
        public double maxrpx = 0.0;
        public double maxrppx = 0.0;

        protected abstract double func(double xx);
        protected abstract double funcp(double xx);
        protected abstract double funcpp(double xx);

        protected double spline(double a, double b, double c, double d, double x, double xk)
        {
            return a + b * (xk - x) + (c / 2) * Math.Pow((xk - x), 2) + (d / 6) * Math.Pow((xk - x), 3);
        }
        protected double splinep(double a, double b, double c, double d, double x, double xk)
        {
            return b + c * (xk - x) + 0.5 * d * Math.Pow((xk - x), 2);
        }
        protected double splinepp(double a, double b, double c, double d, double x, double xk)
        {
            return c + d * (xk - x);
        }

        protected void derivative()
        {
            f = new double[nk + 1];
            fp = new double[nk + 1];
            fpp = new double[nk + 1];

            s = new double[nk + 1];
            sp = new double[nk + 1];
            spp = new double[nk + 1];

            for (int i = 0; i < nk + 1; i++)
            {
                if (i != nk)
                {
                    xk[i + 1] = xk[i] + hk;
                }
                f[i] = func(xk[i]);
                fp[i] = funcp(xk[i]);
                fpp[i] = funcpp(xk[i]);
            }

            int j = 0;
            for (int i = 0; i < n; i++)
            {
                 while ((j < nk + 1) && (xk[j] < x[i + 1] + hk / 2))
                 {
                      s[j] = spline(a[i + 1], b[i + 1], c[i + 1], d[i + 1], x[i + 1], xk[j]);
                      sp[j] = splinep(a[i + 1], b[i + 1], c[i + 1], d[i + 1], x[i + 1], xk[j]);
                      spp[j] = splinepp(a[i + 1], b[i + 1], c[i + 1], d[i + 1], x[i + 1], xk[j]);

                      j = j + 1;
                 }
            }
        }

        protected void error()
        {
            r = new double[nk + 1];
            rp = new double[nk + 1];
            rpp = new double[nk + 1];

            for (int i = 0; i < nk + 1; i++)
            {
                r[i] = Math.Abs(f[i] - s[i]);
                rp[i] = Math.Abs(fp[i] - sp[i]);
                rpp[i] = Math.Abs(fpp[i] - spp[i]);

                if (r[i] > maxr)
                {
                    maxr = r[i];
                    maxrx = xk[i];
                }

                if (rp[i] > maxrp)
                {
                    maxrp = rp[i];
                    maxrpx = xk[i];
                }

                if (rpp[i] > maxrpp)
                {
                    maxrpp = rpp[i];
                    maxrppx = xk[i];
                }
            }
        }

        public Task(int n_, int nk_, double a_, double b_, bool flag)
        {
            n = n_;
            nk = nk_;

            x = new double[n + 1];
            f = new double[n + 1];
            xk = new double[nk + 1];

            a0 = a_;
            b0 = b_;

            if (flag)
            {
                nu1 = funcpp(a0);
                nu2 = funcpp(b0);
            }
            else
            {
                nu1 = 0.0;
                nu2 = 0.0;
            }

            xk[0] = x[0] = a0;
            xk[nk] = x[n] = b0;

            h = (b0 - a0) / n;
            hk = (b0 - a0) / nk;

            for (int i = 0; i < n + 1; i++)
            {
                if (i != n)
                {
                    x[i + 1] = x[i] + h;
                }
                f[i] = func(x[i]);
            }

            this.create();
            this.derivative();
            this.error();
        }

        protected void create()
        {
            double[] alpha = new double[n];
            double[] beta = new double[n];

            a = new double[n + 1];
            b = new double[n + 1];
            c = new double[n + 1];
            d = new double[n + 1];

            alpha[0] = 0;
            beta[0] = nu1;

            c[n] = nu2;
            c[0] = nu1;

            for (int i = 0; i < n - 1; i++)
            {
                alpha[i + 1] = 1 / (-4 - alpha[i]);
                beta[i + 1] = (beta[i] - 6 * (f[i + 2] - 2 * f[i + 1] + f[i]) / (h * h)) / (-4 - alpha[i]);
            }

            for (int i = n - 1; i >= 0; i--)
            {
                c[i] = alpha[i] * c[i + 1] + beta[i];
                b[i + 1] = (f[i + 1] - f[i]) / h + c[i + 1] * h / 3 + c[i] * h / 6;
                d[i + 1] = (c[i + 1] - c[i]) / h;
                a[i + 1] = f[i + 1];
            }
        }

        public void addSplineDGV(DataGridView data)
        {
            data.Rows.Clear();
            for (int i = 0; i < n; i++)
            {
                data.Rows.Add();
                data.Rows[i].Cells[0].Value = i + 1;
                data.Rows[i].Cells[1].Value = x[i];
                data.Rows[i].Cells[2].Value = x[i + 1];
                data.Rows[i].Cells[3].Value = a[i + 1];
                data.Rows[i].Cells[4].Value = b[i + 1];
                data.Rows[i].Cells[5].Value = c[i + 1];
                data.Rows[i].Cells[6].Value = d[i + 1];
            }
        }

        public void addResSplineDGV(DataGridView data)
        {
            data.Rows.Clear();
            for (int j = 0; j < nk; j++)
            {
                data.Rows.Add();
                data.Rows[j].Cells[0].Value = j;
                data.Rows[j].Cells[1].Value = xk[j];
                data.Rows[j].Cells[2].Value = f[j];
                data.Rows[j].Cells[3].Value = s[j];
                data.Rows[j].Cells[4].Value = r[j];
                data.Rows[j].Cells[5].Value = fp[j];
                data.Rows[j].Cells[6].Value = sp[j];
                data.Rows[j].Cells[7].Value = rp[j];
                data.Rows[j].Cells[8].Value = fpp[j];
                data.Rows[j].Cells[9].Value = spp[j];
                data.Rows[j].Cells[10].Value = rpp[j];
            }
        }

        public void addFSGraph(ZedGraphControl zed)
        {
            GraphPane panel = zed.GraphPane;
            panel.CurveList.Clear();

            PointPairList f_list = new PointPairList();
            PointPairList s_list = new PointPairList();

            for (int i = 0; i < nk; i++)
            {
                f_list.Add(xk[i], f[i]);
                s_list.Add(xk[i], s[i]);
            }

            LineItem Curve = panel.AddCurve("F(x)", f_list, Color.Red, SymbolType.None);
            LineItem Curve1 = panel.AddCurve("S(x)", s_list, Color.Blue, SymbolType.None);

            zed.AxisChange();
            zed.Invalidate();
        }

        public void addFpSpGraph(ZedGraphControl zed)
        {
            GraphPane panel = zed.GraphPane;
            panel.CurveList.Clear();

            PointPairList f_list = new PointPairList();
            PointPairList s_list = new PointPairList();

            for (int i = 0; i < nk; i++)
            {
                f_list.Add(xk[i], fp[i]);
                s_list.Add(xk[i], sp[i]);
            }

            LineItem Curve = panel.AddCurve("F'(x)", f_list, Color.Red, SymbolType.None);
            LineItem Curve1 = panel.AddCurve("S'(x)", s_list, Color.Blue, SymbolType.None);

            zed.AxisChange();
            zed.Invalidate();
        }

        public void addFppSppGraph(ZedGraphControl zed)
        {
            GraphPane panel = zed.GraphPane;
            panel.CurveList.Clear();

            PointPairList f_list = new PointPairList();
            PointPairList s_list = new PointPairList();

            for (int i = 0; i < nk; i++)
            {
                f_list.Add(xk[i], fpp[i]);
                s_list.Add(xk[i], spp[i]);
            }

            LineItem Curve = panel.AddCurve("F''(x)", f_list, Color.Red, SymbolType.None);
            LineItem Curve1 = panel.AddCurve("S''(x)", s_list, Color.Blue, SymbolType.None);

            zed.AxisChange();
            zed.Invalidate();
        }

        public void addRGraph(ZedGraphControl zed)
        {
            GraphPane panel = zed.GraphPane;
            panel.CurveList.Clear();

            PointPairList r_list = new PointPairList();

            for (int i = 0; i < nk; i++)
                r_list.Add(xk[i], r[i]);

            LineItem Curve = panel.AddCurve("F(x) - S(x)", r_list, Color.Red, SymbolType.None);

            zed.AxisChange();
            zed.Invalidate();
        }

        public void addRpGraph(ZedGraphControl zed)
        {
            GraphPane panel = zed.GraphPane;
            panel.CurveList.Clear();

            PointPairList r_list = new PointPairList();

            for (int i = 0; i < nk; i++)
                r_list.Add(xk[i], rp[i]);

            LineItem Curve = panel.AddCurve("F'(x) - S'(x)", r_list, Color.Red, SymbolType.None);

            zed.AxisChange();
            zed.Invalidate();
        }

        public void addRppGraph(ZedGraphControl zed)
        {
            GraphPane panel = zed.GraphPane;
            panel.CurveList.Clear();

            PointPairList r_list = new PointPairList();

            for (int i = 0; i < nk; i++)
                r_list.Add(xk[i], rpp[i]);

            LineItem Curve = panel.AddCurve("F''(x) - S''(x)", r_list, Color.Red, SymbolType.None);

            zed.AxisChange();
            zed.Invalidate();
        }
    }
}
