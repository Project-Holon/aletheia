/*
 * function: func_021BF83C
 * address:  0x021BF83C
 * packet:   pkt_ov093_021BF83C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BF894  0x021BF894  thumb  ov093
 *   func_021BF8A4  0x021BF8A4  thumb  ov093
 *   func_021BF8B4  0x021BF8B4  thumb  ov093
 *   func_021BF8C4  0x021BF8C4  thumb  ov093
 *   func_021BF324  0x021BF324  thumb  ov093
 *   func_021C6948  0x021C6948  thumb  ov093
 *   func_021C572C  0x021C572C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021BF894(int d);
extern u8 *func_021BF8A4(int d);
extern void func_021BF8B4(int d, u8 *x);
extern u8 *func_021BF8C4(int d);
extern int func_021BF324(u8 *p, u8 *a, u8 *b);
extern int func_021C6948(u8 *p, u8 *a, u8 *b, u32 v);
extern void func_021C572C(u8 *p, u8 *x, u32 v);

void func_021BF83C(u8 *p, u16 *b, u8 *c, int d)
{
    u8 *x;
    func_021BF894(d);
    x = func_021BF8A4(d);
    while (x != 0) {
        if (func_021BF324(p, c, x) == 0) {
            if (func_021C6948(p, c, x, *b) != 0) {
                func_021BF8B4(d, x);
                func_021C572C(p, x, *b);
            }
        }
        x = func_021BF8C4(d);
    }
}
