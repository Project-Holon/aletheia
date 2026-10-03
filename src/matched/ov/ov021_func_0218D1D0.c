/*
 * function: func_0218D1D0
 * address:  0x0218D1D0
 * packet:   pkt_ov021_0218D1D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207C768  0x0207C768  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   _ll_mul        0x0209C054  arm
 *   func_0218DD80  0x0218DD80  thumb  ov021
 *   func_0218DD9C  0x0218DD9C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct Elem { int idx; int x; int y; int z; } Elem;

extern u32 func_0207C768(u32 a, u32 b);
extern void func_0218DD80(Elem *e, int idx);
extern void func_0218DD9C(Elem *e, int x, int y, int z);

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}

void func_0218D1D0(char *p, void *a, Elem *e)
{
    int r;
    int c;
    int idx;
    int col;
    u32 rows;
    u32 n;
    int base;
    u32 row;
    int y;
    int t;
    int s;

    n = *(u16 *)(p + 0x14) * *(u16 *)(p + 0x16);
    rows = *(u32 *)(p + 0x18) / n;
    if (*(u32 *)(p + 0x18) % n != 0)
        rows++;
    s = *(int *)(p + 4);
    base = func_0207C768(*(int *)(p + 4), 0x2000);
    idx = 0;
    t = *(int *)(p + 8);
    for (row = 0; row < rows; row++) {
        for (col = 0; col < n; col++) {
            y = FX_Mul(row << 12, t);
            c = col % *(u16 *)(p + 0x14);
            r = col / *(u16 *)(p + 0x14);
            if (idx >= *(u32 *)(p + 0x18))
                idx = -1;
            func_0218DD80(e + idx, idx);
            func_0218DD9C(e + idx, base + FX_Mul(c << 12, s), y, base + FX_Mul(r << 12, s));
            idx++;
        }
    }
}

