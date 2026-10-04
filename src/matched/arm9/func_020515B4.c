/*
 * function: func_020515B4
 * address:  0x020515B4
 * packet:   pkt_02051504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Promoted by parks lane 2: the callee 0x02052634 was filed first as an
 * EXACT entry (src/matched/func_02052634.c, shard pkt_0205250C) and this
 * file's call site now resolves through the `matched` class.  No change to
 * the C was needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020515B4.c \
 *       --func func_020515B4 --addr 0x020515B4 --cc 1.1p1 --arm
 */
#include "../include/Obj11458.h"

typedef unsigned int u32;

extern int func_02052634(char *p, int b, int c);

int func_020515B4(void *p, int b, int c)
{
    int r = func_02052634((char *)(((struct Obj11458 *)p)->f0), b, c);
    ((struct Obj11458 *)p)->f8 = r;
    return r;
}
