/*
 * unit: yes
 * function: HAND_WAZA_BellyDrumMaximizeAttack, HAND_WAZA_GetFeintHandlers
 * address: 0x021E4154
 * packet: pkt_ov093_021E4154
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_CALC_DivideMaxHpMin1 0x021D7B74 thumb ov093
 *   BTL_POKEPARAM_GetStatStageRoom 0x021D5D50 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   gFeintHandlers 0x021F2B10 data a4
 */
#include "../include/Obj02138.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
typedef signed char    s8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern int BTL_POKEPARAM_GetStatStageRoom(s8 *p, int i);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *, int, int);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern int gFeintHandlers[];

void HAND_WAZA_BellyDrumMaximizeAttack(int unused, void *s, int k)
{
    void *q;
    int n;
    int t;
    u8 *p;
    if (k == BTL_EVENT_GetVar(3)) {
        q = BTL_SERVER_FLOW_GetPokeParam(s, k);
        n = BTL_CALC_DivideMaxHpMin1(q, 2);
        t = BTL_POKEPARAM_GetStatStageRoom(q, 1);
        if (BTL_POKEPARAM_GetValue(q, 13) > (u32)n && t != 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord(s, 8, k);
            p[4] = 1;
            p[6] = 1;
            p[7] = k;
            ((struct Obj02138 *)p)->f10 = -n;
            BTL_SERVER_FLOW_CommitCmdRecord(s, p);
            p = BTL_SERVER_FLOW_AllocCmdRecord(s, 14, k);
            *(int *)(p + 4) = 1;
            p[12] = t;
            p[15] = 1;
            p[16] = k;
            p[13] = 1;
            p[14] = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(s, p);
            p = BTL_SERVER_FLOW_AllocCmdRecord(s, 4, k);
            BTL_SERVER_FLOW_InitMsgRecord(p + 4, 2, 613);
            BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(p + 4), k);
            BTL_SERVER_FLOW_CommitCmdRecord(s, p);
            p = BTL_SERVER_FLOW_AllocCmdRecord(s, 33, k);
            p[4] = k;
            ((struct Obj02138 *)p)->f8 = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(s, p);
        }
    }
}

int *HAND_WAZA_GetFeintHandlers(int *p)
{
    *p = 3;
    return gFeintHandlers;
}
