/*
 * function: func_021C6F0C
 * address: 0x021C6F0C
 * packet: pkt_ov093_021C6F0C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EF948 0x021EF948 thumb ov093
 *   func_021C6F34 0x021C6F34 thumb ov093
 */
typedef unsigned char u8;
extern int func_021EF948(int);
extern int func_021C6F34(u8 *, u8 *, int);
int func_021C6F0C(u8 *p, u8 *a, int k)
{
    if (func_021EF948(2) == 0 && func_021C6F34(p, a, k) != 0)
        return 1;
    return 0;
}
