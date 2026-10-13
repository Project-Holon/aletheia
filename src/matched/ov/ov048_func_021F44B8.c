/*
 * function: GIMMICK_OBJ_ELBOARD_ClearHighlights
 * address:  0x021F44B8
 * packet:   pkt_ov048_021F44B8
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: fills four halfwords with 0x1AB and four bytes at +8 with 0xFF.
 */

typedef unsigned char  u8;
typedef unsigned short u16;

void GIMMICK_OBJ_ELBOARD_ClearHighlights(u8 *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        ((u16 *)p)[i] = 0x1AB;
        p[8 + i] = 0xFF;
    }
}
