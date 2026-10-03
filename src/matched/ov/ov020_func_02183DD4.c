/*
 * function: func_02183DD4
 * address: 0x02183DD4
 * packet: pkt_ov020_02183DD4
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_020127C4 0x020127C4 thumb
 *   func_02161D64 0x02161D64 thumb ov010
 * interface: 020127C4 forwards 020127D0's returned pointer in r0.
 */
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127C4(void *p);
extern void func_02161D64(void *p);
void func_02183DD4(void *p)
{
    func_02161D64(func_020127C4(func_020120F4(p)));
}
