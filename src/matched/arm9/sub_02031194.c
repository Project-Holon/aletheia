/*
 * unit:     no
 * function: sub_02031194
 * address:  0x02031194
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
 * The public "unregister this node" entry.  A node that asks to be destroyed
 * while the dispatcher is standing on it cannot be unlinked here, because
 * sub_020310C4 still has to read its successor: the request is deferred by
 * setting the manager's flag at +0x10, which the dispatcher tests after every
 * callback and turns into the sub_02030F70 call itself.  Any other node goes
 * straight through.
 *
 * The owner is reached through the node's own +0x00 back-pointer, which is
 * what sub_02030F50 planted there, so the caller does not have to know the
 * manager.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02031194.c \
 *       --func sub_02031194 --addr 0x02031194 --cc 1.1p1 --arm
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

void sub_02031194(struct TcblNode *n)
{
    struct Tcbl *p;

    p = n->owner;
    if (p->cursor == n) {
        p->destroyed = 1;
        return;
    }
    sub_02030F70(n);
}
