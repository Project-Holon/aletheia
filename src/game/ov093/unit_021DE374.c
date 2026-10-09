/*
 * file:     unit_021DE374.c
 * function: func_021DE374, func_021DE3C8
 * address:  0x021DE374
 * packet:   pkt_ov093_021DE374
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F156C     0x021F156C  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   _ffltu         0x0209BE04  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021DCFF8(int a, int b);
typedef signed int     s32;
extern void func_021D7704(int key, s32 m);

void func_021DE374(int a, int b, int c)
{
    u32 v;

    if (c == func_021D775C(4)) {
        v = 100 - func_021DCFF8(a, 2);
        func_021D7704(0x35, (int)(v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) / 100);
    }
}


extern int d_021F156C[];
int *func_021DE3C8(int *p);

int *func_021DE3C8(int *p)
{
    *p = 1;
    return d_021F156C;
}
