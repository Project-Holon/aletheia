/*
 * function: ZKNSEARCH_MAIN_SetFadeStateA
 * address:  0x021BCD30
 * packet:   pkt_ov210_021BCD30
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
void ZKNSEARCH_MAIN_SetFadeStateA(u8 *p)
{
    p[0x2b8] = 1;
}
