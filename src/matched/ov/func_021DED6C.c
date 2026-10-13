/*
 * function: HAND_ITEM_ShellBell_HealFromDamage
 * address:  0x021DED6C
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_ITEM_ShellBell_HealFromDamage   0x021DED6C  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   HAND_ITEM_GetParam   0x021DCFF8  thumb ov093
 *   BTL_EVENT_GetFactorKey   0x021D70A8  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   func_0209C2B0   0x0209C2B0  arm
 *
 * Three BTL_EVENT_GetVar gates (3, 0x4d zero, 0x32 non-zero), then the 0x32
 * handle and HAND_ITEM_GetParam(a, 2) go to the ARM helper at 0x0209C2B0, whose
 * zero result becomes 1.  Record #5 gets c and that halfword plus the same
 * two-string tail as HAND_ITEM_RaiseCriticalRate.  The second argument lives on the stack
 * because all six saved registers are taken.
 */
#include "../include/Obj12154.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
int HAND_ITEM_GetParam(int a, int b);
int func_0209C2B0(int a, int b);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_ITEM_ShellBell_HealFromDamage(void *a, int b, int c)
{
    int r, v;
    u8 *p;

    if (c != BTL_EVENT_GetVar(3))
        return;
    if (BTL_EVENT_GetVar(0x4d) != 0)
        return;
    r = BTL_EVENT_GetVar(0x32);
    if (r == 0)
        return;
    v = func_0209C2B0(r, HAND_ITEM_GetParam((int)a, 2));
    if (v == 0)
        v = 1;
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 5, c);
    ((struct Obj12154 *)p)->f6 = c;
    ((struct Obj12154 *)p)->f4 = v;
    BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 0x392);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), BTL_EVENT_GetFactorKey(a));
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
}
