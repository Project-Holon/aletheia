/*
 * function: PERCENTAGE_SetPosition
 * address:  0x021C271C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   PERCENTAGE_Layout  0x021C278C  thumb  ov217
 *   PERCENTAGE_StorePosition  0x021C288C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PERCENTAGE_Layout();
extern void PERCENTAGE_StorePosition(void *p, u32 a, u32 b);
u32 PERCENTAGE_SetPosition(u32 a0, u32 a1, u32 a2)
{
    PERCENTAGE_StorePosition((void *)a0, a1, a2);
    return PERCENTAGE_Layout(a0);
}

