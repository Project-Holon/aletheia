/*
 * function: BTL_SERVER_FLOW_IsHpRecoverUnneeded
 * address: 0x021C3370
 * packet: pkt_ov093_021C3370
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_IsAbleToBattle 0x021D5B7C thumb ov093
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_POKEPARAM_IsAbleToBattle(void *);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
int BTL_SERVER_FLOW_IsHpRecoverUnneeded(u8 *p, void *q)
{
    if (BTL_POKEPARAM_IsAbleToBattle(q) == 0) return 1;
    if (BTL_POKEPARAM_IsHpFull(q) != 0) return 1;
    return 0;
}
