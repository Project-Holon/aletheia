/*
 * function: TOWNMAP_StepScrollZoom
 * address:  0x021BAFA8
 * packet:   pkt_ov072_021BAFA8
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Ten-step interpolation tick. Levers: the step `(to - from) / 10` in a
 * named local (else the product lands in r0 and the 0x2C load hoists over
 * it); the four s16 fields written as `from - (from - to) / 10 * n` /
 * `from + (to - from) / 10 * n` with literal endpoints (keeps the constants
 * rematerialised off the r4 = 10 register); the reset `pos = dst` as one
 * 8-byte struct assignment placed last (per-field copies schedule the
 * loads between the stores).
 *
 * symbols:
 *   TOWNMAP_MapSetZoom  0x021BA5B0  thumb  ov072
 *   TOWNMAP_ApplyScroll  0x021BB0E4  thumb  ov072
 */
typedef short s16;
typedef unsigned short u16;

typedef struct {
    int x, y;
} Vec;

typedef struct {
    u16 f00;
    u16 n;
    s16 f04;
    s16 f06;
    s16 f08;
    s16 f0a;
    int done;
    int active;
    int cur;
    int to;
    int from;
    Vec pos;
    Vec dst;
    Vec src;
} Anim;

extern void TOWNMAP_MapSetZoom(void *a, int b, Vec *c);
extern void TOWNMAP_ApplyScroll(Anim *p, Vec *c);

void TOWNMAP_StepScrollZoom(Anim *p, void *arg)
{
    int dy;
    int dx;
    int step;

    p->done = 0;
    if (p->active == 0)
        return;
    step = (p->to - p->from) / 10;
    p->cur = p->from + step * p->n;
    dy = (p->dst.y - p->src.y) << 12;
    dx = (p->dst.x - p->src.x) << 12;
    p->pos.x = p->src.x + ((dx * p->n) / 10 >> 12);
    p->pos.y = p->src.y + ((dy * p->n) / 10 >> 12);
    if (p->to == 0x1000) {
        p->f04 = -96 - (-96 - 0) / 10 * p->n;
        p->f0a = 72 - (72 - 0) / 10 * p->n;
        p->f06 = -128 - (-128 - 0) / 10 * p->n;
        p->f08 = 128 - (128 - 0) / 10 * p->n;
    } else {
        p->f04 = 0 + (-96 - 0) / 10 * p->n;
        p->f0a = 0 + (72 - 0) / 10 * p->n;
        p->f06 = 0 + (-128 - 0) / 10 * p->n;
        p->f08 = 0 + (128 - 0) / 10 * p->n;
    }
    if (p->n++ >= 10) {
        p->n = 0;
        p->active = 0;
        p->cur = p->to;
        p->pos = p->dst;
        if (p->to == 0x1000) {
            p->f04 = 0;
            p->f06 = 0;
            p->f08 = 0;
            p->f0a = 0;
        } else {
            p->f04 = -0x60;
            p->f06 = -0x80;
            p->f08 = 0x80;
            p->f0a = 0x48;
        }
        p->done = 1;
    }
    TOWNMAP_MapSetZoom(arg, p->cur, &p->pos);
    TOWNMAP_ApplyScroll(p, &p->pos);
}
