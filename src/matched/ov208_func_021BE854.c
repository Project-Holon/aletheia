/*
 * function: ov208_func_021BE854
 * address:  0x021BE854
 * packet:   pkt_ov208_021BE854
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

void ov208_func_021BE854(struct Ov208Icon *p)
{
    if (p->state != 0) {
        p->state = 3;
        p->step = 0;
    }
}
