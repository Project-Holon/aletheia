/*
 * file:     unit_021D794C_p01.c
 * unit:     yes
 * function: func_021D794C, func_021D799C, func_021D79E8, func_021D7A44, func_021D7A6C, func_021D7A9C, func_021D7AD4, func_021D7AF0, func_021D7B08, func_021D7B10, func_021D7B2C, func_021D7B3C
 * address:  0x021D794C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F047C  0x021F047C  data  ov093  a1
 *   func_021E8D0C  0x021E8D0C  thumb  ov093
 *   func_021E8DA8  0x021E8DA8  thumb  ov093
 *   d_021F0427  0x021F0427  data  ov093  a1
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021D78AC  0x021D78AC  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_021E8D0C(int v, u8 *a, u8 *b);
extern int func_021E8DA8(int v);
extern u32 func_021D78AC(u32 range);
int func_021D794C(int a, int b);
int func_021D799C(int a, int v);
int func_021D79E8(int x, int y);
u32 func_021D7A44(u32 a,u32 b,u32 c,u32 d);
u32 func_021D7A6C(u32 a,u32 b);
u8 func_021D7A9C(int a,u8 *out);
int func_021D7AD4(int a);
int func_021D7AF0(u32 pct);
/* 021D7B08 cmp r0,r1; bge; adds r0,r1,#0 */ int func_021D7B08(int a, int b);
u32 func_021D7B10(u32 a, u32 b);
u32 func_021D7B2C(u32 a,u32 b);
u32 func_021D7B3C(u32 a,u32 b);
extern u8 d_021F047C[17][17];
extern u8 d_021F0427[];


int func_021D794C(int a, int b)
{
    if (a == 0x11 || b == 0x11)
        return 3;
    switch (d_021F047C[a][b]) {
    case 0:
        return 0;
    case 2:
        return 2;
    case 4:
        return 3;
    case 8:
        return 4;
    default:
        return 0;
    }
}


int func_021D799C(int a, int v)
{
    u8 t[2];
    int x;

    func_021E8D0C(v, &t[1], &t[0]);
    if (func_021E8DA8(v))
        return func_021D794C(a, t[1]);
    x = func_021D794C(a, t[1]);
    return func_021D79E8(x, func_021D794C(a, t[0]));
}


/*
 * note:     a plain switch with case 16 after case 8 (mwcc tables 0..8 and compares 16 in
 *           the default path); the u32 switch value gives the unsigned `bhi` range check.
 */
int func_021D79E8(int x, int y)
{
    u32 m = d_021F0427[x] * d_021F0427[y] / 4;

    switch (m) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 4:
        return 3;
    case 8:
        return 4;
    case 16:
        return 5;
    }
    return 0;
}

u32 func_021D7A44(u32 a,u32 b,u32 c,u32 d) { return (a*b*(2*c/5+2)/d)/50+2; }

u32 func_021D7A6C(u32 a,u32 b) { switch(b) { case 0:return 0; case 1:return a/4; case 2:return a/2; case 3:return a; case 4:return a*2; case 5:return a*4; } return a; }

u8 func_021D7A9C(int a,u8 *out) { u8 n,i; i=0; n=0; do { if(d_021F047C[a][i]==0 || d_021F047C[a][i]==2) out[n++]=i; ++i; } while(i<17); return n; }

int func_021D7AD4(int a) { if(a>3) return 2; if(a==3) return 1; if(a!=0) return 3; return 0; }


int func_021D7AF0(u32 pct)
{
    if (func_021D78AC(100) < pct) return 1;
    return 0;
}


/* 021D7B08  cmp r0,r1; bge; adds r0,r1,#0 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: cmp r0, r1; bge loc_021D7B0E; adds r0, r1, #0; bx lr.
 */
int func_021D7B08(int a, int b)
{
    if (a < b)
        a = b;
    return a;
}


/*
 * 2026-10-03 (wave B3 lane 10): EXACT. Rounded 20.12 product. The product,
 * the shift and the increment all reuse the parameter a; with a separate
 * product local mwcc copies an operand to r2 first (adds r2,r0,#0; muls).
 * See docs/idioms/a-product-kept-in-its-parameter-multiplies-in-place.md.
 */
u32 func_021D7B10(u32 a, u32 b)
{
    u32 f;

    a *= b;
    f = a & 0xfff;
    a >>= 12;
    if (f > 0x800)
        a++;
    return a;
}

u32 func_021D7B2C(u32 a,u32 b) { u32 r=func_021D7B10(a,b); if(r==0) r=1; return r; }

u32 func_021D7B3C(u32 a,u32 b) { u32 m; a*=b; m=a%100; a/=100; if(m>=50) ++a; return a; }
