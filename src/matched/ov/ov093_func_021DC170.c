/*
 * function: HAND_TOKUSEI_Healer_CureAllyStatus
 * address:  0x021DC170
 * packet:   pkt_ov093_021DC170
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   HAND_TOKUSEI_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj06259.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
struct Unk021D62A8;
extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
extern int HAND_TOKUSEI_RollChanceOrFlag(int a, u32 b);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, void *);
void HAND_TOKUSEI_Healer_CureAllyStatus(int a, void *b, int c)
{
    u8 buf[4];
    u8 n;
    u8 i;
    u8 *p;
    int two = 2;

    if (c == BTL_EVENT_GetVar(2)) {
        n = BTL_SERVER_FLOW_CollectAlivePokeIds(b, (u16)((two << 9) | BTL_SERVER_FLOW_GetPokeViewPos(b, c)), buf);
        for (i = 0; i < n; i++) {
            if (buf[i] != c) {
                if (BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(b, buf[i])) && HAND_TOKUSEI_RollChanceOrFlag((int)b, 0x1e)) {
                    p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0xb, c);
                    ((struct Obj06259 *)p)->f0 |= 2 << 22;
                    ((struct Obj06259 *)p)->f0 |= 2 << 24;
                    p[0x14] = 1;
                    p[8] = buf[i];
                    ((struct Obj06259 *)p)->f4 = 0x24;
                    BTL_SERVER_FLOW_CommitCmdRecord(b, p);
                }
            }
        }
    }
}
