/*
 * function: SPL_EMITTER_ClearNodeList
 * address:  0x020583CC
 * packet:   pkt_020583CC
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Push-front for a doubly linked list { head +0, count +4, tail +8 },
 * Node { next +0, prev +4 } (the shapes fixed by SPL_EMITTER_FreeNode /
 * SPL_EMITTER_AllocNode, both already EXACT).
 *
 * Body recovered from docs/notes/SPL_EMITTER_ClearNodeList.c.txt (wave r3a): under the
 * pinned dsi/1.1p1 -O4,p this body is 72 bytes and if-converts the non-empty
 * arm into five predicated instructions; under the 1.2 front end the same
 * source lays out the original's 80 bytes. Constant-materialisation pin:
 * docs/FRONTEND-PINS.md, family 0x0205429C..0x020584E0.
 *
 * The ldr r2,[r1] after `node->next = 0` is a genuine reload, which is why the
 * pointee struct - not the pointer member - is volatile-qualified (mwcc
 * ignores volatile on a pointer-typed member; see
 * docs/idioms/volatile-on-a-pointer-typed-member-is-ignored.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SPL_EMITTER_ClearNodeList.c \
 *       --func SPL_EMITTER_ClearNodeList --addr 0x020583CC --arm --cc ../1.2/sp2
 */

struct Node;

struct List {
    volatile struct Node *head;
    int count;
    volatile struct Node *tail;
};

struct Node {
    volatile struct Node *next;
    volatile struct Node *prev;
};

void SPL_EMITTER_ClearNodeList(volatile struct List *list, volatile struct Node *node)
{
    volatile struct Node *head;

    head = list->head;
    if (head == 0) {
        list->head = node;
        list->tail = node;
        node->next = 0;
        node->prev = node->next;
    } else {
        node->next = head;
        node->prev = 0;
        list->head->prev = node;
        list->head = node;
    }
    list->count++;
}
