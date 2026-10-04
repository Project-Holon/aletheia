/*
 * function: func_0219270C
 * address:  0x0219270C
 * packet:   pkt_ov021_0219270C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201D304  0x0201D304  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Q {
    u32 f00;
    u32 f04;
    void *f08;
    u32 f0c;
    u32 f10;
    void *f14;
} Q;

struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

u32 func_0219270C(Q *q, int a, int n)
{
    u32 x;
    u32 r;

    x = n * 2 + func_0201D304((struct StrObj *)a, (int)q->f08, 0);
    r = x >> 3;
    if (x & 7)
        r++;
    return r;
}
