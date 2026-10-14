/*
 * function: ZUKAN_DETAIL_COMMON_UpdateBlendFades
 * address:  0x021BC46C
 * packet:   pkt_ov208_021BC46C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_ApplyBrightness  0x021BC520  thumb
 */

typedef unsigned char u8;

struct Ov208Blend {
    int plane1;
    int plane2;
    int ev;
    int step;
    int wait;
};

extern void ZUKAN_DETAIL_COMMON_ApplyBrightness(int flag, int *p);

void ZUKAN_DETAIL_COMMON_UpdateBlendFades(struct Ov208Blend *main, struct Ov208Blend *sub)
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
                ZUKAN_DETAIL_COMMON_ApplyBrightness(i, (int *)p);
            } else {
                p->wait--;
            }
        }
    }
}
