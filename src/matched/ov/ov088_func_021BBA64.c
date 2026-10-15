/*
 * function: STARTMENU_DrawFrameBox
 * address:  0x021BBA64
 * packet:   pkt_ov088_021BBA64
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Nine-slice frame fill: corners, edges and centre of a w*h box at (x, y)
 * with tiles 1..9 on bg layer `bg`, then commits the layer.
 *
 * The layer is declared narrow and read back as a whole word through its
 * address (`*(u32 *)&bg`).  That read is a memory load the scheduler must
 * keep ahead of the outgoing stack-argument stores, so `ldr r5, [sp, #0x38]`
 * opens the body, as in the image.  A plain u32/int parameter (or a copy
 * of one, volatile included) loads the same word but lets the scheduler
 * sink it below two of those stores.  Any narrow parameter type works
 * (u8/s8/u16); the word read needs the local copy, not one per call.
 *
 * symbols:
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void BG_SYS_SetTileEntry(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5,
                          u32 a6);
extern void func_02041B6C(u32);

void STARTMENU_DrawFrameBox(u8 x, u8 y, u8 w, u8 h, u8 bg)
{
    u32 layer = *(u32 *)&bg;

    BG_SYS_SetTileEntry(layer, 1, x, y, 1, 1, 1);
    BG_SYS_SetTileEntry(layer, 3, x + w - 1, y, 1, 1, 1);
    BG_SYS_SetTileEntry(layer, 7, x, y + h - 1, 1, 1, 1);
    BG_SYS_SetTileEntry(layer, 9, x + w - 1, y + h - 1, 1, 1, 1);
    BG_SYS_SetTileEntry(layer, 2, x + 1, y, w - 2, 1, 1);
    BG_SYS_SetTileEntry(layer, 8, x + 1, y + h - 1, w - 2, 1, 1);
    BG_SYS_SetTileEntry(layer, 4, x, y + 1, 1, h - 2, 1);
    BG_SYS_SetTileEntry(layer, 6, x + w - 1, y + 1, 1, h - 2, 1);
    BG_SYS_SetTileEntry(layer, 5, x + 1, y + 1, w - 2, h - 2, 1);
    func_02041B6C(layer);
}
