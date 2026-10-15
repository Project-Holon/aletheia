/*
 * function: SCRCMD_POKE_ICON_ShowWindow
 * address:  0x021D25E8
 * packet:   pkt_021D25E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the leading word and a constant one.
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BMP_MENUWORK_DrawWindowBorder(u32 v, u32 a);

void SCRCMD_POKE_ICON_ShowWindow(u32 *p)
{
    BMP_MENUWORK_DrawWindowBorder(p[0], 1);
}
