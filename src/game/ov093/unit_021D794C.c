/*
 * file:     unit_021D794C.c
 * unit:     yes
 * function: func_021D794C, func_021D799C, func_021D79E8, func_021D7A44, func_021D7A6C, func_021D7A9C, func_021D7AD4, func_021D7AF0, func_021D7B08, func_021D7B10, func_021D7B2C, func_021D7B3C, func_021D7B60, func_021D7B74, func_021D7B8C, func_021D7BA4, func_021D7BD4, func_021D7C38, func_021D7C70, func_021D7D18, func_021D7D6C, func_021D7D78, func_021D7D9C, func_021D7DC0, func_021D7E10
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
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   d_021F0421 0x021F0421 data a1
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021E89F8  0x021E89F8  thumb  ov093
 *   func_021E8A28  0x021E8A28  thumb  ov093
 *   func_021E89C0  0x021E89C0  thumb  ov093
 *   func_021D7E34 0x021D7E34 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 */
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Sel { u16 kind : 4; u16 lo : 6; u16 hi : 6; };

union Slot_021D794C {
    u32 v;
    u32 raw;
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

typedef union Slot_021D794C Word;

union Slot_021D7D78 { u32 v; u32 raw; struct {u32 kind:3; u32 lo:6; u32 hi:6; u32 rest:17;} s; };

extern void func_021E8D0C(int v, u8 *a, u8 *b);
extern int func_021E8DA8(int v);
extern u32 func_021D78AC(u32 range);
extern int func_021D59B4(u8 *p, int k);
extern u32 _u32_div_f(u32, u32);
extern int func_021D5814(void *p, int k);
extern u8 func_021D5440(u8 *p);
extern Word func_021E899C(u32 a);
extern Word func_021E8940(u8 a);
extern Word func_021E89F8(u8 a, u32 b);
extern Word func_021E8A28(u32 a, u8 b);
extern Word func_021E89C0(void);
extern int func_021D7E34(int);
extern int func_021D62C4(struct Unk021D62A8 *,int);
int func_021D794C(int a, int b);
int func_021D799C(int a, int v);
int func_021D79E8(int x, int y);
u32 func_021D7A44(u32 a,u32 b,u32 c,u32 d);
u32 func_021D7A6C(u32 a,u32 b);
u8 func_021D7A9C(int a,u8 *out);
int func_021D7AD4(int a);
int func_021D7AF0(u32 pct);
int func_021D7B08(int a, int b);
u32 func_021D7B10(u32 a, u32 b);
u32 func_021D7B2C(u32 a,u32 b);
u32 func_021D7B3C(u32 a,u32 b);
u32 func_021D7B60(void *p,u32 b);
int func_021D7B74(u8 *p, u32 k);
u32 func_021D7B8C(u32 lo, u32 hi);
int func_021D7BA4(int a);
int func_021D7BD4(void *p, int k);
u32 func_021D7C38(int a,int b);
void func_021D7C70(struct Sel s, int m, Word *out);
union Slot_021D794C func_021D7D18(int x);
int func_021D7D6C(int x);
union Slot_021D7D78 func_021D7D78(u32 x);
union Slot_021D7D78 func_021D7D9C(u32 x);
void func_021D7DC0(int a, int b, Word *out);
int func_021D7E10(struct Unk021D62A8 *p);
extern u8 d_021F047C[17][17];
extern u8 d_021F0427[];
extern u8 d_021F0421[6];





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




u32 func_021D7B60(void *p,u32 b) { return (u32)func_021D59B4(p,14)/b; }





/*
 * Recursive MATCH unblocker: named callee of the parked ov093 func_021DFABC
 * (the `func_021D7B74(func_021C7CF4(b, k), (u8)func_021DCFF8(a,2))` halfword).
 * Runs func_021D59B4(a, 0xe) through the unsigned divide entry 0x0209C2B0
 * (`_u32_div_f`, see docs/notes/unsigned-divide-entry-is-0209c2b0.c.txt) and
 * floors a zero quotient at 1.
 *
 * Addresses are Black-image addresses.
 */
int func_021D7B74(u8 *p, u32 k)
{
    u32 r = func_021D59B4(p, 0xe);

    r = r / k;
    if (r == 0)
        r = 1;
    return r;
}





u32 func_021D7B8C(u32 lo, u32 hi)
{
    u32 t;
    if (lo > hi) {
        t = lo;
        lo = hi;
        hi = t;
    }
    return lo + func_021D78AC(hi - lo + 1);
}




int func_021D7BA4(int a) { u8 r,i; if(a!=5) return a; r=func_021D78AC(100); for(i=0;i<6;++i) { if(r<d_021F0421[i]) return i; } return a; }





int func_021D7BD4(void *p, int k)
{
    u16 r;

    switch (k) {
    case 4:
        if (func_021D5814(p, 5) != 0) return 0;
        if (func_021D5814(p, 8) != 0) return 0;
        if (func_021D5814(p, 4) != 0) return 0;
        break;
    case 3:
        if (func_021D5814(p, 0xe) != 0) return 0;
        break;
    default:
        return 0;
    }
    r = func_021D59B4(p, 0xe) / 16;
    if (r == 0) r = 1;
    return r;
}




u32 func_021D7C38(int a,int b) { switch(a) { case 1: if(b==9) return 6144; if(b==10) return 2048; break; case 2: if(b==9) return 2048; if(b==10) return 6144; break; } return 4096; }




void func_021D7C70(struct Sel s, int m, Word *out)
{
    u8 x;
    u8 y;

    switch (s.kind) {
    case 3:
        *out = func_021E899C(func_021D5440((u8 *)m));
        break;
    case 2:
        y = func_021D7B8C(s.lo, s.hi);
        *out = func_021E8940(y);
        break;
    case 1:
        *out = func_021E89F8(s.hi, s.lo);
        break;
    case 4:
        x = func_021D5440((u8 *)m);
        y = func_021D7B8C(s.lo, s.hi);
        *out = func_021E8A28(x, y);
        break;
    case 0:
    default:
        break;
    }
}



union Slot_021D794C func_021D7D18(int x)
{
    union Slot_021D794C s;
    s.raw = 0;
    switch (x) {
    case 1:
    case 3:
    case 4:
    case 5:
        s.s.kind = 1;
        break;
    case 2:
        s.s.kind = 2;
        s.s.lo = func_021D7B8C(2, 4);
        break;
    case 0:
    default:
        s.s.kind = 0;
        break;
    }
    return s;
}




/* 021D7D6C  cmp r0,#6; bge; movs r0,#1; bx lr; movs r0,#0; bx lr */
int func_021D7D6C(int x)
{
    if (x < 6)
        return 1;
    return 0;
}


union Slot_021D7D78 func_021D7D78(u32 x) { union Slot_021D7D78 s; s.raw=0; s.s.kind=2; s.s.lo=x; return s; }


union Slot_021D7D78 func_021D7D9C(u32 x) { union Slot_021D7D78 s; s.raw=0; s.s.kind=3; s.s.lo=x; return s; }



void func_021D7DC0(int a, int b, Word *out)
{
    u8 y;

    if (a < 6) {
        *out = func_021D7D18(a);
        return;
    }
    out->v = 0;
    switch (a) {
    case 7:
        *out = func_021E899C(func_021D5440((u8 *)b));
        break;
    case 6:
        y = func_021D7B8C(2, 5);
        *out = func_021E8940(y);
        break;
    default:
        *out = func_021E89C0();
        break;
    }
}


/*
 * lever: declare n before i; both exits return n to retain r0 on the zero path.
 * extent: trailing two-byte alignment before Thumb-to-ARM veneer 021D7E34.
 */
int func_021D7E10(struct Unk021D62A8 *p) { int n; int i=0; for (;;) { n=func_021D7E34(i++); if(n==0) return n; if(func_021D62C4(p,n)) return n; } }
