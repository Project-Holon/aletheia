/*
 * function: PALETTE_ANIME_Destroy
 * address:  0x021C29D8
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
 *   PALETTE_ANIME_Free  0x021C2DC4  thumb  ov217
 *   PALETTE_ANIME_ReleaseOriginal  0x021C2E20  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PALETTE_ANIME_Free(void *a0);
extern void PALETTE_ANIME_ReleaseOriginal(char *p);
u32 PALETTE_ANIME_Destroy(void *a0)
{
    PALETTE_ANIME_ReleaseOriginal((char *)a0);
    return PALETTE_ANIME_Free(a0);
}

