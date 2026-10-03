/*
 * function: func_021FAC50
 * address:  0x021FAC50
 * packet:   pkt_021FAC50
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022028C8  0x022028C8  thumb
 *   func_02045334  0x02045334  arm
 *   func_0202CEBC  0x0202CEBC  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct WinMgr;
extern u32 func_022028C8(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);
extern void func_02045334(void *win);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);

void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g)
{
    func_022028C8(win, 0, str, x, 0, 0, color, g);
    func_02045334(win);
    func_0202CEBC(mgr, 0, win);
}
