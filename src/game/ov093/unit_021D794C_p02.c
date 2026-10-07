/*
 * file:     unit_021D794C_p02.c
 * unit:     yes
 * function: func_021D7B60, func_021D7B74, func_021D7B8C, func_021D7BA4, func_021D7BD4, func_021D7C38
 * address:  0x021D7B60
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
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   d_021F0421 0x021F0421 data a1
 *   func_021D5814  0x021D5814  thumb  ov093
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D59B4(u8 *p, int k);
extern u32 _u32_div_f(u32, u32);
extern u32 func_021D78AC(u32 range);
extern int func_021D5814(void *p, int k);
u32 func_021D7B60(void *p,u32 b);
int func_021D7B74(u8 *p, u32 k);
u32 func_021D7B8C(u32 lo, u32 hi);
int func_021D7BA4(int a);
int func_021D7BD4(void *p, int k);
u32 func_021D7C38(int a,int b);
extern u8 d_021F0421[6];

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
