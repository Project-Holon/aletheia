/*
 * function: PMSIV_MENU_PressEntry2
 * address: 0x021BCDE0
 * packet: pkt_ov110_021BCDE0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_MENU_SetDecideEntry 0x021BCFBC thumb ov110
 */
#include "../include/Obj10278.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void PMSIV_MENU_SetDecideEntry(char *p, u32 index, int value);
void PMSIV_MENU_PressEntry2(u8 *p)
{
    if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj10278 *)p)->f4) == 1) PMSIV_MENU_SetDecideEntry((char *)p, 2, 1);
}
