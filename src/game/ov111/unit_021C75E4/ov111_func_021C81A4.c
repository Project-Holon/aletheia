/*
 * function: func_021C81A4
 * address:  0x021C81A4
 * packet:   pkt_ov111_021C81A4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C810C  0x021C810C  thumb
 *   func_021C8364  0x021C8364  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

typedef struct {
    unsigned char pad0[0x114];
    u16 f114;
    u16 f116;
} Work;

extern void func_021C810C(Work *p, int a, int b);
extern void func_021C8364(Work *p);

void func_021C81A4(Work *p, u16 v)
{
    p->f114 = v;
    func_021C810C(p, v, p->f116);
    func_021C8364(p);
}
