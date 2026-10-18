/*
 * file:     msl_fdlibm.c
 * unit:     yes
 * function: __kernel_rem_pio2, __kernel_sin, copysign, cos, fabs, floor, frexp, ldexp, sin, pow, stricmp, strnicmp, strcmp_nocase
 * address:  0x0209953C
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * MSL C (fdlibm helpers and the string compares) between msl_c_lib.c and the runtime.a
 * floating-point routines of cw_runtime.c.  Its own file: it defines
 * the fdlibm statics zero, one, two24 and huge that msl_c_lib.c also
 * defines (two fdlibm source files).
 *
 * symbols:
 *   _dsub        0x0209AF34  arm
 *   _dmul        0x0209B2E8  arm
 *   _dadd        0x0209AC04  arm
 *   _dfix        0x0209C508  arm
 *   _dflt        0x0209B750  arm
 *   _deq         0x0209BA3C  arm
 *   _dgeq        0x0209B7CC  arm
 *   scalbn  0x02097990  arm
 *   init_jk      0x020A64A8  data
 *   PIo2         0x020A64B8  data
 *   _dgr  0x0209B864  arm
 *   __fpclassifyd  0x020921F4  arm
 *   __ieee754_pow  0x020979BC  arm
 *   __tolower_map  0x020A60DC  data
 *   MSL_C_LIB_StrNICmp  0x02091C40  arm
 *   __ieee754_rem_pio2  0x02098B44  arm
 *   __kernel_cos  0x02099224  arm
 *   _double_arith_prelude  0x0209AC04  arm
 *   __dmul  0x0209B2E8  arm
 */
#define HI(x) (((i32 *)&(x))[1])
#define LO(x) (((i32 *)&(x))[0])
/* Matched units compiled in this file, entered 4 bytes before their function:
 * unit_0209A0EC (0x0209A0EC) holds __kernel_sin
 * unit_0209A390 (0x0209A390) holds cos
 * unit_0209AA08 (0x0209AA08) holds sin
 */

typedef int i32;

typedef unsigned int u32;

typedef unsigned char u8;

extern double scalbn(double x, int n);
extern double _dsub(double x, double y);
extern int _d2s(double x);
extern double __kernel_cos(double x, double y);
extern double __kernel_sin(double x, double y, int iy);
extern int __ieee754_rem_pio2(double x, double *y);
extern int __fpclassifyd(double x);
extern double __ieee754_pow(double x, double y);
extern int MSL_C_LIB_StrNICmp(const u8 *s1, const u8 *s2, int n);
int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, const int *ipio2);
double copysign(double x, double y);
double cos(double x);
double fabs(double x);
double floor(double x);
double frexp(double x, int *eptr);
double ldexp(double x, int n);
double sin(double x);
double pow(double x, double y);
int stricmp(const u8 *s1, const u8 *s2);
int strnicmp(const u8 *s1, const u8 *s2, int n);
int strcmp_nocase(const u8 *s1, const u8 *s2);
asm void _double_arith_prelude(void);
asm void __dmul(void);
asm void _d2f(void);
extern const int init_jk[];
extern const double PIo2[];
extern const u8 __tolower_map[];



static const double
zero   = 0.0,
one    = 1.0,
two24  = 1.67772160000000000000e+07,
twon24 = 5.96046447753906250000e-08;



int __kernel_rem_pio2(double *x, double *y, int e0, int nx, int prec, const int *ipio2)
{
	int jz,jx,jv,jp,jk,carry,n,iq[20],i,j,k,m,q0,ih;
	double z,fw,f[20],fq[20],q[20];

	jk = init_jk[prec];
	jp = jk;

	jx =  nx-1;
	jv = (e0-3)/24; if(jv<0) jv=0;
	q0 =  e0-24*(jv+1);

	j = jv-jx; m = jx+jk; i = 0;
	if(m>=0) for(;i<=m;i++,j++) f[i] = (j<0)? zero : (double) ipio2[j];

	for (i=0;i<=jk;i++) {
	    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j]; q[i] = fw;
	}

	jz = jk;
recompute:
	i=0; j=jz; z=q[jz]; if(j>0) for(;j>0;i++,j--) {
	    fw    =  (double)((int)(twon24* z));
	    iq[i] =  (int)(z-two24*fw);
	    z     =  q[j-1]+fw;
	}

	z  = scalbn(z,q0);
	z -= 8.0*floor(z*0.125);
	n  = (int) z;
	z -= (double)n;
	ih = 0;
	if(q0>0) {
	    i  = (iq[jz-1]>>(24-q0)); n += i;
	    iq[jz-1] -= i<<(24-q0);
	    ih = iq[jz-1]>>(23-q0);
	}
	else if(q0==0) ih = iq[jz-1]>>23;
	else if(z>=0.5) ih=2;

	if(ih>0) {
	    n += 1; carry = 0;
	    for(i=0;i<jz ;i++) {
		j = iq[i];
		if(carry==0) {
		    if(j!=0) {
			carry = 1; iq[i] = 0x1000000- j;
		    }
		} else  iq[i] = 0xffffff - j;
	    }
	    if(q0>0) {
	        switch(q0) {
	        case 1:
	    	   iq[jz-1] &= 0x7fffff; break;
	    	case 2:
	    	   iq[jz-1] &= 0x3fffff; break;
	        }
	    }
	    if(ih==2) {
		z = one - z;
		if(carry!=0) z -= scalbn(one,q0);
	    }
	}

	if(z==zero) {
	    j = 0;
	    for (i=jz-1;i>=jk;i--) j |= iq[i];
	    if(j==0) {
		for(k=1;iq[jk-k]==0;k++);

		for(i=jz+1;i<=jz+k;i++) {
		    f[jx+i] = (double) ipio2[jv+i];
		    for(j=0,fw=0.0;j<=jx;j++) fw += x[j]*f[jx+i-j];
		    q[i] = fw;
		}
		jz += k;
		goto recompute;
	    }
	}

	if(z==0.0) {
	    jz -= 1; q0 -= 24;
	    while(iq[jz]==0) { jz--; q0-=24;}
	} else {
	    z = scalbn(z,-q0);
	    if(z>=two24) {
		fw = (double)((int)(twon24*z));
		iq[jz] = (int)(z-two24*fw);
		jz += 1; q0 += 24;
		iq[jz] = (int) fw;
	    } else iq[jz] = (int) z ;
	}

	fw = scalbn(one,q0);
	for(i=jz;i>=0;i--) {
	    q[i] = fw*(double)iq[i]; fw*=twon24;
	}

	for(i=jz;i>=0;i--) {
	    for(fw=0.0,k=0;k<=jp&&k<=jz-i;k++) fw += PIo2[k]*q[i+k];
	    fq[jz-i] = fw;
	}

	switch(prec) {
	    case 0:
		fw = 0.0;
		for (i=jz;i>=0;i--) fw += fq[i];
		y[0] = (ih==0)? fw: -fw;
		break;
	    case 1:
	    case 2:
		fw = 0.0;
		for (i=jz;i>=0;i--) fw += fq[i];
		y[0] = (ih==0)? fw: -fw;
		fw = fq[0]-fw;
		for (i=1;i<=jz;i++) fw += fq[i];
		y[1] = (ih==0)? fw: -fw;
		break;
	    case 3:
		for (i=jz;i>0;i--) {
		    fw      = fq[i-1]+fq[i];
		    fq[i]  += fq[i-1]-fw;
		    fq[i-1] = fw;
		}
		for (i=jz;i>1;i--) {
		    fw      = fq[i-1]+fq[i];
		    fq[i]  += fq[i-1]-fw;
		    fq[i-1] = fw;
		}
		for (fw=0.0,i=jz;i>=2;i--) fw += fq[i];
		if(ih==0) {
		    y[0] =  fq[0]; y[1] =  fq[1]; y[2] =  fw;
		} else {
		    y[0] = -fq[0]; y[1] = -fq[1]; y[2] = -fw;
		}
	}
	return n&7;
}


/*
 * fdlibm __kernel_sin().  The machine entry is 0x0209A0EC, four bytes before
 * the disasm body label __kernel_sin: 0x0209A0EC is the compiler's
 * `push {r0-r3}` spilling the double arguments x (r0:r1) and y (r2:r3), so
 * the body reads them from the stack and pops 16 bytes on every return.
 * Both the stub address and the body label are worklist entries, so the unit
 * is anchored at the stub and the function list records the body label.
 *
 * Callees by address:
 *   __dmul  __dmul(double, double)
 *   _double_arith_prelude  __dadd(double, double)
 *   _dsub  __dsub(double, double)
 *   _d2s  __d2s (double -> int)
 */
double __kernel_sin(double x, double y, int iy)
{
    static const double half = 5.00000000000000000000e-01;
    static const double S1 = -1.66666666666666324348e-01;
    static const double S2 = 8.33333333332248946124e-03;
    static const double S3 = -1.98412698298579493134e-04;
    static const double S4 = 2.75573137070700676789e-06;
    static const double S5 = -2.50507602534068634195e-08;
    static const double S6 = 1.58969099521155010221e-10;

    double z, r, v;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix < 0x3e400000)
    {
        if ((int)x == 0)
            return x;
    }
    z = x * x;
    v = z * x;
    r = S2 + z * (S3 + z * (S4 + z * (S5 + z * S6)));
    if (iy == 0)
        return x + v * (S1 + z * r);
    else
        return x - ((z * (half * y - v * r) - y) - v * S1);
}


/*
 * note:     EXACT* not EXACT: scan_listing puts the next label 4 bytes past
 *          this function's real end (0x0209A390, a pool-adjacent follower),
 *          so the printed extent is 44 against a compiled 40.  Bytes all
 *          match and there are no relocation sites.
 *
 * MSL copysign(): combines the magnitude of the first double with the sign
 * of the second, reading both hi words off the stack after `push {r0-r3}`
 * (the address-of-a-register-parameter idiom, doubled for two doubles).
 */
double copysign(double x, double y)
{
    ((u32 *)&x)[1] = (((u32 *)&x)[1] & 0x7fffffff) | (((u32 *)&y)[1] & 0x80000000);
    return x;
}


/*
 * fdlibm cos().  The machine entry is 0x0209A390, four bytes before the
 * disasm label cos: the disassembler never saw the real entry
 * because nothing calls cos by name, so it labelled the body and left the
 * prologue stub as an unlabelled word.  That stub is the compiler's
 * `push {r0-r3}` for the register-passed double argument, which is why the
 * body reads x from [sp, #0x20]/[sp, #0x24] and why every return ends
 * `add sp, sp, #0x10` to pop the spilled pair.  Comparing from the label
 * alone starts after the stub and cannot line up; anchored here the whole
 * 372-byte function matches, and the header's function list records the
 * body label so the worklist entry at 0x0209A394 is covered too.
 *
 * |x| <= pi/4 short-circuits to __kernel_cos(x, 0.0); the general path
 * reduces with __ieee754_rem_pio2 and selects a kernel on n & 3.  Unary
 * minus and x-x lower to the MSL soft-float subtract helper _dsub (the
 * table entry `__dadd_dsub` at 0x0209AF34 is its subtract entry).
 *
 * Callees by address:
 *   __kernel_cos  __kernel_cos(double, double)
 *   __kernel_sin  __kernel_sin(double, double, int)
 *   __ieee754_rem_pio2  __ieee754_rem_pio2(double, double *)
 */
double cos(double x)
{
    double y[2];
    double z = 0.0;
    int n;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix <= 0x3fe921fb)
        return __kernel_cos(x, z);
    else if (ix >= 0x7ff00000)
        return x - x;
    else
    {
        n = __ieee754_rem_pio2(x, y);
        switch (n & 3)
        {
        case 0:
            return __kernel_cos(y[0], y[1]);
        case 1:
            return -__kernel_sin(y[0], y[1], 1);
        case 2:
            return -__kernel_cos(y[0], y[1]);
        default:
            return __kernel_sin(y[0], y[1], 1);
        }
    }
}


/*
 * MSL fabs(): the hi word of the double is cleared via `&x`, which is the
 * address-of-a-register-parameter idiom and produces `push {r0-r3}`; the
 * mask folds to `bic r1, r1, #0x80000000`.
 */
double fabs(double x)
{
    ((u32 *)&x)[1] &= 0x7fffffff;
    return x;
}


static const double huge = 1.0e300;



/*
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
double floor(double x)
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


static const double two54 = 1.80143985094819840000e+16;



/*
 * fdlibm frexp().  Word access goes through the address of the register
 * parameter `x`, which is why the prologue preserves r0-r3 even though this
 * is not a call that needs them.  Scaled subnormals are multiplied by the
 * inline double constant two54; the compiler keeps its zero low word in r5
 * and only pools the 0x43500000 high half.
 */
double frexp(double x, int *eptr)
{
    int hx;
    int ix;
    int lx;

    hx = HI(x);
    lx = LO(x);
    ix = 0x7fffffff & hx;
    *eptr = 0;
    if (ix >= 0x7ff00000 || ((ix | lx) == 0))
        return x;
    if (ix < 0x00100000)
    {
        x *= two54;
        hx = HI(x);
        ix = hx & 0x7fffffff;
        *eptr = -54;
    }
    *eptr += (ix >> 20) - 1022;
    hx = (hx & 0x800fffff) | 0x3fe00000;
    HI(x) = hx;
    return x;
}


static const double twom54  = 5.55111512312578270212e-17;



static const double tiny    = 1.0e-300;



/*
 * note:     EXACT* not EXACT: the next function's own home-area push
 *          (0x0209AA08, sin's `push {r0, r1, r2, r3}`, already covered by
 *          src/matched/unit_0209AA08.c) carries no label of its own, so the
 *          printed extent is 612 against a compiled 608.  All 608 compared
 *          bytes match and all 12 relocations resolve.
 * MSL ldexp(double, int), with fdlibm scalbn() inlined into it.
 *
 * The wrapper is the first eight instructions: __fpclassify(x) (0x020921F4)
 * and, only when that says the value is finite-and-not-one-of-the-low-classes,
 * an equality test against 0.0 that lowers to the soft-float __dcmp_5 at
 * 0x0209BA3C.  Either test failing returns x untouched; everything after
 * 0x0209A7F8 is scalbn's own body.
 *
 * Identified by the full fdlibm scalbn constant set in the pool at 0x0209A9DC:
 * two54 (0x43500000), twom54 (0x3C900000), huge = 1.0e300
 * (0x7E37E43C_8800759C), tiny = 1.0e-300 (0x01A56E1F_C2F8F359) and the
 * +-50000 exponent clamps (0x0000C350 / 0xFFFF3CB0).
 *
 * The leading `push {r0, r1, r2, r3}` at 0x0209A7A8 is the home area for the
 * register-passed double: the body reads and writes x's words from
 * [sp, #0x10]/[sp, #0x14] through &x, and every return pops 16 bytes.
 * See the cluster header docs/families/cluster_02098B44.h.
 */
double ldexp(double x, int n)
{
    i32 k, hx, lx;

    if (__fpclassifyd(x) <= 2 || x == 0.0)
        return x;

    hx = HI(x);
    lx = LO(x);
    k = (hx & 0x7ff00000) >> 20;
    if (k == 0)
    {
        if ((lx | (hx & 0x7fffffff)) == 0)
            return x;
        x *= two54;
        hx = HI(x);
        k = ((hx & 0x7ff00000) >> 20) - 54;
        if (n < -50000)
            return tiny * x;
    }
    if (k == 0x7ff)
        return x + x;
    k = k + n;
    if (k > 0x7fe)
        return huge * copysign(huge, x);
    if (k > 0)
    {
        HI(x) = (hx & 0x800fffff) | (k << 20);
        return x;
    }
    if (k <= -54)
    {
        if (n > 50000)
            return huge * copysign(huge, x);
        else
            return tiny * copysign(tiny, x);
    }
    k += 54;
    HI(x) = (hx & 0x800fffff) | (k << 20);
    return x * twom54;
}


/*
 * fdlibm sin().  The machine entry is 0x0209AA08, four bytes before the
 * disasm body label sin: the stub is the compiler's `push {r0-r3}`
 * spilling the register-passed double argument, so the body reads x from the
 * stack and pops 16 bytes on every return.  The unit is anchored at the stub
 * and the function list records the body label the worklist names.
 *
 * |x| <= pi/4 short-circuits to __kernel_sin(x, 0.0, 0); the general path
 * reduces with __ieee754_rem_pio2 and selects a kernel on n & 3.  Negation
 * and x-x lower to the MSL soft-float subtract helper _dsub.
 *
 * Callees by address:
 *   __kernel_sin  __kernel_sin(double, double, int)
 *   __kernel_cos  __kernel_cos(double, double)
 *   __ieee754_rem_pio2  __ieee754_rem_pio2(double, double *)
 *   _dsub  __dsub(double, double)
 */
double sin(double x)
{
    double y[2];
    double z = 0.0;
    int n;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix <= 0x3fe921fb)
        return __kernel_sin(x, z, 0);
    else if (ix >= 0x7ff00000)
        return x - x;
    else
    {
        n = __ieee754_rem_pio2(x, y);
        switch (n & 3)
        {
        case 0:
            return __kernel_sin(y[0], y[1], 1);
        case 1:
            return __kernel_cos(y[0], y[1]);
        case 2:
            return -__kernel_sin(y[0], y[1], 1);
        default:
            return -__kernel_cos(y[0], y[1]);
        }
    }
}


double pow(double x, double y)
{
    return __ieee754_pow(x, y);
}


/*
 * note:     EXACT* not EXACT: the label following this function in the
 *          listing is the veneer block at 0x0209AC04 (0x0209ABEC/0x0209ABF8
 *          are unlabelled), so the printed extent is 120 against a compiled
 *          96.  All 96 compared bytes (code + literal pool) match and the
 *          single relocation resolves via `literal`.
 * Case-insensitive string compare: each byte is mapped through the 256-byte
 * table at 0x020A60DC when it is below 0x80, then compared as unsigned.
 * The `>= 0` half of the guard is what emits the `cmp #0; blt` before the
 * `cmp #0x80; ldrblt`, even though the byte load is unsigned.
 *
 * The interleaved declarations (`int c1; u8 m1; int c2; u8 m2;`) matter:
 * they make mwccarm color the c1 mask into ip and the raw c2 into lr, which
 * is what the original does.  Declaring the two mask temps together instead
 * swaps those two scratch registers (9-byte DIFF).
 */
int stricmp(const u8 *s1, const u8 *s2)
{
    const u8 *tab = __tolower_map;
    int c1;
    u8 m1;
    int c2;
    u8 m2;

    for (;;)
    {
        c1 = *s1++;
        if (c1 >= 0 && c1 < 0x80)
            c1 = tab[c1];
        m1 = (u8)c1;

        c2 = *s2++;
        if (c2 >= 0 && c2 < 0x80)
            c2 = tab[c2];
        m2 = (u8)c2;

        if (m1 < m2)
            return -1;
        if (m1 > m2)
            return 1;
        if (m1 == 0)
            return 0;
    }
}

int strnicmp(const u8 *s1, const u8 *s2, int n)
{
    return MSL_C_LIB_StrNICmp(s1, s2, n);
}

int strcmp_nocase(const u8 *s1, const u8 *s2)
{
    return stricmp(s1, s2);
}
