/*
 * unit: yes
 * function: func_02177094,func_021770A0
 * address: 0x02177094
 * packet: pkt_ov014_02177094
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: lead and unlabelled tail-call follower at 0x021770A0.
 * symbols:
 *   func_0217796C 0x0217796C thumb ov014
 *   func_021776C4 0x021776C4 thumb ov014
 */
typedef unsigned int u32;
extern void func_0217796C(u32);
extern int func_021776C4(void);
int func_02177094(u32 a)
{
    func_0217796C(a);
    return 1;
}
int func_021770A0(void)
{
    return func_021776C4();
}
