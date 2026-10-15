/*
 * function: FIELD_MSGBG_LoadMenuGraphicsUpper
 * address:  0x02193170
 * packet:   pkt_ov021_02193170
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb  arm9
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern u8 BMP_MENUWORK_GetPlttFileId(int i);
extern void ARC_UTIL_UploadPaletteFromArchive(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

void FIELD_MSGBG_LoadMenuGraphicsUpper(u32 heap)
{
    ARC_UTIL_UploadPaletteFromArchive(5, BMP_MENUWORK_GetPlttFileId(0), 0, 0, 0x140, 0x20, heap);
}
