/*
 * function: func_021ADCF0
 * address:  0x021ADCF0
 * packet:   pkt_ov021_021ADCF0
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
 *   func_02047180  0x02047180  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_021ADD64  0x021ADD64  thumb  ov021
 *   d_021DE0FC     0x021DE0FC  data  a4
 */

extern int d_021DE0FC[];

extern int func_021ABE24(int a);
extern int func_02046E24(int a, int b);
extern int func_02047180(unsigned int *p);
extern int func_020056A0(void *fn, void *arg, int z);
typedef unsigned int   u32;
struct Q;
extern void func_021ADD64(u32 a, struct Q *q);

void func_021ADCF0(int *p)
{
    int r7 = func_021ABE24(p[0]);
    int i;

    func_02047180((unsigned int *)(p[1] = func_02046E24(r7, 0x4d)));
    p[6] = func_020056A0((void *)func_021ADD64, p, 0);
    for (i = 0; i < 4; i++)
        p[2 + i] = func_02046E24(r7, d_021DE0FC[i]);
}
