/*
 * function: func_021D7124
 * address:  0x021D7124
 * packet:   pkt_ov125_021D7124
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B99B8  0x021B99B8  thumb  ov114
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B9838  0x021B9838  thumb  ov114
 */

typedef unsigned char u8;

extern void func_021B99B8(u8 *p);
extern void func_021B9774(u8 *p);
extern void func_021B9838(u8 *p);

void func_021D7124(char *p, int unused, int k, int a3)
{
    if ((k == 3 || k == 6) && *(u8 **)(p + 0x404) != 0) {
        func_021B99B8(*(u8 **)(p + 0x404));
        func_021B9774(*(u8 **)(p + 0x404));
        func_021B9838(*(u8 **)(p + 0x404));
        *(int *)(p + 0x404) = 0;
    }
}
