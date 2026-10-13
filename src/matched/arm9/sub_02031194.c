/*
 * unit:     no
 * function: TCBL_DeleteTask
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
 *   TCBL_FreeTask  0x02030F70  arm
 *
 * The public "unregister this node" entry.  A node that asks to be destroyed
 * while the dispatcher is standing on it cannot be unlinked here, because
 * TCBL_Main still has to read its successor: the request is deferred by
 * setting the manager's flag at +0x10, which the dispatcher tests after every
 * callback and turns into the TCBL_FreeTask call itself.  Any other node goes
 * straight through.
 *
 * The owner is reached through the node's own +0x00 back-pointer, which is
 * what TCBL_InitTaskLinks planted there, so the caller does not have to know the
 * manager.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_DeleteTask.c \
 *       --func TCBL_DeleteTask --addr 0x02031194 --cc 1.1p1 --arm
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

extern void TCBL_FreeTask(struct TcblNode *n);

void TCBL_DeleteTask(struct TcblNode *n)
{
    struct Tcbl *p;

    p = n->owner;
    if (p->cursor == n) {
        p->destroyed = 1;
        return;
    }
    TCBL_FreeTask(n);
}
