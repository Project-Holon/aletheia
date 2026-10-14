/*
 * function: ARROW_Reset
 * address:  0x021C20D8
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
 *   ARROW_SetState  0x021C218C  thumb  ov217
 *   ARROW_HideAll  0x021C2260  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void ARROW_SetState(void *p, u32 v);
extern u32 ARROW_HideAll();
u32 ARROW_Reset(u32 a0)
{
    ARROW_SetState((void *)a0, 0);
    return ARROW_HideAll(a0);
}

