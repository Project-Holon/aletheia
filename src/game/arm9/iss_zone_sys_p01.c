/*
 * file:     iss_zone_sys_p01.c
 * unit:     yes
 * function: func_0202BAF4, func_0202BB40, func_0202BB48, func_0202BB68, func_0202BBB0, func_0202BBFC, func_0202BC48, func_0202BC60, func_0202BC78, func_0202BCA0, func_0202BDD0, func_0202BDE8, func_0202BE00, func_0202BE24
 * address:  0x0202BAF4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0202BE24   0x0202BE24  thumb
 *   func_0202BA24  0x0202BA24  thumb
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Mag        0x0207CBD0  arm
 *   sub_0207C768   0x0207C768  arm
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   VEC_Normalize     0x0207CCA4  arm
 *   VEC_CrossProduct  0x0207CAE8  arm
 *   VEC_DotProduct    0x0207CA68  arm
 *   _ll_mul           0x0209C054  arm
 */
#include "../../matched/include/Obj05797.h"

struct Obj0202BE24;
struct Listener;
struct Rec;
struct Vec;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef enum { SLOT_0, SLOT_MAX = 16 } Slot;

typedef signed int    s32_0202BB68;

typedef signed int s32_0202BBFC;

struct Vec { s32_0202BBFC x, y, z; };

struct Rec {
    s32_0202BBFC pad0;
    struct Vec pos;
    s32_0202BBFC radius;
    s32_0202BBFC amp;
};

typedef int s32_0202BC48;

typedef signed int   s32_0202BCA0;

typedef signed long long s64;

struct Listener {
    s32_0202BCA0 pad00;
    struct Vec fwd;
};

typedef int s32_0202BDD0;

typedef int s32_0202BDE8;

typedef unsigned short u16;

struct Obj0202BE24 {
    u8 pad[8];
    u8 target;
    u8 curr;
    u8 step;
};

extern void sub_0202BE24(struct Obj0202BE24 *p);
extern void func_0202BA24(u8 *p);
extern s32_0202BB68 func_0202BBFC(struct Rec *r, const struct Vec *p);
extern s32_0202BB68 func_0202BCA0(const struct Listener *l, const struct Vec *ps, const struct Vec *pp);
extern void VEC_Subtract(const struct Vec *a, const struct Vec *b,
                         struct Vec *out);
extern s32_0202BBFC  VEC_Mag(const struct Vec *v);
extern u32 sub_0207C768(u32 a, u32 b);
extern void VEC_Normalize(const struct Vec *v, struct Vec *out);
extern void VEC_CrossProduct(const struct Vec *a, const struct Vec *b,
                             struct Vec *out);
extern s32_0202BCA0  VEC_DotProduct(const struct Vec *a, const struct Vec *b);
extern void func_02005EE0(u32 a, u32 b, u32 c, u32 d);
void func_0202BAF4(u8 *o);
void func_0202BB40(u8 *p);
int func_0202BB48(int a0);
void func_0202BB68(u8 *o, int i);
void func_0202BBB0(u8 *o, int i);
void sub_0202BC48(void *obj, u32 index, s32_0202BC48 cap);
void sub_0202BC60(void *obj, u32 index, s32_0202BC48 cap);
int func_0202BC78(int a0, int a1);
void sub_0202BDD0(void *obj, u32 index, s32_0202BDD0 cap);
void sub_0202BDE8(void *obj, u32 index, s32_0202BDE8 cap);
void func_0202BE00(u8 *p, u32 i);


/*
 * iss_3ds_sys.c per-frame step: returns when +0x04 is zero, then runs the
 * four per-entry steps over every live entry of the 0x10-slot table.
 * The listing extent (84) runs into the 8-byte thunk at 0x0202BB40; the
 * function itself is 74 bytes.
 *
 * The kept `cmp r4, #0x10; bge` zero-trip guard (the four bytes that were
 * the whole residue in docs/notes/func_0202BAF4.c.txt) is an enum-typed
 * counter (docs/idioms/an-enum-type-keeps-values-out-of-constant-folding.md),
 * the same lever as its sibling func_0202BA24.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BAF4.c \
 *       --func func_0202BAF4 --addr 0x0202BAF4 --thumb --cc 1.1p1
 */
void func_0202BAF4(u8 *o)
{
    Slot i;

    if (((struct Obj05797 *)o)->f4 == 0) {
        return;
    }
    sub_0202BE24((struct Obj0202BE24 *)o);
    for (i = 0; i < 0x10; i++) {
        if (*(u32 *)(o + i * 0x1c + 0x24) != 0) {
            func_0202BB68(o, i);
            func_0202BBB0(o, i);
            func_0202BC78((int)o, i);
            func_0202BE00(o, i);
        }
    }
}


/*
 * iss_3ds_sys.c: a bare tail-call thunk to func_0202BA24 (ldr r3, [pc, #0];
 * bx r3; .word 0x0202BA25), the target of the thunk at 0x0202B90C.  Not a
 * seeded start yet (integrator: seed 0x0202BB40 thumb); filed so that
 * func_0202B90C's pool word has a matched witness.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BB40.c \
 *       --func func_0202BB40 --addr 0x0202BB40 --thumb --cc 1.1p1
 */
void func_0202BB40(u8 *p)
{
    func_0202BA24(p);
}

int func_0202BB48(int a0){ int t0; if ((unsigned int)(*(unsigned char *)(((char *)(a0) + ((int)(0x269) << 0)))) != (unsigned int)(0xff)) { t0 = func_02005F24((int)*(unsigned short *)(((char *)((*(int *)(((char *)(a0) + ((int)((0x269 - 5)) << 0))) + (*(unsigned char *)(((char *)(a0) + ((int)(0x269) << 0))) << 3))) + 4)), (int)0, (int)*(unsigned char *)(((char *)(a0) + ((int)(0x269) << 0)))); } else {  return a0; } }


/*
 * A whole translation unit, matched as one byte range.
 *
 * iss_3ds_sys.c, the per-slot twins that func_0202BAF4 steps: for a live
 * entry (0x1c-byte stride at +0x24), run the entry's comparator and move the
 * slot's s32 level (+0x1E4 or +0x224, indexed by i) toward the result through
 * the clamp helpers of unit_0202BC48 / sub_0202BDD0 / sub_0202BDE8, which
 * take the comparator result as their third argument.  func_0202BBB0's
 * comparator takes the extra sub-object at +0x18, and its two compares are
 * the mirror of func_0202BB68's.
 *
 * What closed them (wave 17, from 37 and 36 out): callee arity read from
 * the callee bodies.  Both clamp helpers compare against r2
 * (src/matched/unit_0202BC48.c, sub_0202BDD0.c, sub_0202BDE8.c are
 * (obj, index, cap)); declaring them with two parameters dropped the
 * image's `adds r2, r0, #0` copy of the comparator result, the one
 * instruction the note had chased as a register-order problem.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202BB68.c \
 *       --addr 0x0202BB68 --thumb
 */
void func_0202BB68(u8 *o, int i)
{
    u8 *e = o + 0x24;
    s32_0202BB68 v;
    s32_0202BB68 lv;

    if (*(u32 *)(e + i * 0x1c) == 0) {
        return;
    }
    v  = func_0202BBFC((struct Rec *)(e + i * 0x1c), (const struct Vec *)(o + 0xc));
    lv = *(s32_0202BB68 *)(o + i * 4 + 0x1e4);
    if (lv < v) {
        sub_0202BC48(o, i, v);
        return;
    }
    if (v < lv) {
        sub_0202BC60(o, i, v);
    }
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * iss_3ds_sys.c, the per-slot twins that func_0202BAF4 steps: for a live
 * entry (0x1c-byte stride at +0x24), run the entry's comparator and move the
 * slot's s32 level (+0x1E4 or +0x224, indexed by i) toward the result through
 * the clamp helpers of unit_0202BC48 / sub_0202BDD0 / sub_0202BDE8, which
 * take the comparator result as their third argument.  func_0202BBB0's
 * comparator takes the extra sub-object at +0x18, and its two compares are
 * the mirror of func_0202BB68's.
 *
 * What closed them (wave 17, from 37 and 36 out): callee arity read from
 * the callee bodies.  Both clamp helpers compare against r2
 * (src/matched/unit_0202BC48.c, sub_0202BDD0.c, sub_0202BDE8.c are
 * (obj, index, cap)); declaring them with two parameters dropped the
 * image's `adds r2, r0, #0` copy of the comparator result, the one
 * instruction the note had chased as a register-order problem.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202BB68.c \
 *       --addr 0x0202BB68 --thumb
 */
void func_0202BBB0(u8 *o, int i)
{
    u8 *e = o + 0x24;
    s32_0202BB68 v;
    s32_0202BB68 lv;

    if (*(u32 *)(e + i * 0x1c) == 0) {
        return;
    }
    v  = func_0202BCA0((const struct Listener *)(e + i * 0x1c), (const struct Vec *)(o + 0xc), (const struct Vec *)(o + 0x18));
    lv = *(s32_0202BB68 *)(o + i * 4 + 0x224);
    if (v < lv) {
        sub_0202BDD0(o, i, v);
        return;
    }
    if (lv < v) {
        sub_0202BDE8(o, i, v);
    }
}


/*
 * Distance falloff: the vector at +4 of the record is taken relative to
 * the caller's point, and the remaining headroom (the radius at +0x10
 * less that distance) is divided by the radius through the hardware
 * divider sub_0207C768.  The quotient is an FX32, so it is scaled back
 * by 4096.0f in float before multiplying the amplitude at +0x14 and
 * truncating; that is the pool word 0x45800000 at 0x0202BC44.
 * Outside the radius the answer is 0.
 *
 * The compare is signed (bge), so the radius field is s32 and the
 * `mag >= radius` arm is the one written first.
 */
s32_0202BBFC func_0202BBFC(struct Rec *r, const struct Vec *p)
{
    struct Vec d;
    s32_0202BBFC mag;
    float q;

    VEC_Subtract(&r->pos, p, &d);
    mag = VEC_Mag(&d);
    if (r->radius < mag) {
        return 0;
    }
    q = (float)(s32_0202BBFC)sub_0207C768((s32_0202BBFC)(r->radius - mag), (s32_0202BBFC)r->radius) / 4096.0f;
    return (s32_0202BBFC)((float)r->amp * q);
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * A clamp-increment and a clamp-decrement on the same signed 32-bit array,
 * offset 0x1E4 of the object, indexed by the second argument and clamped
 * against a caller-supplied bound passed as the third: sub_0202BC48 adds
 * 0x10 and caps at the bound from above, sub_0202BC60 subtracts 0x10 and
 * floors at the bound from below. The two are otherwise identical, back to
 * back with no gap, and neither has a relocation.
 *
 * The comparison order in each is a deliberate `cmp`-operand tell
 * (docs/idioms/cmp-operand-order-names-the-temporary.md): sub_0202BC48
 * compares the bound against the computed value (`cmp r2, r1`), which is
 * what `if (cap < v)` compiles to, not `if (v > cap)`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202BC48.c \
 *       --addr 0x0202BC48 --thumb
 */
void sub_0202BC48(void *obj, u32 index, s32_0202BC48 cap)
{
    s32_0202BC48 *arr = (s32_0202BC48 *)((char *)obj + 0x1E4);
    s32_0202BC48 v = arr[index] + 0x10;

    if (cap < v) {
        v = cap;
    }
    arr[index] = v;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * A clamp-increment and a clamp-decrement on the same signed 32-bit array,
 * offset 0x1E4 of the object, indexed by the second argument and clamped
 * against a caller-supplied bound passed as the third: sub_0202BC48 adds
 * 0x10 and caps at the bound from above, sub_0202BC60 subtracts 0x10 and
 * floors at the bound from below. The two are otherwise identical, back to
 * back with no gap, and neither has a relocation.
 *
 * The comparison order in each is a deliberate `cmp`-operand tell
 * (docs/idioms/cmp-operand-order-names-the-temporary.md): sub_0202BC48
 * compares the bound against the computed value (`cmp r2, r1`), which is
 * what `if (cap < v)` compiles to, not `if (v > cap)`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202BC48.c \
 *       --addr 0x0202BC48 --thumb
 */
void sub_0202BC60(void *obj, u32 index, s32_0202BC48 cap)
{
    s32_0202BC48 *arr = (s32_0202BC48 *)((char *)obj + 0x1E4);
    s32_0202BC48 v = arr[index] - 0x10;

    if (v < cap) {
        v = cap;
    }
    arr[index] = v;
}

int func_0202BC78(int a0, int a1){ int t0, t1; t0 = func_0202BE54((int)a0, (int)((unsigned int)((*(int *)(((char *)(((a0 + 0) + ((a1 + 0) << 2))) + ((int)((0x79 << 2)) << 0))) << 0x18)) >> 0x18), (int)((a0 + 0) + ((a1 + 0) << 2))); t1 = func_02005F24((int)*(unsigned short *)(((char *)(((a0 + 0) + ((a1 + 0) * 0x1c))) + 60)), (int)(t0 + 0)); return t1; }


/*
 * Signed pan, -0x80..0x7f, for a point heard from a listener: build the
 * listener's right-hand axis by crossing its forward vector with world up
 * (and normalising twice, which is what the doubled VEC_Normalize pair is),
 * then project the listener-to-source direction onto it.  The three
 * _ll_mul + shift-by-12 triples are FX_Mul in its open form, scaling the
 * normalised axis by the source distance.
 *
 * The two vector arguments arrive as pointers and are copied into locals
 * before use; the ldm/stm pairs at the top are those copies, not aliasing
 * work (see docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * The 4096.0f divisor is the pool word 0x45800000 at 0x0202BDCC; 0x43000000
 * is 128.0f, materialised as movs #0x43 / lsls #0x18 rather than pooled.
 */
s32_0202BCA0 func_0202BCA0(const struct Listener *l, const struct Vec *ps,
                  const struct Vec *pp)
{
    struct Vec d;
    struct Vec rel;
    struct Vec sv2;
    struct Vec up;
    struct Vec sv;
    struct Vec axis;
    struct Vec scaled;
    struct Vec n;
    struct Vec src;
    struct Vec pos;
    struct Vec fwd;
    s32_0202BCA0 dist;
    s32_0202BCA0 pan;

    src = *ps;
    pos = *pp;
    fwd = l->fwd;
    VEC_Subtract(&pos, &src, &d);
    VEC_Subtract(&fwd, &src, &rel);

    up.x = 0;
    up.y = 0x1000;
    up.z = 0;
    VEC_Normalize(&d, &n);
    VEC_CrossProduct(&n, &up, &axis);
    VEC_Normalize(&axis, &axis);
    VEC_CrossProduct(&axis, &n, &scaled);
    VEC_Normalize(&scaled, &scaled);
    VEC_Normalize(&scaled, &scaled);

    dist = VEC_DotProduct(&rel, &scaled);
    sv.x = (s32_0202BCA0)(((s64)scaled.x * dist + 0x800) >> 12);
    sv.y = (s32_0202BCA0)(((s64)scaled.y * dist + 0x800) >> 12);
    sv.z = (s32_0202BCA0)(((s64)scaled.z * dist + 0x800) >> 12);

    VEC_Subtract(&rel, &sv, &sv2);
    VEC_Normalize(&sv2, &sv2);
    pan = (s32_0202BCA0)((float)VEC_DotProduct(&axis, &sv2) / 4096.0f * 128.0f);
    if (pan < -0x80) {
        pan = -0x80;
    }
    if (pan > 0x7f) {
        pan = 0x7f;
    }
    return pan;
}


/*
 * A clamp-decrement on the same shape as sub_0202BC60, a different signed
 * 32-bit array (offset 0x224 of the object) and a different step (0x20). No
 * relocation. Matched as a one-function unit rather than with `one`: this
 * function is followed by two bytes of inter-section padding before the
 * next label, exactly the situation in src/matched/sub_0202AB64.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/sub_0202BDD0.c \
 *       --addr 0x0202BDD0 --thumb
 */
void sub_0202BDD0(void *obj, u32 index, s32_0202BDD0 cap)
{
    s32_0202BDD0 *arr = (s32_0202BDD0 *)((char *)obj + 0x224);
    s32_0202BDD0 v = arr[index] - 0x20;

    if (v < cap) {
        v = cap;
    }
    arr[index] = v;
}


/*
 * A clamp-increment on the same shape as sub_0202BC48, the same array as
 * sub_0202BDD0 (offset 0x224) and the same step (0x20). No relocation. This
 * function opens the next packet, so it stays a file of its own rather than
 * joining the pkt_0202B7D4 trio it otherwise matches. Matched as a
 * one-function unit rather than with `one`, for the same trailing-padding
 * reason as sub_0202BDD0.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/sub_0202BDE8.c \
 *       --addr 0x0202BDE8 --thumb
 */
void sub_0202BDE8(void *obj, u32 index, s32_0202BDE8 cap)
{
    s32_0202BDE8 *arr = (s32_0202BDE8 *)((char *)obj + 0x224);
    s32_0202BDE8 v = arr[index] + 0x20;

    if (cap < v) {
        v = cap;
    }
    arr[index] = v;
}


/*
 * Signals one record's +0x3c halfword to func_02005EE0 with the +0x224
 * context pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BE00.c \
 *       --func func_0202BE00 --addr 0x0202BE00 --thumb --cc 1.1p1
 */
void func_0202BE00(u8 *p, u32 i)
{
    func_02005EE0(*(u16 *)(p + i * 0x1c + 0x3c), 0x100, 0,
                  *(u32 *)(p + i * 4 + 0x224));
}


void func_0202BE24(struct Obj0202BE24 *p)
{
    int target = p->target;
    int curr = p->curr;
    int diff;
    int abs_diff;
    int step;

    if (curr == target) {
        return;
    }

    diff = target - curr;
    abs_diff = diff;
    if (diff <= 0) {
        abs_diff = -diff;
    }

    step = p->step;
    if (abs_diff >= step) {
        if (diff < 0) {
            diff = -step;
        } else {
            diff = step;
        }
    }

    p->curr += diff;
}
