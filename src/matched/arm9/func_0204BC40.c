/*
 * function: CLACT_UnlinkUnit
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
 *   g_ClactSystem   0x02146A74  data
 *
 * The inverse of src/matched/CLACT_LinkUnit.c: unlink a cell-actor bank from
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
 *   python tools/match.py one --src src/matched/CLACT_UnlinkUnit.c \
 *       --func CLACT_UnlinkUnit --addr 0x0204BC40 --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;

struct Bank {
    u8           pad_00[0x10];
    struct Bank *next;   /* 0x10 */
    struct Bank *prev;   /* 0x14 */
};

extern struct Mgr *g_ClactSystem;

void CLACT_UnlinkUnit(struct Bank *bank)
{
    if (g_ClactSystem->head == bank) {
        if (bank->next == bank) {
            g_ClactSystem->head = 0;
        } else {
            g_ClactSystem->head = bank->next;
        }
    }

    bank->next->prev = bank->prev;
    bank->prev->next = bank->next;
    bank->next = 0;
    bank->prev = 0;
}
