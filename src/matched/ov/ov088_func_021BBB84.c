/*
 * function: STARTMENU_ClearFrameBox
 * address:  0x021BBB84
 * packet:   pkt_ov088_021BBB84
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Fills a w*h box at (x, y) on bg layer bg with tile 0, then commits the
 * layer.  bg is re-read from its stack slot (ldrb) for each call because
 * both callees take it as u8.
 *
 * symbols:
 *   func_02041300  0x02041300  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02041300(u8, u32, u8, u8, u8, u8, u32);
extern void func_02041B6C(u32 bit);
void STARTMENU_ClearFrameBox(u8 x, u8 y, u8 w, u8 h, u8 bg)
{
    func_02041300(bg, 0, x, y, w, h, 0);
    func_02041B6C(bg);
}
