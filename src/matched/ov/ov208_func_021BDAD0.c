/*
 * function: ZUKAN_DETAIL_TOUCHBAR_GetMode
 * address:  0x021BDAD0
 * packet:   pkt_ov208_021BDAD0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 */

typedef unsigned int u32;

struct Ov208Fade {
    u32 f0;
    u32 f4;
    int state;
};

int ZUKAN_DETAIL_TOUCHBAR_GetMode(struct Ov208Fade *p)
{
    return p->state;
}
