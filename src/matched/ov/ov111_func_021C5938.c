/*
 * function: VIEWER_MAIN_SetWindowRect
 * address:  0x021C5938
 * packet:   pkt_ov111_021C5938
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);

void VIEWER_MAIN_SetWindowRect(void *p)
{
    BG_SYS_SetTileEntry(7, 0, 0x14, 6, 6, 9, 0x10);
}
