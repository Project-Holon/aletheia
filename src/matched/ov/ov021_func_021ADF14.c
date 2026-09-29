/*
 * function: func_021ADF14
 * address:  0x021ADF14
 * packet:   pkt_ov021_021ADF14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   d_021DE120     0x021DE120  data  a2
 */

typedef unsigned short u16;

extern u16 d_021DE120;

extern int func_021ABE24(int a);
extern int func_02046E24(int a, int b);
extern void func_02046FF8(void);
extern int func_02047400(int a, int b, int c);
extern int func_02047564(int a, int b, int c);
extern int func_0204767C(int a, int *b, int c);
extern void func_020477A4(int a, int b);

void func_021ADF14(int *p)
{
    int r5 = func_021ABE24(p[0]);

    p[1] = func_02046E24(r5, 0x54);
    func_02046FF8();
    p[2] = func_02046E24(r5, d_021DE120);
    p[5] = func_02047400(p[1], 0, p[1]);
    p[4] = func_02047564(p[5], p[2], 0);
    p[3] = func_0204767C(p[5], &p[4], 1);
    func_020477A4(p[3], 0);
}
