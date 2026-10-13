/*
 * function: OEKAKI_PopStrokeGroup
 * address: 0x02186958
 * packet: pkt_ov023_02186958
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OEKAKI_ClearStrokeGroup 0x02186938 thumb ov023
 */
#include "../include/Obj05109.h"
typedef unsigned char u8;
typedef struct { u8 b[4]; u8 lo:3; u8 mid:3; u8 hi:2; u8 b5; } Rec;
extern void OEKAKI_ClearStrokeGroup(Rec *);
void OEKAKI_PopStrokeGroup(char *p)
{
    if (((struct Obj05109 *)p)->fBB8 != ((struct Obj05109 *)p)->fBBC) {
        OEKAKI_ClearStrokeGroup((Rec *)(p + ((struct Obj05109 *)p)->fBB8 * 30));
        ((struct Obj05109 *)p)->fBB8 += 1;
        if (((struct Obj05109 *)p)->fBB8 >= 100) ((struct Obj05109 *)p)->fBB8 = 0;
    }
}
