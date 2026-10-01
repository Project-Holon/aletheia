/*
 * function: func_021FF198
 * address: 0x021FF198
 * packet: pkt_ov135_021FF198
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0202208C 0x0202208C thumb
 *   func_021FFB00 0x021FFB00 thumb ov135
 *   func_0204B878 0x0204B878 arm
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned short u16;
extern unsigned func_020362DC(void);
extern void func_0202208C(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern int func_021FFB00(int);
extern void func_0204B878(unsigned, u16);
extern void func_021F4EC0(void *, unsigned, unsigned);
extern void func_020061E4(int);
int func_021FF198(char *p)
{
    int r;
    if (func_020362DC() & 1) {
        func_0202208C(0, 0, 0, 0, 16, 1, 72);
    } else {
        r = func_021FFB00(*(int *)(p + 0xd0));
        if (*(u16 *)(p + 0xe1a) && r >= 0) {
            func_0204B878(*(unsigned *)(p + 0xd0c + (r + 1) * 4), (u16)(16 + r * 4));
            *(int *)(p + 0x28) = 2;
            func_021F4EC0(p, 3, 0);
            *(int *)(p + 0xd4) = r;
            func_020061E4(0x54c);
        }
    }
    return 2;
}
