/*
 * file:     tcbl_p06.c
 * unit:     yes
 * function: func_02031140, func_0203115C, func_02031194, func_020311B8, func_02031288, func_02031290
 * address:  0x02031140
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ENV_SetResourceSet  0x020307B0  arm
 *   sub_02030F70  0x02030F70  arm
 *   sub_02030734       0x02030734  arm
 *   sub_02030F04       0x02030F04  arm
 *   sub_020311B8_File  0x020A7834  data
 *   sub_02030FB4  0x02030FB4  arm
 */
struct Tcbl;
struct TcblNode;
struct List;
struct Node;
struct S02031140 {
    char  pad[0x14];
    void *field14;
};

typedef unsigned short u16;

typedef unsigned int   u32;

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

struct S02030FB4 {
    char  pad[0x10];
    void *field10;
    char  pad2[4];
    char  embedded[1];
};

extern void ENV_SetResourceSet(void *p);
extern void sub_02030F70(struct TcblNode *n);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Node *sub_02030F04(struct List *list);
extern void *sub_02030FB4(struct S02030FB4 *p);
void func_02031288(int *p, int v);
extern const char sub_020311B8_File[];


/*
 * Two calls into the TwlSDK environment/resource module: first with a
 * pointer stashed at +0x14 of the argument, then with the argument itself.
 * ENV_SetResourceSet is the recovered SDK symbol at 0x020307B0
 * (TwlSDK/libenv.TWL.HYB.a(env_system.o)); this whole packet's accessors
 * (sub_0202FBAC and neighbours) read the resource-set table that
 * ENV_SetResourceSet installs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02031140.c \
 *       --func sub_02031140 --addr 0x02031140 --cc 1.1p1
 */
void sub_02031140(struct S02031140 *p)
{
    ENV_SetResourceSet(p->field14);
    ENV_SetResourceSet(p);
}


/*
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


/*
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


/*
 * The task-callback registrar: take a node off the free list, stamp the
 * callback and its sort key into it, give it a work area and splice it into
 * the manager's circular list in ascending key order.
 *
 * The work area is the row the constructor already reserved unless the caller
 * asks for more than the manager's own stride at +0x04, in which case a block
 * is allocated here and the pointer is parked at +0x10; sub_02030FB4 is the
 * accessor that picks between the two, and sub_02030F70 frees exactly the
 * pointer this function may have stored.
 *
 * EXACT*, not EXACT: the eight bytes at 0x02031288 (`str r1, [r0, #0x14]`
 * then `bx lr`, the setter for a node's callback field) save no lr, so
 * disasm.py gives them no label and this function's inferred extent runs past
 * its own two pool words to 0x02031290, where the already-matched veneer
 * src/matched/sub_02031290.c starts
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  The extra
 * bytes compare equal; seeding 0x02031288 into layout/function_starts.txt is
 * the integrator's call and the witness is the pool that closes this function
 * at 0x02031288.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020311B8.c \
 *       --func sub_020311B8 --addr 0x020311B8 --cc 1.1p1 --arm
 */
struct TcblNode *sub_020311B8(struct Tcbl *p, TcblFunc func, u32 workSize,
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

void func_02031288(int *p, int v){ p[5] = v; }


/*
 * A four-instruction tail call to sub_02030FB4 (src/matched/sub_02030FB4.c,
 * this same packet), one section back. The mwccarm one-section-per-function
 * rule means even a same-file neighbour is reached through a pool word and
 * `bx`; see docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02031290.c \
 *       --func sub_02031290 --addr 0x02031290 --cc 1.1p1
 */
void *sub_02031290(struct S02030FB4 *p)
{
    return sub_02030FB4(p);
}
