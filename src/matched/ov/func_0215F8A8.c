/*
 * function: SCRCMD_NETWORK_CreateCommBattleEvent
 * address:  0x0215F8A8
 * packet:   pkt_0215F8A8
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, three sub-init calls over the new node.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MOVE_POKEMON_SpawnPendingEntries  0x0215E580  thumb  ov010
 *   SCRCMD_NETWORK_CommBattleEventMain  0x0215F734  thumb  ov010
 *   SCRCMD_NETWORK_InitCommBattleOv180Param  0x0215F900  thumb  ov010
 *   SCRCMD_NETWORK_InitCommBattleOv181Param  0x0215F920  thumb  ov010
 *   SCRCMD_NETWORK_InitCommBattleStepSequence  0x0215F948  thumb  ov010
 */
#include "../include/Obj04132.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc;
struct Obj;
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u8 *GAME_DATA_GetMyStatus(void *p);
void MOVE_POKEMON_SpawnPendingEntries(void *a);
struct Work;
int SCRCMD_NETWORK_CommBattleEventMain(void *evt, u32 *i, struct Work *w);
void SCRCMD_NETWORK_InitCommBattleOv180Param(void *obj);
int SCRCMD_NETWORK_InitCommBattleOv181Param(int a0);
void SCRCMD_NETWORK_InitCommBattleStepSequence(u8 *p);

void *SCRCMD_NETWORK_CreateCommBattleEvent(void *p, int a1)
{
    int r7 = (int)GAMESYSTEM_GetGameData(p);
    void *r0v = func_020122C0(p, 0, SCRCMD_NETWORK_CommBattleEventMain, 0x7C);
    char *r4 = func_020124E8(r0v);

    ((struct Obj04132 *)r4)->f0 = (int)p;
    ((struct Obj04132 *)r4)->f4 = r7;
    ((struct Obj04132 *)r4)->f8 = a1;
    ((struct Obj04132 *)r4)->f10 = (int)GAME_DATA_GetMyStatus((void *)r7);
    ((struct Obj04132 *)r4)->f78 = 0;
    ((struct Obj04132 *)r4)->f14 = (int)p;
    ((struct Obj04132 *)r4)->f18 = a1;
    MOVE_POKEMON_SpawnPendingEntries((void *)r7);
    SCRCMD_NETWORK_InitCommBattleOv180Param(r4);
    SCRCMD_NETWORK_InitCommBattleOv181Param((int)r4);
    SCRCMD_NETWORK_InitCommBattleStepSequence((u8 *)r4);
    return r0v;
}
