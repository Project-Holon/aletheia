/*
 * function: func_021D95A0
 * address: 0x021D95A0
 * packet: pkt_ov119_021D95A0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 */
typedef unsigned int u32;
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
u32 func_021D95A0(void *mon)
{
    u32 r = 0;
    if (func_02017E1C(mon, 3, 0) == 1)
        return 1;
    if ((int)func_02017E1C(mon, 5, r) > 0x28b)
        r = 1;
    return r;
}
