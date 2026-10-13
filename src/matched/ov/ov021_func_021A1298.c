/*
 * function: FIELD_SUBSCREEN_UpdateMenuNoTransition
 * address: 0x021A1298
 * packet: pkt_ov021_021A1298
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/unit_021A1144.c and filed here.
 *
 * symbols:
 *   FIELD_MENU_ApplyBgScroll 0x021A8840 thumb ov021
 */

typedef unsigned int   u32;
extern void FIELD_MENU_ApplyBgScroll(void *s);
void FIELD_SUBSCREEN_UpdateMenuNoTransition(u32 *p);

void FIELD_SUBSCREEN_UpdateMenuNoTransition(u32 *p) { FIELD_MENU_ApplyBgScroll((void *)p[8]); }
