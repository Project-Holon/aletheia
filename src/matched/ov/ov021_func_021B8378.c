/*
 * function: FIELD_RAIL_RoundToGrid
 * address:  0x021B8378
 * packet:   pkt_ov021_021B8378
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int FIELD_RAIL_RoundToGrid(int x)
{
    u32 ax = x < 0 ? -x : x;

    if ((ax & 15) >= 8) {
        if (x >= 0) {
            return x / 16 + 1;
        } else {
            return x / 16 - 1;
        }
    }
    return x / 16;
}
