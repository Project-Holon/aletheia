/*
 * function: ZUKAN_DETAIL_AREA_RequestBlendRestore
 * address:  0x021C2228
 * packet:   pkt_ov208_021C2228
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

void ZUKAN_DETAIL_AREA_RequestBlendRestore(u16 *heap, u8 *p, int key)
{
    p[0x414] = 3;
}
