using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CHM_Dirihle
{
    class Task_3a
    {
        int n, m;
        double h, k;
        public double z;
        public double[,] xr, xx, b;
        public NE ne = new NE();

        double x(int i)
        {
            return -1 + i * h;
        }
        double y(int j)
        {
            return -1 + j * k;
        }

        double u(double x, double y)
        {
            return 1 - x * x - y * y;
        }
        double f(double x, double y)
        {
            return 4;
        }

        public Task_3a(int n_, int m_, double nn, double ee, Func<double[,], double[,], int, int, double, double, NE, int, int, double[,]> method)
        {
            n = n_;
            m = m_;

            int n1 = n / 2;
            int m1 = m / 2;

            h = 2.0 / (double)n;
            k = 2.0 / (double)m;

            xr = new double[n + 1, m + 1];
            xx = new double[n + 1, m + 1];
            b = new double[n + 1, m + 1];

            for (int i = 0; i < n + 1; i++)
                for (int j = 0; j < m + 1; j++)
                {
                    xr[i, j] = 0.0;
                    xx[i, j] = 0.0;
                    b[i, j] = 0.0;
                }

            for (int i = 0; i < n1; i++)
                for (int j = 0; j < m + 1; j++)
                {
                    xr[i, j] = u(x(i), y(j));
                    b[i, j] = -f(x(i), y(j));
                    if (i - 1 == 0)
                        b[i, j] -= u(x(0), y(j)) / (h * h);
                    if ((i + 1 == n1) && (j >= m1))
                        b[i, j] -= u(x(n1), y(j)) / (h * h);
                    if (j - 1 == 0)
                        b[i, j] -= u(x(i), y(0)) / (k * k);
                    if (j + 1 == m)
                        b[i, j] -= u(x(i), y(m)) / (k * k);
                }

            for (int i = n1; i < n; i++)
                for (int j = 0; j < m1; j++)
                {
                    xr[i, j] = u(x(i), y(j));
                    b[i, j] = -f(x(i), y(j));
                    if (i + 1 == n)
                        b[i, j] -= u(x(n), y(j)) / (h * h);
                    if (j - 1 == 0)
                        b[i, j] -= u(x(i), y(0)) / (k * k);
                    if (j + 1 == m1)
                        b[i, j] -= u(x(i), y(m1)) / (k * k);
                }

            ne.nn = nn;
            ne.ee = ee;
            xx = method(xx, b, n, m, h, k, ne, n1, m1);

            z = 0;
            for (int i = 1; i < n; i++)
                for (int j = 1; j < m; j++)
                    if (z < Math.Abs(xx[i, j] - xr[i, j]))
                        z = Math.Abs(xx[i, j] - xr[i, j]);

            // Задание краев
            for (int i = 0; i < n + 1; i++)
            {
                xx[i, 0] = u(x(i), y(0));
                if (i < n1)
                    xx[i, m] = u(x(i), y(m));
                else
                    xx[i, m1] = u(x(i), y(m1));
            }
            for (int j = 0; j < m + 1; j++)
            {
                xx[0, j] = u(x(0), y(j));
                if (j < m1)
                    xx[n, j] = u(x(n), y(j));
                else
                    xx[n1, j] = u(x(n1), y(j));
            }
        }
    }
}
