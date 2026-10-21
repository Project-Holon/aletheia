/*
 * file:     guru2_main.c
 * unit:     yes
 * function: GURU2_MAIN_ProcInit, GURU2_MAIN_ProcExit, GURU2_MAIN_ProcMain, GURU2_MAIN_ClearTransferFlags, GURU2_MAIN_StateStart, GURU2_MAIN_StateWaitWipeIn, GURU2_MAIN_StateWaitIntroMessage, GURU2_MAIN_StateSendReady, GURU2_MAIN_GetUnionApp, GURU2_MAIN_StateWaitAllMembers, GURU2_MAIN_StateSendPlayerCount, GURU2_MAIN_StateCollectReadyMasks, GURU2_MAIN_StateSendAbort, GURU2_MAIN_StateSendCancel, GURU2_MAIN_StateWaitCancelMessage, GURU2_MAIN_StateStartSync1, GURU2_MAIN_StateWaitSync1, GURU2_MAIN_StateSendSelectedSlot, GURU2_MAIN_StateBroadcastPlayerData, GURU2_MAIN_StateWaitPlayerData, GURU2_MAIN_StateWaitBranch, GURU2_MAIN_StateBuildPlayerSlots, GURU2_MAIN_StateAnimateSlots, GURU2_MAIN_StateWaitAllSlotsReady, GURU2_MAIN_StateDelayRole, GURU2_MAIN_StateSendRoleChild, GURU2_MAIN_RegisterPlayerRecords, GURU2_MAIN_StateWaitRoleMessage, GURU2_MAIN_StateStartSync2, GURU2_MAIN_StateWaitSync2, GURU2_MAIN_StateShowRound, GURU2_MAIN_StateRoundDelay, GURU2_MAIN_StateToPlay, GURU2_MAIN_StatePlayRound, GURU2_MAIN_StateRoundEnd, GURU2_MAIN_StateRoundEndChild, GURU2_MAIN_StepAngle, GURU2_MAIN_StateStartSync3, GURU2_MAIN_StateWaitSync3, GURU2_MAIN_SendAngles, GURU2_MAIN_ApplyAngles, GURU2_MAIN_ShowResultNames, GURU2_MAIN_StateResultDelay, GURU2_MAIN_StateWaitSe, GURU2_MAIN_StateComputeReward, GURU2_MAIN_StateWaitEffectToEnd, GURU2_MAIN_StateWaitEffectToMessage, GURU2_MAIN_StateWaitTimerToEnd, GURU2_MAIN_StateSaveResult, GURU2_MAIN_StateAfterSync4, GURU2_MAIN_StateWaitSaveDone, GURU2_MAIN_StateShowEndMessage, GURU2_MAIN_StateEndDelay, GURU2_MAIN_StateStartSync5, GURU2_MAIN_StateWaitSync5, GURU2_MAIN_StateWaitUnionAppReset, GURU2_MAIN_StateStartWipeOut, GURU2_MAIN_StateWaitWipeOut, GURU2_MAIN_StateFinished, GURU2_MAIN_VBlank, GURU2_MAIN_SetupAll, GURU2_MAIN_TeardownAll, GURU2_MAIN_Draw3D, GURU2_MAIN_SetupVram, GURU2_MAIN_ShowPlanes, GURU2_MAIN_HidePlanes, GURU2_MAIN_Setup3dState, GURU2_MAIN_Setup3dSystem, GURU2_MAIN_SetupBg, GURU2_MAIN_LoadBgPalette, GURU2_MAIN_ExitBg, GURU2_MAIN_LoadScreen, GURU2_MAIN_LoadScreen26, GURU2_MAIN_LoadScreen24, GURU2_MAIN_LoadScreen25, GURU2_MAIN_CreatePaletteAnim, GURU2_MAIN_DeletePaletteAnim, GURU2_MAIN_BlendPalette, GURU2_MAIN_InitActorSystem, GURU2_MAIN_LoadActorResources, GURU2_MAIN_FreeActorResources, GURU2_MAIN_CreateWindows, GURU2_MAIN_DeleteWindows, GURU2_MAIN_PrintMessage, GURU2_MAIN_PrintMessageWithName, GURU2_MAIN_PrintMessageWithNumber, GURU2_MAIN_ClearMessageWindow, GURU2_MAIN_CreateNameWindows, GURU2_MAIN_DeleteNameWindows, GURU2_MAIN_PrintNameWindow, GURU2_MAIN_PrintPlayerName, GURU2_MAIN_ClearNameWindow, GURU2_MAIN_DeleteCamera, GURU2_MAIN_IsTouched, GURU2_MAIN_AddCenterUnit, GURU2_MAIN_RemoveCenterUnit, GURU2_MAIN_UpdateCenterTransform, GURU2_MAIN_DrawCenterUnit, GURU2_MAIN_AddAngle, GURU2_MAIN_AddBackgroundUnit, GURU2_MAIN_RemoveBackgroundUnit, GURU2_MAIN_DrawBackgroundUnit, GURU2_MAIN_AddPlayerUnits, GURU2_MAIN_RemovePlayerUnits, GURU2_MAIN_ActivatePlayerRecord, GURU2_MAIN_UpdatePlayerRecords, GURU2_MAIN_DrawPlayerRecords, GURU2_MAIN_RotatePlayerRecords, GURU2_MAIN_UpdateRecordPosition, GURU2_MAIN_FindNearestPlayerRecord, GURU2_MAIN_ActivatePlayerUnit, GURU2_MAIN_InitPlayerUnit, GURU2_MAIN_ActivateCardUnit, GURU2_MAIN_UpdateCardUnitAnim, GURU2_MAIN_StartDropEffect, GURU2_MAIN_DropEffectTask, GURU2_MAIN_DropEffectStateInit, GURU2_MAIN_DropEffectStateFall, GURU2_MAIN_DropEffectStateLand, GURU2_MAIN_UpdateBounceEffect, GURU2_MAIN_BounceEffectTask, GURU2_MAIN_CreateBounceEffectTask, GURU2_MAIN_DeleteBounceEffectTask, GURU2_MAIN_AddBounceEffect, GURU2_MAIN_AddBounceEffectsForActivePlayers, GURU2_MAIN_IsBounceEffectActive, GURU2_MAIN_UpdateSettleEffect, GURU2_MAIN_SettleEffectTask, GURU2_MAIN_CreateSettleEffectTask, GURU2_MAIN_DeleteSettleEffectTask, GURU2_MAIN_AddSettleEffect, GURU2_MAIN_UpdateWobbleEffect, GURU2_MAIN_WobbleEffectTask, GURU2_MAIN_CreateWobbleEffectTask, GURU2_MAIN_DeleteWobbleEffectTask, GURU2_MAIN_AddWobbleEffect, GURU2_MAIN_UpdateEntranceEffect, GURU2_MAIN_EntranceEffectTask, GURU2_MAIN_CreateEntranceEffectTask, GURU2_MAIN_DeleteEntranceEffectTask, GURU2_MAIN_StartEntranceEffect, GURU2_MAIN_GetEntranceEffectState, GURU2_MAIN_GetEntranceEffectActive, GURU2_MAIN_CenterActorTask, GURU2_MAIN_CreateCenterActorTask, GURU2_MAIN_UpdateScreenFlash, GURU2_MAIN_ScreenFlashTask, GURU2_MAIN_CreateScreenFlashTask, GURU2_MAIN_DeleteScreenFlashTask, GURU2_MAIN_GetScreenFlashFlag, GURU2_MAIN_StartScreenFlash, GURU2_MAIN_UpdatePulseEffect, GURU2_MAIN_PulseEffectTask, GURU2_MAIN_CreatePulseEffectTask, GURU2_MAIN_DeletePulseEffectTask, GURU2_MAIN_AddPulseEffect, GURU2_MAIN_AddPulseEffectsForMask, GURU2_MAIN_BlendFadeTask, GURU2_MAIN_StartBlendFade, GURU2_MAIN_AddAngleWrapped, GURU2_MAIN_RotateAll, GURU2_MAIN_TickTimeout, GURU2_MAIN_LoadArcMember, GURU2_MAIN_SetPlayerInput, GURU2_MAIN_StoreRoundResult, GURU2_MAIN_ClearSendBuffer, GURU2_MAIN_GetSendBuffer, GURU2_MAIN_IsMemberFlagSet, GURU2_MAIN_AreAllOthersReady, GURU2_MAIN_CountReadyMembers, GURU2_MAIN_StoreSlotAssignment, GURU2_MAIN_SyncPlayerCount, GURU2_MAIN_IsMemberPresent, GURU2_MAIN_CopyMemberPokemon, GURU2_MAIN_CountActiveMembers, GURU2_MAIN_SetPlayerSelectedSlot, GURU2_MAIN_StoreAngles, GURU2_MAIN_IsAngleInRangeList, GURU2_MAIN_PartyHasEligiblePokemon, GURU2_MAIN_AnyMemberHasEligiblePokemon, GURU2_MAIN_CountContinueVotes, GURU2_MAIN_IsAbortVoted, GURU2_MAIN_PushAndPlayBgm, GURU2_MAIN_PopBgmWhenDone, GURU2_MAIN_BroadcastResult
 * address:  0x021DE7FC
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from guru2_main.c by tools/splitfile.py.
 *
 * symbols:
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   UNION_APP_GetJoinedBits 0x021841A0 thumb ov022
 *   GURU2_MAIN_StoreSlotAssignment 0x021E172C thumb ov137
 *   GURU2_MAIN_SyncPlayerCount 0x021E1758 thumb ov137
 *   GURU2_MAIN_SetPlayerInput 0x021E168C thumb ov137
 *   GURU2_MAIN_StoreRoundResult 0x021E1694 thumb ov137
 *   GURU2_MAIN_SetPlayerSelectedSlot 0x021E180C thumb ov137
 *   GURU2_MAIN_StoreAngles 0x021E1814 thumb ov137
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   UNION_APP_RequestReset 0x02184174 thumb ov022
 *   UNION_APP_IsResetDone 0x0218417C thumb ov022
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   STRBUF_Delete 0x02045808 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   MYSTATUS_NameToStrbuf 0x02008500 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   G3D_UTIL_Create 0x02047CFC arm
 *   TCB_GetTaskOffset 0x02030CB0 arm
 *   TCB_Init 0x02030CBC arm
 *   gGuru2SlotAngleTable 0x021E1FA0 data a2
 *   gGuru2MainAllocFileName 0x021E22B8 data a1
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   TCB_Noop 0x02030DA4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   UI_ClearSoftResetInhibitGlobal 0x020351A0 arm
 *   gGuru2MainStateTable 0x021E217C data a4
 *   TCB_Main 0x02030D28 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_SendDataMask 0x0203D4D0 arm
 *   gGuru2PointerAngleTable 0x021E1FDC data a2
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   GURU2_MAIN_BroadcastResult 0x021E19C0 thumb ov137
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   GAME_DATA_GetMyItem 0x0201292C thumb
 *   MYITEM_SAVEDATA_AddItem 0x02007E50 thumb
 *   gGuru2RewardRangeTable 0x021E1F34 data a4
 *   RECORD_AddOne 0x02008DF0 thumb
 *   UI_SetSoftResetInhibitGlobal 0x0203516C arm
 *   GFL_NET_SAVE_Create 0x0201088C thumb
 *   TIME_ICON_Create 0x0202EE30 thumb
 *   GFL_NET_SAVE_CheckFinished 0x02010904 thumb
 *   GFL_NET_ERR_WaitLinkClosed 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   GFL_NET_SAVE_Delete 0x02010934 thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   G3D_CAMERA_SetFar 0x02048B6C arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   NNS_G3dGlbLightVector 0x0206AA3C arm
 *   NNS_G3dGlbLightColor 0x0206AA78 arm
 *   NNS_G3dGlbMaterialColorDiffAmb 0x0206AA8C arm
 *   NNS_G3dGlbMaterialColorSpecEmi 0x0206AAB0 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   TIME_ICON_Update 0x0202F0B0 thumb
 *   gGuru2GameVramBanks 0x021E1EA4 data a4
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   G3X_SetEdgeColorTable 0x0207DCF8 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   gGuru2ToonTable 0x021E1D90 data a2
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   gGuru2CameraTarget 0x021E2020 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   gGuru2CameraEye 0x021E1D00 data a4
 *   gGuru2CameraUp 0x021E1D0C data a4
 *   gGuru2GameDispConfig 0x021E202C data a4
 *   gGuru2GameBg1Template 0x021E204C data a4
 *   gGuru2GameBg2Template 0x021E206C data a4
 *   gGuru2GameBg3Template 0x021E208C data a4
 *   gGuru2GameBg6Template 0x021E20AC data a4
 *   gGuru2GameBg7Template 0x021E20CC data a4
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   NNS_G2dGetUnpackedCharacterData 0x02062A00 arm
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   NNS_G2dGetUnpackedScreenData 0x02062B30 arm
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   gGuru2SlotDescTable 0x021E1E30 data a4
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   gGuru2TouchRects 0x021E1CB0 data a4
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   gGuru2PlayerUnitSetupTable 0x021E20EC data a4
 *   gGuru2PlayerUnitHeightTable 0x021E1DE8 data a4
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   BUTTON_MAN_MakeRotMtxXYZ 0x020520FC arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   gGuru2BackgroundUnitSetup 0x021E1D80 data a4
 *   gGuru2MarkerUnitSetupA 0x021E1E60 data a4
 *   gGuru2MarkerUnitSetupB 0x021E1E70 data a4
 *   gGuru2CardUnitSetupTable 0x021E212C data a4
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   GF_STANDARD_CosFromDegrees 0x0203F63C arm
 *   GF_STANDARD_SinFromDegrees 0x0203F5FC arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   TCB_AddTask 0x02030DA8 arm
 *   gGuru2DropEffectStateTable 0x021E1CB8 data a4
 *   gGuru2CountSeTable 0x021E203C data a4
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   gGuru2PulseScaleTable 0x021E2278 data a4
 *   gGuru2FadeValues 0x021E2018 data a4
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 *   GURU2_COMM_GetPartyCopy 0x021DCE00 thumb ov137
 *   SAVE_EVENT_Write 0x0202F190 thumb
 *   POKE_TOOL_CopyPartyPokemon 0x02019CE0 thumb
 *   gGuru2PlayerAngleRangeLists 0x021E1F04 data a4
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   GURU2_MAIN_RotateAll   0x021E1604  thumb  ov137
 *   MET_TRAINERS_Insert  0x0200ED54  thumb  arm9
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "ov137_types.h"
#include "../sdk_ioreg.h"
#include "guru2_shared_types.h"
#include "guru2_comm_shared_types.h"
#include "guru2_types.h"
#include "guru2_receipt_shared_types.h"
#include "../arm9/g3d_util.h"
#include "../arm9/nns_g3d_glb.h"
#include "../arm9/g3d_system.h"

#include "../arm9/procsys.h"

#include "../arm9/mi_memory.h"


#include "../arm9/gfl_heap_wrap.h"
struct GameData;

#include "../arm9/game_data.h"

struct GFLNetHandle;

#include "../arm9/net_handle.h"

#include "../arm9/net_system.h"
struct UnionAppWork;

#include "../ov022/union_app.h"


#include "../arm9/gfl_heap.h"

#include "../arm9/arc_tool.h"

#include "../arm9/bg_sys.h"
struct WordSet;

#include "../arm9/gf_font.h"

#include "../arm9/msgdata.h"


#include "../arm9/wipe.h"
struct TcbTask;

#include "../arm9/gfl_use.h"
struct PrintQueue;

#include "../arm9/printsys.h"

#include "../arm9/net.h"



#include "../arm9/net_err.h"



#include "../arm9/clact.h"

#include "../arm9/net_command.h"




#include "../arm9/wordset.h"

struct TcbTask;

#include "../arm9/tcb_list.h"





struct Guru2Comm;

#include "guru2_comm.h"

#define DISP3D (*(volatile u16 *)REG_DISP3DCNT_ADDR)

struct Ctx;

struct Big;

struct L0200ED54;

struct Sub02008C20Obj;

struct Sub0201088CObj;

struct S02021D50;

struct Light;

struct NitroFileHeader;


struct Util;

struct Setup;

struct Arg;

struct Mtx33;

struct ClactActor;

struct ArcFile;

struct RecDC;

typedef struct { u8 pad[0x90]; void *slots[5]; void *other[5]; } SlotObj;

typedef struct {int a,b;u16 values[5];u16 flag;} Guru2MainMsg;

typedef struct {u8 pad[28]; int angle;} Selected;

typedef struct { int state; u8 pad[36]; Selected *selected; int index, count; } SelectObj;

typedef struct { u8 pad[0x60]; u16 angles[5]; } AngleObj;

struct RangeU32 { u32 low, high; };

#include "../sdk_gx.h"

typedef struct { u32 x, y, z; } Guru2MainVec3;

typedef struct { u32 layer; u8 a,b,c,d; u16 e,pad; } Guru2MainDesc;

typedef struct { int x,y,z; } Guru2MainVec;

typedef struct { int m[9]; } Mtx;

typedef struct { Guru2MainVec pos,scale; Mtx rot; } Transform;

typedef enum { COUNT_ZERO=0, COUNT_NEGATIVE=-1 } Count;

typedef struct { int active; char rest[0xb0]; } RecordA;

typedef struct { int active; char rest[0x78]; } RecordB;

typedef struct { int active; char rest[0x64]; } RecordC;

typedef struct {
    char pad[0x140];
    RecordA a[5];
    RecordB b[5];
    RecordC c[5];
} PlayerBlock;

/* Unit ids of the shadow, marker and player pieces, at Guru2Game 0xAD8 (PlayerBlock base + 0x938). */
struct Guru2UnitIds {
    int shadowUnit;
    int markerUnit;
    int playerUnit[5];
};

typedef struct { int active; char rest[0xb0]; } PlayerRecord;

typedef struct { char pad[0x140]; PlayerRecord records[1]; } Guru2MainRecordBlock;

typedef struct { int active, state, x, y, key; } EntryA;

typedef struct { int active, state, x, y, z, key; } EntryB;

typedef struct {unsigned state;int active,other,timer,speed;} PlayerState;

typedef struct { int v[4]; } Table;

typedef struct { u16 state, flag; int count; } ModeState;

typedef struct
{
  int active;
  int a;
  int b;
  int key;
  char rest[0xa4];
} KeyRecord;

typedef struct
{
  char pad[0x140];
  KeyRecord records[1];
} Block;

typedef struct { int a, b; } IntPair;


struct RangeU16 { u16 lo, hi; };
struct RangeList { unsigned count; struct RangeU16 *ranges; };




struct Strbuf;

#include "../arm9/strbuf.h"





#include "../arm9/bmp_menuwork.h"

struct DispVramCfg;
struct SysInit;













#include "../arm9/bmp_win.h"

struct BmpWin;
struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"









struct UnionAppEntry;





#include "../arm9/mystatus.h"

struct MyStatus;






struct TcbSystem;

struct TimeIcon;

#include "../arm9/time_icon.h"




#include "../arm9/ui.h"

struct TcbList;




struct SaveControl;


#include "../arm9/met_trainers_savedata.h"
struct MetTrainersSave;


extern void GURU2_MAIN_BroadcastResult(struct Guru2Game *,int);

struct MyItem;

#include "../arm9/myitem_savedata.h"

#include "../arm9/record.h"

struct NetSaveTask;

#include "../arm9/net_save.h"






struct G3dCamera;

#include "../arm9/g3d_camera.h"



extern void NNS_G3dGlbLightColor(int,u32);
extern void NNS_G3dGlbMaterialColorDiffAmb(u32,u32,u32);
extern void NNS_G3dGlbMaterialColorSpecEmi(u32,u32,u32);



#include "../arm9/g2.h"

#include "../arm9/g3x.h"





#include "../arm9/nns_g2d_anim_bank.h"

#include "../arm9/palanm.h"




#include "../arm9/nns_g2d_load.h"














#include "../arm9/touchpanel.h"




#include "../arm9/button_man.h"
struct G3dObjectStatus;
struct G3dObject;


#include "../arm9/fx_mtx33.h"

#include "../arm9/gf_standard.h"






struct ArcHandle;



struct Party;
struct PokemonParam;

#include "../arm9/pokeparty.h"

#include "../arm9/save_event.h"
struct PartyPokemon;

#include "../arm9/poke_tool.h"







int GURU2_MAIN_ProcInit(void *obj,int unused,struct Guru2Session *q);

int GURU2_MAIN_ProcExit(struct Proc *a, int b, int c, struct Guru2Game *p);

int GURU2_MAIN_ProcMain(int a, int b, int c, struct Guru2Game *p);

void GURU2_MAIN_ClearTransferFlags(struct Guru2Game *p);

int GURU2_MAIN_StateStart(struct Guru2Game *p);

int GURU2_MAIN_StateWaitWipeIn(struct Guru2Game *p);

int GURU2_MAIN_StateWaitIntroMessage(struct Guru2Game *p);

int GURU2_MAIN_StateSendReady(struct Guru2Game *p);

void *GURU2_MAIN_GetUnionApp(struct Guru2Game *p);

int GURU2_MAIN_StateWaitAllMembers(struct Guru2Game *p);

int GURU2_MAIN_StateSendPlayerCount(struct Guru2Game *p);

int GURU2_MAIN_StateCollectReadyMasks(struct Guru2Game *p);

int GURU2_MAIN_StateSendAbort(struct Guru2Game *p);

int GURU2_MAIN_StateSendCancel(struct Guru2Game *p);

int GURU2_MAIN_StateWaitCancelMessage(struct Guru2Game *p);

int GURU2_MAIN_StateStartSync1(struct Guru2Game *p);

int GURU2_MAIN_StateWaitSync1(struct Guru2Game *p);

int GURU2_MAIN_StateSendSelectedSlot(struct Guru2Game *p);

int GURU2_MAIN_StateBroadcastPlayerData(struct Guru2Game *p);

int GURU2_MAIN_StateWaitPlayerData(struct Guru2Game *p);

int GURU2_MAIN_StateWaitBranch(struct Guru2Game *p);

int GURU2_MAIN_StateBuildPlayerSlots(struct Guru2Game *p);

int GURU2_MAIN_StateAnimateSlots(char *p);

int GURU2_MAIN_StateWaitAllSlotsReady(char *p);

int GURU2_MAIN_StateDelayRole(struct Guru2Game *p);

int GURU2_MAIN_StateSendRoleChild(struct Guru2Game *p);

void GURU2_MAIN_RegisterPlayerRecords(struct Guru2Game *obj);

int GURU2_MAIN_StateWaitRoleMessage(struct Guru2Game *p);

int GURU2_MAIN_StateStartSync2(struct Guru2Game *p);

int GURU2_MAIN_StateWaitSync2(struct Guru2Game *p);

int GURU2_MAIN_StateShowRound(struct Guru2Game *p);

int GURU2_MAIN_StateRoundDelay(struct Guru2Game *p);

int GURU2_MAIN_StateToPlay(struct Guru2Game *p);

int GURU2_MAIN_StatePlayRound(struct Guru2Game *p);

int GURU2_MAIN_StateRoundEnd(struct Guru2Game *p);

int GURU2_MAIN_StateRoundEndChild(struct Guru2Game *p);

int GURU2_MAIN_StepAngle(struct Guru2Game *p);

int GURU2_MAIN_StateStartSync3(struct Guru2Game *p);

int GURU2_MAIN_StateWaitSync3(struct Guru2Game *p);

int GURU2_MAIN_SendAngles(struct Guru2Game *p);

int GURU2_MAIN_ApplyAngles(struct Guru2Game *p);

int GURU2_MAIN_ShowResultNames(struct Guru2Game *p);

int GURU2_MAIN_StateResultDelay(struct Guru2Game *p);

int GURU2_MAIN_StateWaitSe(struct Guru2Game *p);

int GURU2_MAIN_StateComputeReward(struct Guru2Game *p);

int GURU2_MAIN_StateWaitEffectToEnd(struct Guru2Game *p);

int GURU2_MAIN_StateWaitEffectToMessage(struct Guru2Game *p);

int GURU2_MAIN_StateWaitTimerToEnd(struct Guru2Game *p);

int GURU2_MAIN_StateSaveResult(struct Guru2Game *p);

int GURU2_MAIN_StateAfterSync4(struct Guru2Game *p);

int GURU2_MAIN_StateWaitSaveDone(struct Guru2Game *p);

int GURU2_MAIN_StateShowEndMessage(struct Guru2Game *p);

int GURU2_MAIN_StateEndDelay(struct Guru2Game *p);

int GURU2_MAIN_StateStartSync5(struct Guru2Game *p);

int GURU2_MAIN_StateWaitSync5(struct Guru2Game *p);

int GURU2_MAIN_StateWaitUnionAppReset(struct Guru2Game *p);

int GURU2_MAIN_StateStartWipeOut(struct Guru2Game *p);

int GURU2_MAIN_StateWaitWipeOut(struct Guru2Game *p);

int GURU2_MAIN_StateFinished(void);

void GURU2_MAIN_VBlank(void *arg,struct Guru2Game *p);

void GURU2_MAIN_SetupAll(struct Guru2Game *p);

void GURU2_MAIN_TeardownAll(struct Guru2Game *p);

void GURU2_MAIN_Draw3D(struct Guru2Game *p);

void GURU2_MAIN_SetupVram(struct Guru2Game *p);

void GURU2_MAIN_ShowPlanes(struct Guru2Game *p);

void GURU2_MAIN_HidePlanes(struct Guru2Game *p);

void GURU2_MAIN_Setup3dState(void);

void GURU2_MAIN_Setup3dSystem(struct Guru2Game *p);

void GURU2_MAIN_SetupBg(struct Guru2Game *p);

void GURU2_MAIN_LoadBgPalette(struct Guru2Game *p);

void GURU2_MAIN_ExitBg(struct Guru2Game *p);

void GURU2_MAIN_LoadScreen(struct Guru2Game *p,int file);

void GURU2_MAIN_LoadScreen26(struct Guru2Game *p);

void GURU2_MAIN_LoadScreen24(struct Guru2Game *p);

void GURU2_MAIN_LoadScreen25(struct Guru2Game *p);

void GURU2_MAIN_CreatePaletteAnim(struct Guru2Game *p);

void GURU2_MAIN_DeletePaletteAnim(struct Guru2Game *p);

void GURU2_MAIN_BlendPalette(struct Guru2Game *p,int a);

void GURU2_MAIN_InitActorSystem(struct Guru2Game *p);

void GURU2_MAIN_LoadActorResources(struct Guru2Game *p);

void GURU2_MAIN_FreeActorResources(struct Guru2Game *p);

void GURU2_MAIN_CreateWindows(struct Guru2Game *p);

void GURU2_MAIN_DeleteWindows(struct Guru2Game *p);

void GURU2_MAIN_PrintMessage(struct Guru2Game *p,int message);

void GURU2_MAIN_PrintMessageWithName(struct Guru2Game *p,int message,void *value);

void GURU2_MAIN_PrintMessageWithNumber(struct Guru2Game *p,int message,unsigned value);

void GURU2_MAIN_ClearMessageWindow(struct Guru2Game *p);

void GURU2_MAIN_CreateNameWindows(struct Guru2Game *p,int count);

void GURU2_MAIN_DeleteNameWindows(struct Guru2Game *p);

void GURU2_MAIN_PrintNameWindow(struct Guru2Game *p,void *text,int index,int color);

void GURU2_MAIN_PrintPlayerName(struct Guru2Game *p,void *text,int index,int a);

void GURU2_MAIN_ClearNameWindow(struct Guru2Game *p,u32 i);

void GURU2_MAIN_DeleteCamera(struct Guru2Game *p);

int GURU2_MAIN_IsTouched(struct Guru2Game *p);

void GURU2_MAIN_AddCenterUnit(struct Guru2Game *p);

void GURU2_MAIN_RemoveCenterUnit(struct Guru2Game *p);

void GURU2_MAIN_UpdateCenterTransform(struct Guru2Game *p);

void GURU2_MAIN_DrawCenterUnit(struct Guru2Game *p);

void GURU2_MAIN_AddAngle(struct Guru2Spinner *s,int a);

void GURU2_MAIN_AddBackgroundUnit(struct Guru2Game *p);

void GURU2_MAIN_RemoveBackgroundUnit(struct Guru2Game *p);

void GURU2_MAIN_DrawBackgroundUnit(struct Guru2Game *p);

void GURU2_MAIN_AddPlayerUnits(struct Guru2Game *p);

void GURU2_MAIN_RemovePlayerUnits(struct Guru2Game *p);

void GURU2_MAIN_ActivatePlayerRecord(struct Guru2Game *p,struct Guru2Player *q);

void GURU2_MAIN_UpdatePlayerRecords(struct Guru2Game *p);

void GURU2_MAIN_DrawPlayerRecords(struct Guru2Game *p);

void GURU2_MAIN_RotatePlayerRecords(struct Guru2Game *p,int amount);

void GURU2_MAIN_UpdateRecordPosition(struct Guru2Player *p,struct Guru2Vec3 *q,int amount,int extra);

void *GURU2_MAIN_FindNearestPlayerRecord(struct Guru2Game *p);

void GURU2_MAIN_ActivatePlayerUnit(struct Guru2Game *p,struct Guru2Player *q);

void GURU2_MAIN_InitPlayerUnit(struct Guru2Game *p,struct Guru2Shadow *q,int amount);

void GURU2_MAIN_ActivateCardUnit(struct Guru2Game *p, struct Guru2Player *q);

void GURU2_MAIN_UpdateCardUnitAnim(struct Guru2Game *p,struct Guru2Marker *q,int i);

void GURU2_MAIN_StartDropEffect(struct Guru2Game *p,int a,int b,int c,int d,int e,int *q);

void GURU2_MAIN_DropEffectTask(struct Node *task,char *p);

/* Work of one drop effect task (24 bytes), allocated by GURU2_MAIN_StartDropEffect. */
struct Guru2DropEffect {
    int state;                        /* 0x00 index into gGuru2DropEffectStateTable */
    unsigned char pad_04[4];
    int landSePlayed;                 /* 0x08 1 once the landing sound started */
    int fallSpeed;                    /* 0x0C */
    struct Guru2Player *player;       /* 0x10 piece that drops */
    struct Guru2Game *game;           /* 0x14 */
};

int GURU2_MAIN_DropEffectStateInit(struct Guru2DropEffect *p);

int GURU2_MAIN_DropEffectStateFall(int *p);

int GURU2_MAIN_DropEffectStateLand(int *p);

void GURU2_MAIN_UpdateBounceEffect(struct Guru2Game *p,int *q);

void GURU2_MAIN_BounceEffectTask(void *unused,struct Guru2Game *p);

void GURU2_MAIN_CreateBounceEffectTask(struct Guru2Game *p);

void GURU2_MAIN_DeleteBounceEffectTask(struct Guru2Game *p);

void GURU2_MAIN_AddBounceEffect(struct Guru2Game *p,int value);

void GURU2_MAIN_AddBounceEffectsForActivePlayers(struct Guru2Game *p);

int GURU2_MAIN_IsBounceEffectActive(struct Guru2Game *p);

void GURU2_MAIN_UpdateSettleEffect(int *p);

void GURU2_MAIN_SettleEffectTask(void *unused,struct Guru2Game *p);

void GURU2_MAIN_CreateSettleEffectTask(struct Guru2Game *p);

void GURU2_MAIN_DeleteSettleEffectTask(struct Guru2Game *p);

void GURU2_MAIN_AddSettleEffect(struct Guru2Game *p, int key);

void GURU2_MAIN_UpdateWobbleEffect(int *p);

void GURU2_MAIN_WobbleEffectTask(void *unused,struct Guru2Game *p);

void GURU2_MAIN_CreateWobbleEffectTask(struct Guru2Game *p);

void GURU2_MAIN_DeleteWobbleEffectTask(struct Guru2Game *p);

void GURU2_MAIN_AddWobbleEffect(struct Guru2Game *p, int key);

void GURU2_MAIN_UpdateEntranceEffect(u8 *p,PlayerState *s);

void GURU2_MAIN_EntranceEffectTask(void *unused,u8 *p);

void GURU2_MAIN_CreateEntranceEffectTask(struct Guru2Game *p);

void GURU2_MAIN_DeleteEntranceEffectTask(struct Guru2Game *p);

void GURU2_MAIN_StartEntranceEffect(struct Guru2Game *p);

int GURU2_MAIN_GetEntranceEffectState(struct Guru2Game *p);

int GURU2_MAIN_GetEntranceEffectActive(struct Guru2Game *p);

void GURU2_MAIN_CenterActorTask(void *task, int *p);

void GURU2_MAIN_CreateCenterActorTask(char *p);

void GURU2_MAIN_UpdateScreenFlash(void *task, ModeState *p);

void GURU2_MAIN_ScreenFlashTask(void *unused, char *p);

void GURU2_MAIN_CreateScreenFlashTask(struct Guru2Game *p);

void GURU2_MAIN_DeleteScreenFlashTask(struct Guru2Game *p);

u16 GURU2_MAIN_GetScreenFlashFlag(struct Guru2Game *p);

void GURU2_MAIN_StartScreenFlash(struct Guru2Game *p);

void GURU2_MAIN_UpdatePulseEffect(void *unused, int *p);

void GURU2_MAIN_PulseEffectTask(void *unused, char *p);

void GURU2_MAIN_CreatePulseEffectTask(struct Guru2Game *p);

void GURU2_MAIN_DeletePulseEffectTask(struct Guru2Game *p);

/* One pulse effect slot, array of 5 at Guru2Game.fx5 (16 bytes each). */
struct Guru2PulseSlot {
    int active;                       /* 0x00 */
    unsigned char pad_04[8];
    struct Guru2Player *owner;        /* 0x0C player piece the pulse follows */
};

void GURU2_MAIN_AddPulseEffect(char *p, char *q);

void GURU2_MAIN_AddPulseEffectsForMask(const char *p);

void GURU2_MAIN_BlendFadeTask(void *task, int *p);

void GURU2_MAIN_StartBlendFade(struct Guru2Game *p, int flag);

void GURU2_MAIN_AddAngleWrapped(int *p, int v);

extern void GURU2_MAIN_RotateAll(struct Guru2Game *, int);

int GURU2_MAIN_TickTimeout(struct Guru2Game *p);

void *GURU2_MAIN_LoadArcMember(struct Guru2Game *p, u32 member, int flag);

void GURU2_MAIN_SetPlayerInput(struct Guru2Game *p,int a);

void GURU2_MAIN_StoreRoundResult(struct Guru2Game *p, const Guru2FiveRecord *q);

char *GURU2_MAIN_ClearSendBuffer(struct Guru2Game *p, int n);

char *GURU2_MAIN_GetSendBuffer(struct Guru2Game *p);

int GURU2_MAIN_IsMemberFlagSet(struct Guru2Game *p, int mask);

int GURU2_MAIN_AreAllOthersReady(const struct Guru2Game *p);

int GURU2_MAIN_CountReadyMembers(struct Guru2Game *p);

void GURU2_MAIN_StoreSlotAssignment(struct Guru2Game *p,unsigned short *q);

void GURU2_MAIN_SyncPlayerCount(struct Guru2Game *p, int unused);

int GURU2_MAIN_IsMemberPresent(struct Guru2Game *p, int i);

void GURU2_MAIN_CopyMemberPokemon(struct Guru2Game *p, int i);

int GURU2_MAIN_CountActiveMembers(struct Guru2Game *p);

void GURU2_MAIN_SetPlayerSelectedSlot(struct Guru2Game *p,int a,int b);

void GURU2_MAIN_StoreAngles(struct Guru2Game *p,u16 *q);

int GURU2_MAIN_IsAngleInRangeList(char *p, int angle, int index);

int GURU2_MAIN_PartyHasEligiblePokemon(void *p);

int GURU2_MAIN_AnyMemberHasEligiblePokemon(struct Guru2Game *p);

int GURU2_MAIN_CountContinueVotes(struct Guru2Game *p);

int GURU2_MAIN_IsAbortVoted(struct Guru2Game *p);

void GURU2_MAIN_PushAndPlayBgm(unsigned int n);

int GURU2_MAIN_PopBgmWhenDone(void);

extern const struct Cfg gClActorInitParam;

extern const u16 gGuru2SlotAngleTable[][5];

extern const char gGuru2MainAllocFileName[];

extern const u16 gGuru2PointerAngleTable[][5];

extern struct RangeU32 gGuru2RewardRangeTable[];

extern const struct DispVram gGuru2GameVramBanks;

extern const u16 gGuru2ToonTable[];

extern const Guru2MainVec3 gGuru2CameraTarget;

extern const s16 d_020A1EB8[];

extern Guru2MainVec3 gGuru2CameraEye, gGuru2CameraUp;

extern const struct DispConfig gGuru2GameDispConfig;

extern const struct BgTemplate gGuru2GameBg1Template,gGuru2GameBg2Template,gGuru2GameBg3Template,gGuru2GameBg6Template,gGuru2GameBg7Template;

extern const Guru2MainDesc *const gGuru2SlotDescTable[];

extern const u8 gGuru2TouchRects[];

extern const Guru2ReceiptDescriptor gGuru2PlayerUnitSetupTable[];

extern const int gGuru2PlayerUnitHeightTable[];

extern const struct Setup gGuru2BackgroundUnitSetup;

extern const char gGuru2MarkerUnitSetupA[],gGuru2MarkerUnitSetupB[],gGuru2CardUnitSetupTable[];

extern const Table gGuru2CountSeTable;

extern const int gGuru2PulseScaleTable[];

extern const IntPair gGuru2FadeValues;

extern struct RangeList gGuru2PlayerAngleRangeLists[];

int GURU2_MAIN_ProcInit(void *obj,int unused,struct Guru2Session *session)
{
    struct Guru2Game *p;
    struct Guru2Spinner *s;
    void *r;
    int i,n,player;
    GFL_NET_SetAutoExit(1);
    GFL_HEAP_CreateChildHeap(1,114,0x80000);
    p=PROCSYS_AllocProcWork(obj,0xdac,114);
    i=0;
    MI_CpuFill8(p,0,0xdac);
    session->gameWork=p;
    p->session=session;
    p->comm=session->comm;
    p->party=GAME_DATA_GetMyParty(p->session->param->gameData);
    p->arcHandle=ARC_TOOL_CreateHandle(183,114);
    GURU2_MAIN_SetupAll(p);
    p->taskMain=GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))((void (*)(int,  void *))GURU2_MAIN_VBlank),(void *)p,1);
    p->g3dUtil=G3D_UTIL_Create(20,11,114);
    GURU2_MAIN_AddBackgroundUnit(p);GURU2_MAIN_AddPlayerUnits(p);GURU2_MAIN_AddCenterUnit(p);
    n=0;
    player=GFL_NET_SYSTEM_GetCurrentAid();
    s=&p->spinner;
    session=p->session;
    for(;i<5;i++) {
        if(session->memberMask&(1<<i)) {if(i==player) break;n++;}
    }
    s->speed=gGuru2SlotAngleTable[session->playerCount][n]<<12;
    r=GFL_HEAP_Alloc(0x8072,TCB_GetTaskOffset(32),0,gGuru2MainAllocFileName,0x4ec);
    p->taskCtx=r;
    p->taskMgr=TCB_Init(32,r);
    GURU2_MAIN_CreateBounceEffectTask(p);GURU2_MAIN_CreateSettleEffectTask(p);GURU2_MAIN_CreateWobbleEffectTask(p);GURU2_MAIN_CreateEntranceEffectTask(p);GURU2_MAIN_CreateScreenFlashTask(p);GURU2_MAIN_CreatePulseEffectTask(p);
    WIPE_SYS_Start(0,1,1,0,8,1,114);
    GFL_NET_SetLoginOption(1);
    return 1;
}

int GURU2_MAIN_ProcExit(struct Proc *proc, int seq, int parentWork, struct Guru2Game *p)
{
    PRINTSYS_QUE_Clear(p->windows.printQueue);
    PRINTSYS_QUE_Delete(p->windows.printQueue);
    if (p->timeIcon != 0) TIME_ICON_Delete(p->timeIcon);
    GURU2_MAIN_DeleteBounceEffectTask(p);
    GURU2_MAIN_DeleteSettleEffectTask(p);
    GURU2_MAIN_DeleteWobbleEffectTask(p);
    GURU2_MAIN_DeleteEntranceEffectTask(p);
    GURU2_MAIN_DeleteScreenFlashTask(p);
    GURU2_MAIN_DeletePulseEffectTask(p);
    TCB_Noop(p->taskMgr);
    GFL_HEAP_Free(p->taskCtx);
    GURU2_MAIN_RemoveBackgroundUnit(p);
    GURU2_MAIN_RemoveCenterUnit(p);
    GURU2_MAIN_RemovePlayerUnits(p);
    G3D_UTIL_Delete(p->g3dUtil);
    G3D_SYSTEM_Exit();
    GURU2_MAIN_TeardownAll(p);
    TCB_DeleteTask(p->taskMain);
    ARC_TOOL_DeleteHandle(p->arcHandle);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x72);
    UI_ClearSoftResetInhibitGlobal(8);
    return 1;
}

extern int (*const gGuru2MainStateTable[])(void *);

int GURU2_MAIN_ProcMain(int proc, int seq, int parentWork, struct Guru2Game *p)
{
    int result;
    do { result = gGuru2MainStateTable[p->state](p); } while (result == 1);
    if (result == 2) return 1;
    GURU2_MAIN_UpdateCenterTransform(p);
    GURU2_MAIN_UpdatePlayerRecords(p);
    GURU2_MAIN_Draw3D(p);
    GURU2_MAIN_ClearTransferFlags(p);
    TCB_Main(p->taskMgr);
    if (WIPE_SYS_EndCheck() && GFL_NET_ERR_GetErrorLevel()) return 1;
    return 0;
}

void GURU2_MAIN_ClearTransferFlags(struct Guru2Game *p) { p->unknown_34=0;p->unknown_3C=0; }

int GURU2_MAIN_StateStart(struct Guru2Game *p)
{
    GURU2_MAIN_PrintMessage(p, 0);
    p->state = 1;
    return 0;
}

int GURU2_MAIN_StateWaitWipeIn(struct Guru2Game *p)
{
    if (WIPE_SYS_EndCheck()) {
        p->state = GFL_NET_SYSTEM_GetCurrentAid() == 0 ? 2 : 8;
        p->timeIcon = TIME_ICON_Create(p->taskMgr, p->windows.mainWindow, 15, 16, 114);
        return 1;
    }
    return 0;
}

int GURU2_MAIN_StateWaitIntroMessage(struct Guru2Game *p)
{
    if (GURU2_MAIN_AreAllOthersReady(p)) {
        p->state = 3;
        return 1;
    }
    return 0;
}

int GURU2_MAIN_StateSendReady(struct Guru2Game *p) {u16 v=1;if(GURU2_COMM_Send(p->comm,0x2805,&v,2)==1){p->state=4;return 1;}return 0;}

/*
 * extent: two trailing bytes of zero alignment padding.
 */
void *GURU2_MAIN_GetUnionApp(struct Guru2Game *p) {return p->session->param->unionApp;}

int GURU2_MAIN_StateWaitAllMembers(struct Guru2Game *p) {unsigned v;v=GURU2_MAIN_CountReadyMembers(p)+1;if(v!=UNION_APP_GetMemberCount(GURU2_MAIN_GetUnionApp(p)))return 0;p->state=5;return 1;}

int GURU2_MAIN_StateSendPlayerCount(struct Guru2Game *p) {p->playerCount=GURU2_MAIN_CountReadyMembers(p)+1;if(GURU2_COMM_Send(p->comm,0x280A,&p->playerCount,4)==1){p->sendCount=0;p->state=6;}return 0;}

int GURU2_MAIN_StateCollectReadyMasks(struct Guru2Game *p)
{
    u16 buf[2];
    int i, count;
    u16 mask;
    if (p->sendCount == 0) {
        buf[1] = 0; buf[0] = 0;
        if (GURU2_COMM_Send(p->comm, 10249, buf, 4) == 1) (p->sendCount)++;
        return 0;
    }
    i = 1;
    mask = p->comm->ackMask;
    for (count = 1; i < 5; i++) {
        if (mask & (1 << i)) {
            if (count >= p->sendCount) {
                buf[1] = i; buf[0] = p->sendCount;
                if (GURU2_COMM_Send(p->comm, 10249, buf, 4) == 1) (p->sendCount)++;
                break;
            }
            count++;
        }
    }
    if (p->sendCount >= p->playerCount) p->state = 7;
    return 0;
}

int GURU2_MAIN_StateSendAbort(struct Guru2Game *p) {u16 v=8;if(GURU2_COMM_Send(p->comm,0x2805,&v,2)==1)p->state=10;return 0;}

int GURU2_MAIN_StateSendCancel(struct Guru2Game *p) {if(GURU2_COMM_Send(p->comm,0x2806,0,0)==1){p->state=9;p->waitCount=0;return 0;}return 0;}

int GURU2_MAIN_StateWaitCancelMessage(struct Guru2Game *p) {if(GURU2_MAIN_IsMemberFlagSet(p,8)==1){p->playerCount=GURU2_MAIN_CountReadyMembers(p)+1;p->state=10;}return 0;}

int GURU2_MAIN_StateStartSync1(struct Guru2Game *p) {void *v;v=GFL_NET_HANDLE_GetCurrentHandle();TIME_ICON_Delete(p->timeIcon);p->timeIcon=0;GFL_NET_HANDLE_SetTimingSyncRange(v,202,40);p->state=11;return 0;}

int GURU2_MAIN_StateWaitSync1(struct Guru2Game *p) {if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),202,40))p->state=12;return 0;}

int GURU2_MAIN_StateSendSelectedSlot(struct Guru2Game *p) {if(GURU2_COMM_Send(p->comm,0x280B,(char *)p->session+4,4))p->state=13;return 0;}

int GURU2_MAIN_StateBroadcastPlayerData(struct Guru2Game *p)
{
    void *q;
    q = GFL_NET_HANDLE_GetCurrentHandle();
    if ((int)GFL_NET_SendDataMask(q, (u8)((int)UNION_APP_GetJoinedBits(GURU2_MAIN_GetUnionApp(p))), (int)10255, (int)1428, (p->party), (int)1, (int)1, (int)1))
        p->state = 14;
    return 0;
}

int GURU2_MAIN_StateWaitPlayerData(struct Guru2Game *p)
{
    if (p->playerCount == GURU2_MAIN_CountActiveMembers(p)) {
        if (GURU2_MAIN_AnyMemberHasEligiblePokemon(p) == 1) {
            GURU2_COMM_Send(p->comm, 10253, 0, 0);
            p->state = 45;
        } else {
            GURU2_COMM_Send(p->comm, 10254, 0, 0);
            p->state = 15;
        }
    }
    return 0;
}

int GURU2_MAIN_StateWaitBranch(struct Guru2Game *p) {if(GURU2_MAIN_IsAbortVoted(p)==1)p->state=45;else if(p->playerCount==GURU2_MAIN_CountContinueVotes(p))p->state=16;return 0;}

int GURU2_MAIN_StateBuildPlayerSlots(struct Guru2Game *p)
{
    struct Guru2SeatInit *slot;
    int i, count;
    slot = (struct Guru2SeatInit *)GURU2_MAIN_ClearSendBuffer(p, 24);
    slot->nextSlot = p->seat;
    count = p->playerCount;
    slot->playerCount = count;
    slot->seatAngle = gGuru2SlotAngleTable[count][p->seat];
    for (i = 0; i < 5; i++) {
        if (GURU2_MAIN_IsMemberPresent(p, i)) {
            p->memberEntry[i] = UNION_APP_GetMemberEntry(GURU2_MAIN_GetUnionApp(p), (u8)i);
            MYSTATUS_NameToStrbuf(p->memberEntry[i], p->nameBuf[i]);
        }
    }
    GURU2_MAIN_RegisterPlayerRecords(p);
    p->spinner.speed = slot->seatAngle << 12;
    p->state = 17;
    GFL_USE_CancelChangeAndPlayBgm(1157, 65535);
    p->session->param->resultFlag = 1;
    GURU2_MAIN_ClearMessageWindow(p);
    return 1;
}

/*
 * extent: unlabelled follower at 021DEED8, filed separately.
 * lever: raw unsigned byte-table address and a named row byte offset restore r6.
 */
int GURU2_MAIN_StateAnimateSlots(char *p)
{
    int *sendBuffer;
    int value, aid, row;
    if (--((struct Guru2Game *)p)->timer>0) return 0;
    ((struct Guru2Game *)p)->timer=15;
    sendBuffer=(int *)GURU2_MAIN_GetSendBuffer((struct Guru2Game *)p);
    row=sendBuffer[5]*10;
    value=*(const u16 *)((uptr)gGuru2PointerAngleTable+row+sendBuffer[4]*2);
    aid=*(u16 *)(p+0x7e + sendBuffer[4]*4);
    *(u16 *)(p+0x60+sendBuffer[4]*2)=value;
    GURU2_MAIN_StartDropEffect((struct Guru2Game *)p,aid,sendBuffer[4],sendBuffer[0],value,sendBuffer[1],(int *)(p+0x2e0+sendBuffer[4]*0xb4));
    sendBuffer[4]++;
    sendBuffer[4]%=sendBuffer[5];
    if (++sendBuffer[0]==sendBuffer[5]) {
        ((struct Guru2Game *)p)->timer=0;
        ((struct Guru2Game *)p)->state=18;
    }
    return 0;
}

int GURU2_MAIN_StateWaitAllSlotsReady(char *p)
{
    char *q=p+0x1a0;
    int i,n,count;
    count=((struct Guru2Game *)p)->playerCount;
    i=0;
    n=0;
    do {
        if (*(int *)(q+i*0xb4+0x148)==1) n++;
        i++;
    } while(i<count);
    if (n==count) {((struct Guru2Game *)p)->state=19;return 1;}
    return 0;
}

int GURU2_MAIN_StateDelayRole(struct Guru2Game *p) {if(++p->timer>30){p->timer=0;if(GFL_NET_SYSTEM_GetCurrentAid()==0)p->state=20;else p->state=21;}return 0;}

int GURU2_MAIN_StateSendRoleChild(struct Guru2Game *p) { u16 buf; buf=4; if(GURU2_COMM_Send(p->comm,0x2805,&buf,2)==1) p->state=22; return 0; }

void GURU2_MAIN_RegisterPlayerRecords(struct Guru2Game *obj)
{
    void *q;
    int i;
    q = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(obj->session->param->gameData));
    for (i = 0; i < 5; i++) {
        if (obj->memberEntry[i] && i != GFL_NET_SYSTEM_GetCurrentAid())
            MET_TRAINERS_Insert(q, MYSTATUS_GetId(obj->memberEntry[i]));
    }
}

/*
 * trailing: Two zero alignment bytes.
 */
int GURU2_MAIN_StateWaitRoleMessage(struct Guru2Game *p) { if(GURU2_MAIN_IsMemberFlagSet(p,4)==1) { p->state=22; return 1; } return 0; }

int GURU2_MAIN_StateStartSync2(struct Guru2Game *p) { GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),203,40); p->state=23; return 0; }

int GURU2_MAIN_StateWaitSync2(struct Guru2Game *p) { if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),203,40)) p->state=24; return 0; }

int GURU2_MAIN_StateShowRound(struct Guru2Game *p) { GURU2_MAIN_StartBlendFade(p,1); GURU2_MAIN_CreateCenterActorTask((char *)p); p->state=25; return 0; }

int GURU2_MAIN_StateRoundDelay(struct Guru2Game *p) { int i; p->timer+=1; if(p->timer<95) return 0; for(i=0;i<p->playerCount;i++) GURU2_MAIN_ClearNameWindow(p,i); p->timer=0; p->state=26; return 0; }

int GURU2_MAIN_StateToPlay(struct Guru2Game *p)
{
    GFL_NET_SYSTEM_GetCurrentAid();
    p->state = 0x1b;
    return 0;
}

int GURU2_MAIN_StatePlayRound(struct Guru2Game *p)
{
    struct Guru2Spinner *s;
    Guru2MainMsg msg;
    int state,i,rate;
    state=GURU2_MAIN_TickTimeout(p);
    if(state==1 && GURU2_MAIN_GetEntranceEffectActive(p)==0 && p->turnSpeed==0) p->unknown_20=1;
    if(*(u16 *)p->unknown_6A==1) {p->state=28;return 1;}
    if(state==0) {
        if(p->unknown_34 && GURU2_MAIN_GetEntranceEffectActive(p)==0) GURU2_MAIN_StartEntranceEffect(p);
        if(GURU2_MAIN_GetScreenFlashFlag(p)==0 && GURU2_MAIN_IsTouched(p)==1) {
            if(GURU2_MAIN_GetEntranceEffectActive(p)==0) p->unknown_38=1;
            GURU2_MAIN_StartScreenFlash(p);
        }
        if(p->unknown_38) {
            if(GURU2_COMM_Send(p->session->comm,0x2807,&p->unknown_38,1)==1) p->unknown_38=0;
        }
    }
    s=&p->spinner;
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        if(p->frameCounter<300) {
            s->unknown_48+=95;
            if(s->unknown_48>=0x7000) s->unknown_48=0x7000;
        } else {
            s->unknown_48-=95;
            if(s->unknown_48<0x4000) s->unknown_48=0x4000;
        }
    }
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        msg.a=p->spinner.angle;
        msg.flag=p->unknown_20;
        msg.b=*(int *)&p->players[0].unknown_5C[0];
        for(i=0;i<p->playerCount;i++) msg.values[i]=p->players[i].angle/4096;
        GURU2_COMM_Send(p->comm,0x2808,&msg,20);
    }
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        rate=p->spinner.unknown_48;
        if(GURU2_MAIN_GetEntranceEffectState(p)==1) GURU2_MAIN_AddAngle(&p->spinner,rate*2);
        else GURU2_MAIN_RotateAll(p,rate);
    }
    return 0;
}

int GURU2_MAIN_StateRoundEnd(struct Guru2Game *p)
{
    GURU2_MAIN_StartBlendFade(p, 0);
    p->current = GURU2_MAIN_FindNearestPlayerRecord(p);
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        if (p->current->aid == GFL_NET_SYSTEM_GetCurrentAid())
            p->state = 29;
        else
            p->state = 30;
    } else {
        p->state = 31;
    }
    GFL_USE_PlaySeDefaultVolume(1833);
    return 1;
}

int GURU2_MAIN_StateRoundEndChild(struct Guru2Game *p) { GURU2_MAIN_BroadcastResult(p,0x4000); p->current=GURU2_MAIN_FindNearestPlayerRecord(p); if(p->current->aid!=GFL_NET_SYSTEM_GetCurrentAid()) p->state=30; return 0; }

#pragma opt_propagation off

/*
 * note 2026-10-05 (wave P17 L7, final push G6L7): DIFF 26/116, obj/step/target colour
 * rotation and index load order; about 60 forms tried (see git history of the pending copy).
 *
 * pass 2 2026-10-06 P2L39: EXACT in --lang c99 and --lang c. Under #pragma opt_propagation
 * off, all locals declared at the top (target before step), with step assigned before
 * target: this gives obj r6, step r5, target r4. A named table pointer local assigned first
 * keeps the table load live across the multiply (table r4), which lets count be a named
 * local without a copy before muls. The reads in the order index, selected, count, angle
 * give the low colours (angle r1, count r2, index r3).
 */
int GURU2_MAIN_StepAngle(struct Guru2Game *p)
{
    struct Guru2Player *sel;
    int current, index, count;
    int target, step;
    int angle, delta;
    const u16 (*table)[5];
    table = gGuru2PointerAngleTable;
    index = p->seat;
    sel = p->current;
    count = p->playerCount;
    current = sel->angle;
    step = 0x4000;
    target = table[count][index] << 12;
    angle = current;
    delta = target - current;
    if (delta < 0) delta = target + 0x168000 - current;
    if (delta <= 0x10000) step >>= 1;
    if (delta < step) step = delta;
    GURU2_MAIN_BroadcastResult(p, step);
    GURU2_MAIN_AddAngleWrapped(&angle, step);
    if (angle / 4096 == target / 4096) p->state = 31;
    return 0;
}

#pragma opt_propagation reset

int GURU2_MAIN_StateStartSync3(struct Guru2Game *p) { GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),204,40); p->state=32; return 0; }

int GURU2_MAIN_StateWaitSync3(struct Guru2Game *p) { if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),204,40)) { if(GFL_NET_SYSTEM_GetCurrentAid()==0) p->state=33; else p->state=34; } return 0; }

int GURU2_MAIN_SendAngles(struct Guru2Game *p)
{
    struct { u16 angle, mask, entries[6]; } buf;
    int i;
    struct Guru2Player *q;
    buf.angle = p->turnAngle / 4096;
    p->resultMask = 0;
    for (i = 0; i < p->playerCount; i++) {
        q = &p->players[i];
        {
        int angle;
        angle = p->angle[i];
        buf.entries[q->slot] = angle;
        if (GURU2_MAIN_IsAngleInRangeList((char *)p, angle << 12, p->playerCount) == 1)
            p->resultMask |= 1 << q->aid;
        }
    }
    buf.mask = p->resultMask;
    if (GURU2_COMM_Send(p->comm, 10252, &buf, 16) == 1) p->state = 35;
    return 0;
}

int GURU2_MAIN_ApplyAngles(struct Guru2Game *p)
{
    int i;
    struct Guru2Player *entry;
    u16 *values;
    if (p->received == 1) {
        values = p->recvBuf;
        p->spinner.angle = values[0] << 12;
        p->turnAngle = values[0] << 12;
        for (i = 0; i < p->playerCount; i++) {
            entry = &p->players[i];
            entry->angle = values[entry->slot + 2] << 12;
            p->angle[i] = values[entry->slot + 2];
        }
        p->resultMask = values[1];
        GURU2_MAIN_UpdateCenterTransform(p);
        GURU2_MAIN_UpdatePlayerRecords(p);
        p->current = GURU2_MAIN_FindNearestPlayerRecord(p);
        p->state = 35;
    }
    return 0;
}

int GURU2_MAIN_ShowResultNames(struct Guru2Game *p)
{
    int index, i, count, selected;
    index = p->current->slot;
    p->turnSpeed = 0;
    for (i = 0; i < p->playerCount; i++) {
        selected = p->players[index].aid;
        GURU2_MAIN_PrintPlayerName(p, (void *)p->nameBuf[selected], i, selected);
        count = p->playerCount;
        index = (index + 1) % count;
    }
    p->timer = 0;
    p->state = 36;
    return 0;
}

int GURU2_MAIN_StateResultDelay(struct Guru2Game *p)
{
    int i;
    p->timer += 1;
    if (p->timer < 120) return 0;
    p->timer = 0;
    for (i = 0; i < p->playerCount; i++) GURU2_MAIN_ClearNameWindow(p, i);
    GURU2_MAIN_PrintMessageWithName(p, 2, (void *)p->memberEntry[p->current->aid]);
    GURU2_MAIN_PushAndPlayBgm(1302);
    p->state = 37;
    return 0;
}

int GURU2_MAIN_StateWaitSe(struct Guru2Game *p) { if(p->timer<120) p->timer+=1; else if(!GURU2_MAIN_PopBgmWhenDone()) { p->timer=0; p->state=38; } return 0; }

/*
 * lever: Mutable range table is reloaded after RNG; updating low in place preserves r4/r5 colouring.
 */
int GURU2_MAIN_StateComputeReward(struct Guru2Game *p)
{
    u32 low, high, value;
    int count;
    GURU2_MAIN_AddPulseEffectsForMask((const char *)p);
    if ((p->resultMask & (1 << p->current->aid)) == 0) {
        p->state = 42;
        return 0;
    }
    count = p->playerCount;
    low = gGuru2RewardRangeTable[count].low;
    high = gGuru2RewardRangeTable[count].high;
    low += GFL_USE_GetRandom(65535) % (high - low + 1);
    if (low < gGuru2RewardRangeTable[count].low) low = gGuru2RewardRangeTable[count].low;
    else if (low > high) low = high;
    GURU2_MAIN_PrintMessageWithNumber(p, 3, low);
    value = MYITEM_SAVEDATA_AddItem(GAME_DATA_GetMyItem((p->session->param->gameData)), low, 1, 114);
    GURU2_MAIN_PushAndPlayBgm(1302);
    if (value == 1) p->state = 39;
    else p->state = 40;
    return 0;
}

int GURU2_MAIN_StateWaitEffectToEnd(struct Guru2Game *p) { if(p->timer<180) p->timer+=1; if(!GURU2_MAIN_PopBgmWhenDone()) { p->timer=0; p->state=42; } return 0; }

int GURU2_MAIN_StateWaitEffectToMessage(struct Guru2Game *p)
{
    if (p->timer < 180) {
        p->timer += 1;
    } else if (GURU2_MAIN_PopBgmWhenDone() == 0) {
        p->timer = 0;
        p->state = 41;
        GURU2_MAIN_PrintMessage(p, 4);
    }
    return 0;
}

int GURU2_MAIN_StateWaitTimerToEnd(struct Guru2Game *p)
{
    if (p->timer < 180) {
        p->timer += 1;
    } else {
        p->timer = 0;
        p->state = 42;
    }
    return 0;
}

int GURU2_MAIN_StateSaveResult(struct Guru2Game *p) { struct Link *link; link=(struct Link *)GFL_NET_HANDLE_GetCurrentHandle(); RECORD_AddOne((struct RecordBlock *)(*(struct Sub02008C20Obj * *)&p->session->param->playerInfo),90); GURU2_MAIN_PrintMessage(p,11); GFL_NET_HANDLE_SetTimingSyncRange((GFLNetHandle *)link,205,40); p->state=43; UI_SetSoftResetInhibitGlobal(8); return 0; }

int GURU2_MAIN_StateAfterSync4(struct Guru2Game *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 205, 40)) {
        GURU2_MAIN_CopyMemberPokemon(p, p->current->aid);
        p->errScreen = GFL_NET_SAVE_Create(114, (uptr)p->session->param->gameData);
        p->timeIcon = TIME_ICON_Create(p->taskMgr, p->windows.mainWindow, 15, 16, 114);
        p->state = 44;
    }
    return 0;
}

/*
 *   extern void GFL_HEAP_Free(void *);
 *   void GFL_NET_SAVE_Delete(void *p) { GFL_HEAP_Free(p); }
 * tail: 021DF6A2..021DF6A4 is two zero alignment bytes.
 */
int GURU2_MAIN_StateWaitSaveDone(struct Guru2Game *p)
{
    int ready;
    ready = GFL_NET_SAVE_CheckFinished(p->errScreen);
    if (GFL_NET_ERR_GetErrorLevel()) {
        GFL_NET_ERR_WaitLinkClosed();
        GFL_NET_ERR_ShowScreen(1);
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
        return 0;
    }
    if (ready) {
        TIME_ICON_Delete(p->timeIcon);
        p->timeIcon = 0;
        GFL_NET_SAVE_Delete(p->errScreen);
        p->state = 47;
    }
    return 0;
}

int GURU2_MAIN_StateShowEndMessage(struct Guru2Game *p){GURU2_MAIN_PrintMessage(p,12);p->state=46;return 0;}

/*
 * follower: unlabelled timer inside handed 021DF6A4 extent, followed by 2-byte zero padding.
 */
int GURU2_MAIN_StateEndDelay(struct Guru2Game *p){if(++p->timer>=180){p->timer=0;p->state=47;return 1;}return 0;}

int GURU2_MAIN_StateStartSync5(struct Guru2Game *p){void *ctx=GFL_NET_HANDLE_GetCurrentHandle();if(!p->modeFlag)GFL_NET_HANDLE_SetTimingSyncRange(ctx,206,40);GURU2_MAIN_PrintMessage(p,10);p->state=48;return 0;}

int GURU2_MAIN_StateWaitSync5(struct Guru2Game *p)
{
    void *ctx;
    ctx = GFL_NET_HANDLE_GetCurrentHandle();
    if (p->modeFlag == 0) {
        if (GFL_NET_HANDLE_IsTimingSyncRange(ctx, 206, 40)) {
            p->timeIcon = TIME_ICON_Create(p->taskMgr, p->windows.mainWindow, 15, 16, 114);
            GFL_NET_SetLoginOption(0);
            GFL_NET_COMMAND_DeleteCommandTable(10240);
            UNION_APP_RequestReset(GURU2_MAIN_GetUnionApp(p));
            p->state = 49;
        }
    } else {
        p->timer += 1;
        if (p->timer >= 180) {
            p->timer = 0;
            if (p->comm->unknown_3C == 0) GFL_NET_SetAutoExit(0);
            p->state = 49;
        }
    }
    return 0;
}

int GURU2_MAIN_StateWaitUnionAppReset(struct Guru2Game *p){if(UNION_APP_IsResetDone(GURU2_MAIN_GetUnionApp(p))){TIME_ICON_Delete(p->timeIcon);p->timeIcon=0;p->state=50;return 1;}return 0;}

int GURU2_MAIN_StateStartWipeOut(struct Guru2Game *p){WIPE_SYS_Start((void *)2,0,0,0,8,1,114);p->state=51;return 0;}

int GURU2_MAIN_StateWaitWipeOut(struct Guru2Game *p){if(WIPE_SYS_EndCheck()){p->state=52;return 1;}return 0;}

int GURU2_MAIN_StateFinished(void){return 2;}

void GURU2_MAIN_VBlank(void *arg,struct Guru2Game *p){PALANM_TransferPalettes((PaletteFade *)(*(struct S02021D50 * *)&p->palAnm));CLACT_VBlankSystem();BG_SYS_Update();}

void GURU2_MAIN_SetupAll(struct Guru2Game *p){GURU2_MAIN_SetupVram(p);GURU2_MAIN_Setup3dSystem(p);GURU2_MAIN_SetupBg(p);GURU2_MAIN_CreatePaletteAnim(p);GURU2_MAIN_InitActorSystem(p);GURU2_MAIN_LoadBgPalette(p);GURU2_MAIN_CreateWindows(p);GURU2_MAIN_LoadActorResources(p);GURU2_MAIN_ShowPlanes(p);}

void GURU2_MAIN_TeardownAll(struct Guru2Game *p){GURU2_MAIN_HidePlanes(p);GURU2_MAIN_FreeActorResources(p);GURU2_MAIN_DeleteWindows(p);GURU2_MAIN_ExitBg(p);GURU2_MAIN_DeletePaletteAnim(p);GURU2_MAIN_DeleteCamera(p);}

/*
 * omits G3D_CAMERA_SetFar from function: and its shard. tu --suggest-split leaves caller OUT.
 * typedef unsigned int u32;
 * void G3D_CAMERA_SetFar(char *p,const u32 *in) {*(u32 *)(p+0x18)=*in;}
 */
void GURU2_MAIN_Draw3D(struct Guru2Game *p)
{
    u32 flags=0x1000000;
    void *r;
    int i;
    G3D_CAMERA_SetFar(p->light,&flags);
    G3D_SYSTEM_DrawStart();
    G3D_CAMERA_Reset(p->light);
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGlbLightVector(0,0,-4096,0);
    NNS_G3dGlbLightColor(0,0x7fff);
    NNS_G3dGlbMaterialColorDiffAmb(0x7fff,0x7fff,0);
    NNS_G3dGlbMaterialColorSpecEmi(0x7fff,0x7fff,0);
    GURU2_MAIN_DrawBackgroundUnit(p);GURU2_MAIN_DrawCenterUnit(p);GURU2_MAIN_DrawPlayerRecords(p);
    G3D_SYSTEM_DrawEnd();CLACT_DrawSystem();
    PRINTSYS_QUE_Main(p->windows.printQueue);
    r=p->windows.printQueue;
    if(p->windows.printPending) {
        if(!PRINTSYS_QUE_IsExistTarget(r,BMP_WIN_GetBmp(p->windows.activeWindow))) {
            BMP_WIN_TransferChars(p->windows.activeWindow);
            p->windows.printPending=0;
        }
    }
    for(i=0;i<5;i++) {
        r=p->windows.printQueue;
        if(p->windows.slot[i].printed) {
            if(!PRINTSYS_QUE_IsExistTarget(r,BMP_WIN_GetBmp(p->windows.slot[i].window))) {
                BMP_WIN_TransferChars(p->windows.slot[i].window);
                p->windows.slot[i].printed=0;
            }
        }
    }
    if(p->timeIcon) TIME_ICON_Update(p->timeIcon);
}

void GURU2_MAIN_SetupVram(struct Guru2Game *p){BG_SYS_SetVramBanks(&gGuru2GameVramBanks);BMP_WIN_Init(114);}

static inline void G2_SetBG0Priority(int priority)
{
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}

/*
 * volatile: BG0CNT 0x04000008 read at 021DF9F2, written 021DF9FC.
 */
void GURU2_MAIN_ShowPlanes(struct Guru2Game *p)
{
    BG_SYS_SetPlaneVisible(0, 1);
    BG_SYS_SetPlaneVisible(1, 1);
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_SetPlaneVisible(3, 1);
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(5, 0);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_SetPlaneVisible(7, 1);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    G2_SetBG0Priority(1);
    G2x_SetBlendAlpha_((unsigned int *)REG_BLDCNT_ADDR, 4, 40, 11, 10);
}

void GURU2_MAIN_HidePlanes(struct Guru2Game *p)
{
    BG_SYS_SetPlaneVisible(0, 0);
    BG_SYS_SetPlaneVisible(1, 0);
    BG_SYS_SetPlaneVisible(2, 0);
    BG_SYS_SetPlaneVisible(3, 0);
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(5, 0);
    BG_SYS_SetPlaneVisible(6, 0);
    BG_SYS_SetPlaneVisible(7, 0);
    BG_SYS_SetMainPlaneVisible(16, 0);
    BG_SYS_SetSubPlaneVisible(16, 0);
}

static inline void G3X_SetShading(GXShading shading)
{
    DISP3D = (u16)((DISP3D & ~(2 | 0x1000 | 0x2000)) | (shading << 1));
}

static inline void G3X_AntiAlias(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 16);
    else DISP3D &= (u16)~0x3010;
}

static inline void G3X_AlphaTest(int enable, int ref)
{
    if (enable) {
        DISP3D = (u16)((DISP3D & ~0x3000) | 4);
        *(volatile u16 *)0x04000340 = (u16)ref;
    } else DISP3D &= (u16)~0x3004;
}

static inline void G3X_AlphaBlend(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 8);
    else DISP3D &= (u16)~0x3008;
}

static inline void G3X_EdgeMarking(int enable)
{
    if (enable) DISP3D = (u16)((DISP3D & ~0x3000) | 32);
    else DISP3D &= (u16)~0x3020;
}

/*
 * volatile: DISP3DCNT 0x04000060 re-read at 021DFA70,76,82,8A,96; GXSTAT written 021DFABA.
 */
void GURU2_MAIN_Setup3dState(void)
{
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(1);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(1);
    G3X_SetEdgeColorTable((void *)gGuru2ToonTable);
    G3X_SetClearColor(0x7fff, 0, 0x7fff, 63, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
}

void GURU2_MAIN_Setup3dSystem(struct Guru2Game *p)
{
    u8 *section;
    Guru2MainVec3 position;
    section = (u8 *)p + 3392;
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, 114, GURU2_MAIN_Setup3dState);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
    position = gGuru2CameraTarget;
    *(void **)(section + 0x14) = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 4096, 0x400000, 0, (VecFx32 *)&gGuru2CameraEye, (VecFx32 *)&position, (VecFx32 *)&gGuru2CameraUp, 114);
    G3D_CAMERA_Reset(*(void **)(section + 0x14));
}

/*
 * volatile: 021DFB6E reads and 021DFB76 writes hardware register 04000304
 */
void GURU2_MAIN_SetupBg(struct Guru2Game *p)
{
    BG_SYS_Create(114);
    *(volatile u16 *)0x04000304 |= 0x8000;
    {struct DispConfig t=gGuru2GameDispConfig; BG_SYS_SetGraphicsMode((struct DispConfig *)&t);}
    {struct BgTemplate t=gGuru2GameBg1Template; BG_SYS_InitBgLayer(1, (const struct BgTemplate *)&t, 0); BG_SYS_ClearSlot(1); BG_SYS_InitRun(1,32,0,114);}
    {struct BgTemplate t=gGuru2GameBg2Template; BG_SYS_InitBgLayer(2, (const struct BgTemplate *)&t, 0); BG_SYS_ClearSlot(2);}
    {struct BgTemplate t=gGuru2GameBg3Template; BG_SYS_InitBgLayer(3, (const struct BgTemplate *)&t, 0); BG_SYS_ClearSlot(3);}
    {struct BgTemplate t=gGuru2GameBg6Template; BG_SYS_InitBgLayer(6, (const struct BgTemplate *)&t, 0); BG_SYS_ClearSlot(6);}
    {struct BgTemplate t=gGuru2GameBg7Template; BG_SYS_InitBgLayer(7, (const struct BgTemplate *)&t, 0); BG_SYS_ClearSlot(7);}
}

void GURU2_MAIN_LoadBgPalette(struct Guru2Game *p)
{
    void *buf;
    u8 *data;
    buf=GURU2_MAIN_LoadArcMember(p,17,0);
    NNS_G2dGetUnpackedPaletteData(buf,&p->res64);
    PALANM_CopyToSlot(p->palAnm,((struct NNSG2dPaletteData *)p->res64)->pRawData,0,0,64);
    GFL_HEAP_Free(buf);
    buf=GURU2_MAIN_LoadArcMember(p,20,0);
    NNS_G2dGetUnpackedPaletteData(buf,&p->res64);
    PALANM_CopyToSlot(p->palAnm,(const void *)(((struct NNSG2dPaletteData *)p->res64)->pRawData),1,0,64);
    GFL_HEAP_Free((void *)buf);
    PALANM_BlendChannelMask(p->palAnm,1,65535,8,0);
    buf=GURU2_MAIN_LoadArcMember(p,16,0);
    NNS_G2dGetUnpackedCharacterData(buf,&p->res60);
    data=(u8 *)p->res60;
    BG_SYS_LoadTileData(3,*(void **)(data+0x14),*(u32 *)(data+0x10),0);
    GFL_HEAP_Free(buf);
    buf=GURU2_MAIN_LoadArcMember(p,22,0);
    NNS_G2dGetUnpackedCharacterData(buf,&p->res60);
    data=(u8 *)p->res60;
    BG_SYS_LoadTileData(6,*(void **)(data+0x14),*(u32 *)(data+0x10),0);
    GFL_HEAP_Free(buf);
    buf=GURU2_MAIN_LoadArcMember(p,21,0);
    NNS_G2dGetUnpackedCharacterData(buf,&p->res60);
    data=(u8 *)p->res60;
    BG_SYS_LoadTileData(7,*(void **)(data+0x14),*(u32 *)(data+0x10),0);
    GFL_HEAP_Free(buf);
    buf=GURU2_MAIN_LoadArcMember(p,19,0);
    NNS_G2dGetUnpackedScreenData(buf,&p->res5C);
    data=(u8 *)p->res5C;
    BG_SYS_DecodeTile(2,data+12,*(u32 *)(data+8));
    BG_SYS_PushTile(2);
    GFL_HEAP_Free(buf);
    buf=GURU2_MAIN_LoadArcMember(p,18,0);
    NNS_G2dGetUnpackedScreenData(buf,&p->res5C);
    data=(u8 *)p->res5C;
    BG_SYS_DecodeTile(3,data+12,*(u32 *)(data+8));
    BG_SYS_PushTile(3);
    GFL_HEAP_Free(buf);
    buf=GURU2_MAIN_LoadArcMember(p,24,0);
    NNS_G2dGetUnpackedScreenData(buf,&p->res5C);
    data=(u8 *)p->res5C;
    BG_SYS_DecodeTile(6,data+12,*(u32 *)(data+8));
    BG_SYS_PushTile(6);
    GFL_HEAP_Free(buf);
    buf=GURU2_MAIN_LoadArcMember(p,23,0);
    NNS_G2dGetUnpackedScreenData(buf,&p->res5C);
    data=(u8 *)p->res5C;
    BG_SYS_DecodeTile(7,data+12,*(u32 *)(data+8));
    BG_SYS_PushTile(7);
    GFL_HEAP_Free(buf);
}

void GURU2_MAIN_ExitBg(struct Guru2Game *p){BMP_WIN_Exit();BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(3);BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(7);BG_SYS_Delete();}

/*
 * followers: 021DFEA0,021DFEAC,021DFEB8 are pooled tail-call stubs; parent cleared ownership.
 */
void GURU2_MAIN_LoadScreen(struct Guru2Game *p,int file)
{
    void *buf;
    u8 *screen;
    buf=GURU2_MAIN_LoadArcMember(p,file,0);
    NNS_G2dGetUnpackedScreenData(buf,&p->res5C);
    screen=(u8 *)p->res5C;
    BG_SYS_DecodeTile(6,screen+12,*(int *)(screen+8));
    BG_SYS_PushTile(6);
    GFL_HEAP_Free(buf);
}

void GURU2_MAIN_LoadScreen26(struct Guru2Game *p) { GURU2_MAIN_LoadScreen(p,26); }

void GURU2_MAIN_LoadScreen24(struct Guru2Game *p) { GURU2_MAIN_LoadScreen(p,24); }

void GURU2_MAIN_LoadScreen25(struct Guru2Game *p) { GURU2_MAIN_LoadScreen(p,25); }

void GURU2_MAIN_CreatePaletteAnim(struct Guru2Game *p){p->palAnm=PALANM_Create(114);PALANM_SetAutoTransfer(p->palAnm,1);PALANM_AllocSlotBuffers(p->palAnm,0,512,114);PALANM_AllocSlotBuffers(p->palAnm,1,512,114);}

void GURU2_MAIN_DeletePaletteAnim(struct Guru2Game *p){PALANM_FreeSlotBuffers(p->palAnm,0);PALANM_FreeSlotBuffers(p->palAnm,1);PALANM_Delete(p->palAnm);}

void GURU2_MAIN_BlendPalette(struct Guru2Game *p,int level){PALANM_BlendChannelMask(p->palAnm,1,65535,(u8)level,0);}

/*
 * blocking: ABS32 data gClActorInitParam at +0x20 has no witness outside 021DFF44..021DFF70; ROM pool at021DFF64 is020A1448. Alignment-only data a4 hint already used; one recheck and tu --suggest-split remain MATCH with zero witnesses. Both ARM9 callees resolve matched.
 */
void GURU2_MAIN_InitActorSystem(struct Guru2Game *p){CLACT_InitSystem((const struct ClactSysInit *)((struct SysInit *)(&gClActorInitParam)),(const struct DispVramCfg *)((struct DispVramCfg *)0x021E1EA4),114);p->clactUnit=CLACT_CreateUnit(30,1,114);}

void GURU2_MAIN_LoadActorResources(struct Guru2Game *p)
{
    void *arc;
    arc = ARC_TOOL_CreateHandle(184,114);
    p->clactChar = CLACT_RegisterCharacter(arc,6,0,0,114);
    p->clactPal = CLACT_RegisterPalette(arc,0,0,0,114);
    p->clactCell = CLACT_RegisterCellAnim(arc,10,14,114);
    ARC_TOOL_DeleteHandle(arc);
    GFL_NET_RefreshWmIconAtTopRight(1,114);
}

void GURU2_MAIN_FreeActorResources(struct Guru2Game *p){CLACT_ReleaseCharacter(p->clactChar);CLACT_ReleasePalette(p->clactPal);CLACT_ReleaseCellAnim(p->clactCell);CLACT_DeleteUnit(p->clactUnit);CLACT_ExitSystem();}

void GURU2_MAIN_CreateWindows(struct Guru2Game *p)
{
    int i;
    struct Guru2Windows *s=&p->windows;
    BMP_MENUWORK_LoadCharAndPltt(1,1,15,0,114);
    PALANM_LoadArcPaletteToSlot(p->palAnm,5,3,114,0,32,224);
    PALANM_LoadArcPaletteToSlot(p->palAnm,23,5,114,0,32,240);
    s->font=GF_FONT_Create(23,0,0,0,114);
    s->msgData=MSGDATA_CreateFromArchive(0,2,41,114);
    s->wordSet=WORDSET_CreateDefault(114);
    s->mainWindow=(void *)BMP_WIN_Create(1,2,19,26,4,15,1);
    s->textBuf=STRBUF_Create(256,114);
    for(i=0;i<5;i++) {p->nameBuf[i]=STRBUF_Create(8,114);}
    s->activeWindow=s->mainWindow;
    s->printPending=0;
    s->printQueue=(void *)PRINTSYS_QUE_Create((unsigned int)114);
    GURU2_MAIN_CreateNameWindows(p,p->session->playerCount);
}

/*
 * extent: Two zero alignment bytes at 021E012E follow the 90-byte function.
 */
void GURU2_MAIN_DeleteWindows(struct Guru2Game *p)
{
    struct Guru2Windows *s=&p->windows;
    void *obj;
    int i;
    obj=s->mainWindow;
    BMP_WIN_ClearScreen(obj);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(obj));
    BMP_WIN_Delete(s->mainWindow);
    GURU2_MAIN_DeleteNameWindows(p);
    MSGDATA_Delete(s->msgData);
    WORDSET_Delete(s->wordSet);
    GF_FONT_Delete(s->font);
    STRBUF_Delete(s->textBuf);
    for(i=0;i<5;i++) STRBUF_Delete(p->nameBuf[i]);
    BMP_WIN_Exit();
}

void GURU2_MAIN_PrintMessage(struct Guru2Game *p,int message)
{
    struct Guru2Windows *s=&p->windows;
    void *window,*owner,*data;
    window=s->mainWindow;
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    BMP_MENUWORK_DrawWindow(window,2,1,14);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    MSGDATA_ReadString(s->msgData,message,s->textBuf);
    owner=s->printQueue;
    data=BMP_WIN_GetBmp(s->activeWindow);
    PRINTSYS_PrintQueColor(owner,data,0,0,s->textBuf,s->font,1088);
    s->printPending=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
}

void GURU2_MAIN_PrintMessageWithName(struct Guru2Game *p,int message,void *value)
{
    struct Guru2Windows *s=&p->windows;
    void *window,*text,*owner,*data;
    window=s->mainWindow;
    WORDSET_SetSlotMyStatus(s->wordSet,1,UNION_APP_GetMemberEntry(GURU2_MAIN_GetUnionApp(p),(u8)GFL_NET_SYSTEM_GetCurrentAid()));
    WORDSET_SetSlotMyStatus(s->wordSet,2,value);
    text=STRBUF_Create(256,114);
    MSGDATA_ReadString(s->msgData,message,text);
    WORDSET_CopyTaggedText(s->wordSet,s->textBuf,text);
    STRBUF_Delete(text);
    BMP_MENUWORK_DrawWindow(window,2,1,14);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    owner=s->printQueue;
    data=BMP_WIN_GetBmp(s->activeWindow);
    PRINTSYS_PrintQueColor(owner,data,0,0,s->textBuf,s->font,1088);
    s->printPending=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
}

/*
 * extent: Two zero alignment bytes at 021E0302.
 */
void GURU2_MAIN_PrintMessageWithNumber(struct Guru2Game *p,int message,unsigned value)
{
    struct Guru2Windows *s=&p->windows;
    void *window,*text,*owner,*data;
    window=s->mainWindow;
    WORDSET_SetSlotFromMsg36(s->wordSet,0,value);
    text=STRBUF_Create(256,114);
    MSGDATA_ReadString(s->msgData,message,text);
    WORDSET_CopyTaggedText(s->wordSet,s->textBuf,text);
    STRBUF_Delete(text);
    BMP_MENUWORK_DrawWindow(window,2,1,14);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    owner=s->printQueue;
    data=BMP_WIN_GetBmp(s->activeWindow);
    PRINTSYS_PrintQueColor(owner,data,0,0,s->textBuf,s->font,1088);
    s->printPending=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
}

void GURU2_MAIN_ClearMessageWindow(struct Guru2Game *p){struct Guru2ReceiptDescriptor *w=(struct Guru2ReceiptDescriptor *)p->windows.mainWindow;BMP_MENUWORK_DrawWindowBorder((struct BmpWin *)w,0);BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)w),0);BMP_WIN_TransferChars((struct BmpWin *)w);BMP_WIN_MakeScreen((struct BmpWin *)w);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)w));}

/*
 * lever: Store the call result directly into its slot, then reuse that slot; declare counter before section base.
 */
void GURU2_MAIN_CreateNameWindows(struct Guru2Game *p,int count)
{
    int i;
    u8 *s=(u8 *)&p->windows;
    const Guru2MainDesc *table;
    u32 obj;
    u32 *slot;
    const Guru2MainDesc *entry;
    i=0;
    table=gGuru2SlotDescTable[count];
    ((struct Guru2Windows *)s)->count=count;
    for(;i<count;i++) {
        entry=&table[i];
        slot=(u32 *)(s+i*4);
        slot[5]=(uptr)BMP_WIN_Create((u8)entry->layer,entry->a,entry->b,entry->c,entry->d,entry->e,1);
        obj=slot[5];
        *(u32 *)(s+48+i*8)=obj;
        *(u8 *)(s+52+i*8)=0;
    }
}

void GURU2_MAIN_DeleteNameWindows(struct Guru2Game *p){int i;struct Guru2Windows *s=&p->windows;for(i=0;i<s->count;i++){struct Guru2ReceiptDescriptor *w=(struct Guru2ReceiptDescriptor *)s->window[i];BMP_WIN_ClearScreen((struct BmpWin *)w);BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)w));BMP_WIN_Delete((struct BmpWin *)s->window[i]);}}

void GURU2_MAIN_PrintNameWindow(struct Guru2Game *p,void *text,int index,int color)
{
    struct Guru2Windows *s=&p->windows;
    void *window,*owner,*data;
    window=s->window[index];
    BMP_MENUWORK_DrawWindow(window,2,1,14);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    owner=s->printQueue;
    data=BMP_WIN_GetBmp(s->slot[index].window);
    PRINTSYS_PrintQueColor(owner,data,4,1,text,s->font,color);
    s->slot[index].printed=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(window));
}

void GURU2_MAIN_PrintPlayerName(struct Guru2Game *p,void *text,int index,int aid){int color=0x440;if(aid==GFL_NET_SYSTEM_GetCurrentAid())color=0xc80;GURU2_MAIN_PrintNameWindow(p,text,index,color);}

void GURU2_MAIN_ClearNameWindow(struct Guru2Game *p,u32 index){struct Guru2ReceiptDescriptor *w=(struct Guru2ReceiptDescriptor *)p->windows.window[index];BMP_MENUWORK_DrawWindowBorder((struct BmpWin *)w,0);BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)w),0);BMP_WIN_TransferChars((struct BmpWin *)w);BMP_WIN_MakeScreen((struct BmpWin *)w);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)w));}

void GURU2_MAIN_DeleteCamera(struct Guru2Game *p){G3D_CAMERA_Delete((void *)p->light);}

int GURU2_MAIN_IsTouched(struct Guru2Game *p){if(TOUCHPANEL_HitTrg((const TouchHitTable *)gGuru2TouchRects)!=-1)return 1;return 0;}

/*
 * lever: Enum zero preserves its early definition; halfword stores use literal zero to avoid truncation.
 */
void GURU2_MAIN_AddCenterUnit(struct Guru2Game *p)
{
    int index;
    enum { ZERO } zero;
    struct Guru2Spinner *s;
    index=p->session->playerCount;
    s=&p->spinner;
    s->g3dUnit=G3D_UTIL_AddUnit(p->g3dUtil,(const G3dUtilSetup *)&gGuru2PlayerUnitSetupTable[index-2]);
    zero=0;
    s->speedDelta=gGuru2PlayerUnitHeightTable[index];
    s->scale.x=4096;
    s->scale.y=4096;
    s->scale.z=4096;
    s->rotX=0;
    s->rotY=0;
    s->rotZ=0;
    s->angle=zero;
    s->anchor.x=zero;
    s->anchor.y=-147456;
    s->anchor.z=zero;
    s->pos=s->anchor;
}

void GURU2_MAIN_RemoveCenterUnit(struct Guru2Game *p){G3D_UTIL_RemoveUnit(p->g3dUtil,(u16)(p->spinner.g3dUnit));}

void GURU2_MAIN_UpdateCenterTransform(struct Guru2Game *p)
{
    struct Guru2Spinner *s;
    int angle;
    s=&p->spinner;
    angle=p->turnAngle;
    GURU2_MAIN_AddAngleWrapped(&angle,s->speed);
    GURU2_MAIN_AddAngleWrapped(&angle,s->speedDelta);
    s->rotY=(360-angle/4096)%360;
    s->pos.x=s->anchor.x+s->offset.x+s->shakeOffset.x;
    s->pos.y=s->anchor.y+s->offset.y+s->shakeOffset.y;
    s->pos.z=s->anchor.z+s->offset.z+s->shakeOffset.z;
}

static inline void VecSet(Guru2MainVec *v,int x,int y,int z)
{
    v->x=x; v->y=y; v->z=z;
}

void GURU2_MAIN_DrawCenterUnit(struct Guru2Game *p)
{
    Transform t;
    struct Guru2Spinner *s;
    void *object;
    s=&p->spinner;
    object=G3D_UTIL_GetObject(p->g3dUtil,(u16)(s->g3dUnit));
    VecSet(&t.pos,s->pos.x,s->pos.y,s->pos.z);
    VecSet(&t.scale,s->scale.x,s->scale.y,s->scale.z);
    BUTTON_MAN_MakeRotMtxXYZ(s->rotX,(u16)(s->rotY*182),s->rotZ,(MtxFx33 *)&t.rot);
    G3D_SYSTEM_DrawObject(object,(struct G3dObjectStatus *)(&t));
}

void GURU2_MAIN_AddAngle(struct Guru2Spinner *s,int amount){GURU2_MAIN_AddAngleWrapped(&s->angle,amount);}

void GURU2_MAIN_AddBackgroundUnit(struct Guru2Game *p){p->skyUnit=G3D_UTIL_AddUnit(p->g3dUtil,(const G3dUtilSetup *)&gGuru2BackgroundUnitSetup);G3X_SetClearColor(0,0,32767,0,0);}

/*
 * note: original narrows the second call argument with lsls/lsrs #16 at 021E0682/021E0686, so this caller's extern uses u16.
 */
void GURU2_MAIN_RemoveBackgroundUnit(struct Guru2Game *p) { G3D_UTIL_RemoveUnit(p->g3dUtil,(u16)(p->skyUnit)); }

/*
 * lever: Position setter before scale setter keeps zero in r0 and scale in r1.
 */
void GURU2_MAIN_DrawBackgroundUnit(struct Guru2Game *p)
{
    Transform t;
    void *object;
    object = G3D_UTIL_GetObject(p->g3dUtil,(u16)(p->skyUnit));
    VecSet(&t.pos,0,0,0);
    VecSet(&t.scale,4096,4096,4096);
    BUTTON_MAN_MakeRotMtxXYZ(0,0,0,(MtxFx33 *)&t.rot);
    G3D_SYSTEM_DrawObject(object,(struct G3dObjectStatus *)(&t));
}

void GURU2_MAIN_AddPlayerUnits(struct Guru2Game *p)
{
    int i;
    u8 *q=(u8 *)p+0x1a0;
    *(int *)(q+0x938)=G3D_UTIL_AddUnit(p->g3dUtil,(const G3dUtilSetup *)gGuru2MarkerUnitSetupA);
    *(int *)(q+0x93C)=G3D_UTIL_AddUnit(p->g3dUtil,(const G3dUtilSetup *)gGuru2MarkerUnitSetupB);
    for (i=0;i<5;i++) *(int *)(q+0x940+i*4)=G3D_UTIL_AddUnit(p->g3dUtil,(const G3dUtilSetup *)(gGuru2CardUnitSetupTable+i*16));
}

void GURU2_MAIN_RemovePlayerUnits(struct Guru2Game *p)
{
    int i;
    u8 *q = (u8 *)p+0x1a0;
    for (i=0;i<5;i++) G3D_UTIL_RemoveUnit(p->g3dUtil,(u16)(*(int *)(q+0x940+i*4)));
    G3D_UTIL_RemoveUnit(p->g3dUtil,(u16)(*(int *)(q+0x938)));
    G3D_UTIL_RemoveUnit(p->g3dUtil,(u16)(*(int *)(q+0x93C)));
}

void GURU2_MAIN_ActivatePlayerRecord(struct Guru2Game *p,struct Guru2Player *player) { player->visible=1; GURU2_MAIN_ActivatePlayerUnit(p,player); GURU2_MAIN_ActivateCardUnit(p,player); }

void GURU2_MAIN_UpdatePlayerRecords(struct Guru2Game *p)
{
    Count count;
    int i=0;
    PlayerBlock *base;
    count=((struct Guru2Game *)p)->playerCount;
    base=(PlayerBlock *)((char *)p+0x1a0);
    for (;i<count;i++) {
        if (base->a[i].active)
            GURU2_MAIN_UpdateRecordPosition((struct Guru2Player *)&base->a[i],(struct Guru2Vec3 *)((char *)p+0x110),(*(u16 *)((char *)p+0x60+i*2))<<12,p->turnSpeed);
        if (base->b[i].active)
            GURU2_MAIN_InitPlayerUnit(p,(struct Guru2Shadow *)&base->b[i],p->turnSpeed);
        if (base->c[i].active)
            GURU2_MAIN_UpdateCardUnitAnim(p,(struct Guru2Marker *)&base->c[i],i);
    }
}

void GURU2_MAIN_DrawPlayerRecords(struct Guru2Game *p)
{
    int i=0;
    int count=((struct Guru2Game *)p)->playerCount;
    u8 *base=(u8 *)p+0x1a0;
    u8 *first=base+0x140,*second=base+0x4c4,*third=base+0x730;
    for(;i<count;i=i+1) {
        if(((struct Guru2Player *)first)->visible) {
            Transform t;
            void *object=G3D_UTIL_GetObject(((struct Guru2Game *)p)->g3dUtil,(u16)(((struct Guru2UnitIds *)(base+0x938))->shadowUnit));
            VecSet(&t.pos,((struct Guru2Player *)first)->pos.x,((struct Guru2Player *)first)->pos.y,((struct Guru2Player *)first)->pos.z);
            VecSet(&t.scale,((struct Guru2Player *)first)->scale.x,((struct Guru2Player *)first)->scale.y,((struct Guru2Player *)first)->scale.z);
            BUTTON_MAN_MakeRotMtxXYZ(((struct Guru2Player *)first)->rotX,((struct Guru2Player *)first)->rotY,((struct Guru2Player *)first)->rotZ,(MtxFx33 *)&t.rot);
            G3D_SYSTEM_DrawObject(object,(struct G3dObjectStatus *)(&t));
        }
        if(((struct Guru2Shadow *)second)->active) {
            Transform t;
            void *object=G3D_UTIL_GetObject(((struct Guru2Game *)p)->g3dUtil,(u16)(((struct Guru2UnitIds *)(base+0x938))->markerUnit));
            VecSet(&t.pos,((struct Guru2Shadow *)second)->pos.x,((struct Guru2Shadow *)second)->pos.y,((struct Guru2Shadow *)second)->pos.z);
            VecSet(&t.scale,((struct Guru2Shadow *)second)->scale.x,((struct Guru2Shadow *)second)->scale.y,((struct Guru2Shadow *)second)->scale.z);
            BUTTON_MAN_MakeRotMtxXYZ(((struct Guru2Shadow *)second)->rotX,((struct Guru2Shadow *)second)->rotY,((struct Guru2Shadow *)second)->rotZ,(MtxFx33 *)&t.rot);
            G3D_SYSTEM_DrawObject(object,(struct G3dObjectStatus *)(&t));
        }
        if(((struct Guru2Marker *)third)->active) {
            Transform t;
            void *object=G3D_UTIL_GetObject(((struct Guru2Game *)p)->g3dUtil,(u16)(((struct Guru2UnitIds *)(base+0x938))->playerUnit[i]));
            VecSet(&t.pos,((struct Guru2Marker *)third)->pos.x,((struct Guru2Marker *)third)->pos.y,((struct Guru2Marker *)third)->pos.z);
            VecSet(&t.scale,4096,4096,4096);
            MTX_Identity33_((MtxFx33 *)&t.rot);
            G3D_SYSTEM_DrawObject(object,(struct G3dObjectStatus *)(&t));
        }
        first+=0xb4;second+=0x7c;third+=0x68;
    }
}

void GURU2_MAIN_RotatePlayerRecords(struct Guru2Game *p,int amount)
{
    int count = p->playerCount;
    int i = 0;
    char *base = (char *)p+0x1a0;
    for (;i<count;i++) {
        if (*(int *)(base+0x140+i*0xb4))
            GURU2_MAIN_AddAngleWrapped((int *)(base+0x15c+i*0xb4),amount);
    }
}

/*
 * extent: two-byte alignment padding at 0x021E0A42.
 * Verified ARM scratch C: the 0203F63C blocker log EXACT (72 bytes),
 * the 0203F5FC blocker log EXACT (64 bytes). Both use this symbol:
 *   FX_SinCosTable_ 0x020A1B38 data a2
 * typedef unsigned short u16;
 * extern const short FX_SinCosTable_[];
 * int GF_STANDARD_CosFromDegrees(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return FX_SinCosTable_[((angle * 65535 / 360) >> 4) * 2 + 1];
 * }
 * int GF_STANDARD_SinFromDegrees(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return FX_SinCosTable_[((angle * 65535 / 360) >> 4) * 2];
 * }
 */
void GURU2_MAIN_UpdateRecordPosition(struct Guru2Player *p,struct Guru2Vec3 *spinnerOffset,int amount,int extra)
{
    u16 angle;
    GURU2_MAIN_AddAngleWrapped(&amount,p->speed);
    angle=amount/4096;
    p->pos.x=p->basePos.x+spinnerOffset->x+22*GF_STANDARD_CosFromDegrees(angle);
    p->pos.y=extra+(p->basePos.y-0x6000+spinnerOffset->y);
    p->pos.z=p->basePos.z+spinnerOffset->z+22*GF_STANDARD_SinFromDegrees(angle);
    p->rotX=p->rotXFixed/4096;
    p->rotY=p->rotYFixed/4096;
    p->rotZ=p->rotZFixed/4096;
}

/*
 * lever: (pass 2 2026-10-06 P2L40) i zeroed before the angle statement, the row offset
 *   count*10 in a named local as in the twin GURU2_MAIN_StateAnimateSlots, and a separate local for the
 *   insertion-sort value in the third loop.
 * history: wave P12 lane A8 33 of 208 bytes off; final push G7L3 26 (initialised declarations
 *   count, table, base); pass 2 P2L40: early i 13, separate sort-value local 6, named row 0.
 */
void *GURU2_MAIN_FindNearestPlayerRecord(struct Guru2Game *p)
{
    int distance[5],indices[5];
    int angle,i,j,key,value,delta,dist,row;
    long count=p->playerCount;
    const u8 *base=(const u8 *)p+0x1a0;
    i=0;
    row=count*10;
    angle=*(const u16 *)((uptr)gGuru2PointerAngleTable+row+p->seat*2)<<12;
    do {indices[i]=i;distance[i]=65535;i++;} while(i<count);
    for(i=0;i<count;i++) {
        value=*(int *)(base+i*0xb4+0x15c);
        delta=angle-value;
        if(delta<0)delta=angle+0x168000-value;
        distance[i]=delta/4096;
    }
    for(i=1;i<count;i++) {
        key=indices[i];dist=distance[key];
        j=i-1;
        while(j>=0 && distance[indices[j]]>dist) {indices[j+1]=indices[j];j--;}
        indices[j+1]=key;
    }
    return (void *)(base+0x140+indices[0]*0xb4);
}

void GURU2_MAIN_ActivatePlayerUnit(struct Guru2Game *p,struct Guru2Player *player) { struct Guru2Shadow *shadow; shadow=&p->shadows[player->slot]; shadow->active=1; shadow->owner=player; GURU2_MAIN_InitPlayerUnit(p,shadow,0); }

void GURU2_MAIN_InitPlayerUnit(struct Guru2Game *p,struct Guru2Shadow *shadow,int amount)
{
    int n;
    shadow->rotX=0;
    shadow->rotY=0;
    shadow->rotZ=0;
    shadow->pos=shadow->owner->pos;
    shadow->pos.x-=shadow->owner->basePos.x;
    shadow->pos.y-=shadow->owner->basePos.y+amount;
    shadow->pos.z-=shadow->owner->basePos.z;
    shadow->pos.y+=0x2000;
    n=shadow->owner->basePos.y+amount;
    if (n<0) n=-n;
    n/=128;
    if (n>0x800) n=0x800;
    shadow->scale.x=0x1000-n;
    shadow->scale.y=0x1000-n;
    shadow->scale.z=0x1000-n;
}

void GURU2_MAIN_ActivateCardUnit(struct Guru2Game *p, struct Guru2Player *player)
{
    struct Guru2Marker *marker = &p->markers[player->slot];

    marker->active = 1;
    marker->owner = player;
}

void GURU2_MAIN_UpdateCardUnitAnim(struct Guru2Game *p,struct Guru2Marker *marker,int index)
{
    void *object = G3D_UTIL_GetObject(p->g3dUtil,(u16)(p->playerUnit[index]));
    marker->pos = marker->owner->pos;
    marker->pos.y += 0x14000;
    G3D_SYSTEM_LoopObjectAnimeFrame(object,0,0x1000);
}

void GURU2_MAIN_StartDropEffect(struct Guru2Game *p,int aid,int slot,int order,int angle,int speed,int *player)
{
    int *dropEffect;
    player[3]=aid;
    player[4]=slot;
    player[5]=order;
    player[6]=slot;
    player[7]=angle<<12;
    player[8]=speed<<12;
    player[0]=1;
    player[2]=0;
    dropEffect=GFL_HEAP_Alloc(0x8072,24,0,gGuru2MainAllocFileName,0x130e);
    MI_CpuFill8(dropEffect,0,24);
    dropEffect[5]=(sptr)p;
    dropEffect[4]=(sptr)player;
    TCB_AddTask((struct TcbSystem *)p->taskMgr,(TcbFunc)((void (*)(void *, void *))GURU2_MAIN_DropEffectTask),(void *)dropEffect,0);
}

extern int (*const gGuru2DropEffectStateTable[])(char *);

void GURU2_MAIN_DropEffectTask(struct Node *task,char *p) { int result; do { result=gGuru2DropEffectStateTable[*(int *)p](p); } while(result==1); if(result==2) { ((struct Guru2DropEffect *)p)->player->ready=1; GFL_HEAP_Free(p); TCB_DeleteTask((struct TcbTask *)task); } }

int GURU2_MAIN_DropEffectStateInit(struct Guru2DropEffect *p) { struct Guru2Player *player; player=p->player; player->scale.x=4096; player->scale.y=4096; player->scale.z=4096; player->basePos.y=0xc0000; GURU2_MAIN_ActivatePlayerRecord(p->game,player); p->fallSpeed=0x8000; p->state=1; return 0; }

int GURU2_MAIN_DropEffectStateFall(int *p)
{
    int *q = (int *)p[4];
    q[21] -= p[3];
    if (p[2] == 0 && q[21] <= 0x68000) {
        p[2] = 1;
        GFL_USE_PlaySeDefaultVolume(0x725);
    }
    if (q[21] <= 0x20000) {
        q[21] = 0x20000;
        p[0] = 2;
    }
    return 0;
}

/*
 * extent: two-byte alignment padding at 0x021E0D4E.
 */
int GURU2_MAIN_DropEffectStateLand(int *p)
{
    int *q = (int *)p[4];
    char *r;
    if (p[3] > 0x1000) {
        p[3] -= 0x1000;
        if (p[3] < 0x1000) p[3] = 0x1000;
    }
    q[21] -= p[3];
    if (q[21] <= 0) {
        q[21] = 0;
        r = (char *)p[5];
        GURU2_MAIN_PrintPlayerName((struct Guru2Game *)r, *(void **)(r + 0xa4 + q[3]*4), q[5], q[3]);
        return 2;
    }
    return 0;
}

void GURU2_MAIN_UpdateBounceEffect(struct Guru2Game *p,int *effect)
{
    int *player=(int *)effect[7];
    switch(effect[1]) {
    case 0:
        GURU2_MAIN_AddSettleEffect(p,(sptr)player);
        effect[4]=0x4000;
        effect[5]=-1092;
        effect[1]++;
    case 1:
        player[23]+=effect[4];
        effect[4]+=effect[5];
        effect[2]++;
        if(effect[2]>=15) {
            effect[2]=0;
            effect[4]=0;
            if(effect[3]==0) { effect[3]=1; return; }
            player[23]=0;
            GURU2_MAIN_AddWobbleEffect(p,(sptr)player);
            MI_CpuFill8(effect,0,32);
        }
        break;
    }
}

void GURU2_MAIN_BounceEffectTask(void *unused,struct Guru2Game *p) { int i; int *effect; effect=(int *)p->fx0; for(i=0;i<5;i++,effect+=8) if(*effect!=0) GURU2_MAIN_UpdateBounceEffect(p,effect); }

void GURU2_MAIN_CreateBounceEffectTask(struct Guru2Game *p) { MI_CpuFill8((void *)p->fx0,0,160); p->taskFx0=TCB_AddTask((struct TcbSystem *)p->taskMgr, (TcbFunc)((void ( *)(void *,void *))((uptr)GURU2_MAIN_BounceEffectTask)), (void *)p, 256); }

void GURU2_MAIN_DeleteBounceEffectTask(struct Guru2Game *p)
{
    TCB_DeleteTask(p->taskFx0);
}

void GURU2_MAIN_AddBounceEffect(struct Guru2Game *p,int value) { int i; int *q; q=(int *)p->fx0; for(i=0;i<5;i++,q+=8) { if(*q==0) { *q=1; q[7]=value; return; } } }

void GURU2_MAIN_AddBounceEffectsForActivePlayers(struct Guru2Game *p)
{
    Guru2MainRecordBlock *base=(Guru2MainRecordBlock *)((char *)p+0x1a0);
    int count=((struct Guru2Game *)p)->playerCount;
    int i;
    i=0;
    do {
        if (base->records[i].active) GURU2_MAIN_AddBounceEffect(p,(sptr)((char *)&base->records[i]));
        i++;
    } while (i<count);
}

/*
 * extent: unlabelled bool scan follower at 0x021E0E8C, through pool at 0x021E0EA8.
 */
int GURU2_MAIN_IsBounceEffectActive(struct Guru2Game *p)
{
    int i;
    char *q=(char *)p->fx0;
    for (i=0;i<5;i++,q+=0x20) if (*(int *)q) return 1;
    return 0;
}

void GURU2_MAIN_UpdateSettleEffect(int *p)
{
    int *q = (int *)p[4];
    switch (p[1]) {
    case 0:
        p[3] = 0x18000;
        q[12] = 0;
        p[1]++;
    case 1:
        GURU2_MAIN_AddAngleWrapped(q + 12, p[3]);
        if (q[12] < 0x4000) {
            p[3] = (unsigned)p[3] >> 1;
            if (p[3] < 0x4000) {
                q[12] = 0;
                MI_CpuFill8(p, 0, 20);
            }
        }
        break;
    }
}

void GURU2_MAIN_SettleEffectTask(void *unused,struct Guru2Game *p) { int i; int *effect; effect=(int *)p->fx1; for(i=0;i<5;i++,effect+=5) if(*effect!=0) GURU2_MAIN_UpdateSettleEffect(effect); }

void GURU2_MAIN_CreateSettleEffectTask(struct Guru2Game *p) { MI_CpuFill8((void *)p->fx1,0,100); p->taskFx1=TCB_AddTask((struct TcbSystem *)p->taskMgr, (TcbFunc)((void ( *)(void *,void *))((uptr)GURU2_MAIN_SettleEffectTask)), (void *)p, 257); }

void GURU2_MAIN_DeleteSettleEffectTask(struct Guru2Game *p)
{
    TCB_DeleteTask(p->taskFx1);
}

void GURU2_MAIN_AddSettleEffect(struct Guru2Game *p, int key)
{
    int i;
    int *entry;
    int *base = (int *)p->fx1;
    entry = base;
    for (i = 0; i < 5; i++, entry += 5) {
        if (entry[0] == 1 && entry[4] == key) {
            entry[1] = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base += 5) {
        if (base[0] == 0) {
            base[0] = 1;
            base[4] = key;
            return;
        }
    }
}

/*
 *   typedef unsigned short u16;
 *   extern const short FX_SinCosTable_[];
 *   int GF_STANDARD_SinFromDegrees(u16 angle) {
 *       if (angle >= 360) return 0;
 *       return FX_SinCosTable_[((angle * 65535 / 360) >> 4) * 2];
 *   }
 */
void GURU2_MAIN_UpdateWobbleEffect(int *p)
{
    int *q = (int *)p[5];
    int old;
    int amount;
    switch (p[1]) {
    case 0:
        q[13] = 0;
        p[4] = 0;
        p[2] = 0x1e000;
        p[3] = 0x14000;
        p[1]++;
    case 1:
        amount = GF_STANDARD_SinFromDegrees((u16)(p[4] / 4096)) * (p[2] / 4096);
        q[13] = 0;
        GURU2_MAIN_AddAngleWrapped(q + 13, amount);
        old = p[4];
        GURU2_MAIN_AddAngleWrapped(p + 4, p[3]);
        if (p[4] < old) {
            p[2] = (unsigned)p[2] >> 1;
            if (p[2] == 0) {
                q[13] = 0;
                MI_CpuFill8(p, 0, 24);
            }
        }
        break;
    }
}

void GURU2_MAIN_WobbleEffectTask(void *unused,struct Guru2Game *p) { int i; int *effect; effect=(int *)p->fx2; for(i=0;i<5;i++,effect+=6) if(*effect!=0) GURU2_MAIN_UpdateWobbleEffect(effect); }

void GURU2_MAIN_CreateWobbleEffectTask(struct Guru2Game *p) { MI_CpuFill8((void *)p->fx2,0,120); p->taskFx2=TCB_AddTask((struct TcbSystem *)p->taskMgr, (TcbFunc)((void ( *)(void *,void *))((uptr)GURU2_MAIN_WobbleEffectTask)), (void *)p, 258); }

void GURU2_MAIN_DeleteWobbleEffectTask(struct Guru2Game *p)
{
    TCB_DeleteTask(p->taskFx2);
}

void GURU2_MAIN_AddWobbleEffect(struct Guru2Game *p, int key)
{
    int i;
    int *entry;
    int *base = (int *)p->fx2;
    entry = base;
    for (i = 0; i < 5; i++, entry += 6) {
        if (entry[0] == 1 && entry[5] == key) {
            entry[1] = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base += 6) {
        if (base[0] == 0) {
            base[0] = 1;
            base[5] = key;
            return;
        }
    }
}

void GURU2_MAIN_UpdateEntranceEffect(u8 *p,PlayerState *effect)
{
    u8 *spinner=p+0xe0;
    switch(effect->state) {
    case 1:
        effect->speed=0x4000;effect->timer=0;effect->state++;
    case 2:
        ((struct Guru2Spinner *)spinner)->offset.y-=4096;
        if(((struct Guru2Spinner *)spinner)->offset.y<=-32768)effect->state++;
        break;
    case 3:
        ((struct Guru2Spinner *)spinner)->offset.y+=8192;
        if(((struct Guru2Spinner *)spinner)->offset.y>=0) {
            ((struct Guru2Spinner *)spinner)->offset.y=0;
            GURU2_MAIN_AddBounceEffectsForActivePlayers((struct Guru2Game *)p);
            effect->active=1;effect->state++;
            GFL_USE_PlaySeDefaultVolume(0x55e);
        }
        break;
    case 4:
        ((struct Guru2Spinner *)spinner)->shakeOffset.y=effect->speed;
        effect->speed=-effect->speed;
        effect->timer++;
        if(!(effect->timer&3)) {
            if(effect->speed<=4096) {((struct Guru2Spinner *)spinner)->shakeOffset.y=0;effect->state++;}
            else effect->speed>>=1;
        }
        break;
    case 5:
        if(!GURU2_MAIN_IsBounceEffectActive((struct Guru2Game *)p)) {
            effect->other=0;effect->active=0;effect->state=0;
            GFL_USE_PlaySeDefaultVolume(0x76d);
        }
        break;
    case 0:break;
    }
}

void GURU2_MAIN_EntranceEffectTask(void *unused,u8 *p)
{
    GURU2_MAIN_UpdateEntranceEffect(p,(PlayerState *)(p+0xc74));
}

void GURU2_MAIN_CreateEntranceEffectTask(struct Guru2Game *p)
{
    MI_CpuFill8((void *)p->fx3, 0, 20);
    p->taskFx3 = (void *)TCB_AddTask((struct TcbSystem *)p->taskMgr, (TcbFunc)((void ( *)(void *,void *))GURU2_MAIN_EntranceEffectTask), (void *)p, 255);
}

void GURU2_MAIN_DeleteEntranceEffectTask(struct Guru2Game *p)
{
    TCB_DeleteTask(p->taskFx3);
}

void GURU2_MAIN_StartEntranceEffect(struct Guru2Game *p)
{
    int *q = (int *)p->fx3;
    q[2] = 1;
    q[0] = 1;
}

int GURU2_MAIN_GetEntranceEffectState(struct Guru2Game *p)
{
    return p->fx3[1];
}

int GURU2_MAIN_GetEntranceEffectActive(struct Guru2Game *p)
{
    return p->fx3[2];
}

void GURU2_MAIN_CenterActorTask(void *task, int *p)
{
    switch (p[0]) {
    case 0:
        if (p[3] < 4) {
            Table sounds = gGuru2CountSeTable;
            p[1]--;
            if (p[1] <= 0) {
                p[1] = 30;
                GFL_USE_PlaySeDefaultVolume(sounds.v[p[3]]);
                p[3]++;
            }
        }
        CLACT_AddActorAnimFrame((struct ClactActor *)p[5], 0x1800);
        if (CLACT_IsActorAnimActive((struct ClactActor *)p[5]) == 0) p[0]++;
        break;
    case 1:
        CLACT_DeleteActor((struct ClactActor *)p[5]);
        GFL_HEAP_Free(p);
        TCB_DeleteTask(task);
        break;
    }
}

void GURU2_MAIN_CreateCenterActorTask(char *p)
{
    struct { u16 x, y, z; u8 a, b; } pos;
    int *q = GFL_HEAP_Alloc(0x8072, 24, 0, gGuru2MainAllocFileName, 5638);
    MI_CpuFill8(q, 0, 24);
    pos.x = 128;
    pos.y = 100;
    pos.z = 0;
    pos.b = 0;
    pos.a = 0;
    q[5] = (sptr)(struct Guru2ReceiptObj *)CLACT_CreateActor((struct Unit *)((void *)((struct Guru2Game *)p)->clactUnit), ((struct Guru2Game *)p)->clactChar, ((struct Guru2Game *)p)->clactPal, ((struct Guru2Game *)p)->clactCell, (const struct ActorInitParam *)&pos, 0, 114);
    CLACT_AddActorAnimFrame((struct ClactActor *)q[5], 4096);
    q[4] = (sptr)p;
    TCB_AddTask((struct TcbSystem *)(((struct Guru2Game *)p)->taskMgr), (TcbFunc)((void ( *)(void *,void *))GURU2_MAIN_CenterActorTask), (void *)q, 0);
}

void GURU2_MAIN_UpdateScreenFlash(void *task, ModeState *p)
{
    switch (p->state) {
    case 0: break;
    case 1:
        GURU2_MAIN_LoadScreen26(task);
        GFL_USE_PlaySeDefaultVolume(1832);
        p->count = 0;
        p->state++;
    case 2:
        p->count++;
        if (p->count >= 2) {
            p->count = 0;
            p->state++;
            GURU2_MAIN_LoadScreen25(task);
        }
        break;
    case 3:
        p->count++;
        if (p->count >= 4) {
            GURU2_MAIN_LoadScreen26(task);
            p->count = 0;
            p->state++;
        }
        break;
    case 4:
        p->count++;
        if (p->count >= 2) {
            GURU2_MAIN_LoadScreen24(task);
            p->flag = 0;
            p->state = 0;
        }
        break;
    }
}

/*
 * follower: 021E13A8 tail-forwards r1 and r1+0xC88 to this callback.
 */
void GURU2_MAIN_ScreenFlashTask(void *unused, char *p)
{
    GURU2_MAIN_UpdateScreenFlash(p, (ModeState *)(p + 0xc88));
}

void GURU2_MAIN_CreateScreenFlashTask(struct Guru2Game *p)
{
    unsigned n = 8;
    MI_CpuFill8((void *)&p->fx4State, 0, n);
    n += 251;
    p->taskFx4 = (void *)TCB_AddTask((struct TcbSystem *)p->taskMgr, (TcbFunc)((void ( *)(void *,void *))GURU2_MAIN_ScreenFlashTask), (void *)p, n);
}

void GURU2_MAIN_DeleteScreenFlashTask(struct Guru2Game *p)
{
    TCB_DeleteTask(p->taskFx4);
}

u16 GURU2_MAIN_GetScreenFlashFlag(struct Guru2Game *p)
{
    return p->fx4Flag;
}

void GURU2_MAIN_StartScreenFlash(struct Guru2Game *p)
{
    unsigned short *q = &p->fx4State;
    q[1] = 1;
    q[0] = 1;
}

void GURU2_MAIN_UpdatePulseEffect(void *unused, int *p)
{
    switch (p[0]) {
    case 0: break;
    case 1:
        *(int *)(p[3] + 0x54) = gGuru2PulseScaleTable[p[1]] << 12;
        p[1]++;
        if (p[1] >= 16) {
            p[1] = 0;
            p[0]++;
        }
        break;
    case 2:
        p[2]++;
        if (p[2] >= 15) {
            p[2] = 0;
            p[0] = 1;
        }
        break;
    }
}

void GURU2_MAIN_PulseEffectTask(void *unused, char *p)
{
    int i;
    int *q = (int *)(p + 0xc90);
    for (i = 0; i < 5; i++, q += 4) GURU2_MAIN_UpdatePulseEffect(p, q);
}

void GURU2_MAIN_CreatePulseEffectTask(struct Guru2Game *p)
{
    unsigned n = 80;
    MI_CpuFill8((void *)p->fx5, 0, n);
    n += 180;
    p->taskFx5 = (void *)TCB_AddTask((struct TcbSystem *)p->taskMgr, (TcbFunc)((void ( *)(void *,void *))GURU2_MAIN_PulseEffectTask), (void *)p, n);
}

void GURU2_MAIN_DeletePulseEffectTask(struct Guru2Game *p)
{
    TCB_DeleteTask(p->taskFx5);
}

void GURU2_MAIN_AddPulseEffect(char *p, char *player)
{
    char *slot = p + 0xC90 + ((struct Guru2Player *)player)->aid * 0x10;

    ((struct Guru2PulseSlot *)slot)->active = 1;
    *(char * *)&((struct Guru2PulseSlot *)slot)->owner = player;
}

void GURU2_MAIN_AddPulseEffectsForMask(const char *p)
{
  int mask = *((int *) (p + 28));
  const Block *base;
  int i;
  int count;
  i = 0;
  base = (const Block *) (p + 0x1a0);
  count = *((int *) (p + 48));
  for (; i < count; i++)
  {
    if ((base->records[i].active != 0) && (mask & (1 << base->records[i].key)))
      GURU2_MAIN_AddPulseEffect((char *) p, (char *) (&base->records[i]));
  }
}

void GURU2_MAIN_BlendFadeTask(void *task, int *p)
{
    int done = 0;
    if (p[1] == 1) {
        p[2]--;
        if (p[2] <= 0) {
            p[2] = 0;
            done = 1;
        }
    } else {
        p[2]++;
        if (p[2] >= 8) {
            p[2] = 8;
            done = 1;
        }
    }
    GURU2_MAIN_BlendPalette((void *)p[0], p[2]);
    if (done == 1) {
        GFL_HEAP_Free(p);
        TCB_DeleteTask(task);
    }
}

void GURU2_MAIN_StartBlendFade(struct Guru2Game *p, int flag)
{
    IntPair values = gGuru2FadeValues;
    int *q = GFL_HEAP_Alloc(0x8072, 12, 0, gGuru2MainAllocFileName, 5992);
    q[0] = (sptr)p;
    q[1] = flag;
    q[2] = ((int *)&values)[flag];
    TCB_AddTask((struct TcbSystem *)p->taskMgr, (TcbFunc)((void ( *)(void *,void *))GURU2_MAIN_BlendFadeTask), (void *)q, 0);
}

void GURU2_MAIN_AddAngleWrapped(int *angle, int amount)
{
    *angle += amount;
    while (*angle < 0) *angle += 0x168000;
    *angle %= 0x168000;
}

void GURU2_MAIN_RotateAll(struct Guru2Game *p, int amount)
{
    GURU2_MAIN_AddAngle(&p->spinner, amount);
    GURU2_MAIN_RotatePlayerRecords(p, amount);
}

int GURU2_MAIN_TickTimeout(struct Guru2Game *p)
{
    int n = p->frameCounter + 1;

    p->frameCounter = n;
    if (n < 0x258)
        return 0;
    p->frameCounter = 0x258;
    return 1;
}

/*
 * extent: following 021E168C is already matched separately.
 */
void *GURU2_MAIN_LoadArcMember(struct Guru2Game *p, u32 member, int flag)
{
    u32 size = ARC_TOOL_GetHandleMemberSize((struct ArcHandle *)p->arcHandle, member);
    void *result;
    if (flag == 1)
        result = GFL_HEAP_Alloc(114, size, 0, gGuru2MainAllocFileName, 6090);
    else
        result = GFL_HEAP_Alloc(0x8072, size, 0, gGuru2MainAllocFileName, 6092);
    ARC_TOOL_ReadHandleMember((struct ArcHandle *)p->arcHandle, member, result);
    return result;
}

void GURU2_MAIN_SetPlayerInput(struct Guru2Game *p,int input) { if(input!=0) p->unknown_34=input; }

void GURU2_MAIN_StoreRoundResult(struct Guru2Game *p, const Guru2FiveRecord *result)
{
    p->unknown_3C = 1;
    *(Guru2FiveRecord *)&p->turnAngle = *result;
}

char *GURU2_MAIN_ClearSendBuffer(struct Guru2Game *p, int unused)
{
    MI_CpuFill8(&p->seatInit, 0, 32);
    return (char *)&p->seatInit;
}

char *GURU2_MAIN_GetSendBuffer(struct Guru2Game *p)
{
    return (char *)&p->seatInit;
}

int GURU2_MAIN_IsMemberFlagSet(struct Guru2Game *p, int mask)
{
    return (p->comm->statusFlags & mask) != 0;
}

/*
 * Lever: initialise count before bound, then carry bound through a plain copy bound_ after x is loaded.
 * Direct bound use left a four-byte zero/subtraction scheduling swap; bounded permuter found the copy spelling.
 * trailing: Two zero alignment bytes.
 */
int GURU2_MAIN_AreAllOthersReady(const struct Guru2Game *p)
{
  unsigned int count;
  int bound;
  unsigned int x;
  int bound_;
  count = 0;
  bound = p->session->playerCount - 1;
  x = p->comm->ackMask;
  bound_ = bound;
  while (x)
  {
    count += x & 1;
    x >>= 1;
  }

  return ((int) count) >= bound_;
}

/*
 * extent: 30-byte body followed by two bytes of zero alignment padding.
 * lever: Initialize count before loading x; declare count before x.
 * Existing result-before-input and declaration-order idioms cover this.
 */
int GURU2_MAIN_CountReadyMembers(struct Guru2Game *p) { int count; unsigned int x; count=0;x=p->comm->ackMask;while(x) { count+=x&1; x>>=1; }return count; }

/*
 * extent: 42-byte body followed by two bytes of zero alignment padding.
 * volatile: The raw halfword at q+0 is re-read at 021E1732/021E1734.
 */
void GURU2_MAIN_StoreSlotAssignment(struct Guru2Game *p,unsigned short *assignment) { unsigned int index;unsigned short value; index=*(volatile unsigned short *)&((struct Guru2RecvEntry *)assignment)->seat;value=*(volatile unsigned short *)&((struct Guru2RecvEntry *)assignment)->seat;p->recvEntry[index].seat=value;p->recvEntry[index].aid=assignment[1];if(assignment[1]==GFL_NET_SYSTEM_GetCurrentAid())p->seat=assignment[0]; }

void GURU2_MAIN_SyncPlayerCount(struct Guru2Game *p, int unused) { p->playerCount=UNION_APP_GetMemberCount(GURU2_MAIN_GetUnionApp(p)); }

/*
 * The `&` operand order names the temporary: `field & (1 << i)` (field into
 * r2, mask into r0) reproduces the original; `(1 << i) & field` rotates them.
 */
int GURU2_MAIN_IsMemberPresent(struct Guru2Game *p, int member)
{
    if (member != 0 && (p->comm->ackMask & (1 << member)) == 0)
        return 0;
    return 1;
}

void GURU2_MAIN_CopyMemberPokemon(struct Guru2Game *p, int member)
{
    void *party;
    void *other;
    int slot;
    void *ownPokemon;
    void *otherPokemon;
    void *unionApp;
    party = p->party;
    other = GURU2_COMM_GetPartyCopy(p->comm, member);
    slot = p->partySlot[member];
    ownPokemon = POKEPARTY_GetMember(party, p->session->selectedSlot);
    otherPokemon = POKEPARTY_GetMember((struct Party *)other, slot);
    unionApp = GURU2_MAIN_GetUnionApp(p);
    SAVE_EVENT_Write((void *)otherPokemon, (int)6, (const struct MyStatus *)((uptr)UNION_APP_GetMemberEntry((UnionAppWork *)unionApp, (u8)GFL_NET_SYSTEM_GetCurrentAid())), (int)30002, (int)114);
    POKE_TOOL_CopyPartyPokemon(otherPokemon, ownPokemon);
}

int GURU2_MAIN_CountActiveMembers(struct Guru2Game *p)
{
    int count = 0;
    unsigned bits = p->comm->partyReceivedMask;
    while (bits) {
        count += bits & 1;
        bits >>= 1;
    }
    return count;
}

void GURU2_MAIN_SetPlayerSelectedSlot(struct Guru2Game *p,int member,int slot) { p->partySlot[member]=slot; }

void GURU2_MAIN_StoreAngles(struct Guru2Game *p,u16 *src)
{
    u16 *dst=p->recvBuf;
    unsigned count=8;
    do { *dst++=*src++; } while(--count);
    p->received=1;
}

int GURU2_MAIN_IsAngleInRangeList(char *p, int angle, int index)
{
    int shifted;
    unsigned probeLow;
    unsigned count;
    unsigned probeHigh;
    struct RangeU16 *range;
    struct RangeList *list;
    GURU2_MAIN_AddAngleWrapped(&angle, -((struct Guru2Game *)p)->spinner.angle);
    GURU2_MAIN_AddAngleWrapped(&angle, -((struct Guru2Game *)p)->spinner.speedDelta);
    shifted = angle;
    GURU2_MAIN_AddAngleWrapped(&shifted, -0x4000);
    probeLow = shifted / 0x1000;
    shifted = angle;
    GURU2_MAIN_AddAngleWrapped(&shifted, 0x5000);
    probeHigh = shifted / 0x1000;
    list = &gGuru2PlayerAngleRangeLists[index];
    count = list->count;
    range = list->ranges;
    while (count) {
        if ((probeLow >= range->lo && probeLow <= range->hi) || (probeHigh >= range->lo && probeHigh <= range->hi))
            return 1;
        range++;
        count--;
    }
    return 0;
}

int GURU2_MAIN_PartyHasEligiblePokemon(void *p)
{
    int count;
    int i;
    void *pokemon;
    count = POKEPARTY_GetCount(p);
    for (i = 0; i < count; i++) {
        pokemon = POKEPARTY_GetMember(p, i);
        if (POKE_TOOL_GetPartyValue(pokemon, 0x4c, 0) != 0 && POKE_TOOL_GetPartyValue(pokemon, 3, 0) != 0)
            return 1;
    }
    return 0;
}

int GURU2_MAIN_AnyMemberHasEligiblePokemon(struct Guru2Game *p)
{
    int i;
    if (GURU2_MAIN_PartyHasEligiblePokemon(p->party) == 1)
        return 1;
    for (i = 0; i < 5; i++) {
        if (GURU2_MAIN_IsMemberPresent(p, i) != 0 && GURU2_MAIN_PartyHasEligiblePokemon(GURU2_COMM_GetPartyCopy(p->comm, i)) == 1)
            return 1;
    }
    return 0;
}

int GURU2_MAIN_CountContinueVotes(struct Guru2Game *p) { int count; unsigned int x; count=0;x=p->comm->continueMask;while(x) { count+=x&1; x>>=1; }return count; }

int GURU2_MAIN_IsAbortVoted(struct Guru2Game *p)
{
    return p->comm->abortMask != 0;
}

void GURU2_MAIN_PushAndPlayBgm(unsigned int bgmId) { GFL_USE_SetBgmPaused((unsigned int)1);GFL_USE_PushBgm();GFL_USE_CancelChangeAndPlayBgm((unsigned int)bgmId,(unsigned int)65535); }

/*
 * prototype: Legacy 02005E9C source lists four inputs, but its complete
 * body starts with 02005FBC(void) and reads no entry inputs; omitted them.
 */
int GURU2_MAIN_PopBgmWhenDone(void) { if(GFL_USE_IsBgmPlaying()==0) { GFL_USE_PopBgm();GFL_USE_SetBgmPaused(0);return 0; }return 1; }

void GURU2_MAIN_BroadcastResult(struct Guru2Game *p, int amount)
{
    struct {
        int a;
        int b;
        short h[6];
    } buf;
    int i;

    if (GFL_NET_SYSTEM_GetCurrentAid() != 0)
        return;
    GURU2_MAIN_RotateAll(p, amount);
    buf.a = p->spinner.angle;
    buf.b = *(int *)&p->players[0].unknown_5C[0];
    for (i = 0; i < p->playerCount; i++) {
        int v = p->players[i].angle;
        buf.h[i] = (short)(v / 4096);
    }
    GURU2_COMM_Send(p->comm, 0x2808, &buf, 0x14);
}
