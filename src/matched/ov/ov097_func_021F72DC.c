/*
 * function: func_021F72DC
 * address: 0x021F72DC
 * packet: pkt_ov097_021F72DC
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
struct Actor;
struct PtS { short x, y; };
extern void func_0204B454(struct Actor *, struct PtS *, unsigned);
extern void func_0204B404(struct Actor *, const struct PtS *, unsigned);
void func_021F72DC(unsigned p, unsigned i, int dx)
{
    struct PtS pt;
    unsigned base = p + 0x54;
    func_0204B454(*(struct Actor **)(base + i * 4), &pt, 0);
    pt.x = pt.x + dx;
    func_0204B404(*(struct Actor **)(base + i * 4), &pt, 0);
}
