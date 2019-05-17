using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Spline
{
    class Task3 : Task
    {
        public Task3(int n_, int nk_, bool flag) : base(n_, nk_, 0.0, 1.0, flag)
        {
        }
        protected override double func(double xx)
        {
            return (Math.Pow(1 + xx * xx, 1.0 / 3.0) + Math.Cos(10.0 * xx));
        }

        protected override double funcp(double xx)
        {
            return ((((2.0 / 3.0) * xx) / (Math.Pow(1 + xx * xx, 2.0 / 3.0))) - 10.0 * Math.Sin(10.0 * xx));
        }

        protected override double funcpp(double xx)
        {
            return ((((2.0 / 3.0) - ((2.0 / 9.0) * xx * xx)) / Math.Pow(1 + xx * xx, 5.0 / 3.0)) - 100.0 * Math.Cos(10.0 * xx));
        }
    }
}
