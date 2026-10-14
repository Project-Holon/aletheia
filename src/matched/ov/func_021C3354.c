/*
 * function: ZUKAN_DETAIL_VOICE_LoadWindowPalette
 * address:  0x021C3354
 * packet:   pkt_021C3354
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm  arm9
 *   (none)

 * Posts message 0x17 with the halfword at +0 as its last argument.
 */


typedef unsigned short u16;
typedef unsigned int   u32;
extern void ARC_UTIL_UploadPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

void ZUKAN_DETAIL_VOICE_LoadWindowPalette(unsigned short *p, void *a1, int a2)
{
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 0, 0, 0x20, 0x20, *p);
}

