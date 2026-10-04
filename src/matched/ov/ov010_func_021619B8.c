/*
 * function: func_021619B8
 * address:  0x021619B8
 * packet:   pkt_ov010_021619B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Hop-and-land movement of a field object: state 0 follows the arc table
 * d_0217140C while sliding along (dx, dz) over 15 frames, state 1 drops
 * it 8.0 per frame onto start + delta, then snaps it there, plays the
 * landing sound and answers done.
 *
 * Levers (2026-09-28 tree_ov010_4): the frame test as `t > 15u` (cmp #15;
 * bls on the ldrsh), and the landing height read into a local before the
 * drop is computed.
 *
 * symbols:
 *   d_0217140C     0x0217140C  data
 *   _ll_mul        0x0209C054  arm
 *   FX_Div         0x0207C768  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_021AC528  0x021AC528  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef long long s64;
typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct HopWork {
    void *owner;        /* 0x00 */
    void *obj;          /* 0x04 */
    s16 t;              /* 0x08 */
    u8 pad0A[2];
    VecFx32 start;      /* 0x0C */
    VecFx32 delta;      /* 0x18 */
} HopWork;

extern const fx32 d_0217140C[];
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern void func_0216D89C(void *obj, const VecFx32 *pos);
struct Actor;
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern u16 func_0216D5F8(void *obj);
extern void func_0216E014(void *a, int *p, int b);
extern void func_020061E4(u32 se);
extern void func_021AC528(u32 a, u32 b);

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

int func_021619B8(void *task, u32 *seq, HopWork *w)
{
    VecFx32 pos;
    fx32 y;
    fx32 floor;
    int done;

    done = 0;
    switch (*seq) {
    case 0:
        pos = w->start;
        pos.y += d_0217140C[w->t];
        w->t += 2;
        pos.x += FX_Div(FX_Mul(w->delta.x, w->t << 12), 15 << 12);
        pos.z += FX_Div(FX_Mul(w->delta.z, w->t << 12), 15 << 12);
        func_0216D89C(w->obj, &pos);
        if (w->t > 15u)
            (*seq)++;
        break;
    case 1:
        func_0216D88C(w->obj, &pos);
        floor = w->start.y + w->delta.y;
        y = pos.y - 0x8000;
        if (y > floor) {
            pos.y = y;
            func_0216D89C(w->obj, &pos);
        } else {
            pos.y = floor;
            done = 1;
            pos.x = w->start.x + w->delta.x;
            pos.z = w->start.z + w->delta.z;
            func_0216E014(w->obj, (int *)(&pos), func_0216D5F8(w->obj));
            func_020061E4(0x67B);
            func_021AC528((u32)w->obj, (u32)w->owner);
        }
        break;
    }
    return done;
}
