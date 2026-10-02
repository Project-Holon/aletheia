/*
 * function: func_021C8434
 * address: 0x021C8434
 * packet: pkt_ov093_021C8434
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C845C 0x021C845C thumb ov093
 *   func_021BE52C 0x021BE52C thumb ov093
 */
typedef unsigned char u8;
extern int func_021C845C(u8 *, int);
extern void func_021BE52C(u8 *, int, int, int);
void func_021C8434(u8 *p, int a, int b)
{
    int c = func_021C845C(p + 0x1ab8, b);
    func_021BE52C(*(u8 **)(p + 0x4b0), a, b, c);
}
