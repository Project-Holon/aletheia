/*
 * function: BTL_POKEPARAM_ChangeForm
 * address:  0x021D66D8
 * packet:   pkt_ov093_021D66D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   BTL_POKEPARAM_LoadStats  0x021D52B4  thumb  ov093
 */
#include "../include/Obj00041.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct {
    void *w;
    u8 pad4[8];
    u16 fC;
    u8 pad0E[13];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj;
struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);
extern u32 POKE_TOOL_GetPartyValue(void *h, u32 k, u32 z);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);
extern void BTL_POKEPARAM_LoadStats(u8 *p, void *h, u32 flag);

void BTL_POKEPARAM_ChangeForm(Obj *p, u32 v)
{
    u32 t;
    ((u8 *)p)[0x141] = v;
    t = POKE_TOOL_DecodePartyParam(p->w);
    POKE_TOOL_ChangeForm(p->w, v);
    BTL_POKEPARAM_LoadStats((u8 *)p, p->w, 1);
    if (p->fC == 0x1ec && v == 0) {
        p->f1b_lo = 0;
        ((struct Obj00041 *)p)->f13C = POKE_TOOL_GetPartyValue(p->w, 10, 0);
    }
    POKE_TOOL_EncodePartyParam(p->w, t);
}
