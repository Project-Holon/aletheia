/*
 * function: CHIHOU_ZUKAN_AWARD_GRAPHIC_GetActor
 * address: 0x021B9F90
 * packet: pkt_ov221_021B9F90
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_GetValue 0x021BA0C0 thumb ov221
 */
extern unsigned CHIHOU_ZUKAN_AWARD_GRAPHIC_GetValue(unsigned *);
unsigned CHIHOU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p){return CHIHOU_ZUKAN_AWARD_GRAPHIC_GetValue((unsigned *)(p+4));}
