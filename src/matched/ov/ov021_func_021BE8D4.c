/*
 * function: func_021BE8D4
 * address:  0x021BE8D4
 * packet:   pkt_ov021_021BE8D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BEB78  0x021BEB78  thumb  ov021
 *   func_021BEAFC  0x021BEAFC  thumb  ov021
 *   func_021BEC24  0x021BEC24  thumb  ov021
 *   func_021BEC54  0x021BEC54  thumb  ov021
 *   func_021BECB4  0x021BECB4  thumb  ov021
 *   func_021BED14  0x021BED14  thumb  ov021
 *   func_021BED74  0x021BED74  thumb  ov021
 *   func_021BEDD4  0x021BEDD4  thumb  ov021
 */

typedef unsigned int   u32;
extern u32 func_021BEB78(u32 a, u32 b);
extern void *func_021BEAFC(int a, int b, int c, int d);
extern int func_021BEC24(int a, int b);
extern int func_021BEC54(int a, int b);
extern void *func_021BECB4(void *p, u32 b);
extern u32 func_021BED14(u32 a, u32 b);
extern int func_021BED74(int a, int b);
extern int func_021BEDD4(void *a, int b);

int func_021BE8D4(void *a, int b, int sel, int d)
{
    switch (sel) {
    default:
        return func_021BEB78((u32)a, b);
    case 0:
    case 1:
    case 3:
        return (int)func_021BEAFC((int)a, b, sel, d);
    case 4:
        return func_021BEC24((int)a, b);
    case 5:
        return func_021BEC54((int)a, b);
    case 6:
        return (int)func_021BECB4(a, b);
    case 7:
        return func_021BED14((u32)a, b);
    case 8:
        return func_021BED74((int)a, b);
    case 9:
        return func_021BEDD4(a, b);
    }
}
