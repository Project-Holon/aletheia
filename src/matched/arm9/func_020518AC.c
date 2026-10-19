/*
 * function: PARTICLE_EMITTER_FindBehaviorData
 * address:  0x020518AC
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SPL_EMITTER_LerpVec  0x02057EF8  arm
 *   SPL_EMITTER_InterpTarget  0x02057F8C  arm
 *   SPL_EMITTER_BuildFrame  0x020580A8  arm
 *   SPL_EMITTER_AddScaledVec  0x02058180  arm
 *   SPL_EMITTER_UpdateNode  0x02058204  arm
 *   SPL_EMITTER_AddVec  0x020582CC  arm
 *
 * Linear search of the block at obj+0x20 for the first 8-byte entry whose
 * first word is the handler address selected by `kind`, returning that
 * entry's second word (or NULL).  The six handlers are the 3D-rig rows at
 * 0x02057EF8..0x020582CC, all pool words and all attested by the sibling
 * pool at 0x02052DB0.
 *
 * Two tells decide the shape.  Declaring the index BEFORE the count is what
 * puts the count in r4 and the index in lr (declaration-order-decides-which-
 * register-a-local-gets).  And the image's `adds ip, r5, lr, lsl #3` / `beq`
 * pair at +0040 is a redundant null test on the entry pointer: the `adds`
 * form only appears when the source writes `if (e == 0) continue;`, which
 * folds into the address computation.  Without it the switch is four bytes
 * shorter and every branch target shifts.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_EMITTER_FindBehaviorData.c \
 *       --func PARTICLE_EMITTER_FindBehaviorData --addr 0x020518AC --cc 1.1p1 --arm
 */
#include "../include/Obj16187.h"

typedef unsigned short u16;

struct Ent {
    void *fn;
    void *data;
};

struct Blk {
    char pad[0x18];
    struct Ent *ents;
    u16 count;
};

typedef unsigned char  u8;
struct A;
struct B;
struct C;
struct Obj;
struct S;
struct Src;
extern void SPL_EMITTER_LerpVec(struct A *a, struct B *b);
extern void SPL_EMITTER_InterpTarget(struct A *a, struct S *s, int unused, struct C *c);
extern void SPL_EMITTER_BuildFrame(struct Obj *o, u8 *dst);
extern void SPL_EMITTER_AddScaledVec(struct A *a, struct B *b, volatile int *c);
extern void SPL_EMITTER_UpdateNode(struct Obj *o, struct Src *s, int *dst);
extern void SPL_EMITTER_AddVec(struct Obj *o, void *s, int *dst);

void *PARTICLE_EMITTER_FindBehaviorData(void *obj, int kind)
{
    struct Blk *b = *(struct Blk * *)&((struct Obj16187 *)obj)->f20;
    int i;
    int n = b->count;

    if (n == 0)
        return 0;

    for (i = 0; i < n; i++) {
        struct Ent *e = &b->ents[i];
        if (e == 0)
            continue;
        switch (kind) {
        case 0:
            if (e->fn == (void *)SPL_EMITTER_AddVec)
                return e->data;
            break;
        case 1:
            if (e->fn == (void *)SPL_EMITTER_UpdateNode)
                return e->data;
            break;
        case 2:
            if (e->fn == (void *)SPL_EMITTER_AddScaledVec)
                return e->data;
            break;
        case 3:
            if (e->fn == (void *)SPL_EMITTER_BuildFrame)
                return e->data;
            break;
        case 4:
            if (e->fn == (void *)SPL_EMITTER_InterpTarget)
                return e->data;
            break;
        case 5:
            if (e->fn == (void *)SPL_EMITTER_LerpVec)
                return e->data;
            break;
        default:
            return 0;
        }
    }
    return 0;
}
