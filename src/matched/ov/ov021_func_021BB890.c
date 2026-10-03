/*
 * function: func_021BB890
 * address:  0x021BB890
 * packet:   pkt_ov021_021BB890
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   d_021DE2F8     0x021DE2F8  data  a4
 */

extern int d_021DE2F8;

int *func_02030734(int a, int b, int c, void *d, int e);
typedef unsigned int   u32;
u32 func_02030CB0(u32 idx);
int func_02030CBC(int n, int buf);

int *func_021BB890(int a, int b, int n)
{
    int *p = func_02030734(b, 0x18, 1, &d_021DE2F8, 0x46);
    int sz;

    p[0] = a;
    p[1] = b;
    p[2] = n;
    p[3] = (int)func_02030734(b, 0x18 * n, 1, &d_021DE2F8, 0x4a);
    sz = func_02030CB0(n);
    p[5] = (int)func_02030734(b, sz, 1, &d_021DE2F8, 0x56);
    p[5] = func_02030CBC(n, p[5]);
    p[4] = (int)func_02030734(b, sz, 1, &d_021DE2F8, 0x59);
    p[4] = func_02030CBC(n, p[4]);
    return p;
}
