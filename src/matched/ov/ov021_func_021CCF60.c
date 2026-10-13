/*
 * function: PARTY_SELECT_LIST_MenuMoveCallback
 * address:  0x021CCF60
 * packet:   pkt_ov021_021CCF60
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Dispatches on a selector below two to PARTY_SELECT_LIST_ShowParty, otherwise to PARTY_SELECT_LIST_HideParty, on the object from BMP_MENULIST_GetUserData.
 *
 * symbols:
 *   BMP_MENULIST_GetUserData  0x02020D0C  thumb
 *   PARTY_SELECT_LIST_ShowParty  0x021CD184  thumb  ov021
 *   PARTY_SELECT_LIST_HideParty  0x021CD1AC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern u32 BMP_MENULIST_GetUserData(u8 *p);
extern void PARTY_SELECT_LIST_ShowParty(void *p, u32 sel);
extern void PARTY_SELECT_LIST_HideParty(void *p);

void PARTY_SELECT_LIST_MenuMoveCallback(void *a, u32 sel)
{
    void *p = (void *)BMP_MENULIST_GetUserData(a);
    if (sel < 2)
        PARTY_SELECT_LIST_ShowParty(p, sel);
    else
        PARTY_SELECT_LIST_HideParty(p);
}
