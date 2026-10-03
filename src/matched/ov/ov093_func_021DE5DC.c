/*
 * unit:     yes
 * function: func_021DE5DC, func_021DE614
 * address:  0x021DE5DC
 * packet:   pkt_ov093_021DE5DC
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
 *   d_021F13D4     0x021F13D4  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int k);
extern void *func_021C7CF4(int a, int b);
struct QF;
extern u16 func_021D5444(struct QF *p);
extern void func_021D76BC(int a, u8 b);
extern int d_021F13D4;

void func_021DE5DC(int u, int a, int b)
{
    u8 v;
    if (b == func_021D775C(3)) {
        if (func_021D5444(func_021C7CF4(a, b)) == 0x53) {
            v = func_021D775C(0x2c);
            func_021D76BC(0x2c, v + 2);
        }
    }
}

int *func_021DE614(int *p)
{
    *p = 1;
    return &d_021F13D4;
}
