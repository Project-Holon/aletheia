/*
 * unit:     no
 * function: func_0209A524
 * address:  0x0209A524
 * packet:   pkt_02098B44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _dadd  0x0209AC04  arm
 *   _dgr   0x0209B864  arm
 *
 * fdlibm floor().  Identified by its two pool constants: huge = 1.0e300
 * (0x7E37E43C_8800759C, the classic fdlibm inexact-raising addend) and
 * 0xBFF00000, the high word of -1.0 that the |x| < 1, x < 0 arm returns.
 * The `huge + x > 0.0` guard is a soft-float __dadd followed by __dcmp_2,
 * which is why every arm of the function calls out twice.
 *
 * The leading `push {r0, r1, r2, r3}` at 0x0209A524 is the home area for the
 * register-passed double: the body reads x's words from [sp, #0x20]/[sp,
 * #0x24] through &x, and every return pops 16 bytes.  See the cluster header
 * docs/families/cluster_02098B44.h.
 */

typedef int i32;
typedef unsigned int u32;

#define HI(x) (((i32 *)&(x))[1])
#define LO(x) (((i32 *)&(x))[0])

static const double huge = 1.0e300;

double func_0209A524(double x)
{
    i32 i0, i1, j0;
    u32 i, j;

    i0 = HI(x);
    i1 = LO(x);
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20)
    {
        if (j0 < 0)
        {
            if (huge + x > 0.0)
            {
                if (i0 >= 0)
                {
                    i0 = i1 = 0;
                }
                else if (((i0 & 0x7fffffff) | i1) != 0)
                {
                    i0 = 0xbff00000;
                    i1 = 0;
                }
            }
        }
        else
        {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0)
                return x;
            if (huge + x > 0.0)
            {
                if (i0 < 0)
                    i0 += (0x00100000) >> j0;
                i0 &= (~i);
                i1 = 0;
            }
        }
    }
    else if (j0 > 51)
    {
        if (j0 == 0x400)
            return x + x;
        else
            return x;
    }
    else
    {
        i = ((u32)(0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0)
            return x;
        if (huge + x > 0.0)
        {
            if (i0 < 0)
            {
                if (j0 == 20)
                    i0 += 1;
                else
                {
                    j = i1 + (1 << (52 - j0));
                    if (j < (u32)i1)
                        i0 += 1;
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }
    HI(x) = i0;
    LO(x) = i1;
    return x;
}
