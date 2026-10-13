/*
 * unit: yes
 * function: HAND_WAZA_RestSleepAndHeal, HAND_WAZA_GetAttractHandlers
 * address: 0x021E448C
 * packet: pkt_ov093_021E448C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   BTL_CALC_MakeSickContTurns 0x021D7D78 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   gAttractHandlers 0x021F278C data a4
 */
#include "../include/Obj02433.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Word { u32 v; } Word;
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern Word BTL_CALC_MakeSickContTurns(int);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int, u32);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern int gAttractHandlers[];

void HAND_WAZA_RestSleepAndHeal(int unused, void *s, int k)
{
    void *q;
    u8 *p;
    u32 n;
    if (k == BTL_EVENT_GetVar(3)) {
        q = BTL_SERVER_FLOW_GetPokeParam(s, k);
        if (BTL_POKEPARAM_IsHpFull(q) == 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord(s, 12, k);
            p[15] = k;
            ((struct Obj02433 *)p)->f4 = 2;
            *(Word *)(p + 8) = BTL_CALC_MakeSickContTurns(3);
            p[12] = 1;
            p[16] = 1;
            p[14] = 1;
            BTL_SERVER_FLOW_InitMsgRecord(p + 20, 2, 638);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 20), k);
            BTL_SERVER_FLOW_CommitCmdRecord(s, p);
            p = BTL_SERVER_FLOW_AllocCmdRecord(s, 5, k);
            p[6] = k;
            n = func_021D59B4(q, 14);
            *(u16 *)&((struct Obj02433 *)p)->f4 = n - func_021D59B4(q, 13);
            ((struct Obj02433 *)p)->f0 |= 0x1000000;
            BTL_SERVER_FLOW_CommitCmdRecord(s, p);
            p = BTL_SERVER_FLOW_AllocCmdRecord(s, 33, k);
            p[4] = k;
            ((struct Obj02433 *)p)->f8 = 3;
            ((struct Obj02433 *)p)->f0 |= 0x1000000;
            BTL_SERVER_FLOW_CommitCmdRecord(s, p);
            BTL_EVENT_OverwriteVar(81, 0);
        }
    }
}

int *HAND_WAZA_GetAttractHandlers(int *p)
{
    *p = 1;
    return gAttractHandlers;
}
