/*
 * function: WIPE_SUB_BoxMain
 * address:  0x020234C0
 * packet:   pkt_02022F60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIPE_SUB_BoxStep  0x02023568  thumb
 *   WIPE_SUB_RequestWindowEnd  0x02022DCC  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * The per-frame step of the wipe/transition task set up at 0x02023464.
 * The task block keeps its phase at +0x0c and the sub-object it allocated
 * at +0x14.  Phase 1 polls WIPE_SUB_BoxStep and, once that answers 1, hands
 * the sub-object's +0x44 field to WIPE_SUB_RequestWindowEnd and advances; phase 2
 * frees the sub-object (func_020307B0), clears the slot and advances;
 * phase 3 is the terminal phase and is the only one that answers 1, which
 * is how the caller learns the transition has finished.  Phase 0 and any
 * other value answer 0 and do nothing.
 *
 * THE LEVER, and it is shared with WIPE_SUB_FadeMain, WIPE_SUB_ShutterMain and
 * WIPE_SUB_BoxMain (all three sat at exactly two bytes out until it was
 * found; WIPE_SUB_CircleMain in src/matched had it right all along and is where
 * it was read from).  Phase 2 assigns the result variable 1 as well,
 * immediately before its `break`:
 *
 *     case 2:  ... t->obj = 0; ret = 1; break;
 *     case 3:  ret = 1; break;
 *
 * The assignment is semantically dead -- the caller re-polls and phase 3
 * answers 1 on the next frame anyway -- but it is what makes phase 2's
 * `break` compile to a branch onto phase 3's own `movs r4, #1` instead of
 * onto the shared tail: the compiler cross-jumps the two identical
 * assignments and phase 2's exit lands on the surviving copy.  Written
 * without it the function is right in every other byte and the one branch
 * displacement is two too large.  Nothing else reaches it: 131 single
 * mutations and 3000 annealing compiles of tools/permuter.py left the
 * residue untouched (it is a cross-jumping decision, not an allocation
 * one), and every other switch spelling tried -- goto into phase 3, a
 * reordered case set, default before case 3, an if/else-if chain, an
 * added empty case -- is the same two bytes out or worse.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_BoxMain.c \
 *       --func WIPE_SUB_BoxMain --addr 0x020234C0 --cc 1.1p1 --thumb
 */
#include "../include/Obj00862.h"

typedef unsigned int  u32;

struct Task {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;   /* 0x0c */
    u32   f10;     /* 0x10 */
    void *obj;     /* 0x14 */
    u32   f18;     /* 0x18 */
};

struct Obj;
extern u32 WIPE_SUB_BoxStep(struct Obj *o);
extern void WIPE_SUB_RequestWindowEnd(u32 a0, void *a1, u32 a2);
extern u32 func_020307B0(void *p);

u32 WIPE_SUB_BoxMain(struct Task *t)
{
    void *obj;
    u32   ret;

    ret = 0;
    obj = t->obj;

    switch (t->phase) {
    case 1:
        if (WIPE_SUB_BoxStep(obj) == 1) {
            WIPE_SUB_RequestWindowEnd(((struct Obj00862 *)obj)->f44, (void *)t->f18, t->f10);
            t->phase = t->phase + 1;
        }
        break;
    case 2:
        func_020307B0(obj);
        t->phase = t->phase + 1;
        t->obj = 0;
        ret = 1;
        break;
    case 3:
        ret = 1;
        break;
    default:
        break;
    }

    return ret;
}
