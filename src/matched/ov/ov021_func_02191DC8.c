/*
 * function: FIELD_MSGBG_DrawBgWinFrame
 * address:  0x02191DC8
 * packet:   pkt_ov021_02191DC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetTileEntry  0x02041300  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BG_SYS_SetTileEntry(u8 layer, u16 tile, u8 x, u8 y, u8 w, u8 h, u8 pal);

void FIELD_MSGBG_DrawBgWinFrame(u8 layer, u8 x, u8 y, u8 w, u8 h, u16 tile, u8 pal)
{
    BG_SYS_SetTileEntry(layer, tile, x - 2, y - 1, 1, 1, pal);
    BG_SYS_SetTileEntry(layer, tile + 1, x - 1, y - 1, 1, 1, pal);
    BG_SYS_SetTileEntry(layer, tile + 2, x, y - 1, w, 1, pal);
    BG_SYS_SetTileEntry(layer, tile + 4, x + w, y - 1, 1, 1, pal);
    BG_SYS_SetTileEntry(layer, tile + 5, x + w + 1, y - 1, 1, 1, pal);
    BG_SYS_SetTileEntry(layer, tile + 6, x - 2, y, 1, h, pal);
    BG_SYS_SetTileEntry(layer, tile + 7, x - 1, y, 1, h, pal);
    BG_SYS_SetTileEntry(layer, tile + 10, x + w, y, 1, h, pal);
    BG_SYS_SetTileEntry(layer, tile + 11, x + w + 1, y, 1, h, pal);
    BG_SYS_SetTileEntry(layer, tile + 12, x - 2, y + h, 1, 1, pal);
    BG_SYS_SetTileEntry(layer, tile + 13, x - 1, y + h, 1, 1, pal);
    BG_SYS_SetTileEntry(layer, tile + 14, x, y + h, w, 1, pal);
    BG_SYS_SetTileEntry(layer, tile + 16, x + w, y + h, 1, 1, pal);
    BG_SYS_SetTileEntry(layer, tile + 17, x + w + 1, y + h, 1, 1, pal);
}
