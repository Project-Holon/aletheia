/*
 * file:     msl_fdlibm_pow.c
 * unit:     yes
 * function: scalbn, __ieee754_pow, __ieee754_rem_pio2, __kernel_cos
 * address:  0x02097990
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from msl_c_lib.c by tools/splitfile.py.
 *
 * symbols:
 *   errno  0x02153FAC  data
 *   fabs  0x0209A504  arm
 *   frexp  0x0209A6E8  arm
 *   ldexp  0x0209A7A8  arm
 *   _double_arith_body  0x0209C5E0  arm
 *   scalbn  0x02097990  arm
 *   bp  0x020A6300  data
 *   dp_h  0x020A62F0  data
 *   dp_l  0x020A6310  data
 *   __float_nan  0x020A8818  data
 *   __kernel_rem_pio2  0x0209953C  arm
 *   npio2_hw  0x020A6320  data
 *   two_over_pi  0x020A63A0  data
 */
#include "msl_crt_shared_types.h"

#define HI(x) (((i32 *)&(x))[1])

#define LO(x) (((i32 *)&(x))[0])

/* Matched units compiled in this file, entered 4 bytes before their function:
 * unit_020979BC (0x020979BC) holds __ieee754_pow
 * unit_02098B44 (0x02098B44) holds __ieee754_rem_pio2
 * unit_02099224 (0x02099224) holds __kernel_cos
 */
typedef int i32;

extern double fabs(double x);

extern double frexp(double x, int *eptr);

extern double ldexp(double x, int n);

extern double _double_arith_body(double x);

extern double scalbn(double x, int n);

extern int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, const i32 *ipio2);

double __ieee754_pow(double x, double y);

int __ieee754_rem_pio2(double x, double *y);

double __kernel_cos(double x, double y);

extern int errno;

extern const float __float_nan;

extern const double bp[];

extern const double dp_h[];

extern const double dp_l[];

extern const i32 npio2_hw[];

extern const i32 two_over_pi[];

double scalbn(double x, int n)
{
    int t;
    double v = frexp(x, &t);
    t += n;
    return ldexp(v, t);
}

static const double
zero    =  0.0,
one	=  1.0,
two	=  2.0,
two53	=  9007199254740992.0,
huge	=  1.0e300,
tiny    =  1.0e-300,
L1  =  5.99999999999994648725e-01,
L2  =  4.28571428578550184252e-01,
L3  =  3.33333329818377432918e-01,
L4  =  2.72728123808534006489e-01,
L5  =  2.30660745775561754067e-01,
L6  =  2.06975017800338417784e-01,
P1   =  1.66666666666666019037e-01,
P2   = -2.77777777770155933842e-03,
P3   =  6.61375632143793436117e-05,
P4   = -1.65339022054652515390e-06,
P5   =  4.13813679705723846039e-08,
lg2  =  6.93147180559945286227e-01,
lg2_h  =  6.93147182464599609375e-01,
lg2_l  = -1.90465429995776804525e-09,
ovt =  8.0085662595372944372e-0017,
cp    =  9.61796693925975554329e-01,
cp_h  =  9.61796700954437255859e-01,
cp_l  = -7.02846165095275826516e-09,
ivln2    =  1.44269504088896338700e+00,
ivln2_h  =  1.44269502162933349609e+00,
ivln2_l  =  1.92596299112661746887e-08;

/*
 * MSL __ieee754_pow(x, y): fdlibm e_pow.c with the MSL edits listed in
 * docs/notes/pkt_020979C0.c.txt.  fabs = fabs, sqrt = _double_arith_body.
 * The machine entry is 0x020979BC (push {r0-r3} home for the register-passed
 * doubles), four bytes before the disasm body label __ieee754_pow.
 *
 * Front end dsi/1.2 (1.2p2 identical): kept &bp base across its three uses
 * and the push {r3-fp,lr} / sub sp,#0x78 frame; 1.1p1 splits the loads and
 * builds a different frame.
 *
 * The self-assignment `s = s;` after `p_h = y1*t1` emits no code; it is what
 * settles the r6/r7/r8 coloring of t2 (hi), s and the final exponent n over
 * 0x0BC8..0x1170 (without it the three rotate, 25 bytes out).  Found by the
 * permuter (wave 18, seed 1902) and reduced by hand to this one line.
 */
double __ieee754_pow(double x, double y)
{
	double z,ax,z_h,z_l,p_h,p_l;
	double y1,t1,t2,r,s,t,u,v,w;
	i32 i,j,k,yisint,n,n0;
	i32 hx,hy,ix,iy;
	u32 lx,ly;

	hx = HI(x); lx = LO(x);
	hy = HI(y); ly = LO(y);
	ix = hx&0x7fffffff;  iy = hy&0x7fffffff;

	if((iy|ly)==0) return one;

	if(ix > 0x7ff00000 || ((ix==0x7ff00000)&&(lx!=0)) ||
	   iy > 0x7ff00000 || ((iy==0x7ff00000)&&(ly!=0)))
		return x+y;

	yisint  = 0;
	if(hx<0) {
	    if(iy>=0x43400000) yisint = 2;
	    else if(iy>=0x3ff00000) {
		k = (iy>>20)-0x3ff;
		if(k>20) {
		    j = ly>>(52-k);
		    if((j<<(52-k))==ly) yisint = 2-(j&1);
		} else if(ly==0) {
		    j = iy>>(20-k);
		    if((j<<(20-k))==iy) yisint = 2-(j&1);
		}
	    }
	}

	if(ly==0) {
	    if (iy==0x7ff00000) {
	        if(((ix-0x3ff00000)|lx)==0)
		    return  y - y;
	        else if (ix >= 0x3ff00000)
		    return (hy>=0)? y: zero;
	        else
		    return (hy<0)?-y: zero;
	    }
	    if(iy==0x3ff00000) {
		if(hy<0) return one/x; else return x;
	    }
	    if(hy==0x40000000) return x*x;
	    if(hy==0x3fe00000) {
		if(hx>=0)
		return _double_arith_body(x);
	    }
	}

	ax   = fabs(x);
	if(lx==0) {
	    if(ix==0x7ff00000||ix==0||ix==0x3ff00000){
		z = ax;
		if(hy<0) z = one/z;
		if(hx<0) {
		    if(((ix-0x3ff00000)|yisint)==0) {
			z = (z-z)/(z-z);
		    } else if(yisint==1)
			z = -z;
		}
		return z;
	    }
	}

	n0 = (hx>>31)+1;

	if((n0|yisint)==0) {
	    errno = 33;
	    return __float_nan;
	}

	if(iy>0x41e00000) {
	    if(iy>0x43f00000){
		if(ix<=0x3fefffff) return (hy<0)? huge*huge:tiny*tiny;
		if(ix>=0x3ff00000) return (hy>0)? huge*huge:tiny*tiny;
	    }
	    if(ix<0x3fefffff) return (hy<0)? huge*huge:tiny*tiny;
	    if(ix>0x3ff00000) return (hy>0)? huge*huge:tiny*tiny;
	    t = x-one;
	    w = (t*t)*(0.5-t*(0.3333333333333333333333-t*0.25));
	    u = ivln2_h*t;
	    v = t*ivln2_l-w*ivln2;
	    t1 = u+v;
	    LO(t1) = 0;
	    t2 = v-(t1-u);
	} else {
	    double ss,s2,s_h,s_l,t_h,t_l;
	    n = 0;
	    if(ix<0x00100000)
		{ax *= two53; n -= 53; ix = HI(ax); }
	    n  += ((ix)>>20)-0x3ff;
	    j  = ix&0x000fffff;
	    ix = j|0x3ff00000;
	    if(j<=0x3988E) k=0;
	    else if(j<0xBB67A) k=1;
	    else {k=0;n+=1;ix -= 0x00100000;}
	    HI(ax) = ix;

	    u = ax-bp[k];
	    v = one/(ax+bp[k]);
	    ss = u*v;
	    s_h = ss;
	    LO(s_h) = 0;
	    t_h = zero;
	    HI(t_h)=((ix>>1)|0x20000000)+0x00080000+(k<<18);
	    t_l = ax - (t_h-bp[k]);
	    s_l = v*((u-s_h*t_h)-s_h*t_l);
	    s2 = ss*ss;
	    r = s2*s2*(L1+s2*(L2+s2*(L3+s2*(L4+s2*(L5+s2*L6)))));
	    r += s_l*(s_h+ss);
	    s2  = s_h*s_h;
	    t_h = 3.0+s2+r;
	    LO(t_h) = 0;
	    t_l = r-((t_h-3.0)-s2);
	    u = s_h*t_h;
	    v = s_l*t_h+t_l*ss;
	    p_h = u+v;
	    LO(p_h) = 0;
	    p_l = v-(p_h-u);
	    z_h = cp_h*p_h;
	    z_l = cp_l*p_h+p_l*cp+dp_l[k];
	    t = (double)n;
	    t1 = (((z_h+z_l)+dp_h[k])+t);
	    LO(t1) = 0;
	    t2 = z_l-(((t1-t)-dp_h[k])-z_h);
	}

	s = one;
	if((n0|(yisint-1))==0) s = -one;

	y1  = y;
	LO(y1) = 0;
	p_l = (y-y1)*t1+y*t2;
	p_h = y1*t1;
	s = s;		/* no code; pins the t2/s/n register coloring */
	z = p_l+p_h;
	j = HI(z);
	i = LO(z);
	if (j>=0x40900000) {
	    if(((j-0x40900000)|i)!=0)
		return s*huge*huge;
	    else {
		if(p_l+ovt>z-p_h) return s*huge*huge;
	    }
	} else if((j&0x7fffffff)>=0x4090cc00 ) {
	    if(((j-0xc090cc00)|i)!=0)
		return s*tiny*tiny;
	    else {
		if(p_l<=z-p_h) return s*tiny*tiny;
	    }
	}
	i = j&0x7fffffff;
	k = (i>>20)-0x3ff;
	n = 0;
	if(i>0x3fe00000) {
	    n = j+(0x00100000>>(k+1));
	    k = ((n&0x7fffffff)>>20)-0x3ff;
	    t = zero;
	    HI(t) = (n&~(0x000fffff>>k));
	    n = ((n&0x000fffff)|0x00100000)>>(20-k);
	    if(j<0) n = -n;
	    p_h -= t;
	}
	t = p_l+p_h;
	LO(t) = 0;
	u = t*lg2_h;
	v = (p_l-(t-p_h))*lg2+t*lg2_l;
	z = u+v;
	w = v-(z-u);
	t  = z*z;
	t1  = z - t*(P1+t*(P2+t*(P3+t*(P4+t*P5))));
	r  = (z*t1)/(t1-two)-(w+z*w);
	z  = one-(r-z);
	j  = HI(z);
	j += (n<<20);
	if((j>>20)<=0) z = scalbn(z,n);
	else HI(z) += (n<<20);
	return s*z;
}

static const double
half =  5.00000000000000000000e-01,
two24 =  1.67772160000000000000e+07,
invpio2 =  6.36619772367581382433e-01,
pio2_1  =  1.57079632673412561417e+00,
pio2_1t =  6.07710050650619224932e-11,
pio2_2  =  6.07710050630396597660e-11,
pio2_2t =  2.02226624879595063154e-21,
pio2_3  =  2.02226624871116645580e-21,
pio2_3t =  8.47842766036889956997e-32;

/*
 * fdlibm __ieee754_rem_pio2(x, y), e_rem_pio2.c transcribed unchanged.  The
 * machine entry is 0x02098B44, four bytes before the disasm body label
 * __ieee754_rem_pio2: the compiler's push {r0-r3} spilling the register-passed
 * double, because HI(x) takes the address of x.  The body is MSL runtime
 * (layout/runtime_arm9.txt, _msl_double_fn_1); the unit exists so the 4-byte
 * worklist row at the stub is reproduced as part of its function.
 *
 * Front end dsi/1.2 (wave 17): the loop store tx[i] = (double)(int)z is two
 * str (1.1p1 merges them into stm), the same pin that fits __ieee754_pow at
 * 0x020979BC.  Fabs = fabs, __kernel_rem_pio2 = __kernel_rem_pio2;
 * npio2_hw and two_over_pi resolve through the sole-ref/data class.
 */
int __ieee754_rem_pio2(double x, double *y)
{
    double z, w, t, r, fn;
    double tx[3];
    int e0, i, j, nx, n, ix, hx;

    hx = HI(x);
    ix = hx & 0x7fffffff;
    if (ix <= 0x3fe921fb)
    {
        y[0] = x;
        y[1] = 0;
        return 0;
    }
    if (ix < 0x4002d97c)
    {
        if (hx > 0)
        {
            z = x - pio2_1;
            if (ix != 0x3ff921fb)
            {
                y[0] = z - pio2_1t;
                y[1] = (z - y[0]) - pio2_1t;
            }
            else
            {
                z -= pio2_2;
                y[0] = z - pio2_2t;
                y[1] = (z - y[0]) - pio2_2t;
            }
            return 1;
        }
        else
        {
            z = x + pio2_1;
            if (ix != 0x3ff921fb)
            {
                y[0] = z + pio2_1t;
                y[1] = (z - y[0]) + pio2_1t;
            }
            else
            {
                z += pio2_2;
                y[0] = z + pio2_2t;
                y[1] = (z - y[0]) + pio2_2t;
            }
            return -1;
        }
    }
    if (ix <= 0x413921fb)
    {
        t = fabs(x);
        n = (int)(t * invpio2 + half);
        fn = (double)n;
        r = t - fn * pio2_1;
        w = fn * pio2_1t;
        if (n < 32 && ix != npio2_hw[n - 1])
        {
            y[0] = r - w;
        }
        else
        {
            j = ix >> 20;
            y[0] = r - w;
            i = j - (((HI(y[0])) >> 20) & 0x7ff);
            if (i > 16)
            {
                t = r;
                w = fn * pio2_2;
                r = t - w;
                w = fn * pio2_2t - ((t - r) - w);
                y[0] = r - w;
                i = j - (((HI(y[0])) >> 20) & 0x7ff);
                if (i > 49)
                {
                    t = r;
                    w = fn * pio2_3;
                    r = t - w;
                    w = fn * pio2_3t - ((t - r) - w);
                    y[0] = r - w;
                }
            }
        }
        y[1] = (r - y[0]) - w;
        if (hx < 0)
        {
            y[0] = -y[0];
            y[1] = -y[1];
            return -n;
        }
        else
            return n;
    }
    if (ix >= 0x7ff00000)
    {
        y[0] = y[1] = x - x;
        return 0;
    }
    LO(z) = LO(x);
    e0 = (ix >> 20) - 1046;
    HI(z) = ix - (e0 << 20);
    for (i = 0; i < 2; i++)
    {
        tx[i] = (double)((int)(z));
        z = (z - tx[i]) * two24;
    }
    tx[2] = z;
    nx = 3;
    while (tx[nx - 1] == zero)
        nx--;
    n = __kernel_rem_pio2(tx, y, e0, nx, 2, two_over_pi);
    if (hx < 0)
    {
        y[0] = -y[0];
        y[1] = -y[1];
        return -n;
    }
    return n;
}

double __kernel_cos(double x, double y)
{
    static const double one = 1.00000000000000000000e+00;
    static const double C1 = 4.16666666666666019037e-02;
    static const double C2 = -1.38888888888741095749e-03;
    static const double C3 = 2.48015872894767294178e-05;
    static const double C4 = -2.75573143513906633035e-07;
    static const double C5 = 2.08757232129817482790e-09;
    static const double C6 = -1.13596475577881948265e-11;

    double a, hz, z, r, qx;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix < 0x3e400000)
    {
        if ((int)x == 0)
            return one;
    }
    z = x * x;
    r = z * (C1 + z * (C2 + z * (C3 + z * (C4 + z * (C5 + z * C6)))));
    if (ix < 0x3FD33333)
        return one - (0.5 * z - (z * r - x * y));
    else
    {
        if (ix > 0x3fe90000)
        {
            qx = 0.28125;
        }
        else
        {
            HI(qx) = ix - 0x00200000;
            LO(qx) = 0;
        }
        hz = 0.5 * z - qx;
        a = one - qx;
        return a - (hz - (z * r - x * y));
    }
}
