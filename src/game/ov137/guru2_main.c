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
 *   func_020315D4 0x020315D4 arm
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
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
 *   func_020490F4 0x020490F4 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045B38 0x02045B38 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_020056A0 0x020056A0 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   UNION_APP_RequestReset 0x02184174 thumb ov022
 *   UNION_APP_IsResetDone 0x0218417C thumb ov022
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_020306F0 0x020306F0 arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
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
 *   func_020409B4 0x020409B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   UNION_APP_GetMemberEntry 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_02008500 0x02008500 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02012934 0x02012934 thumb
 *   G3D_UTIL_Create 0x02047CFC arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   gGuru2SlotAngleTable 0x021E1FA0 data a2
 *   gGuru2MainAllocFileName 0x021E22B8 data a1
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   func_02030DA4 0x02030DA4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_020351A0 0x020351A0 arm
 *   gGuru2MainStateTable 0x021E217C data a4
 *   func_02030D28 0x02030D28 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_SendDataMask 0x0203D4D0 arm
 *   gGuru2PointerAngleTable 0x021E1FDC data a2
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   GURU2_MAIN_BroadcastResult 0x021E19C0 thumb ov137
 *   func_020056EC 0x020056EC thumb
 *   func_0201292C 0x0201292C thumb
 *   func_02007E50 0x02007E50 thumb
 *   gGuru2RewardRangeTable 0x021E1F34 data a4
 *   func_02008DF0 0x02008DF0 thumb
 *   func_0203516C 0x0203516C arm
 *   func_0201088C 0x0201088C thumb
 *   TIME_ICON_Create 0x0202EE30 thumb
 *   func_02010904 0x02010904 thumb
 *   func_0200FBB0 0x0200FBB0 thumb
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   func_02010934 0x02010934 thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_02048B6C 0x02048B6C arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   NNS_G3dGlbLightVector 0x0206AA3C arm
 *   NNS_G3dGlbLightColor 0x0206AA78 arm
 *   NNS_G3dGlbMaterialColorDiffAmb 0x0206AA8C arm
 *   NNS_G3dGlbMaterialColorSpecEmi 0x0206AAB0 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   TIME_ICON_Update 0x0202F0B0 thumb
 *   gGuru2GameVramBanks 0x021E1EA4 data a4
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0207DCF8 0x0207DCF8 arm
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
 *   func_02062A98 0x02062A98 arm
 *   PALANM_CopyToSlot 0x020215BC thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   func_02062A00 0x02062A00 arm
 *   func_02040B1C 0x02040B1C arm
 *   func_02062B30 0x02062B30 arm
 *   func_02040AE0 0x02040AE0 arm
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
 *   func_0201F5BC 0x0201F5BC thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_0201EF40 0x0201EF40 thumb
 *   gGuru2SlotDescTable 0x021E1E30 data a4
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   gGuru2TouchRects 0x021E1CB0 data a4
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   gGuru2PlayerUnitSetupTable 0x021E20EC data a4
 *   gGuru2PlayerUnitHeightTable 0x021E1DE8 data a4
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   func_02048A18 0x02048A18 arm
 *   BUTTON_MAN_MakeRotMtxXYZ 0x020520FC arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   gGuru2BackgroundUnitSetup 0x021E1D80 data a4
 *   gGuru2MarkerUnitSetupA 0x021E1E60 data a4
 *   gGuru2MarkerUnitSetupB 0x021E1E70 data a4
 *   gGuru2CardUnitSetupTable 0x021E212C data a4
 *   func_0207ADC4 0x0207ADC4 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   func_0203F63C 0x0203F63C arm
 *   func_0203F5FC 0x0203F5FC arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   func_02030DA8 0x02030DA8 arm
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
 *   func_0202F190 0x0202F190 thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   gGuru2PlayerAngleRangeLists 0x021E1F04 data a4
 *   func_02017E1C 0x02017E1C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   GURU2_MAIN_RotateAll   0x021E1604  thumb  ov137
 *   MISC_SAVEDATA_InsertRecentValue  0x0200ED54  thumb  arm9
 */
#include "ov137_types.h"
#include "guru2_shared_types.h"
#include "guru2_comm_shared_types.h"
#include "guru2_types.h"
#include "../../matched/include/Obj04542.h"
#include "guru2_receipt_shared_types.h"

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *,int,unsigned);

extern void func_020315D4(struct S020315D4 *);

extern u32 func_020307B0(void *p);

extern void *func_02012934(const struct BigObj *p);

extern void *func_0201292C(const struct BigObj *p);

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

extern int UNION_APP_GetMemberCount(unsigned char *p);

extern u8 UNION_APP_GetJoinedBits(u8 *);

extern void GFL_HEAP_CreateChildHeap(u32 src, u32 dst, u32 size);

extern void *func_020490F4(u32 id, u32 heap);

extern void func_0203F8F4(u16);

extern struct WordSet *func_0201EC64(u32 heap);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);

extern void *func_020056A0(void (*)(int,void *),void *,u32);

extern u32 PRINTSYS_QUE_Create(void *);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void ARC_TOOL_DeleteHandle(void *);

extern u32 WIPE_SYS_EndCheck(void);

extern u32 func_0200FB24(void);

extern void UNION_APP_RequestReset(u8 *p);

extern u32 UNION_APP_IsResetDone(u8 *);

extern void CLACT_DrawSystem(void);

extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned);

extern void PRINTSYS_QUE_Clear(struct PrintSys *);

extern void PRINTSYS_QUE_Delete(struct PrintSys *);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern u32 func_0201ED04(struct WordSet *p);

extern u32 GF_FONT_Delete(void *ptr);

extern void func_02030EAC(struct Node *n);

extern void func_020306F0(u32);

extern void CLACT_VBlankSystem(void);

extern void func_020419E4(void);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void BG_SYS_SetVramBanks(const struct DispVram *);

extern int GURU2_COMM_Send(void *p, u32 a, const void *b, u32 c);

struct Guru2MainCtx3;

struct Guru2MainCtx4;

struct Guru2MainCtx3 {
    int f0;
    int f4;
    unsigned char pad_8[28];
    unsigned short f24;
    unsigned short f26;
    unsigned short f28;
    unsigned char pad_2A[14];
    int f38;
    int f3C;
    int f40;
    int f44;
    int f48;
    int f4C;
    unsigned char pad_50[20];
    void *f64;
};

struct Guru2MainCtx4 {
    unsigned short f0;
    unsigned short f2;
};

#define DISP3D (*(volatile u16 *)0x04000060)

struct Ctx;

struct Big;

struct L0200ED54;

struct Sub02008C20Obj;

struct Sub0201088CObj;

struct S02021D50;

struct Light;

struct NitroFileHeader;

struct PalAnmSlot;

struct Util;

struct Setup;

struct Arg;

struct Mtx33;

struct Actor;

struct ArcFile;

struct RecDC;

typedef struct { u8 pad[0x90]; void *slots[5]; void *other[5]; } SlotObj;

typedef struct {int a,b;u16 values[5];u16 flag;} Msg;

typedef struct {u8 pad[28]; int angle;} Selected;

typedef struct { int state; u8 pad[36]; Selected *selected; int index, count; } SelectObj;

typedef struct { u8 pad[0x60]; u16 angles[5]; } AngleObj;

struct RangeU32 { u32 low, high; };

typedef enum { GX_SHADING_TOON = 0, GX_SHADING_HIGHLIGHT = 1 } GXShading;

typedef short s16_021DEFD0;

typedef struct { u32 x, y, z; } Vec3;

typedef struct { u32 layer; u8 a,b,c,d; u16 e,pad; } Desc;

typedef struct { int x,y,z; } Vec;

typedef struct { int m[9]; } Mtx;

typedef struct { Vec pos,scale; Mtx rot; } Transform;

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

typedef struct { int active; char rest[0xb0]; } PlayerRecord;

typedef struct { char pad[0x140]; PlayerRecord records[1]; } RecordBlock;

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

typedef struct { int a, b, c, d, e; } FiveRecord;

struct RangeU16 { u16 lo, hi; };
struct RangeList { unsigned count; struct RangeU16 *ranges; };

extern void func_0203FC28(struct DispConfig *);

extern void func_0203FCA0(u32,const struct BgTemplate *,u32);

extern void func_020414EC(u32);

extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void func_020403F4(u32);

extern void func_0203F9B4(void);

extern void func_0201F5BC(u32,u32,u32,u32,u16);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);

extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);

extern void CLACT_ReleaseCharacter(u32);

extern void CLACT_ReleasePalette(u32);

extern void CLACT_ReleaseCellAnim(u32);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern struct FrameObj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern void BMP_WIN_Init(u16);

extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void func_020409B4(u32 index);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_WIN_Exit(void);

extern void GFL_NET_SetAutoExit(unsigned char a0);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern void GFL_NET_SetLoginOption(u8 a0);

extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);

extern void func_0201F02C(struct WordSet *p, u32 i, void *a);

extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);


extern void func_02008500(void *,void *);

extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

extern u32 func_02008530(const struct Sub0200852CObj *obj);

extern void func_0201F73C(void *, int, int, int);

extern void func_0201F7A8(void *desc, u32 kind);

extern void *G3D_UTIL_Create(u16,u16,u16);

extern u32 func_02030CB0(u32);

extern void *func_02030734(u32,u32,int,const char *,u16);

extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);

extern void TIME_ICON_Delete(u8 *);

extern void func_02030DA4(void *);

extern void G3D_UTIL_Delete(struct Rec *p);

extern void G3D_SYSTEM_Exit(void);

extern int func_020351A0(u32);

extern void func_02030D28(struct Ctx *c);

extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);

extern u32 GFL_NET_SendDataMask(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

extern void GFL_USE_CancelChangeAndPlayBgm(int, int);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern void *MISC_SAVEDATA_GetBlock44(void *);

extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *l, u32 val);

extern void GURU2_MAIN_BroadcastResult(char *,int);

extern u32 func_020056EC(u32);

extern u32 func_02007E50(u8 *, u16, u16, u16);

extern u32 func_02008DF0(struct Sub02008C20Obj *,int);

extern void func_0203516C(u32);

extern void *func_0201088C(unsigned, unsigned);

extern u32 func_02010904(struct Sub0201088CObj *p);

extern u32 func_0200FBB0(void);

extern u32 GFL_NET_ERR_ShowScreen(u32 a0);

extern void WIPE_SetBrightnessFadeOut(unsigned, unsigned);

extern void func_02010934(struct Sub0201088CObj *p);

extern void PALANM_TransferPalettes(struct S02021D50 *);

extern void func_02048B6C(struct Light *l, const u32 *in);

extern void func_02048AD0(struct Light *l);


extern void NNS_G3dGlbLightVector(int,int,int,int),NNS_G3dGlbLightColor(int,u32),NNS_G3dGlbMaterialColorDiffAmb(u32,u32,u32),NNS_G3dGlbMaterialColorSpecEmi(u32,u32,u32);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void TIME_ICON_Update(u8 *p);

extern void func_0207D63C(unsigned, int, int, int, int);

extern void func_0207DCF8(const u16 *);

extern void G3X_SetClearColor(u16, int, int, int, int);

extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16_021DEFD0 heap, void (*setup)(void));

extern void G3D_SYSTEM_SetSwapBuffersMode(u32, u32);

extern void *G3D_CAMERA_Create(u32, u32, u32, u32, u32, u32, u32, u32, Vec3 *, Vec3 *, Vec3 *, u16);

extern s32 func_02062A98(struct NitroFileHeader *file, void **out);

extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);

extern void PALANM_BlendChannelMask(u32,u32,u16,u32,u32);

extern s32 func_02062A00(struct NitroFileHeader *file, void **out);

extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);

extern int func_02062B30(void *,void **);

extern void func_02040AE0(u32,const void *,u32);

extern void *PALANM_Create(u32);

extern void PALANM_SetAutoTransfer(struct PalAnmSlot *,int);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *,u32,u32,u32);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,u32);

extern void PALANM_Delete(struct PalAnmSlot *);

extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);

extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);

extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void func_02041B6C(u32 bit);

extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);

extern u32 G3D_CAMERA_Delete(void *ptr);

extern int TOUCHPANEL_HitTrg(const void *);

extern int G3D_UTIL_AddUnit(void *,const void *);

extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);

extern u32 func_02048A18(u8 *a0, int i);

extern void BUTTON_MAN_MakeRotMtxXYZ(int,int,int,struct Mtx33 *);

extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

extern void func_0207ADC4(Mtx *);

extern s16 func_0203F63C(u32 x);

extern int func_0203F5FC(u32 x);

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

extern struct Node * func_02030DA8(void *,void (*)(void *,void *),void *,int);

extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);

extern u32 CLACT_IsActorAnimActive(struct Actor *);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *, u32);

extern void ARC_TOOL_ReadHandleMember(struct ArcFile *, u32, void *);

extern void *GURU2_COMM_GetPartyCopy(struct Guru2Comm *p, int i);

extern void *POKEPARTY_GetMember(void *, unsigned);

extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);

extern u32 POKEPARTY_GetCount(void *p);

extern unsigned func_02017E1C(void *, unsigned, unsigned);

extern void GFL_USE_SetBgmPlayerParam(void *);

extern int GFL_USE_PushBgm(void);

extern int GFL_USE_IsBgmPlaying(void);

extern int GFL_USE_PopBgm(void);

int GURU2_MAIN_ProcInit(void *obj,int unused,struct Guru2Session *q);

int GURU2_MAIN_ProcExit(struct S020315D4 *a, int b, int c, struct Guru2Game *p);

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

int GURU2_MAIN_StatePlayRound(char *p);

int GURU2_MAIN_StateRoundEnd(struct Guru2Game *p);

int GURU2_MAIN_StateRoundEndChild(struct Guru2Game *p);

int GURU2_MAIN_StepAngle(SelectObj *obj);

int GURU2_MAIN_StateStartSync3(struct Guru2Game *p);

int GURU2_MAIN_StateWaitSync3(struct Guru2Game *p);

int GURU2_MAIN_SendAngles(AngleObj *obj);

int GURU2_MAIN_ApplyAngles(u8 *p);

int GURU2_MAIN_ShowResultNames(u8 *p);

int GURU2_MAIN_StateResultDelay(u8 *p);

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

void GURU2_MAIN_SetupAll(char *p);

void GURU2_MAIN_TeardownAll(char *p);

void GURU2_MAIN_Draw3D(u8 *p);

void GURU2_MAIN_SetupVram(char *p);

void GURU2_MAIN_ShowPlanes(char *a0);

void GURU2_MAIN_HidePlanes(char *a0);

void GURU2_MAIN_Setup3dState(void);

void GURU2_MAIN_Setup3dSystem(u8 *p);

void GURU2_MAIN_SetupBg(char *a0);

void GURU2_MAIN_LoadBgPalette(char *p);

void GURU2_MAIN_ExitBg(char *p);

void GURU2_MAIN_LoadScreen(u8 *p,int file);

void GURU2_MAIN_LoadScreen26(u8 *p);

void GURU2_MAIN_LoadScreen24(u8 *p);

void GURU2_MAIN_LoadScreen25(u8 *p);

void GURU2_MAIN_CreatePaletteAnim(char *p);

void GURU2_MAIN_DeletePaletteAnim(char *p);

void GURU2_MAIN_BlendPalette(struct Guru2MainCtx2 *p,int a);

void GURU2_MAIN_InitActorSystem(u8 *p);

void GURU2_MAIN_LoadActorResources(u8 *p);

void GURU2_MAIN_FreeActorResources(u8 *p);

void GURU2_MAIN_CreateWindows(u8 *p);

void GURU2_MAIN_DeleteWindows(u8 *p);

void GURU2_MAIN_PrintMessage(u8 *p,int message);

void GURU2_MAIN_PrintMessageWithName(u8 *p,int message,void *value);

void GURU2_MAIN_PrintMessageWithNumber(u8 *p,int message,unsigned value);

void GURU2_MAIN_ClearMessageWindow(u8 *p);

void GURU2_MAIN_CreateNameWindows(u8 *p,int count);

void GURU2_MAIN_DeleteNameWindows(u8 *p);

void GURU2_MAIN_PrintNameWindow(u8 *p,void *text,int index,int color);

void GURU2_MAIN_PrintPlayerName(u8 *p,void *text,int index,int a);

void GURU2_MAIN_ClearNameWindow(u8 *p,u32 i);

void GURU2_MAIN_DeleteCamera(u8 *p);

int GURU2_MAIN_IsTouched(char *a0);

void GURU2_MAIN_AddCenterUnit(u8 *p);

void GURU2_MAIN_RemoveCenterUnit(u8 *p);

void GURU2_MAIN_UpdateCenterTransform(u8 *p);

void GURU2_MAIN_DrawCenterUnit(u8 *p);

void GURU2_MAIN_AddAngle(u8 *p,int a);

void GURU2_MAIN_AddBackgroundUnit(u8 *p);

void GURU2_MAIN_RemoveBackgroundUnit(char *p);

void GURU2_MAIN_DrawBackgroundUnit(u8 *p);

void GURU2_MAIN_AddPlayerUnits(char *p);

void GURU2_MAIN_RemovePlayerUnits(char *p);

void GURU2_MAIN_ActivatePlayerRecord(char *p,char *q);

void GURU2_MAIN_UpdatePlayerRecords(char *p);

void GURU2_MAIN_DrawPlayerRecords(u8 *p);

void GURU2_MAIN_RotatePlayerRecords(char *p,int amount);

void GURU2_MAIN_UpdateRecordPosition(char *p,int *q,int amount,int extra);

void *GURU2_MAIN_FindNearestPlayerRecord(Obj *p);

void GURU2_MAIN_ActivatePlayerUnit(char *p,char *q);

void GURU2_MAIN_InitPlayerUnit(char *p,char *q,int amount);

void GURU2_MAIN_ActivateCardUnit(char *p, char *q);

void GURU2_MAIN_UpdateCardUnitAnim(char *p,char *q,int i);

void GURU2_MAIN_StartDropEffect(char *p,int a,int b,int c,int d,int e,int *q);

void GURU2_MAIN_DropEffectTask(struct Node *task,char *p);

int GURU2_MAIN_DropEffectStateInit(struct Guru2MainCtx *p);

int GURU2_MAIN_DropEffectStateFall(int *p);

int GURU2_MAIN_DropEffectStateLand(int *p);

void GURU2_MAIN_UpdateBounceEffect(char *p,int *q);

void GURU2_MAIN_BounceEffectTask(void *unused,char *p);

void GURU2_MAIN_CreateBounceEffectTask(char *p);

void GURU2_MAIN_DeleteBounceEffectTask(u8 *p);

void GURU2_MAIN_AddBounceEffect(char *p,int value);

void GURU2_MAIN_AddBounceEffectsForActivePlayers(char *p);

int GURU2_MAIN_IsBounceEffectActive(char *p);

void GURU2_MAIN_UpdateSettleEffect(int *p);

void GURU2_MAIN_SettleEffectTask(void *unused,char *p);

void GURU2_MAIN_CreateSettleEffectTask(char *p);

void GURU2_MAIN_DeleteSettleEffectTask(u8 *p);

void GURU2_MAIN_AddSettleEffect(char *p, int key);

void GURU2_MAIN_UpdateWobbleEffect(int *p);

void GURU2_MAIN_WobbleEffectTask(void *unused,char *p);

void GURU2_MAIN_CreateWobbleEffectTask(char *p);

void GURU2_MAIN_DeleteWobbleEffectTask(u8 *p);

void GURU2_MAIN_AddWobbleEffect(char *p, int key);

void GURU2_MAIN_UpdateEntranceEffect(u8 *p,PlayerState *s);

void GURU2_MAIN_EntranceEffectTask(void *unused,u8 *p);

void GURU2_MAIN_CreateEntranceEffectTask(char *p);

void GURU2_MAIN_DeleteEntranceEffectTask(u8 *p);

void GURU2_MAIN_StartEntranceEffect(char *p);

int GURU2_MAIN_GetEntranceEffectState(char *p);

int GURU2_MAIN_GetEntranceEffectActive(char *p);

void GURU2_MAIN_CenterActorTask(void *task, int *p);

void GURU2_MAIN_CreateCenterActorTask(char *p);

void GURU2_MAIN_UpdateScreenFlash(void *task, ModeState *p);

void GURU2_MAIN_ScreenFlashTask(void *unused, char *p);

void GURU2_MAIN_CreateScreenFlashTask(char *p);

void GURU2_MAIN_DeleteScreenFlashTask(u8 *p);

u16 GURU2_MAIN_GetScreenFlashFlag(char *p);

void GURU2_MAIN_StartScreenFlash(char *p);

void GURU2_MAIN_UpdatePulseEffect(void *unused, int *p);

void GURU2_MAIN_PulseEffectTask(void *unused, char *p);

void GURU2_MAIN_CreatePulseEffectTask(char *p);

void GURU2_MAIN_DeletePulseEffectTask(u8 *p);

void GURU2_MAIN_AddPulseEffect(char *p, char *q);

void GURU2_MAIN_AddPulseEffectsForMask(const char *p);

void GURU2_MAIN_BlendFadeTask(void *task, int *p);

void GURU2_MAIN_StartBlendFade(char *p, int flag);

void GURU2_MAIN_AddAngleWrapped(int *p, int v);

extern void GURU2_MAIN_RotateAll(char *, int);

int GURU2_MAIN_TickTimeout(char *p);

void *GURU2_MAIN_LoadArcMember(char *p, u32 member, int flag);

void GURU2_MAIN_SetPlayerInput(int *p,int a);

void GURU2_MAIN_StoreRoundResult(char *p, const FiveRecord *q);

char *GURU2_MAIN_ClearSendBuffer(struct Guru2Game *p, int n);

char *GURU2_MAIN_GetSendBuffer(struct Guru2Game *p);

int GURU2_MAIN_IsMemberFlagSet(struct Guru2Game *p, int mask);

int GURU2_MAIN_AreAllOthersReady(const struct Guru2Game *p);

int GURU2_MAIN_CountReadyMembers(struct Guru2Game *p);

void GURU2_MAIN_StoreSlotAssignment(char *p,unsigned short *q);

void GURU2_MAIN_SyncPlayerCount(char *p, int a1);

int GURU2_MAIN_IsMemberPresent(struct Guru2Game *p, int i);

void GURU2_MAIN_CopyMemberPokemon(struct Guru2Game *p, int i);

int GURU2_MAIN_CountActiveMembers(struct Guru2Game *p);

void GURU2_MAIN_SetPlayerSelectedSlot(int *p,int a,int b);

void GURU2_MAIN_StoreAngles(unsigned char *p,u16 *q);

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

extern const Vec3 gGuru2CameraTarget;

extern const s16_021DEFD0 d_020A1EB8[];

extern Vec3 gGuru2CameraEye, gGuru2CameraUp;

extern const struct DispConfig gGuru2GameDispConfig;

extern const struct BgTemplate gGuru2GameBg1Template,gGuru2GameBg2Template,gGuru2GameBg3Template,gGuru2GameBg6Template,gGuru2GameBg7Template;

extern const Desc *const gGuru2SlotDescTable[];

extern const u8 gGuru2TouchRects[];

extern const Descriptor gGuru2PlayerUnitSetupTable[];

extern const int gGuru2PlayerUnitHeightTable[];

extern const struct Setup gGuru2BackgroundUnitSetup;

extern const char gGuru2MarkerUnitSetupA[],gGuru2MarkerUnitSetupB[],gGuru2CardUnitSetupTable[];

extern const Table gGuru2CountSeTable;

extern const int gGuru2PulseScaleTable[];

extern const IntPair gGuru2FadeValues;

extern struct RangeList gGuru2PlayerAngleRangeLists[];

int GURU2_MAIN_ProcInit(void *obj,int unused,struct Guru2Session *q)
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
    q->gameWork=p;
    p->session=q;
    p->comm=q->comm;
    p->party=func_02012934(p->session->param->gameData);
    p->arcHandle=func_020490F4(183,114);
    GURU2_MAIN_SetupAll((char *)p);
    p->taskMain=func_020056A0((void (*)(int,  void *))GURU2_MAIN_VBlank,p,1);
    p->g3dUtil=G3D_UTIL_Create(20,11,114);
    GURU2_MAIN_AddBackgroundUnit((u8 *)p);GURU2_MAIN_AddPlayerUnits((char *)p);GURU2_MAIN_AddCenterUnit((u8 *)p);
    n=0;
    player=GFL_NET_SYSTEM_GetCurrentAid();
    s=&p->spinner;
    q=p->session;
    for(;i<5;i++) {
        if(q->memberMask&(1<<i)) {if(i==player) break;n++;}
    }
    s->speed=gGuru2SlotAngleTable[q->playerCount][n]<<12;
    r=func_02030734(0x8072,func_02030CB0(32),0,gGuru2MainAllocFileName,0x4ec);
    p->taskCtx=r;
    p->taskMgr=func_02030CBC(32,r);
    GURU2_MAIN_CreateBounceEffectTask((char *)p);GURU2_MAIN_CreateSettleEffectTask((char *)p);GURU2_MAIN_CreateWobbleEffectTask((char *)p);GURU2_MAIN_CreateEntranceEffectTask((char *)p);GURU2_MAIN_CreateScreenFlashTask((char *)p);GURU2_MAIN_CreatePulseEffectTask((char *)p);
    WIPE_SYS_Start(0,1,1,0,8,1,114);
    GFL_NET_SetLoginOption(1);
    return 1;
}

int GURU2_MAIN_ProcExit(struct S020315D4 *a, int b, int c, struct Guru2Game *p)
{
    PRINTSYS_QUE_Clear(p->windows.printQueue);
    PRINTSYS_QUE_Delete(p->windows.printQueue);
    if (p->timeIcon != 0) TIME_ICON_Delete(p->timeIcon);
    GURU2_MAIN_DeleteBounceEffectTask((u8 *)p);
    GURU2_MAIN_DeleteSettleEffectTask((u8 *)p);
    GURU2_MAIN_DeleteWobbleEffectTask((u8 *)p);
    GURU2_MAIN_DeleteEntranceEffectTask((u8 *)p);
    GURU2_MAIN_DeleteScreenFlashTask((u8 *)p);
    GURU2_MAIN_DeletePulseEffectTask((u8 *)p);
    func_02030DA4(p->taskMgr);
    func_020307B0(p->taskCtx);
    GURU2_MAIN_RemoveBackgroundUnit((char *)p);
    GURU2_MAIN_RemoveCenterUnit((u8 *)p);
    GURU2_MAIN_RemovePlayerUnits((char *)p);
    G3D_UTIL_Delete(p->g3dUtil);
    G3D_SYSTEM_Exit();
    GURU2_MAIN_TeardownAll((char *)p);
    func_02030EAC(p->taskMain);
    ARC_TOOL_DeleteHandle(p->arcHandle);
    func_020315D4(a);
    func_020306F0(0x72);
    func_020351A0(8);
    return 1;
}

extern int (*const gGuru2MainStateTable[])(void *);

int GURU2_MAIN_ProcMain(int a, int b, int c, struct Guru2Game *p)
{
    int result;
    do { result = gGuru2MainStateTable[p->state](p); } while (result == 1);
    if (result == 2) return 1;
    GURU2_MAIN_UpdateCenterTransform((u8 *)p);
    GURU2_MAIN_UpdatePlayerRecords((char *)p);
    GURU2_MAIN_Draw3D((u8 *)p);
    GURU2_MAIN_ClearTransferFlags(p);
    func_02030D28(p->taskMgr);
    if (WIPE_SYS_EndCheck() && func_0200FB24()) return 1;
    return 0;
}

void GURU2_MAIN_ClearTransferFlags(struct Guru2Game *p) { p->unknown_34=0;p->unknown_3C=0; }

int GURU2_MAIN_StateStart(struct Guru2Game *p)
{
    GURU2_MAIN_PrintMessage((u8 *)p, 0);
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

int GURU2_MAIN_StateWaitSync1(struct Guru2Game *p) {if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),202,40))p->state=12;return 0;}

int GURU2_MAIN_StateSendSelectedSlot(struct Guru2Game *p) {if(GURU2_COMM_Send(p->comm,0x280B,(char *)p->session+4,4))p->state=13;return 0;}

int GURU2_MAIN_StateBroadcastPlayerData(struct Guru2Game *p)
{
    void *q;
    q = GFL_NET_HANDLE_GetCurrentHandle();
    if ((int)GFL_NET_SendDataMask((u32)q, (u8)((int)UNION_APP_GetJoinedBits(GURU2_MAIN_GetUnionApp(p))), (int)10255, (int)1428, (u32)(p->party), (int)1, (int)1, (int)1))
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
            func_02008500(p->memberEntry[i], p->nameBuf[i]);
        }
    }
    GURU2_MAIN_RegisterPlayerRecords(p);
    p->spinner.speed = slot->seatAngle << 12;
    p->state = 17;
    GFL_USE_CancelChangeAndPlayBgm(1157, 65535);
    p->session->param->resultFlag = 1;
    GURU2_MAIN_ClearMessageWindow((u8 *)p);
    return 1;
}

/*
 * extent: unlabelled follower at 021DEED8, filed separately.
 * lever: raw unsigned byte-table address and a named row byte offset restore r6.
 */
int GURU2_MAIN_StateAnimateSlots(char *p)
{
    int *r;
    int value, a, row;
    if (--((struct Guru2MainCtx *)p)->fC>0) return 0;
    ((struct Guru2MainCtx *)p)->fC=15;
    r=(int *)GURU2_MAIN_GetSendBuffer((struct Guru2Game *)p);
    row=r[5]*10;
    value=*(const u16 *)((unsigned)gGuru2PointerAngleTable+row+r[4]*2);
    a=*(u16 *)(p+0x7e + r[4]*4);
    *(u16 *)(p+0x60+r[4]*2)=value;
    GURU2_MAIN_StartDropEffect(p,a,r[4],r[0],value,r[1],(int *)(p+0x2e0+r[4]*0xb4));
    r[4]++;
    r[4]%=r[5];
    if (++r[0]==r[5]) {
        ((struct Guru2MainCtx *)p)->fC=0;
        ((struct Guru2MainCtx *)p)->f0=18;
    }
    return 0;
}

int GURU2_MAIN_StateWaitAllSlotsReady(char *p)
{
    char *q=p+0x1a0;
    int i,n,count;
    count=((struct Guru2MainCtx *)p)->f30;
    i=0;
    n=0;
    do {
        if (*(int *)(q+i*0xb4+0x148)==1) n++;
        i++;
    } while(i<count);
    if (n==count) {((struct Guru2MainCtx *)p)->f0=19;return 1;}
    return 0;
}

int GURU2_MAIN_StateDelayRole(struct Guru2Game *p) {if(++p->timer>30){p->timer=0;if(GFL_NET_SYSTEM_GetCurrentAid()==0)p->state=20;else p->state=21;}return 0;}

int GURU2_MAIN_StateSendRoleChild(struct Guru2Game *p) { u16 buf; buf=4; if(GURU2_COMM_Send(p->comm,0x2805,&buf,2)==1) p->state=22; return 0; }

void GURU2_MAIN_RegisterPlayerRecords(struct Guru2Game *obj)
{
    void *q;
    int i;
    q = MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(obj->session->param->gameData));
    for (i = 0; i < 5; i++) {
        if (obj->memberEntry[i] && i != GFL_NET_SYSTEM_GetCurrentAid())
            MISC_SAVEDATA_InsertRecentValue(q, func_02008530(obj->memberEntry[i]));
    }
}

/*
 * trailing: Two zero alignment bytes.
 */
int GURU2_MAIN_StateWaitRoleMessage(struct Guru2Game *p) { if(GURU2_MAIN_IsMemberFlagSet(p,4)==1) { p->state=22; return 1; } return 0; }

int GURU2_MAIN_StateStartSync2(struct Guru2Game *p) { GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),203,40); p->state=23; return 0; }

int GURU2_MAIN_StateWaitSync2(struct Guru2Game *p) { if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),203,40)) p->state=24; return 0; }

int GURU2_MAIN_StateShowRound(struct Guru2Game *p) { GURU2_MAIN_StartBlendFade((char *)p,1); GURU2_MAIN_CreateCenterActorTask((char *)p); p->state=25; return 0; }

int GURU2_MAIN_StateRoundDelay(struct Guru2Game *p) { int i; p->timer+=1; if(p->timer<95) return 0; for(i=0;i<p->playerCount;i++) GURU2_MAIN_ClearNameWindow((u8 *)p,i); p->timer=0; p->state=26; return 0; }

int GURU2_MAIN_StateToPlay(struct Guru2Game *p)
{
    GFL_NET_SYSTEM_GetCurrentAid();
    p->state = 0x1b;
    return 0;
}

int GURU2_MAIN_StatePlayRound(char *p)
{
    char *s;
    Msg msg;
    int state,i,rate;
    state=GURU2_MAIN_TickTimeout(p);
    if(state==1 && GURU2_MAIN_GetEntranceEffectActive(p)==0 && ((struct Guru2MainCtx2 *)p)->f5C==0) ((struct Guru2MainCtx2 *)p)->f20=1;
    if(((struct Guru2MainCtx2 *)p)->f6A==1) {*(int *)&((struct Guru2MainCtx2 *)p)->f0=28;return 1;}
    if(state==0) {
        if(((struct Guru2MainCtx2 *)p)->f34 && GURU2_MAIN_GetEntranceEffectActive(p)==0) GURU2_MAIN_StartEntranceEffect(p);
        if(GURU2_MAIN_GetScreenFlashFlag(p)==0 && GURU2_MAIN_IsTouched(p)==1) {
            if(GURU2_MAIN_GetEntranceEffectActive(p)==0) *(int *)&((struct Guru2MainCtx2 *)p)->f38=1;
            GURU2_MAIN_StartScreenFlash(p);
        }
        if(*(int *)&((struct Guru2MainCtx2 *)p)->f38) {
            if(GURU2_COMM_Send(((struct Guru2MainCtx2_fD8 *)((struct Guru2MainCtx2 *)p)->fD8)->f18,0x2807,p+0x38,1)==1) *(int *)&((struct Guru2MainCtx2 *)p)->f38=0;
        }
    }
    s=p+0xe0;
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        if(((struct Guru2MainCtx2 *)p)->f8<300) {
            ((struct Guru2MainCtx *)s)->f48+=95;
            if(((struct Guru2MainCtx *)s)->f48>=0x7000) ((struct Guru2MainCtx *)s)->f48=0x7000;
        } else {
            ((struct Guru2MainCtx *)s)->f48-=95;
            if(((struct Guru2MainCtx *)s)->f48<0x4000) ((struct Guru2MainCtx *)s)->f48=0x4000;
        }
    }
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        msg.a=((struct Guru2MainCtx2 *)p)->f11C;
        msg.flag=((struct Guru2MainCtx2 *)p)->f20;
        msg.b=((struct Guru2MainCtx2 *)p)->f33C;
        for(i=0;i<*(int *)&((struct Guru2MainCtx2 *)p)->f30;i++) msg.values[i]=*(int *)(p+i*0xb4+0x2fc)/4096;
        GURU2_COMM_Send(((struct Guru2MainCtx2 *)p)->fDC,0x2808,&msg,20);
    }
    if(GFL_NET_SYSTEM_GetCurrentAid()==0) {
        rate=((struct Guru2MainCtx2 *)p)->f128;
        if(GURU2_MAIN_GetEntranceEffectState(p)==1) GURU2_MAIN_AddAngle((u8 *)(p+0xe0),rate*2);
        else GURU2_MAIN_RotateAll(p,rate);
    }
    return 0;
}

int GURU2_MAIN_StateRoundEnd(struct Guru2Game *p)
{
    GURU2_MAIN_StartBlendFade((char *)p, 0);
    p->current = GURU2_MAIN_FindNearestPlayerRecord((Obj *)p);
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

int GURU2_MAIN_StateRoundEndChild(struct Guru2Game *p) { GURU2_MAIN_BroadcastResult((char *)p,0x4000); p->current=GURU2_MAIN_FindNearestPlayerRecord((Obj *)p); if(p->current->aid!=GFL_NET_SYSTEM_GetCurrentAid()) p->state=30; return 0; }

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
int GURU2_MAIN_StepAngle(SelectObj *obj)
{
    Selected *sel;
    int current, index, count;
    int target, step;
    int angle, delta;
    const u16 (*table)[5];
    table = gGuru2PointerAngleTable;
    index = obj->index;
    sel = obj->selected;
    count = obj->count;
    current = sel->angle;
    step = 0x4000;
    target = table[count][index] << 12;
    angle = current;
    delta = target - current;
    if (delta < 0) delta = target + 0x168000 - current;
    if (delta <= 0x10000) step >>= 1;
    if (delta < step) step = delta;
    GURU2_MAIN_BroadcastResult((char *)obj, step);
    GURU2_MAIN_AddAngleWrapped(&angle, step);
    if (angle / 4096 == target / 4096) obj->state = 31;
    return 0;
}

#pragma opt_propagation reset

int GURU2_MAIN_StateStartSync3(struct Guru2Game *p) { GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),204,40); p->state=32; return 0; }

int GURU2_MAIN_StateWaitSync3(struct Guru2Game *p) { if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),204,40)) { if(GFL_NET_SYSTEM_GetCurrentAid()==0) p->state=33; else p->state=34; } return 0; }

int GURU2_MAIN_SendAngles(AngleObj *obj)
{
    u8 *p = (u8 *)obj;
    struct { u16 angle, mask, entries[6]; } buf;
    int i;
    u8 *q;
    buf.angle = *(int *)&((struct Guru2MainCtx *)p)->f58 / 4096;
    ((struct Guru2MainCtx *)p)->f1C = 0;
    for (i = 0; i < ((struct Guru2MainCtx *)p)->f30; i++) {
        q = p + 0x2e0 + i * 180;
        {
        int angle;
        angle = obj->angles[i];
        buf.entries[*(int *)&((struct Guru2MainCtx *)q)->f10] = angle;
        if (GURU2_MAIN_IsAngleInRangeList((char *)p, angle << 12, ((struct Guru2MainCtx *)p)->f30) == 1)
            ((struct Guru2MainCtx *)p)->f1C |= 1 << ((struct Guru2MainCtx *)q)->fC;
        }
    }
    buf.mask = ((struct Guru2MainCtx *)p)->f1C;
    if (GURU2_COMM_Send(((struct Guru2MainCtx *)p)->fDC, 10252, &buf, 16) == 1) ((struct Guru2MainCtx *)p)->f0 = 35;
    return 0;
}

int GURU2_MAIN_ApplyAngles(u8 *p)
{
    int i;
    u8 *entry;
    u16 *values;
    if (((struct Guru2MainCtx *)p)->f40 == 1) {
        values = (u16 *)(p + 108);
        ((struct Guru2MainCtx *)p)->f11C = values[0] << 12;
        *(int *)&((struct Guru2MainCtx *)p)->f58 = values[0] << 12;
        for (i = 0; i < ((struct Guru2MainCtx *)p)->f30; i++) {
            entry = p + 736 + i * 180;
            ((struct Guru2MainCtx *)entry)->f1C = values[*(int *)&((struct Guru2MainCtx *)entry)->f10 + 2] << 12;
            *(u16 *)(p + 96 + i * 2) = values[*(int *)&((struct Guru2MainCtx *)entry)->f10 + 2];
        }
        ((struct Guru2MainCtx *)p)->f1C = values[1];
        GURU2_MAIN_UpdateCenterTransform(p);
        GURU2_MAIN_UpdatePlayerRecords((char *)p);
        *(u8 * *)&((struct Guru2MainCtx *)p)->f28 = GURU2_MAIN_FindNearestPlayerRecord((Obj *)p);
        ((struct Guru2MainCtx *)p)->f0 = 35;
    }
    return 0;
}

int GURU2_MAIN_ShowResultNames(u8 *p)
{
    int index, i, count, selected;
    index = (*(int * *)&((struct Guru2MainCtx *)p)->f28)[4];
    *(int *)&((struct Guru2MainCtx *)p)->f5C = 0;
    for (i = 0; i < ((struct Guru2MainCtx *)p)->f30; i++) {
        selected = *(int *)(p + 748 + index * 180);
        GURU2_MAIN_PrintPlayerName(p, (void *)(*(int *)(p + 164 + selected * 4)), i, selected);
        count = ((struct Guru2MainCtx *)p)->f30;
        index = (index + 1) % count;
    }
    ((struct Guru2MainCtx *)p)->fC = 0;
    ((struct Guru2MainCtx *)p)->f0 = 36;
    return 0;
}

int GURU2_MAIN_StateResultDelay(u8 *p)
{
    int i;
    ((struct Guru2MainCtx *)p)->fC += 1;
    if (((struct Guru2MainCtx *)p)->fC < 120) return 0;
    ((struct Guru2MainCtx *)p)->fC = 0;
    for (i = 0; i < ((struct Guru2MainCtx *)p)->f30; i++) GURU2_MAIN_ClearNameWindow(p, i);
    GURU2_MAIN_PrintMessageWithName(p, 2, (void *)(*(int *)(p + 144 + 4 * (*(int * *)&((struct Guru2MainCtx *)p)->f28)[3])));
    GURU2_MAIN_PushAndPlayBgm(1302);
    ((struct Guru2MainCtx *)p)->f0 = 37;
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
    low += func_020056EC(65535) % (high - low + 1);
    if (low < gGuru2RewardRangeTable[count].low) low = gGuru2RewardRangeTable[count].low;
    else if (low > high) low = high;
    GURU2_MAIN_PrintMessageWithNumber((u8 *)p, 3, low);
    value = func_02007E50(func_0201292C((p->session->param->gameData)), low, 1, 114);
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
        GURU2_MAIN_PrintMessage((u8 *)p, 4);
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

int GURU2_MAIN_StateSaveResult(struct Guru2Game *p) { struct Link *link; link=(struct Link *)GFL_NET_HANDLE_GetCurrentHandle(); func_02008DF0(*(struct Sub02008C20Obj * *)&p->session->param->playerInfo,90); GURU2_MAIN_PrintMessage((u8 *)p,11); GFL_NET_HANDLE_SetTimingSyncRange(link,205,40); p->state=43; func_0203516C(8); return 0; }

int GURU2_MAIN_StateAfterSync4(struct Guru2Game *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 205, 40)) {
        GURU2_MAIN_CopyMemberPokemon(p, p->current->aid);
        p->errScreen = func_0201088C(114, (unsigned)p->session->param->gameData);
        p->timeIcon = TIME_ICON_Create(p->taskMgr, p->windows.mainWindow, 15, 16, 114);
        p->state = 44;
    }
    return 0;
}

/*
 *   extern void func_020307B0(void *);
 *   void func_02010934(void *p) { func_020307B0(p); }
 * tail: 021DF6A2..021DF6A4 is two zero alignment bytes.
 */
int GURU2_MAIN_StateWaitSaveDone(struct Guru2Game *p)
{
    int ready;
    ready = func_02010904(p->errScreen);
    if (func_0200FB24()) {
        func_0200FBB0();
        GFL_NET_ERR_ShowScreen(1);
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
        return 0;
    }
    if (ready) {
        TIME_ICON_Delete(p->timeIcon);
        p->timeIcon = 0;
        func_02010934(p->errScreen);
        p->state = 47;
    }
    return 0;
}

int GURU2_MAIN_StateShowEndMessage(struct Guru2Game *p){GURU2_MAIN_PrintMessage((u8 *)p,12);p->state=46;return 0;}

/*
 * follower: unlabelled timer inside handed 021DF6A4 extent, followed by 2-byte zero padding.
 */
int GURU2_MAIN_StateEndDelay(struct Guru2Game *p){if(++p->timer>=180){p->timer=0;p->state=47;return 1;}return 0;}

int GURU2_MAIN_StateStartSync5(struct Guru2Game *p){void *ctx=GFL_NET_HANDLE_GetCurrentHandle();if(!p->modeFlag)GFL_NET_HANDLE_SetTimingSyncRange(ctx,206,40);GURU2_MAIN_PrintMessage((u8 *)p,10);p->state=48;return 0;}

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

void GURU2_MAIN_VBlank(void *arg,struct Guru2Game *p){PALANM_TransferPalettes(*(struct S02021D50 * *)&p->palAnm);CLACT_VBlankSystem();func_020419E4();}

void GURU2_MAIN_SetupAll(char *p){GURU2_MAIN_SetupVram(p);GURU2_MAIN_Setup3dSystem((u8 *)p);GURU2_MAIN_SetupBg(p);GURU2_MAIN_CreatePaletteAnim(p);GURU2_MAIN_InitActorSystem((u8 *)p);GURU2_MAIN_LoadBgPalette(p);GURU2_MAIN_CreateWindows((u8 *)p);GURU2_MAIN_LoadActorResources((u8 *)p);GURU2_MAIN_ShowPlanes(p);}

void GURU2_MAIN_TeardownAll(char *p){GURU2_MAIN_HidePlanes(p);GURU2_MAIN_FreeActorResources((u8 *)p);GURU2_MAIN_DeleteWindows((u8 *)p);GURU2_MAIN_ExitBg(p);GURU2_MAIN_DeletePaletteAnim(p);GURU2_MAIN_DeleteCamera((u8 *)p);}

/*
 * omits func_02048B6C from function: and its shard. tu --suggest-split leaves caller OUT.
 * typedef unsigned int u32;
 * void func_02048B6C(char *p,const u32 *in) {*(u32 *)(p+0x18)=*in;}
 */
void GURU2_MAIN_Draw3D(u8 *p)
{
    u32 flags=0x1000000;
    void *r;
    int i;
    func_02048B6C(*(void **)(p+0xd54),&flags);
    func_02047964();
    func_02048AD0(*(void **)(p+0xd54));
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGlbLightVector(0,0,-4096,0);
    NNS_G3dGlbLightColor(0,0x7fff);
    NNS_G3dGlbMaterialColorDiffAmb(0x7fff,0x7fff,0);
    NNS_G3dGlbMaterialColorSpecEmi(0x7fff,0x7fff,0);
    GURU2_MAIN_DrawBackgroundUnit(p);GURU2_MAIN_DrawCenterUnit(p);GURU2_MAIN_DrawPlayerRecords(p);
    G3D_SYSTEM_DrawEnd();CLACT_DrawSystem();
    PRINTSYS_QUE_Main(*(void **)(p+0xd38));
    r=*(void **)(p+0xd38);
    if(*(u8 *)(p+0xd0c)) {
        if(!PRINTSYS_QUE_IsExistTarget(r,BMP_WIN_GetBmp(*(void **)(p+0xd08)))) {
            BMP_WIN_TransferChars(*(void **)(p+0xd08));
            *(u8 *)(p+0xd0c)=0;
        }
    }
    for(i=0;i<5;i++) {
        r=*(void **)(p+0xd38);
        if(*(u8 *)(p+i*8+0xd14)) {
            if(!PRINTSYS_QUE_IsExistTarget(r,BMP_WIN_GetBmp(*(void **)(p+i*8+0xd10)))) {
                BMP_WIN_TransferChars(*(void **)(p+i*8+0xd10));
                *(u8 *)(p+i*8+0xd14)=0;
            }
        }
    }
    if(*(void **)(p+0xda8)) TIME_ICON_Update(*(void **)(p+0xda8));
}

void GURU2_MAIN_SetupVram(char *p){BG_SYS_SetVramBanks(&gGuru2GameVramBanks);BMP_WIN_Init(114);}

static inline void G2_SetBG0Priority(int priority)
{
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}

/*
 * volatile: BG0CNT 0x04000008 read at 021DF9F2, written 021DF9FC.
 */
void GURU2_MAIN_ShowPlanes(char *a0)
{
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 1);
    func_02040588(7, 1);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    G2_SetBG0Priority(1);
    func_0207D63C(0x04000050, 4, 40, 11, 10);
}

void GURU2_MAIN_HidePlanes(char *a0)
{
    func_02040588(0, 0);
    func_02040588(1, 0);
    func_02040588(2, 0);
    func_02040588(3, 0);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
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
    func_0207DCF8(gGuru2ToonTable);
    G3X_SetClearColor(0x7fff, 0, 0x7fff, 63, 0);
    *(volatile u32 *)0x04000580 = 0xbfff0000;
}

void GURU2_MAIN_Setup3dSystem(u8 *p)
{
    u8 *section;
    Vec3 position;
    section = p + 3392;
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, 114, GURU2_MAIN_Setup3dState);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
    position = gGuru2CameraTarget;
    *(void * *)&((struct Guru2MainCtx *)section)->f14 = G3D_CAMERA_Create(0, d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0, 4096, 0x400000, 0, &gGuru2CameraEye, &position, &gGuru2CameraUp, 114);
    func_02048AD0(*(void * *)&((struct Guru2MainCtx *)section)->f14);
}

/*
 * volatile: 021DFB6E reads and 021DFB76 writes hardware register 04000304
 */
void GURU2_MAIN_SetupBg(char *a0)
{
    func_0203F8F4(114);
    *(volatile u16 *)0x04000304 |= 0x8000;
    {struct DispConfig t=gGuru2GameDispConfig; func_0203FC28((struct DispConfig *)&t);}
    {struct BgTemplate t=gGuru2GameBg1Template; func_0203FCA0(1, (const struct BgTemplate *)&t, 0); func_020414EC(1); func_02040B94(1,32,0,114);}
    {struct BgTemplate t=gGuru2GameBg2Template; func_0203FCA0(2, (const struct BgTemplate *)&t, 0); func_020414EC(2);}
    {struct BgTemplate t=gGuru2GameBg3Template; func_0203FCA0(3, (const struct BgTemplate *)&t, 0); func_020414EC(3);}
    {struct BgTemplate t=gGuru2GameBg6Template; func_0203FCA0(6, (const struct BgTemplate *)&t, 0); func_020414EC(6);}
    {struct BgTemplate t=gGuru2GameBg7Template; func_0203FCA0(7, (const struct BgTemplate *)&t, 0); func_020414EC(7);}
}

void GURU2_MAIN_LoadBgPalette(char *p)
{
    void *buf;
    u8 *data;
    buf=GURU2_MAIN_LoadArcMember(p,17,0);
    func_02062A98(buf,(void **)(p+0xd64));
    PALANM_CopyToSlot(((struct Guru2MainCtx *)p)->fD78,((struct Guru2MainCtx_fD64 *)((struct Guru2MainCtx *)p)->fD64)->fC,0,0,64);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,20,0);
    func_02062A98(buf,(void **)(p+0xd64));
    PALANM_CopyToSlot(((struct Guru2MainCtx *)p)->fD78,((struct Guru2MainCtx_fD64 *)((struct Guru2MainCtx *)p)->fD64)->fC,1,0,64);
    func_020307B0(buf);
    PALANM_BlendChannelMask(*(u32 *)&((struct Guru2MainCtx *)p)->fD78,1,65535,8,0);
    buf=GURU2_MAIN_LoadArcMember(p,16,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD60;
    func_02040B1C(3,*(void * *)&((struct Guru2MainCtx *)data)->f14,*(unsigned int *)&((struct Guru2MainCtx *)data)->f10,0);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,22,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD60;
    func_02040B1C(6,*(void * *)&((struct Guru2MainCtx *)data)->f14,*(unsigned int *)&((struct Guru2MainCtx *)data)->f10,0);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,21,0);
    func_02062A00(buf,(void **)(p+0xd60));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD60;
    func_02040B1C(7,*(void * *)&((struct Guru2MainCtx *)data)->f14,*(unsigned int *)&((struct Guru2MainCtx *)data)->f10,0);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,19,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD5C;
    func_02040AE0(2,data+12,*(unsigned int *)&((struct Guru2MainCtx *)data)->f8);
    func_020409B4(2);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,18,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD5C;
    func_02040AE0(3,data+12,*(unsigned int *)&((struct Guru2MainCtx *)data)->f8);
    func_020409B4(3);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,24,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD5C;
    func_02040AE0(6,data+12,*(unsigned int *)&((struct Guru2MainCtx *)data)->f8);
    func_020409B4(6);
    func_020307B0(buf);
    buf=GURU2_MAIN_LoadArcMember(p,23,0);
    func_02062B30(buf,(void **)(p+0xd5c));
    data=*(u8 * *)&((struct Guru2MainCtx *)p)->fD5C;
    func_02040AE0(7,data+12,*(unsigned int *)&((struct Guru2MainCtx *)data)->f8);
    func_020409B4(7);
    func_020307B0(buf);
}

void GURU2_MAIN_ExitBg(char *p){BMP_WIN_Exit();func_020403F4(1);func_020403F4(2);func_020403F4(3);func_020403F4(6);func_020403F4(7);func_0203F9B4();}

/*
 * followers: 021DFEA0,021DFEAC,021DFEB8 are pooled tail-call stubs; parent cleared ownership.
 */
void GURU2_MAIN_LoadScreen(u8 *p,int file)
{
    void *buf;
    u8 *screen;
    buf=GURU2_MAIN_LoadArcMember((char *)p,file,0);
    func_02062B30(buf,(void **)(p+3420));
    screen=*(u8 * *)&((struct Guru2MainCtx *)p)->fD5C;
    func_02040AE0(6,screen+12,((struct Guru2MainCtx2 *)screen)->f8);
    func_020409B4(6);
    func_020307B0(buf);
}

void GURU2_MAIN_LoadScreen26(u8 *p) { GURU2_MAIN_LoadScreen(p,26); }

void GURU2_MAIN_LoadScreen24(u8 *p) { GURU2_MAIN_LoadScreen(p,24); }

void GURU2_MAIN_LoadScreen25(u8 *p) { GURU2_MAIN_LoadScreen(p,25); }

void GURU2_MAIN_CreatePaletteAnim(char *p){*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78=PALANM_Create(114);PALANM_SetAutoTransfer(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78,1);PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78,0,512,114);PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78,1,512,114);}

void GURU2_MAIN_DeletePaletteAnim(char *p){PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78,0);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78,1);PALANM_Delete(*(struct PalAnmSlot * *)&((struct Guru2MainCtx *)p)->fD78);}

void GURU2_MAIN_BlendPalette(struct Guru2MainCtx2 *p,int a){PALANM_BlendChannelMask(p->fD78,1,65535,(u8)a,0);}

/*
 * blocking: ABS32 data gClActorInitParam at +0x20 has no witness outside 021DFF44..021DFF70; ROM pool at021DFF64 is020A1448. Alignment-only data a4 hint already used; one recheck and tu --suggest-split remain MATCH with zero witnesses. Both ARM9 callees resolve matched.
 */
void GURU2_MAIN_InitActorSystem(u8 *p){CLACT_InitSystem(&gClActorInitParam,0x021E1EA4,114);*(struct Bank **)(p+0xd68)=CLACT_CreateUnit(30,1,114);}

void GURU2_MAIN_LoadActorResources(u8 *p)
{
    void *arc;
    arc = func_020490F4(184,114);
    *(int *)&((struct Guru2MainCtx *)p)->fD6C = CLACT_RegisterCharacter(arc,6,0,0,114);
    *(int *)&((struct Guru2MainCtx *)p)->fD70 = CLACT_RegisterPalette(arc,0,0,0,114);
    *(int *)&((struct Guru2MainCtx *)p)->fD74 = CLACT_RegisterCellAnim(arc,10,14,114);
    ARC_TOOL_DeleteHandle(arc);
    GFL_NET_RestartWithDefaultTimeout(1,114);
}

void GURU2_MAIN_FreeActorResources(u8 *p){CLACT_ReleaseCharacter(((struct Guru2MainCtx *)p)->fD6C);CLACT_ReleasePalette(((struct Guru2MainCtx *)p)->fD70);CLACT_ReleaseCellAnim(((struct Guru2MainCtx *)p)->fD74);CLACT_DeleteUnit(*(struct Bank * *)&((struct Guru2MainCtx *)p)->fD68);CLACT_ExitSystem();}

void GURU2_MAIN_CreateWindows(u8 *p)
{
    int i;
    u8 *s=p+0xce0;
    func_0201F5BC(1,1,15,0,114);
    PALANM_LoadArcPaletteToSlot(((struct Guru2MainCtx *)p)->fD78,5,3,114,0,32,224);
    PALANM_LoadArcPaletteToSlot(((struct Guru2MainCtx *)p)->fD78,23,5,114,0,32,240);
    ((struct Guru2MainCtx *)s)->f4=GF_FONT_Create(23,0,0,0,114);
    ((struct Guru2MainCtx *)s)->f8=func_02045B38(0,2,41,114);
    *(void * *)&((struct Guru2MainCtx *)s)->fC=func_0201EC64(114);
    *(unsigned int *)&((struct Guru2MainCtx *)s)->f10=BMP_WIN_Create(1,2,19,26,4,15,1);
    ((struct Guru2MainCtx *)s)->f5C=STRBUF_Create(256,114);
    for(i=0;i<5;i++) {*(void **)(p+0xa4+i*4)=STRBUF_Create(8,114);}
    *(unsigned int *)&((struct Guru2MainCtx *)s)->f28=*(unsigned int *)&((struct Guru2MainCtx *)s)->f10;
    *(unsigned char *)&((struct Guru2MainCtx *)s)->f2C=0;
    *(unsigned int *)&((struct Guru2MainCtx *)s)->f58=PRINTSYS_QUE_Create((void *)114);
    GURU2_MAIN_CreateNameWindows(p,((struct Guru2Session *)((struct Guru2MainCtx *)p)->fD8)->playerCount);
}

/*
 * extent: Two zero alignment bytes at 021E012E follow the 90-byte function.
 */
void GURU2_MAIN_DeleteWindows(u8 *p)
{
    u8 *s;
    void *obj;
    int i;
    s=p+3296;
    obj=((struct Guru2MainCtx *)s)->f10;
    BMP_WIN_ClearScreen(obj);
    func_020409B4(BMP_WIN_GetBgLayer(obj));
    BMP_WIN_Delete(((struct Guru2MainCtx *)s)->f10);
    GURU2_MAIN_DeleteNameWindows(p);
    MSGDATA_Delete(((struct Guru2MainCtx *)s)->f8);
    func_0201ED04(*(void * *)&((struct Guru2MainCtx *)s)->fC);
    GF_FONT_Delete(((struct Guru2MainCtx *)s)->f4);
    STRBUF_Delete(((struct Guru2MainCtx *)s)->f5C);
    for(i=0;i<5;i++) STRBUF_Delete(*(void **)(p+164+i*4));
    BMP_WIN_Exit();
}

void GURU2_MAIN_PrintMessage(u8 *p,int message)
{
    u8 *s;
    void *window,*owner,*data;
    s=p+3296;
    window=((struct Guru2MainCtx *)s)->f10;
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    func_0201F73C(window,2,1,14);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    func_02045CAC(((struct Guru2MainCtx *)s)->f8,message,((struct Guru2MainCtx *)s)->f5C);
    owner=((struct Guru2MainCtx *)s)->f58;
    data=BMP_WIN_GetBmp(((struct Guru2MainCtx *)s)->f28);
    PRINTSYS_PrintQueColor(owner,(u32)data,0,0,(u32)(((struct Guru2MainCtx *)s)->f5C),(u32)(((struct Guru2MainCtx *)s)->f4),1088);
    *(unsigned char *)&((struct Guru2MainCtx *)s)->f2C=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
}

void GURU2_MAIN_PrintMessageWithName(u8 *p,int message,void *value)
{
    u8 *s;
    void *window,*text,*owner,*data;
    s=p+3296;
    window=((struct Guru2MainCtx *)s)->f10;
    func_0201F02C(*(void * *)&((struct Guru2MainCtx *)s)->fC,1,UNION_APP_GetMemberEntry(GURU2_MAIN_GetUnionApp((struct Guru2Game *)p),(u8)GFL_NET_SYSTEM_GetCurrentAid()));
    func_0201F02C(*(void * *)&((struct Guru2MainCtx *)s)->fC,2,value);
    text=STRBUF_Create(256,114);
    func_02045CAC(((struct Guru2MainCtx *)s)->f8,message,text);
    func_0201F250(*(void * *)&((struct Guru2MainCtx *)s)->fC,((struct Guru2MainCtx *)s)->f5C,text);
    STRBUF_Delete(text);
    func_0201F73C(window,2,1,14);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    owner=((struct Guru2MainCtx *)s)->f58;
    data=BMP_WIN_GetBmp(((struct Guru2MainCtx *)s)->f28);
    PRINTSYS_PrintQueColor(owner,(u32)data,0,0,(u32)(((struct Guru2MainCtx *)s)->f5C),(u32)(((struct Guru2MainCtx *)s)->f4),1088);
    *(unsigned char *)&((struct Guru2MainCtx *)s)->f2C=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
}

/*
 * extent: Two zero alignment bytes at 021E0302.
 */
void GURU2_MAIN_PrintMessageWithNumber(u8 *p,int message,unsigned value)
{
    u8 *s;
    void *window,*text,*owner,*data;
    s=p+3296;
    window=((struct Guru2MainCtx *)s)->f10;
    func_0201EF40(*(void * *)&((struct Guru2MainCtx *)s)->fC,0,value);
    text=STRBUF_Create(256,114);
    func_02045CAC(((struct Guru2MainCtx *)s)->f8,message,text);
    func_0201F250(*(void * *)&((struct Guru2MainCtx *)s)->fC,((struct Guru2MainCtx *)s)->f5C,text);
    STRBUF_Delete(text);
    func_0201F73C(window,2,1,14);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    owner=((struct Guru2MainCtx *)s)->f58;
    data=BMP_WIN_GetBmp(((struct Guru2MainCtx *)s)->f28);
    PRINTSYS_PrintQueColor(owner,(u32)data,0,0,(u32)(((struct Guru2MainCtx *)s)->f5C),(u32)(((struct Guru2MainCtx *)s)->f4),1088);
    *(unsigned char *)&((struct Guru2MainCtx *)s)->f2C=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
}

void GURU2_MAIN_ClearMessageWindow(u8 *p){struct Descriptor *w=*(struct Descriptor * *)&((struct Guru2MainCtx *)p)->fCF0;func_0201F7A8(w,0);BMP_Clear(BMP_WIN_GetBmp(w),0);BMP_WIN_TransferChars(w);BMP_WIN_MakeScreen((struct Cfg *)w);func_02041B6C(BMP_WIN_GetBgLayer(w));}

/*
 * lever: Store the call result directly into its slot, then reuse that slot; declare counter before section base.
 */
void GURU2_MAIN_CreateNameWindows(u8 *p,int count)
{
    int i;
    u8 *s;
    const Desc *table;
    u32 obj;
    u32 *slot;
    const Desc *entry;
    s=p+3296;
    i=0;
    table=gGuru2SlotDescTable[count];
    ((struct Guru2MainCtx3 *)s)->f0=count;
    for(;i<count;i++) {
        entry=&table[i];
        slot=(u32 *)(s+i*4);
        slot[5]=BMP_WIN_Create((u8)entry->layer,entry->a,entry->b,entry->c,entry->d,entry->e,1);
        obj=slot[5];
        *(u32 *)(s+48+i*8)=obj;
        *(u8 *)(s+52+i*8)=0;
    }
}

void GURU2_MAIN_DeleteNameWindows(u8 *p){int i;u8 *s=p+0xce0;for(i=0;i<((struct Guru2MainCtx3 *)s)->f0;i++){u8 *q=s+(u32)i*4;struct Descriptor *w=*(struct Descriptor * *)&((struct Guru2MainCtx *)q)->f14;BMP_WIN_ClearScreen(w);func_020409B4(BMP_WIN_GetBgLayer(w));BMP_WIN_Delete(*(struct Descriptor * *)&((struct Guru2MainCtx *)q)->f14);}}

void GURU2_MAIN_PrintNameWindow(u8 *p,void *text,int index,int color)
{
    u8 *s;
    void *window,*owner,*data;
    s=p+3296;
    window=*(void **)(s+20+index*4);
    func_0201F73C(window,2,1,14);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    owner=((struct Guru2MainCtx *)s)->f58;
    data=BMP_WIN_GetBmp(*(void **)(s+48+index*8));
    PRINTSYS_PrintQueColor(owner,(u32)data,4,1,(u32)text,(u32)(((struct Guru2MainCtx *)s)->f4),color);
    *(u8 *)(s+52+index*8)=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
}

void GURU2_MAIN_PrintPlayerName(u8 *p,void *text,int index,int a){int c=0x440;if(a==GFL_NET_SYSTEM_GetCurrentAid())c=0xc80;GURU2_MAIN_PrintNameWindow(p,text,index,c);}

void GURU2_MAIN_ClearNameWindow(u8 *p,u32 i){struct Descriptor *w=*(struct Descriptor **)(p+i*4+0xcf4);func_0201F7A8(w,0);BMP_Clear(BMP_WIN_GetBmp(w),0);BMP_WIN_TransferChars(w);BMP_WIN_MakeScreen((struct Cfg *)w);func_02041B6C(BMP_WIN_GetBgLayer(w));}

void GURU2_MAIN_DeleteCamera(u8 *p){G3D_CAMERA_Delete(((struct Guru2MainCtx *)p)->fD54);}

int GURU2_MAIN_IsTouched(char *a0){if(TOUCHPANEL_HitTrg(gGuru2TouchRects)!=-1)return 1;return 0;}

/*
 * lever: Enum zero preserves its early definition; halfword stores use literal zero to avoid truncation.
 */
void GURU2_MAIN_AddCenterUnit(u8 *p)
{
    int index;
    enum { ZERO } zero;
    u8 *s;
    index=((struct Guru2Session *)((struct Guru2MainCtx *)p)->fD8)->playerCount;
    s=p+224;
    ((struct Guru2MainCtx *)s)->fBC=G3D_UTIL_AddUnit(((struct Guru2MainCtx *)p)->fAF4,&gGuru2PlayerUnitSetupTable[index-2]);
    zero=0;
    ((struct Guru2MainCtx *)s)->f44=gGuru2PlayerUnitHeightTable[index];
    ((struct Guru2MainCtx *)s)->f18=4096;
    ((struct Guru2MainCtx *)s)->f1C=4096;
    *(int *)&((struct Guru2MainCtx *)s)->f20=4096;
    ((struct Guru2MainCtx *)s)->f4C=0;
    *(unsigned short *)&((struct Guru2MainCtx *)s)->f4E=0;
    ((struct Guru2MainCtx *)s)->f50=0;
    *(int *)&((struct Guru2MainCtx *)s)->f3C=zero;
    ((struct Guru2MainCtx *)p)->fE0=zero;
    *(int *)&((struct Guru2MainCtx *)s)->f4=-147456;
    *(int *)&((struct Guru2MainCtx *)s)->f8=zero;
    *(Vec *)(s+12)=*(Vec *)s;
}

void GURU2_MAIN_RemoveCenterUnit(u8 *p){G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)p)->f19C));}

void GURU2_MAIN_UpdateCenterTransform(u8 *p)
{
    u8 *s;
    int angle;
    s=p+224;
    angle=*(int *)&((struct Guru2MainCtx *)p)->f58;
    GURU2_MAIN_AddAngleWrapped(&angle,((struct Guru2MainCtx *)s)->f40);
    GURU2_MAIN_AddAngleWrapped(&angle,((struct Guru2MainCtx *)s)->f44);
    ((struct Guru2MainCtx *)s)->f4E=(360-angle/4096)%360;
    ((struct Guru2MainCtx *)s)->fC=((struct Guru2MainCtx *)p)->fE0+((struct Guru2MainCtx *)s)->f30+*(int *)&((struct Guru2MainCtx *)s)->f24;
    *(int *)&((struct Guru2MainCtx *)s)->f10=*(int *)&((struct Guru2MainCtx *)s)->f4+((struct Guru2MainCtx *)s)->f34+*(int *)&((struct Guru2MainCtx *)s)->f28;
    ((struct Guru2MainCtx *)s)->f14=*(int *)&((struct Guru2MainCtx *)s)->f8+*(int *)&((struct Guru2MainCtx *)s)->f38+*(int *)&((struct Guru2MainCtx *)s)->f2C;
}

static inline void VecSet(Vec *v,int x,int y,int z)
{
    v->x=x; v->y=y; v->z=z;
}

void GURU2_MAIN_DrawCenterUnit(u8 *p)
{
    Transform t;
    u8 *s;
    void *object;
    s=p+224;
    object=(void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)s)->fBC));
    VecSet(&t.pos,((struct Guru2MainCtx *)s)->fC,*(int *)&((struct Guru2MainCtx *)s)->f10,((struct Guru2MainCtx *)s)->f14);
    VecSet(&t.scale,((struct Guru2MainCtx *)s)->f18,((struct Guru2MainCtx *)s)->f1C,*(int *)&((struct Guru2MainCtx *)s)->f20);
    BUTTON_MAN_MakeRotMtxXYZ(((struct Guru2MainCtx *)s)->f4C,(u16)(((struct Guru2MainCtx *)s)->f4E*182),((struct Guru2MainCtx *)s)->f50,(struct Mtx33 *)&t.rot);
    G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
}

void GURU2_MAIN_AddAngle(u8 *p,int a){GURU2_MAIN_AddAngleWrapped((int *)(p+0x3c),a);}

void GURU2_MAIN_AddBackgroundUnit(u8 *p){((struct Guru2MainCtx *)p)->fDA4=G3D_UTIL_AddUnit(*(struct Util * *)&((struct Guru2MainCtx *)p)->fAF4,&gGuru2BackgroundUnitSetup);G3X_SetClearColor(0,0,32767,0,0);}

/*
 * note: original narrows the second call argument with lsls/lsrs #16 at 021E0682/021E0686, so this caller's extern uses u16.
 */
void GURU2_MAIN_RemoveBackgroundUnit(char *p) { G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)p)->fDA4)); }

/*
 * lever: Position setter before scale setter keeps zero in r0 and scale in r1.
 */
void GURU2_MAIN_DrawBackgroundUnit(u8 *p)
{
    Transform t;
    void *object;
    object = (void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(*(int *)&((struct Guru2MainCtx *)p)->fDA4));
    VecSet(&t.pos,0,0,0);
    VecSet(&t.scale,4096,4096,4096);
    BUTTON_MAN_MakeRotMtxXYZ(0,0,0,(struct Mtx33 *)&t.rot);
    G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
}

void GURU2_MAIN_AddPlayerUnits(char *p)
{
    int i;
    char *q=p+0x1a0;
    ((struct Guru2MainCtx *)q)->f938=G3D_UTIL_AddUnit(((struct Guru2MainCtx *)p)->fAF4,gGuru2MarkerUnitSetupA);
    ((struct Guru2MainCtx *)q)->f93C=G3D_UTIL_AddUnit(((struct Guru2MainCtx *)p)->fAF4,gGuru2MarkerUnitSetupB);
    for (i=0;i<5;i++) *(int *)(q+0x940+i*4)=G3D_UTIL_AddUnit(((struct Guru2MainCtx *)p)->fAF4,gGuru2CardUnitSetupTable+i*16);
}

void GURU2_MAIN_RemovePlayerUnits(char *p)
{
    int i;
    char *q = p+0x1a0;
    for (i=0;i<5;i++) G3D_UTIL_RemoveUnit(((struct Guru2MainCtx *)p)->fAF4,(u16)(*(int *)(q+0x940+i*4)));
    G3D_UTIL_RemoveUnit(((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)q)->f938));
    G3D_UTIL_RemoveUnit(((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)q)->f93C));
}

void GURU2_MAIN_ActivatePlayerRecord(char *p,char *q) { *(int *)&((struct Guru2MainCtx *)q)->f4=1; GURU2_MAIN_ActivatePlayerUnit(p,q); GURU2_MAIN_ActivateCardUnit(p,q); }

void GURU2_MAIN_UpdatePlayerRecords(char *p)
{
    Count count;
    int i=0;
    PlayerBlock *base;
    count=((struct Guru2MainCtx *)p)->f30;
    base=(PlayerBlock *)(p+0x1a0);
    for (;i<count;i++) {
        if (base->a[i].active)
            GURU2_MAIN_UpdateRecordPosition((char *)&base->a[i],(int *)(p+0x110),*(u16 *)(p+0x60+i*2)<<12,*(int *)&((struct Guru2MainCtx *)p)->f5C);
        if (base->b[i].active)
            GURU2_MAIN_InitPlayerUnit(p,(char *)&base->b[i],*(int *)&((struct Guru2MainCtx *)p)->f5C);
        if (base->c[i].active)
            GURU2_MAIN_UpdateCardUnitAnim(p,(char *)&base->c[i],i);
    }
}

void GURU2_MAIN_DrawPlayerRecords(u8 *p)
{
    int i=0;
    int count=((struct Guru2MainCtx *)p)->f30;
    u8 *base=p+0x1a0;
    u8 *first=base+0x140,*second=base+0x4c4,*third=base+0x730;
    for(;i<count;i=i+1) {
        if(((struct Guru2MainCtx3 *)first)->f4) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)base)->f938));
            VecSet(&t.pos,((struct Guru2MainCtx3 *)first)->f44,((struct Guru2MainCtx3 *)first)->f48,((struct Guru2MainCtx3 *)first)->f4C);
            VecSet(&t.scale,((struct Guru2MainCtx3 *)first)->f38,((struct Guru2MainCtx3 *)first)->f3C,((struct Guru2MainCtx3 *)first)->f40);
            BUTTON_MAN_MakeRotMtxXYZ(((struct Guru2MainCtx3 *)first)->f24,((struct Guru2MainCtx3 *)first)->f26,((struct Guru2MainCtx3 *)first)->f28,(struct Mtx33 *)&t.rot);
            G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
        }
        if(*(int *)&((struct Guru2MainCtx2 *)second)->f0) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(((struct Guru2MainCtx *)base)->f93C));
            VecSet(&t.pos,((struct Guru2MainCtx2 *)second)->f18,((struct Guru2MainCtx2 *)second)->f1C,((struct Guru2MainCtx2 *)second)->f20);
            VecSet(&t.scale,((struct Guru2MainCtx2 *)second)->fC,((struct Guru2MainCtx2 *)second)->f10,*(int *)&((struct Guru2MainCtx2 *)second)->f14);
            BUTTON_MAN_MakeRotMtxXYZ(((struct Guru2MainCtx2 *)second)->f4,((struct Guru2MainCtx2 *)second)->f6,*(unsigned short *)&((struct Guru2MainCtx2 *)second)->f8,(struct Mtx33 *)&t.rot);
            G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
        }
        if(((struct Guru2MainCtx *)third)->f0) {
            Transform t;
            void *object=(void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(*(int *)((unsigned)(base+i*4)+0x940)));
            VecSet(&t.pos,*(int *)&((struct Guru2MainCtx *)third)->f4,*(int *)&((struct Guru2MainCtx *)third)->f8,((struct Guru2MainCtx *)third)->fC);
            VecSet(&t.scale,4096,4096,4096);
            func_0207ADC4(&t.rot);
            G3D_SYSTEM_DrawObject(object,(struct Arg *)(&t));
        }
        first+=0xb4;second+=0x7c;third+=0x68;
    }
}

void GURU2_MAIN_RotatePlayerRecords(char *p,int amount)
{
    int count = *(int *)&((struct Guru2MainCtx2 *)p)->f30;
    int i = 0;
    char *base = p+0x1a0;
    for (;i<count;i++) {
        if (*(int *)(base+0x140+i*0xb4))
            GURU2_MAIN_AddAngleWrapped((int *)(base+0x15c+i*0xb4),amount);
    }
}

/*
 * extent: two-byte alignment padding at 0x021E0A42.
 * Verified ARM scratch C: S12/blocker_0203F63C-r1.log EXACT (72 bytes),
 * S13/blocker_0203F5FC-r1.log EXACT (64 bytes). Both use this symbol:
 *   FX_SinCosTable_ 0x020A1B38 data a2
 * typedef unsigned short u16;
 * extern const short FX_SinCosTable_[];
 * int func_0203F63C(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return FX_SinCosTable_[((angle * 65535 / 360) >> 4) * 2 + 1];
 * }
 * int func_0203F5FC(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return FX_SinCosTable_[((angle * 65535 / 360) >> 4) * 2];
 * }
 */
void GURU2_MAIN_UpdateRecordPosition(char *p,int *q,int amount,int extra)
{
    u16 angle;
    GURU2_MAIN_AddAngleWrapped(&amount,*(int *)(p+0x20));
    angle=amount/4096;
    *(int *)(p+0x44)=*(int *)(p+0x50)+q[0]+22*func_0203F63C(angle);
    *(int *)(p+0x48)=extra+(*(int *)(p+0x54)-0x6000+q[1]);
    *(int *)(p+0x4c)=*(int *)(p+0x58)+q[2]+22*func_0203F5FC(angle);
    *(short *)(p+0x24)=*(int *)(p+0x2c)/4096;
    *(short *)(p+0x26)=*(int *)(p+0x30)/4096;
    *(short *)(p+0x28)=*(int *)(p+0x34)/4096;
}

/*
 * lever: (pass 2 2026-10-06 P2L40) i zeroed before the angle statement, the row offset
 *   count*10 in a named local as in the twin GURU2_MAIN_StateAnimateSlots, and a separate local for the
 *   insertion-sort value in the third loop.
 * history: wave P12 lane A8 33 of 208 bytes off; final push G7L3 26 (initialised declarations
 *   count, table, base); pass 2 P2L40: early i 13, separate sort-value local 6, named row 0.
 */
void *GURU2_MAIN_FindNearestPlayerRecord(Obj *p)
{
    int distance[5],indices[5];
    int angle,i,j,key,value,delta,dist,row;
    long count=p->count;
    const u8 *base=(const u8 *)p+0x1a0;
    i=0;
    row=count*10;
    angle=*(const u16 *)((unsigned)gGuru2PointerAngleTable+row+p->index*2)<<12;
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

void GURU2_MAIN_ActivatePlayerUnit(char *p,char *q) { char *r; int offset; r=p+0x664; offset=*(int *)&((struct Guru2MainCtx *)q)->f10*0x7c; *(int *)(r+offset)=1; *(char **)(r+offset+0x78)=q; GURU2_MAIN_InitPlayerUnit(p,r+offset,0); }

void GURU2_MAIN_InitPlayerUnit(char *p,char *q,int amount)
{
    int n;
    *(short *)&((struct Guru2MainCtx2 *)q)->f4=0;
    *(short *)&((struct Guru2MainCtx2 *)q)->f6=0;
    *(short *)&((struct Guru2MainCtx2 *)q)->f8=0;
    *(Vec *)(q+0x18)=*(Vec *)(*(char * *)&((struct Guru2MainCtx2 *)q)->f78+0x44);
    ((struct Guru2MainCtx2 *)q)->f18-=((struct Guru2MainCtx2_f78 *)((struct Guru2MainCtx2 *)q)->f78)->f50;
    ((struct Guru2MainCtx2 *)q)->f1C-=((struct Guru2MainCtx2_f78 *)((struct Guru2MainCtx2 *)q)->f78)->f54+amount;
    ((struct Guru2MainCtx2 *)q)->f20-=((struct Guru2MainCtx2_f78 *)((struct Guru2MainCtx2 *)q)->f78)->f58;
    ((struct Guru2MainCtx2 *)q)->f1C+=0x2000;
    n=((struct Guru2MainCtx2_f78 *)((struct Guru2MainCtx2 *)q)->f78)->f54+amount;
    if (n<0) n=-n;
    n/=128;
    if (n>0x800) n=0x800;
    ((struct Guru2MainCtx2 *)q)->fC=0x1000-n;
    ((struct Guru2MainCtx2 *)q)->f10=0x1000-n;
    *(int *)&((struct Guru2MainCtx2 *)q)->f14=0x1000-n;
}

void GURU2_MAIN_ActivateCardUnit(char *p, char *q)
{
    char *r = p + 0x8D0 + *(int *)&((struct Guru2MainCtx *)q)->f10 * 0x68;

    ((struct Guru2MainCtx3 *)r)->f0 = 1;
    *(char * *)&((struct Guru2MainCtx3 *)r)->f64 = q;
}

void GURU2_MAIN_UpdateCardUnitAnim(char *p,char *q,int i)
{
    void *r = (void *)func_02048A18(((struct Guru2MainCtx *)p)->fAF4,(u16)(*(int *)(p+0xae0+i*4)));
    *(Vec *)(q+4) = *(Vec *)(*(char * *)&((struct Guru2MainCtx2 *)q)->f64+0x44);
    ((struct Guru2MainCtx2 *)q)->f8 += 0x14000;
    G3D_SYSTEM_LoopObjectAnimeFrame(r,0,0x1000);
}

void GURU2_MAIN_StartDropEffect(char *p,int a,int b,int c,int d,int e,int *q)
{
    int *r;
    q[3]=a;
    q[4]=b;
    q[5]=c;
    q[6]=b;
    q[7]=d<<12;
    q[8]=e<<12;
    q[0]=1;
    q[2]=0;
    r=func_02030734(0x8072,24,0,gGuru2MainAllocFileName,0x130e);
    MI_CpuFill8(r,0,24);
    r[5]=(int)p;
    r[4]=(int)q;
    func_02030DA8(((struct Guru2MainCtx *)p)->fD98,(void (*)(void *, void *))GURU2_MAIN_DropEffectTask,r,0);
}

extern int (*const gGuru2DropEffectStateTable[])(char *);

void GURU2_MAIN_DropEffectTask(struct Node *task,char *p) { int result; do { result=gGuru2DropEffectStateTable[*(int *)p](p); } while(result==1); if(result==2) { ((struct Guru2MainCtx2 *)((struct Guru2MainCtx *)p)->f10)->f8=1; func_020307B0(p); func_02030EAC(task); } }

int GURU2_MAIN_DropEffectStateInit(struct Guru2MainCtx *p) { char *q; q=*(char * *)&p->f10; *(int *)&((struct Guru2MainCtx *)q)->f38=4096; *(int *)&((struct Guru2MainCtx *)q)->f3C=4096; ((struct Guru2MainCtx *)q)->f40=4096; ((struct Guru2MainCtx *)q)->f54=0xc0000; GURU2_MAIN_ActivatePlayerRecord(*(char * *)&p->f14,q); p->fC=0x8000; p->f0=1; return 0; }

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
        GURU2_MAIN_PrintPlayerName((u8 *)r, (void *)(*(int *)(r + 0xa4 + q[3]*4)), q[5], q[3]);
        return 2;
    }
    return 0;
}

void GURU2_MAIN_UpdateBounceEffect(char *p,int *q)
{
    int *r=(int *)q[7];
    switch(q[1]) {
    case 0:
        GURU2_MAIN_AddSettleEffect(p,(int)r);
        q[4]=0x4000;
        q[5]=-1092;
        q[1]++;
    case 1:
        r[23]+=q[4];
        q[4]+=q[5];
        q[2]++;
        if(q[2]>=15) {
            q[2]=0;
            q[4]=0;
            if(q[3]==0) { q[3]=1; return; }
            r[23]=0;
            GURU2_MAIN_AddWobbleEffect(p,(int)r);
            MI_CpuFill8(q,0,32);
        }
        break;
    }
}

void GURU2_MAIN_BounceEffectTask(void *unused,char *p) { int i; int *q; q=(int *)(p+0xaf8); for(i=0;i<5;i++,q+=8) if(*q!=0) GURU2_MAIN_UpdateBounceEffect(p,q); }

void GURU2_MAIN_CreateBounceEffectTask(char *p) { MI_CpuFill8(p+2808,0,160); *(struct Node * *)&((struct Guru2MainCtx *)p)->fD7C=func_02030DA8(*(struct Ctx * *)&((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))((u32)GURU2_MAIN_BounceEffectTask), (void *)((u32)p), 256); }

void GURU2_MAIN_DeleteBounceEffectTask(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD7C);
}

void GURU2_MAIN_AddBounceEffect(char *p,int value) { int i; int *q; q=(int *)(p+0xaf8); for(i=0;i<5;i++,q+=8) { if(*q==0) { *q=1; q[7]=value; return; } } }

void GURU2_MAIN_AddBounceEffectsForActivePlayers(char *p)
{
    RecordBlock *base=(RecordBlock *)(p+0x1a0);
    int count=((struct Guru2MainCtx *)p)->f30;
    int i;
    i=0;
    do {
        if (base->records[i].active) GURU2_MAIN_AddBounceEffect(p,(int)((char *)&base->records[i]));
        i++;
    } while (i<count);
}

/*
 * extent: unlabelled bool scan follower at 0x021E0E8C, through pool at 0x021E0EA8.
 */
int GURU2_MAIN_IsBounceEffectActive(char *p)
{
    int i;
    char *q=p+0xaf8;
    for (i=0;i<5;i++,q+=0x20) if (((struct Guru2MainCtx3 *)q)->f0) return 1;
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

void GURU2_MAIN_SettleEffectTask(void *unused,char *p) { int i; int *q; q=(int *)(p+0xb98); for(i=0;i<5;i++,q+=5) if(*q!=0) GURU2_MAIN_UpdateSettleEffect(q); }

void GURU2_MAIN_CreateSettleEffectTask(char *p) { MI_CpuFill8(p+2968,0,100); *(struct Node * *)&((struct Guru2MainCtx *)p)->fD80=func_02030DA8(*(struct Ctx * *)&((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))((u32)GURU2_MAIN_SettleEffectTask), (void *)((u32)p), 257); }

void GURU2_MAIN_DeleteSettleEffectTask(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD80);
}

void GURU2_MAIN_AddSettleEffect(char *p, int key)
{
    int i;
    EntryA *entry;
    EntryA *base = (EntryA *)(p + 0xb98);
    entry = base;
    for (i = 0; i < 5; i++, entry++) {
        if (entry->active == 1 && entry->key == key) {
            entry->state = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base++) {
        if (base->active == 0) {
            base->active = 1;
            base->key = key;
            return;
        }
    }
}

/*
 *   typedef unsigned short u16;
 *   extern const short FX_SinCosTable_[];
 *   int func_0203F5FC(u16 angle) {
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
        amount = func_0203F5FC((u16)(p[4] / 4096)) * (p[2] / 4096);
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

void GURU2_MAIN_WobbleEffectTask(void *unused,char *p) { int i; int *q; q=(int *)(p+0xbfc); for(i=0;i<5;i++,q+=6) if(*q!=0) GURU2_MAIN_UpdateWobbleEffect(q); }

void GURU2_MAIN_CreateWobbleEffectTask(char *p) { MI_CpuFill8(p+3068,0,120); *(struct Node * *)&((struct Guru2MainCtx *)p)->fD84=func_02030DA8(*(struct Ctx * *)&((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))((u32)GURU2_MAIN_WobbleEffectTask), (void *)((u32)p), 258); }

void GURU2_MAIN_DeleteWobbleEffectTask(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD84);
}

void GURU2_MAIN_AddWobbleEffect(char *p, int key)
{
    int i;
    EntryB *entry;
    EntryB *base = (EntryB *)(p + 0xbfc);
    entry = base;
    for (i = 0; i < 5; i++, entry++) {
        if (entry->active == 1 && entry->key == key) {
            entry->state = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base++) {
        if (base->active == 0) {
            base->active = 1;
            base->key = key;
            return;
        }
    }
}

void GURU2_MAIN_UpdateEntranceEffect(u8 *p,PlayerState *s)
{
    u8 *b=p+0xe0;
    switch(s->state) {
    case 1:
        s->speed=0x4000;s->timer=0;s->state++;
    case 2:
        ((struct Guru2MainCtx *)b)->f34-=4096;
        if(((struct Guru2MainCtx *)b)->f34<=-32768)s->state++;
        break;
    case 3:
        ((struct Guru2MainCtx *)b)->f34+=8192;
        if(((struct Guru2MainCtx *)b)->f34>=0) {
            ((struct Guru2MainCtx *)b)->f34=0;
            GURU2_MAIN_AddBounceEffectsForActivePlayers((char *)p);
            s->active=1;s->state++;
            GFL_USE_PlaySeDefaultVolume(0x55e);
        }
        break;
    case 4:
        *(int *)&((struct Guru2MainCtx *)b)->f28=s->speed;
        s->speed=-s->speed;
        s->timer++;
        if(!(s->timer&3)) {
            if(s->speed<=4096) {*(int *)&((struct Guru2MainCtx *)b)->f28=0;s->state++;}
            else s->speed>>=1;
        }
        break;
    case 5:
        if(!GURU2_MAIN_IsBounceEffectActive((char *)p)) {
            s->other=0;s->active=0;s->state=0;
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

void GURU2_MAIN_CreateEntranceEffectTask(char *p)
{
    MI_CpuFill8(p + 0xc74, 0, 20);
    ((struct Guru2MainCtx *)p)->fD88 = (void *)func_02030DA8(((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))GURU2_MAIN_EntranceEffectTask, p, 255);
}

void GURU2_MAIN_DeleteEntranceEffectTask(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD88);
}

void GURU2_MAIN_StartEntranceEffect(char *p)
{
    char *q = p + 0xC74;

    *(int *)&((struct Guru2MainCtx *)q)->f8 = 1;
    ((struct Guru2MainCtx *)q)->f0 = 1;
}

int GURU2_MAIN_GetEntranceEffectState(char *p)
{
    return ((struct Guru2MainCtx2 *)p)->fC78;
}

int GURU2_MAIN_GetEntranceEffectActive(char *p)
{
    return ((struct Guru2MainCtx2 *)p)->fC7C;
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
        CLACT_AddActorAnimFrame((struct Obj *)p[5], 0x1800);
        if (CLACT_IsActorAnimActive((struct Actor *)p[5]) == 0) p[0]++;
        break;
    case 1:
        CLACT_DeleteActor((struct Obj *)p[5]);
        func_020307B0(p);
        func_02030EAC(task);
        break;
    }
}

void GURU2_MAIN_CreateCenterActorTask(char *p)
{
    struct { u16 x, y, z; u8 a, b; } pos;
    int *q = func_02030734(0x8072, 24, 0, gGuru2MainAllocFileName, 5638);
    MI_CpuFill8(q, 0, 24);
    pos.x = 128;
    pos.y = 100;
    pos.z = 0;
    pos.b = 0;
    pos.a = 0;
    q[5] = (int)(struct Obj *)CLACT_CreateActor((void *)*(unsigned int *)&((struct Guru2MainCtx *)p)->fD68, ((struct Guru2MainCtx *)p)->fD6C, ((struct Guru2MainCtx *)p)->fD70, ((struct Guru2MainCtx *)p)->fD74, &pos, 0, 114);
    CLACT_AddActorAnimFrame((struct Obj *)q[5], 4096);
    q[4] = (int)p;
    func_02030DA8(((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))GURU2_MAIN_CenterActorTask, q, 0);
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

void GURU2_MAIN_CreateScreenFlashTask(char *p)
{
    unsigned n = 8;
    MI_CpuFill8(p + 0xc88, 0, n);
    n += 251;
    ((struct Guru2MainCtx *)p)->fD8C = (void *)func_02030DA8(((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))GURU2_MAIN_ScreenFlashTask, p, n);
}

void GURU2_MAIN_DeleteScreenFlashTask(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD8C);
}

u16 GURU2_MAIN_GetScreenFlashFlag(char *p)
{
    return ((struct Guru2MainCtx2 *)p)->fC8A;
}

void GURU2_MAIN_StartScreenFlash(char *p)
{
    char *q = p + 0xC88;

    ((struct Guru2MainCtx4 *)q)->f2 = 1;
    ((struct Guru2MainCtx4 *)q)->f0 = 1;
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

void GURU2_MAIN_CreatePulseEffectTask(char *p)
{
    unsigned n = 80;
    MI_CpuFill8(p + 0xc90, 0, n);
    n += 180;
    ((struct Guru2MainCtx *)p)->fD90 = (void *)func_02030DA8(((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))GURU2_MAIN_PulseEffectTask, p, n);
}

void GURU2_MAIN_DeletePulseEffectTask(u8 *p)
{
    func_02030EAC(((struct Guru2MainCtx *)p)->fD90);
}

void GURU2_MAIN_AddPulseEffect(char *p, char *q)
{
    char *r = p + 0xC90 + ((struct Guru2MainCtx2 *)q)->fC * 0x10;

    ((struct Guru2MainCtx *)r)->f0 = 1;
    *(char * *)&((struct Guru2MainCtx *)r)->fC = q;
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
        func_020307B0(p);
        func_02030EAC(task);
    }
}

void GURU2_MAIN_StartBlendFade(char *p, int flag)
{
    IntPair values = gGuru2FadeValues;
    int *q = func_02030734(0x8072, 12, 0, gGuru2MainAllocFileName, 5992);
    q[0] = (int)p;
    q[1] = flag;
    q[2] = ((int *)&values)[flag];
    func_02030DA8(((struct Guru2MainCtx *)p)->fD98, (void ( *)(void *,void *))GURU2_MAIN_BlendFadeTask, q, 0);
}

void GURU2_MAIN_AddAngleWrapped(int *p, int v)
{
    *p += v;
    while (*p < 0) *p += 0x168000;
    *p %= 0x168000;
}

void GURU2_MAIN_RotateAll(char *p, int v)
{
    GURU2_MAIN_AddAngle((u8 *)(p + 0xe0), v);
    GURU2_MAIN_RotatePlayerRecords(p, v);
}

int GURU2_MAIN_TickTimeout(char *p)
{
    int n = ((struct Guru2MainCtx2 *)p)->f8 + 1;

    ((struct Guru2MainCtx2 *)p)->f8 = n;
    if (n < 0x258)
        return 0;
    ((struct Guru2MainCtx2 *)p)->f8 = 0x258;
    return 1;
}

/*
 * extent: following 021E168C is already matched separately.
 */
void *GURU2_MAIN_LoadArcMember(char *p, u32 member, int flag)
{
    u32 size = ARC_TOOL_GetHandleMemberSize(*(struct ArcFile * *)&((struct Guru2MainCtx *)p)->fD58, member);
    void *result;
    if (flag == 1)
        result = func_02030734(114, size, 0, gGuru2MainAllocFileName, 6090);
    else
        result = func_02030734(0x8072, size, 0, gGuru2MainAllocFileName, 6092);
    ARC_TOOL_ReadHandleMember(*(struct ArcFile * *)&((struct Guru2MainCtx *)p)->fD58, member, result);
    return result;
}

void GURU2_MAIN_SetPlayerInput(int *p,int a) { if(a!=0) p[13]=a; }

void GURU2_MAIN_StoreRoundResult(char *p, const FiveRecord *q)
{
    ((struct Guru2MainCtx2 *)p)->f3C = 1;
    *(FiveRecord *)(p + 0x58) = *q;
}

char *GURU2_MAIN_ClearSendBuffer(struct Guru2Game *p, int n)
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
void GURU2_MAIN_StoreSlotAssignment(char *p,unsigned short *q) { unsigned int index;unsigned short value; index=*(volatile unsigned short *)&((struct Guru2MainCtx4 *)q)->f0;value=*(volatile unsigned short *)&((struct Guru2MainCtx4 *)q)->f0;*(unsigned short *)(p+index*4+0x7c)=value;*(unsigned short *)(p+index*4+0x7e)=q[1];if(q[1]==GFL_NET_SYSTEM_GetCurrentAid())((struct Guru2MainCtx *)p)->f2C=q[0]; }

void GURU2_MAIN_SyncPlayerCount(char *p, int a1) { ((struct Guru2MainCtx *)p)->f30=UNION_APP_GetMemberCount(GURU2_MAIN_GetUnionApp((struct Guru2Game *)p)); }

/*
 * The `&` operand order names the temporary: `field & (1 << i)` (field into
 * r2, mask into r0) reproduces the original; `(1 << i) & field` rotates them.
 */
int GURU2_MAIN_IsMemberPresent(struct Guru2Game *p, int i)
{
    if (i != 0 && (p->comm->ackMask & (1 << i)) == 0)
        return 0;
    return 1;
}

void GURU2_MAIN_CopyMemberPokemon(struct Guru2Game *p, int i)
{
    void *party;
    void *other;
    int slot;
    void *a;
    void *b;
    void *q;
    party = p->party;
    other = GURU2_COMM_GetPartyCopy(p->comm, i);
    slot = p->partySlot[i];
    a = POKEPARTY_GetMember(party, p->session->selectedSlot);
    b = POKEPARTY_GetMember(other, slot);
    q = GURU2_MAIN_GetUnionApp(p);
    func_0202F190(b, (int)6, (u32)UNION_APP_GetMemberEntry(q, (u8)GFL_NET_SYSTEM_GetCurrentAid()), (int)30002, (int)114);
    func_02019CE0(b, a);
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

void GURU2_MAIN_SetPlayerSelectedSlot(int *p,int a,int b) { (p+a)[17]=b; }

void GURU2_MAIN_StoreAngles(unsigned char *p,u16 *q)
{
    u16 *d=(u16 *)(p+108);
    unsigned n=8;
    do { *d++=*q++; } while(--n);
    ((struct Guru2MainCtx3 *)p)->f40=1;
}

int GURU2_MAIN_IsAngleInRangeList(char *p, int angle, int index)
{
    int tmp;
    unsigned a;
    unsigned count;
    unsigned b;
    struct RangeU16 *r;
    struct RangeList *e;
    GURU2_MAIN_AddAngleWrapped(&angle, -((struct Guru2MainCtx *)p)->f11C);
    GURU2_MAIN_AddAngleWrapped(&angle, -((struct Guru2MainCtx *)p)->f124);
    tmp = angle;
    GURU2_MAIN_AddAngleWrapped(&tmp, -0x4000);
    a = tmp / 0x1000;
    tmp = angle;
    GURU2_MAIN_AddAngleWrapped(&tmp, 0x5000);
    b = tmp / 0x1000;
    e = &gGuru2PlayerAngleRangeLists[index];
    count = e->count;
    r = e->ranges;
    while (count) {
        if ((a >= r->lo && a <= r->hi) || (b >= r->lo && b <= r->hi))
            return 1;
        r++;
        count--;
    }
    return 0;
}

int GURU2_MAIN_PartyHasEligiblePokemon(void *p)
{
    int n;
    int i;
    void *m;
    n = POKEPARTY_GetCount(p);
    for (i = 0; i < n; i++) {
        m = POKEPARTY_GetMember(p, i);
        if (func_02017E1C(m, 0x4c, 0) != 0 && func_02017E1C(m, 3, 0) != 0)
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

void GURU2_MAIN_PushAndPlayBgm(unsigned int n) { GFL_USE_SetBgmPlayerParam((void *)1);GFL_USE_PushBgm();GFL_USE_CancelChangeAndPlayBgm(n,65535); }

/*
 * prototype: Legacy 02005E9C source lists four inputs, but its complete
 * body starts with 02005FBC(void) and reads no entry inputs; omitted them.
 */
int GURU2_MAIN_PopBgmWhenDone(void) { if(GFL_USE_IsBgmPlaying()==0) { GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);return 0; }return 1; }

void GURU2_MAIN_BroadcastResult(char *r4, int r5)
{
    struct {
        int a;
        int b;
        short h[6];
    } buf;
    int i;

    if (GFL_NET_SYSTEM_GetCurrentAid() != 0)
        return;
    GURU2_MAIN_RotateAll(r4, r5);
    buf.a = ((struct Obj04542 *)r4)->f11C;
    buf.b = ((struct Obj04542 *)r4)->f33C;
    for (i = 0; i < ((struct Obj04542 *)r4)->f30; i++) {
        int v = *(int *)(r4 + 0x2FC + i * 0xB4);
        buf.h[i] = (short)(v / 4096);
    }
    GURU2_COMM_Send((void *)(((struct Obj04542 *)r4)->fDC), 0x2808, &buf, 0x14);
}
