/*
 * function: func_021C4BE0
 * address:  0x021C4BE0
 * packet:   pkt_ov021_021C4BE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Queues callback d_021DAA18 with a two-word argument block.
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DAA18     0x021DAA18  data  ov021
 */

typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
} P2;

extern u32 func_021ABEA0(void *a, u32 b);
extern void func_021ABFA8(void *a, void *fn, u32 c, u32 d, P2 *e, u32 f);
extern char d_021DAA18[];

void func_021C4BE0(void *a, u32 b)
{
    P2 t;

    t.a = func_021ABEA0(a, 0x11);
    t.b = b;
    func_021ABFA8(a, d_021DAA18, 0, 0, &t, 0);
}
