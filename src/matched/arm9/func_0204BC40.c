/*
 * function: func_0204BC40
 * address:  0x0204BC40
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
 * The inverse of src/matched/func_0204BBC8.c: unlink a cell-actor bank from
 * the singleton's ring at +0x100 and NULL both of its own links.  When the
 * bank being removed is the head, the head moves to its successor, or to
 * NULL when the bank was the only member.
 *
 * The head update is one `if`/`else` whose two arms the compiler predicates
 * into `streq`/`strne` off a shared `moveq r1, #0`
 * (docs/idioms/a-factored-tail-lets-the-compiler-predicate-the-arms.md);
 * writing it as a conditional expression on the stored value instead loses
 * the paired store.
 *
 * Both link fields are re-read between the two ring stores because a store
 * through one Bank pointer may alias the other, so `bank->next` is loaded
 * twice and `bank->prev` twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BC40.c \
 *       --func func_0204BC40 --addr 0x0204BC40 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct Bank {
    u8           pad_00[0x10];
    struct Bank *next;   /* 0x10 */
    struct Bank *prev;   /* 0x14 */
};

struct Sys {
    u8           pad_000[0x100];
    struct Bank *head;   /* 0x100 */
};

extern struct Sys *g_02146A74;

void func_0204BC40(struct Bank *bank)
{
    if (g_02146A74->head == bank) {
        if (bank->next == bank) {
            g_02146A74->head = 0;
        } else {
            g_02146A74->head = bank->next;
        }
    }

    bank->next->prev = bank->prev;
    bank->prev->next = bank->next;
    bank->next = 0;
    bank->prev = 0;
}
