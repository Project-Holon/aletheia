/*
 * function: PALETTE_ANIME_Update
 * address:  0x021C29F0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: passes its argument through to PALETTE_ANIME_UpdateImpl.
 *
 * symbols:
 *   PALETTE_ANIME_UpdateImpl  0x021C2A30  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w[8];
} Rec;

extern void PALETTE_ANIME_UpdateImpl(Rec *);

void PALETTE_ANIME_Update(Rec *p)
{
    PALETTE_ANIME_UpdateImpl(p);
}
