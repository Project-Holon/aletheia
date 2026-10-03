/*
 * function: func_0218D444
 * address:  0x0218D444
 * packet:   pkt_ov021_0218D444
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207C768  0x0207C768  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0218D980  0x0218D980  thumb  ov021
 *   func_0218DD80  0x0218DD80  thumb  ov021
 *   func_0218DD9C  0x0218DD9C  thumb  ov021
 * Addresses are Black-image addresses.
 *
 * The fx32 multiplies use a long long copy of the scale (ls) assigned in the
 * outer loop body: LICM hoists it as a 64-bit temporary, which reserves the
 * 8-byte frame slot whose low word is never stored. The outer loop is an
 * explicit guard plus do-while (a plain for duplicates the guard around the
 * hoisted block), and func_0207C768 re-reads p+4 instead of taking s, which
 * puts s below the hoisted m*w temporary.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct Elem { int idx; int x; int y; int z; } Elem;

extern u32 func_0207C768(u32 a, u32 b);
extern int func_0218D980(u32 a, int b, int c);
extern void func_0218DD80(Elem *e, int idx);
extern void func_0218DD9C(Elem *e, int x, int y, int z);

void func_0218D444(char *p, int *a, Elem *e)
{
    int k;
    Elem *el;
    int col;
    int base;
    int w;
    int y;
    int row;
    int c0;
    int r0;
    int cc;
    int rr;
    int h;
    long long ls;
    int s;
    int m;

    w = *(u16 *)(p + 0x14);
    h = *(u16 *)(p + 0x16);
    s = *(int *)(p + 4);
    base = func_0207C768(*(int *)(p + 4), 0x2000);
    c0 = func_0218D980(*(u8 *)(p + 0x2c), s, a[0]);
    r0 = func_0218D980(*(u8 *)(p + 0x2d), s, a[2]);
    row = 0;
    if (row < *(u8 *)(p + 0x2d)) {
        do {
            ls = s;
            rr = r0 + row;
            m = rr % h;
            if (m < 0)
                m += h;
            for (col = 0; col < *(u8 *)(p + 0x2c); col++) {
                y = (int)(((long long)(rr << 12) * ls + 0x800LL) >> 12);
                cc = c0 + col;
                k = cc % w;
                if (k < 0)
                    k += w;
                el = &e[col + row * *(u8 *)(p + 0x2c)];
                func_0218DD80(el, k + m * w);
                func_0218DD9C(el, base + (int)(((long long)(cc << 12) * ls + 0x800LL) >> 12), 0, base + y);
            }
            row++;
        } while (row < *(u8 *)(p + 0x2d));
    }
}
