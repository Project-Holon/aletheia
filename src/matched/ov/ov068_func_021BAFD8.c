/*
 * function: OPTION_MENU_SelectChoice
 * address: 0x021BAFD8
 * packet: pkt_ov068_021BAFD8
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gOptionMenuChoices 0x021BB704 data a4
 *   OPTION_MENU_WriteSettings 0x021BAFA8 thumb ov068
 */

#include "../include/G__anon_Entry.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern struct _anon_Entry gOptionMenuChoices[];
extern void OPTION_MENU_WriteSettings(u8 *);
void OPTION_MENU_SelectChoice(u8 *p, int i)
{
    if (p[gOptionMenuChoices[i].offset] != gOptionMenuChoices[i].value) {
        p[gOptionMenuChoices[i].offset] = gOptionMenuChoices[i].value;
        p[5] = i;
        OPTION_MENU_WriteSettings(p);
    }
}
