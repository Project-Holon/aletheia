/*
 * unit:     yes
 * function: HAND_WAZA_CircleThrowForceSwitch, HAND_WAZA_AddSmackDown
 * address:  0x021E75E0
 * packet:   pkt_ov093_021E75E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The call result is bound to `r` before `k = 0x1fd`: with the constant
 * assigned first it is hoisted above the call into a callee-saved register.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   d_021F28B8     0x021F28B8  data   ov093  a4
 */
#include "../include/Obj13543.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int d_021F28B8[];

void HAND_WAZA_CircleThrowForceSwitch(int a, int b, int c)
{
    u8 *p;
    int k, r;

    if (c == BTL_EVENT_GetVar(3)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x2e, c);
        p[6] = BTL_EVENT_GetVar(6);
        r = BTL_EVENT_GetFactorKey((void *)a);
        k = 0x1fd;
        if (r == k)
            k += 0x8e;
        else
            k += 0x8f;
        ((struct Obj13543 *)p)->f4 = k;
        BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
    }
}

int *HAND_WAZA_AddSmackDown(int *p)
{
    *p = 2;
    return d_021F28B8;
}
