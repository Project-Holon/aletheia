/*
 * function: PMS_SELECT_GRAPHIC_RedrawRowsAfterInput
 * address: 0x021C0C50
 * packet: pkt_ov110_021C0C50
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_SELECT_GRAPHIC_DrawRows 0x021C0C64 thumb ov110
 *   PMS_SELECT_GRAPHIC_ResetBgBlink 0x021C09E0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void PMS_SELECT_GRAPHIC_DrawRows(u8 *,int);
extern void PMS_SELECT_GRAPHIC_ResetBgBlink(u8 *);
void PMS_SELECT_GRAPHIC_RedrawRowsAfterInput(u8 *p) { PMS_SELECT_GRAPHIC_DrawRows(p,1); PMS_SELECT_GRAPHIC_ResetBgBlink(p+0x24); }
