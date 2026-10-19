/*
 * function: SPL_EMITTER_AllocResource
 * address:  0x02052634
 * packet:   pkt_0205250C
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SPLList_PopFront   0x02058380  arm
 *   SPL_EMITTER_SetupResource   0x02053A60  arm
 *   SPLList_PushFront   0x020583CC  arm
 *
 * Promote-first callee of src/pending/PARTICLE_StartEffect.c (parks lane 2).
 * Pops one node off the list at p+0x10, runs the loader for the node and
 * (p->f28 + (arg1 << 5), arg2), then hands the node to SPLList_PushFront; the
 * node is discarded when bit 14 of the word at *(node->f20) is set.
 *
 * Built by the 1.2 front end, not dsi/1.1p1: the epilogue is the ARMv4T
 * style `pop {r4-r7, lr}; bx lr` *and* the frame pads with `sub sp, sp, #4`
 * instead of spending a dead `push {r3}` on the alignment word, which is
 * the small-frame signature in
 * docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md.
 * On dsi/1.1p1 this same C is 4 bytes short (112) at every -proc value.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_AllocResource.c \
 *       --func SPL_EMITTER_AllocResource --addr 0x02052634 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
#include "../include/Obj00077.h"
#include "../include/Obj11462.h"

typedef unsigned int u32;

struct List;
struct Node;
extern struct Node *SPLList_PopFront(struct List *list);
struct Cfg;
struct Obj;
struct Vec3;
extern void SPL_EMITTER_SetupResource(volatile struct Obj *o, struct Cfg *cfg, const struct Vec3 *pos);
extern void SPLList_PushFront(volatile struct List *list, volatile struct Node *node);

int SPL_EMITTER_AllocResource(char *p, int b, int c)
{
    void *r = 0;

    if (((struct Obj11462 *)p)->f10 != 0) {
        r = SPLList_PopFront((struct List *)(p + 0x10));
        SPL_EMITTER_SetupResource(r, (void *)(((struct Obj11462 *)p)->f28 + (b << 5)), (const struct Vec3 *)c);
        SPLList_PushFront((volatile struct List *)(p + 4), r);
        if ((*(u32 *)(*(u32 *)(*(u32 *)&((struct Obj00077 *)r)->f20)) << 0x11 >> 0x1f) != 0)
            r = 0;
    }
    return (int)r;
}
