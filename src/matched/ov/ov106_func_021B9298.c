/*
 * function: IRC_RANKING_CopyBmpTiles
 * address: 0x021B9298
 * packet: pkt_ov106_021B9298
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_GetPixels 0x020437D4 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
void IRC_RANKING_CopyBmpTiles(const struct Bmp *a, const struct Bmp *b, int x, int y, u16 sx, u16 sy, u16 w, u16 h) {
    u8 *dst = BMP_GetPixels(a);
    u8 *src = BMP_GetPixels(b);
    MIi_CpuCopy32(dst + (x + w * y) * 32, src + (sx + w * sy) * 32, w * h * 32);
}
