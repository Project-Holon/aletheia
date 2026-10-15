/*
 * function: RESEARCH_LIST_FadeIn
 * address:  0x021BC480
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
 *   RESEARCH_LIST_FadeIn  0x021BC480  thumb  ov217
 *   FADE_Start  0x0204E720  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
void RESEARCH_LIST_FadeIn(void)
{
    FADE_Start(3, 16, 0, 0);
}

