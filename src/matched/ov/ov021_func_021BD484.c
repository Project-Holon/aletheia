/*
 * function: func_021BD484
 * address:  0x021BD484
 * packet:   pkt_ov021_021BD484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _fmul  0x0209C77C  arm
 *   _fdiv  0x0209CE10  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 *   _fneq  0x0209BCD0  arm
 *
 * EXACT*: the extent runs past 0x021BD552 into an unlabelled follower.
 */

typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    int f28;
    int f2C;
} Sub;

typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    Sub s;
} Obj;

void func_021BD484(Obj *obj)
{
    float dx;
    float dy;
    Sub *s;

    s = &obj->s;
    dx = s->f18 - obj->s.f0;
    dy = s->f1C - s->f4;

    if (dx != 0.0f) {
        s->f10 = (s->f20 * s->f20 - s->f8 * s->f8) / (2.0f * dx);
    }
    if (dy != 0.0f) {
        s->f14 = (s->f24 * s->f24 - s->fC * s->fC) / (2.0f * dy);
    }
    if (s->f10 != 0.0f) {
        s->f28 = (s->f20 - s->f8) / s->f10;
    }
    if (s->f14 != 0.0f) {
        s->f2C = (s->f24 - s->fC) / s->f14;
    }
}
