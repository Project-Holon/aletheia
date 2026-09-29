/*
 * unit:     yes
 * function: func_021DE834, func_021DE86C
 * address:  0x021DE834
 * packet:   pkt_ov093_021DE834
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
 *   d_021F16AC     0x021F16AC  data   a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int k);
extern void *func_021C7CF4(int a, int b);
extern u16 func_021D5444(void *p);
extern int func_021D6D54(void *p);
extern void func_021D7704(int key, int m);
extern int d_021F16AC;

void func_021DE834(int u, int a, int b)
{
    void *m;
    if (b == func_021D775C(2)) {
        m = func_021C7CF4(a, b);
        if (func_021D5444(m) == 0x84 && func_021D6D54(m) == 0)
            func_021D7704(0x35, 2 << 12);
    }
}

int *func_021DE86C(int *p)
{
    *p = 2;
    return &d_021F16AC;
}
