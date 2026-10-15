/*
 * function: BTL_REC_SEL_GRAPHIC_DrawG3dEnd
 * address: 0x021BB46C
 * packet: pkt_ov214_021BB46C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * trailing: code ends at 021BB474; subsequent words are data.
 * symbols:
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */
extern void G3D_SYSTEM_DrawEnd(void);
void BTL_REC_SEL_GRAPHIC_DrawG3dEnd(void *a0) { G3D_SYSTEM_DrawEnd(); }
