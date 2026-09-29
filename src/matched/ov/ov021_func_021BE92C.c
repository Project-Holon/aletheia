/*
 * function: func_021BE92C
 * address:  0x021BE92C
 * packet:   pkt_ov021_021BE92C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE92C  0x021BE92C  thumb
 *   func_021BEBA8  0x021BEBA8  thumb  ov021
 *   func_021BEB38  0x021BEB38  thumb  ov021
 *   func_021BEBD8  0x021BEBD8  thumb  ov021
 *   func_021BEC84  0x021BEC84  thumb  ov021
 *   func_021BECE4  0x021BECE4  thumb  ov021
 *   func_021BED44  0x021BED44  thumb  ov021
 *   func_021BEDA4  0x021BEDA4  thumb  ov021
 *   func_021BEE24  0x021BEE24  thumb  ov021
 */

typedef unsigned char u8;

extern int func_021BEBA8(void *a, int b);
extern int func_021BEB38(void *a, int b, int c, int d, int e);
extern int func_021BEBD8(void *a, int b, u8 c, u8 d);
extern int func_021BEC84(void *a, int b);
extern int func_021BECE4(void *a, int b);
extern int func_021BED44(void *a, int b);
extern int func_021BEDA4(void *a, int b);
extern int func_021BEE24(void *a, int b);

int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g)
{
    switch (sel) {
    default:
        return func_021BEBA8(a, b);
    case 0:
    case 1:
        return func_021BEB38(a, b, sel, d, e);
    case 3:
        return func_021BEBD8(a, b, f, g);
    case 5:
        return func_021BEC84(a, b);
    case 6:
        return func_021BECE4(a, b);
    case 7:
        return func_021BED44(a, b);
    case 8:
        return func_021BEDA4(a, b);
    case 9:
        return func_021BEE24(a, b);
    }
}
