/*
 * function: func_021D096C
 * address:  0x021D096C
 * packet:   pkt_ov021_021D096C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * symbols:
 *   func_0200E588  0x0200E588  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   func_0201A920  0x0201A920  thumb
 *   func_021D09D0  0x021D09D0  thumb  ov021
 *   d_021DE674     0x021DE674  data  a4
 */

typedef unsigned short u16;

extern int d_021DE674;

extern int func_0200E588(void);
extern int func_020120F4(int x);
extern int func_02012EBC(int x);
extern void *func_02030734(int a, int b, int c, void *d, int e);
extern int func_0201A920(int x);
extern void func_021D09D0(int a, void *p);

void *func_021D096C(int a)
{
    char *p;
    int r7;

    r7 = func_0200E588();
    func_02012EBC(func_020120F4(a));
    p = func_02030734(5, 0x154, 1, &d_021DE674, 0x5D);
    *(u16 *)(p + 0x120) = 5;
    *(int *)(p + 0x14C) = (int)func_02030734(5, r7, 1, &d_021DE674, 0x5F);
    func_021D09D0(a, p);
    *(int *)(p + 0x128) = func_0201A920(*(u16 *)(p + 0x120));
    return p;
}
