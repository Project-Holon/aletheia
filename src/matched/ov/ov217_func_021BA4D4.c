/*
 * function: func_021BA4D4
 * address:  0x021BA4D4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021BA4C8  0x021BA4C8  thumb  ov217
 *   RESEARCH_COMMON_GetInputFlag  0x021C09F8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021BA4C8(void *p);
extern u32 RESEARCH_COMMON_GetInputFlag(void *p);
u32 func_021BA4D4(void *p)
{
    return RESEARCH_COMMON_GetInputFlag((void *)func_021BA4C8(p));
}

