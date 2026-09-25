/*
 * function: func_021BE990
 * address:  0x021BE990
 * packet:   pkt_021BE990
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021BE79C  0x021BE79C  thumb  ov203
 *   d_021C1860  0x021C1860  data  ov203
 * blocker: +0010 ABS32 d_021C1860             -> unresolved: 021C1860: the ov203 hint is contested (another overlay in the window starts an object there) and this function loads no overlay ov203 through an overlay_id site
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021BE79C(void);
extern u8 d_021C1860[];

u32 func_021BE990(void)
{
    return *(u32 *)(d_021C1860 + func_021BE79C() * 0x14);
}

