/*
 * function: INTRUDE_CMD_RecvRecordEcho
 * address: 0x02173F4C
 * packet: pkt_ov011_02173F4C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_COMM_GetActiveSessionRequest 0x02175B34 thumb ov011
 *   GF_STANDARD_CompareBytes 0x0203EFC8 arm
 *   INTRUDE_COMM_ClearSessionTicks 0x021759B0 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int     s32;
u8 *INTRUDE_COMM_GetActiveSessionRequest(u8 *p);
s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
void INTRUDE_COMM_ClearSessionTicks(u8 *a);

void INTRUDE_CMD_RecvRecordEcho(int a, int b, void *c, u8 *d)
{
    void *p;
    p = INTRUDE_COMM_GetActiveSessionRequest(d + 0x1ac);
    if (p != 0 && GF_STANDARD_CompareBytes(p, c, 0x34) == 0) INTRUDE_COMM_ClearSessionTicks(d + 0x1ac);
}
