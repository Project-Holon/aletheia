/*
 * unit:     yes
 * function: func_021DE598, func_021DE5D0
 * address:  0x021DE598
 * packet:   pkt_ov093_021DE598
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F13DC     0x021F13DC  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int k);
extern void *func_021C7CF4(int a, int b);
struct QF;
extern u16 func_021D5444(struct QF *p);
extern void func_021D76BC(int a, u8 b);
extern int d_021F13DC;

void func_021DE598(int u, int a, int b)
{
    u8 v;
    if (b == func_021D775C(3)) {
        if (func_021D5444(func_021C7CF4(a, b)) == 0x71) {
            v = func_021D775C(0x2c);
            func_021D76BC(0x2c, v + 2);
        }
    }
}

int *func_021DE5D0(int *p)
{
    *p = 1;
    return &d_021F13DC;
}
