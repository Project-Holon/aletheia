/*
 * function: BEACON_DETAIL_Init3DParams
 * address:  0x021856CC
 * packet:   pkt_ov219_021856CC
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     2026-10-05 wave D6 lane 03: 92 bytes. Resets twelve words at p+0xC2DC (a camera
 *           record: zero vector, three 0x1000 scales, 0x1A40/0x7C00/0 angles, three 0x1000).
 *           The offset is held in a local so every store reuses one `adds rX,r1,#K` base.
 *           Filed as the unlabelled same-overlay callee of BEACON_DETAIL_Update.
 */

typedef unsigned char u8;

void BEACON_DETAIL_Init3DParams(u8 *p)
{
    int k = 0xC2DC;

    *(int *)(p + k) = 0;
    *(int *)(p + k + 4) = 0;
    *(int *)(p + k + 8) = 0;
    *(int *)(p + k + 0xC) = 0x1000;
    *(int *)(p + k + 0x10) = 0x1000;
    *(int *)(p + k + 0x14) = 0x1000;
    *(int *)(p + k + 0x18) = 0x1A40;
    *(int *)(p + k + 0x1C) = 0x7C00;
    *(int *)(p + k + 0x20) = 0;
    *(int *)(p + k + 0x24) = 0x1000;
    *(int *)(p + k + 0x28) = 0x1000;
    *(int *)(p + k + 0x2C) = 0x1000;
}
