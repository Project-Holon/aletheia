/*
 * unit: yes
 * function: HAND_WAZA_AcupressureRaiseRandomStat, HAND_WAZA_GetRestHandlers
 * address: 0x021E4340
 * packet: pkt_ov093_021E4340
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: chained n = i = 0 initializes the index first; a fresh byte
 * pick for the random selection keeps the second loop's count in r4.
 * Reusing n for that selection swaps the second loop's r4/r5 allocation.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_CanChangeStatStage 0x021D5D14 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gAcupressureStats 0x021F2D20 data a4
 *   gRestHandlers 0x021F2888 data a4
 */
#include "../include/Obj06271.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
typedef signed char    s8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_CanChangeStatStage(s8 *p, int i, int sign);
extern u32 BTL_CALC_Random(u32);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
extern const u32 gAcupressureStats[];
extern int gRestHandlers[];

void HAND_WAZA_AcupressureRaiseRandomStat(int unused, void *s, int k)
{
    u8 v;
    void *q;
    u8 n;
    u8 i;
    u8 *p;
    u8 pick;
    if (k == BTL_EVENT_GetVar(3)) {
        v = BTL_EVENT_GetVar(6);
        q = BTL_SERVER_FLOW_GetPokeParam(s, v);
        n = i = 0;
        for (; i < 7; i++) {
            if (BTL_POKEPARAM_CanChangeStatStage(q, gAcupressureStats[i], 2) != 0)
                n++;
        }
        if (n != 0) {
            pick = BTL_CALC_Random(n);
            for (i = 0; i < 7; i++) {
                if (BTL_POKEPARAM_CanChangeStatStage(q, gAcupressureStats[i], 2) != 0) {
                    if (pick == 0) {
                        p = BTL_SERVER_FLOW_AllocCmdRecord(s, 14, k);
                        p[16] = v;
                        p[15] = 1;
                        ((struct Obj06271 *)p)->f4 = gAcupressureStats[i];
                        p[12] = 2;
                        p[14] = 0;
                        BTL_SERVER_FLOW_CommitCmdRecord(s, p);
                        return;
                    }
                    pick--;
                }
            }
        }
    }
}

int *HAND_WAZA_GetRestHandlers(int *p)
{
    *p = 2;
    return gRestHandlers;
}
