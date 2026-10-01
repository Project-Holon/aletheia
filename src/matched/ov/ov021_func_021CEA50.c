/*
 * function: func_021CEA50
 * address:  0x021CEA50
 * packet:   pkt_ov021_021CEA50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_021CEA50(u8 *p)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (p[0x550 + i] != p[0x70 + i * 0x2c]) {
            return 0;
        }
    }
    return 1;
}
