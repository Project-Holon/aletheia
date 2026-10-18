/*
 * file:     el_scoreboard.c
 * unit:     yes
 * function: EL_SCOREBOARD_CreateLamp, EL_SCOREBOARD_DeleteLamp, EL_SCOREBOARD_TickLamp, EL_SCOREBOARD_AnimateLampPalette, EL_SCOREBOARD_EventMain, EL_SCOREBOARD_StartOnField, EL_SCOREBOARD_StartOnFieldWithCallback, EL_SCOREBOARD_StartStandalone, EL_SCOREBOARD_SetupDisplay, EL_SCOREBOARD_SetupSharedDisplay, EL_SCOREBOARD_SetupStandaloneDisplay, EL_SCOREBOARD_TeardownDisplay, EL_SCOREBOARD_TeardownSharedDisplay, EL_SCOREBOARD_TeardownStandaloneDisplay, EL_SCOREBOARD_LoadSeasonGraphics, EL_SCOREBOARD_UpdateFade, EL_SCOREBOARD_UpdateFadeShared, EL_SCOREBOARD_UpdateFadeStandalone, EL_SCOREBOARD_GetNextState, EL_SCOREBOARD_EnterState, EL_SCOREBOARD_AdvanceState, EL_SCOREBOARD_OnStart, EL_SCOREBOARD_OnFinish, EL_SCOREBOARD_GetMode, EL_SCOREBOARD_IsFinishRequested, EL_SCOREBOARD_RequestFinish, EL_SCOREBOARD_IsStateDone, EL_SCOREBOARD_GetFadeInDuration, EL_SCOREBOARD_GetFadeOutDuration, EL_SCOREBOARD_GetHoldDuration, EL_SCOREBOARD_CallFinishCallback
 * address:  0x021875F4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAME_DATA_GetEntranceLocation  0x02012870  thumb
 *   GAME_DATA_GetStartLocation  0x0201284C  thumb
 *   ZONEDATA_IsParentZoneD6  0x02014068  thumb
 *   GAME_DATA_SetEscapeLocation  0x020128C0  thumb
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   ZONEDATA_IsWeatherEnabled  0x02013C50  thumb
 *   ZONEDATA_IsZoneInTableDFDC 0x02013FEC thumb
 *   GAME_DATA_GetSpecialLocation 0x02012894 thumb
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerObjectCode 0x02012B28 thumb
 *   GAME_DATA_SetPlayerObjectCode 0x02012B2C thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   MAIL_Create  0x02008F08  thumb
 *   MAIL_SetWriterName  0x02008F88  thumb
 *   MAIL_SetGender  0x02008FA0  thumb
 *   MAIL_SetDesign  0x02008FA8  thumb
 *   MAIL_SetLanguage  0x02008FB4  thumb
 *   MAIL_SetVersion  0x02008FBC  thumb
 *   MAIL_SetMessage  0x02008FD8  thumb
 *   MAIL_SetMessageId  0x02008FC4  thumb
 *   MAIL_GetBox  0x02008FEC  thumb
 *   MAIL_SetSlot  0x0200903C  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   d_02187DA4  0x02187DA4  data  ov020  a4
 *   d_02187DAC  0x02187DAC  data  ov020  a4
 *   d_02187DB4  0x02187DB4  data  ov020  a4
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   POKEPARTY_GetSaveData 0x0201AD0C thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   CONSOLE_STAMP_GetDailyClock 0x02008B14 thumb
 *   FORMCHANGE_RevertShayminAtNight 0x0216A358 thumb ov010
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_02187EA0 0x02187EA0 data ov020 a1
 *   FLDMMDL_GetObjId  0x0216D588  thumb
 *   EVENT_FIELD_PROCLINK_ClearReturnEntry 0x02161E78 thumb ov010
 *   MYSTATUS_GetId  0x02008530  thumb
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   EVENT_FIELD_PROCLINK_IsReturnEntryAllowed 0x02161E84 thumb ov010
 *   MYSTATUS_GetAvatarId  0x0200855C  thumb
 *   INTRUDE_COMM_NormalizeVersion  0x021584F4  thumb  ov010
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid 0x02161ECC thumb ov010
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   GAME_DATA_GetMysteryRecvFlagA  0x020127E0  thumb
 *   GAME_DATA_GetMysteryRecvFlagB  0x020127F0  thumb
 *   ZONEDATA_IsZoneInTableDFEC  0x02013DE0  thumb
 *   EVENT_FIELD_PROCLINK_CompactReturnList  0x02161E60  thumb
 *   EVENT_FIELD_PROCLINK_InitIdList  0x02161EEC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   FLDMMDL_InitPosRecord  0x0216E618  thumb  ov010
 *   d_02187EB4     0x02187EB4  data  ov020  a1
 *   d_02187DBC     0x02187DBC  data  ov020  a4
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_ReadHandleMember  0x0204932C  arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   d_02187DE0     0x02187DE0  data  ov020  a4
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELD_G3D_MAPPER_GetWfbc  0x0218DC70  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   FIELD_WFBC_ApplyGiftMood  0x02193B40  thumb  ov021
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   FIELD_WFBC_GetPeopleArrivalFlag  0x02193BE4  thumb  ov021
 *   FIELD_WFBC_ClearPeopleArrivalFlag  0x02193BC4  thumb  ov021
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   FIELD_WFBC_SetWordSetParentName  0x02193B68  thumb  ov021
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   FIELD_WFBC_ReloadSaveData  0x02193904  thumb  ov021
 *   FIELD_WFBC_GetPeople  0x0219390C  thumb  ov021
 *   FIELD_WFBC_PEOPLE_GetNpcRecord  0x02193C00  thumb  ov021
 *   FIELD_WFBC_PEOPLE_GetPersonData  0x02193C04  thumb  ov021
 *   FIELD_WFBC_GetPeopleNum  0x021938F4  thumb  ov021
 *   FIELDMAP_GetGameSystem 0x02188C80 thumb ov021
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   GF_STANDARD_SetField00_F4E4  0x0203F4E4  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   FIELD_WFBC_GetCityType  0x0219391C  thumb  ov021
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_GetReturnSlots  0x02158434  thumb  ov010
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   GAME_DATA_GetUnionInfo  0x020127D0  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_ClearReturnDefaultAndPending  0x021620A0  thumb  ov010
 *   EVENT_FIELD_PROCLINK_RequestReturn  0x02162048  thumb  ov010
 *   EVENT_FIELD_PROCLINK_HasReturnDefaultSlot  0x0216208C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_GetReturnDefaultSlotType  0x0216209C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_HasEventdataEntry  0x02161E4C  thumb  ov010
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   EVENT_FIELD_PROCLINK_ApplyReturnEntry  0x02161F90  thumb  ov010
 *   FIELD_WFBC_RemovePeople  0x02193B20  thumb  ov021
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb  ov021
 *   d_02187E04     0x02187E04  data  ov020  a2
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb  ov021
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb  ov021
 *   FIELD_MSGBG_ClearTalkWin 0x0219131C thumb ov021
 *   WAZA_OSHIE_GetTexFormatCount  0x0216FC4C  thumb  ov010
 *   WAZA_OSHIE_LoadTexPlttByName  0x0216FAB4  thumb  ov010
 *   EL_SCOREBOARD_SourceFileName     0x02187EDC  data  ov020  a4
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   EL_SCOREBOARD_LampPaletteColors 0x02187ECC data ov020 a4
 *   GAME_EVENT_GetSeq  0x020124EC  thumb
 *   COMM_PLAYER_SUPPORT_PrevSeason  0x0202E8B8  thumb
 *   BG_SYS_GetMainVisiblePlanes 0x02043658 arm
 *   FIELDMAP_SetBgMode 0x02188DA0 thumb ov021
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   EL_SCOREBOARD_VramBankConfig     0x02187E58  data  ov020
 *   EL_SCOREBOARD_DispConfig     0x02187E28  data  ov020
 *   EL_SCOREBOARD_BgTemplate     0x02187E38  data  ov020
 *   NNS_G2dGetUnpackedPaletteData  0x02062A98  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_PushTileSource  0x020409E0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   _ffltu  0x0209BE04  arm
 *   __fdiv  0x0209CE10  arm
 *   __fmul  0x0209C77C  arm
 *   __fadd  0x0209C95C  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 *   COMM_PLAYER_SUPPORT_NextSeason  0x0202E8A4  thumb
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   FIELDMAP_ResetBgAffineShowMsg  0x02188DB0  thumb  ov021
 *   FIELDMAP_SetSubscreenBusy 0x02189A50 thumb ov021
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 */

struct ArcHandle;
struct GameEvent;
struct TexKey;
struct BgTemplate;
struct DispConfig;
struct DispVram;
struct NitroFileHeader;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

#include "el_scoreboard_types.h"
u32 GFL_HEAP_Free(void *p);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap);
extern void ARC_TOOL_DeleteHandle(void *p);
extern void *ARC_TOOL_LoadHandleMember(struct ArcHandle *arc, unsigned int member,
                           unsigned int heap);
u16 FIELDMAP_GetHeapId(u8 *p);
struct GameEvent *GAME_EVENT_Create(void *owner, void *a, void *b, u32 size);
void *GAME_EVENT_GetWork(struct GameEvent *p);
extern u32 KEY_GetTrg(void);
extern int WAZA_OSHIE_GetTexFormatCount(void);
extern int WAZA_OSHIE_LoadTexPlttByName(void *file, const char *texName, void *extra, const char *plttName, u32 a4, u16 a5, u16 a6, u16 a7, u16 heap, struct TexKey *out);
extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);
extern u32 *GAME_EVENT_GetSeq(struct GameEvent *p);
extern u8 COMM_PLAYER_SUPPORT_PrevSeason(int);
extern u32 BG_SYS_GetMainVisiblePlanes(void);
extern void FIELDMAP_SetBgMode(void);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);
extern void BG_SYS_FreeSlot(int a);
void BG_SYS_SetVramBanks(const struct DispVram *c);
void BG_SYS_Create(u16 heapId);
void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeLayerBuf(unsigned int i);
extern void BG_SYS_Delete(void);
s32 NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *file, void **out);
void BG_SYS_LoadPltt(u32 r7, void *r6, u32 r5, u32 r4);
s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);
void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
int NNS_G2dGetUnpackedScreenData(void *file, void **out);
void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset);
void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
void G2x_SetBlendAlpha_(u32 addr, int plane1, int plane2, int ev1, int ev2);
void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
u32 _ffltu(u32 x);
u32 __fdiv(u32 a, u32 b);
u32 __fmul(u32 a, u32 b);
u32 __fadd(u32 a, u32 b);
u32 _fsub(u32 a, u32 b);
u32 _ffix(u32 x);
u8 COMM_PLAYER_SUPPORT_NextSeason(u8 x);
void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
void FIELDMAP_ResetBgAffineShowMsg(u8 *a);
extern void FIELDMAP_SetSubscreenBusy(char *p, int v);
ElLamp *EL_SCOREBOARD_CreateLamp(void *archive, const char *texName, const char *plttName, u32 texFormat, ElTexParams loadParams);
void EL_SCOREBOARD_DeleteLamp(ElLamp *lamp);
void EL_SCOREBOARD_TickLamp(ElLamp *lamp);
void EL_SCOREBOARD_AnimateLampPalette(ElLampPaletteRef *paletteRef, int tick);
int EL_SCOREBOARD_EventMain(void *eventTask, int *state, ElScoreboardWork *work);
void *EL_SCOREBOARD_StartOnField(void *gameSystem, void *fieldMap, u8 shownSeason, u8 targetSeason);
void *EL_SCOREBOARD_StartOnFieldWithCallback(void *gameSystem, void *fieldMap, u8 shownSeason, u8 targetSeason, ElScoreboardCallback finishCallback, int finishCallbackArg);
void *EL_SCOREBOARD_StartStandalone(void *p, u8 shownSeason, u8 targetSeason);
void EL_SCOREBOARD_SetupDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_SetupSharedDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_SetupStandaloneDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_TeardownDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_TeardownSharedDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_TeardownStandaloneDisplay(ElScoreboardWork *work);
void EL_SCOREBOARD_LoadSeasonGraphics(int season, int heapId);
void EL_SCOREBOARD_UpdateFade(ElScoreboardWork *work, int state);
void EL_SCOREBOARD_UpdateFadeShared(const ElScoreboardWork *work, int state);
void EL_SCOREBOARD_UpdateFadeStandalone(ElScoreboardWork *work, int state);
int EL_SCOREBOARD_GetNextState(ElScoreboardWork *work, int state);
void EL_SCOREBOARD_EnterState(ElScoreboardWork *work, int *statePtr, int state);
void EL_SCOREBOARD_AdvanceState(ElScoreboardWork *work, int *statePtr);
void EL_SCOREBOARD_OnStart(ElScoreboardWork *work);
void EL_SCOREBOARD_OnFinish(ElScoreboardWork *work);
u32 EL_SCOREBOARD_GetMode(ElScoreboardWork *work);
u32 EL_SCOREBOARD_IsFinishRequested(ElScoreboardWork *work);
void EL_SCOREBOARD_RequestFinish(ElScoreboardWork *work);
int EL_SCOREBOARD_IsStateDone(ElScoreboardWork *work);
int EL_SCOREBOARD_GetFadeInDuration(ElScoreboardWork *work);
int EL_SCOREBOARD_GetFadeOutDuration(ElScoreboardWork *work);
int EL_SCOREBOARD_GetHoldDuration(ElScoreboardWork *work);
void EL_SCOREBOARD_CallFinishCallback(ElScoreboardWork *work);
extern int EL_SCOREBOARD_SourceFileName;
extern int EL_SCOREBOARD_LampPaletteColors[];
extern char EL_SCOREBOARD_VramBankConfig[];
extern char EL_SCOREBOARD_DispConfig[];
extern char EL_SCOREBOARD_BgTemplate[];

ElLamp *EL_SCOREBOARD_CreateLamp(void *archive, const char *texName, const char *plttName, u32 texFormat, ElTexParams loadParams)
{
    ElTexResult loaded;
    ElLamp *lamp;

    lamp = GFL_HEAP_Alloc(((u16 *)&loadParams)[4], 0x1c, 1, (const char *)&EL_SCOREBOARD_SourceFileName, 0x19c);
    lamp->flags = 0;
    lamp->texIndex = WAZA_OSHIE_GetTexFormatCount() - 1;
    lamp->plttIndex = WAZA_OSHIE_GetTexFormatCount() - 1;
    lamp->texVram = -1;
    lamp->plttVram = (char *)-1;
    if (WAZA_OSHIE_LoadTexPlttByName(archive, texName, 0, plttName, texFormat, ((u16 *)&loadParams)[0], ((u16 *)&loadParams)[2], 0xC40, ((u16 *)&loadParams)[4], (struct TexKey *)(&loaded)) != 0) {
        lamp->texAddr = loaded.texAddr;
        lamp->plttSlot = loaded.plttSlot;
        lamp->texVram = loaded.texVram;
        lamp->texIndex = loaded.texIndex;
        lamp->plttIndex = loaded.plttIndex;
        lamp->plttVram = (char *)loaded.plttVram;
        lamp->tick = 0;
    }
    return lamp;
}

void EL_SCOREBOARD_DeleteLamp(ElLamp *lamp) { GFL_HEAP_Free(lamp); }

/*
 * lever: capture the base in a local before filling the stack pair, preserving the original r3 load.
 */
void EL_SCOREBOARD_TickLamp(ElLamp *lamp)
{
    ElLampPaletteRef pair;
    char *base;
    lamp->tick++;
    base = lamp->plttVram;
    if (base != (char *)-1) {
        pair.index = lamp->plttSlot;
        pair.base = base;
        EL_SCOREBOARD_AnimateLampPalette(&pair, lamp->tick);
    }
}

void EL_SCOREBOARD_AnimateLampPalette(ElLampPaletteRef *paletteRef, int tick)
{
    NNS_GfdRegisterNewVramTransferTask((void *)1, (u32)(paletteRef->base + (u16)paletteRef->index * 8), EL_SCOREBOARD_LampPaletteColors[(tick & 31) / 8], 8);
}

int EL_SCOREBOARD_EventMain(void *eventTask, int *state, ElScoreboardWork *work)
{
    switch (*state) {
    case 0: EL_SCOREBOARD_OnStart(work); break;
    case 1: case 3: break;
    case 2: EL_SCOREBOARD_UpdateFade(work, *state); break;
    case 4: EL_SCOREBOARD_UpdateFade(work, *state); break;
    case 5: EL_SCOREBOARD_OnFinish(work); return 1;
    }
    if (KEY_GetTrg() & 1) { if (EL_SCOREBOARD_GetMode(work) == 0) EL_SCOREBOARD_RequestFinish(work); }
    work->stateTimer = work->stateTimer + 1;
    EL_SCOREBOARD_AdvanceState(work, state);
    return 0;
}

/*
 * shownSeason must be u8 (as in the twin EL_SCOREBOARD_StartStandalone): with an int the scheduler
 * hoists its spilled reload above the strb of targetSeason.
 */
void *EL_SCOREBOARD_StartOnField(void *gameSystem, void *fieldMap, u8 shownSeason, u8 targetSeason)
{
    void *eventTask = GAME_EVENT_Create(gameSystem, 0, EL_SCOREBOARD_EventMain, 0x28);
    ElScoreboardWork *work = GAME_EVENT_GetWork(eventTask);
    u32 *statePtr = GAME_EVENT_GetSeq(eventTask);
    work->gameSystem = gameSystem; work->fieldMap = fieldMap; work->heapId = FIELDMAP_GetHeapId((u8 *)fieldMap); work->mode = 0; work->finished = 0;
    work->targetSeason = targetSeason; work->shownSeason = COMM_PLAYER_SUPPORT_PrevSeason(shownSeason); work->finishCallback = 0; work->finishCallbackArg = 0;
    EL_SCOREBOARD_EnterState(work, (int *)statePtr, 0);
    return eventTask;
}

void *EL_SCOREBOARD_StartOnFieldWithCallback(void *gameSystem, void *fieldMap, u8 shownSeason, u8 targetSeason, ElScoreboardCallback finishCallback, int finishCallbackArg)
{
    void *eventTask = GAME_EVENT_Create(gameSystem, 0, EL_SCOREBOARD_EventMain, 0x28);
    ElScoreboardWork *work = GAME_EVENT_GetWork(eventTask);
    u32 *statePtr = GAME_EVENT_GetSeq(eventTask);
    work->gameSystem = gameSystem; work->fieldMap = fieldMap; work->heapId = FIELDMAP_GetHeapId((u8 *)fieldMap); work->mode = 0; work->finished = 0;
    work->targetSeason = targetSeason; work->shownSeason = COMM_PLAYER_SUPPORT_PrevSeason(shownSeason); work->finishCallback = finishCallback; work->finishCallbackArg = finishCallbackArg;
    EL_SCOREBOARD_EnterState(work, (int *)statePtr, 0);
    return eventTask;
}

/*
 * Standalone scoreboard (no field map): create the event task with a 0x28-byte
 * work area, fill it and enter state 0. shownSeason must be u8: with an int
 * (targetSeason either int or u8) the scheduler hoists the spilled reload
 * above the strb of targetSeason.
 */
void *EL_SCOREBOARD_StartStandalone(void *gameSystem, u8 shownSeason, u8 targetSeason)
{
    void *eventTask = GAME_EVENT_Create(gameSystem, 0, EL_SCOREBOARD_EventMain, 0x28);
    ElScoreboardWork *work = GAME_EVENT_GetWork(eventTask);
    void *stateNum = GAME_EVENT_GetSeq(eventTask);

    work->gameSystem = gameSystem;
    work->fieldMap = 0;
    work->heapId = 4;
    work->mode = 1;
    work->finished = 0;
    work->targetSeason = targetSeason;
    work->shownSeason = COMM_PLAYER_SUPPORT_PrevSeason(shownSeason);
    work->finishCallback = 0;
    work->finishCallbackArg = 0;
    EL_SCOREBOARD_EnterState(work, stateNum, 0);
    return eventTask;
}

void EL_SCOREBOARD_SetupDisplay(ElScoreboardWork *work)
{
    switch (EL_SCOREBOARD_GetMode(work)) {
    case 0: EL_SCOREBOARD_SetupSharedDisplay(work); break;
    case 1: EL_SCOREBOARD_SetupStandaloneDisplay(work); break;
    }
}

void EL_SCOREBOARD_SetupSharedDisplay(ElScoreboardWork *work)
{
    int planes;
    planes = BG_SYS_GetMainVisiblePlanes();
    FIELDMAP_SetBgMode();
    BG_SYS_SetMainVisiblePlanes(planes);
    BG_SYS_SetVisibleLayer(0, 1);
    BG_SYS_SetVisibleLayer(3, 0);
    BG_SYS_SetVisibleLayer(1, 3);
    BG_SYS_SetVisibleLayer(2, 3);
    BG_SYS_FreeSlot(3);
}

void EL_SCOREBOARD_SetupStandaloneDisplay(ElScoreboardWork *work)
{
    BG_SYS_SetVramBanks((const struct DispVram *)EL_SCOREBOARD_VramBankConfig);
    BG_SYS_Create(work->heapId);
    BG_SYS_SetGraphicsMode((struct DispConfig *)EL_SCOREBOARD_DispConfig);
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)EL_SCOREBOARD_BgTemplate, 0);
    BG_SYS_SetVisibleLayer(0, 1);
    BG_SYS_SetVisibleLayer(3, 0);
    BG_SYS_SetVisibleLayer(1, 3);
    BG_SYS_SetVisibleLayer(2, 3);
    BG_SYS_FreeSlot(3);
}

void EL_SCOREBOARD_TeardownDisplay(ElScoreboardWork *work)
{
    switch (EL_SCOREBOARD_GetMode(work)) {
    case 0: EL_SCOREBOARD_TeardownSharedDisplay(work); break;
    case 1: EL_SCOREBOARD_TeardownStandaloneDisplay(work); break;
    }
}

void EL_SCOREBOARD_TeardownSharedDisplay(ElScoreboardWork *work)
{
}

/*
 * \n * symbols:\n *   BG_SYS_FreeLayerBuf  0x020403F4  arm\n *   BG_SYS_Delete  0x0203F9B4  arm\n
 */
void EL_SCOREBOARD_TeardownStandaloneDisplay(ElScoreboardWork *work)
{
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_Delete();
}

void EL_SCOREBOARD_LoadSeasonGraphics(int season, int heapId)
{
    int *palFile;
    int *charFile;
    int *screenFile;
    void *archive;
    void *member;
    int palIdx, charIdx, screenIdx;

    switch (season) {
    default:
    case 0:
        palIdx = 0; charIdx = 1; screenIdx = 2;
        break;
    case 1:
        palIdx = 3; charIdx = 4; screenIdx = 5;
        break;
    case 2:
        palIdx = 6; charIdx = 7; screenIdx = 8;
        break;
    case 3:
        palIdx = 9; charIdx = 10; screenIdx = 11;
        break;
    }
    archive = ARC_TOOL_CreateHandle(0x97, heapId);
    member = ARC_TOOL_LoadHandleMember(archive, palIdx, heapId);
    NNS_G2dGetUnpackedPaletteData(member, (void **)(&palFile));
    BG_SYS_LoadPltt(3, (void *)palFile[3], 0x20, 0);
    GFL_HEAP_Free(member);
    member = ARC_TOOL_LoadHandleMember(archive, charIdx, heapId);
    NNS_G2dGetUnpackedCharacterDataEx(member, (void **)(&charFile));
    BG_SYS_LoadTileData(3, (const void *)charFile[5], charFile[4], 0);
    GFL_HEAP_Free(member);
    member = ARC_TOOL_LoadHandleMember(archive, screenIdx, heapId);
    NNS_G2dGetUnpackedScreenData(member, (void **)(&screenFile));
    BG_SYS_PushTileSource(3, screenFile + 3, screenFile[2], 0);
    GFL_HEAP_Free(member);
    ARC_TOOL_DeleteHandle(archive);
}

void EL_SCOREBOARD_UpdateFade(ElScoreboardWork *work, int state)
{
    switch (EL_SCOREBOARD_GetMode(work)) {
    case 0: EL_SCOREBOARD_UpdateFadeShared(work, state); break;
    case 1: EL_SCOREBOARD_UpdateFadeStandalone(work, state); break;
    }
}

/*
 * Blend fade on the main engine (BLDCNT 0x04000050) plus the sub engine's
 * master brightness (0x0400106C), driven by the ratio o->0x18 / o->0x1c.
 * The object pointer is `const char *`: through a const pointer mwcc lets the
 * loads after the G2x_SetBlendAlpha_ call ignore the outgoing stack-argument
 * store, so that store is scheduled last (+0x7E). With a plain `char *` it
 * moves up to +0x78 (8 bytes out); const casts on the loads alone do not.
 */
void EL_SCOREBOARD_UpdateFadeShared(const ElScoreboardWork *work, int state)
{
    int alpha;

    if (state == 2) {
        G2x_SetBlendBrightness_(0x04000050, 8,
            (int)(16.0f * ((float)work->stateTimer / (float)work->stateDuration) + -16.0f));
    } else if (state == 4) {
        if (work->shownSeason == work->targetSeason) {
            alpha = (int)(16.0f * ((float)work->stateTimer / (float)work->stateDuration));
            G2x_SetBlendAlpha_(0x04000050, 8, 0x11, 16 - alpha, alpha);
            GXx_SetMasterBrightness_((volatile u16 *)0x0400106C,
                (int)(16.0f * ((float)work->stateTimer / (float)work->stateDuration) + -16.0f));
        } else {
            G2x_SetBlendBrightness_(0x04000050, 8,
                (int)(0.0f - 16.0f * ((float)work->stateTimer / (float)work->stateDuration)));
        }
    }
}

void EL_SCOREBOARD_UpdateFadeStandalone(ElScoreboardWork *work, int state)
{
    u32 elapsed, ratio;

    if (state == 2) {
        elapsed = _ffltu(work->stateTimer);
        ratio = _ffltu(work->stateDuration);
        ratio = __fdiv(elapsed, ratio);
        ratio = __fmul(0x41800000, ratio);
        ratio = __fadd(0xC1800000, ratio);
        G2x_SetBlendBrightness_(0x04000050, 8, _ffix(ratio));
    } else if (state == 4) {
        elapsed = _ffltu(work->stateTimer);
        ratio = _ffltu(work->stateDuration);
        ratio = __fdiv(elapsed, ratio);
        ratio = __fmul(0x41800000, ratio);
        ratio = _fsub(0, ratio);
        G2x_SetBlendBrightness_(0x04000050, 8, _ffix(ratio));
    }
}

int EL_SCOREBOARD_GetNextState(ElScoreboardWork *work, int state)
{
    switch (state) {
    case 0:
        state = 1;
        break;
    case 1:
        state = 2;
        break;
    case 2:
        if (EL_SCOREBOARD_IsStateDone(work) == 1)
            state = 3;
        break;
    case 3:
        if (EL_SCOREBOARD_IsStateDone(work) == 1 || EL_SCOREBOARD_IsFinishRequested(work) == 1)
            state = 4;
        break;
    case 4:
        if (EL_SCOREBOARD_IsStateDone(work) == 1) {
            state = 5;
            if (work->targetSeason != work->shownSeason)
                state = 1;
        }
        break;
    case 5:
        break;
    }
    return state;
}

void EL_SCOREBOARD_EnterState(ElScoreboardWork *work, int *statePtr, int state)
{
    switch (state) {
    case 0:
        EL_SCOREBOARD_SetupDisplay(work);
        break;
    case 1:
        work->shownSeason = COMM_PLAYER_SUPPORT_NextSeason(work->shownSeason);
        EL_SCOREBOARD_LoadSeasonGraphics(work->shownSeason, work->heapId);
        break;
    case 2:
        BG_SYS_SetPlaneVisible(3, 1);
        BG_SYS_SetPlaneVisible(0, 0);
        GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, 0);
        G2x_SetBlendBrightness_(0x04000050, 8, -16);
        work->stateDuration = EL_SCOREBOARD_GetFadeInDuration(work);
        break;
    case 3:
        work->stateDuration = EL_SCOREBOARD_GetHoldDuration(work);
        break;
    case 4:
        work->stateDuration = EL_SCOREBOARD_GetFadeOutDuration(work);
        if (EL_SCOREBOARD_GetMode(work) == 0 && work->shownSeason == work->targetSeason) {
            FIELDMAP_ResetBgAffineShowMsg((u8 *)work->fieldMap);
            BG_SYS_SetPlaneVisible(3, 1);
            EL_SCOREBOARD_CallFinishCallback(work);
        }
        break;
    case 5:
        break;
    }
    *statePtr = state;
    work->stateTimer = 0;
}

void EL_SCOREBOARD_AdvanceState(ElScoreboardWork *work, int *statePtr)
{
    int newState;
    newState = EL_SCOREBOARD_GetNextState(work, *statePtr);
    if (*statePtr != newState) EL_SCOREBOARD_EnterState(work, statePtr, newState);
}

/* Tells the field map that the scoreboard is up (setter in ov021). */
void EL_SCOREBOARD_OnStart(ElScoreboardWork *work)
{
    void *fieldMap;
    fieldMap = work->fieldMap;
    if (fieldMap != 0) FIELDMAP_SetSubscreenBusy(fieldMap, 1);
}

/* Clears the field map flag, then runs the mode-specific teardown. */
void EL_SCOREBOARD_OnFinish(ElScoreboardWork *work)
{
    BG_SYS_SetPlaneVisible(3, 0);
    if (work->fieldMap != 0) FIELDMAP_SetSubscreenBusy(work->fieldMap, 0);
    EL_SCOREBOARD_TeardownDisplay(work);
}

u32 EL_SCOREBOARD_GetMode(ElScoreboardWork *work)
{
    return work->mode;
}

u32 EL_SCOREBOARD_IsFinishRequested(ElScoreboardWork *work)
{
    return work->finished;
}

void EL_SCOREBOARD_RequestFinish(ElScoreboardWork *work)
{
    work->finished = 1;
}

int EL_SCOREBOARD_IsStateDone(ElScoreboardWork *work)
{
    if (work->stateDuration < work->stateTimer)
        return 1;
    return 0;
}

int EL_SCOREBOARD_GetFadeInDuration(ElScoreboardWork *work)
{
    if (EL_SCOREBOARD_GetMode(work) == 1) return 30;
    return 10;
}

int EL_SCOREBOARD_GetFadeOutDuration(ElScoreboardWork *work)
{
    if (EL_SCOREBOARD_GetMode(work) == 1) return 60;
    if (work->shownSeason == work->targetSeason) return 20;
    return 10;
}

int EL_SCOREBOARD_GetHoldDuration(ElScoreboardWork *work)
{
    if (EL_SCOREBOARD_GetMode(work) == 1) return 120;
    if (work->shownSeason == work->targetSeason) return 60;
    return 30;
}

void EL_SCOREBOARD_CallFinishCallback(ElScoreboardWork *work)
{
    if (work->finishCallback)
        work->finishCallback(work->finishCallbackArg);
}
