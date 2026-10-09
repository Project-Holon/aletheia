/*
 * function: func_021BA014
 * address:  0x021BA014
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A four-byte ARM long-branch veneer over 0x027047C0.
 *
 * symbols:
 *   veneer_027047C0  0x027047C0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

asm void func_021BA014(void)
{
    ldr pc, [pc, #-4]
    dcd 0x027047C0
}
