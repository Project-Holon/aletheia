/*
 * function: func_02191830
 * address:  0x02191830
 * packet:   pkt_ov021_02191830
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: logic right; original keeps a copy of each sum before the >>3 (adds r2,r4 / adds r0,r0,#0, 64 vs 58 bytes). Inline helper, int/u8 locals and out-pointer forms all give the same 58-byte body.
 *
 * symbols:
 *   func_0201D304  0x0201D304  thumb  arm9
 *   func_0201D42C  0x0201D42C  thumb  arm9
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

extern int func_0201D304(int a, int b, int c);
extern int func_0201D42C(int a, int b);

static inline u32 func_02191830_tiles(u32 x)
{
    u32 r = x >> 3;
    if (x & 7)
        r++;
    return r;
}

void func_02191830(Q *q, int a, u8 *w, u8 *h)
{
    u32 tw = func_0201D304(a, (int)q->f08, 0) + 2;
    u32 th = func_0201D42C(a, (int)q->f08);
    *w = func_02191830_tiles(tw);
    *h = func_02191830_tiles(th);
}
