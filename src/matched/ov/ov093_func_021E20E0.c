/*
 * function: HAND_WAZA_RageRaiseAttackOnHit
 * address:  0x021E20E0
 * packet:   pkt_ov093_021E20E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj05220.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_WAZA_RageRaiseAttackOnHit(int u, int a, int b)
{
    u8 *r;

    if (b == BTL_EVENT_GetVar(4) && BTL_EVENT_GetVar(0x46) == 0 && BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam((int *)a, b)) == 0) {
        r = BTL_SERVER_FLOW_AllocCmdRecord((char *)a, 0xe, b);
        ((struct Obj05220 *)r)->f4 = 1;
        r[0xc] = 1;
        r[0xe] = 0;
        r[0xf] = 1;
        r[0x10] = b;
        r[0xd] = 1;
        BTL_SERVER_FLOW_InitMsgRecord(r + 0x18, 2, 0x214);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(r + 0x18), b);
        BTL_SERVER_FLOW_CommitCmdRecord((void *)a, r);
    }
}
