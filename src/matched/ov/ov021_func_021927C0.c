/*
 * function: func_021927C0
 * address:  0x021927C0
 * packet:   pkt_ov021_021927C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020436FC  0x020436FC  arm  arm9
 *   func_02082BCC  0x02082BCC  arm  arm9
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

extern void func_02082BCC(void *p, int v, int n);
extern u32 func_020436FC(u32 a, u32 b, u32 c, u32 d, u32 e);

void func_021927C0(G *g, Fx *a)
{
    func_02082BCC(g, 0, 8);
    g->f04 = func_020436FC(*(u32 *)(*(u8 **)((u8 *)a + 0x178) + 0x14), 1, 1, 0x20, a->f00);
}
