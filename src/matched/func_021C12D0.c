/*
 * function: func_021C12D0
 * address:  0x021C12D0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020399A8  0x020399A8  arm
 *
 * When the arm9 call answers what the fifth argument expects, sets one byte of
 * the fourth argument's block, 0x1355 bytes in.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef int BOOL;

extern int sub_020399A8(int a, int b, int c);

void func_021C12D0(int a, int b, int c, u8 *d, int e)
{
    if (sub_020399A8(a, b, c) == e) {
        d[0x1355] = 1;
    }
}
