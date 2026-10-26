/*
 * file:     dup_fitting.c
 * unit:     yes
 * function: DUP_FITTING_Create, DUP_FITTING_Delete, DUP_FITTING_Main, DUP_FITTING_VBlank, DUP_FITTING_InitDisplay, DUP_FITTING_InitModels, DUP_FITTING_InitBgLayer, DUP_FITTING_InitRenderObj, DUP_FITTING_InitFrames, DUP_FITTING_AddFitElemById, DUP_FITTING_RandomPos, DUP_FITTING_FreeElements, DUP_FITTING_UpdateIdle, DUP_FITTING_SetModelTransform, DUP_FITTING_FreeHeldElem, DUP_FITTING_UpdateCursor, DUP_FITTING_RotateToCursor, DUP_FITTING_PickElem, DUP_FITTING_AttachElem, DUP_FITTING_CreateFitElem, DUP_FITTING_ReleaseElem, DUP_FITTING_ReturnElem, DUP_FITTING_MoveElem, DUP_FITTING_UpdateHeldElem, DUP_FITTING_SelectFrame, DUP_FITTING_UpdateSubMode, DUP_FITTING_UpdateRotation, DUP_FITTING_IsFrameOwned, DUP_FITTING_FindNearestFrame, DUP_FITTING_DrawElems, DUP_FITTING_UpdateHeldVisible, DUP_FITTING_HitCircle, DUP_FITTING_SortFrames, DUP_FITTING_FrameWeight, DUP_FITTING_DrawFrames, DUP_FITTING_HandleTouch, DUP_FITTING_ResetSlots, DUP_FITTING_HandlePickTouch, DUP_FITTING_DragRotate, DUP_FITTING_SaveOutfits, DUP_FITTING_DrawBackActors, DUP_FITTING_EnterPoseMode, DUP_FITTING_ExitPoseMode, DUP_FITTING_UpdatePose, DUP_FITTING_StepPoseRotate, DUP_FITTING_StepPoseHold, DUP_FITTING_StepPoseSlide, DUP_FITTING_CreateText, DUP_FITTING_DeleteText, DUP_FITTING_SetText, DUP_FITTING_SetTextMon, DUP_FITTING_SetTextItem, DUP_FITTING_SetTextHelp, DUP_FITTING_CreateActors, DUP_FITTING_DeleteActors, DUP_FITTING_UpdateActorTimers, DUP_FITTING_ResetActorPose
 * address:  0x021B6100
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from dup_fitting_item.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 *   MUSICAL_SAVE_GetFittingSetting 0x0200A828 thumb
 *   MUSICAL_SAVE_SetFittingSetting 0x0200A834 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   d_021BA600 0x021BA600 data a4
 *   UI_SetInputMode 0x020355D8 arm
 *   MUSICAL_SAVE_ClearNewProps 0x0200A6F8 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MUSICAL_MCSS_FreeRenderObj 0x021F5330 thumb ov112
 *   MUSICAL_MCSS_DeleteRenderObj 0x021F51B0 thumb ov112
 *   TCB_DeleteTask 0x02030EAC arm
 *   BILLBOARD_Delete 0x0204ED24 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 *   MUS_COMM_FUNC_CheckTimingSync 0x021FCE00 thumb ov132
 *   STA_NET_IsTransferDone 0x021FD6A4 thumb ov132
 *   MUSICAL_MCSS_TickAnim 0x021F51E8 thumb ov112
 *   MUSICAL_MCSS_DrawRenderObj 0x021F51F4 thumb ov112
 *   MUSICAL_MCSS_UpdateObject 0x021F4990 thumb ov112
 *   CLACT_DrawSystem 0x0204A600 arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   BILLBOARD_Draw 0x0204F7DC arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   BG_SYS_ClearLayer 0x0204152C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BG_SYS_SetPriority 0x0204047C arm
 *   ARC_UTIL_UploadBgPaletteFromArchive 0x0204989C arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   MUSICAL_MCSS_GetActorPoolResource 0x021F4F10 thumb ov112
 *   MUSICAL_MCSS_GetElemPtr 0x021F4F54 thumb ov112
 *   MUSICAL_MCSS_GetElemSizeFlags 0x021F4F70 thumb ov112
 *   MUSICAL_MCSS_FreeElemImage 0x021F4D74 thumb ov112
 *   MUSICAL_MCSS_NoOp3 0x021F4AA4 thumb ov112
 *   BILLBOARD_GetImagePlttKey 0x0204F32C arm
 *   BILLBOARD_GetImageTexKey 0x0204F2E4 arm
 *   BILLBOARD_SetImageTexAddr 0x0204F2FC arm
 *   BILLBOARD_GetImageSizeFromFlags 0x0204EDD0 arm
 *   BILLBOARD_AddImageFromVramKeys 0x0204F044 arm
 *   BILLBOARD_ReleaseImageVramIfUsed 0x0204F1A0 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   WIPE_ResetWndMask 0x02022224 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3X_SetEdgeColorTable 0x0207DCF8 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_EnableBg0WithPriority 0x0204044C arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BILLBOARD_Create 0x0204EBD4 arm
 *   d_021BA518 0x021BA518 data a4
 *   d_021BA3F4 0x021BA3F4 data a4
 *   d_021BA40C 0x021BA40C data a4
 *   d_021BA400 0x021BA400 data a4
 *   d_021BA418 0x021BA418 data a4
 *   d_021BA428 0x021BA428 data a4
 *   d_021BA438 0x021BA438 data a4
 *   d_021BA458 0x021BA458 data a4
 *   d_021BA478 0x021BA478 data a4
 *   d_021BA4F8 0x021BA4F8 data a4
 *   d_021BA498 0x021BA498 data a4
 *   d_021BA4B8 0x021BA4B8 data a4
 *   d_021BA4D8 0x021BA4D8 data a4
 *   gClActorInitParam 0x020A1448 data a4
 *   d_021BA5C4 0x021BA5C4 data a4
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   MUSICAL_MCSS_CreateRenderObj 0x021F5164 thumb ov112
 *   MUSICAL_MCSS_SetRenderCellVramBase 0x021F5438 thumb ov112
 *   MUSICAL_MCSS_SetRenderAnimVramBase 0x021F5444 thumb ov112
 *   MUSICAL_MCSS_SetupRenderObj 0x021F5204 thumb ov112
 *   MUSICAL_MCSS_GetRenderFlags 0x021F545C thumb ov112
 *   MUSICAL_MCSS_SetRenderPos 0x021F5350 thumb ov112
 *   MUSICAL_SAVE_IsPropOwned 0x0200A644 thumb
 *   MUSICAL_SAVE_IsPropNew 0x0200A680 thumb
 *   MUSICAL_SAVE_GetOutfits 0x0200A628 thumb
 *   MUSICAL_MCSS_CreateActorPool 0x021F48C0 thumb ov112
 *   MUSICAL_MCSS_CreateResourceArc 0x021F4B3C thumb ov112
 *   MUSICAL_MCSS_FreeResourceArc 0x021F4B4C thumb ov112
 *   MUSICAL_MCSS_SetElemFlag 0x021F4EE8 thumb ov112
 *   MUSICAL_MCSS_AddImageNoVram 0x021F4C1C thumb ov112
 *   MUSICAL_MCSS_SetElemVisible 0x021F4E6C thumb ov112
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   MUSICAL_MCSS_TransferVram 0x021F4DE0 thumb ov112
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_GetTexVramKey 0x02047388 arm
 *   G3D_SYSTEM_GetPlttVramKey 0x020473B8 arm
 *   G3D_SYSTEM_GetPlttDataAddr 0x020473EC arm
 *   G3D_SYSTEM_GetResourceFile 0x02046F48 arm
 *   G3D_SYSTEM_GetResourceTex 0x02047250 arm
 *   NNS_G3dPlttSetPlttKey 0x0206A124 arm
 *   NNS_G3dPlttLoad 0x0206A12C arm
 *   DC_FlushRange 0x020862F0 arm
 *   BILLBOARD_AddImageFromArchive 0x0204EFC8 arm
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   d_020A8148    0x020A8148 data
 *   d_021BA3E0    0x021BA3E0 data ov133 a4
 *   MUSICAL_MCSS_FreeElem 0x021F4D40 thumb ov112
 *   MUSICAL_MCSS_DeleteActorPool 0x021F4948 thumb ov112
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   BILLBOARD_DeleteImage 0x0204F150 arm
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 *   MUSICAL_MCSS_SetElemField 0x021F4ED4 thumb ov112
 *   BILLBOARD_SetElemPos 0x0204F638 arm
 *   BILLBOARD_SetElemScale 0x0204F684 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   d_021BA3E4 0x021BA3E4 data
 *   d_021BA3E8 0x021BA3E8 data
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   GF_STANDARD_CalcAngle 0x0203F768 arm
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb ov112
 *   MUSICAL_MCSS_ElemHasAltDepth 0x021F4B24 thumb ov112
 *   MUSICAL_MCSS_SetElemRot 0x021F4EC4 thumb ov112
 *   d_021BA5A0 0x021BA5A0 data a4
 *   d_021BA5B8 0x021BA5B8 data a4
 *   MUSICAL_MCSS_SetElemScale 0x021F4EA4 thumb ov112
 *   d_021BA588 0x021BA588 data a4
 *   d_021BA568 0x021BA568 data a4
 *   MUSICAL_MCSS_GetIndex 0x021F50F4 thumb ov112
 *   d_021BA570 0x021BA570 data a4
 *   MUSICAL_MCSS_GetElemOffset 0x021F4F04 thumb ov112
 *   d_021BA57C 0x021BA57C data a4
 *   d_021BA5AC 0x021BA5AC data a4
 *   MUSICAL_MCSS_IsElemModeSupportedA 0x021F4AF0 thumb ov112
 *   MUSICAL_MCSS_CopyElem 0x021F4E2C thumb ov112
 *   MUSICAL_MCSS_IsElemModeSupportedC 0x021F4B10 thumb ov112
 *   MUSICAL_MCSS_IsElemModeSupportedB 0x021F4AFC thumb ov112
 *   FX_Sqrt 0x0207C7B4 arm
 *   FX_Atan2Idx 0x0207CFB8 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_021BA594 0x021BA594 data ov133 a1
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   FX_Atan2Idx 0x0207CFB8 arm
 *   MUSICAL_SAVE_InitOutfits 0x0200A604 thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   gDupFittingPoseSlide1From 0x021BA558 data a4
 *   gDupFittingPoseSlide1To 0x021BA560 data a4
 *   gDupFittingPoseSlide2From 0x021BA550 data a4
 *   gDupFittingPoseSlide2To 0x021BA548 data a4
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   MUSICAL_MCSS_GetElemC 0x021F5158 thumb ov112
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   BG_SYS_GetPriority 0x020416D4 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   DUP_FITTING_ITEM_NoOp 0x021BA0C8 thumb ov133
 *   DUP_FITTING_ITEM_CreateList 0x021BA0CC thumb ov133
 *   DUP_FITTING_ITEM_DeleteList 0x021BA0F8 thumb ov133
 *   DUP_FITTING_ITEM_InsertElem 0x021BA100 thumb ov133
 *   DUP_FITTING_ITEM_InsertElemTail 0x021BA124 thumb ov133
 *   DUP_FITTING_ITEM_RemoveElem 0x021BA148 thumb ov133
 *   DUP_FITTING_ITEM_ListGetHead 0x021BA184 thumb ov133
 *   DUP_FITTING_ITEM_ListGetCount 0x021BA188 thumb ov133
 *   DUP_FITTING_ITEM_ListIsFull 0x021BA18C thumb ov133
 *   DUP_FITTING_ITEM_CreateElem 0x021BA19C thumb ov133
 *   DUP_FITTING_ITEM_DeleteElem 0x021BA1D8 thumb ov133
 *   DUP_FITTING_ITEM_FreeElemImage 0x021BA1EC thumb ov133
 *   DUP_FITTING_ITEM_ElemGetNext 0x021BA208 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetData 0x021BA20C thumb ov133
 *   DUP_FITTING_ITEM_ElemSetSprite 0x021BA210 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetSprite 0x021BA214 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetRenderElem 0x021BA218 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetPos 0x021BA21C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetPos 0x021BA228 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetBasePos 0x021BA22C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetBasePos 0x021BA238 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetStartScale 0x021BA23C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetStartScale 0x021BA240 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetScale 0x021BA244 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetScale 0x021BA248 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetAnimFrames 0x021BA24C thumb ov133
 *   DUP_FITTING_ITEM_ElemGetAnimFrames 0x021BA250 thumb ov133
 *   DUP_FITTING_ITEM_ElemSetFrameIndex 0x021BA254 thumb ov133
 *   DUP_FITTING_ITEM_ElemGetFrameIndex 0x021BA258 thumb ov133
 *   DUP_FITTING_ITEM_ElemHitTest 0x021BA25C thumb ov133
 *   DUP_FITTING_ITEM_ElemHitDistance 0x021BA324 thumb ov133
 *   GFL_USE_GetRandomBelow       0x02005728  thumb
 *   _fadd                        0x0209C95C  arm
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _ffixu                       0x0209C4C8  arm
 *   _fflt                        0x0209BDBC  arm
 *   _ffltu                       0x0209BE04  arm
 *   _fgr                         0x0209BBB0  arm
 *   _fmul                        0x0209C77C  arm
 *   _fsub                        0x0209CB8C  arm
 *   _u32_div_f                   0x0209C2B0  arm
 *   _ull_mul                     0x0209C054  arm
 */
#include "dup_fitting_types.h"
#include "../sdk_ioreg.h"
#define FXI(d) ((fx32)(((d) > 0) ? ((d) * 4096 + .5f) : ((d) * 4096 - .5f)))

#define FXF(x) ((fx32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))

struct Big;

struct ClactActor;

struct Descriptor;

struct Bank;

struct Node;

struct Board;

struct G3dCamera;

struct Cfg;

struct Lights;

struct PrintSys;

struct BbBoard;

struct DispConfig;

struct DispVram;

struct Light;

struct BgTemplate;

struct Desc;

struct Layer;

struct Tagged;

struct Vec3;

struct Manager0204F684;

struct Trip;

struct Vec2;

struct WordSet;

struct GfFont;

struct MsgBank;

struct CharBuf;

struct U16Vec;

struct ClactActor;

typedef struct { u32 x, y, z; } VecU;

typedef struct { u32 words[2]; u8 a,b,c,d; u32 field; u16 dims[6]; } DupFittingConfig;

typedef enum { DISP_SUB_MAIN=0, DISP_MAIN_SUB=1 } DispSelect;

typedef struct {short x,y,index;u8 a,b;} DupFittingActorParam;

#include "../types.h"

typedef struct {short y,x;u16 limit;} DupFittingScaleLimit;

typedef struct { short y,x; } DupFittingScaleXY;

typedef enum { I_ZERO = 0, I_LIMIT = 9 } DupFittingIndex;

typedef struct { short s; short c; } SC;

typedef struct { short x; short y; } DupFittingPt;

typedef struct { u8 bytes[12]; } Rects;

typedef struct {short x,y;} DupFittingPos;


struct BmpWin;
#ifdef __MWERKS__
#define G3D_SYSTEM_Init G3D_SYSTEM_Init_hdr
#endif
#include "../arm9/g3d_system.h"
#ifdef __MWERKS__
#undef G3D_SYSTEM_Init
void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));
#endif
#include "../arm9/bmp_menuwork.h"
#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/gfl_use.h"

#include "../arm9/wipe.h"
struct MusicalSave;

#include "../arm9/musical_save.h"



#include "../arm9/net.h"

#include "../arm9/ui.h"



#include "../arm9/clact.h"




#include "../arm9/bmp_win.h"



#include "../ov112/mus_poke_draw.h"

struct TcbTask;

#include "../arm9/tcb_list.h"

#include "../arm9/billboard.h"

#include "../arm9/g3d_camera.h"


#ifdef __MWERKS__
#define BG_SYS_SetPlaneVisible BG_SYS_SetPlaneVisible_hdr
#define BG_SYS_FreeSlot BG_SYS_FreeSlot_hdr
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_SetPlaneVisible
#undef BG_SYS_FreeSlot
void BG_SYS_SetPlaneVisible(unsigned int, unsigned int);
void BG_SYS_FreeSlot(unsigned int);
#endif








#include "../ov132/mus_comm_func.h"


#include "../ov132/sta_net.h"


struct McssActorPool;

#include "../ov112/mus_item_draw.h"

struct LightSlot;
struct G3dCamera;





struct PrintQueue;

#include "../arm9/printsys.h"






#include "../arm9/net_err.h"



#include "../ov112/mus_item_data.h"

















struct G3dCamera;


#include "../arm9/g3x.h"





#include "../arm9/g2.h"
struct DispVramCfg;
struct SysInit;






#include "../arm9/arc_tool.h"

#include "../arm9/arc_util.h"


















struct MusicalOutfit;




struct McssActorElem;





struct G3dResource;







#include "../arm9/nns_g3d_tex.h"


#include "../arm9/os_cache.h"












#include "../arm9/touchpanel.h"


#include "../arm9/gf_standard.h"





struct McssOffset;








#include "../arm9/fx_cp.h"


#include "../arm9/gf_font.h"

#include "../arm9/wordset.h"


#include "dup_fitting_item.h"

#include "../arm9/fx_atanidx.h"




#include "../arm9/msgdata.h"






struct Strbuf;

struct Bmp;


typedef short s16_p07;
#include "../arm9/bmp.h"

#include "../arm9/strbuf.h"















u8 *DUP_FITTING_Create(u8 *parent, int heap);

void DUP_FITTING_Delete(char *p);

int DUP_FITTING_Main(struct DupFittingWork *p);

void DUP_FITTING_VBlank(void *unused, struct DupFittingWork *p);

void DUP_FITTING_InitDisplay(struct DupFittingWork *p);

void DUP_FITTING_InitModels(struct DupFittingWork *p);

void DUP_FITTING_InitBgLayer(const void *t,unsigned int id);

void DUP_FITTING_InitRenderObj(struct DupFittingWork *p);

void DUP_FITTING_InitFrames(struct DupFittingWork *p);

void DUP_FITTING_AddFitElemById(struct DupFittingWork *p,u16 id);

void DUP_FITTING_RandomPos(void *unused, int *p);

void DUP_FITTING_FreeElements(struct DupFittingWork *p);

void DUP_FITTING_UpdateIdle(struct DupFittingWork *p);

void *DUP_FITTING_SetModelTransform(struct DupFittingWork *p, u16 base, short speed, u16 rx, u16 ry);

void DUP_FITTING_FreeHeldElem(struct DupFittingWork *p);

void DUP_FITTING_UpdateCursor(struct DupFittingWork *p);

void DUP_FITTING_RotateToCursor(struct DupFittingWork *p, int unused_x, int unused_y);

int DUP_FITTING_PickElem(struct DupFittingWork *p, void *q, u32 a);

void DUP_FITTING_AttachElem(struct DupFittingWork *p,int sound);

void DUP_FITTING_CreateFitElem(struct DupFittingWork *p);

void DUP_FITTING_ReleaseElem(struct DupFittingWork *p);

void DUP_FITTING_ReturnElem(struct DupFittingWork *p, int unused);

void DUP_FITTING_MoveElem(struct DupFittingWork *p);

void DUP_FITTING_UpdateHeldElem(struct DupFittingWork *p);

int DUP_FITTING_SelectFrame(struct DupFittingWork *p);

void DUP_FITTING_UpdateSubMode(struct DupFittingWork *p);

void DUP_FITTING_UpdateRotation(struct DupFittingWork *p);

int DUP_FITTING_IsFrameOwned(struct DupFittingWork *p,unsigned int id);

int DUP_FITTING_FindNearestFrame(struct DupFittingWork *p, void *manager, const int *pos, u16 *limit);

void DUP_FITTING_DrawElems(struct DupFittingWork *p);

void DUP_FITTING_UpdateHeldVisible(struct DupFittingWork *p);

int DUP_FITTING_HitCircle(int x,int y,int radius,float scale);

void DUP_FITTING_SortFrames(struct DupFittingWork *p, int kind, u16 start);

u16 DUP_FITTING_FrameWeight(struct DupFittingWork *p, u8 *q, int v);

void DUP_FITTING_DrawFrames(struct DupFittingWork *p);

int DUP_FITTING_HandleTouch(struct DupFittingWork *p);

void DUP_FITTING_ResetSlots(struct DupFittingWork *p);

void DUP_FITTING_HandlePickTouch(struct DupFittingWork *p);

void DUP_FITTING_DragRotate(struct DupFittingWork *p);

void DUP_FITTING_SaveOutfits(struct DupFittingWork *p);

void DUP_FITTING_DrawBackActors(struct DupFittingWork *p);

void DUP_FITTING_EnterPoseMode(struct DupFittingWork *p);

void DUP_FITTING_ExitPoseMode(struct DupFittingWork *p);

void DUP_FITTING_UpdatePose(struct DupFittingWork *p);

void DUP_FITTING_StepPoseRotate(struct DupFittingWork *p,u16 a,int delta,u16 duration);

void DUP_FITTING_StepPoseHold(struct DupFittingWork *p,unsigned int limit);

void DUP_FITTING_StepPoseSlide(struct DupFittingWork *p, int *a, int *b, u16 duration);

void DUP_FITTING_CreateText(struct DupFittingWork *p);

void DUP_FITTING_DeleteText(struct DupFittingWork *p);

void DUP_FITTING_SetText(struct DupFittingWork *p, unsigned int index, void *object);

void DUP_FITTING_SetTextMon(struct DupFittingWork *p);

void DUP_FITTING_SetTextItem(struct DupFittingWork *p, u8 *entry);

void DUP_FITTING_SetTextHelp(struct DupFittingWork *p, int state);

void DUP_FITTING_CreateActors(struct DupFittingWork *p);

void DUP_FITTING_DeleteActors(struct DupFittingWork *p);

void DUP_FITTING_UpdateActorTimers(struct DupFittingWork *p);

void DUP_FITTING_ResetActorPose(struct DupFittingWork *p);































extern const char d_021BA600[];

extern u8 d_021BA518[],d_021BA418[],d_021BA428[],d_021BA438[],d_021BA458[],d_021BA478[],d_021BA4F8[],d_021BA498[],d_021BA4B8[],d_021BA4D8[];

extern VecU d_021BA3F4,d_021BA40C,d_021BA400;

extern DupFittingConfig gClActorInitParam,d_021BA5C4;

extern u32 d_021BA3E0[];

extern const short FX_SinCosTable_[];

extern u8 d_021BA3E4[], d_021BA3E8[];

extern const DupFittingVec d_021BA5A0;

extern const DupFittingVec d_021BA5B8;

extern const DupFittingVec d_021BA588;

extern const DupFittingPair d_021BA568;

extern const DupFittingVec d_021BA570;

extern const DupFittingVec d_021BA57C,d_021BA5AC;

extern const Rects d_021BA594;

extern const DupFittingPair gDupFittingPoseSlide1From, gDupFittingPoseSlide1To, gDupFittingPoseSlide2From, gDupFittingPoseSlide2To;

extern const short FX_SinCosTable_[];

u8 *DUP_FITTING_Create(u8 *parent, int heap)
{
    struct DupFittingWork *work = GFL_HEAP_Alloc(heap, sizeof(struct DupFittingWork), 1, d_021BA600, 0x1de);
    u32 t, m;
    work->heapId = heap;
    work->parent = (struct DupFittingOwner *)parent;
    work->state = 7;
    work->progress = 0;
    work->touchTrg = 0;
    work->touchCont = 0;
    work->dragActive = 0;
    work->heldElem = 0;
    work->holdState = 0;
    work->holdKind = 0;
    work->subMode = 0;
    work->sortMode = 8;
    work->rotation = 0;
    work->spin = 0;
    work->spinAccel = 0;
    work->firstTouch = 0;
    work->brightness = 0;
    work->mode = 0;
    work->flag = 0;
    work->busy = 0;
    work->sentinel = 0xff;
    work->counter = 0;
    work->startAngle = 0;
    work->window = 0;
    work->rotationVel = 0;
    work->frameIndex = 10;
    DUP_FITTING_InitDisplay(work);
    DUP_FITTING_InitModels(work);
    DUP_FITTING_InitRenderObj(work);
    DUP_FITTING_InitFrames(work);
    DUP_FITTING_CreateActors(work);
    DUP_FITTING_CreateText(work);
    work->task = GFL_USE_AddMainTask((void *)DUP_FITTING_VBlank, work, 8);
    WIPE_SYS_Start((void *)2, 1, 1, 0x7fff, 18, 1, work->heapId);
    t = work->startAngle + 0x18000;
    work->cooldown = 10;
    m = work->frameCount * 0x1249;
    {
        u16 x;
        if (t >= m)
            x = (t - m) / 0x1249;
        else
            x = t / 0x1249;
        DUP_FITTING_SortFrames(work, 8, x);
    }
    work->sortMode = 8;
    work->subMode = 1;
    work->subTurned = 0;
    work->subTurnTarget = work->rotation % 0x1249 + 0x10000;
    if (MUSICAL_SAVE_GetFittingSetting(work->parent->saveData) == 0) {
        MUSICAL_SAVE_SetFittingSetting(work->parent->saveData, 1);
        work->startInPose = 1;
    } else {
        work->startInPose = 0;
    }
    GFL_USE_CancelChangeAndPlayBgm(0x454, 0xffff);
    GFL_NET_RefreshWmIconAtTopRight(0, work->heapId);
    return (u8 *)work;
}

void DUP_FITTING_Delete(char *obj)
{
    struct DupFittingWork *work = (struct DupFittingWork *)obj;
    u8 i;
    UI_SetInputMode(1);
    MUSICAL_SAVE_ClearNewProps(work->parent->saveData);
    GFL_USE_CancelChangeAndStopBgm();
    DUP_FITTING_DeleteText(work);
    DUP_FITTING_DeleteActors(work);
    CLACT_DeleteActor((struct ClactActor *)((struct ClactActor *)(work->actorA)));
    CLACT_DeleteActor((struct ClactActor *)((struct ClactActor *)(work->actorB)));
    CLACT_DeleteActor((struct ClactActor *)((struct ClactActor *)(work->actorC)));
    for(i=0;i<=2;i++) CLACT_ReleasePalette(work->clactRes[i]);
    for(i=3;i<=5;i++) CLACT_ReleaseCharacter(work->clactRes[i]);
    for(i=6;i<=8;i++) CLACT_ReleaseCellAnim(work->clactRes[i]);
    if(work->window) BMP_WIN_Delete((struct BmpWin *)(work->window));
    CLACT_DeleteUnit((struct Unit *)(work->clactUnit));
    CLACT_ExitSystem();
    DUP_FITTING_FreeElements(work);
    MUSICAL_MCSS_FreeRenderObj(work->renderObj,work->renderParam);
    MUSICAL_MCSS_DeleteRenderObj(work->renderObj);
    TCB_DeleteTask((struct TcbTask *)(work->task));
    BILLBOARD_Delete(work->billboard);
    G3D_CAMERA_Delete(work->camera);
    G3D_SYSTEM_Exit();
    BG_SYS_FreeLayerBuf(0);BG_SYS_FreeLayerBuf(1);BG_SYS_FreeLayerBuf(2);BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(4);BG_SYS_FreeLayerBuf(6);BG_SYS_FreeLayerBuf(5);BG_SYS_FreeLayerBuf(7);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    GFL_HEAP_Free(work);
}

static inline void brightness(u8 *value)
{
    BG_SYS_ChangeScroll(6,0,128-*value);
    BG_SYS_ChangeScroll(5,0,*value-128);
}

int DUP_FITTING_Main(struct DupFittingWork *work)
{
    void *desc;
    switch(work->state) {
    case 7:
        GFL_USE_PlaySeDefaultVolume(1358); work->state=8;
    case 8:
        if(WIPE_SYS_EndCheck()==1) {
            if(work->startInPose==1) DUP_FITTING_EnterPoseMode(work);
            else work->state=1;
        }
        if(work->subMode==1) DUP_FITTING_UpdateSubMode(work);
        break;
    case 9:
        if(WIPE_SYS_EndCheck()==1 && GFL_USE_IsBgmFading()==0) return 2;
        break;
    case 0: DUP_FITTING_UpdatePose(work); break;
    case 1: DUP_FITTING_UpdateIdle(work); break;
    case 2:
        work->progress+=6;
        if((int)work->progress>=192) {
            DUP_FITTING_SetText(work,1,0); work->progress=192; work->state=3;
            work->spin=0; work->spinAccel=0; work->clampSlack=0;
        }
        DUP_FITTING_DrawFrames(work); break;
    case 6:
        work->progress-=6;
        if((int)work->progress<0) { work->progress=0; work->state=1; }
        DUP_FITTING_DrawFrames(work); break;
    case 3:
        if(DUP_FITTING_HandleTouch(work)==2) { work->state=10; work->exitTimer=0; CLACT_SetActorDrawEnable((struct ClactActor *)work->actorX,1); }
        break;
    case 10:
        work->exitTimer++; DUP_FITTING_DrawBackActors(work);
        if(work->exitTimer>60) {
            if(work->parent->comm==0) {
                WIPE_SYS_Start(0,0,0,0x7fff,18,1,work->heapId); GFL_USE_FadeOutBgm(60); work->state=9; work->mode=1;
            } else {
                DUP_FITTING_SetText(work,2,0); MUS_COMM_FUNC_SetTimingSync((sptr)work->parent->comm,69); work->state=4;
            }
        }
        break;
    case 4:
        if(MUS_COMM_FUNC_CheckTimingSync(work->parent->comm,69)==1) work->state=5;
        break;
    case 5:
        if(STA_NET_IsTransferDone(work->parent->comm)==1) {
            WIPE_SYS_Start(0,0,0,0x7fff,18,1,work->heapId); GFL_USE_FadeOutBgm(60); work->state=9; work->mode=1;
        }
        break;
    }
    DUP_FITTING_UpdateActorTimers(work); DUP_FITTING_DrawElems(work); MUSICAL_MCSS_TickAnim(work->renderObj);
    MUSICAL_MCSS_UpdateObject((struct McssActorPool *)(work->elemSet)); CLACT_DrawSystem(); G3D_SYSTEM_DrawStart(); G3D_SYSTEM_ApplyLookAt();
    MUSICAL_MCSS_DrawRenderObj(work->renderObj); BILLBOARD_Draw((struct BbBoard *)work->billboard,(struct G3dCamera *)work->camera,0); G3D_SYSTEM_DrawEnd();
    work->counter++;
    if(work->counter>1) {
        work->counter=0;
        BG_SYS_ChangeScroll(3,1,1); BG_SYS_ChangeScroll(3,5,1);
    }
    if(work->mode==0) {
        if(work->brightness<128) { work->brightness+=8; brightness(&work->brightness); }
        else if(work->flag==0) {
            work->flag=1; BG_SYS_ClearLayer(7,0);
            work->window=(void *)BMP_WIN_Create(7,1,19,30,4,14,1);
            if(work->startInPose==0) DUP_FITTING_SetTextMon(work); else DUP_FITTING_SetText(work,6,0);
            BMP_MENUWORK_DrawWindow((struct BmpWin *)work->window,1,128,12);
        }
    } else {
        if(work->flag==1) {
            DUP_FITTING_ITEM_NoOp(work,2); work->flag=0;
            BG_SYS_SetPriority(7,3); BG_SYS_SetPriority(4,0); BG_SYS_SetPriority(5,1); BG_SYS_SetPriority(6,2);
            DUP_FITTING_ITEM_NoOp(work,4); ARC_UTIL_UploadBgPaletteFromArchive(46,13,7,0,0,0,work->heapId); BG_SYS_MarkTileDirty(7);
            work->busy=0; PRINTSYS_QUE_Clear((struct PrintQueue *)work->printSys); BMP_WIN_Delete((struct BmpWin *)work->window); work->window=0; DUP_FITTING_ITEM_NoOp(work,6);
        } else if(work->brightness!=0) {
            DUP_FITTING_ITEM_NoOp(work,work->brightness+96); work->brightness-=8; brightness(&work->brightness);
        }
    }
    DUP_FITTING_ITEM_NoOp(work,8);
    if(work->busy==0 && work->state==1) {
        if(work->heldElem!=0 && work->sentinel!=*(u16 *)DUP_FITTING_ITEM_ElemGetData(work->heldElem)) {
            DUP_FITTING_SetTextItem(work,work->heldElem); work->sentinel=*(u16 *)DUP_FITTING_ITEM_ElemGetData(work->heldElem);
        } else if(work->sentinel!=255 && work->heldElem==0) { DUP_FITTING_SetTextMon(work); work->sentinel=255; }
    }
    DUP_FITTING_ITEM_NoOp(work,10);
    if(work->busy==1 && PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printSys)==1) {
        work->busy=0; desc=work->window;
        BMP_WIN_TransferChars(desc); BMP_WIN_MakeScreen(desc); BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(desc));
        BG_SYS_SetPriority(4,1); BG_SYS_SetPriority(5,2); BG_SYS_SetPriority(6,3); BG_SYS_SetPriority(7,0);
    }
    DUP_FITTING_ITEM_NoOp(work,12);
    if(work->printSys!=0) PRINTSYS_QUE_Main((struct PrintQueue *)work->printSys);
    DUP_FITTING_ITEM_NoOp(work,14);
    if(work->cooldown!=0) work->cooldown--;
    if(work->parent->comm!=0 && work->state!=7 && work->state!=8 && work->state!=9) {
        DUP_FITTING_ITEM_NoOp(work,32);
        if(GFL_NET_ERR_GetErrorLevel()!=0) {
            DUP_FITTING_ITEM_NoOp(work,34); WIPE_SYS_Start(0,0,0,0x7fff,18,1,work->heapId); GFL_USE_FadeOutBgm(60);
            DUP_FITTING_ITEM_NoOp(work,36); work->state=9; DUP_FITTING_ITEM_NoOp(work,38);
        } else DUP_FITTING_ITEM_NoOp(work,64);
    }
    DUP_FITTING_ITEM_NoOp(work,16);
    return 0;
}

void DUP_FITTING_VBlank(void *unused, struct DupFittingWork *work)
{
    u32 height, width;
    u16 sizes[2];
    int changed;
    u8 *e, *q, *r;
    u8 *table;
    int flags;
    u16 index;
    e = DUP_FITTING_ITEM_ListGetHead(work->itemList);
    changed = 0;
    while (e) {
        DUP_FITTING_ITEM_ElemGetRenderElem(e);
        q = (u8 *)DUP_FITTING_ITEM_ElemGetData(e);
        r = DUP_FITTING_ITEM_ElemGetSprite(e);
        if (*(u16 *)q != *(u16 *)r) {
            DUP_FITTING_ITEM_FreeElemImage(e, work->elemSet, r);
            changed = 1;
        }
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
    if (changed == 1) DUP_FITTING_FreeHeldElem(work);
    if (work->heldElem) {
        q = (u8 *)DUP_FITTING_ITEM_ElemGetData(work->heldElem);
        if (work->heldItemId != *(u16 *)q) {
            table = MUSICAL_MCSS_GetActorPoolResource(work->elemSet);
            work->heldItemId = *(u16 *)q;
            BILLBOARD_GetImagePlttKey((work->billboard), work->bmpKeyA, (&height));
            BILLBOARD_GetImageTexKey((struct BbBoard *)(work->billboard), *(int *)(q + 4), &width);
            BILLBOARD_SetImageTexAddr(work->billboard, work->bmpKeyA, width);
            flags = MUSICAL_MCSS_GetElemSizeFlags((int *)MUSICAL_MCSS_GetElemPtr(table, work->heldItemId));
            BILLBOARD_GetImageSizeFromFlags(flags, &sizes[1], &sizes[0]);
            index = BILLBOARD_AddImageFromVramKeys(work->billboard, width, height, 0, flags, sizes[1], sizes[0]);
            MUSICAL_MCSS_FreeElemImage(work->elemSet, work->elemPool, work->heldItemId, index);
            BILLBOARD_ReleaseImageVramIfUsed(work->billboard, work->bmpKeyA);
            work->bmpKeyA = index;
        }
    }
    CLACT_VBlankSystem();
    MUSICAL_MCSS_NoOp3(work->elemSet);
}

static inline void visible_main(int plane)
{
    *(volatile u32 *)REG_DISPCNT_ADDR = (u32)((*(volatile u32 *)REG_DISPCNT_ADDR & ~0x1f00u) | (plane << 8));
}

static inline void visible_sub(int plane)
{
    *(volatile u32 *)REG_DB_DISPCNT_ADDR = (u32)((*(volatile u32 *)REG_DB_DISPCNT_ADDR & ~0x1f00u) | (plane << 8));
}

static inline void select_display(DispSelect sel)
{
    *(volatile u16 *)REG_POWCNT1_ADDR = (u16)((*(volatile u16 *)REG_POWCNT1_ADDR & ~0x8000u) | (sel << 15));
}

void DUP_FITTING_InitDisplay(struct DupFittingWork *work)
{
    DupFittingConfig cfg, board;
    BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    visible_main(0);
    visible_sub(0);
    WIPE_SetBrightnessFadeOut(0,0); WIPE_SetBrightnessFadeOut(1,0);
    WIPE_ResetWndMask(0); WIPE_ResetWndMask(1);
    *(volatile u16 *)REG_BLDCNT_ADDR = 0;
    *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0;
    select_display(DISP_SUB_MAIN);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BA518);
    G3D_SYSTEM_Init(0,2,0,1,0,work->heapId,0);
    G3D_SYSTEM_SetSwapBuffersMode(0,1);
    work->camera = G3D_CAMERA_Create(2,0xc000,0,0,0x10000,0x1000,0x3e8000,0,(VecFx32 *)&d_021BA3F4,(VecFx32 *)&d_021BA40C,(VecFx32 *)&d_021BA400,work->heapId);
    G3D_CAMERA_Reset(work->camera);
    G3X_SetEdgeColorTable(d_021BA418);
    *(volatile u16 *)REG_DISP3DCNT_ADDR &= 0xcfdf;
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
    BG_SYS_Create(work->heapId); BMP_WIN_Init(work->heapId);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BA428); BG_SYS_EnableBg0WithPriority(1);
    DUP_FITTING_InitBgLayer(d_021BA438,1); DUP_FITTING_InitBgLayer(d_021BA458,2);
    DUP_FITTING_InitBgLayer(d_021BA478,3); DUP_FITTING_InitBgLayer(d_021BA4F8,7);
    DUP_FITTING_InitBgLayer(d_021BA498,4); DUP_FITTING_InitBgLayer(d_021BA4B8,5); DUP_FITTING_InitBgLayer(d_021BA4D8,6);
    BG_SYS_SetPlaneVisible(0,1);
    G2x_SetBlendAlpha_((void *)REG_DB_BLDCNT_ADDR,0,15,4,16);
    cfg = gClActorInitParam;
    cfg.a = 16; cfg.b = 112;
    CLACT_InitSystem((const struct ClactSysInit *)((struct SysInit *)(&cfg)),(const struct DispVramCfg *)d_021BA518,work->heapId);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
    work->clactUnit = CLACT_CreateUnit(24,0,work->heapId);
    CLACT_SetUnitDefaultRenderer(work->clactUnit);
    board = d_021BA5C4;
    work->billboard = BILLBOARD_Create((u8 *)&board,work->heapId);
}

/*
 * note 2026-10-05 (wD9r lane78): EXACT. Closed by declaring ARC_UTIL_UploadBgCharFromHandle with its real return type u32
 *   (it returns ARC_UTIL_UploadBgChar's u32 result, as the matched sibling ARC_UTIL_UploadBgCharFromArchive does), not void. The void
 *   prototype hoisted 4 into r7 and turned later zeros into adds rN,r6,#0 copies. 0xd and -128 are literals.
 *   See docs/idioms/a-getter-declared-void-changes-constant-hoisting.md.
 */
void DUP_FITTING_InitModels(struct DupFittingWork *work)
{
    DupFittingActorParam cfg;
    void *g = ARC_TOOL_CreateHandle(0x2e, work->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(g, 4, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgCharFromHandle(g, 7, 3, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(g, 0xc, 3, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(g, 0xb, 2, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(g, 3, 4, 0, 0, work->heapId);
    ARC_UTIL_UploadBgCharFromHandle(g, 0xa, 4, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgCharFromHandle(g, 9, 7, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(g, 0x10, 4, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(g, 0xf, 6, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(g, 0xe, 5, 0, 0, 0, work->heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(g, 0xd, 7, 0, 0, 0, work->heapId);
    BG_SYS_ChangeScroll(6, 0, 128);
    BG_SYS_ChangeScroll(5, 0, -128);
    work->clactRes[0] = CLACT_RegisterPalette(g, 2, 0, 0, work->heapId);
    work->clactRes[3] = CLACT_RegisterCharacter(g, 8, 0, 0, work->heapId);
    work->clactRes[6] = CLACT_RegisterCellAnim(g, 0x14, 0x18, work->heapId);
    work->clactRes[2] = CLACT_RegisterPalette(g, 1, 1, 0, work->heapId);
    work->clactRes[5] = CLACT_RegisterCharacter(g, 6, 0, 1, work->heapId);
    work->clactRes[8] = CLACT_RegisterCellAnim(g, 0x13, 0x17, work->heapId);
    work->clactRes[1] = CLACT_RegisterPalette(g, 0, 0, 0x40, work->heapId);
    work->clactRes[4] = CLACT_RegisterCharacter(g, 5, 0, 0, work->heapId);
    work->clactRes[7] = CLACT_RegisterCellAnim(g, 0x11, 0x15, work->heapId);
    cfg.x = 32; cfg.y = 224; cfg.index = 0; cfg.a = 0; cfg.b = 2;
    work->actorA = CLACT_CreateActor((void *)work->clactUnit, work->clactRes[3], work->clactRes[0], work->clactRes[6], (const struct ActorInitParam *)&cfg, 0, work->heapId);
    cfg.x = 224; cfg.y = 224; cfg.index = 1;
    work->actorB = CLACT_CreateActor((void *)work->clactUnit, work->clactRes[3], work->clactRes[0], work->clactRes[6], (const struct ActorInitParam *)&cfg, 0, work->heapId);
    cfg.x = 128; cfg.y = 96; cfg.index = 2; cfg.a = 0; cfg.b = 0;
    work->actorC = CLACT_CreateActor((void *)work->clactUnit, work->clactRes[3], work->clactRes[0], work->clactRes[6], (const struct ActorInitParam *)&cfg, 0, work->heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)(work->actorA), 1);
    CLACT_SetActorDrawEnable((struct ClactActor *)(work->actorB), 1);
    CLACT_SetActorDrawEnable((struct ClactActor *)(work->actorC), 0);
    ARC_TOOL_DeleteHandle(g);
    BG_SYS_PushTile(3);
    BG_SYS_PushTile(2);
    BG_SYS_PushTile(7);
}

void DUP_FITTING_InitBgLayer(const void *t,unsigned int id) {BG_SYS_InitBgLayer(id,t,0);BG_SYS_SetPlaneVisible(id,1);BG_SYS_FreeSlot(id);BG_SYS_PushTile(id);}

void DUP_FITTING_InitRenderObj(struct DupFittingWork *work)
{
    int v[3];
    int *q;
    work->renderObj = MUSICAL_MCSS_CreateRenderObj(work->heapId);
    MUSICAL_MCSS_SetRenderCellVramBase(work->renderObj, 0x50000);
    MUSICAL_MCSS_SetRenderAnimVramBase(work->renderObj, 0x3fe0);
    work->renderParam = MUSICAL_MCSS_SetupRenderObj(work->renderObj, (const u8 *)work->parent->outfitTable, 0);
    MUSICAL_MCSS_TickAnim(work->renderObj);
    MUSICAL_MCSS_DrawRenderObj(work->renderObj);
    q = (int *)MUSICAL_MCSS_GetRenderFlags(work->renderParam);
    v[0] = (0x80000 - q[0]) / 16;
    v[1] = (0xc0000 - (0x70000 - q[1])) / 16;
    v[2] = 0x28000;
    MUSICAL_MCSS_SetRenderPos(work->renderParam, v);
}

extern u32 (*d_020A8148)(u32, u32, u32);

void DUP_FITTING_InitFrames(struct DupFittingWork *work)
{
    int i;
    int j;
    u32 zero;
    u8 *table;
    void *h;
    int w;
    u32 flags;
    u32 vram;
    u32 hgt;
    u32 sz;
    u16 sizes[2];
    u16 dims[2];
    u16 *pal;
    u32 n;
    u8 k;
    u8 *buf;
    void *res;
    u8 *e;

    work->frameCount = 0;
    zero = 0;
    for (i = 0; i < 250; i++) {
        if (MUSICAL_SAVE_IsPropOwned(work->parent->saveData, i) == 1) {
            work->frames[work->frameCount].id = i;
            work->frames[work->frameCount].mode = zero;
            if (MUSICAL_SAVE_IsPropNew(work->parent->saveData, i) == 1)
                work->frames[work->frameCount].owned = 1;
            else
                work->frames[work->frameCount].owned = zero;
            (work->frameCount)++;
        }
    }
    for (j = 0; work->frameCount + j < 250; j++) {
        work->frames[(work->frameCount + j)].id = 0xff;
        work->frames[(work->frameCount + j)].mode = 0;
        work->frames[work->frameCount].owned = 1;
    }

    work->elemSet = (u8 *)MUSICAL_MCSS_CreateActorPool((uptr)(work->billboard), 0x98, work->heapId);
    table = MUSICAL_MCSS_GetActorPoolResource(work->elemSet);

    for (i = 0; i < work->frameCount; i++) {
        h = MUSICAL_MCSS_CreateResourceArc(work->frames[i].id);
        G3D_SYSTEM_TransVramTexture(h);
        w = G3D_SYSTEM_GetTexVramKey(h);
        hgt = G3D_SYSTEM_GetPlttVramKey(h);
        sz = ((hgt & 0xFFFF0000) >> 16) << 3;
        vram = d_020A8148(sz, 0, 0);
        flags = MUSICAL_MCSS_GetElemSizeFlags((int *)MUSICAL_MCSS_GetElemPtr(table, work->frames[i].id));
        BILLBOARD_GetImageSizeFromFlags(flags, &sizes[1], &sizes[0]);
        work->frames[i].imageKeyA = BILLBOARD_AddImageFromVramKeys(work->billboard, w, hgt, 0, flags, sizes[1], sizes[0]);
        pal = (u16 *)G3D_SYSTEM_GetPlttDataAddr(h);
        n = sz >> 1;
        for (k = 0; k < n; k++) {
            u16 c = pal[k];
            u32 b = (u32)(u8)((c & 0x7C00) >> 10) >> 3;
            u32 r = (u32)(u8)(c & 0x1F) >> 3;
            u32 g = (u32)(u8)((c & 0x3E0) >> 5) >> 3;
            pal[k] = r | (g << 5) | (b << 10);
        }
        buf = G3D_SYSTEM_GetResourceFile(h);
        res = G3D_SYSTEM_GetResourceTex(h);
        NNS_G3dPlttSetPlttKey(res, vram);
        DC_FlushRange(buf, *(u32 *)(buf + 8));
        NNS_G3dPlttLoad(res, 1);
        work->frames[i].imageKeyB = BILLBOARD_AddImageFromVramKeys(work->billboard, w, vram, 0, flags, sizes[1], sizes[0]);
        MUSICAL_MCSS_FreeResourceArc(h);
    }

    DUP_FITTING_SortFrames(work, 8, 0);
    work->itemList = DUP_FITTING_ITEM_CreateList(work->heapId, 0xe);
    work->listA = DUP_FITTING_ITEM_CreateList(work->heapId, 0x80);
    work->listB = DUP_FITTING_ITEM_CreateList(work->heapId, 9);
    work->listC = DUP_FITTING_ITEM_CreateList(work->heapId, 4);

    for (i = 0; i < 14; i++) {
        DupFittingVec v = {0, 0, 0};
        e = DUP_FITTING_ITEM_CreateElem(work->heapId, work->elemSet, (u8 *)&work->frames[i], (int *)(&v));
        DUP_FITTING_ITEM_InsertElem(work->itemList, e);
        MUSICAL_MCSS_SetElemFlag(work->elemSet, (struct McssActorElem *)DUP_FITTING_ITEM_ElemGetRenderElem(e), 0);
    }

    {
    DupFittingVec imageOffset = {0, 0, 0};
    work->heldItemId = 0;
    flags = MUSICAL_MCSS_GetElemSizeFlags((int *)MUSICAL_MCSS_GetElemPtr(table, work->heldItemId));
    BILLBOARD_GetImageSizeFromFlags(flags, &dims[1], &dims[0]);
    h = MUSICAL_MCSS_CreateResourceArc(work->heldItemId);
    G3D_SYSTEM_TransVramTexture(h);
    w = G3D_SYSTEM_GetTexVramKey(h);
    work->bmpKeyA = BILLBOARD_AddImageFromVramKeys(work->billboard, w, G3D_SYSTEM_GetPlttVramKey(h), 0, flags, dims[1], dims[0]);
    work->elemPool = (unsigned char *)MUSICAL_MCSS_AddImageNoVram((struct McssActorPool *)(work->elemSet), work->heldItemId, work->bmpKeyA, (int *)(&imageOffset));
    MUSICAL_MCSS_SetElemVisible(work->elemSet, work->elemPool, 0);
    MUSICAL_MCSS_SetElemRotZ((work->elemSet), (work->elemPool), 0x1000, 0x1000);
    MUSICAL_MCSS_TransferVram((char *)(work->elemSet), (char *)(work->elemPool), h);
    MUSICAL_MCSS_FreeResourceArc(h);
    }

    work->bmpKeyB = BILLBOARD_AddImageFromArchive(work->billboard, 0x2e, 0x19, 2, 0x22, 0x20, 0x20);
    for (k = 0; k < 14; k++) {
        DupFittingVec elemOffset = {0, 0, 0};
        n = BILLBOARD_AddElem((struct BbBoard *)(work->billboard), work->bmpKeyB, 0x1000, 0x1000, (VecFx32 *)((struct Vec3 *)(&elemOffset)), 0x1f, 0, 0);
        work->bmpHandles[k] = n;
        BILLBOARD_SetElemVisible(work->billboard, n, d_021BA3E0);
    }

    work->timer = 0;
    e = (unsigned char *)MUSICAL_SAVE_GetOutfits(work->parent->saveData);
    for (k = 0; k < 8; k++) {
        if (e[k * 6] != 10)
            DUP_FITTING_AddFitElemById(work, *(u16 *)(e + k * 6 + 2));
    }
    DUP_FITTING_FreeHeldElem(work);
    work->startAngle = work->frameCount * 0x1249 - 0x8000;
    DUP_FITTING_SetModelTransform(work, 0, 0, 0x48, 0x30);
}

void DUP_FITTING_AddFitElemById(struct DupFittingWork *work,u16 id)
{
    DupFittingPairU32 pos;
    DupFittingVec scale;
    u8 *e,*q;
    u8 i;
    e=0;
    for(i=0;i<work->frameCount;i++){
        if(id==work->frames[i].id){e=(u8 *)&work->frames[i];break;}
    }
    if(e){
        int y;
        DUP_FITTING_RandomPos(work,(int *)(&pos));
        if((int)pos.x>0) scale.x=(int)(0.5f+(float)((int)pos.x<<12));
        else scale.x=(int)((float)((int)pos.x<<12)-0.5f);
        if((int)pos.y>0) y=(int)(0.5f+(float)((int)pos.y<<12));
        else y=(int)((float)((int)pos.y<<12)-0.5f);
        scale.y=y;
        scale.z=(10<<12)-(DUP_FITTING_ITEM_ListGetCount((char *)(work->listA))<<10);
        q=DUP_FITTING_ITEM_CreateElem(work->heapId,work->elemSet,e,(int *)(&scale));
        DUP_FITTING_ITEM_InsertElem(work->listA,q);
        DUP_FITTING_ITEM_ElemSetPos(q,(const u8 *)(&pos));
        MUSICAL_MCSS_SetElemRotZ(work->elemSet,(u8 *)(DUP_FITTING_ITEM_ElemGetRenderElem(q)),0x1000,0x1000);
        *(u32 *)(e+0xc)=1;
    }
}

void DUP_FITTING_RandomPos(void *unused, int *pos)
{
    do {
        pos[0] = GFL_USE_GetRandomBelow(240) + 8;
        pos[1] = GFL_USE_GetRandomBelow(128) + 32;
    } while (DUP_FITTING_HitCircle((short)(pos[0] - 128), (short)(pos[1] - 80), 84, 0.739130437374115f) == 1);
}

void DUP_FITTING_FreeElements(struct DupFittingWork *work)
{
    u8 *e,*next;
    int i;
    e=DUP_FITTING_ITEM_ListGetHead(work->itemList);
    while(e){next=(u8 *)DUP_FITTING_ITEM_ElemGetNext(e);DUP_FITTING_ITEM_DeleteElem(e,work->elemSet);e=next;}
    e=DUP_FITTING_ITEM_ListGetHead(work->listA);
    while(e){next=(u8 *)DUP_FITTING_ITEM_ElemGetNext(e);DUP_FITTING_ITEM_DeleteElem(e,work->elemSet);e=next;}
    e=DUP_FITTING_ITEM_ListGetHead(work->listB);
    while(e){next=(u8 *)DUP_FITTING_ITEM_ElemGetNext(e);DUP_FITTING_ITEM_DeleteElem(e,work->elemSet);e=next;}
    e=DUP_FITTING_ITEM_ListGetHead(work->listC);
    while(e){next=(u8 *)DUP_FITTING_ITEM_ElemGetNext((u8 *)e);DUP_FITTING_ITEM_DeleteElem((u8 *)e,(u8 *)(work->elemSet));e=next;}
    for(i=0;i<14;i++)BILLBOARD_FreeElem((struct BbBoard *)(work->billboard),work->bmpHandles[i]);
    BILLBOARD_DeleteImage((struct BbBoard *)(work->billboard),work->bmpKeyB);
    MUSICAL_MCSS_FreeElem((u8 *)(work->elemSet),(u8 *)(work->elemPool));
    BILLBOARD_DeleteImage((struct BbBoard *)(work->billboard),work->bmpKeyA);
    for(i=0;i<work->frameCount;i++){
        BILLBOARD_DeleteImage((struct BbBoard *)(work->billboard),work->frames[i].imageKeyA);
        BILLBOARD_DeleteImage((struct BbBoard *)(work->billboard),work->frames[i].imageKeyB);
    }
    DUP_FITTING_ITEM_DeleteList(work->itemList);DUP_FITTING_ITEM_DeleteList(work->listA);
    DUP_FITTING_ITEM_DeleteList(work->listB);DUP_FITTING_ITEM_DeleteList(work->listC);
    MUSICAL_MCSS_DeleteActorPool(work->elemSet);
}

void DUP_FITTING_UpdateIdle(struct DupFittingWork *work)
{
    if (work->subMode == 1) DUP_FITTING_UpdateSubMode(work);
    else { DUP_FITTING_UpdateCursor(work); DUP_FITTING_UpdateRotation(work); }
    DUP_FITTING_UpdateHeldVisible(work);
    ++work->timer;
    if (work->timer >= 90) {
        work->timer = 0;
        DUP_FITTING_SetModelTransform(work, work->rotation, 0, 72, 48);
    }
    if (work->timer == 45)
        DUP_FITTING_SetModelTransform(work, work->rotation, 0, 72, 48);
}

static inline int GetTimer(struct DupFittingWork *work) { return work->timer; }

/*
 * 2026-10-05 (user decision): the field re-read in the loop (for (n = F; t >= n * K; n = F)) is accepted as a real source quirk.
 * note (2026-10-04, wave D3 lane 08): DIFF, same length as the target. Body matches
 *   instruction for instruction except two spots. (1) Prologue order: the target stores
 *   r1 (base) to [sp] before the 0x181C pool load and stores r3 before idx; ours
 *   loads the pool first. (2) At +0x13C the target does "str r1,[sp,#8]; ldr r1,[sp,#8];
 *   muls" (the u16 at work+0xA8 is a spilled value reloaded for 0x1249*n); ours multiplies
 *   r1 before the store, which shifts all later code by 2 bytes. Tried for (2): n as int
 *   (slot moves to 0xC), lim local vs loop-condition multiply, if+do-while guard,
 *   n*0x1249 vs 0x1249*n, no n at all (field re-read so the compiler CSEs the load;
 *   spill slot right but still no reload). Keys that closed big residues: the local
 *   constants h = 0x8000 and sh = 0xC0000 (the target computes h>>1, h>>3, h>>4, h<<1,
 *   sh>>9 at run time, so they are variables, not literals); sx = tp[0]*rx and
 *   sy = tp[1]*ry operand order; cur = old = f() store order; offy written with "* -8";
 *   case a < h>>1 passes h>>3 directly (not sc) so it is not tail-merged.
 * 2026-10-05 (wave D4 lane 01): DIFF, residue unchanged. Tried: `lim = (n = ...) * 0x1249`; `int idx = 0`
 *   at the declaration; an offset local o = 0x181C for the first access and for work + (o + 0x18) in the first
 *   0x1834 lines (no change: the pool load still schedules first); base as int or u32 (moves the base
 *   store, never to +0004). In the original, base, rx, idx and n are all stored at their definition and
 *   reloaded before use (spill everywhere); ours keeps the value in the register and the scheduler sinks the
 *   store. A fifth live value in the original (more register pressure) is the likely cause; not found.
 * 2026-10-05 (wave D5 lane 04): DIFF, residue unchanged (prologue store order and the n store/reload at
 *   +013C). Tried: n as a block-local u16 in the do body; `lim = (n = field) * 0x1249`; the multiply in the
 *   loop condition `while (t >= (lim = n * 0x1249))` and `while (t >= n * 0x1249) t -= n * 0x1249`; a
 *   static inline wrap(t, n) helper for the second loop; `idx = 0` after the first call (worse); volatile n
 *   as a probe (not a fix: changes the frame, still no reload). The listing has real back edges, so both
 *   while loops are real. The reload means the multiply reads n's home, not the ldrh temp: find what
 *   blocks copy propagation of `n = field` in the original.
 * 2026-10-05 (wave D6 lane 09): DIFF, residue unchanged. Finding: the same str/ldr pair appears in our
 *   build for cur at +0x198 (str r0,[sp,#0x10]; ldr r1,[sp,#0x10]) because cur has two definitions
 *   (cur = old and cur = table), so copy propagation does not replace it. The n reload at +0x13C thus
 *   says that n also has a second definition (or is otherwise not copy-propagated) in the original.
 *   Tried: `u16 n = 0` initialiser (no change), `lim = n; lim *= 0x1249` (no change), the second loop
 *   with the field re-read in the condition and body plus n kept for k (no change). Next: find where a
 *   second def of n can sit without a store in the listing (sp+8 is only written at +0x13C).
 * 2026-10-05 (wave D7 lane 04): DIFF, residue unchanged (533 bytes: prologue store order and the n
 *   reload at +013C). Tried: a second def of n in the prologue (`n = field; lim = 0x1249 * n;`, no change:
 *   n is still copy-propagated in the loop). Reading: in the original the three entry stores (base [sp],
 *   rx [sp,#4], idx [sp,#0x2c]) all stay above the first work+0x181C load, as if they were memory-variable
 *   stores that may alias it; ours sinks the rx store below the load. n at [sp,#8] behaves the same way
 *   (store then reload). So base, rx, idx and n look like memory-resident variables in the original,
 *   not allocator spills; the source cause is still not found.
 * 2026-10-05 (wD9 lane08): DIFF, residue unchanged. Tried: n as u32 (same as int: slots for n and ry
 *   swap, multiply still reads the ldrh temp). Note: ry is also copied to a stack home ([sp,#0xC]) at the
 *   loop guard, so base, rx, ry, idx and n all have stack homes; the prologue stores stay above the
 *   first work+0x181C load in the original only.
 * 2026-10-05 (wave D8 lane 02): DIFF, residue unchanged (533 bytes). Tried: n as int (536; the slots
 *   for n and ry swap, 8 and 0xC, and the multiply still reads the ldrh temp, no reload). The
 *   original pattern (store at the definition, reload at every use, entry stores above the first
 *   load) is spill-everywhere for base, rx, idx and n; no source shape found yet that blocks the
 *   copy propagation of n = field into the multiply.
 * 2026-10-05 (wD9r lane02): DIFF, residue unchanged (533 bytes). Tried: n defined inside the first loop
 *   (`while (t < 0) { n = field; t += n * 0x1249; }`, 646, worse); the 0x1249 factor as a local
 *   `unit = 0x1249` for `lim = n * unit` (533, no change); n read through a static inline getter (533,
 *   no change). Reading: the prologue and the loop wrap use the same shape (ldrh, pool K, copy, muls), and
 *   the image reloads n at the multiply, so the multiply reads n after a block boundary or n is not a
 *   single-def copy there; no source form found.
 * 2026-10-05 (wD9r lane20): DIFF, residue unchanged (533 bytes). New tries, each compiled: the whole body
 *   as a static inline called from a wrapper (544, slots move, prologue order unchanged); sx, sy, old,
 *   cur, spr, t, k, n and tp declared in the do-body block (533, no change). Probe: dsi/1.1 to 1.6sp2
 *   all give 533, so the residue is source, not compiler build. Reading: the same shape as ov116
 *   021D7D0C (store at the def, reload at the use, entry stores held above the first load) means the
 *   image keeps base, rx, idx and n as memory variables, not register-allocator spills; no source
 *   form found that does this without address-taking.
 * 2026-10-05 (wD9r lane42): DIFF, 533 -> 521 bytes. The prologue store order is fixed: the callers
 *   (021B7A70, 021B7CFC, 021B8930) declare (u8 *, u16, short, int, u16) and pass 72, 48 for rx, ry, so
 *   speed is short and rx is a narrow parameter like ry (u16; short gives the same code). A narrow rx pins
 *   its home store above the first work+0x181C load (docs/idioms/a-narrow-parameter-pins-its-home-store-
 *   to-the-front-of-the-prologue.md). The only residue left is the n store/reload at +013C (all later
 *   bytes are the 2-byte shift). Probe: a second reaching def of n before the k compare (`if (t == 5)
 *   n = 3;`, not a fix) gives the image's str/ldr/muls exactly, so in the image n has a second
 *   definition that reaches the multiply or the k compare. A def that does not reach (prologue
 *   `n = field; lim = 0x1249 * n;`, a dead `n = 0` at the loop end) changes nothing. Also tried, all 521:
 *   `while (t >= (n = field) * 0x1249) t -= n * 0x1249;`, `while (t >= (lim = (n = field) * 0x1249))`,
 *   `while (t >= (lim = n * 0x1249))`, `while (t >= n * 0x1249) t -= n * 0x1249;`, an explicit if guard
 *   plus do-while, n read through a struct field `((Hdr *)work)->n` (also in the first loop).
 *   More (all compiled): `lim = 0x1249; lim *= n;` after `n = field` (520: str moves above the muls,
 *   still no reload, muls r1,r2,r1); `lim = 0x1249` before `n = field` (525); a `for (;;)` with break
 *   (605); n as a 6th function parameter (probe only, 56 B: parameters are not copy-propagated, the
 *   reload appears at [sp,#0x6c]); reusing the speed parameter for n (612/888). Inline helpers for the
 *   tail (wrap loop, if, k, cur pick) with n as a helper parameter: with `u8 *cur = old;` inside the
 *   helper (668) the image's `str r1,[sp,#8]; ldr r1,[sp,#8]; muls` appears, but the helper adds a
 *   `ldr [sp,#0x14]; str [sp,#0x10]` copy for cur after the t loop (the image stores cur at the call,
 *   +010A); with cur passed by pointer (`u8 **pcur`, 521) or with two returns (663) n is propagated
 *   again. Reading: the image's n is a copy that mwcc does not propagate (a parameter-like variable),
 *   and something sits between `n = field` and the multiply in the IR without code of its own.
 * 2026-10-05 (wD9r lane86): DIFF, residue unchanged (521 bytes, only the n str/ldr at +013C). New
 *   tries, each compiled, all 521 unless noted: k and the second wrap in an inline helper called before
 *   the condition (the divide is not sunk into the if); `t = Wrap(t, n)` inline helper with an int
 *   return; the whole f(e)..pick segment as an inline helper returning cur (523, old/cur stores swap);
 *   `GetCount(work, &n)` inline out-parameter; `register u16 n`; block-local `const u16 n`; `int unit =
 *   0x1249` at the top used in one, two or all three places; the wrap on a copy `f = t`; n reused for the
 *   (u16)(0x6E00 - a) and (u16)(0x78E0 - a) temps; the frame index written into n (`if (k >= n) n = k -
 *   n; else n = k;`, both orders); `lim = field * 0x1249` with `n = field` after the wrap; the n def
 *   behind a goto label; `for (n = field; t >= n * 0x1249; )`; `int speed` reused for n (888).
 *   Findings: (1) n = field written in both arms of `if (t < 0) { while (t < 0) ...; n = field; } else n
 *   = field;` gets cross-jumped into one tail and gives the reload, but the inner while keeps a redundant
 *   `cmp r0,#0; bge` (635), and the reload sits in the join block (str before the pool load, the image
 *   has the pool load first); with a do-while in the arm (630) the arm's n is CSE'd with the loop's
 *   hoisted load. (2) An intervening statement that needs a register between `n = field` and the
 *   multiply (a memory store, a spilled-local copy) also gives the reload; a store of a callee-saved
 *   value (`cur = spr`), a register copy, or a constant assignment does not. (3) A reaching second def
 *   after the wrap (`if (t == 5) n = 3;`, probe) reproduces the image's exact order (pool load, str,
 *   ldr, muls), so the image's n most likely has a second reaching def or is parameter-like; no natural
 *   codeless form found.
 * 2026-10-05 (wD9r lane116): DIFF, residue unchanged (521 bytes, only the n str/ldr at +013C). Twin
 *   search: 0x1249 appears only in ov133 021B6100 (frame pick as `m = F * 0x1249; if (t >= m) x = (t - m)
 *   / 0x1249; else ...`, no n local) and 021B6F00 (init); no matched copy of this routine. New tries
 *   (F = the u16 at work+0xA8), each compiled: n as a one-field local struct (521, scalarised); `while (t <
 *   0) { n = F; t += n * 0x1249; } n = F;` (964/635: the +0134 block is now byte-exact, str/ldr/muls in the
 *   image order, but hoisting the loop assignment adds a re-test `cmp r0,#0; bge` after the preheader);
 *   the same with `(n = F)` in the loop expression and as a for loop (635); `if (t < 0) { n = F; do ...
 *   while }` and `if (t < 0) do { n = F; ... } while` (521); `if (t < 0) { n = F; while ... }` (635,
 *   re-test); `n = F` before the first loop (631, CSE); if/else arms with a for(;;)+break or do-while
 *   loop and `n = F` in both arms (630, 632: CSE with the hoisted load); n re-read (`n = F`) inside the
 *   condition block before or after k, or only there with `lim = F * 0x1249` (521, CSE'd away); no n and
 *   F read at the k compare (521); a later def that reads n (`n += k` or `n = k - n` with a use after,
 *   562/563, no reload); `else n = 3` after the k compare (no reload). Probes (not fixes): moving the
 *   loop-top `sc = 0` (store to the address-taken sc) between `n = F` and the multiply gives the image's
 *   str/ldr/muls (115 bytes left, all from the moved strh), so any memory store there blocks the load
 *   forwarding into the multiply; a def of n inside the condition block before k (`if (t == 5) n = 3;`)
 *   also gives it, a def after the k compare does not. Open: a codeless memory kill or a codeless
 *   second def between +0138 and +0184; none of the image's stores fits.
 */
/*
 * 2026-10-05 (user decision): the field re-read in the loop (for (n = F; t >= n * K; n = F)) is accepted as a real source quirk.
 * note (2026-10-04, wave D3 lane 08): DIFF, same length as the target. Body matches
 *   instruction for instruction except two spots. (1) Prologue order: the target stores
 *   r1 (base) to [sp] before the 0x181C pool load and stores r3 before idx; ours
 *   loads the pool first. (2) At +0x13C the target does "str r1,[sp,#8]; ldr r1,[sp,#8];
 *   muls" (the u16 at work+0xA8 is a spilled value reloaded for 0x1249*n); ours multiplies
 *   r1 before the store, which shifts all later code by 2 bytes. Tried for (2): n as int
 *   (slot moves to 0xC), lim local vs loop-condition multiply, if+do-while guard,
 *   n*0x1249 vs 0x1249*n, no n at all (field re-read so the compiler CSEs the load;
 *   spill slot right but still no reload). Keys that closed big residues: the local
 *   constants h = 0x8000 and sh = 0xC0000 (the target computes h>>1, h>>3, h>>4, h<<1,
 *   sh>>9 at run time, so they are variables, not literals); sx = tp[0]*rx and
 *   sy = tp[1]*ry operand order; cur = old = f() store order; offy written with "* -8";
 *   case a < h>>1 passes h>>3 directly (not sc) so it is not tail-merged.
 * 2026-10-05 (wave D4 lane 01): DIFF, residue unchanged. Tried: `lim = (n = ...) * 0x1249`; `int idx = 0`
 *   at the declaration; an offset local o = 0x181C for the first access and for work + (o + 0x18) in the first
 *   0x1834 lines (no change: the pool load still schedules first); base as int or u32 (moves the base
 *   store, never to +0004). In the original, base, rx, idx and n are all stored at their definition and
 *   reloaded before use (spill everywhere); ours keeps the value in the register and the scheduler sinks the
 *   store. A fifth live value in the original (more register pressure) is the likely cause; not found.
 * 2026-10-05 (wave D5 lane 04): DIFF, residue unchanged (prologue store order and the n store/reload at
 *   +013C). Tried: n as a block-local u16 in the do body; `lim = (n = field) * 0x1249`; the multiply in the
 *   loop condition `while (t >= (lim = n * 0x1249))` and `while (t >= n * 0x1249) t -= n * 0x1249`; a
 *   static inline wrap(t, n) helper for the second loop; `idx = 0` after the first call (worse); volatile n
 *   as a probe (not a fix: changes the frame, still no reload). The listing has real back edges, so both
 *   while loops are real. The reload means the multiply reads n's home, not the ldrh temp: find what
 *   blocks copy propagation of `n = field` in the original.
 * 2026-10-05 (wave D6 lane 09): DIFF, residue unchanged. Finding: the same str/ldr pair appears in our
 *   build for cur at +0x198 (str r0,[sp,#0x10]; ldr r1,[sp,#0x10]) because cur has two definitions
 *   (cur = old and cur = table), so copy propagation does not replace it. The n reload at +0x13C thus
 *   says that n also has a second definition (or is otherwise not copy-propagated) in the original.
 *   Tried: `u16 n = 0` initialiser (no change), `lim = n; lim *= 0x1249` (no change), the second loop
 *   with the field re-read in the condition and body plus n kept for k (no change). Next: find where a
 *   second def of n can sit without a store in the listing (sp+8 is only written at +0x13C).
 * 2026-10-05 (wave D7 lane 04): DIFF, residue unchanged (533 bytes: prologue store order and the n
 *   reload at +013C). Tried: a second def of n in the prologue (`n = field; lim = 0x1249 * n;`, no change:
 *   n is still copy-propagated in the loop). Reading: in the original the three entry stores (base [sp],
 *   rx [sp,#4], idx [sp,#0x2c]) all stay above the first work+0x181C load, as if they were memory-variable
 *   stores that may alias it; ours sinks the rx store below the load. n at [sp,#8] behaves the same way
 *   (store then reload). So base, rx, idx and n look like memory-resident variables in the original,
 *   not allocator spills; the source cause is still not found.
 * 2026-10-05 (wD9 lane08): DIFF, residue unchanged. Tried: n as u32 (same as int: slots for n and ry
 *   swap, multiply still reads the ldrh temp). Note: ry is also copied to a stack home ([sp,#0xC]) at the
 *   loop guard, so base, rx, ry, idx and n all have stack homes; the prologue stores stay above the
 *   first work+0x181C load in the original only.
 * 2026-10-05 (wave D8 lane 02): DIFF, residue unchanged (533 bytes). Tried: n as int (536; the slots
 *   for n and ry swap, 8 and 0xC, and the multiply still reads the ldrh temp, no reload). The
 *   original pattern (store at the definition, reload at every use, entry stores above the first
 *   load) is spill-everywhere for base, rx, idx and n; no source shape found yet that blocks the
 *   copy propagation of n = field into the multiply.
 * 2026-10-05 (wD9r lane02): DIFF, residue unchanged (533 bytes). Tried: n defined inside the first loop
 *   (`while (t < 0) { n = field; t += n * 0x1249; }`, 646, worse); the 0x1249 factor as a local
 *   `unit = 0x1249` for `lim = n * unit` (533, no change); n read through a static inline getter (533,
 *   no change). Reading: the prologue and the loop wrap use the same shape (ldrh, pool K, copy, muls), and
 *   the image reloads n at the multiply, so the multiply reads n after a block boundary or n is not a
 *   single-def copy there; no source form found.
 * 2026-10-05 (wD9r lane20): DIFF, residue unchanged (533 bytes). New tries, each compiled: the whole body
 *   as a static inline called from a wrapper (544, slots move, prologue order unchanged); sx, sy, old,
 *   cur, spr, t, k, n and tp declared in the do-body block (533, no change). Probe: dsi/1.1 to 1.6sp2
 *   all give 533, so the residue is source, not compiler build. Reading: the same shape as ov116
 *   021D7D0C (store at the def, reload at the use, entry stores held above the first load) means the
 *   image keeps base, rx, idx and n as memory variables, not register-allocator spills; no source
 *   form found that does this without address-taking.
 * 2026-10-05 (wD9r lane42): DIFF, 533 -> 521 bytes. The prologue store order is fixed: the callers
 *   (021B7A70, 021B7CFC, 021B8930) declare (u8 *, u16, s16, int, u16) and pass 72, 48 for rx, ry, so
 *   speed is s16 and rx is a narrow parameter like ry (u16; s16 gives the same code). A narrow rx pins
 *   its home store above the first work+0x181C load (docs/idioms/a-narrow-parameter-pins-its-home-store-
 *   to-the-front-of-the-prologue.md). The only residue left is the n store/reload at +013C (all later
 *   bytes are the 2-byte shift). Probe: a second reaching def of n before the k compare (`if (t == 5)
 *   n = 3;`, not a fix) gives the image's str/ldr/muls exactly, so in the image n has a second
 *   definition that reaches the multiply or the k compare. A def that does not reach (prologue
 *   `n = field; lim = 0x1249 * n;`, a dead `n = 0` at the loop end) changes nothing. Also tried, all 521:
 *   `while (t >= (n = field) * 0x1249) t -= n * 0x1249;`, `while (t >= (lim = (n = field) * 0x1249))`,
 *   `while (t >= (lim = n * 0x1249))`, `while (t >= n * 0x1249) t -= n * 0x1249;`, an explicit if guard
 *   plus do-while, n read through a struct field `((Hdr *)work)->n` (also in the first loop).
 *   More (all compiled): `lim = 0x1249; lim *= n;` after `n = field` (520: str moves above the muls,
 *   still no reload, muls r1,r2,r1); `lim = 0x1249` before `n = field` (525); a `for (;;)` with break
 *   (605); n as a 6th function parameter (probe only, 56 B: parameters are not copy-propagated, the
 *   reload appears at [sp,#0x6c]); reusing the speed parameter for n (612/888). Inline helpers for the
 *   tail (wrap loop, if, k, cur pick) with n as a helper parameter: with `u8 *cur = old;` inside the
 *   helper (668) the image's `str r1,[sp,#8]; ldr r1,[sp,#8]; muls` appears, but the helper adds a
 *   `ldr [sp,#0x14]; str [sp,#0x10]` copy for cur after the t loop (the image stores cur at the call,
 *   +010A); with cur passed by pointer (`u8 **pcur`, 521) or with two returns (663) n is propagated
 *   again. Reading: the image's n is a copy that mwcc does not propagate (a parameter-like variable),
 *   and something sits between `n = field` and the multiply in the IR without code of its own.
 * 2026-10-05 (wD9r lane86): DIFF, residue unchanged (521 bytes, only the n str/ldr at +013C). New
 *   tries, each compiled, all 521 unless noted: k and the second wrap in an inline helper called before
 *   the condition (the divide is not sunk into the if); `t = Wrap(t, n)` inline helper with an int
 *   return; the whole f(e)..pick segment as an inline helper returning cur (523, old/cur stores swap);
 *   `GetCount(work, &n)` inline out-parameter; `register u16 n`; block-local `const u16 n`; `int unit =
 *   0x1249` at the top used in one, two or all three places; the wrap on a copy `f = t`; n reused for the
 *   (u16)(0x6E00 - a) and (u16)(0x78E0 - a) temps; the frame index written into n (`if (k >= n) n = k -
 *   n; else n = k;`, both orders); `lim = field * 0x1249` with `n = field` after the wrap; the n def
 *   behind a goto label; `for (n = field; t >= n * 0x1249; )`; `int speed` reused for n (888).
 *   Findings: (1) n = field written in both arms of `if (t < 0) { while (t < 0) ...; n = field; } else n
 *   = field;` gets cross-jumped into one tail and gives the reload, but the inner while keeps a redundant
 *   `cmp r0,#0; bge` (635), and the reload sits in the join block (str before the pool load, the image
 *   has the pool load first); with a do-while in the arm (630) the arm's n is CSE'd with the loop's
 *   hoisted load. (2) An intervening statement that needs a register between `n = field` and the
 *   multiply (a memory store, a spilled-local copy) also gives the reload; a store of a callee-saved
 *   value (`cur = spr`), a register copy, or a constant assignment does not. (3) A reaching second def
 *   after the wrap (`if (t == 5) n = 3;`, probe) reproduces the image's exact order (pool load, str,
 *   ldr, muls), so the image's n most likely has a second reaching def or is parameter-like; no natural
 *   codeless form found.
 * 2026-10-05 (wD9r lane116): DIFF, residue unchanged (521 bytes, only the n str/ldr at +013C). Twin
 *   search: 0x1249 appears only in ov133 021B6100 (frame pick as `m = F * 0x1249; if (t >= m) x = (t - m)
 *   / 0x1249; else ...`, no n local) and 021B6F00 (init); no matched copy of this routine. New tries
 *   (F = the u16 at work+0xA8), each compiled: n as a one-field local struct (521, scalarised); `while (t <
 *   0) { n = F; t += n * 0x1249; } n = F;` (964/635: the +0134 block is now byte-exact, str/ldr/muls in the
 *   image order, but hoisting the loop assignment adds a re-test `cmp r0,#0; bge` after the preheader);
 *   the same with `(n = F)` in the loop expression and as a for loop (635); `if (t < 0) { n = F; do ...
 *   while }` and `if (t < 0) do { n = F; ... } while` (521); `if (t < 0) { n = F; while ... }` (635,
 *   re-test); `n = F` before the first loop (631, CSE); if/else arms with a for(;;)+break or do-while
 *   loop and `n = F` in both arms (630, 632: CSE with the hoisted load); n re-read (`n = F`) inside the
 *   condition block before or after k, or only there with `lim = F * 0x1249` (521, CSE'd away); no n and
 *   F read at the k compare (521); a later def that reads n (`n += k` or `n = k - n` with a use after,
 *   562/563, no reload); `else n = 3` after the k compare (no reload). Probes (not fixes): moving the
 *   loop-top `sc = 0` (store to the address-taken sc) between `n = F` and the multiply gives the image's
 *   str/ldr/muls (115 bytes left, all from the moved strh), so any memory store there blocks the load
 *   forwarding into the multiply; a def of n inside the condition block before k (`if (t == 5) n = 3;`)
 *   also gives it, a def after the k compare does not. Open: a codeless memory kill or a codeless
 *   second def between +0138 and +0184; none of the image's stores fits.
 */
void *DUP_FITTING_SetModelTransform(struct DupFittingWork *work, u16 base, short speed, u16 rx, u16 ry)
{
    DupFittingVec v;
    DupFittingVec w;
    DupFittingPair pos;
    short sc;
    int idx;
    u16 rot;
    int offx;
    int offy;
    int sx;
    int sy;
    u8 *old;
    u8 *cur;
    u16 a;
    u8 *e;
    u8 *spr;
    int t;
    u16 k;
    int lim;
    u16 n;
    const short *tp;
    u32 h = 0x8000;
    int sh = 0xC0000;

    idx = 0;
    e = DUP_FITTING_ITEM_ListGetHead((char *)(work->itemList));
    work->startAngle += speed;
    if (work->startAngle < 0)
        work->startAngle += work->frameCount * 0x1249;
    lim = 0x1249 * work->frameCount;
    if (work->startAngle >= lim)
        work->startAngle -= lim;
    rot = work->spin;
    offx = (FX_SinCosTable_[0] - FX_SinCosTable_[(rot >> 4) * 2]) << 3;
    offy = FX_SinCosTable_[1] - 0x8008 - FX_SinCosTable_[(rot >> 4) * 2 + 1] * -8;
    if (speed > 0x9C4 || speed < -0x9C4) {
        if (work->cooldown == 0) {
            work->cooldown = 30;
            GFL_USE_PlaySeDefaultVolume(0x624);
        }
    }
    if (e == 0)
        goto end;
    do {
        a = (u16)((base + (idx << 16) / 14) % 0x10000);
        sc = 0;
        spr = (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(e);
        tp = &FX_SinCosTable_[(a >> 4) * 2];
        sx = tp[0] * rx + 0x80000;
        sy = tp[1] * ry + 0x50000;
        cur = old = (u8 *)DUP_FITTING_ITEM_ElemGetData(e);
        t = work->startAngle + (a + 0x8000) % 0x10000;
        while (t < 0)
            t += work->frameCount * 0x1249;
        for (n = work->frameCount; t >= n * 0x1249; n = work->frameCount)
            t -= n * 0x1249;
        if (work->subMode == 0 || work->subTurned > (u32)((0x18000 - a) % 0x10000)) {
            k = (u16)((t + 0x924) / 0x1249);
            if (k >= n)
                k = (u16)(k - n);
            cur = (u8 *)(work->frameOrder[k]);
            DUP_FITTING_ITEM_ElemSetSprite(e, cur);
            if (*(u16 *)old != *(u16 *)cur && e == work->heldElem)
                work->heldElem = 0;
        }
        if (a >= h)
            a = (u16)((h << 1) - a);
        pos.x = (int)((float)sx / 4096.0f);
        pos.y = (int)((float)sy / 4096.0f);
        v.x = sx + offx;
        v.y = sy + offy;
        v.z = (h - a) + 0x14000;
        MUSICAL_MCSS_SetElemPos(work->elemSet, (struct McssActorElem *)spr, (int *)(&v));
        MUSICAL_MCSS_SetElemField(work->elemSet, spr, rot);
        DUP_FITTING_ITEM_ElemSetPos(e, (const u8 *)(&pos));
        if (a < (h >> 1)) {
            sc = h >> 3;
            MUSICAL_MCSS_SetElemRotZ(work->elemSet, spr, h >> 3, h >> 3);
            MUSICAL_MCSS_SetElemVisible(work->elemSet, (u8 *)(spr), 1);
            DUP_FITTING_ITEM_ElemSetScale(e, h >> 3);
        } else if (a < 0x6E00) {
            sc = ((u16)(0x6E00 - a) << 11) / 0x2E00 + (h >> 4);
            MUSICAL_MCSS_SetElemRotZ(work->elemSet, spr, sc, sc);
            MUSICAL_MCSS_SetElemVisible(work->elemSet, (u8 *)(spr), 1);
            DUP_FITTING_ITEM_ElemSetScale(e, sc);
        } else if (a < 0x78E0) {
            sc = ((u16)(0x78E0 - a) << 11) / 0xAE0;
            MUSICAL_MCSS_SetElemRotZ(work->elemSet, spr, sc, sc);
            MUSICAL_MCSS_SetElemVisible(work->elemSet, (u8 *)(spr), 1);
            DUP_FITTING_ITEM_ElemSetScale(e, sc);
        } else {
            MUSICAL_MCSS_SetElemVisible(work->elemSet, (u8 *)(spr), 0);
            DUP_FITTING_ITEM_ElemSetScale(e, 0);
            sc = 0;
        }
        if (*(int *)(cur + 0x10) == 1 && GetTimer(work) < 45) {
            w.x = v.x / 16;
            w.y = (sh - (v.y + 0x8000)) / 16;
            w.z = v.z + (sh >> 9);
            BILLBOARD_SetElemPos((struct BbBoard *)(work->billboard), work->bmpHandles[idx], (VecFx32 *)((struct Trip *)(&w)));
            BILLBOARD_SetElemScale(work->billboard, work->bmpHandles[idx], &sc, &sc);
            BILLBOARD_SetElemVisible(work->billboard, work->bmpHandles[idx], (u32 *)d_021BA3E8);
        } else {
            BILLBOARD_SetElemVisible(work->billboard, work->bmpHandles[idx], (u32 *)d_021BA3E4);
        }
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
        idx++;
    } while (e != 0);
end:
    return DUP_FITTING_ITEM_ListGetHead((char *)(work->itemList));
}

void DUP_FITTING_FreeHeldElem(struct DupFittingWork *work)
{
    u8 *e = DUP_FITTING_ITEM_ListGetHead(work->itemList);
    u8 *q;
    u8 *s;
    while (e) {
        q = (u8 *)DUP_FITTING_ITEM_ElemGetData(e);
        s = (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(e);
        if (((struct DupFittingItemData *)q)->worn == 1)
            MUSICAL_MCSS_FreeElemImage(work->elemSet, s, ((struct DupFittingItemData *)q)->id, ((struct DupFittingItemData *)q)->wornImageId);
        else
            MUSICAL_MCSS_FreeElemImage(work->elemSet, s, ((struct DupFittingItemData *)q)->id, ((struct DupFittingItemData *)q)->imageId);
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
}

void DUP_FITTING_UpdateCursor(struct DupFittingWork *work)
{
    int moved=0,other=0,hit=0,outer,n,dx,dy;
    if(work->firstTouch==0){work->touchTrg=TOUCHPANEL_GetTrg();work->touchCont=TOUCHPANEL_GetPointCont((u32 *)&work->cursorX,(u32 *)&work->cursorY);}
    if(work->touchTrg!=0 || work->touchCont!=0){
        if(work->cursorY>176)work->cursorY=176;
        if(work->cursorY<16)work->cursorY=16;
        if(work->holdState==2 && work->heldElem)DUP_FITTING_AttachElem(work,1);
        else if(work->touchTrg==1){
            hit=DUP_FITTING_PickElem(work,work->listB,3);
            if(hit==1){DUP_FITTING_ITEM_RemoveElem(work->listB,work->heldElem);DUP_FITTING_ITEM_InsertElem(work->listA,work->heldElem);DUP_FITTING_AttachElem(work,0);}
            else other=DUP_FITTING_SelectFrame(work);
        }
        if(hit==0 && other==0 && ((work->heldElem==0 && work->touchTrg==1)||work->holdState==1)){
            dy=(short)(work->cursorY-80);dx=(short)(work->cursorX-128);
            hit=DUP_FITTING_HitCircle(dx,dy,28,0.5384615659713745f);
            outer=DUP_FITTING_HitCircle(dx,dy,68,0.739130437374115f);
            if(hit==0 && outer==1){moved=1;DUP_FITTING_RotateToCursor(work,dx,dy);}
            else if((hit==0 && outer==0)||(hit==1 && outer==1)){
                if(DUP_FITTING_ITEM_ListIsFull(work->listA)==0 && work->holdState==1 && work->heldElem){
                    n=work->rotationVel;if(n<0)n=-n;
                    if(n<364)DUP_FITTING_CreateFitElem(work);
                }
            }
            if(moved==0 && work->touchTrg==1)DUP_FITTING_PickElem(work,work->listA,2);
        }
        if(work->touchTrg!=0 && work->heldElem==0 && work->cursorY>160 && *(u32 *)&work->cursorX>96 && *(u32 *)&work->cursorX<160){
            work->state=2;work->progress=0;GFL_USE_PlaySeDefaultVolume(0x622);DUP_FITTING_ResetActorPose(work);
        }
    }else {
        dy=(short)(work->prevY-80);dx=(short)(work->prevX-128);
        hit=DUP_FITTING_HitCircle(dx,dy,28,0.5384615659713745f);outer=DUP_FITTING_HitCircle(dx,dy,68,0.739130437374115f);
        if(work->holdState==2 && work->heldElem){
            if(work->frameIndex!=10)DUP_FITTING_MoveElem(work);
            else if(hit==0 && outer==1)DUP_FITTING_ReturnElem(work,0);
            else if(hit==1)DUP_FITTING_UpdateHeldElem(work);
            else DUP_FITTING_ReleaseElem(work);
        }
        work->dragActive=0;work->heldElem=0;work->holdState=0;work->holdKind=0;work->frameIndex=10;
    }
    if(work->rotationVel!=0 && moved==0){
        n=work->rotation+0x10000-work->rotationVel;if(n<0)n+=0x10000;if(n>=0x10000)n-=0x10000;
        work->rotation=n;DUP_FITTING_SetModelTransform(work,work->rotation,work->rotationVel,72,48);
        if(work->rotationVel>128 || work->rotationVel<-128)work->rotationVel*=0.75f;
        else work->rotationVel=0;
    }
    work->prevX=work->cursorX;work->prevY=work->cursorY;
}

void DUP_FITTING_RotateToCursor(struct DupFittingWork *work, int unused_x, int unused_y)
{
    int y0,y1,angle,hit,n;
    u8 *e,*data;
    y0=(work->prevY*72)/48;
    y1=(work->cursorY*72)/48;
    angle=GF_STANDARD_CalcAngle(work->prevX,y0,work->cursorX,y1,128,80,72);
    work->turnAccum+=(u16)(angle<0?-angle:angle);
    if(work->touchTrg==1 || work->turnAccum>=0x71c){
        e=DUP_FITTING_ITEM_ListGetHead(work->itemList);hit=0;
        if(work->touchTrg==1)*(u16 *)&work->rotationVel=0;
        work->turnAccum=0;work->heldElem=0;
        while(e){
            data=(u8 *)DUP_FITTING_ITEM_ElemGetData(e);
            if(DUP_FITTING_ITEM_ElemHitTest(e,work->cursorX,work->cursorY)==1){
                hit=1;
                if(((struct DupFittingItemData *)data)->worn==0){work->heldElem=e;work->holdState=1;e=0;}
            }
            if(work->heldElem==0)e=(u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
        }
        if(work->touchTrg==1 && hit==1 && work->heldElem==0){work->holdState=1;GFL_USE_PlaySeDefaultVolume(0x557);}
    }
    if(work->dragActive==1){
        if((angle<0?-angle:angle)>227 && (angle<0?-angle:angle)<0x4000){
            n=work->rotation+0x10000-angle;
            if(n<0)n+=0x10000;
            if(n>=0x10000)n-=0x10000;
            work->rotation=n;
            DUP_FITTING_SetModelTransform(work,work->rotation,(short)angle,72,48);
            if(angle>=0 && work->rotationVel>0 && angle<work->rotationVel)
                work->rotationVel=(work->rotationVel+angle)/2;
            else if(angle<=0 && work->rotationVel<0 && angle>work->rotationVel)
                work->rotationVel=(work->rotationVel+angle)/2;
            else work->rotationVel=angle;
            n=work->rotationVel;
            if((n>0 && work->spin>0)||(n<0 && work->spin<0))work->spin=0;
            else if(n>0 && work->spin>-0x3000){
                if(n*15>work->spin*-10)work->spin-=256;
            } else if(n<0 && work->spin<0x3000){
                if(n*-15>work->spin*10)work->spin+=256;
            }
        }else work->rotationVel=0;
    }
    work->dragActive=1;
}

int DUP_FITTING_PickElem(struct DupFittingWork *work, void *list, u32 kind)
{
    u8 *e = DUP_FITTING_ITEM_ListGetHead(list);
    u32 *v;
    while (e) {
        if (DUP_FITTING_ITEM_ElemHitTest(e, work->cursorX, work->cursorY) == 1) {
            v = (u32 *)DUP_FITTING_ITEM_ElemGetPos(e);
            work->holdState = 2;
            work->heldElem = e;
            GFL_USE_PlaySeDefaultVolume(0x623);
            work->holdKind = kind;
            work->holdDx = v[0];
            work->holdDy = v[1];
            return 1;
        }
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
    return 0;
}

void DUP_FITTING_AttachElem(struct DupFittingWork *work,int sound)
{
    DupFittingVec v;
    DupFittingPair pos,relative;
    DupFittingScaleLimit scale;
    int old,index;
    u8 *sprite,*q;
    u16 rotation=0;
    scale.limit=12;v=d_021BA5A0;
    old=work->frameIndex;sprite=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);
    relative.x=work->cursorX-128;relative.y=work->cursorY-112;
    index=DUP_FITTING_FindNearestFrame(work,sprite,(const int *)&relative,&scale.limit);work->frameIndex=index;
    if(index!=10){
        q=(u8 *)MUSICAL_MCSS_GetRenderElem(work->renderParam,index);
        pos.x=(int)((float)(((struct DupFittingRenderElem *)q)->x+((struct DupFittingRenderElem *)q)->offsetX)/4096.f)+128;
        pos.y=(int)((float)(((struct DupFittingRenderElem *)q)->y+((struct DupFittingRenderElem *)q)->offsetY)/4096.f)+96;
        rotation=((struct DupFittingRenderElem *)q)->baseRotation;MUSICAL_MCSS_SetElemFlag((u8 *)(work->elemSet), (struct McssActorElem *)(sprite), 1);
        if(MUSICAL_MCSS_ElemHasAltDepth(sprite)==1)v.z=0x1a000;
        if(DUP_FITTING_IsFrameOwned(work,work->frameIndex)==0){work->holdKind=3;work->holdDx=pos.x;work->holdDy=pos.y;}
        DUP_FITTING_ITEM_ElemSetFrameIndex((char *)(work->heldElem),work->frameIndex);
        if(old!=work->frameIndex && sound==1)GFL_USE_PlaySeDefaultVolume(0x627);
    }else{
        work->frameIndex=10;pos.x=work->cursorX;pos.y=work->cursorY;
        MUSICAL_MCSS_SetElemFlag((u8 *)(work->elemSet), (struct McssActorElem *)(sprite), rotation);
    }
    if(pos.x>0)v.x=(int)(0.5f+(float)(int)((u32)pos.x<<12));else v.x=(int)((float)(int)((u32)pos.x<<12)-0.5f);
    if(pos.y>0)v.y=(int)(0.5f+(float)(int)((u32)pos.y<<12));else v.y=(int)((float)(int)((u32)pos.y<<12)-0.5f);
    MUSICAL_MCSS_SetElemPos(work->elemSet,(struct McssActorElem *)sprite,(int *)(&v));
    DUP_FITTING_ITEM_ElemSetPos(work->heldElem,(const u8 *)(&pos));
    q=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);MUSICAL_MCSS_SetElemField(work->elemSet,q,rotation);
    MUSICAL_MCSS_SetElemRot(work->elemSet,sprite,&scale.x,&scale.y);
    if(scale.x<4096 || scale.y<4096){
        scale.x+=410;scale.y+=410;
        if(scale.x>4096)scale.x=4096;if(scale.y>4096)scale.y=4096;
        MUSICAL_MCSS_SetElemRotZ(work->elemSet,sprite,scale.x,scale.y);
    }
}

void DUP_FITTING_CreateFitElem(struct DupFittingWork *work)
{
    DupFittingVec scale=d_021BA5B8;
    DupFittingPairU32 pos;
    DupFittingScaleXY old;
    u8 *q,*data,*s,*t;
    u32 *v;
    data=(u8 *)DUP_FITTING_ITEM_ElemGetData(work->heldElem);
    pos.x=work->cursorX;pos.y=work->cursorY;
    if(pos.x!=0) scale.x=(int)(0.5f+(float)(pos.x<<12));
    else scale.x=(int)((float)(pos.x<<12)-0.5f);
    if(work->cursorY!=0) scale.y=(int)(0.5f+(float)(work->cursorY<<12));
    else scale.y=(int)((float)(work->cursorY<<12)-0.5f);
    q=DUP_FITTING_ITEM_CreateElem(work->heapId,work->elemSet,data,(int *)(&scale));
    DUP_FITTING_ITEM_InsertElem(work->listA,q);
    DUP_FITTING_ITEM_ElemSetPos(q,(const u8 *)(&pos));
    s=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);t=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(q);
    MUSICAL_MCSS_SetElemRot((void *)(work->elemSet),s,&old.x,&old.y);
    MUSICAL_MCSS_SetElemRotZ((void *)(work->elemSet),t,old.x,old.y);
    MUSICAL_MCSS_SetElemFlag((u8 *)(work->elemSet),(struct McssActorElem *)t,0);
    v=(u32 *)DUP_FITTING_ITEM_ElemGetPos(work->heldElem);
    work->holdKind=1;
    work->holdDx=v[0];work->holdDy=v[1];
    work->holdState=2;work->heldElem=q;work->holdKind=1;
    ((struct DupFittingItemData *)data)->worn=1;
    DUP_FITTING_FreeHeldElem(work);GFL_USE_PlaySeDefaultVolume(0x625);
}

void DUP_FITTING_ReleaseElem(struct DupFittingWork *work)
{
    DupFittingVec v;
    u8 *e, *s;
    int z = 0xa000;
    s = (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);
    DUP_FITTING_ITEM_RemoveElem(work->listA, work->heldElem);
    DUP_FITTING_ITEM_InsertElemTail(work->listA, work->heldElem);
    MUSICAL_MCSS_SetElemRotZ((void *)(work->elemSet), s, 4096, 4096);
    e = DUP_FITTING_ITEM_ListGetHead(work->listA);
    while (e) {
        s = (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(e);
        MUSICAL_MCSS_SetElemScale((sptr)work->elemSet, (struct McssActorElem *)s, (&v));
        v.z = z;
        MUSICAL_MCSS_SetElemPos(work->elemSet, (struct McssActorElem *)s, (int *)&v);
        z -= 1024;
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
}

/*
 * lever: Named halfword call-result local fixes comparison load order.
 */
void DUP_FITTING_ReturnElem(struct DupFittingWork *work, int unused)
{
    DupFittingVec v;
    DupFittingPair pos;
    DupFittingPair fallback;
    u8 *sprite, *data, *entry, *found;
    u16 key;
    DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);
    sprite = (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);
    data = (u8 *)DUP_FITTING_ITEM_ElemGetData(work->heldElem);
    DUP_FITTING_ITEM_RemoveElem(work->listA, work->heldElem);
    DUP_FITTING_ITEM_InsertElemTail(work->listC, work->heldElem);
    v = d_021BA588;
    pos.x = work->cursorX;
    pos.y = work->cursorY;
    if (work->holdDx > 0) v.x = (int)(0.5f + (float)(work->holdDx << 12));
    else v.x = (int)((float)(work->holdDx << 12) - 0.5f);
    if (work->holdDy > 0) v.y = (int)(0.5f + (float)(work->holdDy << 12));
    else v.y = (int)((float)(work->holdDy << 12) - 0.5f);
    DUP_FITTING_ITEM_ElemSetBasePos(work->heldElem, (const u8 *)(&pos));
    MUSICAL_MCSS_SetElemPos((void *)(work->elemSet), (struct McssActorElem *)sprite, (int *)&v);
    MUSICAL_MCSS_SetElemRotZ((void *)(work->elemSet), sprite, 4096, 4096);
    DUP_FITTING_ITEM_ElemSetScale(work->heldElem, 4096);
    found = 0;
    entry = DUP_FITTING_ITEM_ListGetHead(work->itemList);
    while (entry && !found) {
        key = *(u16 *)DUP_FITTING_ITEM_ElemGetData(entry);
        if (key == ((struct DupFittingItemData *)data)->id) found = entry;
        entry = (u8 *)DUP_FITTING_ITEM_ElemGetNext(entry);
    }
    if (found) {
        DUP_FITTING_ITEM_ElemSetPos(work->heldElem, (const u8 *)DUP_FITTING_ITEM_ElemGetPos(found));
        DUP_FITTING_ITEM_ElemSetStartScale(work->heldElem, DUP_FITTING_ITEM_ElemGetScale((char *)found));
    } else {
        fallback = d_021BA568;
        DUP_FITTING_ITEM_ElemSetPos(work->heldElem, (const u8 *)(&fallback));
        DUP_FITTING_ITEM_ElemSetStartScale(work->heldElem, 0);
    }
    DUP_FITTING_ITEM_ElemSetAnimFrames((char *)(work->heldElem), 10);
    ((struct DupFittingItemData *)data)->worn = 0;
    DUP_FITTING_FreeHeldElem(work);
    GFL_USE_PlaySeDefaultVolume(1574);
}

/*
 * ABI: MUSICAL_MCSS_ElemHasAltDepth declared int here: its forwarded MUSICAL_MCSS_GetStateA returns 0/1; original compares the returned r0 despite legacy void declarations.
 */
void DUP_FITTING_MoveElem(struct DupFittingWork *work)
{
    DupFittingVec v, first, second;
    DupFittingPair pos, offset;
    u8 *sprite,*entry,*s;
    DupFittingPair *old;
    int state,depth;
    DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);
    sprite=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);
    if(DUP_FITTING_IsFrameOwned(work,work->frameIndex)==1) {
        state=MUSICAL_MCSS_GetIndex(work->frameIndex);
        entry=DUP_FITTING_ITEM_ListGetHead(work->listB);
        while(entry) {
            if(state==MUSICAL_MCSS_GetIndex(DUP_FITTING_ITEM_ElemGetFrameIndex((char *)entry))) break;
            entry=(u8 *)DUP_FITTING_ITEM_ElemGetNext(entry);
        }
        if(entry) {
            v=d_021BA570;
            s=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(entry);
            MUSICAL_MCSS_GetElemOffset(s,(struct McssOffset *)(&offset));
            DUP_FITTING_RandomPos(work,(int *)&pos);
            pos.x+=offset.x;
            pos.y+=offset.y;
            DUP_FITTING_ITEM_RemoveElem(work->listB,entry);
            DUP_FITTING_ITEM_InsertElemTail(work->listA,entry);
            old=(DupFittingPair *)DUP_FITTING_ITEM_ElemGetPos(entry);
            if(pos.x>0) v.x=(int)(0.5f+(float)(pos.x<<12));
            else v.x=(int)((float)(pos.x<<12)-0.5f);
            if(pos.y>0) v.y=(int)(0.5f+(float)(pos.y<<12));
            else v.y=(int)((float)(pos.y<<12)-0.5f);
            DUP_FITTING_ITEM_ElemSetBasePos(entry,(const u8 *)old);
            MUSICAL_MCSS_SetElemPos((void *)(work->elemSet), (struct McssActorElem *)s, (int *)&v);
            MUSICAL_MCSS_SetElemField((void *)(work->elemSet),s,0);
            DUP_FITTING_ITEM_ElemSetPos(entry,(const u8 *)(&pos));
            DUP_FITTING_ITEM_ElemSetAnimFrames((char *)entry,10);
            depth=0;
            entry=DUP_FITTING_ITEM_ListGetHead(work->listA);
            while(entry) {
                s=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(entry);
                MUSICAL_MCSS_SetElemScale((*(int *)&work->elemSet),(struct McssActorElem *)s,(&first));
                first.z=depth;
                MUSICAL_MCSS_SetElemPos(work->elemSet, (struct McssActorElem *)s, (int *)&first);
                depth-=1024;
                entry=(u8 *)DUP_FITTING_ITEM_ElemGetNext(entry);
            }
        }
    }
    DUP_FITTING_ITEM_RemoveElem(work->listA,work->heldElem);
    DUP_FITTING_ITEM_InsertElemTail(work->listB,work->heldElem);
    MUSICAL_MCSS_SetElemRotZ((void *)(work->elemSet),sprite,4096,4096);
    DUP_FITTING_ITEM_ElemSetFrameIndex((char *)(work->heldElem),work->frameIndex);
    entry=DUP_FITTING_ITEM_ListGetHead(work->listB);
    depth=0;
    while(entry) {
        s=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(entry);
        MUSICAL_MCSS_SetElemScale((sptr)work->elemSet,(struct McssActorElem *)s,(&second));
        if(MUSICAL_MCSS_ElemHasAltDepth(s)==1) second.z=depth+(102<<10);
        else if(DUP_FITTING_ITEM_ElemGetFrameIndex((char *)entry)==7 || DUP_FITTING_ITEM_ElemGetFrameIndex((char *)entry)==8) second.z=depth+(222<<10);
        else second.z=depth+(202<<10);
        MUSICAL_MCSS_SetElemPos(work->elemSet, (struct McssActorElem *)s, (int *)&second);
        depth-=1024;
        entry=(u8 *)DUP_FITTING_ITEM_ElemGetNext(entry);
    }
}

/*
 * lever: Unsigned word state local restores the state/sprite register pair; int and long left DIFF7.
 * ABI: MUSICAL_MCSS_ElemHasAltDepth declared int here: its forwarded MUSICAL_MCSS_GetStateA returns 0/1; original compares the returned r0 despite legacy void declarations.
 */
void DUP_FITTING_UpdateHeldElem(struct DupFittingWork *work)
{
    DupFittingVec a,b,c;
    DupFittingPair posA,currentB,posB,posC;
    unsigned int state;
    u8 *sprite,*record;
    u16 flag;
    if(work->holdKind==2) {
        a=d_021BA57C;
        sprite=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);
        posA.x=work->cursorX; posA.y=work->cursorY;
        if(work->holdDx>0) a.x=(int)(0.5f+(float)(work->holdDx<<12));
        else a.x=(int)((float)(work->holdDx<<12)-0.5f);
        if(work->holdDy>0) a.y=(int)(0.5f+(float)(work->holdDy<<12));
        else a.y=(int)((float)(work->holdDy<<12)-0.5f);
        DUP_FITTING_ITEM_ElemSetBasePos(work->heldElem,(const u8 *)(&posA));
        MUSICAL_MCSS_SetElemPos((void *)(work->elemSet), (struct McssActorElem *)sprite, (int *)&a);
        DUP_FITTING_ITEM_ElemSetPos(work->heldElem,(const u8 *)&work->holdDx);
        DUP_FITTING_ITEM_ElemSetAnimFrames((char *)(work->heldElem),10);
        DUP_FITTING_ReleaseElem(work);
        return;
    } else if(work->holdKind==3) {
        u8 *spriteB;
        spriteB=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);
        state=DUP_FITTING_ITEM_ElemGetFrameIndex((char *)(work->heldElem));
        record=(u8 *)MUSICAL_MCSS_GetRenderElem(work->renderParam,state);
        posB.x=(int)((float)(((struct DupFittingRenderElem *)record)->x+((struct DupFittingRenderElem *)record)->offsetX)/4096.0f)+128;
        posB.y=(int)((float)(((struct DupFittingRenderElem *)record)->y+((struct DupFittingRenderElem *)record)->offsetY)/4096.0f)+96;
        if(posB.x>0) b.x=(int)(0.5f+(float)(posB.x<<12));
        else b.x=(int)((float)(posB.x<<12)-0.5f);
        if(posB.y>0) b.y=(int)(0.5f+(float)(posB.y<<12));
        else b.y=(int)((float)(posB.y<<12)-0.5f);
        if(MUSICAL_MCSS_ElemHasAltDepth(spriteB)==1) b.z=102<<10;
        else if(DUP_FITTING_ITEM_ElemGetFrameIndex((char *)(work->heldElem))==7 || DUP_FITTING_ITEM_ElemGetFrameIndex((char *)(work->heldElem))==8) b.z=222<<10;
        else b.z=202<<10;
        flag=((struct DupFittingRenderElem *)record)->baseRotation;
        MUSICAL_MCSS_SetElemFlag((u8 *)(work->elemSet),(struct McssActorElem *)spriteB,1);
        MUSICAL_MCSS_SetElemPos((void *)(work->elemSet), (struct McssActorElem *)spriteB, (int *)&b);
        MUSICAL_MCSS_SetElemField((void *)(work->elemSet),(u8 *)(DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem)),flag);
        DUP_FITTING_ITEM_ElemSetPos(work->heldElem,(const u8 *)(&posB));
        currentB.x=work->cursorX; currentB.y=work->cursorY;
        DUP_FITTING_ITEM_ElemSetBasePos(work->heldElem,(const u8 *)(&currentB));
        DUP_FITTING_ITEM_ElemSetAnimFrames((char *)(work->heldElem),10);
        work->frameIndex=state;
        DUP_FITTING_MoveElem(work);
        work->frameIndex=10;
        return;
    } else if(work->holdKind==1) {
        DUP_FITTING_ITEM_ElemGetBasePos(work->heldElem);
        c=d_021BA5AC;
        sprite=(u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);
        DUP_FITTING_ITEM_ElemSetPos(work->heldElem,(const u8 *)&work->holdDx);
        DUP_FITTING_ITEM_ElemSetAnimFrames((char *)(work->heldElem),10);
        posC.x=work->cursorX; posC.y=work->cursorY;
        if(work->holdDx>0) c.x=(int)(0.5f+(float)(work->holdDx<<12));
        else c.x=(int)((float)(work->holdDx<<12)-0.5f);
        if(work->holdDy>0) c.y=(int)(0.5f+(float)(work->holdDy<<12));
        else c.y=(int)((float)(work->holdDy<<12)-0.5f);
        DUP_FITTING_ITEM_ElemSetBasePos(work->heldElem,(const u8 *)(&posC));
        MUSICAL_MCSS_SetElemPos((void *)(work->elemSet), (struct McssActorElem *)sprite, (int *)&c);
        DUP_FITTING_ReturnElem(work,1);
        return;
    }
    DUP_FITTING_ReturnElem(work,0);
}

/*
 * lever: Assign mode = 8 after the sort call; the compiler hoists its saved-register assignment between the r0 and r1 argument setups.
 * checks: 1 8BB4/9D54/765C arities verified; 2 matched/pending ov133 callers agree; 3 unsigned-long phase and long mode both DIFF4; 4 early-return/assignment-argument/volatile idioms tested; 5 fresh idiom listing and neighbours reread, stack pair already matches; permuter 300 baseline DIFF4 unchanged; next lever would be inline wrapper argument binding.
 * volatile: 0x021B89AC stores A4; 0x021B89B0 rereads that word for DUP_FITTING_SetTextHelp.
 */
int DUP_FITTING_SelectFrame(struct DupFittingWork *work)
{
    int pos[2];
    u16 limit = 16;
    u16 start;
    u32 phase;
    int mode = 0;
    int index;
    phase = work->startAngle + 0x19249;
    if (phase >= work->frameCount * 4681u)
        start = (phase - work->frameCount * 4681u) / 4681u;
    else start = phase / 4681u;
    pos[0] = work->cursorX - 128;
    pos[1] = work->cursorY - 112;
    index = DUP_FITTING_FindNearestFrame(work, 0, pos, &limit);
    if (index != 10) {
    mode = MUSICAL_MCSS_GetIndex(index);
    if (mode == 7) mode = 6;
    if (mode == work->sortMode) {
        DUP_FITTING_SortFrames(work, 8, start);
        mode = 8;
    } else DUP_FITTING_SortFrames(work, mode, start);
    work->sortMode = mode;
    DUP_FITTING_SetTextHelp(work, *(volatile int *)&work->sortMode);
    work->subMode = 1;
    work->subTurned = 0;
    work->subTurnTarget = work->rotation % 4681 + 65536;
    if (work->subTurnTarget >= 65536 && work->subTurnTarget <= 65538)
        work->subTurnTarget += 4681;
    DUP_FITTING_SetModelTransform(work, work->rotation, 0, 72, 48);
    GFL_USE_PlaySeDefaultVolume(1576);
    return 1;
    }
    return mode;
}

void DUP_FITTING_UpdateSubMode(struct DupFittingWork *work)
{
    u32 delta = work->subTurnTarget - work->subTurned;
    u32 step = delta / 10u;
    if (step < 256) {
        if (delta < 256) {
            step = delta;
            work->subMode = 0;
        } else step = 256;
    }
    if (delta > 4096) {
        work->spin -= 512;
        if (work->spin < -12288) work->spin = -12288;
    } else DUP_FITTING_UpdateRotation(work);
    work->subTurned += step;
    work->rotation -= (u16)step;
    DUP_FITTING_SetModelTransform(work, work->rotation, step, 72, 48);
}

void DUP_FITTING_UpdateRotation(struct DupFittingWork *work)
{
    int n = work->rotationVel;
    if (n < 0) n = -n;
    if (n < 48 && (work->spin != 0 || work->spinAccel != 0)) {
        work->spin += work->spinAccel;
        if (work->spin > 0) {
            if (work->spinAccel > 0) work->spinAccel -= 128;
            else work->spinAccel -= 42;
        } else if (work->spin < 0) {
            if (work->spinAccel < 0) work->spinAccel += 128;
            else work->spinAccel += 42;
        }
        n = work->spin;
        if (n < 0) n = -n;
        if (n < 512) {
            n = work->spinAccel;
            if (n < 0) n = -n;
            if (n < 512) {
                work->spinAccel = 0;
                work->spin = 0;
            }
        }
        DUP_FITTING_SetModelTransform(work, work->rotation, 0, 72, 48);
    }
}

int DUP_FITTING_IsFrameOwned(struct DupFittingWork *work,unsigned int id) {int key=MUSICAL_MCSS_GetIndex(id);unsigned char *q=DUP_FITTING_ITEM_ListGetHead((char *)(work->listB));while(q){if(key==MUSICAL_MCSS_GetIndex(DUP_FITTING_ITEM_ElemGetFrameIndex((char *)q)))return 1;q=(unsigned char *)DUP_FITTING_ITEM_ElemGetNext(q);}return 0;}

static inline int coordinate(int value, DupFittingIndex offset)
{
    return (int)((float)value / 4096.0f) - offset;
}

/*
 * lever: Inline coordinate conversion with an enum offset keeps the zero subtract and matching spill homes.
 */
int DUP_FITTING_FindNearestFrame(struct DupFittingWork *work, void *manager, const int *pos, u16 *limit)
{
    u16 distance;
    int best;
    int x;
    DupFittingIndex i;
    int enabled, y, dx, dy, n;
    u8 *q;
    distance = *limit * *limit;
    best = 10;
    for (i = I_ZERO; i < I_LIMIT; i++) {
        if (manager == 0) enabled = 1;
        else enabled = MUSICAL_MCSS_IsElemModeSupportedA(manager, i);
        q=(u8 *)MUSICAL_MCSS_GetRenderElem(work->renderParam, i);
        if (((struct DupFittingRenderElem *)q)->active == 1 && enabled == 1) {
            x = coordinate(((struct DupFittingRenderElem *)q)->x + ((struct DupFittingRenderElem *)q)->offsetX, I_ZERO);
            y = coordinate(((struct DupFittingRenderElem *)q)->y + ((struct DupFittingRenderElem *)q)->offsetY, (DupFittingIndex)16);
            dx = pos[0] - x;
            dy = pos[1] - y;
            n = dx * dx + dy * dy;
            if (n < distance) { distance = n; best = i; }
        }
    }
    *limit = distance;
    return best;
}

void DUP_FITTING_DrawElems(struct DupFittingWork *work)
{
    DupFittingVec flyPos;
    DupFittingVec slidePos;
    DupFittingVec restPos;
    u32 cnt0;
    u8 *cur;
    int *A;
    int *B;
    int s;
    int flag;
    int n2;
    int *A2;
    int baseX;
    int w;
    int baseY;
    int baseXB;
    int wb;
    int baseYB;
    u8 *e;
    struct McssActorElem *data;
    u32 cnt;
    int n;
    int x;
    int d;
    short sx;
    int *B2;
    struct McssActorElem *data2;
    e = DUP_FITTING_ITEM_ListGetHead(work->listC);
    if (e) {
        do {
            cur = e;
            data = DUP_FITTING_ITEM_ElemGetRenderElem(e);
            cnt = DUP_FITTING_ITEM_ElemGetAnimFrames((char *)e);
            A = (int *)DUP_FITTING_ITEM_ElemGetBasePos(e);
            B = (int *)DUP_FITTING_ITEM_ElemGetPos(e);
            s = (short)DUP_FITTING_ITEM_ElemGetStartScale(e);
            e = (u8 *)(unsigned char *)DUP_FITTING_ITEM_ElemGetNext(e);
            n = (u16)(cnt - 1);
            if (n != 0) {
                x = s + ((0x1000 - s) * n) / 10;
                sx = x;
                MUSICAL_MCSS_SetElemRotZ(work->elemSet, (u8 *)data, sx, sx);
                MUSICAL_MCSS_SetElemScale((sptr)work->elemSet, data, (&flyPos));
                w = 10 - (u16)n;
                baseX = A[0];
                x = B[0] - baseX;
                x *= w;
                x = baseX + x / 10;
                if (x > 0) flyPos.x = (int)(0.5f + (float)(x << 12));
                else flyPos.x = (int)((float)(x << 12) - 0.5f);
                baseY = A[1];
                x = B[1] - baseY;
                x *= w;
                x = baseY + x / 10;
                if (x > 0) flyPos.y = (int)(0.5f + (float)(x << 12));
                else flyPos.y = (int)((float)(x << 12) - 0.5f);
                flyPos.z = 0x46000;
                MUSICAL_MCSS_SetElemPos(work->elemSet, (struct McssActorElem *)data, (int *)&flyPos);
                DUP_FITTING_ITEM_ElemSetAnimFrames((char *)cur, n);
            } else {
                DUP_FITTING_ITEM_RemoveElem(work->listC, cur);
                DUP_FITTING_ITEM_DeleteElem(cur, work->elemSet);
            }
        } while (e);
    }
    flag = 0;
    e = DUP_FITTING_ITEM_ListGetHead(work->listA);
    if (e == 0) {
        flag = 1;
        e = DUP_FITTING_ITEM_ListGetHead(work->listB);
    }
    if (e) {
        do {
            cnt0 = DUP_FITTING_ITEM_ElemGetAnimFrames((char *)e);
            if (cnt0 != 0) {
                data2 = DUP_FITTING_ITEM_ElemGetRenderElem(e);
                A2 = (int *)DUP_FITTING_ITEM_ElemGetBasePos(e);
                B2 = (int *)DUP_FITTING_ITEM_ElemGetPos(e);
                n2 = (u16)(cnt0 - 1);
                if (n2 != 0) {
                    MUSICAL_MCSS_SetElemScale((sptr)work->elemSet, data2, (&slidePos));
                    wb = 10 - n2;
                    baseXB = A2[0];
                    x = B2[0] - baseXB;
                    x *= wb;
                    x = baseXB + x / 10;
                    if (x > 0) slidePos.x = (int)(0.5f + (float)(x << 12));
                    else slidePos.x = (int)((float)(x << 12) - 0.5f);
                    baseYB = A2[1];
                    x = B2[1] - baseYB;
                    x *= wb;
                    x = baseYB + x / 10;
                    if (x > 0) slidePos.y = (int)(0.5f + (float)(x << 12));
                    else slidePos.y = (int)((float)(x << 12) - 0.5f);
                    MUSICAL_MCSS_SetElemPos(work->elemSet, (struct McssActorElem *)data2, (int *)&slidePos);
                } else {
                    MUSICAL_MCSS_SetElemScale((sptr)work->elemSet, data2, (&restPos));
                    if (B2[0] > 0) restPos.x = (int)(0.5f + (float)(B2[0] << 12));
                    else restPos.x = (int)((float)(B2[0] << 12) - 0.5f);
                    if (B2[1] > 0) restPos.y = (int)(0.5f + (float)(B2[1] << 12));
                    else restPos.y = (int)((float)(B2[1] << 12) - 0.5f);
                    MUSICAL_MCSS_SetElemPos(work->elemSet, (struct McssActorElem *)data2, (int *)&restPos);
                    DUP_FITTING_ITEM_ElemSetBasePos(e, (const u8 *)B2);
                }
                DUP_FITTING_ITEM_ElemSetAnimFrames((char *)e, n2);
            }
            e = (u8 *)(unsigned char *)DUP_FITTING_ITEM_ElemGetNext(e);
            if (e == 0 && flag == 0) {
                flag = 1;
                e = DUP_FITTING_ITEM_ListGetHead(work->listB);
            }
        } while (e);
    }
}

void DUP_FITTING_UpdateHeldVisible(struct DupFittingWork *work)
{
    if (work->heldElem == 0) {
        MUSICAL_MCSS_SetElemVisible(work->elemSet, work->elemPool, 0);
        return;
    }
    if (work->heldItemId == *(u16 *)DUP_FITTING_ITEM_ElemGetData(work->heldElem)) {
        MUSICAL_MCSS_SetElemVisible(work->elemSet, work->elemPool, 1);
        MUSICAL_MCSS_CopyElem(work->elemSet, (u8 *)DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem), work->elemPool);
    }
}

int DUP_FITTING_HitCircle(int x,int y,int radius,float scale) {short k=(short)((float)x*scale);if(k*k+y*y<radius*radius)return 1;return 0;}

/*
 * lever: explicit redundant pointer/bound temporaries from the bounded permuter settled the three spill homes.
 */
void DUP_FITTING_SortFrames(struct DupFittingWork *work, int kind, u16 start)
{
    u8 *positionptr;
    u16 i, j, index, position, weight, next, best;
    u8 *tmp;
    u8 *slotPtr;
    struct DupFittingFrame **destSlot;
    u16 frameCount, frameCountRead;
    for (i = 0; i < work->frameCount; i++) {
        index = (u16)((start + i) % work->frameCount);
        work->frameOrder[index] = &work->frames[i];
    }
    for (i = 0; i < work->frameCount; i++) {
        position = (u16)((start + i) % work->frameCount);
        best = position;
        slotPtr = (u8 *)work + position * sizeof(work->frameOrder[0]);
        positionptr = slotPtr;
        weight = DUP_FITTING_FrameWeight(work, (u8 *)((struct DupFittingWork *)positionptr)->frameOrder[0], kind);
        for (j = i + 1; j < work->frameCount; j++) {
            frameCountRead = work->frameCount;
            frameCount = frameCountRead;
            index = (u16)((start + j) % frameCount);
            next = DUP_FITTING_FrameWeight(work, (u8 *)work->frameOrder[index], kind);
            if (weight < next) { weight = next; best = index; }
        }
        if (best != position) {
            tmp = (u8 *)((struct DupFittingWork *)positionptr)->frameOrder[0];
            ((struct DupFittingWork *)positionptr)->frameOrder[0] = work->frameOrder[best];
            destSlot = &work->frameOrder[best];
            *destSlot = (struct DupFittingFrame *)tmp;
        }
    }
}

u16 DUP_FITTING_FrameWeight(struct DupFittingWork *work, u8 *frame, int kind)
{
    int a = MUSICAL_MCSS_IsElemModeSupportedC(work->elemSet, ((struct DupFittingFrame *)frame)->id, kind);
    int b = MUSICAL_MCSS_IsElemModeSupportedB(work->elemSet, ((struct DupFittingFrame *)frame)->id, kind);
    int n;
    if (a == 1) {
        if (((struct DupFittingFrame *)frame)->owned == 1) n = 6000;
        else n = 5000;
    } else if (b == 1) {
        if (((struct DupFittingFrame *)frame)->owned == 1) n = 4000;
        else n = 3000;
    } else {
        if (((struct DupFittingFrame *)frame)->owned == 1) n = 2000;
        else n = 1000;
    }
    return n + (999 - ((struct DupFittingFrame *)frame)->id);
}

void DUP_FITTING_DrawFrames(struct DupFittingWork *work)
{
    u8 *e;
    DupFittingPt r;
    DUP_FITTING_SetModelTransform(work, work->rotation, 0, (u16)(work->progress + 0x48), (u16)(48.0f + (float)work->progress * 0.6666667f));
    e = DUP_FITTING_ITEM_ListGetHead((char *)(work->listA));
    while (e) {
        int *pos = (int *)DUP_FITTING_ITEM_ElemGetPos(e);
        struct McssActorElem *id = DUP_FITTING_ITEM_ElemGetRenderElem(e);
        int y;
        int x;
        int d;
        int dist, ang, k;
        const SC *sc;
        int v[3];
        x = (short)(pos[0] - 0x80);
        y = (short)(pos[1] - 0x50);
        d = x * x + y * y;
        dist = FX_Sqrt(FXI(d));
        ang = FX_Atan2Idx(FXI(y), FXI(x));
        MUSICAL_MCSS_SetElemScale((uptr)(work->elemSet), id, v);
        k = dist + FXI(work->progress);
        sc = &((const SC *)FX_SinCosTable_)[ang >> 4];
        v[0] = (fx32)(((long long)sc->c * k + 0x800) >> 12) + 0x80000;
        k = dist + FXF((float)work->progress * 0.6666667f);
        v[1] = (fx32)(((long long)sc->s * k + 0x800) >> 12) + 0x50000;
        MUSICAL_MCSS_SetElemPos(work->elemSet, (struct McssActorElem *)id, (int *)v);
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
    BG_SYS_ChangeScrollImmediate(2, 3, -work->progress);
    r.x = 0x20;
    {
        int t = 0xC0 - work->progress;
        if (t >= 0x40) t = 0x40;
        r.y = t + 0xA0;
    }
    CLACT_AddActorSurfacePos((struct ClactActor *)(work->actorA), (const struct ClactVec2 *)((const struct Vec2 *)(&r)), 0);
    r.x = 0xE0;
    {
        int t = 0xC0 - work->progress;
        if (t >= 0x40) t = 0x40;
        r.y = t + 0xA0;
    }
    CLACT_AddActorSurfacePos((struct ClactActor *)(work->actorB), (const struct ClactVec2 *)((const struct Vec2 *)(&r)), 0);
}

int DUP_FITTING_HandleTouch(struct DupFittingWork *work)
{
    Rects rects = d_021BA594;
    void *obj;
    TOUCHPANEL_GetPointCont((u32 *)&work->cursorX, (u32 *)&work->cursorY);
    switch (TOUCHPANEL_HitTrg((const TouchHitTable *)&rects)) {
    case 0:
        DUP_FITTING_SaveOutfits(work);
        GFL_USE_PlaySeDefaultVolume(1358);
        DUP_FITTING_ResetActorPose(work);
        return 2;
    case 1:
        work->state = 6;
        work->progress = 192;
        GFL_USE_PlaySeDefaultVolume(1962);
        DUP_FITTING_ResetSlots(work);
        obj = WORDSET_CreateDefault(work->heapId);
        WORDSET_SetSlotMonNickname(obj, 0, work->parent->outfitTable->monSpecies);
        DUP_FITTING_SetText(work, 0, obj);
        WORDSET_Delete(obj);
        DUP_FITTING_ResetActorPose(work);
        break;
    case -1:
        DUP_FITTING_HandlePickTouch(work);
        break;
    }
    DUP_FITTING_UpdateHeldVisible(work);
    return 0;
}

void DUP_FITTING_ResetSlots(struct DupFittingWork *work)
{
    u8 i;
    u8 *e, *q;
    u16 index;
    for (i = 0; i < 9; i++)
        work->parent->outfitTable->rec[i].rotation = 0;
    e = DUP_FITTING_ITEM_ListGetHead(work->listB);
    while (e) {
        index = DUP_FITTING_ITEM_ElemGetFrameIndex((char *)e);
        q=(u8 *)MUSICAL_MCSS_GetRenderElem(work->renderParam, index);
        MUSICAL_MCSS_SetElemField((work->elemSet), (u8 *)(DUP_FITTING_ITEM_ElemGetRenderElem(e)), ((struct DupFittingRenderElem *)q)->baseRotation);
        e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
    }
}

void DUP_FITTING_HandlePickTouch(struct DupFittingWork *work)
{
    u8 *e, *best;
    unsigned int distance, n;
    work->prevX = work->cursorX;
    work->prevY = work->cursorY;
    work->touchTrg = TOUCHPANEL_GetTrg();
    work->touchCont = TOUCHPANEL_GetPointCont((unsigned int *)&work->cursorX, (unsigned int *)&work->cursorY);
    if (work->touchTrg == 1) {
        best = 0;
        distance = 256;
        e = DUP_FITTING_ITEM_ListGetHead(work->listB);
        while (e) {
            n = DUP_FITTING_ITEM_ElemHitDistance(e, work->cursorX, work->cursorY);
            if (distance > n) { best = e; distance = n; }
            e = (u8 *)DUP_FITTING_ITEM_ElemGetNext(e);
        }
        if (best) work->heldElem = best;
    }
    if (work->touchCont == 1 && work->heldElem) DUP_FITTING_DragRotate(work);
    if (work->touchCont == 0) {
        work->dragActive = 0;
        work->heldElem = 0;
    }
}

static inline int fx(int x)
{
    if(x>0) return (int)(0.5f+(float)(int)((unsigned)x<<12));
    return (int)((float)(int)((unsigned)x<<12)-0.5f);
}

void DUP_FITTING_DragRotate(struct DupFittingWork *work)
{
    u16 index,angle;
    u8 *rec;
    u32 *xy;
    int dx,dy,stride,absval,y;
    short old,adjust;
    index=DUP_FITTING_ITEM_ElemGetFrameIndex((char *)(work->heldElem));
    rec=(u8 *)MUSICAL_MCSS_GetRenderElem(work->renderParam,index);
    DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem);
    xy=(u32 *)DUP_FITTING_ITEM_ElemGetPos(work->heldElem);
    y=xy[1];
    dx=fx((int)(work->cursorX-xy[0]));
    dy=fx((int)(work->cursorY-(unsigned)y));
    angle=FX_Atan2Idx(dx,dy);
    if(work->dragActive==1) {
        stride=index*6;
        old=work->parent->outfitTable->rec[index].rotation;
        adjust=old+(short)(work->prevAngle-angle);
        if(adjust< -2730) adjust= -2730;
        if(adjust>2730) adjust=2730;
        work->clampSlack+=(short)(old-adjust);
        absval=work->clampSlack;
        if(absval<0) absval= -absval;
        if(absval>1820) {
            work->clampSlack=0;
            GFL_USE_PlaySeDefaultVolume(1577);
        }
        MUSICAL_MCSS_SetElemField((work->elemSet),(u8 *)(DUP_FITTING_ITEM_ElemGetRenderElem(work->heldElem)),((struct DupFittingRenderElem *)rec)->baseRotation+adjust);
        work->parent->outfitTable->rec[index].rotation=adjust;
    }
    work->prevAngle=angle;
    work->dragActive=1;
}

void DUP_FITTING_SaveOutfits(struct DupFittingWork *work)
{
    u8 *sv = (unsigned char *)MUSICAL_SAVE_GetOutfits(work->parent->saveData);
    void *t;
    u8 i = 0;
    MUSICAL_SAVE_InitOutfits(work->parent->saveData);
    t = DUP_FITTING_ITEM_ListGetHead(work->listB);
    while (t != 0 && i < 8) {
        u32 idx = (u16)DUP_FITTING_ITEM_ElemGetFrameIndex(t);
        u8 *rec;
        (char *)MUSICAL_MCSS_GetRenderElem(work->renderParam, idx);
        rec = sv + i * 6;
        sv[i * 6] = idx;
        *(u16 *)(rec + 2) = *((u16 *)DUP_FITTING_ITEM_ElemGetData(t));
        *(short *)(rec + 4) = work->parent->outfitTable->rec[idx].rotation;
        work->parent->outfitTable->rec[idx].id = *((u16 *)DUP_FITTING_ITEM_ElemGetData(t));
        work->parent->outfitTable->rec[idx].flag = i;
        t = (void *)DUP_FITTING_ITEM_ElemGetNext(t);
        i++;
    }
}

void DUP_FITTING_DrawBackActors(struct DupFittingWork *work)
{
    DupFittingPos pos;
    u8 pal;
    pos.x=32;
    pos.y=work->exitTimer*2+160;
    if(pos.y>=224) pos.y=224;
    CLACT_AddActorSurfacePos((struct ClactActor *)(work->actorA),(const struct ClactVec2 *)((const struct Vec2 *)(&pos)),0);
    pos.x=224;
    pos.y=work->exitTimer*2+160;
    if(pos.y>=224) pos.y=224;
    CLACT_AddActorSurfacePos((struct ClactActor *)(work->actorB),(const struct ClactVec2 *)((const struct Vec2 *)(&pos)),0);
    pal=work->exitTimer*24/60+4;
    if(pal>=11) pal=3;
    BG_SYS_FillTileMap(2,10,44,12,12,pal);
    BG_SYS_MarkTileDirty(2);
}

void DUP_FITTING_EnterPoseMode(struct DupFittingWork *work)
{
    unsigned i;
    work->firstTouch=1;
    work->animStep=0;
    work->animPhase=1;
    i=5;
    do {
        if(work->frameOrder[(unsigned)i]->mode!=1) break;
        i=(u16)(i+1);
        if(i==work->frameCount) i=0;
    } while(i!=5);
    if(i==0) work->animSlot=work->frameCount-1;
    else work->animSlot=i-1;
    work->state=0;
}

void DUP_FITTING_ExitPoseMode(struct DupFittingWork *work) {work->firstTouch=0;work->state=1;CLACT_SetActorDrawEnable(work->actorC,0);DUP_FITTING_SetTextMon(work);}

void DUP_FITTING_UpdatePose(struct DupFittingWork *work)
{
    DupFittingPair firstA,firstB,secondA,secondB;
    DupFittingPos pos;
    switch(work->animPhase) {
    case 0: break;
    case 1: DUP_FITTING_StepPoseRotate(work,work->animSlot*4681,work->animSlot*4681,work->animSlot*15); break;
    case 2: DUP_FITTING_StepPoseHold(work,30); break;
    case 3: DUP_FITTING_StepPoseRotate(work,-(u16)(work->animSlot*4681),-(work->animSlot*4681),work->animSlot*15); break;
    case 4: DUP_FITTING_StepPoseHold(work,30); break;
    case 5: firstA=gDupFittingPoseSlide1From; firstB=gDupFittingPoseSlide1To; DUP_FITTING_StepPoseSlide(work,&firstA.x,&firstB.x,60); break;
    case 6: DUP_FITTING_StepPoseHold(work,30); break;
    case 7: secondA=gDupFittingPoseSlide2From; secondB=gDupFittingPoseSlide2To; DUP_FITTING_StepPoseSlide(work,&secondA.x,&secondB.x,60); break;
    case 8: DUP_FITTING_StepPoseHold(work,30); break;
    case 9: DUP_FITTING_ExitPoseMode(work); return;
    }
    pos.x=work->cursorX; pos.y=work->cursorY;
    CLACT_AddActorSurfacePos((struct ClactActor *)(work->actorC),(const struct ClactVec2 *)((const struct Vec2 *)(&pos)),0);
    DUP_FITTING_UpdateIdle(work);
}

void DUP_FITTING_StepPoseRotate(struct DupFittingWork *work,u16 a,int delta,u16 duration)
{
    int step,index;
    work->touchCont=0;
    work->touchTrg=0;
    CLACT_SetActorDrawEnable(work->actorC,1);
    step=delta / duration;
    index=((u16)((int)((unsigned)a-(unsigned)step*work->animStep+65536)%65536)>>4)*2;
    work->cursorX=(unsigned)((float)(72*FX_SinCosTable_[index]+0x80000)/4096.0f);
    work->cursorY=(unsigned)((float)(48*FX_SinCosTable_[index+1]+0x50000)/4096.0f);
    work->rotation-=(u16)step;
    DUP_FITTING_SetModelTransform(work,work->rotation,step,72,48);
    ++work->animStep;
    if(work->animStep>duration) {
        work->animStep=0;
        ++work->animPhase;
    }
}

void DUP_FITTING_StepPoseHold(struct DupFittingWork *work,unsigned int limit) {work->touchCont=0;work->touchTrg=0;(work->animStep)++;CLACT_SetActorDrawEnable(work->actorC,0);if(work->animStep>limit){work->animStep=0;(work->animPhase)++;}}

void DUP_FITTING_StepPoseSlide(struct DupFittingWork *work, int *a, int *b, u16 duration)
{
    int x, y;
    int count;
    work->touchCont = 1;
    if (work->animStep == 0) work->touchTrg = 1;
    else work->touchTrg = 0;
    count = work->animStep;
    y = a[1] + (b[1] - a[1]) * count / (int)duration;
    x = a[0] + (b[0] - a[0]) * count / (int)duration;
    work->cursorX = x;
    work->cursorY = y;
    CLACT_SetActorDrawEnable(work->actorC, 1);
    (work->animStep)++;
    if (work->animStep > duration) {
        work->animStep = 0;
        (work->animPhase)++;
    }
}

void DUP_FITTING_CreateText(struct DupFittingWork *work)
{
    work->font = GF_FONT_Create(23, 0, 0, 0, work->heapId);
    work->msgBankA = MSGDATA_CreateFromArchive(0, 2, 33, work->heapId);
    work->msgBankB = MSGDATA_CreateFromArchive(0, 2, 79, work->heapId);
    work->msgBankC = MSGDATA_CreateFromArchive(0, 2, 75, work->heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, 4, 448, 32, work->heapId);
    work->printSys = (void *)PRINTSYS_QUE_Create((unsigned int)(work->heapId));
    BMP_MENUWORK_LoadCharAndPltt(7, 128, 12, 0, work->heapId);
}

void DUP_FITTING_DeleteText(struct DupFittingWork *work) {PRINTSYS_QUE_Delete(work->printSys);MSGDATA_Delete(work->msgBankB);MSGDATA_Delete(work->msgBankC);MSGDATA_Delete(work->msgBankA);GF_FONT_Delete(work->font);}

void DUP_FITTING_SetText(struct DupFittingWork *work, unsigned int index, void *object)
{
    void *text = MSGDATA_AllocString(work->msgBankA, index);
    void *copy;
    PRINTSYS_QUE_Clear(work->printSys);
    BMP_Clear(BMP_WIN_GetBmp(work->window), 15);
    if (object) {
        copy = STRBUF_Create(128, work->heapId);
        WORDSET_CopyTaggedText(object, copy, text);
        STRBUF_Delete(text);
        text = copy;
    }
    PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(work->window), 2, 2, text, (work->font), 1088);
    STRBUF_Delete(text);
    work->busy = 1;
}

void DUP_FITTING_SetTextMon(struct DupFittingWork *work) {void *r=WORDSET_CreateDefault(work->heapId);WORDSET_SetSlotMonNickname(r,0,((struct DupFittingOutfitTable *)(*(unsigned char * *)&((struct DupFittingOwner *)(work->parent))->outfitTable))->monSpecies);DUP_FITTING_SetText(work,0,r);WORDSET_Delete(r);}

void DUP_FITTING_SetTextItem(struct DupFittingWork *work, u8 *entry)
{
    void *manager = MUSICAL_MCSS_GetActorPoolResource(work->elemSet);
    u8 *data = (u8 *)DUP_FITTING_ITEM_ElemGetData(entry);
    int index = MUSICAL_MCSS_GetElemC(manager, ((struct DupFittingItemData *)data)->id);
    void *obj = WORDSET_CreateDefault(work->heapId);
    void *a = MSGDATA_AllocString(work->msgBankB, ((struct DupFittingItemData *)data)->id + 3);
    void *b = MSGDATA_AllocString(work->msgBankC, index + 16);
    WORDSET_SetSlotTag(obj, 0, a, 0, 1, 2);
    WORDSET_SetSlotTag(obj, 1, b, 0, 1, 2);
    DUP_FITTING_SetText(work, 3, obj);
    STRBUF_Delete(b);
    STRBUF_Delete(a);
    WORDSET_Delete(obj);
}

void DUP_FITTING_SetTextHelp(struct DupFittingWork *work, int state)
{
    int index;
    void *w;
    void *str;
    if (state == 8) {
        DUP_FITTING_SetText(work, 5, 0);
        return;
    }
    index = 0;
    switch (state) {
    case 0:
    case 1: index = 0x10; break;
    case 2: index = 0x11; break;
    case 3: index = 0x17; break;
    case 4: index = 0x14; break;
    case 5: index = 0x15; break;
    case 6:
    case 7: index = 0x16; break;
    }
    w = WORDSET_CreateDefault(work->heapId);
    str = MSGDATA_AllocString(work->msgBankC, index);
    WORDSET_SetSlotTag(w, 0, str, 0, 1, 2);
    DUP_FITTING_SetText(work, 4, w);
    STRBUF_Delete(str);
    WORDSET_Delete(w);
}

void DUP_FITTING_CreateActors(struct DupFittingWork *work)
{
    DupFittingActorParam configs[2];
    u8 i;
    i=0;
    do {
        configs[1].x=0;configs[1].y=0;configs[1].index=0;configs[1].a=0;configs[1].b=0;
        work->actors[i]=CLACT_CreateActor((void *)work->clactUnit,work->clactRes[2],work->clactRes[5],work->clactRes[8],(const struct ActorInitParam *)&configs[1],1,work->heapId);
        CLACT_SetActorDrawEnable(work->actors[i],1);
        CLACT_SetActorAutoAnim(work->actors[i],1);
        CLACT_SetActorObjMode(work->actors[i],0);
        work->actorTimers[i]=0;
        ++i;
    } while(i<8);
    configs[0].x=128;configs[0].y=96;configs[0].index=0;configs[0].a=0;configs[0].b=0;
    work->actorX=CLACT_CreateActor((void *)work->clactUnit,work->clactRes[1],work->clactRes[4],work->clactRes[7],(const struct ActorInitParam *)&configs[0],0,work->heapId);
    CLACT_SetActorDrawEnable(work->actorX,0);
    CLACT_SetActorAutoAnim(work->actorX,1);
    configs[0].index=2;
    work->actorY=CLACT_CreateActor((void *)work->clactUnit,work->clactRes[1],work->clactRes[4],work->clactRes[7],(const struct ActorInitParam *)&configs[0],0,work->heapId);
    CLACT_SetActorDrawEnable(work->actorY,0);
    CLACT_SetActorAutoAnim(work->actorY,1);
}

void DUP_FITTING_DeleteActors(struct DupFittingWork *work) {unsigned char i;for(i=0;i<8;i++)CLACT_DeleteActor(work->actors[(unsigned int)i]);CLACT_DeleteActor(work->actorY);CLACT_DeleteActor(work->actorX);}

/*
 * lever: Pointer addition for timer stores and unsigned address addition for the guard preserve four independent offset homes and the decrement reload. Uniform integer addition gave 292 bytes; uniform pointer addition gave 304.
 * note 2026-10-05 (wave D9r lane 131): removed the 5 dead first assignments
 * (`a = 0x1890;` before `a = 0x18b8;`; `b = 0x1890;` before `b = 0x18b8;`
 * and 3 more). Game code has no line table, so these were stand-ins. The
 * plain single assignment gives EXACT in --lang c99 and --lang c: the output
 * bytes do not change. Older text in this header that asks for the double
 * assignment is superseded.
 */
void DUP_FITTING_UpdateActorTimers(struct DupFittingWork *work)
{
#ifdef __MWERKS__
    int a, b, delay, c, d;
    DupFittingPos pos;
    u8 i;
    u8 *q, *t;
    a = 0x18b8;
    b = 0x18b8;
    delay = 0x190;
    c = 0x18b8;
    d = 0x18b8;
    for (i = 0; i < 8; i++) {
        q = (u8 *)work + i * 4;
        CLACT_SetActorBgPriority(((struct DupFittingWork *)q)->actors[0], BG_SYS_GetPriority(4));
        CLACT_SetActorObjMode(((struct DupFittingWork *)q)->actors[0], 0);
        t = (u8 *)work + i;
        if (*(u8 *)((uptr)work+(u32)i+(u32)d) == 0) {
            pos.x = ((u64)GF_STANDARD_Rand() * 56) >> 32;
            if ((u32)(((u64)GF_STANDARD_Rand() * 2) >> 32) == 1) pos.x = 256 - pos.x;
            pos.y = ((u64)GF_STANDARD_Rand() * 192) >> 32;
            CLACT_AddActorSurfacePos((struct ClactActor *)(((struct DupFittingWork *)q)->actors[0]), (const struct ClactVec2 *)((const struct Vec2 *)(&pos)), 1);
            if (pos.y > 90) CLACT_SetActorAnimSeq(((struct DupFittingWork *)q)->actors[0], ((u64)GF_STANDARD_Rand() * 2) >> 32);
            else CLACT_SetActorAnimSeq(((struct DupFittingWork *)q)->actors[0], (((u64)GF_STANDARD_Rand() * 2) >> 32) + 2);
            t[c] = (((u64)GF_STANDARD_Rand() * 200) >> 32) + delay;
        } else {
            t[b] = t[a] - 1;
        }
    }
    if (CLACT_GetActorDrawEnable(work->actorY) == 1 && CLACT_IsActorAnimActive(work->actorY) == 0) {
        CLACT_SetActorDrawEnable(work->actorY, 0);
    }
#else
    int delay;
    DupFittingPos pos;
    u8 i;
    delay = 0x190;
    for (i = 0; i < 8; i++) {
        CLACT_SetActorBgPriority(work->actors[i], BG_SYS_GetPriority(4));
        CLACT_SetActorObjMode(work->actors[i], 0);
        if (work->actorTimers[i] == 0) {
            pos.x = ((u64)GF_STANDARD_Rand() * 56) >> 32;
            if ((u32)(((u64)GF_STANDARD_Rand() * 2) >> 32) == 1) pos.x = 256 - pos.x;
            pos.y = ((u64)GF_STANDARD_Rand() * 192) >> 32;
            CLACT_AddActorSurfacePos(work->actors[i], (const struct ClactVec2 *)((const struct Vec2 *)(&pos)), 1);
            if (pos.y > 90) CLACT_SetActorAnimSeq(work->actors[i], ((u64)GF_STANDARD_Rand() * 2) >> 32);
            else CLACT_SetActorAnimSeq(work->actors[i], (((u64)GF_STANDARD_Rand() * 2) >> 32) + 2);
            work->actorTimers[i] = (((u64)GF_STANDARD_Rand() * 200) >> 32) + delay;
        } else {
            work->actorTimers[i] = work->actorTimers[i] - 1;
        }
    }
    if (CLACT_GetActorDrawEnable(work->actorY) == 1 && CLACT_IsActorAnimActive(work->actorY) == 0) {
        CLACT_SetActorDrawEnable(work->actorY, 0);
    }
#endif
}

void DUP_FITTING_ResetActorPose(struct DupFittingWork *work){DupFittingPos pos;pos.x=work->cursorX;pos.y=work->cursorY;CLACT_RestartActorAnim((struct ClactActor *)(work->actorY));CLACT_SetActorDrawEnable((struct ClactActor *)(work->actorY),1);CLACT_AddActorSurfacePos((struct ClactActor *)(work->actorY),(const struct ClactVec2 *)((const struct Vec2 *)(&pos)),0);}
