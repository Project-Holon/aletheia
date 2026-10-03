/*
 * function: func_0218D304
 * address:  0x0218D304
 * packet:   pkt_ov021_0218D304
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207C768  0x0207C768  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0218D934  0x0218D934  thumb  ov021
 *   func_0218D970  0x0218D970  thumb  ov021
 *   func_0218DD80  0x0218DD80  thumb  ov021
 *   func_0218DD9C  0x0218DD9C  thumb  ov021
 * Addresses are Black-image addresses.
 *
 * The inner loop is a guarded do-while: a plain for with y hoisted by the
 * compiler re-tests the bound after the preheader (extra cmp/ble).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct Elem { int idx; int x; int y; int z; } Elem;

extern u32 func_0207C768(u32 a, u32 b);
extern int func_0218D934(u32 a, int b, int c);
extern int func_0218D970(u32 a, int b, int c);
extern void func_0218DD80(Elem *e, int idx);
extern void func_0218DD9C(Elem *e, int x, int y, int z);

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}
void func_0218D304(char *p, int *v, Elem *e)
{
    int coloff;
    int rowoff;
    int x;
    int y;
    int base;
    int s;
    int row;
    int h;
    int w;
    int col;
    int rr;
    int cc;
    int k;

    w = *(u16 *)(p + 0x14);
    h = *(u16 *)(p + 0x16);
    s = *(int *)(p + 4);
    base = func_0207C768(*(int *)(p + 4), 0x2000);
    if (*(u8 *)(p + 0x2c) % 2 == 0)
        coloff = func_0218D934(*(u8 *)(p + 0x2c), s, v[0]);
    else
        coloff = func_0218D970(*(u8 *)(p + 0x2c), s, v[0]);
    if (*(u8 *)(p + 0x2d) % 2 == 0)
        rowoff = func_0218D934(*(u8 *)(p + 0x2d), s, v[2]);
    else
        rowoff = func_0218D970(*(u8 *)(p + 0x2d), s, v[2]);
    for (row = 0; row < *(u8 *)(p + 0x2d); row++) {
        rr = rowoff + row;
        if (rr < 0 || rr >= h)
            continue;
        col = 0;
        if (col >= *(u8 *)(p + 0x2c))
            continue;

        y = FX_Mul(rr << 12, s);
        do {
            cc = coloff + col;
            if (cc < 0 || cc >= w)
                continue;
            k = col + row * *(u8 *)(p + 0x2c);
            func_0218DD80(e + k, cc + rr * w);
            x = FX_Mul(cc << 12, s);
            func_0218DD9C(e + k, base + x, 0, base + y);
        } while (++col < *(u8 *)(p + 0x2c));
    }
}

