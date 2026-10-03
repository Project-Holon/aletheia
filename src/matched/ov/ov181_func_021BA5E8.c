/*
 * function: func_021BA5E8
 * address: 0x021BA5E8
 * packet: pkt_ov181_021BA5E8
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display registers 04000052 and 04001052 are hardware.
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
extern void func_0207D63C(unsigned, int, int, int, int);
int func_021BA5E8(char *p)
{
    int a, b;
    switch (*(u8 *)(p + 0x2ce)) {
    case 0:
        if (*(u8 *)(p + 0x2cf) & 1) func_0207D63C(0x04000050, 2, 0x21, 0, 16);
        if (*(u8 *)(p + 0x2cf) & 2) func_0207D63C(0x04001050, 2, 0x21, 0, 16);
        *(u8 *)(p + 0x2cc) = *(u8 *)(p + 0x2cf);
        ++*(u8 *)(p + 0x2ce);
        break;
    case 1:
        if (*(u8 *)(p + 0x2d2) == 1) *(s8 *)(p + 0x2d0) += 16;
        else *(s8 *)(p + 0x2d0) += 4;
        a = *(s8 *)(p + 0x2d0);
        if (a > 16) { a = 16; b = 0; }
        else b = 16 - a;
        if (*(u8 *)(p + 0x2cf) & 1) *(volatile u16 *)0x04000052 = a | (b << 8);
        if (*(u8 *)(p + 0x2cf) & 2) *(volatile u16 *)0x04001052 = a | (b << 8);
        if (*(s8 *)(p + 0x2d0) >= 16) {
            if (*(u8 *)(p + 0x2cf) & 1) *(volatile u16 *)0x04000050 = 0;
            if (*(u8 *)(p + 0x2cf) & 2) *(volatile u16 *)0x04001050 = 0;
            *(u8 *)(p + 0x2d0) = 0;
            *(u8 *)(p + 0x2ce) = 0;
            return 0;
        }
        break;
    }
    return 1;
}
