/*
 * file:     wipe_sub_p08.c
 * unit:     yes
 * function: func_020225F0, func_020225F4, func_02022608, func_0202262C, func_02022640, func_02022670, func_020226A0, func_020226E0, func_020226FC, func_0202271C, func_02022758
 * address:  0x020225F0
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
 *   func_020222CC  0x020222CC  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_0202262C  0x0202262C  thumb
 *   func_0202223C  0x0202223C  thumb
 *   func_02022224  0x02022224  thumb
 *   func_020229A4  0x020229A4  thumb
 *   func_02022A44  0x02022A44  thumb
 *   func_020222A8  0x020222A8  thumb
 *   func_020238B4  0x020238B4  thumb
 *   func_0202390C  0x0202390C  thumb
 *   d_0209F570     0x0209F570  data
 *   g_020A73D0     0x020A73D0  data
 *   g_wipe_slot0   0x020A73D0  data
 *   d_0209F56C     0x0209F56C  data
 */
struct Node;
struct Q;
struct Task;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct TextObj {
    u8  pad00[0x150];
    u16 f150;
};

struct Sub {
    u8  pad00[0x24];
    u16 unk24;
    u8  pad26[2];
    u32 unk28;
};

struct Obj_0 {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x150 - 0x10];
    u16 unk150;
};

typedef void (*Task)(void *p);

struct Screen_02022640 {
    u8    pad00[0x24];
    u16   f24;
    u16   f26;
    void *f28;
    void *f2C;
};

struct Screen_02022670 {
    u8    pad00[0x10];
    void *f10;
    u8    pad14[0x10];
    u16   f24;
    u16   f26;
    u32   f28;
    void *f2C;
};

struct Obj_1 {
    u8  pad00[0xC];
    u32 unk0C;
    u8  pad10[0x28 - 0x10];
    u32 unk28;
    u32 unk2C;
};

struct T {
    u8  pad00[0xc];
    u32 f0c;
    u8  pad10[0x14];
    u16 f24;
    u8  pad26[2];
    u32 f28;
    u32 f2c;
};

struct G {
    u32 f00;
    u8  pad04[0xc];
    u32 f10;
    u8  pad14[0xc];
    u32 f20;
    u32 pad24;
    u32 f28;
};

extern void func_020222CC(u32 which, int brightness);
extern void func_02030EAC(struct Node *n);
extern void func_020056A0(Task fn, void *arg, u32 prio);
extern void func_0202262C(void *obj, struct Q *q);
extern void func_0202223C(u32 a, u32 color);
extern u32 func_02022224(void *win);
extern void MI_CpuFill8(void *dst, u8 data, u32 size);
extern void func_020229A4(struct Task *t, u32 dir);
extern u32 func_02022A44(struct Task *t);
extern void func_020222A8(u32 v);
extern void func_020238B4(struct Task *t, u32 a1);
extern u32 func_0202390C(struct Task *t);
void func_020226A0(u8 *p);
void func_020225F0(void);
extern const u32 d_0209F570[];
extern struct G g_020A73D0;
extern struct G g_wipe_slot0;
extern const u32 d_0209F56C[];


/*
 * The do-nothing default handler the two-entry callback table in
 * func_02022458 is initialised with: a single `bx lr` plus two bytes of
 * section padding.  It has no branch reference anywhere in the image, only
 * the ABS32 pool word at 0x02022474 that takes its address, so an EXACT
 * entry here is what lets func_02022458 resolve that pool word on the
 * `matched` class.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_020225F0.c \
 *       --addr 0x020225F0 --thumb
 */
void func_020225F0(void)
{
}



/*
 * Sentinel resolver for the dual-screen text cluster: 0xFFFF in the caller's
 * value means "use the object's own default", which lives in the u16 at
 * +0x150, the same sentinel colour slot func_0202223C and func_02022268 read.
 * Any other value passes through untouched, which is what fixes the return
 * type as u32 rather than u16: the pass-through arm carries no truncation.
 *
 * The 0xFFFF compare constant costs a pool word rather than a movs/lsls pair
 * because it is compared, not materialised into a store.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020225F4.c \
 *       --func func_020225F4 --addr 0x020225F4 --cc 1.1p1 --thumb
 */
u32 func_020225F4(struct TextObj *obj, u32 value)
{
    if (value == 0xFFFF)
        value = obj->f150;
    return value;
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * func_02022608 picks one of two sub-objects at fixed offsets (0x14, 0x44)
 * of its argument depending on a mode field at +0xc, then returns a
 * halfword out of that sub-object when its own flag at +0x28 is 1, or
 * else falls back to a halfword 0x150 bytes into the *original* argument
 * (0x15 << 4), untouched by the sub-object selection.
 *
 * func_02022628 alone comes out EXACT* against `one`: its own extent runs
 * two bytes into the ordinary linker fill in front of func_0202262C, a
 * real, separately meaningful function.  Pairing the two in one
 * translation unit lets `tu` lay out both sections with that fill in
 * between, which reproduces cleanly.
 *
 * func_0202262C reads a field 0x10 bytes into its second argument and
 * forwards it, with a fixed 0, to func_020222CC (whose own second
 * argument it never reads: see src/matched/func_020222CC.c), then calls
 * func_02030EAC on the first argument.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02022608.c \
 *       --addr 0x02022608 --thumb
 */
u16 func_02022608(struct Obj_0 *p)
{
    struct Sub *b;

    if (p->unk0C == 1) {
        b = (struct Sub *)((u8 *)p + 0x14);
    } else {
        b = (struct Sub *)((u8 *)p + 0x44);
    }
    if (b->unk28 == 1) {
        return b->unk24;
    }
    return p->unk150;
}

struct Q {
    u8  pad[0x10];
    u32 unk10;
};



void func_0202262C(void *obj, struct Q *q)
{
    func_020222CC(q->unk10, 0);
    func_02030EAC(obj);
}



/*
 * Arms the deferred screen task for one of the two sub-objects func_0202208C
 * built, but only for a screen that is still idle: the task handle at +0x28
 * must be null, the resolved sentinel value at +0x24 must be either the
 * pass-through 0x7FFF or zero, and the second handle at +0x2C must be null
 * too.  All three rejections share one epilogue, so the guard is written as a
 * single conjunction rather than a chain of early returns; see
 * docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022640.c \
 *       --func func_02022640 --addr 0x02022640 --cc 1.1p1 --thumb
 */
void func_02022640(struct Screen_02022640 *s)
{
    if (s->f28 == 0 && (s->f24 == 0x7FFF || s->f24 == 0) && s->f2C == 0)
        func_020056A0((Task)func_0202262C, s, 1 << 10);
}


/*
 * Per-screen finaliser, the mirror of the arming path in func_02022640: it
 * runs only while the screen is in state 1, its resolved sentinel value at
 * +0x24 is the pass-through 0x7FFF or zero, and the second handle at +0x2C is
 * still null.  It then closes the screen's window through the pointer at
 * +0x10, first the flush at 0x0202223C and then the release thunk at
 * 0x02022224.
 *
 * The +0x10 field is re-read for the second call rather than kept in a
 * register, because the first call can alias it; a cached local would drop
 * the second `ldr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022670.c \
 *       --func func_02022670 --addr 0x02022670 --cc 1.1p1 --thumb
 */
void func_02022670(struct Screen_02022670 *s)
{
    if (s->f28 == 1 && (s->f24 == 0x7FFF || s->f24 == 0) && s->f2C == 0) {
        func_0202223C((u32)s->f10, s->f24);
        func_02022224(s->f10);
    }
}


/*
 * A whole translation unit, matched as one byte range.
 *
 * func_020226A0 is five back-to-back MI_CpuFill8 zero-fills over five
 * sub-ranges of one object (sizes 0x14, 0x30, 0x30, 0x18, 0xC0 at offsets
 * 0, 0x14, 0x44, 0x74, 0x8C); it is one of the "0x0209F5xx/0x0209F6xx"
 * cluster's neighbours and clears the object the setup functions in
 * src/matched/func_02022804.c and siblings configure.
 *
 * func_020226E0 checks a delegate pointer at +0xc, the same guard shape as
 * that cluster: when set, the call forwards to func_02022A44 and returns
 * its result; the fall-through has to be written on the guard's
 * complement (`== 0`) with the delegate call left unconditional after it,
 * or the two blocks come out in the wrong order.  The fall-through sets
 * the flag pair at +0x28 and +0x2c to (1, 1) and calls func_020229A4(p, 1).
 *
 * func_020226FC, immediately after this range, is the same shape again
 * with (0, 1) and mode 0 (src/matched/func_020226FC.c); it is kept in its
 * own file specifically so that its calls to func_020229A4 and
 * func_02022A44 stay outside this range and keep attesting them, and vice
 * versa (docs/MATCHING.md, "the label class" and "the pairwise case across
 * two files").  Bundling all three into one file drops both relocations to
 * MATCH, because each one's only other witness is then inside the same
 * compared range.
 *
 * func_020226A0 alone comes out EXACT* against `one`: its own extent runs
 * two bytes into the ordinary linker fill in front of func_020226E0, which
 * is a real, separately-matched function and not an unlabelled follower.
 * Pairing the two in one translation unit lets `tu` lay out both sections
 * with that fill in between, which reproduces cleanly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020226A0.c \
 *       --addr 0x020226A0 --thumb
 */
void func_020226A0(u8 *p)
{
    MI_CpuFill8(p, 0, 0x14);
    MI_CpuFill8(p + 0x14, 0, 0x30);
    MI_CpuFill8(p + 0x44, 0, 0x30);
    MI_CpuFill8(p + 0x74, 0, 0x18);
    MI_CpuFill8(p + 0x8C, 0, 0xC0);
}


u32 func_020226E0(struct Obj_1 *p)
{
    if (p->unk0C == 0) {
        p->unk28 = 1;
        p->unk2C = 1;
        func_020229A4((struct Task *)p, 1);
        return 0;
    }
    return func_02022A44((struct Task *)p);
}


/*
 * Same shape as func_020226E0 in src/matched/unit_020226A0.c, and kept in
 * its own file for the same reason: its calls to func_020229A4 and
 * func_02022A44 have to stay outside that unit's compared range to attest
 * its calls, and vice versa.  Sets the flag pair at +0x28 and +0x2c to
 * (0, 1) instead of (1, 1) and calls func_020229A4(p, 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020226FC.c \
 *       --func func_020226FC --addr 0x020226FC --cc 1.1p1 --thumb
 */
u32 func_020226FC(struct Obj_1 *p)
{
    if (p->unk0C == 0) {
        p->unk28 = 0;
        p->unk2C = 1;
        func_020229A4((struct Task *)p, 0);
        return 0;
    }
    return func_02022A44((struct Task *)p);
}


/*
 * wipe.c (docs/families/wipe.h): the slot-0 member of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC (template: func_02022758).
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 9 out under 1.1p1 and 1 out
 * under every 2.0 build, docs/notes/pkt_0202271C.c.txt): the pool carries
 * 0x020A73D0 TWICE (0x02022750 for the store, 0x02022754 for the argument),
 * so two source-level names were in play. The slot store goes through
 * g_020A73D0 and the argument is a second extern, g_wipe_slot0, at the same
 * address. With one name 1.1p1 CSEs both uses into r5 (push {r3, r4, r5,
 * lr}); with two it reloads each from its own pool word under push {r4, lr}.
 * Same finding as src/matched/func_02023F98.c in the same module, whose
 * header explains why the bytes fix the number of names but not whether the
 * original had one object or two declarations of it. For the other three
 * slots the two uses differ by the slot offset, so one name suffices there.
 */
void func_0202271C(struct T *p)
{
    if (p->f0c == 0) {
        g_020A73D0.f00 = (u32)d_0209F570;
        func_020222A8(p->f24);
        func_020238B4((struct Task *)p, (u32)(&g_wipe_slot0));
        p->f28 = 1;
        p->f2c = 0;
    } else {
        func_0202390C((struct Task *)p);
    }
}


/*
 * wipe.c (docs/families/wipe.h): one of the four setup steps
 * 0x0202271C/0x02022758/0x02022790/0x020227CC.  Each installs a rodata
 * word table (0x0209F568..0x0209F574, four u32 words, NOT ARM code: the
 * old headers declared them as arm functions, which is why they had no
 * witness) into one slot of the wipe state at 0x020A73D0, then hands that
 * slot to func_020238B4.  Declared as data, the table address is attested
 * sole-ref/self.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022758.c  *       --func func_02022758 --addr 0x02022758 --thumb --cc 1.1p1
 */
void func_02022758(struct T *p)
{
    if (p->f0c == 0) {
        g_020A73D0.f10 = (u32)d_0209F56C;
        func_020222A8(p->f24);
        func_020238B4((struct Task *)p, (u32)(&g_020A73D0.f10));
        p->f28 = 0;
        p->f2c = 0;
    } else {
        func_0202390C((struct Task *)p);
    }
}
