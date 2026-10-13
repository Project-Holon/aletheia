/*
 * function: BSUBWAY_SCR_SetSelectedMembers
 * address:  0x021C9F44
 * packet:   pkt_ov021_021C9F44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unless blocked, clamps each slot's +0x7c id to 1..6, copies it into +0x1e and reloads the slot's two stats.
 *
 * symbols:
 *   BSUBWAY_SCR_GetParty  0x021CA210  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00116.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0x22];
    u16 a22[4];
    u16 a2a[4];
} Stats;

extern void *BSUBWAY_SCR_GetParty(u8 *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *m, u32 id, u32 c);

u32 BSUBWAY_SCR_SetSelectedMembers(u8 *p, u32 x)
{
    void *h;
    u16 i;
    u8 *q;
    u32 m;

    if (((struct Obj00116 *)p)->f84 != 0 || ((struct Obj00116 *)p)->f82 == 7 || ((struct Obj00116 *)p)->f82 == 8)
        return 0;
    h = BSUBWAY_SCR_GetParty(p);
    for (i = 0; i < p[8]; i++) {
        q = p + i;
        if (q[0x7c] - 1 >= 6)
            q[0x7c] = 1;
        q[0x1e] = q[0x7c] - 1;
        m = (u32)POKEPARTY_GetMember(h, q[0x1e]);
        ((Stats *)p)->a22[i] = POKE_TOOL_GetPartyValue((void *)m, 5, 0);
        ((Stats *)p)->a2a[i] = POKE_TOOL_GetPartyValue((void *)m, 6, 0);
    }
    return 1;
}
