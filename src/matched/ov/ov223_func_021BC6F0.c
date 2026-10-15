/*
 * function: PSEL_GRAPHIC_G3dDrawEnd
 * address: 0x021BC6F0
 * packet: pkt_ov223_021BC6F0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */
extern void G3D_SYSTEM_DrawEnd(void);
void PSEL_GRAPHIC_G3dDrawEnd(unsigned char *unused){G3D_SYSTEM_DrawEnd();}
