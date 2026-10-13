/*
 * function: HAND_WAZA_CureParty
 * address:  0x021E4958
 * packet:   pkt_ov093_021E4958
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPartyOfPoke  0x021C7FCC  thumb  ov093
 *   BTL_SERVER_FLOW_GetPartyOfPokeIfClientUsed  0x021C7FE0  thumb  ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer  0x021C8120  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   HAND_WAZA_CollectStatusedPokeIds  0x021E4A08  thumb  ov093
 */
#include "../include/Obj10091.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern u8 *BTL_SERVER_FLOW_GetPartyOfPoke(u8 *s, int k);
extern char *BTL_SERVER_FLOW_GetPartyOfPokeIfClientUsed(u8 *p, int v);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(u8 *s, int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern u8 HAND_WAZA_CollectStatusedPokeIds(u8 *x, u8 idx, u8 lim, u8 *buf);

void HAND_WAZA_CureParty(int a0, u8 *s, int k, int a3, u16 x)
{
    u8 *a;
    int b;
    u8 *p;
    u8 *e;
    u8 *e2;
    u8 n;
    u8 i;

    if (k == BTL_EVENT_GetVar(3)) {
        a = BTL_SERVER_FLOW_GetPartyOfPoke(s, k);
        b = (int)BTL_SERVER_FLOW_GetPartyOfPokeIfClientUsed(s, k);
        p = BTL_SERVER_FLOW_GetScratchBuffer(s, 12);
        e = BTL_SERVER_FLOW_AllocCmdRecord((char *)s, 4, k);
        BTL_SERVER_FLOW_InitMsgRecord(e + 4, 1, x);
        BTL_SERVER_FLOW_CommitCmdRecord(s, e);
        n = HAND_WAZA_CollectStatusedPokeIds(a, 0, 12, p);
        if (b != 0)
            n = n + HAND_WAZA_CollectStatusedPokeIds((u8 *)b, n, 12, p);
        if (n != 0) {
            if (n > 12)
                n = 12;
            e2 = BTL_SERVER_FLOW_AllocCmdRecord((char *)s, 0xb, k);
            e2[0x14] = n;
            for (i = 0; i < n; i++)
                e2[8 + i] = p[i];
            ((struct Obj10091 *)e2)->f4 = 0x24;
            BTL_SERVER_FLOW_CommitCmdRecord(s, e2);
        }
    }
}
