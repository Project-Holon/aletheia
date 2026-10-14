/*
 * function: PALETTE_ANIME_Stop
 * address:  0x021C2A00
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer to PALETTE_ANIME_StopImpl.
 *
 * symbols:
 *   PALETTE_ANIME_StopImpl  0x021C2A28  thumb  ov217

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void PALETTE_ANIME_StopImpl(void *p);
void PALETTE_ANIME_Stop(u32 a0)
{
    PALETTE_ANIME_StopImpl((void *)a0);
}

