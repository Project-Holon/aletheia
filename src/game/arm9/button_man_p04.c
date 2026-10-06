/*
 * file:     button_man_p04.c
 * unit:     yes
 * function: func_02051C88, func_02051DE8, func_02051E10, func_02051E64, func_02051E74, func_02051F1C, func_02051F34, func_0205207C, func_020520A4, func_020520FC, func_020521BC
 * address:  0x02051C88
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_020A15E8    0x020A15E8  data
 *   func_02035C38 0x02035C38  arm
 *   func_02035BA4 0x02035BA4  arm
 *   func_02035C08 0x02035C08  arm
 *   func_02035C60 0x02035C60  arm
 *   MTX_Rot22_       0x0207AD64  thumb
 *   MTX_ScaleApply22 0x0207AD70  arm
 *   func_0207C778    0x0207C778  arm
 *   tbl_020A1B38     0x020A1B38  data
 *   VEC_Subtract    0x0207CA00  arm
 *   VEC_DotProduct  0x0207CA68  arm
 *   VEC_Mag         0x0207CBD0  arm
 *   VEC_Normalize   0x0207CCA4  arm
 *   FX_Div          0x0207C768  arm
 *   func_020520A4   0x020520A4  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   MTX_RotX33_      0x0207AF00  thumb
 *   MTX_RotY33_      0x0207AF1C  thumb
 *   MTX_RotZ33_      0x0207AF38  thumb
 *   MTX_Concat33     0x0207B388  arm
 *   FX_Atan2Idx    0x0207CFB8  arm
 */
#include "../../matched/include/Obj04767.h"
#include "../../matched/include/Obj16198.h"

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed int     s32;

typedef unsigned short u16;

typedef signed short   s16_02051C88;

struct Slot { u8 kind; u8 state; u8 pad[2]; };

struct Ctx {
    s32   f00;            /* 0x00 */
    u32   n;              /* 0x04 */
    void (*cb)(s32, s32, s32);  /* 0x08 */
    s32   arg;            /* 0x0c */
    struct Slot *slots;   /* 0x10 */
};

typedef signed short  s16_02051E74;

struct Mtx22 { s32 m[4]; };

struct Vec { int x, y, z; };

struct Ball_02051F1C { struct Vec p; int radius; };

struct Vec3 { int x; int y; int z; };

struct Seg {
    struct Vec3 p0;   /* 0x00 */
    struct Vec3 dir;  /* 0x0c */
    u32 pad18;
};

struct Ball_02051F34 {
    struct Vec3 c;    /* 0x00 */
    int r;            /* 0x0c */
};

struct Out {
    u32 hit;          /* 0x00 */
    struct Vec3 n;    /* 0x04 */
    int d;            /* 0x10 */
};

struct S12 {
    u32 a;
    u32 b;
    u32 c;
};

typedef long long s64;

typedef short s16_020520FC;

struct Mtx33 {
    int m[9];
};

typedef short s16_020521BC;

extern s32 func_02035C38(void);
extern int func_02035BA4(const void *p);
extern int func_02035C08(const void *p);
extern s32 func_02035C60(void);
extern void MTX_Rot22_(struct Mtx22 *mtx, s32 sinVal, s32 cosVal);
extern void MTX_ScaleApply22(const struct Mtx22 *src, struct Mtx22 *dst, s32 x, s32 y);
extern long func_0207C778(long v);
extern void VEC_Subtract(const struct Vec3 *a, const struct Vec3 *b, struct Vec3 *d);
extern int  VEC_DotProduct(const struct Vec3 *a, const struct Vec3 *b);
extern int  VEC_Mag(const struct Vec3 *v);
extern void VEC_Normalize(const struct Vec3 *v, struct Vec3 *d);
extern int  FX_Div(int a, int b);
extern void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *d);
extern void MTX_Identity33_(struct Mtx33 *m);
extern void MTX_RotX33_(struct Mtx33 *m, s16_020520FC sinv, s16_020520FC cosv);
extern void MTX_RotY33_(struct Mtx33 *m, s16_020520FC sinv, s16_020520FC cosv);
extern void MTX_RotZ33_(struct Mtx33 *m, s16_020520FC sinv, s16_020520FC cosv);
extern void MTX_Concat33(const struct Mtx33 *a, const struct Mtx33 *b,
                         struct Mtx33 *dst);
extern int  FX_Atan2Idx(int y, int x);
int func_02051DE8(void *p, int a, int b);
int func_02051E10(char *p, u32 x);
void func_02051E64(void *p, int a);
extern s16_02051E74 tbl_020A1B38[];


extern s32 (*const g_020A15E8[])(struct Slot *, s32, s32);


/*
 * The per-frame slot refresh: every slot state byte is rewritten to
 * (a == i) or (b == i) by its previous value, then every slot is dispatched
 * through the handler table at 0x020A15E8 and each result other than -1 is
 * forwarded to c->cb(i, v, c->arg).  Returns whether a slot newly took the
 * hover.
 *
 * THE LEVER (wave 18, lane ties_a; it was DIFF 352/352, 19 bytes out for
 * five waves, docs/notes/pkt_02051C88.c.txt): the loop index is
 * `unsigned long`, not u32 (unsigned int).  With u32 the first loop's
 * index and the slots base swap ip / lr over 13 instructions; mwcc colours
 * long and int as different types (the same fact wave 16 found with
 * `long i, j` in 0x02048744).  The unsigned compare against the s32 slot
 * indices is kept, which is what holds the fourth 1 in fp.
 */
s32 func_02051C88(struct Ctx *c)
{
    s32 a;
    s32 b;
    s32 h, sel;
    s32 ret = 0;
    unsigned long i;

    a = 0;
    h = func_02035C38();
    if (h != 0) {
        a = func_02035BA4((const void *)c->f00);
        b = func_02035C08((const void *)c->f00);
        sel = func_02035C60();

        for (i = 0; i < c->n; i++) {
            if (c->slots[i].state != 0) {
                c->slots[i].state = (u8)((a == i) ? 1 : 0);
            } else {
                c->slots[i].state = (u8)((b == i) ? 1 : 0);
                if (c->slots[i].state != 0)
                    ret = 1;
            }
        }
    } else {
        sel = 0;
        for (i = 0; i < c->n; i++)
            c->slots[i].state = (u8)a;
    }

    for (i = 0; i < c->n; i++) {
        s32 v = g_020A15E8[c->slots[i].kind](&c->slots[i], h, sel);
        if (v != -1)
            c->cb((s32)i, v, c->arg);
    }

    return ret;
}


/*
 * The conjunction shares one exit; `*(u8 *)(p+1)` is the armed flag the
 * 0x02051E10 sibling also tests.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051DE8.c \
 *       --func func_02051DE8 --addr 0x02051DE8 --cc 1.1p1 --arm
 */
int func_02051DE8(void *p, int a, int b)
{
    if (((struct Obj04767 *)p)->f1 == 0 || b == 0)
        return -1;
    func_02051E64(p, 1);
    return 0;
}


/*
 * State-machine step over a small ARM struct: if the flag byte at +1 is set,
 * bump the halfword at +2 while it is below 0xFFFF and report state 2;
 * otherwise it clears the second argument's slot through func_02051E64 and
 * reports 1 or 3 depending on whether the incoming second argument was zero.
 * The shared `mov r1, #0` before the compare is the constant both arms pass.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051E10.c \
 *       --func func_02051E10 --addr 0x02051E10 --cc 1.1p1 --arm
 */
int func_02051E10(char *p, u32 x)
{
    if (((struct Obj04767 *)p)->f1 != 0) {
        u16 v = ((struct Obj04767 *)p)->f2;

        if (v < 0xFFFF)
            ((struct Obj04767 *)p)->f2 = (u16)(v + 1);
        return 2;
    }
    if (x != 0) {
        func_02051E64(p, 0);
        return 3;
    }
    func_02051E64(p, 0);
    return 1;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051E64.c \
 *       --func func_02051E64 --addr 0x02051E64 --cc 1.1p1 --arm
 */
void func_02051E64(void *p, int a)
{
    ((struct Obj04767 *)p)->f0 = (unsigned char)a;
    ((struct Obj04767 *)p)->f2 = 0;
}


/*
 * Scaled 2x2 rotation: convert the angle to a 16-bit turn fraction (mode 1:
 * (ang * 0xFFFF) >> 8; mode 2: degrees, (ang * 0xFFFF) / 360, the umull by
 * 0x6C16C16D with the add-and-halve fix-up), rotate with the sin/cos pair
 * from the shared table at index ang >> 4 (FX_SinIdx/FX_CosIdx shape), then
 * scale by the two vector magnitudes.  EXACT* because the 24-byte leaf that
 * follows at 0x02051F1C (struct copy of three words plus a fourth store) has
 * no label.
 *
 * Wave 9: closed by writing the two conversions as the plain unsigned
 * expressions (the wave-7 note hand-expanded the division and kept a 19-byte
 * register residue) and the table as the extern data symbol; the old
 * "label wall" on MTX_Rot22_/MTX_ScaleApply22 is now carried by the sdk class.
 */
void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode)
{
    if (mode == 1)
        ang = (u16)((ang * 0xFFFF) >> 8);
    else if (mode == 2)
        ang = (u16)((ang * 0xFFFF) / 360);

    MTX_Rot22_(mtx, tbl_020A1B38[((s32)ang >> 4) * 2], tbl_020A1B38[((s32)ang >> 4) * 2 + 1]);
    MTX_ScaleApply22(mtx, mtx, func_0207C778((long int)v1), func_0207C778((long int)v2));
}

void func_02051F1C(struct Ball_02051F1C *dst, struct Vec *src, unsigned radius)
{
    dst->p = *src;
    dst->radius = radius;
}


/*
 * Segment-versus-sphere test: project the ball's centre onto the segment
 * p0 -> dir (t = FX_Div(dot(d, c - p0), dot(d, d)), d = dir - p0); on the
 * segment compare the distance against b->r + seg->pad18, off it compare the
 * distance to the far end and then to p0 against b->r.  Fills a 20-byte
 * { hit, normal, dist } block copied to *out when out is non-null; returns hit.
 * Compiler pin dsi/1.1p1 (a PART 1 math helper of cluster_02051E64).
 *
 * What closed it (wave 9, from the wave-7 note's 72-byte point): the distance
 * is a register local `d` compared at the shared join, and res.d is stored
 * AFTER the limit is loaded (`d = VEC_Mag(..); lim = ..; res.d = d;`).
 * Comparing res.d itself reloads it from the stack at the join.
 */
u32 func_02051F34(struct Seg *seg, struct Ball_02051F34 *b, struct Out *out)
{
    struct Out  res;    /* sp+0x24: res.hit, n, d -- copied out as one block */
    struct Vec3 sd;     /* sp+0x18 */
    struct Vec3 bc;     /* sp+0x0c */
    struct Vec3 tmp;    /* sp+0x00 */
    int t;
    int d;
    int lim;

    res.hit = 0;
    VEC_Subtract(&seg->dir, &seg->p0, &sd);
    VEC_Subtract(&b->c, &seg->p0, &bc);

    t = FX_Div(VEC_DotProduct(&sd, &bc), VEC_DotProduct(&sd, &sd));
    if (t >= 0 && t <= 0x1000) {
        func_020520A4(&sd, t, &sd);
        VEC_Subtract(&sd, &bc, &tmp);
        d = VEC_Mag(&tmp);
        lim = b->r + seg->pad18;
        res.d = d;
    } else {
        VEC_Subtract(&b->c, &seg->dir, &tmp);
        d = VEC_Mag(&tmp);
        lim = b->r;
        res.d = d;
        if (d <= lim) {
            res.hit = 1;
            goto done;
        }
        tmp = bc;
        d = VEC_Mag(&tmp);
        lim = b->r;
        res.d = d;
    }
    if (d <= lim)
        res.hit = 1;
done:
    if (out != 0) {
        VEC_Normalize(&tmp, &res.n);
        *out = res;
    }
    return res.hit;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0205207C.c \
 *       --func func_0205207C --addr 0x0205207C --cc 1.1p1 --arm
 */
void func_0205207C(char *p, struct S12 *q, struct S12 *r, u32 v)
{
    *(struct S12 *)p = *q;
    *(struct S12 *)(p + 12) = *r;
    ((struct Obj16198 *)p)->f18 = v;
}


/*
 * VEC_MultAdd-style scale: dst = v * s in 1.19.12 fixed point, component by
 * component, with the SDK's own rounding.  Each component is the inlined body
 * of FX_Mul: a 32x32 signed `smull`, +0x800 for round-to-nearest with the
 * carry folded into the high word by `adc`, then the 64-bit >> 12 spelled as
 * `lsr #12` of the low word `orr`ed with `lsl #20` of the high word.  Writing
 * it as a (s64) multiply and shift is what makes the compiler emit exactly
 * that quartet rather than a call to a runtime helper.
 *
 * All three components are computed before any store, which is why the first
 * two land as one `stm r2,{r4,ip}` and only the third takes its own `str`
 * (the source order is x, y, z and the compiler interleaves the three
 * independent multiplies freely).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020520A4.c \
 *       --func func_020520A4 --addr 0x020520A4 --cc 1.1p1 --arm
 */
void func_020520A4(const struct Vec3 *v, int s, struct Vec3 *dst)
{
    dst->x = (int)((((s64)v->x * s) + 0x800) >> 12);
    dst->y = (int)((((s64)v->y * s) + 0x800) >> 12);
    dst->z = (int)((((s64)v->z * s) + 0x800) >> 12);
}


/*
 * Build a 3x3 rotation matrix from three angles, composed X, then Y, then Z.
 * The destination (r3) is used both as the identity seed and as the running
 * accumulator; a 0x24-byte stack scratch holds the per-axis rotation before
 * each MTX_Concat33 folds it in.
 *
 * Each angle feeds the shared interleaved sin/cos halfword table at
 * 0x020A1B38 (see src/matched/func_0203F684.c): index i = angle >> 4, with
 * sin at tbl[2*i] and cos at tbl[2*i+1].  The `asr #4` is a shift, not a
 * division, and the arguments are signed, which is what makes `ldrsh` with a
 * register offset the load (docs/idioms/ldrsh-register-offset-is-signedness.md).
 *
 * The X rotation is applied straight onto the identity in the destination,
 * with no scratch; the Y and Z rotations each build into the stack scratch and
 * are folded in by MTX_Concat33(dst, &tmp, dst).  Both Concat33 calls take the
 * destination as the LEFT operand: swapping the last one to
 * MTX_Concat33(&tmp, dst, dst) is byte-correct everywhere except the two
 * `mov` bytes at +00A4/+00A8, the only residue the whole function had.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020520FC.c \
 *       --func func_020520FC --addr 0x020520FC --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void func_020520FC(int ax, int ay, int az, struct Mtx33 *dst)
{
    struct Mtx33 tmp;
    int i;

    MTX_Identity33_(dst);

    i = ax >> 4;
    MTX_RotX33_(dst, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);

    i = ay >> 4;
    MTX_RotY33_(&tmp, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);
    MTX_Concat33(dst, &tmp, dst);

    i = az >> 4;
    MTX_RotZ33_(&tmp, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);
    MTX_Concat33(dst, &tmp, dst);
}


/*
 * Turn a direction vector into a look-at rotation matrix: pitch about X, yaw
 * about Y, composed into the caller's 3x3.
 *
 * The horizontal run is measured by flattening a copy of the vector: the whole
 * 12-byte vector is copied to a stack scratch with one ldm/stm pair
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), its y component is zeroed,
 * and VEC_Mag of that gives the run.  Pitch is then FX_Atan2Idx(-v->y, run)
 * and yaw is FX_Atan2Idx(v->x, v->z) - note the argument order is (y, x), the
 * SDK's own, and the pitch numerator carries the `rsb r0, r2, #0` negation.
 *
 * Both angle indices feed the shared interleaved sin/cos halfword table at
 * 0x020A1B38 (see src/matched/func_0203F684.c) at i = angle >> 4, sin at
 * tbl[2*i] and cos at tbl[2*i+1], exactly as in func_020520FC next door.
 *
 * Declaration order is the whole difference between 184 correct bytes and four
 * wrong ones: the frame lays `flat` at sp+0x48, `mx` at sp+0x24 and `my` at
 * sp+0x00, so the locals must be declared flat, mx, my - the later declaration
 * takes the LOWER stack address
 * (docs/idioms/local-declaration-order-is-stack-order.md).  Declaring my, mx,
 * flat reproduces every instruction and misses only the three `add rN, sp, #k`
 * immediates and the `str r1, [sp, #0x4c]` offset.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020521BC.c \
 *       --func func_020521BC --addr 0x020521BC --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void func_020521BC(const struct Vec3 *v, struct Mtx33 *dst)
{
    struct Vec3  flat;
    struct Mtx33 mx;
    struct Mtx33 my;
    int          i;
    int          run;

    flat = *v;
    flat.y = 0;
    run = VEC_Mag(&flat);

    i = FX_Atan2Idx(-v->y, run) >> 4;
    MTX_RotX33_(&mx, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);

    i = FX_Atan2Idx(v->x, v->z) >> 4;
    MTX_RotY33_(&my, tbl_020A1B38[2 * i], tbl_020A1B38[2 * i + 1]);

    MTX_Concat33(&mx, &my, dst);
}
