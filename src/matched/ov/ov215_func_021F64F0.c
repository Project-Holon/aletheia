/*
 * function: EGG_DEMO_GRAPHIC_DrawEnd
 * address: 0x021F64F0
 * packet: pkt_ov215_021F64F0
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EGG_DEMO_GRAPHIC_DrawG3dEnd 0x021F66C0 thumb ov215
 */
extern void EGG_DEMO_GRAPHIC_DrawG3dEnd(void *);
void EGG_DEMO_GRAPHIC_DrawEnd(char *p){EGG_DEMO_GRAPHIC_DrawG3dEnd(p+8);}
