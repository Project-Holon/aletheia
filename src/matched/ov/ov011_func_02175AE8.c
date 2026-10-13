/*
 * function: INTRUDE_COMM_UpdateSessionResult
 * address: 0x02175AE8
 * packet: pkt_ov011_02175AE8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: INTRUDE_CMD_SendMemberValue trailing input omitted: full matched body neither
 * reads nor forwards d; original caller supplies no r3 value.
 * symbols:
 *   INTRUDE_COMM_GetSessionWaitRemaining 0x021758B4 thumb ov011
 *   INTRUDE_CMD_SendMemberValue 0x02173FF4 thumb ov011
 */
typedef unsigned char u8;
extern int INTRUDE_COMM_GetSessionWaitRemaining(u8 *p);
extern int INTRUDE_CMD_SendMemberValue(int a, int b, int c);
void INTRUDE_COMM_UpdateSessionResult(int ctx, u8 *p)
{
    u8 mask = p[0x19E];
    if (mask != 0) {
        if (INTRUDE_CMD_SendMemberValue(ctx, INTRUDE_COMM_GetSessionWaitRemaining(p), mask) == 1) p[0x19E] = 0;
    }
}
