/*
 * function: RESEARCH_TOP_ClearPaletteAnime
 * address:  0x021BAAC4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clear five u32 slots at +0x38.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_TOP_ClearPaletteAnime(void *p)
{
    int i;
    for (i = 0; i < 5; i++)
        *(u32 *)((char *)p + i * 4 + 0x38) = 0;
}
