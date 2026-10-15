/*
 * function: UNION_ONESELF_CreateBattleTeamParty
 * address: 0x0217B9CC
 * packet: pkt_ov019_0217B9CC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_BOX_HasMon 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 * Return from the legacy void tail forwarder 0200BAC8 is used by this caller.
 */
#include "../include/Obj19401.h"
#include "../include/Obj19402.h"
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BATTLE_BOX_GetFromSave(void *);
extern unsigned int BATTLE_BOX_HasMon(void *);
extern void *func_0200BAF4(int, int);
void *UNION_ONESELF_CreateBattleTeamParty(char *p)
{
    void *a;
    a = BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(((struct Obj19402 *)(*(char * *)&((struct Obj19401 *)p)->f0))->f8));
    if (BATTLE_BOX_HasMon(a) == 0) return 0;
    return func_0200BAF4((int)a, 65);
}
