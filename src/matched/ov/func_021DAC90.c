/*
 * function: HAND_TOKUSEI_WonderGuardBlockMove
 * address:  0x021DAC90
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_TOKUSEI_WonderGuardBlockMove   0x021DAC90  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_PushCmdRecord   0x021C88B4  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   WAZA_TOOL_IsDamaging   0x0201C314  thumb
 *
 * Gate on BTL_EVENT_GetVar(4) then a re-test on BTL_EVENT_GetVar(3); the
 * BTL_SERVER_FLOW_GetPokeParam(b, c) call's value is dropped, only the (u16) of
 * BTL_EVENT_GetVar(0x12) is kept.  Five more rejections, then the 2-event,
 * record, 3-event tail.  The trailing event's constant 3 is live across the
 * whole body, which is why the image keeps it in r7.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
int BTL_EVENT_OverwriteVar(int key, u32 val);
u32 WAZA_TOOL_IsDamaging(void *p);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_WonderGuardBlockMove(void *a, int b, int c)
{
    void *q;
    u16 v;

    if (c != BTL_EVENT_GetVar(4))
        return;
    if (c == BTL_EVENT_GetVar(3))
        return;
    BTL_SERVER_FLOW_GetPokeParam((int *)b, c);
    v = (u16)BTL_EVENT_GetVar(0x12);
    if (WAZA_TOOL_IsDamaging((void *)v) == 0)
        return;
    if (v == 0xa5)
        return;
    if (BTL_EVENT_GetVar(0x38) > 3)
        return;
    if (BTL_EVENT_OverwriteVar(0x40, 1) == 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord((void *)b, 2, c);
    q = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
    BTL_SERVER_FLOW_InitMsgRecord((u8 *)q + 4, 2, 0xd2);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)q + 4), c);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, q);
    BTL_SERVER_FLOW_PushCmdRecord((void *)b, 3, c);
}
