/*
 * function: func_021BC4F0
 * address:  0x021BC4F0
 * packet:   pkt_ov021_021BC4F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD0A4  0x021BD0A4  thumb  ov021
 *   func_021BCEAC  0x021BCEAC  thumb  ov021
 *   func_021BCEB0  0x021BCEB0  thumb  ov021
 *   func_021BCEB4  0x021BCEB4  thumb  ov021
 *   func_021BCF18  0x021BCF18  thumb  ov021
 *   func_021BCF1C  0x021BCF1C  thumb  ov021
 *   func_021BCF20  0x021BCF20  thumb  ov021
 *   func_021BCF24  0x021BCF24  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021BD0A4(u8 *p);
extern void func_021BCEAC(int a);
extern void func_021BCEB0(int a);
extern void func_021BCEB4(char *p);
extern void func_021BCF18(int a);
extern void func_021BCF1C(int a);
extern void func_021BCF20(int a);
extern void func_021BCF24(char *p);

void func_021BC4F0(int a)
{
    switch (func_021BD0A4((u8 *)a)) {
    case 0:
        func_021BCEAC(a);
        break;
    case 1:
        func_021BCEB0(a);
        break;
    case 2:
        func_021BCEB4((char *)a);
        break;
    case 3:
        func_021BCF18(a);
        break;
    case 4:
        func_021BCF1C(a);
        break;
    case 5:
        func_021BCF20(a);
        break;
    case 6:
        func_021BCF24((char *)a);
        break;
    }
}
