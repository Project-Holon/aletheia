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
 *   func_02175B34 0x02175B34 thumb ov011
 *   func_0203EFC8 0x0203EFC8 arm
 *   INTRUDE_COMM_ClearSessionTicks 0x021759B0 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int     s32;
u8 *func_02175B34(u8 *p);
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
void INTRUDE_COMM_ClearSessionTicks(u8 *a);

void INTRUDE_CMD_RecvRecordEcho(int a, int b, void *c, u8 *d)
{
    void *p;
    p = func_02175B34(d + 0x1ac);
    if (p != 0 && func_0203EFC8(p, c, 0x34) == 0) INTRUDE_COMM_ClearSessionTicks(d + 0x1ac);
}
