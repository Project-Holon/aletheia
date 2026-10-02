/*
 * function: func_0217F4D8
 * address: 0x0217F4D8
 * packet: pkt_ov018_0217F4D8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201210C 0x0201210C thumb
 *   func_02034714 0x02034714 arm
 *   func_02190BE4 0x02190BE4 thumb ov021
 *   d_02183B2C 0x02183B2C data a4
 */
extern unsigned char d_02183B2C[];
extern void func_0201210C(int);
extern void func_02034714(void *, int, void *);
extern void *func_02190BE4(void *, unsigned int);
void func_0217F4D8(void **p, int a)
{
    func_0201210C(a);
    if (p[11] != 0 || p[3] == 0) func_02034714(d_02183B2C, 0, d_02183B2C);
    p[11] = func_02190BE4(p[9], 0);
}
