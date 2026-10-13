/*
 * function: UNION_ONESELF_ConnectGroupMain
 * address:  0x0217D51C
 * packet:   pkt_ov019_0217D51C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   UNION_ONESELF_CheckNetError  0x0217BB04  thumb  ov019
 *   UNION_COMM_StartConnectSync  0x02172EDC  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   UNION_COMM_RemoveMemberOfBeaconPc  0x02173650  thumb  ov012
 *   UNION_COMM_SetSituationParam  0x021734A8  thumb  ov012
 *   UNION_COMM_RequestStart  0x02172D50  thumb  ov012
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   func_020362DC  0x020362DC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int UNION_ONESELF_CheckNetError(char *p);
extern void UNION_COMM_StartConnectSync(u8 *a);
extern int UNION_COMM_IsResetting(u8 *a);
extern int GFL_NET_IsSessionNull(void);
extern void UNION_COMM_RemoveMemberOfBeaconPc(int a, u8 *b);
extern void UNION_COMM_SetSituationParam(u8 *self, u32 id, u32 v);
extern void UNION_COMM_RequestStart(u8 *a);
extern u32 UNION_MSG_CheckTalkPrintEnd(u8 *p);
extern u32 func_020362DC(void);

int UNION_ONESELF_ConnectGroupMain(u8 *a, int *b, int c, u8 *d)
{
    int r, t;
    if (*d < 3 && UNION_ONESELF_CheckNetError((char *)a) == 1)
        return 1;
    switch (*d) {
    case 0:
        UNION_COMM_StartConnectSync(a);
        (*d)++;
        break;
    case 1:
        if (UNION_COMM_IsResetting(a) != 0)
            break;
        r = GFL_NET_IsSessionNull();
        if (r == 1) {
            t = b[8];
            if (t != 0) {
                UNION_COMM_RemoveMemberOfBeaconPc((int)((u8 *)(b + 5)), (u8 *)t);
                UNION_COMM_SetSituationParam(a, 3, 0);
            }
            UNION_COMM_RequestStart(a);
            (*d)++;
        }
        break;
    case 2:
        if (UNION_COMM_IsResetting(a) == 0)
            (*d)++;
        break;
    case 3:
        if (UNION_MSG_CheckTalkPrintEnd(a) == 1) {
            if (func_020362DC() & 0xf3)
                return 1;
        }
        break;
    }
    return 0;
}
