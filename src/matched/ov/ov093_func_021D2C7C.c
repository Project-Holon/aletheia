/*
 * function: func_021D2C7C
 * address: 0x021D2C7C
 * packet: pkt_ov093_021D2C7C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_02006254 0x02006254 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_020061E4(unsigned int);
extern int func_02006254(unsigned int);
int func_021D2C7C(int n)
{
    switch (n) {
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        if (func_02006254(0x56b) != 0) return 1;
        break;
    }
    return 0;
}
