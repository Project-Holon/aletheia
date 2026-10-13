/*
 * function: MOVE_POKEMON_CreateTeleportEvent
 * address: 0x0215EE38
 * packet: pkt_ov010_0215EE38
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   MOVE_POKEMON_InitSkillWork 0x0215F0E8 thumb ov010
 *   MOVE_POKEMON_TeleportEventMain 0x0215EE68 thumb ov010
 *   GAME_BEACON_SEARCH_SetCountValue 0x02165534 thumb ov010
 */
#include "../include/Obj02057.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct C;
struct Desc;
struct Obj;
struct Pair;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MOVE_POKEMON_InitSkillWork(u32 *out, const struct Pair *in, u32 *ctx);
extern int MOVE_POKEMON_TeleportEventMain(void *a, int *st, struct C *c);
extern void GAME_BEACON_SEARCH_SetCountValue(void *a0);
void *MOVE_POKEMON_CreateTeleportEvent(void *p, void *ctx)
{
    void *task;
    GAME_BEACON_SEARCH_SetCountValue((void *)100);
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)MOVE_POKEMON_TeleportEventMain, 20);
    MOVE_POKEMON_InitSkillWork(func_020124E8(task), p, ctx);
    return task;
}
