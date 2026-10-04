/*
 * unit:     yes
 * function: func_021DE7E4, func_021DE828
 * address:  0x021DE7E4
 * packet:   pkt_ov093_021DE7E4
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
 *   func_021D6D54  0x021D6D54  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F14AC     0x021F14AC  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int k);
extern void *func_021C7CF4(int *p, int i);
struct QF;
struct R5;
extern u16 func_021D5444(struct QF *p);
extern int func_021D6D54(struct R5 *p);
extern void func_021D7704(int key, int m);
extern int d_021F14AC;

void func_021DE7E4(int u, int a, int b)
{
    void *m;
    if (b == func_021D775C(4)) {
        m = func_021C7CF4((int *)a, b);
        if (func_021D5444(m) == 0x84 && func_021D6D54(m) == 0) {
            if (func_021D775C(0x1a) == 1)
                func_021D7704(0x35, 4 << 11);
        }
    }
}

int *func_021DE828(int *p)
{
    *p = 1;
    return &d_021F14AC;
}
