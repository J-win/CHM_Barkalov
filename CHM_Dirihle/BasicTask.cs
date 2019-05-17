using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CHM_Dirihle
{
    class BasicTask
    {
        int n, m;
        double h, k;
        public double[,] xx, b;
        public NE ne = new NE();

        public BasicTask(int n_, int m_, int nn, double ee, Func<double[,], double[,], int, int, double, double, NE, double[,]> method)
        {
            n = n_;
            m = m_;

            h = 2.0 / (double)n;
            k = 2.0 / (double)m;

            xx = new double[n + 1, m + 1];
            b = new double[n + 1, m + 1];

            for (int i = 0; i < n + 1; i++)
                for (int j = 0; j < m + 1; j++)
                {
                    xx[i, j] = 0.0;
                    b[i, j] = 0.0;
                }

            for (int i = 0; i < n + 1; i++)
                for (int j = 0; j < m + 1; j++)
                {
                    b[i, j] = -f(x(i), y(j));
                    if (i - 1 == 0)
                        b[i, j] -= mu1(y(j)) / (h * h);
                    if (i + 1 == n)
                        b[i, j] -= mu2(y(j)) / (h * h);
                    if (j - 1 == 0)
                        b[i, j] -= mu3(x(i)) / (k * k);
                    if (j + 1 == m)
                        b[i, j] -= mu4(x(i)) / (k * k);
                }

            ne.nn = nn;
            ne.ee = ee;
            xx = method(xx, b, n, m, h, k, ne);

            // Задание краев
            for (int i = 0; i < n + 1; i++)
            {
                xx[i, 0] = mu3(x(i));
                xx[i, m] = mu4(x(i));
            }
            for (int j = 0; j < m + 1; j++)
            {
                xx[0, j] = mu1(y(j));
                xx[n, j] = mu2(y(j));
            }
        }

        double f(double x, double y)
        {
            return Math.Abs(Math.Pow(Math.Sin(Math.PI * x * y), 3));
        }

        double mu1(double y)
        {
            return -y * y + 1;
        }

        double mu2(double y)
        {
            return -y * y + 1;
        }

        double mu3(double x)
        {
            return Math.Abs(Math.Sin(Math.PI * x));
        }

        double mu4(double x)
        {
            return Math.Abs(Math.Sin(Math.PI * x));
        }

        double x(int i)
        {
            return -1 + i * h;
        }

        double y(int j)
        {
            return -1 + j * k;
        }
    }
}
