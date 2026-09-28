/*
 * function: func_021FC560
 * address:  0x021FC560
 * packet:   pkt_021FC560
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F94B0  0x021F94B0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021F94B0(void *);

int func_021FC560(void *a, void **pp)
{
    func_021F94B0(*(void **)((u8 *)*pp + 0x34));
    return 0;
}
