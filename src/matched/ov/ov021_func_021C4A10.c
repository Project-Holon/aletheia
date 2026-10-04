/*
 * function: func_021C4A10
 * address:  0x021C4A10
 * packet:   pkt_ov021_021C4A10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Queues callback d_021DAA2C with a two-word argument block.
 *
 * symbols:
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DAA2C     0x021DAA2C  data  ov021
 */

typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
} P2;

extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(void *a, void *fn, u32 c, u32 d, P2 *e, u32 f);
extern char d_021DAA2C[];

void func_021C4A10(void *a, u32 b)
{
    P2 t;

    t.a = func_021ABEA0((u32)a, 8);
    t.b = b;
    func_021ABFA8(a, d_021DAA2C, 0, 0, &t, 0);
}
