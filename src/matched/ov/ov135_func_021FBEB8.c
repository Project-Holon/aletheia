/*
 * function: func_021FBEB8
 * address:  0x021FBEB8
 * packet:   pkt_021FBEB8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_022028C8  0x022028C8  thumb
 *   func_02045334  0x02045334  arm
 *   func_0202CEBC  0x0202CEBC  thumb
 *   func_02045808  0x02045808  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02045EC0(void *bank, u32 index);
extern u32 func_022028C8(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);
extern void func_02045334(void *win);
extern void func_0202CEBC(void *mgr, u32 idx, void *win);
extern void func_02045808(void *p);

void func_021FBEB8(void *mgr, void *bank, void *win, u32 index, void *g)
{
    void *str = func_02045EC0(bank, index);

    func_022028C8(win, 0, str, 0, 0, 0, 0x3DC2, g);
    func_02045334(win);
    func_0202CEBC(mgr, 0, win);
    func_02045808(str);
}
