/*
 * unit: yes
 * function: func_021EE84C, func_021EE864
 * address: 0x021EE84C
 * packet: pkt_ov028_021EE84C
 * region: ov028
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A231C 0x021A231C thumb ov021
 *   func_021A2120 0x021A2120 thumb ov021
 */

typedef unsigned int u32;
extern void func_021A231C(u32 *, int);
extern void func_021A2120(u32 *, int);
int func_021EE84C(u32 *a, int b)
{
    func_021A231C(a, b);
    func_021A2120(a, b);
    return 1;
}

void func_021EE864(void)
{
}
