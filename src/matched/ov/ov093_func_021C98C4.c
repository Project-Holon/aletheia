/*
 * function: func_021C98C4
 * address: 0x021C98C4
 * packet: pkt_ov093_021C98C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_FIELD_QueryStaticSlotA 0x021EF8E8 thumb ov093
 *   BTL_SERVER_FLOW_PushFieldEffectExpireMessage 0x021C4C50 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_FIELD_QueryStaticSlotA(int);
extern void BTL_SERVER_FLOW_PushFieldEffectExpireMessage(u8 *, int);
int func_021C98C4(u8 *p, u8 *q)
{
    if (BTL_FIELD_QueryStaticSlotA(*(int *)(q + 4))) {
        BTL_SERVER_FLOW_PushFieldEffectExpireMessage(p, *(int *)(q + 4));
        return 1;
    }
    return 0;
}
