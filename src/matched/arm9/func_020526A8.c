/*
 * function: SPL_EMITTER_FreeNodeHeap
 * address:  0x020526A8
 * packet:   pkt_020526A8
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   SPL_EMITTER_UpdateSubC  0x02052FC8  arm
 *
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
 *   python tools/match.py one --src src/matched/SPL_EMITTER_FreeNodeHeap.c \
 *       --func SPL_EMITTER_FreeNodeHeap --addr 0x020526A8 --cc ../1.2/sp2 --arm \
 *       --flags "-O4,p -proc arm946e"
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Node {
    struct Node *next;   /* 0x00 */
    struct Node *prev;   /* 0x04 */
    u32 pad08[7];
    u32 f24_b0 : 1;
    u32 f24_b1 : 1;
    u32 f24_b2 : 1;
    u32 f24_b3 : 1;
    u32 f24_hi : 28;
};

struct Head {
    u32 f00;
    struct Node *list;   /* 0x04 */
    u32 f08;
    struct Node *rlist;  /* 0x0c */
    u32 pad10[10];
    u32 f38_lo : 24;
    u32 f38_b24 : 1;
    u32 f38_hi : 7;
    u32 f3c;
    struct Node *cur;    /* 0x40 */
    u32 f44;
};

extern void SPL_EMITTER_UpdateSubC(struct Head *h);

void SPL_EMITTER_FreeNodeHeap(struct Head *h, u32 a)
{
    struct Node *n;

    *(volatile u16 *)0x04000060 =
        (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 8);

    h->f44 = a;
    if (h->f38_b24 == 0) {
        n = h->list;
        while (n != 0) {
            h->cur = n;
            if (n->f24_b3 == 0)
                SPL_EMITTER_UpdateSubC(h);
            n = n->next;
        }
    } else {
        n = h->rlist;
        while (n != 0) {
            h->cur = n;
            if (n->f24_b3 == 0)
                SPL_EMITTER_UpdateSubC(h);
            n = n->prev;
        }
    }
}
