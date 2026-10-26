/*
 * file:     intrude_subdisp.c
 * unit:     yes
 * function: INTRUDE_FIELD_InitMmdlCopyAnime, INTRUDE_FIELD_MainMmdlCopyAnime, INTRUDE_SUBDISP_MainRequestAnswerSeq, INTRUDE_SUBDISP_CreatePalaceWarpEvent, INTRUDE_SUBDISP_CreateReturnPalaceEvent, INTRUDE_SUBDISP_CreateDisconnectEvent, INTRUDE_SUBDISP_DisconnectEventMain, INTRUDE_SUBDISP_CreateGuideScriptEvent, INTRUDE_SUBDISP_GuideScriptEventMain, INTRUDE_SUBDISP_CreateTownWarpEvent, INTRUDE_SUBDISP_CreatePlayerWarpEvent, INTRUDE_SUBDISP_CreateBrightFadeEvent, INTRUDE_SUBDISP_BrightFadeEventMain, INTRUDE_SUBDISP_ScriptAddAreaMmdls, INTRUDE_SUBDISP_ScriptAddAreaMapsAndMarkers, INTRUDE_SUBDISP_Init, INTRUDE_SUBDISP_Exit, INTRUDE_SUBDISP_Update, INTRUDE_SUBDISP_Draw, INTRUDE_SUBDISP_EventCheck, INTRUDE_SUBDISP_VBlankTask, INTRUDE_SUBDISP_SystemSetup, INTRUDE_SUBDISP_SystemExit, INTRUDE_SUBDISP_BgSetup, INTRUDE_SUBDISP_BgExit, INTRUDE_SUBDISP_BmpWinSetup, INTRUDE_SUBDISP_BmpWinExit, INTRUDE_SUBDISP_ClactResourceLoad, INTRUDE_SUBDISP_ClactResourceUnload, INTRUDE_SUBDISP_ClactActorCreate, INTRUDE_SUBDISP_ClactActorDelete, INTRUDE_SUBDISP_CreateTownActors, INTRUDE_SUBDISP_CreatePlayerMarkActors, INTRUDE_SUBDISP_CreateTownMarkActors, INTRUDE_SUBDISP_CreateMyPlayerActor, INTRUDE_SUBDISP_CreatePlayerIconActors, INTRUDE_SUBDISP_CreateInfoIconActor, INTRUDE_SUBDISP_CreateButtonActors, INTRUDE_SUBDISP_DeleteButtonBmpOam, INTRUDE_SUBDISP_UpdateTownActors, INTRUDE_SUBDISP_UpdatePlayerMarkActors, INTRUDE_SUBDISP_UpdatePlayerTownActors, INTRUDE_SUBDISP_UpdateTownMarkPalette, INTRUDE_SUBDISP_UpdateMyPlayerActor, INTRUDE_SUBDISP_UpdateButtonActors, INTRUDE_SUBDISP_UpdateInfoIcon, INTRUDE_SUBDISP_PrintTitle, INTRUDE_SUBDISP_PrintInfoMessage, INTRUDE_SUBDISP_GetTargetPlayerData, INTRUDE_SUBDISP_IsZoneMatch, INTRUDE_SUBDISP_SetTouchRect, INTRUDE_SUBDISP_IsInTouchRect, INTRUDE_SUBDISP_UpdateTouch, INTRUDE_SUBDISP_ReloadBgScreens, INTRUDE_SUBDISP_UpdateBgPalette, INTRUDE_SUBDISP_SetBgPalette, INTRUDE_SUBDISP_InitTownState, INTRUDE_SUBDISP_UpdateTownState, INTRUDE_SUBDISP_StartTownBlink, INTRUDE_SUBDISP_IsTownBlinking, INTRUDE_SUBDISP_SetTownCursor, INTRUDE_SUBDISP_StartButtonBlink, INTRUDE_SUBDISP_UpdateButtonBlink, INTRUDE_SUBDISP_IsInfoActive, INTRUDE_SUBDISP_ClearInfoPanel, INTRUDE_SUBDISP_DrawInfoPanel, INTRUDE_SUBDISP_IsAlone
 * address:  0x0217C758
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 *   FLDMMDL_InitPosRecord  0x0216E618  thumb  ov010
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   INTRUDE_FIELD_ChangePlayerLook  0x0217BCDC  thumb  ov018
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   d_02183AF0     0x02183AF0  data  a4
 *   g_02183AF0     0x02183AF0  data  a4
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_GIMMICK_GAUGE_EFFECT_StartEffectAt  0x021F37B8  thumb  ov060
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive  0x021F37D8  thumb  ov060
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   INTRUDE_COMM_SendRequest  0x02173A2C  thumb  ov011
 *   INTRUDE_COMM_TakeRequestResult  0x02175514  thumb  ov011
 *   KEY_GetTrg  0x020362DC  arm
 *   INTRUDE_COMM_SendAnswer  0x02173B9C  thumb  ov011
 *   INTRUDE_COMM_NextRequestToken  0x021753B8  thumb  ov011
 *   INTRUDE_COMM_SendReply  0x02173AE0  thumb  ov011
 *   INTRUDE_FIELD_GetZoneAnchor 0x0217BED4 thumb ov018
 *   EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset 0x02185588 thumb ov020
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_DATA_SetIntrudeId  0x02012B8C  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_SetIntrudeId  0x02175710  thumb  ov011
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GAME_COMM_GetLastKind  0x0202647C  thumb
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   INTRUDE_FIELD_SetSingleAreaMode  0x0217C094  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GAME_COMM_IsTransition  0x02026460  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAMESYSTEM_IsFieldMapActive  0x02012114  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   FIELD_MSGBG_SysWinPrintMsg  0x02190E74  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayTask  0x02029830  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   MSGDATA_Delete  0x02045C04  arm
 *   FIELD_PLAYER_CheckFormModel  0x021A3238  thumb  ov021
 *   INTRUDE_FIELD_InitPlayerSpin  0x0217C658  thumb  ov018
 *   INTRUDE_FIELD_StepPlayerSpin  0x0217C688  thumb  ov018
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   GAMESYSTEM_GetFieldMapState  0x0201212C  thumb
 *   EVENT_COMM_ERROR_Create  0x021C06CC  thumb  ov021
 *   GAME_COMM_ClearCounter  0x02026484  thumb
 *   GAME_COMM_ClearPlayerStatus  0x020264F4  thumb
 *   EVENT_MAPCHANGE_CreateIntrudeReturnEvent  0x02185214  thumb  ov020
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   EVENT_MAPCHANGE_CreateIntrudeWarpEvent  0x02185140  thumb  ov020
 *   INTRUDE_FIELD_FindZonePos  0x0217BEA8  thumb  ov018
 *   EVENT_MAPCHANGE_CreateWarpEvent  0x02184D38  thumb  ov020
 *   FIELDMAP_GetVReq  0x02188E30  thumb  ov021
 *   FLD_VREQ_SetSubMasterBrightness  0x021D324C  thumb  ov021
 *   FIELD_SUBSCREEN_ChangeModeNow  0x021A0F40  thumb  ov021
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   INTRUDE_FIELD_AddAreaMmdls 0x0217BF84 thumb ov018
 *   INTRUDE_FIELD_ResetExtraAreaCount  0x0217BBCC  thumb  ov018
 *   INTRUDE_FIELD_AddAreaMaps  0x0217BBD8  thumb  ov018
 *   INTRUDE_FIELD_AddAreaMapCount  0x0217BC94  thumb  ov018
 *   INTRUDE_FIELD_AddMarkerMmdls  0x0217C194  thumb  ov018
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOn  0x02037174  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   str_02183B14   0x02183B14  data  a1
 *   TCB_DeleteTask  0x02030EAC  arm
 *   MIi_CpuClear16  0x02082A48  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOff  0x02037190  arm
 *   GAME_DATA_GetWifiList            0x0201283C  thumb
 *   WIH_DWC_PollStatus            0x0201058C  thumb
 *   TCBL_Main            0x020310C4  arm
 *   PRINTSYS_QUE_Main            0x0201C4E4  thumb
 *   BMP_WIN_GetBmp            0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget            0x0201C6C4  thumb
 *   BMP_WIN_TransferChars            0x02045334  arm
 *   BMP_OAM_UploadChars            0x020257D0  thumb
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   GAME_DATA_GetIntrudeIdByte            0x0215841C  thumb  ov010
 *   GFL_NET_IsConnectMember            0x0203D1C0  arm
 *   INTRUDE_COMM_SendUnionInfoRequest            0x021746AC  thumb  ov011
 *   INTRUDE_COMM_GetUnionInfoReceived            0x02158428  thumb  ov010
 *   FIELDMAP_GetSubscreen            0x02188CCC  thumb  ov021
 *   GF_PANIC_Fail            0x02034714  arm
 *   str_02183B28             0x02183B28  data  a1
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   INTRUDE_COMM_HasResult  0x02175DA8  thumb  ov011
 *   INTRUDE_COMM_IsSessionAccepted  0x02175B8C  thumb  ov011
 *   INTRUDE_COMM_GetPlayerNetId  0x02158378  thumb  ov010
 *   DC_FlushRange  0x020862F0  arm
 *   GXS_LoadOBJPltt  0x0207E5D0  arm
 *   GXS_LoadOBJ  0x0207E804  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   TCBL_Create  0x0203101C  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   d_021836B4     0x021836B4  data   a4
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   CLACT_DeleteRenderer  0x0204B084  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   BG_SYS_InitBgLayer            0x0203FCA0  arm
 *   MIi_CpuClear32           0x02082A7C  arm
 *   ARC_UTIL_UploadBgCharFromHandle            0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle            0x020498F4  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle            0x02049EF4  arm
 *   MIi_CpuCopy16            0x02082A60  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole            0x02049B68  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole            0x02049B40  arm
 *   BG_SYS_SetPlaneVisible            0x02040588  arm
 *   d_0218370C               0x0218370C  data  a4
 *   d_0218372C               0x0218372C  data  a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   ARC_UTIL_LoadBgCharDataFromHandle  0x02049DF4  arm
 *   CLACT_GetCharacterVramAddress  0x0204ABBC  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   d_021836CC     0x021836CC  data  a4
 *   d_02176AA0     0x02176AA0  data  a4
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   d_021836E4  0x021836E4  data  a4
 *   d_021836DC  0x021836DC  data  a4
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   d_021836D4  0x021836D4  data  a4
 *   d_021836EC  0x021836EC  data  a4
 *   d_021836C4  0x021836C4  data  a4
 *   BMP_Create  0x02043678  arm
 *   BMP_OAM_Create  0x020255A0  thumb
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   d_021836AA     0x021836AA  data   a2
 *   d_021836F4     0x021836F4  data   a4
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   PALANM_BlendColors  0x02021F64  thumb
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   CLACT_GetActorPaletteOffset  0x0204B714  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   d_021836A4     0x021836A4  data   a1
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   MIi_CpuCopy32  0x02082A90  arm
 *   BMP_Clear  0x02043B5C  arm
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   GAME_COMM_PopInfoMessage  0x02026608  thumb
 *   INTRUDE_COMM_IsWarnedWithoutRequest  0x021585BC  thumb  ov010
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb  ov010
 *   INTRUDE_COMM_SetWordSetMemberName  0x021762C0  thumb  ov011
 *   INTRUDE_COMM_SetWordSetRequest  0x021762D8  thumb  ov011
 *   FIELD_PALACE_SYS_IsZoneFlagSet  0x021D3554  thumb  ov021
 *   GAME_DATA_GetBattleRecSlot 0x020127AC thumb
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   FIELD_SUBSCREEN_GetPanelResult  0x021A0F94  thumb  ov021
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   BMP_OAM_GetEnabled  0x020257C4  thumb
 *   ARC_UTIL_UploadBgPaletteFromArchive  0x0204989C  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   MATH_CountPopulation  0x02080D24  arm
 *   INTRUDE_COMM_GetSessionRemaining  0x021758C8  thumb  ov011
 *   INTRUDE_COMM_GetActiveSessionRequest  0x02175B34  thumb  ov011
 *   INTRUDE_FIELD_IsStartRequested  0x0217C070  thumb  ov018
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   INTRUDE_COMM_HasUnlockFlags 0x02158590 thumb ov010
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb  ov018
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb  ov018
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb  ov018
 *   EVENT_COMM_COMMON_GetMissionState  0x0217F5A0  thumb  ov018
 *   EVENT_COMM_COMMON_ChangeTalkedItemSaleEvent  0x021828A8  thumb  ov018
 *   EVENT_COMM_COMMON_ChangeTalkedItemPurchaseEvent  0x021828B0  thumb  ov018
 */
#define REG_DB_DISPCNT_SUB (*(volatile u32 *)REG_DB_DISPCNT_ADDR)
#define REG_WINOUT_SUB     (*(volatile u16 *)REG_DB_WINOUT_ADDR)
#define REG_DB_BLDCNT_SUB (*(volatile u16 *)REG_DB_BLDCNT_ADDR)
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../ov011/intrude_comm_types.h"
#include "event_comm_common_types.h"
#include "intrude_subdisp_types.h"
#include "intrude_field_types.h"
#include "../ov010/fldmmdl_types.h"

#include "../sdk_fx.h"

/* Work of the brightness fade event (12 bytes, allocated by INTRUDE_SUBDISP_CreateBrightFadeEvent). */
typedef struct IntrudeBrightFadeWork {
    struct FieldMap *fieldMap;  /* 0x00 */
    struct FieldSubscreen *subscreen;            /* 0x04: sub screen that is switched back to mode 0 */
    int frame;                  /* 0x08: frames since the fade started */
} IntrudeBrightFadeWork;

/* Work of the disconnect event (0x28 bytes, allocated by INTRUDE_SUBDISP_CreateDisconnectEvent). */
typedef struct {
    void *msgData;          /* 0x00 */
    void *msgBox;           /* 0x04 */
    PlayerSpinWork copyRecord;      /* 0x08: record of the player copy animation */
    int cause;              /* 0x20: 0 = own choice, 1 and 2 = peer left */
    int alone;              /* 0x24 */
} IntrudeDisconnectWork;

extern void MI_CpuFill8(void *, int, int);
struct GameSystem;
struct GameData;
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
struct FieldPlayer;
#include "../ov021/fieldmap.h"
struct Mmdl;
#include "../ov021/field_player.h"
#include "../ov010/fldmmdl.h"
#include "../ov010/fldmmdl_poslog.h"
struct MmdlHeader;
struct MmdlSys;
struct IntrudeCommSys;
#include "intrude_field.h"
#include "../ov060/field_gimmick_gauge_effect.h"
#include "../arm9/gfl_use.h"
struct IntrudeMemberRecord;
#include "../ov011/intrude_comm.h"
#include "../arm9/key.h"
struct GameEvent;
struct GameComm;
#include "../ov010/intrude_comm_query.h"
struct GameEvent;
#include "../arm9/game_comm.h"
#include "../arm9/net_err.h"
struct FieldMsgBg;
struct MsgBank;
#include "../ov021/field_msgbg.h"
struct FieldSysWin;
#include "../arm9/field_sound_system.h"
struct MsgBank;
#include "../arm9/msgdata.h"
struct PlayerSpinWork;
struct EventWork;
#include "../arm9/zonedata.h"
#include "../ov010/script_sys.h"
#include "../ov021/event_comm_error.h"
struct IntrudeZonePos;
struct VecFx32;
struct FldVReq;
#ifdef __MWERKS__
extern void FLD_VREQ_SetSubMasterBrightness(void *vreq, int brightness); /* original prototype; the definition differs in pointer type, argument width */
#else
#include "../ov021/fld_vreq.h"
#endif
struct FieldSubscreen;
#include "../ov021/field_subscreen.h"
struct ScrcmdWork;
#include "../ov010/scrcmd_work.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/arc_tool.h"
#include "../arm9/net.h"
#include "../arm9/wm_icon.h"
struct TcbTask;
struct PlayerWork;
#include "../arm9/tcb_list.h"
extern void MIi_CpuClear16();
struct FieldState;
#include "../arm9/wih_dwc.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
struct PrintQueue;
#include "../arm9/printsys.h"
struct BmpWin;
struct Bmp;
#include "../arm9/bmp_win.h"
struct BmpOam;
#include "../arm9/g2.h"
#include "../arm9/gf_panic.h"
struct IntrudeSession;
#include "../arm9/os_cache.h"
#include "../arm9/gx_load2d.h"
struct SurfaceInit;
struct Renderer;
struct BmpOamSys;
#include "../arm9/gf_font.h"
struct WordSet;
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
#include "../arm9/bg_sys.h"
void MIi_CpuClear32(u32 data, void *dest, u32 size);
#include "../arm9/arc_util.h"
void MIi_CpuCopy16(const void *src, void *dest, u32 size);
struct ClactActor;
struct ClactActor;
struct MyStatus;
#include "../arm9/mystatus.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#ifdef __MWERKS__
extern void PALANM_BlendColors(void *, void *, int, u8, u16); /* original prototype; the definition differs in pointer type, argument sign, argument width */
#else
#include "../arm9/palanm.h"
#endif
extern void MIi_CpuCopy32(const void *src, void *dst, int size);
struct GameCommInfoMessage;
struct IntrudeMemberName;
struct IntrudeRequestHead;
#include "../ov021/field_palace_sys.h"
#include "../arm9/touchpanel.h"
#include "../arm9/math.h"

void INTRUDE_FIELD_InitMmdlCopyAnime(PlayerSpinWork *r, void *gameSystem, void *fieldMap, void *intrudeWork, u16 id, u8 kind, u8 flag, u16 idx, int place);
int INTRUDE_FIELD_MainMmdlCopyAnime(PlayerSpinWork *r);
int INTRUDE_SUBDISP_MainRequestAnswerSeq(IntrudeCommSys *sys, EventCommCommonWork *work, u8 *state);
struct GameEvent *INTRUDE_SUBDISP_CreatePalaceWarpEvent(void *p);
struct GameEvent *INTRUDE_SUBDISP_CreateReturnPalaceEvent(struct GameSystem *gameSystem);
struct GameEvent *INTRUDE_SUBDISP_CreateDisconnectEvent(void *a, int b);
int INTRUDE_SUBDISP_DisconnectEventMain(struct GameEvent *a, int *seq, void *work);
struct GameEvent *INTRUDE_SUBDISP_CreateGuideScriptEvent(void *p);
int INTRUDE_SUBDISP_GuideScriptEventMain(struct GameEvent *p, int *state, void *eventWork);
struct GameEvent *INTRUDE_SUBDISP_CreateTownWarpEvent(void *gameSystem, void *fieldMap, u16 zoneId, int mode);
struct GameEvent *INTRUDE_SUBDISP_CreatePlayerWarpEvent(void *gameSystem, void *fieldMap, int netId);
struct GameEvent *INTRUDE_SUBDISP_CreateBrightFadeEvent(void *p, struct FieldMap *fieldMap, struct FieldSubscreen *subscreen);
int INTRUDE_SUBDISP_BrightFadeEventMain(struct GameEvent *event, int *state, void *work);
int INTRUDE_SUBDISP_ScriptAddAreaMmdls(void *unused, void *p);
int INTRUDE_SUBDISP_ScriptAddAreaMapsAndMarkers(void *unused, void *scriptWork);
IntrudeSubdispWork *INTRUDE_SUBDISP_Init(void *gameSystem);
void INTRUDE_SUBDISP_Exit(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_Update(IntrudeSubdispWork *work, int mode);
void INTRUDE_SUBDISP_Draw(IntrudeSubdispWork *work);
struct GameEvent *INTRUDE_SUBDISP_EventCheck(IntrudeSubdispWork *work, int touched, struct FieldSubscreen *param);
void INTRUDE_SUBDISP_VBlankTask(struct TcbTask *tcb, void *taskWork);
void INTRUDE_SUBDISP_SystemSetup(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_SystemExit(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_BgSetup(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_BgExit(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_BmpWinSetup(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_BmpWinExit(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_ClactResourceLoad(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_ClactResourceUnload(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_ClactActorCreate(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_ClactActorDelete(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_CreateTownActors(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreatePlayerMarkActors(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreateTownMarkActors(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreateMyPlayerActor(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreatePlayerIconActors(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreateInfoIconActor(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_CreateButtonActors(IntrudeSubdispWork *work, void *bg);
void INTRUDE_SUBDISP_DeleteButtonBmpOam(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_UpdateTownActors(IntrudeSubdispWork *work, void *target);
void INTRUDE_SUBDISP_UpdatePlayerMarkActors(IntrudeSubdispWork *work, void *target);
void INTRUDE_SUBDISP_UpdatePlayerTownActors(IntrudeSubdispWork *work, IntrudeCommSys *sys, void *target);
void INTRUDE_SUBDISP_UpdateTownMarkPalette(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_UpdateMyPlayerActor(IntrudeSubdispWork *work, void *target, u16 zoneId);
void INTRUDE_SUBDISP_UpdateButtonActors(IntrudeSubdispWork *work, void *target);
void INTRUDE_SUBDISP_UpdateInfoIcon(IntrudeSubdispWork *work, void *target);
void INTRUDE_SUBDISP_PrintTitle(IntrudeSubdispWork *work, int zoneId);
void INTRUDE_SUBDISP_PrintInfoMessage(IntrudeSubdispWork *work, IntrudeCommSys *sys, u16 zoneId);
void *INTRUDE_SUBDISP_GetTargetPlayerData(IntrudeSubdispWork *work);
int INTRUDE_SUBDISP_IsZoneMatch(u16 zone, u16 zoneA, u16 zoneB);
void INTRUDE_SUBDISP_SetTouchRect(int x, int y, int halfWidth, int halfHeight, IntrudeSubdispRect *rect);
int INTRUDE_SUBDISP_IsInTouchRect(int x, int y, const IntrudeSubdispRect *rect);
void INTRUDE_SUBDISP_UpdateTouch(IntrudeCommSys *sys, IntrudeSubdispWork *work, int zoneId);
void INTRUDE_SUBDISP_ReloadBgScreens(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_UpdateBgPalette(IntrudeSubdispWork *work, IntrudeCommSys *sys);
void INTRUDE_SUBDISP_SetBgPalette(IntrudeSubdispWork *work, int homeSlot);
void INTRUDE_SUBDISP_InitTownState(IntrudeSubdispWork *work, IntrudeCommSys *sys);
void INTRUDE_SUBDISP_UpdateTownState(IntrudeSubdispWork *work, IntrudeCommSys *sys);
void INTRUDE_SUBDISP_StartTownBlink(IntrudeSubdispWork *work);
int INTRUDE_SUBDISP_IsTownBlinking(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_SetTownCursor(IntrudeSubdispWork *work, int index);
void INTRUDE_SUBDISP_StartButtonBlink(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_UpdateButtonBlink(IntrudeSubdispWork *work);
int INTRUDE_SUBDISP_IsInfoActive(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_ClearInfoPanel(void);
void INTRUDE_SUBDISP_DrawInfoPanel(IntrudeSubdispWork *work, int mode);
int INTRUDE_SUBDISP_IsAlone(IntrudeSubdispWork *work);
struct EventCommMsgBox;
#include "event_comm_common.h"
#include "../arm9/game_event.h"
#include "../arm9/clact.h"
#include "../arm9/bmp_oam.h"
#include "../ov020/event_mapchange.h"

extern MmdlHeader d_02183AF0;
extern MmdlHeader g_02183AF0;
extern char str_02183B14[];
extern char str_02183B28[];
extern unsigned char d_021836B4[];
extern const struct BgTemplate d_0218370C;
extern const struct BgTemplate d_0218372C;
extern const IntrudeSubdispActorParam d_021836CC;
extern const IntrudeTownEntry d_02176AA0[];
extern const IntrudeSubdispActorParam d_021836E4;
extern const IntrudeSubdispActorParam d_021836DC;
extern const IntrudeSubdispActorParam d_021836D4;
extern const IntrudeSubdispActorParam d_021836EC;
extern const IntrudeSubdispActorParam d_021836C4;
extern const struct ActorInitParam d_021836AA;
extern const IntrudeSubdispBmpOamTmpl d_021836F4;
extern const s8 d_021836A4[3][2];
struct EventCommCommonWork;

/*
 * Initialises a 0x18-byte record (cleared by the fill below) and, when the
 * last argument is set, places its field object. The pool carries
 * 0x02183AF0 twice (stores, then call arguments), so two extern names:
 * see docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md.
 */
void INTRUDE_FIELD_InitMmdlCopyAnime(PlayerSpinWork *spinWork, void *gameSystem, void *fieldMap, void *intrudeWork, u16 id, u8 kind,
                   u8 flag, u16 idx, int place)
{
    void *sys;
    void *obj;
    int zone;
    int x;
    int y;

    MI_CpuFill8(spinWork, 0, sizeof(PlayerSpinWork));
    spinWork->gameSystem = gameSystem;
    spinWork->fieldMap = fieldMap;
    spinWork->objCode = id;
    spinWork->kind = kind;
    spinWork->flag = flag;
    spinWork->stepFrames = 15;
    spinWork->shownStep = spinWork->stepFrames;
    spinWork->copyIndex = idx;
    if (place != 0) {
        sys = GAME_DATA_GetOccupyInfo(GAMESYSTEM_GetGameData(gameSystem));
        obj = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
        zone = FIELDMAP_GetZoneId(fieldMap);
        d_02183AF0.objCode = FLDMMDL_GetObjCode(obj);
        d_02183AF0.dirHeader = idx;
        x = FLDMMDL_GetGridNowX(obj);
        y = FLDMMDL_GetGridNowZ(obj);
        FLDMMDL_InitPosRecord((&g_02183AF0), x, y, FLDMMDL_GetPosY(obj));
        spinWork->copyMmdl = FLDMMDL_AddMmdl((struct MmdlSys *)sys, (&g_02183AF0), zone);
        INTRUDE_FIELD_ChangePlayerLook(intrudeWork, spinWork->gameSystem, spinWork->objCode, spinWork->kind, spinWork->flag);
        FLDMMDL_SetStatusBitVanish(obj, 1);
        FLDMMDL_SetStatusBitVanish(spinWork->copyMmdl, 0);
    }
}

/*
 * Per-frame step of the 0x18-byte record (same layout as INTRUDE_FIELD_StepPlayerSpin's).
 */
int INTRUDE_FIELD_MainMmdlCopyAnime(PlayerSpinWork *spinWork)
{
    void *fld;
    void *obj;
    u16 anim;
    VecFx32 v;

    fld = FIELDMAP_GetFieldPlayer(spinWork->fieldMap);
    obj = FIELD_PLAYER_GetMmdl((void *)fld);
    switch (spinWork->state) {
    case 0:
        anim = spinWork->copyIndex == 3 ? 7 : 6;
        FLDMMDL_SetAcmd(obj, anim);
        if (spinWork->copyMmdl != 0)
            FLDMMDL_SetAcmd(spinWork->copyMmdl, anim);
        FIELD_PLAYER_GetPos(fld, &v);
        if (spinWork->copyIndex == 3)
            v.x += 0x8000;
        else
            v.x -= 0x8000;
        FIELD_GIMMICK_GAUGE_EFFECT_StartEffectAt(spinWork->fieldMap, &v);
        GFL_USE_PlaySeDefaultVolume(0x774);
        spinWork->state++;
        break;
    case 1:
        spinWork->stepFrames--;
        if (spinWork->stepFrames <= 0) {
            if (spinWork->copyMmdl != 0) {
                FLDMMDL_SetStatusBitVanish(obj, 0);
                FLDMMDL_SetStatusBitVanish(spinWork->copyMmdl, 1);
            }
            spinWork->state++;
        }
        break;
    case 2:
        if (FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive(spinWork->fieldMap) == 0 && FLDMMDL_CheckEndAcmd(obj) == 1) {
            FLDMMDL_EndAcmd(obj);
            if (spinWork->copyMmdl != 0)
                FLDMMDL_EndAcmd(spinWork->copyMmdl);
            spinWork->state++;
        }
        break;
    case 3:
        if (spinWork->copyMmdl != 0) {
            FLDMMDL_DeleteMmdl((struct Mmdl *)spinWork->copyMmdl);
            spinWork->copyMmdl = 0;
        }
        return 1;
    }
    return 0;
}

int INTRUDE_SUBDISP_MainRequestAnswerSeq(IntrudeCommSys *sys, EventCommCommonWork *work, u8 *state)
{
    switch (*state) {
    case 0:
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, 0);
        (*state)++;
        break;
    case 1:
        if (INTRUDE_COMM_SendRequest(sys, sys->requestTarget, &work->member, work->talkType) == 1)
            (*state)++;
        break;
    case 2:
        switch (INTRUDE_COMM_TakeRequestResult(sys)) {
        case 1:
            *state = 6;
            break;
        case 2:
        case 3:
            *state = 3;
            break;
        default:
            if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
                if ((KEY_GetTrg() & 2) && INTRUDE_COMM_SendAnswer(sys->requestTarget, sys->sentRequestSeq) == 1) {
                    INTRUDE_COMM_NextRequestToken(sys);
                    *state = 9;
                }
            }
            break;
        }
        break;
    case 3:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&work->msgBox, 2);
            (*state)++;
        }
        break;
    case 4:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1)
            (*state)++;
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1)
            *state = 8;
        break;
    case 6:
        if (INTRUDE_COMM_SendReply(sys, sys->requestTarget, 1, sys->sentRequestSeq) == 1)
            *state = 7;
        break;
    case 7:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1)
            return 1;
        break;
    case 8:
        return 2;
    case 9:
        return 3;
    }
    return 0;
}

struct GameEvent *INTRUDE_SUBDISP_CreatePalaceWarpEvent(void *gameSystem)
{
    VecFx32 v;
    INTRUDE_FIELD_GetZoneAnchor(0x117, &v);
    return EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(gameSystem, 0x117, (&v));
}

struct GameEvent *INTRUDE_SUBDISP_CreateReturnPalaceEvent(struct GameSystem *gameSystem)
{
    void *gameComm;
    void *gameData;
    IntrudeCommSys *sys;

    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (sys != 0) {
        INTRUDE_COMM_SetIntrudeId(sys, GAME_DATA_GetOwnNetId(gameData));
    } else {
        GAME_DATA_SetIntrudeId(gameData, GAME_DATA_GetOwnNetId(gameData));
    }
    return INTRUDE_SUBDISP_CreatePalaceWarpEvent(gameSystem);
}

struct GameEvent *INTRUDE_SUBDISP_CreateDisconnectEvent(void *gameSystem, int cause)
{
    void *sys;
    struct GameEvent *ret;
    IntrudeDisconnectWork *work;
    unsigned char *x;

    sys = (void *)GAMESYSTEM_GetGameComm(gameSystem);
    ret = GAME_EVENT_Create(gameSystem, 0, INTRUDE_SUBDISP_DisconnectEventMain, sizeof(IntrudeDisconnectWork));
    work = GAME_EVENT_GetWork((void *)ret);
    work->cause = cause;
    if (GAME_COMM_GetKind(sys) == 2) {
        x = (unsigned char *)GAME_COMM_GetWork(sys);
        if (x != 0) {
            INTRUDE_FIELD_SetSingleAreaMode((struct IntrudeCommSys *)GAME_COMM_GetWork(sys));
            x[0x8F8] |= 0x80;
        }
    }
    if (GAMESYSTEM_IsNetOffBySleep(gameSystem) == 1) {
        if (GAME_COMM_GetLastKind(sys) == 1) {
            work->alone = 1;
        }
    }
    GFL_USE_PlaySeDefaultVolume(0x737);
    return ret;
}

int INTRUDE_SUBDISP_DisconnectEventMain(struct GameEvent *event, int *seq, void *workPtr)
{
    IntrudeDisconnectWork *work = workPtr;
    void *x;
    void *s2;
    void *s1;
    void *y;
    void *z;
    void *t;
    int flag;
    int msg;
    int v;
    int r;

    x = GAME_EVENT_GetGameSystem(event);
    s2 = GAMESYSTEM_GetGameData(x);
    s1 = (void *)GAMESYSTEM_GetGameComm(x);
    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, INTRUDE_SUBDISP_CreateReturnPalaceEvent(x));
        (*seq)++;
        break;
    case 1:
        if (GFL_NET_ERR_GetErrorLevel() == 0 && (int)GAME_COMM_IsTransition(s1) != 0) {
            break;
        }
        if (GFL_NET_ERR_GetErrorLevel() == 0 && ((int)GAME_COMM_GetKind(s1) == 2 || (int)GAME_COMM_GetKind(s1) == 1)) {
            GAME_COMM_RequestExitNoCallback(s1);
        }
        (*seq)++;
        break;
    case 2:
        if (GFL_NET_ERR_GetErrorLevel() == 0 && (int)GAME_COMM_GetKind(s1) != 0) {
            break;
        }
        if (work->alone == 1) {
            *seq = 7;
        } else {
            (*seq)++;
        }
        break;
    case 3:
        if (GAMESYSTEM_IsFieldMapActive(x) != 1) {
            break;
        }
        flag = 0;
        y = GAMESYSTEM_GetFieldMap(x);
        if (FIELDMAP_IsReady(y) != 1) {
            break;
        }
        z = (void *)FIELDMAP_GetMsgBg(y);
        work->msgData = t = (void *)FIELD_MSGBG_CreateMsgData((struct FieldMsgBg *)z, 0x2D);
        work->msgBox = FIELD_MSGBG_CreateBottomSysWin(z, (struct MsgBank *)t);
        switch (work->cause) {
        case 1:
        case 2:
            msg = 0x5C;
            goto set;
        default:
            msg = 0x59;
        set:
            flag = 1;
            break;
        case 0:
            switch ((int)GAME_COMM_GetCounter(s1)) {
            case 1:
                msg = 0x5A;
                break;
            case 2:
                msg = 0x56;
                break;
            case 3:
                msg = 0x57;
                flag = 1;
                break;
            case 4:
                msg = 0x58;
                flag = 1;
                break;
            case 0:
            case 5:
            default:
                msg = 0x59;
                break;
            }
            break;
        }
        FIELD_MSGBG_SysWinPrintMsg(work->msgBox, (int)0, (int)0, (int)msg);
        if (flag == 1) {
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushAndPlayTask(x, 0x52D));
            *seq = 4;
        } else {
            *seq = 5;
        }
        break;
    case 4:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(x, 0, 6));
            *seq = 5;
        }
        break;
    case 5:
        if ((int)FIELD_MSGBG_SysWinMain(work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (KEY_GetTrg() & 0xF3) {
            FIELD_MSGBG_DeleteSysWin((struct FieldSysWin *)work->msgBox);
            MSGDATA_Delete(work->msgData);
            (*seq)++;
        }
        break;
    case 7:
        y = GAMESYSTEM_GetFieldMap(x);
        if (FIELDMAP_IsReady(y) == 1) {
            if (FIELD_PLAYER_CheckFormModel(FIELDMAP_GetFieldPlayer(y)) == 0) {
                INTRUDE_FIELD_InitPlayerSpin(&work->copyRecord, x, y, 0, 0, 0);
                (*seq)++;
            } else {
                *seq = 10;
            }
        }
        break;
    case 8:
        if (INTRUDE_FIELD_StepPlayerSpin(&work->copyRecord, 0) == 1) {
            if (work->alone == 1) {
                *seq = 10;
            } else {
                (*seq)++;
            }
        }
        break;
    case 9:
        if ((int)ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(s2), 0x980) == 0) {
            r = (int)GAME_COMM_GetCounter(s1);
            v = 0;
            switch (r) {
            case 0:
            case 1:
                break;
            case 2:
                v = 0xC;
                break;
            case 3:
            case 4:
                v = 0xD;
                break;
            case 5:
                break;
            }
            SCRIPT_SYS_CallScriptEvent(event, (u16)v, 0, 0, (int)0x8015);
        }
        *seq = 10;
        break;
    case 10:
        if ((GAME_DATA_GetOwnNetId(s2) != 0 || (int)GAMESYSTEM_IsNetOffBySleep(x) == 1) && GAMESYSTEM_GetFieldMapState(x) == 1) {
            GAME_EVENT_CallEvent(event, (void *)EVENT_COMM_ERROR_Create(x, GAMESYSTEM_GetFieldMap(x)));
        }
        (*seq)++;
        break;
    case 11:
        GAME_COMM_ClearCounter(s1);
        GAME_COMM_ClearPlayerStatus(s1);
        if (GAME_DATA_GetOwnNetId(s2) != 0 || (int)GAMESYSTEM_IsNetOffBySleep(x) == 1) {
            GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateIntrudeReturnEvent(x));
        }
        (*seq)++;
        break;
    case 12:
        return 1;
    }
    return 0;
}

struct GameEvent *INTRUDE_SUBDISP_CreateGuideScriptEvent(void *gameSystem)
{
    return GAME_EVENT_Create(gameSystem, 0, INTRUDE_SUBDISP_GuideScriptEventMain, 0);
}

int INTRUDE_SUBDISP_GuideScriptEventMain(struct GameEvent *event, int *state, void *eventWork)
{
    switch (*state) {
    case 0:
        SCRIPT_SYS_CallScriptEvent(event, 0x279e, 0, 0, 0x15);
        ++*state;
        break;
    case 1:
        return 1;
    }
    return 0;
}

struct GameEvent *INTRUDE_SUBDISP_CreateTownWarpEvent(void *gameSystem, void *fieldMap, u16 zoneId, int mode)
{
    void *gameComm;
    void *c;
    VecFx32 v;

    gameComm = (void *)GAMESYSTEM_GetGameComm(gameSystem);
    c = GAMESYSTEM_GetGameData((void *)gameSystem);
    INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (INTRUDE_FIELD_GetZoneAnchor(zoneId, &v) == 0)
        return 0;
    if (GAME_DATA_GetIntrudeCount(c) == 0 && zoneId == 0x117)
        return EVENT_MAPCHANGE_CreateIntrudeWarpEvent(gameSystem, zoneId, &v, mode);
    return EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(gameSystem, zoneId, &v);
}

struct GameEvent *INTRUDE_SUBDISP_CreatePlayerWarpEvent(void *gameSystem, void *fieldMap, int netId)
{
    IntrudeCommSys *sys;
    IntrudeZonePos *q;
    VecFx32 v;
    u16 s;

    sys = INTRUDE_COMM_GetWorkIfRunning((void *)GAMESYSTEM_GetGameComm(gameSystem));
    if (sys == 0 || !(sys->peerMask & (1 << netId)))
        return 0;
    q = INTRUDE_FIELD_FindZonePos(sys->peers[netId].zoneId);
    if (q == 0)
        return 0;
    s = q->townId;
    v = *(VecFx32 *)&sys->peers[netId].package.pos;
    v.z += 0x20000;
    return EVENT_MAPCHANGE_CreateWarpEvent(gameSystem, fieldMap, s, &v, 0, 0);
}

struct GameEvent *INTRUDE_SUBDISP_CreateBrightFadeEvent(void *gameSystem, struct FieldMap *fieldMap, struct FieldSubscreen *subscreen)
{
    void *task;
    IntrudeBrightFadeWork *work;
    task = GAME_EVENT_Create(gameSystem, 0, INTRUDE_SUBDISP_BrightFadeEventMain, sizeof(IntrudeBrightFadeWork));
    work = GAME_EVENT_GetWork(task);
    work->fieldMap = fieldMap;
    work->subscreen = subscreen;
    return task;
}

int INTRUDE_SUBDISP_BrightFadeEventMain(struct GameEvent *event, int *state, void *workPtr)
{
    IntrudeBrightFadeWork *work = workPtr;
    switch (*state) {
    case 0:
        work->frame += 1;
        if (work->frame > 15) {
            FLD_VREQ_SetSubMasterBrightness(FIELDMAP_GetVReq((struct FieldMap *)work->fieldMap), -16);
            *state += 1;
        }
        break;
    case 1:
        FIELD_SUBSCREEN_ChangeModeNow(work->subscreen, 0);
        *state += 1;
        break;
    case 2:
        FLD_VREQ_SetSubMasterBrightness(FIELDMAP_GetVReq((struct FieldMap *)work->fieldMap), 0);
        *state += 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}

int INTRUDE_SUBDISP_ScriptAddAreaMmdls(void *unused, void *scriptWork)
{
    void *sys;
    void *obj;
    sys = SCRCMD_WORK_GetGameSystem(scriptWork);
    obj = GAMESYSTEM_GetFieldMap(sys);
    GAMESYSTEM_GetGameComm(sys);
    INTRUDE_FIELD_AddAreaMmdls((struct FieldMap *)obj);
    return 0;
}

int INTRUDE_SUBDISP_ScriptAddAreaMapsAndMarkers(void *unused, void *scriptWork)
{
    void *w;
    void *c;
    void *h;
    void *v;

    w = SCRCMD_WORK_GetGameSystem(scriptWork);
    GAMESYSTEM_GetGameData(w);
    c = GAMESYSTEM_GetFieldMap(w);
    h = GAMESYSTEM_GetGameComm(w);
    v = 0;
    if (GAME_COMM_GetKind(h) == 2)
        v = GAME_COMM_GetWork(h);
    if (v != 0) {
        INTRUDE_FIELD_ResetExtraAreaCount(c, w, (struct IntrudeCommSys *)v);
        INTRUDE_FIELD_AddAreaMaps((struct FieldMap *)c, (struct GameSystem *)w, (struct IntrudeCommSys *)v);
    } else {
        INTRUDE_FIELD_AddAreaMapCount((struct FieldMap *)c, 1);
    }
    INTRUDE_FIELD_AddMarkerMmdls(c);
    return 0;
}

IntrudeSubdispWork *INTRUDE_SUBDISP_Init(void *gameSystem)
{
    void *gameComm;
    IntrudeSubdispWork *work;
    IntrudeCommSys *sys;
    void *bg;
    int i;
    u16 zoneId;
    void *target;
    u32 tmp;

    gameComm = (void *)GAMESYSTEM_GetGameComm(gameSystem);
    work = GFL_HEAP_Alloc(0x70, sizeof(IntrudeSubdispWork), 1, (char *)str_02183B14, 0x240);
    work->gameSystem = gameSystem;
    work->lastBgPalette = 0xFF;
    work->cursorActor = 0xFF;
    work->pendingPeer = 4;
    work->lastPeer = 4;
    work->digitsValue = -1;
    for (i = 0; i < 3; i++) {
        work->peerTowns[i].zoneId = 0x1AB;
    }
    sys = 0;
    if (GAME_COMM_GetKind(gameComm) == 2) {
        sys = (IntrudeCommSys *)GAME_COMM_GetWork(gameComm);
    }
    if (sys != 0 && sys->flagBit7 == 1) {
        sys = 0;
    }
    INTRUDE_SUBDISP_InitTownState(work, sys);
    work->lastPeerCount = work->town.peerCount;
    bg = ARC_TOOL_CreateHandle(0x24, 0x15);
    INTRUDE_SUBDISP_SystemSetup(work);
    INTRUDE_SUBDISP_BgSetup(work, bg);
    INTRUDE_SUBDISP_BmpWinSetup(work);
    INTRUDE_SUBDISP_ClactResourceLoad(work, bg);
    INTRUDE_SUBDISP_ClactActorCreate(work, bg);
    ARC_TOOL_DeleteHandle(bg);
    GFL_NET_RefreshWmIconAtTopRight(0, 0x15);
    GFL_NET_WM_ICON_EasyObjWindowOn();
    REG_WINOUT_SUB = (u16)((REG_WINOUT_SUB & ~0x3F00) | (0x1F << 8));
    tmp = (REG_WINOUT_SUB & ~0x3F) | 0x1F;
    tmp |= 0x20;
    REG_WINOUT_SUB = (u16)tmp;
    REG_DB_DISPCNT_SUB = (REG_DB_DISPCNT_SUB & ~0xE000) | 0x8000;
    work->vblankTask = (struct TcbTask *)GFL_USE_AddMainTask(INTRUDE_SUBDISP_VBlankTask, work, 10);
    zoneId = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(work->gameSystem));
    target = INTRUDE_SUBDISP_GetTargetPlayerData(work);
    INTRUDE_SUBDISP_PrintTitle(work, zoneId);
    INTRUDE_SUBDISP_UpdateTownActors(work, target);
    INTRUDE_SUBDISP_UpdatePlayerMarkActors(work, target);
    INTRUDE_SUBDISP_UpdatePlayerTownActors(work, INTRUDE_COMM_GetWorkIfRunning(gameComm), target);
    INTRUDE_SUBDISP_UpdateMyPlayerActor(work, target, zoneId);
    INTRUDE_SUBDISP_UpdateButtonActors(work, target);
    INTRUDE_SUBDISP_UpdateInfoIcon(work, target);
    return work;
}

void INTRUDE_SUBDISP_Exit(IntrudeSubdispWork *work)
{
    TCB_DeleteTask(work->vblankTask);
    MIi_CpuClear16(0, HW_DB_BG_PLTT, 2);
    INTRUDE_SUBDISP_DeleteButtonBmpOam(work);
    INTRUDE_SUBDISP_ClactActorDelete(work);
    INTRUDE_SUBDISP_ClactResourceUnload(work);
    INTRUDE_SUBDISP_BmpWinExit(work);
    INTRUDE_SUBDISP_BgExit(work);
    INTRUDE_SUBDISP_SystemExit(work);
    GFL_HEAP_Free(work);
    GFL_NET_WM_ICON_EasyObjWindowOff();
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
}

void INTRUDE_SUBDISP_Update(IntrudeSubdispWork *work, int mode)
{
    void *gameComm;
    void *gameData;
    IntrudeCommSys *sys;
    int zoneId;
    int i;
    int v;
    void *printQue;

    gameComm = (void *)GAMESYSTEM_GetGameComm(work->gameSystem);
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    zoneId = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(work->gameSystem));
    WIH_DWC_PollStatus((void *)GAME_DATA_GetWifiList(gameData));
    GFL_NET_WM_ICON_EasyObjWindowOn();
    if (sys == 0 || (sys != 0 && sys->flagBit7 == 0)) {
        INTRUDE_SUBDISP_UpdateTownState(work, sys);
    }
    if (work->lastPeerCount < work->town.peerCount) {
        if (GAME_DATA_GetIntrudeCount(gameData) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x699);
        }
        work->lastPeerCount = work->town.peerCount;
    }
    TCBL_Main((struct TcblSystem *)work->tcbl);
    PRINTSYS_QUE_Main((struct PrintQueue *)work->printQue);
    printQue = work->printQue;
    if (work->titlePending != 0) {
        if (PRINTSYS_QUE_IsExistTarget(printQue, BMP_WIN_GetBmp(work->titleWin)) == 0) {
            BMP_WIN_TransferChars(work->titleWin);
            work->titlePending = 0;
        }
    }
    printQue = work->printQue;
    if (work->infoPending != 0) {
        if (PRINTSYS_QUE_IsExistTarget(printQue, BMP_WIN_GetBmp(work->infoWin)) == 0) {
            BMP_WIN_TransferChars(work->infoWin);
            work->infoPending = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)work->printQue, work->buttonBitmaps[i]) == 0) {
            BMP_OAM_UploadChars(work->buttonOams[i]);
        }
    }
    if (mode == 0) {
        if (INTRUDE_SUBDISP_IsTownBlinking(work) == 1 || work->buttonBlinkActive == 1) {
            REG_DB_BLDCNT_SUB = 0;
        } else {
            G2x_SetBlendBrightness_((uptr)(&REG_DB_BLDCNT_SUB), 0x3F, -8);
            return;
        }
    } else {
        REG_DB_BLDCNT_SUB = 0;
    }
    if (mode == 1) {
        INTRUDE_SUBDISP_UpdateTouch(sys, work, zoneId);
    }
    if (sys != 0 && work->warpPending == 1) {
        v = GAME_DATA_GetIntrudeIdByte(gameData);
        if ((int)GFL_NET_IsConnectMember((u8)v) == 0) {
            work->warpPending = 0;
            return;
        }
        switch (work->warpStep) {
        case 0:
            if (INTRUDE_COMM_SendUnionInfoRequest(sys, (u8)v) == 1) {
                work->warpStep++;
            }
            break;
        case 1:
            if (INTRUDE_COMM_GetUnionInfoReceived(sys) == 1) {
                FIELDMAP_GetSubscreen(GAMESYSTEM_GetFieldMap(work->gameSystem));
                work->targetZone = 0x126;
                work->selectionKind = 1;
                work->warpPending = 0;
            }
            break;
        default:
            GF_PANIC_Fail((char *)str_02183B28, 0, (char *)str_02183B28);
            break;
        }
    }
}

void INTRUDE_SUBDISP_Draw(IntrudeSubdispWork *work)
{
    void *gameComm;
    void *gameData;
    IntrudeCommSys *sys;
    u16 zoneId;
    int flag;
    void *target;

    gameComm = (void *)GAMESYSTEM_GetGameComm(work->gameSystem);
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    zoneId = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(work->gameSystem));
    flag = 0;
    target = INTRUDE_SUBDISP_GetTargetPlayerData(work);
    if (sys != 0 && INTRUDE_COMM_HasResult(&sys->session) == 0) {
        flag = 1;
    } else if (sys == 0 && GAME_DATA_GetIntrudeCount(gameData) == 1 && GAME_COMM_GetKind(gameComm) != 2
               && GAME_COMM_GetCounter(gameComm) == 0 && ZONEDATA_IsEntralink(zoneId) == 1) {
        flag = 1;
    }
    if (sys != 0 && sys->flagBit7 == 1) {
        flag = 0;
    }
    if (flag == 1) {
        INTRUDE_SUBDISP_ReloadBgScreens(work);
        INTRUDE_SUBDISP_UpdateBgPalette(work, sys);
        INTRUDE_SUBDISP_PrintTitle(work, zoneId);
        INTRUDE_SUBDISP_PrintInfoMessage(work, sys, zoneId);
        INTRUDE_SUBDISP_UpdateTownActors(work, target);
        INTRUDE_SUBDISP_UpdatePlayerMarkActors(work, target);
        INTRUDE_SUBDISP_UpdatePlayerTownActors(work, sys, target);
        INTRUDE_SUBDISP_UpdateMyPlayerActor(work, target, zoneId);
        INTRUDE_SUBDISP_UpdateButtonActors(work, target);
        INTRUDE_SUBDISP_UpdateInfoIcon(work, target);
        INTRUDE_SUBDISP_UpdateButtonBlink(work);
        return;
    }
    if (sys != 0 && INTRUDE_COMM_HasResult(&sys->session) == 1 && INTRUDE_COMM_IsSessionAccepted(&sys->session) == 1
        && work->infoShown == 0 && work->town.number == 0) {
        INTRUDE_SUBDISP_UpdateInfoIcon(work, target);
        work->infoShown = 1;
    }
}

struct GameEvent *INTRUDE_SUBDISP_EventCheck(IntrudeSubdispWork *work, int touched, struct FieldSubscreen *param)
{
    void *gameComm;
    void *gameData;
    void *fieldMap;
    struct GameEvent *event;

    gameComm = (void *)GAMESYSTEM_GetGameComm(work->gameSystem);
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(work->gameSystem);
    event = 0;
    if (touched == 0 || fieldMap == 0) {
        return 0;
    }
    if (work->noIntrude == 1 || (GAME_DATA_GetIntrudeCount(gameData) == 0 && INTRUDE_COMM_GetWorkIfRunning(gameComm) == 0)) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        INTRUDE_SUBDISP_StartButtonBlink(work);
        return INTRUDE_SUBDISP_CreateBrightFadeEvent(work->gameSystem, fieldMap, param);
    }
    switch (work->selectionKind) {
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x737);
        INTRUDE_SUBDISP_StartTownBlink(work);
        event = INTRUDE_SUBDISP_CreateTownWarpEvent(work->gameSystem, fieldMap, work->targetZone, 0);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x737);
        event = INTRUDE_SUBDISP_CreatePlayerWarpEvent(work->gameSystem, fieldMap, INTRUDE_COMM_GetPlayerNetId(gameComm));
        break;
    }
    if (event != 0) {
        work->selectionKind = 0;
        return event;
    }
    return 0;
}

void INTRUDE_SUBDISP_VBlankTask(struct TcbTask *tcb, void *taskWork)
{
    IntrudeSubdispWork *work = taskWork;

    work->vblankPhase ^= 1;
    if (work->vblankPhase != 0) {
        if (work->paletteDirty != 0) {
            DC_FlushRange(work->palOut, 8);
            GXS_LoadOBJPltt(work->palOut, 0x102, 8);
            work->paletteDirty = 0;
        }
        if (work->digitsDirty != 0) {
            DC_FlushRange(work->numberBuf, 0x200);
            GXS_LoadOBJ(work->numberBuf, work->numberVram, 0x200);
            work->digitsDirty = 0;
        }
    }
}

void INTRUDE_SUBDISP_SystemSetup(IntrudeSubdispWork *work)
{
    struct ClactRenderer *renderer;

    work->clactUnit = CLACT_CreateUnit(0x29, 5, 0x70);
    renderer = (struct ClactRenderer *)CLACT_CreateRenderer((struct SurfaceInit *)d_021836B4, 1, 0x70);
    work->renderer = renderer;
    CLACT_SetUnitRenderer(work->clactUnit, renderer);
    work->bmpOamSys = BMP_OAM_CreateSys(0x70, work->clactUnit);
    work->tcbl = (struct Tcbl *)TCBL_Create(0x70, 0x70, 4, 0x20);
    work->font = GF_FONT_Create(0x17, 0, 0, 0, 0x70);
    work->wordSet = WORDSET_CreateDefault(0x70);
    work->printQue = (struct PrintQue *)PRINTSYS_QUE_Create(0x70);
    work->msgData = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, 0x2D, 0x70);
    work->msgDataDetail = (struct MsgBank *)MSGDATA_CreateFromArchive(0, 2, 0x42, 0x70);
    work->strbufMsg = STRBUF_Create(0x80, 0x70);
    work->strbufText = STRBUF_Create(0x80, 0x70);
    work->strbufTitle = STRBUF_Create(0x80, 0x70);
}

void INTRUDE_SUBDISP_SystemExit(IntrudeSubdispWork *work)
{
    STRBUF_Delete(work->strbufMsg);
    STRBUF_Delete(work->strbufText);
    STRBUF_Delete(work->strbufTitle);
    MSGDATA_Delete((struct MsgBank *)work->msgData);
    MSGDATA_Delete((struct MsgBank *)work->msgDataDetail);
    PRINTSYS_QUE_Clear((struct PrintQueue *)work->printQue);
    PRINTSYS_QUE_Delete((struct PrintQueue *)work->printQue);
    WORDSET_Delete(work->wordSet);
    GF_FONT_Delete(work->font);
    TCBL_Destroy((struct TcblSystem *)work->tcbl);
    BMP_OAM_DeleteSys(work->bmpOamSys);
    CLACT_DeleteRenderer((struct Renderer *)work->renderer);
    CLACT_DeleteUnit(work->clactUnit);
}

void INTRUDE_SUBDISP_BgSetup(IntrudeSubdispWork *work, void *bg)
{
    int layer;
    u8 *pal;
    void *res;

    layer = 6;
    BG_SYS_InitBgLayer(6, &d_0218370C, 0);
    BG_SYS_InitBgLayer(7, &d_0218372C, 0);
    MIi_CpuClear32(0, (void *)HW_DB_BG_VRAM, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    G2x_SetBlendBrightness_((uptr)(&REG_DB_BLDCNT_SUB), 0x3F, -8);
    ARC_UTIL_UploadBgCharFromHandle(bg, 4, 7, 0, 0, 1, 0x15);
    ARC_UTIL_UploadBgPaletteFromHandle(bg, 5, 7, 0, 0x800, 1, 0x15);
    if (work->town.peerCount <= 1) {
        work->bgLayerVariant = 0;
    } else {
        layer = 7;
        work->bgLayerVariant = 1;
    }
    ARC_UTIL_UploadBgPaletteFromHandle(bg, layer, 6, 0, 0x800, 1, 0x15);
    INTRUDE_SUBDISP_SetBgPalette(work, work->town.homeSlot);
    res = ARC_UTIL_LoadPaletteDataFromHandle(bg, 8, 1, (void **)(&pal), 0x15);
    MIi_CpuCopy16(pal + 0xC, work->infoPalette, 0x30);
    GFL_HEAP_Free(res);
    if (INTRUDE_SUBDISP_IsInfoActive(work) == 1) {
        INTRUDE_SUBDISP_DrawInfoPanel(work, 0);
    }
    ARC_UTIL_UploadPaletteFromHandleWhole(bg, 9, 4, 0, 0x140, 0x15);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1C0, 0x20, 0x15);
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(5, 0);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_SetPlaneVisible(7, 1);
}

void INTRUDE_SUBDISP_BgExit(IntrudeSubdispWork *work)
{
    BG_SYS_SetPlaneVisible(6, 0);
    BG_SYS_SetPlaneVisible(7, 0);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
}

void INTRUDE_SUBDISP_BmpWinSetup(IntrudeSubdispWork *work)
{
    struct BmpWin *win;
    u8 zero;

    zero = 0;
    win = BMP_WIN_Create(6, 0, 0, 0x20, 2, 14, 1);
    work->titleWin = win;
    work->titlePending = zero;
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
    win = BMP_WIN_Create(6, 1, 0x12, 0x1e, 4, 14, 1);
    work->infoWin = win;
    work->infoPending = zero;
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(win));
}

void INTRUDE_SUBDISP_BmpWinExit(IntrudeSubdispWork *work)
{
    BMP_WIN_Delete(work->titleWin);
    BMP_WIN_Delete(work->infoWin);
}

void INTRUDE_SUBDISP_ClactResourceLoad(IntrudeSubdispWork *work, void *bg)
{
    void *bg2;

    work->palRes = CLACT_RegisterPaletteEx(bg, 3, 1, 0, 0, 9, 0x15);
    work->charRes = CLACT_RegisterCharacter(bg, 0, 1, 1, 0x15);
    work->cellRes = CLACT_RegisterCellAnim(bg, 1, 2, 0x70);
    bg2 = ARC_TOOL_CreateHandle(0x17, 0x15);
    work->bmpOamPalRes = CLACT_RegisterPaletteCompressed(bg2, 5, 1, 0x1a0, 0x15);
    ARC_TOOL_DeleteHandle(bg2);
    work->infoCharRes = CLACT_RegisterCharacter(bg, 10, 1, 1, 0x15);
    work->infoCellRes = CLACT_RegisterCellAnim(bg, 12, 13, 0x70);
    work->numberRes = ARC_UTIL_LoadBgCharDataFromHandle(bg, 10, 1, &work->numberGfx, 0x70);
    work->numberVram = CLACT_GetCharacterVramAddress((u32)work->infoCharRes, 2);
    work->numberBuf = GFL_HEAP_Alloc(0x70, 0x200, 1, (char *)str_02183B14, 0x495);
    MIi_CpuCopy16((void *)0x050006E2, work->palBase, 8);
    MIi_CpuCopy16(work->palBase, work->palOut, 8);
    MIi_CpuCopy16((void *)0x05000702, work->palTarget, 8);
}

void INTRUDE_SUBDISP_ClactResourceUnload(IntrudeSubdispWork *work)
{
    GFL_HEAP_Free(work->numberBuf);
    GFL_HEAP_Free(work->numberRes);
    CLACT_ReleasePalette((u32)work->bmpOamPalRes);
    CLACT_ReleasePalette((u32)work->palRes);
    CLACT_ReleaseCharacter((u32)work->charRes);
    CLACT_ReleaseCharacter((u32)work->infoCharRes);
    CLACT_ReleaseCellAnim((u32)work->cellRes);
    CLACT_ReleaseCellAnim((u32)work->infoCellRes);
}

/*
 * interface: r1 is visibly restored before every call; preserve incoming bg.
 * Callees' matched definitions omit this unused input; no callee edits.
 */
void INTRUDE_SUBDISP_ClactActorCreate(IntrudeSubdispWork *work, void *bg)
{
    INTRUDE_SUBDISP_CreateTownActors(work, bg);
    INTRUDE_SUBDISP_CreatePlayerMarkActors(work, bg);
    INTRUDE_SUBDISP_CreateTownMarkActors(work, bg);
    INTRUDE_SUBDISP_CreateMyPlayerActor(work, bg);
    INTRUDE_SUBDISP_CreatePlayerIconActors(work, bg);
    INTRUDE_SUBDISP_CreateInfoIconActor(work, bg);
    INTRUDE_SUBDISP_CreateButtonActors(work, bg);
}

void INTRUDE_SUBDISP_ClactActorDelete(IntrudeSubdispWork *work)
{
    int i;
    for (i = 0; i < INTRUDE_SUBDISP_ACTOR_COUNT; i++) CLACT_DeleteActor((struct ClactActor *)work->actors[i]);
}

void INTRUDE_SUBDISP_CreateTownActors(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    int i;

    param = d_021836CC;
    for (i = 0; i <= 7; i++) {
        param.x = d_02176AA0[i].x;
        param.y = d_02176AA0[i].y;
        work->actors[i] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[i], 0);
        CLACT_SetActorAutoAnim((struct ClactActor *)work->actors[i], 1);
    }
    param.anim_seq = 8;
    param.x = 0x80;
    param.y = 0x5c;
    work->actors[8] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[8], 0);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->actors[8], 1);
}

void INTRUDE_SUBDISP_CreatePlayerMarkActors(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    int i;

    param = d_021836E4;
    for (i = 9; i <= 11; i++) {
        work->actors[i] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
        CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[i], (u8)(i - 8), 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[i], 0);
    }
}

void INTRUDE_SUBDISP_CreateTownMarkActors(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    int i;

    param = d_021836DC;
    for (i = 12; i <= 14; i++) {
        work->actors[i] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
        CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[i], (u8)(i - 11), 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[i], 0);
        CLACT_SetActorAutoAnim((struct ClactActor *)work->actors[i], 1);
    }
}

void INTRUDE_SUBDISP_CreateMyPlayerActor(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    void *gameData;

    param = d_021836D4;
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    if (MYSTATUS_GetSex(GAME_DATA_GetMyStatus(gameData)) == 1) {
        param.anim_seq = 3;
    }
    work->actors[15] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
    CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[15], (u8)(GAME_DATA_GetOwnNetId(gameData) + 1), 1);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[15], 0);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->actors[15], 1);
}

void INTRUDE_SUBDISP_CreatePlayerIconActors(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    int i;

    param = d_021836EC;
    for (i = 17; i <= 19; i++) {
        work->actors[i] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
        CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[i], (u8)(i - 16), 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[i], 0);
    }
}

void INTRUDE_SUBDISP_CreateInfoIconActor(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    int infoActive;

    param = d_021836C4;
    infoActive = INTRUDE_SUBDISP_IsInfoActive(work);
    work->actors[20] = CLACT_CreateActor(work->clactUnit, work->infoCharRes, work->palRes, work->infoCellRes, &param, 0, 0x70);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[20], infoActive);
}

void INTRUDE_SUBDISP_CreateButtonActors(IntrudeSubdispWork *work, void *bg)
{
    void *gameData;
    int i;
    struct Strbuf *str;
    IntrudeSubdispBmpOamTmpl copy;
    IntrudeSubdispBmpOamTmpl tmpl;

    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    work->actors[16] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &d_021836AA, 0, 0x70);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[16], 0);
    tmpl = d_021836F4;
    for (i = 0; i < 2; i++) {
        copy = tmpl;
        work->buttonBitmaps[i] = BMP_Create(6, 2, 0x20, 0x70);
        copy.bmp = work->buttonBitmaps[i];
        copy.animResId = work->bmpOamPalRes;
        work->buttonOams[i] = BMP_OAM_Create(work->bmpOamSys, &copy);
        BMP_OAM_SetEnabled(work->buttonOams[i], 0);
        str = MSGDATA_AllocString((struct MsgBank *)work->msgData, i + 0x45);
        PRINTSYS_PrintQueColor((struct PrintQueue *)work->printQue, work->buttonBitmaps[i], 0, 0, str, work->font, 0x3c40);
        STRBUF_Delete(str);
    }
    if (work->noIntrude == 0 && GAME_DATA_GetIntrudeCount(gameData) == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[16], 1);
        BMP_OAM_SetEnabled(work->buttonOams[1], 1);
    }
}

void INTRUDE_SUBDISP_DeleteButtonBmpOam(IntrudeSubdispWork *work)
{
    int i;
    for (i = 0; i < 2; i++) {
        BMP_OAM_Delete(work->buttonOams[i]);
        BMP_Delete(work->buttonBitmaps[i]);
    }
}

void INTRUDE_SUBDISP_UpdateTownActors(IntrudeSubdispWork *work, void *target)
{
    void *gameData;
    int i;
    int anim;
    int index;
    struct ClactActor *actor;

    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    if (INTRUDE_SUBDISP_IsAlone(work) == 1) {
        for (i = 0; i <= 7; i++) {
            CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[i], 0);
        }
        CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[8], 0);
    } else if (work->town.homeSlot == GAME_DATA_GetOwnNetId(gameData) || GAME_DATA_GetIntrudeCount(gameData) == 0) {
        for (i = 0; i <= 7; i++) {
            CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[i], 0);
        }
        CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[8], 0);
    } else {
        for (i = 0; i <= 7; i++) {
            CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[i], 1);
        }
        CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[8], 1);
    }
    for (i = 6; i <= 8; i++) {
        MIi_CpuCopy16((void *)(HW_DB_OBJ_PLTT + 2 + (work->town.homeSlot + 1) * 32), (void *)(HW_DB_OBJ_PLTT + 0xC + i * 32), 2);
    }
    if (work->blinkActive == 1) {
        if (work->blinkCount % 2 == 0) {
            if (((unsigned)work->blinkCount >> 1) & 1) {
                anim = 6;
            } else {
                anim = 7;
            }
            index = work->selectedActor;
            if (index != 8) {
                actor = work->actors[index];
            } else {
                actor = work->actors[8];
            }
            CLACT_SetActorPaletteOffset((struct ClactActor *)actor, (u8)anim, (int)1);
        }
        if (work->blinkCount < 10) {
            work->blinkCount++;
        }
        return;
    }
    if (work->cursorActor == 0xff) {
        return;
    }
    if (work->cursorPulseDir == 0) {
        work->cursorPulse += 0x100;
        if (work->cursorPulse >= 0x1100) {
            work->cursorPulse = 0x2000 - work->cursorPulse;
            work->cursorPulseDir = 1;
        }
    } else {
        work->cursorPulse -= 0x100;
        if (work->cursorPulse < 0) {
            work->cursorPulse = 0x100 - work->cursorPulse;
            work->cursorPulseDir = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        PALANM_BlendColors(&work->palBase[i], &work->palOut[i], 1, work->cursorPulse >> 8, work->palTarget[i]);
    }
    work->paletteDirty = 1;
}

#pragma opt_propagation off

/*
 * final push 2026-10-05 G7L8: closed with opt_propagation off, a named slot
 * pointer `s` (declared first, assigned after the call, used for the three
 * zero stores and the first loop), n zeroed right before the first loop,
 * do-while loops (for loops gain entry guards under the pragma), an explicit
 * `if (n > 0)` guard on the second loop, and the mask test written as
 * `p[0xd9] & (1 << i)`.
 */
void INTRUDE_SUBDISP_UpdatePlayerMarkActors(IntrudeSubdispWork *work, void *target)
{
    u8 *s;
    struct ClactActor *actor;
    int cur;
    int sel;
    int max;
    int n;
    int i;
    int j;
    IntrudeSubdispMarkLayout layout;

    GAMESYSTEM_GetGameData(work->gameSystem);
    s = layout.slot;
    s[0] = 0;
    s[1] = 0;
    s[2] = 0;
    max = work->town.peerCount;
    cur = work->town.homeSlot;
    sel = 0;
    layout.pos.y = 0x1c;
    n = 0;
    i = 0;
    do {
        if (work->town.peerMask & (1 << i)) {
            s[n] = i;
            if (i == cur) {
                sel = n;
            }
            n++;
        }
        i++;
    } while (i < 3);
    j = 0;
    i = 0;
    if (n > 0) {
        do {
            if (sel != i) {
                if (layout.slot[i] == cur + 1 || (layout.slot[i] == 0 && cur == max - 1)) {
                    layout.pos.x = 0xa0;
                } else {
                    layout.pos.x = 0x60;
                }
                actor = work->actors[9 + j];
                CLACT_AddActorSurfacePos(actor, &layout.pos, 0);
                CLACT_SetActorPaletteOffset((struct ClactActor *)actor, (u8)(layout.slot[i] + 1), 1);
                CLACT_SetActorDrawEnable((struct ClactActor *)actor, 1);
                j++;
            }
            i++;
        } while (i < n);
    }
    for (; i < 3; i++) {
        CLACT_SetActorDrawEnable((struct ClactActor *)(work->actors[9 + i]), 0);
    }
}

#pragma opt_propagation reset

void INTRUDE_SUBDISP_UpdatePlayerTownActors(IntrudeSubdispWork *work, IntrudeCommSys *sys, void *target)
{
    void *gameData;
    int cur;
    int i;
    int k;
    struct ClactActor *mark;
    IntrudePeer *peer;
    IntrudeZonePos *prev;
    u16 prevZone;
    IntrudeZonePos *town;
    struct ClactActor *icon;
    IntrudeSubdispPosPair pair;

    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    cur = work->town.homeSlot;
    INTRUDE_SUBDISP_UpdateTownMarkPalette(work);
    for (i = 0; i < 3; i++) {
        town = 0;
        prev = work->peerTowns[i].town;
        prevZone = work->peerTowns[i].zoneId;
        if (i != GAME_DATA_GetOwnNetId(gameData)) {
            work->peerTowns[i].town = 0;
            work->peerTowns[i].zoneId = 0x1ab;
        }
        mark = work->actors[12 + i];
        icon = work->actors[17 + i];
        if (i == GAME_DATA_GetOwnNetId(gameData)) {
            CLACT_SetActorDrawEnable((struct ClactActor *)mark, 0);
            CLACT_SetActorDrawEnable((struct ClactActor *)icon, 0);
            continue;
        }
        if (sys == 0) {
            CLACT_SetActorDrawEnable((struct ClactActor *)mark, 0);
            CLACT_SetActorDrawEnable((struct ClactActor *)icon, 0);
            continue;
        }
        if (work->town.peerMask & (1 << i)) {
            peer = &sys->peers[i];
        } else {
            CLACT_SetActorDrawEnable((struct ClactActor *)mark, 0);
            CLACT_SetActorDrawEnable((struct ClactActor *)icon, 0);
            continue;
        }
        if (peer->state == 2) {
            CLACT_SetActorAutoAnimSpeed((struct ClactActor *)mark, 0x2000);
        } else {
            CLACT_SetActorAutoAnimSpeed((struct ClactActor *)mark, 0x1000);
        }
        if (peer->intrudeId == cur) {
            if (ZONEDATA_IsEntralink(peer->zoneId) == 1) {
                pair.pos.x = d_021836A4[i][0] + 0x80;
                pair.pos.y = d_021836A4[i][1] + 0x4c;
                CLACT_SetActorDrawEnable((struct ClactActor *)icon, 0);
            } else {
                if (peer->zoneId != prevZone) {
                    town = INTRUDE_FIELD_FindZonePos(peer->zoneId);
                } else {
                    town = prev;
                }
                if (town != 0) {
                    pair.pos.x = town->x + d_021836A4[i][0];
                    pair.pos.y = town->y + d_021836A4[i][1];
                    CLACT_SetActorDrawEnable((struct ClactActor *)icon, 0);
                } else {
                    pair.pos.x = 0xe8;
                    pair.pos.y = i * 0x18 + 0x50;
                    pair.marker = pair.pos;
                    pair.marker.x = 0xf0;
                    CLACT_AddActorSurfacePos(icon, &pair.marker, 0);
                    CLACT_SetActorDrawEnable((struct ClactActor *)icon, 1);
                }
            }
            CLACT_AddActorSurfacePos(mark, &pair.pos, 0);
            work->peerTowns[i].town = town;
            work->peerTowns[i].zoneId = peer->zoneId;
        } else {
            CLACT_SetActorDrawEnable((struct ClactActor *)icon, 0);
            for (k = 0; k < 3; k++) {
                if (CLACT_GetActorPaletteOffset((struct ClactActor *)(work->actors[9 + k])) == i + 1) {
                    CLACT_GetActorSurfacePos(work->actors[9 + k], &pair.pos, 0);
                    break;
                }
            }
            if (k == 3) {
                CLACT_SetActorDrawEnable((struct ClactActor *)mark, 0);
                continue;
            }
            pair.pos.x += d_021836A4[i][0];
            pair.pos.y += d_021836A4[i][1];
            CLACT_AddActorSurfacePos(mark, &pair.pos, 0);
        }
        CLACT_SetActorDrawEnable((struct ClactActor *)mark, 1);
    }
}

void INTRUDE_SUBDISP_UpdateTownMarkPalette(IntrudeSubdispWork *work)
{
    int sel;
    int v;
    int anim;
    u16 buf[16];

    if (work->town.sessionState == 3 && work->town.selection != 0) {
        sel = work->town.selection->peerIndex;
        anim = -1;
        v = work->lastPeer;
        if (v != 4 && v != sel) {
            CLACT_SetActorPaletteOffset((struct ClactActor *)(work->actors[v + 12]), (u8)(v + 1), (int)1);
        }
        if (work->lastPeer != sel) {
            MIi_CpuCopy16((void *)(HW_DB_OBJ_PLTT + (sel + 1) * 32), buf, 0x20);
            PALANM_BlendColors(buf, buf, 0x10, 8, 0x7fff);
            MIi_CpuCopy16(buf, (void *)0x05000720, 0x20);
            work->lastPeer = sel;
        }
        work->peerBlinkCount++;
        if (work->peerBlinkCount == 15) {
            anim = 9;
        } else if (work->peerBlinkCount >= 30) {
            anim = sel + 1;
            work->peerBlinkCount = 0;
        }
        if (anim != -1) {
            CLACT_SetActorPaletteOffset((struct ClactActor *)(work->actors[sel + 12]), (u8)anim, (int)1);
        }
        return;
    }
    v = work->lastPeer;
    if (v != 4) {
        CLACT_SetActorPaletteOffset((struct ClactActor *)(work->actors[v + 12]), (u8)(v + 1), (int)1);
        work->lastPeer = 4;
        work->peerBlinkCount = 0;
    }
}

void INTRUDE_SUBDISP_UpdateMyPlayerActor(IntrudeSubdispWork *work, void *target, u16 zoneId)
{
    IntrudeSubdispPos pos;
    int sel;
    int idx;
    IntrudeZonePos *town;
    int i;
    int v;
    struct ClactActor *actor;

    idx = GAME_DATA_GetOwnNetId(GAMESYSTEM_GetGameData(work->gameSystem));
    sel = 0xFF;
    if (ZONEDATA_IsEntralink(zoneId) == 1) {
        pos.x = d_021836A4[idx][0] + 0x80;
        pos.y = d_021836A4[idx][1] + 0x4C;
        sel = 8;
        work->peerTowns[idx].town = 0;
    } else {
        if (zoneId != work->peerTowns[idx].zoneId) {
            town = INTRUDE_FIELD_FindZonePos(zoneId);
        } else {
            town = work->peerTowns[idx].town;
        }
        work->peerTowns[idx].town = town;
        work->peerTowns[idx].zoneId = zoneId;
        if (town != 0) {
            pos.x = town->x + d_021836A4[idx][0];
            pos.y = town->y + d_021836A4[idx][1];
            v = town->zoneId;
            for (i = 0; i < 8; i++) {
                if (v == d_02176AA0[i].zoneA || v == d_02176AA0[i].zoneB) {
                    sel = i;
                    break;
                }
            }
        } else {
            pos.x = 0xE8;
            pos.y = idx * 0x18 + 0x50;
            sel = 0xFF;
            work->peerTowns[idx].town = 0;
        }
    }
    actor = work->actors[15];
    CLACT_AddActorSurfacePos(actor, &pos, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)actor, 1);
    INTRUDE_SUBDISP_SetTownCursor(work, sel);
    work->peerTowns[idx].zoneId = zoneId;
}

void INTRUDE_SUBDISP_UpdateButtonActors(IntrudeSubdispWork *work, void *target)
{
    void *gameData;

    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    if (work->town.busyFlag == 0 && GAME_DATA_GetIntrudeCount(gameData) == 1) {
        switch (work->town.sessionState) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[16], 0);
            BMP_OAM_SetEnabled(work->buttonOams[0], 0);
            break;
        }
    }
}

void INTRUDE_SUBDISP_UpdateInfoIcon(IntrudeSubdispWork *work, void *target)
{
    void *gameData;
    int v;
    int i;
    int digit;
    u8 *tiles;

    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    if (INTRUDE_SUBDISP_IsInfoActive(work) == 0) {
        if (CLACT_GetActorDrawEnable((struct ClactActor *)work->actors[20]) == 1) {
            CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[20], 0);
            INTRUDE_SUBDISP_ClearInfoPanel();
        }
        return;
    }
    if (CLACT_GetActorDrawEnable((struct ClactActor *)work->actors[20]) == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)work->actors[20], 1);
        INTRUDE_SUBDISP_DrawInfoPanel(work, 1);
    }
    GAME_DATA_GetLastBattleRecSlot(gameData);
    v = work->town.number;
    if (work->digitsValue != -1 && work->digitsValue != v && v <= 5 && work->town.sessionState == 3) {
        GFL_USE_PlaySeDefaultVolume(0x550);
    }
    if (work->digitsValue == v) {
        return;
    }
    tiles = work->numberGfx->tiles;
    work->digitsValue = v;
    for (i = 0; i < 3; i++) {
        digit = v % 10;
        v = v / 10;
        MIi_CpuCopy32(tiles + digit * 0x40, work->numberBuf + (2 - i) * 0x40, 0x40);
        MIi_CpuCopy32(tiles + (digit * 0x40 + 0x280), work->numberBuf + ((2 - i) * 0x40 + 0x100), 0x40);
    }
    work->digitsDirty = 1;
}

void INTRUDE_SUBDISP_PrintTitle(IntrudeSubdispWork *work, int zoneId)
{
    struct PrintQue *printQue;
    void *gameData;
    int anim;
    int mode;
    int v;

    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)work->printQue, BMP_WIN_GetBmp(work->titleWin)) == 1) {
        return;
    }
    if (GAME_DATA_GetIntrudeCount(gameData) == 1) {
        v = work->town.homeSlot;
        if (v == GAME_DATA_GetOwnNetId(gameData)) {
            mode = 2;
            anim = 0x43;
        } else {
            mode = v + 3;
            anim = 0x44;
        }
    } else {
        mode = 7;
    }
    if (work->titleMode == mode || mode == 0) {
        return;
    }
    work->titleMode = mode;
    if (mode == 7) {
        BMP_Clear(BMP_WIN_GetBmp(work->titleWin), 0);
        BMP_WIN_TransferChars(work->titleWin);
        return;
    }
    if (mode >= 3 && mode <= 6) {
        WORDSET_SetSlotMyStatus(work->wordSet, 0, GAME_DATA_GetMyStatusPlayer(gameData, work->town.homeSlot));
    }
    MSGDATA_ReadString((struct MsgBank *)work->msgData, anim, work->strbufMsg);
    WORDSET_CopyTaggedText(work->wordSet, work->strbufTitle, work->strbufMsg);
    BMP_Clear(BMP_WIN_GetBmp(work->titleWin), 0);
    printQue = work->printQue;
    PRINTSYS_PrintQueColor((struct PrintQueue *)printQue, BMP_WIN_GetBmp(work->titleWin), 0, 0, work->strbufTitle, work->font, 0x3C40);
    work->titlePending = 1;
}

void INTRUDE_SUBDISP_PrintInfoMessage(IntrudeSubdispWork *work, IntrudeCommSys *sys, u16 zoneId)
{
    void *gameComm;
    void *gameData;
    int done;
    int cur;
    int prev;
    int i;
    int n;
    int msg;
    struct PrintQue *printQue;
    void *wordArg;
    IntrudeZonePos *zone1;
    IntrudeZonePos *zone2;
    IntrudeZonePos *town;
    IntrudeSubdispMsgReq req;
    VecFx32 pos;

    gameComm = (void *)GAMESYSTEM_GetGameComm(work->gameSystem);
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    done = 0;
    if (work->msgTimer > 0) {
        work->msgTimer--;
        if (work->msgTimer == 0 && sys == 0) {
            BMP_Clear(BMP_WIN_GetBmp(work->infoWin), done);
            BMP_WIN_TransferChars(work->infoWin);
        }
        return;
    }
    prev = work->msgState;
    work->msgState = 0;
    cur = GAME_DATA_GetOwnNetId(gameData);
    if (sys != 0 && GFL_NET_GetNegotiationNum() <= 1) {
        n = sys->foundCount;
        if (n != 0) {
            if (n == 1) {
                msg = 0x29;
            } else {
                msg = 0x2A;
            }
            for (i = 0; i < sys->foundCount; i++) {
                WORDSET_SetSlotTag(work->wordSet, i, (struct Strbuf *)sys->foundNames[i],
                              sys->foundSex[i], 1, sys->foundLanguage[i]);
            }
            MSGDATA_ReadString((struct MsgBank *)work->msgData, msg, work->strbufMsg);
            WORDSET_CopyTaggedText(work->wordSet, work->strbufText, work->strbufMsg);
        } else {
            MSGDATA_ReadString((struct MsgBank *)work->msgData, 0x33, work->strbufText);
        }
        done = 1;
    }
    if (done == 0 && sys != 0 && GFL_NET_GetNegotiationNum() > 1 && INTRUDE_COMM_IsWarnedWithoutRequest(sys) != 0) {
        MSGDATA_ReadString((struct MsgBank *)work->msgData, 0x35, work->strbufText);
        done = 1;
    }
    if (done == 0 && GAME_DATA_GetIntrudeCount(gameData) == 0) {
        town = work->peerTowns[cur].town;
        if (town != 0) {
            for (i = 0; i < 3; i++) {
                if (cur != i && work->peerTowns[i].town != 0
                    && town->x == work->peerTowns[i].town->x && town->y == work->peerTowns[i].town->y) {
                    MSGDATA_ReadString((struct MsgBank *)work->msgData, 0x31, work->strbufText);
                    done = 1;
                    break;
                }
            }
        }
        if (done == 0 && work->town.busyFlag == 1) {
            MSGDATA_ReadString((struct MsgBank *)work->msgData, 0x34, work->strbufText);
            done = 1;
        }
        if (done == 0 && work->town.sameHomeFlag == 1) {
            MSGDATA_ReadString((struct MsgBank *)work->msgData, 0x32, work->strbufText);
            done = 1;
        }
    }
    if (done == 0 && sys != 0 && work->pendingPeer != 4 && GAME_DATA_GetMyStatusByNetId(gameData, work->pendingPeer) != 0) {
        wordArg = (void *)GAME_DATA_GetMyStatusByNetId(gameData, work->pendingPeer);
        if (sys->peers[work->pendingPeer].state == 2) {
            msg = 0x36;
        } else {
            msg = 0x28;
        }
        MSGDATA_ReadString((struct MsgBank *)work->msgData, msg, work->strbufMsg);
        WORDSET_SetSlotMyStatus(work->wordSet, 0, wordArg);
        WORDSET_CopyTaggedText(work->wordSet, work->strbufText, work->strbufMsg);
        work->pendingPeer = 4;
        done = 1;
    } else if (work->town.sessionState != 0 && work->town.selection != 0
               && (work->town.sessionState == 3 || prev != work->town.sessionState)) {
        if (work->town.sessionState == 3 && sys != 0 && work->town.selection->kind != 4) {
            IntrudePeer *peer;
            IntrudeZonePos *peerTown;
            void *fieldMap;

            fieldMap = GAMESYSTEM_GetFieldMap(work->gameSystem);
            peer = &sys->peers[work->town.selection->peerIndex];
            FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &pos);
            INTRUDE_COMM_SetWordSetMemberName(work->wordSet, 0, (struct IntrudeMemberName *)work->town.selection->words, 0x70);
            peerTown = INTRUDE_FIELD_FindZonePos(peer->zoneId);
            if (work->town.homeSlot == work->town.partnerHome && peerTown != 0
                && INTRUDE_SUBDISP_IsZoneMatch(zoneId, peerTown->zoneId, peerTown->zoneIdAlt) == 1) {
                if (peer->package.vanish == 1) {
                    MSGDATA_ReadString((struct MsgBank *)work->msgData, 0x2F, work->strbufMsg);
                    WORDSET_CopyTaggedText(work->wordSet, work->strbufText, work->strbufMsg);
                    done = 1;
                } else {
                    int dx = peer->package.pos.x - pos.x;
                    int dy = peer->package.pos.z - pos.z;
                    int ady = dy < 0 ? -dy : dy;
                    int adx = dx < 0 ? -dx : dx;
                    if (adx > ady) {
                        msg = 0x2D;
                        if (dx <= 0) {
                            msg = 0x2E;
                        }
                    } else {
                        msg = 0x2C;
                        if (dy <= 0) {
                            msg = 0x2B;
                        }
                    }
                    MSGDATA_ReadString((struct MsgBank *)work->msgData, msg, work->strbufMsg);
                    WORDSET_CopyTaggedText(work->wordSet, work->strbufText, work->strbufMsg);
                    done = 1;
                }
            } else {
                zone1 = INTRUDE_FIELD_FindZonePos(peer->zoneId);
                zone2 = INTRUDE_FIELD_FindZonePos(zoneId);
                if (zone1 != 0 && zone2 != 0 && zone1->x == zone2->x && zone1->y == zone2->y) {
                    MSGDATA_ReadString((struct MsgBank *)work->msgData, 0x2F, work->strbufMsg);
                    WORDSET_CopyTaggedText(work->wordSet, work->strbufText, work->strbufMsg);
                    done = 1;
                }
            }
        }
        if (done == 0 && GAME_DATA_GetIntrudeCount(gameData) == 1) {
            work->msgState = 0;
            switch (work->town.sessionState) {
            case 1:
                MSGDATA_ReadString((struct MsgBank *)work->msgData, 0x21, work->strbufText);
                break;
            case 2:
                MSGDATA_ReadString((struct MsgBank *)work->msgData, 0x22, work->strbufText);
                break;
            case 3:
                if (work->msgToggle == 0) {
                    MSGDATA_ReadString((struct MsgBank *)work->msgData, work->town.selection->kind + 0x37, work->strbufText);
                } else {
                    MSGDATA_ReadString((struct MsgBank *)work->msgDataDetail, work->town.selection->msgId, work->strbufMsg);
                    INTRUDE_COMM_SetWordSetRequest((struct IntrudeRequestHead *)work->town.selection, (struct IntrudeMemberName *)work->town.selection->words, work->wordSet, (u16)0x70);
                    WORDSET_CopyTaggedText(work->wordSet, work->strbufText, work->strbufMsg);
                }
                work->msgToggle ^= 1;
                break;
            case 0:
            case 4:
                return;
            default:
                return;
            }
            if (work->town.sessionState != 3) {
                work->msgToggle = 0;
            }
            work->msgState = work->town.sessionState;
            done = 1;
        }
    } else {
        if (GAME_COMM_PopInfoMessage(gameComm, (struct GameCommInfoMessage *)(&req)) == 1) {
            work->msgState = 0;
            MSGDATA_ReadString((struct MsgBank *)work->msgData, req.msgId, work->strbufMsg);
            done = 1;
            for (i = 0; i < 2; i++) {
                if (req.words[i] != 0) {
                    WORDSET_SetSlotTag(work->wordSet, req.slot[i], req.words[i], req.param[i], 1, 2);
                }
            }
            WORDSET_CopyTaggedText(work->wordSet, work->strbufText, work->strbufMsg);
            done = 1;
        }
    }
    if (done == 0 && GAME_DATA_GetIntrudeCount(gameData) == 1 && ZONEDATA_IsEntralink(zoneId) == 0 && ZONEDATA_IsZoneGroup118To120(zoneId) == 0
        && FIELD_PALACE_SYS_IsZoneFlagSet(gameData, zoneId) == 0) {
        MSGDATA_ReadString((struct MsgBank *)work->msgData, 0x30, work->strbufText);
        done = 1;
    }
    work->pendingPeer = 4;
    if (done == 1) {
        BMP_Clear(BMP_WIN_GetBmp(work->infoWin), 0);
        printQue = work->printQue;
        PRINTSYS_PrintQueColor((struct PrintQueue *)printQue, BMP_WIN_GetBmp(work->infoWin), 0, 0, work->strbufText, work->font, 0x3C40);
        work->infoPending = 1;
        work->msgTimer = 0x5A;
    }
}

/*
 * extent: two zero padding bytes at 0x0217EC06.
 * interface: GAME_DATA_GetLastBattleRecSlot tail-forwards GAME_DATA_GetBattleRecSlot's pointer result.
 */
void *INTRUDE_SUBDISP_GetTargetPlayerData(IntrudeSubdispWork *work)
{
    void *gameData;
    int i;
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    i = work->town.homeSlot;
    if (i == GAME_DATA_GetOwnNetId(gameData) || i == 0x80) {
        return GAME_DATA_GetLastBattleRecSlot(gameData);
    } else {
        return GAME_DATA_GetBattleRecSlot(gameData, i);
    }
}

/*
 * lever: integer t initialized to 0x126 and incremented conditionally retains
 * the u16 assignment's shift pair; assigning either u16 constant removes it.
 */
int INTRUDE_SUBDISP_IsZoneMatch(u16 zone, u16 zoneA, u16 zoneB)
{
    int t;
    if (zone == zoneA || zone == zoneB) return 1;
    if ((u16)(zone + 0xfeda) <= 1) {
        t = 0x126;
        if (zone == t) t++;
        zone = t;
        if (zone == zoneA || zone == zoneB) return 1;
    }
    return 0;
}

void INTRUDE_SUBDISP_SetTouchRect(int x, int y, int halfWidth, int halfHeight, IntrudeSubdispRect *rect)
{
    rect->top = y - halfHeight;
    rect->bottom = y + halfHeight;
    rect->left = x - halfWidth;
    rect->right = x + halfWidth;
}

int INTRUDE_SUBDISP_IsInTouchRect(int x, int y, const IntrudeSubdispRect *rect)
{
    if (rect->left < x && rect->right > x && rect->top < y && rect->bottom > y) return 1;
    return 0;
}

/*
 *           witness: 0x02013DD0 is an unlabelled arm9 leaf inside
 *           ZONEDATA_IsZoneGroup118To120's listing extent, called only from here. Verified
 *           EXACT (match.py one --region arm9 --thumb) as:
 *             extern const int d_0209DFC0[];   (0x0209DFC0 data a4)
 *             int ZONEDATA_IsZoneInTable(int a0, const int *a1, int a2);
 *             int ZONEDATA_IsZoneInTableDFC0(int a0)
 *             { return ZONEDATA_IsZoneInTable(a0, d_0209DFC0, 4); }
 *           Once that leaf is filed and in a shard, this file verifies EXACT.
 */
void INTRUDE_SUBDISP_UpdateTouch(IntrudeCommSys *sys, IntrudeSubdispWork *work, int zoneId)
{
    IntrudeSubdispRect rect;
    u32 touchX;
    u32 touchY;
    IntrudeSubdispPos pt;
    struct FieldSubscreen *fieldObj;
    int sel;
    void *gameData;
    int i;
    struct ClactActor *actor;
    int zone;
    const IntrudeTownEntry *entry;
    IntrudeZonePos *town;

    fieldObj = FIELDMAP_GetSubscreen(GAMESYSTEM_GetFieldMap(work->gameSystem));
    GAMESYSTEM_GetGameComm(work->gameSystem);
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    if (work->selectionKind != 0 || work->warpPending == 1 || !TOUCHPANEL_GetPointTrg(&touchX, &touchY) || FIELD_SUBSCREEN_GetPanelResult(fieldObj) != 0) {
        return;
    }
    sel = GAME_DATA_GetOwnNetId(gameData);
    for (i = 0; i < 3; i++) {
        if (i == sel) {
            continue;
        }
        if (!(work->town.peerMask & (1 << i))) {
            continue;
        }
        actor = work->actors[12 + i];
        if (CLACT_GetActorDrawEnable((struct ClactActor *)actor) != 1) {
            continue;
        }
        CLACT_GetActorSurfacePos(actor, &pt, 0);
        if (touchX - 12 > pt.x || touchX + 12 < pt.x) {
            continue;
        }
        if (touchY - 12 > pt.y || touchY + 12 < pt.y) {
            continue;
        }
        if (sys == 0) {
            continue;
        }
        if (INTRUDE_FIELD_FindZonePos(sys->peers[i].zoneId) == 0) {
            continue;
        }
        work->pendingPeer = i;
        return;
    }
    if (INTRUDE_SUBDISP_IsAlone(work) == 1) {
        return;
    }
    if (work->town.homeSlot != GAME_DATA_GetOwnNetId(gameData)) {
        for (i = 0; i < 8; i++) {
            entry = &d_02176AA0[i];
            INTRUDE_SUBDISP_SetTouchRect(entry->x, entry->y, 0x10, 0x10, &rect);
            if (INTRUDE_SUBDISP_IsInTouchRect(touchX, touchY, &rect) != 1) {
                continue;
            }
            zone = entry->zoneA;
            if (zoneId == zone || zoneId == entry->zoneB || (ZONEDATA_IsZoneInTableDFC0(zoneId) == 1 && ZONEDATA_IsZoneInTableDFC0(zone) == 1)) {
                GFL_USE_PlaySeDefaultVolume(0x557);
                return;
            }
            if (i == 7) {
                work->warpPending = 1;
                work->warpStep = 0;
            } else {
                town = INTRUDE_FIELD_FindZonePos(zone);
                if (town == 0) {
                    continue;
                }
                work->targetZone = town->townId;
                work->selectionKind = 1;
            }
            work->selectedActor = i;
            return;
        }
    }
    if (work->town.homeSlot != GAME_DATA_GetOwnNetId(gameData)) {
        INTRUDE_SUBDISP_SetTouchRect(0x80, 0x5C, 0x10, 0x10, &rect);
        if (INTRUDE_SUBDISP_IsInTouchRect(touchX, touchY, &rect) == 1) {
            if (ZONEDATA_IsEntralink(zoneId) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x557);
                return;
            }
            work->targetZone = 0x117;
            work->selectionKind = 1;
            work->selectedActor = 8;
            return;
        }
    }
    if (work->noIntrude == 0 && BMP_OAM_GetEnabled(work->buttonOams[1]) == 1) {
        INTRUDE_SUBDISP_SetTouchRect(0xE0, 0x80, 0x1E, 0xC, &rect);
        if (INTRUDE_SUBDISP_IsInTouchRect(touchX, touchY, &rect) == 1) {
            work->noIntrude = 1;
        }
    }
}

void INTRUDE_SUBDISP_ReloadBgScreens(IntrudeSubdispWork *work)
{
    int changed;

    changed = 0;
    if (work->bgLayerVariant == 0) {
        if (work->town.peerCount > 1) {
            ARC_UTIL_UploadBgPaletteFromArchive(0x24, 7, 6, 0, 0x800, 1, 0x15);
            work->bgLayerVariant = 1;
            changed++;
        }
    } else {
        if (work->town.peerCount <= 1) {
            ARC_UTIL_UploadBgPaletteFromArchive(0x24, 6, 6, 0, 0x800, 1, 0x15);
            work->bgLayerVariant = 0;
            changed++;
        }
    }
    if (changed != 0) {
        BMP_WIN_MakeScreen(work->titleWin);
        BMP_WIN_MakeScreen(work->infoWin);
        BG_SYS_MarkTileDirty(6);
        if (INTRUDE_SUBDISP_IsInfoActive(work) == 1) {
            INTRUDE_SUBDISP_DrawInfoPanel(work, 1);
        }
    }
}

/*
 * interface: r1 holds p[0xd8] at 0x0217EF64 and EF70 reads it.
 */
void INTRUDE_SUBDISP_UpdateBgPalette(IntrudeSubdispWork *work, IntrudeCommSys *sys)
{
    GAMESYSTEM_GetGameData(work->gameSystem);
    GAMESYSTEM_GetGameComm(work->gameSystem);
    if (work->town.homeSlot != work->lastBgPalette) INTRUDE_SUBDISP_SetBgPalette(work, work->town.homeSlot);
}

void INTRUDE_SUBDISP_SetBgPalette(IntrudeSubdispWork *work, int homeSlot)
{
    BG_SYS_FillTileMap(7, 0, 2, 0x20, 0x10, (u8)(homeSlot + 5));
    BG_SYS_FillTileMap(6, 0, 2, 0x20, 0x10, (u8)(homeSlot + 1));
    if (work->titleWin != 0) {
        BMP_WIN_MakeScreen(work->titleWin);
        BMP_WIN_MakeScreen(work->infoWin);
    }
    BG_SYS_MarkTileDirty(7);
    BG_SYS_MarkTileDirty(6);
    work->lastBgPalette = homeSlot;
}

/*
 * extent: two zero padding bytes at 0x0217F006.
 * lever: assign the shifted mask before the flag; its flag store schedules
 * ahead of the shift while retaining separate constant-one registers.
 */
void INTRUDE_SUBDISP_InitTownState(IntrudeSubdispWork *work, IntrudeCommSys *sys)
{
    IntrudeSubdispTownState *state;
    void *gameData;
    state = &work->town;
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    if (sys == 0) {
        state->homeSlot = GAME_DATA_GetOwnNetId(gameData);
        state->peerMask = 1 << state->homeSlot;
        state->peerCount = 1;
        state->specialZone = 0;
        state->sessionState = 0;
        state->number = 0;
    } else {
        INTRUDE_SUBDISP_UpdateTownState(work, sys);
    }
}

void INTRUDE_SUBDISP_UpdateTownState(IntrudeSubdispWork *work, IntrudeCommSys *sys)
{
    IntrudeSubdispTownState *state;
    void *gameData;
    int n;
    int i;

    state = &work->town;
    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    if (sys == 0) {
        MI_CpuFill8(&work->town, 0, sizeof(work->town));
        work->lastPeerCount = 1;
        return;
    }
    n = GAME_DATA_GetOwnNetId(gameData);
    state->homeSlot = sys->localPeer.intrudeId;
    state->peerMask = sys->peerMask;
    state->peerCount = MATH_CountPopulation(state->peerMask);
    state->specialZone = sys->specialZoneEntered;
    state->sessionState = EVENT_COMM_COMMON_GetMissionState(&sys->session);
    state->number = INTRUDE_COMM_GetSessionRemaining(&sys->session);
    state->selection = (struct IntrudeSubdispSel *)INTRUDE_COMM_GetActiveSessionRequest(&sys->session);
    if (state->selection != 0) {
        state->partnerHome = sys->peers[state->selection->peerIndex].intrudeId;
    }
    state->busyFlag = INTRUDE_FIELD_IsStartRequested(sys);
    state->sameHomeFlag = 0;
    for (i = 0; i < 3; i++) {
        if (i != n && state->homeSlot == sys->peers[i].intrudeId) {
            state->sameHomeFlag = 1;
            return;
        }
    }
}

void INTRUDE_SUBDISP_StartTownBlink(IntrudeSubdispWork *work)
{
    int i;
    work->blinkCount = 0;
    work->blinkActive = 1;
    for (i = 0; i < 7; i++) CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[i], 6, 1);
    CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[8], 6, 1);
}

int INTRUDE_SUBDISP_IsTownBlinking(IntrudeSubdispWork *work)
{
    if (work->blinkActive == 1 && work->blinkCount < 10) return 1;
    return 0;
}

void INTRUDE_SUBDISP_SetTownCursor(IntrudeSubdispWork *work, int index)
{
    u8 cursor;

    cursor = work->cursorActor;
    if (cursor != index && work->blinkActive != 1) {
        if (cursor < 8) {
            CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[cursor], 6, 1);
        } else if (cursor == 8) {
            CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[8], 6, 1);
        }
        if (index < 8) {
            CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[index], 8, 1);
        } else if (index == 8) {
            CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[8], 8, 1);
        }
        work->cursorActor = index;
        work->cursorPulse = 0;
        work->cursorPulseDir = 0;
    }
}

void INTRUDE_SUBDISP_StartButtonBlink(IntrudeSubdispWork *work)
{
    work->buttonBlinkCount = 0;
    work->buttonBlinkActive = 1;
    CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[16], 6, 1);
}

void INTRUDE_SUBDISP_UpdateButtonBlink(IntrudeSubdispWork *work)
{
    int count;

    if (work->buttonBlinkActive != 0) {
        count = work->buttonBlinkCount;
        if (count % 2 == 0) {
            CLACT_SetActorPaletteOffset((struct ClactActor *)work->actors[16], (u8)(((unsigned)count >> 1) & 1 ? 6 : 7), (int)1);
        }
        if (work->buttonBlinkCount < 10) {
            work->buttonBlinkCount++;
        }
    }
}

/*
 * extent: Two bytes of alignment padding at 0x0217F212.
 */
int INTRUDE_SUBDISP_IsInfoActive(IntrudeSubdispWork *work)
{
    if (GAME_DATA_GetIntrudeCount(GAMESYSTEM_GetGameData(work->gameSystem)) == 1) {
        switch (work->town.sessionState) {
        case 2: case 3: case 4: return 1;
        }
    }
    return 0;
}

void INTRUDE_SUBDISP_ClearInfoPanel(void)
{
    BG_SYS_SetTileEntry(6, 0x3001, 0x14, 0x16, 0xc, 2, 0x11);
    BG_SYS_MarkTileDirty(6);
}

void INTRUDE_SUBDISP_DrawInfoPanel(IntrudeSubdispWork *work, int mode)
{
    BG_SYS_DrawTileEx(6, 0x14, 0x16, 0xC, 2, work->infoPalette, 0, 0, 0xC, 2);
    if (mode == 1) {
        BG_SYS_MarkTileDirty(6);
    } else {
        BG_SYS_PushTile(6);
    }
}

/*
 * extent: Two bytes of alignment padding at 0x0217F2B2.
 */
int INTRUDE_SUBDISP_IsAlone(IntrudeSubdispWork *work)
{
    void *gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    if (work->town.selection == 0 && GAME_DATA_GetOwnNetId(gameData) == 0 && INTRUDE_COMM_HasUnlockFlags(gameData) == 0) return 1;
    return 0;
}
