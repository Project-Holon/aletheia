/*
 * function: func_021F8154
 * address:  0x021F8154
 * packet:   pkt_021F8154
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F8178  0x021F8178  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021F8178(void *win, void *bank, int idx, u32 e, u32 x, u32 y, u16 color, int alt, u32 g);

void func_021F8154(void *win, void *bank, int idx, u32 e, u32 y, u16 color, int alt, void *g)
{
    func_021F8178(win, bank, idx, e, 0, y, color, alt, (u32)g);
}
