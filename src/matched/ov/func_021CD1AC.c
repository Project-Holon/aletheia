/*
 * function: PARTY_SELECT_LIST_HideParty
 * address:  0x021CD1AC
 * packet:   pkt_021CD1AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   PARTY_SELECT_LIST_DeleteListWindow  0x021CD038  thumb  ov021
 *   PARTY_SELECT_LIST_SetMonIconsVisible  0x021CCBE0  thumb  ov021
 *   PARTY_SELECT_LIST_SetStatusIconsVisible  0x021CCE48  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void PARTY_SELECT_LIST_SetMonIconsVisible(u8 *s, int flag);
extern u32 PARTY_SELECT_LIST_SetStatusIconsVisible(u32, u32);
extern u32 PARTY_SELECT_LIST_DeleteListWindow(u32, u32, u32, u32);

int PARTY_SELECT_LIST_HideParty(u32 a, u32 b, u32 c, u32 d)
{
PARTY_SELECT_LIST_DeleteListWindow(a, b, c, d);
PARTY_SELECT_LIST_SetMonIconsVisible((u8 *)a, 2);
return PARTY_SELECT_LIST_SetStatusIconsVisible(a, 2);
}

