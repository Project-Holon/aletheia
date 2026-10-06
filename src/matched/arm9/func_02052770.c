/*
 * function: func_02052770
 * address:  0x02052770
 * packet:   pkt_020526A8
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02053218  0x02053218  arm
 *   func_02058300  0x02058300  arm
 *   func_020583CC  0x020583CC  arm
 *
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
#include "../include/Obj16203.h"

typedef unsigned short u16;
typedef unsigned int   u32;

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

struct Node {
    struct Node *next;   /* 0x00 */
    struct Node *prev;   /* 0x04 */
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

struct Head {
    u32 f00;
    struct Node *list;   /* 0x04 */
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 pad14[13];
    u16 f48;             /* 0x48 */
};

struct List;
struct SPLEmitter;
struct SPLManager;
extern void func_02053218(struct SPLManager *mgr, struct SPLEmitter *emtr);
extern struct Node *func_02058300(struct List *list, struct Node *node);
extern void func_020583CC(volatile struct List *list, volatile struct Node *node);

void func_02052770(struct Head *h)
{
    struct Node *n = h->list;

    if (n != 0) {
        u16 z = 0;
        struct Node *next;

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
                    void *r = func_02058300((struct List *)(&h->list), n);
                    func_020583CC((volatile struct List *)(&h->f10), r);
                }
            }
            n = next;
        } while (next != 0);
    }
    h->f48 = h->f48 + 1;
    if (h->f48 > 1)
        h->f48 = 0;
}
