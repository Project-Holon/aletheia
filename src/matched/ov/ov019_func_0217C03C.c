/*
 * function: UNION_ONESELF_ConnectParentEnd
 * address: 0x0217C03C
 * packet: pkt_ov019_0217C03C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Remaining two bytes are alignment padding.
 * symbols:
 *   UNION_COMM_SetSituationParam 0x021734A8 thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v);
int UNION_ONESELF_ConnectParentEnd(u8 *self)
{
    UNION_COMM_SetSituationParam(self, 1, 0);
    return 1;
}
