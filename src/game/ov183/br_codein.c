/*
 * file:     br_codein.c
 * unit:     yes
 * function: BR_CODEIN_SidebarCreate, BR_CODEIN_SidebarDestroy, BR_CODEIN_SidebarMain, BR_CODEIN_SidebarStepIntro, BR_CODEIN_SidebarStepSlideIn, BR_CODEIN_SidebarStepSlideOut, BR_CODEIN_SidebarClearStep, BR_CODEIN_ButtonCreate, BR_CODEIN_ButtonDestroy, BR_CODEIN_ButtonMain, BR_CODEIN_ButtonLoadFadePalettes, BR_CODEIN_RecordCreate, BR_CODEIN_RecordDestroy, BR_CODEIN_RecordMain, BR_CODEIN_RecordStepCreateProfile, BR_CODEIN_RecordStepFadeIn, BR_CODEIN_RecordStepFadeOut, BR_CODEIN_RecordStepDeleteProfile, BR_CODEIN_RecordStepMenu, BR_CODEIN_RecordStepProfileText, BR_CODEIN_RecordStepRequest, BR_CODEIN_RecordStepReceive, BR_CODEIN_RecordStepSave, BR_CODEIN_RecordStepConfirm, BR_CODEIN_RecordSetupProfile, BR_CODEIN_RecordSetupActors, BR_CODEIN_RecordCreateProfileScreen, BR_CODEIN_RecordDeleteProfileScreen, BR_CODEIN_RecordDeleteActors, BR_CODEIN_RecordSetupButtons, BR_CODEIN_RecordDeleteButtons, BR_CODEIN_RecordCreateTextWin, BR_CODEIN_RecordDeleteTextWin, BR_CODEIN_RecordSetupTextWin, BR_CODEIN_RecordTeardownTextWin, BR_CODEIN_RecordIsMultiBattle, BR_CODEIN_RecordIsType2, BR_CODEIN_RecordHitProfileToggle, BR_CODEIN_RecordHitRecordPanel, BR_CODEIN_RecordHitOptionLeft, BR_CODEIN_RecordHitOptionRight, BR_CODEIN_ListCreate, BR_CODEIN_ListDestroy, BR_CODEIN_ListMain, BR_CODEIN_ListSetupText, BR_CODEIN_ListSetupRowA, BR_CODEIN_ListSetupRowB, BR_CODEIN_ListSetupRowC, BR_CODEIN_ListSetupRowD, BR_CODEIN_ListTeardown, BR_CODEIN_ListSetupButtons, BR_CODEIN_ListDeleteButtons, BR_CODEIN_ListHitButton, BR_CODEIN_ListIsEventA, BR_CODEIN_ListIsEventB, BR_CODEIN_ListIsEventC, BR_CODEIN_ListCreateActor, BR_CODEIN_ListDeleteActor, BR_CODEIN_ListSetActorAnim, BR_CODEIN_ResultCreate, BR_CODEIN_ResultDestroy, BR_CODEIN_ResultMain, BR_CODEIN_ResultSetupTextWin, BR_CODEIN_ResultSetupRowA, BR_CODEIN_ResultSetupRowB, BR_CODEIN_ResultSetupRowC, BR_CODEIN_ResultTeardown, BR_CODEIN_ResultSetupButtons, BR_CODEIN_ResultDeleteButtons, BR_CODEIN_ResultHitButton, BR_CODEIN_StatCreate, BR_CODEIN_StatDestroy, BR_CODEIN_StatMain, BR_CODEIN_StatSetup, BR_CODEIN_StatTeardown, BR_CODEIN_StatStepFadeIn, BR_CODEIN_StatStepFadeOut, BR_CODEIN_StatStepMenu, BR_CODEIN_SearchStep, BR_CODEIN_SearchStepText, BR_CODEIN_SearchStepFade, BR_CODEIN_SearchCreateList, BR_CODEIN_SearchDeleteList, BR_CODEIN_SearchMainList, BR_CODEIN_SearchGetHitId, BR_CODEIN_SearchCreateActor, BR_CODEIN_SearchDeleteActor, BR_CODEIN_SearchUpdateActor, BR_CODEIN_SearchBuildHeader, BR_CODEIN_SearchHitBox, BR_CODEIN_CodeCreate, BR_CODEIN_CodeDestroy, BR_CODEIN_CodeMain, BR_CODEIN_CodeSetupButtons, BR_CODEIN_CodeDeleteButtons, BR_CODEIN_CodeStepInput, BR_CODEIN_CodeSetupMenu, BR_CODEIN_CodeDeleteMenu, BR_CODEIN_CodeStepMenu, BR_CODEIN_CodeOpenPokeSearch, BR_CODEIN_CodeClosePokeSearch, BR_CODEIN_CodeStepPokeSearch, BR_CODEIN_CodeSetupPokeList, BR_CODEIN_CodeDeletePokeList, BR_CODEIN_CodeStepPokeList, BR_CODEIN_CodeSetupText, BR_CODEIN_CodeDeleteText, BR_CODEIN_CodeSetMenuText, BR_CODEIN_CodeHitTestOptions, BR_CODEIN_ProfileScreenCreate, BR_CODEIN_ProfileScreenDestroy, BR_CODEIN_ProfileScreenMain, BR_CODEIN_ProfileCreate, BR_CODEIN_ProfileUpdate, BR_CODEIN_ProfileGetState, BR_CODEIN_ProfileGetValue, BR_CODEIN_ProfileDestroy, BR_CODEIN_ProfileCreateObject, BR_CODEIN_ProfileDestroyObject, BR_CODEIN_ProfileNoop, BR_CODEIN_ProfileSetupSprite, BR_CODEIN_ProfileDeleteActor, BR_CODEIN_ProfileCreateRecordActors, BR_CODEIN_ProfileCreateMarkerActors, BR_CODEIN_ProfileCreateArrowActors, BR_CODEIN_ProfileSetActorVisible, BR_CODEIN_ProfileSetActorPos, BR_CODEIN_ProfileAddActorSurfacePos, BR_CODEIN_ProfileUpdateActorAnims, BR_CODEIN_ProfileGetActorIndex, BR_CODEIN_ProfileUpdateActorVisible, BR_CODEIN_ProfileSetActorAnimFrame, BR_CODEIN_ProfileUpdateActorPos, BR_CODEIN_ProfileCreateOam, BR_CODEIN_ProfileDeleteOam, BR_CODEIN_ProfileDeleteBgHandle, BR_CODEIN_ProfileCreateOamObjects, BR_CODEIN_ProfilePrintOamObject, BR_CODEIN_ProfileSetActorAnim, BR_CODEIN_ProfileInitRecordLayout, BR_CODEIN_ProfileSetAnimSeq, BR_CODEIN_ProfileCreateAllActors, BR_CODEIN_ProfileUpdatePendingAndButtons, BR_CODEIN_ProfileUpdateScrollAnim, BR_CODEIN_ProfileUpdateActorAnim, BR_CODEIN_ProfileBuildAnimName, BR_CODEIN_ProfileApplyRecords, BR_CODEIN_ProfileCreateButtons, BR_CODEIN_ProfileHandleInput, BR_CODEIN_ProfileApplyPendingStep, BR_CODEIN_ProfileClear, BR_CODEIN_ProfileFindActorIndex, BR_CODEIN_ProfileFindRecord, BR_CODEIN_UploadCreate, BR_CODEIN_UploadDestroy, BR_CODEIN_UploadMain, BR_CODEIN_UploadStepFadeIn, BR_CODEIN_UploadStepFadeOut, BR_CODEIN_UploadStep, BR_CODEIN_SaveCreate, BR_CODEIN_SaveDestroy, BR_CODEIN_SaveMain, BR_CODEIN_SaveStepFadeIn, BR_CODEIN_SaveStepFadeOut, BR_CODEIN_SaveStepVideo, BR_CODEIN_SaveSetupText, BR_CODEIN_SaveDeleteTextWin, BR_CODEIN_SaveTeardown, BR_CODEIN_SaveHitOptionLeft, BR_CODEIN_SaveHitOptionRight, BR_CODEIN_SoclCreate, BR_CODEIN_SoclDestroy, BR_CODEIN_SoclMain, BR_CODEIN_SoclStep, BR_CODEIN_MenuStep, BR_CODEIN_MenuStepInput, BR_CODEIN_MenuStepSave, BR_CODEIN_CallAndClearStepFn, BR_CODEIN_CallAndClearDestroyFn, BR_CODEIN_CopySoclResource, BR_CODEIN_SoclSetupText, BR_CODEIN_SoclTeardown
 * address:  0x021DB2E0
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BR_PROC_SYS_GetSlotId 0x021F9B9C thumb ov186
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BR_UTIL_CreateHandles 0x021FD760 thumb ov186
 *   BR_UTIL_SetHandlesAnimSeq 0x021FD940 thumb ov186
 *   BR_UTIL_CreateTask 0x021FD6D8 thumb ov186
 *   BR_UTIL_DeleteHandles 0x021FD820 thumb ov186
 *   BR_UTIL_DeleteTask 0x021FD714 thumb ov186
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   BR_UTIL_RunTask 0x021FD71C thumb ov186
 *   BR_UTIL_RunHandles 0x021FD854 thumb ov186
 *   BR_UTIL_IsTaskIdle 0x021FD72C thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_IsEffectDone 0x021FD938 thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   BR_FADE_StartTimed 0x021FE794 thumb ov186
 *   BR_FADE_GetResult 0x021FE7B0 thumb ov186
 *   BR_UTIL_Delete 0x021FC734 thumb ov186
 *   BR_SIDEBAR_StartBounce 0x021FEE24 thumb ov186
 *   BR_PROC_SYS_PushEntry 0x021F9BF4 thumb ov186
 *   BR_UTIL_SetTaskStep 0x021FD73C thumb ov186
 *   BR_UTIL_FlushText 0x021FC830 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BR_SIDEBAR_StartSlide 0x021FEE74 thumb ov186
 *   BR_PROC_SYS_PopEntry 0x021F9BA0 thumb ov186
 *   BR_SIDEBAR_ResetPositions 0x021FEE9C thumb ov186
 *   BR_SIDEBAR_StartWobble 0x021FEE4C thumb ov186
 *   BR_UTIL_ClearTaskStep 0x021FD744 thumb ov186
 *   BR_RES_ReleaseUiPalette 0x021FC1F8 thumb ov186
 *   BR_RES_LoadUiPalette 0x021FC148 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_BTN_Create 0x021F9CB8 thumb ov186
 *   BR_FADE_SetBlendLevel 0x021FE840 thumb ov186
 *   BR_RES_ApplyBgSet 0x021FBDA4 thumb ov186
 *   BR_BTN_Delete 0x021F9F48 thumb ov186
 *   BR_FADE_Start 0x021FE784 thumb ov186
 *   BR_BTN_GetPressed 0x021FA018 thumb ov186
 *   BR_BTN_UpdatePrint 0x021F9FE8 thumb ov186
 *   BR_BTN_GetPlacement 0x021FA004 thumb ov186
 *   BR_BTN_GetResultValue 0x021FA01C thumb ov186
 *   BR_RES_GetPalSet 0x021FC238 thumb ov186
 *   BR_RES_SetPalSet 0x021FC230 thumb ov186
 *   BR_RES_GetCurrentSetParam 0x021FC224 thumb ov186
 *   BR_FADE_SetBlendColor 0x021FE7F4 thumb ov186
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E3280 0x021E3280 data a4
 *   BR_RES_LoadFadePalettes  0x021FC240  thumb  ov186
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   BATTLE_REC_GetHeader 0x0200B928 thumb
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   GAME_DATA_IsSaving 0x02012E40 thumb
 *   BR_NET_HandleNetError 0x021FF88C thumb ov186
 *   BR_PROC_SYS_FlushWindows 0x021F9C6C thumb ov186
 *   BR_UTIL_MainProfileScreen 0x021FD6B0 thumb ov186
 *   BR_UTIL_FlushWindow 0x021FD1BC thumb ov186
 *   BR_BTN_HitTestWithSound 0x021FB4B4 thumb ov186
 *   BR_PROC_SYS_SetupWindow 0x021F9C50 thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_NET_StartRequest 0x021FF54C thumb ov186
 *   BR_NET_IsIdle 0x021FF648 thumb ov186
 *   BR_NET_PollErrorMessage 0x021FF72C thumb ov186
 *   BR_NET_GetVideoReply 0x021FF698 thumb ov186
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_REC_SetData 0x0200B938 thumb
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   GDS_RAP_SaveVideoSecured 0x021D7630 thumb ov125
 *   d_021E3960 0x021E3960 data a1
 *   GF_PANIC_Fail 0x02034714 arm
 *   BATTLE_REC_DecodeWork 0x0200B490 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   GDS_PROFILE_GetEggFlag 0x0200D6EC thumb
 *   GDS_PROFILE_ExportRecord 0x0200D774 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   d_021E32C8 0x021E32C8 data a4
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021E32F0 0x021E32F0 data a2
 *   BR_UTIL_CreateProfileScreen 0x021FD1C4 thumb ov186
 *   BR_UTIL_DeleteProfileScreen 0x021FD640 thumb ov186
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   d_021E32A8 0x021E32A8 data a4
 *   BSUBWAY_SCOREDATA_GetBattlePoints 0x0200DABC thumb
 *   d_021E3350 0x021E3350 data a4
 *   BSUBWAY_SCOREDATA_HasCleared 0x0200DB44 thumb
 *   BSUBWAY_SCOREDATA_GetWinCount 0x0200DAC4 thumb
 *   BSUBWAY_SCOREDATA_GetMaxWinCount 0x0200DAD8 thumb
 *   d_021E33C0 0x021E33C0 data a4
 *   d_021E3400 0x021E3400 data a4
 *   d_021E3490 0x021E3490 data a4
 *   BSUBWAY_SCOREDATA_GetLevel 0x0200DC08 thumb
 *   d_021E338C 0x021E338C data a4
 *   d_021E336C 0x021E336C data a4
 *   d_021E3440 0x021E3440 data a4
 *   BSUBWAY_SCOREDATA_AccessFlag 0x0200DBA0 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   d_021E3358 0x021E3358 data a4
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   d_021E3574 0x021E3574 data a4
 *   d_021E3664 0x021E3664 data a4
 *   d_021E35D4 0x021E35D4 data a4
 *   MSGDATA_ReadString 0x02045CAC arm
 *   d_021E351C 0x021E351C data a4
 *   d_021E3534 0x021E3534 data a4
 *   d_021E3964 0x021E3964 data a1
 *   BR_NET_GetSearchResultsForRanking 0x021FF6DC thumb ov186
 *   BR_NET_GetSearchResultsForNewest 0x021FF704 thumb ov186
 *   BR_NET_GetSearchResults 0x021FF6B4 thumb ov186
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BR_UTIL_CreateListMenu 0x021FC8C8 thumb ov186
 *   BMP_Create 0x02043678 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_SetString 0x02045924 arm
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BR_UTIL_SetListItemBitmap 0x021FCDAC thumb ov186
 *   BR_UTIL_RefreshList 0x021FCE50 thumb ov186
 *   d_021E3700 0x021E3700 data a4
 *   BR_UTIL_GetListMenuField 0x021FCE0C thumb ov186
 *   BR_UTIL_GetListItemBitmap 0x021FCDE8 thumb ov186
 *   BMP_Delete 0x020437AC arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   BR_UTIL_DeleteListMenu 0x021FCC80 thumb ov186
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BR_UTIL_MainListMenu 0x021FCD0C thumb ov186
 *   BR_UTIL_GetListMenuHitId 0x021FCDA8 thumb ov186
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   CLACT_GetActorPaletteOffset 0x0204B714 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   CLACT_GetCharacterProxy 0x0204AB84 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   d_021E37A8 0x021E37A8 data a4
 *   d_021E3734 0x021E3734 data a2
 *   d_021E3740 0x021E3740 data a4
 *   MYSTATUS_GetNation 0x0200856C thumb
 *   MYSTATUS_GetArea 0x02008570 thumb
 *   BR_BTN_TestHitBox 0x021FB4CC thumb ov186
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   d_021E3758 0x021E3758 data a4
 *   d_021E3728 0x021E3728 data a4
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   BR_POKESEARCH_Create 0x021FFBD4 thumb ov186
 *   BR_POKESEARCH_Open 0x021FFE5C thumb ov186
 *   BR_POKESEARCH_UpdatePrint 0x021FFE34 thumb ov186
 *   BR_POKESEARCH_Close 0x021FFE70 thumb ov186
 *   BR_POKESEARCH_Destroy 0x021FFC6C thumb ov186
 *   BR_POKESEARCH_Main 0x021FFC9C thumb ov186
 *   BR_POKESEARCH_GetResult 0x021FFE90 thumb ov186
 *   BMP_MENUWORK_AddStrItem 0x0201F898 thumb
 *   NATION_AREA_GetAreaCount 0x02025B64 thumb
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   WORDSET_SetSlotFromKeyedMessage 0x0201F094 thumb
 *   d_021E3780 0x021E3780 data a4
 *   d_021E372E 0x021E372E data a4
 *   d_021E37D8 0x021E37D8 data ov183
 *   gSpeciesNameBank 0x020A7370 data a4
 *   g_021E3808     0x021E3808  data  ov183
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021E3968 0x021E3968 data ov183
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   d_021E3974 0x021E3974 data a4
 *   d_021E3978 0x021E3978 data ov183
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   d_021E3850 0x021E3850 data a4
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_OAM_SetObjMode 0x0202597C thumb
 *   d_021E3868 0x021E3868 data a4
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   d_021E3998 0x021E3998 data a4
 *   d_021E397C 0x021E397C data a4
 *   d_021E3858 0x021E3858 data a4
 *   STRBUF_Append 0x02045AA8 arm
 *   WORDSET_FormatNumber 0x0201F35C thumb
 *   _ull_mul 0x0209C054 arm
 *   d_021E3880 0x021E3880 data a2
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   d_021E38E0 0x021E38E0 data a4
 *   BATTLE_REC_Load 0x0200B570 thumb
 *   BR_NET_GetUploadedDataNumber 0x021FF67C thumb ov186
 *   BR_UTIL_SetWindowTextBuf 0x021FD19C thumb ov186
 *   d_021E39B4 0x021E39B4 data a4
 *   GDS_RAP_StartVideoSave 0x021D76A8 thumb ov125
 *   GDS_RAP_StepVideoSave 0x021D76D8 thumb ov125
 *   d_021E3900 0x021E3900 data a4
 *   BR_CODEIN_SOCL_InitDefault 0x021E2F98 thumb ov183
 *   BR_CODEIN_GetMenuCallbacks 0x021E300C thumb ov183
 *   BR_CODEIN_HitTestOptionLeft 0x021E31E8 thumb ov183
 *   BR_CODEIN_HitTestOptionRight 0x021E3228 thumb ov183
 *   GDS_RAP_SaveVideoSeq 0x021D7540 thumb ov125
 *   d_021E3910 0x021E3910 data a4
 *   d_021E3928 0x021E3928 data a4
 */
#include "br_codein_types.h"
#include "soc_types.h"

struct BrProcQuery;
struct Proc;
struct Proc;
struct PrintSys;
struct Obj;
struct Node;
struct BattleRecSave;
struct Big;
struct Actor;
struct Blk1AC;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct BigObj;
struct Bmp;
struct CharBuf;
struct State;
struct StrObj;
struct Strbuf;
struct Struct36;
struct Sub0204A9D0;
struct Sub0200852CObj;
struct Object;
struct Coordinates;
struct Vec2;
struct PtS;
struct Grid;
struct Sys;
struct Param;
struct Ctx;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long long u64;
typedef signed short s16;

typedef struct {char pad[0x4c];char saved[0x18];int count;void *ptr;} CodeinWindowState;

typedef struct CodeinProcEntry CodeinProcEntry;

typedef struct {u8 x,y,w,h;u32 message;} CodeinMenuItem;

typedef struct U16Vec U16Vec;

typedef struct MsgBank MsgBank;

typedef struct WordSet WordSet;

typedef struct GdsProfile GdsProfile;

typedef struct GdsRecord GdsRecord;

typedef struct RecGet RecGet;

typedef struct {s16 x,y,z;u8 a,b;} Position;

typedef struct {s16 x,y;} Point16;

typedef signed int     s32;


typedef struct Triple { int a,b,c; } Triple;



typedef struct Point { u32 x,y; } Point;





typedef struct Rect { u32 x0, y0, x1, y1; } Rect;




typedef u16 Row[3];




struct CodeinRecordData { u8 pad[0x1718]; int count; u32 selected; };

typedef struct {void *text;int id;} Item;

typedef struct {Item *list;u32 count;u8 x,y,width,height,palette,bg,spacing,pad;int mode;char *resources;u32 manager,cursor,other;u16 *selection;} CodeinListMenuConfig;

typedef struct {u32 words[10];} CfgTpl;

typedef struct BmpMenuWorkSlot { u32 a,b; } BmpMenuWorkSlot;

typedef struct {BmpMenuWorkSlot *list;void *view;void *words;u32 c,d;u8 pad[0xbc];char *base;} Menu;

typedef signed char s8;

struct CodeinSearchState { u8 pad[0x14]; u16 shared0,shared1; u16 indices[5][6]; int cursor; void *sprites[5][6]; char *source; };

struct Pos { u16 x; short y; u16 z; u8 a,b; };

struct Entries { u32 species[6],form[6],gender[6]; };

struct Rec { u32 w[9]; };

struct Sub { u8 pad[16]; u32 size,data; };

typedef int (*Method)(char *,int *);

struct Methods { Method init,update,finish; };


typedef struct Rec6 { u8 x,y,id,pad; u16 file; } Rec6;

struct Rec8 { u8 a,b,c,d; void *value; };


typedef struct {u16 a,b,c;u8 flag,pad;} Params;



typedef struct Record { u8 a, b, c, d; int value; } Record;


struct CodeinWorkData { void *object, *profile, *textWin, *printQue; u16 heap; u16 pad; void *handles; };


struct Object { int capacity; int entries[4]; int unused; void *vector; void *actorSys; void *res; void *handles; };

struct PosParams {s16 x,y,a,b,z;u8 mode,flag;};

struct Coordinates { u8 pad[0x298]; u8 rect[32][4]; };

typedef struct {s16 a,b,x,y;} Coords;

typedef struct {void *handle; short x,y; unsigned data,zero; u8 a,b; u16 c; unsigned d;} CodeinProfileDescriptor;

typedef struct {char pad0[0x300]; struct Sys *oamSys; struct Grid *grid[1];} Object;

typedef enum {INDEX_0,INDEX_1} Index;

typedef struct 
{
  int v[3];
} CodeinProfileRow;

typedef struct 
{
  CodeinProfileRow row[2];
} CodeinProfileTable;

typedef struct 
{
  char pad[0x328];
  int count;
} CodeinProfileState;



typedef struct {int tag,value,mode,handle; char rest[12];} CodeinProfileRecord;

typedef struct {short a,b,c,d;} CodeinTableRow;

typedef struct {CodeinTableRow row[12];} CodeinTable;



typedef struct { u32 index; u8 f4[8]; char *owner; u8 f10[8]; u32 base; } Input;

typedef struct { u8 a,b,c,d; void *value; } Rec;

typedef signed long long s64;

typedef enum { STATE_ZERO=0, STATE_TWELVE=12 } CodeinSoclState;


typedef struct {u32 fields[7];Point request;} Arg;





typedef union CodeinProfileConfig {u64 wide;Point pair;} CodeinProfileConfig;



typedef struct Table {int head[4];SOCLResource pair;} Table;

extern unsigned BR_PROC_SYS_GetSlotId(struct BrProcQuery *p);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void * MI_CpuFill8(void *,int,unsigned);
extern u32 PRINTSYS_QUE_Create(void *p);
extern char *BR_UTIL_CreateHandles(unsigned owner, char *resources, int index, int heap);
extern void BR_UTIL_SetHandlesAnimSeq(u8 *p, u32 value);
extern int *BR_UTIL_CreateTask(int payload, int callback, u32 heap);
extern void BR_UTIL_DeleteHandles(char *);
extern void BR_UTIL_DeleteTask(void *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void PROCSYS_FreeProcWork(struct Proc *);
extern void BR_UTIL_RunTask(u8 *p);
extern void BR_UTIL_RunHandles(char *);
extern int BR_UTIL_IsTaskIdle(int *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern void BR_UTIL_StartEffect(void *, unsigned, const Point *);
extern int BR_UTIL_IsEffectDone(char *);
extern void *BR_UTIL_Create(unsigned short,unsigned,unsigned short,unsigned short,unsigned char,unsigned char,void *,unsigned short);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,unsigned short);
extern void BR_FADE_StartTimed(char *p, u32 index, u32 a, u32 b, u32 c);
extern int BR_FADE_GetResult(int *);
extern void BR_UTIL_Delete(u8 *p);
extern void BR_SIDEBAR_StartBounce(char *p);
extern int BR_UTIL_FlushText(u8 *p);
extern void BR_PROC_SYS_PushEntry(unsigned *,unsigned);
extern int *BR_UTIL_SetTaskStep(int *p, int v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void BG_SYS_PushTile(u32 index);
extern int TOUCHPANEL_GetTrg(void);
extern void BR_SIDEBAR_StartSlide(char *p);
extern void BR_PROC_SYS_PopEntry(unsigned *ctx);
extern void BR_SIDEBAR_ResetPositions(char *p);
extern void BR_SIDEBAR_StartWobble(char *p);
extern int BR_UTIL_ClearTaskStep(int *a);
extern void BR_RES_ReleaseUiPalette(int *,int);
extern void BR_RES_LoadUiPalette(char *p, unsigned i, unsigned heap);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern struct Obj *BR_BTN_Create(int a, int b, int c, int d, int e, int f, u32 heap);
extern void BR_FADE_SetBlendLevel(int,int,int);
extern void BR_FADE_Start(int,int,int,int);
extern int BR_BTN_GetPressed(char *),BR_BTN_GetResultValue(char *);
extern void BR_BTN_UpdatePrint(char *);
extern int BR_BTN_GetPlacement(char *,int *,int *);
extern int BR_RES_GetPalSet(char *),BR_RES_GetCurrentSetParam(char *);
extern void BR_RES_SetPalSet(char *,int),BR_FADE_SetBlendColor(int *,int);
extern u32 TOUCHPANEL_GetPointTrg(u32 *,u32 *);
extern void *GFL_USE_AddMainTask(void (*)(void),void *,int);
extern void TCB_DeleteTask(struct Node *n);
extern void BR_RES_LoadFadePalettes(char *p, void *owner, unsigned short heap);
extern void * BMP_OAM_CreateSys(unsigned,void *);
extern char * BATTLE_REC_GetHeader(void);
extern struct BattleRecSave *BATTLE_REC_GetWork(void);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
extern void BR_UTIL_DeleteTextWin(void *,int);
extern void BMP_OAM_DeleteSys(void *p);
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern int BR_NET_HandleNetError(char *p);
extern void BR_PROC_SYS_FlushWindows(void *);
extern int BR_UTIL_MainProfileScreen(u8 *p);
extern void BR_UTIL_FlushWindow(void *);
extern int BR_BTN_HitTestWithSound(unsigned int *obj, int x, int y);
extern void BR_PROC_SYS_SetupWindow(CodeinWindowState *);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void BR_NET_StartRequest(char *p, int kind, const int *values);
extern int BR_NET_IsIdle(char *p);
extern int BR_NET_PollErrorMessage(char *p, int *out);
extern int BR_NET_GetVideoReply(char *,int,int *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void BATTLE_REC_SetData(const void *,const void *,const void *,unsigned int);
extern int GFL_USE_IsSeqPlaying(u32 a);
extern int GDS_RAP_SaveVideoSecured(void *a, int x, u16 *state, u16 *b, u16 c);
extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);
extern void BATTLE_REC_DecodeWork(void);
extern int GAME_DATA_SaveStart(int),GAME_DATA_SaveMain(u8 *);
extern int BR_RES_GetWordSet(char *);
extern void BR_UTIL_SetTextLayout(u8 *p, u32 a, u32 b, u32 c);
extern void BR_UTIL_SetTextFromBuffer(char *,void *,void *,u16);
extern struct U16Vec *STRBUF_Create(u32 capacity, u16 heapId);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void *GDS_PROFILE_CreateNameStr(const void *,u32);
extern void *GDS_PROFILE_ExportRecord(struct GdsProfile *p, struct GdsRecord *out, u32 tag);
extern u32 GDS_PROFILE_GetEggFlag(struct RecGet *p);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern int POKE_TOOL_GetIconPaletteArcId(void),POKE_TOOL_GetIconCellArcId(void),POKE_TOOL_GetIconCellEntryId(void);
extern int CLACT_RegisterPaletteCompressed(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32),POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void ARC_TOOL_DeleteHandle(void *);
extern char *BR_UTIL_CreateProfileScreen(void *prof, char *q, void *a2, void *a3, int mode, u16 heap);
extern void BR_UTIL_DeleteProfileScreen(int *);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void BR_RES_ApplyBgSet(int a, unsigned mode);
extern void BR_RES_LoadSprite(char *,u32,u32);
extern int BR_RES_GetSprite(void *,int,Triple *);
extern void *BR_BTN_CreateFromMessage(void *,int,int,int,int,int,int,int,void *,u16);
extern void BR_BTN_DeleteObject(char *p);
extern void BR_RES_ReleaseSprite(char *p, unsigned i);
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern u16 BSUBWAY_SCOREDATA_GetBattlePoints(struct Blk1AC *p);
extern u32 BSUBWAY_SCOREDATA_HasCleared(struct Blk1AC *p, u32 i);
extern u16 BSUBWAY_SCOREDATA_GetWinCount(struct Blk1AC *p, u32 i);
extern u16 BSUBWAY_SCOREDATA_GetMaxWinCount(struct Blk1AC *p, u32 i);
extern u8 BSUBWAY_SCOREDATA_GetLevel(struct Blk1AC *p);
extern u32 BSUBWAY_SCOREDATA_AccessFlag(struct Blk1AC *p, s32 i, u32 op);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *,int);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u16 BSUBWAY_SAVEDATA_GetStat(Row *,int,int);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void WORDSET_SetSlotMyStatus(struct WordSet *,u32,void *);
extern void MSGDATA_ReadString(struct MsgBank *,u32,void *);
extern int BR_NET_GetSearchResultsForRanking(char *p, void *buffer, int count, int *out);
extern int BR_NET_GetSearchResultsForNewest(char *p, void *buffer, int count, int *out);
extern int BR_NET_GetSearchResults(char *p, void *buffer, int count, int *out);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern BmpMenuWorkSlot *BMP_MENUWORK_Create(u32,u32);
extern void *BR_UTIL_CreateListMenu(const CodeinListMenuConfig *,u16);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern u32 PRINTSYS_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void BR_UTIL_SetListItemBitmap(u8 *p, u16 i, u32 v);
extern void BR_UTIL_RefreshList(char *p);
extern int BR_UTIL_GetListMenuField(char *p, unsigned field);
extern u32 BR_UTIL_GetListItemBitmap(u8 *p, u16 i);
extern void BMP_Delete(struct Bmp *p);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void BR_UTIL_DeleteListMenu(char *p);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void BR_UTIL_MainListMenu(char *p);
extern int BR_UTIL_GetListMenuHitId(char *);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int POKE_TOOL_GetIconCellArcId(void);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern u32 CLACT_GetActorPaletteOffset(struct Obj *o);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);
extern void *ARC_UTIL_LoadScreenDataFromHandle(void *,u32,u32,u32,u16);
extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);
extern void CLACT_GetCharacterProxy(u32,struct Rec *);
extern u32 GFL_HEAP_Free(void *p);
extern u8 MYSTATUS_GetNation(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetArea(const struct Sub0200852CObj *obj);
extern int BR_BTN_TestHitBox(u32 *p, int a1, int a2);
extern void BMP_MENUWORK_AddMsgItem(BmpMenuWorkSlot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern char *BR_POKESEARCH_Create(void *, void *, int, int, int, int, int, u16);
extern void BR_POKESEARCH_Open(char *);
extern unsigned BR_POKESEARCH_UpdatePrint(char *p);
extern void BR_POKESEARCH_Close(char *p);
extern void BR_POKESEARCH_Destroy(char *p);
extern int BR_POKESEARCH_Main(char *);
extern int BR_POKESEARCH_GetResult(int *, u16 *);
extern void BMP_MENUWORK_AddStrItem(BmpMenuWorkSlot *table, u32 a, u32 b, u32 tag);
extern u8 NATION_AREA_GetAreaCount(u32);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);
extern void WORDSET_SetSlotFromKeyedMessage(struct WordSet *p, u32 i, u32 a, u32 n);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BUTTON_MAN_Delete(void *);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void BMP_OAM_Delete(struct Grid *);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_UploadChars(struct Obj *o);
extern void BMP_OAM_SetObjMode(u8 *g, u32 a);
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void CLACT_SetActorScale(struct Obj *dst, Point *src);
extern void STRBUF_Append(struct U16Vec *dst, struct U16Vec *src);
extern void WORDSET_FormatNumber(void *, int, u32, u32, u32);
extern void *BUTTON_MAN_Create(u8 *,int,int,int);
extern u32 BATTLE_REC_Load(void *a, u16 heap, u32 *dp, u32 id);
extern u32 BR_NET_GetUploadedDataNumber(u8 *p, unsigned long long *out);
extern void BR_UTIL_SetWindowTextBuf(char *p, void *q, void *text);
extern void GDS_RAP_StartVideoSave(int,int,int);
extern int GDS_RAP_StepVideoSave(char *p, int id);
extern void BR_CODEIN_SOCL_InitDefault(SOCLResource *resource);
extern void BR_CODEIN_GetMenuCallbacks(Point *);
extern int BR_CODEIN_HitTestOptionLeft(char *,int,int),BR_CODEIN_HitTestOptionRight(char *,int,int);
extern int GDS_RAP_SaveVideoSeq(void *a, int x, int mode, u16 *state, u16 *b, u16 c);
int BR_CODEIN_SidebarCreate(int *task, int unused, char *p);
int BR_CODEIN_SidebarDestroy(struct Proc *task,int b,int c,struct CodeinWorkB *p);
int BR_CODEIN_SidebarMain(int a,int b,int c,struct CodeinWorkB *p);
void BR_CODEIN_SidebarStepIntro(int *task,int *state,struct CodeinWorkE *p);
void BR_CODEIN_SidebarStepSlideIn(int *task, int *state, struct CodeinWorkA *p);
void BR_CODEIN_SidebarStepSlideOut(int *task, int *state, struct CodeinWorkA *p);
void BR_CODEIN_SidebarClearStep(int *task);
int BR_CODEIN_ButtonCreate(int *task,int b,char *p);
int BR_CODEIN_ButtonDestroy(struct Proc *task,int b,struct CodeinArgB *q,struct CodeinWorkA *p);
int BR_CODEIN_ButtonMain(int *task,int *state,struct CodeinWorkB *p,struct CodeinArgA *q);
void BR_CODEIN_ButtonLoadFadePalettes(int unused, struct CodeinWorkF *p);
int BR_CODEIN_RecordCreate(int *task,int *state,char *q);
int BR_CODEIN_RecordDestroy(int task,int b,char *q,char *p);
int BR_CODEIN_RecordMain(int a,int b,int c,struct CodeinWorkB *p);
void BR_CODEIN_RecordStepCreateProfile(int a, int b, char *p);
void BR_CODEIN_RecordStepFadeIn(int *task, int *state, struct CodeinWorkA *p);
void BR_CODEIN_RecordStepFadeOut(int *task, int *state, struct CodeinWorkA *p);
void BR_CODEIN_RecordStepDeleteProfile(int *task,int b,char *p);
void BR_CODEIN_RecordStepMenu(int *task,int *state,char *p);
void BR_CODEIN_RecordStepProfileText(int *task,int *state,char *p);
void BR_CODEIN_RecordStepRequest(int *a,int *state,char *p);
void BR_CODEIN_RecordStepReceive(int *a,int *state,char *p);
void BR_CODEIN_RecordStepSave(int *a,int *state,char *p);
void BR_CODEIN_RecordStepConfirm(int *a,int *state,char *p);
void BR_CODEIN_RecordSetupProfile(char *p,char *q);
void BR_CODEIN_RecordSetupActors(char *p,void *manager,void *party,u16 heap);
void BR_CODEIN_RecordCreateProfileScreen(char *p, char *q);
void BR_CODEIN_RecordDeleteProfileScreen(char *p,char *unused);
void BR_CODEIN_RecordDeleteActors(char *p,char *q);
void BR_CODEIN_RecordSetupButtons(char *p,char *q);
void BR_CODEIN_RecordDeleteButtons(char *p, char *q);
void BR_CODEIN_RecordCreateTextWin(char *p, char *unused);
void BR_CODEIN_RecordDeleteTextWin(char *p, char *unused);
void BR_CODEIN_RecordSetupTextWin(char *p, char *q);
void BR_CODEIN_RecordTeardownTextWin(char *p, char *q);
int BR_CODEIN_RecordIsMultiBattle(void *p);
int BR_CODEIN_RecordIsType2(void *p);
int BR_CODEIN_RecordHitProfileToggle(char *p, int a, int b);
int BR_CODEIN_RecordHitRecordPanel(char *p, int a, int b);
int BR_CODEIN_RecordHitOptionLeft(char *p, int a, int b);
int BR_CODEIN_RecordHitOptionRight(char *p, int a, int b);
int BR_CODEIN_ListCreate(void *a, int unused, char *q);
int BR_CODEIN_ListDestroy(struct Proc *a, int unused, char *q, char *p);
int BR_CODEIN_ListMain(void *unused,u32 *state,char *q,char *p);
void BR_CODEIN_ListSetupText(struct CodeinWorkA *p, char *q);
void BR_CODEIN_ListSetupRowA(char *p,char *q);
void BR_CODEIN_ListSetupRowB(char *p,char *q);
void BR_CODEIN_ListSetupRowC(char *p, char *q);
void BR_CODEIN_ListSetupRowD(char *p,char *q);
void BR_CODEIN_ListTeardown(char *p, char *q);
void BR_CODEIN_ListSetupButtons(struct CodeinWorkA *p,char *q);
void BR_CODEIN_ListDeleteButtons(char *p, char *q);
int BR_CODEIN_ListHitButton(char *p, int x, int y);
int BR_CODEIN_ListIsEventA(void *p,char *q);
int BR_CODEIN_ListIsEventB(void *p, void *q);
int BR_CODEIN_ListIsEventC(void *p, void *q);
void BR_CODEIN_ListCreateActor(char *p, void *manager, const char *q, unsigned int value, s16 x, s16 y, u16 heap);
void BR_CODEIN_ListDeleteActor(char *p);
void BR_CODEIN_ListSetActorAnim(char *p, u32 value);
int BR_CODEIN_ResultCreate(void *a, int b, char *q);
int BR_CODEIN_ResultDestroy(void *a, int b, char *q, struct CodeinWorkA *p);
int BR_CODEIN_ResultMain(void *unused,u32 *state,char *q,struct CodeinWorkA *p);
void BR_CODEIN_ResultSetupTextWin(char *p, char *q);
void BR_CODEIN_ResultSetupRowA(struct CodeinWorkA *p,char *q);
void BR_CODEIN_ResultSetupRowB(struct CodeinWorkA *p,char *q);
void BR_CODEIN_ResultSetupRowC(struct CodeinWorkA *p,char *q);
void BR_CODEIN_ResultTeardown(struct CodeinWorkA *p, char *q);
void BR_CODEIN_ResultSetupButtons(char *p,char *q);
void BR_CODEIN_ResultDeleteButtons(struct CodeinWorkA *p, char *q);
int BR_CODEIN_ResultHitButton(struct CodeinWorkA *p, int x, int y);
int BR_CODEIN_StatCreate(void *a, int b, char *q);
int BR_CODEIN_StatDestroy(void *a, int b, struct CodeinArgA *q, struct CodeinWorkD *p);
int BR_CODEIN_StatMain(int a, int b, int c, struct CodeinWorkD *p);
void BR_CODEIN_StatSetup(int *task,int *state,struct CodeinWorkD *p);
void BR_CODEIN_StatTeardown(void *a, int b, struct CodeinWorkD *p);
void BR_CODEIN_StatStepFadeIn(int *a, int *state, struct CodeinWorkD *p);
void BR_CODEIN_StatStepFadeOut(int *p, int *state, struct CodeinArgA *q);
void BR_CODEIN_StatStepMenu(int *task, int *state, char *p);
void BR_CODEIN_SearchStep(int *task,u32 *state,char *p);
void BR_CODEIN_SearchStepText(int *p, int *state, struct CodeinArgA *q);
void BR_CODEIN_SearchStepFade(int *p, int *state, struct CodeinArgA *q);
void BR_CODEIN_SearchCreateList(Menu *p,char *base,char *res,u32 mgr,u32 listParam,u32 tapFx,u16 *sel,u16 heap);
void BR_CODEIN_SearchDeleteList(char *p);
void BR_CODEIN_SearchMainList(char *p, u16 a);
int BR_CODEIN_SearchGetHitId(char *p);
void BR_CODEIN_SearchCreateActor(struct CodeinSearchState *p,u32 mgr,u16 heap);
void BR_CODEIN_SearchDeleteActor(char *p);
void BR_CODEIN_SearchUpdateActor(struct CodeinSearchState *p,int first,short step,u16 heap);
void BR_CODEIN_SearchBuildHeader(int p, char *out);
int BR_CODEIN_SearchHitBox(int x, int y);
int BR_CODEIN_CodeCreate(void *obj, int unused, struct CodeinArgB *q);
int BR_CODEIN_CodeDestroy(void *p, int unused, struct CodeinArgA *q, char *data);
int BR_CODEIN_CodeMain(void *unused,u32 *state,int *q,char *p);
int BR_CODEIN_CodeSetupButtons(struct CodeinWorkA *p,struct CodeinArgA *q);
int BR_CODEIN_CodeDeleteButtons(char *p, struct CodeinArgA *q);
int BR_CODEIN_CodeStepInput(struct CodeinWorkB *p,struct CodeinArgB *q);
int BR_CODEIN_CodeSetupMenu(struct CodeinWorkB *p,struct CodeinArgA *q);
int BR_CODEIN_CodeDeleteMenu(struct CodeinWorkB *p, struct CodeinArgA *q);
int BR_CODEIN_CodeStepMenu(struct CodeinWorkB *p, struct CodeinArgB *q);
void BR_CODEIN_CodeOpenPokeSearch(struct CodeinWorkA *p, struct CodeinArgA *q);
int BR_CODEIN_CodeClosePokeSearch(struct CodeinWorkA *p);
int BR_CODEIN_CodeStepPokeSearch(struct CodeinWorkB *p, struct CodeinArgB *q);
int BR_CODEIN_CodeSetupPokeList(struct CodeinWorkB *p,struct CodeinArgA *q);
int BR_CODEIN_CodeDeletePokeList(struct CodeinWorkB *p, struct CodeinArgA *q);
int BR_CODEIN_CodeStepPokeList(struct CodeinWorkB *p, struct CodeinArgB *q);
void BR_CODEIN_CodeSetupText(struct CodeinWorkA *p, int *q);
void BR_CODEIN_CodeDeleteText(char *p,struct CodeinArgA *q);
void BR_CODEIN_CodeSetMenuText(struct CodeinWorkB *p,struct CodeinArgB *q,int mode);
int BR_CODEIN_CodeHitTestOptions(void);
int BR_CODEIN_ProfileScreenCreate(void *task, int unused, struct CodeinArgA *q);
int BR_CODEIN_ProfileScreenDestroy(void *a, int unused, int *q, void **p);
int BR_CODEIN_ProfileScreenMain(int unused, int *state, int *q, int *p);
char *BR_CODEIN_ProfileCreate(const CfgTpl *src, u16 heap);
void BR_CODEIN_ProfileUpdate(char *p);
int BR_CODEIN_ProfileGetState(char *p);
u64 BR_CODEIN_ProfileGetValue(char *p);
void BR_CODEIN_ProfileDestroy(struct CodeinWorkA *p);
struct Object *BR_CODEIN_ProfileCreateObject(int heap, int n, void *actorSys, void *res, void *handles, int *entries);
void BR_CODEIN_ProfileDestroyObject(struct Object *p);
void BR_CODEIN_ProfileNoop(void);
void BR_CODEIN_ProfileSetupSprite(char *p);
void BR_CODEIN_ProfileDeleteActor(struct CodeinWorkA *p);
void BR_CODEIN_ProfileCreateRecordActors(char *p);
void BR_CODEIN_ProfileCreateMarkerActors(char *p);
void BR_CODEIN_ProfileCreateArrowActors(char *p);
void BR_CODEIN_ProfileSetActorVisible(char *p, int index, int visible);
void BR_CODEIN_ProfileSetActorPos(char *p,int i);
void BR_CODEIN_ProfileAddActorSurfacePos(struct Coordinates *p, int index);
void BR_CODEIN_ProfileUpdateActorAnims(char *p);
int BR_CODEIN_ProfileGetActorIndex(int a, int b);
void BR_CODEIN_ProfileUpdateActorVisible(char *p);
void BR_CODEIN_ProfileSetActorAnimFrame(char *p,int animated);
void BR_CODEIN_ProfileUpdateActorPos(char *p);
void BR_CODEIN_ProfileCreateOam(char *p);
void BR_CODEIN_ProfileDeleteOam(struct CodeinWorkA *p);
void BR_CODEIN_ProfileDeleteBgHandle(char *p);
void BR_CODEIN_ProfileCreateOamObjects(char *p);
void BR_CODEIN_ProfilePrintOamObject(const Object *object,Index index,int x,int y,int unused);
void BR_CODEIN_ProfileSetActorAnim(char *p,int state);
void BR_CODEIN_ProfileInitRecordLayout(CodeinProfileState *p);
void BR_CODEIN_ProfileSetAnimSeq(char *p, int v);
int BR_CODEIN_ProfileCreateAllActors(char *p);
int BR_CODEIN_ProfileReturnTrue(void);
s32 BR_CODEIN_ProfileUpdatePendingAndButtons(char *p);
int BR_CODEIN_ProfileUpdateScrollAnim(char *p);
int BR_CODEIN_ProfileUpdateActorAnim(char *p);
void BR_CODEIN_ProfileBuildAnimName(char *p);
void BR_CODEIN_ProfileApplyRecords(const CodeinProfileRecord *records);
void BR_CODEIN_ProfileCreateButtons(char *p);
void BR_CODEIN_ProfileHandleInput(u32 idx, int arg, char *p);
void BR_CODEIN_ProfileApplyPendingStep(char *p);
void BR_CODEIN_ProfileClear(char *p);
int BR_CODEIN_ProfileFindActorIndex(char *p,int a);
int BR_CODEIN_ProfileFindRecord(const char *p, int a);
int BR_CODEIN_UploadCreate(struct Proc *obj,int unused,char *arg);
int BR_CODEIN_UploadDestroy(struct Proc *a,int b,struct CodeinArgA *q,struct CodeinWorkA *p);
int BR_CODEIN_UploadMain(int a,int b,int c,struct CodeinWorkB *p);
void BR_CODEIN_UploadStepFadeIn(int a,int *state,struct CodeinWorkB *p);
void BR_CODEIN_UploadStepFadeOut(int *a,int *state,struct CodeinWorkB *p);
void BR_CODEIN_UploadStep(int *task,int *state,struct CodeinWorkB *p);
int BR_CODEIN_SaveCreate(struct Proc *obj,int unused,char *arg);
int BR_CODEIN_SaveDestroy(int obj,int b,char *arg,char *p);
int BR_CODEIN_SaveMain(int a,int b,int c,struct CodeinWorkC *p);
void BR_CODEIN_SaveStepFadeIn(int *task,int *state,struct CodeinWorkC *p);
void BR_CODEIN_SaveStepFadeOut(int *task,int *state,struct CodeinWorkC *p);
void BR_CODEIN_SaveStepVideo(int task,int *state,char *p);
void BR_CODEIN_SaveSetupText(char *p,const Input *q);
void BR_CODEIN_SaveDeleteTextWin(char *p, char *res);
void BR_CODEIN_SaveTeardown(char *p,char *q);
int BR_CODEIN_SaveHitOptionLeft(char *p, int a, int b);
int BR_CODEIN_SaveHitOptionRight(char *p, int a, int b);
int BR_CODEIN_SoclCreate(void *obj,int b,char *q);
int BR_CODEIN_SoclDestroy(int obj,int b,int c,char *p);
int BR_CODEIN_SoclMain(int a,int b,int c,struct CodeinWorkD *p);
void BR_CODEIN_SoclStep(int *task,CodeinSoclState *state,char *p);
void BR_CODEIN_MenuStep(int *task,int *state,char *p);
void BR_CODEIN_MenuStepInput(int *task,unsigned *state,char *p);
void BR_CODEIN_MenuStepSave(int *task,unsigned *state,char *p);
void BR_CODEIN_CallAndClearStepFn(char *p, int work, int ctx);
void BR_CODEIN_CallAndClearDestroyFn(char *p,int a,int b);
void BR_CODEIN_CopySoclResource(SOCLResource *p);
void BR_CODEIN_SoclSetupText(char *p, const char *q);
void BR_CODEIN_SoclTeardown(struct CodeinWorkD *p,struct CodeinArgA *q);
extern int d_021E3280[];
extern char d_021E3960[];
extern const CodeinMenuItem d_021E32C8[];
extern const Point16 d_021E32F0[];
extern const Record d_021E32A8[];
extern const Record d_021E3350[];
extern const Record d_021E33C0[];
extern const Record d_021E3400[];
extern const Record d_021E3490[];
extern const Record d_021E338C[];
extern const Record d_021E336C[];
extern const Rect d_021E3440[];
extern const u32 d_021E3358[];
extern const Record d_021E3574[];
extern const Record d_021E3664[];
extern const Record d_021E35D4[];
extern const Record d_021E351C[];
extern const Rect d_021E3534[];
extern const char d_021E3964[];
extern const CfgTpl d_021E3700;
extern const struct Methods d_021E37A8[];
extern const struct Rec6 d_021E3734[];
extern const struct Rec8 d_021E3740[];
extern const CfgTpl d_021E3758;
extern const Rec6 d_021E3728[];
extern const CfgTpl d_021E3780;
extern const Rec6 d_021E372E[];
extern const Record d_021E37D8[];
extern int gSpeciesNameBank;
extern Rect g_021E3808[];
extern char d_021E3968[];
extern char d_021E3974[];
extern char d_021E3978[];
extern const int d_021E3850[];
extern const CodeinProfileTable d_021E3868;
extern const int d_021E3998[],d_021E397C[];
extern const CodeinTable d_021E3880;
extern const Point d_021E38E0;
extern char d_021E39B4[];
extern const Rec d_021E3900[];
extern const Table d_021E3910;
extern const unsigned char d_021E3928[];















int BR_CODEIN_SidebarCreate(int *task, int unused, char *work)
{
    struct CodeinStateA *s;
    void *callback;
    s=PROCSYS_AllocProcWork((struct Proc *)task,0x20,BR_PROC_SYS_GetSlotId(((struct CodeinSidebarArg *)work)->procQuery));
    MI_CpuFill8(s,0,0x20);
    s->work=work;
    s->heapId=BR_PROC_SYS_GetSlotId(((struct CodeinSidebarArg *)work)->procQuery);
    s->printQue=(void *)PRINTSYS_QUE_Create((void *)(s->heapId));
    s->handlesMain=BR_UTIL_CreateHandles((*(int *)&((struct CodeinSidebarArg *)work)->actorSys),(char *)((*(int *)&((struct CodeinSidebarArg *)work)->res)),0,s->heapId);
    s->handlesSub=BR_UTIL_CreateHandles((*(int *)&((struct CodeinSidebarArg *)work)->actorSys),(char *)((*(int *)&((struct CodeinSidebarArg *)work)->res)),1,s->heapId);
    BR_UTIL_SetHandlesAnimSeq(s->handlesMain,1);
    BR_UTIL_SetHandlesAnimSeq(s->handlesSub,1);
    if((*(int *)&((struct CodeinSidebarArg *)work)->mode)==0) callback=BR_CODEIN_SidebarStepIntro;
    else if((*(int *)&((struct CodeinSidebarArg *)work)->mode)==1) callback=BR_CODEIN_SidebarStepSlideIn;
    else callback=BR_CODEIN_SidebarStepSlideOut;
    s->task=BR_UTIL_CreateTask((int)s,(int)callback,s->heapId);
    return 1;
}















int BR_CODEIN_SidebarDestroy(struct Proc *task,int seq,int arg,struct CodeinWorkB *work) { BR_UTIL_DeleteHandles(*(char * *)&work->menuWork); BR_UTIL_DeleteHandles(*(char * *)&work->textWin); PRINTSYS_QUE_Delete((*(void * *)&work->button)); BR_UTIL_DeleteTask((void *)(work->task)); PROCSYS_FreeProcWork(task); return 1; }















int BR_CODEIN_SidebarMain(int proc,int seq,int arg,struct CodeinWorkB *work) { BR_UTIL_RunTask((u8 *)(work->task)); PRINTSYS_QUE_Main(*(struct PrintSys * *)&work->button); BR_UTIL_RunHandles(*(char * *)&work->menuWork); BR_UTIL_RunHandles(*(char * *)&work->textWin); if(BR_UTIL_IsTaskIdle(*(int * *)&work->task)) return 1; return 0; }















/*
 * lever: enum-valued one-bit mask preserves the original call/mask scheduling, as in sibling 021DB594.
 * abi: 02035C60 returns a full word consumed by the original caller's comparison.
 */
void BR_CODEIN_SidebarStepIntro(int *task,int *state,struct CodeinWorkE *work)
{
    int a,b;
    switch(*state) {
    case 0: {Point args;args.x=128;args.y=96;BR_UTIL_StartEffect((void *)(work->fxCenter), 2, &args);GFL_USE_PlaySeDefaultVolume(0x700);*state=1;break;}
    case 1: if(BR_UTIL_IsEffectDone(*(char * *)&work->fxCenter))*state=2;break;
    case 2: {Point args;args.x=128;args.y=-8;BR_UTIL_StartEffect((void *)(work->fxTop), 3, &args);*state=3;break;}
    case 3: if(BR_UTIL_IsEffectDone(*(char * *)&work->fxTop))*state=4;break;
    case 4:
        work->noticeText=BR_UTIL_Create(4,8,16,16,2,14,work->printQue,work->heapId);
        a=BR_RES_GetFont(*(char * *)&((struct CodeinSubA *)(work->ctx))->subFade);
        b=BR_RES_GetMsgData(*(char * *)&((struct CodeinSubA *)(work->ctx))->subFade);
        BR_UTIL_SetTextFromMessage(*(char * *)&work->noticeText,(void *)b,(void *)228,(void *)a,0x440);
        BR_FADE_StartTimed((char *)((*(int *)&((struct CodeinSubA *)(work->ctx))->screenFade)),3,15,1,4);*state=5;break;
    case 5: if(BR_FADE_GetResult(((struct CodeinSubA *)(work->ctx))->screenFade))*state=6;break;
    case 6: BR_FADE_StartTimed((char *)((*(int *)&((struct CodeinSubA *)(work->ctx))->screenFade)),3,15,0,4);*state=7;break;
    case 7: if(BR_FADE_GetResult(((struct CodeinSubA *)(work->ctx))->screenFade))*state=8;break;
    case 8: if(TOUCHPANEL_GetTrg()) {GFL_USE_PlaySeDefaultVolume(0x6ff);BR_UTIL_Delete(work->noticeText);*(int *)&work->noticeText=0;BG_SYS_PushTile(4);*state=9;}break;
    case 9: BR_FADE_StartTimed((char *)((*(int *)&((struct CodeinSubA *)(work->ctx))->screenFade)),3,3,0,48);BR_SIDEBAR_StartBounce((char *)(((struct CodeinSubA *)(work->ctx))->procQuery));*state=10;break;
    case 10: {enum {ONE=1} mask=ONE;if(BR_FADE_GetResult((int *)(((struct CodeinSubA *)(work->ctx))->screenFade))&mask) {BR_UTIL_StartEffect((void *)(work->fxTop), 8, 0);*state=11;}break;}
    case 11: BR_FADE_StartTimed((char *)((*(int *)&((struct CodeinSubA *)(work->ctx))->screenFade)),2,3,1,1);*state=12;break;
    case 12: if(BR_FADE_GetResult(((struct CodeinSubA *)(work->ctx))->screenFade))*state=13;break;
    case 13: if(BR_UTIL_IsEffectDone(*(char * *)&work->fxTop)) {BR_PROC_SYS_PushEntry(*(unsigned * *)&((struct CodeinSubA *)(work->ctx))->res,1);BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_SidebarClearStep);}break;
    }
    if(work->noticeText)BR_UTIL_FlushText(work->noticeText);
}















/*
 * lever: enum mask local materializes one before the call; int mask left nine bytes different
 */
void BR_CODEIN_SidebarStepSlideIn(int *task, int *state, struct CodeinWorkA *work)
{
    switch(*state) {
    case 0: *state=1; break;
    case 1:
        BR_SIDEBAR_StartSlide((char *)(((struct CodeinSubA *)(work->ctx))->procQuery));
        *state=2;
        break;
    case 2:
        if(((*(int *)&work->recordTapFx))++ !=0) {
            (*(int *)&work->recordTapFx)=0;
            BR_FADE_StartTimed((char *)((*(int *)&((struct CodeinSubA *)(work->ctx))->screenFade)),3,3,1,26);
            *state=3;
        }
        break;
    case 3:
    {
        enum { MASK=1 } mask=MASK;
        if(BR_FADE_GetResult(((struct CodeinSubA *)(work->ctx))->screenFade)&mask) *state=4;
        break;
    }
    case 4:
        BR_PROC_SYS_PopEntry((*(void * *)&((struct CodeinSubA *)(work->ctx))->res));
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_SidebarClearStep);
        break;
    }
}















void BR_CODEIN_SidebarStepSlideOut(int *task, int *state, struct CodeinWorkA *work)
{
    switch(*state) {
    case 0:
        BR_FADE_StartTimed((char *)((*(int *)&((struct CodeinSubA *)(work->ctx))->screenFade)),2,3,1,1);
        *state=1;
        break;
    case 1:
        if(BR_FADE_GetResult(((struct CodeinSubA *)(work->ctx))->screenFade)) *state=2;
        break;
    case 2:
        BR_SIDEBAR_ResetPositions((char *)(((struct CodeinSubA *)(work->ctx))->procQuery));
        BR_SIDEBAR_StartWobble((char *)(((struct CodeinSubA *)(work->ctx))->procQuery));
        BR_PROC_SYS_PushEntry((unsigned int *)(((struct CodeinSubA *)(work->ctx))->res),1);
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_SidebarClearStep);
        break;
    }
}















void BR_CODEIN_SidebarClearStep(int *task)
{
    BR_UTIL_ClearTaskStep((int *)task);
}















/*
 * extent: two bytes of zero alignment padding at 0x021DB73E
 */
int BR_CODEIN_ButtonCreate(int *task,int seq,char *work)
{
    struct CodeinStateB *s;
    s=PROCSYS_AllocProcWork((struct Proc *)task,24,BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(*(char * *)&((struct CodeinWorkB *)work)->procQuery)));
    MI_CpuFill8(s,0,24);
    s->work=work;
    s->heapId=BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(*(char * *)&((struct CodeinWorkB *)work)->procQuery));
    BR_RES_ReleaseUiPalette(*(int * *)&((struct CodeinWorkB *)work)->textWin,0);
    BR_RES_ReleaseUiPalette(*(int * *)&((struct CodeinWorkB *)work)->textWin,1);
    BR_RES_LoadUiPalette((char *)(*(int * *)&((struct CodeinWorkB *)work)->textWin),0,s->heapId);
    BR_RES_LoadUiPalette((char *)(*(int * *)&((struct CodeinWorkB *)work)->textWin),1,s->heapId);
    if(((struct CodeinWorkB *)work)->task<5) BR_RES_LoadBgGraphics(*(int * *)&((struct CodeinWorkB *)work)->textWin,3,s->heapId);
    else BR_RES_LoadBgGraphics(*(int * *)&((struct CodeinWorkB *)work)->textWin,4,s->heapId);
    s->handles=(int)BR_UTIL_CreateHandles((*(int *)&((struct CodeinWorkB *)work)->menuWork),(char *)(*(int *)&((struct CodeinWorkB *)work)->textWin),1,s->heapId);
    s->button=(int)BR_BTN_Create(((struct CodeinWorkB *)work)->task,(*(int *)&((struct CodeinWorkB *)work)->menuWork),*(int *)&((struct CodeinWorkB *)work)->textWin,((struct CodeinWorkB *)work)->f20,(*(int *)&((struct CodeinWorkB *)work)->categoryText),s->handles,s->heapId);
    if(((struct CodeinWorkB *)work)->button==4) BR_FADE_SetBlendLevel(((struct CodeinWorkB *)work)->screenFade,2,0);
    else BR_FADE_SetBlendLevel(((struct CodeinWorkB *)work)->screenFade,3,0);
    return 1;
}















/*
 * lever: Explicit call arms preserve the original conditional argument branch.
 */
int BR_CODEIN_ButtonDestroy(struct Proc *task,int seq,struct CodeinArgB *arg,struct CodeinWorkA *work) { if(arg->screenFade<5) BR_RES_ApplyBgSet(arg->category,3); else BR_RES_ApplyBgSet(arg->category,4); BR_BTN_Delete(*(u8 * *)&work->oamSys); BR_UTIL_DeleteHandles(*(char * *)&work->printQue); PROCSYS_FreeProcWork(task); return 1; }















/*
 * lever: explicit case-3 call arms preserve the original block shape; ARM9 division helper uses the proven _u32_div_f ABI.
 */
int BR_CODEIN_ButtonMain(int *task,int *state,struct CodeinWorkB *work,struct CodeinArgA *arg)
{
    u32 x,y;
    switch(*state) {
    case 0: BR_FADE_Start(work->screenFade,work->button,3,0);*state=1;break;
    case 1: if(BR_FADE_GetResult(*(int * *)&work->screenFade))*state=2;break;
    case 2:
        if(work->task<=4 && !BR_BTN_GetPressed(*(char * *)&arg->screenFade) && TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(x<8 || x>248) {GFL_USE_PlaySeDefaultVolume(0x703);*state=6;break;}
        }
        BR_BTN_UpdatePrint(*(char * *)&arg->screenFade);
        if(BR_BTN_GetPlacement(*(char * *)&arg->screenFade,(int *)((char *)work+4),(int *)((char *)work+8))) *state=3;
        break;
    case 3:
        if(work->printQue==12)BR_FADE_Start(work->screenFade,4,3,1);
        else BR_FADE_Start(work->screenFade,2,3,1);
        *state=4;break;
    case 4: if(BR_FADE_GetResult(*(int * *)&work->screenFade))*state=5;break;
    case 5:
        switch(BR_BTN_GetPlacement(*(char * *)&arg->screenFade,(int *)((char *)work+4),(int *)((char *)work+8))) {
        case 1: BR_PROC_SYS_PushEntry(*(unsigned * *)&work->procQuery,(unsigned short)work->printQue);return 1;
        case 2: BR_PROC_SYS_PopEntry((*(void * *)&work->procQuery));**(int * *)&work->noticeText=BR_BTN_GetResultValue(*(char * *)&arg->screenFade);return 1;
        }
        break;
    case 6: {
        int v=BR_RES_GetPalSet(*(char * *)&work->textWin);u32 i;
        for(i=0;i<7;i++) {if(v==d_021E3280[i]) {v=d_021E3280[(i+1)%7];break;}}
        BR_RES_SetPalSet(*(char * *)&work->textWin,v);
        BR_FADE_SetBlendColor(*(int * *)&work->screenFade,BR_RES_GetCurrentSetParam(*(char * *)&work->textWin));
        BR_FADE_Start(work->screenFade,3,3,1);*state=7;break;
    }
    case 7: if(BR_FADE_GetResult(*(int * *)&work->screenFade))*state=8;break;
    case 8: (*(void * *)&arg->res)=GFL_USE_AddMainTask((void (*)(void))BR_CODEIN_ButtonLoadFadePalettes,arg,0);arg->uiRes=0;*state=9;break;
    case 9: if(arg->uiRes) {TCB_DeleteTask((*(void * *)&arg->res));*state=10;}break;
    case 10: BR_FADE_Start(work->screenFade,3,3,0);*state=11;break;
    case 11: if(BR_FADE_GetResult(*(int * *)&work->screenFade))*state=2;break;
    }
    BR_UTIL_RunHandles(*(char * *)&arg->actorSys);return 0;
}
















void BR_CODEIN_ButtonLoadFadePalettes(int unused, struct CodeinWorkF *work)
{
    int v = work->tapFx;
    char *q = *(char * *)&work->textWin;

    if (v == 0) {
        BR_RES_LoadFadePalettes((char *)(((struct CodeinArgB *)q)->category), (void *)((*(int *)&((struct CodeinArgB *)q)->gameData)),
                      work->fadeHeapId);
    }
    work->tapFx = 1;
}















/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: shared state-flag store and distinct case-5 null path preserve the original switch layout.
 * blocker-C: copied prior verified Thumb EXACT from BR_CODEIN_SearchBuildHeader.c header, blocker-r2.log; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 */
int BR_CODEIN_RecordCreate(int *task,int *state,char *arg)
{
    char *p,*s;
    int i;
    p=PROCSYS_AllocProcWork((struct Proc *)task,0xe8,BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(*(char **)(arg+0x14))));
    MI_CpuFill8(p,0,0xe8);
    *(unsigned short *)(p+0xb4)=BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(*(char **)(arg+0x14)));
    *(int *)(p+0xb0)=0;
    *(char **)(p+0xd0)=arg;
    *(void **)p=BMP_OAM_CreateSys(*(unsigned short *)(p+0xb4),*(void **)(arg+0x18));
    *(void **)(p+4)=(void *)PRINTSYS_QUE_Create((void *)(*(unsigned short *)(p+0xb4)));
    *(void **)(p+8)=BR_UTIL_CreateTask((int)p,0,*(unsigned short *)(p+0xb4));
    for(i=0;i<2;i++) *(char **)(p+i*4+0xc)=BR_UTIL_CreateHandles(*(unsigned *)(arg+0x18),*(char **)(arg+0x10),i,*(unsigned short *)(p+0xb4));
    switch(*(int *)(*(char **)(p+0xd0)+8)) {
    case 4:
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc4)=s+*(int *)(s+0x171c)*0xc4+0x80;
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(char **)(p+0xc0)=s+*(int *)(s+0x171c)*0xc4;
        *(int *)(p+0xcc)=1;
        if(**(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(*(char **)(p+0xd0)+0x34)) {
            s=*(char **)(*(char **)(p+0xd0)+0x30);
            *(s+*(int *)(s+0x171c)+0x16f8)=1;
        }
        s=*(char **)(*(char **)(p+0xd0)+0x30);
        *(int *)(p+0xc8)=*(unsigned char *)(s+*(int *)(s+0x171c)+0x16f8);
        break;
    case 0:
        *(char **)(p+0xc4)=BATTLE_REC_GetHeader();*(char **)(p+0xc0)=(char *)BATTLE_REC_GetWork();
        *(int *)(p+0xc8)=1;i=0;goto set_cc;
    case 1: case 2: case 3:
        *(char **)(p+0xc4)=BATTLE_REC_GetHeader();*(char **)(p+0xc0)=(char *)BATTLE_REC_GetWork();
        *(int *)(p+0xc8)=BATTLE_REC_GetHeaderParam(*(void **)(p+0xc4),5,0);*(int *)(p+0xcc)=0;break;
    case 5:
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0) {
            *(int *)(p+0xc4)=0;*(int *)(p+0xc0)=0;
        }else {
            *(char **)(p+0xc4)=BATTLE_REC_GetHeader();*(char **)(p+0xc0)=(char *)BATTLE_REC_GetWork();
            *(int *)(p+0xc8)=**(int **)(*(char **)(p+0xd0)+0x3c);
        }
        i=1;
    set_cc:
        *(int *)(p+0xcc)=i;
        break;
    }
    if(*(int *)(*(char **)(p+0xd0)+8)==5) {
        if(*(int *)(*(char **)(p+0xd0)+0x34)==0)BR_UTIL_SetTaskStep(*(int **)(p+8),(int)BR_CODEIN_RecordStepRequest);
        else BR_UTIL_SetTaskStep(*(int **)(p+8),(int)BR_CODEIN_RecordStepCreateProfile);
    }else if((u32)(*(int *)(*(char **)(p+0xd0)+8)-1)<=2 && *(int *)(*(char **)(p+0xd0)+0x34) && **(int **)(*(char **)(p+0xd0)+0x3c) && *(int *)(p+0xc8)==0) {
        BR_UTIL_SetTaskStep(*(int **)(p+8),(int)BR_CODEIN_RecordStepSave);
    }else BR_UTIL_SetTaskStep(*(int **)(p+8),(int)BR_CODEIN_RecordStepCreateProfile);
    return 1;
}















int BR_CODEIN_RecordDestroy(int task,int seq,char *arg,char *work)
{
    int i;
    BR_CODEIN_RecordDeleteProfileScreen(work,arg);
    BR_CODEIN_RecordDeleteActors(work,arg);
    BR_CODEIN_RecordDeleteButtons(work,arg);
    BR_CODEIN_RecordDeleteTextWin(work,arg);
    BR_CODEIN_RecordTeardownTextWin(work,arg);
    ((struct CodeinArgA *)arg)->actorSys=((struct CodeinWorkB *)work)->savedActorSys;
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(1);
    if(((struct CodeinWorkB *)work)->textWin) {
        BR_UTIL_DeleteTextWin(((struct CodeinWorkB *)work)->textWin,((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->res);
        ((struct CodeinWorkB *)work)->textWin=0;
    }
    for(i=0;i<2;i++) BR_UTIL_DeleteHandles(*(char **)(work+i*4+0xc));
    BR_UTIL_DeleteTask((void *)((*(int *)&((struct CodeinWorkB *)work)->recordTask)));
    PRINTSYS_QUE_Delete((*(void * *)&((struct CodeinWorkB *)work)->printQue));
    BMP_OAM_DeleteSys((void *)(((struct CodeinWorkB *)work)->task));
    PROCSYS_FreeProcWork((struct Proc *)task);
    return 1;
}















/*
 * extent: two bytes of zero alignment padding at 0x021DBC66
 */
int BR_CODEIN_RecordMain(int proc,int seq,int arg,struct CodeinWorkB *work)
{
    int i;
    if(GAME_DATA_IsSaving(((struct CodeinSubA *)(work->recordCtx))->gameData)==0 && BR_NET_HandleNetError(((struct CodeinSubA *)(work->recordCtx))->recordNet)==2) {
        BR_PROC_SYS_FlushWindows((*(void * *)&((struct CodeinSubA *)(work->recordCtx))->procQuery));
        return 1;
    }
    BR_UTIL_RunTask(work->recordTask);
    if(BR_UTIL_IsTaskIdle(work->recordTask)) return 1;
    for(i=0;i<2;i++) BR_UTIL_RunHandles(*(void **)((char *)work+i*4+0xc));
    PRINTSYS_QUE_Main((*(void * *)&work->printQue));
    for(i=0;i<2;i++) if(*(void **)((char *)work+i*4+0x28)) BR_UTIL_FlushText(*(void **)((char *)work+i*4+0x28));
    for(i=0;i<5;i++) if(*(void **)((char *)work+i*4+0x30)) BR_UTIL_FlushText(*(void **)((char *)work+i*4+0x30));
    if((*(void * *)&work->profileScreen)) BR_UTIL_MainProfileScreen((*(void * *)&work->profileScreen));
    if(work->textWin) BR_UTIL_FlushWindow(work->textWin);
    return 0;
}














/*
 * Flush the object, dispatch on the p+0xB0 flag, then chain to 0x21FD73C.
 */
void BR_CODEIN_RecordStepCreateProfile(int task, int b, char *work)
{
    BR_CODEIN_RecordSetupButtons(work, (char *)((*(int *)&((struct CodeinWorkA *)work)->recordCtx)));
    if (((struct CodeinWorkA *)work)->profileScreenShown != 0)
        BR_CODEIN_RecordCreateProfileScreen(work, (char *)((*(int *)&((struct CodeinWorkA *)work)->recordCtx)));
    else
        BR_CODEIN_RecordSetupProfile(work, (char *)((*(int *)&((struct CodeinWorkA *)work)->recordCtx)));
    BR_UTIL_SetTaskStep((int *)task, (int)BR_CODEIN_RecordStepFadeIn);
}













void BR_CODEIN_RecordStepFadeIn(int *task, int *state, struct CodeinWorkA *work)
{
    switch(*state) {
    case 0:
        BR_FADE_Start((*(int *)&((struct CodeinSubA *)(work->recordCtx))->subFade),2,3,0);
        *state=1;
        break;
    case 1:
        if(BR_FADE_GetResult(((struct CodeinSubA *)(work->recordCtx))->subFade)) *state=2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepMenu);
        break;
    }
}













void BR_CODEIN_RecordStepFadeOut(int *task, int *state, struct CodeinWorkA *work)
{
    switch(*state) {
    case 0:
        BR_FADE_Start((*(int *)&((struct CodeinSubA *)(work->recordCtx))->subFade),2,3,1);
        *state=1;
        break;
    case 1:
        if(BR_FADE_GetResult(((struct CodeinSubA *)(work->recordCtx))->subFade)) *state=2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepDeleteProfile);
        break;
    }
}












void BR_CODEIN_RecordStepDeleteProfile(int *task,int b,char *work) { if(((struct CodeinWorkB *)work)->profileScreenShown) BR_CODEIN_RecordDeleteProfileScreen(work,((struct CodeinWorkB *)work)->recordCtx); else BR_CODEIN_RecordDeleteActors(work,((struct CodeinWorkB *)work)->recordCtx); BR_CODEIN_RecordDeleteButtons(work,((struct CodeinWorkB *)work)->recordCtx); BR_UTIL_ClearTaskStep(task); }












/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * lever: decode each callback literal from its actual PC-relative pool slot; repeated shared loads obscure distinct callback targets.
 * blocker-C: copied prior verified Thumb EXACT from BR_CODEIN_SearchBuildHeader.c header, blocker-r2.log; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 */
void BR_CODEIN_RecordStepMenu(int *task,int *state,char *work)
{
    u32 x,y;
    if(TOUCHPANEL_GetPointTrg(&x,&y)) {
        if(BR_CODEIN_RecordHitProfileToggle(work,x,y)) {
            *(int *)(work+0xb0)^=1;
            BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepProfileText);
        }
        if(BR_BTN_HitTestWithSound((unsigned int *)(*(int *)(work+0x1c)),x,y)) {
            Point args;
            args.x=x;args.y=y;
            BR_UTIL_StartEffect((void *)(*(int *)(work+0x10)), 1, &args);
            **(int **)(work+0xd0)=0;
            BR_PROC_SYS_PopEntry(*(void **)(*(char **)(work+0xd0)+0x14));
            BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepFadeOut);
        }
        if(*(int *)(work+0x20) && BR_BTN_HitTestWithSound((unsigned int *)(*(int *)(work+0x20)),x,y)) {
            Point args;
            args.x=x;args.y=y;
            BR_UTIL_StartEffect((void *)(*(int *)(work+0x10)), 1, &args);
            BR_PROC_SYS_PushEntry(*(unsigned **)(*(char **)(work+0xd0)+0x14),10);
            *(u64 *)(*(char **)(work+0xd0)+0x1c)=BATTLE_REC_GetHeaderParam(*(void **)(work+0xc4),4,0);
            BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepFadeOut);
        }
        if(BR_CODEIN_RecordHitRecordPanel(work,x,y)) {
            if((u32)(*(u32 *)(*(char **)(work+0xd0)+8)-4)<=1)BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepReceive);
            else if(*(int *)(work+0xc8)==0)BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepConfirm);
            else {
                **(int **)(work+0xd0)=1;
                BR_PROC_SYS_SetupWindow((CodeinWindowState *)(*(CodeinWindowState **)(*(char **)(work+0xd0)+0x14)));
                BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepFadeOut);
            }
        }
    }
}












void BR_CODEIN_RecordStepProfileText(int *task,int *state,char *work)
{
    int a,b;
    switch(*state) {
    case 0:
        BR_FADE_Start((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade),2,1,1);
        (*state)++;break;
    case 1:
        if(BR_FADE_GetResult(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade))(*state)++;
        break;
    case 2:
        a=BR_RES_GetFont(*(char * *)&((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->res);
        b=BR_RES_GetMsgData(*(char * *)&((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->res);
        if(((struct CodeinWorkB *)work)->profileScreenShown) {
            BR_CODEIN_RecordDeleteActors(work,((struct CodeinWorkB *)work)->recordCtx);
            BR_UTIL_SetTextFromMessage(*(char * *)&((struct CodeinWorkB *)work)->noticeText,(void *)b,(void *)0x72,(void *)a,0x3da0);
            BR_CODEIN_RecordCreateProfileScreen(work,((struct CodeinWorkB *)work)->recordCtx);
        }else{
            BR_CODEIN_RecordDeleteProfileScreen(work,((struct CodeinWorkB *)work)->recordCtx);
            BR_UTIL_SetTextFromMessage(*(char * *)&((struct CodeinWorkB *)work)->noticeText,(void *)b,(void *)0x71,(void *)a,0x3da0);
            BR_CODEIN_RecordSetupProfile(work,(char *)(*(int *)&((struct CodeinWorkB *)work)->recordCtx));
        }
        BR_FADE_Start((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade),2,1,0);
        (*state)++;break;
    case 3:
        if(BR_FADE_GetResult(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade))BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepMenu);
        break;
    }
}











/*
 * note 2026-10-05: shape copied from matched twin BR_CODEIN_RecordStepReceive.c (same state machine, same callees). v1 was 4 bytes off (stack slots of source and index swapped); declaring source before index fixed it. Older draft docs/notes/pkt_ov183_021DBFB0.c.txt (167 B off) superseded.
 */
void BR_CODEIN_RecordStepRequest(int *task,int *state,char *work)
{
    u64 t;
    int message;
    char *source;
    int index;
    u32 x,y;
    Point args;
    switch(*state) {
    case 0:
        BR_CODEIN_RecordCreateTextWin(work,*(char **)(work+0xd0));
        BR_UTIL_SetWindowText(*(void **)(work+0x18),(char *)(*(int *)(*(char **)(work+0xd0)+0x10)),(void *)0x14b);*state=1;break;
    case 1: BR_FADE_Start((int)(*(int **)(*(char **)(work+0xd0)+12)),2,3,0);*state=2;break;
    case 2: if(BR_FADE_GetResult(*(int **)(*(char **)(work+0xd0)+12))) *state=3;break;
    case 3:
        MI_CpuFill8(&t,0,8);
        t=*(u64 *)(*(char **)(work+0xd0)+0x1c);
        BR_NET_StartRequest(*(void **)(*(char **)(work+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(work+0xbc)=0;*state=4;break;
    case 4:
        ++*(int *)(work+0xbc);
        if(BR_NET_IsIdle(*(void **)(*(char **)(work+0xd0)+0x24)) && *(u32 *)(work+0xbc)>96) {
            BR_UTIL_StartEffect((void *)(*(int *)(work+12)), 0, 0);*state=5;
        }
        break;
    case 5:
        if(!BR_NET_PollErrorMessage(*(void **)(*(char **)(work+0xd0)+0x24),&message)) {
            if(BR_NET_GetVideoReply(*(char **)(*(char **)(work+0xd0)+0x24),(int)&source,&index)) {
                *(char **)(work+0xc0)=source;
                *(char **)(work+0xc4)=source+0x80;*state=6;
            } else {
                BR_UTIL_SetWindowText(*(void **)(work+0x18),(char *)(*(int *)(*(char **)(work+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            BR_UTIL_SetWindowText(*(void **)(work+0x18),(char *)(*(int *)(*(char **)(work+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);args.x=x;args.y=y;
            BR_UTIL_StartEffect((void *)(*(int *)(work+0x10)), 1, &args);GFL_USE_PlaySeDefaultVolume(0x703);
            BR_PROC_SYS_PopEntry((unsigned int *)(*(CodeinProcEntry **)(*(char **)(work+0xd0)+0x14)));*state=12;
        }
        break;
    case 6: BR_FADE_Start((int)(*(int **)(*(char **)(work+0xd0)+12)),2,3,1);*state=7;break;
    case 7:
        if(BR_FADE_GetResult(*(int **)(*(char **)(work+0xd0)+12))) {
            BR_CODEIN_RecordDeleteTextWin(work,*(char **)(work+0xd0));
            BR_CODEIN_RecordSetupButtons(work,*(char **)(work+0xd0));
            BR_CODEIN_RecordSetupProfile(work,*(char **)(work+0xd0));*state=8;
        }
        break;
    case 8: BR_FADE_Start((int)(*(int **)(*(char **)(work+0xd0)+12)),2,3,0);*state=9;break;
    case 9: if(BR_FADE_GetResult(*(int **)(*(char **)(work+0xd0)+12))) *state=10;break;
    case 10: BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepMenu);break;
    case 12: BR_FADE_Start((int)(*(int **)(*(char **)(work+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(BR_FADE_GetResult(*(int **)(*(char **)(work+0xd0)+12))) *state=14;break;
    case 14: BR_CODEIN_RecordDeleteTextWin(work,*(char **)(work+0xd0));BR_UTIL_ClearTaskStep((int *)task);break;
    }
}











/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * diagnostic: ov186 0x021FF648 +013C resolved through a sibling's new shard in the TU; only ARM9 remains. TU --suggest-split leaves caller out.
 * blocker-C: prior verified Thumb EXACT from BR_CODEIN_SearchBuildHeader.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * abi: B938 retains caller-loaded r3; DD0AC/DD0F4 retain caller-loaded r1; 35C60 return is consumed.
 */
void BR_CODEIN_RecordStepReceive(int *task,int *state,char *work)
{
    u64 t;
    int message;
    int index;
    char *source;
    u32 x,y;
    Point args;
    switch(*state) {
    case 0: BR_FADE_Start((int)(*(int **)(*(char **)(work+0xd0)+12)),2,3,1);*state=1;break;
    case 1: if(BR_FADE_GetResult(*(int **)(*(char **)(work+0xd0)+12))) *state=2;break;
    case 2:
        if(*(int *)(work+0xb0)) BR_CODEIN_RecordDeleteProfileScreen(work,*(char **)(work+0xd0));
        else BR_CODEIN_RecordDeleteActors(work,*(char **)(work+0xd0));
        BR_CODEIN_RecordDeleteButtons(work,*(char **)(work+0xd0));
        BR_CODEIN_RecordCreateTextWin(work,*(char **)(work+0xd0));
        BR_UTIL_SetWindowText(*(void **)(work+0x18),(char *)(*(int *)(*(char **)(work+0xd0)+0x10)),(void *)0x14b);
        *state=3;break;
    case 3: BR_FADE_Start((int)(*(int **)(*(char **)(work+0xd0)+12)),2,3,0);*state=4;break;
    case 4: if(BR_FADE_GetResult(*(int **)(*(char **)(work+0xd0)+12))) *state=5;break;
    case 5:
        MI_CpuFill8(&t,0,8);
        t=BATTLE_REC_GetHeaderParam(*(void **)(work+0xc4),4,0);
        BR_NET_StartRequest(*(void **)(*(char **)(work+0xd0)+0x24),3,(const int *)(&t));
        *(int *)(work+0xbc)=0;*state=6;break;
    case 6:
        ++*(int *)(work+0xbc);
        if(BR_NET_IsIdle(*(void **)(*(char **)(work+0xd0)+0x24)) && *(u32 *)(work+0xbc)>96) {
            BR_UTIL_StartEffect((void *)(*(int *)(work+12)), 0, 0);*state=7;
        }
        break;
    case 7:
        if(!BR_NET_PollErrorMessage(*(void **)(*(char **)(work+0xd0)+0x24),&message)) {
            if(BR_NET_GetVideoReply(*(char **)(*(char **)(work+0xd0)+0x24),(int)&source,&index)) {
                BATTLE_REC_SetData(source,source+0x80,source+0xc4,(unsigned int)GAME_DATA_GetSaveControl(*(void **)(*(char **)(work+0xd0)+0x28)));
                **(long long **)(*(char **)(work+0xd0)+0x2c)=index;
                **(int **)(work+0xd0)=1;
                BR_PROC_SYS_SetupWindow((CodeinWindowState *)(*(CodeinProcEntry **)(*(char **)(work+0xd0)+0x14)));*state=8;
            } else {
                BR_UTIL_SetWindowText(*(void **)(work+0x18),(char *)(*(int *)(*(char **)(work+0xd0)+0x10)),(void *)0x114);*state=11;
            }
        } else {
            BR_UTIL_SetWindowText(*(void **)(work+0x18),(char *)(*(int *)(*(char **)(work+0xd0)+0x10)),(void *)message);*state=11;
        }
        break;
    case 11:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);args.x=x;args.y=y;
            BR_UTIL_StartEffect((void *)(*(int *)(work+0x10)), 1, &args);GFL_USE_PlaySeDefaultVolume(0x703);*state=12;
        }
        break;
    case 8: BR_FADE_Start((int)(*(int **)(*(char **)(work+0xd0)+12)),2,3,1);*state=9;break;
    case 9: if(BR_FADE_GetResult(*(int **)(*(char **)(work+0xd0)+12))) *state=10;break;
    case 10:
        if(!GFL_USE_IsSeqPlaying(0x701)) {BR_CODEIN_RecordDeleteTextWin(work,*(char **)(work+0xd0));BR_UTIL_ClearTaskStep((int *)(*(int *)(work+8)));}
        break;
    case 12: BR_FADE_Start((int)(*(int **)(*(char **)(work+0xd0)+12)),2,3,1);*state=13;break;
    case 13: if(BR_FADE_GetResult(*(int **)(*(char **)(work+0xd0)+12))) *state=14;break;
    case 14: BR_CODEIN_RecordDeleteTextWin(work,*(char **)(work+0xd0));BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepCreateProfile);break;
    }
}











/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-C: prior verified Thumb EXACT from BR_CODEIN_SearchBuildHeader.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * abi: DD0AC/DD0F4 keep the visibly loaded second descriptor argument despite body using only the first.
 */
void BR_CODEIN_RecordStepSave(int *task,int *state,char *work)
{
    switch(*state) {
    case 0:
        BR_CODEIN_RecordCreateTextWin(work,*(char **)(work+0xd0));
        BR_UTIL_SetWindowText(*(void **)(work+0x18),(char *)(*(int *)(*(char **)(work+0xd0)+0x10)),(void *)0x152);
        BR_FADE_Start((int)(*(int **)(*(char **)(work+0xd0)+12)),2,3,0);
        *state=1;break;
    case 1: if(BR_FADE_GetResult(*(int **)(*(char **)(work+0xd0)+12))) *state=2;break;
    case 2: *state=3;break;
    case 3: *(u16 *)(work+0xb6)=0;*(u16 *)(work+0xb8)=0;*state=4;break;
    case 4:
        if(*(int *)(*(char **)(work+0xd0)+8)>3) GF_PANIC_Fail(d_021E3960,0,d_021E3960);
        if(GDS_RAP_SaveVideoSecured((void *)(*(int *)(*(char **)(work+0xd0)+0x28)),*(int *)(*(char **)(work+0xd0)+8),(u16 *)(work+0xb6),(u16 *)(work+0xb8),*(u16 *)(work+0xb4))==2) {
            BATTLE_REC_DecodeWork();
            *(int *)(work+0xc8)=(int)BATTLE_REC_GetHeaderParam(*(void **)(work+0xc4),5,0);
            *state=5;
        }
        break;
    case 5: BR_FADE_Start((int)(*(int **)(*(char **)(work+0xd0)+12)),2,3,1);*state=6;break;
    case 6: if(BR_FADE_GetResult(*(int **)(*(char **)(work+0xd0)+12))) *state=7;break;
    case 7: BR_CODEIN_RecordDeleteTextWin(work,*(char **)(work+0xd0));BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepCreateProfile);break;
    }
}










/*
 * abi: DD0AC/DD0F4 retain caller-loaded r1.
 */
void BR_CODEIN_RecordStepConfirm(int *task,int *state,char *work)
{
    u32 x,y;
    switch(*state) {
    case 0: BR_FADE_Start((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade),2,3,1);*state=1;break;
    case 1: if(BR_FADE_GetResult(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade)) *state=2;break;
    case 2:
        if(((struct CodeinWorkB *)work)->profileScreenShown) BR_CODEIN_RecordDeleteProfileScreen(work,((struct CodeinWorkB *)work)->recordCtx);
        else BR_CODEIN_RecordDeleteActors(work,((struct CodeinWorkB *)work)->recordCtx);
        BR_CODEIN_RecordDeleteButtons(work,((struct CodeinWorkB *)work)->recordCtx);BR_CODEIN_RecordSetupTextWin(work,((struct CodeinWorkB *)work)->recordCtx);*state=3;break;
    case 3: BR_FADE_Start((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade),2,3,0);++*state;break;
    case 4: if(BR_FADE_GetResult(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade)) ++*state;break;
    case 5: ++*state;break;
    case 6:
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(BR_CODEIN_RecordHitOptionLeft(work,x,y)) *state=7;
            else if(BR_CODEIN_RecordHitOptionRight(work,x,y)) *state=10;
        }
        break;
    case 7: BR_FADE_Start((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade),2,3,1);++*state;break;
    case 8: if(BR_FADE_GetResult(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade)) ++*state;break;
    case 9: BR_CODEIN_RecordTeardownTextWin(work,((struct CodeinWorkB *)work)->recordCtx);*state=13;break;
    case 10: BR_FADE_Start((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade),2,3,1);++*state;break;
    case 11: if(BR_FADE_GetResult(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade)) ++*state;break;
    case 12: BR_CODEIN_RecordTeardownTextWin(work,((struct CodeinWorkB *)work)->recordCtx);BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_RecordStepCreateProfile);break;
    case 13: BR_CODEIN_RecordCreateTextWin(work,((struct CodeinWorkB *)work)->recordCtx);*state=14;break;
    case 14:
        BR_UTIL_SetWindowText(((struct CodeinWorkB *)work)->textWin,(char *)(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->res),(void *)0x152);
        BR_FADE_Start((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade),2,3,0);*state=15;break;
    case 15: if(BR_FADE_GetResult(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade)) *state=16;break;
    case 16: *state=17;break;
    case 17: GAME_DATA_SaveStart((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->gameData));*state=18;break;
    case 18:
        if(GAME_DATA_SaveMain(*(u8 * *)&((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->gameData)==2) {BR_UTIL_StartEffect((void *)(((struct CodeinWorkB *)work)->button), 0, 0);*state=19;}
        break;
    case 19: BR_FADE_Start((int)(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade),2,3,1);*state=20;break;
    case 20: if(BR_FADE_GetResult(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->subFade)) *state=21;break;
    case 21:
        if(!GFL_USE_IsSeqPlaying(0x701)) {
            BR_CODEIN_RecordDeleteTextWin(work,((struct CodeinWorkB *)work)->recordCtx);
            **(int * *)&((struct CodeinWorkB *)work)->recordCtx=1;
            BR_PROC_SYS_SetupWindow((CodeinWindowState *)(*(CodeinWindowState * *)&((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->procQuery));
            BR_UTIL_ClearTaskStep((int *)task);
        }
        break;
    }
}










/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-C: prior verified Thumb EXACT from BR_CODEIN_SearchBuildHeader.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * lever: counter declared before context locals restores stack homes; named selector fixes call-result addition operand order (existing idioms).
 * abi: EE0C retains caller's sixth outgoing word (2), beyond callee's five used arguments.
 */
void BR_CODEIN_RecordSetupProfile(char *work,char *arg)
{
    u16 record[4];
    int i;
    void *font;
    MsgBank *bank;
    WordSet *words;
    int ready;
    const CodeinMenuItem *d;
    char *slot;
    U16Vec *text;
    if(!*(int *)(work+0xd4)) {
        *(int *)(work+0xd4)=1;
        if(BR_CODEIN_RecordIsMultiBattle(*(void **)(work+0xc4))) BR_RES_LoadBgGraphics((void *)(*(int *)(arg+0x10)),7,*(u16 *)(work+0xb4));
        else BR_RES_LoadBgGraphics((void *)(*(int *)(arg+0x10)),6,*(u16 *)(work+0xb4));
        font=(void *)BR_RES_GetFont(*(char **)(arg+0x10));
        bank=(MsgBank *)BR_RES_GetMsgData(*(char **)(arg+0x10));
        words=(WordSet *)BR_RES_GetWordSet(*(char **)(arg+0x10));
        for(i=0;i<5;i++) {
            d=&d_021E32C8[i];
            slot=work+i*4;
            *(void **)(slot+0x30)=BR_UTIL_Create(1,d->x,d->y,d->w,d->h,14,*(void **)(work+4),*(u16 *)(work+0xb4));
            switch(i) {
            case 0:
                {
                void *name;
                void *message;
                text=STRBUF_Create(128,*(u16 *)(work+0xb4));
                name=GDS_PROFILE_CreateNameStr(*(void **)(work+0xc0),*(u16 *)(work+0xb4));
                message=MSGDATA_AllocString(bank,d->message);
                WORDSET_SetSlotTag(words,0,name,GDS_PROFILE_GetEggFlag(*(RecGet **)(work+0xc0)),1,2);
                WORDSET_CopyTaggedText(words,text,message);
                STRBUF_Delete((U16Vec *)name);STRBUF_Delete((U16Vec *)message);
                BR_UTIL_SetTextLayout(*(void **)(slot+0x30),0,1,0);
                ready=1;break;
                }
            case 1:
                {
                u32 selector;
                selector=BATTLE_REC_GetHeaderParam(*(void **)(work+0xc4),3,0);
                text=MSGDATA_AllocString(bank,selector+d->message);
                BR_UTIL_SetTextLayout(*(void **)(slot+0x30),0,1,0);ready=1;break;
                }
            case 2:
                {
                u64 value;
                u64 quotient;
                u32 low,middle,high;
                void *message;
                void *temporary;
                value=BATTLE_REC_GetHeaderParam(*(void **)(work+0xc4),4,0);
                low=value%100000ULL;
                quotient=value/100000ULL;
                middle=quotient%100000ULL;
                high=quotient/100000ULL;
                temporary=GDS_PROFILE_ExportRecord(*(GdsProfile **)(work+0xc0),(GdsRecord *)record,*(u16 *)(work+0xb4));
                if(temporary) {
                    message=MSGDATA_AllocString(bank,13);STRBUF_Delete((U16Vec *)temporary);
                } else message=MSGDATA_AllocString(bank,d->message);
                text=STRBUF_Create(128,*(u16 *)(work+0xb4));
                WORDSET_SetSlotNumber(words,2,low,5,2,1);WORDSET_SetSlotNumber(words,1,middle,5,2,1);WORDSET_SetSlotNumber(words,0,high,2,2,1);
                WORDSET_CopyTaggedText(words,text,message);
                BR_UTIL_SetTextLayout(*(void **)(slot+0x30),0,1,0);STRBUF_Delete((U16Vec *)message);
                ready=1;break;
                }
            case 3:
                if(BR_CODEIN_RecordIsType2(*(void **)(work+0xc4))) {
                    u32 count;
                    void *message;
                    count=BATTLE_REC_GetHeaderParam(*(void **)(work+0xc4),2,0);
                    text=STRBUF_Create(128,*(u16 *)(work+0xb4));
                    message=MSGDATA_AllocString(bank,d->message);
                    WORDSET_SetSlotNumber(words,0,count,4,0,1);WORDSET_CopyTaggedText(words,text,message);STRBUF_Delete((U16Vec *)message);
                    BR_UTIL_SetTextLayout(*(void **)(slot+0x30),0,1,1);ready=1;
                } else ready=0;
                break;
            case 4:
                if(BR_CODEIN_RecordIsType2(*(void **)(work+0xc4))) {
                    text=MSGDATA_AllocString(bank,d->message);
                    BR_UTIL_SetTextLayout(*(void **)(slot+0x30),0,1,1);ready=1;
                } else ready=0;
                break;
            }
            if(ready) {
                BR_UTIL_SetTextFromBuffer(*(char **)(slot+0x30),text,font,0x3da0);STRBUF_Delete(text);
            }
        }
        BR_CODEIN_RecordSetupActors(work,*(void **)(arg+0x18),*(void **)(work+0xc4),*(u16 *)(work+0xb4));
    }
}










/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 BattleRecModeTable[];
 *   u64 BATTLE_REC_GetHeaderParam(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * lever: swapped start/end declaration homes, then zeroed phase-two j before coords assignment; DIFF16 to4 to MATCH.
 * checks: 1 own ARM9 and matched caller arities re-derived; B98C original shown, 3 args/u64, DD228 shown 1 arg; 2 F838 and F620/DE084 twins reread; 3 codegen became MATCH in3 runs, further type probes unnecessary; 4 counter-before-base/declared-struct idioms read; 5 fresh directory/neighbors reread before handoff; prior permuter300 not repeated.
 * TU: cbd8-tu.log terminal exit0, MATCH, three B98C wildcards at +009A/+00A6/+00B2, no viable split.
 */
void BR_CODEIN_RecordSetupActors(char *work,void *manager,void *party,u16 heap)
{
    u32 species[12],forms[12],half[12];
    Position pos;
    u32 v,f,h;
    int count=0;
    int mode;
    void *archive;
    int step;
    int i;
    int start;
    int n;
    int end;
    const Point16 *coords;
    char *slot;
    int mapping;
    archive=ARC_TOOL_CreateHandle(7,(u16)((heap&0x7fff)|0x8000));
    *(void **)(work+0x48)=(void *)CLACT_RegisterPaletteCompressed(archive,POKE_TOOL_GetIconPaletteArcId(),0,128,heap);
    mapping=POKE_TOOL_GetIconCellArcId();
    *(void **)(work+0x4c)=(void *)CLACT_RegisterCellAnim(archive,mapping,POKE_TOOL_GetIconCellEntryId(),heap);
    n=0;
    step=6;start=0;end=6;mode=0;
    if(BR_CODEIN_RecordIsMultiBattle(party)==1) {step=3;end=3;mode=1;}
    do {
        for(i=start;i<end;i++) {
            species[n]=255;
            v=BATTLE_REC_GetHeaderParam(party,0,i);
            f=BATTLE_REC_GetHeaderParam(party,1,i);
            h=BATTLE_REC_GetHeaderParam(party,6,i);
            if(v) {species[n]=v;forms[n]=f;half[n]=h;n++;}
        }
        for(i=n;i<end;i++) {species[n]=0;forms[n]=0;half[n]=0;n++;}
        start+=step;end+=step;
    } while(end<=12);
    {
    int j;
    u32 h2,f2,v2;
    j=0;
    coords=(const Point16 *)((u32)d_021E32F0+(int)mode*48);
    for(;j<12;j++) {
        slot=work+j*4;
        *(void **)(slot+0x80)=0;
        *(u32 *)(slot+0x50)=-1;
        v2=species[j];
        if(v2) {
            h2=half[j];f2=forms[j];
            *(u32 *)(slot+0x50)=CLACT_RegisterCharacter(archive,POKE_TOOL_CalcGraphicIndex(v2,f2,h2,0),0,0,heap);
            MI_CpuFill8(&pos,0,8);
            pos.x=coords[j].x+8;pos.y=coords[j].y-12;pos.z=1;pos.a=12-count;
            *(void **)(work+count*4+0x80)=CLACT_CreateActor(manager,(u32)(*(void **)(slot+0x50)),(u32)(*(void **)(work+0x48)),(u32)(*(void **)(work+0x4c)),&pos,0,heap);
            CLACT_SetActorObjMode(*(void **)(count*4+work+0x80),1);
            CLACT_SetActorPaletteOffset(*(void **)(work+count*4+0x80),POKE_TOOL_CalcIconPalette(v2,f2,h2,0),0);
            count++;
        }
    }
    }
    ARC_TOOL_DeleteHandle(archive);
}










void BR_CODEIN_RecordCreateProfileScreen(char *work, char *arg)
{
    int flag;
    if(*(int *)(work+0x44)==0 && *(int *)(work+0xdc)==0) {
        *(int *)(work+0xdc)=1;
        flag=1;
        if(*(int *)(*(char **)(work+0xd0)+8)==0) flag=0;
        *(void **)(work+0x44)=BR_UTIL_CreateProfileScreen((void *)(*(int *)(work+0xc0)),(char *)(*(int *)(arg+0x10)),(void *)(*(int *)(arg+0x18)),(void *)(*(int *)(work+4)),flag,*(unsigned short *)(work+0xb4));
    }
}










void BR_CODEIN_RecordDeleteProfileScreen(char *work,char *unused) { if(((struct CodeinWorkB *)work)->profileScreenLoaded && *(int * *)&((struct CodeinWorkB *)work)->profileScreen) { BR_UTIL_DeleteProfileScreen(*(int * *)&((struct CodeinWorkB *)work)->profileScreen); ((struct CodeinWorkB *)work)->profileScreen=0; ((struct CodeinWorkB *)work)->profileScreenLoaded=0; } }









void BR_CODEIN_RecordDeleteActors(char *work,char *arg)
{
    int i;
    char *slot;
    if(((struct CodeinWorkB *)work)->actorsLoaded) {
        for(i=0;i<12;i++) {
            slot=work+i*4;
            if(((struct CodeinWorkC *)slot)->actor) {
                CLACT_SetActorDrawEnable(((struct CodeinWorkC *)slot)->actor,0);
                CLACT_DeleteActor(((struct CodeinWorkC *)slot)->actor);
                *(int *)&((struct CodeinWorkC *)slot)->actor=0;
            }
            if(((struct CodeinWorkC *)slot)->charRes!=-1) { CLACT_ReleaseCharacter(((struct CodeinWorkC *)slot)->charRes); ((struct CodeinWorkC *)slot)->charRes=-1; }
        }
        if(((struct CodeinWorkB *)work)->paletteRes!=-1) { CLACT_ReleasePalette(((struct CodeinWorkB *)work)->paletteRes); ((struct CodeinWorkB *)work)->paletteRes=-1; }
        if(((struct CodeinWorkB *)work)->cellAnimRes!=-1) { CLACT_ReleaseCellAnim(((struct CodeinWorkB *)work)->cellAnimRes); ((struct CodeinWorkB *)work)->cellAnimRes=-1; }
        for(i=0;i<5;i++) {
            slot=work+i*4;
            if(((struct CodeinWorkC *)slot)->profileText) { BR_UTIL_Delete(((struct CodeinWorkC *)slot)->profileText); *(int *)&((struct CodeinWorkC *)slot)->profileText=0; }
        }
        BR_RES_ApplyBgSet(((struct CodeinArgA *)arg)->uiRes,6);
        BG_SYS_PushTile(1);
        ((struct CodeinWorkB *)work)->actorsLoaded=0;
    }
}









void BR_CODEIN_RecordSetupButtons(char *work,char *arg)
{
    int a,b;
    if(!((struct CodeinWorkA *)work)->buttonsLoaded) {
        ((struct CodeinWorkA *)work)->buttonsLoaded=1;
        BR_RES_LoadBgGraphics((void *)(*(int *)&((struct CodeinArgB *)arg)->gameData),5,((struct CodeinWorkA *)work)->recordHeapId);
        BR_RES_LoadSprite(*(char * *)&((struct CodeinArgB *)arg)->gameData,6,((struct CodeinWorkA *)work)->recordHeapId);
        a=BR_RES_GetFont(*(char * *)&((struct CodeinArgB *)arg)->gameData);
        b=BR_RES_GetMsgData(*(char * *)&((struct CodeinArgB *)arg)->gameData);
        if(((struct CodeinWorkA *)work)->hasSecondButton) {
            Params d;
            Triple t;
            MI_CpuFill8(&d,0,8);
            d.a=24;d.b=168;d.c=0;d.flag=1;
            BR_RES_GetSprite(((struct CodeinArgB *)arg)->gameData,6,&t);
            (*(void * *)&((struct CodeinWorkA *)work)->ctx)=BR_BTN_CreateFromMessage(&d,4,96,1,((struct CodeinArgB *)arg)->category,(*(int *)&((struct CodeinWorkA *)work)->oamSys),a,b,&t,((struct CodeinWorkA *)work)->recordHeapId);
            d.a=136;d.c=3;
            (*(void * *)&((struct CodeinWorkA *)work)->saveCtx)=BR_BTN_CreateFromMessage(&d,84,96,1,((struct CodeinArgB *)arg)->category,(*(int *)&((struct CodeinWorkA *)work)->oamSys),a,b,&t,((struct CodeinWorkA *)work)->recordHeapId);
        } else {
            Params d;
            Triple t;
            MI_CpuFill8(&d,0,8);
            d.a=80;d.b=168;d.c=0;d.flag=1;
            BR_RES_GetSprite(((struct CodeinArgB *)arg)->gameData,6,&t);
            (*(void * *)&((struct CodeinWorkA *)work)->ctx)=BR_BTN_CreateFromMessage(&d,4,96,1,((struct CodeinArgB *)arg)->category,(*(int *)&((struct CodeinWorkA *)work)->oamSys),a,b,&t,((struct CodeinWorkA *)work)->recordHeapId);
        }
        (*(void * *)&((struct CodeinWorkA *)work)->noticeText)=BR_UTIL_Create(4,8,3,16,2,14,((struct CodeinWorkA *)work)->printQue,((struct CodeinWorkA *)work)->recordHeapId);
        if(((struct CodeinWorkA *)work)->profileScreenShown) BR_UTIL_SetTextFromMessage(((struct CodeinWorkA *)work)->noticeText,(void *)b,(void *)0x72,(void *)a,0x3da0);
        else BR_UTIL_SetTextFromMessage(((struct CodeinWorkA *)work)->noticeText,(void *)b,(void *)0x71,(void *)a,0x3da0);
    }
}









void BR_CODEIN_RecordDeleteButtons(char *work, char *arg)
{
    int i;
    char *slot;
    if(((struct CodeinWorkB *)work)->buttonsLoaded) {
        if(((struct CodeinWorkB *)work)->noticeText) { BR_UTIL_Delete(((struct CodeinWorkB *)work)->noticeText); *(int *)&((struct CodeinWorkB *)work)->noticeText=0; }
        for(i=0;i<2;i++) {
            slot=work+i*4;
            if(((struct CodeinSlotA *)slot)->rowText) { BR_BTN_DeleteObject(((struct CodeinSlotA *)slot)->rowText); *(int *)&((struct CodeinSlotA *)slot)->rowText=0; }
        }
        BG_SYS_PushTile(4);
        BR_RES_ReleaseSprite((char *)(((struct CodeinArgA *)arg)->uiRes),6);
        BR_RES_ApplyBgSet(((struct CodeinArgA *)arg)->uiRes,5);
        ((struct CodeinWorkB *)work)->buttonsLoaded=0;
    }
}







void BR_CODEIN_RecordCreateTextWin(char *work, char *unused)
{
    if (!((struct CodeinWorkB *)work)->textWinCreated) {
        Point args;
        ((struct CodeinWorkB *)work)->textWinCreated = 1;
        if (!((struct CodeinWorkB *)work)->textWin)
            ((struct CodeinWorkB *)work)->textWin = BR_UTIL_CreateTextWin(((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->res, (void *)(((struct CodeinWorkB *)work)->printQue), ((struct CodeinWorkB *)work)->recordHeapId);
        args.x = 0x80;
        args.y = 0x60;
        BR_UTIL_StartEffect((void *)(((struct CodeinWorkB *)work)->button), 4, &args);
    }
}







void BR_CODEIN_RecordDeleteTextWin(char *work, char *unused) { if(((struct CodeinWorkB *)work)->textWinCreated) { BR_UTIL_StartEffect(*(char * *)&((struct CodeinWorkB *)work)->button,0,0); if(((struct CodeinWorkB *)work)->textWin) { BR_UTIL_DeleteTextWin(((struct CodeinWorkB *)work)->textWin,((struct CodeinSubA *)(((struct CodeinWorkB *)work)->recordCtx))->res); *(int *)&((struct CodeinWorkB *)work)->textWin=0; } ((struct CodeinWorkB *)work)->textWinCreated=0; } }







void BR_CODEIN_RecordSetupTextWin(char *work, char *arg)
{
    if (!((struct CodeinWorkB *)work)->textWinSetup) {
        int first, second, i;
        const Record *rec;
        char *slot;
        ((struct CodeinWorkB *)work)->textWinSetup = 1;
        if (!((struct CodeinWorkB *)work)->textWin)
            ((struct CodeinWorkB *)work)->textWin = BR_UTIL_CreateTextWin(((struct CodeinArgA *)arg)->uiRes, (void *)(((struct CodeinWorkB *)work)->printQue), ((struct CodeinWorkB *)work)->recordHeapId);
        BR_UTIL_SetWindowText(((struct CodeinWorkB *)work)->textWin, (char *)(((struct CodeinArgA *)arg)->uiRes), (void *)0x14f);
        BR_RES_LoadBgGraphics((void *)(((struct CodeinArgA *)arg)->uiRes), 30, ((struct CodeinWorkB *)work)->recordHeapId);
        first = BR_RES_GetFont(*(char * *)&((struct CodeinArgA *)arg)->uiRes);
        second = BR_RES_GetMsgData(*(char * *)&((struct CodeinArgA *)arg)->uiRes);
        for (i = 0; i < 2; i++) {
            rec = &d_021E32A8[i];
            slot = work + i * 4;
            ((struct CodeinWorkC *)slot)->captionText = BR_UTIL_Create(4, rec->a, rec->b, rec->c, rec->d, 14, (void *)(((struct CodeinWorkB *)work)->printQue), ((struct CodeinWorkB *)work)->recordHeapId);
            BR_UTIL_SetTextFromMessage(((struct CodeinWorkC *)slot)->captionText, (void *)second, (void *)rec->value, (void *)first, 0x3da0);
        }
    }
}












/*
 * trailing: 2 zero alignment bytes at 0x021DD226
 */
void BR_CODEIN_RecordTeardownTextWin(char *work, char *arg)
{
    int i;
    char *slot;
    if (((struct CodeinWorkB *)work)->textWinSetup) {
        for (i = 0; i < 2; i++) {
            slot = work + i * 4;
            if (((struct CodeinWorkC *)slot)->captionText) {
                BR_UTIL_Delete(((struct CodeinWorkC *)slot)->captionText);
                *(int *)&((struct CodeinWorkC *)slot)->captionText = 0;
            }
        }
        BG_SYS_PushTile(4);
        BR_RES_ApplyBgSet(((struct CodeinArgA *)arg)->uiRes, 30);
        if (((struct CodeinWorkB *)work)->textWin) {
            BR_UTIL_DeleteTextWin(((struct CodeinWorkB *)work)->textWin, ((struct CodeinArgA *)arg)->uiRes);
            *(int *)&((struct CodeinWorkB *)work)->textWin = 0;
        }
        ((struct CodeinWorkB *)work)->textWinSetup = 0;
    }
}












/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 BattleRecModeTable[];
 *   u64 BATTLE_REC_GetHeaderParam(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1: return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4: return *(u64 *)(p + 0x38);
 *       case 5: return *(u8 *)(p + 0x2A);
 *       case 6: return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7: return *(u8 *)(p + 0x2B);
 *       default: return 0;
 *       }
 *   }
 */
int BR_CODEIN_RecordIsMultiBattle(void *work) { switch((int)BATTLE_REC_GetHeaderParam(work,3,0)) { case 16: case 17: case 18: case 19: case 22: return 1; case 20: case 21: default: return 0; } }












int BR_CODEIN_RecordIsType2(void *work) { int result; int v; result=0; v=(int)BATTLE_REC_GetHeaderParam(work,3,0); if(v==20) goto yes; if(v==21) goto yes; if(v!=22) goto no; yes: return 1; no: return result; }












int BR_CODEIN_RecordHitProfileToggle(char *work, int x, int y)
{
    int ok = ((unsigned int)(x - 0x40) <= 0x88) &
             ((unsigned int)(y - 0x10) <= 0x20);
    if (ok) {
        Point args;
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((void *)((*(int *)&((struct CodeinWorkA *)work)->recordTapFx)), 1, &args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}












int BR_CODEIN_RecordHitRecordPanel(char *work, int x, int y)
{
    int ok = ((unsigned int)(x - 0x50) <= 0x60) &
             ((unsigned int)(y - 0x38) <= 0x40);
    if (ok) {
        Point args;
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((void *)((*(int *)&((struct CodeinWorkA *)work)->recordTapFx)), 1, &args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}












int BR_CODEIN_RecordHitOptionLeft(char *work, int x, int y)
{
    int ok = ((unsigned int)(x - 0x20) <= 0x48) &
             ((unsigned int)(y - 0x30) <= 0x10);
    if (ok) {
        Point args;
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((void *)(((struct CodeinWorkB *)work)->screenFade), 1, &args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}












int BR_CODEIN_RecordHitOptionRight(char *work, int x, int y)
{
    int ok = ((unsigned int)(x - 0x90) <= 0x48) &
             ((unsigned int)(y - 0x30) <= 0x10);
    if (ok) {
        Point args;
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((void *)(((struct CodeinWorkB *)work)->screenFade), 1, &args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}












/*
 * trailing: 2 zero alignment bytes at 0x021DD3F6
 */
int BR_CODEIN_ListCreate(void *proc, int unused, char *arg)
{
    struct CodeinWorkA *p = PROCSYS_AllocProcWork(proc, 0x80, BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(*(char * *)&((struct CodeinArgA *)arg)->procQuery)));
    MI_CpuFill8(p, 0, 0x80);
    p->listHeapId = BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(*(char * *)&((struct CodeinArgA *)arg)->procQuery));
    p->oamSys = BMP_OAM_CreateSys(p->listHeapId, (*(void * *)&((struct CodeinArgA *)arg)->actorSys));
    p->printQue = (void *)PRINTSYS_QUE_Create((void *)(p->listHeapId));
    p->listFx = BR_UTIL_CreateHandles((unsigned int)((*(void * *)&((struct CodeinArgA *)arg)->actorSys)), (char *)(((struct CodeinArgA *)arg)->res), 1, p->listHeapId);
    BR_RES_LoadSprite(*(char * *)&((struct CodeinArgA *)arg)->res, 13, p->listHeapId);
    BR_CODEIN_ListSetupButtons(p, arg);
    BR_CODEIN_ListSetupText(p, arg);
    return 1;
}











int BR_CODEIN_ListDestroy(struct Proc *proc, int unused, char *arg, char *work)
{
    BR_CODEIN_ListDeleteButtons(work, arg);
    BR_CODEIN_ListTeardown(work, arg);
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(1);
    BR_RES_ReleaseSprite((char *)(((struct CodeinArgA *)arg)->res), 13);
    BR_UTIL_DeleteHandles(*(char * *)&((struct CodeinWorkA *)work)->listFx);
    PRINTSYS_QUE_Delete(((struct CodeinWorkA *)work)->printQue);
    BMP_OAM_DeleteSys(((struct CodeinWorkA *)work)->oamSys);
    PROCSYS_FreeProcWork(proc);
    return 1;
}











/*
 * tail: 021DD5C6..021DD5C8 is two zero alignment bytes.
 */
int BR_CODEIN_ListMain(void *unused,u32 *state,char *arg,char *work)
{
 int x,y,i;
 Point pair;
 switch(*state){
 case 0:BR_FADE_Start(((struct CodeinArgA *)arg)->screenFade,2,3,0);*state=1;break;
 case 1:if(BR_FADE_GetResult(*(int * *)&((struct CodeinArgA *)arg)->screenFade)) *state=2;break;
 case 2:
  if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))){
   ((struct CodeinWorkA *)work)->listChoice=BR_CODEIN_ListHitButton(work,x,y);
   if(((struct CodeinWorkA *)work)->listChoice) *state=3;
   if(BR_BTN_HitTestWithSound((unsigned int *)((*(int *)&((struct CodeinWorkA *)work)->saveCtx)),x,y)){
    pair.x=x;pair.y=y;
    BR_UTIL_StartEffect((void *)(*(int *)&((struct CodeinWorkA *)work)->listFx), 1, &pair);
    *state=7;
   }
  }break;
 case 3:BR_FADE_Start(((struct CodeinArgA *)arg)->screenFade,2,1,1);++*state;break;
 case 4:if(BR_FADE_GetResult(*(int * *)&((struct CodeinArgA *)arg)->screenFade)) ++*state;break;
 case 5:
  BR_CODEIN_ListTeardown(work,arg);
  switch(*(u32 *)&((struct CodeinWorkA *)work)->listChoice){
  case 1:BR_CODEIN_ListSetupRowA(work,arg);break;
  case 2:BR_CODEIN_ListSetupRowB(work,arg);break;
  case 3:BR_CODEIN_ListSetupRowC(work,arg);break;
  case 4:BR_CODEIN_ListSetupRowD(work,arg);break;
  }
  BR_FADE_Start(((struct CodeinArgA *)arg)->screenFade,2,1,0);++*state;break;
 case 6:if(BR_FADE_GetResult(*(int * *)&((struct CodeinArgA *)arg)->screenFade)) *state=2;break;
 case 7:BR_FADE_Start(((struct CodeinArgA *)arg)->screenFade,2,3,1);*state=8;break;
 case 8:if(BR_FADE_GetResult(*(int * *)&((struct CodeinArgA *)arg)->screenFade)) *state=9;break;
 case 9:BR_PROC_SYS_PopEntry(((struct CodeinArgA *)arg)->procQuery);return 1;
 }
 for(i=0;i<4;i++) if(*(void **)(work+i*4+0x24)) BR_UTIL_FlushText(*(void **)(work+i*4+0x24));
 for(i=0;i<16;i++) if(*(void **)(work+i*4+0x34)) BR_UTIL_FlushText(*(void **)(work+i*4+0x34));
 PRINTSYS_QUE_Main(((struct CodeinWorkA *)work)->printQue);
 if((*(void * *)&((struct CodeinWorkA *)work)->ctx))BR_UTIL_FlushWindow((*(void * *)&((struct CodeinWorkA *)work)->ctx));
 BR_UTIL_RunHandles(((struct CodeinWorkA *)work)->listFx);
 return 0;
}











/*
 * lever: const record array at the table address restores early argument loads;
 *        a scalar record and const pointer local remained 22 bytes DIFF.
 */
void BR_CODEIN_ListSetupText(struct CodeinWorkA *work, char *arg)
{
    int first, second, v;
    Triple triple;
    const Record *rec;
    u8 a, b, c, d;
    first = BR_RES_GetFont(*(char * *)&((struct CodeinArgA *)arg)->res);
    second = BR_RES_GetMsgData(*(char * *)&((struct CodeinArgA *)arg)->res);
    BR_RES_LoadBgGraphics((void *)(((struct CodeinArgA *)arg)->res), 14, work->listHeapId);
    rec = &d_021E3350[0];
    d = rec->d;
    a = rec->a;
    b = rec->b;
    c = rec->c;
    work->listText = BR_UTIL_Create(1, a, b, c, d, 14, work->printQue, work->listHeapId);
    BR_UTIL_SetTextLayout(work->listText, 0, 1, 0);
    BR_UTIL_SetTextFromMessage(work->listText, (void *)second, (void *)rec->value, (void *)first, 0x3da0);
    (*(void * *)&work->ctx) = BR_UTIL_CreateTextWin(((struct CodeinArgA *)arg)->res, (void *)(*(int *)&work->printQue), work->listHeapId);
    BR_UTIL_SetWindowText((*(void * *)&work->ctx), (char *)(((struct CodeinArgA *)arg)->res), (void *)0x86);
    v = BSUBWAY_SCOREDATA_GetBattlePoints((struct Blk1AC *)(((struct CodeinArgA *)arg)->uiRes));
    BR_RES_GetSprite((void *)(((struct CodeinArgA *)arg)->res), 13, (Triple *)((Triple *)&triple));
    BR_CODEIN_ListCreateActor((void *)((char *)work + 8), (void *)(((struct CodeinArgA *)arg)->actorSys), (const char *)(&triple), v, 0x68, 0x58, work->listHeapId);
}










void BR_CODEIN_ListSetupRowA(char *work,char *arg)
{
 int first,second,third,index,v;
 const Record *rec;
 char *slot;
 unsigned select;
 int number1,number2;
 void *obj;
 Triple triple;
 first=BR_RES_GetFont(*(char **)(arg+8));
 second=BR_RES_GetMsgData(*(char **)(arg+8));
 third=BR_RES_GetWordSet(*(char **)(arg+8));
 BR_RES_LoadBgGraphics((void *)(*(int *)(arg+8)),10,*(u16 *)(work+0x7c));
 select=BR_CODEIN_ListIsEventA((void *)(*(int *)(arg+0x10)),(char *)(*(int *)(arg+0x14)))?5:0;
 for(index=0;index<8;index++){
  rec=&d_021E33C0[index];slot=work+index*4;
  *(void **)(slot+0x34)=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,*(void **)(work+4),*(u16 *)(work+0x7c));
  BR_UTIL_SetTextLayout(*(void **)(slot+0x34),0,1,0);
  switch(index){
   case 1:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BR_CODEIN_ListIsEventA((void *)(*(int *)(arg+0x10)),(char *)(*(int *)(arg+0x14)))?0x83:0x7e);break;
   case 2:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BSUBWAY_SCOREDATA_HasCleared(*(void **)(arg+0x10),select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=BSUBWAY_SCOREDATA_GetWinCount(*(void **)(arg+0x10),select);
    number1=(number1>9999)?9999:number1;
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(work+0x7c));
    WORDSET_SetSlotNumber((void *)third,0,number1,4,1,1);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 6:{
    void *base;
    number2=BSUBWAY_SCOREDATA_GetMaxWinCount(*(void **)(arg+0x10),select);
    number2=(number2>9999)?9999:number2;
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(work+0x7c));
    WORDSET_SetSlotNumber((void *)third,0,number2,4,1,1);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   default:obj=MSGDATA_AllocString((struct MsgBank *)second,rec->value);break;
  }
  BR_UTIL_SetTextFromBuffer(*(char **)(slot+0x34),obj,(void *)first,0x3da0);
  STRBUF_Delete(obj);
 }
 v=BSUBWAY_SCOREDATA_GetBattlePoints(*(void **)(arg+0x10));
 BR_RES_GetSprite((void *)(*(int *)(arg+8)), 13, (Triple *)((Triple *)&triple));
 BR_CODEIN_ListCreateActor(work+8,*(void **)(arg+4),(const char *)&triple,v,0xa0,0x20,*(u16 *)(work+0x7c));
}










/*
 * note: 2026-10-05 wave P10 lane Y1. Twin of BR_CODEIN_ListSetupRowA (same body: other table d_021E3400, getter BR_CODEIN_ListIsEventB, selector 6/1, argument 11, strings 0x84/0x7f). 468 B; the 1140 B listing extent also holds BR_CODEIN_ListSetupRowC, filed separately. The clamps are n = (n > 9999) ? 9999 : n; as in the twin.
 */
void BR_CODEIN_ListSetupRowB(char *work,char *arg)
{
 int first,second,third,index,v;
 const Record *rec;
 char *slot;
 unsigned select;
 int number1,number2;
 void *obj;
 Triple triple;
 first=BR_RES_GetFont(*(char **)(arg+8));
 second=BR_RES_GetMsgData(*(char **)(arg+8));
 third=BR_RES_GetWordSet(*(char **)(arg+8));
 BR_RES_LoadBgGraphics((void *)(*(int *)(arg+8)),11,*(u16 *)(work+0x7c));
 select=BR_CODEIN_ListIsEventB((void *)(*(int *)(arg+0x10)),(void *)(*(int *)(arg+0x14)))?6:1;
 for(index=0;index<8;index++){
  rec=&d_021E3400[index];slot=work+index*4;
  *(void **)(slot+0x34)=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,*(void **)(work+4),*(u16 *)(work+0x7c));
  BR_UTIL_SetTextLayout(*(void **)(slot+0x34),0,1,0);
  switch(index){
   case 1:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BR_CODEIN_ListIsEventB((void *)(*(int *)(arg+0x10)),(void *)(*(int *)(arg+0x14)))?0x84:0x7f);break;
   case 2:
    obj=MSGDATA_AllocString((struct MsgBank *)second,BSUBWAY_SCOREDATA_HasCleared(*(void **)(arg+0x10),select)?0x91:0x87);break;
   case 3:{
    void *base;
    number1=BSUBWAY_SCOREDATA_GetWinCount(*(void **)(arg+0x10),select);
    number1=(number1>9999)?9999:number1;
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(work+0x7c));
    WORDSET_SetSlotNumber((void *)third,0,number1,4,1,1);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   case 6:{
    void *base;
    number2=BSUBWAY_SCOREDATA_GetMaxWinCount(*(void **)(arg+0x10),select);
    number2=(number2>9999)?9999:number2;
    base=MSGDATA_AllocString((struct MsgBank *)second,rec->value);
    obj=STRBUF_Create(0x80,*(u16 *)(work+0x7c));
    WORDSET_SetSlotNumber((void *)third,0,number2,4,1,1);
    WORDSET_CopyTaggedText((void *)third,obj,base);
    STRBUF_Delete(base);break;
   }
   default:obj=MSGDATA_AllocString((struct MsgBank *)second,rec->value);break;
  }
  BR_UTIL_SetTextFromBuffer(*(char **)(slot+0x34),obj,(void *)first,0x3da0);
  STRBUF_Delete(obj);
 }
 v=BSUBWAY_SCOREDATA_GetBattlePoints(*(void **)(arg+0x10));
 BR_RES_GetSprite((void *)(*(int *)(arg+8)), 13, (Triple *)((Triple *)&triple));
 BR_CODEIN_ListCreateActor(work+8,*(void **)(arg+4),(const char *)&triple,v,0xa0,0x20,*(u16 *)(work+0x7c));
}








/*
 * lever: bounded permuter rec/index declaration order, selector use and
 *        field-base expansion restore the three selector/index spill homes.
 */
void BR_CODEIN_ListSetupRowC(char *work, char *arg)
{
  int first;
  int second;
  int third;
  const Record *rec;
  int v;
  unsigned select;
  unsigned select2;
  int index;
  char *slot;
  int number1;
  int number2;
  int number3;
  int number4;
  void *obj;
  Triple triple;
  char **textSlot;
  u16 heapId;
  first = BR_RES_GetFont(*((char **) (arg + 8)));
  second = BR_RES_GetMsgData(*((char **) (arg + 8)));
  third = BR_RES_GetWordSet(*((char **) (arg + 8)));
  heapId = *((u16 *) (work + 0x7c));
  BR_RES_LoadBgGraphics((void *)(*((int *) (arg + 8))), 12, heapId);
  if (BR_CODEIN_ListIsEventC((void *)(*((int *) (arg + 0x10))), (void *)(*((int *) (arg + 0x14)))))
  {
    select = 7;
    select2 = 8;
  }
  else
  {
    select = 2;
    select2 = 3;
  }
  ;
  for (index = 0; index < 16; index++)
  {
    rec = &d_021E3490[index];
    slot = work + (index * 4);
    *((void **) (slot + 0x34)) = BR_UTIL_Create(1, (&d_021E3490[index])->a, (&d_021E3490[index])->b, (&d_021E3490[index])->c, (&d_021E3490[index])->d, 14, *((void **) (work + 4)), *((u16 *) (work + 0x7c)));
    BR_UTIL_SetTextLayout(*((void **) (slot + 0x34)), 0, 1, 0);
    switch (index)
    {
      if (select2)
      {
      }
      case 1:
        obj = MSGDATA_AllocString((struct MsgBank *)second, (BR_CODEIN_ListIsEventC((void *)(*((int *) (arg + 0x10))), (void *)(*((int *) (arg + 0x14))))) ? (0x85) : (0x80));
        break;

      case 3:
        obj = MSGDATA_AllocString((struct MsgBank *)second, (BSUBWAY_SCOREDATA_HasCleared(*((void **) (arg + 0x10)), select)) ? (0x91) : (0x87));
        break;

      case 4:
      {
        void *base;
        number1 = BSUBWAY_SCOREDATA_GetWinCount(*((void **) (arg + 0x10)), select);
        if (number1 > 9999)
          number1 = 9999;
        base = MSGDATA_AllocString((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (work + 0x7c)));
        WORDSET_SetSlotNumber((void *) third, 0, number1, 4, 1, 1);
        WORDSET_CopyTaggedText((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      case 7:
      {
        void *base;
        number2 = BSUBWAY_SCOREDATA_GetMaxWinCount(*((void **) (arg + 0x10)), select);
        if (number2 > 9999)
          number2 = 9999;
        base = MSGDATA_AllocString((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (work + 0x7c)));
        WORDSET_SetSlotNumber((void *) third, 0, number2, 4, 1, 1);
        WORDSET_CopyTaggedText((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      case 10:
        obj = MSGDATA_AllocString((struct MsgBank *)second, (BSUBWAY_SCOREDATA_HasCleared(*((void **) (arg + 0x10)), select2)) ? (0x91) : (0x87));
        break;

      case 11:
      {
        void *base;
        number3 = BSUBWAY_SCOREDATA_GetWinCount(*((void **) (arg + 0x10)), select2);
        if (number3 > 9999)
          number3 = 9999;
        base = MSGDATA_AllocString((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (work + 0x7c)));
        WORDSET_SetSlotNumber((void *) third, 0, number3, 4, 1, 1);
        WORDSET_CopyTaggedText((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      case 14:
      {
        void *base;
        number4 = BSUBWAY_SCOREDATA_GetMaxWinCount(*((void **) (arg + 0x10)), select2);
        if (number4 > 9999)
          number4 = 9999;
        base = MSGDATA_AllocString((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (work + 0x7c)));
        WORDSET_SetSlotNumber((void *) third, 0, number4, 4, 1, 1);
        WORDSET_CopyTaggedText((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      default:
        obj = MSGDATA_AllocString((struct MsgBank *)second, rec->value);
        break;

    }

    textSlot = (char **) (slot + 0x34);
    BR_UTIL_SetTextFromBuffer(*textSlot, obj, (void *) first, 0x3da0);
    STRBUF_Delete(obj);
  }

  v = BSUBWAY_SCOREDATA_GetBattlePoints((struct Blk1AC *)(*((int *) (arg + 0x10))));
  BR_RES_GetSprite((void *)(*((int *) (arg + 8))), 13, (Triple *)((Triple *)&triple));
  BR_CODEIN_ListCreateActor(work + 8, *((void **) (arg + 4)), (const char *) (&triple), v, 0xa0, 0x20, *((u16 *) (work + 0x7c)));
}








/*
 * lever: declaring the text object before the loop index fixes r4/r5.
 */
void BR_CODEIN_ListSetupRowD(char *work,char *arg)
{
 int first,second,third,v,text;
 void *obj;
 int i;
 char *slot;
 const Record *rec;
 Triple triple;
 first=BR_RES_GetFont(*(char * *)&((struct CodeinArgA *)arg)->res);
 second=BR_RES_GetMsgData(*(char * *)&((struct CodeinArgA *)arg)->res);
 third=BR_RES_GetWordSet(*(char * *)&((struct CodeinArgA *)arg)->res);
 BR_RES_LoadBgGraphics((void *)(((struct CodeinArgA *)arg)->res),13,((struct CodeinWorkA *)work)->listHeapId);
 for(i=0;i<5;i++){
  rec=&d_021E338C[i]; slot=work+i*4;
  ((struct CodeinWorkC *)slot)->rowText=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,((struct CodeinWorkA *)work)->printQue,((struct CodeinWorkA *)work)->listHeapId);
  if(i==4){
   v=BSUBWAY_SCOREDATA_GetLevel((struct Blk1AC *)(((struct CodeinArgA *)arg)->uiRes));
   text=(int)MSGDATA_AllocString((struct MsgBank *)second,rec->value);
   obj=STRBUF_Create(0x80,((struct CodeinWorkA *)work)->listHeapId);
   WORDSET_SetSlotNumber((void *)third,0,v,2,1,1);
   WORDSET_CopyTaggedText((void *)third,obj,(void *)text);
   STRBUF_Delete((struct U16Vec *)text);
  }else obj=(void *)MSGDATA_AllocString((struct MsgBank *)second,rec->value);
  BR_UTIL_SetTextFromBuffer(*(char * *)&((struct CodeinWorkC *)slot)->rowText,obj,(void *)first,0x3da0);
  STRBUF_Delete((struct U16Vec *)((int)obj));
 }
 v=BSUBWAY_SCOREDATA_GetBattlePoints((struct Blk1AC *)(((struct CodeinArgA *)arg)->uiRes));
 BR_RES_GetSprite((void *)(((struct CodeinArgA *)arg)->res), 13, (Triple *)((Triple *)&triple));
 BR_CODEIN_ListCreateActor(work+8,(*(void * *)&((struct CodeinArgA *)arg)->actorSys),(const char *)&triple,v,0xa0,0x20,((struct CodeinWorkA *)work)->listHeapId);
}








void BR_CODEIN_ListTeardown(char *work, char *arg)
{
    int i;
    char *slot;
    BR_CODEIN_ListDeleteActor(work + 8);
    for (i = 0; i < 16; i++) {
        slot = work + i * 4;
        if (((struct CodeinWorkC *)slot)->rowText) {
            BR_UTIL_Delete(((struct CodeinWorkC *)slot)->rowText);
            *(int *)&((struct CodeinWorkC *)slot)->rowText = 0;
        }
    }
    BR_RES_ApplyBgSet(((struct CodeinArgA *)arg)->res, 10);
    if ((*(void * *)&((struct CodeinWorkA *)work)->ctx)) {
        BR_UTIL_DeleteTextWin((*(void * *)&((struct CodeinWorkA *)work)->ctx), ((struct CodeinArgA *)arg)->res);
        *(int *)&((struct CodeinWorkA *)work)->ctx = 0;
    }
}







void BR_CODEIN_ListSetupButtons(struct CodeinWorkA *work,char *arg)
{
 int first,second,i,id;
 Triple triple;
 Position pos;
 const Record *rec;
 char *slot;
 BR_RES_LoadSprite(*(char * *)&((struct CodeinArgA *)arg)->res,6,work->listHeapId);
 BR_RES_LoadBgGraphics((void *)(((struct CodeinArgA *)arg)->res),9,work->listHeapId);
 first=BR_RES_GetFont(*(char * *)&((struct CodeinArgA *)arg)->res);
 second=BR_RES_GetMsgData(*(char * *)&((struct CodeinArgA *)arg)->res);
 MI_CpuFill8(&pos,0,8);
 pos.x=0x50;pos.y=0xa8;pos.z=0;pos.a=1;
 BR_RES_GetSprite((void *)(((struct CodeinArgA *)arg)->res), 6, (Triple *)((Triple *)&triple));
 (*(void * *)&work->saveCtx)=BR_BTN_CreateFromMessage(&pos,4,0x60,1,((struct CodeinArgA *)arg)->actorSys,*(int *)&work->oamSys,first,second,&triple,work->listHeapId);
 for(i=0;i<4;i++){
  rec=&d_021E336C[i];slot=(char *)work+i*4;
  (*(void * *)&((struct CodeinWorkC *)slot)->buttonText)=BR_UTIL_Create(4,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->listHeapId);
  switch(i){
   case 0: if(BR_CODEIN_ListIsEventA((void *)(((struct CodeinArgA *)arg)->uiRes),(char *)(((struct CodeinArgA *)arg)->bsubwaySave))) id=0x83;else id=0x7e;break;
   case 1: if(BR_CODEIN_ListIsEventB((void *)(((struct CodeinArgA *)arg)->uiRes),(void *)(((struct CodeinArgA *)arg)->bsubwaySave))) id=0x84;else id=0x7f;break;
   case 2: if(BR_CODEIN_ListIsEventC((void *)(((struct CodeinArgA *)arg)->uiRes),(void *)(((struct CodeinArgA *)arg)->bsubwaySave))) id=0x85;else id=0x80;break;
   case 3: id=0x81;break;
  }
  BR_UTIL_SetTextFromMessage((*(void * *)&((struct CodeinWorkC *)slot)->buttonText),(void *)second,(void *)id,(void *)first,0x3da0);
 }
}







void BR_CODEIN_ListDeleteButtons(char *work, char *arg)
{
    int i;
    char *slot;
    for (i = 0; i < 4; i++) {
        slot = work + i * 4;
        if ((*(void * *)&((struct CodeinWorkC *)slot)->buttonText)) {
            BR_UTIL_Delete((*(void * *)&((struct CodeinWorkC *)slot)->buttonText));
            *(int *)&((struct CodeinWorkC *)slot)->buttonText = 0;
        }
    }
    if ((*(void * *)&((struct CodeinWorkA *)work)->saveCtx)) {
        BR_BTN_DeleteObject((*(void * *)&((struct CodeinWorkA *)work)->saveCtx));
        *(int *)&((struct CodeinWorkA *)work)->saveCtx = 0;
    }
    BR_RES_ReleaseSprite((char *)(((struct CodeinArgA *)arg)->res), 6);
    BR_RES_ApplyBgSet(((struct CodeinArgA *)arg)->res, 9);
}







int BR_CODEIN_ListHitButton(char *work, int x, int y)
{
    int skip = ((struct CodeinWorkA *)work)->listChoice;
    int i;
    for (i = 0; i < 5; i++) {
        if (i != skip && (u32)(x - d_021E3440[i].x0) <= d_021E3440[i].x1 - d_021E3440[i].x0 &&
            (u32)(y - d_021E3440[i].y0) <= d_021E3440[i].y1 - d_021E3440[i].y0) {
            Point args;
            args.x = x;
            args.y = y;
            BR_UTIL_StartEffect((void *)(*(int *)&((struct CodeinWorkA *)work)->listFx), 1, &args);
            GFL_USE_PlaySeDefaultVolume(0x703);
            return i;
        }
    }
    return 0;
}







int BR_CODEIN_ListIsEventA(void *work,char *arg) { u32 a,b; a=BSUBWAY_SCOREDATA_AccessFlag(work,4,0); b=ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork((const struct BigObj *)arg),0x960); if(a && b) return 1; return 0; }







int BR_CODEIN_ListIsEventB(void *work, void *arg)
{
    int a = BSUBWAY_SCOREDATA_AccessFlag(work, 5, 0);
    unsigned b = ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(arg), 0x960);
    if (a && b) return 1;
    return 0;
}







int BR_CODEIN_ListIsEventC(void *work, void *arg)
{
    int a = BSUBWAY_SCOREDATA_AccessFlag(work, 6, 0);
    unsigned b = ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(arg), 0x960);
    if (a && b) return 1;
    return 0;
}









/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`base = x;` before `base = x + 20;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void BR_CODEIN_ListCreateActor(char *work, void *manager, const char *arg, unsigned int value, s16 x, s16 y, u16 heap)
{
    Position pos;
    int base;
    int i;
    MI_CpuFill8(work, 0, 0x14);
    MI_CpuFill8(&pos, 0, 8);
    pos.x = x;
    pos.y = y;
    pos.z = 10;
    ((struct CodeinWorkA *)work)->oamSys = CLACT_CreateActor(manager, (unsigned int)(*(void * *)&((struct CodeinArgA *)arg)->actorSys), (unsigned int)(*(void * *)&((struct CodeinArgA *)arg)->res), (unsigned int)(*(void * *)&((struct CodeinArgA *)arg)->screenFade), &pos, 0, heap);
    CLACT_SetActorObjMode(((struct CodeinWorkA *)work)->oamSys, 1);
    pos.z = 0;
    base = x + 20;
    for (i = 0; i < 4; i++) {
        char *slot;
        pos.x = base + i * 16;
        pos.y = y;
        slot = work + i * 4;
        ((struct CodeinWorkC *)slot)->textWin = CLACT_CreateActor(manager, (unsigned int)(*(void * *)&((struct CodeinArgA *)arg)->actorSys), (unsigned int)(*(void * *)&((struct CodeinArgA *)arg)->res), (unsigned int)(*(void * *)&((struct CodeinArgA *)arg)->screenFade), &pos, 0, heap);
        CLACT_SetActorObjMode(((struct CodeinWorkC *)slot)->textWin, 1);
    }
    BR_CODEIN_ListSetActorAnim(work, value);
}









void BR_CODEIN_ListDeleteActor(char *work)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = work + i * 4;
        if (((struct CodeinWorkC *)slot)->textWin) {
            CLACT_DeleteActor(((struct CodeinWorkC *)slot)->textWin);
            ((struct CodeinWorkC *)slot)->textWin = 0;
        }
    }
    CLACT_DeleteActor(((struct CodeinWorkA *)work)->oamSys);
    MI_CpuFill8(work, 0, 20);
}









void BR_CODEIN_ListSetActorAnim(char *work, u32 value)
{
    u8 temp = value;
    int i;
    int j;
    if (temp != 0) {
        for (;;) {
            if (temp == 0) break;
            temp /= 10;
        }
    }
    for (i = 0; i < 4; i++) CLACT_SetActorAnimSeq(*(void **)(work + i * 4 + 4), 0);
    for (j = 0; j < 4; j++)
        CLACT_SetActorAnimSeq(*(void **)(work + (3 - j) * 4 + 4), value % d_021E3358[j + 1] / d_021E3358[j]);
}









int BR_CODEIN_ResultCreate(void *proc, int seq, char *arg)
{
    char *p = PROCSYS_AllocProcWork(proc, 0x70, BR_PROC_SYS_GetSlotId(((struct CodeinArgA *)arg)->procQuery));
    MI_CpuFill8(p, 0, 0x70);
    ((struct CodeinWorkA *)p)->resultHeapId = BR_PROC_SYS_GetSlotId(((struct CodeinArgA *)arg)->procQuery);
    ((struct CodeinWorkA *)p)->oamSys = BMP_OAM_CreateSys(((struct CodeinWorkA *)p)->resultHeapId, (*(void * *)&((struct CodeinArgA *)arg)->screenFade));
    ((struct CodeinWorkA *)p)->printQue = (void *)PRINTSYS_QUE_Create((void *)(((struct CodeinWorkA *)p)->resultHeapId));
    ((struct CodeinWorkA *)p)->resultFx = BR_UTIL_CreateHandles((unsigned int)((*(void * *)&((struct CodeinArgA *)arg)->screenFade)), (char *)(((struct CodeinArgA *)arg)->res), 1, ((struct CodeinWorkA *)p)->resultHeapId);
    BR_CODEIN_ResultSetupTextWin(p, arg);
    BR_CODEIN_ResultSetupButtons(p, arg);
    return 1;
}









int BR_CODEIN_ResultDestroy(void *proc, int seq, char *arg, struct CodeinWorkA *work)
{
    BR_CODEIN_ResultTeardown(work, arg);
    BR_CODEIN_ResultDeleteButtons(work, arg);
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(1);
    BR_UTIL_DeleteHandles(work->resultFx);
    PRINTSYS_QUE_Delete(work->printQue);
    BMP_OAM_DeleteSys(work->oamSys);
    PROCSYS_FreeProcWork(proc);
    return 1;
}









int BR_CODEIN_ResultMain(void *unused,u32 *state,char *arg,struct CodeinWorkA *work)
{
 int x,y,i;
 Point pair;
 switch(*state){
 case 0:BR_FADE_Start(((struct CodeinArgA *)arg)->actorSys,2,3,0);*state=1;break;
 case 1:if(BR_FADE_GetResult(*(int * *)&((struct CodeinArgA *)arg)->actorSys)) *state=2;break;
 case 2:
  if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))){
   work->resultChoice=BR_CODEIN_ResultHitButton(work,x,y);
   if(work->resultChoice) *state=3;
   if(BR_BTN_HitTestWithSound((unsigned int *)((*(int *)&work->backButton)),x,y)){
    pair.x=x;pair.y=y;
    BR_UTIL_StartEffect((void *)(*(int *)&work->resultFx), 1, &pair);
    *state=7;
   }
  }break;
 case 3:BR_FADE_Start(((struct CodeinArgA *)arg)->actorSys,2,1,1);++*state;break;
 case 4:if(BR_FADE_GetResult(*(int * *)&((struct CodeinArgA *)arg)->actorSys)) ++*state;break;
 case 5:
  BR_CODEIN_ResultTeardown(work,arg);
  switch(*(u32 *)&work->resultChoice){
  case 1:BR_CODEIN_ResultSetupRowA(work,arg);break;
  case 2:BR_CODEIN_ResultSetupRowB(work,arg);break;
  case 3:BR_CODEIN_ResultSetupRowC(work,arg);break;
  }
  BR_FADE_Start(((struct CodeinArgA *)arg)->actorSys,2,1,0);++*state;break;
 case 6:if(BR_FADE_GetResult(*(int * *)&((struct CodeinArgA *)arg)->actorSys)) *state=2;break;
 case 7:BR_FADE_Start(((struct CodeinArgA *)arg)->actorSys,2,3,1);*state=8;break;
 case 8:if(BR_FADE_GetResult(*(int * *)&((struct CodeinArgA *)arg)->actorSys)) *state=9;break;
 case 9:BR_PROC_SYS_PopEntry(((struct CodeinArgA *)arg)->procQuery);return 1;
 }
 for(i=0;i<3;i++) if(*(void **)((char *)work+i*4+0x10)) BR_UTIL_FlushText(*(void **)((char *)work+i*4+0x10));
 for(i=0;i<18;i++) if(*(void **)((char *)work+i*4+0x1c)) BR_UTIL_FlushText(*(void **)((char *)work+i*4+0x1c));
 PRINTSYS_QUE_Main(work->printQue);
 BR_UTIL_RunHandles(work->resultFx);
 if(work->textWin)BR_UTIL_FlushWindow(work->textWin);
 return 0;
}









void BR_CODEIN_ResultSetupTextWin(char *work, char *arg)
{
    ((struct CodeinWorkA *)work)->textWin = BR_UTIL_CreateTextWin(((struct CodeinArgA *)arg)->res, (void *)(*(int *)&((struct CodeinWorkA *)work)->printQue), ((struct CodeinWorkA *)work)->resultHeapId);
    BR_UTIL_SetWindowText(((struct CodeinWorkA *)work)->textWin, (char *)(((struct CodeinArgA *)arg)->res), (void *)0x86);
}









/*
 * lever: declaring text before i/flag restores the original stack slots.
 */
void BR_CODEIN_ResultSetupRowA(struct CodeinWorkA *work,char *arg)
{
    int font, bank, words;
    struct U16Vec *text;
    int i, flag;
    const Record *rec;
    char *slot;
    void *base;
    font=BR_RES_GetFont(*(char * *)&((struct CodeinArgA *)arg)->res);
    bank=BR_RES_GetMsgData(*(char * *)&((struct CodeinArgA *)arg)->res);
    words=BR_RES_GetWordSet(*(char * *)&((struct CodeinArgA *)arg)->res);
    BR_RES_LoadBgGraphics((void *)(((struct CodeinArgA *)arg)->res),16,work->resultHeapId);
    for(i=0;i<12;i++) {
        flag=1;
        rec=&d_021E3574[i];
        slot=(char *)work+i*4;
        ((struct CodeinSlotA *)slot)->rowText=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->resultHeapId);
        BR_UTIL_SetTextLayout(((struct CodeinSlotA *)slot)->rowText,0,1,0);
        switch(i) {
        case 0: WORDSET_SetSlotMyStatus((struct WordSet *)words,0,GAME_DATA_GetMyStatus((*(void * *)&((struct CodeinArgA *)arg)->uiRes))); break;
        case 7: WORDSET_SetSlotNumber((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)arg)->bsubwaySave,5,0),4,1,1); break;
        case 8: WORDSET_SetSlotNumber((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)arg)->bsubwaySave,6,0),4,1,1); break;
        case 9: WORDSET_SetSlotNumber((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)arg)->bsubwaySave,7,0),4,1,1); break;
        case 10: WORDSET_SetSlotNumber((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)arg)->bsubwaySave,8,0),4,1,1); break;
        case 11: WORDSET_SetSlotNumber((struct WordSet *)words,0,BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)arg)->bsubwaySave,9,0),4,1,1); break;
        default: text=MSGDATA_AllocString((struct MsgBank *)bank,rec->value); flag=0; break;
        }
        if(flag) {
            base=MSGDATA_AllocString((struct MsgBank *)bank,rec->value);
            text=STRBUF_Create(128,work->resultHeapId);
            WORDSET_CopyTaggedText((struct WordSet *)words,text,base);
            STRBUF_Delete(base);
        }
        BR_UTIL_SetTextFromBuffer(*(char * *)&((struct CodeinSlotA *)slot)->rowText,text,(void *)font,0x3da0);
        STRBUF_Delete(text);
    }
}









void BR_CODEIN_ResultSetupRowB(struct CodeinWorkA *work,char *arg)
{
    int font, bank, words, i, flag, value;
    const Record *rec;
    char *slot;
    struct U16Vec *text;
    void *base;
    font=BR_RES_GetFont(*(char * *)&((struct CodeinArgA *)arg)->res);
    bank=BR_RES_GetMsgData(*(char * *)&((struct CodeinArgA *)arg)->res);
    words=BR_RES_GetWordSet(*(char * *)&((struct CodeinArgA *)arg)->res);
    BR_RES_LoadBgGraphics((void *)(((struct CodeinArgA *)arg)->res),17,work->resultHeapId);
    for(i=0;i<18;i++) {
        rec=&d_021E3664[i];
        slot=(char *)work+i*4;
        ((struct CodeinSlotA *)slot)->rowText=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->resultHeapId);
        BR_UTIL_SetTextLayout(((struct CodeinSlotA *)slot)->rowText,0,1,0);
        if(i>=8 && i<=12) {value=BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)arg)->bsubwaySave,i-3,1);flag=1;}
        else if(i>=13 && i<=17) {value=BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)arg)->bsubwaySave,i-8,2);flag=1;}
        else {text=MSGDATA_AllocString((struct MsgBank *)bank,rec->value);flag=0;}
        if(flag) {
            base=MSGDATA_AllocString((struct MsgBank *)bank,rec->value);
            text=STRBUF_Create(128,work->resultHeapId);
            WORDSET_SetSlotNumber((struct WordSet *)words,0,value,5,1,1);
            WORDSET_CopyTaggedText((struct WordSet *)words,text,base);
            STRBUF_Delete(base);
        }
        BR_UTIL_SetTextFromBuffer(*(char * *)&((struct CodeinSlotA *)slot)->rowText,text,(void *)font,0x3da0);
        STRBUF_Delete(text);
    }
}









void BR_CODEIN_ResultSetupRowC(struct CodeinWorkA *work,char *arg)
{
    int font, bank, words, i, flag, value;
    const Record *rec;
    char *slot;
    struct U16Vec *text;
    void *base;
    font=BR_RES_GetFont(*(char * *)&((struct CodeinArgA *)arg)->res);
    bank=BR_RES_GetMsgData(*(char * *)&((struct CodeinArgA *)arg)->res);
    words=BR_RES_GetWordSet(*(char * *)&((struct CodeinArgA *)arg)->res);
    BR_RES_LoadBgGraphics((void *)(((struct CodeinArgA *)arg)->res),17,work->resultHeapId);
    for(i=0;i<18;i++) {
        rec=&d_021E35D4[i];
        slot=(char *)work+i*4;
        ((struct CodeinSlotA *)slot)->rowText=BR_UTIL_Create(1,rec->a,rec->b,rec->c,rec->d,14,work->printQue,work->resultHeapId);
        BR_UTIL_SetTextLayout(((struct CodeinSlotA *)slot)->rowText,0,1,0);
        if(i>=8 && i<=12) {value=BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)arg)->bsubwaySave,i-8,1);flag=1;}
        else if(i>=13 && i<=17) {value=BSUBWAY_SAVEDATA_GetStat(*(Row * *)&((struct CodeinArgA *)arg)->bsubwaySave,i-13,2);flag=1;}
        else {text=MSGDATA_AllocString((struct MsgBank *)bank,rec->value);flag=0;}
        if(flag) {
            base=MSGDATA_AllocString((struct MsgBank *)bank,rec->value);
            text=STRBUF_Create(128,work->resultHeapId);
            WORDSET_SetSlotNumber((struct WordSet *)words,0,value,5,1,1);
            WORDSET_CopyTaggedText((struct WordSet *)words,text,base);
            STRBUF_Delete(base);
        }
        BR_UTIL_SetTextFromBuffer(*(char * *)&((struct CodeinSlotA *)slot)->rowText,text,(void *)font,0x3da0);
        STRBUF_Delete(text);
    }
}









/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 */
void BR_CODEIN_ResultTeardown(struct CodeinWorkA *work, char *arg)
{
    int i;
    for (i = 0; i < 18; i++) {
        char *slot = (char *)work + i * 4;
        if (((struct CodeinSlotA *)slot)->rowText != 0) {
            BR_UTIL_Delete(((struct CodeinSlotA *)slot)->rowText);
            ((struct CodeinSlotA *)slot)->rowText = 0;
        }
    }
    BR_RES_ApplyBgSet(((struct CodeinArgA *)arg)->res, 17);
    if (work->textWin != 0) {
        BR_UTIL_DeleteTextWin(work->textWin, ((struct CodeinArgA *)arg)->res);
        work->textWin = 0;
    }
}









/*
 * lever: bank/words declaration order selects their original stack slots.
 * omits MSGDATA_ReadString from its function header. Existing C verified EXACT
 * (344 bytes, 12/12 relocations; ARM9-45CAC-one.log, terminal exit 0).
 * typedef unsigned char  u8;
 * typedef unsigned short u16;
 * typedef unsigned int   u32;
 *
 * struct MsgEntry {
 *     u32 off;
 *     u16 len;
 *     u16 pad_06;
 * };
 *
 * struct MsgFile {
 *     u16 langCount;
 *     u16 count;
 *     u32 unk_04;
 *     u32 unk_08;
 *     u32 langOff[1];
 * };
 *
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void                 *base;
 *     struct MsgEntry       cache;
 *     u32                   origin;
 *     void                 *stream;
 *     u16                   heapId;
 *     u8                    langIndex;
 *     u8                    resident;
 * };
 *
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
 *                           u16 tag);
 * extern void GFL_HEAP_Free(void *p);
 * extern void ARC_TOOL_ReadHandle(void *stream, u32 size, void *dest);
 * extern void ARC_TOOL_SeekHandle(void *stream, u32 pos);
 * extern void STRBUF_Clear(void *dest);
 * extern void STRBUF_SetChars(void *dest, const void *src, u16 len);
 * extern void MSGDATA_DecryptStrbuf(void *dest, u32 index);
 * extern u8 MSGDATA_GetLanguageIndex(const void *file);
 * extern void MSGDATA_LoadBank(struct MsgBank *bank);
 * extern void MSGDATA_RefreshLanguage(struct MsgBank *bank);
 *
 * void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *
 *     MSGDATA_RefreshLanguage(bank);
 *
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *
 *         ARC_TOOL_SeekHandle(bank->stream, pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *
 *     if (bank->resident == 0) {
 *         void *buf;
 *
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000), size,
 *                            0, MSGDATA_AllocSite, 0xd6);
 *         if (buf != 0) {
 *             ARC_TOOL_SeekHandle(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *             STRBUF_SetChars(dest, buf, e->len);
 *             GFL_HEAP_Free(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 *
 *     MSGDATA_DecryptStrbuf(dest, index);
 * }
 */
void BR_CODEIN_ResultSetupButtons(char *work,char *arg)
{
    int font,words,bank,i;
    Params config;
    Triple triple;
    struct U16Vec *base,*text;
    void *value;
    const Record *rec;
    char *slot;
    BR_RES_LoadSprite(*(char **)(arg+8),6,*(u16 *)(work+0x6c));
    BR_RES_LoadBgGraphics((void *)(*(int *)(arg+8)),15,*(u16 *)(work+0x6c));
    font=BR_RES_GetFont(*(char **)(arg+8));
    bank=BR_RES_GetMsgData(*(char **)(arg+8));
    words=BR_RES_GetWordSet(*(char **)(arg+8));
    MI_CpuFill8(&config,0,8);
    config.a=80; config.b=168; config.c=0; config.flag=1;
    BR_RES_GetSprite((void *)(*(void **)(arg+8)), 6, (Triple *)&triple);
    *(void **)(work+0xc)=BR_BTN_CreateFromMessage(&config,4,96,1,*(int *)arg,*(int *)work,font,bank,&triple,*(u16 *)(work+0x6c));
    base=STRBUF_Create(128,*(u16 *)(work+0x6c));
    text=STRBUF_Create(128,*(u16 *)(work+0x6c));
    value=GAME_DATA_GetMyStatus(*(void **)(arg+0x10));
    for(i=0;i<3;i++) {
        rec=&d_021E351C[i];
        slot=work+i*4;
        *(void **)(slot+0x10)=BR_UTIL_Create(4,rec->a,rec->b,rec->c,rec->d,14,*(void **)(work+4),*(u16 *)(work+0x6c));
        if(i==0) {
            MSGDATA_ReadString((struct MsgBank *)bank,rec->value,base);
            WORDSET_SetSlotMyStatus((struct WordSet *)words,0,value);
            WORDSET_CopyTaggedText((struct WordSet *)words,text,base);
        } else MSGDATA_ReadString((struct MsgBank *)bank,rec->value,text);
        BR_UTIL_SetTextFromBuffer(*(char **)(slot+0x10),text,(void *)font,0x3da0);
    }
    STRBUF_Delete(base);
    STRBUF_Delete(text);
}









void BR_CODEIN_ResultDeleteButtons(struct CodeinWorkA *work, char *arg)
{
    int i;
    for (i = 0; i < 3; i++) {
        char *slot = (char *)work + i * 4;
        if (((struct CodeinWorkC *)slot)->resultText) {
            BR_UTIL_Delete(((struct CodeinWorkC *)slot)->resultText);
            ((struct CodeinWorkC *)slot)->resultText = 0;
        }
    }
    if (work->backButton) {
        BR_BTN_DeleteObject(work->backButton);
        work->backButton = 0;
    }
    BR_RES_ReleaseSprite((char *)(((struct CodeinArgA *)arg)->res), 6);
    BR_RES_ApplyBgSet(((struct CodeinArgA *)arg)->res, 15);
}









int BR_CODEIN_ResultHitButton(struct CodeinWorkA *work, int x, int y)
{
    int skip = work->resultChoice;
    int i;
    for (i = 0; i < 4; i++) {
        if (i != skip && (u32)(x - d_021E3534[i].x0) <= d_021E3534[i].x1 - d_021E3534[i].x0 &&
            (u32)(y - d_021E3534[i].y0) <= d_021E3534[i].y1 - d_021E3534[i].y0) {
            Point args;
            args.x = x;
            args.y = y;
            BR_UTIL_StartEffect((void *)(*(int *)&work->resultFx), 1, &args);
            GFL_USE_PlaySeDefaultVolume(0x703);
            return i;
        }
    }
    return 0;
}









int BR_CODEIN_StatCreate(void *proc, int seq, char *arg)
{
    struct CodeinWorkD *p = PROCSYS_AllocProcWork(proc, 0x10C, BR_PROC_SYS_GetSlotId((*(void * *)&((struct CodeinArgA *)arg)->bsubwaySave)));
    int i;
    MI_CpuFill8(p, 0, 0x10C);
    p->statCtx = arg;
    p->heapId = BR_PROC_SYS_GetSlotId((*(void * *)&((struct CodeinArgA *)arg)->bsubwaySave));
    p->oamSys = BMP_OAM_CreateSys(p->heapId, ((struct CodeinArgA *)arg)->procQuery);
    p->printQue = (void *)PRINTSYS_QUE_Create((void *)(p->heapId));
    for (i = 0; i < 2; i++)
        *(void **)((char *)p + i * 4 + 0x1C) = BR_UTIL_CreateHandles((unsigned int)(((struct CodeinArgA *)arg)->procQuery), (char *)(((struct CodeinArgA *)arg)->uiRes), i, p->heapId);
    p->task = BR_UTIL_CreateTask((int)p, (int)BR_CODEIN_SearchStepText, p->heapId);
    if (((struct CodeinSubA *)(p->statCtx))->saveFade != 0)
        BR_UTIL_SetTaskStep(p->task, (int)BR_CODEIN_StatSetup);
    else
        BR_UTIL_SetTaskStep(p->task, (int)BR_CODEIN_SearchStepText);
    return 1;
}









int BR_CODEIN_StatDestroy(void *proc, int seq, struct CodeinArgA *arg, struct CodeinWorkD *work)
{
    int i;
    if (work->listCreated != 0) {
        BR_CODEIN_SearchDeleteList((char *)work + 0x28);
        work->listCreated = 0;
    }
    if (work->titleText != 0) {
        BR_UTIL_Delete(work->titleText);
        work->titleText = 0;
    }
    if (work->headerText != 0) {
        BR_UTIL_Delete(work->headerText);
        work->headerText = 0;
    }
    if (work->backButton != 0) {
        BR_BTN_DeleteObject(work->backButton);
        work->backButton = 0;
    }
    if (work->spriteLoaded != 0) {
        BR_RES_ReleaseSprite((*(void * *)&((struct CodeinSubA *)(work->statCtx))->res), 6);
        BR_RES_ApplyBgSet((int)((*(void * *)&((struct CodeinSubA *)(work->statCtx))->res)), 24);
        work->spriteLoaded = 0;
    }
    BR_UTIL_DeleteTask(work->task);
    if (work->textWin != 0) {
        BR_UTIL_DeleteTextWin(work->textWin, arg->uiRes);
        work->textWin = 0;
    }
    for (i = 0; i < 2; i++) BR_UTIL_DeleteHandles(*(void **)((char *)work + 0x1C + i * 4));
    BMP_OAM_DeleteSys(work->oamSys);
    PRINTSYS_QUE_Delete(work->printQue);
    PROCSYS_FreeProcWork(proc);
    return 1;
}









int BR_CODEIN_StatMain(int proc, int seq, int arg, struct CodeinWorkD *work)
{
    int i;
    if (BR_NET_HandleNetError(((struct CodeinSubA *)(work->statCtx))->net) == 2) {
        BR_PROC_SYS_FlushWindows((*(void * *)&((struct CodeinSubA *)(work->statCtx))->procQuery));
        return 1;
    }
    BR_UTIL_RunTask(work->task);
    if (BR_UTIL_IsTaskIdle(work->task) != 0) return 1;
    for (i = 0; i < 2; i++) BR_UTIL_RunHandles(*(void **)((char *)work + 0x1C + i * 4));
    PRINTSYS_QUE_Main(work->printQue);
    if (work->headerText != 0) BR_UTIL_FlushText(work->headerText);
    if (work->titleText != 0) BR_UTIL_FlushText(work->titleText);
    if (work->textWin != 0) BR_UTIL_FlushWindow(work->textWin);
    return 0;
}









void BR_CODEIN_StatSetup(int *task,int *state,struct CodeinWorkD *work)
{
    int font,bank;
    Params config;
    Triple triple;
    font=BR_RES_GetFont(*(char * *)&((struct CodeinSubA *)(work->statCtx))->res);
    bank=BR_RES_GetMsgData(*(char * *)&((struct CodeinSubA *)(work->statCtx))->res);
    if(work->textWin) {
        BR_UTIL_DeleteTextWin(work->textWin,((struct CodeinSubA *)(work->statCtx))->res);
        work->textWin=0;
    }
    BR_RES_LoadBgGraphics((void *)(((struct CodeinSubA *)(work->statCtx))->res),24,work->heapId);
    BR_RES_LoadSprite(*(char * *)&((struct CodeinSubA *)(work->statCtx))->res,6,work->heapId);
    work->spriteLoaded=1;
    MI_CpuFill8(&config,0,8);
    config.a=80;config.b=168;config.c=0;config.flag=1;
    if(!BR_RES_GetSprite((void *)((*(void * *)&((struct CodeinSubA *)(work->statCtx))->res)), 6, (Triple *)&triple))
        GF_PANIC_Fail(d_021E3964,0,d_021E3964);
    work->backButton=BR_BTN_CreateFromMessage(&config,4,96,1,(*(int *)&((struct CodeinSubA *)(work->statCtx))->subFade),(*(int *)&work->oamSys),font,bank,&triple,work->heapId);
    work->headerText=BR_UTIL_Create(4,11,6,10,4,14,work->printQue,work->heapId);
    BR_UTIL_SetTextFromMessage(*(char * *)&work->headerText,(void *)bank,(void *)0x55,(void *)font,0x3da0);
    work->titleText=BR_UTIL_Create(1,3,3,26,4,14,work->printQue,work->heapId);
    BR_UTIL_SetTextLayout(work->titleText,0,1,0);
    BR_UTIL_SetTextFromMessage(*(char * *)&work->titleText,(void *)bank,(void *)(**(int * *)&work->statCtx+0x57),(void *)font,0x3da0);
    BR_CODEIN_SearchCreateList((Menu *)((char *)work+0x28), ((struct CodeinSubA *)(work->statCtx))->menuState, *(char * *)&((struct CodeinSubA *)(work->statCtx))->res, (*(int *)&((struct CodeinSubA *)(work->statCtx))->subFade), (u32)(work->listParam), (u32)((*(void * *)&work->tapFx)), *(u16 * *)&((struct CodeinSubA *)(work->statCtx))->gameData, work->heapId);
    work->listCreated=1;
    BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_StatStepFadeIn);
}









void BR_CODEIN_StatTeardown(void *proc, int seq, struct CodeinWorkD *work)
{
    BR_CODEIN_SearchDeleteList((char *)work + 0x28);
    work->listCreated = 0;
    BR_UTIL_Delete(work->titleText);
    work->titleText = 0;
    BR_UTIL_Delete(work->headerText);
    work->headerText = 0;
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(1);
    BR_BTN_DeleteObject(work->backButton);
    work->backButton = 0;
    BR_RES_ReleaseSprite((*(void * *)&((struct CodeinSubA *)(work->statCtx))->res), 6);
    BR_RES_ApplyBgSet((int)((*(void * *)&((struct CodeinSubA *)(work->statCtx))->res)), 24);
    work->spriteLoaded = 0;
    BR_UTIL_ClearTaskStep((int *)proc);
}









void BR_CODEIN_StatStepFadeIn(int *task, int *state, struct CodeinWorkD *work)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((int)((*(void * *)&((struct CodeinSubA *)(work->statCtx))->screenFade)), 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult(((struct CodeinSubA *)(work->statCtx))->screenFade) != 0) *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(task, (int)BR_CODEIN_StatStepMenu);
        break;
    }
}









void BR_CODEIN_StatStepFadeOut(int *work, int *state, struct CodeinArgA *arg)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((int)(((struct CodeinSubA *)(arg->statCtx))->screenFade), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult(((struct CodeinSubA *)(arg->statCtx))->screenFade) != 0) *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(work, (int)BR_CODEIN_StatTeardown);
        break;
    }
}









void BR_CODEIN_StatStepMenu(int *task, int *state, char *work)
{
    u32 x,y;
    BR_CODEIN_SearchMainList(work+0x28,((struct CodeinWorkD *)work)->heapId);
    if (TOUCHPANEL_GetPointTrg(&x,&y)) {
        if (BR_BTN_HitTestWithSound((unsigned int *)((*(int *)&((struct CodeinWorkD *)work)->backButton)),x,y)) {
            Point args;
            args.x=x; args.y=y;
            BR_UTIL_StartEffect((void *)(((struct CodeinWorkD *)work)->tapFx), 1, &args);
            BR_PROC_SYS_PopEntry((*(void * *)&((struct CodeinSubA *)(((struct CodeinWorkD *)work)->statCtx))->procQuery));
            BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_StatStepFadeOut);
        }
        if (BR_CODEIN_SearchHitBox(x,y)) {
            u32 selection;
            Point args;
            selection=BR_CODEIN_SearchGetHitId(work+0x28);
            if (selection>=((struct CodeinSubA *)(((struct CodeinSubA *)(((struct CodeinWorkD *)work)->statCtx))->menuState))->itemCount)
                GF_PANIC_Fail(d_021E3964,0,d_021E3964);
            ((struct CodeinSubA *)(((struct CodeinSubA *)(((struct CodeinWorkD *)work)->statCtx))->menuState))->selection=selection;
            BR_PROC_SYS_PushEntry(*(unsigned * *)&((struct CodeinSubA *)(((struct CodeinWorkD *)work)->statCtx))->procQuery,2);
            BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_StatStepFadeOut);
            args.x=x; args.y=y;
            BR_UTIL_StartEffect((void *)(((struct CodeinWorkD *)work)->tapFx), 1, &args);
        }
    }
}







void BR_CODEIN_SearchStep(int *task,u32 *state,char *work)
{
    switch(*state) {
    case 0: {
        Point initial;
        int mode;
        MI_CpuFill8(&initial,0,8);
        switch(**(u32 **)(work+0x108)) {
        case 0: mode=5; break;
        case 1: mode=6; break;
        case 2: mode=7; break;
        case 3: initial=*(Point *)(*(char **)(work+0x108)+0x20); mode=4; break;
        default: GF_PANIC_Fail(d_021E3964,0,d_021E3964); break;
        }
        MI_CpuFill8(*(void **)(*(char **)(work+0x108)+0x1c),0,0x1720);
        *(u32 *)(work+0xfc)=0;
        BR_NET_StartRequest(*(void **)(*(char **)(work+0x108)+0x18),mode,(const int *)(&initial));
        *state=1; break;
    }
    case 1:
        ++*(u32 *)(work+0xfc);
        if(BR_NET_IsIdle(*(char **)(*(char **)(work+0x108)+0x18)) && *(u32 *)(work+0xfc)>96) {
            BR_UTIL_StartEffect((void *)(*(int *)(work+0x1c)), 0, 0); *state=2;
        } break;
    case 2: {
        int message,success,i;
        struct CodeinRecordData *data;
        enum { COUNT_OFFSET=0x1718 } offset;
        data=*(struct CodeinRecordData **)(*(char **)(work+0x108)+0x1c);
        offset=COUNT_OFFSET;
        if(!BR_NET_PollErrorMessage(*(void **)(*(char **)(work+0x108)+0x18),&message)) {
            switch(**(u32 **)(work+0x108)) {
            case 0: success=BR_NET_GetSearchResultsForRanking(*(void **)(*(char **)(work+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 1: success=BR_NET_GetSearchResultsForRanking(*(void **)(*(char **)(work+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 2: success=BR_NET_GetSearchResultsForNewest(*(void **)(*(char **)(work+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            case 3: success=BR_NET_GetSearchResults(*(void **)(*(char **)(work+0x108)+0x18),data,30,(void *)((u32)data+offset)); break;
            default: GF_PANIC_Fail(d_021E3964,0,d_021E3964); break;
            }
            if(success) {
                for(i=0;i<(*(struct CodeinRecordData **)(*(char **)(work+0x108)+0x1c))->count;i++) {
                    *(u8 *)(*(char **)(*(char **)(work+0x108)+0x1c)+i+0x16f8)=(u8)BATTLE_REC_GetHeaderParam((u8 *)(*(char **)(*(char **)(work+0x108)+0x1c)+i*0xc4+0x80),5,0);
                }
                BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_SearchStepFade);
            } else {
                if(**(u32 **)(work+0x108)==3) BR_UTIL_SetWindowText(*(void **)(work+0x24),(char *)(*(int *)(*(char **)(work+0x108)+0x10)),(void *)276);
                else BR_UTIL_SetWindowText(*(void **)(work+0x24),(char *)(*(int *)(*(char **)(work+0x108)+0x10)),(void *)339);
                *state=3;
            }
        } else {
            BR_UTIL_SetWindowText(*(void **)(work+0x24),(char *)(*(int *)(*(char **)(work+0x108)+0x10)),(void *)message);
            *state=3;
        } break;
    }
    case 3: {
        u32 x,y;
        Point clicked;
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);
            clicked.x=x; clicked.y=y;
            BR_UTIL_StartEffect((void *)(*(int *)(work+0x20)), 1, &clicked);
            GFL_USE_PlaySeDefaultVolume(0x703);
            BR_FADE_Start(*(int *)(*(char **)(work+0x108)+8),2,3,1);
            *state=4;
        } break;
    }
    case 4:
        if(BR_FADE_GetResult(*(int **)(*(char **)(work+0x108)+8))) *state=5;
        break;
    case 5:
        BR_PROC_SYS_PopEntry(*(void **)(*(char **)(work+0x108)+0x14)); BR_UTIL_ClearTaskStep((int *)task); break;
    }
}







void BR_CODEIN_SearchStepText(int *work, int *state, struct CodeinArgA *arg)
{
    Point args;
    switch (*state) {
    case 0:
        if (arg->textWin == 0) {
            arg->textWin = (int)BR_UTIL_CreateTextWin(((struct CodeinSubA *)(arg->statCtx))->res, (void *)(arg->bsubwaySave), arg->heapId);
        }
        if (**(int * *)&arg->statCtx == 3) {
            BR_UTIL_SetWindowText((char *)(arg->textWin), (char *)(((struct CodeinSubA *)(arg->statCtx))->res), (void *)0x14B);
        } else {
            BR_UTIL_SetWindowText((char *)(arg->textWin), (char *)(((struct CodeinSubA *)(arg->statCtx))->res), (void *)0x13E);
        }
        args.x = 0x80;
        args.y = 0x60;
        BR_UTIL_StartEffect((void *)(arg->tapFx), 4, &args);
        *state = 1;
        break;
    case 1:
        BR_FADE_Start((int)(((struct CodeinSubA *)(arg->statCtx))->screenFade), 2, 3, 0);
        *state = 2;
        break;
    case 2:
        if (BR_FADE_GetResult(((struct CodeinSubA *)(arg->statCtx))->screenFade) != 0) *state = 3;
        break;
    case 3:
        BR_UTIL_SetTaskStep(work, (int)BR_CODEIN_SearchStep);
        break;
    }
}







void BR_CODEIN_SearchStepFade(int *work, int *state, struct CodeinArgA *arg)
{
    switch (*state) {
    case 0:
        BR_FADE_Start((int)(((struct CodeinSubA *)(arg->statCtx))->screenFade), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult(((struct CodeinSubA *)(arg->statCtx))->screenFade) != 0) *state = 2;
        break;
    case 2:
        BR_UTIL_SetTaskStep(work, (int)BR_CODEIN_StatSetup);
        break;
    }
}





void BR_CODEIN_SearchCreateList(Menu *menu,char *base,char *res,u32 mgr,u32 listParam,u32 tapFx,u16 *sel,u16 heap)
{
    unsigned first,second;
    int i;
    void *bmp;
    void *buf1,*msg,*buf2;
    CodeinListMenuConfig cfg;
    first=BR_RES_GetFont(res);
    second=BR_RES_GetMsgData(res);
    MI_CpuFill8(menu,0,0xd4);
    menu->base=base;
    menu->words=WORDSET_CreateDefault(heap);
    menu->c=listParam;
    menu->d=tapFx;
    menu->list=BMP_MENUWORK_Create(*(u32 *)(base+0x1718),heap);
    for(i=0;i<*(int *)(base+0x1718);i++)menu->list[i].b=i;
    *(CfgTpl *)&cfg=d_021E3700;
    cfg.list=(Item *)menu->list;
    cfg.count=*(u32 *)(base+0x1718);
    cfg.resources=res;
    cfg.manager=mgr;
    cfg.cursor=menu->c;
    cfg.other=menu->d;
    cfg.selection=sel;
    menu->view=BR_UTIL_CreateListMenu((const CodeinListMenuConfig *)&cfg, heap);
    buf1=STRBUF_Create(0xff,heap);
    msg=MSGDATA_AllocString((struct MsgBank *)second,0x7a);
    buf2=STRBUF_Create(0xff,heap);
    for(i=0;i<*(int *)(base+0x1718);i++){
        bmp=BMP_Create(cfg.width,cfg.spacing,0x20,heap);
        BMP_Clear(bmp,0);
        WORDSET_SetSlotNumber(menu->words,0,i+1,2,0,1);
        WORDSET_CopyTaggedText(menu->words,buf1,msg);
        STRBUF_SetString(buf2,(const u16 *)(base+i*0xc4));
        PRINTSYS_PrintColor(bmp,(short)(16-PRINTSYS_MeasureWidestLine(buf1,first,0)),4,buf1,(void *)first,0x3DA0);
        PRINTSYS_PrintColor(bmp,0x14,4,buf2,(void *)first,0x3DA0);
        BR_UTIL_SetListItemBitmap(menu->view,(u16)i,(u32)bmp);
    }
    STRBUF_Delete(buf2);
    STRBUF_Delete(buf1);
    STRBUF_Delete(msg);
    BR_UTIL_RefreshList(menu->view);
    BR_CODEIN_SearchCreateActor((struct CodeinSearchState *)menu,mgr,heap);
    for(i=0;i<*sel;i++)BR_CODEIN_SearchUpdateActor((struct CodeinSearchState *)menu,i+1,1,heap);
}





/*
 * trailing: two zero alignment bytes at 0x021DF3DA
 */
void BR_CODEIN_SearchDeleteList(char *work)
{
    unsigned int i;
    BR_CODEIN_SearchDeleteActor(work);
    for (i = 0; i < BR_UTIL_GetListMenuField(((struct CodeinWorkG *)work)->listMenu, 3); i++) {
        BMP_Delete((struct Bmp *)BR_UTIL_GetListItemBitmap(((struct CodeinWorkG *)work)->listMenu, i));
    }
    WORDSET_Delete(((struct CodeinWorkG *)work)->wordSet);
    BR_UTIL_DeleteListMenu(((struct CodeinWorkG *)work)->listMenu);
    BMP_MENUWORK_Delete(((struct CodeinWorkG *)work)->menuWork);
    MI_CpuFill8(work, 0, 0xD4);
}





/*
 * trailing: two zero alignment bytes at 0x021DF41A
 */
void BR_CODEIN_SearchMainList(char *work, u16 heapId)
{
    unsigned int old, current;
    s8 direction;
    old = BR_UTIL_GetListMenuField(((struct CodeinWorkD *)work)->backButton, 1);
    BR_UTIL_MainListMenu(((struct CodeinWorkD *)work)->backButton);
    current = BR_UTIL_GetListMenuField(((struct CodeinWorkD *)work)->backButton, 1);
    direction = BR_UTIL_GetListMenuField(((struct CodeinWorkD *)work)->backButton, 2);
    if (direction != 0 && old != current) BR_CODEIN_SearchUpdateActor((struct CodeinSearchState *)work, current, direction, heapId);
}








int BR_CODEIN_SearchGetHitId(char *work)
{
    return BR_UTIL_GetListMenuHitId(*(char * *)&((struct CodeinWorkA *)work)->printQue);
}








/*
 * 2026-10-05 (wave P6 lane U1b): EXACT. Types from matched ov183 021DF1DC (Menu: base
 * at +0xD0) and 021DF620 (State layout). Two fixes closed the earlier 24 B residue:
 * heap is a u16 parameter (it is only masked and passed to u16-style callees; the
 * narrow type moves its home store before mgr's), and the clamp is a ternary
 * `n = (n >= 5) ? 5 : n;` which gives n the lowest spill slot, under the loop temps.
 * Final call is an if/else with a call in each arm.
 */
void BR_CODEIN_SearchCreateActor(struct CodeinSearchState *search,u32 mgr,u16 heap)
{
    int i,j;
    void *archive;
    u32 mode,species;
    int n;
    struct Entries e;
    struct Pos pos;
    n=*(int *)(search->source+0x1718);
    n=(n>=5)?5:n;
    mode=(heap&0x7fff)|0x8000;
    archive=ARC_TOOL_CreateHandle(7,(u16)mode);
    i=0;
    search->shared0=CLACT_RegisterPaletteCompressed(archive,POKE_TOOL_GetIconPaletteArcId(),0,0x80,heap);
    search->shared1=CLACT_RegisterCellAnim(archive,POKE_TOOL_GetIconCellArcId(),POKE_TOOL_GetIconCellEntryId(),heap);
    MI_CpuFill8(&pos,0,8);
    pos.z=1;
    pos.a=i;
    pos.b=i;
    for(i=0;i<n;i++) {
        BR_CODEIN_SearchBuildHeader((int)(search->source+i*0xc4),(char *)(&e));
        for(j=0;j<6;j++) {
            species=e.species[j];
            if(species==0) species=1;
            search->indices[i][j]=CLACT_RegisterCharacter(archive,POKE_TOOL_CalcGraphicIndex(species,e.form[j],e.gender[j],0),0,0,heap);
            pos.x=j*0x18+0x6e;
            pos.y=i*0x18+0x48;
            pos.a=6-j;
            search->sprites[i][j]=CLACT_CreateActor((void *)mgr,search->indices[i][j],search->shared0,search->shared1,&pos,0,heap);
            CLACT_SetActorPaletteOffset(search->sprites[i][j],POKE_TOOL_CalcIconPalette(species,e.form[j],e.gender[j],0),0);
            CLACT_SetActorObjMode(search->sprites[i][j],1);
            if(e.species[j]==0) CLACT_SetActorDrawEnable(search->sprites[i][j],0);
            else CLACT_SetActorDrawEnable(search->sprites[i][j],1);
        }
    }
    ARC_TOOL_DeleteHandle(archive);
}








/*
 * trailing: two zero alignment bytes at 0x021DF61E
 * lever: padded struct array members prevent caching the element cursor across calls.
 */
void BR_CODEIN_SearchDeleteActor(char *work)
{
    int i, j;
    CLACT_ReleaseCellAnim(((struct CodeinWorkG *)work)->cellAnimRes);
    CLACT_ReleasePalette(((struct CodeinWorkG *)work)->paletteRes);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            if (((struct CodeinSearchState *)work)->sprites[i][j] != 0) {
                CLACT_ReleaseCharacter(((struct CodeinSearchState *)work)->indices[i][j]);
                CLACT_DeleteActor(((struct CodeinSearchState *)work)->sprites[i][j]);
                ((struct CodeinSearchState *)work)->sprites[i][j] = 0;
            }
        }
    }
}








/*
 * Lever: short step spills first; i remains live after the first loop and
 * supplies the second loop's row; forward/back/loaded declaration order
 * gives the three 36-byte buffers at sp+7c, sp+58, sp+34.
 */
void BR_CODEIN_SearchUpdateActor(struct CodeinSearchState *search,int first,short step,u16 heap)
{
    int i,j;
    char *src,*dst;
    u32 value;
    void *archive,*handle;
    struct Sub *data;
    struct Rec forward,back,loaded;
    struct Entries entries;
    u32 mode;
    for(i=0;i<5;i++) {
        for(j=0;j<6;j++) {
            if(step==1 && i!=4) {
                src=search->sprites[i+1][j]; dst=search->sprites[i][j];
                if(CLACT_GetActorDrawEnable((struct Obj *)src)) {
                    CLACT_GetActorImageProxy(src,(struct Struct36 *)(&forward));
                    value=CLACT_GetActorPaletteOffset((struct Obj *)src);
                    CLACT_SetActorImageProxy(dst,(const struct Struct36 *)(&forward));
                    CLACT_SetActorPaletteOffset((struct Obj *)dst,value,0);
                    CLACT_SetActorDrawEnable((struct Obj *)dst,1);
                } else CLACT_SetActorDrawEnable((struct Obj *)dst,0);
            } else if(step==-1 && i!=4) {
                src=search->sprites[3-i][j]; dst=search->sprites[4-i][j];
                if(CLACT_GetActorDrawEnable((struct Obj *)src)) {
                    CLACT_GetActorImageProxy(src,(struct Struct36 *)(&back));
                    value=CLACT_GetActorPaletteOffset((struct Obj *)src);
                    CLACT_SetActorImageProxy(dst,(const struct Struct36 *)(&back));
                    CLACT_SetActorPaletteOffset((struct Obj *)dst,value,0);
                    CLACT_SetActorDrawEnable((struct Obj *)dst,1);
                } else CLACT_SetActorDrawEnable((struct Obj *)dst,0);
            }
        }
    }
    mode=(heap&0x7fff)|0x8000;
    archive=ARC_TOOL_CreateHandle(7,(u16)mode);
    if(step==-1) { --search->cursor; if(search->cursor<0) search->cursor=4; }
    for(j=0;j<6;j++) {
        if(step==1) i=4; else if(step==-1) i=0;
        BR_CODEIN_SearchBuildHeader((int)((u32)search->source+(i+first)*0xc4),(char *)&entries);
        if(entries.species[j]) {
            handle=ARC_UTIL_LoadScreenDataFromHandle(archive,POKE_TOOL_CalcGraphicIndex(entries.species[j],entries.form[j],entries.gender[j],0),0,(u32)&data,mode);
            CLACT_TransferCharacter(search->indices[search->cursor][j],(struct Sub0204A9D0 *)data);
            CLACT_GetCharacterProxy(search->indices[search->cursor][j],&loaded);
            CLACT_SetActorImageProxy(search->sprites[i][j],(const struct Struct36 *)(&loaded));
            CLACT_SetActorPaletteOffset((struct Obj *)search->sprites[i][j],POKE_TOOL_CalcIconPalette(entries.species[j],entries.form[j],entries.gender[j],0),0);
            GFL_HEAP_Free(handle);
            CLACT_SetActorDrawEnable((struct Obj *)search->sprites[i][j],1);
        } else CLACT_SetActorDrawEnable((struct Obj *)search->sprites[i][j],0);
    }
    if(step==1) { ++search->cursor; if(search->cursor>4) search->cursor=0; }
    ARC_TOOL_DeleteHandle(archive);
}








/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 * + *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 BattleRecModeTable[];
 *   u64 BATTLE_REC_GetHeaderParam(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * checks: 1 full callee reads 3 args, 64-bit return; 2 no filed twin; 3 int base/long index unchanged (2/2); 4 named base and second declaration order close DIFF (2/2); 5 fresh idiom/neighbour reread, no stack-object residue. Both reorder variants consumed.
 */
void BR_CODEIN_SearchBuildHeader(int work, char *out)
{
    long i;
    int a, b, c;
    void *base;
    int special, n = 0;
    unsigned int count;
    MI_CpuFill8(out, 0, 0x48);
    base = (void *)(work + 0x80);
    switch ((int)BATTLE_REC_GetHeaderParam(base, 3, 0)) {
    case 16: case 17: case 18: case 19: case 22:
        special = 1;
        count = 9;
        break;
    default:
        special = 0;
        count = 6;
        break;
    }
    for (i = 0; i < count; i++) {
        if (special && i >= 3 && i <= 5) continue;
        a = BATTLE_REC_GetHeaderParam(base, 0, i);
        b = BATTLE_REC_GetHeaderParam(base, 1, i);
        c = BATTLE_REC_GetHeaderParam(base, 6, i);
        if (a >= 0x28B) a = 0;
        if (a != 0) {
            *(int *)(out + n * 4) = a;
            *(int *)(out + n * 4 + 0x18) = b;
            *(int *)(out + n * 4 + 0x30) = c;
            n++;
        }
    }
}








int BR_CODEIN_SearchHitBox(int x, int y)
{
    int ok = ((unsigned)(x - 80) <= 88) & ((unsigned)(y - 32) <= 56);
    if (ok) GFL_USE_PlaySeDefaultVolume(0x703);
    return ok;
}








int BR_CODEIN_CodeCreate(void *obj, int unused, struct CodeinArgB *arg)
{
    struct CodeinWorkA *p;
    int i;
    p = PROCSYS_AllocProcWork(obj, 0x58, BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(arg->procQuery)));
    MI_CpuFill8(p, 0, 0x58);
    p->heapId = BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(arg->procQuery));
    p->codePrintQue = (void *)PRINTSYS_QUE_Create((void *)(p->heapId));
    (*(void * *)&p->codeOamSys) = BMP_OAM_CreateSys(p->heapId, arg->actorSys);
    (*(int *)&p->codeWin) = (int)BR_UTIL_CreateTextWin(arg->res, (void *)(*(int *)&p->codePrintQue), p->heapId);
    BR_UTIL_SetWindowText((char *)((*(int *)&p->codeWin)), (char *)(arg->res), (void *)0x6B);
    for (i = 0; i < 2; i++) {
        *(int *)((char *)p + i * 4 + 0x3C) = (int)BR_UTIL_CreateHandles(*(int *)&arg->actorSys, (char *)(arg->res), i, p->heapId);
    }
    arg->species = 0xFFFF;
    arg->language = 0xFF;
    arg->version = 0xFF;
    arg->category = 0x13;
    BR_RES_LoadSprite((char *)(arg->res), 6, p->heapId);
    BR_CODEIN_CodeSetupText(p, (int *)arg);
    return 1;
}








int BR_CODEIN_CodeDestroy(void *work, int unused, struct CodeinArgA *arg, char *data)
{
    int i;
    BR_CODEIN_CodeDeleteText(data, arg);
    BR_RES_ReleaseSprite((char *)(arg->res), 6);
    for (i = 0; i < 2; i++) BR_UTIL_DeleteHandles(*(char **)(data + i * 4 + 0x3c));
    BR_UTIL_DeleteTextWin(((struct CodeinDataA *)data)->codeWin, arg->res);
    BMP_OAM_DeleteSys(((struct CodeinDataA *)data)->codeOamSys);
    PRINTSYS_QUE_Delete(((struct CodeinDataA *)data)->codePrintQue);
    PROCSYS_FreeProcWork(work);
    return 1;
}








int BR_CODEIN_CodeMain(void *unused,u32 *state,int *arg,char *work)
{
    int i;
    switch(*state) {
    case 0: if(d_021E37A8[*(int *)(work+0x4c)].init(work,arg)) ++*state; break;
    case 1: BR_FADE_Start(arg[0],2,3,0); ++*state; break;
    case 2: if(BR_FADE_GetResult((int *)arg[0])) *state=3; break;
    case 3: if(d_021E37A8[*(int *)(work+0x4c)].update(work,arg)) {
        if(((struct CodeinWorkA *)work)->nextStage==-1) *state=10; else *state=4;
    } break;
    case 4: BR_FADE_Start(arg[0],2,2,1); ++*state; break;
    case 5: if(BR_FADE_GetResult((int *)arg[0])) ++*state; break;
    case 6: if(d_021E37A8[*(int *)(work+0x4c)].finish(work,arg)) {
        ((struct CodeinWorkA *)work)->stage=((struct CodeinWorkA *)work)->nextStage; ++*state;
    } break;
    case 7: if(d_021E37A8[*(int *)(work+0x4c)].init(work,arg)) ++*state; break;
    case 8: BR_FADE_Start(arg[0],2,2,0); ++*state; break;
    case 9: if(BR_FADE_GetResult((int *)arg[0])) *state=3; break;
    case 10: BR_FADE_Start(arg[0],2,3,1); ++*state; break;
    case 11: if(BR_FADE_GetResult((int *)arg[0])) *state=12; break;
    case 12: if(d_021E37A8[*(int *)(work+0x4c)].finish(work,arg)) return 1; break;
    }
    for(i=0;i<3;i++) if(*(void **)(work+i*4)) BR_UTIL_FlushText(*(void **)(work+i*4));
    for(i=0;i<6;i++) if(*(void **)(work+0x20+i*4)) BR_UTIL_FlushText(*(void **)(work+0x20+i*4));
    if(((struct CodeinWorkA *)work)->codeWin) BR_UTIL_FlushWindow(((struct CodeinWorkA *)work)->codeWin);
    PRINTSYS_QUE_Main(((struct CodeinWorkA *)work)->codePrintQue);
    for(i=0;i<2;i++) BR_UTIL_RunHandles(*(char **)(work+0x3c+i*4));
    return 0;
}








int BR_CODEIN_CodeSetupButtons(struct CodeinWorkA *work,struct CodeinArgA *arg)
{
    int first,second,i;
    Params req;
    Triple triple;
    const struct Rec6 *r;
    const struct Rec8 *s;
    first=BR_RES_GetFont(*(char * *)&arg->res);
    second=BR_RES_GetMsgData(*(char * *)&arg->res);
    BR_RES_LoadBgGraphics((void *)(arg->res),26,work->heapId);
    MI_CpuFill8(&req,0,8);
    BR_RES_GetSprite((void *)arg->res,6,&triple);
    for(i=0;i<2;i++) {
        r=&d_021E3734[i];
        req.a=r->x; req.b=r->y; req.c=r->id; req.flag=1;
        *(void **)((char *)work+0xc+i*4)=BR_BTN_CreateFromMessage(&req,r->file,0x60,1,arg->actorSys,work->codeOamSys,first,second,&triple,work->heapId);
    }
    for(i=0;i<3;i++) {
        s=&d_021E3740[i];
        *(void **)((char *)work+i*4)=BR_UTIL_Create(4,s->a,s->b,s->c,s->d,14,work->codePrintQue,work->heapId);
        BR_UTIL_SetTextFromMessage(*(char **)((char *)work+i*4),(void *)second,s->value,(void *)first,0x3da0);
    }
    BR_UTIL_SetWindowText(work->codeWin,(char *)(arg->res),(void *)107);
    return 1;
}








int BR_CODEIN_CodeDeleteButtons(char *work, struct CodeinArgA *arg)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (*(void **)(work + i * 4) != 0) {
            BR_UTIL_Delete(*(void **)(work + i * 4));
            *(void **)(work + i * 4) = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (*(void **)(work + i * 4 + 12) != 0) {
            BR_BTN_DeleteObject(*(void **)(work + i * 4 + 12));
            *(void **)(work + i * 4 + 12) = 0;
        }
    }
    BG_SYS_PushTile(4);
    BR_RES_ApplyBgSet(arg->res, 26);
    return 1;
}







/*
 * lever: A separate result!=3 guard around the three-case switch removes the extra 8-byte dense dispatch (460 to 452 B).
 */
int BR_CODEIN_CodeStepInput(struct CodeinWorkB *work,struct CodeinArgB *arg)
{
    int result=BR_CODEIN_CodeHitTestOptions();
    if(result!=3) {
    switch(result) {
    case 0: {
        u32 x,y;
        Point args;
        TOUCHPANEL_GetPointTrg(&x,&y);args.x=x;args.y=y;
        BR_UTIL_StartEffect((void *)work->tapFx,1,&args);
        GFL_USE_PlaySeDefaultVolume(0x703);
        arg->category=19;
        BR_CODEIN_CodeSetMenuText(work,arg,0);
        BR_UTIL_SetWindowText(work->codeWin,(char *)(arg->res),(void *)105);
        work->nextStage=1;
        return 1;
    }
    case 1: {
        u32 x,y;
        Point args;
        TOUCHPANEL_GetPointTrg(&x,&y);args.x=x;args.y=y;
        BR_UTIL_StartEffect((void *)work->tapFx,1,&args);
        GFL_USE_PlaySeDefaultVolume(0x703);
        arg->species=0xffff;
        BR_CODEIN_CodeSetMenuText(work,arg,1);
        BR_UTIL_SetWindowText(work->codeWin,(char *)(arg->res),(void *)106);
        work->nextStage=2;
        return 1;
    }
    case 2: {
        void *v;
        int a,b;
        u32 x,y;
        Point args;
        v=GAME_DATA_GetMyStatus(arg->gameData);
        a=MYSTATUS_GetNation(v);b=MYSTATUS_GetArea(v);
        if(!a && !b) {
            BR_UTIL_SetWindowText(work->codeWin,(char *)(arg->res),(void *)120);
            GFL_USE_PlaySeDefaultVolume(0x704);
            break;
        }
        TOUCHPANEL_GetPointTrg(&x,&y);args.x=x;args.y=y;
        BR_UTIL_StartEffect((void *)work->tapFx,1,&args);
        GFL_USE_PlaySeDefaultVolume(0x703);
        if(arg->language==255){arg->language=a;arg->version=b;}
        else{arg->language=255;arg->version=255;}
        BR_CODEIN_CodeSetMenuText(work,arg,2);
        return 0;
    }
    }
    }
    {
        u32 x,y;
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(BR_BTN_HitTestWithSound((unsigned int *)(work->button),x,y)) {
                Point args;
                args.x=x;args.y=y;
                BR_UTIL_StartEffect((void *)work->tapFx,1,&args);
                work->nextStage=-1;
                BR_PROC_SYS_PopEntry((*(void * *)&arg->procQuery));
                return 1;
            }
            if(BR_BTN_TestHitBox((u32 *)(work->screenFade),x,y)) {
                if(arg->species!=0xffff || arg->version!=255 || arg->category!=19) {
                    Point args;
                    args.x=x;args.y=y;
                    GFL_USE_PlaySeDefaultVolume(0x703);
                    BR_UTIL_StartEffect((void *)work->tapFx,1,&args);
                    work->nextStage=-1;
                    BR_PROC_SYS_PushEntry(*(unsigned * *)&arg->procQuery,5);
                    return 1;
                }
                GFL_USE_PlaySeDefaultVolume(0x704);
                BR_UTIL_SetWindowText(work->codeWin,(char *)(arg->res),(void *)108);
            }
        }
    }
    return 0;
}







int BR_CODEIN_CodeSetupMenu(struct CodeinWorkB *work,struct CodeinArgA *arg)
{
    int first,second,i;
    CfgTpl cfg;
    Triple triple;
    Params params;
    first=BR_RES_GetFont(*(char * *)&arg->res);
    second=BR_RES_GetMsgData(*(char * *)&arg->res);
    BR_RES_LoadBgGraphics((void *)(arg->res),27,work->heapId);
    *(BmpMenuWorkSlot * *)&work->menuWork=BMP_MENUWORK_Create(19,work->heapId);
    for(i=0;i<19;i++)BMP_MENUWORK_AddMsgItem((BmpMenuWorkSlot *)((u32)*(BmpMenuWorkSlot * *)&work->menuWork+i*8),second,i+205,i,work->heapId);
    cfg=d_021E3758;
    cfg.words[0]=*(u32 *)&work->menuWork;cfg.words[1]=19;
    cfg.words[5]=*(u32 *)&arg->res;cfg.words[6]=(*(unsigned int *)&arg->actorSys);
    work->textWin=BR_UTIL_CreateListMenu((const CodeinListMenuConfig *)&cfg,work->heapId);
    MI_CpuFill8(&params,0,8);
    BR_RES_GetSprite((void *)arg->res, 6, (Triple *)&triple);
    params.a=d_021E3728[0].x;params.b=d_021E3728[0].y;params.c=d_021E3728[0].id;params.flag=1;
    (*(void * *)&work->button)=BR_BTN_CreateFromMessage(&params,d_021E3728[0].file,96,1,arg->actorSys,work->profileScreen,first,second,&triple,work->heapId);
    return 1;
}







int BR_CODEIN_CodeDeleteMenu(struct CodeinWorkB *work, struct CodeinArgA *arg)
{
    if ((*(void * *)&work->button)) {
        BR_BTN_DeleteObject((*(void * *)&work->button));
        (*(void * *)&work->button) = 0;
    }
    BR_UTIL_DeleteListMenu(work->textWin);
    work->textWin = 0;
    BMP_MENUWORK_Delete(work->menuWork);
    work->menuWork = 0;
    BR_RES_ApplyBgSet(arg->res, 27);
    BG_SYS_PushTile(4);
    return 1;
}







int BR_CODEIN_CodeStepMenu(struct CodeinWorkB *work, struct CodeinArgB *arg)
{
    int selected, pressed;
    unsigned int x, y;
    BR_UTIL_MainListMenu(work->textWin);
    selected = BR_UTIL_GetListMenuHitId(work->textWin);
    pressed = TOUCHPANEL_GetPointTrg(&x, &y);
    pressed &= BR_BTN_HitTestWithSound((unsigned int *)(work->button), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        Point args;
        TOUCHPANEL_GetPointTrg(&x1, &y1);
        args.x = x1;
        args.y = y1;
        BR_UTIL_StartEffect((void *)work->tapFx, 1, &args);
        arg->category = selected;
        BR_CODEIN_CodeSetMenuText(work, arg, 0);
        work->nextStage = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        Point args;
        TOUCHPANEL_GetPointTrg(&x2, &y2);
        args.x = x2;
        args.y = y2;
        BR_UTIL_StartEffect((void *)work->tapFx, 1, &args);
        work->nextStage = 0;
        return 1;
    }
    return 0;
}







void BR_CODEIN_CodeOpenPokeSearch(struct CodeinWorkA *work, struct CodeinArgA *arg)
{
    work->ctx = BR_POKESEARCH_Create(ZUKAN_SAVE_GetFromGameData((*(void * *)&arg->uiRes)), (*(void * *)&arg->res), arg->actorSys, work->codeOamSys, arg->screenFade, (*(int *)&work->menuCtx), work->tapFx, work->heapId);
    BR_POKESEARCH_Open(work->ctx);
    BR_POKESEARCH_UpdatePrint(work->ctx);
}







int BR_CODEIN_CodeClosePokeSearch(struct CodeinWorkA *work)
{
    BR_POKESEARCH_Close((*(void * *)&work->ctx));
    BR_POKESEARCH_Destroy((*(void * *)&work->ctx));
    BG_SYS_PushTile(4);
    return 1;
}






/*
 * lever: Repeat the reset store in both result arms, with return 1 shared after them; hoisting the store removes the branch at 0x021E00C8.
 */
int BR_CODEIN_CodeStepPokeSearch(struct CodeinWorkB *work, struct CodeinArgB *arg)
{
    u16 out;
    int result;
    BR_POKESEARCH_Main(*(char * *)&work->procQuery);
    result = BR_POKESEARCH_GetResult(*(int * *)&work->procQuery, &out);
    if (result) {
        if (result == 2) {
            arg->species = out;
            BR_CODEIN_CodeSetMenuText(work, arg, 1);
            work->nextStage = 0;
        } else {
            work->nextStage = 0;
        }
        return 1;
    }
    return 0;
}






int BR_CODEIN_CodeSetupPokeList(struct CodeinWorkB *work,struct CodeinArgA *arg)
{
    int first,second,a,b;
    void *v,*text,*data;
    int ws;
    CfgTpl cfg;
    Triple triple;
    Params params;
    first=BR_RES_GetFont(*(char * *)&arg->res);
    second=BR_RES_GetMsgData(*(char * *)&arg->res);
    BR_RES_LoadBgGraphics((void *)(arg->res),28,work->heapId);
    text=STRBUF_Create(128,work->heapId);
    v=GAME_DATA_GetMyStatus((*(void * *)&arg->uiRes));
    a=MYSTATUS_GetNation(v);b=MYSTATUS_GetArea(v);
    ws=BR_RES_GetWordSet(*(char * *)&arg->res);
    data=MSGDATA_AllocString((void *)second,125);
    if(!NATION_AREA_GetAreaCount(a))WORDSET_SetSlotFromMsgE7((void *)ws,0,a);
    else WORDSET_SetSlotFromKeyedMessage((void *)ws,0,a,b);
    WORDSET_CopyTaggedText((void *)ws,text,data);
    STRBUF_Delete(data);
    *(BmpMenuWorkSlot * *)&work->menuWork=BMP_MENUWORK_Create(1,work->heapId);
    BMP_MENUWORK_AddStrItem(*(BmpMenuWorkSlot * *)&work->menuWork,(u32)text,0,work->heapId);
    STRBUF_Delete(text);
    cfg=d_021E3780;
    cfg.words[0]=*(u32 *)&work->menuWork;cfg.words[1]=1;
    cfg.words[5]=*(u32 *)&arg->res;cfg.words[6]=(*(unsigned int *)&arg->actorSys);
    work->textWin=BR_UTIL_CreateListMenu((const CodeinListMenuConfig *)&cfg,work->heapId);
    MI_CpuFill8(&params,0,8);
    BR_RES_GetSprite((void *)arg->res, 6, (Triple *)&triple);
    params.a=d_021E372E[0].x;params.b=d_021E372E[0].y;params.c=d_021E372E[0].id;params.flag=1;
    (*(void * *)&work->button)=BR_BTN_CreateFromMessage(&params,d_021E372E[0].file,96,1,arg->actorSys,work->profileScreen,first,second,&triple,work->heapId);
    return 1;
}






int BR_CODEIN_CodeDeletePokeList(struct CodeinWorkB *work, struct CodeinArgA *arg)
{
    if ((*(void * *)&work->button)) {
        BR_BTN_DeleteObject((*(void * *)&work->button));
        (*(void * *)&work->button) = 0;
    }
    BR_UTIL_DeleteListMenu(work->textWin);
    work->textWin = 0;
    BMP_MENUWORK_Delete(work->menuWork);
    work->menuWork = 0;
    BR_RES_ApplyBgSet(arg->res, 28);
    BG_SYS_PushTile(4);
    return 1;
}






/*
 * trailing: two zero alignment bytes at 0x021E02F6
 */
int BR_CODEIN_CodeStepPokeList(struct CodeinWorkB *work, struct CodeinArgB *arg)
{
    int selected, pressed;
    unsigned int x, y;
    BR_UTIL_MainListMenu(work->textWin);
    selected = BR_UTIL_GetListMenuHitId(work->textWin);
    pressed = TOUCHPANEL_GetPointTrg(&x, &y);
    pressed &= BR_BTN_HitTestWithSound((unsigned int *)(work->button), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        Point args;
        void *v;
        int a;
        TOUCHPANEL_GetPointTrg(&x1, &y1);
        args.x = x1;
        args.y = y1;
        BR_UTIL_StartEffect((void *)work->tapFx, 1, &args);
        v = GAME_DATA_GetMyStatus(arg->gameData);
        a = MYSTATUS_GetNation(v);
        arg->version = MYSTATUS_GetArea(v);
        arg->language = a;
        BR_CODEIN_CodeSetMenuText(work, arg, 2);
        work->nextStage = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        Point args;
        TOUCHPANEL_GetPointTrg(&x2, &y2);
        args.x = x2;
        args.y = y2;
        BR_UTIL_StartEffect((void *)work->tapFx, 1, &args);
        work->nextStage = 0;
        return 1;
    }
    return 0;
}






void BR_CODEIN_CodeSetupText(struct CodeinWorkA *work, int *arg)
{
    int first, second, i;
    const Record *r;
    first = BR_RES_GetFont((char *)arg[2]);
    second = BR_RES_GetMsgData((char *)arg[2]);
    BR_RES_LoadBgGraphics((void *)arg[2], 25, work->heapId);
    for (i = 0; i < 6; i++) {
        r = &d_021E37D8[i];
        *(void **)((char *)work + i * 4 + 0x20) = BR_UTIL_Create(1, r->a, r->b, r->c, r->d, 14, work->codePrintQue, work->heapId);
        BR_UTIL_SetTextLayout(*(void **)((char *)work + i * 4 + 0x20), 0, 1, 0);
        BR_UTIL_SetTextFromMessage(*(void **)((char *)work + i * 4 + 0x20), (void *)second, (void *)r->value, (void *)first, 15776);
    }
}






/*
 * extent: final two bytes are alignment padding.
 */
void BR_CODEIN_CodeDeleteText(char *work,struct CodeinArgA *arg){int i;for(i=0;i<6;i++){if(*(void **)(work+i*4+0x20)){BR_UTIL_Delete(*(void **)(work+i*4+0x20));*(void **)(work+i*4+0x20)=0;}}BR_RES_ApplyBgSet(arg->res,25);BG_SYS_PushTile(1);}






void BR_CODEIN_CodeSetMenuText(struct CodeinWorkB *work,struct CodeinArgB *arg,int mode)
{
    int first,second,ws;
    void *data,*text;
    first=BR_RES_GetFont(*(char * *)&arg->res);
    second=BR_RES_GetMsgData(*(char * *)&arg->res);
    switch(mode) {
    case 0:
        if(arg->category!=19)BR_UTIL_SetTextFromMessage(work->categoryText,(void *)second,(void *)(arg->category+205),(void *)first,0x3da0);
        else BR_UTIL_SetTextFromMessage(work->categoryText,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 1:
        if(arg->species!=0xffff)BR_UTIL_SetTextFromMessage(work->speciesText,(void *)gSpeciesNameBank,(void *)(u32)arg->species,(void *)first,0x3da0);
        else BR_UTIL_SetTextFromMessage(work->speciesText,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 2:
        if(arg->language==255 && arg->version==255) {
            BR_UTIL_SetTextFromMessage(work->versionText,(void *)second,(void *)117,(void *)first,0x3da0);
            return;
        }
        ws=BR_RES_GetWordSet(*(char * *)&arg->res);
        data=MSGDATA_AllocString((void *)second,24);
        text=STRBUF_Create(128,work->heapId);
        if(!NATION_AREA_GetAreaCount(arg->language))WORDSET_SetSlotFromMsgE7((void *)ws,0,arg->language);
        else WORDSET_SetSlotFromKeyedMessage((void *)ws,0,arg->language,arg->version);
        WORDSET_CopyTaggedText((void *)ws,text,data);
        BR_UTIL_SetTextFromBuffer(work->versionText,text,(void *)first,0x3da0);
        STRBUF_Delete(data);STRBUF_Delete(text);
        break;
    }
}







/*
 * Hit-test a point against a table of three rectangles; returns the index
 * of the first hit, or 3 when none (or when no point is available).
 */
int BR_CODEIN_CodeHitTestOptions(void)
{
    unsigned int x, y;
    int i;

    if (TOUCHPANEL_GetPointTrg(&x, &y)) {
        for (i = 0; i < 3; i++) {
            const Rect *r = &g_021E3808[i];
            if (x - r->x0 <= r->x1 - r->x0 && y - r->y0 <= r->y1 - r->y0) {
                return i;
            }
        }
    }
    return 3;
}






/*
 * extent: 021E05C2 alignment padding.
 */
int BR_CODEIN_ProfileScreenCreate(void *task, int unused, struct CodeinArgA *arg)
{
    struct CodeinWorkData *p;
    int entries[3];
    BR_RES_GetFont((char *)(arg->res));
    BR_RES_GetMsgData(*(char * *)&arg->res);
    p = PROCSYS_AllocProcWork(task, 24, BR_PROC_SYS_GetSlotId(arg->procQuery));
    MI_CpuFill8(p, 0, 24);
    p->heap = BR_PROC_SYS_GetSlotId(arg->procQuery);
    BR_RES_LoadBgGraphics((void *)(arg->res), 29, p->heap);
    BR_RES_LoadSprite(*(char * *)&arg->res, 11, p->heap);
    BR_RES_LoadSprite(*(char * *)&arg->res, 12, p->heap);
    BR_RES_LoadSprite(*(char * *)&arg->res, 6, p->heap);
    p->handles = BR_UTIL_CreateHandles((unsigned int)((*(void * *)&arg->actorSys)), (char *)(arg->res), 1, p->heap);
    entries[0] = 2;
    entries[1] = 5;
    entries[2] = 5;
    p->object = BR_CODEIN_ProfileCreateObject(p->heap, 12, (*(void * *)&arg->actorSys), (void *)(arg->res), p->handles, entries);
    p->profile = BR_CODEIN_ProfileCreate(p->object, p->heap);
    p->printQue = (void *)PRINTSYS_QUE_Create((void *)p->heap);
    p->textWin = BR_UTIL_CreateTextWin(arg->res, p->printQue, p->heap);
    BR_UTIL_SetWindowText(p->textWin, (char *)(arg->res), (void *)104);
    return 1;
}






/*
 * extent: 021E0616 alignment padding; next owned function starts 021E0618.
 */
int BR_CODEIN_ProfileScreenDestroy(void *proc, int unused, int *arg, void **work)
{
    BR_UTIL_DeleteTextWin((void *)((int)work[2]), arg[2]);
    BR_CODEIN_ProfileDestroy(work[1]);
    BR_CODEIN_ProfileDestroyObject(work[0]);
    PRINTSYS_QUE_Delete(work[3]);
    BR_UTIL_DeleteHandles(work[5]);
    BR_RES_ApplyBgSet(arg[2], 29);
    BR_RES_ReleaseSprite((char *)arg[2], 6);
    BR_RES_ReleaseSprite((char *)arg[2], 12);
    BR_RES_ReleaseSprite((char *)arg[2], 11);
    PROCSYS_FreeProcWork(proc);
    return 1;
}






/*
 * extent: 021E06CE alignment padding.
 */
int BR_CODEIN_ProfileScreenMain(int unused, int *state, int *arg, int *work)
{
    switch (*state) {
    case 0:
        BR_FADE_Start(arg[0], 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (BR_FADE_GetResult((int *)arg[0])) *state = 2;
        break;
    case 2:
        BR_CODEIN_ProfileUpdate((char *)work[1]);
        switch (BR_CODEIN_ProfileGetState((char *)work[1])) {
        case 1: BR_PROC_SYS_PopEntry((unsigned int *)arg[3]); *state = 3; break;
        case 2: ((struct CodeinArgD *)arg)->result = BR_CODEIN_ProfileGetValue((char *)work[1]); BR_PROC_SYS_PushEntry((unsigned int *)arg[3], 2); *state = 3; break;
        }
        break;
    case 3:
        BR_FADE_Start(arg[0], 2, 3, 1);
        *state = 4;
        break;
    case 4:
        if (BR_FADE_GetResult((int *)arg[0])) *state = 5;
        break;
    case 5: return 1;
    }
    if (work[2]) BR_UTIL_FlushWindow((void *)work[2]);
    PRINTSYS_QUE_Main((struct PrintSys *)work[3]);
    BR_UTIL_RunHandles((char *)work[5]);
    return 0;
}



/*
 * extent: 0754 tail-call stub; 075C state getter; 0764 64-bit getter; 0772 padding.
 */
char *BR_CODEIN_ProfileCreate(const CfgTpl *src, u16 heap)
{
    char *p;
    p = GFL_HEAP_Alloc(heap, 0x368, 0, d_021E3968, 56);
    MI_CpuFill8(p, 0, 0x368);
    *(CfgTpl *)(p + 0x324) = *src;
    ((struct CodeinWorkA *)p)->profileHeapId = heap;
    (*(int *)&((struct CodeinWorkA *)p)->actorSys) = src->words[7];
    ((struct CodeinWorkA *)p)->font = BR_RES_GetFont((char *)src->words[8]);
    ((struct CodeinWorkA *)p)->arcHandle = ARC_TOOL_CreateHandle(59, ((struct CodeinWorkA *)p)->profileHeapId);
    BR_CODEIN_ProfileInitRecordLayout((CodeinProfileState *)p);
    BR_CODEIN_ProfileCreateButtons(p);
    ((struct CodeinWorkA *)p)->task = GFL_USE_AddMainTask(BR_CODEIN_ProfileNoop, p, 16);
    return p;
}



void BR_CODEIN_ProfileUpdate(char *work)
{
    BR_CODEIN_ProfileUpdateActorAnim(work);
}



int BR_CODEIN_ProfileGetState(char *work)
{
    return ((struct CodeinWorkA *)work)->state;
}



u64 BR_CODEIN_ProfileGetValue(char *work)
{
    return ((struct CodeinWorkA *)work)->result;
}



void BR_CODEIN_ProfileDestroy(struct CodeinWorkA *work){TCB_DeleteTask(work->task);BR_CODEIN_ProfileDeleteActor(work);ARC_TOOL_DeleteHandle(work->arcHandle);BUTTON_MAN_Delete(work->buttonMan);GFL_HEAP_Free(work);}



struct Object *BR_CODEIN_ProfileCreateObject(int heap, int n, void *actorSys, void *res, void *handles, int *entries)
{
    int i;
    struct Object *p;
    p = GFL_HEAP_Alloc((u16)heap, 40, 0, d_021E3968, 192);
    p->actorSys = actorSys;
    p->res = res;
    p->capacity = n;
    p->vector = STRBUF_Create(n + 1, heap);
    p->handles = handles;
    for (i = 0; i < 3; i++) p->entries[i] = entries[i];
    p->entries[i] = entries[i - 1];
    return p;
}



/*
 * extent: existing matched callback 021E083C and its alignment follow the pool.
 */
void BR_CODEIN_ProfileDestroyObject(struct Object *work){if(!work->vector)GF_PANIC_Fail(d_021E3974,0,d_021E3974);if(!work)GF_PANIC_Fail(d_021E3974,0,d_021E3974);STRBUF_Delete(work->vector);GFL_HEAP_Free(work);}



/*
 * leaf: empty callback solely blocks owned constructor 021E06D0; parent cleared.
 * extent: bx lr at 083C; 083E alignment; existing owned 0840 follows.
 */
void BR_CODEIN_ProfileNoop(void)
{
}



void BR_CODEIN_ProfileSetupSprite(char *work)
{
    struct Triple t;
    if (!BR_RES_GetSprite(((struct CodeinWorkA *)work)->res, 11, &t)) GF_PANIC_Fail(d_021E3978, 0, d_021E3978);
    ((struct CodeinWorkA *)work)->sprite11PaletteId = t.c;
    ((struct CodeinWorkA *)work)->sprite11CharId = t.b;
    ((struct CodeinWorkA *)work)->sprite11CellAnimId = t.a;
    if (!BR_RES_GetSprite(((struct CodeinWorkA *)work)->res, 12, &t)) GF_PANIC_Fail(d_021E3978, 0, d_021E3978);
    ((struct CodeinWorkA *)work)->sprite12PaletteId = t.c;
    ((struct CodeinWorkA *)work)->sprite12CharId = t.b;
    ((struct CodeinWorkA *)work)->sprite12CellAnimId = t.a;
    if (!BR_RES_GetSprite(((struct CodeinWorkA *)work)->res, 6, &t)) GF_PANIC_Fail(d_021E3978, 0, d_021E3978);
    *(int *)&((struct CodeinWorkA *)work)->sprite6PaletteId = t.c;
    *(int *)&((struct CodeinWorkA *)work)->sprite6CharId = t.b;
    *(int *)&((struct CodeinWorkA *)work)->sprite6CellAnimId = t.a;
}



/*
 * extent: 021E0952 alignment padding.
 */
void BR_CODEIN_ProfileDeleteActor(struct CodeinWorkA *work)
{
    int i;
    for (i = 0; i < work->recordCount; i++) CLACT_DeleteActor(*(void **)((char *)work + i * 28 + 12));
    for (i = 0; i < 2; i++) {
        CLACT_DeleteActor(*(void **)((char *)work + i * 28 + 0x15c));
        CLACT_DeleteActor(*(void **)((char *)work + i * 28 + 0x1e8));
    }
    for (i = 0; i < 3; i++) CLACT_DeleteActor(*(void **)((char *)work + i * 28 + 0x194));
    BR_CODEIN_ProfileDeleteOam(work);
}



/*
 * lever: The explicit entry guard encloses a do-while; a for adds a second entry test (308 B DIFF to 306 B EXACT*).
 * trailing: 021E0A86..021E0A88 is two zero alignment bytes.
 * abi: 0204B294 caller uses returned r0 despite callee's void spelling; fifth payload remains its u32 address word.
 * note 2026-10-05 (wave D9r lane 131): removed the 7 dead first assignments
 * (`heapA=0x25c;` before `heapA=0x34c;`; `aA=0x25c;` before `aA=0x26c;` and
 * 5 more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT* in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void BR_CODEIN_ProfileCreateRecordActors(char *work)
{
    int i,special,normal,base;
    u32 owner;
    int heapA,aA,bA,cA,heapB,aB,bB,cB,countOffset,recordOffset;
    Params params;
    normal=0;
    base=0x25c;
    owner=*(u32 *)(work+base);
    params.a=normal;params.b=normal;params.c=normal;params.flag=10;params.pad=normal;
    special=0;i=0;
    if(*(int *)(work+base-0x20)+2>0) {
        heapA=0x34c;
        aA=0x26c;
        bA=0x260;
        cA=0x284;
        heapB=0x34c;
        aB=0x26c;
        bB=0x260;
        cB=0x284;
        countOffset=0x23c;
        recordOffset=0x150;
        do {
            char *q;
            q=work+special*28;
            if(i==*(int *)(q+recordOffset)+special+1) {
                void *obj;
                params.a=i*8+76;params.b=24;params.c=22;
                obj=CLACT_CreateActor((void *)owner,*(u32 *)(work+aB),*(u32 *)(work+bB),*(u32 *)(work+cB),&params,1,*(u16 *)(work+heapB));
                ((struct CodeinArgA *)q)->slideActor=obj;CLACT_SetActorObjMode(obj,1);
                special++;
            } else {
                void *obj;
                params.a=i*8+76;params.b=24;
                q=work+normal*28;
                params.c=BR_CODEIN_ProfileGetActorIndex(((struct CodeinArgA *)q)->screenFade,((struct CodeinArgA *)q)->res);
                obj=CLACT_CreateActor((void *)owner,*(u32 *)(work+aA),*(u32 *)(work+bA),*(u32 *)(work+cA),&params,1,*(u16 *)(work+heapA));
                ((struct CodeinArgA *)q)->procQuery=obj;CLACT_SetActorObjMode(obj,1);
                normal++;
            }
            i++;
        } while(i<*(int *)(work+countOffset)+2);
    }
}



/*
 * abi: 0204B294 r0 consumed after call; pointer request passed as the unchanged u32 fifth payload.
 */
void BR_CODEIN_ProfileCreateMarkerActors(char *work)
{
    int base,zero;
    u32 owner;
    Params params;
    base=0x25c;owner=*(u32 *)(work+base);zero=0;
    params.a=zero;params.b=zero;params.c=zero;params.flag=zero;params.pad=zero;
    *(u32 *)(work+base-0xc8)=(u32)CLACT_CreateActor((void *)owner,*(u32 *)(work+base+0x18),*(u32 *)(work+base+0xc),*(u32 *)(work+base+0x30),&params,1,*(u16 *)(work+base+0xf0));
    CLACT_SetActorObjMode(*(void **)(work+base-0xc8),1);
    *(u32 *)(work+base-0xac)=(u32)CLACT_CreateActor((void *)owner,*(u32 *)(work+base+0x18),*(u32 *)(work+base+0xc),*(u32 *)(work+base+0x30),&params,1,*(u16 *)(work+base+0xf0));
    CLACT_SetActorObjMode(*(void **)(work+base-0xac),1);
    *(u32 *)(work+base-0x90)=(u32)CLACT_CreateActor((void *)owner,*(u32 *)(work+base+0x18),*(u32 *)(work+base+0xc),*(u32 *)(work+base+0x30),&params,1,*(u16 *)(work+base+0xf0));
    CLACT_SetActorObjMode(*(void **)(work+base-0x90),1);
    BR_CODEIN_ProfileSetActorPos(work,0);
    CLACT_SetActorAnimSeq(*(void **)(work+base-0xc8),0);CLACT_SetActorAutoAnim(*(void **)(work+base-0xc8),1);
    *(u16 *)(work+base-0xa4)=zero;*(u16 *)(work+base-0xa2)=zero;*(u32 *)(work+base-0xb8)=1;
    BR_CODEIN_ProfileAddActorSurfacePos((struct Coordinates *)work,0);
    CLACT_SetActorAnimSeq(*(void **)(work+base-0xac),*(u32 *)(work+base-0xb8));
    CLACT_SetActorAutoAnim(*(void **)(work+base-0xac),1);CLACT_SetActorObjMode(*(void **)(work+base-0xac),1);
    *(u16 *)(work+base-0x88)=zero;*(u16 *)(work+base-0x86)=zero;*(u32 *)(work+base-0x9c)=1;
    BR_CODEIN_ProfileAddActorSurfacePos((struct Coordinates *)work,zero);
    CLACT_SetActorAnimSeq(*(void **)(work+base-0x90),*(u32 *)(work+base-0x9c));
    CLACT_SetActorObjMode(*(void **)(work+base-0x90),1);CLACT_SetActorAutoAnim(*(void **)(work+base-0x90),1);
    BR_CODEIN_ProfileSetActorVisible(work,1,zero);BR_CODEIN_ProfileSetActorVisible(work,2,zero);
}



/*
 * Caller evidence: 0204B294 leaves its forwarded return word live in r0; consumed by store and 0204B688 here.
 */
void BR_CODEIN_ProfileCreateArrowActors(char *work) {
    struct PosParams pos;
    u32 manager=*(u32 *)&((struct CodeinWorkA *)work)->actorSys;
    pos.a=0;pos.b=0;pos.z=0;pos.mode=10;pos.flag=0;
    *(u32 *)&((struct CodeinWorkA *)work)->prevArrowActor=(u32)CLACT_CreateActor((void *)manager,((struct CodeinWorkA *)work)->sprite6CharId,((struct CodeinWorkA *)work)->sprite6PaletteId,((struct CodeinWorkA *)work)->sprite6CellAnimId,&pos.a,1,((struct CodeinWorkA *)work)->profileHeapId);
    CLACT_SetActorObjMode(((struct CodeinWorkA *)work)->prevArrowActor,1);
    pos.z=1;
    *(u32 *)&((struct CodeinWorkA *)work)->nextArrowActor=(u32)CLACT_CreateActor((void *)manager,((struct CodeinWorkA *)work)->sprite6CharId,((struct CodeinWorkA *)work)->sprite6PaletteId,((struct CodeinWorkA *)work)->sprite6CellAnimId,&pos.a,1,((struct CodeinWorkA *)work)->profileHeapId);
    CLACT_SetActorObjMode(((struct CodeinWorkA *)work)->nextArrowActor,1);
    pos.x=((struct CodeinWorkA *)work)->prevArrowX;pos.y=((struct CodeinWorkA *)work)->prevArrowY+16;
    CLACT_AddActorSurfacePos(((struct CodeinWorkA *)work)->prevArrowActor,(const struct Vec2 *)(&pos.x),1);
    CLACT_SetActorAnimSeq(((struct CodeinWorkA *)work)->prevArrowActor,0);
    pos.x=((struct CodeinWorkA *)work)->nextArrowX;pos.y=((struct CodeinWorkA *)work)->nextArrowY+16;
    CLACT_AddActorSurfacePos(((struct CodeinWorkA *)work)->nextArrowActor,(const struct Vec2 *)(&pos.x),1);
    CLACT_SetActorAnimSeq(((struct CodeinWorkA *)work)->nextArrowActor,1);
}




void BR_CODEIN_ProfileSetActorVisible(char *work, int index, int visible)
{
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)(work + index * 0x1c + 0x194), (unsigned int)visible);
}



void BR_CODEIN_ProfileSetActorPos(char *work,int i){short pos[2];void *obj;obj=*(void **)(work+i*28+12);((struct CodeinWorkA *)work)->selectedIndex=i;CLACT_GetActorSurfacePos(obj,(struct PtS *)pos,1);pos[1]+=16;CLACT_AddActorSurfacePos(((struct CodeinWorkA *)work)->cursorActor,(const struct Vec2 *)pos,1);}



/*
 * extent: 021E0D8E alignment padding.
 */
void BR_CODEIN_ProfileAddActorSurfacePos(struct Coordinates *coords, int index)
{
    int width = coords->rect[index + 12][1] - coords->rect[index + 12][0];
    int height = coords->rect[index + 12][3] - coords->rect[index + 12][2];
    s16 pos[2];
    pos[0] = height / 2 + coords->rect[index + 12][2];
    pos[1] = width / 2 + coords->rect[index + 12][0];
    CLACT_AddActorSurfacePos(((struct CodeinWorkA *)coords)->markerActor, (const struct Vec2 *)pos, 1);
    CLACT_SetActorAnimFrame(((struct CodeinWorkA *)coords)->markerActor, 0);
}



/*
 * extent: 021E0E3E alignment padding.
 */
void BR_CODEIN_ProfileUpdateActorAnims(char *work)
{
    int i, state;
    for (i = 1; i < 3; i++) {
        state = CLACT_GetActorAnimSeq(*(void **)(work + i * 28 + 0x194));
        if (state == 3) {
            if (!CLACT_IsActorAnimActive(*(void **)(work + i * 28 + 0x194))) {
                CLACT_SetActorAnimSeq(*(void **)(work + i * 28 + 0x194), *(int *)(work + i * 28 + 0x188));
                if (((struct CodeinWorkA *)work)->markerHidden == 1) BR_CODEIN_ProfileSetActorVisible(work, 1, 0);
                else BR_CODEIN_ProfileSetActorVisible(work, 1, 1);
                BR_CODEIN_ProfileSetActorVisible(work, 2, 0);
            }
        } else {
            if (state != *(int *)(work + i * 28 + 0x188)) CLACT_SetActorAnimSeq(*(void **)(work + i * 28 + 0x194), *(int *)(work + i * 28 + 0x188));
            if (CLACT_GetActorAnimSeq(*(void **)(work + i * 28 + 0x194)) != 3) {
                if (((struct CodeinWorkA *)work)->markerHidden == 1) BR_CODEIN_ProfileSetActorVisible(work, 1, 0);
                else BR_CODEIN_ProfileSetActorVisible(work, 1, 1);
            }
        }
    }
}



int BR_CODEIN_ProfileGetActorIndex(int tag, int mode) { int n=0; if(mode==0)n=11; return n+tag; }



void BR_CODEIN_ProfileUpdateActorVisible(char *work)
{
    int i;
    for (i = 0; i < ((struct CodeinWorkA *)work)->recordCount; i++) {
        if (i >= ((struct CodeinWorkA *)work)->rangeAFirst && i < ((struct CodeinWorkA *)work)->rangeAEnd)
            *(int *)(work + i * 28 + 8) = 1;
        else
            *(int *)(work + i * 28 + 8) = 0;
    }
}



void BR_CODEIN_ProfileSetActorAnimFrame(char *work,int animated) {
    int i,group;
    s16 pos;
    char *record,*special;
    Coords coords;
    pos=*(s16 *)((u32)work+((struct CodeinWorkA *)work)->animState*2+0x214);
    group=0;
    for(i=0;i<((struct CodeinWorkA *)work)->recordCount;i++){
        if(i>=((struct CodeinWorkA *)work)->rangeAFirst&&i<((struct CodeinWorkA *)work)->rangeAEnd){
            if(i==((struct CodeinWorkA *)work)->rangeAFirst)pos+=20;else pos+=32;
        }else{
            if(i==0)pos+=20;else pos+=8;
        }
        record=(char *)((u32)work+i*28);
        CLACT_GetActorSurfacePos(((struct CodeinRecordA *)record)->actor,(struct PtS *)&coords.x,1);
        if(animated==0){
            coords.x=pos;
            CLACT_AddActorSurfacePos(((struct CodeinRecordA *)record)->actor,(const struct Vec2 *)(&coords.x),1);
        }else{
            ((struct CodeinRecordA *)record)->moveDx=(pos-coords.x)/4;
            ((struct CodeinRecordA *)record)->moveDy=0;
            ((struct CodeinRecordA *)record)->moveFrames=4;
            ((struct CodeinRecordA *)record)->scaleStep=0;
        }
        special=(char *)((u32)work+group*28);
        if(i==((struct CodeinSpecialA *)special)->tag&&group!=2){
            CLACT_GetActorSurfacePos(((struct CodeinSpecialA *)special)->slideActor,(struct PtS *)&coords.a,1);
            if(((struct CodeinWorkA *)work)->rangeAFirst==((struct CodeinWorkA *)work)->rangeAEnd)pos+=8;
            else {
                if(i>((struct CodeinWorkA *)work)->rangeAFirst&&i<((struct CodeinWorkA *)work)->rangeAEnd)pos+=20;
                else pos+=8;
            }
            if(animated==0){
                coords.a=pos;
                CLACT_AddActorSurfacePos(((struct CodeinSpecialA *)special)->slideActor,(const struct Vec2 *)(&coords.a),1);
            }else{
                ((struct CodeinSpecialA *)special)->slideDx=(pos-coords.a)/4;
                ((struct CodeinSpecialA *)special)->slideDy=0;
                ((struct CodeinSpecialA *)special)->slideFrames=4;
            }
            group++;
        }
    }
}



void BR_CODEIN_ProfileUpdateActorPos(char *work)
{
    int i, x, y;
    s16 pos[2];
    for (i = 0; i < ((struct CodeinWorkA *)work)->recordCount; i++) {
        if (i >= ((struct CodeinWorkA *)work)->rangeAFirst && i < ((struct CodeinWorkA *)work)->rangeAEnd) {
            x = 16;
            y = 16;
        } else {
            x = 4;
            y = 8;
        }
        CLACT_GetActorSurfacePos(*(void **)(work + i * 28 + 12), (struct PtS *)pos, 1);
        (*(u8 **)(work + i * 28 + 16))[0] = pos[1] - y;
        (*(u8 **)(work + i * 28 + 16))[2] = pos[0] - x;
        (*(u8 **)(work + i * 28 + 16))[1] = pos[1] + y;
        (*(u8 **)(work + i * 28 + 16))[3] = pos[0] + x;
    }
}




void BR_CODEIN_ProfileCreateOam(char *work)
{
    ((struct CodeinWorkA *)work)->profileOamSys =
        BMP_OAM_CreateSys(((struct CodeinWorkA *)work)->profileHeapId, ((struct CodeinWorkA *)work)->actorSys);
}



void BR_CODEIN_ProfileDeleteOam(struct CodeinWorkA *work){ BMP_OAM_Delete(*(struct Grid * *)&work->nameGrid); BMP_OAM_Delete(*(struct Grid * *)&work->valueGrid); BMP_OAM_DeleteSys(work->profileOamSys); }




void BR_CODEIN_ProfileDeleteBgHandle(char *work)
{
    ARC_TOOL_DeleteHandle(ARC_TOOL_CreateHandle(0x17, ((struct CodeinWorkA *)work)->profileHeapId));
}



void BR_CODEIN_ProfileCreateOamObjects(char *work){ BR_CODEIN_ProfileDeleteBgHandle(work);BR_CODEIN_ProfilePrintOamObject((const Object *)work,0,32,8,0);BR_CODEIN_ProfilePrintOamObject((const Object *)work,1,32,8,0); }







/*
 * lever: form slot=&out[index] before the constructor call and store/reload through slot. The direct out[index] spelling sank the output base and left 15 bytes different.
 */
void BR_CODEIN_ProfilePrintOamObject(const Object *object,Index index,int x,int y,int unused)
{
    char *p=(char *)object;
    int source,handle,obj;
    u8 xx,yy;
    struct Grid **slots;
    CodeinProfileDescriptor desc;
    source=BR_RES_GetMsgData(*(char * *)&((struct CodeinWorkA *)p)->res);
    source=(int)MSGDATA_AllocString((struct MsgBank *)source,d_021E3850[index]);
    handle=(int)BMP_Create(10,2,32,((struct CodeinWorkA *)p)->profileHeapId);
    PRINTSYS_Print((void *)handle,1,0,(void *)source,(void *)(((struct CodeinWorkA *)p)->font));
    xx=((u8 *)(p+0x29a))[(index+22)*4];
    yy=((u8 *)(p+0x298))[(index+22)*4];
    desc.handle=(void *)handle;
    desc.x=xx+x;
    desc.y=yy+y;
    desc.data=(*(int *)&((struct CodeinWorkA *)p)->sprite6PaletteId);
    desc.zero=0;
    desc.a=0;
    desc.b=0;
    desc.c=1;
    desc.d=1;
    {
        struct Grid **out=(struct Grid **)(char *)object->grid;
        struct Grid **slot;
        struct Grid *grid;
        slot=&out[index];
        grid=BMP_OAM_Create(object->oamSys,(const struct Param *)(&desc));
        *slot=grid;
        BMP_OAM_UploadChars((struct Obj *)((int)grid));
        BMP_OAM_SetObjMode((u8 *)((int)*slot),1);
    }
    BMP_Delete((struct Bmp *)handle);
    STRBUF_Delete((struct U16Vec *)source);
}







/*
 * Extent remainder: zero alignment halfword at 021E1242.
 */
void BR_CODEIN_ProfileSetActorAnim(char *work,int state)
{
    ((struct CodeinWorkA *)work)->prevAnimState=((struct CodeinWorkA *)work)->animState;
    ((struct CodeinWorkA *)work)->animState=state;
    ((struct CodeinWorkA *)work)->rangeAFirst=0;
    ((struct CodeinWorkA *)work)->rangeAEnd=0;
    ((struct CodeinWorkA *)work)->rangeBFirst=0;
    ((struct CodeinWorkA *)work)->rangeBEnd=0;
    if (state) {
        ((struct CodeinWorkA *)work)->rangeAFirst=*(u16 *)(work+(state-1)*4+0x21c);
        ((struct CodeinWorkA *)work)->rangeAEnd=*(u16 *)(work+(state-1)*4+0x21e);
    }
    if (((struct CodeinWorkA *)work)->prevAnimState) {
        ((struct CodeinWorkA *)work)->rangeBFirst=*(u16 *)(work+(((struct CodeinWorkA *)work)->prevAnimState-1)*4+0x21c);
        ((struct CodeinWorkA *)work)->rangeBEnd=*(u16 *)(work+(((struct CodeinWorkA *)work)->prevAnimState-1)*4+0x21e);
    }
}







/*
 * 2026-10-05 (wave P7 lane V7, pengy share): EXACT in c99 and c. The older DIFF28 draft (see docs/notes) closed with two
 * changes. (1) The row index is a block-local initialised BEFORE the table copy (int row = 0, then the const Table copy):
 * the zero then lives across the copy and the copy takes r5/r3 as in the original. (2) The count row pointer of the last
 * loop is a named CodeinProfileState pointer local declared before j (cnt = p + group * 4), which gives j r3
 * and the row pointer r2. Original reads: p[0x2FC] = 1; halfword offsets; a stray store at 0x21A reading row[i - 1] after the
 * copy loop (reproduced as in the listing, probably an off-by-one in the original); no hidden callee arguments.
 */
void BR_CODEIN_ProfileInitRecordLayout(CodeinProfileState *profile)
{
  int i;
  int sum;
  int prefix;
  int group;
  int k;
  CodeinProfileState *cnt;
  int j;
  u16 truncated;
  char *tmp;
  *((int *) (((char *) profile) + 0x2FC)) = 1;
  *((u16 *) (((char *) profile) + 0x21C)) = 0;
  sum = *((int *) (((char *) profile) + 0x328));
  truncated = sum;
  *((u16 *) (((char *) profile) + 0x21E)) = truncated;
  *((u16 *) (((char *) profile) + 0x220)) = truncated;
  sum += *((int *) (((char *) profile) + 0x32C));
  tmp = ((char *) profile) + 0x222;
  truncated = sum;
  *((u16 *) tmp) = truncated;
  *((u16 *) (((char *) profile) + 0x224)) = truncated;
  sum = (*((int *) (((char *) profile) + 0x330))) + ((int) sum);
  *((u16 *) (((char *) profile) + 0x226)) = sum;
  BR_CODEIN_ProfileSetActorAnim((char *) profile, 1);
  for (i = 0; i < 3; i++)
    *((int *) (((char *) profile) + 0x23C)) += *((int *) ((((u32) profile) + (i * 4)) + 0x328));

  {
    int row = 0;
    const CodeinProfileTable table = d_021E3868;
    if ((*((int *) (((char *) profile) + 0x328))) != 4)
      row = 1;
    for (i = 0; i < 3; i++)
      *((u16 *) ((((u32) profile) + (i * 2)) + 0x214)) = table.row[row].v[i];

    *((u16 *) ((((u32) profile) + (i * 2)) + 0x214)) = table.row[row].v[i - 1];
    prefix = 0;
    for (group = 0; group < 2; group++)
    {
      prefix += *((int *) ((((u32) profile) + (group * 4)) + 0x328));
      *((int *) ((((u32) profile) + (group * 28)) + 0x150)) = prefix - 1;
    }

    group = 0;
    j = 0;
    do
    {
      cnt = (CodeinProfileState *) (((u32) profile) + (group * 4));
      for (k = 0; k < cnt->count; k++)
      {
        *((int *) ((((u32) profile) + (j * 28)) + 4)) = group + 1;
        j++;
      }

      group++;
    }
    while (j < (*((int *) (((char *) profile) + 0x23C))));
  }
}








void BR_CODEIN_ProfileSetAnimSeq(char *work, int v)
{
    ((struct CodeinWorkA *)work)->animSeq = v;
    ((struct CodeinWorkA *)work)->f230 = 0;
    ((struct CodeinWorkA *)work)->phase = 0;
    ((struct CodeinWorkA *)work)->phaseTimer = 0;
}







/*
 * Follower: 021E13D4 return-one stub, after 021E13D2 alignment.
 */
int BR_CODEIN_ProfileCreateAllActors(char *work)
{
    BR_CODEIN_ProfileSetupSprite(work);
    BR_CODEIN_ProfileUpdateActorVisible(work);
    BR_CODEIN_ProfileCreateRecordActors(work);
    BR_CODEIN_ProfileSetActorAnimFrame(work,0);
    BR_CODEIN_ProfileCreateMarkerActors(work);
    BR_CODEIN_ProfileCreateArrowActors(work);
    BR_CODEIN_ProfileUpdateActorPos(work);
    BR_CODEIN_ProfileCreateOam(work);
    BR_CODEIN_ProfileCreateOamObjects(work);
    BR_CODEIN_ProfileSetAnimSeq(work,1);
    return 0;
}







int BR_CODEIN_ProfileReturnTrue(void)
{
    return 1;
}







s32 BR_CODEIN_ProfileUpdatePendingAndButtons(char *work)
{
    if (*(s32 *)(work + 0x234) == 0) {
        (*(s32 *)(work + 0x234))++;
    } else {
        BR_CODEIN_ProfileApplyPendingStep(work);
        BUTTON_MAN_UpdateSlots(*(void **)(work + 0x294));
    }
    return 0;
}







int BR_CODEIN_ProfileUpdateScrollAnim(char *work) {
    int i,factor,selected;
    char *record;
    Point scale;
    Coords coords;
    switch(((struct CodeinWorkA *)work)->phase){
    case 0:
        BR_CODEIN_ProfileSetActorVisible(work,0,0);
        for(i=0;i<((struct CodeinWorkA *)work)->recordCount;i++){
            record=(char *)((u32)work+i*28);
            if(((struct CodeinRecordA *)record)->moveFrames!=0){
                CLACT_GetActorSurfacePos(((struct CodeinRecordA *)record)->actor,(struct PtS *)&coords.x,1);
                coords.x+=((struct CodeinRecordA *)record)->moveDx;
                coords.y+=((struct CodeinRecordA *)record)->moveDy;
                CLACT_AddActorSurfacePos(((struct CodeinRecordA *)record)->actor,(const struct Vec2 *)(&coords.x),1);
                --((struct CodeinRecordA *)record)->moveFrames;
                if(i>=((struct CodeinWorkA *)work)->rangeAFirst&&i<((struct CodeinWorkA *)work)->rangeAEnd){
                    factor=*(int *)((u32)d_021E3998+((struct CodeinRecordA *)record)->scaleStep*4);
                    scale.x=factor;scale.y=factor;
                    CLACT_SetActorScale(((struct CodeinRecordA *)record)->actor,&scale);
                    ++((struct CodeinRecordA *)record)->scaleStep;
                }
                if(i>=((struct CodeinWorkA *)work)->rangeBFirst&&i<((struct CodeinWorkA *)work)->rangeBEnd){
                    factor=*(int *)((u32)d_021E397C+((struct CodeinRecordA *)record)->scaleStep*4);
                    scale.x=factor;scale.y=factor;
                    CLACT_SetActorScale(((struct CodeinRecordA *)record)->actor,&scale);
                    ++((struct CodeinRecordA *)record)->scaleStep;
                }
            }
        }
        for(i=0;i<2;i++){
            record=(char *)((u32)work+i*28);
            if(((struct CodeinRecordA *)record)->slideFrames!=0){
                CLACT_GetActorSurfacePos(((struct CodeinRecordA *)record)->slideActor,(struct PtS *)&coords.a,1);
                coords.a+=((struct CodeinRecordA *)record)->slideDx;
                coords.b+=((struct CodeinRecordA *)record)->slideDy;
                CLACT_AddActorSurfacePos(((struct CodeinRecordA *)record)->slideActor,(const struct Vec2 *)(&coords.a),1);
                --((struct CodeinRecordA *)record)->slideFrames;
            }
        }
        if(((struct CodeinWorkA *)work)->moveFrames==0){
            for(i=((struct CodeinWorkA *)work)->rangeAFirst;i<((struct CodeinWorkA *)work)->rangeAEnd;i++){
                record=(char *)((u32)work+i*28);
                CLACT_SetActorAnimSeq(((struct CodeinRecordA *)record)->actor,BR_CODEIN_ProfileGetActorIndex(((struct CodeinRecordA *)record)->tag,((struct CodeinRecordA *)record)->mode));
            }
            for(i=((struct CodeinWorkA *)work)->rangeBFirst;i<((struct CodeinWorkA *)work)->rangeBEnd;i++){
                record=(char *)((u32)work+i*28);
                CLACT_SetActorAnimSeq(((struct CodeinRecordA *)record)->actor,BR_CODEIN_ProfileGetActorIndex(((struct CodeinRecordA *)record)->tag,((struct CodeinRecordA *)record)->mode));
            }
            ++((struct CodeinWorkA *)work)->phase;
        }
        ++((struct CodeinWorkA *)work)->phaseTimer;
        break;
    case 1:
        for(i=((struct CodeinWorkA *)work)->rangeAFirst;i<((struct CodeinWorkA *)work)->rangeAEnd;i++){
            record=(char *)((u32)work+i*28);
            if(((struct CodeinRecordA *)record)->scaleStep!=6){
                factor=*(int *)((u32)d_021E3998+((struct CodeinRecordA *)record)->scaleStep*4);
                scale.x=factor;scale.y=factor;
                CLACT_SetActorScale(((struct CodeinRecordA *)record)->actor,&scale);
                ++((struct CodeinRecordA *)record)->scaleStep;
            }
        }
        for(i=((struct CodeinWorkA *)work)->rangeBFirst;i<((struct CodeinWorkA *)work)->rangeBEnd;i++){
            record=(char *)((u32)work+i*28);
            if(((struct CodeinRecordA *)record)->scaleStep!=6){
                factor=*(int *)((u32)d_021E397C+((struct CodeinRecordA *)record)->scaleStep*4);
                scale.x=factor;scale.y=factor;
                CLACT_SetActorScale(((struct CodeinRecordA *)record)->actor,&scale);
                ++((struct CodeinRecordA *)record)->scaleStep;
            }
        }
        if(++((struct CodeinWorkA *)work)->phaseTimer==6)++((struct CodeinWorkA *)work)->phase;
        break;
    default:
        BR_CODEIN_ProfileUpdateActorPos(work);
        if(((struct CodeinWorkA *)work)->pendingKeyIsRecord==0)selected=BR_CODEIN_ProfileFindActorIndex(work,((struct CodeinWorkA *)work)->pendingKey);
        else selected=BR_CODEIN_ProfileFindRecord(work,((struct CodeinWorkA *)work)->pendingKey);
        BR_CODEIN_ProfileSetActorPos(work,selected);
        if(((struct CodeinWorkA *)work)->animState!=0)BR_CODEIN_ProfileSetActorVisible(work,0,1);
        BR_CODEIN_ProfileClear(work);
        BR_CODEIN_ProfileSetAnimSeq(work,1);
        break;
    }
    return 0;
}







extern int (*const d_021E3858[])(char *);







int BR_CODEIN_ProfileUpdateActorAnim(char *work){ int r=d_021E3858[*(int *)(work+0x22c)](work); BR_CODEIN_ProfileUpdateActorAnims(work); return r; }







/*
 * Matching: named digit load and byte-field address, with group before used in declaration order, preserve the original loop registers.
 */
void BR_CODEIN_ProfileBuildAnimName(char *work)
{
  u32 group = 0;
  u32 i;
  int used = 0;
  int digit;
  void *text;
  char *record;
  u64 *acc;
  u64 product;
  u32 tag;
  char *statusByte;
  text = STRBUF_Create(100, *((u16 *) (work + 0x34C)));
  statusByte = work + 0x210;
  *((int *) (work + 0x1F8)) = 1;
  *((u8 *) statusByte) = 0;
  *((int *) (work + 0x354)) = 0;
  *((int *) (work + 0x358)) = 0;
  *((int *) (work + 0x35C)) = 0;
  *((u32 *) (work + 0x360)) = 0;
  *((u32 *) (work + 0x364)) = 0;
  i = 0;
  if (((int) i) < (*((int *) (work + 0x23C))))
  {
    acc = (u64 *) (work + 0x360);
    do
    {
      record = (char *) (((u32) work) + (i * 28));
      if ((*((int *) record)) == 0)
      {
        *((int *) record) = 1;
        CLACT_SetActorAnimSeq(*((void **) (record + 12)), BR_CODEIN_ProfileGetActorIndex(1, *((int *) (record + 8))));
      }
      tag = *((u32 *) record);
      digit = tag - 1;
      WORDSET_FormatNumber(text, digit, 1, 1, 1);
      STRBUF_Append(*((void **) (work + 0x33C)), text);
      *((int *) ((((u32) work) + (group * 4)) + 0x354)) *= 10;
      *((int *) ((((u32) work) + (group * 4)) + 0x354)) += digit;
      used++;
      if (((int) used) >= (*((int *) ((((u32) work) + (group * 4)) + 0x328))))
      {
        group++;
        used = 0;
      }
      product = (*acc) * 10;
      *acc = product + ((u32) digit);
      i++;
    }
    while (((int) i) < (*((int *) (work + 0x23C))));
  }
  STRBUF_Delete(text);
  BR_CODEIN_ProfileSetAnimSeq(work, 3);
  *((int *) (work + 0x350)) = 2;
}







void BR_CODEIN_ProfileApplyRecords(const CodeinProfileRecord *records)
{
    char *p=(char *)records;
    int i,old,value,offset;
    ((struct CodeinWorkA *)p)->recordsApplied=1;
    p[0x1f4]=0;
    if (((struct CodeinWorkA *)p)->animState==0) {
        i=((struct CodeinWorkA *)p)->recordCount-1;
        ((struct CodeinWorkA *)p)->selectedIndex=i;
        value=records[i].value;
        ((struct CodeinWorkA *)p)->pendingStep=1;
        ((struct CodeinWorkA *)p)->pendingKey=value;
        ((struct CodeinWorkA *)p)->pendingKeyIsRecord=1;
    } else {
        i=((struct CodeinWorkA *)p)->selectedIndex;
        CLACT_SetActorAnimSeq((struct Obj *)records[i].handle,BR_CODEIN_ProfileGetActorIndex(((CodeinProfileRecord *)records)[i].tag=0,records[i].mode));
        old=records[i].value;
        if (i>0) {
            CLACT_SetActorAnimSeq((struct Obj *)records[i-1].handle,BR_CODEIN_ProfileGetActorIndex(records[i-1].tag,records[i-1].mode));
            value=records[i-1].value;
            if (old!=value) {
                ((struct CodeinWorkA *)p)->pendingStep=1;
                ((struct CodeinWorkA *)p)->pendingKey=value;
                ((struct CodeinWorkA *)p)->pendingKeyIsRecord=1;
            } else {
                ((struct CodeinWorkA *)p)->pendingStep=2;
                ((struct CodeinWorkA *)p)->pendingKey=i-1;
            }
        } else ((struct CodeinWorkA *)p)->state=1;
    }
}







void BR_CODEIN_ProfileCreateButtons(char *work) {
    int i;
    CodeinTable table;
    for(i=0;i<12;i++)*(char **)(work+i*28+16)=(work+0x298)+i*4;
    table=d_021E3880;
    for(;i<24;i++){
        *(u8 *)(work+i*4+0x298)=table.row[i-12].b-table.row[i-12].d;
        *(u8 *)(work+i*4+0x29A)=table.row[i-12].a-table.row[i-12].c;
        *(u8 *)(work+i*4+0x299)=table.row[i-12].b+table.row[i-12].d;
        *(u8 *)(work+i*4+0x29B)=table.row[i-12].a+table.row[i-12].c;
    }
    ((struct CodeinWorkA *)work)->pressedButton=255;
    ((struct CodeinWorkA *)work)->buttonMan=BUTTON_MAN_Create((u8 *)(work+0x298),(int)BR_CODEIN_ProfileHandleInput,(int)work,((struct CodeinWorkA *)work)->profileHeapId);
}







/*
 * 2026-10-05 wave P5 lane T5 (pengy share): earlier DIFF, two residues (merged far-branch stubs, idx-12 CSE).
 * 2026-10-05 wave P5 lane T5b: EXACT with the ov129 021D958C forms: idx is u32 (unsigned % and / by plain 5),
 *   `if (*(int *)(p + 0x22C) != 1) return;` then `if (arg == 0) {`, non-const CodeinProfileRecord pointer. One compile.
 *   Callbacks: BR_CODEIN_ProfileCreateButtons passes this as BUTTON_MAN_Create's callback (idx, arg, obj).
 */
void BR_CODEIN_ProfileHandleInput(u32 idx, int arg, char *work)
{
    CodeinProfileRecord *rec = (CodeinProfileRecord *)work;
    u32 i, j, v;
    int old, val;
    if (*(int *)(work + 0x22C) != 1) return;
    if (arg == 0) {
    if (idx <= 11) {
        if (rec[idx].mode == 1) {
            *(int *)(work + 0x318) = 2;
            *(int *)(work + 0x31C) = idx;
        } else {
            *(int *)(work + 0x318) = 1;
            *(int *)(work + 0x31C) = rec[idx].value;
        }
        GFL_USE_PlaySeDefaultVolume(0x703);
        return;
    }
    if (idx == 0x16) {
        u32 x, y;
        Point args;
        *(u16 *)(work + 0x1B8) = 0;
        *(u16 *)(work + 0x1BA) = 2;
        GFL_USE_PlaySeDefaultVolume(0x703);
        TOUCHPANEL_GetPointTrg(&x, &y);
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((void *)(*(int *)(work + 0x348)), 1, &args);
    } else if (idx == 0x17) {
        u32 x, y;
        Point args;
        *(u16 *)(work + 0x1B8) = 3;
        *(u16 *)(work + 0x1BA) = 2;
        GFL_USE_PlaySeDefaultVolume(0x703);
        TOUCHPANEL_GetPointTrg(&x, &y);
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((void *)(*(int *)(work + 0x348)), 1, &args);
    } else {
        *(u16 *)(work + 0x1B8) = (idx - 12) % 5;
        *(u16 *)(work + 0x1BA) = (idx - 12) / 5;
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    if (idx >= 12 && idx <= 21) {
        u32 x, y;
        Point args;
        if (*(int *)(work + 0x240) != 0) {
        TOUCHPANEL_GetPointTrg(&x, &y);
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((void *)(*(int *)(work + 0x348)), 1, &args);
        i = *(int *)(work + 0x188);
        v = idx - 11;
        CLACT_SetActorAnimSeq((struct Obj *)rec[i].handle, (u16)BR_CODEIN_ProfileGetActorIndex(rec[i].tag = v, rec[i].mode));
        old = rec[i].value;
        j = i + 1;
        if (j == *(u32 *)(work + 0x23C)) {
            *(int *)(work + 0x318) = 1;
            *(int *)(work + 0x31C) = 0;
            *(int *)(work + 0x320) = 0;
        } else {
            val = rec[j].value;
            if (old != val) {
                *(int *)(work + 0x318) = 1;
                *(int *)(work + 0x31C) = val;
                *(int *)(work + 0x320) = 0;
            } else {
                *(int *)(work + 0x318) = 2;
                *(int *)(work + 0x31C) = j;
            }
        }
        }
    } else if (idx == 0x16) {
        BR_CODEIN_ProfileApplyRecords((const CodeinProfileRecord *)work);
    } else {
        BR_CODEIN_ProfileBuildAnimName(work);
    }
    }
}







/*
 * Extent remainder: zero alignment halfword at 021E1BFE.
 */
void BR_CODEIN_ProfileApplyPendingStep(char *work)
{
    switch (((struct CodeinWorkA *)work)->pendingStep) {
    case 0: break;
    case 1:
        BR_CODEIN_ProfileSetActorAnim(work,((struct CodeinWorkA *)work)->pendingKey);
        BR_CODEIN_ProfileUpdateActorVisible(work);
        BR_CODEIN_ProfileSetActorAnimFrame(work,1);
        BR_CODEIN_ProfileSetAnimSeq(work,2);
        ((struct CodeinWorkA *)work)->pendingStep=255;
        break;
    case 2:
        BR_CODEIN_ProfileSetActorPos(work,((struct CodeinWorkA *)work)->pendingKey);
        BR_CODEIN_ProfileClear(work);
        break;
    case 255: break;
    }
}








void BR_CODEIN_ProfileClear(char *work)
{
    ((struct CodeinWorkA *)work)->pendingStep = 0;
    ((struct CodeinWorkA *)work)->pendingKey = 0;
    ((struct CodeinWorkA *)work)->pendingKeyIsRecord = 0;
}








/*
 * extent: final two bytes are alignment padding.
 */
int BR_CODEIN_ProfileFindActorIndex(char *work,int value){int i,n; n=((struct CodeinWorkA *)work)->recordCount;for(i=0;i<n;i++){if(value==*(int *)(work+i*28+4))return i;}return 0;}







/*
 * checks: 1 n/a no calls; 2 matched 1C14 confirms signed index/raw28 stride; 3 enum index DIFF7, unsigned-long count and long index each DIFF4; 4 count/address reuse DIFF4, permuter expands the read-only count field at guard and return; 5 refreshed directory and neighbours; no stack object.
 * matching: re-reading count at guard and return instead of a cached scalar lets the dying offset use r4. No stores or calls can change count during this function.
 * extent: 58 code bytes, alignment padding at021E1C7E..021E1C80; next function starts1C80.
 * retry: 5 one runs, once-only permuter budget300 found expand(n x2) after9 candidates; emitted DIFF4 baseline agrees; winner validated by run6.
 */
int BR_CODEIN_ProfileFindRecord(const char *work, int value)
{
  int i;
  int found;
  unsigned n;
  n = *((const unsigned *) (work + 0x23c));
  found = 0;
  for (i = 0; i < ((int) (*((const unsigned *) (work + 0x23c)))); i++)
  {
    if (value == (*((const int *) ((work + (i * 28)) + 4))))
      found = 1;
    else
      if (found == 1)
      return i - 1;
  }

  return (*((const unsigned *) (work + 0x23c))) - 1;
}






int BR_CODEIN_UploadCreate(struct Proc *obj,int unused,char *arg)
{
    struct CodeinWorkF *p;
    int i;
    Point pair;
    p=PROCSYS_AllocProcWork(obj,32,BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(((struct CodeinArgC *)arg)->procQuery)));
    MI_CpuFill8(p,0,32);
    p->ctx=arg;
    p->heapId=BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(((struct CodeinArgC *)arg)->procQuery));
    p->task=(int)BR_UTIL_CreateTask((int)p,(int)BR_CODEIN_UploadStepFadeIn,p->heapId);
    p->printQue=PRINTSYS_QUE_Create((void *)(p->heapId));
    p->textWin=(int)BR_UTIL_CreateTextWin(((struct CodeinArgC *)arg)->res,(void *)(p->printQue),p->heapId);
    BR_UTIL_SetWindowText((char *)(p->textWin),(char *)(((struct CodeinArgC *)arg)->res),(void *)111);
    for (i=0;i<2;i++) *(int *)((char *)p+i*4+0x10)=(int)BR_UTIL_CreateHandles(((struct CodeinArgC *)arg)->actorSys,(char *)(((struct CodeinArgC *)arg)->res),i,p->heapId);
    pair=d_021E38E0;
    BR_UTIL_StartEffect((void *)(p->tapFx), 4, &pair);
    return 1;
}






int BR_CODEIN_UploadDestroy(struct Proc *proc,int seq,struct CodeinArgA *arg,struct CodeinWorkA *work){int i;for(i=0;i<2;i++)BR_UTIL_DeleteHandles(*(char **)((char *)work+i*4+16));BR_UTIL_DeleteTextWin(work->backButton,arg->res);PRINTSYS_QUE_Delete(work->oamSys);BR_UTIL_DeleteTask((void *)((*(int *)&work->printQue)));PROCSYS_FreeProcWork(proc);return 1;}






int BR_CODEIN_UploadMain(int proc,int seq,int arg,struct CodeinWorkB *work)
{
    int i;
    if (!GAME_DATA_IsSaving((const u8 *)(((struct CodeinSubA *)(*(char * *)&work->textWin))->procQuery)) && BR_NET_HandleNetError((char *)(((struct CodeinSubA *)(*(char * *)&work->textWin))->res))==2) {
        BR_PROC_SYS_FlushWindows((void *)((*(int *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->subFade)));
        return 1;
    }
    BR_UTIL_RunTask((u8 *)(work->printQue));
    if (BR_UTIL_IsTaskIdle((int *)(work->printQue))) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles((char *)(*(int *)((char *)work+i*4+0x10)));
    PRINTSYS_QUE_Main((struct PrintSys *)(work->task));
    BR_UTIL_FlushWindow((void *)(work->button));
    return 0;
}





void BR_CODEIN_UploadStepFadeIn(int task,int *state,struct CodeinWorkB *work)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&work->textWin,2,3,0); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&work->textWin))) *state=2; break;
    case 2: BR_UTIL_SetTaskStep((int *)task,(int)BR_CODEIN_UploadStep); break;
    }
}





void BR_CODEIN_UploadStepFadeOut(int *task,int *state,struct CodeinWorkB *work)
{
    switch (*state) {
    case 0: BR_FADE_Start(**(int * *)&work->textWin,2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult((int *)(**(int * *)&work->textWin))) *state=2; break;
    case 2: BR_PROC_SYS_PopEntry((unsigned int *)((*(int *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->subFade))); BR_UTIL_ClearTaskStep(task); break;
    }
}





/*
 * lever: keep the copied u64 and quotient distinct; use the emitted _ull_mod runtime symbol.
 */
void BR_CODEIN_UploadStep(int *task,int *state,struct CodeinWorkB *work) {
    u32 out;
    u64 total;
    u32 msg,x,y; Point pair;
    void *str,*expanded,*ws,*bank;
    u64 copy,quotient;
    int result;
    switch(*state) {
    case 0:
        BATTLE_REC_Load(GAME_DATA_GetSaveControl((*(void * *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->procQuery)),89,&out,0);
        if(out==1)*state=1;else BR_UTIL_SetTaskStep((int *)task,(int)BR_CODEIN_UploadStepFadeOut);break;
    case 1:
        work->procQuery=0;BR_NET_StartRequest((*(void * *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->res),2,0);*state=2;break;
    case 2:
        ++work->procQuery;
        if(BR_NET_IsIdle((*(void * *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->res))) {
            total=0;
            if(work->procQuery>=96) {
                result=BR_NET_PollErrorMessage((*(void * *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->res),(int *)(&msg));
                if(result==0) {
                    if(BR_NET_GetUploadedDataNumber((*(void * *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->res),&total)) {
                        bank=(void *)BR_RES_GetMsgData(*(char * *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->screenFade);
                        ws=(void *)BR_RES_GetWordSet(*(char * *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->screenFade);
                        str=MSGDATA_AllocString(bank,334);expanded=STRBUF_Create(128,0x8059);
                        copy=total;quotient=copy/100000;
                        WORDSET_SetSlotNumber(ws,2,(u32)(copy%100000),5,2,1);
                        WORDSET_SetSlotNumber(ws,1,(u32)(quotient%100000),5,2,1);
                        WORDSET_SetSlotNumber(ws,0,(u32)(quotient/100000),2,2,1);
                        WORDSET_CopyTaggedText(ws,expanded,str);
                        BR_UTIL_SetWindowTextBuf((char *)(work->button),(void *)((*(int *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->screenFade)),expanded);
                        STRBUF_Delete(expanded);STRBUF_Delete(str);
                    }
                } else if(result==3) {
                    BR_PROC_SYS_FlushWindows((void *)((*(void * *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->subFade)));BR_UTIL_ClearTaskStep(task);break;
                } else BR_UTIL_SetWindowText((char *)(work->button),(char *)((*(int *)&((struct CodeinSubA *)(*(char * *)&work->textWin))->screenFade)),(void *)msg);
                BR_UTIL_StartEffect((void *)(work->screenFade), 0, 0);*state=4;
            }
        }break;
    case 3:BR_UTIL_SetTaskStep((int *)task,(int)BR_CODEIN_UploadStepFadeOut);break;
    case 4:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);pair.x=x;pair.y=y;BR_UTIL_StartEffect((void *)((*(int *)&work->menuWork)), 1, &pair);
            GFL_USE_PlaySeDefaultVolume(0x703);*state=3;
        }break;
    }
}




int BR_CODEIN_SaveCreate(struct Proc *obj,int unused,char *arg)
{
    char *p;
    int i;
    if (((struct CodeinArgC *)arg)->kind>=4) GF_PANIC_Fail(d_021E39B4,0,d_021E39B4);
    p=PROCSYS_AllocProcWork(obj,40,BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(((struct CodeinArgC *)arg)->saveProcQuery)));
    MI_CpuFill8(p,0,40);
    ((struct CodeinWorkC *)p)->saveCtx=arg;
    ((struct CodeinWorkC *)p)->heapId=BR_PROC_SYS_GetSlotId((struct BrProcQuery *)(((struct CodeinArgC *)arg)->saveProcQuery));
    ((struct CodeinWorkC *)p)->task=(int)BR_UTIL_CreateTask((int)p,(int)BR_CODEIN_SaveStepFadeIn,((struct CodeinWorkC *)p)->heapId);
    ((struct CodeinWorkC *)p)->printQue=PRINTSYS_QUE_Create((void *)(((struct CodeinWorkC *)p)->heapId));
    BR_CODEIN_SaveSetupText(p,(const Input *)arg);
    for (i=0;i<2;i++) *(int *)(p+i*4+0x14)=(int)BR_UTIL_CreateHandles(((struct CodeinArgC *)arg)->res,(char *)(((struct CodeinArgC *)arg)->procQuery),i,((struct CodeinWorkC *)p)->heapId);
    return 1;
}




/*
 * Extent remainder: zero alignment halfword at 021E20F6.
 */
int BR_CODEIN_SaveDestroy(int obj,int seq,char *arg,char *work)
{
    int i;
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles((char *)(*(int *)(work+i*4+0x14)));
    if ((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->menuState)) BR_CODEIN_SaveDeleteTextWin(work,arg);
    else { BR_CODEIN_SaveDeleteTextWin(work,arg); BR_CODEIN_SaveTeardown(work,arg); }
    PRINTSYS_QUE_Delete((struct PrintSys *)((*(int *)&((struct CodeinWorkC *)work)->printQue)));
    BR_UTIL_DeleteTask((void *)((*(int *)&((struct CodeinWorkC *)work)->task)));
    PROCSYS_FreeProcWork((struct Proc *)obj);
    return 1;
}




int BR_CODEIN_SaveMain(int proc,int seq,int arg,struct CodeinWorkC *work)
{
    int i;
    BR_UTIL_RunTask((u8 *)((*(int *)&work->task)));
    if (BR_UTIL_IsTaskIdle((int *)((*(int *)&work->task)))) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles((char *)(*(int *)((char *)work+i*4+0x14)));
    PRINTSYS_QUE_Main((struct PrintSys *)((*(int *)&work->printQue)));
    if ((*(int *)&work->textWin)) BR_UTIL_FlushWindow((void *)((*(int *)&work->textWin)));
    for (i=0;i<2;i++) if (*(int *)((char *)work+i*4+0xc)) BR_UTIL_FlushText((u8 *)(*(int *)((char *)work+i*4+0xc)));
    return 0;
}




void BR_CODEIN_SaveStepFadeIn(int *task,int *state,struct CodeinWorkC *work)
{
    switch (*state) {
    case 0: BR_FADE_Start(((struct CodeinSubA *)(work->saveCtx))->saveFade,2,3,0); *state=1; break;
    case 1: if (BR_FADE_GetResult(*(int * *)&((struct CodeinSubA *)(work->saveCtx))->saveFade)) *state=2; break;
    case 2: BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_SaveStepVideo); break;
    }
}




void BR_CODEIN_SaveStepFadeOut(int *task,int *state,struct CodeinWorkC *work)
{
    switch (*state) {
    case 0: BR_FADE_Start(((struct CodeinSubA *)(work->saveCtx))->saveFade,2,3,1); *state=1; break;
    case 1: if (BR_FADE_GetResult(*(int * *)&((struct CodeinSubA *)(work->saveCtx))->saveFade)) *state=2; break;
    case 2: BR_PROC_SYS_PopEntry((unsigned int *)(((struct CodeinSubA *)(work->saveCtx))->res)); BR_UTIL_ClearTaskStep(task); break;
    }
}




/*
 * lever: separate function-scope coordinate pairs retain the switch cases' stack slots.
 */
void BR_CODEIN_SaveStepVideo(int task,int *state,char *work) {
    u32 x0,y0,x1,y1; Point first; u32 x9,y9; Point second;
    u32 old; int result;
    switch(*state) {
    case 0:
        if(TOUCHPANEL_GetPointTrg(&x0,&y0)) {
            if(BR_CODEIN_SaveHitOptionLeft(work,x0,y0)) {BR_UTIL_SetWindowText((char *)((*(int *)&((struct CodeinWorkC *)work)->textWin)),(char *)((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->subFade)),(void *)322);*state=1;}
            else if(BR_CODEIN_SaveHitOptionRight(work,x0,y0))*state=10;
        } break;
    case 1:
        if(TOUCHPANEL_GetPointTrg(&x1,&y1)) {
            if(BR_CODEIN_SaveHitOptionLeft(work,x1,y1))*state=2;
            else if(BR_CODEIN_SaveHitOptionRight(work,x1,y1))*state=10;
        } break;
    case 2:BR_FADE_Start(((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->saveFade,2,2,1);++*state;break;
    case 3:
        if(BR_FADE_GetResult(*(int * *)&((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->saveFade)) {
            BR_CODEIN_SaveTeardown(work,((struct CodeinWorkC *)work)->saveCtx);
            BR_UTIL_SetWindowText((char *)((*(int *)&((struct CodeinWorkC *)work)->textWin)),(char *)((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->subFade)),(void *)323);
            first.x=128;first.y=96;BR_UTIL_StartEffect((void *)(((struct CodeinWorkC *)work)->introFx), 4,&first);
            ((struct CodeinWorkC *)work)->buttonText=0;++*state;
        } break;
    case 4:BR_FADE_Start(((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->saveFade,2,2,0);++*state;break;
    case 5:if(BR_FADE_GetResult(*(int * *)&((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->saveFade))++*state;break;
    case 6:
        GDS_RAP_StartVideoSave(((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->procQuery,((struct CodeinWorkC *)work)->heapId,**(int * *)&((struct CodeinWorkC *)work)->saveCtx);
        ++((struct CodeinWorkC *)work)->buttonText;++*state;break;
    case 7:
        result=GDS_RAP_StepVideoSave((char *)(((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->procQuery),**(int * *)&((struct CodeinWorkC *)work)->saveCtx);
        ++((struct CodeinWorkC *)work)->buttonText;
        if((u32)(result-2)<=1) {(*(int *)&((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->menuState)=1;*state=8;}break;
    case 8:
        old=((struct CodeinWorkC *)work)->buttonText;((struct CodeinWorkC *)work)->buttonText=old+1;
        if(old>96) {BR_UTIL_StartEffect((void *)(((struct CodeinWorkC *)work)->introFx), 0,0);BR_UTIL_SetWindowText((char *)((*(int *)&((struct CodeinWorkC *)work)->textWin)),(char *)((*(int *)&((struct CodeinSubA *)(((struct CodeinWorkC *)work)->saveCtx))->subFade)),(void *)324);*state=9;}break;
    case 9:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x9,&y9);second.x=x9;second.y=y9;
            BR_UTIL_StartEffect((void *)(((struct CodeinWorkC *)work)->tapFx), 1,&second);GFL_USE_PlaySeDefaultVolume(0x703);*state=10;
        }break;
    case 10:BR_UTIL_SetTaskStep((int *)task,(int)BR_CODEIN_SaveStepFadeOut);break;
    }
}




/*
 * lever: bounded permuter extracted index/base/heap-address temporaries;
 *   unsigned index arithmetic and top-of-block declarations preserve behavior.
 *   This removes the 12-byte setup scheduling residue; fixed one confirms EXACT.
 * arity: 0201EE0C's unit declares five arguments; this caller visibly supplies
 *   the sixth stack word (2), retained without editing the callee.
 */
void BR_CODEIN_SaveSetupText(char *work,const Input *input) {
    struct WordSet *ws;
    struct U16Vec *str,*expanded;
    int font,bank,i;
    const Rec *r;
    char *slot;
    u32 base,index;
    u16 *heapIdPtr;
    if(!((struct CodeinWorkC *)work)->textWin) ((struct CodeinWorkC *)work)->textWin=BR_UTIL_CreateTextWin((int)input->owner,(void *)(((struct CodeinWorkC *)work)->printQue),((struct CodeinWorkC *)work)->heapId);
    ws=(struct WordSet *)BR_RES_GetWordSet(input->owner);
    str=MSGDATA_AllocString((struct MsgBank *)BR_RES_GetMsgData(input->owner),321);
    heapIdPtr=(u16 *)(work+28);
    expanded=STRBUF_Create(128,*heapIdPtr);
    base=input->base;
    index=input->index;
    WORDSET_SetSlotTag(ws,0,*(void **)(input->base+index*4+16),
        *(u32 *)(base+index*4+32),1,2);
    WORDSET_CopyTaggedText(ws,expanded,str);
    BR_UTIL_SetWindowTextBuf(((struct CodeinWorkC *)work)->textWin,input->owner,expanded);
    STRBUF_Delete(expanded); STRBUF_Delete(str);
    BR_RES_LoadBgGraphics((void *)((int)input->owner),30,((struct CodeinWorkC *)work)->heapId);
    font=BR_RES_GetFont(input->owner);
    bank=BR_RES_GetMsgData(input->owner);
    for(i=0;i<2;i++) {
        r=&d_021E3900[i]; slot=work; slot=slot+i*4;
        ((struct CodeinWorkC *)slot)->bodyText=BR_UTIL_Create(4,r->a,r->b,r->c,r->d,14,(*(void * *)&((struct CodeinWorkC *)work)->printQue),((struct CodeinWorkC *)work)->heapId);
        BR_UTIL_SetTextFromMessage(*(char * *)&((struct CodeinWorkC *)slot)->bodyText,(void *)bank,r->value,(void *)font,0x3da0);
    }
}





void BR_CODEIN_SaveDeleteTextWin(char *work, char *res)
{
    if ((*(int *)&((struct CodeinWorkC *)work)->textWin) != 0) {
        BR_UTIL_DeleteTextWin((void *)((*(int *)&((struct CodeinWorkC *)work)->textWin)), ((struct CodeinA1A *)res)->res);
        (*(int *)&((struct CodeinWorkC *)work)->textWin) = 0;
    }
}








/*
 * extent: final two bytes are alignment padding.
 */
void BR_CODEIN_SaveTeardown(char *work,char *arg){int i;for(i=0;i<2;i++){if(*(void **)(work+i*4+12)){BR_UTIL_Delete(*(void **)(work+i*4+12));*(void **)(work+i*4+12)=0;}}BG_SYS_PushTile(4);BR_RES_ApplyBgSet((*(int *)&((struct CodeinArgA *)arg)->procQuery),30);}









int BR_CODEIN_SaveHitOptionLeft(char *work, int x, int y)
{
    int ok = ((unsigned int)(x - 0x20) <= 0x48) &
             ((unsigned int)(y - 0x30) <= 0x10);
    if (ok) {
        Point args;
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((void *)(((struct CodeinWorkC *)work)->tapFx), 1, &args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}









int BR_CODEIN_SaveHitOptionRight(char *work, int x, int y)
{
    int ok = ((unsigned int)(x - 0x90) <= 0x48) &
             ((unsigned int)(y - 0x30) <= 0x10);
    if (ok) {
        Point args;
        args.x = x;
        args.y = y;
        BR_UTIL_StartEffect((void *)(((struct CodeinWorkC *)work)->tapFx), 1, &args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}








int BR_CODEIN_SoclCreate(void *obj,int seq,char *arg)
{
    struct CodeinWorkD *p;
    int i;
    p=PROCSYS_AllocProcWork(obj,0x54,BR_PROC_SYS_GetSlotId((*(void * *)&((struct CodeinArgA *)arg)->uiRes)));
    MI_CpuFill8(p,0,0x54);
    p->arg=arg;
    p->soclHeapId=BR_PROC_SYS_GetSlotId((*(void * *)&((struct CodeinArgA *)arg)->uiRes));
    p->oamSys=BMP_OAM_CreateSys(p->soclHeapId,(*(void * *)&((struct CodeinArgA *)arg)->actorSys));
    p->titleText=BR_UTIL_CreateTask((int)p,(int)BR_CODEIN_SoclStep,p->soclHeapId);
    (*(unsigned int *)&p->backButton)=PRINTSYS_QUE_Create((void *)(unsigned int)p->soclHeapId);
    for (i=0;i<2;i++) *(void **)((char *)p+i*4+0x30)=BR_UTIL_CreateHandles((unsigned int)((*(void * *)&((struct CodeinArgA *)arg)->actorSys)),(char *)(((struct CodeinArgA *)arg)->res),i,p->soclHeapId);
    return 1;
}








/*
 * Extent remainder: zero alignment halfword at 021E263E.
 */
int BR_CODEIN_SoclDestroy(int obj,int seq,int arg,char *work)
{
    int i;
    BR_CODEIN_CallAndClearDestroyFn(work+0x4c,(int)work,(int)(((struct CodeinWorkD *)work)->arg));
    for (i=0;i<2;i++) BR_UTIL_DeleteHandles(*(char **)(work+i*4+0x30));
    if (((struct CodeinWorkD *)work)->headerText) {
        BR_UTIL_DeleteTextWin(((struct CodeinWorkD *)work)->headerText,(*(int *)&((struct CodeinSubA *)(((struct CodeinWorkD *)work)->arg))->screenFade));
        *(int *)&((struct CodeinWorkD *)work)->headerText=0;
    }
    PRINTSYS_QUE_Delete((struct PrintSys *)((*(int *)&((struct CodeinWorkD *)work)->backButton)));
    BR_UTIL_DeleteTask((void *)((*(int *)&((struct CodeinWorkD *)work)->titleText)));
    BMP_OAM_DeleteSys((void *)((*(int *)&((struct CodeinWorkD *)work)->oamSys)));
    BR_PROC_SYS_PopEntry((unsigned int *)(((struct CodeinSubA *)(((struct CodeinWorkD *)work)->arg))->res));
    PROCSYS_FreeProcWork((struct Proc *)obj);
    return 1;
}








int BR_CODEIN_SoclMain(int proc,int seq,int arg,struct CodeinWorkD *work)
{
    int i;
    if (!GAME_DATA_IsSaving((const u8 *)(((struct CodeinSubA *)(work->arg))->procQuery)) && BR_NET_HandleNetError((char *)((*(int *)&((struct CodeinSubA *)(work->arg))->subFade)))==2) {
        BR_PROC_SYS_FlushWindows((void *)(((struct CodeinSubA *)(work->arg))->res));
        return 1;
    }
    BR_UTIL_RunTask((u8 *)((*(int *)&work->titleText)));
    if (BR_UTIL_IsTaskIdle((int *)((*(int *)&work->titleText)))) return 1;
    for (i=0;i<2;i++) BR_UTIL_RunHandles((char *)(*(int *)((char *)work+i*4+0x30)));
    PRINTSYS_QUE_Main((struct PrintSys *)((*(int *)&work->backButton)));
    if ((*(int *)&work->headerText)) BR_UTIL_FlushWindow((void *)((*(int *)&work->headerText)));
    for (i=0;i<2;i++) if (*(int *)((char *)work+i*4+0x28)) BR_UTIL_FlushText((u8 *)(*(int *)((char *)work+i*4+0x28)));
    return 0;
}






void BR_CODEIN_SoclStep(int *task,CodeinSoclState *state,char *work) {
    u32 req[2];
    u32 msg;
    int extra;char *rec;
    u32 x,y;Point click;SOCLResource cb;
    int result,found,i;
    u64 value;char *arg;
    switch(*state) {
    case 0:
        BR_CODEIN_SOCL_InitDefault(&cb);arg=*(char **)(work+0x3c);*(SOCLResource *)(work+0x4c)=cb;
        BR_CODEIN_CallAndClearStepFn((char *)work+0x4c,(int)work,(int)arg);*state=1;break;
    case 1:BR_FADE_Start(**(int **)(work+0x3c),2,3,0);*state=2;break;
    case 2:if(BR_FADE_GetResult((int *)**(int **)(work+0x3c)))*state=3;break;
    case 3:
        MI_CpuFill8(req,0,8);*(u64 *)req=*(u64 *)(*(char **)(work+0x3c)+0x1c);
        BR_NET_StartRequest(*(void **)(*(char **)(work+0x3c)+12),3,(const int *)req);
        *(u32 *)(work+0x44)=0;*state=4;break;
    case 4:
        ++*(u32 *)(work+0x44);
        if(BR_NET_IsIdle(*(void **)(*(char **)(work+0x3c)+12)) && *(u32 *)(work+0x44)>96) {
            BR_UTIL_StartEffect((void *)(*(int *)(work+0x30)), 0, 0);*state=5;
        }break;
    case 5:
        result=BR_NET_PollErrorMessage(*(void **)(*(char **)(work+0x3c)+12),(int *)(&msg));
        if(result==0) {
            if(BR_NET_GetVideoReply(*(void **)(*(char **)(work+0x3c)+12),(int)(&rec),&extra)) {
                BATTLE_REC_SetData(rec,rec+0x80,rec+0xc4,(unsigned int)GAME_DATA_GetSaveControl(*(void **)(*(char **)(work+0x3c)+0x14)));
                found=0;value=BATTLE_REC_GetHeaderParam((u8 *)BATTLE_REC_GetHeader(),4,0);
                i=1;arg=*(char **)(work+0x3c);
                for(;i<=3;i++) {
                    if(*(u64 *)(*(char **)(arg+0x18)+i*8+0x30)==value) {found=1;break;}
                }
                if(found==1) {BR_UTIL_SetWindowText((char *)(*(int *)(work+8)),(char *)(*(int *)(arg+8)),(void *)316);*state=9;}
                else *state=6;
            } else {BR_UTIL_SetWindowText((char *)(*(int *)(work+8)),(char *)(*(int *)(*(char **)(work+0x3c)+8)),(void *)339);*state=9;}
        } else {BR_UTIL_SetWindowText((char *)(*(int *)(work+8)),(char *)(*(int *)(*(char **)(work+0x3c)+8)),(void *)msg);*state=9;}
        break;
    case 9:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);click.x=x;click.y=y;BR_UTIL_StartEffect((void *)(*(int *)(work+0x34)), 1, &click);
            GFL_USE_PlaySeDefaultVolume(0x703);*state=10;
        }break;
    case 6:BR_FADE_Start(**(int **)(work+0x3c),2,3,1);*state=7;break;
    case 7:if(BR_FADE_GetResult((int *)**(int **)(work+0x3c)))*state=8;break;
    case 8:BR_CODEIN_CallAndClearDestroyFn((char *)work+0x4c,(int)((char *)work),(int)(*(char **)(work+0x3c)));BR_UTIL_SetTaskStep((int *)task,(int)BR_CODEIN_MenuStep);break;
    case 10:BR_FADE_Start(**(int **)(work+0x3c),2,3,1);*state=11;break;
    case 11:if(BR_FADE_GetResult((int *)**(int **)(work+0x3c)))*state=12;break;
    case 12:BR_CODEIN_CallAndClearDestroyFn((char *)work+0x4c,(int)((char *)work),(int)(*(char **)(work+0x3c)));BR_UTIL_ClearTaskStep(task);break;
    }
}






/*
 * lever: function-scope pair locals preserve stack-slot order across switch cases.
 */
void BR_CODEIN_MenuStep(int *task,int *state,char *work) {
    u32 x,y;
    Point first,second,cb;
    int i;
    switch(*state) {
    case 0: {
        BR_CODEIN_GetMenuCallbacks(&cb);
        *(Point *)(work+0x4c)=cb;
        BR_CODEIN_CallAndClearStepFn(work+0x4c,(int)work,*(int *)&((struct CodeinWorkA *)work)->menuCtx);
        *state=1; break;
    }
    case 1: BR_FADE_Start(**(int * *)&((struct CodeinWorkA *)work)->menuCtx,2,3,0); *state=2; break;
    case 2: if(BR_FADE_GetResult((int *)**(int * *)&((struct CodeinWorkA *)work)->menuCtx)) *state=3; break;
    case 3: {
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            for(i=0;i<=2;i++) {
                if(BR_BTN_HitTestWithSound((unsigned int *)(*(int *)(work+i*4+0x14)),x,y)) {
                    first.x=x; first.y=y;
                    BR_UTIL_StartEffect((void *)((*(int *)&((struct CodeinWorkA *)work)->listText)), 1, &first);
                    (*(int *)&((struct CodeinWorkA *)work)->recordTapFx)=i;
                    if(*(int *)((u32)*(char * *)&((struct CodeinSubA *)(((struct CodeinWorkA *)work)->menuCtx))->net+(u32)i*4+4)) *state=7;
                    else *state=4;
                }
            }
            if(BR_BTN_HitTestWithSound((unsigned int *)((*(int *)&((struct CodeinWorkA *)work)->saveCtx)),x,y)) {
                second.x=x; second.y=y;
                BR_UTIL_StartEffect((void *)((*(int *)&((struct CodeinWorkA *)work)->listText)), 1, &second); *state=10;
            }
        }
        break;
    }
    case 4: BR_FADE_Start(**(int * *)&((struct CodeinWorkA *)work)->menuCtx,2,3,1); *state=5; break;
    case 5: if(BR_FADE_GetResult((int *)**(int * *)&((struct CodeinWorkA *)work)->menuCtx)) *state=6; break;
    case 6: BR_CODEIN_CallAndClearDestroyFn(work+0x4c,(int)work,(int)(((struct CodeinWorkA *)work)->menuCtx)); BR_UTIL_SetTaskStep(*(int * *)&((struct CodeinWorkA *)work)->backButton,(int)BR_CODEIN_MenuStepSave); break;
    case 7: BR_FADE_Start(**(int * *)&((struct CodeinWorkA *)work)->menuCtx,2,3,1); ++*state; break;
    case 8: if(BR_FADE_GetResult((int *)**(int * *)&((struct CodeinWorkA *)work)->menuCtx)) ++*state; break;
    case 9: BR_CODEIN_CallAndClearDestroyFn(work+0x4c,(int)work,(int)(((struct CodeinWorkA *)work)->menuCtx)); BR_UTIL_SetTaskStep(*(int * *)&((struct CodeinWorkA *)work)->backButton,(int)BR_CODEIN_MenuStepInput); break;
    case 10: BR_FADE_Start(**(int * *)&((struct CodeinWorkA *)work)->menuCtx,2,3,1); *state=11; break;
    case 11: if(BR_FADE_GetResult((int *)**(int * *)&((struct CodeinWorkA *)work)->menuCtx)) *state=12; break;
    case 12: BR_CODEIN_CallAndClearDestroyFn(work+0x4c,(int)work,(int)(((struct CodeinWorkA *)work)->menuCtx)); BR_UTIL_ClearTaskStep(task); break;
    }
}






/*
 * lever: Declare scalar locals before Point; assign the returned Point as a whole to p+0x4C. Separate word stores produced the wrong stack/copy schedule.
 */
void BR_CODEIN_MenuStepInput(int *task,unsigned *state,char *work)
{
    unsigned x,y;
    SOCLResource a;
    switch(*state) {
    case 0:
        BR_CODEIN_CopySoclResource(&a);
        *(SOCLResource *)(work+0x4c)=a;
        BR_CODEIN_CallAndClearStepFn(work+0x4c,(int)work,*(int *)&((struct CodeinWorkA *)work)->menuCtx);
        ++*state; break;
    case 1:
        BR_FADE_Start(**(int * *)&((struct CodeinWorkA *)work)->menuCtx,2,3,0);
        ++*state; break;
    case 2:
        if(BR_FADE_GetResult(**(int ** *)&((struct CodeinWorkA *)work)->menuCtx)) ++*state;
        break;
    case 3:
        if(TOUCHPANEL_GetPointTrg(&x,&y)) {
            if(BR_CODEIN_HitTestOptionLeft(work,x,y)) *state=4;
            if(BR_CODEIN_HitTestOptionRight(work,x,y)) *state=7;
        }
        break;
    case 4:
        BR_FADE_Start(**(int * *)&((struct CodeinWorkA *)work)->menuCtx,2,3,1);
        ++*state; break;
    case 5:
        if(BR_FADE_GetResult(**(int ** *)&((struct CodeinWorkA *)work)->menuCtx)) ++*state;
        break;
    case 6:
        BR_CODEIN_CallAndClearDestroyFn(work+0x4c,(int)work,(int)(((struct CodeinWorkA *)work)->menuCtx));
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_MenuStepSave); break;
    case 7:
        BR_FADE_Start(**(int * *)&((struct CodeinWorkA *)work)->menuCtx,2,3,1);
        ++*state; break;
    case 8:
        if(BR_FADE_GetResult(**(int ** *)&((struct CodeinWorkA *)work)->menuCtx)) ++*state;
        break;
    case 9:
        BR_CODEIN_CallAndClearDestroyFn(work+0x4c,(int)work,(int)(((struct CodeinWorkA *)work)->menuCtx));
        BR_UTIL_SetTaskStep(task,(int)BR_CODEIN_MenuStep); break;
    }
}





/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * lever: Write the zero halfwords in source order p+0x40 then p+0x42; the reversed spelling exchanged those two store addresses.
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 BattleRecModeTable[];
 * u64 BATTLE_REC_GetHeaderParam(char *p,int selector,int index) {
 *     int i;
 *     u16 v;
 *     switch(selector) {
 *     case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *     case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *     case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *     case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==BattleRecModeTable[i])return i;return 0;
 *     case 4: return *(u64 *)(p+0x38);
 *     case 5: return *(u8 *)(p+0x2a);
 *     case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *     case 7: return *(u8 *)(p+0x2b);
 *     default:return 0;
 *     }
 * }
 */
void BR_CODEIN_MenuStepSave(int *task,unsigned *state,char *work)
{
    Point initial;
    CodeinProfileConfig cfg;
    int x,y;
    Point pair;
    int r;
    switch(*state) {
    case 0:
        if(!*(void **)(work+8)) *(void **)(work+8)=BR_UTIL_CreateTextWin(*(int *)(*(char **)(work+0x3c)+8),(void *)(*(int *)(work+4)),*(u16 *)(work+0x38));
        BR_UTIL_SetWindowText(*(void **)(work+8),(char *)(*(int *)(*(char **)(work+0x3c)+8)),(void *)0x13d);
        initial.x=0x80;initial.y=0x60;
        BR_UTIL_StartEffect((void *)(*(int *)(work+0x30)), 4, &initial);
        BR_FADE_Start(**(int **)(work+0x3c),2,3,0);++*state;break;
    case 1:if(BR_FADE_GetResult(**(int ***)(work+0x3c))) ++*state;break;
    case 2:
        *(int *)(work+0x44)=0;
        *(u16 *)(work+0x40)=0;*(u16 *)(work+0x42)=0;
        ++*state;break;
    case 3:
        r=GDS_RAP_SaveVideoSeq((void *)(*(int *)(*(char **)(work+0x3c)+0x14)),*(int *)(work+0x10)+1,(unsigned char)(*(int *)(*(char **)(work+0x3c)+0x24)),(u16 *)(work+0x40),(u16 *)(work+0x42),*(u16 *)(work+0x38));
        if((unsigned)(r-2)<=1) {
            *(int *)(*(char **)(work+0x3c)+0x28)=1;
            *(int *)(*(char **)(work+0x3c)+0x2c)=*(int *)(work+0x10)+1;
            ++*state;
        }
        ++*(int *)(work+0x44);break;
    case 4:
        MI_CpuFill8(&cfg,0,8);
        cfg.wide=BATTLE_REC_GetHeaderParam((u8 *)BATTLE_REC_GetHeader(),4,0);
        BR_NET_StartRequest(*(char **)(*(char **)(work+0x3c)+12),8,(const int *)(&cfg));
        BR_UTIL_SetWindowText(*(void **)(work+8),(char *)(*(int *)(*(char **)(work+0x3c)+8)),(void *)0x13f);
        *(int *)(work+0x48)=0;++*(int *)(work+0x44);++*state;break;
    case 5:
        ++*(unsigned *)(work+0x44);++*(unsigned *)(work+0x48);
        if(BR_NET_IsIdle(*(char **)(*(char **)(work+0x3c)+12)) && *(unsigned *)(work+0x44)>0x60 && *(unsigned *)(work+0x48)>0x3c) {
            BR_UTIL_StartEffect((void *)(*(int *)(work+0x30)), 0, 0);
            BR_UTIL_SetWindowText(*(void **)(work+8),(char *)(*(int *)(*(char **)(work+0x3c)+8)),(void *)0x140);
            ++*state;
        }break;
    case 6:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            BR_UTIL_StartEffect((void *)(*(int *)(work+0x34)), 1, &pair);
            GFL_USE_PlaySeDefaultVolume((int)0x703);++*state;
        }break;
    case 7:BR_FADE_Start(**(int **)(work+0x3c),2,3,1);++*state;break;
    case 8:if(BR_FADE_GetResult(**(int ***)(work+0x3c))) ++*state;break;
    case 9:
        if(*(void **)(work+8)) {BR_UTIL_DeleteTextWin(*(void **)(work+8),*(int *)(*(char **)(work+0x3c)+8));*(int *)(work+8)=0;}
        BR_UTIL_ClearTaskStep(task);break;
    }
}






void BR_CODEIN_CallAndClearStepFn(char *holder, int work, int ctx)
{
    if (((struct CodeinStoredFns *)holder)->stepFn != 0) {
        ((void (*)(int, int)) * (void **)holder)(work, ctx);
        *(int *)&((struct CodeinStoredFns *)holder)->stepFn = 0;
    }
}






void BR_CODEIN_CallAndClearDestroyFn(char *holder,int work,int ctx) { void (*f)(int,int);f=*(void (**)(int,int))(holder+4);if(f){f(work,ctx);*(int *)&((struct CodeinStoredFns *)holder)->destroyFn=0;} }





void BR_CODEIN_CopySoclResource(SOCLResource *resource)
{
    *resource=d_021E3910.pair;
}





/*
 * lever: Bounded permuter split the scaled index and delayed the base load, then introduced store-address temporaries after the constructor. Fixed one validated its behavior-preserving winning C.
 */
void BR_CODEIN_SoclSetupText(char *work, const char *arg)
{
  void *a;
  void *s;
  void *b;
  int h;
  int c;
  int i;
  const unsigned char *r;
  unsigned base;
  unsigned index;
  void **textRef;
  void **textPtr;
  char *printQuePtr;
  if (!(*((void **) (work + 8))))
    *((void **) (work + 8)) = BR_UTIL_CreateTextWin(*((int *) (arg + 8)), (void *)(*((int *) (work + 4))), *((u16 *) (work + 0x38)));
  a = (void *) BR_RES_GetWordSet(*((char **) (arg + 8)));
  s = MSGDATA_AllocString((struct MsgBank *)BR_RES_GetMsgData(*((char **) (arg + 8))), 0x141);
  b = STRBUF_Create(0x80, *((u16 *) (work + 0x38)));
  index = *((unsigned *) (work + 0x10));
  index = index * 4;
  base = *((unsigned *) (arg + 0x18));
  WORDSET_SetSlotTag(a, 0, (const void *)(*((unsigned *) ((base + index) + 0x14))), *((unsigned *) ((((unsigned) base) + index) + 0x24)), 1, 2);
  WORDSET_CopyTaggedText(a, b, s);
  BR_UTIL_SetWindowTextBuf(*((void **) (work + 8)), (void *)(*((int *) (arg + 8))), b);
  STRBUF_Delete(b);
  STRBUF_Delete(s);
  BR_RES_LoadBgGraphics((void *)(*((int *) (arg + 8))), 0x1e, *((u16 *) (work + 0x38)));
  h = BR_RES_GetFont(*((char **) (arg + 8)));
  c = BR_RES_GetMsgData(*((char **) (arg + 8)));
  for (i = 0; i < 2; i++)
  {
    r = d_021E3928;
    r = r + (i * 8);
    printQuePtr = work + 4;
    *((void **) ((work + (i * 4)) + 0x28)) = BR_UTIL_Create(4, r[0], r[1], r[2], r[3], 14, *((void **) printQuePtr), *((u16 *) (work + 0x38)));
    textPtr = (void **) (0x28 + (work + (i * 4)));
    textRef = textPtr;
    BR_UTIL_SetTextFromMessage(*textRef, (void *)c, (void *)(*((int *) (r + 4))), (void *)h, 0x3da0);
  }

}





void BR_CODEIN_SoclTeardown(struct CodeinWorkD *work,struct CodeinArgA *arg)
{
    int i;
    for (i=0;i<2;i++) {
        if (*(void **)((char *)work+i*4+0x28)) {
            BR_UTIL_Delete(*(void **)((char *)work+i*4+0x28));
            *(int *)((char *)work+i*4+0x28)=0;
        }
    }
    BG_SYS_PushTile(4);
    BR_RES_ApplyBgSet(arg->res,0x1e);
    if (work->headerText) {
        BR_UTIL_DeleteTextWin(work->headerText,arg->res);
        *(int *)&work->headerText=0;
    }
}
