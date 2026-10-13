/*
 * unit:     yes
 * function: HAND_WAZA_BatonPassSwitchOut, HAND_WAZA_GetTeleportHandlers
 * address:  0x021E5B78
 * packet:   pkt_ov093_021E5B78
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
 *   BTL_SERVER_FLOW_TrySetOnceFlag  0x021C7F4C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gTeleportHandlers     0x021F2CD8  data   ov093  a4
 */
#include "../include/Obj02791.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct Flag;
extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(u8 *p, int i);
extern int BTL_SERVER_FLOW_TrySetOnceFlag(struct Flag *p);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int gTeleportHandlers[];

void HAND_WAZA_BatonPassSwitchOut(int a, void *b, int c)
{
    u8 *m;

    if (c == BTL_EVENT_GetVar(3) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(b, c) != 0 && BTL_SERVER_FLOW_TrySetOnceFlag(b) != 0) {
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x1e, c);
        ((struct Obj02791 *)m)->f4 = 4;
        m[8] = BTL_SERVER_FLOW_GetPokeViewPos(b, c);
        ((struct Obj02791 *)m)->fC = c;
        m[0x1c] = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x17, c);
        m[8] = c;
        ((struct Obj02791 *)m)->f4 = 0xe;
        ((struct Obj02791 *)m)->f0 |= 1 << 24;
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x29, c);
        m[0x4c] = c;
        m[0x4d] = 1;
        ((struct Obj02791 *)m)->f0 |= 1 << 24;
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
    }
}

int *HAND_WAZA_GetTeleportHandlers(int *p)
{
    *p = 3;
    return gTeleportHandlers;
}
