/*
 * unit: yes
 * function: HAND_WAZA_PowerSplitOnUncategorizedMove, HAND_WAZA_AddGuardSplit
 * address: 0x021E508C
 * packet: pkt_ov093_021E508C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   func_021D58A8 0x021D58A8 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   gGuardSplitHandlers 0x021F2704 data a4
 */
#include "../include/Obj07831.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Rec {
    u8 pad[14];
    u8 id;
    u8 f0:1;
    u8 f1:1;
    u8 f2:1;
    u8 f3:1;
    u8 rest:4;
} Rec;
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D58A8(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern u8 gGuardSplitHandlers[];
void HAND_WAZA_PowerSplitOnUncategorizedMove(void *x, void *a, int c)
{
    u8 k;
    void *m, *n;
    int first, second;
    Rec *p;
    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(6);
        m = BTL_SERVER_FLOW_GetPokeParam(a, c);
        n = BTL_SERVER_FLOW_GetPokeParam(a, k);
        first = (func_021D58A8(m, 8) + func_021D58A8(n, 8)) / 2;
        second = (func_021D58A8(m, 10) + func_021D58A8(n, 10)) / 2;
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 17, c);
        p->id = k;
        ((struct Obj07831 *)p)->f4 = first;
        ((struct Obj07831 *)p)->f8 = second;
        p->f0 = 1;
        p->f2 = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 17, c);
        p->id = c;
        ((struct Obj07831 *)p)->f4 = first;
        ((struct Obj07831 *)p)->f8 = second;
        p->f0 = 1;
        p->f2 = 1;
        BTL_SERVER_FLOW_InitMsgRecord((u8 *)p + 16, 2, 0x448);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)((u8 *)p + 16), c);
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
    }
}
void *HAND_WAZA_AddGuardSplit(int *p)
{
    *p = 1;
    return gGuardSplitHandlers;
}
