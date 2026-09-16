/*
 * unit:     no
 * function: sub_02030F50
 * address:  0x02030F50
 * packet:   pkt_02030F50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Reset one task-callback node to the "not in the live list" state: owner
 * back-pointer, both links parked on the manager's sentinel at +0x18, and
 * the three payload words cleared.  It is the shape sub_02030C68 has for the
 * timer pool in src/matched/unit_02030C44.c, one layer up.
 *
 * A leaf: no lr is saved, so disasm.py gives it no label of its own and the
 * function is only visible by address
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md does not apply
 * here only because the callers name it).
 *
 * The owner and the prev link are one `stm r1, {r0, r3}`, which is what two
 * adjacent word stores of two already-live registers collapse to; the zero is
 * materialised between them, filling the load slot.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030F50.c \
 *       --func sub_02030F50 --addr 0x02030F50 --cc 1.1p1 --arm
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
    u16              unk_08;
    u16              pad_0a;
    u32              unk_0c;
    u32              destroyed;
    void            *table;
    struct TcblNode  sentinel;
    struct TcblNode *cursor;
    struct TcblNode *freeHead;
};

void sub_02030F50(struct Tcbl *p, struct TcblNode *n)
{
    n->owner = p;
    n->prev = &p->sentinel;
    n->next = &p->sentinel;
    n->key = 0;
    n->work = 0;
    n->func = 0;
}
