/*
 * function: func_021E781C
 * address:  0x021E781C
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E781C   0x021E781C  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_POKEPARAM_GetTypePair   0x021D57FC  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *
 * Gate on BTL_EVENT_GetVar(3); the (u8) of BTL_EVENT_GetVar(6) keys BTL_SERVER_FLOW_GetPokeParam,
 * whose result is halfword-stored through BTL_POKEPARAM_GetTypePair in record #0x14.  A
 * second record #4 gets the 4<<22 flag in its header word and the two-string
 * tail (c and the key).
 */
#include "../include/Obj07237.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
u16 BTL_POKEPARAM_GetTypePair(void *p);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);

void func_021E781C(void *a, int b, int c)
{
    u8 k;
    void *r;
    u8 *p;

    if (c != BTL_EVENT_GetVar(3))
        return;
    k = (u8)BTL_EVENT_GetVar(6);
    r = BTL_SERVER_FLOW_GetPokeParam((int *)b, k);
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x14, c);
    ((struct Obj07237 *)p)->f6 = c;
    ((struct Obj07237 *)p)->f4 = BTL_POKEPARAM_GetTypePair(r);
    ((struct Obj07237 *)p)->f7 = 1;
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 4, c);
    ((struct Obj07237 *)p)->f0 |= 4 << 22;
    BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 0x441);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), c);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), k);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
}
