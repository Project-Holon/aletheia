/*
 * function: ZUKAN_DETAIL_HEADBAR_GetIconKind
 * address:  0x021BE840
 * packet:   pkt_ov208_021BE840
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ov208Icon {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

int ZUKAN_DETAIL_HEADBAR_GetIconKind(struct Ov208Icon *p)
{
    return p->state;
}
