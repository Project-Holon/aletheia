/*
 * function: POKETRADE_2D_BuildPartyMarkingTable
 * address: 0x021E3DBC
 * packet: pkt_ov119_021E3DBC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_GetMonMarkingIcon 0x021E3D04 thumb ov119
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 */
#include "../include/Obj22798.h"
typedef unsigned int   u32;
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void *POKE_TOOL_CastToBoxParam(void *);
extern unsigned char POKETRADE_2D_GetMonMarkingIcon(void *, unsigned int);
void POKETRADE_2D_BuildPartyMarkingTable(char *p, void *party, unsigned char *out)
{
    int count;
    unsigned char i;
    count = POKEPARTY_GetCount(party);
    for (i = 0; i < 6; i++) {
        if (count > i)
            out[i] = POKETRADE_2D_GetMonMarkingIcon(POKE_TOOL_CastToBoxParam(POKEPARTY_GetMember(party, i)), ((struct Obj22798 *)p)->f5F4);
        else
            out[i] = 0;
    }
}
