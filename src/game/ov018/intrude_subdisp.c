/*
 * file:     intrude_subdisp.c
 * unit:     yes
 * function: INTRUDE_FIELD_InitMmdlCopyAnime, INTRUDE_FIELD_MainMmdlCopyAnime, INTRUDE_SUBDISP_MainRequestAnswerSeq, INTRUDE_SUBDISP_CreatePalaceWarpEvent, INTRUDE_SUBDISP_CreateReturnPalaceEvent, INTRUDE_SUBDISP_CreateDisconnectEvent, INTRUDE_SUBDISP_DisconnectEventMain, INTRUDE_SUBDISP_CreateGuideScriptEvent, INTRUDE_SUBDISP_GuideScriptEventMain, INTRUDE_SUBDISP_CreateTownWarpEvent, INTRUDE_SUBDISP_CreatePlayerWarpEvent, INTRUDE_SUBDISP_CreateBrightFadeEvent, INTRUDE_SUBDISP_BrightFadeEventMain, INTRUDE_SUBDISP_ScriptResetFieldState, INTRUDE_SUBDISP_ScriptApplyCommState, INTRUDE_SUBDISP_Init, INTRUDE_SUBDISP_Exit, INTRUDE_SUBDISP_Update, INTRUDE_SUBDISP_Draw, INTRUDE_SUBDISP_EventCheck, INTRUDE_SUBDISP_VBlankTask, INTRUDE_SUBDISP_SystemSetup, INTRUDE_SUBDISP_SystemExit, INTRUDE_SUBDISP_BgSetup, INTRUDE_SUBDISP_BgExit, INTRUDE_SUBDISP_BmpWinSetup, INTRUDE_SUBDISP_BmpWinExit, INTRUDE_SUBDISP_ClactResourceLoad, INTRUDE_SUBDISP_ClactResourceUnload, INTRUDE_SUBDISP_ClactActorCreate, INTRUDE_SUBDISP_ClactActorDelete, INTRUDE_SUBDISP_CreateTownActors, INTRUDE_SUBDISP_CreatePlayerMarkActors, INTRUDE_SUBDISP_CreateTownMarkActors, INTRUDE_SUBDISP_CreateMyPlayerActor, INTRUDE_SUBDISP_CreatePlayerIconActors, INTRUDE_SUBDISP_CreateInfoIconActor, INTRUDE_SUBDISP_CreateButtonActors, INTRUDE_SUBDISP_DeleteButtonBmpOam, INTRUDE_SUBDISP_UpdateTownActors, INTRUDE_SUBDISP_UpdatePlayerMarkActors, INTRUDE_SUBDISP_UpdatePlayerTownActors, INTRUDE_SUBDISP_UpdateTownMarkPalette, INTRUDE_SUBDISP_UpdateMyPlayerActor, INTRUDE_SUBDISP_UpdateButtonActors, INTRUDE_SUBDISP_UpdateInfoIcon, INTRUDE_SUBDISP_PrintTitle, INTRUDE_SUBDISP_PrintInfoMessage, INTRUDE_SUBDISP_GetTargetPlayerData, INTRUDE_SUBDISP_IsZoneMatch, INTRUDE_SUBDISP_SetTouchRect, INTRUDE_SUBDISP_IsInTouchRect, INTRUDE_SUBDISP_UpdateTouch, INTRUDE_SUBDISP_ReloadBgScreens, INTRUDE_SUBDISP_UpdateBgPalette, INTRUDE_SUBDISP_SetBgPalette, INTRUDE_SUBDISP_InitTownState, INTRUDE_SUBDISP_UpdateTownState, INTRUDE_SUBDISP_StartTownBlink, INTRUDE_SUBDISP_IsTownBlinking, INTRUDE_SUBDISP_SetTownCursor, INTRUDE_SUBDISP_StartButtonBlink, INTRUDE_SUBDISP_UpdateButtonBlink, INTRUDE_SUBDISP_IsInfoActive, INTRUDE_SUBDISP_ClearInfoPanel, INTRUDE_SUBDISP_DrawInfoPanel, INTRUDE_SUBDISP_IsAlone
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
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
 *   func_021F37B8  0x021F37B8  thumb  ov060
 *   func_020061E4  0x020061E4  thumb
 *   GIMMICK60_IsEffectActive  0x021F37D8  thumb  ov060
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   INTRUDE_COMM_SendRequest  0x02173A2C  thumb  ov011
 *   INTRUDE_COMM_TakeRequestResult  0x02175514  thumb  ov011
 *   func_020362DC  0x020362DC  arm
 *   INTRUDE_COMM_SendAnswer  0x02173B9C  thumb  ov011
 *   INTRUDE_COMM_NextRequestToken  0x021753B8  thumb  ov011
 *   INTRUDE_COMM_SendReply  0x02173AE0  thumb  ov011
 *   INTRUDE_FIELD_GetZoneAnchor 0x0217BED4 thumb ov018
 *   EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset 0x02185588 thumb ov020
 *   func_02012138  0x02012138  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   func_02175710  0x02175710  thumb  ov011
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_0202647C  0x0202647C  thumb
 *   func_02012204  0x02012204  thumb
 *   INTRUDE_FIELD_SetSingleAreaMode  0x0217C094  thumb
 *   func_020124E4  0x020124E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026460  0x02026460  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   func_02012114  0x02012114  thumb
 *   func_0201210C  0x0201210C  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   func_0202648C  0x0202648C  thumb
 *   FIELD_MSGBG_SysWinPrintMsg  0x02190E74  thumb  ov021
 *   func_02029830  0x02029830  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   MSGDATA_Delete  0x02045C04  arm
 *   FIELD_PLAYER_CheckFormModel  0x021A3238  thumb  ov021
 *   INTRUDE_FIELD_InitPlayerSpin  0x0217C658  thumb  ov018
 *   INTRUDE_FIELD_StepPlayerSpin  0x0217C688  thumb  ov018
 *   func_0201296C  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   func_0201212C  0x0201212C  thumb
 *   EVENT_COMM_ERROR_Create  0x021C06CC  thumb  ov021
 *   func_02026484  0x02026484  thumb
 *   GAME_COMM_ClearPlayerStatus  0x020264F4  thumb
 *   EVENT_MAPCHANGE_CreateIntrudeReturnEvent  0x02185214  thumb  ov020
 *   func_02012B70  0x02012B70  thumb
 *   EVENT_MAPCHANGE_CreateIntrudeWarpEvent  0x02185140  thumb  ov020
 *   INTRUDE_FIELD_FindZonePos  0x0217BEA8  thumb  ov018
 *   EVENT_MAPCHANGE_CreateWarpEvent  0x02184D38  thumb  ov020
 *   FIELDMAP_GetVReq  0x02188E30  thumb  ov021
 *   func_021D324C  0x021D324C  thumb  ov093
 *   FIELD_SUBSCREEN_ChangeModeNow  0x021A0F40  thumb  ov021
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   INTRUDE_FIELD_AddAreaMmdls 0x0217BF84 thumb ov018
 *   INTRUDE_FIELD_ResetExtraAreaCount  0x0217BBCC  thumb  ov018
 *   INTRUDE_FIELD_AddAreaMaps  0x0217BBD8  thumb  ov018
 *   INTRUDE_FIELD_AddAreaMapCount  0x0217BC94  thumb  ov018
 *   INTRUDE_FIELD_AddMarkerMmdls  0x0217C194  thumb  ov018
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOn  0x02037174  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   str_02183B14   0x02183B14  data  a1
 *   func_02030EAC  0x02030EAC  arm
 *   func_02082A48  0x02082A48  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOff  0x02037190  arm
 *   func_0201283C            0x0201283C  thumb
 *   WIH_DWC_PollStatus            0x0201058C  thumb
 *   TCBL_Main            0x020310C4  arm
 *   PRINTSYS_QUE_Main            0x0201C4E4  thumb
 *   func_02045770            0x02045770  arm
 *   func_0201C6C4            0x0201C6C4  thumb
 *   BMP_WIN_TransferChars            0x02045334  arm
 *   BMP_OAM_UploadChars            0x020257D0  thumb
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   GAME_DATA_GetIntrudeIdByte            0x0215841C  thumb  ov010
 *   GFL_NET_IsConnectMember            0x0203D1C0  arm
 *   INTRUDE_COMM_SendUnionInfoRequest            0x021746AC  thumb  ov011
 *   INTRUDE_COMM_GetUnionInfoReceived            0x02158428  thumb  ov010
 *   FIELDMAP_GetSubscreen            0x02188CCC  thumb  ov021
 *   func_02034714            0x02034714  arm
 *   str_02183B28             0x02183B28  data  a1
 *   func_02013D5C  0x02013D5C  thumb
 *   INTRUDE_COMM_HasResult  0x02175DA8  thumb  ov011
 *   INTRUDE_COMM_IsSessionAccepted  0x02175B8C  thumb  ov011
 *   func_02158378  0x02158378  thumb  ov010
 *   func_020862F0  0x020862F0  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0207E804  0x0207E804  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   TCBL_Create  0x0203101C  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   d_021836B4     0x021836B4  data   a4
 *   STRBUF_Delete  0x02045808  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   CLACT_DeleteRenderer  0x0204B084  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   func_0203FCA0            0x0203FCA0  arm
 *   MIi_CpuClear32           0x02082A7C  arm
 *   func_02049658            0x02049658  arm
 *   func_020498F4            0x020498F4  arm
 *   func_02049EF4            0x02049EF4  arm
 *   MIi_CpuCopy16            0x02082A60  arm
 *   func_02049B68            0x02049B68  arm
 *   func_02049B40            0x02049B40  arm
 *   func_02040588            0x02040588  arm
 *   d_0218370C               0x0218370C  data  a4
 *   d_0218372C               0x0218372C  data  a4
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8 0x020452E8 arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   func_02049DF4  0x02049DF4  arm
 *   CLACT_GetCharacterVramAddress  0x0204ABBC  arm
 *   func_02082A60  0x02082A60  arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   d_021836CC     0x021836CC  data  a4
 *   d_02176AA0     0x02176AA0  data  a4
 *   func_0204B6F4  0x0204B6F4  arm
 *   d_021836E4  0x021836E4  data  a4
 *   d_021836DC  0x021836DC  data  a4
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   d_021836D4  0x021836D4  data  a4
 *   d_021836EC  0x021836EC  data  a4
 *   d_021836C4  0x021836C4  data  a4
 *   BMP_Create  0x02043678  arm
 *   BMP_OAM_Create  0x020255A0  thumb
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   d_021836AA     0x021836AA  data   a2
 *   d_021836F4     0x021836F4  data   a4
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   PALANM_BlendColors  0x02021F64  thumb
 *   func_0204B404  0x0204B404  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   func_0204B714  0x0204B714  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   d_021836A4     0x021836A4  data   a1
 *   func_0204B3F4  0x0204B3F4  arm
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   MIi_CpuCopy32  0x02082A90  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_02012950  0x02012950  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   GAME_COMM_PopInfoMessage  0x02026608  thumb
 *   INTRUDE_COMM_IsWarnedWithoutRequest  0x021585BC  thumb  ov010
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb  ov010
 *   INTRUDE_COMM_SetWordSetMemberName  0x021762C0  thumb  ov011
 *   INTRUDE_COMM_SetWordSetRequest  0x021762D8  thumb  ov011
 *   FIELD_PALACE_SYS_IsZoneFlagSet  0x021D3554  thumb  ov021
 *   func_020127AC 0x020127AC thumb
 *   func_02035D20  0x02035D20  arm
 *   FIELD_SUBSCREEN_GetPanelResult  0x021A0F94  thumb  ov021
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   BMP_OAM_GetEnabled  0x020257C4  thumb
 *   func_0204989C  0x0204989C  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02080D24  0x02080D24  arm
 *   INTRUDE_COMM_GetSessionRemaining  0x021758C8  thumb  ov011
 *   INTRUDE_COMM_GetActiveSessionRequest  0x02175B34  thumb  ov011
 *   INTRUDE_FIELD_IsStartRequested  0x0217C070  thumb  ov018
 *   func_02041300 0x02041300 arm
 *   func_020410D0  0x020410D0  arm
 *   INTRUDE_COMM_HasUnlockFlags 0x02158590 thumb ov010
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb  ov018
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb  ov018
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb  ov018
 *   EVENT_COMM_COMMON_GetMissionState  0x0217F5A0  thumb  ov018
 *   EVENT_COMM_COMMON_ChangeTalkedItemSaleEvent  0x021828A8  thumb  ov018
 *   EVENT_COMM_COMMON_ChangeTalkedItemPurchaseEvent  0x021828B0  thumb  ov018
 */
#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_WINOUT_SUB     (*(volatile u16 *)0x0400104A)
#define REG_DB_BLDCNT_SUB (*(volatile u16 *)0x04001050)
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

#include "../ov011/intrude_comm_types.h"
#include "intrude_subdisp_types.h"

typedef struct VecFx32 {
    s32 x;
    s32 y;
    s32 z;
} VecFx32;


/* Record of the player copy that plays the split animation (0x18 bytes). */
typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    void *f14;
} Rec;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad04[8];
    u16 fC;
} Tmpl_0217C758;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct { int x, y, z; } V12;

/* Work of the disconnect event (0x28 bytes, allocated by INTRUDE_SUBDISP_CreateDisconnectEvent). */
typedef struct {
    void *msgData;          /* 0x00 */
    void *msgBox;           /* 0x04 */
    unsigned char copyRecord[0x18]; /* 0x08: record of the player copy animation */
    int cause;              /* 0x20: 0 = own choice, 1 and 2 = peer left */
    int alone;              /* 0x24 */
} Ov018Work_0217CAFC;

typedef struct {
    int f0;
    int f4;
    int f8;
} Obj_0217CF0C;

typedef struct { u8 a : 7; u8 b : 1; } FlagsF8_0217C758;

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};
extern void func_02082BCC(void *, int, int);
extern void *func_020120F4(const void *p);
extern u32 func_02012964(const void *p);
extern void *FIELDMAP_GetFieldPlayer(void *p);
extern void *FIELD_PLAYER_GetMmdl(void *p);
extern u16 FIELDMAP_GetZoneId(void *);
extern u16 FLDMMDL_GetObjCode(void *);
extern int FLDMMDL_GetGridNowX(void *);
extern int FLDMMDL_GetGridNowZ(void *);
extern u32 FLDMMDL_GetPosY(void *p);
extern void FLDMMDL_InitPosRecord(void *, u16, u16, int);
extern void *FLDMMDL_AddMmdl(int, void *, int);
extern void INTRUDE_FIELD_ChangePlayerLook(void *p, void *a1, int id, u8 kind, u8 flag);
extern void FLDMMDL_SetStatusBitVanish(void *, unsigned int);
extern void FLDMMDL_SetAcmd(void *, int);
extern void FIELD_PLAYER_GetPos(void *, void *);
extern void func_021F37B8(int, void *);
extern void func_020061E4(u32 a);
extern int GIMMICK60_IsEffectActive(void *);
extern int FLDMMDL_CheckEndAcmd(int);
extern int FLDMMDL_EndAcmd(void *p);
extern void FLDMMDL_DeleteMmdl(int);
extern int INTRUDE_COMM_SendRequest(void *p, int b, void *c, int d);
extern int INTRUDE_COMM_TakeRequestResult(void *);
extern u32 func_020362DC(void);
extern int INTRUDE_COMM_SendAnswer(int a, int b);
extern void INTRUDE_COMM_NextRequestToken(void *);
extern int INTRUDE_COMM_SendReply(int a, int b, int c, int d);
extern int INTRUDE_FIELD_GetZoneAnchor(int, void *);
extern void *EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(void *owner, u16 id, const void *pos);
extern unsigned int func_02012138(const void *p);
extern u8 func_02012B58(const void *p);
extern void func_02012B8C(void *p, unsigned int v);
extern IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(void *gameComm);
extern void func_02175710(void *o, u32 v);
struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
void *func_020124E8(void *p);
u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
u32 func_0202647C(void *obj);
u32 func_02012204(const void *p);
void INTRUDE_FIELD_SetSingleAreaMode(void *);
void *func_020124E4(void *p);
void GAME_EVENT_CallEvent(void *evt, void *out);
u32 func_0200FB24(void);
u32 func_02026460(void *obj);
void GAME_COMM_RequestExitNoCallback(void *p);
u32 func_02012114(const void *p);
void *func_0201210C(const void *p);
int FIELDMAP_IsReady(void *);
u32 FIELDMAP_GetMsgBg(void *p);
int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
struct Obj2 *FIELD_MSGBG_CreateBottomSysWin(void *a, u32 b);
u32 func_0202648C(void *obj);
void FIELD_MSGBG_SysWinPrintMsg(void *p, u32 b, u32 c, u32 d);
void *func_02029830(void *a, u32 b);
int func_02005F38(void);
void *func_02029620(void *a, u32 b, u32 c);
u32 FIELD_MSGBG_SysWinMain(void *p);
int FIELD_MSGBG_DeleteSysWin(u32 a);
u32 MSGDATA_Delete(void *rec);
int FIELD_PLAYER_CheckFormModel(void *p);
void INTRUDE_FIELD_InitPlayerSpin(void *, void *, void *, int, int, int);
int INTRUDE_FIELD_StepPlayerSpin(void *, int);
u32 func_0201296C(const void *p);
u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
u8 func_0201212C(const void *p);
int EVENT_COMM_ERROR_Create(void *, void *);
void func_02026484(void *);
void GAME_COMM_ClearPlayerStatus(void *p);
void *EVENT_MAPCHANGE_CreateIntrudeReturnEvent(void *a);
extern int func_02012B70(const void *p);
extern void *EVENT_MAPCHANGE_CreateIntrudeWarpEvent();
extern IntrudeZoneInfo *INTRUDE_FIELD_FindZonePos(int zoneId);
extern void *EVENT_MAPCHANGE_CreateWarpEvent(void *p, int unused, int a, const void *q, u16 s, int t);
extern u32 FIELDMAP_GetVReq(void *p);
extern void func_021D324C();
extern void FIELD_SUBSCREEN_ChangeModeNow(void *p, u32 v);
extern void *SCRCMD_WORK_GetGameSystem(void *);
extern void INTRUDE_FIELD_AddAreaMmdls(int a);
extern void INTRUDE_FIELD_ResetExtraAreaCount(int a, int b, void *p);
extern void INTRUDE_FIELD_AddAreaMaps(void *a, int b, void *c);
extern void INTRUDE_FIELD_AddAreaMapCount(int a, int n);
extern void INTRUDE_FIELD_AddMarkerMmdls();
void *func_02030734(u32 heapId, u32 size, int clear, const void *site, u16 tag);
void *func_020490F4(u32 id, u32 heap);
void ARC_TOOL_DeleteHandle(void *bg);
void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
void GFL_NET_WM_ICON_EasyObjWindowOn(void);
struct TcbTask *func_020056A0(void (*cb)(void *, void *), void *arg, int pri);
u8 *func_020120F8(const void *p);
u16 func_02012AC8(const void *p);
extern void func_02030EAC(void *n);
extern void func_02082A48();
extern u32 func_020307B0(void *p);
extern void GFL_NET_WM_ICON_EasyObjWindowOff();
u32 func_0201283C(const void *p);
u32 WIH_DWC_PollStatus(void *key);
void TCBL_Main(void *p);
u32 PRINTSYS_QUE_Main(void *ps);
void *func_02045770(void *p);
u32 func_0201C6C4(void *p, void *v);
void BMP_WIN_TransferChars(void *d);
void BMP_OAM_UploadChars(void *o);
void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
u8 GAME_DATA_GetIntrudeIdByte(void *p);
u32 GFL_NET_IsConnectMember(u32 index);
int INTRUDE_COMM_SendUnionInfoRequest(void *a, int b);
u8 INTRUDE_COMM_GetUnionInfoReceived(void *p);
u32 FIELDMAP_GetSubscreen(void *p);
void func_02034714(const void *expr, u32 line, const void *file);
u32 func_02013D5C(u32 id);
int INTRUDE_COMM_HasResult(void *p);
int INTRUDE_COMM_IsSessionAccepted(void *p);
int func_02158378(void *);
extern void func_020862F0();
extern void func_0207E5D0();
extern void func_0207E804();
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct ClactRenderer *CLACT_CreateRenderer(void *a0, unsigned int a1, unsigned int heap);
extern void func_0204B258(void *bank, void *p);
extern struct BmpOamSys *BMP_OAM_CreateSys(unsigned int heapId, struct ClactUnit *unit);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct PrintQue *func_0201C440(u32 heapId);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(void *vec);
extern void func_0201C6EC(void *p);
extern void func_0201C4C0(void *p);
extern unsigned int func_0201ED04(void *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(void *p);
extern void BMP_OAM_DeleteSys(void *p);
extern void CLACT_DeleteRenderer(struct ClactRenderer *);
extern u32 CLACT_DeleteUnit(void *bank);
void func_0203FCA0(u32 bgId, const void *tmpl, u32 type);
void MIi_CpuClear32(u32 data, void *dest, u32 size);
u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void *func_02049EF4(void *p, u32 a, u32 b, void *out, u16 d);
void MIi_CpuCopy16(const void *src, void *dest, u32 size);
void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned int);
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_MakeScreen(void *cfg);
extern u8 func_02045730(void *p);
extern void func_020409B4(unsigned int);
extern u32 func_020452E8(void *d);
extern struct ClactRes *CLACT_RegisterPaletteEx(void *a, unsigned int b, unsigned int c, unsigned int d, u16 e, u16 f, u16 g);
extern struct ClactRes *CLACT_RegisterCharacter(void *a, unsigned int b, unsigned int c, unsigned int a3, u16 flags);
extern struct ClactRes *CLACT_RegisterCellAnim(void *owner, unsigned int first, unsigned int second, unsigned int mode);
extern struct ClactRes *CLACT_RegisterPaletteCompressed(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern struct ClactRes *func_02049DF4(void *a0, unsigned int a1, unsigned int a2, void *out, u16 a4);
extern u32 CLACT_GetCharacterVramAddress(struct ClactRes *res, unsigned int flag);
extern void func_02082A60(const void *, void *, int);
extern void CLACT_ReleasePalette(struct ClactRes *);
extern void CLACT_ReleaseCharacter(struct ClactRes *);
extern void CLACT_ReleaseCellAnim(struct ClactRes *);
extern void CLACT_DeleteActor(void *p);
extern struct ClactActor *CLACT_CreateActor(struct ClactUnit *, struct ClactRes *, struct ClactRes *, struct ClactRes *, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(void *, unsigned int);
extern void func_0204B92C(void *p, unsigned int v);
extern void func_0204B6F4(void *o, unsigned int v, unsigned int flag);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const void *obj);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern struct BmpOam *BMP_OAM_Create(struct BmpOamSys *sys, const void *param);
extern void BMP_OAM_SetEnabled(void *g, u32 a);
extern struct Strbuf *func_02045EC0(struct MsgData *msgData, u32 index);
extern void PRINTSYS_PrintQueColor(struct PrintQue *queue, struct Bmp *bmp, u32 x, u32 y, struct Strbuf *str, struct GfFont *font, u16 color);
extern void BMP_OAM_Delete(void *g);
extern void BMP_Delete(void *p);
extern void PALANM_BlendColors(void *, void *, int, u8, u16);
extern void func_0204B404(void *p, const void *delta, u32 which);
extern void CLACT_SetActorAutoAnimSpeed(void *a, u32 v);
extern u32 func_0204B714(void *o);
extern void CLACT_GetActorSurfacePos(void *actor, void *out, u16 space);
extern unsigned int func_0204B3F4(void *p);
extern void *GAME_DATA_GetLastBattleRecSlot(void *p);
extern void MIi_CpuCopy32(const void *src, void *dst, int size);
void BMP_Clear(void *buf, u8 value);
void *func_02012950(void *gameData, u32 slot);
void func_0201F02C(void *p, u32 i, void *a);
void func_02045CAC(void *bank, u32 index, void *dest);
void func_0201F250(void *ws, void *dst, void *src);
u32 func_02013D9C(u32 id);
int GFL_NET_GetNegotiationNum(void);
void func_0201EE0C(void *p, u32 i, const void *src, u32 n, u32 f, u32 c);
int GAME_COMM_PopInfoMessage(void *p, void *out);
int INTRUDE_COMM_IsWarnedWithoutRequest(IntrudeCommSys *sys);
int GAME_DATA_GetMyStatusByNetId(void *a0, int a1);
void INTRUDE_COMM_SetWordSetMemberName(void *win, u32 slot, void *src, u16 heap);
void INTRUDE_COMM_SetWordSetRequest();
int FIELD_PALACE_SYS_IsZoneFlagSet(void *arg0, int arg1);
extern void *func_020127AC(void *p, u32 idx);
extern u32 func_02035D20(void *outA, void *outB);
extern int FIELD_SUBSCREEN_GetPanelResult(u32 a);
extern int ZONEDATA_IsZoneInTableDFC0(int a0);
extern int BMP_OAM_GetEnabled(const void *p);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02041B6C(u32 bit);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int func_02080D24(unsigned int x);
extern int INTRUDE_COMM_GetSessionRemaining(void *o);
extern int INTRUDE_FIELD_IsStartRequested(void *p);
extern void func_02041300(unsigned int, int, int, int, u8, u8, u8);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, const void *palette, u8 a6, u8 a7, u8 a8, u8 a9);
extern int INTRUDE_COMM_HasUnlockFlags(void *);

void INTRUDE_FIELD_InitMmdlCopyAnime(Rec *r, void *a1, void *a2, void *a3, u16 id, u8 kind, u8 flag, u16 idx, int place);
int INTRUDE_FIELD_MainMmdlCopyAnime(Rec *r);
int INTRUDE_SUBDISP_MainRequestAnswerSeq(IntrudeCommSys *sys, u8 *w, u8 *state);
void *INTRUDE_SUBDISP_CreatePalaceWarpEvent(void *p);
void *INTRUDE_SUBDISP_CreateReturnPalaceEvent(int a0);
int INTRUDE_SUBDISP_CreateDisconnectEvent(void *a, int b);
int INTRUDE_SUBDISP_DisconnectEventMain(void *a, int *seq, Ov018Work_0217CAFC *work);
void *INTRUDE_SUBDISP_CreateGuideScriptEvent(void *p);
int INTRUDE_SUBDISP_GuideScriptEventMain(void *p, int *state);
void *INTRUDE_SUBDISP_CreateTownWarpEvent(void *a0, void *a1, u16 a2, int a3);
void *INTRUDE_SUBDISP_CreatePlayerWarpEvent(void *a0, void *a1, int a2);
void *INTRUDE_SUBDISP_CreateBrightFadeEvent(void *p, int a, int b);
int INTRUDE_SUBDISP_BrightFadeEventMain(int a0, int *state, Obj_0217CF0C *o);
int INTRUDE_SUBDISP_ScriptResetFieldState(void *unused, void *p);
int INTRUDE_SUBDISP_ScriptApplyCommState(int a0, int a1);
IntrudeSubdispWork *INTRUDE_SUBDISP_Init(void *gameSystem);
void INTRUDE_SUBDISP_Exit(IntrudeSubdispWork *work);
void INTRUDE_SUBDISP_Update(IntrudeSubdispWork *work, int mode);
void INTRUDE_SUBDISP_Draw(IntrudeSubdispWork *work);
void *INTRUDE_SUBDISP_EventCheck(IntrudeSubdispWork *work, int touched, int param);
void INTRUDE_SUBDISP_VBlankTask(void *tcb, void *taskWork);
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
void EVENT_COMM_COMMON_PrintMsg(void *, u16 a);
int EVENT_COMM_COMMON_IsPrintFinished(void *);
int EVENT_COMM_COMMON_IsKeyTrg(void);
int EVENT_COMM_COMMON_GetMissionState(void *session);
extern IntrudeSubdispSel *INTRUDE_COMM_GetActiveSessionRequest(void *session);

extern Tmpl_0217C758 d_02183AF0;
extern Tmpl_0217C758 g_02183AF0;
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
extern const unsigned short d_021836AA[];
extern const IntrudeSubdispBmpOamTmpl d_021836F4;
extern const s8 d_021836A4[3][2];

/*
 * Initialises a 0x18-byte record (cleared by the fill below) and, when the
 * last argument is set, places its field object. The pool carries
 * 0x02183AF0 twice (stores, then call arguments), so two extern names:
 * see docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md.
 */
void INTRUDE_FIELD_InitMmdlCopyAnime(Rec *r, void *a1, void *a2, void *a3, u16 id, u8 kind,
                   u8 flag, u16 idx, int place)
{
    int sys;
    void *obj;
    int zone;
    int x;
    int y;

    func_02082BCC(r, 0, 0x18);
    r->f0 = a1;
    r->f4 = a2;
    r->fC = id;
    r->fE = kind;
    r->fF = flag;
    r->fA = 15;
    r->f8 = r->fA;
    r->f13 = idx;
    if (place != 0) {
        sys = func_02012964(func_020120F4(a1));
        obj = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(a2));
        zone = FIELDMAP_GetZoneId(a2);
        d_02183AF0.f2 = FLDMMDL_GetObjCode(obj);
        d_02183AF0.fC = idx;
        x = FLDMMDL_GetGridNowX(obj);
        y = FLDMMDL_GetGridNowZ(obj);
        FLDMMDL_InitPosRecord(((Tmpl_0217C758 *)&g_02183AF0), x, y, FLDMMDL_GetPosY(obj));
        r->f14 = FLDMMDL_AddMmdl(sys, ((Tmpl_0217C758 *)&g_02183AF0), zone);
        INTRUDE_FIELD_ChangePlayerLook(a3, r->f0, r->fC, r->fE, r->fF);
        FLDMMDL_SetStatusBitVanish(obj, 1);
        FLDMMDL_SetStatusBitVanish(r->f14, 0);
    }
}
void EVENT_COMM_COMMON_ChangeTalkedItemSaleEvent(void *a, void *b);
void EVENT_COMM_COMMON_ChangeTalkedItemPurchaseEvent(void *a, void *b);


/*
 * Per-frame step of the 0x18-byte record (same layout as INTRUDE_FIELD_StepPlayerSpin's).
 */
int INTRUDE_FIELD_MainMmdlCopyAnime(Rec *r)
{
    void *fld;
    void *obj;
    u16 anim;
    Vec v;

    fld = FIELDMAP_GetFieldPlayer(r->f4);
    obj = FIELD_PLAYER_GetMmdl((void *)fld);
    switch (r->f10) {
    case 0:
        anim = r->f13 == 3 ? 7 : 6;
        FLDMMDL_SetAcmd(obj, anim);
        if (r->f14 != 0)
            FLDMMDL_SetAcmd(r->f14, anim);
        FIELD_PLAYER_GetPos(fld, &v);
        if (r->f13 == 3)
            v.x += 0x8000;
        else
            v.x -= 0x8000;
        func_021F37B8((int)r->f4, &v);
        func_020061E4(0x774);
        r->f10++;
        break;
    case 1:
        r->fA--;
        if (r->fA <= 0) {
            if (r->f14 != 0) {
                FLDMMDL_SetStatusBitVanish(obj, 0);
                FLDMMDL_SetStatusBitVanish(r->f14, 1);
            }
            r->f10++;
        }
        break;
    case 2:
        if (GIMMICK60_IsEffectActive(r->f4) == 0 && FLDMMDL_CheckEndAcmd((int)obj) == 1) {
            FLDMMDL_EndAcmd(obj);
            if (r->f14 != 0)
                FLDMMDL_EndAcmd(r->f14);
            r->f10++;
        }
        break;
    case 3:
        if (r->f14 != 0) {
            FLDMMDL_DeleteMmdl((int)r->f14);
            r->f14 = 0;
        }
        return 1;
    }
    return 0;
}


int INTRUDE_SUBDISP_MainRequestAnswerSeq(IntrudeCommSys *sys, u8 *w, u8 *state)
{
    switch (*state) {
    case 0:
        EVENT_COMM_COMMON_PrintMsg(w + 0x10, 0);
        (*state)++;
        break;
    case 1:
        if (INTRUDE_COMM_SendRequest(sys, sys->requestTarget, (w + 0x44), w[0x41]) == 1)
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
            if (EVENT_COMM_COMMON_IsPrintFinished(w + 0x10) == 1) {
                if ((func_020362DC() & 2) && INTRUDE_COMM_SendAnswer(sys->requestTarget, sys->sentRequestSeq) == 1) {
                    INTRUDE_COMM_NextRequestToken(sys);
                    *state = 9;
                }
            }
            break;
        }
        break;
    case 3:
        if (EVENT_COMM_COMMON_IsPrintFinished(w + 0x10) == 1) {
            EVENT_COMM_COMMON_PrintMsg(w + 0x10, 2);
            (*state)++;
        }
        break;
    case 4:
        if (EVENT_COMM_COMMON_IsPrintFinished(w + 0x10) == 1)
            (*state)++;
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1)
            *state = 8;
        break;
    case 6:
        if (INTRUDE_COMM_SendReply((int)sys, sys->requestTarget, 1, sys->sentRequestSeq) == 1)
            *state = 7;
        break;
    case 7:
        if (EVENT_COMM_COMMON_IsPrintFinished(w + 0x10) == 1)
            return 1;
        break;
    case 8:
        return 2;
    case 9:
        return 3;
    }
    return 0;
}


void *INTRUDE_SUBDISP_CreatePalaceWarpEvent(void *p)
{
    V12 v;
    INTRUDE_FIELD_GetZoneAnchor(0x117, &v);
    return EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(p, 0x117, (&v));
}


void *INTRUDE_SUBDISP_CreateReturnPalaceEvent(int a0)
{
    void *gameComm;
    void *gameData;
    IntrudeCommSys *sys;

    gameComm = (void *)func_02012138((void *)a0);
    gameData = func_020120F4((void *)a0);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (sys != 0) {
        func_02175710(sys, func_02012B58(gameData));
    } else {
        func_02012B8C(gameData, func_02012B58(gameData));
    }
    return INTRUDE_SUBDISP_CreatePalaceWarpEvent((void *)a0);
}


int INTRUDE_SUBDISP_CreateDisconnectEvent(void *a, int b)
{
    void *sys;
    int ret;
    Ov018Work_0217CAFC *work;
    unsigned char *x;

    sys = (void *)func_02012138(a);
    ret = (int)func_020122C0(a, 0, INTRUDE_SUBDISP_DisconnectEventMain, 0x28);
    work = func_020124E8((void *)ret);
    work->cause = b;
    if (func_02026454(sys) == 2) {
        x = (unsigned char *)func_02026474(sys);
        if (x != 0) {
            INTRUDE_FIELD_SetSingleAreaMode((unsigned char *)func_02026474(sys));
            x[0x8F8] |= 0x80;
        }
    }
    if (func_02012204(a) == 1) {
        if (func_0202647C(sys) == 1) {
            work->alone = 1;
        }
    }
    func_020061E4(0x737);
    return ret;
}


int INTRUDE_SUBDISP_DisconnectEventMain(void *a, int *seq, Ov018Work_0217CAFC *work)
{
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

    x = func_020124E4(a);
    s2 = func_020120F4(x);
    s1 = (void *)func_02012138(x);
    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(a, INTRUDE_SUBDISP_CreateReturnPalaceEvent((int)x));
        (*seq)++;
        break;
    case 1:
        if (func_0200FB24() == 0 && (int)func_02026460(s1) != 0) {
            break;
        }
        if (func_0200FB24() == 0 && ((int)func_02026454(s1) == 2 || (int)func_02026454(s1) == 1)) {
            GAME_COMM_RequestExitNoCallback(s1);
        }
        (*seq)++;
        break;
    case 2:
        if (func_0200FB24() == 0 && (int)func_02026454(s1) != 0) {
            break;
        }
        if (work->alone == 1) {
            *seq = 7;
        } else {
            (*seq)++;
        }
        break;
    case 3:
        if (func_02012114(x) != 1) {
            break;
        }
        flag = 0;
        y = func_0201210C(x);
        if (FIELDMAP_IsReady(y) != 1) {
            break;
        }
        z = (void *)FIELDMAP_GetMsgBg(y);
        work->msgData = t = (void *)FIELD_MSGBG_CreateMsgData((u32)z, 0x2D);
        work->msgBox = FIELD_MSGBG_CreateBottomSysWin(z, (u32)t);
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
            switch ((int)func_0202648C(s1)) {
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
            GAME_EVENT_CallEvent(a, func_02029830(x, 0x52D));
            *seq = 4;
        } else {
            *seq = 5;
        }
        break;
    case 4:
        if (func_02005F38() == 0) {
            GAME_EVENT_CallEvent(a, func_02029620(x, 0, 6));
            *seq = 5;
        }
        break;
    case 5:
        if ((int)FIELD_MSGBG_SysWinMain(work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (func_020362DC() & 0xF3) {
            FIELD_MSGBG_DeleteSysWin((u32)work->msgBox);
            MSGDATA_Delete(work->msgData);
            (*seq)++;
        }
        break;
    case 7:
        y = func_0201210C(x);
        if (FIELDMAP_IsReady(y) == 1) {
            if (FIELD_PLAYER_CheckFormModel(FIELDMAP_GetFieldPlayer(y)) == 0) {
                INTRUDE_FIELD_InitPlayerSpin(work->copyRecord, x, y, 0, 0, 0);
                (*seq)++;
            } else {
                *seq = 10;
            }
        }
        break;
    case 8:
        if (INTRUDE_FIELD_StepPlayerSpin(work->copyRecord, 0) == 1) {
            if (work->alone == 1) {
                *seq = 10;
            } else {
                (*seq)++;
            }
        }
        break;
    case 9:
        if ((int)ZONEDATA_CheckEventFlag((void *)func_0201296C(s2), 0x980) == 0) {
            r = (int)func_0202648C(s1);
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
            SCRIPT_SYS_CallScriptEvent(a, (u16)v, 0, 0, (int)0x8015);
        }
        *seq = 10;
        break;
    case 10:
        if ((func_02012B58(s2) != 0 || (int)func_02012204(x) == 1) && func_0201212C(x) == 1) {
            GAME_EVENT_CallEvent(a, (void *)EVENT_COMM_ERROR_Create(x, func_0201210C(x)));
        }
        (*seq)++;
        break;
    case 11:
        func_02026484(s1);
        GAME_COMM_ClearPlayerStatus(s1);
        if (func_02012B58(s2) != 0 || (int)func_02012204(x) == 1) {
            GAME_EVENT_CallEvent(a, EVENT_MAPCHANGE_CreateIntrudeReturnEvent(x));
        }
        (*seq)++;
        break;
    case 12:
        return 1;
    }
    return 0;
}


void *INTRUDE_SUBDISP_CreateGuideScriptEvent(void *p)
{
    return func_020122C0(p, 0, INTRUDE_SUBDISP_GuideScriptEventMain, 0);
}


int INTRUDE_SUBDISP_GuideScriptEventMain(void *p, int *state)
{
    switch (*state) {
    case 0:
        SCRIPT_SYS_CallScriptEvent(p, 0x279e, 0, 0, 0x15);
        ++*state;
        break;
    case 1:
        return 1;
    }
    return 0;
}


void *INTRUDE_SUBDISP_CreateTownWarpEvent(void *a0, void *a1, u16 a2, int a3)
{
    void *gameComm;
    void *c;
    V12 v;

    gameComm = (void *)func_02012138(a0);
    c = func_020120F4((void *)a0);
    INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (INTRUDE_FIELD_GetZoneAnchor(a2, &v) == 0)
        return 0;
    if (func_02012B70(c) == 0 && a2 == 0x117)
        return EVENT_MAPCHANGE_CreateIntrudeWarpEvent(a0, a2, &v, a3);
    return EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(a0, a2, &v);
}


void *INTRUDE_SUBDISP_CreatePlayerWarpEvent(void *a0, void *a1, int a2)
{
    u8 *p;
    IntrudeZoneInfo *q;
    V12 v;
    u16 s;

    p = (u8 *)INTRUDE_COMM_GetWorkIfRunning((void *)func_02012138(a0));
    if (p == 0 || !(p[0x8FB] & (1 << a2)))
        return 0;
    q = INTRUDE_FIELD_FindZonePos(*(u16 *)(p + a2 * 0x1C + 0xA0));
    if (q == 0)
        return 0;
    s = q->townId;
    v = *(V12 *)(p + a2 * 0x1C + 0x90);
    v.z += 0x20000;
    return EVENT_MAPCHANGE_CreateWarpEvent(a0, (int)a1, s, (const int *)(&v), 0, 0);
}


void *INTRUDE_SUBDISP_CreateBrightFadeEvent(void *p, int a, int b)
{
    void *task;
    int *work;
    task = func_020122C0(p, 0, INTRUDE_SUBDISP_BrightFadeEventMain, 12);
    work = func_020124E8(task);
    work[0] = a;
    work[1] = b;
    return task;
}


int INTRUDE_SUBDISP_BrightFadeEventMain(int a0, int *state, Obj_0217CF0C *o)
{
    switch (*state) {
    case 0:
        o->f8 += 1;
        if (o->f8 > 15) {
            func_021D324C(FIELDMAP_GetVReq((u8 *)o->f0), -16);
            *state += 1;
        }
        break;
    case 1:
        FIELD_SUBSCREEN_ChangeModeNow((u32 *)o->f4, 0);
        *state += 1;
        break;
    case 2:
        func_021D324C(FIELDMAP_GetVReq((u8 *)o->f0), 0);
        *state += 1;
        break;
    case 3:
        return 1;
    }
    return 0;
}


int INTRUDE_SUBDISP_ScriptResetFieldState(void *unused, void *p)
{
    void *sys;
    void *obj;
    sys = SCRCMD_WORK_GetGameSystem(p);
    obj = func_0201210C(sys);
    func_02012138(sys);
    INTRUDE_FIELD_AddAreaMmdls((int)obj);
    return 0;
}


int INTRUDE_SUBDISP_ScriptApplyCommState(int a0, int a1)
{
    void *w;
    void *c;
    int h;
    int v;

    w = SCRCMD_WORK_GetGameSystem((void *)a1);
    func_020120F4(w);
    c = func_0201210C((void *)w);
    h = func_02012138(w);
    v = 0;
    if (func_02026454((void *)h) == 2)
        v = func_02026474((void *)h);
    if (v != 0) {
        INTRUDE_FIELD_ResetExtraAreaCount((int)c, (int)w, (char *)v);
        INTRUDE_FIELD_AddAreaMaps((u8 *)c, (int)w, (u8 *)v);
    } else {
        INTRUDE_FIELD_AddAreaMapCount((int)c, 1);
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

    gameComm = (void *)func_02012138(gameSystem);
    work = func_02030734(0x70, 0x170, 1, str_02183B14, 0x240);
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
    if (func_02026454(gameComm) == 2) {
        sys = (IntrudeCommSys *)func_02026474(gameComm);
    }
    if (sys != 0 && sys->flagBit7 == 1) {
        sys = 0;
    }
    INTRUDE_SUBDISP_InitTownState(work, sys);
    work->lastPeerCount = work->town.peerCount;
    bg = func_020490F4(0x24, 0x15);
    INTRUDE_SUBDISP_SystemSetup(work);
    INTRUDE_SUBDISP_BgSetup(work, bg);
    INTRUDE_SUBDISP_BmpWinSetup(work);
    INTRUDE_SUBDISP_ClactResourceLoad(work, bg);
    INTRUDE_SUBDISP_ClactActorCreate(work, bg);
    ARC_TOOL_DeleteHandle(bg);
    GFL_NET_RestartWithDefaultTimeout(0, 0x15);
    GFL_NET_WM_ICON_EasyObjWindowOn();
    REG_WINOUT_SUB = (u16)((REG_WINOUT_SUB & ~0x3F00) | (0x1F << 8));
    tmp = (REG_WINOUT_SUB & ~0x3F) | 0x1F;
    tmp |= 0x20;
    REG_WINOUT_SUB = (u16)tmp;
    REG_DB_DISPCNT_SUB = (REG_DB_DISPCNT_SUB & ~0xE000) | 0x8000;
    work->vblankTask = func_020056A0(INTRUDE_SUBDISP_VBlankTask, work, 10);
    zoneId = func_02012AC8(func_020120F8(work->gameSystem));
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
    func_02030EAC(work->vblankTask);
    func_02082A48(0, 0x05000400, 2);
    INTRUDE_SUBDISP_DeleteButtonBmpOam(work);
    INTRUDE_SUBDISP_ClactActorDelete(work);
    INTRUDE_SUBDISP_ClactResourceUnload(work);
    INTRUDE_SUBDISP_BmpWinExit(work);
    INTRUDE_SUBDISP_BgExit(work);
    INTRUDE_SUBDISP_SystemExit(work);
    func_020307B0(work);
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

    gameComm = (void *)func_02012138(work->gameSystem);
    gameData = func_020120F4(work->gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    zoneId = func_02012AC8(func_020120F8(work->gameSystem));
    WIH_DWC_PollStatus((void *)func_0201283C(gameData));
    GFL_NET_WM_ICON_EasyObjWindowOn();
    if (sys == 0 || (sys != 0 && sys->flagBit7 == 0)) {
        INTRUDE_SUBDISP_UpdateTownState(work, sys);
    }
    if (work->lastPeerCount < work->town.peerCount) {
        if (func_02012B70(gameData) == 1) {
            func_020061E4(0x699);
        }
        work->lastPeerCount = work->town.peerCount;
    }
    TCBL_Main(work->tcbl);
    PRINTSYS_QUE_Main(work->printQue);
    printQue = work->printQue;
    if (work->titlePending != 0) {
        if (func_0201C6C4(printQue, func_02045770(work->titleWin)) == 0) {
            BMP_WIN_TransferChars(work->titleWin);
            work->titlePending = 0;
        }
    }
    printQue = work->printQue;
    if (work->infoPending != 0) {
        if (func_0201C6C4(printQue, func_02045770(work->infoWin)) == 0) {
            BMP_WIN_TransferChars(work->infoWin);
            work->infoPending = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (func_0201C6C4(work->printQue, work->buttonBitmaps[i]) == 0) {
            BMP_OAM_UploadChars(work->buttonOams[i]);
        }
    }
    if (mode == 0) {
        if (INTRUDE_SUBDISP_IsTownBlinking(work) == 1 || work->buttonBlinkActive == 1) {
            REG_DB_BLDCNT_SUB = 0;
        } else {
            G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
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
                FIELDMAP_GetSubscreen(func_0201210C(work->gameSystem));
                work->targetZone = 0x126;
                work->selectionKind = 1;
                work->warpPending = 0;
            }
            break;
        default:
            func_02034714(str_02183B28, 0, str_02183B28);
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

    gameComm = (void *)func_02012138(work->gameSystem);
    gameData = func_020120F4(work->gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    zoneId = func_02012AC8(func_020120F8(work->gameSystem));
    flag = 0;
    target = INTRUDE_SUBDISP_GetTargetPlayerData(work);
    if (sys != 0 && INTRUDE_COMM_HasResult(&sys->session) == 0) {
        flag = 1;
    } else if (sys == 0 && func_02012B70(gameData) == 1 && func_02026454(gameComm) != 2
               && func_0202648C(gameComm) == 0 && func_02013D5C(zoneId) == 1) {
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


void *INTRUDE_SUBDISP_EventCheck(IntrudeSubdispWork *work, int touched, int param)
{
    void *gameComm;
    void *gameData;
    void *fieldMap;
    void *event;

    gameComm = (void *)func_02012138(work->gameSystem);
    gameData = func_020120F4(work->gameSystem);
    fieldMap = func_0201210C(work->gameSystem);
    event = 0;
    if (touched == 0 || fieldMap == 0) {
        return 0;
    }
    if (work->noIntrude == 1 || (func_02012B70(gameData) == 0 && INTRUDE_COMM_GetWorkIfRunning(gameComm) == 0)) {
        func_020061E4(0x551);
        INTRUDE_SUBDISP_StartButtonBlink(work);
        return INTRUDE_SUBDISP_CreateBrightFadeEvent(work->gameSystem, (int)fieldMap, param);
    }
    switch (work->selectionKind) {
    case 1:
        func_020061E4(0x737);
        INTRUDE_SUBDISP_StartTownBlink(work);
        event = INTRUDE_SUBDISP_CreateTownWarpEvent(work->gameSystem, fieldMap, work->targetZone, 0);
        break;
    case 2:
        func_020061E4(0x737);
        event = INTRUDE_SUBDISP_CreatePlayerWarpEvent(work->gameSystem, fieldMap, func_02158378(gameComm));
        break;
    }
    if (event != 0) {
        work->selectionKind = 0;
        return event;
    }
    return 0;
}


void INTRUDE_SUBDISP_VBlankTask(void *tcb, void *taskWork)
{
    IntrudeSubdispWork *work = taskWork;

    work->vblankPhase ^= 1;
    if (work->vblankPhase != 0) {
        if (work->paletteDirty != 0) {
            func_020862F0(work->palOut, 8);
            func_0207E5D0(work->palOut, 0x102, 8);
            work->paletteDirty = 0;
        }
        if (work->digitsDirty != 0) {
            func_020862F0(work->numberBuf, 0x200);
            func_0207E804(work->numberBuf, work->numberVram, 0x200);
            work->digitsDirty = 0;
        }
    }
}


void INTRUDE_SUBDISP_SystemSetup(IntrudeSubdispWork *work)
{
    struct ClactRenderer *renderer;

    work->clactUnit = CLACT_CreateUnit(0x29, 5, 0x70);
    renderer = CLACT_CreateRenderer(d_021836B4, 1, 0x70);
    work->renderer = renderer;
    func_0204B258(work->clactUnit, renderer);
    work->bmpOamSys = BMP_OAM_CreateSys(0x70, work->clactUnit);
    work->tcbl = TCBL_Create(0x70, 0x70, 4, 0x20);
    work->font = GF_FONT_Create(0x17, 0, 0, 0, 0x70);
    work->wordSet = func_0201EC64(0x70);
    work->printQue = func_0201C440(0x70);
    work->msgData = func_02045B38(0, 2, 0x2D, 0x70);
    work->msgDataDetail = func_02045B38(0, 2, 0x42, 0x70);
    work->strbufMsg = STRBUF_Create(0x80, 0x70);
    work->strbufText = STRBUF_Create(0x80, 0x70);
    work->strbufTitle = STRBUF_Create(0x80, 0x70);
}


void INTRUDE_SUBDISP_SystemExit(IntrudeSubdispWork *work)
{
    STRBUF_Delete(work->strbufMsg);
    STRBUF_Delete(work->strbufText);
    STRBUF_Delete(work->strbufTitle);
    MSGDATA_Delete(work->msgData);
    MSGDATA_Delete(work->msgDataDetail);
    func_0201C6EC(work->printQue);
    func_0201C4C0(work->printQue);
    func_0201ED04(work->wordSet);
    GF_FONT_Delete(work->font);
    TCBL_Destroy(work->tcbl);
    BMP_OAM_DeleteSys(work->bmpOamSys);
    CLACT_DeleteRenderer(work->renderer);
    CLACT_DeleteUnit(work->clactUnit);
}


void INTRUDE_SUBDISP_BgSetup(IntrudeSubdispWork *work, void *bg)
{
    int layer;
    u8 *pal;
    void *res;

    layer = 6;
    func_0203FCA0(6, &d_0218370C, 0);
    func_0203FCA0(7, &d_0218372C, 0);
    MIi_CpuClear32(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
    func_02049658(bg, 4, 7, 0, 0, 1, 0x15);
    func_020498F4(bg, 5, 7, 0, 0x800, 1, 0x15);
    if (work->town.peerCount <= 1) {
        work->bgLayerVariant = 0;
    } else {
        layer = 7;
        work->bgLayerVariant = 1;
    }
    func_020498F4(bg, layer, 6, 0, 0x800, 1, 0x15);
    INTRUDE_SUBDISP_SetBgPalette(work, work->town.homeSlot);
    res = func_02049EF4(bg, 8, 1, &pal, 0x15);
    MIi_CpuCopy16(pal + 0xC, work->infoPalette, 0x30);
    func_020307B0(res);
    if (INTRUDE_SUBDISP_IsInfoActive(work) == 1) {
        INTRUDE_SUBDISP_DrawInfoPanel(work, 0);
    }
    func_02049B68(bg, 9, 4, 0, 0x140, 0x15);
    func_02049B40(0x17, 5, 4, 0x1C0, 0x20, 0x15);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 1);
    func_02040588(7, 1);
}


void INTRUDE_SUBDISP_BgExit(IntrudeSubdispWork *work)
{
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020403F4(6);
    func_020403F4(7);
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
    func_020409B4(func_02045730(win));
    win = BMP_WIN_Create(6, 1, 0x12, 0x1e, 4, 14, 1);
    work->infoWin = win;
    work->infoPending = zero;
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_020409B4(func_02045730(win));
}


void INTRUDE_SUBDISP_BmpWinExit(IntrudeSubdispWork *work)
{
    func_020452E8(work->titleWin);
    func_020452E8(work->infoWin);
}


void INTRUDE_SUBDISP_ClactResourceLoad(IntrudeSubdispWork *work, void *bg)
{
    void *bg2;

    work->palRes = CLACT_RegisterPaletteEx(bg, 3, 1, 0, 0, 9, 0x15);
    work->charRes = CLACT_RegisterCharacter(bg, 0, 1, 1, 0x15);
    work->cellRes = CLACT_RegisterCellAnim(bg, 1, 2, 0x70);
    bg2 = func_020490F4(0x17, 0x15);
    work->bmpOamPalRes = CLACT_RegisterPaletteCompressed(bg2, 5, 1, 0x1a0, 0x15);
    ARC_TOOL_DeleteHandle(bg2);
    work->infoCharRes = CLACT_RegisterCharacter(bg, 10, 1, 1, 0x15);
    work->infoCellRes = CLACT_RegisterCellAnim(bg, 12, 13, 0x70);
    work->numberRes = func_02049DF4(bg, 10, 1, &work->numberGfx, 0x70);
    work->numberVram = CLACT_GetCharacterVramAddress(work->infoCharRes, 2);
    work->numberBuf = func_02030734(0x70, 0x200, 1, str_02183B14, 0x495);
    func_02082A60((void *)0x050006E2, work->palBase, 8);
    func_02082A60(work->palBase, work->palOut, 8);
    func_02082A60((void *)0x05000702, work->palTarget, 8);
}


void INTRUDE_SUBDISP_ClactResourceUnload(IntrudeSubdispWork *work)
{
    func_020307B0(work->numberBuf);
    func_020307B0(work->numberRes);
    CLACT_ReleasePalette(work->bmpOamPalRes);
    CLACT_ReleasePalette(work->palRes);
    CLACT_ReleaseCharacter(work->charRes);
    CLACT_ReleaseCharacter(work->infoCharRes);
    CLACT_ReleaseCellAnim(work->cellRes);
    CLACT_ReleaseCellAnim(work->infoCellRes);
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
    for (i = 0; i < INTRUDE_SUBDISP_ACTOR_COUNT; i++) CLACT_DeleteActor(work->actors[i]);
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
        func_0204B3DC(work->actors[i], 0);
        func_0204B92C(work->actors[i], 1);
    }
    param.anim = 8;
    param.x = 0x80;
    param.y = 0x5c;
    work->actors[8] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
    func_0204B3DC(work->actors[8], 0);
    func_0204B92C(work->actors[8], 1);
}


void INTRUDE_SUBDISP_CreatePlayerMarkActors(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    int i;

    param = d_021836E4;
    for (i = 9; i <= 11; i++) {
        work->actors[i] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
        func_0204B6F4(work->actors[i], (u8)(i - 8), 1);
        func_0204B3DC(work->actors[i], 0);
    }
}


void INTRUDE_SUBDISP_CreateTownMarkActors(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    int i;

    param = d_021836DC;
    for (i = 12; i <= 14; i++) {
        work->actors[i] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
        func_0204B6F4(work->actors[i], (u8)(i - 11), 1);
        func_0204B3DC(work->actors[i], 0);
        func_0204B92C(work->actors[i], 1);
    }
}


void INTRUDE_SUBDISP_CreateMyPlayerActor(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    void *gameData;

    param = d_021836D4;
    gameData = func_020120F4(work->gameSystem);
    if (func_02008550(func_02012944(gameData)) == 1) {
        param.anim = 3;
    }
    work->actors[15] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
    func_0204B6F4(work->actors[15], (u8)(func_02012B58(gameData) + 1), 1);
    func_0204B3DC(work->actors[15], 0);
    func_0204B92C(work->actors[15], 1);
}


void INTRUDE_SUBDISP_CreatePlayerIconActors(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    int i;

    param = d_021836EC;
    for (i = 17; i <= 19; i++) {
        work->actors[i] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &param, 0, 0x70);
        func_0204B6F4(work->actors[i], (u8)(i - 16), 1);
        func_0204B3DC(work->actors[i], 0);
    }
}


void INTRUDE_SUBDISP_CreateInfoIconActor(IntrudeSubdispWork *work, void *bg)
{
    IntrudeSubdispActorParam param;
    int infoActive;

    param = d_021836C4;
    infoActive = INTRUDE_SUBDISP_IsInfoActive(work);
    work->actors[20] = CLACT_CreateActor(work->clactUnit, work->infoCharRes, work->palRes, work->infoCellRes, &param, 0, 0x70);
    func_0204B3DC(work->actors[20], infoActive);
}


void INTRUDE_SUBDISP_CreateButtonActors(IntrudeSubdispWork *work, void *bg)
{
    void *gameData;
    int i;
    struct Strbuf *str;
    IntrudeSubdispBmpOamTmpl copy;
    IntrudeSubdispBmpOamTmpl tmpl;

    gameData = func_020120F4(work->gameSystem);
    work->actors[16] = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, d_021836AA, 0, 0x70);
    func_0204B3DC(work->actors[16], 0);
    tmpl = d_021836F4;
    for (i = 0; i < 2; i++) {
        copy = tmpl;
        work->buttonBitmaps[i] = BMP_Create(6, 2, 0x20, 0x70);
        copy.bmp = work->buttonBitmaps[i];
        copy.palRes = work->bmpOamPalRes;
        work->buttonOams[i] = BMP_OAM_Create(work->bmpOamSys, &copy);
        BMP_OAM_SetEnabled(work->buttonOams[i], 0);
        str = func_02045EC0(work->msgData, i + 0x45);
        PRINTSYS_PrintQueColor(work->printQue, work->buttonBitmaps[i], 0, 0, str, work->font, 0x3c40);
        STRBUF_Delete(str);
    }
    if (work->noIntrude == 0 && func_02012B70(gameData) == 0) {
        func_0204B3DC(work->actors[16], 1);
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

    gameData = func_020120F4(work->gameSystem);
    if (INTRUDE_SUBDISP_IsAlone(work) == 1) {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(work->actors[i], 0);
        }
        func_0204B3DC(work->actors[8], 0);
    } else if (work->town.homeSlot == func_02012B58(gameData) || func_02012B70(gameData) == 0) {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(work->actors[i], 0);
        }
        func_0204B3DC(work->actors[8], 0);
    } else {
        for (i = 0; i <= 7; i++) {
            func_0204B3DC(work->actors[i], 1);
        }
        func_0204B3DC(work->actors[8], 1);
    }
    for (i = 6; i <= 8; i++) {
        func_02082A60((void *)(0x05000602 + (work->town.homeSlot + 1) * 32), (void *)(0x0500060C + i * 32), 2);
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
            func_0204B6F4(actor, (u8)anim, (int)1);
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

    func_020120F4(work->gameSystem);
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
                func_0204B404(actor, &layout.pos, 0);
                func_0204B6F4(actor, (u8)(layout.slot[i] + 1), 1);
                func_0204B3DC(actor, 1);
                j++;
            }
            i++;
        } while (i < n);
    }
    for (; i < 3; i++) {
        func_0204B3DC(work->actors[9 + i], 0);
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
    IntrudeZoneInfo *prev;
    u16 prevZone;
    IntrudeZoneInfo *town;
    struct ClactActor *icon;
    IntrudeSubdispPosPair pair;

    gameData = func_020120F4(work->gameSystem);
    cur = work->town.homeSlot;
    INTRUDE_SUBDISP_UpdateTownMarkPalette(work);
    for (i = 0; i < 3; i++) {
        town = 0;
        prev = work->peerTowns[i].town;
        prevZone = work->peerTowns[i].zoneId;
        if (i != func_02012B58(gameData)) {
            work->peerTowns[i].town = 0;
            work->peerTowns[i].zoneId = 0x1ab;
        }
        mark = work->actors[12 + i];
        icon = work->actors[17 + i];
        if (i == func_02012B58(gameData)) {
            func_0204B3DC(mark, 0);
            func_0204B3DC(icon, 0);
            continue;
        }
        if (sys == 0) {
            func_0204B3DC(mark, 0);
            func_0204B3DC(icon, 0);
            continue;
        }
        if (work->town.peerMask & (1 << i)) {
            peer = &sys->peers[i];
        } else {
            func_0204B3DC(mark, 0);
            func_0204B3DC(icon, 0);
            continue;
        }
        if (peer->state == 2) {
            CLACT_SetActorAutoAnimSpeed(mark, 0x2000);
        } else {
            CLACT_SetActorAutoAnimSpeed(mark, 0x1000);
        }
        if (peer->intrudeId == cur) {
            if (func_02013D5C(peer->zoneId) == 1) {
                pair.pos.x = d_021836A4[i][0] + 0x80;
                pair.pos.y = d_021836A4[i][1] + 0x4c;
                func_0204B3DC(icon, 0);
            } else {
                if (peer->zoneId != prevZone) {
                    town = INTRUDE_FIELD_FindZonePos(peer->zoneId);
                } else {
                    town = prev;
                }
                if (town != 0) {
                    pair.pos.x = town->x + d_021836A4[i][0];
                    pair.pos.y = town->y + d_021836A4[i][1];
                    func_0204B3DC(icon, 0);
                } else {
                    pair.pos.x = 0xe8;
                    pair.pos.y = i * 0x18 + 0x50;
                    pair.marker = pair.pos;
                    pair.marker.x = 0xf0;
                    func_0204B404(icon, &pair.marker, 0);
                    func_0204B3DC(icon, 1);
                }
            }
            func_0204B404(mark, &pair.pos, 0);
            work->peerTowns[i].town = town;
            work->peerTowns[i].zoneId = peer->zoneId;
        } else {
            func_0204B3DC(icon, 0);
            for (k = 0; k < 3; k++) {
                if (func_0204B714(work->actors[9 + k]) == i + 1) {
                    CLACT_GetActorSurfacePos(work->actors[9 + k], &pair.pos, 0);
                    break;
                }
            }
            if (k == 3) {
                func_0204B3DC(mark, 0);
                continue;
            }
            pair.pos.x += d_021836A4[i][0];
            pair.pos.y += d_021836A4[i][1];
            func_0204B404(mark, &pair.pos, 0);
        }
        func_0204B3DC(mark, 1);
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
            func_0204B6F4(work->actors[v + 12], (u8)(v + 1), (int)1);
        }
        if (work->lastPeer != sel) {
            func_02082A60((void *)(0x05000600 + (sel + 1) * 32), buf, 0x20);
            PALANM_BlendColors(buf, buf, 0x10, 8, 0x7fff);
            func_02082A60(buf, (void *)0x05000720, 0x20);
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
            func_0204B6F4(work->actors[sel + 12], (u8)anim, (int)1);
        }
        return;
    }
    v = work->lastPeer;
    if (v != 4) {
        func_0204B6F4(work->actors[v + 12], (u8)(v + 1), (int)1);
        work->lastPeer = 4;
        work->peerBlinkCount = 0;
    }
}


void INTRUDE_SUBDISP_UpdateMyPlayerActor(IntrudeSubdispWork *work, void *target, u16 zoneId)
{
    IntrudeSubdispPos pos;
    int sel;
    int idx;
    IntrudeZoneInfo *town;
    int i;
    int v;
    struct ClactActor *actor;

    idx = func_02012B58(func_020120F4(work->gameSystem));
    sel = 0xFF;
    if (func_02013D5C(zoneId) == 1) {
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
    func_0204B404(actor, &pos, 0);
    func_0204B3DC(actor, 1);
    INTRUDE_SUBDISP_SetTownCursor(work, sel);
    work->peerTowns[idx].zoneId = zoneId;
}


void INTRUDE_SUBDISP_UpdateButtonActors(IntrudeSubdispWork *work, void *target)
{
    void *gameData;

    gameData = func_020120F4(work->gameSystem);
    if (work->town.busyFlag == 0 && func_02012B70(gameData) == 1) {
        switch (work->town.sessionState) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            func_0204B3DC(work->actors[16], 0);
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

    gameData = func_020120F4(work->gameSystem);
    if (INTRUDE_SUBDISP_IsInfoActive(work) == 0) {
        if (func_0204B3F4(work->actors[20]) == 1) {
            func_0204B3DC(work->actors[20], 0);
            INTRUDE_SUBDISP_ClearInfoPanel();
        }
        return;
    }
    if (func_0204B3F4(work->actors[20]) == 0) {
        func_0204B3DC(work->actors[20], 1);
        INTRUDE_SUBDISP_DrawInfoPanel(work, 1);
    }
    GAME_DATA_GetLastBattleRecSlot(gameData);
    v = work->town.number;
    if (work->digitsValue != -1 && work->digitsValue != v && v <= 5 && work->town.sessionState == 3) {
        func_020061E4(0x550);
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

    gameData = func_020120F4(work->gameSystem);
    if (func_0201C6C4(work->printQue, func_02045770(work->titleWin)) == 1) {
        return;
    }
    if (func_02012B70(gameData) == 1) {
        v = work->town.homeSlot;
        if (v == func_02012B58(gameData)) {
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
        BMP_Clear(func_02045770(work->titleWin), 0);
        BMP_WIN_TransferChars(work->titleWin);
        return;
    }
    if (mode >= 3 && mode <= 6) {
        func_0201F02C(work->wordSet, 0, func_02012950(gameData, work->town.homeSlot));
    }
    func_02045CAC(work->msgData, anim, work->strbufMsg);
    func_0201F250(work->wordSet, work->strbufTitle, work->strbufMsg);
    BMP_Clear(func_02045770(work->titleWin), 0);
    printQue = work->printQue;
    PRINTSYS_PrintQueColor(printQue, func_02045770(work->titleWin), 0, 0, work->strbufTitle, work->font, 0x3C40);
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
    IntrudeZoneInfo *zone1;
    IntrudeZoneInfo *zone2;
    IntrudeZoneInfo *town;
    IntrudeSubdispMsgReq req;
    VecFx32 pos;

    gameComm = (void *)func_02012138(work->gameSystem);
    gameData = func_020120F4(work->gameSystem);
    done = 0;
    if (work->msgTimer > 0) {
        work->msgTimer--;
        if (work->msgTimer == 0 && sys == 0) {
            BMP_Clear(func_02045770(work->infoWin), done);
            BMP_WIN_TransferChars(work->infoWin);
        }
        return;
    }
    prev = work->msgState;
    work->msgState = 0;
    cur = func_02012B58(gameData);
    if (sys != 0 && GFL_NET_GetNegotiationNum() <= 1) {
        n = sys->foundCount;
        if (n != 0) {
            if (n == 1) {
                msg = 0x29;
            } else {
                msg = 0x2A;
            }
            for (i = 0; i < sys->foundCount; i++) {
                func_0201EE0C(work->wordSet, i, sys->foundNames[i],
                              sys->foundSex[i], 1, sys->foundLanguage[i]);
            }
            func_02045CAC(work->msgData, msg, work->strbufMsg);
            func_0201F250(work->wordSet, work->strbufText, work->strbufMsg);
        } else {
            func_02045CAC(work->msgData, 0x33, work->strbufText);
        }
        done = 1;
    }
    if (done == 0 && sys != 0 && GFL_NET_GetNegotiationNum() > 1 && INTRUDE_COMM_IsWarnedWithoutRequest(sys) != 0) {
        func_02045CAC(work->msgData, 0x35, work->strbufText);
        done = 1;
    }
    if (done == 0 && func_02012B70(gameData) == 0) {
        town = work->peerTowns[cur].town;
        if (town != 0) {
            for (i = 0; i < 3; i++) {
                if (cur != i && work->peerTowns[i].town != 0
                    && town->x == work->peerTowns[i].town->x && town->y == work->peerTowns[i].town->y) {
                    func_02045CAC(work->msgData, 0x31, work->strbufText);
                    done = 1;
                    break;
                }
            }
        }
        if (done == 0 && work->town.busyFlag == 1) {
            func_02045CAC(work->msgData, 0x34, work->strbufText);
            done = 1;
        }
        if (done == 0 && work->town.sameHomeFlag == 1) {
            func_02045CAC(work->msgData, 0x32, work->strbufText);
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
        func_02045CAC(work->msgData, msg, work->strbufMsg);
        func_0201F02C(work->wordSet, 0, wordArg);
        func_0201F250(work->wordSet, work->strbufText, work->strbufMsg);
        work->pendingPeer = 4;
        done = 1;
    } else if (work->town.sessionState != 0 && work->town.selection != 0
               && (work->town.sessionState == 3 || prev != work->town.sessionState)) {
        if (work->town.sessionState == 3 && sys != 0 && work->town.selection->kind != 4) {
            IntrudePeer *peer;
            IntrudeZoneInfo *peerTown;
            void *fieldMap;

            fieldMap = func_0201210C(work->gameSystem);
            peer = &sys->peers[work->town.selection->peerIndex];
            FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldMap), &pos);
            INTRUDE_COMM_SetWordSetMemberName(work->wordSet, 0, work->town.selection->words, 0x70);
            peerTown = INTRUDE_FIELD_FindZonePos(peer->zoneId);
            if (work->town.homeSlot == work->town.partnerHome && peerTown != 0
                && INTRUDE_SUBDISP_IsZoneMatch(zoneId, peerTown->zoneId, peerTown->zoneIdAlt) == 1) {
                if (peer->package.vanish == 1) {
                    func_02045CAC(work->msgData, 0x2F, work->strbufMsg);
                    func_0201F250(work->wordSet, work->strbufText, work->strbufMsg);
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
                    func_02045CAC(work->msgData, msg, work->strbufMsg);
                    func_0201F250(work->wordSet, work->strbufText, work->strbufMsg);
                    done = 1;
                }
            } else {
                zone1 = INTRUDE_FIELD_FindZonePos(peer->zoneId);
                zone2 = INTRUDE_FIELD_FindZonePos(zoneId);
                if (zone1 != 0 && zone2 != 0 && zone1->x == zone2->x && zone1->y == zone2->y) {
                    func_02045CAC(work->msgData, 0x2F, work->strbufMsg);
                    func_0201F250(work->wordSet, work->strbufText, work->strbufMsg);
                    done = 1;
                }
            }
        }
        if (done == 0 && func_02012B70(gameData) == 1) {
            work->msgState = 0;
            switch (work->town.sessionState) {
            case 1:
                func_02045CAC(work->msgData, 0x21, work->strbufText);
                break;
            case 2:
                func_02045CAC(work->msgData, 0x22, work->strbufText);
                break;
            case 3:
                if (work->msgToggle == 0) {
                    func_02045CAC(work->msgData, work->town.selection->kind + 0x37, work->strbufText);
                } else {
                    func_02045CAC(work->msgDataDetail, work->town.selection->msgId, work->strbufMsg);
                    INTRUDE_COMM_SetWordSetRequest(work->town.selection, work->town.selection->words, work->wordSet, (void *)0x70);
                    func_0201F250(work->wordSet, work->strbufText, work->strbufMsg);
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
        if (GAME_COMM_PopInfoMessage(gameComm, &req) == 1) {
            work->msgState = 0;
            func_02045CAC(work->msgData, req.msgId, work->strbufMsg);
            done = 1;
            for (i = 0; i < 2; i++) {
                if (req.words[i] != 0) {
                    func_0201EE0C(work->wordSet, req.slot[i], (void *)req.words[i], req.param[i], 1, 2);
                }
            }
            func_0201F250(work->wordSet, work->strbufText, work->strbufMsg);
            done = 1;
        }
    }
    if (done == 0 && func_02012B70(gameData) == 1 && func_02013D5C(zoneId) == 0 && func_02013D9C(zoneId) == 0
        && FIELD_PALACE_SYS_IsZoneFlagSet(gameData, zoneId) == 0) {
        func_02045CAC(work->msgData, 0x30, work->strbufText);
        done = 1;
    }
    work->pendingPeer = 4;
    if (done == 1) {
        BMP_Clear(func_02045770(work->infoWin), 0);
        printQue = work->printQue;
        PRINTSYS_PrintQueColor(printQue, func_02045770(work->infoWin), 0, 0, work->strbufText, work->font, 0x3C40);
        work->infoPending = 1;
        work->msgTimer = 0x5A;
    }
}


/*
 * extent: two zero padding bytes at 0x0217EC06.
 * interface: GAME_DATA_GetLastBattleRecSlot tail-forwards func_020127AC's pointer result.
 */
void *INTRUDE_SUBDISP_GetTargetPlayerData(IntrudeSubdispWork *work)
{
    void *gameData;
    int i;
    gameData = func_020120F4(work->gameSystem);
    i = work->town.homeSlot;
    if (i == func_02012B58(gameData) || i == 0x80) {
        return GAME_DATA_GetLastBattleRecSlot(gameData);
    } else {
        return func_020127AC(gameData, i);
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
 *           func_02013D9C's listing extent, called only from here. Verified
 *           EXACT (match.py one --region arm9 --thumb) as:
 *             extern const int d_0209DFC0[];   (0x0209DFC0 data a4)
 *             int func_02013B10(int a0, const int *a1, int a2);
 *             int ZONEDATA_IsZoneInTableDFC0(int a0)
 *             { return func_02013B10(a0, d_0209DFC0, 4); }
 *           Once that leaf is filed and in a shard, this file verifies EXACT.
 */
void INTRUDE_SUBDISP_UpdateTouch(IntrudeCommSys *sys, IntrudeSubdispWork *work, int zoneId)
{
    IntrudeSubdispRect rect;
    u32 touchX;
    u32 touchY;
    IntrudeSubdispPos pt;
    int fieldObj;
    int sel;
    void *gameData;
    int i;
    struct ClactActor *actor;
    int zone;
    const IntrudeTownEntry *entry;
    IntrudeZoneInfo *town;

    fieldObj = FIELDMAP_GetSubscreen(func_0201210C(work->gameSystem));
    func_02012138(work->gameSystem);
    gameData = func_020120F4(work->gameSystem);
    if (work->selectionKind != 0 || work->warpPending == 1 || !func_02035D20(&touchX, &touchY) || FIELD_SUBSCREEN_GetPanelResult(fieldObj) != 0) {
        return;
    }
    sel = func_02012B58(gameData);
    for (i = 0; i < 3; i++) {
        if (i == sel) {
            continue;
        }
        if (!(work->town.peerMask & (1 << i))) {
            continue;
        }
        actor = work->actors[12 + i];
        if (func_0204B3F4(actor) != 1) {
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
    if (work->town.homeSlot != func_02012B58(gameData)) {
        for (i = 0; i < 8; i++) {
            entry = &d_02176AA0[i];
            INTRUDE_SUBDISP_SetTouchRect(entry->x, entry->y, 0x10, 0x10, &rect);
            if (INTRUDE_SUBDISP_IsInTouchRect(touchX, touchY, &rect) != 1) {
                continue;
            }
            zone = entry->zoneA;
            if (zoneId == zone || zoneId == entry->zoneB || (ZONEDATA_IsZoneInTableDFC0(zoneId) == 1 && ZONEDATA_IsZoneInTableDFC0(zone) == 1)) {
                func_020061E4(0x557);
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
    if (work->town.homeSlot != func_02012B58(gameData)) {
        INTRUDE_SUBDISP_SetTouchRect(0x80, 0x5C, 0x10, 0x10, &rect);
        if (INTRUDE_SUBDISP_IsInTouchRect(touchX, touchY, &rect) == 1) {
            if (func_02013D5C(zoneId) == 1) {
                func_020061E4(0x557);
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
            func_0204989C(0x24, 7, 6, 0, 0x800, 1, 0x15);
            work->bgLayerVariant = 1;
            changed++;
        }
    } else {
        if (work->town.peerCount <= 1) {
            func_0204989C(0x24, 6, 6, 0, 0x800, 1, 0x15);
            work->bgLayerVariant = 0;
            changed++;
        }
    }
    if (changed != 0) {
        BMP_WIN_MakeScreen(work->titleWin);
        BMP_WIN_MakeScreen(work->infoWin);
        func_02041B6C(6);
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
    func_020120F4(work->gameSystem);
    func_02012138(work->gameSystem);
    if (work->town.homeSlot != work->lastBgPalette) INTRUDE_SUBDISP_SetBgPalette(work, work->town.homeSlot);
}


void INTRUDE_SUBDISP_SetBgPalette(IntrudeSubdispWork *work, int homeSlot)
{
    func_020413B0(7, 0, 2, 0x20, 0x10, (u8)(homeSlot + 5));
    func_020413B0(6, 0, 2, 0x20, 0x10, (u8)(homeSlot + 1));
    if (work->titleWin != 0) {
        BMP_WIN_MakeScreen(work->titleWin);
        BMP_WIN_MakeScreen(work->infoWin);
    }
    func_02041B6C(7);
    func_02041B6C(6);
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
    gameData = func_020120F4(work->gameSystem);
    if (sys == 0) {
        state->homeSlot = func_02012B58(gameData);
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
    int gameData;
    int n;
    int i;

    state = &work->town;
    gameData = (int)func_020120F4(work->gameSystem);
    if (sys == 0) {
        func_02082BCC(&work->town, 0, 0x14);
        work->lastPeerCount = 1;
        return;
    }
    n = func_02012B58((void *)gameData);
    state->homeSlot = sys->localPeer.intrudeId;
    state->peerMask = sys->peerMask;
    state->peerCount = func_02080D24(state->peerMask);
    state->specialZone = sys->specialZoneEntered;
    state->sessionState = EVENT_COMM_COMMON_GetMissionState(&sys->session);
    state->number = INTRUDE_COMM_GetSessionRemaining(&sys->session);
    state->selection = INTRUDE_COMM_GetActiveSessionRequest(&sys->session);
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
    for (i = 0; i < 7; i++) func_0204B6F4(work->actors[i], 6, 1);
    func_0204B6F4(work->actors[8], 6, 1);
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
            func_0204B6F4(work->actors[cursor], 6, 1);
        } else if (cursor == 8) {
            func_0204B6F4(work->actors[8], 6, 1);
        }
        if (index < 8) {
            func_0204B6F4(work->actors[index], 8, 1);
        } else if (index == 8) {
            func_0204B6F4(work->actors[8], 8, 1);
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
    func_0204B6F4(work->actors[16], 6, 1);
}


void INTRUDE_SUBDISP_UpdateButtonBlink(IntrudeSubdispWork *work)
{
    int count;

    if (work->buttonBlinkActive != 0) {
        count = work->buttonBlinkCount;
        if (count % 2 == 0) {
            func_0204B6F4(work->actors[16], (u8)(((unsigned)count >> 1) & 1 ? 6 : 7), (int)1);
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
    if (func_02012B70(func_020120F4(work->gameSystem)) == 1) {
        switch (work->town.sessionState) {
        case 2: case 3: case 4: return 1;
        }
    }
    return 0;
}


void INTRUDE_SUBDISP_ClearInfoPanel(void)
{
    func_02041300(6, 0x3001, 0x14, 0x16, 0xc, 2, 0x11);
    func_02041B6C(6);
}


void INTRUDE_SUBDISP_DrawInfoPanel(IntrudeSubdispWork *work, int mode)
{
    func_020410D0(6, 0x14, 0x16, 0xC, 2, work->infoPalette, 0, 0, 0xC, 2);
    if (mode == 1) {
        func_02041B6C(6);
    } else {
        func_020409B4(6);
    }
}


/*
 * extent: Two bytes of alignment padding at 0x0217F2B2.
 */
int INTRUDE_SUBDISP_IsAlone(IntrudeSubdispWork *work)
{
    void *gameData = func_020120F4(work->gameSystem);
    if (work->town.selection == 0 && func_02012B58(gameData) == 0 && INTRUDE_COMM_HasUnlockFlags(gameData) == 0) return 1;
    return 0;
}
