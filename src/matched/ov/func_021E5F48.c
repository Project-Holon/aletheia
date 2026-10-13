/*
 * function: HAND_WAZA_HelpingHandAssistAlly
 * address:  0x021E5F48
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_WAZA_HelpingHandAssistAlly   0x021E5F48  thumb ov093
 *   BTL_SERVER_FLOW_GetActivePosPerSide   0x021C8180  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag   0x021D5BB0  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   BTL_EVENT_MarkFactorDead   0x021D7090  thumb ov093
 *
 * BTL_SERVER_FLOW_GetActivePosPerSide(b) must exceed 1, the gate is BTL_EVENT_GetVar(3), and the
 * (u8) of BTL_EVENT_GetVar(6) keys BTL_SERVER_FLOW_GetPokeParam for two rejection tests.  Record
 * #4 is published as a two-string record, its key goes back through the d
 * pointer, and the first argument is left for the very last call.  a and d
 * both live on the stack because all four saved registers are taken.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_SERVER_FLOW_GetActivePosPerSide(int *p);
int BTL_EVENT_GetVar(int a);
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
int BTL_POKEPARAM_IsFainted(void *p);
struct UtilWork;
int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
void BTL_EVENT_MarkFactorDead(u8 *p);

void HAND_WAZA_HelpingHandAssistAlly(void *a, int b, int c, int *d)
{
    u8 k;
    void *r;
    u8 *p;

    if ((u32)BTL_SERVER_FLOW_GetActivePosPerSide((int *)b) <= 1)
        return;
    if (c != BTL_EVENT_GetVar(3))
        return;
    k = (u8)BTL_EVENT_GetVar(6);
    r = BTL_SERVER_FLOW_GetPokeParam((int *)b, k);
    if (BTL_POKEPARAM_IsFainted(r) != 0)
        return;
    if (BTL_POKEPARAM_TestTurnFlag(r, 1) != 0)
        return;
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
    BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x414);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), k);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    *d = k;
    BTL_EVENT_MarkFactorDead(a);
}
