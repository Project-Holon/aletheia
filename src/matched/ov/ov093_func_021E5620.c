/*
 * unit:     yes
 * function: HAND_WAZA_LunarDanceSetPosEffect, HAND_WAZA_GetHealingWishHandlers
 * address:  0x021E5620
 * packet:   pkt_ov093_021E5620
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckClientHasBackupPoke  0x021C7F24  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gHealingWishHandlers     0x021F2694  data   ov093  a4
 */
#include "../include/Obj10094.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(u8 *p, int i);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int gHealingWishHandlers[];

void HAND_WAZA_LunarDanceSetPosEffect(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(b, c) != 0) {
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x1e, c);
        ((struct Obj10094 *)m)->f4 = 1;
        m[8] = BTL_SERVER_FLOW_GetPokeViewPos(b, c);
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x13, c);
        m[4] = c;
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
    }
}

int *HAND_WAZA_GetHealingWishHandlers(int *p)
{
    *p = 1;
    return gHealingWishHandlers;
}
