/*
 * function: func_021C6488
 * address:  0x021C6488
 * packet:   pkt_021C6488
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CFFAC   0x021CFFAC   arm
 *   func_021D7680   0x021D7680   arm
 *   func_021C61A4   0x021C61A4   arm
 *   g_021DE5D8      0x021DE5D8   data
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct G021DE5D8 {
    u8  pad00[2];
    u16 f2;
    u8 *f4;
};

extern struct G021DE5D8 g_021DE5D8;
extern void func_021CFFAC(unsigned int v);
extern void *func_021D7680(int a, void *b, int c, int d);
extern void  func_021C61A4(void);

void func_021C6488(void)
{
    u8 *p = g_021DE5D8.f4;

    if (g_021DE5D8.f2 == *(u16 *)(p + 0x40) || p[0x51] <= 4) {
        if (p[0x59] == 0) {
            func_021CFFAC(9);
            g_021DE5D8.f4[0x59] = 1;
        }
        return;
    }
    func_021CFFAC(0x13);
    *(void **)(g_021DE5D8.f4 + 0x38) = func_021D7680(0, func_021C61A4, 0, 0x78);
}
