/*
 * function: FIELD_MSGBG_LoadSpWinPalette
 * address:  0x02192244
 * packet:   pkt_ov021_02192244
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void ARC_UTIL_UploadPaletteFromArchive(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

void FIELD_MSGBG_LoadSpWinPalette(u32 unused, u32 a, u32 b)
{
    ARC_UTIL_UploadPaletteFromArchive(5, 2, 0, 0, a * 32, 0x20, b);
}
