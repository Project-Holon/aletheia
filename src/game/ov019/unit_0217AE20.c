/*
 * file:     unit_0217AE20.c
 * unit:     yes
 * function: UNION_CHARA_ClearTable, UNION_CHARA_SetNextAction, UNION_CHARA_AddMmdl, UNION_CHARA_MakeObjId, UNION_CHARA_IsChildObjId, UNION_CHARA_GetBeaconIndex, UNION_CHARA_GetSexByObjId, UNION_CHARA_IsUnionObjId, UNION_CHARA_CheckTalkable, UNION_CHARA_GetMmdl, UNION_CHARA_AddSlot, UNION_CHARA_DeleteSlot, UNION_CHARA_AddBeaconMembers, UNION_CHARA_CheckMemberUnique, UNION_CHARA_FocusRequestedMember, UNION_CHARA_Main, UNION_CHARA_RunAction, UNION_CHARA_TickBeaconLife, UNION_CHARA_RefreshParentMarks, UNION_CHARA_ActionIdle, UNION_CHARA_ActionAppear, UNION_CHARA_ActionDisappear, UNION_CHARA_ActionTalk, UNION_CHARA_ProcessBeaconUpdates, UNION_CHARA_OnBeaconUpdate, UNION_ONESELF_TryStartSubEvent, UNION_ONESELF_GetFieldTalkEvent, UNION_ONESELF_RunPlayCategory, UNION_ONESELF_SetNextPlayCategory, UNION_ONESELF_SetNextPlayCategoryInMainPhase, UNION_ONESELF_GetRegulationId, UNION_ONESELF_GetRegulationFlag, UNION_ONESELF_IsBattleStatus, UNION_ONESELF_CreateBattleTeamParty, UNION_ONESELF_DeleteParty, UNION_ONESELF_LoadRegulation, UNION_ONESELF_CheckMyParty, UNION_ONESELF_CheckBattleTeamParty, UNION_ONESELF_CheckEntryParties, UNION_ONESELF_SetFieldBusy, UNION_ONESELF_CheckNetError, UNION_ONESELF_CheckNetErrorExit, UNION_ONESELF_IdleStart, UNION_ONESELF_IdleMain, UNION_ONESELF_ErrorMain, UNION_ONESELF_NoOpMain, UNION_ONESELF_FieldExitMain
 * address:  0x0217AE20
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012964  0x02012964  thumb
 *   func_02025C74  0x02025C74  thumb
 *   FLDMMDL_InitPosRecord  0x0216E618  thumb  ov010
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   gUnionCharaMmdlHeader     0x0217FFF8  data  ov019  a4
 *   gUnionCharaSeatPos     0x0218001C  data  ov019  a2
 *   gUnionCharaMemberOffset     0x0217FFE4  data  ov019  a2
 *   FLDMMDL_SysSearchObjId 0x0216DE94 thumb ov010
 *   func_02034714 0x02034714 arm
 *   gUnionEmptyString0 0x021807E0 data a1
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   FIELDMAP_GetUnionEff  0x02188CE0  thumb  ov021
 *   UNION_EFF_DeleteIcon  0x0217F958  thumb  ov019
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   func_0217F894  0x0217F894  thumb  ov019
 *   func_0200EDC4  0x0200EDC4  thumb
 *   UNION_EFF_AddIcon  0x0217F948  thumb  ov019
 *   memcmp  0x0203EFC8  arm
 *   func_02012114 0x02012114  thumb
 *   UNION_EFF_AddAnimEffect 0x0217F93C  thumb  ov019
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0201283C  0x0201283C  thumb
 *   gUnionCharaActionStart  0x02180044  data  a4
 *   gUnionCharaActionMain  0x02180048  data  a4
 *   gUnionCharaActionEnd  0x0218004C  data  a4
 *   UNION_MSG_GetCategoryTableValue  0x0217F060  thumb  ov019
 *   func_0217F858  0x0217F858  thumb  ov019
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_ChangeMoveCode  0x0216E0E8  thumb  ov010
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp 0x0216D5F8  thumb  ov010
 *   FLDMMDL_SetStatusBit 0x0216D548  thumb  ov010
 *   FLDMMDL_ClearStatusBit 0x0216D550  thumb  ov010
 *   UNION_CHAT_LOG_Add 0x021BBA70  thumb  ov021
 *   UNION_COMM_SetSituationParam 0x021734A8  thumb  ov012
 *   func_02012138 0x02012138 thumb
 *   GAME_COMM_GetWork 0x02026474 thumb
 *   func_0217413C 0x0217413C thumb ov012
 *   gUnionOneselfActionStart  0x02180074  data  a4
 *   gUnionOneselfActionMain  0x02180078  data  a4
 *   gUnionOneselfActionEnd  0x0218007C  data  a4
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BBA8 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_020307B0 0x020307B0 arm
 *   gUnionEmptyString1 0x021807E4 data a1
 *   POKE_REGULATION_LoadInto 0x0201A364 thumb
 *   func_0200AEE8 0x0200AEE8 thumb
 *   func_02012934 0x02012934 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 *   FIELDMAP_CTRL_GRID_SetBusy 0x021A2E44 thumb ov021
 *   func_0200FB24 0x0200FB24 thumb
 *   UNION_COMM_InitConnectInfo 0x02173524 thumb ov012
 *   UNION_MSG_CloseAllWindows 0x0217F074 thumb ov019
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   UNION_COMM_RequestRestart  0x02172D20  thumb  ov012
 *   UNION_COMM_IsResetting  0x02172D68  thumb  ov012
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   func_0217F7E4  0x0217F7E4  thumb  ov019
 *   UNION_MSG_CheckTalkPrintEnd  0x0217F1EC  thumb  ov019
 *   func_02012124  0x02012124  thumb
 *   UNION_COMM_RequestShutdown  0x02172D38  thumb  ov012
 *   UNION_COMM_ReleaseWorks  0x02173420  thumb  ov012
 *   UNION_COMM_RequestStart  0x02172D50  thumb  ov012
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

typedef signed int     s32;

typedef enum { FALSE, TRUE } BOOL;

typedef struct { s32 x, y, z; } VecFx32;
#include "../ov012/union_comm_types.h"
#include "unit_0217AE20_types.h"

struct GameData;
struct GameSystem;
struct Regulation;

void MI_CpuFill8(void *dstp, u8 data, u32 size);
int memcmp(const void *a, const void *b, int n);

extern u32 func_02012964(const struct GameData *gameData);
extern u32 func_02025C74(u32 trainerView);
extern void FLDMMDL_InitPosRecord(void *header, u32 gridX, u32 gridZ, int gridY);
extern int FLDMMDL_AddMmdl(int mmdlSys, void *header, int param);
extern void *FLDMMDL_SysSearchObjId(void *mmdlSys, unsigned int objId);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *mmdl, unsigned int vanish);
extern void *func_0201210C(struct GameSystem *gameSystem);
extern u32 FIELDMAP_GetUnionEff(void *fieldMap);
extern void UNION_EFF_DeleteIcon(char *markSys, u32 mmdl);
extern void FLDMMDL_DeleteMmdl(void *mmdl);
extern void OS_GetMacAddress(void *ownMac);
extern int func_0217F894(void *wifiFriends, UnionBeaconPc *beaconPc);
extern int func_0200EDC4(void *metTrainers, u32 trainerId);
extern void UNION_EFF_AddIcon(char *markSys, u32 mmdl, u32 kind);
extern unsigned int func_02012114(struct GameSystem *gameSystem);
extern void UNION_EFF_AddAnimEffect(int markSys, int mmdl);
extern void *GAME_DATA_GetSaveControl(const struct GameData *gameData);
extern void *func_0200ED48(void *saveControl);
extern u32 func_0201283C(const struct GameData *gameData);
extern int UNION_MSG_GetCategoryTableValue(int status);
extern int func_0217F858(int status);
extern int FLDMMDL_CheckPossibleAcmd(int mmdl);
extern void FLDMMDL_SetAcmd(void *mmdl, u16 acmd);
extern u16 FLDMMDL_GetMoveCode(void *mmdl);
extern int FLDMMDL_ChangeMoveCode(int mmdl, int moveCode);
extern void FLDMMDL_GetGridNowPos(int mmdl, s16 *pos);
extern int FLDMMDL_CheckEndAcmd(int mmdl);
extern int FLDMMDL_EndAcmd(char *mmdl);
extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);
extern void *FIELD_PLAYER_GetMmdl(void *fieldPlayer);
extern u16 FLDMMDL_GetDirDisp(void *mmdl);
extern u32 *FLDMMDL_SetStatusBit(u32 *mmdl, u32 bit);
extern u32 *FLDMMDL_ClearStatusBit(u32 *mmdl, u32 bit);
extern void UNION_CHAT_LOG_Add(UnionRoomWork *work, UnionBeaconPc *beaconPc, u16 *outValue, u8 mode);
extern void UNION_COMM_SetSituationParam(UnionRoomWork *work, u32 id, u32 value);
extern unsigned int func_02012138(struct GameSystem *gameSystem);
extern u32 GAME_COMM_GetWork(void *gameComm);
extern int func_0217413C(struct GameSystem *gameSystem, void *fieldMap, UnionRoomWork *work);
extern void *func_0200BAC8(void *saveControl);
extern unsigned int func_0200BBA8(void *battleTeam);
extern void *func_0200BAF4(int battleTeam, int heapId);
extern u32 func_020307B0(void *p);
extern void POKE_REGULATION_LoadInto(int regulationId, struct Regulation *regulation);
extern void func_0200AEE8(struct Regulation *regulation, u32 id, s32 value);
extern void *func_02012934(const struct GameData *gameData);
extern int POKE_REGULATION_CheckParty(struct Regulation *regulation, void *party, unsigned int *violationMask);
extern void FIELDMAP_CTRL_GRID_SetBusy(void *fieldMap, unsigned int busy);
extern unsigned int func_0200FB24(void);
extern void UNION_COMM_InitConnectInfo(UnionRoomWork *work, UnionConnectInfo *connect);
extern void UNION_MSG_CloseAllWindows(UnionRoomWork *work);
extern void *FIELDMAP_GetMmdlSys(void *fieldMap);
extern int FIELD_PLAYER_GetFrontGridPos(u32 fieldPlayer, u32 outGridX, u32 outGridY, u32 outGridZ);
extern void  UNION_COMM_RequestRestart(UnionRoomWork *work);
extern int   UNION_COMM_IsResetting(UnionRoomWork *work);
extern u16   FLDMMDL_GetObjId(void *mmdl);
extern void *FLDMMDL_SysSearchGridPos(u32 mmdlSys, u32 gridX, u32 gridZ, u32 gridY);
extern int   GFL_NET_GetNegotiationNum(void);
extern u32   KEY_GetTrg(void);
extern int func_0217F7E4(u32 fieldMap);
extern unsigned int UNION_MSG_CheckTalkPrintEnd(UnionRoomWork *work);
extern void func_02012124(struct GameSystem *gameSystem, u32 state);
extern void UNION_COMM_RequestShutdown(UnionRoomWork *work);
extern void UNION_COMM_ReleaseWorks(UnionRoomWork *work);
extern void UNION_COMM_RequestStart(UnionRoomWork *work);
void UNION_CHARA_ClearTable(UnionRoomWork *work);
int UNION_CHARA_SetNextAction(UnionCharaSlot *slot, char nextAction);
int UNION_CHARA_AddMmdl(UnionRoomWork *work, struct GameData *gameData, u16 trainerView, int objId);
u16 UNION_CHARA_MakeObjId(UnionBeaconPc *beaconPc, UnionCharaSlot *slot);
BOOL UNION_CHARA_IsChildObjId(u16 objId);
u16 UNION_CHARA_GetBeaconIndex(unsigned int objId);
int UNION_CHARA_GetSexByObjId(UnionRoomWork *work, u16 objId);
int UNION_CHARA_IsUnionObjId(u16 objId);
int UNION_CHARA_CheckTalkable(UnionRoomWork *work, u16 objId);
void *UNION_CHARA_GetMmdl(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionCharaSlot *slot);
UnionCharaSlot *UNION_CHARA_AddSlot(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionMember *member, int memberIndex, int visible, int *mmdlOut);
void UNION_CHARA_DeleteSlot(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionCharaSlot *slot);
void UNION_CHARA_AddBeaconMembers(UnionRoomWork *work, u32 metTrainers, u32 wifiFriends, u32 markSys, UnionBeaconPc *beaconPc);
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
int UNION_ONESELF_TryStartSubEvent(struct GameSystem *gameSystem, void *fieldMap);
int UNION_ONESELF_GetFieldTalkEvent(void *gameSystem, void *pos);
int UNION_ONESELF_RunPlayCategory(UnionRoomWork *work, void *fieldMap);
int UNION_ONESELF_SetNextPlayCategory(UnionRoomWork *work, int playCategory);
int UNION_ONESELF_SetNextPlayCategoryInMainPhase(UnionRoomWork *work, char playCategory);
int UNION_ONESELF_GetRegulationId(int status);
int UNION_ONESELF_GetRegulationFlag(int status);
int UNION_ONESELF_IsBattleStatus(unsigned int status);
void *UNION_ONESELF_CreateBattleTeamParty(UnionRoomWork *work);
void UNION_ONESELF_DeleteParty(void *party);
void UNION_ONESELF_LoadRegulation(UnionRoomWork *work, int status);
int UNION_ONESELF_CheckMyParty(UnionRoomWork *work, unsigned int *violationMask);
int UNION_ONESELF_CheckBattleTeamParty(UnionRoomWork *work, unsigned int *violationMask);
int UNION_ONESELF_CheckEntryParties(UnionRoomWork *work, int status, unsigned int *myPartyMask, unsigned int *battleTeamMask);
void UNION_ONESELF_SetFieldBusy(UnionRoomWork *work, void *fieldMap, unsigned int busy);
int UNION_ONESELF_CheckNetError(UnionRoomWork *work);
int UNION_ONESELF_CheckNetErrorExit(UnionRoomWork *work);
int UNION_ONESELF_IdleStart(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap);
int UNION_ONESELF_IdleMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap);
int UNION_ONESELF_ErrorMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step);
extern const UnionCharaMmdlHeader gUnionCharaMmdlHeader;
extern const UnionGridPos gUnionCharaSeatPos[];
extern const UnionGridPos gUnionCharaMemberOffset[];
extern const char gUnionEmptyString0[];
extern UnionCharaActionEntry gUnionCharaActionStart[];
extern UnionCharaActionEntry gUnionCharaActionMain[];
extern UnionCharaActionEntry gUnionCharaActionEnd[];
extern UnionOneselfActionEntry gUnionOneselfActionStart[];
extern UnionOneselfActionEntry gUnionOneselfActionMain[];
extern UnionOneselfActionEntry gUnionOneselfActionEnd[];
extern const char gUnionEmptyString1[];






void UNION_CHARA_ClearTable(UnionRoomWork *work)
{
    MI_CpuFill8(work->charaSlot, 0, sizeof(UnionCharaSlot) * UNION_CHARA_MAX);
}





int UNION_CHARA_SetNextAction(UnionCharaSlot *slot, char nextAction)
{
    slot->nextAction = nextAction;
    return 1;
}






/*
 * What closed it: the spilled third parameter is u16, not u32. As u32 the
 * scheduler hoists its reload (`ldr r0,[sp]`) above the `strh` of d into
 * the local; as u16 the reload stays after it (see
 * docs/notes/pkt_ov019_0217AE40.c.txt for the earlier near miss).
 */
int UNION_CHARA_AddMmdl(UnionRoomWork *work, struct GameData *gameData, u16 trainerView, int objId)
{
    int mmdlSys;
    u16 beaconIndex, memberIndex;
    UnionCharaMmdlHeader header;

    mmdlSys = func_02012964(gameData);
    beaconIndex = (u16)(objId >> 8);
    memberIndex = (u16)((objId & 0xff) - 0x20);
    header = gUnionCharaMmdlHeader;
    header.f.objId = objId;
    header.f.graphicsId = func_02025C74(trainerView);
    if (memberIndex != 0)
        header.f.moveCode = 15;
    FLDMMDL_InitPosRecord(&header, (u16)(gUnionCharaSeatPos[beaconIndex].x + gUnionCharaMemberOffset[memberIndex].x),
                  (u16)(gUnionCharaSeatPos[beaconIndex].z + gUnionCharaMemberOffset[memberIndex].z), 0);
    return FLDMMDL_AddMmdl(mmdlSys, &header, 422);
}





u16 UNION_CHARA_MakeObjId(UnionBeaconPc *beaconPc, UnionCharaSlot *slot) { return (beaconPc->index << 8) | (slot->memberIndex + 0x20); }





BOOL UNION_CHARA_IsChildObjId(u16 objId) { if ((u16)((unsigned char)objId - 0x20) == 0) return FALSE; else return TRUE; }






u16 UNION_CHARA_GetBeaconIndex(unsigned int objId)
{
    return (u16)(objId >> 8);
}





int UNION_CHARA_GetSexByObjId(UnionRoomWork *work, u16 objId) { int i; UnionCharaSlot *slot; slot = work->charaSlot; for(i=0;i<UNION_CHARA_MAX;i++,slot++) { if(slot->inUse == 1 && slot->beaconPc != 0 && objId == UNION_CHARA_MakeObjId(slot->beaconPc,slot)) return slot->sex; } return 0; }





int UNION_CHARA_IsUnionObjId(u16 objId) { unsigned int memberKey; memberKey = (unsigned char)objId; if ((u16)memberKey >= 0x20) return 1; else return 0; }






int UNION_CHARA_CheckTalkable(UnionRoomWork *work, u16 objId)
{
    UnionCharaSlot *slot;
    int i;

    slot = work->charaSlot;
    for (i = 0; i < UNION_CHARA_MAX; i++, slot++) {
        if (slot->inUse == 1 && slot->beaconPc != 0 && slot->beaconPc->life != 0
            && objId == ((slot->beaconPc->index << 8) | (slot->memberIndex + 0x20))) {
            if (slot->action == 2 || slot->action == 1 || (u8)(slot->nextAction + 0xff) <= 1)
                return 0;
            return 1;
        }
    }
    return 0;
}





void *UNION_CHARA_GetMmdl(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionCharaSlot *slot) { u16 objId; void *mmdl; objId = UNION_CHARA_MakeObjId(beaconPc,slot); mmdl = FLDMMDL_SysSearchObjId((void *)func_02012964(work->parent->gameData),objId); if(mmdl == 0) func_02034714(gUnionEmptyString0,0,gUnionEmptyString0); return mmdl; }






UnionCharaSlot *UNION_CHARA_AddSlot(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionMember *member, int memberIndex, int visible, int *mmdlOut)
{
    UnionCharaSlot *slot;
    int i;
    int mmdl;

    slot = work->charaSlot;
    for (i = 0; i < UNION_CHARA_MAX; i++, slot++) {
        if (slot->inUse == 0) {
            slot->beaconPc = beaconPc;
            slot->trainerView = member->trainerView;
            slot->sex = member->sex;
            slot->memberIndex = memberIndex;
            slot->inUse = 1;
            mmdl = UNION_CHARA_MakeObjId(beaconPc, slot);
            mmdl = UNION_CHARA_AddMmdl(work, work->parent->gameData, member->trainerView, mmdl);
            if (visible == 0)
                FLDMMDL_SetStatusBitVanish((unsigned int *)mmdl, 1);
            *mmdlOut = mmdl;
            return slot;
        }
    }
    func_02034714(gUnionEmptyString0, 0, gUnionEmptyString0);
    return 0;
}







void UNION_CHARA_DeleteSlot(UnionRoomWork *work, UnionBeaconPc *beaconPc, UnionCharaSlot *slot)
{
    void *fieldMap;
    void *mmdl;

    fieldMap = func_0201210C(work->parent->gameSystem);
    mmdl = UNION_CHARA_GetMmdl(work, beaconPc, slot);
    if (fieldMap != 0 && mmdl != 0)
        UNION_EFF_DeleteIcon((char *)FIELDMAP_GetUnionEff(fieldMap), (u32)mmdl);
    FLDMMDL_DeleteMmdl(mmdl);
    MI_CpuFill8(slot, 0, sizeof(UnionCharaSlot));
}







void UNION_CHARA_AddBeaconMembers(UnionRoomWork *work, u32 metTrainers, u32 wifiFriends, u32 markSys, UnionBeaconPc *beaconPc)
{
    int mmdl;
    u8 ownMac[8];
    int i;

    if (beaconPc->life == 0)
        return;
    OS_GetMacAddress(ownMac);
    for (i = 0; i < UNION_MEMBER_MAX; i++) {
        if (beaconPc->charaSlot[i] == 0 && beaconPc->beacon.group.member[i].valid == 1
            && memcmp(ownMac, (const u8 *)(&beaconPc->beacon.group.member[i]), 6) != 0
            && UNION_CHARA_CheckMemberUnique(work, beaconPc, (u8 *)(&beaconPc->beacon.group.member[i])) != 0) {
            beaconPc->charaSlot[i] = UNION_CHARA_AddSlot(work, beaconPc, &beaconPc->beacon.group.member[i], i, 0, &mmdl);
            beaconPc->charaSlot[i]->action = 1;
            UNION_CHARA_SetNextAction(beaconPc->charaSlot[i], 0);
            if (i == 0) {
                if (func_0217F894((void *)wifiFriends, beaconPc) == 1)
                    UNION_EFF_AddIcon((char *)markSys, mmdl, 0);
                else if (func_0200EDC4((void *)metTrainers, beaconPc->beacon.trainerId) == 1)
                    UNION_EFF_AddIcon((char *)markSys, mmdl, 1);
            }
        }
    }
}






int UNION_CHARA_CheckMemberUnique(UnionRoomWork *work, UnionBeaconPc *ownerPc, u8 *mac)
{
    UnionBeaconPc *pc = work->beaconPc;
    int i;
    int j;

    for (i = 0; i < UNION_BEACON_PC_MAX; i++, pc++) {
        if (pc == ownerPc || pc->beacon.valid != 1) {
            continue;
        }
        for (j = 0; j < UNION_MEMBER_MAX; j++) {
            if (pc->beacon.group.member[j].valid == 1 && memcmp(mac, pc->beacon.group.member[j].mac, 6) == 0) {
                if (pc->life != 0) {
                    pc->life = 1;
                }
                return 0;
            }
        }
    }
    return 1;
}






int UNION_CHARA_FocusRequestedMember(UnionRoomWork *work, UnionBeaconPc *beaconPc)
{
    int i;
    UnionCharaSlot *slot;
    int markSys;
    int objId;

    for (i = 0; i < UNION_MEMBER_MAX; i++) {
        slot = beaconPc->charaSlot[i];
        if (slot == 0 || beaconPc->beacon.group.member[i].valid != 1) {
            continue;
        }
        if (memcmp(beaconPc->beacon.group.member[i].mac, work->mySituation.focusMac, 6) != 0) {
            continue;
        }
        if (func_02012114(work->parent->gameSystem) == 1) {
            markSys = FIELDMAP_GetUnionEff(func_0201210C(work->parent->gameSystem));
            if (markSys != 0) {
                objId = UNION_CHARA_MakeObjId(beaconPc, slot);
                objId = (int)FLDMMDL_SysSearchObjId((void *)func_02012964(work->parent->gameData), objId);
                if (objId != 0) {
                    UNION_EFF_AddAnimEffect(markSys, objId);
                }
            }
        }
        MI_CpuFill8(work->mySituation.focusMac, 0, 6);
        return 1;
    }
    return 0;
}






/*
 * Addresses are Black-image addresses.
 */
void UNION_CHARA_Main(UnionRoomWork *work, struct GameData *gameData, void *fieldMap)
{
    int i;
    int focusPending;
    u32 metTrainers;
    u32 wifiFriends;
    u32 markSys;
    UnionBeaconPc *beaconPc;
    u8 zeroMac[6] = {0, 0, 0, 0, 0, 0};

    focusPending = 0;
    metTrainers = (u32)func_0200ED48(GAME_DATA_GetSaveControl(gameData));
    wifiFriends = func_0201283C(gameData);
    markSys = FIELDMAP_GetUnionEff(fieldMap);
    func_02012964(gameData);
    if (memcmp(zeroMac, work->mySituation.focusMac, 6) != 0) {
        focusPending = 1;
    }
    beaconPc = work->beaconPc;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++, beaconPc++) {
        if (beaconPc->beacon.valid == 1) {
            int freeCount;
            int j;
            UnionCharaSlot *slot;

            UNION_CHARA_TickBeaconLife(work, beaconPc);
            UNION_CHARA_AddBeaconMembers(work, metTrainers, wifiFriends, markSys, beaconPc);
            if (focusPending == 1) {
                if (UNION_CHARA_FocusRequestedMember(work, beaconPc) == 1) {
                    focusPending = 0;
                }
            }
            freeCount = 0;
            for (j = 0; j < UNION_MEMBER_MAX; j++) {
                slot = beaconPc->charaSlot[j];
                if (slot != 0) {
                    if (UNION_CHARA_RunAction(work, slot, fieldMap) == 0) {
                        UNION_CHARA_DeleteSlot(work, beaconPc, slot);
                        beaconPc->charaSlot[j] = 0;
                        freeCount++;
                    }
                } else {
                    freeCount++;
                }
            }
            if (freeCount >= 5 && beaconPc->life == 0) {
                MI_CpuFill8(beaconPc, 0, sizeof(UnionBeaconPc));
            }
        }
    }
    MI_CpuFill8(work->mySituation.focusMac, 0, 6);
}






int UNION_CHARA_RunAction(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap)
{
    int result = 1;
    UnionCharaActionFunc func;

    switch (slot->phase) {
    case 0:
        func = gUnionCharaActionStart[slot->action].func;
        break;
    case 1:
        func = gUnionCharaActionMain[slot->action].func;
        break;
    case 2:
        func = gUnionCharaActionEnd[slot->action].func;
        break;
    }
    if (func != 0) {
        result = func(work, slot, fieldMap, &slot->step);
    }
    if (result == 1) {
        slot->step = 0;
        slot->phase = slot->phase + 1;
        if (slot->phase > 2) {
            if (slot->action == 2) {
                return 0;
            }
            slot->phase = 0;
            slot->action = slot->nextAction;
            slot->nextAction = 0;
        }
    }
    return 1;
}






int UNION_CHARA_TickBeaconLife(UnionRoomWork *work, UnionBeaconPc *beaconPc)
{
    UnionMySituation *situation = (&work->mySituation);
    if ((UnionBeaconPc *)situation->connect.talkParam == beaconPc || situation->connect.talkPc == beaconPc ||
        (UnionBeaconPc *)situation->connect.connectParam == beaconPc || situation->connect.connectPc == beaconPc) {
        if (beaconPc->life == 0) {
            beaconPc->life = 1;
        }
        return 1;
    }
    if (beaconPc->life == 0) {
        return 0;
    }
    beaconPc->life -= 1;
    return 1;
}






void UNION_CHARA_RefreshParentMarks(UnionRoomWork *work, struct GameData *gameData, void *fieldMap)
{
    UnionBeaconPc *beaconPc;
    int metTrainers;
    int wifiFriends;
    int markSys;
    int mmdl;
    int i;

    metTrainers = (int)func_0200ED48(GAME_DATA_GetSaveControl(gameData));
    wifiFriends = func_0201283C(gameData);
    markSys = FIELDMAP_GetUnionEff(fieldMap);
    beaconPc = work->beaconPc;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++, beaconPc++) {
        if (beaconPc->beacon.valid == 1 && beaconPc->charaSlot[0] != 0) {
            mmdl = (int)UNION_CHARA_GetMmdl(work, beaconPc->charaSlot[0]->beaconPc, beaconPc->charaSlot[0]);
            if (mmdl != 0) {
                if (func_0217F894((void *)wifiFriends, beaconPc) == 1) {
                    UNION_EFF_AddIcon((char *)markSys, mmdl, 0);
                } else if (func_0200EDC4((void *)metTrainers, beaconPc->beacon.trainerId) == 1) {
                    UNION_EFF_AddIcon((char *)markSys, mmdl, 1);
                }
            }
        }
    }
}






int UNION_CHARA_ActionIdle(UnionRoomWork *work, UnionCharaSlot *slot)
{
    UnionBeaconPc *beaconPc;
    UnionMySituation *situation;
    int groupCategory;
    int appealNo;
    void *mmdl;

    situation = (&work->mySituation);
    beaconPc = slot->beaconPc;
    if (beaconPc->life == 0) {
        UNION_CHARA_SetNextAction(slot, 2);
        return 1;
    }
    if (!beaconPc->beacon.group.member[slot->memberIndex].valid || slot->trainerView != beaconPc->beacon.group.member[slot->memberIndex].trainerView) {
        UNION_CHARA_SetNextAction(slot, 2);
        return 1;
    }
    groupCategory = func_0217F858(beaconPc->beacon.status);
    if (situation->connect.requestId == UNION_CHARA_MakeObjId(slot->beaconPc, slot)) {
        UNION_CHARA_SetNextAction(slot, 3);
        return 1;
    }
    appealNo = situation->appealNo;
    if (appealNo != 0 && (appealNo == groupCategory || (groupCategory == 0 && appealNo == beaconPc->beacon.appealNo)) && slot->memberIndex == 0
        && UNION_MSG_GetCategoryTableValue(beaconPc->beacon.status) > beaconPc->beacon.connectNum) {
        mmdl = UNION_CHARA_GetMmdl(work, slot->beaconPc, slot);
        if (FLDMMDL_CheckPossibleAcmd((int)mmdl) == 1) {
            FLDMMDL_SetAcmd(mmdl, 0x31);
        }
    } else if (slot->memberIndex == 0 && beaconPc->beacon.connectNum > 1) {
        mmdl = UNION_CHARA_GetMmdl(work, slot->beaconPc, slot);
        if (FLDMMDL_GetMoveCode(mmdl) == 2) {
            FLDMMDL_ChangeMoveCode((int)mmdl, 0xF);
        }
    } else if (slot->memberIndex == 0 && beaconPc->beacon.connectNum <= 1) {
        mmdl = UNION_CHARA_GetMmdl(work, slot->beaconPc, slot);
        if (FLDMMDL_GetMoveCode(mmdl) == 0xF) {
            FLDMMDL_ChangeMoveCode((int)mmdl, 2);
        }
    }
    return 0;
}






int UNION_CHARA_ActionAppear(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step)
{
    s16 pos[8];
    int mmdl = (int)UNION_CHARA_GetMmdl(work, slot->beaconPc, slot);
    switch (*step) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
            FLDMMDL_GetGridNowPos((int)FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), pos);
            FLDMMDL_GetGridNowPos(mmdl, pos + 4);
            if (pos[4] != pos[0] || pos[6] != pos[2]) {
                FLDMMDL_SetAcmd((void *)mmdl, 0x44);
                FLDMMDL_SetStatusBitVanish((unsigned int *)mmdl, 0);
                *step = *step + 1;
            }
        }
        break;
    case 1:
        if (FLDMMDL_CheckEndAcmd(mmdl) == 1) { FLDMMDL_EndAcmd((char *)mmdl); return 1; }
        break;
    }
    return 0;
}






int UNION_CHARA_ActionDisappear(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step)
{
    int mmdl = (int)UNION_CHARA_GetMmdl(work, slot->beaconPc, slot);
    switch (*step) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) { FLDMMDL_SetAcmd((void *)mmdl, 0x43); *step = *step + 1; }
        break;
    case 1:
        if (FLDMMDL_CheckEndAcmd(mmdl) == 1) { FLDMMDL_EndAcmd((char *)mmdl); return 1; }
        break;
    }
    return 0;
}







int UNION_CHARA_ActionTalk(UnionRoomWork *work, UnionCharaSlot *slot, void *fieldMap, u8 *step)
{
    UnionMySituation *situation = (&work->mySituation);
    int mmdl;
    u16 acmd;

    mmdl = (int)UNION_CHARA_GetMmdl(work, slot->beaconPc, slot);
    switch (*step) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(mmdl) == 1) {
            switch (FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)))) {
            case 0:
                acmd = 1;
                break;
            case 1:
                acmd = 0;
                break;
            case 2:
                acmd = 3;
                break;
            case 3:
            default:
                acmd = 2;
                break;
            }
            FLDMMDL_SetAcmd((void *)mmdl, acmd);
            *step = *step + 1;
        }
        break;
    case 1:
        if (FLDMMDL_EndAcmd((char *)mmdl) == 1) {
            FLDMMDL_SetStatusBit((u32 *)mmdl, 8);
            *step = *step + 1;
        }
        break;
    case 2:
        if (situation->connect.requestId != UNION_CHARA_MakeObjId(slot->beaconPc, slot)) {
            FLDMMDL_ClearStatusBit((u32 *)mmdl, 8);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * lever: the bit at byte 7, bit 4 is a one-bit unsigned char field;
 * integer masks instead produce asrs/movs/ands and grow the body by 4 bytes.
 */
void UNION_CHARA_ProcessBeaconUpdates(UnionRoomWork *work)
{
    int i;
    UnionBeaconPc *beaconPc;
    beaconPc = work->beaconPc;
    for (i = 0; i < UNION_BEACON_PC_MAX; i++, beaconPc++) {
        if (beaconPc->beacon.valid == 1 && beaconPc->updateState != 0) {
            UNION_CHARA_OnBeaconUpdate(work, beaconPc);
            beaconPc->updateState = 0;
        }
    }
}







void UNION_CHARA_OnBeaconUpdate(UnionRoomWork *work, UnionBeaconPc *beaconPc)
{
    UnionMySituation *situation = (&work->mySituation);
    u8 ownMac[6];

    UNION_CHAT_LOG_Add(work, beaconPc, 0, 0);
    if (situation->playCategory == 0 && situation->nextPlayCategory == 0 && beaconPc->beacon.playCategory == 5 && beaconPc->life != 0) {
        OS_GetMacAddress(ownMac);
        if (memcmp(beaconPc->beacon.mac, ownMac, 6) == 0 && UNION_ONESELF_SetNextPlayCategoryInMainPhase(work, 6) == 1) {
            UNION_COMM_SetSituationParam(work, 2, (u32)beaconPc);
            UNION_COMM_SetSituationParam(work, 0, (u32)beaconPc);
        }
    }
}






/*
 * extent: follower 0217B83C already has its own source and shard.
 */
int UNION_ONESELF_TryStartSubEvent(struct GameSystem *gameSystem, void *fieldMap)
{
    UnionRoomWork *work;
    UnionSubEvent *subEvent;
    int result;
    work = (UnionRoomWork *)GAME_COMM_GetWork((void *)func_02012138(gameSystem));
    result = 0;
    subEvent = &work->subEvent;
    if (subEvent->id != 0 && subEvent->active == 0) result = func_0217413C(gameSystem, fieldMap, work);
    return result;
}






/*
 * Unlabelled leaf (a .word after a pool in the ov019 listing): returns 0.
 * Callee of ov021 func_0218A0E4, which passes (sys, pos).
 * Addresses are Black-image addresses.
 */
int UNION_ONESELF_GetFieldTalkEvent(void *gameSystem, void *pos)
{
    return 0;
}







int UNION_ONESELF_RunPlayCategory(UnionRoomWork *work, void *fieldMap)
{
    UnionMySituation *situation = (&work->mySituation);
    int result = 1;
    UnionOneselfActionFunc func;

    switch (situation->phase) {
    case 0:
        func = gUnionOneselfActionStart[situation->playCategory].func;
        break;
    case 1:
        func = gUnionOneselfActionMain[situation->playCategory].func;
        break;
    case 2:
        func = gUnionOneselfActionEnd[situation->playCategory].func;
        break;
    }
    if (func != 0) {
        result = func(work, situation, fieldMap, &situation->step);
    }
    if (result == 1) {
        situation->step = 0;
        situation->phase = situation->phase + 1;
        if (situation->phase > 2) {
            situation->phase = 0;
            situation->prevPlayCategory = situation->playCategory;
            situation->playCategory = situation->nextPlayCategory;
            situation->nextPlayCategory = 0;
        }
    }
    return situation->playCategory;
}






int UNION_ONESELF_SetNextPlayCategory(UnionRoomWork *work, int playCategory)
{
    (&work->mySituation)->nextPlayCategory = playCategory;
    return 1;
}






int UNION_ONESELF_SetNextPlayCategoryInMainPhase(UnionRoomWork *work, char playCategory)
{
    if ((&work->mySituation)->phase == 1) return UNION_ONESELF_SetNextPlayCategory(work, playCategory);
    return 0;
}






int UNION_ONESELF_GetRegulationId(int status)
{
    switch (status) {
    case 0: case 1: case 2: case 3:
        break;
    case 4: case 5:
        return 5;
    case 6: case 7:
        return 0x18;
    case 8: case 9:
        return 6;
    case 10: case 11:
        return 0x19;
    case 12: case 13:
        return 7;
    case 14: case 15:
        return 0x1a;
    case 16: case 17:
        return 8;
    case 18: case 19:
        return 0x1b;
    case 20: case 21:
        return 9;
    case 22: case 23:
        return 0x1c;
    }
    return 5;
}






int UNION_ONESELF_GetRegulationFlag(int status)
{
    switch (status) {
    case 0: case 1: case 2: case 3:
    case 5: case 7: case 9: case 11: case 13: case 15:
    case 17: case 19: case 21:
        break;
    case 4: case 6: case 8: case 10: case 12: case 14:
    case 16: case 18: case 20: case 22:
        return 1;
    }
    return 0;
}






int UNION_ONESELF_IsBattleStatus(unsigned int status)
{
    if (status < 4 || status > 23) return 0;
    return 1;
}






/*
 * Return from the legacy void tail forwarder 0200BAC8 is used by this caller.
 */
void *UNION_ONESELF_CreateBattleTeamParty(UnionRoomWork *work)
{
    void *battleTeam;
    battleTeam = func_0200BAC8(GAME_DATA_GetSaveControl(work->parent->gameData));
    if (func_0200BBA8(battleTeam) == 0) return 0;
    return func_0200BAF4((int)battleTeam, UNION_HEAP_ID);
}






void UNION_ONESELF_DeleteParty(void *party)
{
    if (!party) func_02034714(gUnionEmptyString1, 0, gUnionEmptyString1);
    func_020307B0(party);
}






/*
 * Interface evidence: stub at 0201A364 moves r0 to r2, r1 to r0,
 * sets r1=0x69, then jumps through pool 02048F4C. the integrator owns it.
 */
void UNION_ONESELF_LoadRegulation(UnionRoomWork *work, int status)
{
    POKE_REGULATION_LoadInto(UNION_ONESELF_GetRegulationId(status), work->regulation);
    if (UNION_ONESELF_GetRegulationFlag(status) == 1) func_0200AEE8(work->regulation, 13, 1);
    else func_0200AEE8(work->regulation, 13, 0);
}






int UNION_ONESELF_CheckMyParty(UnionRoomWork *work, unsigned int *violationMask)
{
    void *party;
    *violationMask = 0;
    party = func_02012934(work->parent->gameData);
    return POKE_REGULATION_CheckParty(work->regulation, party, violationMask);
}






int UNION_ONESELF_CheckBattleTeamParty(UnionRoomWork *work, unsigned int *violationMask)
{
    void *party;
    int result;
    party = UNION_ONESELF_CreateBattleTeamParty(work);
    *violationMask = 0;
    if (party != 0) {
        result = POKE_REGULATION_CheckParty(work->regulation, party, violationMask);
        UNION_ONESELF_DeleteParty(party);
    } else {
        *violationMask = -1;
        result = 5;
    }
    return result;
}







int UNION_ONESELF_CheckEntryParties(UnionRoomWork *work, int status, unsigned int *myPartyMask, unsigned int *battleTeamMask)
{
    int myPartyResult, battleTeamResult;
    *myPartyMask = 0;
    *battleTeamMask = 0;
    if (UNION_ONESELF_IsBattleStatus(status) == 0)
        return 1;
    UNION_ONESELF_LoadRegulation(work, status);
    myPartyResult = UNION_ONESELF_CheckMyParty(work, myPartyMask);
    battleTeamResult = UNION_ONESELF_CheckBattleTeamParty(work, battleTeamMask);
    if (myPartyResult == 0 || battleTeamResult == 0)
        return 1;
    return 0;
}





void UNION_ONESELF_SetFieldBusy(UnionRoomWork *work, void *fieldMap, unsigned int busy)
{
    work->fieldBusy = busy;
    FIELDMAP_CTRL_GRID_SetBusy(fieldMap, busy);
}





int UNION_ONESELF_CheckNetError(UnionRoomWork *work)
{
    if (func_0200FB24() != 0) {
        UNION_ONESELF_SetNextPlayCategory(work, 1);
        return 1;
    }
    return 0;
}





int UNION_ONESELF_CheckNetErrorExit(UnionRoomWork *work)
{
    if (UNION_ONESELF_CheckNetError(work) == 1) {
        UNION_ONESELF_SetNextPlayCategory(work, 50);
        return 1;
    }
    return 0;
}



int UNION_ONESELF_IdleStart(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap)
{
    UNION_COMM_InitConnectInfo(work, &situation->connect);
    UNION_COMM_SetSituationParam(work, 4, 0);
    UNION_MSG_CloseAllWindows(work);
    UNION_ONESELF_SetFieldBusy(work, fieldMap, 0);
    work->talkCancel = 0;
    return 1;
}



int UNION_ONESELF_IdleMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap)
{
    void *fieldPlayer;
    void *mmdlSys;
    void *mmdl;
    u16 objId;
    u16 beaconIndex;
    s16 gridX;
    s16 gridY;
    s16 gridZ;

    fieldPlayer = FIELDMAP_GetFieldPlayer(fieldMap);
    mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    if (UNION_ONESELF_CheckNetError(work) == 1) {
        return 1;
    }
    if (UNION_COMM_IsResetting(work) == 1) {
        return 0;
    }
    if (situation->nextPlayCategory != 0) {
        return 1;
    }
    if (GFL_NET_GetNegotiationNum() > 1) {
        UNION_COMM_RequestRestart(work);
        return 0;
    }
    if (KEY_GetTrg() & 1) {
        FIELD_PLAYER_GetFrontGridPos((u32)fieldPlayer, (u32)(&gridX), (u32)(&gridY), (u32)(&gridZ));
        mmdl = FLDMMDL_SysSearchGridPos((u32)mmdlSys, gridX, gridZ, 0);
        if (mmdl == 0) {
            return 0;
        }
        objId = FLDMMDL_GetObjId(mmdl);
        if (UNION_CHARA_IsUnionObjId(objId) == 0 || UNION_CHARA_CheckTalkable(work, objId) == 0) {
            return 0;
        }
        situation->connect.requestId = objId;
        beaconIndex = UNION_CHARA_GetBeaconIndex(objId);
        UNION_COMM_SetSituationParam(work, 0, (u32)(&work->beaconPc[beaconIndex]));
        if (UNION_CHARA_IsChildObjId(objId) == 0) {
            if (work->beaconPc[beaconIndex].beacon.status == 0) {
                UNION_COMM_SetSituationParam(work, 1, (u32)(&work->beaconPc[beaconIndex]));
                UNION_ONESELF_SetNextPlayCategory(work, 5);
            } else {
                UNION_ONESELF_SetNextPlayCategory(work, 0xB);
            }
        } else {
            UNION_ONESELF_SetNextPlayCategory(work, 0xC);
        }
        UNION_ONESELF_SetFieldBusy(work, fieldMap, 1);
        return 1;
    }
    if (work->talkCancel == 1) {
        UNION_ONESELF_SetNextPlayCategory(work, 4);
        return 1;
    }
    if (func_0217F7E4((u32)fieldMap) == 1) {
        if (work->fieldRequestArmed == 1) {
            UNION_ONESELF_SetFieldBusy(work, fieldMap, 1);
            UNION_ONESELF_SetNextPlayCategory(work, 3);
        }
    } else {
        work->fieldRequestArmed = 1;
    }
    return 0;
}



int UNION_ONESELF_ErrorMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step)
{
    switch (*step) {
    case 0:
        UNION_ONESELF_SetFieldBusy(work, fieldMap, 1);
        (*step)++;
        break;
    case 1:
        if (UNION_MSG_CheckTalkPrintEnd(work) == 1) {
            UNION_MSG_CloseAllWindows(work);
            (*step)++;
        }
        break;
    case 2:
        if (func_0200FB24() != 0) {
            func_02012124(work->parent->gameSystem, 1);
            return 0;
        }
        UNION_COMM_RequestShutdown(work);
        (*step)++;
        break;
    case 3:
        if (UNION_COMM_IsResetting(work) == 0)
            (*step)++;
        break;
    case 4:
        UNION_COMM_ReleaseWorks(work);
        UNION_COMM_InitConnectInfo(work, &situation->connect);
        UNION_COMM_RequestStart(work);
        (*step)++;
        break;
    case 5:
        if (UNION_COMM_IsResetting(work) == 0)
            (*step)++;
        break;
    default:
        UNION_ONESELF_SetNextPlayCategory(work, 0);
        return 1;
    }
    return 0;
}


int UNION_ONESELF_NoOpMain(void)
{
    return 1;
}


int UNION_ONESELF_FieldExitMain(UnionRoomWork *work, UnionMySituation *situation, void *fieldMap, u8 *step)
{
    if (*step == 0) {
        work->fieldRequest = 1;
        (*step)++;
    }
    return 0;
}
