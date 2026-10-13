/*
 * function: WIPE_SUB_FadeMain
 * address:  0x02022A44
 * packet:   pkt_02022940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SUB_FadeStep  0x02022A88  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_020307B0  0x020307B0  arm
 *
 * The per-frame step of a wipe task, the sibling of WIPE_SUB_BoxMain at the
 * other end of the family: the same four-phase switch over the task's
 * +0x0c, the same sub-object slot at +0x14, and the same terminal phase 3
 * that is the only one to answer 1.  Phase 1 polls WIPE_SUB_FadeStep and
 * advances when it answers 1; phase 2 releases the sub-object's +0x20
 * handle through func_02030EAC, frees the object itself, clears the slot
 * and advances.
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
 *   python tools/match.py one --src src/matched/WIPE_SUB_FadeMain.c \
 *       --func WIPE_SUB_FadeMain --addr 0x02022A44 --cc 1.1p1 --thumb
 */

typedef unsigned int  u32;

struct Obj {
    u32 pad00[8];
    u32 f20;      /* 0x20 */
};

struct Task {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    struct Obj *obj;  /* 0x14 */
};

struct AnimStep;
extern int WIPE_SUB_FadeStep(struct AnimStep *p);
struct Node;
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);

u32 WIPE_SUB_FadeMain(struct Task *t)
{
    struct Obj *obj;
    u32         ret;

    ret = 0;
    obj = t->obj;

    switch (t->phase) {
    case 1:
        if (WIPE_SUB_FadeStep((struct AnimStep *)obj) == 1) {
            t->phase = t->phase + 1;
        }
        break;
    case 2:
        func_02030EAC((struct Node *)obj->f20);
        func_020307B0(t->obj);
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
