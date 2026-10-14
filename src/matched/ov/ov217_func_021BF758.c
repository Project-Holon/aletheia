/*
 * function: func_021BF758
 * address:  0x021BF758
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
 *   func_021BF750  0x021BF750  thumb  ov217
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

extern u32 func_021BF750(void *);
extern u32 RESEARCH_COMMON_GetInputFlag(void *);
u32 func_021BF758(void *p)
{
    return RESEARCH_COMMON_GetInputFlag((void *)func_021BF750(p));
}

