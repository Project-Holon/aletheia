/*
 * function: func_022081A4
 * address:  0x022081A4
 * packet:   pkt_022081A4
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_022082DC 0x022082DC thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct Fade {
    u8 f00[0x28];
    int state;
    u16 pal[16];
    u16 color;
    s16 cur;
    s16 end;
    s16 wait;
    s16 step;
    s16 level;
    s16 count;
} Fade;

extern void func_022082DC(Fade *p, int x);

void func_022081A4(Fade *p, int unused, u16 color, s16 cur, s16 end, s16 wait, s16 step)
{
    s16 v;

    p->color = color;
    p->cur = cur;
    p->end = end;
    p->wait = wait;
    p->step = step;

    v = p->cur;
    if (v > 31)
        v = 31;
    else if (v < 0)
        v = 0;
    p->cur = v;

    v = p->end;
    if (v > 31)
        v = 31;
    else if (v < 0)
        v = 0;
    p->end = v;

    v = p->step;
    if (v > 31)
        v = 31;
    else if (v < -31)
        v = -31;
    p->step = v;

    if (p->cur < p->end) {
        if (p->step < 0)
            p->step = p->step * 0xFFFFFFFF;
    } else if (p->cur > p->end) {
        if (p->step > 0)
            p->step = p->step * 0xFFFFFFFF;
    } else {
        p->step = 0;
    }

    p->level = p->cur;
    p->count = p->wait;
    func_022082DC(p, unused);
}
