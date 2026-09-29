/*
 * function: func_021F4318
 * address:  0x021F4318
 * packet:   pkt_ov055_021F4318
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_021F4388  0x021F4388  thumb  ov055
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern int func_021F4388(int a, int b, int c, int d, u16 hi, u16 lo, u16 dir);

int func_021F4318(const u8 *a, void *b, u16 c, u16 d)
{
    int x0 = func_0216D83C(b);
    int y0 = func_0216D86C(b);
    int x1 = func_0216D83C(*(void * const *)(a + 0xc));
    int y1 = func_0216D86C(*(void * const *)(a + 0xc));
    int x2;
    int y2;

    if (func_021F4388(x1, y1, x0, y0, c, d, a[3])) {
        return 1;
    }
    x2 = func_0216D804(b);
    y2 = func_0216D81C(b);
    return func_021F4388(x1, y1, x2, y2, c, d, a[3]);
}
