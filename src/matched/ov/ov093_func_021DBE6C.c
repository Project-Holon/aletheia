/*
 * function: HAND_TOKUSEI_WeakArmor_LowerDefenseRaiseSpeed
 * address:  0x021DBE6C
 * packet:   pkt_ov093_021DBE6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_CanChangeStatStage  0x021D5D14  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj02789.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_CanChangeStatStage(s8 *p, int i, int sign);
extern int BTL_POKEPARAM_IsFainted(void *m);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_WeakArmor_LowerDefenseRaiseSpeed(int u, void *a, u32 b)
{
    u8 *e;
    void *m;
    int ok;
    if (b != BTL_EVENT_GetVar(4)) {
        return;
    }
    if (BTL_EVENT_GetVar(0x1a) != 1) {
        return;
    }
    if (BTL_EVENT_GetVar(0x46) != 0) {
        return;
    }
    m = BTL_SERVER_FLOW_GetPokeParam((int *)((int)a), b);
    ok = 0;
    if (BTL_POKEPARAM_CanChangeStatStage(m, 2, -1) != 0 || BTL_POKEPARAM_CanChangeStatStage(m, 5, 1) != 0) {
        ok = 1;
    }
    if (ok == 0) {
        return;
    }
    if (BTL_POKEPARAM_IsFainted(m) != 0) {
        return;
    }
    BTL_SERVER_FLOW_PushCmdRecord(a, 2, b);
    e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xe, b);
    e[0xf] = 1;
    e[0x10] = b;
    e[0xe] = 1;
    ((struct Obj02789 *)e)->f4 = 2;
    *(s8 *)&((struct Obj02789 *)e)->fC = -1;
    BTL_SERVER_FLOW_CommitCmdRecord(a, e);
    e = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xe, b);
    e[0xf] = 1;
    e[0x10] = b;
    e[0xe] = 1;
    ((struct Obj02789 *)e)->f4 = 5;
    e[0xc] = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(a, e);
    BTL_SERVER_FLOW_PushCmdRecord(a, 3, b);
}
