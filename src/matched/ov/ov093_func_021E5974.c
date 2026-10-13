/*
 * unit:     yes
 * function: HAND_WAZA_UTurnSwitchOut, HAND_WAZA_GetRapidSpinHandlers
 * address:  0x021E5974
 * packet:   pkt_ov093_021E5974
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
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   gRapidSpinHandlers     0x021F258C  data   ov093  a4
 */
#include "../include/Obj06274.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct Flag;
struct QQ;
extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(u8 *p, int i);
extern int BTL_SERVER_FLOW_TrySetOnceFlag(struct Flag *p);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 v);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern int gRapidSpinHandlers[];

void HAND_WAZA_UTurnSwitchOut(void *a, void *b, int c)
{
    u8 *m;
    int v;

    if (c == BTL_EVENT_GetVar(3) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(b, c) != 0 && BTL_SERVER_FLOW_TrySetOnceFlag(b) != 0) {
        v = BTL_MAIN_PokeIdToClientIdThunk(c);
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x29, c);
        m[0x4c] = c;
        BTL_SERVER_FLOW_InitMsgRecord(m + 4, 2, 0x302);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 4), c);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(m + 4), v);
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
        m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0x37, c);
        ((struct Obj06274 *)m)->f4 = (BTL_EVENT_GetFactorKey(a) == 0x171) ? 0x283 : 0x284;
        m[6] = BTL_SERVER_FLOW_GetPokeViewPos(b, c);
        m[7] = 6;
        ((struct Obj06274 *)m)->f0 |= 1 << 24;
        BTL_SERVER_FLOW_CommitCmdRecord(b, m);
    }
}

int *HAND_WAZA_GetRapidSpinHandlers(int *p)
{
    *p = 1;
    return gRapidSpinHandlers;
}
