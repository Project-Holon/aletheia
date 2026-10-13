/*
 * function: FIELD_PLAYER_NOGRID_EndInputHoldFrame
 * address:  0x021A6C30
 * packet:   pkt_ov021_021A6C30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 */

typedef unsigned char u8;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 rest : 5;
    int f4;
} T;

void FIELD_PLAYER_NOGRID_EndInputHoldFrame(T *t)
{
    if (t->b2) {
        t->b2 = 0;
    }
    if (!t->b1) {
        t->f4 = 9;
    }
}
