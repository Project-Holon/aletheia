/*
 * function: func_021D4BA8
 * address: 0x021D4BA8
 * packet: pkt_ov123_021D4BA8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_021D4244 0x021D4244 thumb ov123
 *   func_021D4B44 0x021D4B44 thumb ov123
 */
typedef unsigned int u32;
extern void func_020061E4(int);
extern void func_0204B878(void *, int);
extern void func_021D4244(char *, void *, int);
extern void func_021D4B44(char *);
int func_021D4BA8(int n, char *p)
{
    *(u32 *)(p + 0x270) = n;
    switch (n) {
    case 0:
        func_020061E4(0x73b);
        func_0204B878(*(void **)(p + 0x2a0), 14);
        func_021D4244(p, func_021D4B44, 0x389);
        *(u32 *)(p + 8) = 2;
        break;
    case 1:
        func_020061E4(0x73b);
        *(u32 *)(p + 8) = 3;
        func_021D4244(p, func_021D4B44, 0x393);
        break;
    case 2:
        func_020061E4(0x73c);
        *(u32 *)(p + 8) = 0;
        func_021D4244(p, func_021D4B44, 0x399);
        break;
    }
    return 1;
}
