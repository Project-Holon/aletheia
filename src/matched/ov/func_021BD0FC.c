/*
 * function: func_021BD0FC
 * address:  0x021BD0FC
 * packet:   pkt_021BD0FC
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
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008854  0x02008854  thumb
 *   func_020089A0  0x020089A0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02008854(u32);
extern u32 func_020089A0(u32, u32);
extern u32 func_020120F4(u32);
extern u32 func_02012EBC(u32);

int func_021BD0FC(u32 a)
{
return func_020089A0(func_02008854(func_02012EBC(func_020120F4(*(u32 *)((u8 *)(a))))), *(u16 *)((u8 *)((a + 70))));
}

