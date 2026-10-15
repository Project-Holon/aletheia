/*
 * function: MYSTERY_GRAPHIC_DrawScene
 * address: 0x021D972C
 * packet: pkt_ov121_021D972C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_GRAPHIC_RenderScene 0x021D9974 thumb ov121
 */
extern void MYSTERY_GRAPHIC_RenderScene(void **);
void MYSTERY_GRAPHIC_DrawScene(char *p) { MYSTERY_GRAPHIC_RenderScene((void **)(p+12)); }
