/*
 * file:     pokemontrade_nego.c
 * unit:     yes
 * function: POKETRADE_NEGO_FreeOfferMons, POKETRADE_NEGO_ClearOfferSlots, POKETRADE_NEGO_CountOwnOffers, POKETRADE_NEGO_CheckCancelTouch, POKETRADE_NEGO_CloseCancelMenu, POKETRADE_NEGO_CanConfirmOffers, POKETRADE_NEGO_HasOffer, POKETRADE_NEGO_FindOfferIndex, POKETRADE_NEGO_StoreRemoteOffer, POKETRADE_NEGO_FindFreeOfferIndex, POKETRADE_NEGO_AddOffer, POKETRADE_NEGO_RemoveOffer, POKETRADE_NEGO_RegisterIconResources, POKETRADE_NEGO_ReleaseIconResources, POKETRADE_NEGO_AddSelectedAsOffer, POKETRADE_NEGO_DrawPlayerNames, POKETRADE_NEGO_DrawOfferStatusLabel, POKETRADE_NEGO_DeleteHeaderWindows, POKETRADE_NEGO_StepQuitMenuChoice, POKETRADE_NEGO_StepOpenQuitMenu, POKETRADE_NEGO_StepWaitSync25, POKETRADE_NEGO_StepSendSync25, POKETRADE_NEGO_StepWaitReplyKey, POKETRADE_NEGO_StepResolveReplies, POKETRADE_NEGO_StepSendReply, POKETRADE_NEGO_StepWaitReplySync, POKETRADE_NEGO_StepSendCancelReply, POKETRADE_NEGO_StepWaitCancelSync, POKETRADE_NEGO_StepShowWaitMessageA, POKETRADE_NEGO_StepShowWaitMessageB, POKETRADE_NEGO_StepConfirmMenuChoice, POKETRADE_NEGO_StepOpenConfirmMenu, POKETRADE_NEGO_StepResolveConfirm, POKETRADE_NEGO_StepSendConfirm, POKETRADE_NEGO_StepBeginConfirm, POKETRADE_NEGO_ShowOfferSummary, POKETRADE_NEGO_PollOfferCursorKeys, POKETRADE_NEGO_StepReturnFromSummary, POKETRADE_NEGO_StepWaitSelectionDelay, POKETRADE_NEGO_StepBrowseOffers, POKETRADE_NEGO_StepOpenSummaryFromBrowse, POKETRADE_NEGO_StepOfferActionChoice, POKETRADE_NEGO_StepOpenOfferActionMenu, POKETRADE_NEGO_StepSendOfferMon, POKETRADE_NEGO_StepSendOfferIndex, POKETRADE_NEGO_TrySelectOffer, POKETRADE_NEGO_StepRebuildSceneAfterWipe, POKETRADE_NEGO_StepWaitMessageThenWipe, POKETRADE_NEGO_StepSendDeclineConfirm, POKETRADE_NEGO_StepBeginDeclineConfirm, POKETRADE_NEGO_StepDeclineMenuChoice, POKETRADE_NEGO_StepOpenDeclineMenu, POKETRADE_NEGO_StepBrowseOffersMain, POKETRADE_NEGO_StepWaitInputAfterMessage, POKETRADE_NEGO_StepShowNoOfferMessage, POKETRADE_NEGO_SetupWindowRegsOffers, POKETRADE_NEGO_StepWaitWipeBrowse, POKETRADE_NEGO_StepBuildBrowseScene, POKETRADE_NEGO_StepWaitWipeToBrowse, POKETRADE_NEGO_StepWipeToBrowse, POKETRADE_NEGO_StepSendReady, POKETRADE_NEGO_StepWaitReadySync, POKETRADE_NEGO_StepSendCheckResult, POKETRADE_NEGO_AbortHttpRequest, POKETRADE_NEGO_StepPollMonCheck, POKETRADE_NEGO_StepStartMonCheck, POKETRADE_NEGO_StepRetryMonCheck, POKETRADE_NEGO_StepBeginMonCheckWipe, POKETRADE_NEGO_StepResolveFinalAgree, POKETRADE_NEGO_StepSendFinalAgree, POKETRADE_NEGO_StepSendFinalReady, POKETRADE_NEGO_StepWaitMessageThenContinue, POKETRADE_NEGO_StepBeginFinalReady, POKETRADE_NEGO_StepFinalAgreeMenuChoice, POKETRADE_NEGO_StepOpenFinalAgreeMenu, POKETRADE_NEGO_StepWaitFinalMessage, POKETRADE_NEGO_StepBeginFinalWait, POKETRADE_NEGO_StepCancelMenuChoice, POKETRADE_NEGO_StepOpenCancelMenu, POKETRADE_NEGO_StepShowCancelMessage, POKETRADE_NEGO_IsMonOwnOffer, POKETRADE_NEGO_IsMonPeerSelected, POKETRADE_NEGO_StepWaitTouchRelease, POKETRADE_NEGO_StepSendOfferRemoval, POKETRADE_NEGO_InitOfferMarkers, POKETRADE_NEGO_SetOfferMarkersState, POKETRADE_NEGO_UpdateOfferMarkers, POKETRADE_NEGO_PollMarkerTouch, POKETRADE_NEGO_TickMarkerTimers, POKETRADE_NEGO_FlashMarker, POKETRADE_NEGO_ResetMarkers, POKETRADE_NEGO_ExitMarkers, POKETRADE_NEGO_ShowOfferSlotMon, POKETRADE_NEGO_TickOfferSlotTimers, POKETRADE_NEGO_SendOfferMon, POKETRADE_NEGO_PlaySeByKeyA, POKETRADE_NEGO_PlaySeByKeyB, POKETRADE_NEGO_PlaySeByEvent
 * address:  0x021DD174
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pokemontrade_proc.c, pokemontrade_3d.c by tools/splitfile.py.
 *
 * symbols:
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   func_020173EC 0x020173EC thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   MI_CpuFill8 0x02082BCC arm
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_02017E1C 0x02017E1C thumb
 *   POKETRADE_2D_CreateOfferIconActor 0x021E6334 thumb ov119
 *   POKETRADE_NEGO_ShowOfferSlotMon 0x021DF918 thumb ov119
 *   POKETRADE_2D_DeleteOfferIconActor 0x021E62D4 thumb ov119
 *   POKETRADE_NEGO_FlashMarker 0x021DF8A0 thumb ov119
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssFlipped  0x021E36A8  thumb  ov119
 *   func_0202136C 0x0202136C thumb
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_02045CAC 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   POKETRADE_SAVE_ShowSummaryMon 0x021E219C thumb ov119
 *   func_02040588 0x02040588 arm
 *   POKETRADE_SAVE_CloseSummaryPage 0x021E1CE8 thumb ov119
 *   POKETRADE_2D_LoadBackgroundGfx 0x021E3E80 thumb ov119
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   POKETRADE_SAVE_OpenSummaryScreen 0x021E1D68 thumb ov119
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   POKETRADE_SAVE_CloseTaskMenu 0x021E12F8 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   POKETRADE_SAVE_OpenTaskMenu 0x021E1410 thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_0207D658 0x0207D658 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   POKETRADE_NEGO_StepSendOfferRemoval 0x021DF708 thumb ov119
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020307B0 0x020307B0 arm
 *   POKETRADE_NEGO_StepShowCancelMessage 0x021DF5D8 thumb ov119
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   POKETRADE_NEGO_SetOfferMarkersState 0x021DF7AC thumb ov119
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   POKETRADE_NEGO_ExitMarkers 0x021DF904 thumb ov119
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   POKETRADE_NEGO_InitOfferMarkers 0x021DF78C thumb ov119
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   WIPE_ResetBrightness 0x02022230 thumb
 *   POKETRADE_SAVE_OpenTaskMenuAt 0x021E131C thumb ov119
 *   GFL_NET_IsNetTypeWifi 0x0203D29C arm
 *   POKETRADE_NEGO_PollMarkerTouch 0x021DF7F0 thumb
 *   POKETRADE_2D_SetupSubBgs 0x021E5680 thumb ov119
 *   func_02049B40 0x02049B40 arm
 *   POKETRADE_2D_RegisterIconSpriteResources 0x021E58A0 thumb ov119
 *   POKETRADE_2D_CreateBoxIconActors 0x021E467C thumb ov119
 *   POKETRADE_2D_LoadMainGfxAndMessageWindow 0x021E3F74 thumb ov119
 *   func_02030734 0x02030734 arm
 *   func_0201293C 0x0201293C thumb
 *   func_02012934 0x02012934 thumb
 *   POKETRADE_2D_DeleteAllOfferIconActors 0x021E64B8 thumb ov119
 *   POKETRADE_NEGO_ResetMarkers 0x021DF8E0 thumb ov119
 *   POKETRADE_2D_DeleteBoxWindows 0x021E4570 thumb ov119
 *   POKETRADE_NEGO_UpdateOfferMarkers 0x021DF7D0 thumb ov119
 *   POKETRADE_2D_DeleteAllBoxIcons 0x021E4888 thumb ov119
 *   POKETRADE_SAVE_DeletePartnerOfferCard 0x021E293C thumb ov119
 *   POKETRADE_2D_FreeMainResources 0x021E4000 thumb ov119
 *   CLACT_CreateUnit 0x0204B100 arm
 *   POKETRADE_SAVE_CreateMessageResources 0x021E10D8 thumb ov119
 *   POKETRADE_2D_CreateFontResource 0x021E3FE4 thumb ov119
 *   POKETRADE_3D_CreateTouchbar 0x021E3C20 thumb ov119
 *   POKETRADE_NEGO_TickMarkerTimers 0x021DF868 thumb ov119
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   POKETRADE_NEGO_TickOfferSlotTimers 0x021DF978 thumb ov119
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   DWC_RAPCOMMON_DestroySubHeap 0x02156ED0 thumb ov009
 *   POKETRADE_2D_MovePickedIconActor 0x021E68F4 thumb ov119
 *   POKETRADE_SAVE_OpenTaskMenuWindow 0x021E2984 thumb ov119
 *   POKETRADE_SAVE_IsTouchOutsideArea 0x021E2A80 thumb ov119
 *   POKETRADE_SAVE_CloseTaskMenuWindow 0x021E2A1C thumb ov119
 *   func_02007984 0x02007984 thumb
 *   d_021E80E0 0x021E80E0 data a4
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   POKETRADE_NEGO_SendOfferMon 0x021DF9E8 thumb ov119
 *   d_021E7704     0x021E7704  data  a4
 *   func_020275E4  0x020275E4  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   d_021E76FC 0x021E76FC data a4
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   POKETRADE_NEGO_SetupWindowRegsOffers  0x021DEBD4  thumb  ov119
 *   d_021E76F4 0x021E76F4 data a4
 *   POKETRADE_NEGO_StepBrowseOffersMain 0x021DEA24 thumb ov119
 *   d_021E76E4 0x021E76E4 data a4
 *   POKETRADE_2D_UpdateOfferIconHighlight 0x021E6440 thumb ov119
 *   func_02049990 0x02049990 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   d_021E770C 0x021E770C data a4
 *   POKETRADE_2D_SetDisplayConfig 0x021E57E8 thumb ov119
 *   d_021E76DC     0x021E76DC  data  a4
 *   func_021DD09C 0x021DD09C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepOpenDeclineMenu 0x021DE9E8 thumb ov119
 *   POKETRADE_NEGO_TrySelectOffer 0x021DE754 thumb ov119
 *   POKETRADE_NEGO_PollOfferCursorKeys 0x021DE208 thumb ov119
 *   func_021DD140 0x021DD140 thumb ov119
 *   POKETRADE_PROC_ResetTouchbarBackButton 0x021D8980 thumb ov119
 *   POKETRADE_2D_StepCursorSlide 0x021E69C0 thumb ov119
 *   POKETRADE_NEGO_ReleaseIconResources 0x021DD588 thumb ov119
 *   POKETRADE_NEGO_DeleteHeaderWindows 0x021DD9DC thumb ov119
 *   POKETRADE_NEGO_RegisterIconResources 0x021DD528 thumb ov119
 *   func_02041570 0x02041570 arm
 *   POKETRADE_2D_SetupCursorBg 0x021E6B90 thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_NEGO_StepWaitMessageThenWipe 0x021DE8C0 thumb ov119
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   NHTTP_RAP_RecordList_GetCount 0x021B99F0 thumb ov114
 *   NHTTP_RAP_RecordList_GetValue 0x021B99F4 thumb ov114
 *   NHTTP_RAP_FreePostData 0x021B99B8 thumb ov114
 *   POKETRADE_PROC_IsMonValid 0x021D89EC thumb ov119
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   MAIL_Create 0x02008F08 thumb
 *   func_02008F88 0x02008F88 thumb
 *   func_02019B58 0x02019B58 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_Delete 0x02045808 arm
 *   DWC_RAPCOMMON_CreateSubHeapUnlimited 0x02156E24 thumb ov009
 *   func_0200853C 0x0200853C thumb
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   NHTTP_RAP_AllocPostData 0x021B98A0 thumb ov114
 *   NHTTP_RAP_AppendPostData 0x021B98D8 thumb ov114
 *   NHTTP_RAP_CreatePostRequest 0x021B98F8 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   POKETRADE_PROC_ClearNetAutoExit 0x021D89CC thumb ov119
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 *   POKETRADE_NEGO_CheckCancelTouch 0x021DD24C thumb ov119
 *   POKETRADE_NEGO_CloseCancelMenu 0x021DD294 thumb ov119
 *   POKETRADE_NEGO_DrawOfferStatusLabel 0x021DD90C thumb ov119
 *   func_021DAEF0 0x021DAEF0 thumb ov119
 *   func_021DBBD0 0x021DBBD0 thumb ov119
 *   d_021E76D4 0x021E76D4 data a4
 *   d_021E76EC 0x021E76EC data a4
 *   POKETRADE_PROC_GetBoxIndexForSlot 0x021D8AF4 thumb ov119
 *   POKETRADE_PROC_GetSlotIndexInBox 0x021D8B0C thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_NEGO_FindOfferIndex  0x021DD34C  thumb  ov119
 *   POKETRADE_NEGO_RemoveOffer  0x021DD4F4  thumb  ov119
 *   POKETRADE_2D_CreateMarkerActor  0x021E6718  thumb  ov119
 *   POKETRADE_2D_SetMarkerActorVisible  0x021E6790  thumb  ov119
 *   POKETRADE_2D_DeleteMarkerActor  0x021E67A8  thumb  ov119
 *   POKETRADE_2D_SetMarkerActorAnim 0x021E67C4 thumb ov119
 *   POKETRADE_2D_DeleteMarkerButtonPair  0x021E68B4  thumb  ov119
 *   POKETRADE_2D_CreateMarkerButtonActor 0x021E67E0 thumb ov119
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   POKETRADE_2D_ReleaseMarkerResources  0x021E5868  thumb  ov119
 *   POKETRADE_2D_RegisterMarkerResources  0x021E57FC  thumb  ov119
 *   POKETRADE_2D_SetOfferIconsVisible 0x021E6308 thumb ov119
 *   POKETRADE_2D_LoadMonPalette 0x021E6F0C thumb ov119
 *   func_02041300 0x02041300 arm
 *   g_021E7844      0x021E7844  data  ov119
 *   d_021E7794 0x021E7794 data a4
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   func_021DACE4 0x021DACE4 thumb ov119
 *   POKETRADE_NEGO_HasOffer 0x021DD2F4 thumb ov119
 *   POKETRADE_PROC_LoadSlotMon 0x021D8D4C thumb ov119
 *   POKETRADE_PROC_GetSideValue 0x021D8F20 thumb ov119
 *   POKETRADE_PROC_SetSideValue 0x021D8F60 thumb ov119
 *   POKETRADE_PROC_SetSideMon 0x021D9468 thumb ov119
 *   func_021D94D4 0x021D94D4 thumb ov119
 *   POKETRADE_PROC_IsHostSideAlt 0x021D95D0 thumb ov119
 *   POKETRADE_PROC_IsGuestSide 0x021D95F0 thumb ov119
 *   func_021D9610 0x021D9610 thumb ov119
 *   func_021DA76C 0x021DA76C thumb ov119
 *   func_021DC720 0x021DC720 thumb ov119
 *   func_021DD080 0x021DD080 thumb ov119
 *   POKETRADE_SAVE_DrawOfferListWindows 0x021E24E8 thumb ov119
 *   POKETRADE_SAVE_SetupWindowRegsSummary 0x021E26AC thumb ov119
 *   POKETRADE_SAVE_DrawPartnerOfferCard 0x021E272C thumb ov119
 */
#include "pokemontrade_types.h"
#include "../../matched/include/Obj22746.h"
#include "../../matched/include/Obj22747.h"

typedef unsigned int   u32_021DD528;

typedef unsigned int   u32_021DD588;

typedef unsigned int u32_021DD68C;

typedef signed short s16_021DBB6C;

typedef struct {
    int a;
    int b;
} Pair_021DD68C;

typedef struct { int a,b; } Pair_021DD90C;

typedef struct { int a,b; } Pair_021DDAD4;

typedef struct { int a,b; } Pair_021DC2B0;

typedef struct { int a,b,c; } Triple_021DBB6C;

typedef struct {
    int a;
    int b;
} Pair_021DE3E8;

extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);

extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);

extern unsigned int func_020173EC(void);

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

extern void MI_CpuFill8(void *,int,int);

extern u32 POKEPARTY_GetCount(void *m);

extern void MI_CpuCopy8(const void *,void *,unsigned);

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

extern unsigned int GFL_NET_GetHandleNetID(struct Link *p);

extern u32_021DEF1C func_02017E1C(void *,u32_021DEF1C,u32_021DEF1C);

extern void POKETRADE_2D_CreateOfferIconActor(char *p, int i, int j, void *mon, int selected, u32 visible);

void POKETRADE_NEGO_ShowOfferSlotMon(void *p,int i,void *v);

extern u32_021DEC4C WIPE_SYS_EndCheck(void);

extern void WIPE_SYS_Start(void *p1, u32_021DECA0 p2, u32_021DECA0 p3, u32_021DECA0 p4, u32_021DECA0 p5, u32_021DECA0 p6, u32_021DECA0 p7);

int POKETRADE_SAVE_IsMessagePrintDone(char *p);

extern int GFL_NET_SendToHandle(struct Entry *a, u32_021DEDBC b, u32_021DEDBC c, u32_021DEDBC d);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);

extern void func_02045CAC(struct MsgBank *,unsigned,void *);

void POKETRADE_SAVE_OpenMessageWindowTop(void *p);

void POKETRADE_SAVE_ShowTimeIcon(char *p);

extern u8 func_020355C4(void);

extern void POKETRADE_SAVE_ShowSummaryMon(char *p, void *mon, int side, int flag);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void POKETRADE_SAVE_CloseSummaryPage(void *,int);

extern void POKETRADE_2D_LoadBackgroundGfx(char *p);

extern void POKETRADE_3D_AddUnitAndInit(void *,int);

extern void func_02041B6C(u32_021DF918 bit);

extern int TOUCHPANEL_HitTrg(const void *);

extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);

extern u32_021DEA24 KEY_GetTrg(void);

extern void func_020355D8(u8);

extern void GFL_USE_PlaySeDefaultVolume(u32_021DEA24 a);

extern void TOUCHBAR_Update(void *p);

extern void POKETRADE_SAVE_OpenSummaryScreen(char *p, void *a);

extern unsigned int APP_TASKMENU_IsFinish(struct TaskMenu *m);

extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);

void POKETRADE_SAVE_CloseTaskMenu(char *p);

void POKETRADE_SAVE_CloseMessageWindowClear(char *p);

extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);

extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

extern void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count);

extern void BG_SYS_SetMainVisiblePlanes(u32 planes);

extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);

extern int TOUCHPANEL_GetTrg(void);

extern u32_021DEF1C func_020307B0(void *p);

extern int TOUCHPANEL_GetCont(void);

extern void BG_SYS_SetSubVisiblePlanes(u32_021DF168 planes);

extern void DWC_RAP_SetVchatTalkLock(int);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

void POKETRADE_SAVE_OpenTaskMenuAt(char *p,int *ids,int count,int x,int y);

extern u32_021DB7AC GFL_NET_IsNetTypeWifi(void);

extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *);

extern void POKETRADE_2D_SetupSubBgs(char *p);

extern void func_02049B40(int,int,int,int,int,int);

extern void POKETRADE_2D_RegisterIconSpriteResources(void *);

extern void POKETRADE_2D_CreateBoxIconActors(void *);

extern void POKETRADE_2D_LoadMainGfxAndMessageWindow(void *);

extern void *func_02030734(unsigned,unsigned,int,const char *,u16);

extern unsigned int func_0201293C(const void *);

extern void *func_02012934(void *p);

extern void POKETRADE_2D_DeleteAllOfferIconActors(void *);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void POKETRADE_SAVE_CreateMessageResources(char *p);

extern void POKETRADE_2D_CreateFontResource(char *p);

extern void POKETRADE_3D_CreateTouchbar(char *p);

extern void GF_FONT_SetTextColor(u32_021DCD38,u32_021DCD38,u32_021DCD38);

extern void DWC_RAPCOMMON_DestroySubHeap(void);

extern void POKETRADE_2D_MovePickedIconActor(int,int);

extern void *POKETRADE_SAVE_OpenTaskMenuWindow(char *p, int a);

extern int POKETRADE_SAVE_IsTouchOutsideArea(void *);

extern void POKETRADE_SAVE_CloseTaskMenuWindow(char *p, int a, int b);

extern int func_02007984(void *save);

extern void *func_020490F4(unsigned int id, unsigned int heap);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32_021DD528 a1, u32_021DD528 a2, u32_021DD528 a3, u16 a4);

extern s32_021D8EC8 CLACT_RegisterCellAnim(void *owner, u32_021DD528 first, u32_021DD528 second, u32_021DD528 mode);

extern int func_0201BC3C(void);

extern int func_0201BC78(void);

extern int func_0201BCB4(void);

extern void ARC_TOOL_DeleteHandle(void *);

extern void CLACT_ReleasePalette(u32_021DD588 i);

extern void CLACT_ReleaseCellAnim(u32_021DD588 i);

int POKETRADE_NEGO_SendOfferMon(char *p,void *src,int kind);

extern u32_021DD68C func_020275E4(void);

extern u32_021DD68C BMP_WIN_Delete(struct Descriptor *d);

extern u32_021DD68C BMP_WIN_Create(u32_021DD68C layer, u32_021DD68C a, u32_021DD68C b, u32_021DD68C tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void PRINTSYS_Print(void *, s16_021DBB6C, s16_021DBB6C, void *, void *);

extern void func_0201F02C(struct WordSet *p, u32_021DD68C i, void *a);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);

void POKETRADE_NEGO_SetupWindowRegsOffers(void *p);

void POKETRADE_NEGO_StepBrowseOffersMain(char *p);

extern void POKETRADE_2D_UpdateOfferIconHighlight(int p, int a, int b);

extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

extern void POKETRADE_2D_SetDisplayConfig(int);

extern int POKETRADE_PROC_ResetTouchbarBackButton(char *p);

extern void POKETRADE_PROC_ClearNetAutoExit(char *p);

extern int POKETRADE_PROC_IsMonValid(const u8 *p);

extern int POKETRADE_PROC_IsNetSession(void *);

extern int POKETRADE_PROC_IsHostSide(void *);

void *POKETRADE_PROC_LoadSlotMon(void **a, int b, int c, char *p);

extern void POKETRADE_PROC_SetStep(void *,int);

int POKETRADE_PROC_GetSideValue(void *p,int idx);

void POKETRADE_PROC_SetSideValue(void *p,int idx,int x);

void *POKETRADE_PROC_GetSideMon(void *p, int idx);

extern void POKETRADE_PROC_StepBeginWipeOut(void *);

void POKETRADE_PROC_SetSideMon(void *p, int a, void *b);

int func_021D94D4(char *p);

int POKETRADE_PROC_IsHostSideAlt(void *p);

u32 POKETRADE_PROC_IsGuestSide(void *p);

int func_021D9610(unsigned char *p);

void func_021DA76C(void *p);

void func_021DACE4(char *p);

void func_021DC720(char *p);

void func_021DD080(void *a, void *b, void *c);

extern void func_021DD09C(char *p);

extern int func_021DD140(char *p);

void POKETRADE_NEGO_FreeOfferMons(char *p);

void POKETRADE_NEGO_ClearOfferSlots(char *p);

int POKETRADE_NEGO_CountOwnOffers(char *p);

extern int POKETRADE_NEGO_CheckCancelTouch(char *p);

extern void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);

int POKETRADE_NEGO_CanConfirmOffers(char *p);

int POKETRADE_NEGO_HasOffer(char *p);

extern int POKETRADE_NEGO_FindOfferIndex(char *p, int a, int b);

void POKETRADE_NEGO_StoreRemoteOffer(char *p,int i,void *src);

int POKETRADE_NEGO_FindFreeOfferIndex(const char *p, int n, int a, int b);

int POKETRADE_NEGO_AddOffer(TradeWork *p,int side,int a,int b,void *value);

extern void POKETRADE_NEGO_RemoveOffer(TradeWork *p, int i, int j);

extern void POKETRADE_NEGO_RegisterIconResources(char *,int);

extern void POKETRADE_NEGO_ReleaseIconResources(char *p);

int POKETRADE_NEGO_AddSelectedAsOffer(char *p,int a,int b);

void POKETRADE_NEGO_DrawPlayerNames(char *p);

extern void POKETRADE_NEGO_DrawOfferStatusLabel(u8 *p, int i, int msg, int force);

extern void POKETRADE_NEGO_DeleteHeaderWindows(unsigned char *);

void POKETRADE_NEGO_StepQuitMenuChoice(void *p);

void POKETRADE_NEGO_StepOpenQuitMenu(char *p);

void POKETRADE_NEGO_StepWaitSync25(unsigned char *p);

void POKETRADE_NEGO_StepSendSync25(unsigned char *p);

void POKETRADE_NEGO_StepWaitReplyKey(unsigned char *p);

void POKETRADE_NEGO_StepResolveReplies(char *p);

void POKETRADE_NEGO_StepSendReply(unsigned char *p);

void POKETRADE_NEGO_StepWaitReplySync(unsigned char *p);

void POKETRADE_NEGO_StepSendCancelReply(unsigned char *p);

void POKETRADE_NEGO_StepWaitCancelSync(unsigned char *p);

void POKETRADE_NEGO_StepShowWaitMessageA(unsigned char *p);

void POKETRADE_NEGO_StepShowWaitMessageB(unsigned char *p);

void POKETRADE_NEGO_StepConfirmMenuChoice(unsigned char *p);

void POKETRADE_NEGO_StepOpenConfirmMenu(char *p);

void POKETRADE_NEGO_StepResolveConfirm(char *p);

void POKETRADE_NEGO_StepSendConfirm(void *p);

void POKETRADE_NEGO_StepBeginConfirm(char *p);

void POKETRADE_NEGO_ShowOfferSummary(TradeWork *p,int index);

extern int POKETRADE_NEGO_PollOfferCursorKeys(char *);

void POKETRADE_NEGO_StepReturnFromSummary(char *p);

void POKETRADE_NEGO_StepWaitSelectionDelay(char *p);

void POKETRADE_NEGO_StepBrowseOffers(char *p);

void POKETRADE_NEGO_StepOpenSummaryFromBrowse(TradeWork *p);

void POKETRADE_NEGO_StepOfferActionChoice(char *p);

void POKETRADE_NEGO_StepOpenOfferActionMenu(char *p);

void POKETRADE_NEGO_StepSendOfferMon(char *p);

void POKETRADE_NEGO_StepSendOfferIndex(void *p);

extern int POKETRADE_NEGO_TrySelectOffer(char *,int);

void POKETRADE_NEGO_StepRebuildSceneAfterWipe(char *p);

extern void POKETRADE_NEGO_StepWaitMessageThenWipe(char *p);

void POKETRADE_NEGO_StepSendDeclineConfirm(void *p);

void POKETRADE_NEGO_StepBeginDeclineConfirm(char *p);

void POKETRADE_NEGO_StepDeclineMenuChoice(char *p);

extern void POKETRADE_NEGO_StepOpenDeclineMenu(void *);

extern const char d_021E80E0[];

extern const Pair_021DD68C d_021E7704;

extern const Pair_021DD90C d_021E76FC;

extern const Pair_021DDAD4 d_021E76F4;

extern const Pair_021DC2B0 d_021E76E4;

extern const char d_021E80C4[];

extern const Triple_021DBB6C d_021E770C;

extern const Pair_021DE3E8 d_021E76DC;

void POKETRADE_NEGO_FreeOfferMons(char *p)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            char *q = p + i * 12 + j * 4;
            if (((TradeWork *)q)->offerMon[0][0]) {
                func_020307B0(((TradeWork *)q)->offerMon[0][0]);
                ((TradeWork *)q)->offerMon[0][0] = 0;
            }
        }
    }
}

void POKETRADE_NEGO_ClearOfferSlots(char *p)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            char *q = p + i * 12 + j * 4;
            ((TradeWork *)q)->offerSlot[0][0] = -1;
            ((TradeWork *)q)->offerBox[0][0] = -1;
            if (((TradeWork *)q)->offerMon[0][0]) MI_CpuFill8(((TradeWork *)q)->offerMon[0][0], 0, func_020173EC());
        }
    }
}

int POKETRADE_NEGO_CountOwnOffers(char *p)
{
    int i, n = 0;
    for (i = 0; i < 3; i++) {
        if (((TradeWork *)p)->offerSlot[0][i] != -1 && ((TradeWork *)p)->offerBox[0][i] != -1)
            n++;
    }
    return n;
}

int POKETRADE_NEGO_CheckCancelTouch(char *p)
{
    if (((TradeWork *)p)->f118C == 3) {
        if (*(int *)&((TradeWork *)p)->taskMenuWindow == 0) POKETRADE_SAVE_OpenTaskMenuWindow(p, 0x9a);
        if (POKETRADE_SAVE_IsTouchOutsideArea(p)) {
            POKETRADE_PROC_ClearNetAutoExit(p);
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBeginWipeOut);
            return 1;
        }
    }
    return 0;
}

void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b)
{
    if (((TradeWork *)p)->f118C == 3)
        POKETRADE_SAVE_CloseTaskMenuWindow(p, a, b);
}

int POKETRADE_NEGO_CanConfirmOffers(char *p)
{
    int a, b, n;
    a = func_0201293C((const struct BigObj *)(*(int *)&((TradeWork *)p)->f82C));
    b = POKETRADE_NEGO_CountOwnOffers(p);
    n = POKEPARTY_GetCount(func_02012934(((TradeWork *)p)->f82C));
    n += func_02007984((void *)a);
    if (n == 2 && b >= 1) return 1;
    if (n > 2 && b >= 2) return 1;
    return 0;
}

int POKETRADE_NEGO_HasOffer(char *p)
{
    int i;
    if (POKETRADE_PROC_IsHostSide(p)) {
        for (i = 0; i < 3; i++) {
            if (((TradeWork *)p)->offerSlot[0][i] != -1 && ((TradeWork *)p)->offerBox[0][i] != -1) return 1;
        }
    } else {
        if (((TradeWork *)p)->selectedSlot != -1 && ((TradeWork *)p)->selectedBox != -1) return 1;
    }
    return 0;
}

int POKETRADE_NEGO_FindOfferIndex(char *p, int a, int b)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (b == ((TradeWork *)p)->offerSlot[0][i] && a == ((TradeWork *)p)->offerBox[0][i])
            return i;
    }
    return -1;
}

void POKETRADE_NEGO_StoreRemoteOffer(char *p,int i,void *src)
{
    *(int *)(p+0xfb0+i*4)=i; *(int *)(p+0xfc8+i*4)=i; if(*(void **)(p+0xfe4+i*4)==0) *(void **)(p+0xfe4+i*4)=func_02030734(((TradeWork *)p)->heapId,func_020173EC(),1,(void *)d_021E80E0,0x122);MI_CpuCopy8(src,*(void **)(p+0xfe4+i*4),func_020173EC());
}

/*
 * lever: Spell the indexed object base at each field read; a cached q local
 * swaps the first-loop counter and pooled-offset registers (10 bytes).
 */
int POKETRADE_NEGO_FindFreeOfferIndex(const char *p, int n, int a, int b)
{
    int j;
    long i;
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + n * 12 + 0xfa4 + i * 4) == a &&
            *(int *)(p + n * 12 + 0xfbc + i * 4) == b)
            return -1;
    }
    for (j = 0; j < 3; j++) {
        if (*(int *)(p + n * 12 + 0xfa4 + j * 4) == -1)
            return j;
    }
    return 2;
}

/*
 * lever: Separate two-by-three struct fields recompute the side offset;
 * raw combined offsets cached it in ip and produced 208 rather than 204 bytes.
 */
int POKETRADE_NEGO_AddOffer(TradeWork *p,int side,int a,int b,void *value)
{
    int i;
    for(i=0;i<3;i++) {
        if(a==p->offerSlot[side][i] && b==p->offerBox[side][i])
            return -1;
    }
    for(i=0;i<3;i++) {
        if(p->offerSlot[side][i]==-1 || i==2) {
            p->offerSlot[side][i]=a;
            p->offerBox[side][i]=b;
            if(p->offerMon[side][i]==0)
                p->offerMon[side][i]=func_02030734(((TradeWork *)p)->heapId,func_020173EC(),1,d_021E80E0,0x14c);
            MI_CpuCopy8(value,p->offerMon[side][i],func_020173EC());
            POKETRADE_NEGO_ShowOfferSlotMon(p,side,value);
            return i;
        }
    }
    return -1;
}

void POKETRADE_NEGO_RemoveOffer(TradeWork *p, int i, int j)
{
    p->offerSlot[i][j] = -1;
    p->offerBox[i][j] = -1;
    if (p->offerMon[i][j])
        func_020307B0((void *)p->offerMon[i][j]);
    p->offerMon[i][j] = 0;
}

void POKETRADE_NEGO_RegisterIconResources(char *p,int n)
{
    void *v;int off;int a;v=func_020490F4(7,((TradeWork *)p)->heapId);off=96;if(n!=1)off=0;(*(int *)&((TradeWork *)p)->f890)=CLACT_RegisterPaletteCompressed(v,func_0201BC3C(),n,(u16)off,((TradeWork *)p)->heapId);a=func_0201BC78();(*(int *)&((TradeWork *)p)->f8C0)=CLACT_RegisterCellAnim(v,a,func_0201BCB4(),((TradeWork *)p)->heapId);ARC_TOOL_DeleteHandle(v);
}

void POKETRADE_NEGO_ReleaseIconResources(char *p)
{
    if (((TradeWork *)p)->f890 != 0) {
        CLACT_ReleasePalette((u32_021DD588)(((TradeWork *)p)->f890));
        ((TradeWork *)p)->f890 = 0;
    }
    if (((TradeWork *)p)->f8C0 != 0) {
        CLACT_ReleaseCellAnim((u32_021DD588)(((TradeWork *)p)->f8C0));
        ((TradeWork *)p)->f8C0 = 0;
    }
}

int POKETRADE_NEGO_AddSelectedAsOffer(char *p,int a,int b)
{
    int value,slot;
    unsigned i;
    GFL_NET_HANDLE_GetCurrentHandle();
    value=(int)POKETRADE_PROC_LoadSlotMon(*(void ** *)&((TradeWork *)p)->gameData,((TradeWork *)p)->selectedBox,((TradeWork *)p)->selectedSlot,p);
    if(POKETRADE_PROC_IsNetSession(p)) {
        i=0;
        slot=POKETRADE_NEGO_AddOffer((TradeWork *)p,0,a,b,(void *)value);
        if(slot!=-1) {
            if(POKETRADE_NEGO_SendOfferMon(p,((TradeWork *)p)->offerMon[0][slot],slot+0xc07)==0) {
                POKETRADE_NEGO_RemoveOffer((TradeWork *)p,0,slot);
                func_020307B0((void *)value);
                return 0;
            }
            for(i=0;i<(unsigned)func_020173EC();i++) {}
        }
    } else {
        slot=POKETRADE_NEGO_AddOffer((TradeWork *)p,0,a,b,(void *)value);
    }
    if(slot==-1) {func_020307B0((void *)value);return 1;}
    POKETRADE_2D_CreateOfferIconActor(p,0,slot,(void *)value,1,0);
    func_020307B0((void *)value);
    return 1;
}

void POKETRADE_NEGO_DrawPlayerNames(char *p)
{
    Pair_021DD68C t;
    Pair_021DD68C u;
    void *h;
    int q;
    void *h2;
    int i;
    int k;
    int m;
    int x;

    t = d_021E7704;
    u.a = ((TradeWork *)p)->f830;
    u.b = ((TradeWork *)p)->f834;
    func_02049B40(func_020275E4(), 0x1F, 0, 0x1A0, 0x20, ((TradeWork *)p)->heapId);
    if ((*(void * *)&((TradeWork *)p)->f5D4) != 0) {
        BMP_WIN_Delete((*(void * *)&((TradeWork *)p)->f5D4));
        BMP_WIN_Delete((*(void * *)&((TradeWork *)p)->f5D8));
    }
    h = (void *)BMP_WIN_Create(3, 0, 0, 0x20, 2, 13, 0);
    (*(void * *)&((TradeWork *)p)->f5D4) = h;
    GF_FONT_SetTextColor(14, 15, 0);
    if (((TradeWork *)p)->f118C == 3 && ((TradeWork *)p)->f1050 != -1) {
        func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), 0x85, (*(void * *)&((TradeWork *)p)->f730));
        PRINTSYS_Print(BMP_WIN_GetBmp(h), 8, 2, (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
        func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), ((TradeWork *)p)->f1050 + 0x7B, (*(void * *)&((TradeWork *)p)->f730));
        PRINTSYS_Print(BMP_WIN_GetBmp(h), 0x88, 2, (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
    }
    BMP_WIN_TransferChars(h);
    BMP_WIN_MakeScreen(h);
    i = 0;
    h2 = (void *)BMP_WIN_Create(3, 0, 3, 0x20, 8, 5, 0);
    (*(void * *)&((TradeWork *)p)->f5D8) = h2;
    for (i = 0; i < 2; i++) {
        k = i * 4;
        q = *(int *)((char *)&u + k);
        if (q != 0) {
            if (((TradeWork *)p)->f118C == 3 && *(int *)(p + k + 0x1048) != -1) {
                m = 0x75;
            } else {
                m = 0x80;
            }
            GF_FONT_SetTextColor(1, 2, 0);
            func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), m, (*(void * *)&((TradeWork *)p)->f734));
            func_0201F02C((*(void * *)&((TradeWork *)p)->f724), 0, (void *)q);
            func_0201F250((*(void * *)&((TradeWork *)p)->f724), (*(void * *)&((TradeWork *)p)->f730), (*(void * *)&((TradeWork *)p)->f734));
            x = *(int *)((char *)&t + k) * 8;
            PRINTSYS_Print(BMP_WIN_GetBmp(h2), x, 2, (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
            if (((TradeWork *)p)->f118C == 3 && *(int *)(p + k + 0x1048) != -1) {
                GF_FONT_SetTextColor(3, 4, 0);
                func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), *(int *)(p + k + 0x1048) + 0x76, (*(void * *)&((TradeWork *)p)->f730));
                PRINTSYS_Print(BMP_WIN_GetBmp(h2), x + 4, 0x22, (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
            }
        }
    }
    BMP_WIN_TransferChars(h2);
    BMP_WIN_MakeScreen(h2);
    func_02041B6C(3);
}

/*
 * 2026-10-02 lane R1: closed by storing the call result straight into items[i] and reading it back
 * (w=items[i]): the pointer local stays live across the call and the forwarded value is spilled.
 */
void POKETRADE_NEGO_DrawOfferStatusLabel(u8 *p,int i,int msg,int force)
{
    Pair_021DD90C t=d_021E76FC;
    int w;
    int *items;
    if(force==0) {
        if((p+i)[0x11e8]==3) return;
        if(p[0x11ea]==0) return;
        if(POKETRADE_PROC_IsHostSide(p)==0) return;
    }
    if(*(int *)(p+i*4+0x5bc)) BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+i*4+0x5bc)));
    items=(int *)(p+0x5bc); items[i]=(int)BMP_WIN_Create(3,(u8)(((int *)&t)[i]),16,12,2,5,0); w=items[i];
    GF_FONT_SetTextColor(5,6,0);
    msg+=0x72;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),msg,(void *)(((TradeWork *)p)->f730));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)w),0,0,(void *)(((TradeWork *)p)->f730),(void *)(*(int *)&((TradeWork *)p)->f728));
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_02041B6C(3);
    (p+i)[0x11e8]=3;
}

void POKETRADE_NEGO_DeleteHeaderWindows(unsigned char *p)
{
    if(((TradeWork *)p)->f5BC){BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f5BC));BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f5BC));((TradeWork *)p)->f5BC=0;}if(((TradeWork *)p)->f5C0){BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f5C0));BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f5C0));((TradeWork *)p)->f5C0=0;}if(((TradeWork *)p)->f5D4){BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f5D4));BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f5D4));((TradeWork *)p)->f5D4=0;}if(((TradeWork *)p)->f5D8){BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->f5D8));BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->f5D8));((TradeWork *)p)->f5D8=0;}func_02041B6C(3);
}

void POKETRADE_NEGO_StepQuitMenuChoice(void *p)
{
    int v;

    if (APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->taskMenu)) == 0)
        return;
    v = APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->taskMenu));
    POKETRADE_SAVE_CloseTaskMenu(p);
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    ((TradeWork *)p)->taskMenu = 0;
    switch (v) {
    case 0:
        WIPE_SYS_Start((void *)3, 0, 0, 0, 6, 1, ((TradeWork *)p)->heapId);
        POKETRADE_PROC_SetStep(p, 0x021DE519);
        return;
    case 1:
        POKETRADE_PROC_ResetTouchbarBackButton(p);
        POKETRADE_NEGO_SetupWindowRegsOffers(p);
        func_021DD09C(p);
        POKETRADE_PROC_SetStep(p, 0x021DEA25);
        return;
    }
}

void POKETRADE_NEGO_StepOpenQuitMenu(char *p)
{
    Pair_021DDAD4 t=d_021E76F4;
    POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),2);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),1,0);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepQuitMenuChoice);
}

void POKETRADE_NEGO_StepWaitSync25(unsigned char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle(); if(POKETRADE_PROC_IsNetSession(p)) { if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),25,8)==0) {POKETRADE_NEGO_CheckCancelTouch((char *)p);return;} } POKETRADE_SAVE_CloseMessageWindowClear((char *)p);POKETRADE_NEGO_CloseCancelMenu((char *)p,0,0);POKETRADE_PROC_ResetTouchbarBackButton((char *)p);func_021DD09C((char *)p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffersMain);
}

void POKETRADE_NEGO_StepSendSync25(unsigned char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if(POKETRADE_SAVE_IsMessagePrintDone((char *)p)) {
        func_021DD080((void *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),(void *)25,p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitSync25);
    }
}

void POKETRADE_NEGO_StepWaitReplyKey(unsigned char *p)
{
    int v;GFL_NET_HANDLE_GetCurrentHandle();if(POKETRADE_SAVE_IsMessagePrintDone((char *)p)){v=KEY_GetTrg();if(v)func_020355D8(0);if(v==0){v=TOUCHPANEL_GetTrg();if(v)func_020355D8(1);if(v==0)return;}func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),0x88,(void *)(((TradeWork *)p)->f738));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon((char *)p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendSync25);}
}

void POKETRADE_NEGO_StepResolveReplies(char *p)
{
    int a, b, c, d, m;
    a = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    b = 1 - a;
    if (POKETRADE_SAVE_IsMessagePrintDone(p) == 0) return;
    if (func_021DD140(p) == 0) return;
    if (POKETRADE_PROC_IsNetSession(p) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1D, 8) == 0) {
        POKETRADE_NEGO_CheckCancelTouch(p);
        return;
    }
    POKETRADE_NEGO_CloseCancelMenu(p, 0, 0);
    c = (unsigned char)(p + a)[0x11E0];
    if (c == 13 && (unsigned char)(p + b)[0x11E0] == 13) {
        func_021DD080((void *)((u32)GFL_NET_HANDLE_GetCurrentHandle()), (void *)13, p);
        POKETRADE_PROC_SetStep(p, (int)func_021DA76C);
        return;
    }
    d = (unsigned char)(p + b)[0x11E0];
    if (d == 5) m = 0x61;
    else if (c == 5) m = 0x62;
    else if (d == 7) m = 0x63;
    else if (c == 7) m = 0x64;
    else if (d == 8) m = 0x64;
    else if (c == 8) m = 0x63;
    else if (d == 6) m = 0x61;
    else if (c == 6) m = 0x6F;
    else if (d == 14) m = 0x97;
    else if (c == 14) m = 0x96;
    func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), m, (*(void * *)&((TradeWork *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    p[0x11E0] = 0;
    p[0x11E1] = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepWaitReplyKey);
}

void POKETRADE_NEGO_StepSendReply(unsigned char *p)
{
    unsigned char b=13;if(func_021D94D4((char *)p))b=5;else if(POKETRADE_PROC_IsHostSideAlt(p))b=7;else if(POKETRADE_PROC_IsGuestSide(p))b=8;else if(func_021D9610(p))b=6;if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,(u32_021DEDBC)&b)){func_021DD080(GFL_NET_HANDLE_GetCurrentHandle(),(void *)29,p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveReplies);}
}

void POKETRADE_NEGO_StepWaitReplySync(unsigned char *p)
{
    if(POKETRADE_PROC_IsNetSession(p)==0){p[0x11e0]=13;p[0x11e1]=13;POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveReplies);return;} if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),30,8)==0){POKETRADE_NEGO_CheckCancelTouch((char *)p);return;}POKETRADE_NEGO_CloseCancelMenu((char *)p,0,0);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendReply);
}

void POKETRADE_NEGO_StepSendCancelReply(unsigned char *p)
{
    unsigned char v=14;
    if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,(u32_021DEDBC)&v)) {
        func_021DD080(GFL_NET_HANDLE_GetCurrentHandle(),(void *)29,p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveReplies);
    }
}

void POKETRADE_NEGO_StepWaitCancelSync(unsigned char *p)
{
    if(POKETRADE_PROC_IsNetSession(p)==0){p[0x11e0]=14;p[0x11e1]=14;POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveReplies);return;} if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),30,8)==0){POKETRADE_NEGO_CheckCancelTouch((char *)p);return;}POKETRADE_NEGO_CloseCancelMenu((char *)p,0,0);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendCancelReply);
}

void POKETRADE_NEGO_StepShowWaitMessageA(unsigned char *p)
{
    func_021DD080((void *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),(void *)30,p); func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),0x88,(void *)(((TradeWork *)p)->f738)); POKETRADE_SAVE_OpenMessageWindowTop(p); POKETRADE_SAVE_ShowTimeIcon((char *)p); p[0x11f1]=120; POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitReplySync);
}

void POKETRADE_NEGO_StepShowWaitMessageB(unsigned char *p)
{
    func_021DD080((void *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),(void *)30,p); func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),0x88,(void *)(((TradeWork *)p)->f738)); POKETRADE_SAVE_OpenMessageWindowTop(p); POKETRADE_SAVE_ShowTimeIcon((char *)p); p[0x11f1]=120; POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitCancelSync);
}

void POKETRADE_NEGO_StepConfirmMenuChoice(unsigned char *p)
{
    int v; if(APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->taskMenu))==0)return;v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->taskMenu));POKETRADE_SAVE_CloseTaskMenu((char *)p);POKETRADE_SAVE_CloseMessageWindowClear((char *)p);((TradeWork *)p)->taskMenu=0;switch(v){case 0:POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepShowWaitMessageA);return;case 1:POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepShowWaitMessageB);return;}
}

void POKETRADE_NEGO_StepOpenConfirmMenu(char *p)
{
    if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
        Pair_021DC2B0 t=d_021E76E4;
        POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),2);
        BG_SYS_SetMainVisiblePlanes(31);
        TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),1,0);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepConfirmMenuChoice);
    }
}

void POKETRADE_NEGO_StepResolveConfirm(char *p)
{
    int a, b, c, i, m;
    a = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    b = 1 - a;
    if (POKETRADE_SAVE_IsMessagePrintDone(p) == 0) return;
    if (func_021DD140(p) == 0) return;
    if (POKETRADE_PROC_IsNetSession(p) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1C, 8) == 0) {
        POKETRADE_NEGO_CheckCancelTouch(p);
        return;
    }
    i = 0;
    POKETRADE_NEGO_CloseCancelMenu(p, 0, 0);
    c = (unsigned char)(p + a)[0x11E0];
    if (c == 11 && (unsigned char)(p + b)[0x11E0] == 11) {
        func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), 0x92, ((TradeWork *)p)->f73C);
        do {
            func_0201EEF4((*(void * *)&((TradeWork *)p)->f724), i, POKETRADE_PROC_GetSideMon(p, i));
            i++;
        } while (i < 2);
        func_0201F250((*(void * *)&((TradeWork *)p)->f724), (*(void * *)&((TradeWork *)p)->f738), ((TradeWork *)p)->f73C);
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepOpenConfirmMenu);
        return;
    }
    if ((unsigned char)(p + b)[0x11E0] == 12) {
        (p + 0x11E0)[0x11] = 0x78;
        m = 0x93;
        if (((TradeWork *)p)->f118C == 3 && (u8)p[0x11FA] >= 3) {
            POKETRADE_PROC_ClearNetAutoExit(p);
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBeginWipeOut);
            return;
        }
    } else if (c == 12) {
        (p + 0x11E0)[0x11] = 0x78;
        m = 0x95;
        if (((TradeWork *)p)->f118C == 3 && (u8)p[0x11FA] >= 3) {
            POKETRADE_PROC_ClearNetAutoExit(p);
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBeginWipeOut);
            return;
        }
    }
    func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), m, (*(void * *)&((TradeWork *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    p[0x11E0] = 0;
    p[0x11E1] = 0;
    if (POKETRADE_PROC_IsNetSession(p) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x19, 8);
    }
    ((TradeWork *)p)->fF2C = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepWaitMessageThenWipe);
}

void POKETRADE_NEGO_StepSendConfirm(void *p)
{
    u8 cmd;
    cmd = 0xB;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xC00, 1, (u32_021DEDBC)&cmd) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1C, 8);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepResolveConfirm);
    }
}

void POKETRADE_NEGO_StepBeginConfirm(char *p)
{
    void *obj;
    int n;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),0x88,(void *)(((TradeWork *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    p[0x11f1]=120;
    if(POKETRADE_PROC_IsNetSession(p)==0) {
        p[0x11e0]=11;
        p[0x11e1]=11;
        obj=((TradeWork *)p)->offerMon[0][0];
        POKETRADE_PROC_SetSideMon(p,1,obj);
        n=func_020173EC();
        MI_CpuCopy8(obj,POKETRADE_PROC_GetSideMon(p,1),n);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveConfirm);
        return;
    }
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendConfirm);
}

void POKETRADE_NEGO_ShowOfferSummary(TradeWork *p,int index)
{
    int col=index%3;
    int row=index/3;
    int other=1-row;
    void *obj=p->offerMon[other][col];
    if(POKETRADE_PROC_IsMonValid(obj)) {
        POKETRADE_SAVE_ShowSummaryMon((char *)p,obj,other,1);
        POKETRADE_2D_UpdateOfferIconHighlight((int)p,row,col);
    }
}

static inline int poll(void) { int v=KEY_GetTrg(); if(v)func_020355D8(0); return v; }

int POKETRADE_NEGO_PollOfferCursorKeys(char *p)
{
    int changed=0;
    int v;
    if(poll()==16) { ((TradeWork *)p)->cursorIndex=(((TradeWork *)p)->cursorIndex+3)%6; changed=1; }
    if(poll()==32) {
        ((TradeWork *)p)->cursorIndex=(((TradeWork *)p)->cursorIndex-3)%6;
        if(((TradeWork *)p)->cursorIndex<0) ((TradeWork *)p)->cursorIndex+=6;
        changed=1;
    }
    if(poll()==64) {
        v=((TradeWork *)p)->cursorIndex;
        if(v==0 || v==3) ((TradeWork *)p)->cursorIndex+=3;
        ((TradeWork *)p)->cursorIndex-=1; changed=1;
    }
    if(poll()==128) {
        v=((TradeWork *)p)->cursorIndex;
        if(v==2 || v==5) ((TradeWork *)p)->cursorIndex-=3;
        ((TradeWork *)p)->cursorIndex+=1; changed=1;
    }
    return changed;
}

void POKETRADE_NEGO_StepReturnFromSummary(char *p)
{
    void *resource;
    int zero,slot;
    void *mon;
    if(WIPE_SYS_EndCheck()) {
        zero=0;
        func_02040588(3,zero);
        POKETRADE_2D_UpdateOfferIconHighlight((int)p,-1,-1);
        POKETRADE_SAVE_CloseSummaryPage(p,0);
        resource=func_020490F4(102,((TradeWork *)p)->heapId);
        func_02049990(resource,11,2,0,(u16)((TradeWork *)p)->f86C,zero,zero,((TradeWork *)p)->heapId);
        ARC_TOOL_DeleteHandle(resource);
        POKETRADE_3D_AddUnitAndInit(p,0);
        func_02041B6C(3);
        p[0x11f3]=zero;
        slot=1;
        if(POKETRADE_PROC_IsMonValid(POKETRADE_PROC_GetSideMon(p,slot))) {
            mon=POKETRADE_PROC_GetSideMon(p,slot);
            POKETRADE_PROC_SetSideMon(p,slot,mon);
        }
        slot=0;
        if(POKETRADE_PROC_IsMonValid(POKETRADE_PROC_GetSideMon(p,slot))) {
            mon=POKETRADE_PROC_GetSideMon(p,slot);
            POKETRADE_PROC_SetSideMon(p,slot,mon);
        }
        POKETRADE_NEGO_SetupWindowRegsOffers(p);
        func_021DD09C(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffersMain);
        POKETRADE_PROC_ResetTouchbarBackButton(p);
        WIPE_SYS_Start((void *)3,1,1,0,6,1,((TradeWork *)p)->heapId);
    }
}

void POKETRADE_NEGO_StepWaitSelectionDelay(char *p)
{
    int lim;
    lim = 3;
    if (GFL_NET_IsNetTypeWifi() != 0) {
        lim = 10;
    }
    if (((TradeWork *)p)->fF2C > lim) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepBrowseOffers);
    }
}

/*
 * prototype: 02035C08 return is consumed in r0; full 02035BBC forwarding body returns int, as in matched 021D98AC.
 */
void POKETRADE_NEGO_StepBrowseOffers(char *p)
{
    int idx;
    func_02040588(3,1);
    if(WIPE_SYS_EndCheck()) {
        TOUCHBAR_Update(*(void * *)&((TradeWork *)p)->touchbar);
        if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((TradeWork *)p)->touchbar)==1) {
            WIPE_SYS_Start((void *)3,0,0,0,6,1,((TradeWork *)p)->heapId);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepReturnFromSummary);
            return;
        }
        if(TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((TradeWork *)p)->touchbar)==-1) {
            idx=TOUCHPANEL_HitTrg(d_021E80C4);
            if(idx!=-1) {
                func_020355D8(1);
                ((TradeWork *)p)->cursorIndex=idx;
                POKETRADE_2D_MovePickedIconActor((int)p,-1);
                POKETRADE_NEGO_ShowOfferSummary((TradeWork *)p,((TradeWork *)p)->cursorIndex);
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((TradeWork *)p)->fF2C=0;
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitSelectionDelay);
                return;
            }
            if(func_020355C4() && poll()) {
                func_020355D8(0);
                POKETRADE_2D_MovePickedIconActor((int)p,((TradeWork *)p)->cursorIndex);
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((TradeWork *)p)->fF2C=0;
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitSelectionDelay);
                return;
            }
            if(POKETRADE_NEGO_PollOfferCursorKeys(p)) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                POKETRADE_2D_MovePickedIconActor((int)p,((TradeWork *)p)->cursorIndex);
                POKETRADE_NEGO_ShowOfferSummary((TradeWork *)p,((TradeWork *)p)->cursorIndex);
                ((TradeWork *)p)->fF2C=0;
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitSelectionDelay);
            }
        }
    }
}

void POKETRADE_NEGO_StepOpenSummaryFromBrowse(TradeWork *p)
{
    char *b=(char *)p;
    u16 idx;
    int col,row;
    void *obj;
    int other;
    if(WIPE_SYS_EndCheck()) {
        idx=(u16)((TradeWork *)b)->cursorIndex;
        col=idx%3; row=idx/3;
        other=1-row;
        obj=p->offerMon[other][col];
        b[0x11f3]=1;
        if(obj && func_02017E1C(obj,169,0)) {
            POKETRADE_SAVE_OpenSummaryScreen((char *)p,obj); POKETRADE_2D_UpdateOfferIconHighlight((int)p,row,col);
        }
        POKETRADE_NEGO_SetupWindowRegsOffers(p);
        WIPE_SYS_Start((void *)3,1,1,0,6,1,((TradeWork *)b)->heapId);
        POKETRADE_PROC_ResetTouchbarBackButton((char *)p); func_021DD09C((char *)p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffers);
    }
}

void POKETRADE_NEGO_StepOfferActionChoice(char *p)
{
    int v;
    if(APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->taskMenu))) {
        v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->taskMenu));
        POKETRADE_SAVE_CloseTaskMenu(p); POKETRADE_SAVE_CloseMessageWindowClear(p);
        ((TradeWork *)p)->taskMenu=0;
        switch(v) {
        case 0: POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBeginConfirm); return;
        case 1:
            WIPE_SYS_Start((void *)3,0,0,0,6,1,((TradeWork *)p)->heapId);
            TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->touchbar),1,0);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOpenSummaryFromBrowse); return;
        case 2:
            POKETRADE_NEGO_SetupWindowRegsOffers(p); POKETRADE_PROC_ResetTouchbarBackButton(p); func_021DD09C(p);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffersMain); return;
        }
    }
}

void POKETRADE_NEGO_StepOpenOfferActionMenu(char *p)
{
    Triple_021DBB6C t=d_021E770C;
    POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),3);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),1,0);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOfferActionChoice);
}

void POKETRADE_NEGO_StepSendOfferMon(char *p)
{
    unsigned id;
    if(((TradeWork *)p)->stateFlags.bits.sendBusy==1) return;
    if(POKETRADE_PROC_IsNetSession(p)!=0) {
        id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
        if(!GFL_NET_SendToHandle((void *)id,(u16)0xc01,(u16)func_020173EC(), (u32_021DEDBC)((void *)(((TradeWork *)p)->f106C)))) return;
    }
    ((TradeWork *)p)->stateFlags.bits.sendBusy=1;
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOpenOfferActionMenu);
}

void POKETRADE_NEGO_StepSendOfferIndex(void *p)
{
    u8 v;
    if (POKETRADE_PROC_IsNetSession(p) != 0) {
        v = POKETRADE_PROC_GetSideValue(p, 0);
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), (u16)0xC16, (u16)func_020173EC(), (u32_021DEDBC)(&v)) == 0) {
            return;
        }
    }
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepSendOfferMon);
}

/*
 * lever: Shared failure label; padded two-dimensional array members reproduce index scheduling.
 */
int POKETRADE_NEGO_TrySelectOffer(char *p,int idx)
{
    int row,col,entry;
    void *mon;
    int value;
    TradeWork *s=(TradeWork *)p;
    row=idx/3;
    col=idx%3;
    if(idx==-1) goto fail;
    entry=s->offerSlot[1-row][col];
    if(entry==-1) goto fail;
    mon=s->offerMon[1-row][col];
    value=s->offerReceivedValue[1-row][col];
    if(mon==0 || func_02017E1C(mon,169,0)==0) goto fail;
    ((TradeWork *)p)->cursorIndex=idx;
    GFL_USE_PlaySeDefaultVolume(0x54c);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),1,0);
    if(row!=0) {
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOpenQuitMenu);
    } else {
        POKETRADE_PROC_SetSideMon(p,row,mon);
        MI_CpuCopy8(mon,((TradeWork *)p)->f106C,func_020173EC());
        POKETRADE_PROC_SetSideValue(p,0,value);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendOfferIndex);
    }
    return 1;
fail:
    return 0;
}

/*
 * volatile: 0x021DE89A reads 0x04001000 before the store at 0x021DE89E.
 */
void POKETRADE_NEGO_StepRebuildSceneAfterWipe(char *p)
{
    if(WIPE_SYS_EndCheck()) {
        func_021DC720(p); POKETRADE_2D_SetDisplayConfig(0); POKETRADE_2D_SetupSubBgs(p);
        (*(void * *)&((TradeWork *)p)->clactSystem)=CLACT_CreateUnit(0x154,0,((TradeWork *)p)->heapId);
        POKETRADE_SAVE_CreateMessageResources(p); POKETRADE_2D_RegisterIconSpriteResources(p); POKETRADE_2D_CreateBoxIconActors(p);
        POKETRADE_2D_LoadBackgroundGfx(p); POKETRADE_2D_CreateFontResource(p); POKETRADE_2D_LoadMainGfxAndMessageWindow(p);
        POKETRADE_3D_AddUnitAndInit(p,0); BG_SYS_SetMainVisiblePlanes(31); BG_SYS_SetSubVisiblePlanes(30);
        POKETRADE_3D_CreateTouchbar(p); GFL_NET_RestartWithDefaultTimeout(0,((TradeWork *)p)->heapId);
        *(volatile unsigned *)0x04001000 &= 0xffff1fff;
        POKETRADE_PROC_SetStep(p,(int)func_021DACE4);
    }
}

void POKETRADE_NEGO_StepWaitMessageThenWipe(char *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if(POKETRADE_SAVE_IsMessagePrintDone(p) && func_021DD140(p) && ((TradeWork *)p)->fF2C>=120) {
        WIPE_SYS_Start(0,0,0,0,6,1,((TradeWork *)p)->heapId);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepRebuildSceneAfterWipe);
    }
}

void POKETRADE_NEGO_StepSendDeclineConfirm(void *p)
{
    u8 cmd;
    cmd = 0xC;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xC00, 1, (u32_021DEDBC)&cmd) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1C, 8);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepResolveConfirm);
    }
}

void POKETRADE_NEGO_StepBeginDeclineConfirm(char *p)
{
    func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), 0x88, (*(void * *)&((TradeWork *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    *(p + 0x11F1) = 0x78;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepSendDeclineConfirm);
}

void POKETRADE_NEGO_StepDeclineMenuChoice(char *p)
{
    int v;
    if(APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->taskMenu))) {
        v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->taskMenu));
        POKETRADE_SAVE_CloseTaskMenu(p);
        POKETRADE_SAVE_CloseMessageWindowClear(p);
        ((TradeWork *)p)->taskMenu=0;
        if(v==0) {
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBeginDeclineConfirm);
            return;
        }
        POKETRADE_SAVE_CloseMessageWindowClear(p);
        POKETRADE_PROC_ResetTouchbarBackButton(p);
        func_021DD09C(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffersMain);
    }
}

void POKETRADE_NEGO_StepOpenDeclineMenu(void *p)
{
    Pair_021DE3E8 t;
    if (POKETRADE_SAVE_IsMessagePrintDone(p) != 0) {
        t = d_021E76DC;
        POKETRADE_SAVE_OpenTaskMenuAt(p, (int *)&t, 2, 0x20, 12);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepDeclineMenuChoice);
    }
}

typedef struct S_021DEA24 S_021DEA24;

typedef unsigned int   u32_021DEEA8;

typedef unsigned int   u32_021DF0B8;

typedef unsigned int   u32_021DF338;

typedef unsigned int   u32_021DF37C;

typedef unsigned int   u32_021DF43C;

typedef struct { int a, b; } Pair_021DF490;

typedef struct { int a, b; } Pair_021DF59C;

typedef unsigned int   u32_021DF708;

typedef unsigned int   u32_021DF7F0;

typedef unsigned int   u32_021DF8A0;


typedef unsigned int   u32_021DF9E8;

typedef unsigned int u32_021DFA60;

typedef struct {
    u32_021DFA60 a;
    u32_021DFA60 b;
} Pair_021DFA60;

typedef struct {
    Pair_021DFA60 t[25];
} Table_021DEA24;

typedef struct { int id; int key; } Ent_021DFA98;

typedef struct { Ent_021DFA98 e[22]; } Tbl;

typedef struct { int fn; int id; } Ent_021DFAD0;

typedef struct { Ent_021DFAD0 e[2]; } T2;

typedef struct { Ent_021DFAD0 e[6]; } T6;

extern void func_0207D658(u32_021DEBD4,int,int);

extern int POKETRADE_2D_StepCursorSlide(char *p);

extern void func_02041570(int channel, u16 val);

extern void POKETRADE_2D_SetupCursorBg(char *p);

extern void NHTTP_RAP_DeleteConnection(u8 *p);

extern void NHTTP_RAP_Destroy(u8 *p);

extern int NHTTP_RAP_GetResultCode(u8 *);

extern int NHTTP_RAP_PollConnection(u8 *);

extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *);

extern int NHTTP_RAP_RecordList_GetCount(u8 *p);

extern u32_021DEF1C NHTTP_RAP_RecordList_GetValue(u32_021DEF1C p, u32_021DEF1C i);

extern void NHTTP_RAP_FreePostData(u8 *);

extern void POKE_TOOL_SetPartyValue(void *,u32_021DEF1C,u32_021DEF1C);

extern u32_021DEF1C func_0202136C(u16);

extern void *MAIL_Create(int);

extern void func_02008F88(struct Sub02008F80Obj *obj, const void *src);

extern void func_02019B58(void *);

extern struct MsgBank *func_02045B38(u32_021DEF1C resident, u32_021DEF1C arcId, u32_021DEF1C fileId, u32_021DEF1C heapId);

extern void *func_02045EC0(struct MsgBank *bank, u32_021DEF1C index);

extern u32_021DEF1C MSGDATA_Delete(struct Rec *rec);

extern u16 *STRBUF_GetChars(struct U16Vec *vec);

extern void STRBUF_Delete(struct U16Vec *vec);

extern void DWC_RAP_SetErrorCallback(int a0, int a1);

extern void DWC_RAPCOMMON_CreateSubHeapUnlimited(int,int,int);

extern u32_021DF0B8 func_0200853C(const struct Sub0200852CObj *obj);

extern u8 *NHTTP_RAP_Create(int,int,int);

extern void NHTTP_RAP_AllocPostData(u8 *,int,int,int);

extern void NHTTP_RAP_AppendPostData(u8 *,int,int);

extern int NHTTP_RAP_CreatePostRequest(u8 *);

extern int NHTTP_RAP_StartConnection(u8 *);

extern void WIPE_ResetBrightness(u32_021DF168 which);

extern void func_021DAEF0(char *p);

extern void func_021DBBD0(char *p);

extern int POKETRADE_PROC_GetBoxIndexForSlot(int,char *);

extern int POKETRADE_PROC_GetSlotIndexInBox(int,int);

extern void POKETRADE_2D_DeleteOfferIconActor(void *p, int a, int b);

extern void POKETRADE_2D_CreateMarkerActor(char *p, int i);

extern void POKETRADE_2D_SetMarkerActorVisible(void *p, int i, int a);

extern void POKETRADE_2D_DeleteMarkerActor(void *p, int i);

extern u32_021DF7F0 TOUCHPANEL_GetPointTrg(u32_021DF7F0 *outA, u32_021DF7F0 *outB);

extern void POKETRADE_2D_SetMarkerActorAnim(void *,int);

extern void POKETRADE_2D_DeleteMarkerButtonPair(int p, int n);

extern void POKETRADE_2D_CreateMarkerButtonActor(void *, int, int);

extern int GFL_USE_IsSeqPlaying(u32_021DF8A0 a);

extern void POKETRADE_2D_ReleaseMarkerResources(char *p);

extern void POKETRADE_2D_RegisterMarkerResources(int p);

extern void POKETRADE_2D_SetOfferIconsVisible(void *,int,int);

extern void POKETRADE_2D_LoadMonPalette(char *p, int side, void *mon);

extern void func_02041300(int,int,unsigned char,int,int,int,int);

extern u32_021DF9E8 GFL_NET_SendData(u32_021DF9E8 entry, u32_021DF9E8 sendID, u32_021DF9E8 c, u32_021DF9E8 d, u32_021DF9E8 e, u32_021DF9E8 f, u32_021DF9E8 g, u32_021DF9E8 h);

void POKETRADE_NEGO_StepWaitInputAfterMessage(void *p);

void POKETRADE_NEGO_StepShowNoOfferMessage(char *p);

void POKETRADE_NEGO_StepWaitWipeBrowse(void *p);

void POKETRADE_NEGO_StepBuildBrowseScene(char *p);

void POKETRADE_NEGO_StepWaitWipeToBrowse(void *p);

void POKETRADE_NEGO_StepWipeToBrowse(void *p);

void POKETRADE_NEGO_StepSendReady(void *p);

void POKETRADE_NEGO_StepWaitReadySync(unsigned char *p);

void POKETRADE_NEGO_StepSendCheckResult(void *p);

void POKETRADE_NEGO_AbortHttpRequest(void **p);

void POKETRADE_NEGO_StepPollMonCheck(u8 *p);

void POKETRADE_NEGO_StepStartMonCheck(char *p);

void POKETRADE_NEGO_StepRetryMonCheck(void *p);

void POKETRADE_NEGO_StepBeginMonCheckWipe(void *p);

void POKETRADE_NEGO_StepResolveFinalAgree(char *p);

void POKETRADE_NEGO_StepSendFinalAgree(void *p);

void POKETRADE_NEGO_StepSendFinalReady(u8 *p);

void POKETRADE_NEGO_StepWaitMessageThenContinue(void *p);

void POKETRADE_NEGO_StepBeginFinalReady(char *p);

void POKETRADE_NEGO_StepFinalAgreeMenuChoice(void *p);

void POKETRADE_NEGO_StepOpenFinalAgreeMenu(void *p);

void POKETRADE_NEGO_StepWaitFinalMessage(char *p);

void POKETRADE_NEGO_StepBeginFinalWait(char *p);

void POKETRADE_NEGO_StepCancelMenuChoice(void *p);

void POKETRADE_NEGO_StepOpenCancelMenu(void *p);

void POKETRADE_NEGO_StepShowCancelMessage(char *p);

int POKETRADE_NEGO_IsMonOwnOffer(char *p,int a,int b);

int POKETRADE_NEGO_IsMonPeerSelected(char *p, int a, int b);

void POKETRADE_NEGO_StepWaitTouchRelease(void *p);

void POKETRADE_NEGO_StepSendOfferRemoval(void *p);

void POKETRADE_NEGO_InitOfferMarkers(void *p);

void POKETRADE_NEGO_SetOfferMarkersState(void *p, int a);

void POKETRADE_NEGO_UpdateOfferMarkers(void *p);

void POKETRADE_NEGO_PollMarkerTouch(void *p);

void POKETRADE_NEGO_TickMarkerTimers(void *p);

void POKETRADE_NEGO_FlashMarker(void *p, int a, int b);

void POKETRADE_NEGO_ResetMarkers(void *p);

void POKETRADE_NEGO_ExitMarkers(void *p);

void POKETRADE_NEGO_TickOfferSlotTimers(void *p);

void POKETRADE_NEGO_PlaySeByKeyA(u32_021DFA60 key);

void POKETRADE_NEGO_PlaySeByKeyB(int key);

void POKETRADE_NEGO_PlaySeByEvent(int a0, u8 *a1);

void POKETRADE_SAVE_DrawOfferListWindows(char *p, int a1);

void POKETRADE_SAVE_SetupWindowRegsSummary(void *a0);

void POKETRADE_SAVE_DrawPartnerOfferCard(char *p,int i,void *mon);

void POKETRADE_SAVE_DeletePartnerOfferCard(char *p,int i);

void POKETRADE_3D_AddPokemonMcssFlipped(void *a, int b, int c, void *d, int e, int f);

void POKETRADE_3D_DeleteMcssSlot(void *p, int idx);

void POKETRADE_2D_FreeMainResources(char *p);

void POKETRADE_2D_DeleteBoxWindows(char *p);

void POKETRADE_2D_DeleteAllBoxIcons(char *p);

extern const Pair_021DF490 d_021E76D4;

extern const Pair_021DF59C d_021E76EC;

extern const Table_021DEA24 g_021E7844;

extern const Tbl d_021E7794;


/*
 * prototype: 02035C08 returns the r0 consumed by original after its forwarding call; matched 021D98AC documents full ARM9 forwarding proof.
 */
void POKETRADE_NEGO_StepBrowseOffersMain(char *p)
{
    int idx,sentinel;
    TOUCHBAR_Update(*(void * *)&((TradeWork *)p)->touchbar);
    if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((TradeWork *)p)->touchbar)==1) {
        func_02045CAC(*(struct MsgBank * *)&((TradeWork *)p)->messageBank,148,(*(void * *)&((TradeWork *)p)->f738));
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->touchbar),1,0);
        func_021DD09C(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOpenDeclineMenu);
        return;
    }
    sentinel=-1;
    if(TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((TradeWork *)p)->touchbar)==sentinel) {
        idx=TOUCHPANEL_HitTrg(d_021E80C4);
        if(idx!=sentinel) {
            func_020355D8(1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            POKETRADE_2D_MovePickedIconActor((int)p,sentinel);
            if(POKETRADE_NEGO_TrySelectOffer(p,idx)) return;
        }
        if(func_020355C4() && poll()) {
            ((TradeWork *)p)->cursorIndex%=6;
            if(((TradeWork *)p)->cursorIndex<0) ((TradeWork *)p)->cursorIndex=0;
            POKETRADE_2D_MovePickedIconActor((int)p,((TradeWork *)p)->cursorIndex);
            GFL_USE_PlaySeDefaultVolume(0x548);
            return;
        }
        if(poll()==1) {
            if(POKETRADE_NEGO_TrySelectOffer(p,((TradeWork *)p)->cursorIndex)) return;
        }
        if(POKETRADE_NEGO_PollOfferCursorKeys(p)) {
            POKETRADE_2D_MovePickedIconActor((int)p,((TradeWork *)p)->cursorIndex);
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
}

void POKETRADE_NEGO_StepWaitInputAfterMessage(void *p)
{
    int v;
    if(func_021DD140(p) && POKETRADE_SAVE_IsMessagePrintDone(p)) {
        v=KEY_GetTrg();
        if(v) func_020355D8(0);
        if(v==0) {
            v=TOUCHPANEL_GetTrg();
            if(v) func_020355D8(1);
            if(v==0) return;
        }
        if(func_020355C4()) POKETRADE_2D_MovePickedIconActor((int)p,-1);
        else POKETRADE_2D_MovePickedIconActor((int)p,0);
        POKETRADE_SAVE_CloseMessageWindowClear(p);
        POKETRADE_PROC_ResetTouchbarBackButton(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBrowseOffersMain);
    }
}

void POKETRADE_NEGO_StepShowNoOfferMessage(char *p)
{
    func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), 0x91, (*(void * *)&((TradeWork *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    *(p + 0x11F1) = 0x78;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepWaitInputAfterMessage);
}

static inline void inside(int wnd,int effect) {u32_021DEBD4 tmp=(*(volatile u16 *)0x04001048 & ~0x3f)|wnd;if(effect)tmp|=0x20;*(volatile u16 *)0x04001048=(u16)tmp;}

static inline void outside(int wnd,int effect) {u32_021DEBD4 tmp=(*(volatile u16 *)0x0400104a & ~0x3f)|wnd;if(effect)tmp|=0x20;*(volatile u16 *)0x0400104a=(u16)tmp;}

/*
 * volatile: hardware WININ 0x04001048, WINOUT 0x0400104A and DISPCNT 0x04001000 read-modify-written at 0x021DEBE8/0x021DEBF8, 0x021DEC0C/0x021DEC18, 0x021DEC1A/0x021DEC22.
 */
void POKETRADE_NEGO_SetupWindowRegsOffers(void *p) {
 func_0207D658(0x04001050,27,-8);
 inside(31,1);
 *(volatile u16 *)0x04001040=0x80ff;
 *(volatile u16 *)0x04001044=0xa9;
 outside(31,0);
 *(volatile u32_021DEBD4 *)0x04001000=(*(volatile u32_021DEBD4 *)0x04001000 & ~0xe000)|0x2000;
 func_02040588(3,1);func_02040588(5,1);func_02040588(4,1);
}

void POKETRADE_NEGO_StepWaitWipeBrowse(void *p) {
 if(POKETRADE_2D_StepCursorSlide(p)) {
  if(func_020355C4()) {POKETRADE_2D_MovePickedIconActor((int)p,-1);((TradeWork *)p)->cursorIndex=0;}
  else {POKETRADE_2D_MovePickedIconActor((int)p,0);((TradeWork *)p)->cursorIndex=0;}
  if(WIPE_SYS_EndCheck()) {POKETRADE_NEGO_SetupWindowRegsOffers(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepShowNoOfferMessage);}
 }
}

void POKETRADE_NEGO_StepBuildBrowseScene(char *p) {
 POKETRADE_2D_FreeMainResources(p);POKETRADE_NEGO_UpdateOfferMarkers(p);POKETRADE_NEGO_ResetMarkers(p);POKETRADE_2D_DeleteAllOfferIconActors(p);POKETRADE_NEGO_ReleaseIconResources(p);POKETRADE_2D_DeleteBoxWindows(p);POKETRADE_NEGO_DeleteHeaderWindows((unsigned char *)p);POKETRADE_2D_DeleteAllBoxIcons(p);
 POKETRADE_NEGO_RegisterIconResources(p,1);func_02041570(6,0);CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF04,0);
 TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),1,1);TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->touchbar),1,0);POKETRADE_SAVE_DrawOfferListWindows(p,6);
 ((TradeWork *)p)->f108C=0;((TradeWork *)p)->f1084=1;POKETRADE_2D_SetupCursorBg(p);
 WIPE_SYS_Start(0,1,1,0,6,1,((TradeWork *)p)->heapId);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitWipeBrowse);
}

void POKETRADE_NEGO_StepWaitWipeToBrowse(void *p)
{
    if (WIPE_SYS_EndCheck() != 0) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepBuildBrowseScene);
    }
}

void POKETRADE_NEGO_StepWipeToBrowse(void *p) {
 if(!POKETRADE_PROC_IsNetSession(p) || ((TradeWork *)p)->f1060) {
  WIPE_SYS_Start(0,0,0,0,6,1,((TradeWork *)p)->heapId);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitWipeToBrowse);
 }
}

void POKETRADE_NEGO_StepSendReady(void *p) {
 unsigned h=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(POKETRADE_PROC_IsNetSession(p)) {
  b=1;
  if(GFL_NET_SendToHandle((void *)h,0xc0a,1,(u32_021DEDBC)(&b))) {POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWipeToBrowse);return;}
 } else {POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWipeToBrowse);}
}

void POKETRADE_NEGO_StepWaitReadySync(unsigned char *p) {
 int v;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),21,8)) {
  if(p[0x11e6]==0 && p[0x11e7]==0) {POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendReady);return;}
  if(p[0x11e6]==0xf0) v=0x9e;
  else if(p[0x11e6]==0xf1) v=0x9f;
  else if(p[0x11e6]==0xf2) v=0xa0;
  else if(p[0x11e6]==0xff) v=0xa1;
  else if((p[0x11e7]&0xf0)==0xf0) v=0xa1;
  else if(p[0x11e7]) v=0x8f;
  else v=0x90;
  func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),v,(void *)(((TradeWork *)p)->f738));
  POKETRADE_SAVE_OpenMessageWindowTop(p);p[0x11f1]=120;((TradeWork *)p)->fF2C=0;
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitMessageThenWipe);
 }
}

void POKETRADE_NEGO_StepSendCheckResult(void *p) {
 void *h=GFL_NET_HANDLE_GetCurrentHandle();
 ((TradeWork *)p)->f109A=0;
 if(GFL_NET_SendToHandle((void *)h,0xc11,1, (u32_021DEDBC)((u32_021DEEA8)((char *)p+0x11e6)))) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),21,8);
  if(((TradeWork *)p)->f118C==2) DWC_RAP_SetVchatTalkLock(0);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitReadySync);
 }
}

void POKETRADE_NEGO_AbortHttpRequest(void **p)
{
    if (*p != 0) {
        NHTTP_RAP_DeleteConnection(*p);
        NHTTP_RAP_Destroy(*p);
        *p = 0;
        DWC_RAPCOMMON_DestroySubHeap();
    }
}

/*
 * lever: Nested success tests share the normal callback after the inner
 * guards. The bank allocation reads p+0x5f4 directly; the name allocation
 * reads the saved heap pointer, reproducing the original two load forms.
 * interface: 02019B58 receives the visibly loaded record pointer: its
 * empty 020185F0 call preserves r0 for 02019B64, which reads that input.
 */
void POKETRADE_NEGO_StepPollMonCheck(u8 *p)
{
    int status, result, i, off1, off2;
    u8 n=0, error;
    u8 *data;
    const u16 *heap;
    void *mon, *bank, *text, *name;
    u32_021DEF1C value;
    status=NHTTP_RAP_GetResultCode(*(u8 * *)&((TradeWork *)p)->f0);
    result=NHTTP_RAP_PollConnection(*(u8 * *)&((TradeWork *)p)->f0);
    if(result==0) {
    if(status==200) {
        data=NHTTP_RAP_GetRecvBuffer(*(u8 * *)&((TradeWork *)p)->f0);
        p[0x11e6]=NHTTP_RAP_RecordList_GetCount(data);
        if(p[0x11e6]==1) {
            off1=0x109a;
            if(*(u16 *)(p+off1)==0) {
                i=n;
                heap=(const u16 *)(p+0x5f4);
                off2=off1;
                off2-=0xb6;
                off1-=0xb6;
                do {
                    if(POKETRADE_PROC_IsMonValid(*(void **)(p+i*4+off1))) {
                        mon=*(void **)(p+i*4+off2);
                        if(NHTTP_RAP_RecordList_GetValue((u32_021DEF1C)data,n)) {
                            value=func_02017E1C(mon,6,0);
                            bank=func_02045B38(0,2,81,((TradeWork *)p)->heapId);
                            text=func_02045EC0(bank,15);
                            MSGDATA_Delete(bank);
                            if(func_0202136C(value)) {
                                name=MAIL_Create(*heap);
                                func_02017E1C(mon,167,(u32_021DEF1C)name);
                                func_02008F88(name,STRBUF_GetChars(text));
                                POKE_TOOL_SetPartyValue(mon,167,(u32_021DEF1C)name);
                                func_020307B0(name);
                            }
                            func_02019B58(mon);
                            POKE_TOOL_SetPartyValue(mon,142,(u32_021DEF1C)STRBUF_GetChars(text));
                            STRBUF_Delete(text);
                        }
                        n++;
                    }
                    i++;
                } while(i<3);
                ((TradeWork *)p)->f109A=1;
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepStartMonCheck);
                goto cleanup;
            }
        }
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendCheckResult);
    } else goto failed;
    } else goto failed;
    goto cleanup;
failed:
    {
        if(result==15 || status==200) return;
        switch(status) {
        case 400: error=240; break;
        case 401: error=241; break;
        case 408: error=242; break;
        default: error=255; break;
        }
        p[0x11e6]=error;
        NHTTP_RAP_DeleteConnection(*(u8 * *)&((TradeWork *)p)->f0);
    }
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendCheckResult);
cleanup:
    if(*(u8 * *)&((TradeWork *)p)->f0) {
        NHTTP_RAP_FreePostData(*(u8 * *)&((TradeWork *)p)->f0);
        NHTTP_RAP_Destroy(*(u8 * *)&((TradeWork *)p)->f0);
        *(u8 * *)&((TradeWork *)p)->f0=0;
        DWC_RAPCOMMON_DestroySubHeap();
        DWC_RAP_SetErrorCallback(0,0);
    }
}

void POKETRADE_NEGO_StepStartMonCheck(char *p) {
 int n=0;
 int i;
 DWC_RAPCOMMON_CreateSubHeapUnlimited(13,0x10000,((TradeWork *)p)->heapId);
 *(u8 * *)&((TradeWork *)p)->f0=NHTTP_RAP_Create(((TradeWork *)p)->heapId,func_0200853C((*(void * *)&((TradeWork *)p)->f830)),((struct Obj22746 *)(((TradeWork *)p)->f8))->f24);
 DWC_RAP_SetErrorCallback((int)POKETRADE_NEGO_AbortHttpRequest,(int)p);
 for(i=0;i<3;i++) if(POKETRADE_PROC_IsMonValid(((TradeWork *)p)->offerMon[1][i])) n++;
 NHTTP_RAP_AllocPostData(*(u8 * *)&((TradeWork *)p)->f0,((TradeWork *)p)->heapId,func_020173EC()*n,2);
 for(i=0;i<3;i++) if(POKETRADE_PROC_IsMonValid(((TradeWork *)p)->offerMon[1][i])) NHTTP_RAP_AppendPostData(*(u8 * *)&((TradeWork *)p)->f0,(int)((TradeWork *)p)->offerMon[1][i],func_020173EC());
 NHTTP_RAP_CreatePostRequest(*(u8 * *)&((TradeWork *)p)->f0);NHTTP_RAP_StartConnection(*(u8 * *)&((TradeWork *)p)->f0);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepPollMonCheck);
}

/*
 * volatile: field p+0x11fa re-read at 0x021DF18E after store at 0x021DF18C.
 */
void POKETRADE_NEGO_StepRetryMonCheck(void *p) {
 if(WIPE_SYS_EndCheck()) {
  POKETRADE_2D_DeleteAllBoxIcons(p);BG_SYS_SetSubVisiblePlanes(4);WIPE_ResetBrightness(4);
  ++*(volatile unsigned char *)&((TradeWork *)p)->f11FA;
  if(*(volatile unsigned char *)&((TradeWork *)p)->f11FA>=3) {POKETRADE_PROC_ClearNetAutoExit(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut);return;}
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),31,8);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepStartMonCheck);
 }
}

void POKETRADE_NEGO_StepBeginMonCheckWipe(void *p) {
 WIPE_SYS_Start((void *)4,0,0,0,6,1,((TradeWork *)p)->heapId);
 if(((TradeWork *)p)->f118C==2) DWC_RAP_SetVchatTalkLock(1);
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepRetryMonCheck);
}

void POKETRADE_NEGO_StepResolveFinalAgree(char *p)
{
    unsigned a, b;
    volatile int v; /* memory-resident on purpose: the original keeps v in [sp] and reads it uninitialised on the fall-through path; a plain local takes r7 */
    a = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
    b = 1 - a;
    if (!POKETRADE_PROC_IsNetSession(p)) {
        a = 0;
        b = 1;
    }
    if (POKETRADE_PROC_IsNetSession(p)) {
        if (!GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1A, 8)) {
            POKETRADE_NEGO_CheckCancelTouch(p);
            return;
        }
    }
    POKETRADE_NEGO_CloseCancelMenu(p, 0, 0);
    ((TradeWork *)p)->f11EA = 0;
    ((TradeWork *)p)->f11E8 = 3;
    ((TradeWork *)p)->f11E9 = 3;
    if (*(unsigned char *)(p + a + 0x11E0) == 10 && *(unsigned char *)(p + b + 0x11E0) == 10) {
        POKETRADE_NEGO_DrawOfferStatusLabel((u8 *)p, 0, 1, 1);
        POKETRADE_NEGO_DrawOfferStatusLabel((u8 *)p, 1, 1, 1);
        if (((TradeWork *)p)->f118C == 3) {
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepBeginMonCheckWipe);
        } else {
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepSendReady);
        }
        return;
    }
    if (*(unsigned char *)(p + a + 0x11E0) == 4 && *(unsigned char *)(p + b + 0x11E0) == 4) {
        ((struct Obj22747 *)(((TradeWork *)p)->f8))->f8 = 3;
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBeginWipeOut);
        return;
    }
    if (*(unsigned char *)(p + b + 0x11E0) == 4) {
        v = 0x61;
    } else if (*(unsigned char *)(p + a + 0x11E0) == 4) {
        v = 0x66;
    }
    func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), v, (*(void * *)&((TradeWork *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    ((TradeWork *)p)->f11E0 = 0;
    ((TradeWork *)p)->f11E1 = 0;
    ((TradeWork *)p)->f11E8 = 0;
    ((TradeWork *)p)->f11E9 = 0;
    POKETRADE_PROC_SetStep(p, (int)func_021DAEF0);
}

void POKETRADE_NEGO_StepSendFinalAgree(void *p) {
 unsigned h=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(POKETRADE_PROC_IsNetSession(p)) {
  b=1;
  if(GFL_NET_SendToHandle((void *)h,0xc0f,1, (u32_021DEDBC)((u32_021DF338)(&b)))) {POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveFinalAgree);return;}
 } else {POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveFinalAgree);}
}

void POKETRADE_NEGO_StepSendFinalReady(u8 *p) {
 unsigned h=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(POKETRADE_SAVE_IsMessagePrintDone((char *)p)) {
  if(POKETRADE_PROC_IsNetSession(p)) {
   b=10;
   if(GFL_NET_SendToHandle((void *)h,0xc00,1, (u32_021DEDBC)((u32_021DF37C)(&b)))) {
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendFinalAgree);return;
   }
  } else {p[0x11e0]=10;p[0x11e1]=10;POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendFinalAgree);}
 }
}

void POKETRADE_NEGO_StepWaitMessageThenContinue(void *p)
{
    GFL_NET_HANDLE_GetCurrentHandle();
    if (POKETRADE_SAVE_IsMessagePrintDone(p)) {
        POKETRADE_PROC_SetStep(p, (int)func_021DBBD0);
    }
}

void POKETRADE_NEGO_StepBeginFinalReady(char *p)
{
    func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), 0x88, (*(void * *)&((TradeWork *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    ((TradeWork *)p)->f11F1 = 0x78;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepSendFinalReady);
}

void POKETRADE_NEGO_StepFinalAgreeMenuChoice(void *p)
{
    int v;
    if (!APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->taskMenu))) return;
    v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->taskMenu));
    POKETRADE_SAVE_CloseTaskMenu(p);
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    ((TradeWork *)p)->taskMenu=0;
    if (v==0) {POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBeginFinalReady);return;}
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitMessageThenContinue);
}

void POKETRADE_NEGO_StepOpenFinalAgreeMenu(void *p)
{
    Pair_021DF490 t;
    if (POKETRADE_SAVE_IsMessagePrintDone(p)) {
        t = d_021E76D4;
        POKETRADE_SAVE_OpenTaskMenuAt(p, (int *)&t, 2, 0x20, 0xc);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepFinalAgreeMenuChoice);
    }
}

void POKETRADE_NEGO_StepWaitFinalMessage(char *p)
{
    GFL_NET_GetHandleNetID((struct Link *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()));
    if (POKETRADE_SAVE_IsMessagePrintDone(p) && func_021DD140(p)) {
        func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),0x89,(void *)(((TradeWork *)p)->f738));
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOpenFinalAgreeMenu);
    }
}

void POKETRADE_NEGO_StepBeginFinalWait(char *p)
{
    func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), 0x88, (*(void * *)&((TradeWork *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    ((TradeWork *)p)->f11F1 = 0x78;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepWaitFinalMessage);
}

void POKETRADE_NEGO_StepCancelMenuChoice(void *p)
{
    int v;
    if (!APP_TASKMENU_IsFinish((struct TaskMenu *)(((TradeWork *)p)->taskMenu))) return;
    v=APP_TASKMENU_GetCursorPos((const u8 *)(((TradeWork *)p)->taskMenu));
    POKETRADE_SAVE_CloseTaskMenu(p);
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    ((TradeWork *)p)->taskMenu=0;
    if (v==0) {POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepBeginFinalWait);return;}
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    POKETRADE_PROC_SetStep(p,(int)func_021DBBD0);
}

void POKETRADE_NEGO_StepOpenCancelMenu(void *p)
{
    Pair_021DF59C t;
    if (POKETRADE_SAVE_IsMessagePrintDone(p)) {
        t = d_021E76EC;
        POKETRADE_SAVE_OpenTaskMenuAt(p, (int *)&t, 2, 0x20, 0xc);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepCancelMenuChoice);
    }
}

void POKETRADE_NEGO_StepShowCancelMessage(char *p)
{
    func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), 0x87, (*(void * *)&((TradeWork *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    TOUCHBAR_SetButtonEnabled((*(void * *)&((TradeWork *)p)->touchbar), 1, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepOpenCancelMenu);
    POKETRADE_SAVE_SetupWindowRegsSummary(p);
}

int POKETRADE_NEGO_IsMonOwnOffer(char *p,int a,int b)
{
    int x,y,i;
    x=POKETRADE_PROC_GetBoxIndexForSlot(a,p);
    y=POKETRADE_PROC_GetSlotIndexInBox(a,b);
    if(((TradeWork *)p)->fF7C==y && ((TradeWork *)p)->fF80==x) return 1;
    if(POKETRADE_PROC_IsHostSide(p)) {
        for(i=0;i<3;i++) {
            if(((TradeWork *)p)->offerSlot[0][i]==-1) continue;
            if(y==((TradeWork *)p)->offerSlot[0][i] && x==((TradeWork *)p)->offerBox[0][i]) return 1;
        }
    } else {
        if(((TradeWork *)p)->selectedSlot==y && ((TradeWork *)p)->selectedBox==x && ((TradeWork *)p)->fF7C==-1 && ((TradeWork *)p)->fF80==-1) return 1;
    }
    return 0;
}

int POKETRADE_NEGO_IsMonPeerSelected(char *p, int a, int b)
{
    int x = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
    int y = POKETRADE_PROC_GetSlotIndexInBox(a, b);
    if (((TradeWork *)p)->peerSelectedSlot == y && ((TradeWork *)p)->peerSelectedBox == x) {
        return 1;
    }
    return 0;
}

void POKETRADE_NEGO_StepWaitTouchRelease(void *p)
{
    if (TOUCHPANEL_GetCont() == 0) {
        POKETRADE_PROC_SetStep(p, (int)func_021DBBD0);
    }
}

void POKETRADE_NEGO_StepSendOfferRemoval(void *p)
{
    int v = POKETRADE_NEGO_FindOfferIndex(p, ((TradeWork *)p)->peerSelectedBox,
                          ((TradeWork *)p)->peerSelectedSlot);

    if (POKETRADE_PROC_IsNetSession(p) == 0 ||
        GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc0b, 4, (u32_021DEDBC)((u32_021DF708)(&v))) != 0) {
        ((TradeWork *)p)->selectedSlot = -1;
        ((TradeWork *)p)->selectedBox = -1;
        ((TradeWork *)p)->fF7C = -1;
        ((TradeWork *)p)->fF80 = -1;
        ((TradeWork *)p)->peerSelectedSlot = -1;
        ((TradeWork *)p)->peerSelectedBox = -1;
        if (v != -1) {
            POKETRADE_NEGO_RemoveOffer(p, 0, v);
            POKETRADE_2D_DeleteOfferIconActor(p, 0, v);
        }
        POKETRADE_PROC_SetStep(p, 0x021DF6ED);
    }
}

/*
 * Init the four sub-objects when the object is in the first state.
 */
void POKETRADE_NEGO_InitOfferMarkers(void *p)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        POKETRADE_2D_CreateMarkerActor(p, i);
}

void POKETRADE_NEGO_SetOfferMarkersState(void *p, int a)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        POKETRADE_2D_SetMarkerActorVisible(p, i, a);
}

void POKETRADE_NEGO_UpdateOfferMarkers(void *p)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0)
        return;
    for (i = 0; i < 4; i++)
        POKETRADE_2D_DeleteMarkerActor(p, i);
}

void POKETRADE_NEGO_PollMarkerTouch(void *p)
{
    unsigned x,y;
    unsigned char slot;
    if (!POKETRADE_PROC_IsHostSide(p)) return;
    if (!TOUCHPANEL_GetPointTrg(&x,&y)) return;
    if(x<8 || x>=104 || y<144 || y>=168) return;
    slot=(x-8)/24U;
    if(slot>=4) slot=3;
    POKETRADE_2D_SetMarkerActorAnim(p,slot);
    POKETRADE_NEGO_FlashMarker(p,slot,0);
    if(POKETRADE_PROC_IsNetSession(p)) GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc0d,1, (u32_021DEDBC)((u32_021DF7F0)(&slot)));
}

/*
 * Count the two arm timers down and re-arm the ones that expired.
 */
void POKETRADE_NEGO_TickMarkerTimers(void *p)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0)
        return;
    for (i = 0; i < 2; i++) {
        if (((unsigned char *)p)[0x11e4 + i] == 0)
            continue;
        ((unsigned char *)p)[0x11e4 + i]--;
        if (((unsigned char *)p)[0x11e4 + i] == 0)
            POKETRADE_2D_DeleteMarkerButtonPair((int)p, i);
    }
}

void POKETRADE_NEGO_FlashMarker(void *p, int a, int b)
{
    if (POKETRADE_PROC_IsHostSide(p)) {
        POKETRADE_2D_CreateMarkerButtonActor(p,a,b);
        ((unsigned char *)p+b)[0x11e4]=60;
        if (!GFL_USE_IsSeqPlaying(0x54a)) GFL_USE_PlaySeDefaultVolume(0x54a);
    }
}

/*
 * Reset the two sub-objects and the decoder when in the first state.
 */
void POKETRADE_NEGO_ResetMarkers(void *p)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0)
        return;
    for (i = 0; i < 2; i++)
        POKETRADE_2D_DeleteMarkerButtonPair((int)p, i);
    POKETRADE_2D_ReleaseMarkerResources(p);
}

/*
 * Tear the object down when it is in the first state.
 */
void POKETRADE_NEGO_ExitMarkers(void *p)
{
    if (POKETRADE_PROC_IsHostSide(p))
        POKETRADE_2D_RegisterMarkerResources((int)p);
}

void POKETRADE_NEGO_ShowOfferSlotMon(void *p,int i,void *v)
{
    int one;
    POKETRADE_2D_SetOfferIconsVisible(p,i,0);
    if (((unsigned char *)p+i)[0x11e2]) {
        POKETRADE_SAVE_DeletePartnerOfferCard(p,i);
        POKETRADE_3D_DeleteMcssSlot(p,i);
    }
    POKETRADE_2D_LoadMonPalette(p,i,v);
    POKETRADE_SAVE_DrawPartnerOfferCard(p,i,v);
    one=1;
    func_02041B6C(1);
    POKETRADE_3D_AddPokemonMcssFlipped(p,i,one-i,v,one-i,one);
}

void POKETRADE_NEGO_TickOfferSlotTimers(void *p)
{
    int i;
    for(i=0;i<2;i++) {
        if (((unsigned char *)p+i)[0x11e2]==0) continue;
        ((unsigned char *)p+i)[0x11e2]--;
        POKETRADE_2D_SetOfferIconsVisible(p,i,0);
        if (((unsigned char *)p+i)[0x11e2]==0) {
            POKETRADE_SAVE_DeletePartnerOfferCard(p,i);
            func_02041300(1,0,(unsigned char)(i<<4),0,16,24,16);
            func_02041B6C(1);
            POKETRADE_3D_DeleteMcssSlot(p,i);
            POKETRADE_2D_SetOfferIconsVisible(p,i,1);
        }
    }
}

int POKETRADE_NEGO_SendOfferMon(char *p,void *src,int kind)
{
    unsigned id;
    int one;
    id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
    if(((TradeWork *)p)->stateFlags.bits.sendBusy) return 0;
    MI_CpuCopy8(src,((TradeWork *)p)->f106C,func_020173EC());
    one=1;
    if(!(int)GFL_NET_SendData(id,255,(u16)kind,func_020173EC(),(u32_021DF9E8)(((TradeWork *)p)->f106C),(int)0,(int)0,(int)one)) return 0;
    ((TradeWork *)p)->stateFlags.bits.sendBusy=one;
    return one;
}

void POKETRADE_NEGO_PlaySeByKeyA(u32_021DFA60 key)
{
    Table_021DEA24 local;
    unsigned int i;

    local = g_021E7844;
    for (i = 0; i < 25; i++)
        if (key == local.t[i].b)
            GFL_USE_PlaySeDefaultVolume(local.t[i].a);
}

void POKETRADE_NEGO_PlaySeByKeyB(int key)
{
    Tbl t = d_021E7794;
    unsigned i;
    for (i = 0; i < 22; i++) {
        if (key == t.e[i].key) {
            GFL_USE_PlaySeDefaultVolume(t.e[i].id);
        }
    }
}

/*
 * Recursive MATCH unblocker: the non-SDK callee of ov119 POKETRADE_MCSS_SlideApplyOffset
 * (+0038) and a dependency of the func_021D7130 tree.  Copies two constant
 * eight-byte-record tables from 0x021E7754 (two records) and 0x021E7764 (six
 * records) to the stack, gates on two bytes of the second argument, then
 * calls GFL_USE_PlaySeDefaultVolume on each record whose id matches arg0.  Both table
 * addresses are literal pool words, so they carry no relocation; the byte at
 * +0x11ED picks the six-record table (the `== 0` arm is the fall-through, the
 * unsigned counter is what makes the loop `blo`, not `blt`).
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_NEGO_PlaySeByEvent(int a0, u8 *a1)
{
    T2 t1 = *(T2 *)0x021E7754;
    T6 t2 = *(T6 *)0x021E7764;
    unsigned int i;

    if (a1[0x11EF] != 0)
        return;
    if (a1[0x11ED] == 0) {
        for (i = 0; i < 2; i++)
            if (a0 == t1.e[i].id)
                GFL_USE_PlaySeDefaultVolume(t1.e[i].fn);
    } else {
        for (i = 0; i < 6; i++)
            if (a0 == t2.e[i].id)
                GFL_USE_PlaySeDefaultVolume(t2.e[i].fn);
    }
}
