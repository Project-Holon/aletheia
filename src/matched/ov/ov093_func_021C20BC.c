/*
 * function: func_021C20BC
 * address: 0x021C20BC
 * packet: pkt_ov093_021C20BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return at 0x021C20CE.
 * symbols:
 *   func_021C7330 0x021C7330 thumb ov093
 */
typedef unsigned char u8;
extern int func_021C7330(u8 *, u8 *);
int func_021C20BC(u8 *p, u8 *a, int r)
{
    if (func_021C7330(p, a))
        return 1;
    return 0;
}
