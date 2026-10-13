/*
 * function: BTL_SERVER_StepSendCommResult
 * address:  0x021BB3F8
 * packet:   pkt_ov093_021BB3F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 68, compiled 66, trailing padding)
 *
 * symbols:
 *   BTL_SERVER_SendCommandData  0x021BB724  thumb  ov093
 *   BTL_SERVER_AreRepliesReady  0x021BB798  thumb  ov093
 *   BTL_SERVER_ClearReplies  0x021BB7D0  thumb  ov093
 */

typedef unsigned char u8;

extern void BTL_SERVER_SendCommandData(u8 *p, int a, int b, int c);
extern int BTL_SERVER_AreRepliesReady(u8 *);
extern void BTL_SERVER_ClearReplies(const u8 *p);

int BTL_SERVER_StepSendCommResult(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        BTL_SERVER_SendCommandData(p, 0xd, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(p) != 0) {
            BTL_SERVER_ClearReplies(p);
            (*s)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}
