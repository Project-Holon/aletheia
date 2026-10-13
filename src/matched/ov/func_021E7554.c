/*
 * function: func_021E7554
 * address:  0x021E7554
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E7554   0x021E7554  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_GetItem   0x021D5B40  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   ITEM_IsBerry   0x020213C0  thumb
 *
 * Gate on BTL_EVENT_GetVar(3) and on BTL_EVENT_GetVar(0x46) being zero, then the
 * (u8) of BTL_EVENT_GetVar(4) keys BTL_SERVER_FLOW_GetPokeParam and the (u16) of
 * BTL_POKEPARAM_GetItem is the value ITEM_IsBerry must accept.  Both truncations
 * are materialised in the image, so both callees are declared int.
 */
#include "../include/Obj12159.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
u16 BTL_POKEPARAM_GetItem(struct QI *p);
int ITEM_IsBerry(u32 a);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void func_021E7554(void *a, int b, int c)
{
    u8 k;
    u16 v;
    u8 *p;

    if (c != BTL_EVENT_GetVar(3))
        return;
    if (BTL_EVENT_GetVar(0x46) != 0)
        return;
    k = (u8)BTL_EVENT_GetVar(4);
    v = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam((int *)b, k));
    if (ITEM_IsBerry(v) == 0)
        return;
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x20, c);
    ((struct Obj12159 *)p)->f6 = k;
    ((struct Obj12159 *)p)->f4 = 0;
    BTL_SERVER_FLOW_InitMsgRecord(p + 0xc, 2, 0x454);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 0xc), k);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 0xc), v);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
}
