/*
 * function: func_02192788
 * address:  0x02192788
 * packet:   pkt_ov021_02192788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm  arm9
 *   func_021927C0  0x021927C0  thumb  ov021
 *   d_021DDA50     0x021DDA50  data   ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Fx {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u32 f08;
} Fx;

typedef struct G {
    u32 f00;
    u32 f04;
} G;

extern char d_021DDA50[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021927C0(G *g, Fx *a);

G *func_02192788(Fx *a)
{
    G *g = func_02030734(a->f00, 8, 1, d_021DDA50, 0x1202);
    func_021927C0(g, a);
    return g;
}
