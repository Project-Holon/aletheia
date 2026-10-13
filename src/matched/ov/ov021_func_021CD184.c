/*
 * function: PARTY_SELECT_LIST_ShowParty
 * address:  0x021CD184
 * packet:   pkt_ov021_021CD184
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Selector 0 or 1 path of PARTY_SELECT_LIST_MenuMoveCallback: applies the +4 or +8 entry, then refreshes the two per-selector views.
 *
 * symbols:
 *   PARTY_SELECT_LIST_PrintPartyNames  0x021CD050  thumb  ov021
 *   PARTY_SELECT_LIST_SetMonIconsVisible  0x021CCBE0  thumb  ov021
 *   PARTY_SELECT_LIST_SetStatusIconsVisible  0x021CCE48  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
} Obj;

extern void PARTY_SELECT_LIST_PrintPartyNames(Obj *o, void *e);
typedef unsigned char  u8;
extern void PARTY_SELECT_LIST_SetMonIconsVisible(u8 *s, int flag);
extern void PARTY_SELECT_LIST_SetStatusIconsVisible(u8 *s, int flag);

void PARTY_SELECT_LIST_ShowParty(Obj *o, u32 sel)
{
    PARTY_SELECT_LIST_PrintPartyNames(o, sel == 0 ? o->f4 : o->f8);
    PARTY_SELECT_LIST_SetMonIconsVisible((u8 *)o, sel);
    PARTY_SELECT_LIST_SetStatusIconsVisible((u8 *)o, sel);
}
