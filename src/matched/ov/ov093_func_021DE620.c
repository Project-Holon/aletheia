/*
 * unit:     yes
 * function: func_021DE620, func_021DE65C
 * address:  0x021DE620
 * packet:   pkt_ov093_021DE620
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
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F1474     0x021F1474  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int k);
extern void *func_021C7CF4(int a, u8 b);
struct UtilWork;
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern int func_021DD008(int a);
extern void func_021D7704(int key, int m);
extern int d_021F1474;

void func_021DE620(int a, int b, int c)
{
    u8 v;
    if (c == func_021D775C(3)) {
        v = func_021D775C(4);
        if (func_021D5BB0(func_021C7CF4(b, v), 1) != 0)
            func_021D7704(0x35, func_021DD008(a));
    }
}

int *func_021DE65C(int *p)
{
    *p = 1;
    return &d_021F1474;
}
