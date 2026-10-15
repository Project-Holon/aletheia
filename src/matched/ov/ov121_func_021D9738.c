/*
 * function: MYSTERY_GRAPHIC_DrawEnd
 * address: 0x021D9738
 * packet: pkt_ov121_021D9738
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_GRAPHIC_FinishScene 0x021D9994 thumb ov121
 */
extern void MYSTERY_GRAPHIC_FinishScene(void **);
void MYSTERY_GRAPHIC_DrawEnd(char *p) { MYSTERY_GRAPHIC_FinishScene((void **)(p+12)); }
