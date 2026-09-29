/*
 * function: func_021B9788
 * address:  0x021B9788
 * packet:   pkt_ov091_021B9788
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB714  0x021BB714  thumb  ov091
 *   func_021BB860  0x021BB860  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;

extern void func_021BB714(u8 *p, int v, int n);
extern void func_021BB860(u8 *p, int v, int a, int b);
extern void func_0204B3DC(int h, int f);

#define W(o) (*(int *)(p + (o)))

void func_021B9788(u8 *p, int a1, int a2, int a3)
{
    p[0xc] = 7;
    W(0x144) = a2;
    W(0x148) = a3;
    func_021BB714(p, W(0x150), 3);
    func_021BB860(p, W(0x150), a1, a2);
    func_0204B3DC(W(0x1e0), 0);
    func_0204B3DC(W(0x1e4), 0);
}
