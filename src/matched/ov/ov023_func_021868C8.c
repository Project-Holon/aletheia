/*
 * function: OEKAKI_AdvanceQueueTail
 * address:  0x021868C8
 * packet:   pkt_ov023_021868C8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   OEKAKI_GetPrevQueueIndex  0x02186878  thumb
 *
 * The second loop indexes ((Grp *)p)[idx].r[j] in full and lets the
 * compiler hoist p + idx*30 itself: a named group pointer puts the 30*idx
 * temporary in r1 instead of r2.
 * Byte 6 of Rec (b5) exists only to make sizeof(Rec) == 6 so `r[i]` is `muls #6`.
 */
#include "../include/Obj09772.h"

typedef unsigned char u8;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
    u8 b5;
} Rec;

typedef struct {
    Rec r[5];
} Grp;

extern int OEKAKI_GetPrevQueueIndex(char *p);

void OEKAKI_AdvanceQueueTail(char *p)
{
    int i;
    int n;
    int m;
    Rec *r;

    n = 0;
    m = 0;
    i = 0;
    r = ((Grp *)p)[*(int *)(p + 0xBBC)].r;

    for (; i < 5; i++) {
        if (r[i].mid == 0) {
            n++;
        }
    }
    if (n == 5) {
        int idx = OEKAKI_GetPrevQueueIndex(p);
        int j;
        for (j = 0; j < 5; j++) {
            if (((Grp *)p)[idx].r[j].mid == 0) {
                m++;
            }
        }
    }
    if (m != 5) {
        ((struct Obj09772 *)p)->fBBC += 1;
        if (((struct Obj09772 *)p)->fBBC >= 100) {
            ((struct Obj09772 *)p)->fBBC = 0;
        }
    }
}
