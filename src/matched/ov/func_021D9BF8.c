/*
 * function: HAND_TOKUSEI_AngerPointOnDamageReaction
 * address:  0x021D9BF8
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   HAND_TOKUSEI_AngerPointOnDamageReaction   0x021D9BF8  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   func_021D5D50   0x021D5D50  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *
 * Three gates on BTL_EVENT_GetVar (4, 0x46 zero, 0x45 non-zero); the signed
 * func_021D5D50(BTL_SERVER_FLOW_GetPokeParam(b,c),1) must be positive and its byte goes to the
 * record's +0xc.  Record #0xe also sets the 1<<23 header flag and the two-
 * string tail (c) at +0x18.
 */
#include "../include/Obj04137.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
int func_021D5D50(s8 *p, int i);
void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, unsigned int a);
void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_AngerPointOnDamageReaction(void *a, int b, int c)
{
    void *r;
    u8 *p;

    if (c != BTL_EVENT_GetVar(4))
        return;
    if (BTL_EVENT_GetVar(0x46) != 0)
        return;
    if (BTL_EVENT_GetVar(0x45) == 0)
        return;
    r = BTL_SERVER_FLOW_GetPokeParam((int *)b, c);
    if (func_021D5D50(r, 1) <= 0)
        return;
    p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0xe, c);
    ((struct Obj04137 *)p)->f4 = 1;
    ((struct Obj04137 *)p)->fC = func_021D5D50(r, 1);
    ((struct Obj04137 *)p)->fE = 1;
    ((struct Obj04137 *)p)->fF = 1;
    ((struct Obj04137 *)p)->f10 = c;
    ((struct Obj04137 *)p)->fD = 1;
    ((struct Obj04137 *)p)->f0 |= 1 << 23;
    BTL_SERVER_FLOW_InitMsgRecord(p + 0x18, 2, 0x1e1);
    BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 0x18), c);
    BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
}
