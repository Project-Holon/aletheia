/*
 * function: func_021BC274
 * address:  0x021BC274
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set +0x4c to the difference of the two u32 fields at +0x34 and +0x38.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BC274(void *p)
{
    int a = *(u32 *)((char *)p + 0x34);
    int b = *(u32 *)((char *)p + 0x38);
    *(u32 *)((char *)p + 0x4c) = a - b;
}
