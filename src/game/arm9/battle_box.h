#ifndef GAME_ARM9_BATTLE_BOX_H
#define GAME_ARM9_BATTLE_BOX_H

/* Public functions of battle_box.c, prototypes copied from their definitions. */

struct BattleBoxSave;
struct SaveControl;
struct BoxMonGroup;
struct BoxMon;
struct Party;

#include "../types.h"

u32 BATTLE_BOX_GetSize(void);
void BATTLE_BOX_Init(struct BattleBoxSave *box);
struct BattleBoxSave *BATTLE_BOX_GetFromSave(struct SaveControl *save);
void BATTLE_BOX_SetMon(struct BoxMonGroup *groups, u32 group, u32 index, const struct BoxMon *src);
struct Party *BATTLE_BOX_CreateParty(struct BoxMonGroup *box, int heap);
void BATTLE_BOX_StoreParty(struct BoxMonGroup *box, struct Party *party);
u32 BATTLE_BOX_HasMon(struct BoxMonGroup *box);
void BATTLE_BOX_SetLockFlags(struct BattleBoxSave *box, u32 flags);
void BATTLE_BOX_ClearLockFlags(struct BattleBoxSave *box, int flags);
struct BoxMon *BATTLE_BOX_GetMon(struct BoxMonGroup *groups, u32 group, u32 index);
u32 BATTLE_BOX_IsLocked(struct BattleBoxSave *box, u32 flags);

#endif
