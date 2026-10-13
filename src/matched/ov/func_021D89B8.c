/*
 * function: HAND_TOKUSEI_SlowStartCountTurn
 * address:  0x021D89B8
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_TOKUSEI_SlowStartCountTurn   0x021D89B8  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_GetActionWordByPokeId   0x021C804C  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *
 * Gate on BTL_EVENT_GetVar(2); the counter at +4 of d must reach 5 -- the
 * BTL_SERVER_FLOW_GetActionWordByPokeId(b,c,&v) block bumps it once (rejecting a low nibble of 3) --
 * then record #4 is published as a two-string record and d's flag pair is set
 * to (0, 1).
 */
#include "../include/Obj04900.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
int BTL_SERVER_FLOW_GetActionWordByPokeId(int a, int b, void *v);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_SlowStartCountTurn(void *a, int b, int c, void *d)
{
    struct { unsigned int kind : 4; } v;
    u8 *p;

    if (c != BTL_EVENT_GetVar(2))
        return;
    if (((struct Obj04900 *)d)->f8 != 0)
        return;
    if (((struct Obj04900 *)d)->f4 < 5) {
        if (BTL_SERVER_FLOW_GetActionWordByPokeId(b, c, &v) == 0)
            return;
        if (v.kind == 3)
            return;
        ((struct Obj04900 *)d)->f4 += 1;
    }
    if (((struct Obj04900 *)d)->f4 < 5)
        return;
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
    BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x1f3);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    ((struct Obj04900 *)d)->fC = 0;
    ((struct Obj04900 *)d)->f8 = 1;
}
