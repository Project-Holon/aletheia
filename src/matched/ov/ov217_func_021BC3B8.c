/*
 * function: RESEARCH_LIST_SetScrollY
 * address:  0x021BC3B8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_LIST_SetScrollY  0x021BC3B8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02040618(u32 layer, u32 a, u32 b);
void RESEARCH_LIST_SetScrollY(u32 a0)
{
    func_02040618(2, 3, a0);
    func_02040618(3, 3, a0);
}

