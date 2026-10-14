/*
 * function: PALETTE_ANIME_Start
 * address:  0x021C29F8
 * packet:   pkt_ov217_021C09D8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
  * status:   EXACT
 *
 * Unlabelled 4-byte tail-call veneer in a .word run; pool 0x021C29FC names
 * PALETTE_ANIME_StartImpl. Middle of the func_021BA31C blocker chain.
 *
 * symbols:
 *   PALETTE_ANIME_StartImpl  0x021C2A18  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void PALETTE_ANIME_StartImpl(u8 *p, u32 b, u16 c);

void PALETTE_ANIME_Start(u8 *p, u32 b, u16 c)
{
    PALETTE_ANIME_StartImpl(p, b, c);
}
