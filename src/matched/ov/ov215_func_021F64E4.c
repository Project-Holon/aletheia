/*
 * function: EGG_DEMO_GRAPHIC_Draw3d
 * address: 0x021F64E4
 * packet: pkt_ov215_021F64E4
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EGG_DEMO_GRAPHIC_DrawG3d 0x021F66AC thumb ov215
 */
extern void EGG_DEMO_GRAPHIC_DrawG3d(void *);
void EGG_DEMO_GRAPHIC_Draw3d(char *p){EGG_DEMO_GRAPHIC_DrawG3d(p+8);}
