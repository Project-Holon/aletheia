/*
 * function: func_0202390C
 * address:  0x0202390C
 * packet:   pkt_0202384C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02023A50  0x02023A50  thumb
 *   func_02023AAC  0x02023AAC  thumb
 *   func_02022DCC  0x02022DCC  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * The per-frame step of a wipe task, the third of the family's four
 * identical phase machines (func_02022A44, func_020234C0, this one and
 * func_020238B4): the same switch over the task's +0x0c, the same
 * sub-object slot at +0x14, the same terminal phase 3.
 *
 * The two far fields at +0x324 and +0x32c are past every Thumb immediate
 * reach, so both are addressed with a register offset built once
 * (movs #0xc9 / lsls #2 = 0x324) and then bumped by 8 for the second
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md); reading them as
 * two separate far offsets would cost a second pool word.
 *
 * THE LEVER, and it is shared with func_02022A44, func_0202390C and
 * func_020234C0 (all three sat at exactly two bytes out until it was
 * found; func_0202363C in src/matched had it right all along and is where
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
 *   python tools/match.py one --src src/matched/func_0202390C.c \
 *       --func func_0202390C --addr 0x0202390C --cc 1.1p1 --thumb
 */

typedef unsigned int  u32;

struct Obj {
    u32 pad000[0xc9];
    u32 f324;     /* 0x324 */
    u32 f328;
    u32 f32c;     /* 0x32c */
};

struct Task {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    struct Obj *obj;  /* 0x14 */
};

struct Wipe;
extern u32 func_02023A50(struct Wipe *w);
extern void func_02023AAC(struct Obj *obj);
extern void func_02022DCC(u32 a0, void *a1, u32 a2);
extern void func_020307B0(void *p);

u32 func_0202390C(struct Task *t)
{
    struct Obj *obj;
    u32         ret;

    ret = 0;
    obj = t->obj;

    switch (t->phase) {
    case 1:
        if (func_02023A50((struct Wipe *)obj) == 1) {
            func_02022DCC(obj->f324, (void *)obj->f32c, t->f10);
            t->phase = t->phase + 1;
        }
        break;
    case 2:
        func_02023AAC(obj);
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
