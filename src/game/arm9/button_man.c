/*
 * file:     button_man.c
 * unit:     yes
 * function: BUTTON_MAN_Create, BUTTON_MAN_ClearSlot, BUTTON_MAN_Delete, BUTTON_MAN_UpdateSlots, BUTTON_MAN_SlotHandlerIdle, BUTTON_MAN_SlotHandlerPressed, BUTTON_MAN_SlotSetKind, BUTTON_MAN_RotScaleMtx22, BUTTON_MAN_InitSphere, BUTTON_MAN_SegmentSphereTest, BUTTON_MAN_InitSegment, BUTTON_MAN_ScaleVec, BUTTON_MAN_MakeRotMtxXYZ, BUTTON_MAN_MakeLookAtMtx, BUTTON_MAN_ConvertUcs2ToSjis, BUTTON_MAN_Ucs2CharToSjis
 * address:  0x02051B84
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * The button manager: a rect table ended by 0xFF, one Slot per rect, and a
 * per-frame touch refresh that dispatches each slot through the handler table
 * at 0x020A15E8.  Own object: the button_man.c __FILE__ string
 * (layout/file_anchors.txt, pool of BUTTON_MAN_Create).  Builds EXACT with
 * 1.1p1 and dsi/1.2, DIFF with ../1.2/sp2 (the compiler of spl_emitter.c next
 * to it) and with -proc arm7tdmi (the flags of spl_random.c).
 *
 * Wave 13 lane A6: the ParticleMan/ParticleSys accessor head that used to sit
 * at 0x02051774..0x02051B84 was moved to particle.c, which abuts this file
 * exactly and owns the same g_pParticleMan/ParticleSys object.
 *
 * symbols:
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   g_020A7FCC      0x020A7FCC  data
 *   g_020A15E8    0x020A15E8  data
 *   TOUCHPANEL_GetCont 0x02035C38  arm
 *   TOUCHPANEL_HitCont 0x02035BA4  arm
 *   TOUCHPANEL_HitTrg 0x02035C08  arm
 *   TOUCHPANEL_GetTrg 0x02035C60  arm
 *   MTX_Rot22_       0x0207AD64  thumb
 *   MTX_ScaleApply22 0x0207AD70  arm
 *   FX_Inv    0x0207C778  arm
 *   FX_SinCosTable_     0x020A1B38  data
 *   VEC_Subtract    0x0207CA00  arm
 *   VEC_DotProduct  0x0207CA68  arm
 *   VEC_Mag         0x0207CBD0  arm
 *   VEC_Normalize   0x0207CCA4  arm
 *   FX_Div          0x0207C768  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   MTX_RotX33_      0x0207AF00  thumb
 *   MTX_RotY33_      0x0207AF1C  thumb
 *   MTX_RotZ33_      0x0207AF38  thumb
 *   MTX_Concat33     0x0207B388  arm
 *   FX_Atan2Idx    0x0207CFB8  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 */
#include "../types.h"

#include "../sdk_fx.h"
#include "button_man.h"

struct ButtonSlot {
    u8  kind;               /* index into g_020A15E8: 0 idle, 1 pressed */
    u8  state;
    u16 count;
};

struct ButtonMan {
    u8          *rects;     /* +0x00, 4-byte entries ended by 0xFF */
    u32          n;         /* +0x04 */
    void       (*cb)(u32, s32, void *);  /* +0x08 */
    void        *arg;       /* +0x0C */
    struct ButtonSlot *slots;     /* +0x10 */
};

/* Kept local: the heap id is a u16 here (gfl_heap_wrap.h takes u32). */
#ifdef __MWERKS__
extern void *GFL_HEAP_Alloc(u16 id, u32 size, u32 flags, void *file, u32 line); /* original prototype; the definition differs in argument sign, argument width, pointer type */
extern u32 GFL_HEAP_Free(void *p);
#else
#include "gfl_heap_wrap.h"
#endif
#include "touchpanel.h"
#include "fx_mtx22.h"
#include "fx_cp.h"
#include "fx_vec.h"
#include "fx_mtx33.h"
#include "fx_atanidx.h"
#include "strbuf.h"
struct ButtonMan *BUTTON_MAN_Create(u8 *rects, void (*cb)(u32, s32, void *), void *arg, int heap);
void BUTTON_MAN_ClearSlot(struct ButtonSlot *slot);
void BUTTON_MAN_Delete(struct ButtonMan *bm);
s32 BUTTON_MAN_UpdateSlots(struct ButtonMan *c);
int BUTTON_MAN_SlotHandlerIdle(struct ButtonSlot *p, int a, int b);
int BUTTON_MAN_SlotHandlerPressed(struct ButtonSlot *p, u32 x);
void BUTTON_MAN_SlotSetKind(struct ButtonSlot *p, int a);
void BUTTON_MAN_RotScaleMtx22(MtxFx22 *mtx, u32 ang, long scaleX, long scaleY, u8 mode);
void BUTTON_MAN_InitSphere(ButtonSphere *dst, VecFx32 *src, unsigned radius);
u32 BUTTON_MAN_SegmentSphereTest(ButtonSegment *seg, ButtonSphere *b, ButtonHitInfo *out);
void BUTTON_MAN_InitSegment(ButtonSegment *p, VecFx32 *q, VecFx32 *r, u32 v);
void BUTTON_MAN_ScaleVec(const VecFx32 *v, int s, VecFx32 *dst);
void BUTTON_MAN_MakeRotMtxXYZ(int ax, int ay, int az, MtxFx33 *dst);
void BUTTON_MAN_MakeLookAtMtx(const VecFx32 *v, MtxFx33 *dst);
void BUTTON_MAN_ConvertUcs2ToSjis(u8 *a, u8 *b, u32 n);
int BUTTON_MAN_Ucs2CharToSjis(u16 *src, char *dst, u32 *stop);
extern char g_020A7FCC[];
extern s16 FX_SinCosTable_[];

extern s32 (*const g_020A15E8[])(struct ButtonSlot *, s32, s32);

struct ButtonMan *BUTTON_MAN_Create(u8 *rects, void (*cb)(u32, s32, void *), void *arg, int heap)
{
    struct ButtonMan *r;
    int i = 0;
    unsigned j;

    while (i < 0xff) {
        if (rects[i * 4] == 0xff) {
            break;
        }
        i++;
    }
    r = GFL_HEAP_Alloc((u16)heap, sizeof(*r), 0, g_020A7FCC, 0x6b);
    if (r != 0) {
        r->rects = rects;
        r->n = i;
        r->cb = cb;
        r->arg = arg;
        r->slots = GFL_HEAP_Alloc((u16)heap, i * 4, 0, g_020A7FCC, 0x73);
        if (r->slots != 0) {
            for (j = 0; j < i; j++) {
                BUTTON_MAN_ClearSlot(&r->slots[j]);
            }
        } else {
            GFL_HEAP_Free(r);
            r = 0;
        }
    }
    return r;
}

void BUTTON_MAN_ClearSlot(struct ButtonSlot *slot)
{
    slot->kind = 0;
    slot->state = 0;
    slot->count = 0;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_Delete.c \
 *       --func BUTTON_MAN_Delete --addr 0x02051C6C --cc 1.1p1 --arm
 */
void BUTTON_MAN_Delete(struct ButtonMan *bm)
{
    GFL_HEAP_Free(bm->slots);
    GFL_HEAP_Free(bm);
}

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
s32 BUTTON_MAN_UpdateSlots(struct ButtonMan *c)
{
    s32 a;
    s32 b;
    s32 h, sel;
    s32 ret = 0;
    unsigned long i;

    a = 0;
    h = TOUCHPANEL_GetCont();
    if (h != 0) {
        a = TOUCHPANEL_HitCont((const TouchHitTable *)(c->rects));
        b = TOUCHPANEL_HitTrg((const TouchHitTable *)(c->rects));
        sel = TOUCHPANEL_GetTrg();

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
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SlotHandlerIdle.c \
 *       --func BUTTON_MAN_SlotHandlerIdle --addr 0x02051DE8 --cc 1.1p1 --arm
 */
int BUTTON_MAN_SlotHandlerIdle(struct ButtonSlot *p, int a, int b)
{
    if (p->state == 0 || b == 0)
        return -1;
    BUTTON_MAN_SlotSetKind(p, 1);
    return 0;
}

/*
 * State-machine step over a small ARM struct: if the flag byte at +1 is set,
 * bump the halfword at +2 while it is below 0xFFFF and report state 2;
 * otherwise it clears the second argument's slot through BUTTON_MAN_SlotSetKind and
 * reports 1 or 3 depending on whether the incoming second argument was zero.
 * The shared `mov r1, #0` before the compare is the constant both arms pass.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SlotHandlerPressed.c \
 *       --func BUTTON_MAN_SlotHandlerPressed --addr 0x02051E10 --cc 1.1p1 --arm
 */
int BUTTON_MAN_SlotHandlerPressed(struct ButtonSlot *p, u32 x)
{
    if (p->state != 0) {
        u16 v = p->count;

        if (v < 0xFFFF)
            p->count = (u16)(v + 1);
        return 2;
    }
    if (x != 0) {
        BUTTON_MAN_SlotSetKind(p, 0);
        return 3;
    }
    BUTTON_MAN_SlotSetKind(p, 0);
    return 1;
}

/*
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_SlotSetKind.c \
 *       --func BUTTON_MAN_SlotSetKind --addr 0x02051E64 --cc 1.1p1 --arm
 */
void BUTTON_MAN_SlotSetKind(struct ButtonSlot *p, int a)
{
    p->kind = (u8)a;
    p->count = 0;
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
void BUTTON_MAN_RotScaleMtx22(MtxFx22 *mtx, u32 ang, long scaleX, long scaleY, u8 mode)
{
    if (mode == 1)
        ang = (u16)((ang * 0xFFFF) >> 8);
    else if (mode == 2)
        ang = (u16)((ang * 0xFFFF) / 360);

    MTX_Rot22_(mtx, FX_SinCosTable_[((s32)ang >> 4) * 2], FX_SinCosTable_[((s32)ang >> 4) * 2 + 1]);
    MTX_ScaleApply22(mtx, mtx, FX_Inv(scaleX), FX_Inv(scaleY));
}

void BUTTON_MAN_InitSphere(ButtonSphere *dst, VecFx32 *src, unsigned radius)
{
    dst->c = *src;
    dst->r = radius;
}

/*
 * Segment-versus-sphere test: project the ball's centre onto the segment
 * p0 -> dir (t = FX_Div(dot(d, c - p0), dot(d, d)), d = dir - p0); on the
 * segment compare the distance against b->r + seg->radius, off it compare the
 * distance to the far end and then to p0 against b->r.  Fills a 20-byte
 * { hit, normal, dist } block copied to *out when out is non-null; returns hit.
 * Compiler pin dsi/1.1p1 (a PART 1 math helper of cluster_02051E64).
 *
 * What closed it (wave 9, from the wave-7 note's 72-byte point): the distance
 * is a register local `d` compared at the shared join, and res.d is stored
 * AFTER the limit is loaded (`d = VEC_Mag(..); lim = ..; res.d = d;`).
 * Comparing res.d itself reloads it from the stack at the join.
 */
u32 BUTTON_MAN_SegmentSphereTest(ButtonSegment *seg, ButtonSphere *b, ButtonHitInfo *out)
{
    ButtonHitInfo      res;    /* sp+0x24: res.hit, n, d -- copied out as one block */
    VecFx32 sd;     /* sp+0x18 */
    VecFx32 bc;     /* sp+0x0c */
    VecFx32 tmp;    /* sp+0x00 */
    int t;
    int d;
    int lim;

    res.hit = 0;
    VEC_Subtract(&seg->dir, &seg->p0, &sd);
    VEC_Subtract(&b->c, &seg->p0, &bc);

    t = FX_Div(VEC_DotProduct(&sd, &bc), VEC_DotProduct(&sd, &sd));
    if (t >= 0 && t <= 0x1000) {
        BUTTON_MAN_ScaleVec(&sd, t, &sd);
        VEC_Subtract(&sd, &bc, &tmp);
        d = VEC_Mag(&tmp);
        lim = b->r + seg->radius;
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
 *   python tools/match.py one --src src/matched/BUTTON_MAN_InitSegment.c \
 *       --func BUTTON_MAN_InitSegment --addr 0x0205207C --cc 1.1p1 --arm
 */
void BUTTON_MAN_InitSegment(ButtonSegment *p, VecFx32 *q, VecFx32 *r, u32 v)
{
    p->p0 = *q;
    p->dir = *r;
    p->radius = v;
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
 *   python tools/match.py one --src src/matched/BUTTON_MAN_ScaleVec.c \
 *       --func BUTTON_MAN_ScaleVec --addr 0x020520A4 --cc 1.1p1 --arm
 */
void BUTTON_MAN_ScaleVec(const VecFx32 *v, int s, VecFx32 *dst)
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
 * 0x020A1B38 (see src/matched/GF_STANDARD_Get_F684.c): index i = angle >> 4, with
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
 *   python tools/match.py one --src src/matched/BUTTON_MAN_MakeRotMtxXYZ.c \
 *       --func BUTTON_MAN_MakeRotMtxXYZ --addr 0x020520FC --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void BUTTON_MAN_MakeRotMtxXYZ(int ax, int ay, int az, MtxFx33 *dst)
{
    MtxFx33 tmp;
    int i;

    MTX_Identity33_(dst);

    i = ax >> 4;
    MTX_RotX33_(dst, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);

    i = ay >> 4;
    MTX_RotY33_(&tmp, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);
    MTX_Concat33(dst, &tmp, dst);

    i = az >> 4;
    MTX_RotZ33_(&tmp, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);
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
 * 0x020A1B38 (see src/matched/GF_STANDARD_Get_F684.c) at i = angle >> 4, sin at
 * tbl[2*i] and cos at tbl[2*i+1], exactly as in BUTTON_MAN_MakeRotMtxXYZ next door.
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
 *   python tools/match.py one --src src/matched/BUTTON_MAN_MakeLookAtMtx.c \
 *       --func BUTTON_MAN_MakeLookAtMtx --addr 0x020521BC --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */
void BUTTON_MAN_MakeLookAtMtx(const VecFx32 *v, MtxFx33 *dst)
{
    VecFx32         flat;
    MtxFx33        mx;
    MtxFx33        my;
    int          i;
    int          run;

    flat = *v;
    flat.y = 0;
    run = VEC_Mag(&flat);

    i = FX_Atan2Idx(-v->y, run) >> 4;
    MTX_RotX33_(&mx, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);

    i = FX_Atan2Idx(v->x, v->z) >> 4;
    MTX_RotY33_(&my, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);

    MTX_Concat33(&mx, &my, dst);
}

/*
 * Convert a run of n wide characters at `a` into the narrow buffer at `b`,
 * stopping early when the converter raises its flag.  BUTTON_MAN_Ucs2CharToSjis is the
 * per-character encoder next door; it returns 1 when it wrote two bytes and
 * something else when it wrote one, and it reports "stop" by storing 1 into
 * the scratch word it is handed.
 *
 * Four declaration-level levers carry this function, three of them measured
 * by an earlier lane (docs/notes/pkt_02052274.c.txt) and the fourth the one
 * that finally closed it:
 *
 *  1. BOTH cursors are initialised BEFORE the `n == 0` guard.  That is what
 *     gives the original its nine-register push and `sub sp, sp, #4` pad;
 *     guard-first drops to eight callee-saved registers and 92 bytes.
 *  2. The scratch word is reset INSIDE the loop from a separate zero-valued
 *     local `z`, not once outside: `scratch = z;` is the `mov r5, r6` /
 *     `str r5, [sp]` pair.
 *  3. `i++` sits BEFORE the `scratch == 1` early return, not after it.
 *  4. `&scratch` is written INLINE at the call, NOT bound to a `u32 *p`
 *     hoisted above the loop.  With the pointer local, the scratch pointer
 *     and the zero seed trade r4 and r5 -- eight bytes out, and a residue no
 *     permuter mutation moves (164 single mutations tried, none improved,
 *     and ten hand spellings before that).  Written inline, the compiler
 *     materialises the seed first and colours it r5 exactly as the image
 *     does.  This is the same lever that closed SPL_EMITTER_FreeTexNode in this
 *     cluster: hoisting an address-of into a named local gives that value
 *     the lower colour and displaces the values the image wanted there.
 *
 * Unlike most of this cluster this row is dsi/1.1p1, not the 1.2 front end:
 * under ../1.2/sp2 the same C compiles to 132 bytes.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_ConvertUcs2ToSjis.c \
 *       --func BUTTON_MAN_ConvertUcs2ToSjis --addr 0x02052274 --cc 1.1p1 --arm
 */
void BUTTON_MAN_ConvertUcs2ToSjis(u8 *a, u8 *b, u32 n)
{
    u32 scratch;
    u32 z;
    u32 i;
    u32 j;

    i = 0;
    j = 0;
    if (n == 0)
        return;
    z = i;
    do {
        scratch = z;
        if (BUTTON_MAN_Ucs2CharToSjis((u16 *)(a + i * 2), (char *)(b + j), &scratch) == 1)
            j += 2;
        else
            j += 1;
        i++;
        if (scratch == 1)
            return;
    } while (i < n);
}

/*
 * The per-character encoder behind BUTTON_MAN_ConvertUcs2ToSjis: one UCS-2 code unit to
 * Shift-JIS.  The terminator (STRBUF_GetEosChar's value) writes a NUL and raises
 * *stop; printable ASCII is copied; hiragana, both katakana runs and the
 * full-width A-Z, a-z and 0-9 are offset into their Shift-JIS rows and
 * written high byte first; the long-vowel mark, U+8140 (passed through as the
 * SJIS ideographic space), and the two gender signs are special-cased; any
 * other code writes '?'.  Returns 1 when two bytes were written.
 *
 * Levers: dst is plain (signed) char -- the 0x81 lead byte is `mvn r1,#0x7e`
 * and the trail bytes 0x89/0x8a are derived from it by `add` -- and the
 * result `two` is declared BEFORE the character (declaration order decides
 * the r4/r5 colours).  dsi/1.1p1; 1.2 and 2.0 are 170-220 bytes longer.
 */
int BUTTON_MAN_Ucs2CharToSjis(u16 *src, char *dst, u32 *stop)
{
    int two = 0;
    u16 c = *src;
    u16 v;

    if (c == STRBUF_GetEosChar()) {
        *dst = 0;
        if (stop != 0)
            *stop = 1;
    } else if (c >= 0x20 && c <= 0x7e) {
        *dst = c;
    } else if (c >= 0x3041 && c <= 0x3093) {
        v = c + 0x525E;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0x30A1 && c <= 0x30DF) {
        v = c + 0x529F;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0x30E0 && c <= 0x30F3) {
        v = c + 0x52A0;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF21 && c <= 0xFF3A) {
        v = c - 0x7CC1;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF41 && c <= 0xFF5A) {
        v = c - 0x7CC0;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c >= 0xFF10 && c <= 0xFF19) {
        v = c - 0x7CC1;
        dst[0] = (v & 0xff00) >> 8;
        dst[1] = v;
        two = 1;
    } else if (c == 0x30FC) {
        dst[0] = 0x81;
        dst[1] = 0x5B;
        two = 1;
    } else if (c == 0x8140) {
        dst[0] = 0x81;
        dst[1] = 0x40;
        two = 1;
    } else if (c == 0x2642) {
        dst[0] = 0x81;
        dst[1] = 0x89;
        two = 1;
    } else if (c == 0x2640) {
        dst[0] = 0x81;
        dst[1] = 0x8A;
        two = 1;
    } else {
        *dst = '?';
    }
    return two;
}
