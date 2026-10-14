/*
 * function: BR_MAIN_SanitizeBgmIds
 * address: 0x0220B240
 * packet: pkt_ov187_0220B240
 * region: ov187
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void BR_MAIN_SanitizeBgmIds(u16 *a, u16 *b)
{
    u16 x = *a;
    u16 y = *b;
    switch (x) {
    case 0x46B: case 0x470: case 0x48D: case 0x490: break;
    case 0x48B: case 0x48C: case 0x48E: case 0x48F: default: *a = 0x490; break;
    }
    if (y != 0x47D && y != 0x480) *b = 0x47D;
}
