/*
 * function: SPL_EMITTER_AllocResourceEx
 * address:  0x020525A0
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
 * Promote-first callee of src/pending/PARTICLE_StartEffectWithCallback.c (parks lane 2).
 * Same shape as its neighbour SPL_EMITTER_AllocResource with two extra steps: the
 * loader takes the address of a twelve-byte zeroed scratch block as its
 * third argument, and a non-null third parameter is called back with the
 * popped node before SPLList_PushFront runs.
 *
 * Built by the 1.2 front end (ARMv4T-style `pop {... lr}; bx lr` epilogue
 * and a `sub sp, sp, #4` alignment word), see
 * docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_AllocResourceEx.c \
 *       --func SPL_EMITTER_AllocResourceEx --addr 0x020525A0 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
#include "../include/Obj00077.h"
#include "../include/Obj11461.h"

typedef unsigned int u32;

struct Scratch {
    u32 a;
    u32 b;
    u32 c;
};

struct Cfg;
struct List;
struct Node;
struct Obj;
struct Vec3;
extern struct Node *SPLList_PopFront(struct List *list);
extern void SPL_EMITTER_SetupResource(volatile struct Obj *o, struct Cfg *cfg, const struct Vec3 *pos);
extern void SPLList_PushFront(volatile struct List *list, volatile struct Node *node);

int SPL_EMITTER_AllocResourceEx(char *p, int b, void (*fn)(void *))
{
    void *r = 0;

    if (((struct Obj11461 *)p)->f10 != 0) {
        struct Scratch scratch = { 0, 0, 0 };

        r = SPLList_PopFront((struct List *)(p + 0x10));
        SPL_EMITTER_SetupResource(r, (void *)(((struct Obj11461 *)p)->f28 + (b << 5)), (const struct Vec3 *)(&scratch));
        if (fn != 0)
            fn(r);
        SPLList_PushFront((volatile struct List *)(p + 4), r);
        if ((*(u32 *)(*(u32 *)(*(u32 *)&((struct Obj00077 *)r)->f20)) << 0x11 >> 0x1f) != 0)
            r = 0;
    }
    return (int)r;
}
