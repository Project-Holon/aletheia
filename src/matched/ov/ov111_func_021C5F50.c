/*
 * function: VIEWER_MAIN_CopyTouchPos
 * address:  0x021C5F50
 * packet:   pkt_ov111_021C5F50
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 x;
    u8 y;
    u8 size;
    u8 active;
} TouchPos;

void VIEWER_MAIN_CopyTouchPos(TouchPos *src, TouchPos *dst)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->size = src->size;
    dst->active = src->active;
}
