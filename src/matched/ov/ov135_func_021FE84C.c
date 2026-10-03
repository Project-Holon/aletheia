/*
 * function: func_021FE84C
 * address: 0x021FE84C
 * packet: pkt_ov135_021FE84C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF318 0x021FF318 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_020061E4 0x020061E4 thumb
 */
extern void func_021FF318(char *, int, int, int, int);
extern void func_021F4E98(char *, unsigned, unsigned);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
int func_021FE84C(char *p)
{
    if (*(int *)(p + 0xd0) == 0) {
        func_021FF318(p, 14, 1, 0, 0xf0f);
        func_021F4E98(p, 23, 1);
        func_020061E4(0x557);
    } else {
        func_021FF318(p, 36, 1, 0, 0xf0f);
        func_021F4E98(p, 23, 21);
        *(int *)(p + 0xdfc) = 0;
    }
    return 2;
}
