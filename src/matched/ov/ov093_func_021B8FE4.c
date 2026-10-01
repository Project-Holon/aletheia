/*
 * function: func_021B8FE4
 * address: 0x021B8FE4
 * packet: pkt_ov093_021B8FE4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8FC0 0x021B8FC0 thumb ov093
 * Leaf: sole unresolved overlay blocker of ov094 func_021F745C.
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021B8FC0(void *, u32);
u8 func_021B8FE4(u8 *p)
{
    return func_021B8FC0(p, p[0x46c]);
}
