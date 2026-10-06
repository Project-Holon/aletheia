/*
 * function: func_02196944
 * address:  0x02196944
 * packet:   pkt_ov021_02196944
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021975D0  0x021975D0  thumb  ov021
 *   func_02035C60  0x02035C60  arm
 *   func_021962F4  0x021962F4  thumb  ov021
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196A4C  0x02196A4C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int func_021975D0(u8 *p);
extern int func_02035C60(void);
extern void func_021962F4(u8 *);
extern void func_02196034(u8 *, void (*)(), u32);
extern void func_02196A4C(u8 *a);

void func_02196944(u8 *a)
{
    if (func_021975D0(a) != 0 && func_02035C60() != 0) {
        func_021962F4(a);
        func_02196034(a, func_02196A4C, 0x3CB);
    }
}
