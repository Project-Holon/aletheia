/*
 * function: func_021F39B4
 * address: 0x021F39B4
 * packet: pkt_ov038_021F39B4
 * region: ov038
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02188D2C 0x02188D2C thumb ov021
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE418 0x021BE418 thumb ov021
 */
typedef unsigned short u16;
extern int func_02188D2C(int *);
extern int *func_021897BC(char *, int);
extern void func_021897A0(unsigned char *, int);
extern void func_021BE418(unsigned char *, u16);
void func_021F39B4(void *p)
{
    int h = func_02188D2C(p);
    func_021897BC(p, 1);
    func_021897A0(p, 1);
    func_021BE418((unsigned char *)h, 0);
}
