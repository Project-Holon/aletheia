/*
 * function: B_PLIST_ANM_BlitTileRect
 * address: 0x0220B460
 * packet: pkt_ov198_0220B460
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 0220B4AE..0220B4AF is two-byte alignment padding.
 */
typedef unsigned char u8;
typedef unsigned short u16;
void B_PLIST_ANM_BlitTileRect(u16 *dst, u16 *src, int x, int y, u8 width, u8 height)
{
    u16 row;
    u16 col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++)
            dst[row * width + col] = src[(y + row) * 32 + x + col];
    }
}
