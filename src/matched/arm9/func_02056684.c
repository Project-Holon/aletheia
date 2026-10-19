/*
 * function: SPLEmitter_EmitChildren
 * address:  0x02056684
 * packet:   pkt_02052F58
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * symbols:
 *   SPLList_PopFront  0x02058380  arm
 *   SPLList_PushFront  0x020583CC  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   g_02146A8C     0x02146A8C  data
 * status:   EXACT
 *
 * Particle spawn for the rig emitter (the SPL-style particle system this
 * cluster renders; docs/families/cluster_02052F58.h).  For each of
 * desc->f0c particles: pop one from the free list (SPLList_PopFront), push it
 * on the owner's live list at +0x14 (SPLList_PushFront), copy the emitter
 * position, set velocity = FX_Mul(emitter velocity, FX_Mul(f08 << 12, 0x10))
 * plus a random term in [-f02, f02) per axis from the LCG at 0x02146A8C
 * (0x5EEDF715 / 0x1B0CB173, the same generator SPL_EMITTER_UpdateNode uses), and
 * fill scale, colour, the 5-bit tile fields, the rotation pair (3-way
 * switch on desc bits 3..4), life and the two 0xFFFF reciprocal rates.
 *
 * LOAD-BEARING SHAPES (wave 8, each measured):
 *   1. The random term is a MACRO whose rng update is an assignment
 *      expression used as a value, `(g = g * A + C) >> 23`.  The same body
 *      as a static inline function (or a separate Rand() inline) is 792
 *      bytes against 800 and 534 out: the inline's statement boundary moves
 *      the whole velocity block.  The macro puts it at 52 out.
 *   2. `(s32)((u32)e->f24 >> 1)`: lsr, not asr, but _s32_div_f, not
 *      _u32_div_f.  An unsigned dividend picks the unsigned helper.
 *   3. `s = (e->f30 * e->f34) >> 12` bound to a local, operands in that
 *      order (40 out without it).
 *   4. `struct Ptcl *p;` declared FIRST, before `d`.  With p declared in the
 *      loop body (or after d) the two pointers swap r6/r7 and the last 40
 *      bytes stay out; tools/permuter.py --mode hill (222 singles) could not
 *      move it -- a declaration residue, as docs/notes/permuter.md predicts.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPLEmitter_EmitChildren.c \
 *       --func SPLEmitter_EmitChildren --addr 0x02056684 --arm --cc ../1.2/sp2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef s32 fx32;

struct VecFx32 { fx32 x, y, z; };

struct PBf { u16 b0 : 5; u16 b5 : 5; u16 b10 : 6; };

struct Ptcl {
    u8 pad00[0x08];
    struct VecFx32 pos;     /* +0x08 */
    struct VecFx32 vel;     /* +0x14 */
    u16 f20;
    s16 f22;
    u16 f24;
    u16 f26;
    u16 f28;
    u16 f2a;
    u8 f2c;
    u8 f2d;
    struct PBf w;           /* +0x2e */
    fx32 f30;
    u16 f34;
    u16 f36;
    struct VecFx32 f38;
};

struct DescBf { u16 b0 : 3; u16 sel : 2; u16 b5 : 1; u16 col : 1; u16 rest : 9; };

struct Desc {
    struct DescBf f;        /* +0x00 */
    s16 f02;
    u8 pad04[2];
    u16 f06;
    u8 f08;
    u8 f09;
    u16 f0a;
    u8 f0c;
    u8 pad0d[2];
    u8 f0f;
};

struct Emt {
    u8 pad00[0x08];
    struct VecFx32 pos;     /* +0x08 */
    struct VecFx32 vel;     /* +0x14 */
    u16 f20;
    s16 f22;
    u16 f24;
    u8 pad26[0x08];
    struct PBf w;           /* +0x2e */
    fx32 f30;
    s16 f34;
    u16 f36;
    struct VecFx32 f38;
};

struct SubX { u8 pad00[0x14]; struct Desc *desc; };
struct Owner { u8 pad00[0x14]; u8 list[0x0c]; struct SubX *x; };

extern u32 g_02146A8C;
struct List;
struct Node;
extern struct Node *SPLList_PopFront(struct List *list);
extern void SPLList_PushFront(volatile struct List *list, volatile struct Node *node);

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800) >> 12);
}

#define RandRange(v) (((v) * (s32)((g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173) >> 23) - ((v) << 8)) >> 8)

void SPLEmitter_EmitChildren(struct Emt *e, struct Owner *o, void *pool)
{
    struct Ptcl *p;
    struct Desc *d = o->x->desc;
    fx32 scale = FX_Mul(d->f08 << 12, 0x10);
    s32 i;
    for (i = 0; i < d->f0c; i++) {
        p = (struct Ptcl *)SPLList_PopFront(pool);
        if (p == 0)
            return;
        SPLList_PushFront((volatile struct List *)o->list, (volatile struct Node *)p);
        p->pos = e->pos;
        p->vel.x = FX_Mul(e->vel.x, scale) + RandRange(d->f02);
        p->vel.y = FX_Mul(e->vel.y, scale) + RandRange(d->f02);
        p->vel.z = FX_Mul(e->vel.z, scale) + RandRange(d->f02);
        p->f38 = e->f38;
        {
            s32 s = (e->f30 * e->f34) >> 12;
            p->f30 = s * (d->f09 + 1) >> 6;
        }
        p->f34 = 0x1000;
        if (d->f.col)
            p->f36 = d->f0a;
        else
            p->f36 = e->f36;
        p->w.b0 = (u16)((e->w.b0 * (e->w.b5 + 1)) >> 5);
        p->w.b5 = 0x1f;
        switch (d->f.sel) {
        case 0:
            p->f20 = 0;
            p->f22 = 0;
            break;
        case 1:
            p->f20 = e->f20;
            p->f22 = 0;
            break;
        case 2:
            p->f20 = e->f20;
            p->f22 = e->f22;
            break;
        }
        p->f24 = d->f06;
        p->f26 = 0;
        p->f2c = d->f0f;
        p->f28 = 0xffff / (s32)((u32)e->f24 >> 1);
        p->f2a = 0xffff / e->f24;
        p->f2d = 0;
    }
}
