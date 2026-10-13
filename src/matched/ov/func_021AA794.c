/*
 * function: EFFECT_ENCOUNT_Delete
 * address:  0x021AA794
 * packet:   pkt_021AA794
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern u32 MI_CpuFill8(u32, u32, u32, u32);

int EFFECT_ENCOUNT_Delete(void *a, u32 b, u32 c, u32 d)
{
MI_CpuFill8((u32)a, 0, (23 << 6), d);
return func_020307B0(a);
}

