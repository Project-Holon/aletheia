/*
 * function: PMS_SELECT_GRAPHIC_RedrawRows
 * address:  0x021C0C44
 * packet:   pkt_ov110_021C0C44
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMS_SELECT_GRAPHIC_DrawRows  0x021C0C64  thumb  ov110
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void PMS_SELECT_GRAPHIC_DrawRows(u8 *p, int flag);
void PMS_SELECT_GRAPHIC_RedrawRows(void *p) { PMS_SELECT_GRAPHIC_DrawRows(p, 0); }
