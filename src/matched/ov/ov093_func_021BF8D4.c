/*
 * function: func_021BF8D4
 * address:  0x021BF8D4
 * packet:   pkt_ov093_021BF8D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BF944  0x021BF944  thumb  ov093
 *   func_021BF954  0x021BF954  thumb  ov093
 *   func_021BF964  0x021BF964  thumb  ov093
 *   func_021BF974  0x021BF974  thumb  ov093
 *   func_021BF984  0x021BF984  thumb  ov093
 *   func_021BF994  0x021BF994  thumb  ov093
 *   func_021BF9A4  0x021BF9A4  thumb  ov093
 *   func_021BFA60  0x021BFA60  thumb  ov093
 *   func_021C572C  0x021C572C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021BF944(int d);
extern u8 *func_021BF954(int d, int k);
extern void func_021BF964(int d);
extern u8 *func_021BF974(int d);
extern void func_021BF984(int d, u8 *x);
extern u8 *func_021BF994(int d);
extern int func_021BF9A4(u8 *p, u8 *a, u8 *b, u16 *c);
extern int func_021BFA60(u8 *p, u8 *a, u8 *b, u16 *c);
extern void func_021C572C(u8 *p, u8 *x, u32 v);

void func_021BF8D4(u8 *p, u16 *b, u8 *c, int d)
{
    u8 *x;
    if (func_021BF944(d) == 1 && func_021BF954(d, 0) == c)
        return;
    func_021BF964(d);
    x = func_021BF974(d);
    while (x != 0) {
        if (func_021BF9A4(p, c, x, b) == 0 && func_021BFA60(p, c, x, b) == 0) {
            func_021BF984(d, x);
            func_021C572C(p, x, *b);
        }
        x = func_021BF994(d);
    }
}
