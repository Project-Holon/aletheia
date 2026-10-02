/*
 * function: func_021F1A18
 * address: 0x021F1A18
 * packet: pkt_ov032_021F1A18
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F1A28 0x021F1A28 thumb ov032
 */

typedef unsigned char u8;
extern void func_021F1A28(char *p, int b, u8 c, int *r);
void func_021F1A18(char *p, int b)
{
    func_021F1A28(p, b, 2, (int *)(p + 0xa8));
}
