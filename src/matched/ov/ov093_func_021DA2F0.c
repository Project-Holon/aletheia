/*
 * unit: yes
 * function: HAND_TOKUSEI_NaturalCureOnMemberOut, HAND_TOKUSEI_AddNaturalCure
 * address: 0x021DA2F0
 * packet: pkt_ov093_021DA2F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gNaturalCureHandlers 0x021F07F0 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 * extent: includes store-and-return followers 021DA320.
 */
#include "../include/Obj07811.h"
extern unsigned char gNaturalCureHandlers[];
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);

void HAND_TOKUSEI_NaturalCureOnMemberOut(int a, void *b, int c)
{
    unsigned char *p;
    if (c == BTL_EVENT_GetVar(2)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(b, 11, c);
        ((struct Obj07811 *)p)->f4 = 0x24;
        p[0x14] = 1;
        p[8] = c;
        p[0x15] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(b, p);
    }
}

void *HAND_TOKUSEI_AddNaturalCure(int *p)
{
    *p = 1;
    return gNaturalCureHandlers;
}
