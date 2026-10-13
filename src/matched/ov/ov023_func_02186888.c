/*
 * function: OEKAKI_AdvanceQueueTailIfUsed
 * address:  0x02186888
 * packet:   pkt_ov023_02186888
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   OEKAKI_GetPrevQueueIndex  0x02186878  thumb
 */
#include "../include/Obj07611.h"

typedef unsigned char u8;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
    u8 pad;
} Rec;

extern int OEKAKI_GetPrevQueueIndex(char *p);

void OEKAKI_AdvanceQueueTailIfUsed(char *p)
{
    if (((Rec *)(p + ((struct Obj07611 *)p)->fBBC * 30))->mid != 0
        || ((Rec *)(p + OEKAKI_GetPrevQueueIndex(p) * 30))->mid != 0) {
        ((struct Obj07611 *)p)->fBBC += 1;
        if (((struct Obj07611 *)p)->fBBC >= 100) {
            ((struct Obj07611 *)p)->fBBC = 0;
        }
    }
}
