using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Spline
{
    class Task1 : Task
    {
        public Task1(int n_, int nk_) : base(n_, nk_, -1.0, 1.0, true)
        {
        }

        protected override double func(double xx)
        {
            if (xx <= 0)
                return Math.Pow(xx, 3) + 3 * Math.Pow(xx, 2);
            else
                return -1.0 * Math.Pow(xx, 3) + 3 * Math.Pow(xx, 2);
        }

        protected override double funcp(double xx)
        {
            if (xx <= 0)
                return 3.0 * Math.Pow(xx, 2) + 6.0 * xx;
            else
                return -3.0 * Math.Pow(xx, 2) + 6.0 * xx;
        }

        protected override double funcpp(double xx)
        {
            if (xx <= 0)
                return 6.0 * xx + 6.0;
            else
                return -6.0 * xx + 6.0;
        }
    }
}
