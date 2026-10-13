/*
 * function: CLACT_DrawAllUnits
 * address:  0x0204BB8C
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH: all 60 concrete bytes are correct, but the PC24 at +0x001C
 * (the call to CLACT_DrawUnit) has no witness of any class.  0x0204C944 has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0204C944, which sits in the
 * packet after pkt_0204BD64.
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   CLACT_DrawUnit  0x0204C944  arm
 *
 * Walk the singleton's bank ring at +0x100 and run CLACT_DrawUnit over every
 * member.  The ring is the one src/matched/CLACT_LinkUnit.c builds, so the
 * walk is a do/while around the head test rather than a null-terminated
 * list.
 *
 * Unlike CLACT_LinkUnit's insertion walk, this one needs no `goto`: the call
 * in the body is an optimisation barrier, so the compiler neither rotates the
 * loop nor hoists the `->head` reload, and the structured form already
 * reproduces the re-read at +0x20.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_DrawAllUnits.c \
 *       --func CLACT_DrawAllUnits --addr 0x0204BB8C --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;

struct Bank {
    u8           pad_00[0x10];
    struct Bank *next;   /* 0x10 */
};

extern struct Mgr *g_ClactSystem;

struct Ring;
extern void CLACT_DrawUnit(struct Ring *b);

void CLACT_DrawAllUnits(void)
{
    struct Bank *cur;

    cur = g_ClactSystem->head;
    if (cur == 0) {
        return;
    }

    do {
        CLACT_DrawUnit((struct Ring *)cur);
        cur = cur->next;
    } while (cur != g_ClactSystem->head);
}
