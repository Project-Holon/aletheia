/*
 * function: func_021E7234
 * address: 0x021E7234
 * packet: pkt_ov119_021E7234
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020435F4 0x020435F4 arm
 *   func_02030EAC 0x02030EAC arm
 */
extern void func_020435F4(int);
extern void func_02030EAC(void *);

void func_021E7234(void *p, int a)
{
    func_020435F4(a);
    func_02030EAC(p);
}
