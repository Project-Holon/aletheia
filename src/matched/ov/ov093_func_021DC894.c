/*
 * function: HAND_TOKUSEI_MoxieRaiseAttackOnKnockOut
 * address:  0x021DC894
 * packet:   pkt_ov093_021DC894
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "../include/Obj06261.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);

void HAND_TOKUSEI_MoxieRaiseAttackOnKnockOut(int a, void *b, u8 c)
{
    u32 n;
    u32 i;
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        n = BTL_EVENT_GetVar(5);
        for (i = 0; i < n; i++) {
            if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(b, (u8)BTL_EVENT_GetVar(i + 6))) != 0) {
                m = (u8 *)BTL_SERVER_FLOW_AllocCmdRecord(b, 0xe, c);
                ((struct Obj06261 *)m)->f0 |= 2 << 22;
                m[0xf] = 1;
                m[0x10] = c;
                ((struct Obj06261 *)m)->f4 = 1;
                m[0xc] = 1;
                BTL_SERVER_FLOW_CommitCmdRecord(b, m);
            }
        }
    }
}
