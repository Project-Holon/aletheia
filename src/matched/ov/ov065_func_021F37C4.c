/*
 * function: func_021F37C4
 * address: 0x021F37C4
 * packet: pkt_ov065_021F37C4
 * region: ov065
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 */
extern unsigned char *func_02188D2C(void *p);
extern void func_021BE418(unsigned char *p, unsigned short i);
extern void func_021897A0(unsigned char *p, int id);

void func_021F37C4(unsigned char *p)
{
    func_021BE418(func_02188D2C(p), 0);
    func_021897A0(p, 1);
}
