/*
 * function: func_021C43C4
 * address:  0x021C43C4
 * packet:   pkt_ov111_021C43C4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049B40  0x02049B40  arm
 *   d_021C86E8     0x021C86E8  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 heap;
} Work;

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern const u32 d_021C86E8[][2];

void func_021C43C4(Work *p, int k)
{
    func_02049B40(0x29, d_021C86E8[k][1], 4, 0x80, 0x20, p->heap);
}
