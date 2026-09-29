/*
 * function: func_021BF04C
 * address:  0x021BF04C
 * packet:   pkt_ov093_021BF04C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF0A4  0x021BF0A4  thumb  ov093
 *   func_021BF0B4  0x021BF0B4  thumb  ov093
 *   func_021BF0C4  0x021BF0C4  thumb  ov093
 *   func_021BF0D4  0x021BF0D4  thumb  ov093
 *   func_021BFA00  0x021BFA00  thumb  ov093
 *   func_021C572C  0x021C572C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021BF0A4(int c);
extern int func_021BF0B4(int c);
extern void func_021BF0C4(int c, int x);
extern int func_021BF0D4(int c);
extern int func_021BFA00(u8 *p, int s, int x, u32 v);
extern void func_021C572C(u8 *p, int x, u32 v);

void func_021BF04C(u8 *p, u16 *b, int s, int c)
{
    int x;
    func_021BF0A4(c);
    x = func_021BF0B4(c);
    while (x != 0) {
        if (func_021BFA00(p, s, x, *b) != 0) {
            func_021BF0C4(c, x);
            func_021C572C(p, x, *b);
            p[0x78a] |= 0x10;
        }
        x = func_021BF0D4(c);
    }
}
