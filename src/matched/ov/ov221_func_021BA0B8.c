/*
 * function: CHIHOU_ZUKAN_AWARD_GRAPHIC_VBlank, CHIHOU_ZUKAN_AWARD_GRAPHIC_GetValue
 * unit: yes
 * address: 0x021BA0B8
 * packet: pkt_ov221_021BA0B8
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
extern void CLACT_VBlankSystem(void);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_VBlank(void *p){CLACT_VBlankSystem();}
unsigned CHIHOU_ZUKAN_AWARD_GRAPHIC_GetValue(unsigned *p){return *p;}
