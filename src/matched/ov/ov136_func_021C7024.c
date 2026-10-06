/*
 * unit: yes
 * function: func_021C7024, func_021C703C
 * address: 0x021C7024
 * packet: pkt_ov136_021C7024
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C630C 0x021C630C thumb ov136
 *   func_021C71A8 0x021C71A8 thumb ov136
 *   func_021C71BC 0x021C71BC thumb ov136
 * extent: stops before separately filed leaf func_021C7048.
 */
extern void func_021C630C(unsigned char *p, unsigned int i);
extern int func_021C71A8(char *, int, int);
typedef unsigned char  u8;
extern int func_021C71BC(u8 *p, int v);
void func_021C7024(char *p)
{
    func_021C630C((unsigned char *)p, 2);
    func_021C71A8(p, 0, 0x13);
}
int func_021C703C(char *p)
{
    return func_021C71BC((u8 *)p, 1);
}
