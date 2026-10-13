/*
 * function: BTL_SERVER_FLOW_TryRecoverHp
 * address: 0x021C334C
 * packet: pkt_ov093_021C334C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_CheckHealBlocked 0x021C3394 thumb ov093
 *   BTL_SERVER_FLOW_ApplyHpRecover 0x021C33E8 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_SERVER_FLOW_CheckHealBlocked(u8 *, u8 *, int);
extern void BTL_SERVER_FLOW_ApplyHpRecover(int, int, int);
int BTL_SERVER_FLOW_TryRecoverHp(u8 *p, u8 *q, int a, int b)
{
    if (BTL_SERVER_FLOW_CheckHealBlocked(p, q, b) == 0) {
        BTL_SERVER_FLOW_ApplyHpRecover((int)p, (int)q, a);
        return 1;
    }
    return 0;
}
