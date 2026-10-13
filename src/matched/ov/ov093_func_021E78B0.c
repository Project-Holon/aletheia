/*
 * unit:     yes
 * function: func_021E78B0, func_021E7918
 * address:  0x021E78B0
 * packet:   pkt_ov093_021E78B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * d_021F26D4: the ov093 hint is contested at this address; the plain
 * `data a4` line resolves it as sole-ref/data.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetWeight  0x021D67E8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   d_021F26D4     0x021F26D4  data   a4
 */
#include "../include/Obj13544.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetWeight(u8 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int d_021F26D4[];

void func_021E78B0(int a, int b, int c)
{
    u32 n, v;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        n = BTL_POKEPARAM_GetWeight(BTL_SERVER_FLOW_GetPokeParam((int *)b, c));
        if (n > 1) {
            p = BTL_SERVER_FLOW_AllocCmdRecord((char *)b, 0x2d, c);
            v = (n > 0x3e9) ? n - 0x3e8 : 1;
            p[4] = c;
            ((struct Obj13544 *)p)->f6 = v;
            BTL_SERVER_FLOW_InitMsgRecord(p + 8, 2, 0x44e);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 8), c);
            BTL_SERVER_FLOW_CommitCmdRecord((void *)b, p);
        }
    }
}

int *func_021E7918(int *p)
{
    *p = 1;
    return d_021F26D4;
}
