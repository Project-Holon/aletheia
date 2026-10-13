/*
 * function: INTRUDE_COMM_UpdateQueuedRequest
 * address: 0x02174DF4
 * packet: pkt_ov011_02174DF4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRUDE_CMD_SendSaveSummary 0x02173CB0 thumb ov011
 */
typedef unsigned char u8;
int INTRUDE_CMD_SendSaveSummary(int *a, int b);
void INTRUDE_COMM_UpdateQueuedRequest(u8 *p)
{
    if (p[0x924] != 0) {
        if (INTRUDE_CMD_SendSaveSummary((int *)p, p[0x924]) == 1) {
            p[0x924] = 0;
        }
    }
}
