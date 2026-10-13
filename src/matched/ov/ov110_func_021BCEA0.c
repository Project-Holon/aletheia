/*
 * function: PMSIV_MENU_PressEntry0
 * address: 0x021BCEA0
 * packet: pkt_ov110_021BCEA0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BCEBA.
 * symbols:
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_MENU_SetDecideEntry 0x021BCFBC thumb ov110
 */
#include "../include/Obj10278.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 PMS_INPUT_GetBrowseMode(u8 *);
extern void PMSIV_MENU_SetDecideEntry(char *,u32,int);
void PMSIV_MENU_PressEntry0(char *p) { if (PMS_INPUT_GetBrowseMode(*(u8 * *)&((struct Obj10278 *)p)->f4)==1) PMSIV_MENU_SetDecideEntry(p,0,1); }
