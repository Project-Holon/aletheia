/*
 * function: BTL_REC_SEL_GRAPHIC_DrawEnd
 * address: 0x021BB29C
 * packet: pkt_ov214_021BB29C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_REC_SEL_GRAPHIC_DrawG3dEnd 0x021BB46C thumb ov214
 */
extern void BTL_REC_SEL_GRAPHIC_DrawG3dEnd(void *);
void BTL_REC_SEL_GRAPHIC_DrawEnd(char *p) { BTL_REC_SEL_GRAPHIC_DrawG3dEnd(p+8); }
