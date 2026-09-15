/*
 * function: func_0204BBC8
 * address:  0x0204BBC8
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74   0x02146A74  data
 *
 * Link a cell-actor bank into the singleton's priority-ordered ring at
 * +0x100.  The ring is circular and doubly linked through +0x10 (next) and
 * +0x14 (prev); the sort key is the u8 at +0x0f that
 * src/matched/sub_0204B100.c stores from its caller's flag.
 *
 * Empty ring: the bank becomes the head and both of its own links point at
 * itself.  The three stores are written through the global each time, which
 * is why the global is reloaded twice after the first store: a store through
 * a Bank pointer may alias the pointer variable itself, so the compiler
 * cannot keep the initial load live across it.  The walk in the other arm
 * performs no store and keeps the cached copy in ip throughout.
 *
 * The walk has to be written with explicit labels and `goto`.  Every
 * structured spelling (`while`, `do`/`while`, `for(;;)` with two breaks) is
 * rotated: the compiler peels the first priority test, and once the loop has
 * a single back edge it also hoists the `->head` reload out of it, which
 * costs twelve bytes and loses the `ldr r1, [ip, #0x100]` at +0x48.  See
 * docs/idioms/a-reloaded-loop-invariant-means-the-loop-was-not-rotated.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BBC8.c \
 *       --func func_0204BBC8 --addr 0x0204BBC8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct Bank {
    u8           pad_00[0x0f];
    u8           prio;   /* 0x0f */
    struct Bank *next;   /* 0x10 */
    struct Bank *prev;   /* 0x14 */
};

struct Sys {
    u8           pad_000[0x100];
    struct Bank *head;   /* 0x100 */
};

extern struct Sys *g_02146A74;

void func_0204BBC8(struct Bank *bank)
{
    struct Bank *cur;
    struct Bank *prev;

    if (g_02146A74->head == 0) {
        g_02146A74->head = bank;
        g_02146A74->head->next = bank;
        g_02146A74->head->prev = bank;
        return;
    }

    cur = g_02146A74->head;
loop:
    if (cur->prio > bank->prio) {
        goto found;
    }
    cur = cur->next;
    if (cur != g_02146A74->head) {
        goto loop;
    }
found:

    prev = cur->prev;
    bank->prev = prev;
    bank->next = prev->next;
    prev->next->prev = bank;
    prev->next = bank;
}
