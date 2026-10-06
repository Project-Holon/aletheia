/*
 * file:     wipe_sub_p12.c
 * unit:     yes
 * function: func_0202384C, func_020238B4, func_0202390C
 * address:  0x0202384C
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
 *   sub_02022D88   0x02022D88  thumb
 *   func_020237B8  0x020237B8  thumb
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02023964  0x02023964  thumb
 *   func_02023A50  0x02023A50  thumb
 *   func_02023AAC  0x02023AAC  thumb
 *   func_02022DCC  0x02022DCC  thumb
 *   func_020307B0  0x020307B0  arm
 */
struct Obj;
struct Desc;
struct Wipe;
typedef signed short s16;

typedef signed int   s32;

typedef unsigned int u32;

struct Wipe {
    u32 f00;
    u32 f04;
    u32 f08;
    s32 f0c;      /* 0x0c */
    s32 f10;      /* 0x10 */
    s32 f14;      /* 0x14  half-height of the mirrored band */
};

struct Buf {
    s16 pad000[0x180];
    s16 left[0xC0];   /* 0x300 */
    s16 right[0xC0];  /* 0x480 */
};

typedef unsigned short u16;

struct Task_020238B4 {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    void *obj;    /* 0x14 */
    u32   f18;
    u32   f1c;
    u32   f20;    /* 0x20 */
};

typedef unsigned char  u8;

struct Obj {
    u32 pad000[0xc9];
    u32 f324;     /* 0x324 */
    u32 f328;
    u32 f32c;     /* 0x32c */
};

struct Task_0202390C {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    struct Obj *obj;  /* 0x14 */
};

extern void *sub_02022D88(struct Obj *obj, u32 idx);
extern void func_020237B8(s32 a0, s32 a1, s32 a2, s32 a3, s32 *out0,
                          s32 *out1);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern void func_02023964(u8 *w, struct Desc *d, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 func_02023A50(struct Wipe *w);
extern void func_02023AAC(struct Obj *obj);
extern void func_02022DCC(u32 a0, void *a1, u32 a2);
extern u32 func_020307B0(void *p);


/*
 * Rebuilds the wipe's per-scanline window table, one row for each of the
 * screen's 0xC0 lines.  sub_02022D88 hands back the buffer whose two s16
 * arrays live at +0x300 (left edge) and +0x480 (right edge).  Inside the
 * band (f14, 2*f14] the pair is mirrored from row 2*f14 - y; everywhere
 * else it is computed through func_020237B8.
 *
 * Two facts closed it (the notes stood at 98 bytes against 104):
 *  - func_020237B8's THIRD argument is w->f14, the value still live in r2
 *    from the band test, not 0.  That was the "re-load" the notes chased.
 *  - The guard is an if / else-if / else chain with the call written out
 *    in BOTH outer arms; mwcc cross-jumps the two copies, leaving the
 *    `bgt` over a `b` at +0x16 and hoisting &l into r7
 *    (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * EXACT* only because the 102-byte body is followed by two bytes of
 * alignment padding before func_020238B4.
 */
void func_0202384C(struct Wipe *w)
{
    struct Buf *b;
    s32 y;
    s32 l;
    s32 r;

    y = 0;
    b = sub_02022D88((struct Obj *)w, 0);

    do {
        if (y <= w->f14) {
            func_020237B8(w->f0c, w->f10, w->f14, y, &l, &r);
        } else if (y <= w->f14 * 2) {
            l = b->left[w->f14 * 2 - y];
            r = b->right[w->f14 * 2 - y];
        } else {
            func_020237B8(w->f0c, w->f10, w->f14, y, &l, &r);
        }
        b->left[y] = (s16)l;
        b->right[y] = (s16)r;
        y = y + 1;
    } while (y < 0xC0);
}


/*
 * The constructor of the wipe task whose per-frame step is func_0202390C:
 * it allocates the 0x334-byte sub-object from the task's own heap id,
 * zeroes it, hands the task's five parameter words to func_02023964 and
 * advances the phase.  The sibling of func_02023464 (which builds the
 * 0x4c-byte object at the other end of the family) and of func_020235F0.
 *
 * 0x334 is past every Thumb immediate, and it is needed TWICE (the
 * allocation size and the memset length), so it is materialised once into
 * a callee-saved register (movs #0xcd / lsls #2) and reused rather than
 * spelled at each site; writing it as a literal at both sites costs a pool
 * word.  That is what makes r6 live across the first call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020238B4.c \
 *       --func func_020238B4 --addr 0x020238B4 --cc 1.1p1 --thumb
 */
void func_020238B4(struct Task_020238B4 *t, u32 a1)
{
    t->obj = func_02030734((u16)t->f20, 0x334, 0, (const char *)0x020A7450, 0x1354);
    func_02082BCC(t->obj, 0, 0x334);
    func_02023964(t->obj, (struct Desc *)a1, t->f04, t->f08, t->f10, t->f18, t->f1c,
                  t->f20);
    t->phase = t->phase + 1;
}


/*
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
u32 func_0202390C(struct Task_0202390C *t)
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
