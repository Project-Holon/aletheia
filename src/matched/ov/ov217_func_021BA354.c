/*
 * function: func_021BA354
 * address:  0x021BA354
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Wraps ARM FADE_Start(3, 0x10, 0, 0).
 *
 * symbols:
 *   func_021BA354  0x021BA354  thumb  ov217
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
void func_021BA354(void)
{
    FADE_Start(3, 0x10, 0, 0);
}

