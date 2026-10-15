/*
 * function: INTRO_GRAPHIC_Draw3dEnd
 * address: 0x021BDD6C
 * packet: pkt_ov204_021BDD6C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_GRAPHIC_DrawEnd 0x021BE100 thumb ov204
 */
extern void INTRO_GRAPHIC_DrawEnd(char *);
void INTRO_GRAPHIC_Draw3dEnd(char *p){INTRO_GRAPHIC_DrawEnd(p+8);}
