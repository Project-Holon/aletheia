/*
 * function: BOX2_MAIN_RecalcPartyParam
 * address:  0x021DD8A8
 * packet:   pkt_021DD8A8
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 */
#include "../include/Obj18451.h"
typedef unsigned int u32;

extern void *POKEPARTY_GetMember(void *p, u32 idx);
struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern void POKE_TOOL_RecalcParam(void *p);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);

void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx)
{
    void *h;
    u32 v;

    if (idx < 0x1e)
        return;
    h = POKEPARTY_GetMember(((struct Obj18451 *)((char *)*pp))->f8, idx - 0x1e);
    v = POKE_TOOL_DecodePartyParam(h);
    POKE_TOOL_RecalcParam(h);
    POKE_TOOL_EncodePartyParam(h, v);
}
