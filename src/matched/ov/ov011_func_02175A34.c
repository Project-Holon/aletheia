/*
 * function: INTRUDE_COMM_UpdateSessionSends
 * address:  0x02175A34
 * packet:   pkt_ov011_02175A34
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_CMD_SendMemberEntry  0x02173DA0  thumb  ov011
 *   INTRUDE_CMD_SendGroupRecord  0x02173EEC  thumb  ov011
 *   INTRUDE_CMD_SendResultRecord  0x021741E8  thumb  ov011
 *   INTRUDE_CMD_SendRecordEcho  0x02173F74  thumb  ov011
 *   INTRUDE_CMD_SendEndNotice  0x021742EC  thumb  ov011
 *   INTRUDE_CMD_SendStartNotice  0x021742A8  thumb  ov011
 */

typedef unsigned char u8;

extern int INTRUDE_CMD_SendMemberEntry(int a, int b, int c);
extern int INTRUDE_CMD_SendGroupRecord(char *a, char *b);
extern int INTRUDE_CMD_SendResultRecord(char *a, char *b);
extern int INTRUDE_CMD_SendRecordEcho(int a, u8 *b);
typedef unsigned int   u32;
extern u32 INTRUDE_CMD_SendEndNotice(u32 a);
extern int INTRUDE_CMD_SendStartNotice(int a);

void INTRUDE_COMM_UpdateSessionSends(void *a, u8 *b)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (b[0x194 + i] == 1 && INTRUDE_CMD_SendMemberEntry((int)a, (int)b, i) == 1) {
            b[0x194 + i] = 0;
        }
    }
    if (b[0x19a] == 1 && INTRUDE_CMD_SendGroupRecord(a, (char *)b) == 1) {
        b[0x19a] = 0;
    }
    if (b[0x19b] == 1 && INTRUDE_CMD_SendResultRecord(a, (char *)b) == 1) {
        b[0x19b] = 0;
    }
    if (b[0x19c] == 1 && INTRUDE_CMD_SendRecordEcho((int)a, b) == 1) {
        b[0x19c] = 2;
    }
    if (b[0x19f] != 0 && INTRUDE_CMD_SendEndNotice(b[0x19f]) == 1) {
        b[0x19f] = 0;
    }
    if (b[0x1a0] != 0 && INTRUDE_CMD_SendStartNotice(b[0x1a0]) == 1) {
        b[0x1a0] = 0;
    }
}
