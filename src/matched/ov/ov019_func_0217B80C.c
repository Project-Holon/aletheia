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
 *   GAME_COMM_GetWork 0x02026474 thumb
 *   UNION_SCENE_CreateSubEvent 0x0217413C thumb ov012
 */
#include "../include/Obj12521.h"
struct Ctx;
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
typedef unsigned int   u32;
extern u32 GAME_COMM_GetWork(void *obj);
extern int UNION_SCENE_CreateSubEvent(int, int, unsigned char *);
int UNION_ONESELF_TryStartSubEvent(int a, int b)
{
    char *p;
    char *q;
    int result;
    p = (char *)GAME_COMM_GetWork((void *)GAMESYSTEM_GetGameComm((const struct Ctx *)a));
    result = 0;
    q = p + 0x3548;
    if (((struct Obj12521 *)q)->f4 != 0 && ((struct Obj12521 *)q)->f0 == 0) result = UNION_SCENE_CreateSubEvent(a, b, (unsigned char *)p);
    return result;
}
