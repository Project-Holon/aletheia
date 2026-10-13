/*
 * function: EVENT_BATTLE_FinishBattleTask
 * address: 0x0216EFF0
 * packet: pkt_ov010_0216EFF0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * func_0202C83C's body consumes only r0/r1, forwarding those to
 * func_0202C794; original supplies no new r2/r3. Legacy trailing
 * arguments are omitted. GAME_DATA_GetPlayerZoneId consumes the preceding result.
 * symbols:
 *   GAME_DATA_SetFieldMode 0x02012A4C thumb
 *   MOVE_POKEMON_HandleBattleResult 0x0215E5B0 thumb ov010
 *   EVENT_BATTLE_NotifyBattleEnd 0x0216EE7C thumb ov010
 *   EVENT_BATTLE_SetResultSound 0x0216EF84 thumb ov010
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   func_0202C83C 0x0202C83C thumb
 */
#include "../include/Obj00020.h"
#include "../include/Obj19144.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct BigObj;
struct Rec44;
struct SaveBlock;
extern void GAME_DATA_SetFieldMode(struct BigObj *p, u32 v);
struct BattleEndCtx;
struct Work;
extern void MOVE_POKEMON_HandleBattleResult(void *a0, struct Work *w);
extern void EVENT_BATTLE_NotifyBattleEnd(struct BattleEndCtx *c);
extern int EVENT_BATTLE_SetResultSound(int a0);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern int func_0202C83C(int,int);
void EVENT_BATTLE_FinishBattleTask(int *p,void *a) {
    GAME_DATA_SetFieldMode(a,((struct Obj19144 *)(*(char * *)&((struct Obj00020 *)p)->f8))->f8C);
    MOVE_POKEMON_HandleBattleResult(a,(void *)p[2]);
    EVENT_BATTLE_NotifyBattleEnd((struct BattleEndCtx *)p);
    EVENT_BATTLE_SetResultSound((int)p);
    func_0202C83C(p[0],GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(a)));
}
