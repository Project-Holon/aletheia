/*
 * function: HAND_ITEM_RecoverHpPercentOfMaxHp
 * address:  0x021DD588
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_ITEM_RecoverHpPercentOfMaxHp   0x021DD588  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_GetValue   0x021D59B4  thumb ov093
 *   HAND_ITEM_GetParam   0x021DCFF8  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   BTL_EVENT_GetFactorKey   0x021D70A8  thumb ov093
 *   func_0209C2B0   0x0209C2B0  arm
 *
 * Gate on BTL_EVENT_GetVar(2); the 0xe count of BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam(b,c))
 * times the (u8) of HAND_ITEM_GetParam(a, 2) goes to the ARM helper at 0x0209C2B0,
 * whose result is the record's +4 halfword.  a and m go on the stack because
 * all four saved registers are live.
 */
#include "../include/Obj12151.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
int HAND_ITEM_GetParam(int a, int b);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
int func_0209C2B0(int a, int b);

void HAND_ITEM_RecoverHpPercentOfMaxHp(void *a, int b, int c)
{
    void *p;
    int m;
    u8 v;

    if (c != BTL_EVENT_GetVar(2))
        return;
    m = BTL_POKEPARAM_GetValue(BTL_SERVER_FLOW_GetPokeParam((int *)b, c), 0xe);
    v = (u8)HAND_ITEM_GetParam((int)a, 2);
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 5, c);
    ((struct Obj12151 *)p)->f6 = c;
    ((struct Obj12151 *)p)->f4 = func_0209C2B0(m * v, 0x64);
    BTL_SERVER_FLOW_InitMsgRecord((u8 *)p + 8, 2, 0xe3 << 2);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)p + 8), c);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)p + 8), BTL_EVENT_GetFactorKey(a));
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
}
