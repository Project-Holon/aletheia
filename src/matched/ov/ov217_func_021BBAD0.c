/*
 * function: func_021BBAD0
 * address:  0x021BBAD0
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
 *   func_021BC574  0x021BC574  thumb  ov217
 *
 * evidence: func_021BC574 is ov217's own code ("ldr r0, [r0]; ldr r3,
 * =RESEARCH_COMMON_StartPaletteAnime; bx r3" after the pop at 0x021BC570), inside ov217's window,
 * so only ov217 can be resident there when this pool word is used.  Its start
 * is seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov217's own listing.  The old
 * hint ov209 named a different overlay's function mapped over the address.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021BC574(u8 **p, u32 i);
void func_021BBAD0(u32 a0)
{
    func_021BC574((u8 **)a0, 0);
}

