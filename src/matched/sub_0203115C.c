/*
 * unit:     no
 * function: sub_0203115C
 * address:  0x0203115C
 * packet:   pkt_0203115C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02030F70  0x02030F70  arm
 *
 * Destroy every node still registered with the manager.  The walk cursor at
 * +0x30 is published on each step for the same reason sub_020310C4 publishes
 * it: a callback destroying itself through sub_02031194 compares against it.
 *
 * The successor is read out before the call because sub_02030F70 unlinks the
 * node and pushes it on the free list, so its own +0x08 is no longer the
 * list's.  The cursor store follows the advance rather than preceding it,
 * which is what puts `mov r0, r5` before `str r5, [r6, #0x30]`.
 *
 * Unlike sub_020310C4 the cursor is not cleared on exit: the loop leaves the
 * sentinel's own address parked there.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203115C.c \
 *       --func sub_0203115C --addr 0x0203115C --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Tcbl;
struct TcblNode;

typedef void (*TcblFunc)(struct TcblNode *node, void *work);

struct TcblNode {
    struct Tcbl     *owner;
    struct TcblNode *prev;
    struct TcblNode *next;
    u32              key;
    void            *work;
    TcblFunc         func;
};

struct Tcbl {
    u32              count;
    u32              workSize;
    u16              heapId;
    u16              pad_0a;
    u32              unk_0c;
    u32              destroyed;
    void            *table;
    struct TcblNode  sentinel;
    struct TcblNode *cursor;
    struct TcblNode *freeHead;
};

extern void sub_02030F70(struct TcblNode *n);

void sub_0203115C(struct Tcbl *p)
{
    struct TcblNode *s;
    struct TcblNode *cur;
    struct TcblNode *next;

    s = &p->sentinel;
    cur = s->next;
    p->cursor = cur;
    while (cur != s) {
        next = cur->next;
        sub_02030F70(cur);
        cur = next;
        p->cursor = next;
    }
}
