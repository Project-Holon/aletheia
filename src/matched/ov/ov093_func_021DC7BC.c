/*
 * function: HAND_TOKUSEI_ZenModeRevertForm
 * address:  0x021DC7BC
 * packet:   pkt_ov093_021DC7BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QF;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_ZenModeRevertForm(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_GetSpecies(BTL_SERVER_FLOW_GetPokeParam(b, c)) == 0x22b) {
            m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x39, c);
            m[4] = c;
            m[5] = 0;
            BTL_SERVER_FLOW_InitMsgRecord(m + 8, 1, 0xba);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 8), c);
            BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        }
    }
}
