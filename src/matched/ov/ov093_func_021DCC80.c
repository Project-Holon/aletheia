/*
 * function: HAND_TOKUSEI_UnnerveAnnounce
 * address:  0x021DCC80
 * packet:   pkt_ov093_021DCC80
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb  ov093
 *   BTL_MAIN_IsZero  0x021B9A5C  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_SetFactorSkipCheck  0x021D7320  thumb  ov093
 *   HAND_TOKUSEI_UnnerveSkipBerry  0x021DCCEC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int x);
extern u8 BTL_MAIN_IsZero(u32 x);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
struct QS;
extern void BTL_EVENT_SetFactorSkipCheck(struct QS *p, u32 v);
extern void HAND_TOKUSEI_UnnerveSkipBerry(void);

void HAND_TOKUSEI_UnnerveAnnounce(void *a, void *b, int c, int *d)
{
    u8 *m;
    u32 x;

    if (*d == 0) {
        x = BTL_MAIN_IsZero(BTL_MAIN_IsPokeIdInSecondPair(c));
        BTL_SERVER_FLOW_PushCmdRecord(b, 2, c);
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 4, c);
        BTL_SERVER_FLOW_InitMsgRecord(m + 4, 1, 0xb0);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 4), x);
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        BTL_SERVER_FLOW_PushCmdRecord(b, 3, c);
        BTL_EVENT_SetFactorSkipCheck(a, (u32)((void *)HAND_TOKUSEI_UnnerveSkipBerry));
        *d = 1;
    }
}
