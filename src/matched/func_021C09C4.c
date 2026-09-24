/*
 * function: func_021C09C4
 * address:  0x021C09C4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter: store the word at +0x38.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021C09C4(u8 *p, u32 v);
void func_021C09C4(u8 *p, u32 v)
{
    *(u32 *)(p + 0x38) = v;
}

