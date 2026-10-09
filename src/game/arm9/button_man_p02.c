/*
 * file:     button_man_p02.c
 * unit:     yes
 * function: func_020524C8, func_0205250C, func_020525A0, func_02052634, func_020526A8, func_02052770, func_020528A8, func_020528BC, func_020528D0
 * address:  0x020524C8
 * region:   arm9
 * compiler: dsi/../1.2/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02058380  0x02058380  arm
 *   func_020583CC  0x020583CC  arm
 *   func_02058300  0x02058300  arm
 *   func_02053A60   0x02053A60  arm
 *   func_02052FC8  0x02052FC8  arm
 *   func_02053218  0x02053218  arm
 *   func_02052F58  0x02052F58  arm
 *   func_02052984  0x02052984  arm
 *   func_02052F90  0x02052F90  arm
 *   GX_BeginLoadTexPltt  0x0207FA0C  arm
 *   GX_LoadTexPltt       0x0207FA40  arm
 *   GX_EndLoadTexPltt    0x0207FADC  arm
 */
#include "../../matched/include/Obj16203.h"
#include "../../matched/include/Obj00077.h"
#include "../../matched/include/Obj11462.h"
#include "../../matched/include/Obj16201.h"
#include "../../matched/include/Obj16202.h"
#include "../../matched/include/Obj00077.h"
#include "../../matched/include/Obj11461.h"

struct List;
struct SPLEmitter;
struct SPLManager;
struct Node_020524C8;
struct Cfg;
struct Obj;
struct Vec3;
typedef unsigned int u32;

typedef unsigned short u16;

struct Res {
    u32 f00;
    u32 kind : 4;
    u32 f04_hi : 28;
    u32 f08;
    u32 f0c;
    u32 f10;
};

struct Row {
    struct Res *res;
    u32 tex_vram;
    u32 pltt_vram;
    u32 pad[2];
};

struct Obj {
    u32 pad0[11];
    struct Row *f2c;
    u16 pad1[1];
    u16 f32;
};

typedef u32 (*Alloc)(u32, u32);

struct Cls {
    u32 c00_lo : 14;
    u32 c00_b14 : 1;
    u32 c00_hi : 17;
    u32 pad04[11];
    u16 pad30;
    u16 f32;             /* 0x32 */
    u32 pad34[2];
    u16 f3c;             /* 0x3c */
    u16 pad3e;
};

struct Node_02052770 {
    struct Node_02052770 *next;   /* 0x00 */
    struct Node_02052770 *prev;   /* 0x04 */
    u32 f08;
    u32 f0c;
    u32 pad10[2];
    u32 f18;
    u32 f1c;
    struct Cls **f20;    /* 0x20 */
    u32 f24_b0 : 1;
    u32 f24_b1 : 1;
    u32 f24_b2 : 1;
    u32 f24_b3 : 1;
    u32 f24_b4 : 1;
    u32 f24_hi : 27;
    u16 pad28[18];
    u16 f4c;             /* 0x4c */
    u16 pad4e;
    u32 pad50[12];
};

struct Head_02052770 {
    u32 f00;
    struct Node_02052770 *list;   /* 0x04 */
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 pad14[13];
    u16 f48;             /* 0x48 */
};

struct Node_020524C8 {
    struct Node_020524C8 *next;   /* 0x00 */
    struct Node_020524C8 *prev;   /* 0x04 */
    u32 pad08[7];
    u32 f24_b0 : 1;
    u32 f24_b1 : 1;
    u32 f24_b2 : 1;
    u32 f24_b3 : 1;
    u32 f24_hi : 28;
};

struct Head_020524C8 {
    u32 f00;
    struct Node_020524C8 *list;   /* 0x04 */
    u32 f08;
    struct Node_020524C8 *rlist;  /* 0x0c */
    u32 pad10[10];
    u32 f38_lo : 24;
    u32 f38_b24 : 1;
    u32 f38_hi : 7;
    u32 f3c;
    struct Node_020524C8 *cur;    /* 0x40 */
    u32 f44;
};

struct Scratch {
    u32 a;
    u32 b;
    u32 c;
};

extern int func_02052984(u32 a0, void *cb);
extern int func_02052F90(u32 a0, u32 a1);
extern void GX_BeginLoadTexPltt(void);
extern void GX_LoadTexPltt(void *dst, u32 a, u32 b);
extern void GX_EndLoadTexPltt(void);
extern int func_02052F58(u32 a0, u32 a1);
extern void func_02053218(struct SPLManager *mgr, struct SPLEmitter *emtr);
extern struct Node_02052770 *func_02058300(struct List *list, struct Node_02052770 *node);
extern void func_020583CC(volatile struct List *list, volatile struct Node_02052770 *node);
extern void func_02052FC8(struct Head_020524C8 *h);
extern struct Node_020524C8 *func_02058380(struct List *list);
extern void func_02053A60(volatile struct Obj *o, struct Cfg *cfg, const struct Vec3 *pos);
int func_020528D0(struct Obj *o, Alloc alloc);
void func_020528BC(u32 a0);
void func_020528A8(u32 a0);
void func_02052770(struct Head_02052770 *h);
void func_020526A8(struct Head_020524C8 *h, u32 a);
int func_02052634(char *p, int b, int c);
int func_020525A0(char *p, int b, void (*fn)(void *));
void func_0205250C(char *p, char *q);
void func_020524C8(void *p);



/*
 * The texture-palette upload pass: GX_BeginLoadTexPltt, then for every row
 * of o->f2c with a non-zero resource size, allocate through the caller's
 * callback (first argument is the SIZE word, second is kind == 2) and upload
 * with GX_LoadTexPltt; the handle (0 when skipped) goes to row+0x08.  Then
 * GX_EndLoadTexPltt; always returns 1.  Twin of func_02052984 (textures).
 *
 * What closed it (wave 9): array indexing o->f2c[i] and "kind == 2 ? 1 : 0"
 * instead of hand-written offset/one/zero locals (the wave-7 note's 8-byte
 * register swap was the compiler's strength reduction disagreeing with the
 * hand-reduced loop).
 */
int func_020528D0(struct Obj *o, Alloc alloc)
{
    int i;

    GX_BeginLoadTexPltt();

    for (i = 0; i < o->f32; i++) {
        struct Row *r = &o->f2c[i];
        struct Res *res = r->res;
        u32 v = 0;

        if (res->f10 != 0) {
            v = alloc(res->f10, res->kind == 2 ? 1 : 0);
            GX_LoadTexPltt((char *)r->res + res->f0c, v, res->f10);
        }
        r->pltt_vram = v;
    }

    GX_EndLoadTexPltt();
    return 1;
}



/*
 * Twin of src/matched/func_020528A8.c, same twelve bytes by position: forward
 * r0 to 0x02052984 with the address of func_02052F90 as the second argument.
 * Same 1.2 pin and same tail-call schedule tell.
 *
 * The callback site resolves through the `matched` class once
 * src/matched/func_02052F90.c is in the manifest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020528BC.c \
 *       --func func_020528BC --addr 0x020528BC --arm --cc ../1.2/sp2
 */
void func_020528BC(u32 a0)
{
    func_02052984(a0, (void *)func_02052F90);
}



/*
 * A twelve-byte tailcall thunk: forward r0 to 0x020528D0 and pass the
 * address of func_02052F58 as the second argument.  mwcc emits a tail call as
 * a pool word plus `bx ip`, and for two pool words the 1.2 front end issues
 * the callee load into ip first, then the argument load; 1.1p1 issues them in
 * the other order (the documented tail-call schedule gap,
 * docs/idioms/a-tail-calls-pool-word-is-scheduled-before-the-last-argument-write.md),
 * so this row needs the packet's 1.2 pin as well.
 *
 * The callback site resolves through the `matched` class once
 * src/matched/func_02052F58.c is in the manifest: this row is filed after
 * that entry, and it is the second half of the pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020528A8.c \
 *       --func func_020528A8 --addr 0x020528A8 --arm --cc ../1.2/sp2
 */
void func_020528A8(u32 a0)
{
    func_020528D0((struct Obj *)a0, (Alloc)((void *)func_02052F58));
}




/*
 * The rig's per-frame node walk: for every node on h->list, age it, maybe
 * dispatch it, and maybe retire it onto the recycle list.  This is the callee
 * src/pending/func_020514F4.c was capped on.
 *
 * Per node, with c = *n->f20 (the node's class record, doubly indirected):
 *   - if n's "expired" bit (+0x24 bit 4) is clear and the node's age n->f4c
 *     has reached the class lifetime c->f32, set the bit and zero the age;
 *   - if n's "suppressed" bit (+0x24 bit 2) is clear, read the 3-bit phase
 *     index at +0x80 bits 16..18 and call func_02053218(h, n) when the phase
 *     is zero or matches the rig's own frame parity h->f48;
 *   - retire the node when either the class asks for it (c bit 14 set, a
 *     non-zero c->f3c cap, the expired bit set and the age past the cap) or
 *     the node's own "kill" bit (+0x24 bit 0) is set -- and then only if the
 *     node has no pending work (n->f0c == 0 && n->f18 == 0).  Retiring is
 *     func_020583CC(&h->f10, func_02058300(&h->list, n)).
 * After the walk h->f48 is incremented and wrapped back to zero above 1, so
 * it is a two-frame parity counter.
 *
 * Two declarations carry the whole match, and both were the residue:
 *
 *  1. The retire call's two addresses must be written INLINE at the call site
 *     (&h->list, &h->f10), not bound to two pointer locals hoisted before the
 *     loop.  The original DOES hoist them into sl and sb -- but hoisting them
 *     in the C gives those two values the low colours and pushes the head and
 *     node pointers up to sl/sb instead, a clean two-cycle register swap in
 *     33 bytes that no permuter mutation moves (266 single mutations tried,
 *     none improved).  Written inline, the compiler performs the hoist itself
 *     and colours in the original's order.
 *  2. The class record's lifetime field is at 0x32 and its cap at 0x3c; one
 *     halfword of padding wrong in the Cls layout was the last byte out.
 *
 * Every bit test is the lsl/lsr shift pair, so all six selectors are real
 * bitfields rather than masks
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md); the 3-bit
 * phase index is read as a plain (word << 13) >> 29 because it is not a
 * field of the bitfield struct the +0x24 word is.
 *
 * Built by the 1.2 front end, the packet-wide pin for this cluster.  An
 * earlier lane worked this function under dsi/1.1p1 and stopped at 288/312
 * bytes (docs/notes/pkt_020526A8.c.txt); the front end was the first half of
 * the answer, the two declarations above the second.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02052770.c \
 *       --func func_02052770 --addr 0x02052770 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
void func_02052770(struct Head_02052770 *h)
{
    struct Node_02052770 *n = h->list;

    if (n != 0) {
        u16 z = 0;
        struct Node_02052770 *next;

        do {
            struct Cls *c = *n->f20;
            u32 idx;

            next = n->next;

            if (n->f24_b4 == 0) {
                if (n->f4c >= c->f32) {
                    n->f24_b4 = 1;
                    n->f4c = z;
                }
            }
            if (n->f24_b2 == 0) {
                idx = (((struct Obj16203 *)n)->f80 << 13) >> 29;
                if (idx == 0 || h->f48 == idx - 1)
                    func_02053218((struct SPLManager *)h, (struct SPLEmitter *)n);
            }
            if ((c->c00_b14 != 0 && c->f3c != 0 && n->f24_b4 != 0
                 && n->f4c > c->f3c) || n->f24_b0 != 0) {
                if (n->f0c == 0 && n->f18 == 0) {
                    void *r = (struct Node *)func_02058300((struct List *)(&h->list), (struct Node_02052770 *)n);
                    func_020583CC((volatile struct List *)(&h->f10), (volatile struct Node_02052770 *)r);
                }
            }
            n = next;
        } while (next != 0);
    }
    h->f48 = h->f48 + 1;
    if (h->f48 > 1)
        h->f48 = 0;
}





/*
 * Per-frame sweep of one display rig.  It first pokes the 3D display control
 * halfword at 0x04000060 (DISP3DCNT): clear bits 12-13, set bit 3.  That is a
 * cast constant, not a relocation
 * (docs/idioms/volatile-reread-needs-two-locals.md gives the shape; the two
 * accesses here are one read-modify-write and stay one expression).
 *
 * The argument is stored to h->f44, then bit 24 of the word at h+0x38 chooses
 * which of the rig's two lists to walk: clear walks h->list forward through
 * node->next, set walks h->rlist backward through node->prev.  Both arms are
 * written out in full rather than factored behind a shared body, which is what
 * gives the function its two identical epilogues and two `bl` sites
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * Every bit test is the lsl/lsr shift pair, so the selectors are genuine
 * bitfields, not masks: h+0x38 bit 24 is (x << 7) >> 31 and node+0x24 bit 3
 * is (x << 28) >> 31
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Built by the 1.2 front end, the packet-wide pin for this cluster.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020526A8.c \
 *       --func func_020526A8 --addr 0x020526A8 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
void func_020526A8(struct Head_020524C8 *h, u32 a)
{
    struct Node_020524C8 *n;

    *(volatile u16 *)0x04000060 =
        (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 8);

    h->f44 = a;
    if (h->f38_b24 == 0) {
        n = h->list;
        while (n != 0) {
            h->cur = n;
            if (n->f24_b3 == 0)
                func_02052FC8((struct Head_020524C8 *)h);
            n = n->next;
        }
    } else {
        n = h->rlist;
        while (n != 0) {
            h->cur = n;
            if (n->f24_b3 == 0)
                func_02052FC8((struct Head_020524C8 *)h);
            n = n->prev;
        }
    }
}






/*
 * Promote-first callee of src/pending/func_020515B4.c (parks lane 2).
 * Pops one node off the list at p+0x10, runs the loader for the node and
 * (p->f28 + (arg1 << 5), arg2), then hands the node to func_020583CC; the
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
 *   python tools/match.py one --src src/matched/func_02052634.c \
 *       --func func_02052634 --addr 0x02052634 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
int func_02052634(char *p, int b, int c)
{
    void *r = 0;

    if (((struct Obj11462 *)p)->f10 != 0) {
        r = (struct Node *)func_02058380((struct List *)(p + 0x10));
        func_02053A60(r, (void *)(((struct Obj11462 *)p)->f28 + (b << 5)), (const struct Vec3 *)c);
        func_020583CC((volatile struct List *)(p + 4), (volatile struct Node_02052770 *)r);
        if ((*(u32 *)(*(u32 *)(*(u32 *)&((struct Obj00077 *)r)->f20)) << 0x11 >> 0x1f) != 0)
            r = 0;
    }
    return (int)r;
}







/*
 * Promote-first callee of src/pending/func_020515CC.c (parks lane 2).
 * Same shape as its neighbour func_02052634 with two extra steps: the
 * loader takes the address of a twelve-byte zeroed scratch block as its
 * third argument, and a non-null third parameter is called back with the
 * popped node before func_020583CC runs.
 *
 * Built by the 1.2 front end (ARMv4T-style `pop {... lr}; bx lr` epilogue
 * and a `sub sp, sp, #4` alignment word), see
 * docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020525A0.c \
 *       --func func_020525A0 --addr 0x020525A0 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
int func_020525A0(char *p, int b, void (*fn)(void *))
{
    void *r = 0;

    if (((struct Obj11461 *)p)->f10 != 0) {
        struct Scratch scratch = { 0, 0, 0 };

        r = (struct Node *)func_02058380((struct List *)(p + 0x10));
        func_02053A60(r, (void *)(((struct Obj11461 *)p)->f28 + (b << 5)), (const struct Vec3 *)(&scratch));
        if (fn != 0)
            fn(r);
        func_020583CC((volatile struct List *)(p + 4), (volatile struct Node_02052770 *)r);
        if ((*(u32 *)(*(u32 *)(*(u32 *)&((struct Obj00077 *)r)->f20)) << 0x11 >> 0x1f) != 0)
            r = 0;
    }
    return (int)r;
}







/*
 * Tear down one node q owned by container p.  Two identical drain loops move
 * every child off q's two sublists (q+8 and q+0x14) onto the container's own
 * recycle list at p+0x1c with func_020583CC; func_02058380 is the pop, and it
 * is re-called at the bottom of each loop rather than at the top, which is why
 * the original re-materialises `add r5,r7,#0x1c` and `add r4,r6,#k` INSIDE the
 * loop body rather than hoisting them (the two locals are declared in the
 * body, one live range per iteration).  Then q is unlinked from p+4 and pushed
 * onto p+0x10.
 *
 * Called from func_020524C8 next door, which drains p+4 through this routine.
 *
 * Built by the 1.2 front end (`sub sp,sp,#4` alignment word and a
 * `pop {...,lr}; bx lr` epilogue), the packet-wide pin for this cluster.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0205250C.c \
 *       --func func_0205250C --addr 0x0205250C --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
void func_0205250C(char *p, char *q)
{
    void *n;

    n = (struct Node *)func_02058380((struct List *)(q + 8));
    while (n != 0) {
        char *head = p + 0x1c;
        char *list = q + 8;
        func_020583CC((volatile struct List *)head, (volatile struct Node_02052770 *)n);
        n = (struct Node *)func_02058380((struct List *)list);
    }

    n = (struct Node *)func_02058380((struct List *)(q + 0x14));
    while (n != 0) {
        char *head = p + 0x1c;
        char *list = q + 0x14;
        func_020583CC((volatile struct List *)head, (volatile struct Node_02052770 *)n);
        n = (struct Node *)func_02058380((struct List *)list);
    }

    (struct Node *)func_02058300((struct List *)(p + 4), (struct Node_02052770 *)((struct Node_020524C8 *)q));
    func_020583CC((volatile struct List *)(p + 0x10), (volatile struct Node_02052770 *)((volatile struct Node_020524C8 *)q));
}







/*
 * Drain the singly-linked list hanging off p+4: for each node, cache its
 * `next` pointer (the first word) BEFORE handing the node to func_0205250C,
 * which tears the node down.  The cached-next shape is what produces the
 * `ldr r4,[r1]` above the call and the `mov r1,r4; cmp r4,#0` pair below it.
 *
 * Built by the 1.2 front end like the rest of this cluster: the frame pads
 * with `sub sp, sp, #4` and the epilogue is `pop {r4,r5,lr}; bx lr`
 * (docs/idioms/an-armv4t-style-return-and-a-register-blx-name-a-1-2-front-end-not-a-proc-value.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020524C8.c \
 *       --func func_020524C8 --addr 0x020524C8 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */
void func_020524C8(void *p)
{
    void *n = ((struct Obj16201 *)p)->f4;

    while (n != 0) {
        void *next = ((struct Obj16202 *)n)->f0;
        func_0205250C(p, n);
        n = next;
    }
}
