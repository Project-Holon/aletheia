/*
 * function: PERCENTAGE_Destroy
 * address:  0x021C270C
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
 *   PERCENTAGE_Free  0x021C2914  thumb  ov217
 *   PERCENTAGE_Exit  0x021C2950  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PERCENTAGE_Free(void *a0);
extern void PERCENTAGE_Exit(u32);
u32 PERCENTAGE_Destroy(void *a0)
{
    PERCENTAGE_Exit((u32)a0);
    return PERCENTAGE_Free(a0);
}

