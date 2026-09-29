/*
 * function: func_021B977C
 * address:  0x021B977C
 * packet:   pkt_ov021_021B977C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021B976C  0x021B976C  thumb  ov021
 *   func_021B87D8  0x021B87D8  thumb  ov021
 *   d_021DE2B0     0x021DE2B0  data  a4
 *   d_021DE2B4     0x021DE2B4  data  a4
 *   d_021DE2BC     0x021DE2BC  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 d_021DE2B0[];
extern u8 d_021DE2B4[];
extern u8 d_021DE2BC[];

void func_021B976C(void *a, void *b, void *c);
void *func_021B87D8(void *a, u32 b);

void func_021B977C(u8 *p)
{
    void *x;
    void *y;

    if (*(u16 *)p == 0) {
        func_021B976C(0, *(void **)(p + 4), d_021DE2B0);
    } else if (*(u16 *)p == 1) {
        x = func_021B87D8(*(void **)(p + 0x24), **(u32 **)(p + 4));
        y = func_021B87D8(*(void **)(p + 0x24), *(u32 *)(*(u8 **)(p + 4) + 4));
        func_021B976C(d_021DE2B4, x, 0);
        func_021B976C(d_021DE2BC, y, d_021DE2B0);
    }
}
