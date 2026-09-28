/*
 * function: func_020229A4
 * address:  0x020229A4
 * packet:   pkt_02022940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020222CC  0x020222CC  thumb
 *   func_0202290C  0x0202290C  thumb
 *   sub_020056A0   0x020056A0  thumb
 *   sub_02022AC4   0x02022AC4  thumb
 *
 * The constructor of the wipe task whose per-frame step is func_02022A44:
 * it allocates and zeroes the 0x24-byte sub-object, picks the pair of
 * start/end extents from the task's direction flag and the sentinel in
 * +0x24, fills the sub-object's eight words and registers the per-frame
 * callback sub_02022AC4 with sub_020056A0 at priority 0x80.
 *
 * The 0x7FFF in +0x24 is a "no explicit extent" sentinel: when it is
 * present the moving edge starts at 0x10 (or ends there, depending on the
 * direction flag) and the other edge starts at 0; when it is absent both
 * edges start at 0 and the moving one is biased by -0x10.  The four arms
 * are written out separately, which is what gives four `b` to the shared
 * continuation rather than a computed pair
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * Both extents reach the sub-object scaled by 128 (`lsls #7`), i.e. as
 * 24.7 fixed point, while the unscaled values stay in r7/r6 for the
 * func_0202290C call and the +0x1c store.

 * The direction test is written `dir == 0` first: the image's `bne` at
 * +0x2e takes the SECOND arm, so the zero case is the fall-through and
 * therefore the source's first
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).  Written the
 * other way round every byte from +0x2e to +0x4a is wrong -- the four arm
 * bodies come out in the mirrored order and r6/r7 trade roles -- while
 * everything before and after stays identical, which is exactly the
 * signature that says polarity rather than shape.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020229A4.c \
 *       --func func_020229A4 --addr 0x020229A4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;

struct Obj {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    void *f20;    /* 0x20 */
};

struct Task {
    u32   f00;
    u32   f04;
    u32   f08;
    u32   phase;  /* 0x0c */
    u32   f10;
    struct Obj *obj;  /* 0x14 */
    u32   f18;
    u32   f1c;
    u32   f20;    /* 0x20 */
    u16   f24;    /* 0x24 */
};

extern void *func_02030734(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern void  func_020222CC(u32 a, u32 b);
extern u32   func_0202290C(s32 a, s32 b, s32 c);
extern void *sub_020056A0(void *fn, void *arg, u32 prio);
extern void  sub_02022AC4(void);

void func_020229A4(struct Task *t, u32 dir)
{
    struct Obj *o;
    s32         a;
    s32         b;

    t->obj = (struct Obj *)func_02030734((u16)t->f20, 0x24, 0, 0x020A7450,
                                         0x09AC);
    func_02082BCC(t->obj, 0, 0x24);
    o = t->obj;

    b = 0;
    if (dir == 0) {
        if (t->f24 == 0x7FFF) {
            a = 0x10;
        } else {
            a = b;
            a = a - 0x10;
        }
    } else {
        if (t->f24 == 0x7FFF) {
            a = b;
            b = 0x10;
        } else {
            a = b;
            b = b - 0x10;
        }
    }

    func_020222CC(t->f10, a);

    o->f00 = t->f04;
    o->f04 = t->f08;
    o->f08 = 0;
    o->f0c = a << 7;
    o->f10 = b << 7;
    o->f14 = func_0202290C(a, b, t->f04);
    o->f18 = t->f10;
    o->f1c = a;
    t->phase = t->phase + 1;
    o->f20 = sub_020056A0((void *)sub_02022AC4, o, 0x80);
}
