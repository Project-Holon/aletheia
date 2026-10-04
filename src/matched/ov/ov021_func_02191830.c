/*
 * function: func_02191830
 * address:  0x02191830
 * packet:   pkt_ov021_02191830
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The margins are locals (mx = 2, my = 0): the `+ my` add is folded to a
 * move after coalescing, which is the original's `adds r0, r0, #0` at +0x22.
 * A literal `+ 0` folds early and loses it.
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

struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);

void func_02191830(Q *q, int a, u8 *w, u8 *h)
{
    u32 mx = 2, my = 0;
    u32 tw = func_0201D304((struct StrObj *)a, (int)q->f08, 0) + mx;
    u32 th = func_0201D42C((struct StrObj *)a, (void *)((int)q->f08)) + my;
    u32 m = tw;
    tw >>= 3;
    if (m & 7) tw++;
    m = th;
    th >>= 3;
    *w = tw;
    if (m & 7) th++;
    *h = th;
}
