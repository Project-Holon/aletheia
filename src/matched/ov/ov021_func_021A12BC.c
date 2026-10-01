/*
 * function: func_021A12BC
 * address:  0x021A12BC
 * packet:   pkt_ov021_021A12BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A8E20  0x021A8E20  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern int func_021A0F90(u32 *);
extern void func_021A8E20(u32, u32);

void func_021A12BC(u32 *p, u32 a)
{
    if (func_021A0F90(p) == 1)
        func_021A8E20(p[8], a);
}
