/*
 * unit:     no
 * function: TCBL_AddTask
 * address:  0x020311B8
 * packet:   pkt_0203115C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734       0x02030734  arm
 *   sub_02030F04       0x02030F04  arm
 *   sub_020311B8_File  0x020A7834  data
 *
 * The task-callback registrar: take a node off the free list, stamp the
 * callback and its sort key into it, give it a work area and splice it into
 * the manager's circular list in ascending key order.
 *
 * The work area is the row the constructor already reserved unless the caller
 * asks for more than the manager's own stride at +0x04, in which case a block
 * is allocated here and the pointer is parked at +0x10; TCBL_GetTaskWork is the
 * accessor that picks between the two, and TCBL_FreeTask frees exactly the
 * pointer this function may have stored.
 *
 * EXACT*, not EXACT: the eight bytes at 0x02031288 (`str r1, [r0, #0x14]`
 * then `bx lr`, the setter for a node's callback field) save no lr, so
 * disasm.py gives them no label and this function's inferred extent runs past
 * its own two pool words to 0x02031290, where the already-matched veneer
 * src/matched/TCBL_GetWork.c starts
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  The extra
 * bytes compare equal; seeding 0x02031288 into layout/function_starts.txt is
 * the integrator's call and the witness is the pool that closes this function
 * at 0x02031288.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TCBL_AddTask.c \
 *       --func TCBL_AddTask --addr 0x020311B8 --cc 1.1p1 --arm
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

extern const char sub_020311B8_File[];

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct List;
struct Node;
extern struct Node *sub_02030F04(struct List *list);

struct TcblNode *TCBL_AddTask(struct Tcbl *p, TcblFunc func, u32 workSize,
                              u32 key)
{
    struct TcblNode *n;
    struct TcblNode *cur;
    struct TcblNode *s;

    s = &p->sentinel;
    n = (struct TcblNode *)sub_02030F04((struct List *)p);
    if (n == 0) {
        return 0;
    }

    n->key = key;
    n->func = func;

    if (workSize > p->workSize) {
        n->work = sub_02030734(p->heapId, workSize, 0, sub_020311B8_File, 325);
    } else {
        n->work = 0;
    }

    for (cur = s->next; cur != s; cur = cur->next) {
        if (cur->key > n->key) {
            n->prev = cur->prev;
            n->next = cur;
            cur->prev->next = n;
            cur->prev = n;
            return n;
        }
    }

    n->prev = p->sentinel.prev;
    n->next = &p->sentinel;
    p->sentinel.prev->next = n;
    p->sentinel.prev = n;
    return n;
}
