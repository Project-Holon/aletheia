#ifndef GAME_OV019_UNION_CHARA_H
#define GAME_OV019_UNION_CHARA_H
struct UnionEffWork;
struct WifiList;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of union_chara.c, prototypes copied from their definitions. */

struct GameData;

#include "../ov012/union_comm_types.h"
#include "../types.h"
#include "../bool_types.h"

void UNION_CHARA_ClearTable(UnionRoomWork *work);
int UNION_CHARA_SetNextAction(UnionCharaSlot *slot, char nextAction);
struct Mmdl *UNION_CHARA_AddMmdl(UnionRoomWork *work, struct GameData *gameData, u16 trainerView, int objId);
u16 UNION_CHARA_MakeObjId(UnionBeaconPc *beaconPc, UnionCharaSlot *slot);
Bool UNION_CHARA_IsChildObjId(u16 objId);
u16 UNION_CHARA_GetBeaconIndex(unsigned int objId);
int UNION_CHARA_GetSexByObjId(UnionRoomWork *work, u16 objId);
int UNION_CHARA_IsUnionObjId(u16 objId);
int UNION_CHARA_CheckTalkable(UnionRoomWork *work, u16 objId);
void *UNION_CHARA_GetMmdl(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionCharaSlot *slot);
UnionCharaSlot *UNION_CHARA_AddSlot(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionMember *member, int memberIndex, int visible, void **mmdlOut);
void UNION_CHARA_DeleteSlot(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionCharaSlot *slot);
void UNION_CHARA_AddBeaconMembers(UnionRoomWork *work, void *metTrainers, struct WifiList *wifiFriends, struct UnionEffWork *markSys, UnionBeaconPc *beaconPc);
int UNION_CHARA_CheckMemberUnique(UnionRoomWork *work, UnionBeaconPc *ownerPc, u8 *mac);
int UNION_CHARA_FocusRequestedMember(UnionRoomWork *work, UnionBeaconPc *beaconPc);
void UNION_CHARA_Main(UnionRoomWork *work, struct GameData *gameData, void *fieldMap);
int UNION_CHARA_RunAction(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap);
int UNION_CHARA_TickBeaconLife(UnionRoomWork *work, UnionBeaconPc *beaconPc);
void UNION_CHARA_RefreshParentMarks(UnionRoomWork *work, struct GameData *gameData, void *fieldMap);
int UNION_CHARA_ActionIdle(UnionRoomWork *work, UnionCharaSlot *slot);
int UNION_CHARA_ActionAppear(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step);
int UNION_CHARA_ActionDisappear(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step);
int UNION_CHARA_ActionTalk(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step);
void UNION_CHARA_ProcessBeaconUpdates(UnionRoomWork *work);
void UNION_CHARA_OnBeaconUpdate(UnionRoomWork *work, UnionBeaconPc *beaconPc);
/* END mkheaders: generated region */

#endif
