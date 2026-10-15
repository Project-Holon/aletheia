/*
 * function: VIEWER_MAIN_UploadBgBuf
 * address:  0x021C5ACC
 * packet:   pkt_ov111_021C5ACC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   VIEWER_MAIN_ClearBgBuf  0x021C59DC  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
extern void VIEWER_MAIN_ClearBgBuf(u32 bg, int mode);

void VIEWER_MAIN_UploadBgBuf(u32 bg, const void *src, int mode)
{
    BG_SYS_LoadTileData((u8)bg, src, 0x3000, 1);
    VIEWER_MAIN_ClearBgBuf(bg, mode);
}
