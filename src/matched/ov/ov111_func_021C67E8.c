/*
 * function: VIEWER_TEXT_SetScroll
 * address:  0x021C67E8
 * packet:   pkt_ov111_021C67E8
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[0x32FA];
    u8 list[0x13];
    u8 count;
} Work;

void VIEWER_TEXT_SetScroll(Work *p, int v)
{
    p->list[p->count] = v;
    p->count++;
}
