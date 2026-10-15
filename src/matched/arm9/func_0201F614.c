/*
 * function: BMP_MENUWORK_DeleteHalf
 * address:  0x0201F614
 * packet:   pkt_0201F614
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BG_SYS_DeleteHalf  0x0203FB44  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

void BMP_MENUWORK_DeleteHalf(int a, u32 x)
{
    BG_SYS_DeleteHalf((int)a, (u16)x, (u16)(x >> 16));
}
