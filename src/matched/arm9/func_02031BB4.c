/*
 * function: func_02031BB4
 * address:  0x02031BB4
 * packet:   pkt_02031BB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH on the `label`/`matched` classes: 75 of 76 bytes
 * reproduce and the only unresolved site is the PC24 at +0x24 to
 * func_02032CD0, whose single branch reference image-wide is this call, so
 * there is no witness outside 02031BB4..02031C04.  Filing 0x02032CD0 as an
 * EXACT manifest entry promotes this file with no change to the C.
 *
 * 0x02031BB4 is called from 0x02031B88 (the same packet's neighbour) and the
 * stack slot it hands func_02032CD0 is the pushed r3 scratch word, so the
 * local's address is taken but its value is never read here.
 *
 * symbols:
 *   g_02146994     0x02146994  data
 *   func_02032CD0  0x02032CD0  arm
 *   func_020331A4  0x020331A4  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02031BB4.c \
 *       --func func_02031BB4 --addr 0x02031BB4 --cc 1.1p1 --arm
 */

#include "../include/G_SaveMain.h"

typedef unsigned int u32;

extern struct SaveMain *g_02146994;
extern int func_02032CD0(u32 a0, void *out);
struct SaveBackup;
extern void func_020331A4(struct SaveBackup *p, u32 result, u32 flag);

int func_02031BB4(u32 a0)
{
    int r;
    u32 v;

    if (*((u32 *)g_02146994) == 0)
        return 3;
    r = func_02032CD0(a0, &v);
    if (r != 0 && r != 1)
        func_020331A4((struct SaveBackup *)a0, r, 1);
    return r;
}
