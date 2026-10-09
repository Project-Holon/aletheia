/*
 * file:     unit_021DE79C.c
 * unit:     yes
 * function: func_021DE79C, func_021DE7D8
 * address:  0x021DE79C
 * packet:   pkt_ov093_021DE79C
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
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F1454     0x021F1454  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int k);
extern void *func_021C7CF4(int *p, int i);
struct QF;
extern u16 func_021D5444(struct QF *p);
extern void func_021D7704(int key, int m);
extern int d_021F1454;

void func_021DE79C(int u, int a, int b)
{
    if (b == func_021D775C(4)) {
        if (func_021D5444(func_021C7CF4((int *)a, b)) == 0x16e) {
            if (func_021D775C(0x1a) == 2)
                func_021D7704(0x35, 4 << 11);
        }
    }
}

int *func_021DE7D8(int *p)
{
    *p = 1;
    return &d_021F1454;
}
