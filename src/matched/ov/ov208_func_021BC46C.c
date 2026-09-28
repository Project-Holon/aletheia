/*
 * function: ov208_func_021BC46C
 * address:  0x021BC46C
 * packet:   pkt_ov208_021BC46C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BC520  0x021BC520  thumb
 */

typedef unsigned char u8;

struct Ov208Blend {
    int plane1;
    int plane2;
    int ev;
    int step;
    int wait;
};

extern void func_021BC520(int sub, struct Ov208Blend *p);

void ov208_func_021BC46C(struct Ov208Blend *main, struct Ov208Blend *sub)
{
    struct Ov208Blend *b[2];
    struct Ov208Blend *p;
    u8 i;

    b[0] = main;
    b[1] = sub;
    for (i = 0; i < 2; i++) {
        p = b[i];
        if (p->step != 0) {
            if (p->wait == 0) {
                p->wait = 0;
                p->ev += p->step;
                if (p->step > 0) {
                    if (p->ev >= 16) {
                        p->ev = 16;
                        p->step = 0;
                    }
                } else if (p->ev <= 0) {
                    p->ev = 0;
                    p->step = 0;
                }
                func_021BC520(i, p);
            } else {
                p->wait--;
            }
        }
    }
}
