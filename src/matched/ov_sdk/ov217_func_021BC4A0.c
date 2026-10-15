/*
 * function: RESEARCH_LIST_IsFadeDone
 * address:  0x021BC4A0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Returns 1 when ARM FADE_IsActive() is 0.
 *
 * symbols:
 *   RESEARCH_LIST_IsFadeDone  0x021BC4A0  thumb  ov217
 *   FADE_IsActive  0x0204E804  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int FADE_IsActive(void);
int RESEARCH_LIST_IsFadeDone(void)
{
    return FADE_IsActive() == 0;
}

