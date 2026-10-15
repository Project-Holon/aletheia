/*
 * function: ZKNSEARCH_SYS_IsReady
 * address:  0x021BC270
 * packet:   pkt_021BC270
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKNSEARCH_MAIN_RunState  0x021BCF50  thumb  ov210
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 ZKNSEARCH_MAIN_RunState(u8 *p);

u32 ZKNSEARCH_SYS_IsReady(u32 a, u32 b, u32 c, u32 d)
{
    return ZKNSEARCH_MAIN_RunState((u8 *)d) == 0;
}

