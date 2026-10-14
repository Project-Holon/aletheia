/*
 * function: FIELD_G3D_MAP_BLOCK_QueryClear
 * address: 0x0219361C
 * packet: pkt_ov021_0219361C
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov021/unit_02192CF0.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int   u32;

void FIELD_G3D_MAP_BLOCK_QueryClear(u8 *p)
{
    *(u32 *)(p + 0x100) = 0;
}
