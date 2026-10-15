/*
 * function: BOX2_SEQ_CheckTradableMon
 * address:  0x021EA8CC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_HasOtherTradable  0x021DD694  thumb  ov170
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 *
 * Busy 1 for the 0x16 field below 0x1e, else run the panel query and
 *   answer 2 for a hit, 0 otherwise.  `p` must be unsigned char *
 *   (ldrb, not ldrsb) and the result must be the CONSTANTS 1/2/0 with
 *   an early return -- an `int r = 0; ... return r;` keeps r live from
 *   the top, which pushes i from r4 to r6 and widens the push set.
 */
#include "../include/Obj12168.h"

typedef unsigned int u32;

extern int BOX2_MAIN_HasOtherTradable(void ***p, unsigned skip);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
typedef unsigned short u16;
extern u32 func_0202136C(u16 v);
extern int BOX2_MAIN_HasOtherTradable(void ***p, unsigned skip);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern u32 func_0202136C(u16 v);
int BOX2_SEQ_CheckTradableMon(unsigned char *p)
{
    int i = p[0x16] - 0x1e;
    if (BOX2_MAIN_HasOtherTradable((void ***)p, i) == 0)
        return 1;
    if (func_0202136C((unsigned short)POKE_TOOL_GetPartyValue(
            POKEPARTY_GetMember(*(void **)(((struct Obj12168 *)p)->f0 + 8), i), 6, 0)) == 1)
        return 2;
    return 0;
}

