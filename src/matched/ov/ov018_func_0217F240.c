/*
 * function: INTRUDE_SUBDISP_DrawInfoPanel
 * address:  0x0217F240
 * packet:   pkt_ov018_0217F240
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u32 bit);
extern void func_020409B4(u32 layer);

void INTRUDE_SUBDISP_DrawInfoPanel(u8 *p, int mode)
{
    BG_SYS_DrawTileEx(6, 0x14, 0x16, 0xC, 2, (u32)(p + 0x138), 0, 0, 0xC, 2);
    if (mode == 1) {
        func_02041B6C(6);
    } else {
        func_020409B4(6);
    }
}
