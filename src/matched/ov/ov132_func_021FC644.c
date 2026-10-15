/*
 * function: MUS_COMM_FUNC_Create
 * address: 0x021FC644
 * packet: pkt_ov132_021FC644
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021FDE5C 0x021FDE5C data a4
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   GAME_COMM_Start  0x020263D8  thumb  arm9
 */
#include "../include/Obj05406.h"
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Comm;
extern void GAME_COMM_Start(struct Comm *p, u32 a1, u32 a2);
extern const char d_021FDE5C[];
void MUS_COMM_FUNC_Create(int a, void *b, void *c, int d)
{
    char *p;
    p = func_02030734(4, 0x1ac, 1, d_021FDE5C, 0x14c);
    ((struct Obj05406 *)p)->fC = d;
    ((struct Obj05406 *)p)->f54 = b;
    ((struct Obj05406 *)p)->f58 = GAMESYSTEM_GetGameData(b);
    ((struct Obj05406 *)p)->f50 = c;
    ((struct Obj05406 *)p)->f4 = 0;
    ((struct Obj05406 *)p)->f8 = 0;
    GAME_COMM_Start(c, 4, (u32)p);
}
