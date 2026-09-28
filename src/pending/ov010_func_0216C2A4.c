/*
 * function: func_0216C2A4
 * address:  0x0216C2A4
 * packet:   pkt_ov010_0216C2A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Snap the actor's position to the 16-unit grid (z biased by 32) and
 * write it to the ov021 map object. Size-exact, 27 bytes out: the image
 * loads x, z, y in that order and stores x, z, y; hoisting the call into
 * q, locals for the three coordinates and storing y last got here from
 * 65. An inline Snap(), a struct copy, and permuter seed 9603 (best 15,
 * only by an unnatural temp) do not close it.
 *
 * symbols:
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021BE480  0x021BE480  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3044  0x021A3044  thumb  ov021
 */

typedef unsigned char u8;
typedef int s32;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Work {
    u8 pad00[8];
    void *field;        /* 0x08 */
} Work;

extern void *func_02188D2C(void *field);
extern VecFx32 *func_021BE480(void *p, int a, int b);
extern void *func_02188CB4(void *field);
extern void func_021A3044(void *q, const VecFx32 *pos);

void func_0216C2A4(Work *w)
{
    VecFx32 v;
    VecFx32 *pos;
    void *q;
    fx32 x;
    fx32 y;
    fx32 z;

    pos = func_021BE480(func_02188D2C(w->field), 0, 0);
    q = func_02188CB4(w->field);
    x = pos->x;
    y = pos->y;
    z = pos->z + 0x20000;
    v.x = ((x >> 12) / 16 << 16) + 0x8000;
    v.z = ((z >> 12) / 16 << 16) + 0x8000;
    v.y = y;
    func_021A3044(q, &v);
}
