/*
 * file:     sta_acting.c
 * unit:     yes
 * function: STA_ACTING_Create, STA_ACTING_Delete, STA_ACTING_Update, STA_ACTING_VBlankCallback, STA_ACTING_InitDisplay, STA_ACTING_UploadPalettes, STA_ACTING_SetBaseProgram, STA_ACTING_SetupBg, STA_ACTING_CreateActors, STA_ACTING_CreateActObj, STA_ACTING_CreateActorSys, STA_ACTING_UpdateCamera, STA_ACTING_LoadCharAnims, STA_ACTING_LoadRankAnim, STA_ACTING_LoadAnimMember, STA_ACTING_FadePalette, STA_ACTING_CreateText, STA_ACTING_UpdateText, STA_ACTING_PrintText, STA_ACTING_ClearText, STA_ACTING_UpdateSelection, STA_ACTING_SetSelection, STA_ACTING_MarkDirty, STA_ACTING_RankScores, STA_ACTING_InstallBgm, STA_ACTING_StartSeq, STA_ACTING_StopSeq, STA_ACTING_ReplaceWaveData, STA_ACTING_PlayBgm, STA_ACTING_StopBgm, STA_ACTING_PlayRankSe, STA_ACTING_RequestAction, STA_ACTING_ApplyAction, STA_ACTING_GetCurrentAction, STA_ACTING_GetActionByIndex, STA_ACTING_ProcessRecords, STA_ACTING_AddScore, STA_ACTING_TickActionTimers, STA_ACTING_ScheduleActions, STA_ACTING_CreateAnimHandle, STA_ACTING_DeleteAnimHandle, STA_ACTING_PositionAnim, STA_ACTING_ShowButton, STA_ACTING_HideButton, STA_ACTING_GetActorSystem, STA_ACTING_GetActor, STA_ACTING_GetActObj, STA_ACTING_GetSlot, STA_ACTING_SetSlot, STA_ACTING_GetEffectSystem, STA_ACTING_GetAnimSlot, STA_ACTING_SetAnimSlot, STA_ACTING_GetCharSystem, STA_ACTING_GetCharSlot, STA_ACTING_SetCharSlot, STA_ACTING_GetAudience, STA_ACTING_GetCameraPos, STA_ACTING_SetCameraPos, STA_ACTING_GetCameraScrollX, STA_ACTING_SetCameraTarget, STA_ACTING_GetActorCount, STA_ACTING_GetSelection, STA_ACTING_GetRecordScore, STA_ACTING_GetBonus, STA_ACTING_SetCameraHoldScore
 * address:  0x021F8480
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from sta_acting.c, script_command.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   STA_NET_GetCurrentSlotValue 0x021FD8D4 thumb ov132
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   STA_ACT_LIGHT_CreateUnit 0x021F6BD8 thumb ov112
 *   STA_ACT_AUDIENCE_Create 0x021F9FEC thumb ov132
 *   STA_ACT_BUTTON_Create 0x021FA5B0 thumb ov132
 *   STA_ACT_SCRIPT_Create 0x021FAAF4 thumb ov132
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   d_021FDCA0 0x021FDCA0 data a1
 *   g_02FFFC3C 0x02FFFC3C data a4
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GFL_USE_StopSeqAndUnload 0x02006504 thumb
 *   GFL_USE_ClearPreloadedBgmBuffers 0x02006518 thumb
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   STA_ACT_SCRIPT_Delete 0x021FAB58 thumb ov132
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   STA_ACT_BUTTON_Delete 0x021FA64C thumb ov132
 *   STA_ACT_AUDIENCE_Delete 0x021FA04C thumb ov132
 *   STA_ACT_LIGHT_DeleteModel 0x021F6F4C thumb ov112
 *   STA_ACT_LIGHT_DeleteUnit 0x021F6C7C thumb ov112
 *   STA_ACT_EFFECT_Delete 0x021F9E94 thumb ov132
 *   STA_ACT_OBJ_Delete 0x021F6A24 thumb ov112
 *   STA_ACT_LIGHT_DeleteBillboardImage 0x021F7120 thumb ov112
 *   MUSICAL_MCSS_DeleteRenderObj 0x021F51B0 thumb ov112
 *   MUSICAL_MCSS_DeleteActorPool 0x021F4948 thumb ov112
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BILLBOARD_Delete 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STA_ACT_BUTTON_Update 0x021FA6CC thumb ov132
 *   STA_ACT_SCRIPT_Update 0x021FABD8 thumb ov132
 *   STA_ACT_EFFECT_Update 0x021F9ECC thumb ov132
 *   STA_ACT_AUDIENCE_Update 0x021FA064 thumb ov132
 *   STA_ACT_EFFECT_Draw 0x021F9ED4 thumb ov132
 *   STA_ACT_EFFECT_Noop 0x021F9E4C thumb ov132
 *   STA_ACT_SCRIPT_CountScripts 0x021FAD7C thumb ov132
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 *   MUS_COMM_FUNC_CheckTimingSync 0x021FCE00 thumb ov132
 *   STA_ACT_LIGHT_StepModelAnim 0x021F6F64 thumb ov112
 *   STA_ACT_LIGHT_UpdateBillboard 0x021F7160 thumb ov112
 *   STA_ACT_OBJ_Update 0x021F6A58 thumb ov112
 *   MUSICAL_MCSS_TickAnim 0x021F51E8 thumb ov112
 *   STA_ACT_LIGHT_UpdateElemActors 0x021F6CB0 thumb ov112
 *   STA_ACT_LIGHT_NoOp 0x021F6E74 thumb ov112
 *   STA_ACT_LIGHT_UpdateElem 0x021F75A0 thumb ov112
 *   MUSICAL_MCSS_DrawRenderObj 0x021F51F4 thumb ov112
 *   STA_ACT_LIGHT_UpdateSprite 0x021F718C thumb ov112
 *   STA_ACT_LIGHT_DrawModel 0x021F6F8C thumb ov112
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   d_021FDE80 0x021FDE80 data a4
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   BG_SYS_EnableBg0WithPriority 0x0204044C arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3X_SetEdgeColorTable 0x0207DCF8 arm
 *   BILLBOARD_Create 0x0204EBD4 arm
 *   BILLBOARD_SetScale 0x0204ED70 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   d_021FDBA0 0x021FDBA0 data a4
 *   d_021FDAA0 0x021FDAA0 data a4
 *   d_021FDB40 0x021FDB40 data a4
 *   d_021FDB60 0x021FDB60 data a4
 *   d_021FDB80 0x021FDB80 data a4
 *   d_021FDAC0 0x021FDAC0 data a4
 *   d_021FDAE0 0x021FDAE0 data a4
 *   d_021FDB00 0x021FDB00 data a4
 *   d_021FDB20 0x021FDB20 data a4
 *   d_021FDAB0 0x021FDAB0 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   d_021FDA7C 0x021FDA7C data a4
 *   d_021FDBF8 0x021FDBF8 data a4
 *   d_021FDBD4 0x021FDBD4 data a4
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   STA_ACT_LIGHT_AllocElem 0x021F6F24 thumb ov112
 *   MUSICAL_PROGRAM_GetBaseProgramId  0x02157364  thumb  ov010
 *   STA_ACT_LIGHT_CreateModel  0x021F6FB0  thumb  ov112
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   MUSICAL_MCSS_CreateRenderObj 0x021F5164 thumb ov112
 *   MUSICAL_MCSS_SetRenderCellVramBase 0x021F5438 thumb ov112
 *   MUSICAL_MCSS_CreateActorPool 0x021F48C0 thumb ov112
 *   STA_ACT_LIGHT_AddBillboardImage 0x021F709C thumb ov112
 *   STA_ACT_LIGHT_AddPokemonElem 0x021F760C thumb ov112
 *   STA_ACT_LIGHT_SetActorPos 0x021F8054 thumb ov112
 *   d_021FDBE0 0x021FDBE0 data a4
 *   STA_ACT_OBJ_Create 0x021F69E4 thumb ov112
 *   STA_ACT_EFFECT_Create 0x021F9E50 thumb ov132
 *   STA_ACT_LIGHT_CopyActorPos 0x021F8044 thumb ov112
 *   STA_ACT_LIGHT_GetElemPos 0x021F6F04 thumb ov112
 *   STA_ACT_LIGHT_SetModelFrame 0x021F7098 thumb ov112
 *   STA_ACT_LIGHT_SetElemFrame 0x021F75DC thumb ov112
 *   STA_ACT_OBJ_SetCount 0x021F6AF0 thumb ov112
 *   STA_ACT_AUDIENCE_SetBgScroll 0x021FA57C thumb ov132
 *   KEY_GetCont 0x0203630C arm
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_SetCamTarget 0x02048B44 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   d_021FDBEC 0x021FDBEC data a4
 *   STA_ACT_SCRIPT_AddScript 0x021FAC74 thumb ov132
 *   d_021FDBD0 0x021FDBD0 data a1
 *   ARC_UTIL_LoadHandleMember 0x0204A380 arm
 *   STA_ACT_SCRIPT_AddScriptFromTable 0x021FAD0C thumb ov132
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromMemory 0x02045C44 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   STA_ACT_AUDIENCE_SetSlotValue 0x021FA558 thumb ov132
 *   STA_ACT_AUDIENCE_SetHighlight 0x021FA56C thumb ov132
 *   GFL_USE_InstallBgmBuffers  0x02006448  thumb
 *   GFL_USE_StartSeq  0x020064F4  thumb
 *   GFL_USE_ReplaceWaveData  0x020064B8  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   STA_ACT_LIGHT_IsElemActive 0x021F7A80 thumb ov112
 *   STA_NET_SendKindA 0x021FD8C4 thumb ov132
 *   STA_ACT_LIGHT_HandleElemAnim 0x021F79A8 thumb ov112
 *   GFL_USE_GetRandomBelow 0x02005728 thumb
 *   STA_SLOT_GetCurrentKey 0x021FD9FC thumb ov132
 *   STA_SLOT_GetStateByKey 0x021FD9A0 thumb ov132
 *   STA_SLOT_ClearCurrent 0x021FDA18 thumb ov132
 *   STA_SLOT_ResetStateByKey 0x021FD9D0 thumb ov132
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   STA_SLOT_PushRecord 0x021FDA24 thumb ov132
 *   MUSICAL_MCSS_GetElemA 0x021F5140 thumb ov112
 *   MUSICAL_PROGRAM_GetCategoryShare 0x02157394 thumb ov010
 *   STA_SLOT_SetValueByKey 0x021FD974 thumb ov132
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   STA_ACT_EFFECT_StartSystem  0x021F9EDC  thumb
 *   STA_ACT_EFFECT_KillSystem  0x021F9F58  thumb
 *   STA_ACT_EFFECT_StartEffect 0x021F9F74 thumb ov132
 *   STA_ACT_BUTTON_SetVisible  0x021FAAB8  thumb
 *   MUSICAL_MCSS_GetActorPoolResource 0x021F4F10 thumb ov112
 *   STA_ACTING_GetCameraPos 0x021F9DFC thumb ov132
 *   STA_ACTING_GetCameraScrollX 0x021F9E04 thumb ov132
 *   STA_ACTING_GetActorSystem 0x021F9DA0 thumb ov132
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   STA_ACTING_GetCharSystem 0x021F9DD4 thumb ov132
 *   STA_ACTING_GetCharSlot 0x021F9DDC thumb ov132
 *   STA_ACTING_RequestAction 0x021F9730 thumb ov132
 *   STA_ACTING_GetCurrentAction 0x021F9768 thumb ov132
 *   STA_ACTING_GetActorCount 0x021F9E0C thumb ov132
 *   STA_ACTING_PlayRankSe 0x021F96D0 thumb ov132
 *   STA_ACTING_SetCameraPos 0x021F9E00 thumb ov132
 *   STA_ACTING_SetCameraTarget 0x021F9E08 thumb ov132
 *   STA_ACTING_ShowButton  0x021F9D80  thumb
 *   STA_ACTING_ScheduleActions  0x021F9AD8  thumb
 *   STA_ACTING_HideButton  0x021F9D90  thumb
 *   STA_ACTING_PositionAnim 0x021F9D18 thumb ov132
 *   STA_ACTING_SetSelection 0x021F95CC thumb ov132
 *   STA_ACTING_LoadRankAnim 0x021F9140 thumb ov132
 *   STA_ACTING_LoadAnimMember 0x021F91A8 thumb ov132
 *   STA_ACTING_GetRecordScore 0x021F9E20 thumb ov132
 *   STA_ACTING_GetBonus 0x021F9E34 thumb ov132
 *   STA_ACTING_SetCameraHoldScore 0x021F9E3C thumb ov132
 *   STA_ACTING_GetActObj 0x021F9DAC thumb ov132
 *   STA_ACTING_SetSlot 0x021F9DB8 thumb ov132
 *   STA_ACTING_GetSlot 0x021F9DB0 thumb ov132
 *   STA_ACTING_GetEffectSystem 0x021F9DC0 thumb ov132
 *   STA_ACTING_SetAnimSlot 0x021F9DCC thumb ov132
 *   STA_ACTING_GetAnimSlot 0x021F9DC4 thumb ov132
 *   STA_ACTING_SetCharSlot 0x021F9DE8 thumb ov132
 *   STA_ACTING_MarkDirty 0x021F95E8 thumb ov132
 *   STA_ACTING_GetAudience 0x021F9DF4 thumb ov132
 *   STA_ACTING_PrintText 0x021F93D8 thumb ov132
 *   STA_ACTING_ClearText  0x021F94B0  thumb
 *   STA_ACTING_InstallBgm  0x021F9664  thumb
 *   STA_ACTING_StartSeq  0x021F9680  thumb
 *   STA_ACTING_StopSeq  0x021F9690  thumb
 *   STA_ACTING_ReplaceWaveData 0x021F969C thumb ov132
 *   STA_ACTING_PlayBgm  0x021F96B0  thumb
 *   STA_ACTING_StopBgm  0x021F96C4  thumb
 *   _fadd                        0x0209C95C  arm
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _ffltu                       0x0209BE04  arm
 *   _fgr                         0x0209BBB0  arm
 *   _fmul                        0x0209C77C  arm
 *   _fsub                        0x0209CB8C  arm
 *   _ull_mul                     0x0209C054  arm
 */
#include "ov132_types.h"
#include "../sdk_ioreg.h"
#include "sta_acting_shared_types.h"
#ifdef __MWERKS__
#define G3D_SYSTEM_Init G3D_SYSTEM_Init_hdr
#endif
#include "../arm9/g3d_system.h"
#ifdef __MWERKS__
#undef G3D_SYSTEM_Init
void G3D_SYSTEM_Init(unsigned int,unsigned int,unsigned int,unsigned int,u16,u16,void (*)(void));
#endif
#ifdef __MWERKS__
#define BG_SYS_SetPlaneVisible BG_SYS_SetPlaneVisible_hdr
#define BG_SYS_FreeSlot BG_SYS_FreeSlot_hdr
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_SetPlaneVisible
#undef BG_SYS_FreeSlot
void BG_SYS_SetPlaneVisible(u32 which, unsigned char enable);
void BG_SYS_FreeSlot(u32);
#endif

#define FX(x) ((int)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))

struct Descriptor;

struct PrintSys;

struct Rec;

struct S02031140;

struct U16Vec;

struct Board;

struct Camera;

struct Lights;

struct BgTemplate;

struct Blk3;

struct Cfg;

struct DispConfig;

struct DispVram;

struct Light;

struct GfFont;

struct MsgBank;

struct Tcbl;

struct Rec3;

struct CharBuf;

#include "../types.h"

typedef struct { unsigned int w[3]; } StaActingVec3;

typedef struct { StaActingVec3 a,b,c; } Vectors;

typedef struct { unsigned int w[7]; } Blob28;

#include "../sdk_gx.h"

struct Slots { u8 pad[0x44]; void *slots[4]; };

typedef struct Object Object;

struct Bytes { u8 a, b, c, d; };

typedef struct {
    u8 pad[0x168];
    u16 phase;
    u16 base[16];
    s8 dr[16];
    s8 dg[16];
    s8 db[16];
    u16 out[16];
} StaActingFade;

typedef enum { ZERO } Zero;

typedef enum { ENABLED = 1 } Enabled;

typedef enum { ACTION7 = 7, ACTION8 = 8 } StaActingAction;

#include "../arm9/gfl_heap_wrap.h"
struct TcbTask;

#include "../arm9/gfl_use.h"

#include "sta_net.h"

#include "../arm9/arc_tool.h"


#include "sta_act_audience.h"

#include "sta_act_button.h"

#include "sta_act_script.h"

#include "../arm9/net.h"




#include "../arm9/gx.h"

#include "../arm9/g2.h"

struct Strbuf;

#include "../arm9/strbuf.h"
struct PrintQueue;

#ifdef __MWERKS__
#define PRINTSYS_PrintStream PRINTSYS_PrintStream_hdr
#define PRINTSYS_PrintQue PRINTSYS_PrintQue_hdr
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintStream
#undef PRINTSYS_PrintQue
void *PRINTSYS_PrintStream(void *, u32, u32, void *, void *, u32, void *, u32, u16, u32);
void PRINTSYS_PrintQue(struct PrintQueue *, struct Bmp *, u32, u32, struct Strbuf *, struct GfFont *);
#endif


#include "../arm9/msgdata.h"
struct BmpWin;

#include "../arm9/bmp_win.h"

#include "../arm9/gf_font.h"
struct TcblSystem;

#include "../arm9/tcbl.h"



#include "../ov112/sta_act_bg.h"

#include "../ov112/sta_act_light.h"

#include "sta_act_effect.h"

#include "../ov112/sta_act_obj.h"

#include "../ov112/sta_act_poke.h"

#include "../ov112/mus_poke_draw.h"

#include "../ov112/mus_item_draw.h"

#include "../arm9/clact.h"

#include "../arm9/billboard.h"

#include "../arm9/g3d_camera.h"

extern void G3D_SYSTEM_Exit(void);



struct TcbTask;

#include "../arm9/tcb_list.h"



#include "../arm9/wipe.h"


#include "../arm9/net_err.h"


#include "mus_comm_func.h"



















extern void G3D_SYSTEM_DrawStart(void);

extern void G3D_SYSTEM_ApplyLookAt(void);

extern void G3D_SYSTEM_DrawEnd(void);


struct LightSlot;
struct BbBoard;
struct G3dCamera;













extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned int,unsigned int);

struct G3dCamera;


#include "../arm9/g3x.h"


struct DispVramCfg;
struct SysInit;


#include "../arm9/arc_util.h"




#include "../arm9/mi_memory.h"


struct MusicalShowProgram;

#include "../ov010/musical_program.h"





struct McssActorPool;







#include "../arm9/key.h"













#include "../arm9/nns_gfd_vram_transfer.h"









struct TextPrinter;




struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"















#ifdef __MWERKS__
#define STA_SLOT_GetStateByKey STA_SLOT_GetStateByKey_hdr
#endif
#include "sta_slot.h"
#ifdef __MWERKS__
#undef STA_SLOT_GetStateByKey
int STA_SLOT_GetStateByKey(void *, unsigned);
#endif




struct StaSlotOwner;


#include "../ov112/mus_item_data.h"



#include "../arm9/gf_standard.h"






u8 *STA_ACTING_Create(u8 *input, int heap);

void STA_ACTING_Delete(char *p);

int STA_ACTING_Update(u8 *p);

void STA_ACTING_VBlankCallback(void);

void STA_ACTING_InitDisplay(u8 *p);

void STA_ACTING_UploadPalettes(u8 *p);

void STA_ACTING_SetBaseProgram(u8 *p, u32 unused);

void STA_ACTING_SetupBg(const struct BgTemplate *p,u32 id,u32 type);

void STA_ACTING_CreateActors(u8 *p);

void STA_ACTING_CreateActObj(char *p);

void STA_ACTING_CreateActorSys(char *p);

void STA_ACTING_UpdateCamera(u8 *p);

void STA_ACTING_LoadCharAnims(u8 *p);

void STA_ACTING_LoadRankAnim(u8 *p, u8 n, u8 i);

void STA_ACTING_LoadAnimMember(char *p, u8 n, u8 mask);

void STA_ACTING_FadePalette(StaActingFade *p);

void STA_ACTING_CreateText(u8 *p);

void STA_ACTING_UpdateText(u8 *p);

void STA_ACTING_PrintText(u8 *p, u16 index, u32 speed);

void STA_ACTING_ClearText(u8 *p);

void STA_ACTING_UpdateSelection(char *p);

void STA_ACTING_SetSelection(char *p, u8 v, int c);

void STA_ACTING_MarkDirty(char *p);

void STA_ACTING_RankScores(u8 *p);

void STA_ACTING_InstallBgm(char *p, int a);

void STA_ACTING_StartSeq(char *p, int a);

void STA_ACTING_StopSeq(char *p);

int STA_ACTING_ReplaceWaveData(char *p, u32 a, u32 b, u32 d);

void STA_ACTING_PlayBgm(char *p, int a);

void STA_ACTING_StopBgm(char *p);

void STA_ACTING_PlayRankSe(char *p);

void STA_ACTING_RequestAction(char *p,int value);

void STA_ACTING_ApplyAction(char *p, u32 i, int v);

int STA_ACTING_GetCurrentAction(char *p);

int STA_ACTING_GetActionByIndex(char *p,u32 i);

void STA_ACTING_ProcessRecords(char *p);

int STA_ACTING_AddScore(char *p, unsigned i, unsigned j);

void STA_ACTING_TickActionTimers(char *p);

void STA_ACTING_ScheduleActions(char *p, int mode, u8 slot);

void STA_ACTING_CreateAnimHandle(char *p);

void STA_ACTING_DeleteAnimHandle(char *p);

void STA_ACTING_PositionAnim(char *p, unsigned i);

void STA_ACTING_ShowButton(char *p);

void STA_ACTING_HideButton(char *p);

void *STA_ACTING_GetActorSystem(char *p);

void *STA_ACTING_GetActor(char *p,u32 i);

void *STA_ACTING_GetActObj(void *p);

u32 *STA_ACTING_GetSlot(void *p,u8 i);

void STA_ACTING_SetSlot(void *p,void *v,u32 i);

void *STA_ACTING_GetEffectSystem(void *p);

void *STA_ACTING_GetAnimSlot(void *p,u8 i);

void STA_ACTING_SetAnimSlot(void *p,void *v,u32 i);

void *STA_ACTING_GetCharSystem(void *p);

void *STA_ACTING_GetCharSlot(void *p,u8 i);

void STA_ACTING_SetCharSlot(void *p,void *v,u8 i);

void *STA_ACTING_GetAudience(void *p);

u16 STA_ACTING_GetCameraPos(void *p);

void STA_ACTING_SetCameraPos(void *p,u16 v);

u16 STA_ACTING_GetCameraScrollX(u8 *p);

void STA_ACTING_SetCameraTarget(u8 *p,u16 v);

u32 STA_ACTING_GetActorCount(u8 *p);

int STA_ACTING_GetSelection(char *p);

extern const char d_021FDCA0[];

extern unsigned int g_02FFFC3C;

extern unsigned int d_02FFFC3C;

extern unsigned int d_021FDE80;

extern const Vectors d_021FDA7C;

extern const Blob28 d_021FDBF8;

extern const StaActingVec3 d_021FDBD4;

extern const unsigned int d_021FDBA0[];

extern const unsigned int d_021FDAA0[];

extern const unsigned int d_021FDB40[];

extern const unsigned int d_021FDB60[];

extern const unsigned int d_021FDB80[];

extern const unsigned int d_021FDAC0[];

extern const unsigned int d_021FDAE0[];

extern const unsigned int d_021FDB00[];

extern const unsigned int d_021FDB20[];

extern const unsigned int d_021FDAB0[];

extern const unsigned int gClActorInitParam[];

extern const struct StaActingVec d_021FDBE0;

extern const StaActingVec d_021FDBEC;

extern const struct Bytes d_021FDBD0;

extern const signed short FX_SinCosTable_[];

u8 *STA_ACTING_Create(u8 *input, int heap)
{
    u8 *p;
    u8 i;
    p=GFL_HEAP_Alloc(heap,0x1f0,1,d_021FDCA0,0x11a);
    *(u16 *)p=heap;
    *(void **)(p+0x30)=input;
    i=0;
    *(u16 *)(p+2)=0;
    *(u16 *)(p+4)=127;
    *(u16 *)(p+6)=128;
    *(u16 *)(p+8)=0;
    *(unsigned int *)(p+0xb4)=0;
    *(unsigned int *)(p+0x1c)=0;
    *(unsigned int *)(p+0x164)=0;
    *(unsigned int *)(p+0xc)=1;
    *(unsigned int *)(p+0x14)=0;
    *(unsigned int *)(p+0x10)=0;
    *(unsigned int *)(p+0x24)=0;
    *(unsigned int *)(p+0x28)=0;
    *(unsigned int *)(p+0x2c)=0;
    *(void **)(p+0x20)=GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))STA_ACTING_VBlankCallback,(void *)p,64);
    if(**(unsigned int **)(p+0x30)==0){
        for(;i<4;i++){
            if(**(unsigned int **)(*(u8 **)(p+0x30)+4+i*4)==0){p[0xa]=i;break;}
        }
        if(i==4)p[0xa]=1;
    }else p[0xa]=STA_NET_GetCurrentSlotValue((void *)**(unsigned int **)(p+0x30));
    for(i=0;i<4;i++)p[0xf7+i]=0;
    STA_ACTING_RankScores(p);
    *(unsigned int *)(p+0xec)=1;
    p[0xf0]=4;
    p[0xf1]=4;
    p[0xf2]=4;
    p[0x11c]=4;
    *(u16 *)(p+0x11e)=0;
    *(unsigned int *)(p+0x15c)=0;
    *(u16 *)(p+0x168)=0;
    for(i=0;i<4;i++){
        *(unsigned int *)(p+0xfc+i*4)=0;
        *(u16 *)(p+0x124+i*2)=0;
        *(unsigned int *)(p+0x13c+i*8)=0;
        *(unsigned int *)(p+0x140+i*8)=0;
    }
    *(void **)(p+0x18)=ARC_TOOL_CreateHandle(47,*(u16 *)p);
    STA_ACTING_InitDisplay(p);
    STA_ACTING_UploadPalettes(p);
    STA_ACTING_CreateText(p);
    STA_ACTING_CreateActors(p);
    STA_ACTING_CreateActObj((char *)p);
    STA_ACTING_CreateActorSys((char *)p);
    *(void **)(p+0x90)=STA_ACT_LIGHT_CreateUnit(*(u16 *)p,p);
    *(void **)(p+0xb8)=STA_ACT_AUDIENCE_Create(*(u16 *)p,p,*(unsigned int *)(p+0x30));
    *(void **)(p+0xa4)=STA_ACT_BUTTON_Create(*(u16 *)p,p,*(char **)(*(u8 **)(p+0x30)+p[0xa]*4+4));
    *(void **)(p+0xb0)=STA_ACT_SCRIPT_Create(*(u16 *)p,p);
    STA_ACTING_CreateAnimHandle((char *)p);
    GFL_NET_RefreshWmIconAtTopRight(0,*(u16 *)p);
    STA_ACTING_SetBaseProgram(p,0);
    *(unsigned int *)(p+0x1dc)=*(unsigned int *)((*(u8 ***)(p+0x30))[6]+0x14);
    *(unsigned int *)(p+0x1e0)=*(unsigned int *)((*(u8 ***)(p+0x30))[6]+0x18);
    *(unsigned int *)(p+0x1e4)=*(unsigned int *)((*(u8 ***)(p+0x30))[6]+0x1c);
    *(unsigned int *)(p+0x1ec)=g_02FFFC3C;
    return p;
}

/*
 * volatile: hardware display register 0x04000000 read at 0x021F868C.
 */
void STA_ACTING_Delete(char *p)
{
    if(((struct ActingScene *)p)->bgmPlaying.u==1)GFL_USE_CancelChangeAndStopBgm();
    if(((struct ActingScene *)p)->seqPlaying.u==1)GFL_USE_StopSeqAndUnload();
    if(((struct ActingScene *)p)->bgmBuffersInstalled.u==1)GFL_USE_ClearPreloadedBgmBuffers();
    GXx_SetMasterBrightness_((volatile u16 *)REG_MASTER_BRIGHT_ADDR,-16);
    GXx_SetMasterBrightness_((volatile u16 *)REG_DB_MASTER_BRIGHT_ADDR,-16);
    G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,0,0,31,31);
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    STA_ACTING_DeleteAnimHandle(p);
    STA_ACT_SCRIPT_Delete(((struct ActingScene *)p)->scriptSystem);
    if(((struct ActingScene *)p)->strBuf.p!=0)STRBUF_Delete(((struct ActingScene *)p)->strBuf.p);
    PRINTSYS_QUE_Clear(((struct ActingScene *)p)->printQueue.p);
    PRINTSYS_QUE_Delete(((struct ActingScene *)p)->printQueue.p);
    MSGDATA_Delete(((struct ActingScene *)p)->msgData.p);
    BMP_WIN_Delete(((struct ActingScene *)p)->bmpWin.p);
    GF_FONT_Delete(((struct ActingScene *)p)->font.p);
    TCBL_Destroy(((struct ActingScene *)p)->textTcbl.p);
    STA_ACT_BUTTON_Delete(*(char * *)&((struct ActingScene *)p)->button);
    STA_ACT_AUDIENCE_Delete(((struct ActingScene *)p)->audience);
    STA_ACT_LIGHT_DeleteModel(((struct ActingScene *)p)->model);
    STA_ACT_LIGHT_DeleteUnit(((struct ActingScene *)p)->charSystem);
    STA_ACT_EFFECT_Delete(((struct ActingScene *)p)->effectSystem);
    STA_ACT_OBJ_Delete(((struct ActingScene *)p)->actObj);
    STA_ACT_LIGHT_DeleteBillboardImage(((struct ActingScene *)p)->actorSystem);
    MUSICAL_MCSS_DeleteRenderObj((sptr)(((struct ActingScene *)p)->mcssRender));
    MUSICAL_MCSS_DeleteActorPool(((struct ActingScene *)p)->actorPool);
    CLACT_ExitSystem();
    BILLBOARD_Delete(((struct ActingScene *)p)->billboard.p);
    G3D_CAMERA_Delete(((struct ActingScene *)p)->camera);
    G3D_SYSTEM_Exit();
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(7);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    TCB_DeleteTask(((struct ActingScene *)p)->vblankTask);
    ARC_TOOL_DeleteHandle(((struct ActingScene *)p)->arcHandle.p);
    GFL_HEAP_Free(p);
}

/*
 * extent: lead followed by 021F8994 tail-call stub.
 * note: 021F6E74 retains the explicitly loaded pointer despite own void prototype.
 */
int STA_ACTING_Update(u8 *p)
{
    unsigned int tick;
    tick=d_02FFFC3C;
    ((struct ActingScene *)p)->elapsedTicks=tick-((struct ActingScene *)p)->lastTick.u;
    ((struct ActingScene *)p)->lastTick.u=tick;
    switch(((struct ActingScene *)p)->phase) {
    case 0:
        WIPE_SYS_Start(0,1,1,0,6,1,((struct ActingScene *)p)->heapId);
        ((struct ActingScene *)p)->phase=1;
        break;
    case 1:
        if(WIPE_SYS_EndCheck()==1) {
            if(**(unsigned int * *)&((struct ActingScene *)p)->input!=0) {
                ((struct ActingScene *)p)->phase=7;
                MUS_COMM_FUNC_SetTimingSync(**(int * *)&((struct ActingScene *)p)->input,200);
            } else ((struct ActingScene *)p)->phase=4;
        }
        break;
    case 2:
        if(GFL_USE_IsAnySeBusy()==0) {
            WIPE_SYS_Start(0,0,0,0,6,1,((struct ActingScene *)p)->heapId);
            ((struct ActingScene *)p)->phase=3;
        }
        break;
    case 3:
        if(WIPE_SYS_EndCheck()==1) return 1;
        break;
    case 4:
        if((((struct ActingScene *)p)->introTimer)++ >=60) ((struct ActingScene *)p)->phase=5;
        break;
    case 5:
        if(((struct ActingScene *)p)->abortRequested==0) {
            ((struct ActingScene *)p)->charAnimTable.u=((struct ActingPartB *)(*(u8 * *)&((struct ActingPartA *)(*(u8 * *)&((struct ActingScene *)p)->input))->resources))->charAnims;
            STA_ACTING_LoadCharAnims(p);
            ((struct ActingScene *)p)->phase=6;
        }
        break;
    case 6:
        if(STA_ACT_SCRIPT_CountScripts(*(char * *)&((struct ActingScene *)p)->scriptSystem)==0) {
            ((struct ActingScene *)p)->charAnimTable.u=0;
            if(((struct ActingScene *)p)->abortRequested==0) ((struct ActingScene *)p)->phase=2;
            else ((struct ActingScene *)p)->phase=255;
        }
        break;
    case 7:
        if(MUS_COMM_FUNC_CheckTimingSync(*(void **)*(u8 * *)&((struct ActingScene *)p)->input,200)==1)
            ((struct ActingScene *)p)->phase=4;
        break;
    }
    STA_ACTING_UpdateCamera(p);
    STA_ACT_BUTTON_Update((char *)(*(u8 * *)&((struct ActingScene *)p)->button));
    STA_ACTING_ProcessRecords((char *)p);
    if(d_021FDE80==0) STA_ACT_SCRIPT_Update((char *)(*(u8 * *)&((struct ActingScene *)p)->scriptSystem));
    STA_ACT_LIGHT_StepModelAnim(*(u8 * *)&((struct ActingScene *)p)->model);
    STA_ACT_LIGHT_UpdateBillboard(*(u8 * *)&((struct ActingScene *)p)->actorSystem);
    STA_ACT_OBJ_Update((char *)(*(u8 * *)&((struct ActingScene *)p)->actObj));
    STA_ACT_EFFECT_Update(*(u8 * *)&((struct ActingScene *)p)->effectSystem);
    STA_ACTING_UpdateText(p);
    MUSICAL_MCSS_TickAnim(*(u8 * *)&((struct ActingScene *)p)->mcssRender);
    STA_ACT_LIGHT_UpdateElemActors((char *)(*(u8 * *)&((struct ActingScene *)p)->charSystem));
    STA_ACTING_UpdateSelection((char *)p);
    STA_ACT_AUDIENCE_Update((char *)(*(u8 * *)&((struct ActingScene *)p)->audience));
    STA_ACTING_FadePalette((StaActingFade *)p);
    G3D_SYSTEM_DrawStart(); G3D_SYSTEM_ApplyLookAt();
    STA_ACT_LIGHT_NoOp(*(u8 * *)&((struct ActingScene *)p)->charSystem);
    STA_ACT_LIGHT_UpdateElem(*(u8 * *)&((struct ActingScene *)p)->actorSystem);
    MUSICAL_MCSS_DrawRenderObj((void **)(*(u8 * *)&((struct ActingScene *)p)->mcssRender));
    STA_ACT_LIGHT_UpdateSprite((char *)(*(u8 * *)&((struct ActingScene *)p)->actorSystem));
    STA_ACT_LIGHT_DrawModel(*(u8 * *)&((struct ActingScene *)p)->model);
    BILLBOARD_Draw(((struct ActingScene *)p)->billboard.p,((struct ActingScene *)p)->camera,0);
    STA_ACT_EFFECT_Draw(*(u8 * *)&((struct ActingScene *)p)->effectSystem);
    STA_ACT_EFFECT_Noop(p);
    G3D_SYSTEM_DrawEnd(); CLACT_DrawSystem();
    if(**(unsigned int * *)&((struct ActingScene *)p)->input!=0 && ((struct ActingScene *)p)->phase!=0 &&
       ((struct ActingScene *)p)->phase!=1 && ((struct ActingScene *)p)->phase!=2 &&
       ((struct ActingScene *)p)->phase!=3 && GFL_NET_ERR_GetErrorLevel()!=0)
        ((struct ActingScene *)p)->phase=2;
    return 0;
}

void STA_ACTING_VBlankCallback(void) { CLACT_VBlankSystem(); }

static inline void GX_SetVisiblePlane(int plane) { *(volatile unsigned int *)REG_DISPCNT_ADDR=(*(volatile unsigned int *)REG_DISPCNT_ADDR&~0x1F00u)|((unsigned int)plane<<8); }

static inline void GXS_SetVisiblePlane(int plane) { *(volatile unsigned int *)REG_DB_DISPCNT_ADDR=(*(volatile unsigned int *)REG_DB_DISPCNT_ADDR&~0x1F00u)|((unsigned int)plane<<8); }

static inline void GX_SetDispSelect(GXDispSelect sel) { *(volatile u16 *)REG_POWCNT1_ADDR=(u16)((*(volatile u16 *)REG_POWCNT1_ADDR&~0x8000u)|(sel<<15)); }

static inline void G3X_EdgeMarking(BOOL enable) { if(enable) *(volatile u16 *)REG_DISP3DCNT_ADDR=(u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR&~0x3000u)|0x20); else *(volatile u16 *)REG_DISP3DCNT_ADDR&=(u16)~0x3020; }

static inline void G3X_AntiAlias(BOOL enable) { if(enable) *(volatile u16 *)REG_DISP3DCNT_ADDR=(u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR&~0x3000u)|0x10); else *(volatile u16 *)REG_DISP3DCNT_ADDR&=(u16)~0x3010; }

static inline void G3X_AlphaBlend(BOOL enable) { if(enable) *(volatile u16 *)REG_DISP3DCNT_ADDR=(u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR&~0x3000u)|8); else *(volatile u16 *)REG_DISP3DCNT_ADDR&=(u16)~0x3008; }

static inline void GX_SetVisibleWnd(int window) { *(volatile unsigned int *)REG_DISPCNT_ADDR=(*(volatile unsigned int *)REG_DISPCNT_ADDR&~0xE000u)|((unsigned int)window<<13); }

static inline void G2_SetWndOBJInsidePlane(int wnd,BOOL effect) { unsigned int tmp; tmp=(*(volatile u16 *)REG_WINOUT_ADDR&~0x3F00u)|((unsigned int)wnd<<8); if(effect) tmp|=0x2000; *(volatile u16 *)REG_WINOUT_ADDR=(u16)tmp; }

static inline void G2_SetWndOutsidePlane(int wnd,BOOL effect) { unsigned int tmp; tmp=(*(volatile u16 *)REG_WINOUT_ADDR&~0x3Fu)|(unsigned int)wnd; if(effect) tmp|=0x20; *(volatile u16 *)REG_WINOUT_ADDR=(u16)tmp; }

void STA_ACTING_InitDisplay(u8 *p)
{
    Blob28 big;
    StaActingVec3 small;
    void *light,*board;
    BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0); GXS_SetVisiblePlane(0);
    WIPE_SetBrightnessFadeOut(0,0); WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0); WIPE_ResetWndMask((void *)1);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021FDBA0);
    BG_SYS_Create(*(u16 *)p); BMP_WIN_Init(*(u16 *)p);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021FDAA0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB40,1,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB60,2,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB80,3,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDAC0,5,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDAE0,6,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB00,4,0);
    STA_ACTING_SetupBg((const struct BgTemplate *)d_021FDB20,7,0);
    BG_SYS_SetPlaneVisible(0,1);
    G3D_SYSTEM_Init(0,2,0,4,0,*(u16 *)p,0);
    BG_SYS_EnableBg0WithPriority(3);
    G3D_SYSTEM_SetSwapBuffersMode(0,1);
    light=G3D_CAMERA_Create(2,0xC000,0,0,0x10000,0x1000,0x3E8000,0,(VecFx32 *)&d_021FDA7C.c,(VecFx32 *)&d_021FDA7C.a,(VecFx32 *)&d_021FDA7C.b,*(u16 *)p);
    *(void **)(p+0xA8)=light;
    G3D_CAMERA_Reset(light);
    G3X_SetEdgeColorTable(d_021FDAB0);
    G3X_EdgeMarking(0); G3X_AntiAlias(1); G3X_AlphaBlend(1);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
    big=d_021FDBF8;
    small=d_021FDBD4;
    board=BILLBOARD_Create((u8 *)(&big),(void *)(unsigned int)*(u16 *)p);
    *(void **)(p+0xAC)=board;
    BILLBOARD_SetScale(board,(struct Blk3 *)(&small));
    CLACT_InitSystem((const struct ClactSysInit *)gClActorInitParam,(const struct DispVramCfg *)d_021FDBA0,*(u16 *)p);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
    G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,8,1,0,10);
    GX_SetVisibleWnd(4);
    G2_SetWndOBJInsidePlane(23,1);
    G2_SetWndOutsidePlane(31,1);
}

void STA_ACTING_UploadPalettes(u8 *p)
{
    u16 palette[16];
    u8 i=0;
    u16 old,new;
    ARC_UTIL_UploadPaletteFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),2,0,32,32,32,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),8,3,0,0,0,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),14,3,0,0,0,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),3,0,0,0,32,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),9,2,0,0,0,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),15,2,0,0,0,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)(((struct ActingScene *)p)->arcHandle.u),5,4,0,0,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),13,5,0,0,0,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),17,5,0,0,0,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),12,6,0,0,0,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),16,6,0,0,0,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadBgCharFromHandle((void *)(((struct ActingScene *)p)->arcHandle.u),11,4,0,0,0,((struct ActingScene *)p)->heapId);
    MIi_CpuCopy16((void *)HW_DB_BG_PLTT,p+0x16a,32);
    MIi_CpuCopy16((void *)0x05000420,palette,32);
    for(i=0;i<16;i++){
        old=*(u16 *)(p+0x16a+i*2);
        new=palette[i];
        p[0x18a+i]=(u8)(new&31)-(u8)(old&31);
        p[0x19a+i]=(u8)((new&0x3e0)>>5)-(u8)((old&0x3e0)>>5);
        p[0x1aa+i]=(u8)((new&0x7c00)>>10)-(u8)((old&0x7c00)>>10);
    }
    BG_SYS_PushTile(3);
    BG_SYS_PushTile(5);
    ((struct ActingScene *)p)->model=STA_ACT_LIGHT_AllocElem(((struct ActingScene *)p)->heapId,(uptr)p);
}

/*
 * Unblocked by matching MUSICAL_PROGRAM_GetBaseProgramId (ov010, EXACT, Thumb): the +0008 call
 * site now attests as `matched`. ov009 holds ARM code at that address; ov010
 * is the coherent Thumb leaf, so the declaration is thumb/ov010 (the earlier
 * `arm` was wrong).
 *
 * Addresses are Black-image addresses.
 */
void STA_ACTING_SetBaseProgram(u8 *p, u32 unused)
{
    int v = MUSICAL_PROGRAM_GetBaseProgramId(((struct ActingPartA *)((u8 *)((struct ActingScene *)p)->input))->program);
    STA_ACT_LIGHT_CreateModel(((struct ActingScene *)p)->model, v);
}

void STA_ACTING_SetupBg(const struct BgTemplate *p,u32 id,u32 type) { BG_SYS_InitBgLayer(id,p,type); BG_SYS_SetPlaneVisible(id,1); BG_SYS_FreeSlot(id); BG_SYS_PushTile(id); }

void STA_ACTING_CreateActors(u8 *p)
{
    struct StaActingVec pos;
    u8 i;
    pos = d_021FDBE0;
    ((struct ActingScene *)p)->mcssRender=MUSICAL_MCSS_CreateRenderObj(((struct ActingScene *)p)->heapId);
    MUSICAL_MCSS_SetRenderCellVramBase(((struct ActingScene *)p)->mcssRender,0x20000);
    ((struct ActingScene *)p)->actorPool=MUSICAL_MCSS_CreateActorPool(((struct ActingScene *)p)->billboard.u,36,((struct ActingScene *)p)->heapId);
    ((struct ActingScene *)p)->actorSystem=STA_ACT_LIGHT_AddBillboardImage(((struct ActingScene *)p)->heapId,(uptr)p,(uptr)(((struct ActingScene *)p)->mcssRender),(uptr)(((struct ActingScene *)p)->actorPool),((struct ActingScene *)p)->billboard.u);
    for (i=0;i<4;i++) *(u32 *)(p+0x44+i*4)=0;
    for (i=0;i<4;i++) {
        ((struct Slots *)p)->slots[i]=STA_ACT_LIGHT_AddPokemonElem(((struct ActingScene *)p)->actorSystem,*(void **)(*(u8 * *)&((struct ActingScene *)p)->input+4+i*4));
        STA_ACT_LIGHT_SetActorPos(((struct ActingScene *)p)->actorSystem,((struct Slots *)p)->slots[i],(const u32 *)(&pos));
        pos.z-=0x1e000;
    }
}

void STA_ACTING_CreateActObj(char *p){int tmp[3]={0};int i;for(i=0;i<5;i++)*(int *)((uptr)p+i*4+0x58)=0;*(StaActObjObject * *)&((struct ActingScene *)p)->actObj=STA_ACT_OBJ_Create(((struct ActingScene *)p)->heapId,((struct ActingScene *)p)->billboard.p);}

void STA_ACTING_CreateActorSys(char *p){int i;*(char * *)&((struct ActingScene *)p)->effectSystem=STA_ACT_EFFECT_Create(((struct ActingScene *)p)->heapId);for(i=0;i<8;i++)*(int *)((uptr)p+i*4+0x70)=0;}

/*
 * blocker C (read-only root show):
 *   void G3D_CAMERA_SetEye(char *p, const StaActingVec *v) { *(StaActingVec *)(p + 0x20) = *v; }
 *   void G3D_CAMERA_SetCamTarget(char *p, const StaActingVec *v) { *(StaActingVec *)(p + 0x38) = *v; }
 */
void STA_ACTING_UpdateCamera(u8 *p)
{
    StaActingVec v;
    signed short target;
    u8 index;
    if (KEY_GetCont() & 16) {
        if (*(u16 *)(p + 6) + 2 < 256) *(u16 *)(p + 6) = *(u16 *)(p + 6) + 2;
        else *(u16 *)(p + 6) = 256;
    }
    if (KEY_GetCont() & 32) {
        if (*(u16 *)(p + 6) - 2 > 0) *(u16 *)(p + 6) = *(u16 *)(p + 6) - 2;
        else *(u16 *)(p + 6) = 0;
    }
    if (!(KEY_GetCont() & 48) && !*(int *)(p + 0x14) && !*(int *)(p + 0x10) && !*(int *)(p + 0xC)) {
        if (*(u8 *)(p + 0xF2) == 4) {
            index = *(u8 *)(p + 0xF1);
            if (index == 4) index = *(u8 *)(p + 0xA);
            if (*(void **)(p + 0x44 + index * 4)) {
                STA_ACT_LIGHT_CopyActorPos(*(void **)(p + 0x40), *(void **)(p + 0x44 + index * 4), (u32 *)(&v));
                target = (float)v.x / 4096.0f - 128.0f;
            }
        } else {
            STA_ACT_LIGHT_GetElemPos((void *)(*(void **)(p + 0x90)), (char *)(*(void **)(p + 0x94 + *(u8 *)(p + 0xF2) * 4)), (StaActLightVec3 *)&v);
            target = (float)v.x / 4096.0f - 128.0f;
        }
        if (target > 256) target = 256;
        else if (target < 0) target = 0;
        if (target != *(u16 *)(p + 4)) *(u16 *)(p + 6) = target;
    }
    if (*(u16 *)(p + 6) != *(u16 *)(p + 4)) {
        StaActingVec scale = d_021FDBEC;
        StaActingVec translation = {0, 0, 0};
        if (*(u16 *)(p + 4) > *(u16 *)(p + 6)) {
            if (*(u16 *)(p + 4) > 4 && *(u16 *)(p + 4) - 4 > *(u16 *)(p + 6)) *(u16 *)(p + 4) -= 4;
            else *(u16 *)(p + 4) = *(u16 *)(p + 6);
        } else if (*(u16 *)(p + 4) < *(u16 *)(p + 6)) {
            if (*(u16 *)(p + 4) + 4 < *(u16 *)(p + 6)) *(u16 *)(p + 4) += 4;
            else *(u16 *)(p + 4) = *(u16 *)(p + 6);
        }
        scale.x = FX((float)*(u16 *)(p + 4) / 16.0f);
        translation.x = FX((float)*(u16 *)(p + 4) / 16.0f);
        G3D_CAMERA_SetEye((struct G3dCamera *)(*(void **)(p + 0xA8)), (const VecFx32 *)&scale);
        G3D_CAMERA_SetCamTarget((struct G3dCamera *)(*(void **)(p + 0xA8)), (const VecFx32 *)&translation);
        G3D_CAMERA_Reset(*(void **)(p + 0xA8));
        BG_SYS_ChangeScrollImmediate(2, 0, *(u16 *)(p + 4));
        STA_ACT_LIGHT_SetModelFrame(*(void **)(p + 0x3C), *(u16 *)(p + 4));
        STA_ACT_LIGHT_SetElemFrame(*(void **)(p + 0x40), *(u16 *)(p + 4));
        STA_ACT_OBJ_SetCount(*(void **)(p + 0x54), *(u16 *)(p + 4));
        STA_ACT_AUDIENCE_SetBgScroll(*(void **)(p + 0xB8), *(u16 *)(p + 4));
    }
    if (*(u16 *)(p + 8) == 224) *(int *)(p + 0xC) = 0;
    BG_SYS_ChangeScrollImmediate(2, 3, *(u16 *)(p + 8));
}

void STA_ACTING_LoadCharAnims(u8 *p)
{
    u8 i;
    u32 *table;
    struct Bytes order;
    table = *(u32 * *)&((struct ActingScene *)p)->charAnimTable;
    order = d_021FDBD0;
    STA_ACT_SCRIPT_AddScript(((struct ActingScene *)p)->scriptSystem, (u8 *)table + table[0], 1);
    for (i = 0; i < 4; i++) {
        if (table[0] != table[((u8 *)&order)[i]]) {
            STA_ACT_SCRIPT_AddScript(((struct ActingScene *)p)->scriptSystem, *(u8 * *)&((struct ActingScene *)p)->charAnimTable + table[((u8 *)&order)[i]], 1);
        }
    }
}

void STA_ACTING_LoadRankAnim(u8 *p, u8 setIndex, u8 player)
{
    void *table;
    u16 score;
    table = ARC_UTIL_LoadHandleMember((void *)(((struct ActingScene *)p)->arcHandle.u), setIndex + 0x37, 0, ((struct ActingScene *)p)->heapId);
    score = *(u16 *)(*(u8 **)(*(u8 * *)&((struct ActingScene *)p)->input + player * 4 + 4) + 0x4a);
    if (score >= 70) {
        STA_ACT_SCRIPT_AddScriptFromTable(((struct ActingScene *)p)->scriptSystem, table, 0, (u8)(1 << player));
    } else if (score >= 40) {
        STA_ACT_SCRIPT_AddScriptFromTable(((struct ActingScene *)p)->scriptSystem, table, 1, (u8)(1 << player));
    } else {
        STA_ACT_SCRIPT_AddScriptFromTable(((struct ActingScene *)p)->scriptSystem, table, 2, (u8)(1 << player));
    }
}

void STA_ACTING_LoadAnimMember(char *p, u8 setIndex, u8 mask){void *table;table=ARC_UTIL_LoadHandleMember((void *)(((struct ActingScene *)p)->arcHandle.u),setIndex+0x4b,0,((struct ActingScene *)p)->heapId);STA_ACT_SCRIPT_AddScriptFromTable(((struct ActingScene *)p)->scriptSystem,table,0,mask);}

/*
 * Palette fade, 16 colours. The object holds a u16 phase at +0x168 (advanced by 0x160, wrapped at
 * 0x10000), 16 base colours at +0x16A, s8 red, green and blue deltas at +0x18A, +0x19A, +0x1AA,
 * and 16 output colours at +0x1BA. The factor is (cos table entry + 0x1000) / 2. Each channel gets
 * (s8 delta * factor >> 12) added, then the colours go to NNS_GfdRegisterNewVramTransferTask(31, 0, out, 32).
 * Twins for the channel pack: ov068 021B9D68, ov104 021B89DC.
 * What closed it: a struct view of the object (p->phase, p->base[i], p->out[i]) with no colour
 * local (every channel reads p->base[i], CSE keeps one load), which makes the allocator spill p
 * instead of p + 2i; compound assignment `p->phase += 0x160` in the else wrap
 * arm (the else arm then recomputes the sum, as the image does); `u8 i` declared before
 * `int factor`. final push 2026-10-05 G9L6.
 */
void STA_ACTING_FadePalette(StaActingFade *p)
{
    u8 i;
    int factor;
    if (p->phase + 0x160 >= 0x10000)
        p->phase = p->phase - 0xFEA0;
    else
        p->phase += 0x160;
    factor = (FX_SinCosTable_[(p->phase >> 4) * 2] + 0x1000) / 2;
    for (i = 0; i < 16; i++) {
        u8 b = (p->base[i] & 0x7C00) >> 10;
        u8 r = p->base[i] & 0x1F;
        u8 g = (p->base[i] & 0x3E0) >> 5;
        int B = b + (s8)((p->db[i] * factor) >> 12);
        int R = r + (s8)((p->dr[i] * factor) >> 12);
        int G = g + (s8)((p->dg[i] * factor) >> 12);
        p->out[i] = (B << 10) | (R | (G << 5));
    }
    NNS_GfdRegisterNewVramTransferTask((void *)31, 0, (uptr)p->out, 32);
}

void STA_ACTING_CreateText(u8 *p)
{
    int zero;
    ((struct ActingScene *)p)->bmpWin.u=(uptr)BMP_WIN_Create((unsigned int)1,(unsigned int)4,(unsigned int)20,24,4,15,1);
    BMP_WIN_TransferChars((struct BmpWin *)((struct ActingScene *)p)->bmpWin.u);
    BMP_WIN_MakeScreen((struct BmpWin *)(((struct ActingScene *)p)->bmpWin.u));
    BG_SYS_PushTile(1);
    zero=0;
    ((struct ActingScene *)p)->font.u=(uptr)GF_FONT_Create(23,0,0,0,((struct ActingScene *)p)->heapId);
    ((struct ActingScene *)p)->msgData.u=(uptr)MSGDATA_CreateFromMemory(((struct ActingPartB *)(*(u8 * *)&((struct ActingPartA *)(*(u8 * *)&((struct ActingScene *)p)->input))->resources))->messages,((struct ActingScene *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,480,32,((struct ActingScene *)p)->heapId);
    ((struct ActingScene *)p)->textTcbl.u=(uptr)TCBL_Create(((struct ActingScene *)p)->heapId,((struct ActingScene *)p)->heapId,3,256);
    ((struct ActingScene *)p)->printStream.u=zero;
    ((struct ActingScene *)p)->strBuf.u=zero;
    ((struct ActingScene *)p)->queuePending.u=zero;
    ((struct ActingScene *)p)->printQueue.u=(uptr)PRINTSYS_QUE_Create((unsigned int)(u32)((struct ActingScene *)p)->heapId);
}

void STA_ACTING_UpdateText(u8 *p)
{
    TCBL_Main(((struct ActingScene *)p)->textTcbl.p);
    if (((struct ActingScene *)p)->printStream.p && PRINTSYS_PrintStreamGetState(((struct ActingScene *)p)->printStream.p) == 2) {
        PRINTSYS_PrintStreamDelete(((struct ActingScene *)p)->printStream.p);
        ((struct ActingScene *)p)->printStream.p = 0;
    }
    if (((struct ActingScene *)p)->queuePending.s == 1) {
        PRINTSYS_QUE_Main(((struct ActingScene *)p)->printQueue.p);
        if (PRINTSYS_QUE_IsFinished(((struct ActingScene *)p)->printQueue.p) == 1) {
            BMP_WIN_TransferChars(((struct ActingScene *)p)->bmpWin.p);
            ((struct ActingScene *)p)->queuePending.s = 0;
        }
    }
}

/*
 * abi: 0201CCE4 forwards the pointer result of matched 0201CD10; the caller stores it at d8.
 */
void STA_ACTING_PrintText(u8 *p, u16 index, u32 speed)
{
    Zero zero;
    if (((struct ActingScene *)p)->printStream.p) {
        PRINTSYS_PrintStreamDelete(((struct ActingScene *)p)->printStream.p);
        ((struct ActingScene *)p)->printStream.p = 0;
    }
    if (((struct ActingScene *)p)->strBuf.p) {
        STRBUF_Delete(((struct ActingScene *)p)->strBuf.p);
        ((struct ActingScene *)p)->strBuf.p = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(((struct ActingScene *)p)->bmpWin.p), 0);
    zero = ZERO;
    ((struct ActingScene *)p)->strBuf.p = MSGDATA_AllocString(((struct ActingScene *)p)->msgData.p, index);
    if (speed != 255) {
        ((struct ActingScene *)p)->printStream.p = PRINTSYS_PrintStream(((struct ActingScene *)p)->bmpWin.p, zero, zero,
            ((struct ActingScene *)p)->strBuf.p, ((struct ActingScene *)p)->font.p, speed,
            ((struct ActingScene *)p)->textTcbl.p, 2, ((struct ActingScene *)p)->heapId, zero);
    } else {
        PRINTSYS_PrintQue(((struct ActingScene *)p)->printQueue.p, (struct Bmp *)(uptr)BMP_WIN_GetBmp(((struct ActingScene *)p)->bmpWin.p),
            zero, zero, ((struct ActingScene *)p)->strBuf.p, (struct GfFont *)(*(u32 *)&((struct ActingScene *)p)->font));
        ((struct ActingScene *)p)->queuePending.s = 1;
        STRBUF_Delete(((struct ActingScene *)p)->strBuf.p);
        ((struct ActingScene *)p)->strBuf.p = (void *)zero;
    }
}

void STA_ACTING_ClearText(u8 *p)
{
    if (((struct ActingScene *)p)->printStream.p) {
        PRINTSYS_PrintStreamDelete(((struct ActingScene *)p)->printStream.p);
        ((struct ActingScene *)p)->printStream.p = 0;
    }
    if (((struct ActingScene *)p)->strBuf.p) {
        STRBUF_Delete(((struct ActingScene *)p)->strBuf.p);
        ((struct ActingScene *)p)->strBuf.p = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(((struct ActingScene *)p)->bmpWin.p), 0);
    BMP_WIN_TransferChars(((struct ActingScene *)p)->bmpWin.p);
}

void STA_ACTING_UpdateSelection(char *p)
{
    u8 count, i, j, selected, index;
    if (*(int *)(p + 0xEC) != 1) return;
    count = 0;
    i = 0;
    for (; i < 4; i++) STA_ACT_AUDIENCE_SetSlotValue(*(char **)(p + 0xB8), i, 0);
    STA_ACT_AUDIENCE_SetHighlight(*(char **)(p + 0xB8), 255);
    *(u8 *)(p + 0xF1) = 4;
    *(u8 *)(p + 0xF2) = 4;
    for (j = count; j < 4; j = (u8)(j + 1)) {
        if (*(int *)(p + 0x94 + j * 4) != 0) {
            selected = j;
            count = (u8)(count + 1);
        }
    }
    index = *(u8 *)(p + 0x11C);
    if (index < 4) {
        *(u8 *)(p + 0xF1) = index;
        STA_ACT_AUDIENCE_SetSlotValue(*(char **)(p + 0xB8), index, 1);
    } else if ((index = *(u8 *)(p + 0xF0)) < 4) {
        *(u8 *)(p + 0xF1) = index;
        STA_ACT_AUDIENCE_SetSlotValue(*(char **)(p + 0xB8), index, 1);
    } else if (count == 1) {
        *(u8 *)(p + 0xF2) = selected;
        STA_ACT_AUDIENCE_SetHighlight(*(char **)(p + 0xB8), selected);
    } else {
        for (j = 0; j < 4; j = (u8)(j + 1)) {
            if (*(u8 *)(p + 0xF3 + j) == 0)
                STA_ACT_AUDIENCE_SetSlotValue(*(char **)(p + 0xB8), j, 1);
        }
    }
    *(int *)(p + 0xEC) = 0;
}

/*
 * The original stores p+0xEC = 1 unconditionally after the if/else, so the
 * store is a shared tail reached by both arms (b .end out of the `c == 1`
 * arm); writing it inside the else made the compiler emit two epilogues.
 * See docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md.
 */
void STA_ACTING_SetSelection(char *p, u8 player, int enable)
{
    if (enable == 1) {
        ((struct ActingScene *)p)->forcedSelection = player;
    } else {
        ((struct ActingScene *)p)->forcedSelection = 4;
    }
    ((struct ActingScene *)p)->selectionDirty = 1;
}

void STA_ACTING_MarkDirty(char *p){((struct ActingScene *)p)->selectionDirty=1;}

void STA_ACTING_RankScores(u8 *p)
{
    u8 i, j;
    u16 score;
    for (i = 0; i < 4; i++) p[0xf3 + i] = 0;
    for (i = 0; i < 4; i++) {
        score = (u16)(*(u16 *)((*(u8 ***)(p + 0x30))[i + 1] + 0x4a) + p[0xf7 + i]);
        for (j = 0; j < 4; j++) {
            if (i != j) {
                if ((u16)(*(u16 *)((*(u8 ***)(p + 0x30))[j + 1] + 0x4a) + p[0xf7 + j]) > score) p[0xf3 + i]++;
            }
        }
    }
}

/*
 * Addresses are Black-image addresses.
 */
void STA_ACTING_InstallBgm(char *p, int bgmNo)
{
    ((struct ActingScene *)p)->bgmBuffersInstalled.s = 1;
    GFL_USE_InstallBgmBuffers(((struct ActingScene *)p)->seqAddr, ((struct ActingScene *)p)->bankAddr, bgmNo);
}

void STA_ACTING_StartSeq(char *p, int seqNo)
{
    ((struct ActingScene *)p)->seqPlaying.s = 1;
    GFL_USE_StartSeq(seqNo);
}

void STA_ACTING_StopSeq(char *p){((struct ActingScene *)p)->seqPlaying.s=0;GFL_USE_StopSeqAndUnload();}

/*
 * lever: The matched 020064B8 body reads four arguments; incoming r3 is
 * forwarded unchanged, preventing the erroneous three-argument tail call.
 *
 * Addresses are Black-image addresses.
 */
int STA_ACTING_ReplaceWaveData(char *p, u32 waveArcNo, u32 waveIndex, u32 srcWaveIndex)
{
    return GFL_USE_ReplaceWaveData(waveArcNo, waveIndex, ((struct ActingScene *)p)->srcWaveArc, srcWaveIndex);
}

void STA_ACTING_PlayBgm(char *p, int bgmNo)
{
    ((struct ActingScene *)p)->bgmPlaying.s = 1;
    GFL_USE_CancelChangeAndPlayBgm(bgmNo, 0xffff);
}

void STA_ACTING_StopBgm(char *p){((struct ActingScene *)p)->bgmPlaying.s=0;GFL_USE_CancelChangeAndStopBgm();}

void STA_ACTING_PlayRankSe(char *p)
{
    u8 i;
    u8 min = 255;
    char *a = *(char * *)&((struct ActingScene *)p)->input;
    for (i = 0; i < 4; i++) {
        u16 v = *(u16 *)(*(char **)(a + i * 4 + 4) + 0x4a) + *(u8 *)(p + i + 0xf7);
        if (min > v) min = v;
    }
    if (min >= 70) GFL_USE_PlaySeDefaultVolume(1578);
    else if (min >= 30) GFL_USE_PlaySeDefaultVolume(1579);
    else if (min >= 1) GFL_USE_PlaySeDefaultVolume(1580);
}

void STA_ACTING_RequestAction(char *p,int value){if(!**(int * *)&((struct ActingScene *)p)->input)STA_ACTING_ApplyAction(p,((struct ActingScene *)p)->localPlayer,value);else{((struct ActingScene *)p)->netActionPending=1;((struct ActingScene *)p)->netActionValue=value;}}

void STA_ACTING_ApplyAction(char *p, u32 player, int action)
{
    Enabled one;
    one = ENABLED;
    player = (uptr)p + player * 4;
    ((struct ScriptOwner *)player)->actionRequest = one;
    ((struct ScriptOwner *)player)->actionValue = action;
}

int STA_ACTING_GetCurrentAction(char *p){return STA_ACTING_GetActionByIndex(p,((struct ActingScene *)p)->localPlayer);}

int STA_ACTING_GetActionByIndex(char *p,u32 player){if(STA_ACT_LIGHT_IsElemActive(*(char * *)&((struct ActingScene *)p)->actorSystem,*(char **)((uptr)p+player*4+0x44))==1)return 1;return *(int *)((uptr)p+0xfc+player*4);}

/*
 * lever: slots[count] = i; count++; keeps the byte store before the increment; if/else field stores preserve the shared flag-store block.
 */
void STA_ACTING_ProcessRecords(char *p)
{
    u8 count = 0;
    u8 slots[4];
    u8 i;
    int action;
    int index;
    int result;
    STA_ACTING_TickActionTimers(p);
    if (**(void ** *)&((struct ActingScene *)p)->input && ((struct ActingScene *)p)->netActionPending == 1) {
        if (STA_NET_SendKindA(**(void ** *)&((struct ActingScene *)p)->input, (u8)((struct ActingScene *)p)->netActionValue) == 1)
            ((struct ActingScene *)p)->netActionPending = 0;
    }
    if (!**(void ** *)&((struct ActingScene *)p)->input) {
        for (i = 0; i < 4; i++) {
            if (*(int *)(p + i * 4 + 0xFC) == 1) {
                STA_ACT_LIGHT_HandleElemAnim(*(char * *)&((struct ActingScene *)p)->actorSystem, *(char **)(p + i * 4 + 0x44), *(int *)(p + i * 4 + 0x10C));
                slots[count] = i;
                count++;
                *(int *)(p + i * 4 + 0xFC) = 0;
                if (*(int *)(p + i * 4 + 0x10C) == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (*(int *)(p + i * 4 + 0x10C) == 8) *(int *)(p + i * 8 + 0x140) = 1;
                STA_ACTING_ScheduleActions(p, 2, i);
            }
        }
        if (count != 0) {
            if (((struct ActingScene *)p)->lastActor == 4) ((struct ActingScene *)p)->scoreOnFinish = 1;
            else ((struct ActingScene *)p)->scoreOnFinish = 0;
            ((struct ActingScene *)p)->actionDelay = 180;
            ((struct ActingScene *)p)->lastActor = slots[GFL_USE_GetRandomBelow(count)];
            ((struct ActingScene *)p)->lastAction = *(int *)(p + ((struct ActingScene *)p)->lastActor * 4 + 0x10C);
            ((struct ActingScene *)p)->selectionDirty = 1;
        }
    } else {
        index = STA_SLOT_GetCurrentKey(**(void ** *)&((struct ActingScene *)p)->input);
        if ((unsigned)index < 4) {
            if (((struct ActingScene *)p)->lastActor == 4) ((struct ActingScene *)p)->scoreOnFinish = 1;
            else ((struct ActingScene *)p)->scoreOnFinish = 0;
            ((struct ActingScene *)p)->actionDelay = 180;
            ((struct ActingScene *)p)->lastActor = index;
            ((struct ActingScene *)p)->lastAction = STA_SLOT_GetStateByKey(**(void ** *)&((struct ActingScene *)p)->input, index);
            ((struct ActingScene *)p)->selectionDirty = 1;
            STA_SLOT_ClearCurrent(**(void ** *)&((struct ActingScene *)p)->input);
        }
        for (i = 0; i < 4; i++) {
            action = STA_SLOT_GetStateByKey(**(void ** *)&((struct ActingScene *)p)->input, i);
            if (action != 10) {
                STA_ACT_LIGHT_HandleElemAnim(*(char * *)&((struct ActingScene *)p)->actorSystem, *(char **)(p + i * 4 + 0x44), action);
                STA_SLOT_ResetStateByKey(**(void ** *)&((struct ActingScene *)p)->input, i);
                if (action == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (action == 8) *(int *)(p + i * 8 + 0x140) = 1;
                STA_ACTING_ScheduleActions(p, 2, i);
            }
        }
    }
    if (((struct ActingScene *)p)->actionDelay != 0) {
        if (((struct ActingScene *)p)->actionDelay > ((struct ActingScene *)p)->elapsedTicks) {
            ((struct ActingScene *)p)->actionDelay -= (u16)((struct ActingScene *)p)->elapsedTicks;
            return;
        }
        ((struct ActingScene *)p)->actionDelay = 0;
        if (((struct ActingScene *)p)->scoreOnFinish == 1) {
            if (!**(void ** *)&((struct ActingScene *)p)->input) {
                result = STA_ACTING_AddScore(p, ((struct ActingScene *)p)->lastActor, ((struct ActingScene *)p)->lastAction);
                *(int *)(*(char **)(*(char * *)&((struct ActingScene *)p)->input + ((struct ActingScene *)p)->lastActor * 4 + 4) + ((struct ActingScene *)p)->lastAction * 4 + 0x54) = 1;
                GFL_USE_PlaySeDefaultVolume(result);
            } else if (GFL_NET_IsParentAid() == 1) {
                result = STA_ACTING_AddScore(p, ((struct ActingScene *)p)->lastActor, ((struct ActingScene *)p)->lastAction);
                if (result == 1580) STA_SLOT_PushRecord(**(void ** *)&((struct ActingScene *)p)->input, ((struct ActingScene *)p)->lastActor, ((struct ActingScene *)p)->lastAction, 1);
                else STA_SLOT_PushRecord(**(void ** *)&((struct ActingScene *)p)->input, ((struct ActingScene *)p)->lastActor, ((struct ActingScene *)p)->lastAction, 2);
            }
        }
        ((struct ActingScene *)p)->lastActor = 4;
        ((struct ActingScene *)p)->selectionDirty = 1;
    }
}

int STA_ACTING_AddScore(char *p, unsigned player, unsigned actionIndex)
{
    u16 v;
    u8 old;
    v = MUSICAL_PROGRAM_GetCategoryShare((((struct ActingPartA *)(*(char * *)&((struct ActingScene *)p)->input))->program), (u8)(int)MUSICAL_MCSS_GetElemA((void *)STA_ACTING_GetActorCount((u8 *)p), (u16)(*(u16 *)(*(char **)(*(char * *)&((struct ActingScene *)p)->input + player * 4 + 4) + actionIndex * 6 + 0x14))));
    old = *(u8 *)(p + 0xf7 + player);
    *(u8 *)(p + 0xf7 + player) = old + v;
    STA_ACTING_RankScores((u8 *)p);
    return (unsigned)v >= 7 ? 1579 : 1580;
}

void STA_ACTING_TickActionTimers(char *p)
{
    u8 i;
    if (**(void ** *)&((struct ActingScene *)p)->input != 0 && GFL_NET_IsParentAid() != 1) return;
    for (i = 0; i < 4; i++) {
        if (*(u16 *)(p + i * 2 + 0x124) != 0) {
            *(u16 *)(p + i * 2 + 0x124) -= 1;
            if (*(u16 *)(p + i * 2 + 0x124) == 0) {
                if (**(void ** *)&((struct ActingScene *)p)->input == 0) STA_ACTING_ApplyAction(p, i, *(int *)(p + i * 4 + 0x12c));
                else STA_SLOT_SetValueByKey(**(void ** *)&((struct ActingScene *)p)->input, i, *(int *)(p + i * 4 + 0x12c));
            }
        }
    }
}

static inline u32 random_below(u32 bound)
{
    u32 draw;
    draw = GF_STANDARD_Rand();
    return ((u64)draw * bound) >> 32;
}

/*
 * lever: The final random choice is a ternary; an if/else shares the earlier action-seven assignment and leaves 36 bytes different.
 * ABI: The matched 0203D378 body returns u32(void); the preceding guard loads r0 without an argument to that call.
 */
void STA_ACTING_ScheduleActions(char *p, int mode, u8 slot)
{
    u8 i;
    if (**(void ** *)&((struct ActingScene *)p)->input && GFL_NET_IsParentAid() != 1) return;
    for (i = 0; i < 4; i++) {
        int eligible[2] = {0, 0};
        char *record = *(char **)(*(char * *)&((struct ActingScene *)p)->input + i * 4 + 4);
        StaActingAction action;
        int value;
        if (((struct ActingRecord *)record)->state != 2 || STA_ACTING_GetActionByIndex(p, i) == 1 || *(u16 *)(p + i * 2 + 0x124) != 0) continue;
        if (((struct ActingRecord *)record)->leftActorId != 255 && !*(int *)(p + i * 8 + 0x13C)) eligible[0] = 1;
        if (((struct ActingRecord *)record)->rightActorId != 255 && !*(int *)(p + i * 8 + 0x140)) eligible[1] = 1;
        if (!eligible[0] && !eligible[1]) continue;
        if (eligible[0] == 1 && eligible[1] == 0) action = ACTION7;
        else if (eligible[1] == 1 && eligible[0] == 0) action = ACTION8;
        else {
            action = (u8)random_below(2) == 0 ? ACTION7 : ACTION8;
        }
        switch (mode) {
        case 1:
            if (((struct ActingRecord *)record)->actionTiming == 65533 && i == slot) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(30) + 30;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        case 2:
            if (((struct ActingRecord *)record)->actionTiming == 65535 && random_below(100) < 50) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(60) + 60;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            if (((struct ActingRecord *)record)->actionTiming == 65534 && random_below(100) < 25) {
                *(u16 *)(p + i * 2 + 0x124) = random_below(60) + 60;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        case 0:
            if (((struct ActingRecord *)record)->actionTiming != 0 && ((struct ActingRecord *)record)->actionTiming < 65533) {
                value = ((struct ActingRecord *)record)->actionTiming + (s8)(random_below(121) - 60);
                if (value < 0) *(u16 *)(p + i * 2 + 0x124) = 0;
                else *(u16 *)(p + i * 2 + 0x124) = value;
                *(int *)(p + i * 4 + 0x12C) = action;
            }
            break;
        }
    }
}

void STA_ACTING_CreateAnimHandle(char *p)
{
    ((struct ActingScene *)p)->animHandle = STA_ACT_EFFECT_StartSystem(((struct ActingScene *)p)->effectSystem, 0x36);
}

void STA_ACTING_DeleteAnimHandle(char *p)
{
    STA_ACT_EFFECT_KillSystem(((struct ActingScene *)p)->effectSystem, ((struct ActingScene *)p)->animHandle);
}

void STA_ACTING_PositionAnim(char *p, unsigned player)
{
    StaActingVec v;
    u8 j;
    STA_ACT_LIGHT_CopyActorPos(((struct ActingScene *)p)->actorSystem, *(void **)(p + player * 4 + 0x44), (unsigned int *)(&v));
    v.x /= 16;
    v.y = (0xc0000 - (v.y - 0x20000)) / 16;
    v.z = 0xb4000;
    for (j = 0; j < 3; j++) STA_ACT_EFFECT_StartEffect((char *)(*(char * *)&((struct ActingScene *)p)->animHandle), j, (StaActingVec *)&v.x);
    GFL_USE_PlaySeDefaultVolume(1961);
}

void STA_ACTING_ShowButton(char *p)
{
    STA_ACT_BUTTON_SetVisible(((struct ActingScene *)p)->button, 1);
}

void STA_ACTING_HideButton(char *p){STA_ACT_BUTTON_SetVisible(((struct ActingScene *)p)->button,0);}

void *STA_ACTING_GetActorSystem(char *p){return ((struct ActingScene *)p)->actorSystem;}

void *STA_ACTING_GetActor(char *p,u32 player){return *(void **)((uptr)p+4*player+0x44);}

void *STA_ACTING_GetActObj(void *p){return ((struct ActingScene *)p)->actObj;}

u32 *STA_ACTING_GetSlot(void *p,u8 index){return *(u32 **)((u8 *)p+(u32)index*4+0x58);}

void STA_ACTING_SetSlot(void *p,void *value,u32 index){*(void **)((u8 *)p+index*4+0x58)=value;}

void *STA_ACTING_GetEffectSystem(void *p){return ((struct ActingScene *)p)->effectSystem;}

void *STA_ACTING_GetAnimSlot(void *p,u8 index){return *(void **)((u8 *)p+(u32)index*4+0x70);}

void STA_ACTING_SetAnimSlot(void *p,void *value,u32 index){*(void **)((u8 *)p+index*4+0x70)=value;}

void *STA_ACTING_GetCharSystem(void *p){return ((struct ActingScene *)p)->charSystem;}

void *STA_ACTING_GetCharSlot(void *p,u8 index){return *(void **)((u8 *)p+(u32)index*4+0x94);}

void STA_ACTING_SetCharSlot(void *p,void *value,u8 index){*(void **)((u8 *)p+(u32)index*4+0x94)=value;}

void *STA_ACTING_GetAudience(void *p){return ((struct ActingScene *)p)->audience;}

u16 STA_ACTING_GetCameraPos(void *p){return ((struct ActingScene *)p)->scrollY;}

void STA_ACTING_SetCameraPos(void *p,u16 pos){((struct ActingScene *)p)->scrollY=pos;}

u16 STA_ACTING_GetCameraScrollX(u8 *p) { return ((struct ActingScene *)p)->scrollX; }

void STA_ACTING_SetCameraTarget(u8 *p,u16 target) { ((struct ActingScene *)p)->scrollTargetX=target; }

u32 STA_ACTING_GetActorCount(u8 *p) { return MUSICAL_MCSS_GetActorPoolResource(*(u8 * *)&((struct ActingScene *)p)->actorPool); }

/*
 * note: unlabelled getter witnessing ov112 021F6CE0.
 */
int STA_ACTING_GetSelection(char *p) { return ((struct ActingScene *)p)->lastActor; }

unsigned char STA_ACTING_GetRecordScore(char *p, unsigned int player) { return *(unsigned short *)(((char **)(*(char **)(p + 0x30) + player * 4))[1] + 0x4A); }

unsigned char STA_ACTING_GetBonus(char *p, unsigned int player) { return *(unsigned char *)(p + player + 0xF7); }

void STA_ACTING_SetCameraHoldScore(char *p, unsigned int hold) { *(unsigned int *)(p + 0x10) = hold; }
