/*
 * function: ov208_func_021BDAD4
 * address:  0x021BDAD4
 * packet:   pkt_ov208_021BDAD4
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

struct Ov208Fade {
    u32 f0;
    u32 f4;
    int state;
    u32 pad[5];
    int arg;
    u8  step;
};

void ov208_func_021BDAD4(struct Ov208Fade *p, int v)
{
    p->arg = v;
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}
