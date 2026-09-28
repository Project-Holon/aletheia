/*
 * function: ov208_func_021BC4E4
 * address:  0x021BC4E4
 * packet:   pkt_ov208_021BC4E4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 */

struct Ov208Blend {
    int plane1;
    int plane2;
    int ev;
    int step;
    int wait;
};

void ov208_func_021BC4E4(struct Ov208Blend *p)
{
    p->ev = 16;
    p->step = -2;
    p->wait = 0;
}
