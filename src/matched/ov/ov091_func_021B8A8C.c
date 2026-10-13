/*
 * function: POKELIST_UpdateCursorInput
 * address: 0x021B8A8C
 * packet: pkt_ov091_021B8A8C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   POKELIST_ReadCursorKeys 0x021B8AC4 thumb ov091
 *   POKELIST_HandleTouch 0x021B8DB4 thumb ov091
 */
#include "../include/Obj00009.h"
extern void POKELIST_ReadCursorKeys(unsigned char *);
extern void POKELIST_HandleTouch(unsigned char *);
void POKELIST_UpdateCursorInput(unsigned char *p) { POKELIST_ReadCursorKeys(p); if(p[15]==4) POKELIST_HandleTouch(p); if(p[15]!=4) p[14]=2; if(*(unsigned char *)(*(unsigned *)&((struct Obj00009 *)p)->f280+99)==1) { p[14]=2; p[15]=1; } }
