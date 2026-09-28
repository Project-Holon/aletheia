/*
 * unit:     no
 * function: sub_020310C4
 * address:  0x020310C4
 * packet:   pkt_02030FC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02030F70  0x02030F70  arm
 *   sub_02030FB4  0x02030FB4  arm
 *
 * Run one pass over the task-callback list: for every node still linked to
 * the sentinel at +0x18, clear the manager's "current node was destroyed"
 * flag at +0x10, invoke the node's callback at +0x14 with the node and its
 * work area (sub_02030FB4, the "owned or embedded" accessor), then advance.
 * If the callback set the flag, the node is unlinked and returned to the
 * free list by sub_02030F70, so its successor has to be read out before the
 * call.
 *
 * The walk cursor lives in the manager at +0x30 rather than in a local, so
 * a callback that destroys a *different* node can fix it up; it is cleared
 * on both exits, which is why this is a `while` and not a `do`/`while`: the
 * empty-list arm branches to the same tail.
 *
 * The loop is carried by a local that is refreshed from +0x30 at the bottom
 * of the body, *and* the body re-reads +0x30 into its own local at the top.
 * Written as a bare `while (p->cursor != s)` with `n = p->cursor` inside,
 * the compiler common-subexpressions the two reads and the body top becomes
 * a register copy, four bytes short; see
 * docs/idioms/a-loop-carried-local-beside-a-re-read-field-keeps-both-loads.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020310C4.c \
 *       --func sub_020310C4 --addr 0x020310C4 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct TcblNode;

typedef void (*TcblFunc)(struct TcblNode *node, void *work);

struct TcblNode {
    u32              unk_00;
    struct TcblNode *prev;
    struct TcblNode *next;
    u32              unk_0c;
    u32              unk_10;
    TcblFunc         func;
};

struct Tcbl {
    u32              count;
    u32              workSize;
    u16              unk_08;
    u16              pad_0a;
    u32              unk_0c;
    u32              destroyed;
    void            *table;
    struct TcblNode  sentinel;
    struct TcblNode *cursor;
    struct TcblNode *freeHead;
};

extern void sub_02030F70(struct TcblNode *node);
extern void *sub_02030FB4(struct TcblNode *node);

void sub_020310C4(struct Tcbl *p)
{
    struct TcblNode *s = &p->sentinel;
    struct TcblNode *cur;

    cur = s->next;
    p->cursor = cur;
    while (cur != s) {
        struct TcblNode *n = p->cursor;
        p->destroyed = 0;
        n->func(n, sub_02030FB4(n));
        if (p->destroyed == 0) {
            p->cursor = p->cursor->next;
        } else {
            struct TcblNode *next = p->cursor->next;
            sub_02030F70(p->cursor);
            p->cursor = next;
        }
        cur = p->cursor;
    }
    p->cursor = 0;
}
