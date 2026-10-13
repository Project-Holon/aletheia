/*
 * function: INTRUDE_CMD_RecvRecordAccept
 * address: 0x02173F9C
 * packet: pkt_ov011_02173F9C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_GetActiveSessionRequest 0x02175B34 thumb ov011
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   INTRUDE_COMM_AddSessionMember 0x021759C0 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
u8 *INTRUDE_COMM_GetActiveSessionRequest(u8 *p);
u32 GFL_NET_IsParentAid(void);
void INTRUDE_COMM_AddSessionMember(u8 *a, u8 b);

void INTRUDE_CMD_RecvRecordAccept(int a, int b, void *c, u8 *d)
{
    INTRUDE_COMM_GetActiveSessionRequest(d + 0x1ac);
    if (GFL_NET_IsParentAid()) INTRUDE_COMM_AddSessionMember(d + 0x1ac, a);
}
