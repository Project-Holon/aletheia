/*
 * function: func_021977C0
 * address:  0x021977C0
 * packet:   pkt_ov021_021977C0
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
 *   func_02196228  0x02196228  thumb  ov021
 *   func_020414EC  0x020414EC  arm
 *   func_021962F4  0x021962F4  thumb  ov021
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196A4C  0x02196A4C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021975D0(u8 *p);
extern u32 func_02035C60(void);
extern void func_02196228(u8 *p, int flag);
extern void func_020414EC(u32);
extern void func_021962F4(u8 *);
extern void func_02196034(u8 *, void (*)(), u32);
extern void func_02196A4C(u8 *a);

void func_021977C0(u8 *a)
{
    if (func_021975D0(a) != 0 && func_02035C60() != 0) {
        func_02196228(a, 0);
        func_020414EC(3);
        func_021962F4(a);
        *(u32 *)(a + 8) = 12;
        func_02196034(a, func_02196A4C, 0x7a2);
    }
}
