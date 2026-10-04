/*
 * function: func_02185B70
 * address: 0x02185B70
 * packet: pkt_ov020_02185B70
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_021859F0 0x021859F0 thumb ov020
 * interface: 021859F0 forwards incoming r0 to 02012964.
 */
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_021859F0(int a);
void func_02185B70(void *p)
{
    void *q = func_020120F4(p);
    func_0201210C(p);
    func_021859F0((int)q);
}
