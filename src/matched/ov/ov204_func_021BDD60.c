/*
 * function: INTRO_GRAPHIC_Draw3d
 * address: 0x021BDD60
 * packet: pkt_ov204_021BDD60
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_GRAPHIC_DrawCamera 0x021BE0EC thumb ov204
 */
extern void INTRO_GRAPHIC_DrawCamera(char *);
void INTRO_GRAPHIC_Draw3d(char *p){INTRO_GRAPHIC_DrawCamera(p+8);}
