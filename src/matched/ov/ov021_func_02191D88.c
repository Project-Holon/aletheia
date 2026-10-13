/*
 * function: FIELD_MSGBG_LoadBgWinGraphics
 * address:  0x02191D88
 * packet:   pkt_ov021_02191D88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm
 */

typedef unsigned int u32;

extern void ARC_UTIL_UploadBgCharFromArchive(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void ARC_UTIL_UploadPaletteFromArchive(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

void FIELD_MSGBG_LoadBgWinGraphics(u32 a, u32 b, u32 c, u32 d)
{
    if (c >= 4)
        c = 0;
    ARC_UTIL_UploadBgCharFromArchive(5, 6, a, 0x33, 0, 0, d);
    ARC_UTIL_UploadPaletteFromArchive(5, 1, 0, c << 5, b << 5, 0x20, d);
}
