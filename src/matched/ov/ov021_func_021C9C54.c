/*
 * function: BSUBWAY_SCR_LoadMembers
 * address:  0x021C9C54
 * packet:   pkt_ov021_021C9C54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Classifies the kind into the +8 count and reads two stats per slot into +0x22 and +0x2a.
 *
 * symbols:
 *   BSUBWAY_SCR_GetMemberNum  0x021CA270  thumb
 *   func_0200D884  0x0200D884  thumb
 *   BSUBWAY_SCR_GetParty  0x021CA210  thumb
 *   func_0201AB28  0x0201AB28  thumb
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

extern int BSUBWAY_SCR_GetMemberNum(u16 kind);
struct Blk3C;
extern u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
extern void *BSUBWAY_SCR_GetParty(u8 *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *m, u32 id, u32 v);

void BSUBWAY_SCR_LoadMembers(u8 *p, u32 x)
{
    void *h;
    int i;
    u32 m;

    p[8] = BSUBWAY_SCR_GetMemberNum(p[9]);
    func_0200D884((struct Blk3C *)(((struct Obj00116 *)p)->f70), 5, p + 0x1e);
    h = BSUBWAY_SCR_GetParty(p);
    for (i = 0; i < p[8]; i++) {
        m = (u32)func_0201AB28(h, p[0x1e + i]);
        ((Stats *)p)->a22[i] = POKE_TOOL_GetPartyValue((void *)m, 5, 0);
        ((Stats *)p)->a2a[i] = POKE_TOOL_GetPartyValue((void *)m, 6, 0);
    }
}
