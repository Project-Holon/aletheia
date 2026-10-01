/*
 * function: func_021C730C
 * address: 0x021C730C
 * packet: pkt_ov136_021C730C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C670C 0x021C670C thumb ov136
 *   func_0207D63C 0x0207D63C arm
 */
extern void func_021C670C(void *, int, int);
extern void func_0207D63C(void *, int, int, int, int);
void func_021C730C(void *p)
{
    func_021C670C(p, 0, 1);
    func_021C670C(p, 1, 1);
    func_021C670C(p, 3, 0);
    func_021C670C(p, 7, 0);
    func_0207D63C((void *)0x04000050, 4, 8, 4, 12);
}
