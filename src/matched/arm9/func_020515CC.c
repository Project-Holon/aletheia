/*
 * function: func_020515CC
 * address:  0x020515CC
 * packet:   pkt_020515CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_pParticleMan      0x02146A88  data
 *
 * Promoted by parks lane 2: the callee 0x020525A0 was filed first as an
 * EXACT entry (src/matched/func_020525A0.c, shard pkt_0205250C) and this
 * file's call site now resolves through the `matched` class.  No change to
 * the C was needed.
 *
 * EXACT: every byte is identical and the listing extent is now 72 bytes
 * (it once ran on to 0x02051620 for want of a label at 0x02051610).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020515CC.c \
 *       --func func_020515CC --addr 0x020515CC --cc 1.1p1 --arm
 */
#include "../include/Obj08873.h"
#include "../include/G_02146A88.h"

extern int func_020525A0(char *p, int b, void (*fn)(void *));
extern struct G_02146A88 *g_pParticleMan;
int func_020515CC(int *p, int a, int b, int c)
{
    int r;
    if (*(int *)((char *)((struct Obj08873 *)p)->f0 + 8) >= 0x18)
        return -1;
    ((int *)g_pParticleMan)[0x10] = c;
    r = func_020525A0((void *)p[0], a, (void (*)(void *))b);
    ((int *)g_pParticleMan)[0x10] = 0;
    p[2] = r;
    return r;
}
