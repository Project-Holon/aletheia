/*
 * function: UNION_ONESELF_TryStartSubEvent
 * address: 0x0217B80C
 * packet: pkt_ov019_0217B80C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: follower 0217B83C already has its own source and shard.
 * symbols:
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   func_02026474 0x02026474 thumb
 *   func_0217413C 0x0217413C thumb ov012
 */
#include "../include/Obj12521.h"
struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
typedef unsigned int   u32;
extern u32 func_02026474(void *obj);
extern int func_0217413C(int, int, unsigned char *);
int UNION_ONESELF_TryStartSubEvent(int a, int b)
{
    char *p;
    char *q;
    int result;
    p = (char *)func_02026474((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)a));
    result = 0;
    q = p + 0x3548;
    if (((struct Obj12521 *)q)->f4 != 0 && ((struct Obj12521 *)q)->f0 == 0) result = func_0217413C(a, b, (unsigned char *)p);
    return result;
}
