/*
 * function: func_021BEE24
 * address:  0x021BEE24
 * packet:   pkt_ov021_021BEE24
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021BED44  0x021BED44  thumb  ov021
 *   func_021BEDA4  0x021BEDA4  thumb  ov021
 *   func_021BEC84  0x021BEC84  thumb  ov021
 *   func_021BECE4  0x021BECE4  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02188CB4(u8 *p);
extern u16 func_021A3050(u8 *p);
extern void *func_021BED44(int a, int b);
extern int func_021BEDA4(int a, int b);
extern void *func_021BEC84(void *a, u32 b);
extern void *func_021BECE4(int a, int b);

void func_021BEE24(void *a, void *b)
{
    switch (func_021A3050(func_02188CB4(b))) {
    case 2:
    default:
        func_021BED44((int)a, (int)b);
        break;
    case 3:
        func_021BEDA4((int)a, (int)b);
        break;
    case 0:
        func_021BEC84(a, (u32)b);
        break;
    case 1:
        func_021BECE4((int)a, (int)b);
        break;
    }
}
