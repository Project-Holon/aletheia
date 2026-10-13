/*
 * function: FIELD_MSGBG_LoadSysWindowFrameGraphics
 * address:  0x021929E8
 * packet:   pkt_ov021_021929E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void ARC_UTIL_UploadBgCharFromArchive(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

void FIELD_MSGBG_LoadSysWindowFrameGraphics(u32 heap)
{
    ARC_UTIL_UploadBgCharFromArchive(5, 10, 1, 0x1F, 0, 0, heap);
}
