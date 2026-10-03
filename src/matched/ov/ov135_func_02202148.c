/*
 * function: func_02202148
 * address: 0x02202148
 * packet: pkt_ov135_02202148
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: nested if with equal sentinel arm first preserves the branch hop.
 * symbols:
 *   func_021F4FC4 0x021F4FC4 thumb ov135
 *   func_0207D55C 0x0207D55C arm
 *   func_0202208C 0x0202208C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021F4FC4(u8 *p);
extern int func_0207D55C(volatile u16 *reg);
extern void func_0202208C(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
int func_02202148(u8 *p)
{
    func_021F4FC4(p);
    if (*(unsigned *)(p + 0xEB4) == 1) {
        if (func_0207D55C((u16 *)0x0400106C) == -16)
            func_0202208C(3, 0, 0, 0, 6, 1, 0x48);
        else
            func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    } else {
        func_0202208C(3, 0, 0, 0, 6, 1, 0x48);
    }
    *(unsigned *)(p + 0x28) = 0;
    return 3;
}
