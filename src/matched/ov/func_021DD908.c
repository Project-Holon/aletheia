/*
 * function: HAND_ITEM_RaiseCriticalRate
 * address:  0x021DD908
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_ITEM_RaiseCriticalRate   0x021DD908  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_TestContFlag   0x021D5BDC  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_EVENT_GetFactorKey   0x021D70A8  thumb ov093
 *
 * Shape F1 gate on BTL_EVENT_GetVar(2), reject if BTL_POKEPARAM_TestContFlag(r,9) says so,
 * publish record #0x17 (carrying c and the constant 9), then build record #4
 * as two strings and publish it too.
 */
#include "../include/Obj12152.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QQ;
struct UtilWork;
int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);

void HAND_ITEM_RaiseCriticalRate(void *a, int b, int c)
{
    void *p, *q;

    if (c != BTL_EVENT_GetVar(2))
        return;
    if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam((int *)b, c), 9) != 0)
        return;
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x17, c);
    ((struct Obj12152 *)p)->f8 = c;
    ((struct Obj12152 *)p)->f4 = 9;
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    q = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
    BTL_SERVER_FLOW_InitMsgRecord((u8 *)q + 4, 2, 0x3e9);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)q + 4), c);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)q + 4), BTL_EVENT_GetFactorKey(a));
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, q);
}
