/*
 * function: BTL_SERVER_StepSendWildWin
 * address:  0x021BB368
 * packet:   pkt_ov093_021BB368
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_SendCommandData  0x021BB724  thumb  ov093
 *   BTL_SERVER_AreRepliesReady  0x021BB798  thumb  ov093
 *   BTL_SERVER_ClearReplies  0x021BB7D0  thumb  ov093
 *   BTL_SERVER_SetHandler  0x021BABEC  thumb  ov093
 *   BTL_SERVER_StepWaitEnd  0x021BB320  thumb  ov093
 */

typedef unsigned char u8;

extern void BTL_SERVER_SendCommandData(u8 *p, int a, int b, int c);
extern int BTL_SERVER_AreRepliesReady(u8 *);
extern void BTL_SERVER_ClearReplies(const u8 *p);
extern void BTL_SERVER_SetHandler(int *p, void *f);
extern int BTL_SERVER_StepWaitEnd(u8 *, int *);

int BTL_SERVER_StepSendWildWin(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        BTL_SERVER_SendCommandData(p, 0xe, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (BTL_SERVER_AreRepliesReady(p) != 0) {
            BTL_SERVER_ClearReplies(p);
            (*s)++;
        }
        break;
    case 2:
        BTL_SERVER_SetHandler((int *)p, (void *)BTL_SERVER_StepWaitEnd);
        break;
    }
    return 0;
}
