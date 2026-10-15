/*
 * function: PSEL_GRAPHIC_Draw
 * address:  0x021BC4F4
 * packet:   pkt_ov223_021BC4F4
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * This address is also matched as PSEL_GRAPHIC_Draw in ov208; the ov223 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   PSEL_GRAPHIC_ClactDraw  0x021BC64C  thumb  ov223
 *   PSEL_GRAPHIC_NopDraw  0x021BC5E4  thumb  ov223
 *
 * Addresses are Black-image addresses.
 */

extern void PSEL_GRAPHIC_ClactDraw(void *);
extern void PSEL_GRAPHIC_NopDraw(void *);

void PSEL_GRAPHIC_Draw(char *p)
{
    PSEL_GRAPHIC_ClactDraw(p + 4);
    PSEL_GRAPHIC_NopDraw(p);
}
