/*
 * file:     iss_zone_sys.c
 * unit:     yes
 * function: func_0202BAF4, func_0202BB40, func_0202BB48, func_0202BB68, func_0202BBB0, func_0202BBFC, func_0202BC48, func_0202BC60, func_0202BC78, func_0202BCA0, func_0202BDD0, func_0202BDE8, func_0202BE00, func_0202BE24, func_0202BE54, func_0202BE68, func_0202BEA4, func_0202BEBC, func_0202BECC, func_0202BEDC, func_0202BEE4, func_0202BEEC, func_0202BF54, func_0202BF84, func_0202BF90, func_0202BFC4, func_0202BFF0
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
 *   _u32_div_f   0x0209C2B0  arm
 *   _ffltu  0x0209BE04  arm
 *   _fsub   0x0209CB8C  arm
 *   _f2s    0x0209C494  arm
 */
#include "../../matched/include/Obj03439.h"
#include "../../matched/include/Obj11316.h"
#include "../../matched/include/Obj02602.h"
#include "../../matched/include/Obj03440.h"
#include "../../matched/include/Obj08807.h"

struct Obj0202BE24;
struct Listener;
struct Rec;
struct Vec;
struct Obj;
struct ArcFile;
struct Container;
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
    u8 pad_00[0x4];
    unsigned int f4;
    u8 target;
    u8 curr;
    u8 step;
    u8 pad_0B[0x1];
};

struct Rec_0202BF54 {
    u16 key;
    u16 f2;
    u16 f4;
    u16 f6;
};

struct Obj_0202BF54 {
    u32 state;
    u32 pad4;
    const struct Rec_0202BF54 *base;
    u8  sel;
    u8  pad_d;
    u16 fxe;
    u16 f10;
    u16 f12;
    u16 f14;
};

struct Rec_0202BF90 {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
};

struct Obj_0202BF90 {
    u32 pad0;
    u32 pad4;
    u32 base;
    u8  sel;
    u8  pad_d;
    u16 fxe;
    u16 f10;
    u16 f12;
    u16 f14;
};

struct Item {
    u16 key;
    u16 pad[3];
};

struct Container {
    u8 pad[4];
    u8 count;
    u8 pad2[3];
    const struct Item *items;
};

struct Obj_0202BFF0 {
    u32 pad0;
    u32 pad4;
    u32 pad8;
    u8  padc[2];
    u16 fxe;
    u16 f10;
    u16 f12;
    u16 f14;
};

extern void sub_0202BE24(struct Obj0202BE24 *p);
extern void func_0202BA24(u8 *p);
extern void VEC_Subtract(const struct Vec *a, const struct Vec *b,
                         struct Vec *out);
extern s32_0202BBFC  VEC_Mag(const struct Vec *v);
extern u32 sub_0207C768(u32 a, u32 b);
extern void VEC_Normalize(const struct Vec *v, struct Vec *out);
extern void VEC_CrossProduct(const struct Vec *a, const struct Vec *b,
                             struct Vec *out);
extern s32_0202BCA0  VEC_DotProduct(const struct Vec *a, const struct Vec *b);
extern void func_02005EE0(u32 a, u32 b, u32 c, u32 d);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern u16 func_0204961C(void *obj);
extern void func_0204944C(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dst);
extern void   func_02049238(void *handle);
extern void func_02005F24(u32 a0, u32 a1);
extern float _ffltu(u32 v);
extern float _fdiv(float a, float b);
extern float _fmul(float a, float b);
extern float _fsub(float a, float b);
extern int   _f2s(float a);
void func_0202BAF4(u8 *o);
void func_0202BB40(u8 *p);
void func_0202BB48(u8 *o);
void func_0202BB68(u8 *o, int i);
void func_0202BBB0(u8 *o, int i);
s32_0202BBFC func_0202BBFC(struct Rec *r, const struct Vec *p);
void sub_0202BC48(void *obj, u32 index, s32_0202BC48 cap);
void sub_0202BC60(void *obj, u32 index, s32_0202BC48 cap);
void func_0202BC78(u8 *o, u32 i);
s32_0202BCA0 func_0202BCA0(const struct Listener *l, const struct Vec *ps, const struct Vec *pp);
void sub_0202BDD0(void *obj, u32 index, s32_0202BDD0 cap);
void sub_0202BDE8(void *obj, u32 index, s32_0202BDE8 cap);
void func_0202BE00(u8 *p, u32 i);
void func_0202BE24(struct Obj0202BE24 *p);
u32 func_0202BE54(u8 *p, u32 a, void *unused);
u8 *func_0202BE68(u32 heapId);
void func_0202BEA4(u8 *p);
void func_0202BEBC(u8 *p);
void func_0202BECC(u8 *p, u32 key);
void func_0202BEDC(u8 *o, u16 key);
void func_0202BEE4(void *p);
void func_0202BEEC(u8 *p, u32 id);
void func_0202BF54(struct Obj_0202BF54 *o, u16 key);
void func_0202BF84(u32 *p);
void func_0202BF90(struct Obj_0202BF90 *o, u32 key);
u32 func_0202BFC4(const struct Container *c, u32 key);
void func_0202BFF0(struct Obj_0202BFF0 *o);




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

    if (((struct Obj0202BE24 *)o)->f4 == 0) {
        return;
    }
    sub_0202BE24((struct Obj0202BE24 *)o);
    for (i = 0; i < 0x10; i++) {
        if (*(u32 *)(o + i * 0x1c + 0x24) != 0) {
            func_0202BB68(o, i);
            func_0202BBB0(o, i);
            func_0202BC78(o, i);
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



void func_0202BB48(u8 *o)
{
    u8 idx = o[0x269];

    if (idx != 0xff) {
        func_02005F24(*(u16 *)(*(u32 *)(o + 0x264) + idx * 8 + 4), 0);
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




void sub_0202BC60(void *obj, u32 index, s32_0202BC48 cap)
{
    s32_0202BC48 *arr = (s32_0202BC48 *)((char *)obj + 0x1E4);
    s32_0202BC48 v = arr[index] - 0x10;

    if (v < cap) {
        v = cap;
    }
    arr[index] = v;
}



void func_0202BC78(u8 *o, u32 i)
{
    u8 *slot = o + i * 4;
    int vol = func_0202BE54(o, (u8)*(int *)(slot + 0x1E4), slot);

    func_02005F24(*(u16 *)(o + i * 0x1c + 60), vol);
}




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





/*
 * Returns (p[9] * a) / 0x7f truncated to a byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BE54.c \
 *       --func func_0202BE54 --addr 0x0202BE54 --thumb --cc 1.1p1
 */
u32 func_0202BE54(u8 *p, u32 a, void *unused)
{
    return (u8)((p[9] * a) / 0x7f);
}





/*
 * Allocates a 0x18-byte iss_zone_sys node through the debug allocator, zeroes
 * its fields with the two exceptions (+0xc takes 0xff, the "no record" index),
 * and runs the init that takes the heap id.
 *
 * The allocator's __FILE__ word is the anchor at 0x0202BEA0, the same
 * 0x020A7748 the sibling func_0202BEEC pools.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BE68.c \
 *       --func func_0202BE68 --addr 0x0202BE68 --thumb --cc 1.1p1
 */
u8 *func_0202BE68(u32 heapId)
{
    u8 *p = (u8 *)func_02030734(heapId, 0x18, 0, (const void *)0x020A7748,
                                0x55);

    ((struct Obj03439 *)p)->f0 = 0;
    p[4] = 0;
    ((struct Obj03439 *)p)->f8 = 0;
    p[0xc] = 0xff;
    ((struct Obj03439 *)p)->fE = 0;
    ((struct Obj03439 *)p)->f10 = 0;
    ((struct Obj03439 *)p)->f12 = 0;
    ((struct Obj03439 *)p)->f14 = 0;
    func_0202BEEC(p, heapId);
    return p;
}





/*
 * Releases the +8 pointer when set, then the object itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEA4.c \
 *       --func func_0202BEA4 --addr 0x0202BEA4 --thumb --cc 1.1p1
 */
void func_0202BEA4(u8 *p)
{
    if (*(u32 *)&((struct Obj11316 *)p)->f8 != 0) {
        func_020307B0(((struct Obj11316 *)p)->f8);
    }
    func_020307B0(p);
}





/*
 * Calls func_0202BFF0 when the object's +0 word is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEBC.c \
 *       --func func_0202BEBC --addr 0x0202BEBC --thumb --cc 1.1p1
 */
void func_0202BEBC(u8 *p)
{
    if (((struct Obj02602 *)p)->f0 != 0) {
        func_0202BFF0((struct Obj_0202BFF0 *)((struct Obj *)p));
    }
}





/*
 * Guarded one-argument forward: only when the node's first word is set does
 * func_0202BF90 get called with the node itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202BECC.c \
 *       --func func_0202BECC --addr 0x0202BECC --thumb --cc 1.1p1
 *
 * Closed by the `matched` class: 0x0202BF90 was filed as an EXACT entry this wave (pkt_0202BEBC), matched with the object spelled as a struct.
 */
void func_0202BECC(u8 *p, u32 key)
{
    if (((struct Obj03440 *)p)->f0 != 0) {
        func_0202BF90((struct Obj_0202BF90 *)((struct Obj *)p), key);
    }
}





/*
 * A four-byte tail-call thunk to func_0202BF54: one PROGBITS section per
 * function means this compiler cannot encode a displacement to another
 * function, so the target's address materialises through a literal pool word
 * and a `bx` (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The pool
 * word's low bit carries the Thumb bit, so the extern is declared Thumb.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEDC.c \
 *       --func func_0202BEDC --addr 0x0202BEDC --thumb --cc 1.1p1
 */
void func_0202BEDC(u8 *o, u16 key)
{
    func_0202BF54((struct Obj_0202BF54 *)o, key);
}




void func_0202BEE4(void *p)
{
    func_0202BF84(p);
}



/*
 * Sibling of func_0202B958: builds a selector out of the caller's id, takes
 * a handle from func_020490F4, sizes the record table from func_0204961C's
 * count and allocates it with func_02030734, then reads every 8-byte record
 * into the handle with func_0204944C and releases it with func_02049238.
 * The record table is at +8 and the count byte at +4 rather than the +0x264
 * and +0x268 func_0202B958 uses, and the count here stays a signed int (the
 * guard is `ble`), which is the whole difference between the two.
 *
 * The five-argument window read is the same call func_0204944C makes from
 * its other sites; the buffer is its own stack word because the argument
 * count already spends r0-r3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEEC.c \
 *       --func func_0202BEEC --addr 0x0202BEEC --thumb --cc 1.1p1
 */
void func_0202BEEC(u8 *p, u32 id)
{
    void *h = func_020490F4(0x88, (u16)((id & 0x7fff) | 0x8000));
    int   n = func_0204961C(h);
    int   i;

    p[4] = (u8)n;
    ((struct Obj08807 *)p)->f8 = (u32)func_02030734(id, (u32)(n << 3), 0,
                                         (const void *)0x020A7748, 0xd2);

    for (i = 0; i < n; i++) {
        func_0204944C(h, (u32)i, 0, 8,
                      (void *)(((struct Obj08807 *)p)->f8 + ((u32)i << 3)));
    }
    func_02049238(h);
}



/*
 * Selects the record func_0202BFC4 matches for the caller's key and latches
 * it into the object: +0xc keeps the index, +0xe and +0x10 take the record's
 * +2 and +4 words, +0x12 and +0x14 are the arm flag and its counter, and the
 * +0 word marks the object live.  A non-zero +0 word means "already
 * selected", and 0xff means "no match"; both leave the object untouched.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BF54.c \
 *       --func func_0202BF54 --addr 0x0202BF54 --thumb --cc 1.1p1
 */
void func_0202BF54(struct Obj_0202BF54 *o, u16 key)
{
    u32 idx;

    if (o->state != 0) {
        return;
    }
    idx = func_0202BFC4((const struct Container *)((const u8 *)o), key);
    if (idx == 0xff) {
        return;
    }
    o->sel = (u8)idx;
    o->state = 1;
    o->fxe = o->base[idx].f2;
    o->f10 = o->base[idx].f4;
    o->f12 = 1;
    o->f14 = 0;
}



void func_0202BF84(u32 *p)
{
    if (*p != 0) {
        *p = 0;
    }
}



/*
 * Combines the record selected by the object's +0xc byte with the record
 * func_0202BFC4 has just selected for the caller's key: the two crossings are
 * ANDed into +0xe and +0x10, +0x12 takes the new record's +6 and +0xc records
 * the new selection.
 *
 * The spelling that matters here is the object as a struct with named members:
 * with `u8 *p` and literal offsets the allocator puts p in r4 and sel in r5,
 * twenty bytes of register numbering away.  Reading `o->sel` first, calling
 * func_0202BFC4 on the same object and only then loading `o->base` is what puts
 * sel in r4, p in r5 and the base in r6, which is the original.
 *
 * Closes the blocker of src/pending/func_0202BECC.c and, through it,
 * src/pending/func_0202B7D4.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BF90.c \
 *       --func func_0202BF90 --addr 0x0202BF90 --thumb --cc 1.1p1
 */
void func_0202BF90(struct Obj_0202BF90 *o, u32 key)
{
    u8 sel;
    u32 idx;
    const struct Rec_0202BF90 *base;

    sel = o->sel;
    idx = func_0202BFC4((const struct Container *)o, key);
    base = (const struct Rec_0202BF90 *)o->base;
    if (idx == 0xff) {
        return;
    }
    o->fxe = base[sel].f4 & base[idx].f2;
    o->f10 = base[sel].f2 & base[idx].f4;
    o->f12 = base[idx].f6;
    o->f14 = 0;
    o->sel = (u8)idx;
}



u32 func_0202BFC4(const struct Container *c, u32 key)
{
    u8 i;

    for (i = 0; i < c->count; i++) {
        if (c->items[i].key == key) {
            return i;
        }
    }

    return 0xff;
}



/*
 * The record's active window: while +0x12 exceeds the running +0x14 counter,
 * bump the counter and push a percentage to the +0xe and +0x10 gauges
 * (func_02005F24).  The two gauges differ only in the numerator: the first
 * scales the counter, the second the counter brought round by one.
 *
 * Each gauge id is bound to a local before the counter is stored and before
 * the division, which is what keeps it in the callee-saved r4 across the five
 * soft-float calls; read at the call site it is reloaded instead and the
 * frame loses a register and its numbering shifts.  Both arms re-read the two
 * u16 fields rather than sharing a computed quotient, which is why each is
 * loaded and converted twice.
 *
 * The counter bump is the one spelling that matters: `o->f14 = o->f14 + 1;`
 * compiles the same increment but lands the guard's two u16 loads in the
 * opposite r0/r1 pair (and so the `adds` that follows them), four concrete
 * bytes away from the original, while `o->f14 += 1;` reproduces it.  See
 * docs/idioms/a-compound-assignment-on-a-field-flips-the-guards-register-pair.md.
 *
 * The soft-float helpers are MSL/runtime.a's; this front end names them
 * _ffltu, _fdiv, _fmul, _fsub and _f2s, which is what the relocations carry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BFF0.c \
 *       --func func_0202BFF0 --addr 0x0202BFF0 --thumb --cc 1.1p1
 */
void func_0202BFF0(struct Obj_0202BFF0 *o)
{
    u16 id;

    if (o->f12 <= o->f14) {
        return;
    }
    id = o->fxe;
    o->f14 += 1;
    if (id != 0) {
        func_02005F24(id, _f2s(_fmul(127.0f,
                                      _fdiv(_ffltu(o->f14),
                                            _ffltu(o->f12)))));
    }
    id = o->f10;
    if (id != 0) {
        func_02005F24(id, _f2s(_fmul(127.0f,
                                      _fsub(1.0f,
                                            _fdiv(_ffltu(o->f14),
                                                  _ffltu(o->f12))))));
    }
}
