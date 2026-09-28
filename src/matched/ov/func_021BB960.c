/*
 * function: func_021BB960
 * address:  0x021BB960
 * packet:   pkt_021BB960
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void func_021BB960(u32 a, u32 b, u32 c, u32 d)
{
if (*(u32 *)((u8 *)(*(u32 *)((u8 *)(b) + 12)) + 16) != 0) {
    ((void (*)(u32, u32, u32, u32))*(u32 *)((u8 *)(*(u32 *)((u8 *)(b) + 12)) + 16))(b, *(u32 *)((u8 *)(*(u32 *)((u8 *)(b)))), *(u32 *)((u8 *)(b) + 16), *(u32 *)((u8 *)(*(u32 *)((u8 *)(b) + 12)) + 16));
}
}

