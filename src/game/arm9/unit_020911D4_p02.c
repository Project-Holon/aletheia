/*
 * file:     unit_020911D4_p02.c
 * unit:     yes
 * function: func_0209953C, func_0209A0F0, func_0209A368, func_0209A394, func_0209A504, func_0209A524, func_0209A6E8, func_0209A7A8, func_0209AA0C, func_0209AB80, func_0209AB8C, func_0209ABEC, func_0209ABF8, _double_arith_prelude, __dadd_dsub, func_0209B2E8, func_0209B64C
 * address:  0x0209953C
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _dsub        0x0209AF34  arm
 *   _dmul        0x0209B2E8  arm
 *   _dadd        0x0209AC04  arm
 *   _dfix        0x0209C508  arm
 *   _dflt        0x0209B750  arm
 *   _deq         0x0209BA3C  arm
 *   _dgeq        0x0209B7CC  arm
 *   func_02097990  0x02097990  arm
 *   init_jk      0x020A64A8  data
 *   PIo2         0x020A64B8  data
 *   _dgr  0x0209B864  arm
 *   func_020921F4  0x020921F4  arm
 *   func_020979BC  0x020979BC  arm
 *   g_020A60DC  0x020A60DC  data
 *   func_02091C40  0x02091C40  arm
 */
#define HI(x) (((i32 *)&(x))[1])
#define LO(x) (((i32 *)&(x))[0])
/* Matched units compiled in this file, entered 4 bytes before their function:
 * unit_0209A0EC (0x0209A0EC) holds func_0209A0F0
 * unit_0209A390 (0x0209A390) holds func_0209A394
 * unit_0209AA08 (0x0209AA08) holds func_0209AA0C
 */

typedef int i32;

typedef unsigned int u32;

typedef unsigned char u8;

extern double func_02097990(double x, int n);
extern double func_0209B2E8(double x, double y);
extern double func_0209AC04(double x, double y);
extern double func_0209AF34(double x, double y);
extern int func_0209C508(double x);
extern double func_02099224(double x, double y);
extern double func_0209A0EC(double x, double y, int iy);
extern int func_02098B44(double x, double *y);
extern int func_020921F4(double x);
extern double func_020979BC(double x, double y);
extern int func_02091C40(const u8 *s1, const u8 *s2, int n);
int func_0209953C(double *x, double *y, int e0, int nx, int prec, const int *ipio2);
double func_0209A0F0(double x, double y, int iy);
double func_0209A368(double x, double y);
double func_0209A394(double x);
double func_0209A504(double x);
double func_0209A524(double x);
double func_0209A6E8(double x, int *eptr);
double func_0209A7A8(double x, int n);
double func_0209AA0C(double x);
double func_0209AB80(double x, double y);
int func_0209AB8C(const u8 *s1, const u8 *s2);
int func_0209ABEC(const u8 *s1, const u8 *s2, int n);
int func_0209ABF8(const u8 *s1, const u8 *s2);
asm void _double_arith_prelude(void);
asm void __dmul(void);
asm void _d2f(void);
extern const int init_jk[];
extern const double PIo2[];
extern const u8 g_020A60DC[];



static const double
zero   = 0.0,
one    = 1.0,
two24  = 1.67772160000000000000e+07,
twon24 = 5.96046447753906250000e-08;



int func_0209953C(double *x, double *y, int e0, int nx, int prec, const int *ipio2)
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

	z  = func_02097990(z,q0);
	z -= 8.0*func_0209A524(z*0.125);
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
		if(carry!=0) z -= func_02097990(one,q0);
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
	    z = func_02097990(z,-q0);
	    if(z>=two24) {
		fw = (double)((int)(twon24*z));
		iq[jz] = (int)(z-two24*fw);
		jz += 1; q0 += 24;
		iq[jz] = (int) fw;
	    } else iq[jz] = (int) z ;
	}

	fw = func_02097990(one,q0);
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
 * the disasm body label func_0209A0F0: 0x0209A0EC is the compiler's
 * `push {r0-r3}` spilling the double arguments x (r0:r1) and y (r2:r3), so
 * the body reads them from the stack and pops 16 bytes on every return.
 * Both the stub address and the body label are worklist entries, so the unit
 * is anchored at the stub and the function list records the body label.
 *
 * Callees by address:
 *   func_0209B2E8  __dmul(double, double)
 *   func_0209AC04  __dadd(double, double)
 *   func_0209AF34  __dsub(double, double)
 *   func_0209C508  __d2s (double -> int)
 */
double func_0209A0F0(double x, double y, int iy)
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
 *           this function's real end (0x0209A390, a pool-adjacent follower),
 *           so the printed extent is 44 against a compiled 40.  Bytes all
 *           match and there are no relocation sites.
 *
 * MSL copysign(): combines the magnitude of the first double with the sign
 * of the second, reading both hi words off the stack after `push {r0-r3}`
 * (the address-of-a-register-parameter idiom, doubled for two doubles).
 */
double func_0209A368(double x, double y)
{
    ((u32 *)&x)[1] = (((u32 *)&x)[1] & 0x7fffffff) | (((u32 *)&y)[1] & 0x80000000);
    return x;
}



/*
 * fdlibm cos().  The machine entry is 0x0209A390, four bytes before the
 * disasm label func_0209A394: the disassembler never saw the real entry
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
 *   func_02099224  __kernel_cos(double, double)
 *   func_0209A0EC  __kernel_sin(double, double, int)
 *   func_02098B44  __ieee754_rem_pio2(double, double *)
 */
double func_0209A394(double x)
{
    double y[2];
    double z = 0.0;
    int n;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix <= 0x3fe921fb)
        return func_02099224(x, z);
    else if (ix >= 0x7ff00000)
        return x - x;
    else
    {
        n = func_02098B44(x, y);
        switch (n & 3)
        {
        case 0:
            return func_02099224(y[0], y[1]);
        case 1:
            return -func_0209A0EC(y[0], y[1], 1);
        case 2:
            return -func_02099224(y[0], y[1]);
        default:
            return func_0209A0EC(y[0], y[1], 1);
        }
    }
}



/*
 * MSL fabs(): the hi word of the double is cleared via `&x`, which is the
 * address-of-a-register-parameter idiom and produces `push {r0-r3}`; the
 * mask folds to `bic r1, r1, #0x80000000`.
 */
double func_0209A504(double x)
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



static const double two54 = 1.80143985094819840000e+16;



/*
 * fdlibm frexp().  Word access goes through the address of the register
 * parameter `x`, which is why the prologue preserves r0-r3 even though this
 * is not a call that needs them.  Scaled subnormals are multiplied by the
 * inline double constant two54; the compiler keeps its zero low word in r5
 * and only pools the 0x43500000 high half.
 */
double func_0209A6E8(double x, int *eptr)
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
 *           (0x0209AA08, sin's `push {r0, r1, r2, r3}`, already covered by
 *           src/matched/unit_0209AA08.c) carries no label of its own, so the
 *           printed extent is 612 against a compiled 608.  All 608 compared
 *           bytes match and all 12 relocations resolve.
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
double func_0209A7A8(double x, int n)
{
    i32 k, hx, lx;

    if (func_020921F4(x) <= 2 || x == 0.0)
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
        return huge * func_0209A368(huge, x);
    if (k > 0)
    {
        HI(x) = (hx & 0x800fffff) | (k << 20);
        return x;
    }
    if (k <= -54)
    {
        if (n > 50000)
            return huge * func_0209A368(huge, x);
        else
            return tiny * func_0209A368(tiny, x);
    }
    k += 54;
    HI(x) = (hx & 0x800fffff) | (k << 20);
    return x * twom54;
}



/*
 * fdlibm sin().  The machine entry is 0x0209AA08, four bytes before the
 * disasm body label func_0209AA0C: the stub is the compiler's `push {r0-r3}`
 * spilling the register-passed double argument, so the body reads x from the
 * stack and pops 16 bytes on every return.  The unit is anchored at the stub
 * and the function list records the body label the worklist names.
 *
 * |x| <= pi/4 short-circuits to __kernel_sin(x, 0.0, 0); the general path
 * reduces with __ieee754_rem_pio2 and selects a kernel on n & 3.  Negation
 * and x-x lower to the MSL soft-float subtract helper _dsub.
 *
 * Callees by address:
 *   func_0209A0EC  __kernel_sin(double, double, int)
 *   func_02099224  __kernel_cos(double, double)
 *   func_02098B44  __ieee754_rem_pio2(double, double *)
 *   func_0209AF34  __dsub(double, double)
 */
double func_0209AA0C(double x)
{
    double y[2];
    double z = 0.0;
    int n;
    int ix;

    ix = HI(x) & 0x7fffffff;
    if (ix <= 0x3fe921fb)
        return func_0209A0EC(x, z, 0);
    else if (ix >= 0x7ff00000)
        return x - x;
    else
    {
        n = func_02098B44(x, y);
        switch (n & 3)
        {
        case 0:
            return func_0209A0EC(y[0], y[1], 1);
        case 1:
            return func_02099224(y[0], y[1]);
        case 2:
            return -func_0209A0EC(y[0], y[1], 1);
        default:
            return -func_02099224(y[0], y[1]);
        }
    }
}



double func_0209AB80(double x, double y)
{
    return func_020979BC(x, y);
}



/*
 * note:     EXACT* not EXACT: the label following this function in the
 *           listing is the veneer block at 0x0209AC04 (0x0209ABEC/0x0209ABF8
 *           are unlabelled), so the printed extent is 120 against a compiled
 *           96.  All 96 compared bytes (code + literal pool) match and the
 *           single relocation resolves via `literal`.
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
int func_0209AB8C(const u8 *s1, const u8 *s2)
{
    const u8 *tab = g_020A60DC;
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


int func_0209ABEC(const u8 *s1, const u8 *s2, int n)
{
    return func_02091C40(s1, s2, n);
}


int func_0209ABF8(const u8 *s1, const u8 *s2)
{
    return func_0209AB8C(s1, s2);
}


asm void _double_arith_prelude(void)
{
    stmdb sp!, {r4, lr}
    eors ip, r1, r3
    eormi r3, r3, #0x80000000
    bmi L_0209AF44
L_0209AC14:
    subs ip, r0, r2
    sbcs lr, r1, r3
    bhs L_0209AC30
    adds r2, r2, ip
    adc r3, r3, lr
    subs r0, r0, ip
    sbc r1, r1, lr
L_0209AC30:
    mov lr, #0x80000000
    mov ip, r1, lsr #0x14
    orr r1, lr, r1, lsl #11
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #0xb
    movs r4, ip, lsl #0x15
    cmnne r4, #0x200000
    beq L_0209AD2C
    mov r4, r3, lsr #0x14
    orr r3, lr, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs lr, r4, lsl #0x15
    beq L_0209AD74
L_0209AC68:
    subs r4, ip, r4
    beq L_0209ACC0
    cmp r4, #0x20
    ble L_0209ACA4
    cmp r4, #0x38
    movge r4, #0x3f
    sub r4, r4, #0x20
    rsb lr, r4, #0x20
    orrs lr, r2, r3, lsl lr
    mov r2, r3, lsr r4
    orrne r2, r2, #1
    adds r0, r0, r2
    adcs r1, r1, #0
    blo L_0209ACE8
    b L_0209ACCC
L_0209ACA4:
    rsb lr, r4, #0x20
    movs lr, r2, lsl lr
    rsb lr, r4, #0x20
    mov r2, r2, lsr r4
    orr r2, r2, r3, lsl lr
    mov r3, r3, lsr r4
    orrne r2, r2, #1
L_0209ACC0:
    adds r0, r0, r2
    adcs r1, r1, r3
    blo L_0209ACE8
L_0209ACCC:
    add ip, ip, #1
    and r4, r0, #1
    movs r1, r1, rrx
    orr r0, r4, r0, rrx
    mov lr, ip, lsl #0x15
    cmn lr, #0x200000
    beq L_0209AEF8
L_0209ACE8:
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, ip, lsl #20
    tst r2, #0x80000000
    ldmeqia sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, lr}
    bx lr
L_0209AD2C:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bics ip, ip, #0x800
    beq L_0209AD98
    orrs r4, r0, r1, lsl #1
    bne L_0209AED4
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    beq L_0209AEC0
    cmn r4, #0x200000
    bne L_0209AEC0
    orrs r4, r2, r3, lsl #1
    beq L_0209AEC0
    b L_0209AED4
L_0209AD74:
    cmp r4, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bic ip, ip, #0x800
    bics r4, r4, #0x800
    beq L_0209AE04
    orrs r4, r2, r3, lsl #1
    bne L_0209AED4
    b L_0209AEC0
L_0209AD98:
    orrs r4, r0, r1, lsl #1
    beq L_0209ADD8
    mov ip, #1
    bic r1, r1, #0x80000000
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    cmnne r4, #0x200000
    mov r4, r4, lsr #0x15
    orr r4, r4, lr, lsr #20
    beq L_0209AD74
    orr r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    b L_0209AC68
L_0209ADD8:
    mov ip, r3, lsr #0x14
    mov r1, r3, lsl #0xb
    orr r1, r1, r2, lsr #21
    mov r0, r2, lsl #0xb
    movs r4, ip, lsl #0x15
    beq L_0209AE8C
    cmn r4, #0x200000
    bne L_0209AE8C
    orrs r4, r0, r1, lsl #1
    beq L_0209AEC0
    b L_0209AED8
L_0209AE04:
    orrs r4, r2, r3, lsl #1
    beq L_0209AE9C
    mov r4, #1
    bic r3, r3, #0x80000000
    cmp r1, #0
    bpl L_0209AE28
    orr ip, ip, lr, lsr #20
    orr r4, r4, lr, lsr #20
    b L_0209AC68
L_0209AE28:
    adds r0, r0, r2
    adcs r1, r1, r3
    blo L_0209AE48
    add ip, ip, #1
    and r4, r0, #1
    movs r1, r1, rrx
    mov r0, r0, rrx
    orr r0, r0, r4
L_0209AE48:
    cmp r1, #0
    subges ip, ip, #1
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmeqia sp!, {r4, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqia sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, lr}
    bxeq lr
L_0209AE8C:
    mov r1, r3
    mov r0, r2
    ldmia sp!, {r4, lr}
    bx lr
L_0209AE9C:
    cmp r1, #0
    subges ip, ip, #1
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmia sp!, {r4, lr}
    bx lr
L_0209AEC0:
    ldr r1, [pc, #0x50]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
L_0209AED4:
    mov r1, r3
L_0209AED8:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
L_0209AEF8:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    ldr r1, [pc, #0xc]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
    dcd 0x7FF00000
    eor r1, r1, r3
    eor r3, r1, r3
    eor r1, r1, r3
    eor r0, r0, r2
    eor r2, r0, r2
    eor r0, r0, r2
__dadd_dsub:
    stmdb sp!, {r4, lr}
    eors ip, r1, r3
    eormi r3, r3, #0x80000000
    bmi L_0209AC14
L_0209AF44:
    subs ip, r0, r2
    sbcs lr, r1, r3
    bhs L_0209AF64
    eor lr, lr, #0x80000000
    adds r2, r2, ip
    adc r3, r3, lr
    subs r0, r0, ip
    sbc r1, r1, lr
L_0209AF64:
    mov lr, #0x80000000
    mov ip, r1, lsr #0x14
    orr r1, lr, r1, lsl #11
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #0xb
    movs r4, ip, lsl #0x15
    cmnne r4, #0x200000
    beq L_0209B168
    mov r4, r3, lsr #0x14
    orr r3, lr, r3, lsl #11
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs lr, r4, lsl #0x15
    beq L_0209B1B0
L_0209AF9C:
    subs r4, ip, r4
    beq L_0209B044
    cmp r4, #0x20
    ble L_0209AFD8
    cmp r4, #0x38
    movge r4, #0x3f
    sub r4, r4, #0x20
    rsb lr, r4, #0x20
    orrs lr, r2, r3, lsl lr
    mov r2, r3, lsr r4
    orrne r2, r2, #1
    subs r0, r0, r2
    sbcs r1, r1, #0
    bmi L_0209B000
    b L_0209B0F0
L_0209AFD8:
    rsb lr, r4, #0x20
    movs lr, r2, lsl lr
    rsb lr, r4, #0x20
    mov r2, r2, lsr r4
    orr r2, r2, r3, lsl lr
    mov r3, r3, lsr r4
    orrne r2, r2, #1
    subs r0, r0, r2
    sbcs r1, r1, r3
    bpl L_0209B0F0
L_0209B000:
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, ip, lsl #20
    tst r2, #0x80000000
    ldmeqia sp!, {r4, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, lr}
    bx lr
L_0209B044:
    subs r0, r0, r2
    sbc r1, r1, r3
    orrs lr, r1, r0
    beq L_0209B2D4
    mov lr, ip, lsl #0x14
    and lr, lr, #0x80000000
    bic ip, ip, #0x800
    cmp r1, #0
    bmi L_0209B0CC
    bne L_0209B07C
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0
    bmi L_0209B098
L_0209B07C:
    clz r4, r1
    movs r1, r1, lsl r4
    rsb r4, r4, #0x20
    orr r1, r1, r0, lsr r4
    rsb r4, r4, #0x20
    mov r0, r0, lsl r4
    sub ip, ip, r4
L_0209B098:
    cmp ip, #0
    bgt L_0209B0D4
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    ldmia sp!, {r4, lr}
    bx lr
L_0209B0CC:
    cmp r1, #0
    subges ip, ip, #1
L_0209B0D4:
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmia sp!, {r4, lr}
    bx lr
L_0209B0F0:
    mov lr, ip, lsl #0x14
    and lr, lr, #0x80000000
    bic ip, ip, #0x800
    cmp r1, #0
    bne L_0209B114
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0
    bmi L_0209B130
L_0209B114:
    clz r4, r1
    movs r1, r1, lsl r4
    rsb r4, r4, #0x20
    orr r1, r1, r0, lsr r4
    rsb r4, r4, #0x20
    mov r0, r0, lsl r4
    sub ip, ip, r4
L_0209B130:
    cmp ip, #0
    orrgt ip, ip, lr, lsr #20
    bgt L_0209B000
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    ldmia sp!, {r4, lr}
    bx lr
L_0209B168:
    cmp ip, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bics ip, ip, #0x800
    beq L_0209B1D4
    orrs r4, r0, r1, lsl #1
    bne L_0209B2B0
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    beq L_0209B29C
    cmn r4, #0x200000
    bne L_0209B29C
    orrs r4, r2, r3, lsl #1
    beq L_0209B2C4
    b L_0209B2B0
L_0209B1B0:
    cmp r4, #0x800
    movge lr, #0x80000000
    movlt lr, #0
    bic ip, ip, #0x800
    bics r4, r4, #0x800
    beq L_0209B24C
    orrs r4, r2, r3, lsl #1
    bne L_0209B2B0
    b L_0209B29C
L_0209B1D4:
    orrs r4, r0, r1, lsl #1
    beq L_0209B214
    mov ip, #1
    bic r1, r1, #0x80000000
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r4, r4, lsl #0x15
    cmnne r4, #0x200000
    mov r4, r4, lsr #0x15
    orr r4, r4, lr, lsr #20
    beq L_0209B1B0
    orr r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    b L_0209AF9C
L_0209B214:
    mov ip, r3, lsr #0x14
    mov r1, r3, lsl #0xb
    orr r1, r1, r2, lsr #21
    mov r0, r2, lsl #0xb
    movs r4, ip, lsl #0x15
    beq L_0209B240
    cmn r4, #0x200000
    bne L_0209B268
    orrs r4, r0, r1, lsl #1
    bne L_0209B2B4
    b L_0209B29C
L_0209B240:
    orrs r4, r0, r1, lsl #1
    beq L_0209B2D4
    b L_0209B268
L_0209B24C:
    orrs r4, r2, r3, lsl #1
    beq L_0209B278
    mov r4, #1
    bic r3, r3, #0x80000000
    orr ip, ip, lr, lsr #20
    orr r4, r4, lr, lsr #20
    b L_0209AF9C
L_0209B268:
    mov r1, r3
    mov r0, r2
    ldmia sp!, {r4, lr}
    bx lr
L_0209B278:
    cmp r1, #0
    subges ip, ip, #1
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmia sp!, {r4, lr}
    bx lr
L_0209B29C:
    ldr r1, [pc, #0x40]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
L_0209B2B0:
    mov r1, r3
L_0209B2B4:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
L_0209B2C4:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, lr}
    bx lr
L_0209B2D4:
    mov r1, #0
    mov r0, #0
    ldmia sp!, {r4, lr}
    bx lr
    dcd 0x7FF00000
}



asm void __dmul(void)
{
    stmdb sp!, {r4, r5, r6, r7, lr}
    eor lr, r1, r3
    and lr, lr, #0x80000000
    mov ip, r1, lsr #0x14
    mov r1, r1, lsl #0xb
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #0xb
    movs r6, ip, lsl #0x15
    cmnne r6, #0x200000
    beq L_0209B3F0
    orr r1, r1, #0x80000000
    bic ip, ip, #0x800
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    cmnne r5, #0x200000
    beq L_0209B438
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
L_0209B33C:
    add ip, r4, ip
    umull r5, r4, r0, r2
    umull r7, r6, r0, r3
    adds r4, r7, r4
    adc r6, r6, #0
    umull r7, r0, r1, r2
    adds r4, r7, r4
    adcs r0, r0, r6
    umull r7, r2, r1, r3
    adc r1, r2, #0
    adds r0, r0, r7
    adc r1, r1, #0
    orrs r4, r4, r5
    orrne r0, r0, #1
    cmp r1, #0
    blt L_0209B388
    sub ip, ip, #1
    adds r0, r0, r0
    adc r1, r1, r1
L_0209B388:
    add ip, ip, #2
    subs ip, ip, #0x400
    bmi L_0209B524
    beq L_0209B524
    mov r6, ip, lsl #0x14
    cmn r6, #0x100000
    bmi L_0209B624
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, ip, lsl #20
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B3F0:
    bics ip, ip, #0x800
    beq L_0209B44C
    orrs r6, r0, r1, lsl #1
    bne L_0209B5D8
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    beq L_0209B42C
    cmn r5, #0x200000
    bne L_0209B5C4
    orrs r5, r2, r3, lsl #1
    beq L_0209B5C4
    b L_0209B5D8
L_0209B42C:
    orrs r5, r3, r2
    beq L_0209B5EC
    b L_0209B5C4
L_0209B438:
    bics r4, r4, #0x800
    beq L_0209B4E0
    orrs r6, r2, r3, lsl #1
    bne L_0209B5D8
    b L_0209B5C4
L_0209B44C:
    orrs r6, r0, r1, lsl #1
    beq L_0209B4B4
    mov ip, #1
    cmp r1, #0
    bne L_0209B470
    sub ip, ip, #0x20
    movs r1, r0
    mov r0, #0
    bmi L_0209B48C
L_0209B470:
    clz r6, r1
    movs r1, r1, lsl r6
    rsb r6, r6, #0x20
    orr r1, r1, r0, lsr r6
    rsb r6, r6, #0x20
    mov r0, r0, lsl r6
    sub ip, ip, r6
L_0209B48C:
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    cmnne r5, #0x200000
    beq L_0209B438
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
    b L_0209B33C
L_0209B4B4:
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    beq L_0209B638
    cmn r5, #0x200000
    bne L_0209B638
    orrs r6, r2, r3, lsl #1
    beq L_0209B5EC
    b L_0209B5D8
L_0209B4E0:
    orrs r5, r2, r3, lsl #1
    beq L_0209B638
    mov r4, #1
    cmp r3, #0
    bne L_0209B504
    sub r4, r4, #0x20
    movs r3, r2
    mov r2, #0
    bmi L_0209B33C
L_0209B504:
    clz r6, r3
    movs r3, r3, lsl r6
    rsb r6, r6, #0x20
    orr r3, r3, r2, lsr r6
    rsb r6, r6, #0x20
    mov r2, r2, lsl r6
    sub r4, r4, r6
    b L_0209B33C
L_0209B524:
    cmn ip, #0x34
    beq L_0209B5BC
    bmi L_0209B614
    mov r2, r1
    mov r3, r0
    add r4, ip, #0x34
    cmp r4, #0x20
    movge r2, r3
    movge r3, #0
    subge r4, r4, #0x20
    rsb r5, r4, #0x20
    mov r2, r2, lsl r4
    orr r2, r2, r3, lsr r5
    movs r3, r3, lsl r4
    orrne r2, r2, #1
    rsb ip, ip, #0xc
    cmp ip, #0x20
    movge r0, r1
    movge r1, #0
    subge ip, ip, #0x20
    rsb r4, ip, #0x20
    mov r0, r0, lsr ip
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr ip
    cmp r2, #0
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqia sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B5BC:
    orr r0, r0, r1, lsl #1
    b L_0209B5FC
L_0209B5C4:
    ldr r1, [pc, #0x7c]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B5D8:
    mov r1, r3
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B5EC:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B5FC:
    movs r2, r0
    mov r1, lr
    mov r0, #0
    addne r0, r0, #1
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B614:
    mov r1, lr
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B624:
    ldr r1, [pc, #0x1c]
    orr r1, lr, r1
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
L_0209B638:
    mov r1, lr
    mov r0, #0
    ldmia sp!, {r4, r5, r6, r7, lr}
    bx lr
    dcd 0x7FF00000
}



asm void _d2f(void)
{
    and r2, r1, #0x80000000
    mov ip, r1, lsr #0x14
    bics ip, ip, #0x800
    beq L_0209B6C4
    mov r3, ip, lsl #0x15
    cmn r3, #0x200000
    bhs L_0209B6A8
    subs ip, ip, #0x380
    bls L_0209B6D4
    cmp ip, #0xff
    bge L_0209B744
    mov r1, r1, lsl #0xc
    orr r3, r2, r1, lsr #9
    orr r3, r3, r0, lsr #29
    movs r1, r0, lsl #3
    orr r0, r3, ip, lsl #23
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209B6A8:
    orrs r3, r0, r1, lsl #12
    bne L_0209B6BC
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209B6BC:
    mvn r0, #0x80000000
    bx lr
L_0209B6C4:
    orrs r3, r0, r1, lsl #12
    bne L_0209B73C
    mov r0, r2
    bx lr
L_0209B6D4:
    cmn ip, #0x17
    beq L_0209B728
    bmi L_0209B73C
    mov r1, r1, lsl #0xb
    orr r1, r1, #0x80000000
    mov r3, r1, lsr #8
    orr r3, r3, r0, lsr #29
    rsb ip, ip, #1
    movs r1, r0, lsl #3
    orr r0, r2, r3, lsr ip
    rsb ip, ip, #0x20
    mov r3, r3, lsl ip
    orrne r3, r3, #1
    movs r1, r3
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209B728:
    orr r0, r0, r1, lsl #12
    movs r1, r0
    mov r0, r2
    addne r0, r0, #1
    bx lr
L_0209B73C:
    mov r0, r2
    bx lr
L_0209B744:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
}
