/*
 * function: BEACON_DETAIL_GRA_DeleteInfoWindow
 * address:  0x021BC6FC
 * packet:   pkt_021BC6FC
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call getter: loads p[0x52] and tail-calls BMP_WIN_Delete.
 *
 * symbols:
 *   BMP_WIN_Delete  0x020452E8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

u32 BEACON_DETAIL_GRA_DeleteInfoWindow(u32 *p)
{
    return BMP_WIN_Delete((struct Descriptor *)p[0x52]);
}
