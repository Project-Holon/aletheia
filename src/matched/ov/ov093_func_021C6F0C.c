/*
 * function: BTL_SERVER_FLOW_IsPokeGrounded
 * address: 0x021C6F0C
 * packet: pkt_ov093_021C6F0C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_FIELD_IsStaticSlotInUse 0x021EF948 thumb ov093
 *   BTL_SERVER_FLOW_QueryPokeGroundedEvent 0x021C6F34 thumb ov093
 */
typedef unsigned char u8;
extern int BTL_FIELD_IsStaticSlotInUse(int);
extern int BTL_SERVER_FLOW_QueryPokeGroundedEvent(u8 *, u8 *, int);
int BTL_SERVER_FLOW_IsPokeGrounded(u8 *p, u8 *a, int k)
{
    if (BTL_FIELD_IsStaticSlotInUse(2) == 0 && BTL_SERVER_FLOW_QueryPokeGroundedEvent(p, a, k) != 0)
        return 1;
    return 0;
}
