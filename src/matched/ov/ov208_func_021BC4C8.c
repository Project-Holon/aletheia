/*
 * function: ov208_func_021BC4C8
 * address:  0x021BC4C8
 * packet:   pkt_ov208_021BC4C8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 */

struct Ov208Blend {
    int plane1;
    int plane2;
    int ev;
    int step;
    int wait;
};

int ov208_func_021BC4C8(struct Ov208Blend *p)
{
    if (p->step != 0)
        return 1;
    return 0;
}
