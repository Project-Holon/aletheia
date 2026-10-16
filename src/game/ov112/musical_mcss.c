/*
 * file:     musical_mcss.c
 * unit:     yes
 * function: MUSICAL_MCSS_SetObjectValue, MUSICAL_MCSS_DrawLabel, MUSICAL_MCSS_NoOp, MUSICAL_MCSS_Create, MUSICAL_MCSS_Delete, MUSICAL_MCSS_Main, MUSICAL_MCSS_NoOp2, MUSICAL_MCSS_CreateUnits, MUSICAL_MCSS_InitBg, MUSICAL_MCSS_InitWindows, MUSICAL_MCSS_DeleteWindows, MUSICAL_MCSS_PrintStream, MUSICAL_MCSS_PrintQue, MUSICAL_MCSS_OpenMenu, MUSICAL_MCSS_CreateActorPool, MUSICAL_MCSS_DeleteActorPool, MUSICAL_MCSS_UpdateObject, MUSICAL_MCSS_GetArcFileCount, MUSICAL_MCSS_SetupObject, MUSICAL_MCSS_SetIndexA, MUSICAL_MCSS_SetIndexB, MUSICAL_MCSS_SetIndexC, MUSICAL_MCSS_GetFlagA, MUSICAL_MCSS_GetFlagB, MUSICAL_MCSS_CreateResourceArc, MUSICAL_MCSS_FreeResourceArc, MUSICAL_MCSS_NoOp4, MUSICAL_MCSS_AddImage, MUSICAL_MCSS_AddImageNoVram, MUSICAL_MCSS_AddElem, MUSICAL_MCSS_FreeElem, MUSICAL_MCSS_FreeElemImage, MUSICAL_MCSS_TransferVram, MUSICAL_MCSS_CopyElem, MUSICAL_MCSS_SetElemVisible, MUSICAL_MCSS_SetElemPos, MUSICAL_MCSS_SetElemScale, MUSICAL_MCSS_SetElemRotZ, MUSICAL_MCSS_SetElemRot, MUSICAL_MCSS_SetElemField, MUSICAL_MCSS_GetElemField, MUSICAL_MCSS_SetElemFlag, MUSICAL_MCSS_GetElemFlag, MUSICAL_MCSS_GetElemOffset, MUSICAL_MCSS_NoOp5, MUSICAL_MCSS_LoadActorData, MUSICAL_MCSS_FreeActorData, MUSICAL_MCSS_GetElemPtr, MUSICAL_MCSS_GetOffset, MUSICAL_MCSS_NoOp6, MUSICAL_MCSS_SetModeA, MUSICAL_MCSS_SetModeB, MUSICAL_MCSS_SetModeC, MUSICAL_MCSS_GetStateA, MUSICAL_MCSS_GetStateB, MUSICAL_MCSS_GetIndex, MUSICAL_MCSS_GetElemA, MUSICAL_MCSS_GetElemB, MUSICAL_MCSS_GetElemC, MUSICAL_MCSS_CreateRenderObj, MUSICAL_MCSS_DeleteRenderObj, MUSICAL_MCSS_TickAnim, MUSICAL_MCSS_DrawRenderObj, MUSICAL_MCSS_SetupRenderObj, MUSICAL_MCSS_FreeRenderObj, MUSICAL_MCSS_GetRenderPos, MUSICAL_MCSS_GetRenderRot, MUSICAL_MCSS_SetRenderFrame, MUSICAL_MCSS_SetRenderMode, MUSICAL_MCSS_GetRenderHandle, MUSICAL_MCSS_GetRenderFieldA, MUSICAL_MCSS_GetRenderFieldB, MUSICAL_MCSS_SetRenderAnim, MUSICAL_MCSS_ResetRender, MUSICAL_MCSS_ResetRender2, MUSICAL_MCSS_GetRenderSize, MUSICAL_MCSS_SetRenderFieldA, MUSICAL_MCSS_SetRenderFieldB, MUSICAL_MCSS_GetRenderElem, MUSICAL_MCSS_GetRenderFlags, MUSICAL_MCSS_GetRenderMatrix, MUSICAL_MCSS_SetMatrix, MUSICAL_MCSS_GetPokemonArcs, MUSICAL_MCSS_AllocRenderPool, MUSICAL_MCSS_FreeRenderPool, MUSICAL_MCSS_TickMCAnim, MUSICAL_MCSS_DrawMC, MUSICAL_MCSS_DrawSprite, MUSICAL_MCSS_LoadMC, MUSICAL_MCSS_FreeMC, MUSICAL_MCSS_NoOp7, MUSICAL_MCSS_SetFieldA, MUSICAL_MCSS_SetFieldB, MUSICAL_MCSS_GetFieldA, MUSICAL_MCSS_GetFieldB, MUSICAL_MCSS_SetFieldC, MUSICAL_MCSS_GetFieldC, MUSICAL_MCSS_GetFieldD, MUSICAL_MCSS_GetFieldE, MUSICAL_MCSS_GetFieldF, MUSICAL_MCSS_SetMCAnim, MUSICAL_MCSS_GetFieldG, MUSICAL_MCSS_NoOp8, MUSICAL_MCSS_NoOp9, MUSICAL_MCSS_CopyField, MUSICAL_MCSS_LoadCellBank, MUSICAL_MCSS_FreeCellBank, MUSICAL_MCSS_InitMCAnim, MUSICAL_MCSS_SetupG3, MUSICAL_MCSS_CalcMatrix, MUSICAL_MCSS_GetMonValue, MUSICAL_MCSS_CreateMon, MUSICAL_MCSS_AllocMon, MUSICAL_MCSS_AllocSmall, MUSICAL_MCSS_FreeMon, MUSICAL_MCSS_LoadDistSave
 * address:  0x021F40D0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F8264 0x021F8264 data a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02049B40 0x02049B40 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_SetString 0x02045924 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02030734 0x02030734 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021F8394 0x021F8394 data a1
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   func_020307B0 0x020307B0 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   MUSICAL_SAVE_NoOp 0x0200A640 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   MUS_COMM_FUNC_SetTimingSync 0x021FCDEC thumb ov132
 *   MUS_COMM_FUNC_CheckTimingSync 0x021FCE00 thumb ov132
 *   func_0200FB24 0x0200FB24 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   TCBL_Main 0x020310C4 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   d_021F8290 0x021F8290 data a1
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   d_021F8298 0x021F8298 data a4
 *   d_021F82B8 0x021F82B8 data a4
 *   d_021F82D8 0x021F82D8 data a4
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   TCBL_Create 0x0203101C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   d_021F83A4 0x021F83A4 data a1
 *   NNS_GfdResetVramTransferTaskQueue 0x02061C30 arm
 *   BILLBOARD_SetElemPos 0x0204F638 arm
 *   BILLBOARD_SetElemScale 0x0204F684 arm
 *   BILLBOARD_SetElemRotZ 0x0204F7C4 arm
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   ARC_TOOL_GetArchiveFileCount 0x02049030 arm
 *   BILLBOARD_GetImageSizeFromFlags 0x0204EDD0 arm
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   BILLBOARD_AddImage 0x0204EF58 arm
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   d_021F8300 0x021F8300 data a4
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   BILLBOARD_ReleaseImageVramIfUsed 0x0204F1A0 arm
 *   BILLBOARD_SetElemId 0x0204F604 arm
 *   BILLBOARD_GetImagePlttVramOffset 0x0204F2CC arm
 *   BILLBOARD_GetImagePlttKey 0x0204F32C arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   d_021F83B4 0x021F83B4 data a1
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021F83C4 0x021F83C4 data a1
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKE_TOOL_NormalizeForm 0x02019D30 thumb
 *   POKE_TOOL_FilterSpecies 0x02019D58 thumb
 *   POKEGRA_GetCbrArcIndex 0x0202D09C thumb
 *   POKEGRA_GetPalArcIndex 0x0202D0D4 thumb
 *   POKEGRA_GetCelArcIndex 0x0202D110 thumb
 *   POKEGRA_GetAnmArcIndex 0x0202D144 thumb
 *   POKEGRA_GetMCelArcIndex 0x0202D178 thumb
 *   POKEGRA_GetMAnmArcIndex 0x0202D1AC thumb
 *   POKEGRA_GetNcecArcIndex 0x0202D1E0 thumb
 *   d_021F83D4 0x021F83D4 data a1
 *   d_02FFFC3C 0x02FFFC3C data a4
 *   NNS_G2dTickMCAnimation 0x020649D4 arm
 *   G3i_LookAt_ 0x0207D7C4 arm
 *   func_0207B67C 0x0207B67C arm
 *   func_02082B60 0x02082B60 arm
 *   MTX_Copy33To44_ 0x0207ADE8 arm
 *   MTX_Copy43To44_ 0x0207B5C0 arm
 *   func_0207BE14 0x0207BE14 arm
 *   func_0207C768 0x0207C768 arm
 *   func_0207D8FC 0x0207D8FC arm
 *   G3_RotZ 0x0207D888 arm
 *   func_0207AF38 0x0207AF38 thumb
 *   MTX_MultVec33 0x0207B51C arm
 *   VEC_Subtract 0x0207CA00 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   d_02148D8C 0x02148D8C data
 *   d_02148D98 0x02148D98 data
 *   d_02148DA4 0x02148DA4 data
 *   d_021F8310 0x021F8310 data ov112
 *   d_021F831C 0x021F831C data ov112
 *   d_021F8304 0x021F8304 data ov112
 *   d_02148B98 0x02148B98 data
 *   d_02148B54 0x02148B54 data
 *   G3i_OrthoW_ 0x0207D760 arm
 *   NNS_G2dGetAnimSequenceByIdx 0x020627D8 arm
 *   NNS_G2dSetAnimSequenceToMCAnimation 0x0206469C arm
 *   NNSi_G2dInitVramHandle 0x02063790 arm
 *   NNSi_G2dInitVramHandleEx 0x020637D4 arm
 *   ARC_UTIL_LoadCellBankFromArchive 0x02049FBC arm
 *   ARC_UTIL_LoadMultiCellBankFromArchive 0x0204A03C arm
 *   ARC_UTIL_LoadAnimBankFromArchive 0x0204A0BC arm
 *   ARC_UTIL_LoadMultiAnimBankFromArchive 0x0204A13C arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   func_02049DB4 0x02049DB4 arm
 *   func_02049F34 0x02049F34 arm
 *   MCSS_TOOL_DrawSpindaSpots 0x020172D8 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   NNSi_G2dLoadVramResourceSub 0x02063A54 arm
 *   NNSi_G2dLoadVramResourceBySel 0x02063E54 arm
 *   NNS_G2dGetMCWorkAreaSize 0x020648B4 arm
 *   NNS_G2dInitMCAnimation 0x02064754 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_IsShiny 0x02017EAC thumb
 *   d_021F83E4 0x021F83E4 data a4
 *   MUSICAL_DIST_SAVE_Create 0x0200C52C thumb
 *   MUSICAL_DIST_SAVE_GetPayload 0x0200C6D8 thumb
 *   MUSICAL_DIST_SAVE_GetPayloadSize 0x0200C6DC thumb
 *   MUSICAL_DIST_SAVE_Delete 0x0200C5A4 thumb
 *   ARC_TOOL_CreateHandleFromMemory 0x0204913C arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   ARC_TOOL_GetHandleMemberSize 0x020493D4 arm
 *   ARC_TOOL_ReadHandleMember 0x0204932C arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb  arm9
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   TIME_ICON_Delete  0x0202F038  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 */

#define REG(a) (*(volatile u32 *)(a))
#define SLOT (*(char ***)(a+4))[i]
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
struct Strbuf;
struct TaskMenuRes;
struct Bank;
struct Obj;
struct TaskMenuState;
struct Actor;
struct PrintSys;
struct Rec3;
struct TaskMenu;
struct Tcbl;
struct BgTemplate;
struct S02031140;
struct TaskMenuTmpl;
struct Manager0204F684;
struct Tagged;
struct Desc;
struct Board;
struct Vec3;
struct BbBoard;
struct AnimBank;
struct AnimSequence;
struct Node;
struct Out;
struct Res;
struct ArcFile;
struct Blk2C;
struct MusicalDist;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 words[4]; } Quad;

typedef signed short s16_021F40F4;

typedef struct { u32 pad:9; u32 a:7; u32 b:5; u32 c:6; u32 tail:5; } Input_021F40D0;

typedef short s16_021F4280;

typedef signed char s8;

typedef int s32_021F40D0;

typedef struct { u16 v; u16 pad; } H16;

typedef struct { u8 b[8]; } Box;

typedef struct { u16 x,y,z; u8 a,b; } Desc;

typedef signed int     s32_021F44F8;

typedef struct Item { void *data; u16 value; u16 pad; int zero; } Item;

typedef struct Menu { u32 heap; u8 count; u8 pad[3]; Item *items; int zero; u8 a,b,c,d; } Menu;

typedef short s16;

typedef struct Record_021F48C0 { u16 active:1; u16 enabled:1; u16 rest:14; u8 data[34]; } Record_021F48C0;

typedef struct { u16 flags,zero; u32 id,index,type; int x,y,z; s16 a,b; u8 *data; } Entry_021F4B10;

typedef struct Object_021F48C0 { u16 heap; u16 pad; union { u32 owner; void *board; }; union { Record_021F48C0 *records; Entry_021F4B10 *entries; }; void *resource; u16 count; u16 slots[16]; } Object_021F48C0;

typedef struct Record_021F4948 { u16 active:1; u16 rest:15; u8 data[34]; } Record_021F4948;

#include "musical_shot_types.h"

typedef union {
    u16 value;
    struct { u16 active:1, dirty:1, rotate:1, rest:13; } bits;
} Flags_021F40D0;

typedef struct { Flags_021F40D0 flags; u16 angle; u32 id,index,type; int x,y,z; s16 a,b; u8 *data; } Entry_021F40D0;

typedef struct { u32 pad; u8 *board; Entry_021F40D0 *entries; u8 *table; u16 count; } Object_021F4990;

typedef struct { int x,y; } Offset_021F40D0;

typedef struct { u8 x,y; s16 b,a; } Scale;

struct Trip { u32 a,b,c; };

typedef int s32;


typedef struct { u8 x,y; } Pair;

typedef short s16_021F4C94;

typedef signed int     s32_021F4C94;


typedef struct { u32 pad; void *board; Entry_021F4B10 *entries; } Object_021F4C94;

typedef short s16_021F4D40;

typedef struct { u16 low:4; u16 bit4:1; u16 rest:11; } Bits_021F4D40;

typedef struct { u16 low:3; u16 bit3:1; u16 bit4:1; u16 rest:11; } Bits_021F4D74;

typedef struct { u16 low:3; u16 bit3:1; u16 rest:12; } Bits_021F4DE0;

typedef signed int     s32_021F4DE0;

typedef signed short s16_021F4E2C;

typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags_021F4E2C;

typedef short s16_021F4E6C;

typedef short s16_021F4E8C;

typedef struct { u16 flags,zero; u32 id,index,type; int x,y,z; s16_021F4E8C a,b; u8 *data; } Entry_021F4E8C;

typedef short s16_021F4EA4;

typedef short s16_021F4EB4;

typedef short s16_021F4EC4;

typedef short s16_021F4ED4;

typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags_021F4EE8;

typedef struct { u16 lo : 2; u16 flag : 1; u16 hi : 13; } Flags_021F4EFC;

typedef struct { int x, y; } Offset_021F4C94;

typedef short s16_021F4F10;

typedef int s32_021F4F10;

typedef short s16_021F4F54;

typedef int s32_021F4F54;

typedef struct { int f0, f4, active; } Fields;

typedef struct { u32 value; u8 pad[52]; } Track;

typedef struct {
    u32 active, enabled;
    u8 *object;
    char *primary, *secondary;
    Track tracks[9];
    u32 f524, f528, f532, f536, f540, f544, f548, f552;
} Slot;

/* The render object (allocated 4456 bytes by CreateRenderObj): a halfword heap
   id, then the render pool pointer and 8 slots. heap is stored as a u16. */
typedef struct { u16 heap; u16 pad_2; char *main; Slot slots[8]; } Scene;

typedef struct { u32 stats[9]; int scale[3]; } Buffers;

typedef short s16_021F53D8;

typedef short s16_021F5450;

typedef short s16_021F545C;

typedef struct { int x,y,z; } Vec_021F56BC;

typedef struct { Vec_021F56BC a,b,c,d; u16 e,f; } Input_021F53CC;

typedef struct { int pad[5]; u32 tracks[126]; /* 9 tracks of 0x38 bytes */ Vec_021F56BC t[2]; int flag[2]; } Big;

typedef struct { u32 low:1; u32 paused:1; u32 rest:30; } Flags_021F53CC;

typedef signed short   s16_021F56BC;

typedef long long      s64;

typedef struct {
    u16 id;
    u16 rot;
    int sx;
    int sy;
    s16_021F56BC dx;
    s16_021F56BC dz;
} Pose;

typedef struct {
    u32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C;
    u8 parts[8];
} Ent;

typedef struct {
    u32 f0;
    u32 f4;
    int x;
    int z;
    u32 f10;
} Part;

typedef struct {
    u16 f0;
    s16_021F56BC x;
    s16_021F56BC z;
    u16 h;
} TabEnt;

typedef struct {
    u16 count;
    u16 pad;
    TabEnt *ents;
} Tab;

typedef struct {
    int w;
    int z;
    Input_021F53CC in;
} CB;

typedef struct { int m[12]; } Mtx43;

typedef struct { int m[16]; } Mtx44;

typedef struct { int m[9]; } Mtx33;

typedef struct { u32 b0 : 1; u32 rest : 31; } Bits_021F53CC;

typedef struct { u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 rest : 29; } Bits3;

typedef struct { u16 id; u16 pad; s16_021F56BC dx; s16_021F56BC dz; } PoseSrc;

typedef struct { u32 addr; u32 f04; u32 f08; u32 s; u32 t; u32 fmt; u32 f18; u32 pltt0; } TexInfo;

typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;

typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;

typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;

typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;

typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;

typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;

typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;

/* The sprite set reached as obj+0x6C; its Tab table sits at 0x4. */
struct McssSpriteSet { int p0; Tab *tbl; };

typedef struct { u32 a:1,b:1,c:1,rest:29; } Flags;

typedef struct { int x,y,z; } Vec;

/* Three int components; BILLBOARD_AddElem takes a struct Vec3 *. */
struct Vec3 { int x, y, z; };

typedef struct { char pad[200]; Vec a,b,c; u32 b0:1,b1:1,b2:1,rest:29; char pad2[12]; u16 h,pad3; Vec d,e; } Object;

typedef unsigned long long u64;

/* A word used both as a pointer handle and as a raw integer by different views. */
typedef union { void *ptr; u32 val; } McssPtrWord;

/*
 * The MUSICAL_MCSS work object. MUSICAL_MCSS_Create allocates 0x5C bytes for it.
 * Main, Delete, CreateUnits, InitWindows, DeleteWindows, PrintStream, PrintQue
 * and OpenMenu all read this one record.
 */
typedef struct MusicalMcssWork {
    u16 heap;               /* 0x00 */
    u16 pad_2;              /* 0x02 */
    u32 state;              /* 0x04 */
    u8 counter;             /* 0x08 */
    u8 pad_9[3];            /* 0x09 */
    u32 mode;               /* 0x0C */
    void *src;              /* 0x10 */
    void *dst;              /* 0x14 */
    McssPtrWord tcbl;       /* 0x18 text control block handle */
    McssPtrWord win;        /* 0x1C window bitmap */
    McssPtrWord font;       /* 0x20 */
    McssPtrWord printStream;/* 0x24 */
    McssPtrWord msgBank;    /* 0x28 */
    McssPtrWord strbuf;     /* 0x2C */
    u32 queActive;          /* 0x30 */
    McssPtrWord timeIcon;   /* 0x34 */
    McssPtrWord printQue;   /* 0x38 */
    void *taskMenu;         /* 0x3C */
    u32 taskMenuRes;        /* 0x40 */
    void *musComm;          /* 0x44 */
    void *unit;             /* 0x48 */
    u32 palette;            /* 0x4C */
    u32 character;          /* 0x50 */
    u32 cellAnim;           /* 0x54 */
    void *actor;            /* 0x58 */
} MusicalMcssWork;

typedef char MusicalMcssWork_size_check[(sizeof(MusicalMcssWork) == 0x5C) ? 1 : -1];

/*
 * The render pool (allocated 28 bytes by MUSICAL_MCSS_AllocRenderPool). Holds
 * the child MC anim pointers and the VRAM bases for the cell and anim banks.
 * cellVram/animVram start as 3<<16 and 1<<12 and are rewritten by
 * MUSICAL_MCSS_SetRenderFieldA/SetRenderFieldB.
 */
typedef struct McssRenderPool {
    int count;              /* 0x00 number of child slots */
    void **children;        /* 0x04 child MC anim pointers */
    u32 flags;              /* 0x08 bit 0 set by MUSICAL_MCSS_NoOp7 */
    u32 cellVram;           /* 0x0C cell bank VRAM base */
    u32 animVram;           /* 0x10 anim bank VRAM base */
    u32 heap;               /* 0x14 heap id */
    u32 lastTick;           /* 0x18 last tick timestamp */
} McssRenderPool;

typedef char McssRenderPool_size_check[(sizeof(McssRenderPool) == 0x1C) ? 1 : -1];

/*
 * A child MC animation instance (allocated 292 bytes by MUSICAL_MCSS_LoadMC).
 * 0x00..0x24 are resource handles, 0x28 is the embedded NNS MC animation,
 * 0x8C is the NNS work area and the tail holds per-child state words.
 */
typedef struct McssMcAnim {
    void *cellBank;         /* 0x00 */
    int cellBankArg;        /* 0x04 passed to NNS_G2dInitMCAnimation */
    void *animBank;         /* 0x08 */
    void *cellArg;          /* 0x0C passed to NNS_G2dInitMCAnimation */
    void *multiCellBank;    /* 0x10 */
    void *field14;          /* 0x14 passed to NNS_G2dInitMCAnimation */
    void *multiAnimBank;    /* 0x18 */
    void *animSequenceBank; /* 0x1C */
    void *cellTable;        /* 0x20 */
    void *field24;          /* 0x24 */
    u8 pad_28[0x64];        /* 0x28 embedded NNS MC animation */
    void *workArea;         /* 0x8C NNS MC work area */
    u8 pad_90[0x38];        /* 0x90 */
    int fieldC8;            /* 0xC8 MUSICAL_MCSS_GetFieldA[0] */
    int fieldCC;            /* 0xCC MUSICAL_MCSS_GetFieldA[1] */
    int fieldD0;            /* 0xD0 MUSICAL_MCSS_GetFieldA[2] */
    int fieldD4;            /* 0xD4 MUSICAL_MCSS_GetFieldB[0] */
    int fieldD8;            /* 0xD8 MUSICAL_MCSS_GetFieldB[1] */
    int fieldDC;            /* 0xDC MUSICAL_MCSS_GetFieldB[2] */
    u8 pad_E0[0x0C];        /* 0xE0 */
    u32 flags;              /* 0xEC MC anim state bits */
    u32 childIndex;         /* 0xF0 index in the render pool */
    u32 heapTag;            /* 0xF4 heap tag */
    void *ownerSlot;        /* 0xF8 slot passed to MUSICAL_MCSS_LoadMC */
    u16 frame;              /* 0xFC MUSICAL_MCSS_SetFieldC */
    u8 pad_FE[0x26];        /* 0xFE */
} McssMcAnim;

typedef char McssMcAnim_size_check[(sizeof(McssMcAnim) == 0x124) ? 1 : -1];

/* The mon record (allocated 124 bytes by MUSICAL_MCSS_CreateMon/AllocMon). */
typedef struct McssMon {
    u32 kind;               /* 0x00 = 4 */
    void *source;           /* 0x04 source pokemon */
    u16 species;            /* 0x08 */
    u8 form;                /* 0x0A */
    u8 fieldB;              /* 0x0B */
    u8 fieldC;              /* 0x0C */
    u8 pad_D[3];            /* 0x0D */
    u32 field10;            /* 0x10 */
    u16 slots[9][3];        /* 0x14 9 records of 6 bytes */
    u16 field4A;            /* 0x4A */
    u8 pad_4C[8];           /* 0x4C */
    u32 values[9];          /* 0x54 */
    u16 field78;            /* 0x78 */
    u8 pad_7A[2];           /* 0x7A */
} McssMon;

typedef char McssMon_size_check[(sizeof(McssMon) == 0x7C) ? 1 : -1];

/* The MUSICAL_MCSS_LoadDistSave object: four loaded ARC members at 0x04..0x10. */
typedef struct McssDistSave {
    u8 kind;                /* 0x00 */
    u8 pad_1[3];            /* 0x01 */
    void *member0;          /* 0x04 */
    void *member1;          /* 0x08 */
    void *member2;          /* 0x0C */
    void *member3;          /* 0x10 */
} McssDistSave;

/* A 12-byte element data record (MUSICAL_MCSS_GetElemPtr stride 0x0C). */
typedef struct McssElemData {
    u32 field0;             /* 0x00 */
    s8 offsetX;             /* 0x04 MUSICAL_MCSS_GetOffset x */
    s8 offsetY;             /* 0x05 MUSICAL_MCSS_GetOffset y */
    u16 flags;              /* 0x06 MUSICAL_MCSS_GetStateA/B bits */
    u8 field8;              /* 0x08 MUSICAL_MCSS_GetElemC */
    u8 field9;              /* 0x09 MUSICAL_MCSS_GetElemA */
    u8 fieldA;              /* 0x0A MUSICAL_MCSS_GetElemB */
    u8 fieldB;              /* 0x0B */
} McssElemData;

typedef char McssElemData_size_check[(sizeof(McssElemData) == 0x0C) ? 1 : -1];

/* The 8-byte actor data wrapper returned by MUSICAL_MCSS_LoadActorData; both
   words hold the loaded elem table. */
typedef struct McssActorData {
    void *handle;           /* 0x00 */
    void *table;            /* 0x04 MUSICAL_MCSS_GetElemPtr base */
} McssActorData;

typedef char McssActorData_size_check[(sizeof(McssActorData) == 0x08) ? 1 : -1];

/* The multi-cell bank loaded by MUSICAL_MCSS_LoadCellBank: a count at 0x00 and
   56-byte cell entries at 0x04. */
typedef struct McssMultiCellBank {
    u32 count;              /* 0x00 */
} McssMultiCellBank;

/* The resource passed to MCSS_TOOL_DrawSpindaSpots (job[0]); a pointer at 0x14. */
typedef struct McssSpindaRes {
    u8 pad_0[0x14];         /* 0x00 */
    void *spots;            /* 0x14 */
} McssSpindaRes;

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintColor(void *,s16_021F40F4,s16_021F40F4,void *,void *,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BG_SYS_PushTile(u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct TaskMenuRes *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern u32 func_020307B0(void *p);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 WIPE_SYS_EndCheck(void);
extern void APP_TASKMENU_UpdateMenu(void *);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void *MUSICAL_SAVE_NoOp(void *);
extern void MI_CpuCopy8(const void *,void *,u32);
extern void MUS_COMM_FUNC_SetTimingSync(int,int);
extern int MUS_COMM_FUNC_CheckTimingSync(char *p, int id);
extern u32 func_0200FB24(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern u32 PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern u8 *TIME_ICON_CreateNode(u32,void *,u8,u8,u16);
extern void TCBL_Main(struct Tcbl *p);
extern void BG_SYS_ResetSlot(u32,u32,u32);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern s32_021F44F8 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern s32_021F44F8 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
extern s32_021F44F8 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void BG_SYS_FreeSlot(u32);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void GF_FONT_SetDefaultTextColor(u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void TIME_ICON_Delete(u8 *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
extern signed char MSG_SPEED_GetWait(void);
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void NNS_GfdResetVramTransferTaskQueue(void);
extern void BILLBOARD_SetElemPos(u8 *,int,struct Trip *);
extern void BILLBOARD_SetElemScale(struct Manager0204F684 *,int,const s16 *,const s16 *);
extern void BILLBOARD_SetElemRotZ(u8 *,int,u16 *);
extern u32 ARC_TOOL_GetArchiveFileCount(u32 a);
extern void BILLBOARD_GetImageSizeFromFlags(int,u16 *,u16 *);
extern void *G3D_SYSTEM_CreateResourceArc(u32,u32);
extern void func_02046EFC(struct Tagged *p);
extern u32 BILLBOARD_AddImage(struct Desc *desc, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern s32_021F4C94 BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void BILLBOARD_SetElemVisible(void *,u32,u32 *);
extern void BILLBOARD_FreeElem(void *,u32);
extern void BILLBOARD_ReleaseImageVramIfUsed(struct BbBoard *a0, u32 a1);
extern void BILLBOARD_SetElemId(void *,u32,u16 *);
extern void BILLBOARD_GetImagePlttVramOffset(int p0, int p1, int p2);
extern void BILLBOARD_GetImagePlttKey(int p0, int p1, int p2);
extern s32_021F4DE0 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32_021F4DE0 size);
extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);
extern void *GFL_HEAP_Alloc(u32, u32, int, const char *, u16);
extern void *POKE_TOOL_GetBoxParam(void *p);
extern u32 POKE_TOOL_NormalizeForm(u32, u32);
extern int POKE_TOOL_FilterSpecies(u16 a, int b);
extern int POKEGRA_GetCbrArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetPalArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetCelArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetAnmArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetMCelArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetMAnmArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern int POKEGRA_GetNcecArcIndex(u32,u32,u32,u32,u32,u32,u32);
extern void NNS_G2dTickMCAnimation(char *, int);
extern void G3i_LookAt_(const Vec_021F56BC *a, const Vec_021F56BC *b, const Vec_021F56BC *c, int d, void *e);
extern void func_0207B67C(const Mtx43 *a, Mtx43 *m);
extern void func_02082B60(Mtx43 *a, Mtx33 *b);
extern void MTX_Copy33To44_(Mtx33 *a, Mtx44 *b);
extern void MTX_Copy43To44_(const Mtx43 *src, Mtx44 *dst);
extern void func_0207BE14(const Mtx44 *a, const Mtx44 *b, Mtx44 *ab);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_0207D8FC(Mtx44 *m);
extern void G3_RotZ(int s, int c);
extern void func_0207AF38(Mtx33 *m, int s, int c);
extern void MTX_MultVec33(void *v, Mtx33 *m, void *out);
extern void VEC_Subtract(void *a, void *b, void *c);
extern void G3i_OrthoW_(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern struct AnimSequence *NNS_G2dGetAnimSequenceByIdx(struct AnimBank *bank, u32 idx);
extern void NNS_G2dSetAnimSequenceToMCAnimation(void *,void *);
extern void NNSi_G2dInitVramHandle(u32 *);
extern void NNSi_G2dInitVramHandleEx(u32 *);
extern void *ARC_UTIL_LoadCellBankFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *ARC_UTIL_LoadMultiCellBankFromArchive(u32,u32,u32,u32,u16);
extern void *ARC_UTIL_LoadAnimBankFromArchive(u32,u32,u32,u32,u16);
extern void *ARC_UTIL_LoadMultiAnimBankFromArchive(u32,u32,u32,u32,u16);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void MCSS_TOOL_DrawSpindaSpots(u8 *,u32);
extern void *func_020056A0(u32,u32,u32);
extern void func_02030EAC(struct Node *n);
extern void NNSi_G2dLoadVramResourceSub(struct Res *r, u32 dst, int mode, struct Out *out);
extern void NNSi_G2dLoadVramResourceBySel(void *,void *,int,void *);
extern int NNS_G2dGetMCWorkAreaSize(u32,u32);
extern void NNS_G2dInitMCAnimation(char *,char *,void *,int,void *,int);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u32 POKE_TOOL_IsShiny(void *);
extern struct MusicalDist *MUSICAL_DIST_SAVE_Create(void *sys, u32 heap);
extern u32 MUSICAL_DIST_SAVE_GetPayload(struct Blk2C *p);
extern u32 MUSICAL_DIST_SAVE_GetPayloadSize(struct Blk2C *p);
extern void *ARC_TOOL_CreateHandleFromMemory(void *a0, u32 a1, u32 heap);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void ARC_TOOL_ReadHandleMember(struct ArcFile *arc, u32 member, void *dst);
extern void MUSICAL_DIST_SAVE_Delete(struct MusicalDist *p);
u32 MUSICAL_MCSS_SetObjectValue(void *p,u32 i,u16 c);
void MUSICAL_MCSS_DrawLabel(u8 *p);
void MUSICAL_MCSS_NoOp(u8 *a0);
void *MUSICAL_MCSS_Create(u32 a, u32 b, u32 c, u32 d, H16 heap);
void MUSICAL_MCSS_Delete(u8 *p);
void MUSICAL_MCSS_Main(u8 *p);
int MUSICAL_MCSS_NoOp2(u32 *p);
void MUSICAL_MCSS_CreateUnits(u8 *p);
void MUSICAL_MCSS_InitBg(const void *a,u32 b,u32 c);
void MUSICAL_MCSS_InitWindows(u8 *p);
void MUSICAL_MCSS_DeleteWindows(u8 *p);
void MUSICAL_MCSS_PrintStream(u8 *p,u32 index);
void MUSICAL_MCSS_PrintQue(u8 *p,u32 index);
void MUSICAL_MCSS_OpenMenu(u8 *p);
Object_021F48C0 *MUSICAL_MCSS_CreateActorPool(u32 owner,int count,u16 heap);
void MUSICAL_MCSS_DeleteActorPool(u8 *p);
void MUSICAL_MCSS_UpdateObject(Object_021F4990 *p);
void MUSICAL_MCSS_NoOp3(void *a0);
u16 MUSICAL_MCSS_GetArcFileCount(int i);
void MUSICAL_MCSS_SetupObject(u8 *p,u8 *a,u8 *b);
int MUSICAL_MCSS_SetIndexA(u8 *p, int index);
int MUSICAL_MCSS_SetIndexB(u8 *p,int index,int mode);
int MUSICAL_MCSS_SetIndexC(u8 *p,int index,int mode);
int MUSICAL_MCSS_GetFlagA(u8 *p);
int MUSICAL_MCSS_GetFlagB(u8 *p);
void *MUSICAL_MCSS_CreateResourceArc(int type);
void MUSICAL_MCSS_FreeResourceArc(struct Tagged *a0);
u16 MUSICAL_MCSS_NoOp4(u32 p);
Entry_021F4B10 *MUSICAL_MCSS_AddImage(Object_021F48C0 *p,int type,u32 id,int *v);
Entry_021F4B10 *MUSICAL_MCSS_AddImageNoVram(Object_021F48C0 *p, int type, u32 id, int *v);
Entry_021F4B10 *MUSICAL_MCSS_AddElem(Object_021F4C94 *p, u16 index, int *v, s16_021F4C94 a, s16_021F4C94 b);
void MUSICAL_MCSS_FreeElem(u8 *p,u8 *e);
void MUSICAL_MCSS_FreeElemImage(u8 *p, u8 *e, int type, u16 id);
void MUSICAL_MCSS_TransferVram(char *p, char *e, void *a2);
void MUSICAL_MCSS_CopyElem(void *unused, u8 *s, u8 *d);
void MUSICAL_MCSS_SetElemVisible(u8 *p,u8 *e,u32 value);
void MUSICAL_MCSS_SetElemPos(u32 unused,Entry_021F4E8C *p,const int *q);
void MUSICAL_MCSS_SetElemScale(u32 unused,u32 p,u32 q);
void MUSICAL_MCSS_SetElemRotZ(u32 unused,u32 p,s16_021F4EB4 a,s16_021F4EB4 b);
void MUSICAL_MCSS_SetElemRot(u32 unused,u32 p,s16_021F4EC4 *a,s16_021F4EC4 *b);
void MUSICAL_MCSS_SetElemField(u32 unused,u32 p,u16 v);
void MUSICAL_MCSS_GetElemField(int unused, u16 *p, u16 *out);
void MUSICAL_MCSS_SetElemFlag(int unused,Flags_021F4EE8 *s,int flag);
int MUSICAL_MCSS_GetElemFlag(int unused, Flags_021F4EFC *p);
void MUSICAL_MCSS_GetElemOffset(u8 *p, Offset_021F4C94 *out);
u32 MUSICAL_MCSS_NoOp5(u8 *p);
u32 *MUSICAL_MCSS_LoadActorData(int heap);
void MUSICAL_MCSS_FreeActorData(void **p);
u8 *MUSICAL_MCSS_GetElemPtr(u8 *p, int i);
void MUSICAL_MCSS_GetOffset(u8 *p, Offset_021F4C94 *out);
int MUSICAL_MCSS_NoOp6(int *p);
int MUSICAL_MCSS_SetModeA(u16 *p, int mode);
int MUSICAL_MCSS_SetModeB(u16 *p, int mode);
int MUSICAL_MCSS_SetModeC(u8 *p, int mode);
int MUSICAL_MCSS_GetStateA(const unsigned char *p);
int MUSICAL_MCSS_GetStateB(const unsigned char *p);
int MUSICAL_MCSS_GetIndex(unsigned index);
unsigned char MUSICAL_MCSS_GetElemA(void *p, int i);
unsigned char MUSICAL_MCSS_GetElemB(void *p, int i);
unsigned char MUSICAL_MCSS_GetElemC(void *p, int i);
void *MUSICAL_MCSS_CreateRenderObj(u32 heap);
void MUSICAL_MCSS_DeleteRenderObj(int a);
void MUSICAL_MCSS_TickAnim(u8 *p);
void MUSICAL_MCSS_DrawRenderObj(void **p);
u8 *MUSICAL_MCSS_SetupRenderObj(Scene *p,const u8 *b,int c);
void MUSICAL_MCSS_FreeRenderObj(int a, int b);
void MUSICAL_MCSS_GetRenderPos(int *p, int *q);
void MUSICAL_MCSS_GetRenderRot(int *p, int *q);
void MUSICAL_MCSS_SetRenderFrame(int *p, unsigned short v);
void MUSICAL_MCSS_SetRenderMode(int *p,int b);
int MUSICAL_MCSS_GetRenderHandle(u8 **p);
void MUSICAL_MCSS_GetRenderFieldA(void **p);
void MUSICAL_MCSS_GetRenderFieldB(int a);
void MUSICAL_MCSS_SetRenderAnim(int a, u32 n);
void MUSICAL_MCSS_ResetRender(int a);
void MUSICAL_MCSS_ResetRender2(int a,int b);
void MUSICAL_MCSS_GetRenderSize(int a0, int a1);
void MUSICAL_MCSS_SetRenderFieldA(void **p,int b);
void MUSICAL_MCSS_SetRenderFieldB(u8 *p, int a);
u8 *MUSICAL_MCSS_GetRenderElem(u8 *p, int i);
u8 *MUSICAL_MCSS_GetRenderFlags(u8 *p);
char *MUSICAL_MCSS_GetRenderMatrix(char *p);
void MUSICAL_MCSS_SetMatrix(unsigned mode, Input_021F53CC *in, Big *p);
void MUSICAL_MCSS_GetPokemonArcs(u8 *p, u32 *out, u32 k);
void *MUSICAL_MCSS_AllocRenderPool(int count, u32 heap);
void MUSICAL_MCSS_FreeRenderPool(char *p);
void MUSICAL_MCSS_TickMCAnim(char *p);
void MUSICAL_MCSS_DrawMC(int *p, void (*arg)(unsigned, Input_021F53CC *, Big *));
void MUSICAL_MCSS_DrawSprite(char *p, int a1, int a2, int a3, int a4, int a5, int a6, Pose *s, u16 *pa, int a9, int flag, int *pz, u8 mode);
char *MUSICAL_MCSS_LoadMC(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g);
void MUSICAL_MCSS_FreeMC(char *a, char *p);
void MUSICAL_MCSS_NoOp7(void *p);
void MUSICAL_MCSS_SetFieldA(char *p,int b);
void MUSICAL_MCSS_SetFieldB(u8 *p, int a);
void MUSICAL_MCSS_GetFieldA(char *p, int *q);
void MUSICAL_MCSS_GetFieldB(char *p, int *q);
void MUSICAL_MCSS_SetFieldC(char *p, unsigned short v);
void MUSICAL_MCSS_GetFieldC(u8 *p);
void MUSICAL_MCSS_GetFieldD(u8 *p);
void MUSICAL_MCSS_GetFieldE(u8 *p);
void MUSICAL_MCSS_GetFieldF(char *p);
void MUSICAL_MCSS_SetMCAnim(char *p,u32 n);
u32 MUSICAL_MCSS_GetFieldG(u8 *p);
void MUSICAL_MCSS_NoOp8(char *p);
void MUSICAL_MCSS_NoOp9(char *p);
void MUSICAL_MCSS_CopyField(Object *a,Object *b);
void MUSICAL_MCSS_LoadCellBank(u8 *a,int index,u32 *res,u32 mode);
void MUSICAL_MCSS_FreeCellBank(void *a, void **p);
void MUSICAL_MCSS_InitMCAnim(char *p, int kind);
void MUSICAL_MCSS_SetupG3(void);
void MUSICAL_MCSS_CalcMatrix(const int *p, const int *m, u32 *out, u32 *w);
int MUSICAL_MCSS_GetMonValue(void *p);
char *MUSICAL_MCSS_CreateMon(void *a,u16 heap);
char *MUSICAL_MCSS_AllocMon(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap);
void *MUSICAL_MCSS_AllocSmall(u32 heap);
void MUSICAL_MCSS_FreeMon(char *p);
void MUSICAL_MCSS_LoadDistSave(u8 *p, u32 unused, void *sys, u8 kind, u16 heap);
extern const Quad d_021F8264;
extern char d_021F8394[];
extern const Box d_021F8290;
extern const u32 d_021F8298[];
extern const u32 d_021F82B8[];
extern const u32 d_021F82D8[];
extern char d_021F83A4[];
extern s16 FX_SinCosTable_[];
extern u32 d_021F8300;
extern char d_021F83B4[];
extern const char d_021F83C4[];
extern const char d_021F83D4[];
extern u32 d_02FFFC3C;
extern const Vec_021F56BC d_02148D8C;
extern const Vec_021F56BC d_02148D98;
extern const Vec_021F56BC d_02148DA4;
extern const Vec_021F56BC d_021F8310;
extern const Vec_021F56BC d_021F831C;
extern const Vec_021F56BC d_021F8304;
extern const Mtx43 d_02148B98;
extern const Mtx44 d_02148B54;
extern const char d_021F83E4[];








u32 MUSICAL_MCSS_SetObjectValue(void *p,u32 i,u16 c) { Quad q=d_021F8264; return q.words[i]; }








void MUSICAL_MCSS_DrawLabel(u8 *p)
{
    void *buf;
    void *t;
    void *f;
    void *b;
    ((ShotScene *)p)->winA=(void *)BMP_WIN_Create(1,24,22,8,2,10,1);
    ((ShotScene *)p)->winB=(void *)BMP_WIN_Create(1,1,1,30,2,10,1);
    BMP_Clear(BMP_WIN_GetBmp(((ShotScene *)p)->winA),0);
    BMP_Clear(BMP_WIN_GetBmp(((ShotScene *)p)->winB),0);
    ((ShotScene *)p)->fontA=GF_FONT_Create(23,3,0,0,((ShotScene *)p)->heap);
    ((ShotScene *)p)->fontB=GF_FONT_Create(23,0,0,0,((ShotScene *)p)->heap);
    func_02049B40(23,5,0,320,32,((ShotScene *)p)->heap);
    buf=STRBUF_Create(128,((ShotScene *)p)->heap);
    t=WORDSET_CreateDefault(((ShotScene *)p)->heap);
    f=func_02045B38(0,2,78,((ShotScene *)p)->heap);
    b=func_02045EC0(f,0);
    WORDSET_SetSlotNumber(t,0,(*(Input_021F40D0 * *)&((ShotScene *)p)->record)->a,2,2,1);
    WORDSET_SetSlotNumber(t,1,(*(Input_021F40D0 * *)&((ShotScene *)p)->record)->b,2,2,1);
    WORDSET_SetSlotNumber(t,2,(*(Input_021F40D0 * *)&((ShotScene *)p)->record)->c,2,2,1);
    WORDSET_CopyTaggedText(t,buf,b);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((ShotScene *)p)->winA),0,0,buf,((ShotScene *)p)->fontA,3424);
    STRBUF_Delete(buf);
    STRBUF_Delete(b);
    WORDSET_DeleteStrbufED04(t);
    MSGDATA_Delete(f);
    buf=STRBUF_Create(37,((ShotScene *)p)->heap);
    STRBUF_SetString(buf,(const u16 *)(*(u8 * *)&((ShotScene *)p)->record+356));
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((ShotScene *)p)->winB),0,0,buf,((ShotScene *)p)->fontB,15424);
    STRBUF_Delete(buf);
    BMP_WIN_TransferChars(((ShotScene *)p)->winA);
    BMP_WIN_MakeScreen(((ShotScene *)p)->winA);
    BMP_WIN_TransferChars(((ShotScene *)p)->winB);
    BMP_WIN_MakeScreen(((ShotScene *)p)->winB);
    BG_SYS_PushTile(1);
}









void MUSICAL_MCSS_NoOp(u8 *a0) { }








void *MUSICAL_MCSS_Create(u32 a, u32 b, u32 c, u32 d, H16 heap)
{
    u8 *p = func_02030734(*(u16 *)&heap, 0x5c, 1, d_021F8394, 0x8d);
    *(u16 *)p = *(u16 *)&heap;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x10) = a;
    *(u32 *)(p + 0x14) = b;
    *(u32 *)(p + 0x44) = d;
    *(u32 *)(p + 0x2c) = 0;
    *(u8 *)(p + 8) = 0;
    if (c == 1) *(u32 *)(p + 4) = 0; else *(u32 *)(p + 4) = 1;
    MUSICAL_MCSS_CreateUnits(p);
    MUSICAL_MCSS_InitWindows(p);
    *(u32 *)(p + 0x40) = (u32)APP_TASKMENU_RES_Create(4, 12, *(u32 *)(p + 0x20), *(u32 *)(p + 0x38), *(u16 *)p);
    GFL_NET_RestartWithDefaultTimeout(0, *(u16 *)&heap);
    BG_SYS_SetSubPlaneVisible(16, 1);
    return p;
}








/*
 * extent: trailing two-byte padding at 0x021F434E.
 */
void MUSICAL_MCSS_Delete(u8 *p)
{
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((MusicalMcssWork *)p)->taskMenuRes));
    if (((MusicalMcssWork *)p)->mode==0) {
        CLACT_ReleasePalette(((MusicalMcssWork *)p)->palette);
        CLACT_ReleaseCharacter(((MusicalMcssWork *)p)->character);
        CLACT_ReleaseCellAnim(((MusicalMcssWork *)p)->cellAnim);
        CLACT_DeleteActor((struct Obj *)(((MusicalMcssWork *)p)->actor));
    }
    CLACT_DeleteUnit((struct Bank *)(((MusicalMcssWork *)p)->unit));
    MUSICAL_MCSS_DeleteWindows(p);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(7);
    func_020307B0(p);
}








/*
 * volatile: byte +8 is re-read after the increment at 0x021F44BA.
 * ABI: 0200A640 leaves its incoming pointer in r0; the caller copies that return.
 */
void MUSICAL_MCSS_Main(u8 *p)
{
    u8 v;
    switch (((MusicalMcssWork *)p)->state) {
    case 0:
        ((MusicalMcssWork *)p)->state=1;
        GFL_USE_PlaySeDefaultVolume(1583);
    case 1:
        if(WIPE_SYS_EndCheck()==1) {
            if(((MusicalMcssWork *)p)->mode==1) {
                MUSICAL_MCSS_PrintStream(p,3);
                ((MusicalMcssWork *)p)->state=2;
            } else ((MusicalMcssWork *)p)->state=5;
        }
        break;
    case 2:
        if(!((MusicalMcssWork *)p)->printStream.ptr) {
            MUSICAL_MCSS_OpenMenu(p);
            ((MusicalMcssWork *)p)->state=3;
        }
        break;
    case 3:
        APP_TASKMENU_UpdateMenu(((MusicalMcssWork *)p)->taskMenu);
        if(APP_TASKMENU_IsFinish(((MusicalMcssWork *)p)->taskMenu)==1) {
            v=APP_TASKMENU_GetCursorPos(*(u8 * *)&((MusicalMcssWork *)p)->taskMenu);
            APP_TASKMENU_CloseMenu(((MusicalMcssWork *)p)->taskMenu);
            if(v==0) MI_CpuCopy8(((MusicalMcssWork *)p)->src,MUSICAL_SAVE_NoOp(((MusicalMcssWork *)p)->dst),432);
            if(*(int *)&((MusicalMcssWork *)p)->musComm) {
                ((MusicalMcssWork *)p)->state=4;
                MUS_COMM_FUNC_SetTimingSync(*(int *)&((MusicalMcssWork *)p)->musComm,71);
                MUSICAL_MCSS_PrintQue(p,6);
            } else ((MusicalMcssWork *)p)->state=7;
        } else if(func_0200FB24()!=0) {
            APP_TASKMENU_CloseMenu(((MusicalMcssWork *)p)->taskMenu);
            ((MusicalMcssWork *)p)->state=7;
        }
        break;
    case 4:
        if(MUS_COMM_FUNC_CheckTimingSync(((MusicalMcssWork *)p)->musComm,71)==1) ((MusicalMcssWork *)p)->state=7;
        else if(func_0200FB24()!=0) ((MusicalMcssWork *)p)->state=7;
        break;
    case 5:
        if((KEY_GetTrg()&2)||!TOUCHPANEL_HitTrg(&d_021F8290)) {
            GFL_USE_PlaySeDefaultVolume(1361);
            ((MusicalMcssWork *)p)->state=6;
            CLACT_SetActorAnimSeq(((MusicalMcssWork *)p)->actor,9);
            CLACT_SetActorAutoAnim(((MusicalMcssWork *)p)->actor,1);
        }
        break;
    case 6:
        if(!CLACT_IsActorAnimActive(((MusicalMcssWork *)p)->actor)) ((MusicalMcssWork *)p)->state=7;
        break;
    case 7: break;
    }
    if(((MusicalMcssWork *)p)->printStream.ptr&&PRINTSYS_PrintStreamGetState(((MusicalMcssWork *)p)->printStream.ptr)==2) {
        PRINTSYS_PrintStreamDelete(((MusicalMcssWork *)p)->printStream.ptr);
        ((MusicalMcssWork *)p)->printStream.ptr=0;
    }
    PRINTSYS_QUE_Main(((MusicalMcssWork *)p)->printQue.ptr);
    if(((MusicalMcssWork *)p)->queActive==1&&PRINTSYS_QUE_IsFinished(((MusicalMcssWork *)p)->printQue.ptr)==1) {
        ((MusicalMcssWork *)p)->queActive=0;
        *(u8 * *)&((MusicalMcssWork *)p)->timeIcon.ptr=TIME_ICON_CreateNode(*(u32 *)&((MusicalMcssWork *)p)->tcbl.ptr,((MusicalMcssWork *)p)->win.ptr,15,16,((MusicalMcssWork *)p)->heap);
        BMP_WIN_TransferChars(((MusicalMcssWork *)p)->win.ptr);
    }
    TCBL_Main(((MusicalMcssWork *)p)->tcbl.ptr);
    (*(volatile u8 *)&((MusicalMcssWork *)p)->counter)++;
    if(*(volatile u8 *)&((MusicalMcssWork *)p)->counter>1) {
        *(volatile u8 *)&((MusicalMcssWork *)p)->counter=0;
        BG_SYS_ResetSlot(7,1,1);
        BG_SYS_ResetSlot(7,5,1);
    }
}









int MUSICAL_MCSS_NoOp2(u32 *p) { if(p[1]==7) return 1; return 0; }








/*
 * ABI: 0204B294 returns an Obj pointer, which the original stores at +88.
 */
void MUSICAL_MCSS_CreateUnits(u8 *p)
{
    Desc d;
    void *t;
    u32 v;
    u32 w;
    MUSICAL_MCSS_InitBg(d_021F8298,4,0);
    MUSICAL_MCSS_InitBg(d_021F82B8,6,0);
    MUSICAL_MCSS_InitBg(d_021F82D8,7,0);
    ((MusicalMcssWork *)p)->unit=CLACT_CreateUnit(8,0,((MusicalMcssWork *)p)->heap);
    CLACT_SetUnitDefaultRenderer(((MusicalMcssWork *)p)->unit);
    BG_SYS_SetSubPlaneVisible(16,1);
    t=func_020490F4((unsigned int)46,((MusicalMcssWork *)p)->heap);
    func_02049B68((void *)((u32)t),4,4,0,0,((MusicalMcssWork *)p)->heap);
    func_02049658((void *)((u32)t),7,7,0,0,0,((MusicalMcssWork *)p)->heap);
    func_020498F4((void *)((u32)t),12,7,0,0,0,((MusicalMcssWork *)p)->heap);
    ARC_TOOL_DeleteHandle(t);
    if (((MusicalMcssWork *)p)->mode==0) {
        t=func_020490F4((unsigned int)APP_ICON_GetArchiveId(),((MusicalMcssWork *)p)->heap);
        func_02049B68((void *)((u32)t),APP_ICON_GetStatusAnimFileId(),4,288,32,((MusicalMcssWork *)p)->heap);
        func_02049658((void *)((u32)t),APP_ICON_GetStatusFrameFileId(),6,0,0,0,((MusicalMcssWork *)p)->heap);
        func_020498F4((void *)((u32)t),APP_ICON_GetStatusDataFileId(),6,0,0,0,((MusicalMcssWork *)p)->heap);
        BG_SYS_FillTileMap(6,0,21,32,3,9);
        BG_SYS_PushTile(6);
        ((MusicalMcssWork *)p)->palette=CLACT_RegisterPaletteEx((void *)((u32)t),APP_ICON_GetMoveKindPaletteFileId(),1,0,0,3,((MusicalMcssWork *)p)->heap);
        ((MusicalMcssWork *)p)->character=CLACT_RegisterCharacter((void *)((u32)t),APP_ICON_GetMoveKindAnimFileId(),0,1,((MusicalMcssWork *)p)->heap);
        v=APP_ICON_GetStatusCellFileId(0);
        w=APP_ICON_GetStatusPaletteFileId(0);
        ((MusicalMcssWork *)p)->cellAnim=CLACT_RegisterCellAnim((void *)((u32)t),v,w,((MusicalMcssWork *)p)->heap);
        ARC_TOOL_DeleteHandle(t);
        d.x=232;
        d.y=168;
        d.z=1;
        d.b=0;
        d.a=0;
        ((MusicalMcssWork *)p)->actor=CLACT_CreateActor((void *)*(u32 *)&((MusicalMcssWork *)p)->unit,((MusicalMcssWork *)p)->character,((MusicalMcssWork *)p)->palette,((MusicalMcssWork *)p)->cellAnim,&d,1,((MusicalMcssWork *)p)->heap);
    }
}








void MUSICAL_MCSS_InitBg(const void *a,u32 b,u32 c) { BG_SYS_InitBgLayer(b,a,c); func_02040588(b,1); BG_SYS_FreeSlot(b); BG_SYS_PushTile(b); }








void MUSICAL_MCSS_InitWindows(u8 *p)
{
    int zero;
    ((MusicalMcssWork *)p)->win.val=BMP_WIN_Create(4,1,1,30,4,10,1);
    BMP_WIN_TransferChars((struct Descriptor *)((MusicalMcssWork *)p)->win.val);
    BMP_WIN_MakeScreen((struct Cfg *)(((MusicalMcssWork *)p)->win.val));
    BG_SYS_PushTile(4);
    zero=0;
    ((MusicalMcssWork *)p)->font.val=(u32)GF_FONT_Create(23,0,0,0,((MusicalMcssWork *)p)->heap);
    ((MusicalMcssWork *)p)->msgBank.val=(u32)func_02045B38(0,2,78,((MusicalMcssWork *)p)->heap);
    BMP_MENUWORK_LoadCharAndPltt(4,1,11,0,((MusicalMcssWork *)p)->heap);
    GF_FONT_SetDefaultTextColor(func_02049B40(23,5,4,320,32,((MusicalMcssWork *)p)->heap));
    ((MusicalMcssWork *)p)->tcbl.val=(u32)TCBL_Create(((MusicalMcssWork *)p)->heap,((MusicalMcssWork *)p)->heap,3,256);
    ((MusicalMcssWork *)p)->printStream.val=zero;
    ((MusicalMcssWork *)p)->strbuf.val=zero;
    ((MusicalMcssWork *)p)->queActive=zero;
    ((MusicalMcssWork *)p)->timeIcon.val=zero;
    ((MusicalMcssWork *)p)->printQue.val=PRINTSYS_QUE_Create((void *)(((MusicalMcssWork *)p)->heap));
}








void MUSICAL_MCSS_DeleteWindows(u8 *p)
{
    PRINTSYS_QUE_Clear((struct PrintSys *)(((MusicalMcssWork *)p)->printQue.val));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((MusicalMcssWork *)p)->printQue.val));
    if (*(u8 * *)&((MusicalMcssWork *)p)->timeIcon.ptr) {
        TIME_ICON_Delete(*(u8 * *)&((MusicalMcssWork *)p)->timeIcon.ptr);
        *(u32 *)&((MusicalMcssWork *)p)->timeIcon.ptr=0;
    }
    if (((MusicalMcssWork *)p)->printStream.ptr) PRINTSYS_PrintStreamDelete(((MusicalMcssWork *)p)->printStream.ptr);
    if (((MusicalMcssWork *)p)->strbuf.ptr) STRBUF_Delete(((MusicalMcssWork *)p)->strbuf.ptr);
    MSGDATA_Delete(((MusicalMcssWork *)p)->msgBank.ptr);
    BMP_WIN_Delete(((MusicalMcssWork *)p)->win.ptr);
    GF_FONT_Delete(((MusicalMcssWork *)p)->font.ptr);
    TCBL_Destroy(((MusicalMcssWork *)p)->tcbl.ptr);
}








void MUSICAL_MCSS_PrintStream(u8 *p,u32 index)
{
    u32 t;
    if (((MusicalMcssWork *)p)->printStream.ptr) {
        PRINTSYS_PrintStreamDelete(((MusicalMcssWork *)p)->printStream.ptr);
        *(u32 *)&((MusicalMcssWork *)p)->printStream.ptr=0;
    }
    if (((MusicalMcssWork *)p)->strbuf.ptr) {
        STRBUF_Delete(((MusicalMcssWork *)p)->strbuf.ptr);
        *(u32 *)&((MusicalMcssWork *)p)->strbuf.ptr=0;
    }
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((MusicalMcssWork *)p)->win.ptr)),15);
    ((MusicalMcssWork *)p)->strbuf.ptr=func_02045EC0((struct MsgBank *)(((MusicalMcssWork *)p)->msgBank.val),index);
    t=MSG_SPEED_GetWait();
    *(u32 *)&((MusicalMcssWork *)p)->printStream.ptr=PRINTSYS_PrintStream(*(u32 *)&((MusicalMcssWork *)p)->win.ptr,0,0,*(u32 *)&((MusicalMcssWork *)p)->strbuf.ptr,((MusicalMcssWork *)p)->font.val,t,((MusicalMcssWork *)p)->tcbl.val,2,((MusicalMcssWork *)p)->heap,0);
    BMP_MENUWORK_DrawWindow(((MusicalMcssWork *)p)->win.ptr,1,1,11);
}








void MUSICAL_MCSS_PrintQue(u8 *p,u32 index)
{
    u32 win;
    if (((MusicalMcssWork *)p)->strbuf.ptr) {
        STRBUF_Delete(((MusicalMcssWork *)p)->strbuf.ptr);
        *(u32 *)&((MusicalMcssWork *)p)->strbuf.ptr=0;
    }
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((MusicalMcssWork *)p)->win.ptr)),15);
    ((MusicalMcssWork *)p)->strbuf.ptr=func_02045EC0((struct MsgBank *)(((MusicalMcssWork *)p)->msgBank.val),index);
    win=(u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((MusicalMcssWork *)p)->win.ptr);
    PRINTSYS_PrintQue((struct PrintSys *)(((MusicalMcssWork *)p)->printQue.val),win,0,0,((MusicalMcssWork *)p)->strbuf.ptr,((MusicalMcssWork *)p)->font.val);
    ((MusicalMcssWork *)p)->queActive=1;
    BMP_MENUWORK_DrawWindow(((MusicalMcssWork *)p)->win.ptr,1,1,11);
}








void MUSICAL_MCSS_OpenMenu(u8 *p)
{
    Item items[2];
    Menu menu;
    items[0].data=func_02045EC0((struct MsgBank *)(((MusicalMcssWork *)p)->msgBank.val),4);
    items[1].data=func_02045EC0((struct MsgBank *)(((MusicalMcssWork *)p)->msgBank.val),5);
    items[0].value=0x39e0;
    items[1].value=0x39e0;
    items[0].zero=0;
    items[1].zero=0;
    menu.heap=((MusicalMcssWork *)p)->heap;
    menu.count=2;
    menu.items=items;
    menu.zero=0;
    menu.a=24;
    menu.b=6;
    menu.c=8;
    menu.d=3;
    ((MusicalMcssWork *)p)->taskMenu=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&menu),(void *)(((MusicalMcssWork *)p)->taskMenuRes));
    STRBUF_Delete(items[0].data);
    STRBUF_Delete(items[1].data);
}







Object_021F48C0 *MUSICAL_MCSS_CreateActorPool(u32 owner,int count,u16 heap)
{
    int i=0;
    Object_021F48C0 *p;
    int j;
    p=func_02030734(heap,0x34,0,d_021F83A4,0x55);
    p->records=func_02030734(heap,count*0x24,0,d_021F83A4,0x57);
    p->heap=heap;
    p->count=count;
    p->owner=owner;
    for(;i<p->count;i++) {
        p->records[i].active=0;
        p->records[i].enabled=0;
    }
    p->resource=MUSICAL_MCSS_LoadActorData(heap);
    for(j=0;j<16;j++) p->slots[j]=0x5a56;
    return p;
}







void MUSICAL_MCSS_DeleteActorPool(u8 *p)
{
    int i;
    NNS_GfdResetVramTransferTaskQueue();
    MUSICAL_MCSS_FreeActorData(*(void **)(p+0xc));
    for(i=0;i<*(u16 *)(p+0x10);i++) {
        if ((*(Record_021F4948 **)(p+8))[i].active==1)
            MUSICAL_MCSS_FreeElem(p,(u8 *)(&(*(Record_021F4948 **)(p+8))[i]));
    }
    func_020307B0(*(void **)(p+8));
    func_020307B0(p);
}







/*
 * extent: 276-byte lead plus 4AA4 two-byte return stub; 4AA6 is zero alignment padding.
 * function_starts: 0x021F4AA4
 * lever: bitfield dirty clear retains the hoisted mask; named offset.x keeps trig load order.
 */
void MUSICAL_MCSS_UpdateObject(Object_021F4990 *p)
{
    int i;
    Entry_021F40D0 *e;
    Offset_021F40D0 offset;
    Scale scale;
    struct Trip v;
    int x,y,s,c,ox;
    for(i=0;i<p->count;i++) {
        e=&p->entries[i];
        if(e->flags.bits.active==1 && e->flags.bits.dirty==1) {
            if(e->flags.bits.rotate==1) {
                MUSICAL_MCSS_GetOffset((u8 *)e->data, (Offset_021F4C94 *)&offset);
                if(e->a<0) offset.x *= -1;
                ox=offset.x;
                s=FX_SinCosTable_[(e->angle>>4)*2];
                c=FX_SinCosTable_[(e->angle>>4)*2+1];
                x=ox*c-offset.y*s;
                y=ox*s+offset.y*c;
            } else { x=0; y=0; }
            v.a=(e->x-x)/16;
            v.b=(0xC0000-(e->y-y))/16;
            v.c=e->z;
            BILLBOARD_SetElemPos(p->board,e->index,&v);
            MUSICAL_MCSS_SetupObject((u8 *)e,&scale.y,&scale.x);
            scale.a=e->a*scale.y;
            scale.b=e->b*scale.x;
            BILLBOARD_SetElemScale((struct Manager0204F684 *)p->board,e->index,&scale.a,&scale.b);
            BILLBOARD_SetElemRotZ(p->board,e->index,&e->angle);
            p->entries[i].flags.bits.dirty=0;
        }
    }
}







void MUSICAL_MCSS_NoOp3(void *a0)
{
}







u16 MUSICAL_MCSS_GetArcFileCount(int i)
{
    u32 n = (u16)ARC_TOOL_GetArchiveFileCount(45) - 2;
    if (i >= (int)n) return 100;
    return (u16)i;
}







void MUSICAL_MCSS_SetupObject(u8 *p,u8 *a,u8 *b) { u16 x,y; BILLBOARD_GetImageSizeFromFlags(MUSICAL_MCSS_NoOp6(*(int * *)&((Entry_021F4B10 *)p)->data),&x,&y); *a=(u32)x>>5; *b=(u32)y>>5; }







int MUSICAL_MCSS_SetIndexA(u8 *p, int index)
{
    return MUSICAL_MCSS_SetModeA(*(u16 * *)&((Entry_021F4B10 *)p)->data, index);
}







int MUSICAL_MCSS_SetIndexB(u8 *p,int index,int mode) { return MUSICAL_MCSS_SetModeB((u16 *)MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((Object_021F48C0 *)p)->resource,index),mode); }






int MUSICAL_MCSS_SetIndexC(u8 *p,int index,int mode) { return MUSICAL_MCSS_SetModeC(MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((Object_021F48C0 *)p)->resource,index),mode); }






int MUSICAL_MCSS_GetFlagA(u8 *p) { return MUSICAL_MCSS_GetStateA((const unsigned char *)(((Entry_021F4B10 *)p)->data)); }






int MUSICAL_MCSS_GetFlagB(u8 *p) { return MUSICAL_MCSS_GetStateB((const unsigned char *)(((Entry_021F4B10 *)p)->data)); }






void *MUSICAL_MCSS_CreateResourceArc(int type) { return G3D_SYSTEM_CreateResourceArc(45,MUSICAL_MCSS_GetArcFileCount(type)); }






void MUSICAL_MCSS_FreeResourceArc(struct Tagged *a0) { func_02046EFC(a0); }






u16 MUSICAL_MCSS_NoOp4(u32 p) { u16 n; int i; n=((Object_021F48C0 *)p)->count; for (i=0;i<n;i++) { if (((Object_021F48C0 *)p)->records[i].active==0) break; } if (i==n) return 0; return i; }






Entry_021F4B10 *MUSICAL_MCSS_AddImage(Object_021F48C0 *p,int type,u32 id,int *v)
{
    int index;
    int data;
    Pair pair;
    index=MUSICAL_MCSS_NoOp4((u32)p);
    p->entries[index].type=MUSICAL_MCSS_GetArcFileCount(type);
    p->entries[index].data=MUSICAL_MCSS_GetElemPtr(p->resource,type);
    data=MUSICAL_MCSS_NoOp6((int *)p->entries[index].data);
    MUSICAL_MCSS_SetupObject((u8 *)(&p->entries[index]),&pair.y,&pair.x);
    p->entries[index].id=BILLBOARD_AddImage(p->board,id,0,data,pair.y<<5,pair.x<<5);
    p->entries[index].flags |= 16;
    MUSICAL_MCSS_AddElem((Object_021F4C94 *)p, index, (int *)v, pair.y, pair.x);
    return &p->entries[index];
}






Entry_021F4B10 *MUSICAL_MCSS_AddImageNoVram(Object_021F48C0 *p, int type, u32 id, int *v)
{
    int index;
    Pair pair;
    index=MUSICAL_MCSS_NoOp4((u32)p);
    p->entries[index].type=MUSICAL_MCSS_GetArcFileCount(type);
    p->entries[index].data=MUSICAL_MCSS_GetElemPtr(p->resource,type);
    MUSICAL_MCSS_NoOp6((int *)p->entries[index].data);
    MUSICAL_MCSS_SetupObject((u8 *)(&p->entries[index]),&pair.y,&pair.x);
    p->entries[index].id=id;
    p->entries[index].flags=p->entries[index].flags & ~16;
    MUSICAL_MCSS_AddElem((Object_021F4C94 *)p, index, (int *)v, pair.y, pair.x);
    return &p->entries[index];
}





Entry_021F4B10 *MUSICAL_MCSS_AddElem(Object_021F4C94 *p, u16 index, int *v, s16_021F4C94 a, s16_021F4C94 b)
{
    p->entries[index].index = BILLBOARD_AddElem(p->board,p->entries[index].id,4096,4096,(struct Vec3 *)v,31,0,0);
    BILLBOARD_SetElemVisible(p->board,p->entries[index].index,&d_021F8300);
    p->entries[index].flags = (p->entries[index].flags & ~1) | 1;
    p->entries[index].flags |= 2;
    p->entries[index].flags |= 4;
    p->entries[index].flags = p->entries[index].flags & ~8;
    p->entries[index].x = v[0];
    p->entries[index].y = v[1];
    p->entries[index].z = v[2];
    p->entries[index].a = a;
    p->entries[index].b = b;
    p->entries[index].zero = 0;
    return &p->entries[index];
}





void MUSICAL_MCSS_FreeElem(u8 *p,u8 *e) { BILLBOARD_FreeElem(((Object_021F48C0 *)p)->board,((Entry_021F4B10 *)e)->index); if (((Bits_021F4D40 *)e)->bit4==1) BILLBOARD_ReleaseImageVramIfUsed(((Object_021F48C0 *)p)->board,((Entry_021F4B10 *)e)->id); ((Entry_021F4B10 *)e)->flags=((Entry_021F4B10 *)e)->flags & ~1; ((Entry_021F4B10 *)e)->flags=((Entry_021F4B10 *)e)->flags & ~2; }





void MUSICAL_MCSS_FreeElemImage(u8 *p, u8 *e, int type, u16 id)
{
    ((Entry_021F4B10 *)e)->type = MUSICAL_MCSS_GetArcFileCount(type);
    *(u8 * *)&((Entry_021F4B10 *)e)->data = MUSICAL_MCSS_GetElemPtr(*(u8 * *)&((Object_021F48C0 *)p)->resource,type);
    ((Entry_021F4B10 *)e)->flags = ((Entry_021F4B10 *)e)->flags & ~8;
    BILLBOARD_SetElemId(((Object_021F48C0 *)p)->board,((Entry_021F4B10 *)e)->index,&id);
    if (((Bits_021F4D74 *)e)->bit4 == 1) BILLBOARD_ReleaseImageVramIfUsed(((Object_021F48C0 *)p)->board,((Entry_021F4B10 *)e)->id);
    ((Entry_021F4B10 *)e)->flags = ((Entry_021F4B10 *)e)->flags & ~16;
    ((Entry_021F4B10 *)e)->id = id;
    ((Entry_021F4B10 *)e)->flags = (((Entry_021F4B10 *)e)->flags & ~1) | 1;
    ((Entry_021F4B10 *)e)->flags |= 2;
}





/*
 * Note: when the address 0x0204F32C is registered this should resolve to EXACT. Scratch blocker.log EXACT.
 *   typedef unsigned int u32;
 *   void BILLBOARD_GetImagePlttKey(char *p,u32 i,u32 *out) {
 *       *out = *(u32 *)(*(char **)(p+4)+i*40+36);
 *   }
 * follower: 0x021F4E2C vector/flags leaf left unfiled while ARM9 blocks.
 */
/*
 *   once 0x0204F32C is registered (manifest/label) this should resolve to EXACT*. Scratch blocker.log EXACT.
 *   typedef unsigned int u32;
 *   void BILLBOARD_GetImagePlttKey(char *p,u32 i,u32 *out) {
 *       *out = *(u32 *)(*(char **)(p+4)+i*40+36);
 *   }
 * follower: 0x021F4E2C vector/flags leaf left unfiled while ARM9 blocks.
 */
void MUSICAL_MCSS_TransferVram(char *p, char *e, void *a2)
{
    u32 first, second;
    if (!((Bits_021F4DE0 *)e)->bit3) {
        BILLBOARD_GetImagePlttVramOffset((int)(*(void **)(p+4)),*(u32 *)(e+4),(int)(&first));
        BILLBOARD_GetImagePlttKey((int)(*(void **)(p+4)),*(u32 *)(e+4),(int)(&second));
        NNS_GfdRegisterNewVramTransferTask((void *)1,first,(u32)(p+18),((second & 0xffff0000) >> 16) * 8);
        *(u16 *)e |= 8;
    }
}





/*
 * lever: Three-shift single-bit extraction is a halfword bitfield copy.
 */
void MUSICAL_MCSS_CopyElem(void *unused, u8 *s, u8 *d)
{
    ((Entry_021F4B10 *)d)->x = ((Entry_021F4B10 *)s)->x + 8192;
    ((Entry_021F4B10 *)d)->y = ((Entry_021F4B10 *)s)->y + 8192;
    ((Entry_021F4B10 *)d)->z = ((Entry_021F4B10 *)s)->z - 2048;
    ((Entry_021F4B10 *)d)->a = ((Entry_021F4B10 *)s)->a;
    ((Entry_021F4B10 *)d)->b = ((Entry_021F4B10 *)s)->b;
    ((Entry_021F4B10 *)d)->zero = ((Entry_021F4B10 *)s)->zero;
    ((Flags_021F4E2C *)d)->flag = ((Flags_021F4E2C *)s)->flag;
}





void MUSICAL_MCSS_SetElemVisible(u8 *p,u8 *e,u32 value) { BILLBOARD_SetElemVisible(((Object_021F48C0 *)p)->board,((Entry_021F4B10 *)e)->index,&value); ((Entry_021F4B10 *)e)->flags |=2; }





void MUSICAL_MCSS_SetElemPos(u32 unused,Entry_021F4E8C *p,const int *q) { p->x=q[0]; p->y=q[1]; p->z=q[2]; p->flags |=2; }





void MUSICAL_MCSS_SetElemScale(u32 unused,u32 p,u32 q) { ((struct Vec3 *)q)->x=((Entry_021F4B10 *)p)->x; ((struct Vec3 *)q)->y=((Entry_021F4B10 *)p)->y; ((struct Vec3 *)q)->z=((Entry_021F4B10 *)p)->z; }





void MUSICAL_MCSS_SetElemRotZ(u32 unused,u32 p,s16_021F4EB4 a,s16_021F4EB4 b) { u16 flags; ((Entry_021F4B10 *)p)->a=a; flags=((Entry_021F4B10 *)p)->flags; ((Entry_021F4B10 *)p)->b=b; ((Entry_021F4B10 *)p)->flags=flags|2; }





void MUSICAL_MCSS_SetElemRot(u32 unused,u32 p,s16_021F4EC4 *a,s16_021F4EC4 *b) { *a=((Entry_021F4B10 *)p)->a; *b=((Entry_021F4B10 *)p)->b; }





void MUSICAL_MCSS_SetElemField(u32 unused,u32 p,u16 v) { ((Entry_021F4B10 *)p)->zero=v; ((Entry_021F4B10 *)p)->flags |=2; }





/*
 * extent: six-byte body, two zero alignment bytes before separately filed 021F4EE8.
 */
void MUSICAL_MCSS_GetElemField(int unused, u16 *p, u16 *out)
{
    *out = p[1];
}





/*
 * lever: wide int argument into u16 bitfield preserves the redundant
 * halfword narrowing pair; a u16 argument produced 16 bytes, DIFF10.
 * leaf: sole overlay blocker of handed ov133 021B8140; explicit unused r0
 * retained from the caller. Twenty-byte body; following getter omitted.
 */
void MUSICAL_MCSS_SetElemFlag(int unused,Flags_021F4EE8 *s,int flag)
{
    s->flag=flag;
}





int MUSICAL_MCSS_GetElemFlag(int unused, Flags_021F4EFC *p)
{
    return p->flag;
}





void MUSICAL_MCSS_GetElemOffset(u8 *p, Offset_021F4C94 *out)
{
    MUSICAL_MCSS_GetOffset(*(u8 * *)&((Entry_021F4B10 *)p)->data, out);
}






u32 MUSICAL_MCSS_NoOp5(u8 *p) { return (u32)((Object_021F48C0 *)p)->resource; }





u32 *MUSICAL_MCSS_LoadActorData(int heap)
{
    u32 *p = func_02030734(heap, 8, 0, d_021F83B4, 0x47);
    int r = ARC_UTIL_LoadMember(45, 0x65, 0, heap);
    p[0] = r;
    p[1] = r;
    return p;
}





void MUSICAL_MCSS_FreeActorData(void **p) { func_020307B0(*p); func_020307B0(p); }






u8 *MUSICAL_MCSS_GetElemPtr(u8 *p, int i) { return *(u8 * *)&((McssActorData *)p)->table + i * 0xc; }





void MUSICAL_MCSS_GetOffset(u8 *p, Offset_021F4C94 *out)
{
    out->x = ((McssElemData *)p)->offsetX;
    out->y = ((McssElemData *)p)->offsetY;
}





/*
 * follower: MUSICAL_MCSS_SetModeA filed separately.
 */
int MUSICAL_MCSS_NoOp6(int *p) { return *p; }





int MUSICAL_MCSS_SetModeA(u16 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[3] & 1) return 1; break;
    case 2: if (p[3] & 2) return 1; break;
    case 3: if (p[3] & 4) return 1; break;
    case 4: if (p[3] & 8) return 1; break;
    case 5: if (p[3] & 16) return 1; break;
    case 6: if (p[3] & 32) return 1; break;
    case 7: case 8: if (p[3] & 64) return 1; break;
    case 9: return 0;
    }
    return 0;
}





int MUSICAL_MCSS_SetModeB(u16 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[3] & 1) return 1; break;
    case 2: if (p[3] & 2) return 1; break;
    case 3: if (p[3] & 12) return 1; break;
    case 4: if (p[3] & 16) return 1; break;
    case 5: if (p[3] & 32) return 1; break;
    case 6: case 7: if (p[3] & 64) return 1; break;
    case 8: return 0;
    }
    return 0;
}





int MUSICAL_MCSS_SetModeC(u8 *p, int mode)
{
    switch (mode) {
    case 0: case 1: if (p[8] == 0) return 1; break;
    case 2: if (p[8] == 1) return 1; break;
    case 3: if ((u8)(p[8] + 254) <= 1) return 1; break;
    case 4: if (p[8] == 4) return 1; break;
    case 5: if (p[8] == 5) return 1; break;
    case 6: case 7: if (p[8] == 6) return 1; break;
    case 8: return 0;
    }
    return 0;
}






int MUSICAL_MCSS_GetStateA(const unsigned char *p)
{
    if (*(const unsigned short *)&((McssElemData *)p)->flags & 0x80)
        return 1;
    return 0;
}






int MUSICAL_MCSS_GetStateB(const unsigned char *p)
{
    if (*(const unsigned short *)&((McssElemData *)p)->flags & 0x200)
        return 1;
    return 0;
}





/*
 * leaf: Sole unresolved ov112 mapper for concrete-correct ov133 DUP_FITTING_MoveElem; root reserved ownership.
 */
int MUSICAL_MCSS_GetIndex(unsigned index)
{
    switch (index) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3:
    case 4: return 3;
    case 5: return 4;
    case 6: return 5;
    case 7: return 6;
    case 8: return 7;
    case 9: return 8;
    default: return 9;
    }
}






unsigned char MUSICAL_MCSS_GetElemA(void *p, int i)
{
    return *(unsigned char *)(MUSICAL_MCSS_GetElemPtr(p, i) + 9);
}






unsigned char MUSICAL_MCSS_GetElemB(void *p, int i)
{
    return *(unsigned char *)(MUSICAL_MCSS_GetElemPtr(p, i) + 10);
}





unsigned char MUSICAL_MCSS_GetElemC(void *p, int i)
{
    return *(MUSICAL_MCSS_GetElemPtr(p, i) + 8);
}




void *MUSICAL_MCSS_CreateRenderObj(u32 heap)
{
    int i;
    char *p;
    p = GFL_HEAP_Alloc(heap, 4456, 0, d_021F83C4, 76);
    ((Scene *)p)->heap = heap;
    ((Scene *)p)->main = MUSICAL_MCSS_AllocRenderPool(8, heap);
    for (i = 0; i < 8; i++) *(u32 *)(p + i * 556 + 8) = 0;
    MUSICAL_MCSS_NoOp7(((Scene *)p)->main);
    return p;
}




void MUSICAL_MCSS_DeleteRenderObj(int a) { int i; for(i=0;i<8;i++) { if(((Fields *)(a+i*556))->active==1)MUSICAL_MCSS_FreeRenderObj(a,a+8+i*556); } MUSICAL_MCSS_FreeRenderPool(((Scene *)a)->main); func_020307B0((void *)a); }




void MUSICAL_MCSS_TickAnim(u8 *p) { MUSICAL_MCSS_TickMCAnim((char *)(((Scene *)p)->main)); }




/*
 * 2026-10-05 (wave D5 lane 02): ov112 0x021F546C is a different function from the ov194 one (a 172-byte slot
 * writer: mode >= 7 copies an input record into slot mode-7, modes 4 and 5 write four words). Parked as
 * src/pending/ov/ov112_func_021F546C.c, DIFF. Still blocks this MATCH.
 * 2026-10-05 (wD4 lane16): re-checked, bytes identical; MATCH only because MUSICAL_MCSS_SetMatrix (ov112) has no EXACT witness (ov194 has a pending file at the same address, 9 overlays overlap). Needs the callback matched in ov112.
 * 2026-10-05 (wave D6 lane 01): bytes still identical; still blocked by ov112 021F546C (DIFF 170/172).
 * 2026-10-05 (wave D7 lane 01): still MATCH, blocked by ov112 021F546C, now DIFF 172/172 with 27 bytes
 *   (two register-order residues, see that file).
 * 2026-10-05 (wave D8 lane 01): bytes still identical, still blocked by ov112 021F546C. Finding for
 *   that draft (not in this lane, so not edited): dropping const from the input pointer
 *   (`Input_021F40D0 *in`) fixes its residue (b), the modes 4/5 y-before-x load order; with the y local kept
 *   it is 172/172 with 5 bytes left, only the slot multiply colours (original idx r4 and product
 *   r1, ours idx r1 and product r4). No change to that from: no idx local, mode -= 7, unsigned idx,
 *   idx declared at function scope, an else-if chain, a void * parameter cast to Big *, an inline
 *   SetSlot(p, idx, in), enabled stored last; a byte-offset form loses the copy shape.
 * 2026-10-05 (D9 lane 02): still blocked by ov112 021F546C. Tried one more reading there: `Slot *s = &p->slots[mode - 7]` instead of the idx local (worse, 128 bytes differ).
 * 2026-10-05 (D9r lane 45): bytes still identical; still blocked by ov112 021F546C, now DIFF 172/172 with
 *   5 bytes (only the slot multiply colours), see that file.
 * 2026-10-05 (D9r lane 74): bytes still identical; still blocked by ov112 021F546C (DIFF, 5 bytes, slot
 *   multiply colours; new tries listed in that file).
 * 2026-10-05 (D9r lane 94): bytes still identical; still blocked by ov112 021F546C (DIFF, 5 bytes, slot multiply
 *   colours; three more tries listed in that file).
 * 2026-10-05 (D9r lane 121): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes,
 *   same slot multiply colours; new tries listed in that file).
 * 2026-10-05 (D9r lane 144): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes;
 *   new tries listed in that file).
 * 2026-10-05 (D9r lane 155): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes;
 *   new finding and tries listed in that file).
 * 2026-10-05 (D9r lane 171): bytes still identical (re-checked, MATCH, the MUSICAL_MCSS_SetMatrix ABS32 word has no
 *   witness); still blocked by ov112 021F546C (DIFF, 5 bytes; tries listed in that file).
 * 2026-10-05 (D9r lane 195): ov112 021F546C is now EXACT (src/matched/ov/ov112_func_021F546C.c, compound product form).
 *   This MATCH should resolve once the integrator regenerates the witness index (the tool still reads the old
 *   manifest: "no witness outside"). Re-run match.py one after the regenerate and file as EXACT.
 */
void MUSICAL_MCSS_DrawRenderObj(void **p) { MUSICAL_MCSS_DrawMC(p[1],MUSICAL_MCSS_SetMatrix); }




u8 *MUSICAL_MCSS_SetupRenderObj(Scene *p,const u8 *b,int c)
{
    int i;
    int j;
    u8 *slot;
    Buffers buffers;
    char *second;
    for(i=0;i<8;i++) if(p->slots[i].active==0) break;
    slot=(u8 *)&p->slots[i];
    ((Slot *)slot)->active=1;
    MUSICAL_MCSS_GetPokemonArcs((u8 *)b,buffers.stats,0);
    p->slots[i].primary=MUSICAL_MCSS_LoadMC(p->main,0,0,0,(u32)buffers.stats,(u32)slot,0);
    if(c==1) {
        MUSICAL_MCSS_GetPokemonArcs((u8 *)b,buffers.stats,1);
        p->slots[(u32)i].secondary=MUSICAL_MCSS_LoadMC(p->main,0,0,0,(u32)buffers.stats,(u32)slot,0);
        MUSICAL_MCSS_NoOp8(p->slots[(u32)i].secondary);
    } else p->slots[i].secondary=0;
    p->slots[i].enabled=1;
    p->slots[i].object=(u8 *)p->slots[i].primary;
    buffers.scale[0]=65536;
    buffers.scale[1]=65536;
    buffers.scale[2]=4096;
    for(j=0;j<9;j++) p->slots[i].tracks[j].value=0;
    p->slots[i].f548=0;
    p->slots[i].f552=0;
    p->slots[i].f524=0;
    p->slots[i].f528=0;
    p->slots[i].f532=0;
    p->slots[i].f536=0;
    p->slots[i].f540=0;
    p->slots[i].f544=0;
    MUSICAL_MCSS_GetRenderRot((int *)&p->slots[i],buffers.scale);
    MUSICAL_MCSS_GetFieldE(p->slots[i].object);
    return (u8 *)&p->slots[i];
}





void MUSICAL_MCSS_FreeRenderObj(int a, int b) {
    if (((Slot *)b)->secondary != 0) {
        MUSICAL_MCSS_FreeMC((char *)(*(int *)&((Scene *)a)->main), (char *)(((Slot *)b)->secondary));
    }
    MUSICAL_MCSS_FreeMC((char *)(*(int *)&((Scene *)a)->main), (char *)(((Slot *)b)->primary));
    ((Slot *)b)->active = 0;
}





void MUSICAL_MCSS_GetRenderPos(int *p, int *q)
{
    MUSICAL_MCSS_GetFieldA(*(char * *)&((Slot *)p)->object, q);
}





void MUSICAL_MCSS_GetRenderRot(int *p, int *q)
{
    MUSICAL_MCSS_GetFieldB(*(char * *)&((Slot *)p)->object, q);
}





void MUSICAL_MCSS_SetRenderFrame(int *p, unsigned short v)
{
    MUSICAL_MCSS_SetFieldC(*(char * *)&((Slot *)p)->object, v);
}




void MUSICAL_MCSS_SetRenderMode(int *p,int b) { if(b==1)MUSICAL_MCSS_NoOp9((char *)p[2]); else MUSICAL_MCSS_NoOp8((char *)p[2]); }




int MUSICAL_MCSS_GetRenderHandle(u8 **p) { return MUSICAL_MCSS_GetFieldG(p[2]) != 1; }




void MUSICAL_MCSS_GetRenderFieldA(void **p) {MUSICAL_MCSS_GetFieldF(p[3]); if(p[4])MUSICAL_MCSS_GetFieldF(p[4]); }





void MUSICAL_MCSS_GetRenderFieldB(int a) {
    MUSICAL_MCSS_GetFieldE((u8 *)(((Slot *)a)->primary));
    if (((Slot *)a)->secondary != 0) {
        MUSICAL_MCSS_GetFieldE((u8 *)(((Slot *)a)->secondary));
    }
}



void MUSICAL_MCSS_SetRenderAnim(int a, u32 n)
{
    MUSICAL_MCSS_SetMCAnim(*(char * *)&((Slot *)a)->object, n);
}




void MUSICAL_MCSS_ResetRender(int a) {
    if (((Slot *)a)->enabled == 1) {
        MUSICAL_MCSS_CopyField((Object *)((Slot *)a)->primary, (Object *)((Slot *)a)->secondary);
        ((Slot *)a)->object = (u8 *)((Slot *)a)->secondary;
        ((Slot *)a)->enabled = 0;
        MUSICAL_MCSS_NoOp8((char *)(((Slot *)a)->primary));
    } else {
        MUSICAL_MCSS_CopyField((Object *)((Slot *)a)->secondary, (Object *)((Slot *)a)->primary);
        ((Slot *)a)->object = (u8 *)((Slot *)a)->primary;
        ((Slot *)a)->enabled = 1;
        MUSICAL_MCSS_NoOp8((char *)(((Slot *)a)->secondary));
    }
}



void MUSICAL_MCSS_ResetRender2(int a,int b) { if(b!=((Slot *)a)->enabled)MUSICAL_MCSS_ResetRender(a); }




/*
 * Recursive MATCH unblocker: unresolved callee named by the parked
 * ov112_func_021F80B0.  The +8 word is loaded once and shared by both arms
 * (the two identical loads CSE, which schedules the load before the branch).
 *
 * Addresses are Black-image addresses.
 */
void MUSICAL_MCSS_GetRenderSize(int a0, int a1)
{
    if (a1 == 1)
        MUSICAL_MCSS_GetFieldC((u8 *)(((Slot *)a0)->object));
    else
        MUSICAL_MCSS_GetFieldD((u8 *)(((Slot *)a0)->object));
}



void MUSICAL_MCSS_SetRenderFieldA(void **p,int b) {MUSICAL_MCSS_SetFieldA(p[1],b); }



void MUSICAL_MCSS_SetRenderFieldB(u8 *p, int a)
{
    MUSICAL_MCSS_SetFieldB(*(u8 * *)&((Scene *)p)->main, a);
}




u8 *MUSICAL_MCSS_GetRenderElem(u8 *p, int i) { return p + 0x14 + i * 0x38; }




u8 *MUSICAL_MCSS_GetRenderFlags(u8 *p) { return p + 0x20c; }



/*
 * follower: aggregate-copy function 021F546C parked as DIFF note.
 */
char *MUSICAL_MCSS_GetRenderMatrix(char *p) { return p+536; }



void MUSICAL_MCSS_SetMatrix(unsigned mode, Input_021F53CC *in, Big *p)
{
    if (mode >= 7) {
        u32 off = mode - 7;
        u32 base = (u32)p;
        off *= 0x38;
        *(int *)(base + off + 0x14) = 1;
        base += off;
        *(Vec_021F56BC *)(base + 0x18) = in->a;
        *(Vec_021F56BC *)(base + 0x24) = in->b;
        *(u16 *)(base + 0x48) = in->e;
        *(u16 *)(base + 0x4a) = in->f;
        *(Vec_021F56BC *)(base + 0x30) = in->c;
        *(Vec_021F56BC *)(base + 0x3c) = in->d;
        return;
    }
    if (mode == 4) {
        int y = in->b.y;
        p->t[0].x = in->b.x;
        p->t[0].y = y;
        p->t[0].z = 0;
        p->flag[0] = 1;
        return;
    }
    if (mode == 5) {
        int y = in->b.y;
        p->t[1].x = in->b.x;
        p->t[1].y = y;
        p->t[1].z = 0;
        p->flag[1] = 1;
    }
}



void MUSICAL_MCSS_GetPokemonArcs(u8 *p, u32 *out, u32 k)
{
    u32 a, c, d, flag;
    int b;
    u32 n;
    POKE_TOOL_GetBoxParam(((McssMon *)p)->source);
    a = ((McssMon *)p)->species;
    n = POKE_TOOL_NormalizeForm(a, p[11]);
    c = p[10];
    d = p[12];
    flag = 0;
    b = POKE_TOOL_FilterSpecies(((McssMon *)p)->species, (u8)n);
    if (k == 1) flag = 1;
    out[0] = 52;
    out[1] = POKEGRA_GetCbrArcIndex(out[0],a,b,c,d,flag,0);
    out[2] = POKEGRA_GetPalArcIndex(out[0],a,b,c,d,flag,0);
    out[3] = POKEGRA_GetCelArcIndex(out[0],a,b,c,d,flag,0);
    out[4] = POKEGRA_GetAnmArcIndex(out[0],a,b,c,d,flag,0);
    out[5] = POKEGRA_GetMCelArcIndex(out[0],a,b,c,d,flag,0);
    out[6] = POKEGRA_GetMAnmArcIndex(out[0],a,b,c,d,flag,0);
    out[7] = POKEGRA_GetNcecArcIndex(out[0],a,b,c,d,flag,0);
    out[8] = ((McssMon *)p)->field10;
}



void *MUSICAL_MCSS_AllocRenderPool(int count, u32 heap)
{
    char *p;
    p = GFL_HEAP_Alloc(heap, 28, 1, d_021F83D4, 132);
    ((McssRenderPool *)p)->count = count;
    ((McssRenderPool *)p)->heap = heap;
    ((McssRenderPool *)p)->children = GFL_HEAP_Alloc(heap, count * 4, 1, d_021F83D4, 137);
    ((McssRenderPool *)p)->lastTick = d_02FFFC3C;
    ((McssRenderPool *)p)->cellVram = 3 << 16;
    ((McssRenderPool *)p)->animVram = 1 << 12;
    return p;
}



void MUSICAL_MCSS_FreeRenderPool(char *p) { int i; char *q; for(i=0;i<((McssRenderPool *)p)->count;i++) { q=(*(char ***)(p+4))[i]; if(q)MUSICAL_MCSS_FreeMC(p,q); } func_020307B0(((McssRenderPool *)p)->children); func_020307B0(p); }



void MUSICAL_MCSS_TickMCAnim(char *p)
{
    int i;
    u32 now;
    int delta;
    char *child;
    i = 0;
    now = d_02FFFC3C;
    delta = now - ((McssRenderPool *)p)->lastTick;
    for (; i < ((McssRenderPool *)p)->count; i++) {
        child = (*(char ***)(p + 4))[i];
        if (child && !((Flags_021F53CC *)(child + 236))->paused)
            NNS_G2dTickMCAnimation(child + 40, delta << 12);
    }
    ((McssRenderPool *)p)->lastTick = now;
}



static inline int FxMul(s64 a, s64 b)
{
    return (int)((a * b + 0x800) >> 12);
}



static inline int RoundF(int v)
{
    return (int)(v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f);
}



static inline void LoadPose(Pose *r, char *src, int one)
{
    switch ((u16)*(u32 *)(*(char **)(src + 0x1c) + 4)) {
    case 0: {
        const PoseSrc *s = **(PoseSrc ***)src;
        r->id = s->id;
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = 0;
        r->dz = 0;
        break;
    }
    case 1:
        *r = ***(Pose ***)src;
        break;
    case 2: {
        const PoseSrc *s = **(PoseSrc ***)src;
        r->id = s->id;
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = s->dx;
        r->dz = s->dz;
        break;
    }
    }
}



static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    REG(0x040004A8) = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}



static inline void VEC_Set(Vec_021F56BC *a, int x, int y, int z)
{
    a->x = x;
    a->y = y;
    a->z = z;
}



static inline void G3_Translate(int x, int y, int z)
{
    REG(0x04000470) = (u32)x;
    REG(0x04000470) = (u32)y;
    REG(0x04000470) = (u32)z;
}



static inline void G3_Scale(int x, int y, int z)
{
    REG(0x0400046C) = (u32)x;
    REG(0x0400046C) = (u32)y;
    REG(0x0400046C) = (u32)z;
}



/*
 * note (2026-10-04, wave D3 lane 03): first complete structural draft, not tuned.
 *   Listing extent 021F56BC..021F5EDC (2080 bytes), frame 0x254, mid pool at 021F5A24
 *   (0x04000444, 02148D8C/98/A4, 021F8310/1C/04, 02148B98, 0xFFFFF000, 0xFFFA0000,
 *   02148B54, 0x04000470, 020A1B38 sin/cos table, 0x0400046C) and tail pool 021F5ED0.
 *   Shape: G3 setup (push, mode 0, store 0, mode 3, identity, mode 2); camera pick by
 *   p->f8 bit 0; outer loop i < p[0] over p[1][i] objects, skip null or (fEC >> 2) & 1;
 *   per object a 16-byte pose rec at sp+0x244 filled by kind 0/1/2 of
 *   obj+0x28 -> [0x1c] -> f4; translation/rotation/scale writes; MUSICAL_MCSS_SetupG3;
 *   polygon attr word built from bitfields at obj+0x90; inner loop j over parts of
 *   p->f6C->f4[rec.id]; second pose rec at sp+0x234; two MUSICAL_MCSS_DrawSprite calls;
 *   innermost k < 8 over bytes ent[0x30+k] != 0xFF with s64 fixed point math and
 *   an indirect call through p->fF8.
 *   Known hard parts: the compiler derives small constants from register-held I/O
 *   addresses (lsrs r1, r0, #0x13 = 0x80 from 0x04000470; lsrs #0xe = 0x1000 from
 *   0x0400046C; r0 >> 0x12 = 0x100), the float rounding idiom
 *   (v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) then _ffix, and the
 *   many spilled loop-invariant offsets at sp+0x80..0xAC (0x80 constants and
 *   field offsets r5-8, r5-4 with r5 = 0x10C).
 *   The innermost k-loop math is an approximation of the listing (021F5BD4..021F5E8C),
 *   re-derive it from the listing before tuning.
 *   Verdict of this draft: DIFF, compiled 1680 bytes vs 2080, 1623 bytes differ, 52 of 55
 *   relocations resolved. Prologue already differs (push r3 extra, frame 0x198 vs 0x254):
 *   the original keeps more stack locals (spilled invariants at sp+0x80..0xAC, s64 halves
 *   at sp+0x68..0x74, sub-pose rec at sp+0x234, 0x5C-byte source records).
 *   Siblings: MUSICAL_MCSS_DrawSprite (callee, 13 args, see 021F5B6A..021F5BCC for the stack layout).
 *
 * note (2026-10-05, wave D4 lane 06): p->f8 bit 0 is now read through a one-bit bitfield
 *   (Bits_021F53CC.b0): the camera pick now gives the original lsls #0x1f; lsrs #0x1f test (1623 -> 1611
 *   bytes differ, compiled 1684 vs 2080).  Still open: the frame (0x254 vs 0x198, push without
 *   r3), the zero local stored at [sp] at entry, the spilled invariants, and the innermost k-loop
 *   which still needs re-deriving from the listing (021F5BD4..021F5E8C).
 *
 * note (2026-10-05, wave D5 lane 06): body rewritten from a fresh reading of the listing
 *   (the code after the mid pool needs `show --addr 0x021F5A5C --size 0x480 --thumb`, the
 *   default show desyncs at 021F5A44).  Fixes: r4 is obj for the whole loop, so the j/k loops
 *   read obj+0x6C/0x68/0x20/0x24/0xF8, MUSICAL_MCSS_DrawSprite takes obj (not p) and &cb.z (sp+0xB8,
 *   zeroed per object), and the indirect call goes through the second parameter `arg`
 *   (`arg((u8)pt->f4, &cb.in.a, obj->fF8)`); a 0x3C-byte callback record at sp+0xB4 (w out
 *   word, z, pos with y negated, x2/y2 scaled by obj->fD4/16 and fD8/16, z, obj+0xD4 vec,
 *   obj+0x100 vec, obj->fFC, ang + (pt->f10 << 11)); on pt->f4 == 5 the result goes to
 *   obj+0x100/0x104/0x108.  k loop: two rotations (part by pose.rot + sub.rot scaled by the
 *   pose*sub scale, then the table entry (x, z at +2/+4) plus pose.dx/dz by pose.rot scaled by
 *   pose.sx/sy), operand order (s64)vec * scale.  Else-branch: a local 4x4 matrix filled with
 *   constants at sp+0x114, MTX_Copy43To44_(&d_02148B98, &m4), func_0207BE14(&m4, &d_02148B54,
 *   &m4), second MUSICAL_MCSS_CalcMatrix uses that matrix.  Sub-pose kind 0 leaves dz unset.  obj skip
 *   test reads p[1][i] twice and bit 2 of obj->fEC as a bitfield; obj+0x90 and obj+0x68 are
 *   loop-level pointer locals (sp+0x5C, sp+0x50).  Result: compiled 1996 vs 2080 (was 1684),
 *   frame 0x248 vs 0x254, prologue and the obj test now line up modulo slot numbers.
 *   Open: the zero stored at [sp] at entry (push without r3 in the original), the i slot
 *   (0x5C vs 0x58), mid-pool placement (original after the attr word at 021F5A20), LoadPose
 *   register shape (original keeps src = obj+0x28 in r0), the eight spilled 0x800 rounding
 *   words at sp+0x80..0x94/0x9C/0xA0 and the 0x100/0x10C offsets at sp+0x98/0xA4..0xAC.
 * note (2026-10-05, wave D6 lane 01): three fixes from a fresh reading of the head and the pose loader.
 *   (1) G3i_LookAt_ takes a fifth argument (NULL, as in the matched callers): the zero stored at [sp]
 *   at entry is that stack argument, written once before the camera-pick branch. The prologue now
 *   matches to 021F56F8 apart from the frame size. (2) LoadPose is a switch on the u16 kind with a
 *   compare chain (beq 0, cmp 1, cmp 2, b out), and the id is a u16 read (ldrh) through a
 *   {u16 id; u16 pad; s16 dx; s16 dz} source record. (3) obj+0x90, obj+0x68 and obj+0x28 come from
 *   static inline accessors (ObjAttr, ObjSrcs, ObjAnim): the parameter copy gives the original
 *   `adds r0,r4,#0; str [sp,#K]; adds r0,#0x90; str [sp,#K]` double store for srcs and keeps src =
 *   obj+0x28 in r0 for the kind load (`ldr r3,[r0,#0x1c]`). Compiled 2008 vs 2080 (was 1996).
 *   Open: frame 0x24C vs 0x254 (8 bytes of locals missing, every sp offset is 8 low), attr (obj+0x90)
 *   stays in r5 where the original spills it to sp+0x5C, the zero/kind registers in the obj head
 *   (original zero r2, kind r3; ours zero r3, kind r1), and everything after 021F57BC not re-checked.
 * note (2026-10-05, wave D7 lane 01): read only, no new build. The original spills attr (obj+0x90) to
 *   sp+0x5C and reloads it three times for the attr word (021F59EE, 021F59F0, 021F5A00); r5 is a
 *   short-lived temp there (0x10C offset at 021F59A6). So the original has more long-lived values than
 *   ours; the 8 missing frame bytes are likely two more spilled locals. Also: the callback arg is
 *   ov112 MUSICAL_MCSS_SetMatrix (mode = (u8)pt->f4, in = &cb.in.a, p = obj->fF8), see that draft for the
 *   0x38-byte slot layout of obj->fF8.
 * note (2026-10-05, wave D8 lane 01): three local shape fixes from the listing at 021F58C4..021F591E.
 *   (1) The pos and (ox, oy, 0) MTX_TRANS writes are a G3_Translate(x, y, z) static inline: the
 *   original loads all three values before the three stores (ldr r3,[sp,#0x230]; ldr r2; ldr r1;
 *   str; str; str); 0x0400046C writes are G3_Scale(sx, sy, 0x1000). (2) The flag increment is
 *   `flag++` on the u8 local: the original reloads the spilled zero and does adds/lsls/lsrs, where
 *   `flag = (u8)(flag + 1)` folds to movs #1. (3) The rotation ternary has no inner (u16) cast:
 *   `u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;` truncates once after the join, as in the
 *   original. Compiled 2012 vs 2080 (byte count is not comparable, every later offset shifts).
 *   Still open: frame 0x24C vs 0x254. The original spill area is 8 bytes larger (struct locals start
 *   at sp+0xB4 in the original, sp+0xAC in ours), so the original spills two more values; attr
 *   (obj+0x90) is one of them (sp+0x5C, ours keeps it in r5). G3_Translate(pos) still takes r2/r1/r0
 *   for z/y/x and r3 for the register base, the original r3/r2/r1 and r0. The rounding constant
 *   0x800 is derived from the halfword offset 2 held in r6 (`movs r6,#2; ldrsh r1,[r2,r6]` then
 *   `lsls r2,r6,#0xa`), ours does the same from r7. The k-loop past 021F5A5C was not re-checked.
 * note (2026-10-05, wave D9 lane 04): six fixes from a fresh reading of the j/k loops (compiled 2064 vs
 *   2080; on a register-blind instruction diff 94 lines differ, was 210).  (1) obj->f6C has one more
 *   level: the record table is at obj->f6C->f4 (as in matched MUSICAL_MCSS_DrawSprite, McssSpriteSet/Tab/TabEnt), both in
 *   the j-loop test and for the entry reads.  (2) The sub-pose uses the same LoadPose switch: kind 0
 *   also zeroes dz, by cross-jumping into the kind 2 tail (listing 021F5AE6 b 021F5B1A).  The entry
 *   te and the part pt are not locals: j*8 and b*0x14 are spilled CSE values and every read is
 *   written inline.  (3) The 0x1D write goes to 0x0400044C (MTX_STORE), not 0x04000450.  (4) Every
 *   fixed-point product is a FxMul(s64 a, s64 b) static inline: it puts the vector in r0:r1 and the
 *   scale in r2:r3 and spills fx/fz with s/c in r5/r6, as in the original.  psx/psy are s64 locals
 *   assigned before the first product (the original sign-extends both before the first _ll_mul).
 *   (5) obj->fEC bit 0 is a one-bit bitfield.  (6) Declaration order `fx, fz, c, s, X, c2, Z, s2`
 *   gives the original registers in both rotations; the attr word is written right-nested
 *   a7 | (0xF0000 | (a4 | (a3 | (a5 | a0 | 0x40000000)))) to get the original OR order.
 *   Still open: frame 0x250 + push r3 vs 0x254. The original spills attr (obj+0x90) to sp+0x5C and
 *   keeps &pos in r7 across the two MUSICAL_MCSS_CalcMatrix calls; ours keeps attr in r5 and rematerialises
 *   &pos.  Tried without effect: attr declaration position, block scope, a struct type, a PolyAttr
 *   inline, a Persp inline and a `Vec *pp` local for the 660C calls.  A separate `int w` local (not
 *   cb.w) gives the 0x254 frame but puts w at sp+0xB0, not 0xB4, so it is not the answer.  The k-loop
 *   head schedules the fx/fz loads before `ang` (original: ang first); `ent->parts[k]` inline instead
 *   of `b` is worse.  `j = 0` sits after the first scale product in the original; only an unnatural
 *   split of the sy/sx block reproduces it.
 * note (2026-10-05, wave D9r lane 22): 94 -> 0 instruction lines differ; 5 bytes left (two spill slots).
 *   (1) The 0x040004A8 word is the SDK inline G3_TexImageParam with enum parameter types, as in the
 *   matched sibling arm9 MCSS_Draw (same renderer: same matrix calls, Pose switch, TexInfo record
 *   at obj+0x90 with addr/s/t/fmt/pltt0 at 0/0xC/0x10/0x14/0x1C).  With it, attr spills to sp+0x5C and
 *   &pos stays in r7 across the MUSICAL_MCSS_CalcMatrix calls; the frame is 0x254 and the push has no r3.
 *   (2) attr, srcs and a new ctrl (obj+0x28) are plain assignments in the order attr, ctrl, srcs (the
 *   accessor inlines are gone; they made no difference once attr spills).  (3) Declaration order
 *   ent, attr, i, j, srcs, k gives the original slots.  (4) for (j = 0; ...) without the early
 *   j = 0 statement: the 0 is shared with the first FxMul high word, as in the original.  (5) ang is an int
 *   (u16 cast at the assignment).  (6) X = te.x; X += pose.dx; (same for Z) gives the te.x-first load
 *   order.  (7) c2 (the cos of pr) is written inline at both uses: the original spills it as a CSE
 *   temp (lowest slot, reload with no copy).  (8) The obj+0x100 write is VEC_Set(v, x2, y2, 0), which
 *   loads y2 before x2.
 *   Residue: the CSE temps j*8 and c2 have swapped slots (original j*8 sp+0x34, c2 sp+0x30; ours the
 *   reverse).  A diagnostic without the j-loop use of ents[j] gives the original order, so the j*8
 *   temp is created later than c2 in ours.  Tried without effect: s2 inline too, c/s inline (worse),
 *   an idx local, operand order of the c2 products, k-loop locals at function scope, a te local in
 *   the k loop, src passed straight to LoadPose, named c2 in any scope (goes to the named slots).
 * note (2026-10-05, wave D9r lane 53): residue unchanged at 5 bytes (j*8 CSE temp at sp+0x30, cos(pr) temp
 *   at sp+0x34; original reverse).  One clean-up: the `one` local (0x1000 for the sub-pose LoadPose) is
 *   gone; LoadPose(&sub, src, 0x1000) gives the same bytes (the 0x1000 reload from sp+0x64 is the
 *   compiler's own hoisted constant).  Tried without effect on the slot pair (each a real compile): a TabEnt
 *   pointer or a u16 h local for the head read; `int id = j` alias at head or in the k loop; the j loop and the
 *   k loop as if/do-while; pose.rot inline (no pr local; same bytes); s2 load moved above the X/Z reads; X/Z
 *   reads as (ents + j)->x, as a Cell() inline, or as byte offsets (j * 8 + 2) in both head and k loop
 *   (byte offsets in the k loop only stop the j*8 CSE and LICM-hoist a second copy); cos(pr) spelled four
 *   other ways (1 + idx, (T + idx)[1], &T[idx][1], idx << 1) and through a Cos() inline; RotX/RotZ inlines and
 *   an FX_MUL-style macro for the second rotation (worse); a `const s16 *sc` pointer for s2/cos (worse);
 *   k-loop declaration order.  The pair stays swapped in every variant, so its order is probably fixed by the
 *   colouring tie-break, not by source position of the two expressions.
 * note (2026-10-05, wave D9r lane 90): residue unchanged at 5 bytes (same slot pair).  Compared with the
 *   matched twin arm9 MCSS_Draw line by line and tested new forms, each a real compile.  Same 5 bytes:
 *   outer i loop as the twin's `i = 0; if (n > 0) do { } while (++i < n);`; a typed MAnim/Frame chain
 *   (`((Obj *)obj)->anim->frames[pose.id]`) instead of the raw obj+0x6C casts; the node as a 0x5C-byte
 *   struct array (`&(*nodes)[idx]`, as the twin); a frame-cells pointer local at the head; a named int
 *   node index at the head; SDK FX_SinIdx/FX_CosIdx inlines (int idx, fx16 return) for every table
 *   read; the break test as `if (ent->parts[k] == 0xFF) break; b = ent->parts[k];`; the rotated vector
 *   in vx/vz locals before the two FxMul calls.  Worse: the head index through a NodeIdx() inline
 *   (loses the loop-condition entry pointer, 1056 B); the k loop as a static inline (not inlined,
 *   1832 B); `k < 8 && parts[k] != 0xFF` in the for condition (744 B); X/Z as one expression each
 *   (64 B).  Diagnostics (not candidates): a third use of the cos(pr) temp, X/Z reads moved to the top
 *   of the k loop, and no Z read all keep ours order (j*8 below cos(pr), b*0x14 lowest), so the order
 *   does not follow use count or program position of the k-loop reads.
 * note (2026-10-05, wave D9r lane 107): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp sp+0x34;
 *   original reverse).  New tries, each a real compile: FxMul with int (fx32) parameters as in the twin's
 *   FX_MUL, with s64 or int psx/psy (89 B, worse); cos(pr) as an int-typed value ((int) cast at both uses,
 *   or an int-returning CosI() inline; same 5 B); 5EDC prototype and Ent fields as int, as in the matched
 *   MUSICAL_MCSS_DrawSprite, and 660C with its matched const int / u32 parameters (same 5 B); `int b` for the part
 *   byte (same 5 B); s16 (fx16) locals for s2, for c/s, or for all three (508 to 728 B, worse); named c2 in
 *   three placements (430+ B, adds a copy); mixed spellings for the X/Z reads (index for one, byte offset
 *   for the other: 870 B; `(ents + j)->x` for X only: same 5 B).  Diagnostics: `int pr` swaps the pr and
 *   flag slots (0x38/0x3C), so local width moves slot order; an extra k-loop use of ents[j] does not move
 *   j*8 off sp+0x30.  The slot order of the two CSE temps does not follow use count or type.
 * note (2026-10-05, wave D9r lane 124): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  Tested the inline-return-temp idiom (ov125 021D6B40) on every helper in
 *   the j/k loops, each a real compile: LoadPose hand-expanded for sub, and for both pose and sub (output
 *   identical to the draft, byte for byte); RoundF hand-expanded as a plain ternary and with a block-local
 *   `int v` (identical); the two second-rotation FxMul calls hand-expanded with a block-local s64 operand
 *   (identical) or as one expression (2084 B, worse); a Cell() inline returning &ents[j] at all three
 *   uses, head included (1056 B).  So the inlines are transparent here; no inline temp sets this pair.
 *   Also tried: the head .h read as a byte offset (j*8+6: 1040 B) or as (ents + j) cast to char * (same
 *   5 B); an index local for s2/cos(pr) as u32, int (same 5 B) or u16 (483 B).  Diagnostics: `u32 j`
 *   and a branch between the two cos(pr) uses keep ours order.
 * note (2026-10-05, wave D9r lane 135): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  New head-of-j-loop forms, each a real compile, all give the same 5 B
 *   (the front end normalises them to one tree): a `Tab *tab` assigned in the loop condition
 *   (`j < (tab = &T[pose.id])->count`) and read at the head as tab->ents[j].h, also through a TabEnt
 *   pointer local taken from tab (te = tab->ents; te[j].h, or te = &tab->ents[j]); entries as a u16/s16
 *   halfword array at all three uses (`((u16 *)ents)[j * 4 + 3]`, x/z at j * 4 + 1 / + 2); getters that
 *   take the already-computed ents (or &T[pose.id]) plus j: EntH(e, j), EntAt(e, j)->h, EntIdx(e, j),
 *   TabEntAt(t, j)->h (head only: same 5 B; also at the X/Z reads: 6 B, add operand swap); src at
 *   function scope.  Worse: a struct copy `TabEnt e = ents[j]` at the head (1100 B); h as an 8-bit
 *   bitfield pair (u16, s16 or u32 fields: 998 to 1056 B, lsls/lsrs instead of and/asr); the u16 head
 *   read only (X/Z left as fields: 1040 B); tab also used at the X/Z reads (1136 B, tab held in a register).
 *   Off the head, also same 5 B: a non-const `s16` table (as in the twin), the table named
 *   FX_SinCosTable_, s2 and the second rotation in a nested block.  Diagnostics: without cos(pr) as a CSE
 *   (second use replaced) j*8 stays at sp+0x30, so it is the cos(pr) temp that lands above j*8; without
 *   the head use j*8 becomes a LICM temp at sp+0x3C (above the narrow pr/flag locals) and cos(pr) drops
 *   to sp+0x30.  No head spelling reached changes the temp order.
 * note (2026-10-05, wave D9r lane 152): residue unchanged at 5 bytes; the file body is unchanged.
 *   New tries, each a real compile.  The slot order of the late group (flag, pr, j*8, cos(pr), b*0x14)
 *   moves with the declared TYPE of j, not with any spelling of the expressions:
 *   - `long j` (or s32/unsigned long): j*8 goes to sp+0x38, above pr (pr 0x34, cos 0x30 correct, b*0x14
 *     0x2c correct): 6 B.  `unsigned int j` keeps ours order (7 B).  The type of i, of the k-loop
 *     locals (long/fx32), of b (int), of u32 (unsigned long), and fx32 struct fields do not move it.
 *   - `long j` plus `int pr` (or long pr): j*8 0x34 and cos 0x30 are correct, but pr and flag swap
 *     (pr 0x3C, flag 0x38): 9 B.  So the original needs u16 pr with j*8 between pr and cos; no type
 *     pair of (j, pr) gives that.
 *   - reusing the first-rotation `c` (or `s` and `c`) for the second rotation: j*8 goes to 0x34, but
 *     the second web of c gets the lowest slot (0x2C, below b*0x14) and the rz product gains a copy
 *     (431 B).  A named s16 c2 also adds the copy and stays at 0x34.
 *   - pose.rot spelled in place of pr in ang, s2, or one/both cos reads: j*8 goes to 0x34, but pr
 *     takes a late slot (0x30) and cos moves to 0x38 (5 to 10 B; split spellings also break the
 *     shared T+idx address).
 *   - same 5 B: cos and sin as a {sin, cos} struct table (cast or extern), five mixed spellings of one
 *     cos read (1 + idx, (T + idx)[1], *(&T[i] + 1), (idx << 1) + 1, (&T[i])[1]), FX_SinIdx/FX_CosIdx
 *     with int or long idx (with long j), pr declared with an initialiser in a block, pr at function
 *     scope reused for the G3 rotation angles (with long j: still 6 B), b assigned after its
 *     declaration, an unreferenced label between the products, byte-offset j * sizeof(TabEnt) reads.
 *   Worse: RotA/RotB inlines taking cos as a parameter (432 B, rz product copy); a `const s16 *sc`
 *   pointer (432 B); a 5EDC prototype with a long j parameter (j itself moves to the late group).
 *   Reading of the pattern: the late slots look like spill temporaries in the order the allocator
 *   spills them (round by round, then by definition order).  cos(pr) is in the first round in every
 *   variant; the original needs it in a later round than pr.  No natural source change found that
 *   does this without moving another slot.
 * note (2026-10-05, wave D9r lane 198): residue unchanged at 5 bytes; the file body is unchanged.  Lane 152's
 *   suggestion (long j or s32 plus a way to push pr back above j*8 with pr still u16) tested as a table; every row a
 *   real compile.  Slots low to high (b*0x14 is 0x2C in every row):
 *   original                     cos 30, j*8 34, pr 38, flag 3C
 *   base (int j)                 j*8 30, cos 34, pr 38, flag 3C: 5 B
 *   long j / unsigned long j     cos 30, pr 34, j*8 38, flag 3C: 6 B (8 B for unsigned long: extra loop-test byte)
 *   unsigned int / size_t j      as base, 7 B (loop-test byte differs)
 *   named `int jo = j * 8;` (head, X and Z read through ((TabEnt *)((char *)ents + jo))), int or u32, any
 *   declaration order of {jo, pr, flag} at function scope (6 orders), jo at function or j-body scope:
 *                                cos 30, pr 34, jo 38, flag 3C: 7 B (the X/Z add operand order also changes)
 *   named jo plus a redundant second `jo = j * 8;` BEFORE the last use (idiom a-redundant-second-assignment...;
 *   after the loadpose, before the 5EDC calls, before the k loop, first or after the break test in the k body):
 *                                jo 30, cos 34, pr 38, flag 3C: 6 B.  A second assignment after the last use
 *                                (after cb.in.a or at the end of the k body) is dead and gives the single-assign row.
 *   jo declared long or as a char * / void *: long moves it to a high named slot (22 B); a pointer is the base row.
 *   jo split into jh (head) and jk (k loop): as the double-assign row.
 *   So j*8 only ever lands at one of two places: below cos (temp) or above pr (named, or long-typed); the original
 *   needs the slot between them.  Declaration order and scope of jo, pr and flag never moved any slot.
 *   pr changes with long j: `int`, `long`, `u32` or `unsigned long` pr give j*8 34 and cos 30 (correct) but pr 3C and
 *   flag 38 (5 B differ); flag as u16, s16 (same 5 B), int, u32, long with `flag = (flag + 1) & 0xFF` (1429 to 1462 B);
 *   pr s16 or u8 (740 B); pr at function scope as int (14 to 43 B, pr 0x48).  pr read earlier (at the top of the j
 *   body, 1034 B; before the k loop, 309 B; first statement of the k body or declared with an initialiser before
 *   the break test, 19 B: the load schedule changes), later (just before the s2 read: 1780 B).  pr declared at j
 *   body scope: same as base (5 B) or, with long j, 6 B.
 *   The angle through u16 helpers SinA(u16)/CosA(u16): with pr passed or with pose.rot passed directly, no pr local
 *   used at the reads: same slots as base (5 B) or as long j (6 B).  j as an enum type: 1091 B; signed char j: 91 B.
 *   Diagnostic only: a third pr use does not give a comparable build (frame changes).
 *   Reading: the slot order is a ranking, not a source position: with j*8 a CSE temp it ranks below cos(pr), with
 *   j*8 named (or long) it ranks above pr, and the original has it between.  No natural form found for the middle rank.
 * note (2026-10-05, wave D9r lane S8): residue unchanged at 5 bytes; the file body is unchanged (the earlier
 *   lane left only notes, body identical to HEAD).  Slot facts measured with a Thumb decode of the compiled
 *   bytes (7 real compiles, none repeating a lane 152 or 198 row):
 *   - the compound byte-offset idiom of the sibling 021F546C (`u32 jo = j; jo *= 8;`, head, X and Z read
 *     through (TabEnt *)((char *)ents + jo)): b 2C, cos 30, pr 34, jo 38, flag 3C (7 B).  j*8 is not a named
 *     byte offset: any named local lands above pr, the original has j*8 below pr.
 *   - named locals order by first assignment in the code, not by declaration: with `u16 pr;` declared in the
 *     j body BEFORE jo, pr still lands below jo (pr 34, jo 38).  So declaration order cannot place jo.
 *   - the spilled CSE temps (b*0x14, cos, j*8) always sit below every named local.  The original j*8 (0x34)
 *     is in the temp band, above cos, which is the only pair left swapped.
 *   - statement order tests (second rotation before the first; fz read after the Z read) change the frame
 *     and schedule (836 and 842 B), so they cannot show the pair order.
 *   mwcc source (inspiredrobot/mwcc): Coloring_SelectColors flags a web Spilled in select-stack order and
 *   SpillCode_00531800 (slot assignment, not reconstructed there) runs per retry round; Coloring_SimplifyGraph
 *   picks potential spills by min spill_cost / degree.  Our listing and the original are instruction identical,
 *   so cost and degree of j*8 and cos are equal in both builds; only the web numbering or tie order differs.
 *   Lane 22's diagnostic (no head use of ents[j] gives the original order) fits a numbering reading: the head
 *   use makes j*8 a temp that is created before cos in ours.  No source form that creates cos(pr) before j*8
 *   without moving code was found (cos has no occurrence before the k body in the original listing).
 * note (2026-10-05, final push G2L5, rounds 2 and 3): 16 more real compiles, all DIFF, none better than 5 B.  `u16 j`, `s16 j`
 *   (94/93 B); rx and rz as one expression each with both products (836 B); `long j` with `int pr` at function scope
 *   (18 B), with pr assigned at object level (1794 B), with `u16`/`s16`/`unsigned short` flag (11 B), plus opt_lifetimes
 *   or scheduling off (9 B); head chain through a named `int id = pose.id` (723 B); second rotation rz before rx (652 B);
 *   `Z * cos` operand order (5 B, same).  Also off: opt_unroll_loops, opt_vectorize_loops, opt_findoffsets (5 B).  mwcc
 *   SpillCode.c: spill cost is use count times block weight; earlier lanes' extra-use diagnostics did not move the pair, so
 *   slot order is not cost-driven.  Twin arm9 MCSS_Draw re-read: no k-body pr rotation, nothing to borrow.
 * note (pass 2 2026-10-06 P2L09): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Slots low to high of the triple j*8 / cos(pr) / pr (flag 0x3C in all rows unless said):
 *   - `#pragma opt_strength_reduction off`: cos 30, pr 34, j*8 38 (6 B), the same as `long j`.  So strength
 *     reduction is what ranks j*8 below cos.  Under SR off: pose.rot for pr everywhere, pr at j-body or function
 *     scope (3 positions), u16 pr with an int/u32 `pi = pr >> 4` index, `(pr = pose.rot) + sub.rot`: SR-off row
 *     (6 to 7 B); int or u32 pr: cos 30, j*8 34 (correct), flag 38, pr 3C (9 to 10 B); pose.rot in ang only:
 *     pr 30, cos 34, j*8 38 (8 B).  SR off plus opt_loop_invariants off: 1501 B; plus opt_lifetimes off: SR-off row.
 *   - SR on, pose.rot spelled in ang only (pr kept for s2 and both cos reads): pr 30, j*8 34 (correct), cos 38,
 *     5 B.  In that form, same 5 B and same slots: ang before `pr = pose.rot`, pr declared at function scope,
 *     j-body scope or first in the k body, pr assigned right before s2, SinA/CosA(u16) inlines on pr.  Back to
 *     the base order (5 B): int pr, an int `pi = pr >> 4` or `pi = pose.rot >> 4` index, SinA/CosA(pose.rot).
 *     u32 pr 6 B; plus long j 8 B.  pose.rot in rz cos only 653 B, rx cos only 505 B, both cos or s2 only 10 B.
 *   - j*8 written as `(char *)ents + (j << 3)` at all three uses: base slots, 6 B (add operand byte); at the head
 *     only or the k loop only: 1040 B (CSE lost).  opt_loop_invariants plus opt_lifetimes off: 5 B (base).
 *   Four orders of the triple are reachable (j8<cos<pr, cos<pr<j8, pr<j8<cos, cos<j8 with pr above flag); the
 *   original cos<j8<pr<flag was not produced.
 * note (pass 3 2026-10-06 P3L04): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   New regime: the second-rotation cos stored in the first-rotation `c` with `rz += FxMul(X * s2 + Z * c, psy)`
 *   (operand order Z * c removes lane 152's extra copy): 7 B, j*8 0x34 and pr 0x38 now correct, but the c web
 *   takes 0x2C and b*0x14 moves to 0x30 (original b*0x14 0x2C, cos 0x30).  In that regime, same 7 B: s also
 *   reused for s2, s or fx reused for cos, int/u32 b, the assignment inside the rx argument, opt_loop_invariants
 *   off.  Worse: `c * X` (18 B), plus pose.rot in ang (13 B), plus SR off (13 B), plus opt_lifetimes off (546 B),
 *   c at function scope (684 B), c and s2 moved above the X/Z reads (851 B), CosA/SinA(u16) inlines (14 B).
 *   Same 5 B base slots: s reused for s2 only; an int idx index local for s2 only; RotX/RotZ inlines reading the
 *   table; a named TabEnt *e for the k-loop reads; rx/rz as a local struct; c assigned from one read with the other
 *   read inline (either order); opt_strength_reduction_strict on.  Worse: idx local in some cos reads only
 *   (508 B / 9 B), a const s16 *sc pair pointer for one cos read (502/508 B), named c2 with Z * c2 at three
 *   declaration places (14/23/64 B), separate x1/z1/x2/z2 running locals (898 B); SR off plus an `int id = j`
 *   alias at the head or in the k loop gives the SR-off row (6 B).  Reading: a reused variable's second web ranks
 *   below every optimizer temp, a first named web ranks in the named band, so cos in the original is a temp made
 *   after the SR-created j*8 web and before b*0x14; no source form found that delays the cos CSE that way.
 * note (pass 4 2026-10-06 P4L03): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Same 5 B: RotA/RotB inlines with cos as a parameter and `Z * c`; a `const s16 *sc` pair pointer with
 *   `Z * sc[1]` (with or without s2); `s16 sc[2]` with `Z * sc[1]`; rx/rz as `int r[2]` (const or non-const
 *   table); `register` on pr or j.  Long-j row (6 B, flag 3C, j*8 38, pr 34, cos 30): u16 pr reused at
 *   function scope for either G3 angle; s2 read above the X/Z reads (77 B, same slots); the head .h read as
 *   a byte offset `j * 8 + 6` or `(j << 3) + 6` (merged under long j); `u16 pr = 0;` initialisers.  Long j
 *   plus int pr with `pr >>= 4`: 9 B (pr 3C, flag 38); with u16 pr: 10 B (pr 3C, lsrs).  Long j plus int pr
 *   reused for the obj+0xFC G3 angle: 18 B (pr 0x48).  `int sc[2]` for s2/cos: 14 B (the array-to-register
 *   web takes 0x3C above flag).  Worse: `pr / 16` (15 B all reads, 656 B rz only), a {s, c} struct copied
 *   from the table (576 B), one cos read as a char* byte offset (495/504 B: the table load is never merged
 *   after CSE0), opt_propagation off (1898 B), opt_common_subs off (1438 B).  Reading (research in the lane
 *   folder): the global table load is merged only by the first CSE, so cos is always numbered before the SR
 *   j*8 web; without SR on j, j*8 is numbered at the j-loop head, before the k-top pr.  The original order
 *   (flag, pr, j*8, cos) needs one of the two moved, and no source form found does that.
 * note (pass 5 2026-10-06 P5L02): residue unchanged at 5 bytes; the body is unchanged.  41 real compiles.
 *   New forms, none better: `int b` reused as the Part byte offset (`b *= sizeof(Part)`) with the cos stored in the
 *   first-rotation c (or s, fx): instructions identical, 7 B, j*8 and pr right but b*0x14 30 above the c web 2C (both
 *   are second webs and rank by def position, so b*0x14 at the k top always ranks above the cos); declaration order
 *   of b and c in that form: same or 593/684 B.  A local struct {int s, c} for s2/cos: 14 B (promoted, cos 3C above
 *   flag).  Function-scope `s16 sn, cs` shared with the object-level G3 rotation, cs reused for the k-loop cos: 5 B
 *   base slots (narrow reuse is transparent); as int: 23 B (decl slot 0x48); a j-body `int n` node index reused for
 *   the cos: 23 B; the function-scope int ox reused: 821 B.  Same 5 B: a `u16 pr2 = pr` (or int) copy for the rz
 *   cos read (value numbering sees through it), a k-loop `const s16 *tab` for all table reads, pose.rot spelled
 *   everywhere, a named s16 c2, the break as a goto, pr first assigned at the object-level G3 angle.  Named jo
 *   (head or k loop): 7 B or 1040 B.  Strength reduction off or long j in the reuse forms: 13 B (J P B C order).
 *   Reading (research in scratchpad wD9r/p5_P5L02): every measured order fits one birth-phase ranking (decl webs and
 *   promoted aggregates, then code-order webs flag/pr/cos with the head j*8 first when not strength reduced, then
 *   strength-reduced j*8, then load-deletion temps, then b*0x14, then second webs of reused ints).  The original
 *   needs j*8 between pr and cos, which no tested source form produces.
 * note (pass 6 2026-10-06 P6L10): residue unchanged at 5 bytes; the body is unchanged.  4 real compiles plus about 25
 *   traced compiler runs (tools in scratchpad wD9r/p6_P6L10).  FX_SinIdx/FX_CosIdx inlines (`T[((idx >> 4) << 1)]`, + 1):
 *   5 B, the parameter is propagated before the first CSE and cos stays a first-run temp.  The b*0x14 split at the first
 *   CSE is caused by any branch between the uses, but only for the b chain (index under a memory-loaded base); the
 *   const-table pr/cos chain crosses the same branches at the first CSE.  Single-use locals for the rz read (pointer,
 *   cos value, second pose.rot read) are propagated back before the first CSE or leave the load read twice.  `long j`
 *   plus `int pr`: 9 B with j*8, cos and b*0x14 correct and only pr/flag swapped; the trace shows that the flag slot
 *   is the CAST(flag) temp and a named int pr outranks every temp, so the original pr must be a temp created between
 *   the flag temp and the k-preheader j*8 temp, where no pr occurrence exists.  `#pragma opt_loop_invariants off`
 *   with s2 above the X/Z reads: 77 B (the head j*8 stops being a CSE candidate).
 * note (pass 6 2026-10-06 P6L02, round 2): residue unchanged at 5 bytes; the body is unchanged.  Traced why j*8 and
 *   b*0x14 are second-run CSE temps: their uses differ at the first CSE (k-loop j*8 rewritten into CAST/MUL temps by the
 *   loop transforms; b uses split by the arg() call) and become equal after copy propagation.  Tried for cos(pr), each
 *   traced: an index local for the rz read only (propagated back before the first CSE, 5 B); an index local for s2 and
 *   rz (508 B, the loads stay different); a cos local (441 B); a const s16 *sc for s2 and rz (508 B).  Both cos reads
 *   are in one block with no call between, so the first CSE always merges them; a store, a call or a struct copy put between the
 *   two rotations (diagnostics) does not split them either.  A CSE run names each temp at the first reuse of the
 *   expression (pr at the s2 read, cos at the rz read), so j*8 between them needs a j*8 reuse inside the rx statement.
 * note (pass 6 2026-10-06 P6L02): residue unchanged at 5 bytes; the body is unchanged.  New method: mwccarm traced
 *   under a debugger (tools in scratchpad wD9r/p6_P6L02).  Measured: spill slots follow the creation order of the
 *   compiler temps ("@N" names, lower N = higher slot).  The temps are made by IRO_CommonSubs, which runs twice here;
 *   each run names its temps in IR program order.  Ours: the (int)pr temp and cos(pr) are made by the first run, j*8
 *   only by the second run (at the j-loop head), b*0x14 later in the second run.  With long j the first run names
 *   j*8 at the head (above pr).  The original order needs cos(pr) to become common only in the second run (its two
 *   reads must differ at the first CSE and become equal through the copy/expression propagation that runs between
 *   the two CSE runs), or j*8 named in the first run between the s2 read and the rz cos read.  No such form found:
 *   a pr2 copy is removed before the first run (5 B), a second pr = pose.rot reloads pose (653 B).  The same 5 B with
 *   dsi 1.1 to 1.6sp2; the hidden opt_* pragmas tested have no effect.
 * note (pass 6 2026-10-06 P6L12): EXACT (c99 and c).  The residue was the declaration-order ranking of named
 *   spill webs, not CSE timing.  Measured with the temp tracer: named locals take spill slots in declaration order,
 *   above all compiler temps.  Three changes together give the original slots (flag 3C, pr 38, j*8 34, cos 30):
 *   (1) `long j` (NitroSDK s32): j*8 becomes a first-run CSE temp at the k preheader, above cos;
 *   (2) the MUSICAL_MCSS_DrawSprite prototype takes the flag as `u8` (the matched callee is EXACT with `u8 mode` as well),
 *   so the u8 flag is passed without a widening cast and keeps its own named web (no CAST(flag) temp);
 *   (3) C89-style function-scope declarations: the k-loop ints (ang, fx, ... rz) before `u8 flag`, then `int pr`.
 *   With int pr and the u8 flag named, declaration order places ang/fx/X, flag, pr in the original order.
 */
/*
 * note (2026-10-04, wave D3 lane 03): first complete structural draft, not tuned.
 *   Listing extent 021F56BC..021F5EDC (2080 bytes), frame 0x254, mid pool at 021F5A24
 *   (0x04000444, 02148D8C/98/A4, 021F8310/1C/04, 02148B98, 0xFFFFF000, 0xFFFA0000,
 *   02148B54, 0x04000470, 020A1B38 sin/cos table, 0x0400046C) and tail pool 021F5ED0.
 *   Shape: G3 setup (push, mode 0, store 0, mode 3, identity, mode 2); camera pick by
 *   p->f8 bit 0; outer loop i < p[0] over p[1][i] objects, skip null or (fEC >> 2) & 1;
 *   per object a 16-byte pose rec at sp+0x244 filled by kind 0/1/2 of
 *   obj+0x28 -> [0x1c] -> f4; translation/rotation/scale writes; MUSICAL_MCSS_SetupG3;
 *   polygon attr word built from bitfields at obj+0x90; inner loop j over parts of
 *   p->f6C->f4[rec.id]; second pose rec at sp+0x234; two MUSICAL_MCSS_DrawSprite calls;
 *   innermost k < 8 over bytes ent[0x30+k] != 0xFF with s64 fixed point math and
 *   an indirect call through p->fF8.
 *   Known hard parts: the compiler derives small constants from register-held I/O
 *   addresses (lsrs r1, r0, #0x13 = 0x80 from 0x04000470; lsrs #0xe = 0x1000 from
 *   0x0400046C; r0 >> 0x12 = 0x100), the float rounding idiom
 *   (v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) then _ffix, and the
 *   many spilled loop-invariant offsets at sp+0x80..0xAC (0x80 constants and
 *   field offsets r5-8, r5-4 with r5 = 0x10C).
 *   The innermost k-loop math is an approximation of the listing (021F5BD4..021F5E8C),
 *   re-derive it from the listing before tuning.
 *   Verdict of this draft: DIFF, compiled 1680 bytes vs 2080, 1623 bytes differ, 52 of 55
 *   relocations resolved. Prologue already differs (push r3 extra, frame 0x198 vs 0x254):
 *   the original keeps more stack locals (spilled invariants at sp+0x80..0xAC, s64 halves
 *   at sp+0x68..0x74, sub-pose rec at sp+0x234, 0x5C-byte source records).
 *   Siblings: MUSICAL_MCSS_DrawSprite (callee, 13 args, see 021F5B6A..021F5BCC for the stack layout).
 *
 * note (2026-10-05, wave D4 lane 06): p->f8 bit 0 is now read through a one-bit bitfield
 *   (Bits.b0): the camera pick now gives the original lsls #0x1f; lsrs #0x1f test (1623 -> 1611
 *   bytes differ, compiled 1684 vs 2080).  Still open: the frame (0x254 vs 0x198, push without
 *   r3), the zero local stored at [sp] at entry, the spilled invariants, and the innermost k-loop
 *   which still needs re-deriving from the listing (021F5BD4..021F5E8C).
 *
 * note (2026-10-05, wave D5 lane 06): body rewritten from a fresh reading of the listing
 *   (the code after the mid pool needs `show --addr 0x021F5A5C --size 0x480 --thumb`, the
 *   default show desyncs at 021F5A44).  Fixes: r4 is obj for the whole loop, so the j/k loops
 *   read obj+0x6C/0x68/0x20/0x24/0xF8, MUSICAL_MCSS_DrawSprite takes obj (not p) and &cb.z (sp+0xB8,
 *   zeroed per object), and the indirect call goes through the second parameter `arg`
 *   (`arg((u8)pt->f4, &cb.pos, obj->fF8)`); a 0x3C-byte callback record at sp+0xB4 (w out
 *   word, z, pos with y negated, x2/y2 scaled by obj->fD4/16 and fD8/16, z, obj+0xD4 vec,
 *   obj+0x100 vec, obj->fFC, ang + (pt->f10 << 11)); on pt->f4 == 5 the result goes to
 *   obj+0x100/0x104/0x108.  k loop: two rotations (part by pose.rot + sub.rot scaled by the
 *   pose*sub scale, then the table entry (x, z at +2/+4) plus pose.dx/dz by pose.rot scaled by
 *   pose.sx/sy), operand order (s64)vec * scale.  Else-branch: a local 4x4 matrix filled with
 *   constants at sp+0x114, MTX_Copy43To44_(&d_02148B98, &m4), func_0207BE14(&m4, &d_02148B54,
 *   &m4), second MUSICAL_MCSS_CalcMatrix uses that matrix.  Sub-pose kind 0 leaves dz unset.  obj skip
 *   test reads p[1][i] twice and bit 2 of obj->fEC as a bitfield; obj+0x90 and obj+0x68 are
 *   loop-level pointer locals (sp+0x5C, sp+0x50).  Result: compiled 1996 vs 2080 (was 1684),
 *   frame 0x248 vs 0x254, prologue and the obj test now line up modulo slot numbers.
 *   Open: the zero stored at [sp] at entry (push without r3 in the original), the i slot
 *   (0x5C vs 0x58), mid-pool placement (original after the attr word at 021F5A20), LoadPose
 *   register shape (original keeps src = obj+0x28 in r0), the eight spilled 0x800 rounding
 *   words at sp+0x80..0x94/0x9C/0xA0 and the 0x100/0x10C offsets at sp+0x98/0xA4..0xAC.
 * note (2026-10-05, wave D6 lane 01): three fixes from a fresh reading of the head and the pose loader.
 *   (1) G3i_LookAt_ takes a fifth argument (NULL, as in the matched callers): the zero stored at [sp]
 *   at entry is that stack argument, written once before the camera-pick branch. The prologue now
 *   matches to 021F56F8 apart from the frame size. (2) LoadPose is a switch on the u16 kind with a
 *   compare chain (beq 0, cmp 1, cmp 2, b out), and the id is a u16 read (ldrh) through a
 *   {u16 id; u16 pad; s16 dx; s16 dz} source record. (3) obj+0x90, obj+0x68 and obj+0x28 come from
 *   static inline accessors (ObjAttr, ObjSrcs, ObjAnim): the parameter copy gives the original
 *   `adds r0,r4,#0; str [sp,#K]; adds r0,#0x90; str [sp,#K]` double store for srcs and keeps src =
 *   obj+0x28 in r0 for the kind load (`ldr r3,[r0,#0x1c]`). Compiled 2008 vs 2080 (was 1996).
 *   Open: frame 0x24C vs 0x254 (8 bytes of locals missing, every sp offset is 8 low), attr (obj+0x90)
 *   stays in r5 where the original spills it to sp+0x5C, the zero/kind registers in the obj head
 *   (original zero r2, kind r3; ours zero r3, kind r1), and everything after 021F57BC not re-checked.
 * note (2026-10-05, wave D7 lane 01): read only, no new build. The original spills attr (obj+0x90) to
 *   sp+0x5C and reloads it three times for the attr word (021F59EE, 021F59F0, 021F5A00); r5 is a
 *   short-lived temp there (0x10C offset at 021F59A6). So the original has more long-lived values than
 *   ours; the 8 missing frame bytes are likely two more spilled locals. Also: the callback arg is
 *   ov112 MUSICAL_MCSS_SetMatrix (mode = (u8)pt->f4, in = &cb.pos, p = obj->fF8), see that draft for the
 *   0x38-byte slot layout of obj->fF8.
 * note (2026-10-05, wave D8 lane 01): three local shape fixes from the listing at 021F58C4..021F591E.
 *   (1) The pos and (ox, oy, 0) MTX_TRANS writes are a G3_Translate(x, y, z) static inline: the
 *   original loads all three values before the three stores (ldr r3,[sp,#0x230]; ldr r2; ldr r1;
 *   str; str; str); 0x0400046C writes are G3_Scale(sx, sy, 0x1000). (2) The flag increment is
 *   `flag++` on the u8 local: the original reloads the spilled zero and does adds/lsls/lsrs, where
 *   `flag = (u8)(flag + 1)` folds to movs #1. (3) The rotation ternary has no inner (u16) cast:
 *   `u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;` truncates once after the join, as in the
 *   original. Compiled 2012 vs 2080 (byte count is not comparable, every later offset shifts).
 *   Still open: frame 0x24C vs 0x254. The original spill area is 8 bytes larger (struct locals start
 *   at sp+0xB4 in the original, sp+0xAC in ours), so the original spills two more values; attr
 *   (obj+0x90) is one of them (sp+0x5C, ours keeps it in r5). G3_Translate(pos) still takes r2/r1/r0
 *   for z/y/x and r3 for the register base, the original r3/r2/r1 and r0. The rounding constant
 *   0x800 is derived from the halfword offset 2 held in r6 (`movs r6,#2; ldrsh r1,[r2,r6]` then
 *   `lsls r2,r6,#0xa`), ours does the same from r7. The k-loop past 021F5A5C was not re-checked.
 * note (2026-10-05, wave D9 lane 04): six fixes from a fresh reading of the j/k loops (compiled 2064 vs
 *   2080; on a register-blind instruction diff 94 lines differ, was 210).  (1) obj->f6C has one more
 *   level: the record table is at obj->f6C->f4 (as in matched MUSICAL_MCSS_DrawSprite, McssSpriteSet/Tab/TabEnt), both in
 *   the j-loop test and for the entry reads.  (2) The sub-pose uses the same LoadPose switch: kind 0
 *   also zeroes dz, by cross-jumping into the kind 2 tail (listing 021F5AE6 b 021F5B1A).  The entry
 *   te and the part pt are not locals: j*8 and b*0x14 are spilled CSE values and every read is
 *   written inline.  (3) The 0x1D write goes to 0x0400044C (MTX_STORE), not 0x04000450.  (4) Every
 *   fixed-point product is a FxMul(s64 a, s64 b) static inline: it puts the vector in r0:r1 and the
 *   scale in r2:r3 and spills fx/fz with s/c in r5/r6, as in the original.  psx/psy are s64 locals
 *   assigned before the first product (the original sign-extends both before the first _ll_mul).
 *   (5) obj->fEC bit 0 is a one-bit bitfield.  (6) Declaration order `fx, fz, c, s, X, c2, Z, s2`
 *   gives the original registers in both rotations; the attr word is written right-nested
 *   a7 | (0xF0000 | (a4 | (a3 | (a5 | a0 | 0x40000000)))) to get the original OR order.
 *   Still open: frame 0x250 + push r3 vs 0x254. The original spills attr (obj+0x90) to sp+0x5C and
 *   keeps &pos in r7 across the two MUSICAL_MCSS_CalcMatrix calls; ours keeps attr in r5 and rematerialises
 *   &pos.  Tried without effect: attr declaration position, block scope, a struct type, a PolyAttr
 *   inline, a Persp inline and a `Vec *pp` local for the 660C calls.  A separate `int w` local (not
 *   cb.w) gives the 0x254 frame but puts w at sp+0xB0, not 0xB4, so it is not the answer.  The k-loop
 *   head schedules the fx/fz loads before `ang` (original: ang first); `ent->parts[k]` inline instead
 *   of `b` is worse.  `j = 0` sits after the first scale product in the original; only an unnatural
 *   split of the sy/sx block reproduces it.
 * note (2026-10-05, wave D9r lane 22): 94 -> 0 instruction lines differ; 5 bytes left (two spill slots).
 *   (1) The 0x040004A8 word is the SDK inline G3_TexImageParam with enum parameter types, as in the
 *   matched sibling arm9 MCSS_Draw (same renderer: same matrix calls, Pose switch, TexInfo record
 *   at obj+0x90 with addr/s/t/fmt/pltt0 at 0/0xC/0x10/0x14/0x1C).  With it, attr spills to sp+0x5C and
 *   &pos stays in r7 across the MUSICAL_MCSS_CalcMatrix calls; the frame is 0x254 and the push has no r3.
 *   (2) attr, srcs and a new ctrl (obj+0x28) are plain assignments in the order attr, ctrl, srcs (the
 *   accessor inlines are gone; they made no difference once attr spills).  (3) Declaration order
 *   ent, attr, i, j, srcs, k gives the original slots.  (4) for (j = 0; ...) without the early
 *   j = 0 statement: the 0 is shared with the first FxMul high word, as in the original.  (5) ang is an int
 *   (u16 cast at the assignment).  (6) X = te.x; X += pose.dx; (same for Z) gives the te.x-first load
 *   order.  (7) c2 (the cos of pr) is written inline at both uses: the original spills it as a CSE
 *   temp (lowest slot, reload with no copy).  (8) The obj+0x100 write is VEC_Set(v, x2, y2, 0), which
 *   loads y2 before x2.
 *   Residue: the CSE temps j*8 and c2 have swapped slots (original j*8 sp+0x34, c2 sp+0x30; ours the
 *   reverse).  A diagnostic without the j-loop use of ents[j] gives the original order, so the j*8
 *   temp is created later than c2 in ours.  Tried without effect: s2 inline too, c/s inline (worse),
 *   an idx local, operand order of the c2 products, k-loop locals at function scope, a te local in
 *   the k loop, src passed straight to LoadPose, named c2 in any scope (goes to the named slots).
 * note (2026-10-05, wave D9r lane 53): residue unchanged at 5 bytes (j*8 CSE temp at sp+0x30, cos(pr) temp
 *   at sp+0x34; original reverse).  One clean-up: the `one` local (0x1000 for the sub-pose LoadPose) is
 *   gone; LoadPose(&sub, src, 0x1000) gives the same bytes (the 0x1000 reload from sp+0x64 is the
 *   compiler's own hoisted constant).  Tried without effect on the slot pair (each a real compile): a TabEnt
 *   pointer or a u16 h local for the head read; `int id = j` alias at head or in the k loop; the j loop and the
 *   k loop as if/do-while; pose.rot inline (no pr local; same bytes); s2 load moved above the X/Z reads; X/Z
 *   reads as (ents + j)->x, as a Cell() inline, or as byte offsets (j * 8 + 2) in both head and k loop
 *   (byte offsets in the k loop only stop the j*8 CSE and LICM-hoist a second copy); cos(pr) spelled four
 *   other ways (1 + idx, (T + idx)[1], &T[idx][1], idx << 1) and through a Cos() inline; RotX/RotZ inlines and
 *   an FX_MUL-style macro for the second rotation (worse); a `const s16 *sc` pointer for s2/cos (worse);
 *   k-loop declaration order.  The pair stays swapped in every variant, so its order is probably fixed by the
 *   colouring tie-break, not by source position of the two expressions.
 * note (2026-10-05, wave D9r lane 90): residue unchanged at 5 bytes (same slot pair).  Compared with the
 *   matched twin arm9 MCSS_Draw line by line and tested new forms, each a real compile.  Same 5 bytes:
 *   outer i loop as the twin's `i = 0; if (n > 0) do { } while (++i < n);`; a typed MAnim/Frame chain
 *   (`((Obj *)obj)->anim->frames[pose.id]`) instead of the raw obj+0x6C casts; the node as a 0x5C-byte
 *   struct array (`&(*nodes)[idx]`, as the twin); a frame-cells pointer local at the head; a named int
 *   node index at the head; SDK FX_SinIdx/FX_CosIdx inlines (int idx, fx16 return) for every table
 *   read; the break test as `if (ent->parts[k] == 0xFF) break; b = ent->parts[k];`; the rotated vector
 *   in vx/vz locals before the two FxMul calls.  Worse: the head index through a NodeIdx() inline
 *   (loses the loop-condition entry pointer, 1056 B); the k loop as a static inline (not inlined,
 *   1832 B); `k < 8 && parts[k] != 0xFF` in the for condition (744 B); X/Z as one expression each
 *   (64 B).  Diagnostics (not candidates): a third use of the cos(pr) temp, X/Z reads moved to the top
 *   of the k loop, and no Z read all keep ours order (j*8 below cos(pr), b*0x14 lowest), so the order
 *   does not follow use count or program position of the k-loop reads.
 * note (2026-10-05, wave D9r lane 107): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp sp+0x34;
 *   original reverse).  New tries, each a real compile: FxMul with int (fx32) parameters as in the twin's
 *   FX_MUL, with s64 or int psx/psy (89 B, worse); cos(pr) as an int-typed value ((int) cast at both uses,
 *   or an int-returning CosI() inline; same 5 B); 5EDC prototype and Ent fields as int, as in the matched
 *   MUSICAL_MCSS_DrawSprite, and 660C with its matched const int / u32 parameters (same 5 B); `int b` for the part
 *   byte (same 5 B); s16 (fx16) locals for s2, for c/s, or for all three (508 to 728 B, worse); named c2 in
 *   three placements (430+ B, adds a copy); mixed spellings for the X/Z reads (index for one, byte offset
 *   for the other: 870 B; `(ents + j)->x` for X only: same 5 B).  Diagnostics: `int pr` swaps the pr and
 *   flag slots (0x38/0x3C), so local width moves slot order; an extra k-loop use of ents[j] does not move
 *   j*8 off sp+0x30.  The slot order of the two CSE temps does not follow use count or type.
 * note (2026-10-05, wave D9r lane 124): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  Tested the inline-return-temp idiom (ov125 021D6B40) on every helper in
 *   the j/k loops, each a real compile: LoadPose hand-expanded for sub, and for both pose and sub (output
 *   identical to the draft, byte for byte); RoundF hand-expanded as a plain ternary and with a block-local
 *   `int v` (identical); the two second-rotation FxMul calls hand-expanded with a block-local s64 operand
 *   (identical) or as one expression (2084 B, worse); a Cell() inline returning &ents[j] at all three
 *   uses, head included (1056 B).  So the inlines are transparent here; no inline temp sets this pair.
 *   Also tried: the head .h read as a byte offset (j*8+6: 1040 B) or as (ents + j) cast to char * (same
 *   5 B); an index local for s2/cos(pr) as u32, int (same 5 B) or u16 (483 B).  Diagnostics: `u32 j`
 *   and a branch between the two cos(pr) uses keep ours order.
 * note (2026-10-05, wave D9r lane 135): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  New head-of-j-loop forms, each a real compile, all give the same 5 B
 *   (the front end normalises them to one tree): a `Tab *tab` assigned in the loop condition
 *   (`j < (tab = &T[pose.id])->count`) and read at the head as tab->ents[j].h, also through a TabEnt
 *   pointer local taken from tab (te = tab->ents; te[j].h, or te = &tab->ents[j]); entries as a u16/s16
 *   halfword array at all three uses (`((u16 *)ents)[j * 4 + 3]`, x/z at j * 4 + 1 / + 2); getters that
 *   take the already-computed ents (or &T[pose.id]) plus j: EntH(e, j), EntAt(e, j)->h, EntIdx(e, j),
 *   TabEntAt(t, j)->h (head only: same 5 B; also at the X/Z reads: 6 B, add operand swap); src at
 *   function scope.  Worse: a struct copy `TabEnt e = ents[j]` at the head (1100 B); h as an 8-bit
 *   bitfield pair (u16, s16 or u32 fields: 998 to 1056 B, lsls/lsrs instead of and/asr); the u16 head
 *   read only (X/Z left as fields: 1040 B); tab also used at the X/Z reads (1136 B, tab held in a register).
 *   Off the head, also same 5 B: a non-const `s16` table (as in the twin), the table named
 *   FX_SinCosTable_, s2 and the second rotation in a nested block.  Diagnostics: without cos(pr) as a CSE
 *   (second use replaced) j*8 stays at sp+0x30, so it is the cos(pr) temp that lands above j*8; without
 *   the head use j*8 becomes a LICM temp at sp+0x3C (above the narrow pr/flag locals) and cos(pr) drops
 *   to sp+0x30.  No head spelling reached changes the temp order.
 * note (2026-10-05, wave D9r lane 152): residue unchanged at 5 bytes; the file body is unchanged.
 *   New tries, each a real compile.  The slot order of the late group (flag, pr, j*8, cos(pr), b*0x14)
 *   moves with the declared TYPE of j, not with any spelling of the expressions:
 *   - `long j` (or s32/unsigned long): j*8 goes to sp+0x38, above pr (pr 0x34, cos 0x30 correct, b*0x14
 *     0x2c correct): 6 B.  `unsigned int j` keeps ours order (7 B).  The type of i, of the k-loop
 *     locals (long/fx32), of b (int), of u32 (unsigned long), and fx32 struct fields do not move it.
 *   - `long j` plus `int pr` (or long pr): j*8 0x34 and cos 0x30 are correct, but pr and flag swap
 *     (pr 0x3C, flag 0x38): 9 B.  So the original needs u16 pr with j*8 between pr and cos; no type
 *     pair of (j, pr) gives that.
 *   - reusing the first-rotation `c` (or `s` and `c`) for the second rotation: j*8 goes to 0x34, but
 *     the second web of c gets the lowest slot (0x2C, below b*0x14) and the rz product gains a copy
 *     (431 B).  A named s16 c2 also adds the copy and stays at 0x34.
 *   - pose.rot spelled in place of pr in ang, s2, or one/both cos reads: j*8 goes to 0x34, but pr
 *     takes a late slot (0x30) and cos moves to 0x38 (5 to 10 B; split spellings also break the
 *     shared T+idx address).
 *   - same 5 B: cos and sin as a {sin, cos} struct table (cast or extern), five mixed spellings of one
 *     cos read (1 + idx, (T + idx)[1], *(&T[i] + 1), (idx << 1) + 1, (&T[i])[1]), FX_SinIdx/FX_CosIdx
 *     with int or long idx (with long j), pr declared with an initialiser in a block, pr at function
 *     scope reused for the G3 rotation angles (with long j: still 6 B), b assigned after its
 *     declaration, an unreferenced label between the products, byte-offset j * sizeof(TabEnt) reads.
 *   Worse: RotA/RotB inlines taking cos as a parameter (432 B, rz product copy); a `const s16 *sc`
 *   pointer (432 B); a 5EDC prototype with a long j parameter (j itself moves to the late group).
 *   Reading of the pattern: the late slots look like spill temporaries in the order the allocator
 *   spills them (round by round, then by definition order).  cos(pr) is in the first round in every
 *   variant; the original needs it in a later round than pr.  No natural source change found that
 *   does this without moving another slot.
 * note (2026-10-05, wave D9r lane 198): residue unchanged at 5 bytes; the file body is unchanged.  Lane 152's
 *   suggestion (long j or s32 plus a way to push pr back above j*8 with pr still u16) tested as a table; every row a
 *   real compile.  Slots low to high (b*0x14 is 0x2C in every row):
 *   original                     cos 30, j*8 34, pr 38, flag 3C
 *   base (int j)                 j*8 30, cos 34, pr 38, flag 3C: 5 B
 *   long j / unsigned long j     cos 30, pr 34, j*8 38, flag 3C: 6 B (8 B for unsigned long: extra loop-test byte)
 *   unsigned int / size_t j      as base, 7 B (loop-test byte differs)
 *   named `int jo = j * 8;` (head, X and Z read through ((TabEnt *)((char *)ents + jo))), int or u32, any
 *   declaration order of {jo, pr, flag} at function scope (6 orders), jo at function or j-body scope:
 *                                cos 30, pr 34, jo 38, flag 3C: 7 B (the X/Z add operand order also changes)
 *   named jo plus a redundant second `jo = j * 8;` BEFORE the last use (idiom a-redundant-second-assignment...;
 *   after the loadpose, before the 5EDC calls, before the k loop, first or after the break test in the k body):
 *                                jo 30, cos 34, pr 38, flag 3C: 6 B.  A second assignment after the last use
 *                                (after cb.pos or at the end of the k body) is dead and gives the single-assign row.
 *   jo declared long or as a char * / void *: long moves it to a high named slot (22 B); a pointer is the base row.
 *   jo split into jh (head) and jk (k loop): as the double-assign row.
 *   So j*8 only ever lands at one of two places: below cos (temp) or above pr (named, or long-typed); the original
 *   needs the slot between them.  Declaration order and scope of jo, pr and flag never moved any slot.
 *   pr changes with long j: `int`, `long`, `u32` or `unsigned long` pr give j*8 34 and cos 30 (correct) but pr 3C and
 *   flag 38 (5 B differ); flag as u16, s16 (same 5 B), int, u32, long with `flag = (flag + 1) & 0xFF` (1429 to 1462 B);
 *   pr s16 or u8 (740 B); pr at function scope as int (14 to 43 B, pr 0x48).  pr read earlier (at the top of the j
 *   body, 1034 B; before the k loop, 309 B; first statement of the k body or declared with an initialiser before
 *   the break test, 19 B: the load schedule changes), later (just before the s2 read: 1780 B).  pr declared at j
 *   body scope: same as base (5 B) or, with long j, 6 B.
 *   The angle through u16 helpers SinA(u16)/CosA(u16): with pr passed or with pose.rot passed directly, no pr local
 *   used at the reads: same slots as base (5 B) or as long j (6 B).  j as an enum type: 1091 B; signed char j: 91 B.
 *   Diagnostic only: a third pr use does not give a comparable build (frame changes).
 *   Reading: the slot order is a ranking, not a source position: with j*8 a CSE temp it ranks below cos(pr), with
 *   j*8 named (or long) it ranks above pr, and the original has it between.  No natural form found for the middle rank.
 * note (2026-10-05, wave D9r lane S8): residue unchanged at 5 bytes; the file body is unchanged (the earlier
 *   lane left only notes, body identical to HEAD).  Slot facts measured with a Thumb decode of the compiled
 *   bytes (7 real compiles, none repeating a lane 152 or 198 row):
 *   - the compound byte-offset idiom of the sibling 021F546C (`u32 jo = j; jo *= 8;`, head, X and Z read
 *     through (TabEnt *)((char *)ents + jo)): b 2C, cos 30, pr 34, jo 38, flag 3C (7 B).  j*8 is not a named
 *     byte offset: any named local lands above pr, the original has j*8 below pr.
 *   - named locals order by first assignment in the code, not by declaration: with `u16 pr;` declared in the
 *     j body BEFORE jo, pr still lands below jo (pr 34, jo 38).  So declaration order cannot place jo.
 *   - the spilled CSE temps (b*0x14, cos, j*8) always sit below every named local.  The original j*8 (0x34)
 *     is in the temp band, above cos, which is the only pair left swapped.
 *   - statement order tests (second rotation before the first; fz read after the Z read) change the frame
 *     and schedule (836 and 842 B), so they cannot show the pair order.
 *   mwcc source (inspiredrobot/mwcc): Coloring_SelectColors flags a web Spilled in select-stack order and
 *   SpillCode_00531800 (slot assignment, not reconstructed there) runs per retry round; Coloring_SimplifyGraph
 *   picks potential spills by min spill_cost / degree.  Our listing and the original are instruction identical,
 *   so cost and degree of j*8 and cos are equal in both builds; only the web numbering or tie order differs.
 *   Lane 22's diagnostic (no head use of ents[j] gives the original order) fits a numbering reading: the head
 *   use makes j*8 a temp that is created before cos in ours.  No source form that creates cos(pr) before j*8
 *   without moving code was found (cos has no occurrence before the k body in the original listing).
 * note (2026-10-05, final push G2L5, rounds 2 and 3): 16 more real compiles, all DIFF, none better than 5 B.  `u16 j`, `s16 j`
 *   (94/93 B); rx and rz as one expression each with both products (836 B); `long j` with `int pr` at function scope
 *   (18 B), with pr assigned at object level (1794 B), with `u16`/`s16`/`unsigned short` flag (11 B), plus opt_lifetimes
 *   or scheduling off (9 B); head chain through a named `int id = pose.id` (723 B); second rotation rz before rx (652 B);
 *   `Z * cos` operand order (5 B, same).  Also off: opt_unroll_loops, opt_vectorize_loops, opt_findoffsets (5 B).  mwcc
 *   SpillCode.c: spill cost is use count times block weight; earlier lanes' extra-use diagnostics did not move the pair, so
 *   slot order is not cost-driven.  Twin arm9 MCSS_Draw re-read: no k-body pr rotation, nothing to borrow.
 * note (pass 2 2026-10-06 P2L09): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Slots low to high of the triple j*8 / cos(pr) / pr (flag 0x3C in all rows unless said):
 *   - `#pragma opt_strength_reduction off`: cos 30, pr 34, j*8 38 (6 B), the same as `long j`.  So strength
 *     reduction is what ranks j*8 below cos.  Under SR off: pose.rot for pr everywhere, pr at j-body or function
 *     scope (3 positions), u16 pr with an int/u32 `pi = pr >> 4` index, `(pr = pose.rot) + sub.rot`: SR-off row
 *     (6 to 7 B); int or u32 pr: cos 30, j*8 34 (correct), flag 38, pr 3C (9 to 10 B); pose.rot in ang only:
 *     pr 30, cos 34, j*8 38 (8 B).  SR off plus opt_loop_invariants off: 1501 B; plus opt_lifetimes off: SR-off row.
 *   - SR on, pose.rot spelled in ang only (pr kept for s2 and both cos reads): pr 30, j*8 34 (correct), cos 38,
 *     5 B.  In that form, same 5 B and same slots: ang before `pr = pose.rot`, pr declared at function scope,
 *     j-body scope or first in the k body, pr assigned right before s2, SinA/CosA(u16) inlines on pr.  Back to
 *     the base order (5 B): int pr, an int `pi = pr >> 4` or `pi = pose.rot >> 4` index, SinA/CosA(pose.rot).
 *     u32 pr 6 B; plus long j 8 B.  pose.rot in rz cos only 653 B, rx cos only 505 B, both cos or s2 only 10 B.
 *   - j*8 written as `(char *)ents + (j << 3)` at all three uses: base slots, 6 B (add operand byte); at the head
 *     only or the k loop only: 1040 B (CSE lost).  opt_loop_invariants plus opt_lifetimes off: 5 B (base).
 *   Four orders of the triple are reachable (j8<cos<pr, cos<pr<j8, pr<j8<cos, cos<j8 with pr above flag); the
 *   original cos<j8<pr<flag was not produced.
 * note (pass 3 2026-10-06 P3L04): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   New regime: the second-rotation cos stored in the first-rotation `c` with `rz += FxMul(X * s2 + Z * c, psy)`
 *   (operand order Z * c removes lane 152's extra copy): 7 B, j*8 0x34 and pr 0x38 now correct, but the c web
 *   takes 0x2C and b*0x14 moves to 0x30 (original b*0x14 0x2C, cos 0x30).  In that regime, same 7 B: s also
 *   reused for s2, s or fx reused for cos, int/u32 b, the assignment inside the rx argument, opt_loop_invariants
 *   off.  Worse: `c * X` (18 B), plus pose.rot in ang (13 B), plus SR off (13 B), plus opt_lifetimes off (546 B),
 *   c at function scope (684 B), c and s2 moved above the X/Z reads (851 B), CosA/SinA(u16) inlines (14 B).
 *   Same 5 B base slots: s reused for s2 only; an int idx index local for s2 only; RotX/RotZ inlines reading the
 *   table; a named TabEnt *e for the k-loop reads; rx/rz as a local struct; c assigned from one read with the other
 *   read inline (either order); opt_strength_reduction_strict on.  Worse: idx local in some cos reads only
 *   (508 B / 9 B), a const s16 *sc pair pointer for one cos read (502/508 B), named c2 with Z * c2 at three
 *   declaration places (14/23/64 B), separate x1/z1/x2/z2 running locals (898 B); SR off plus an `int id = j`
 *   alias at the head or in the k loop gives the SR-off row (6 B).  Reading: a reused variable's second web ranks
 *   below every optimizer temp, a first named web ranks in the named band, so cos in the original is a temp made
 *   after the SR-created j*8 web and before b*0x14; no source form found that delays the cos CSE that way.
 * note (pass 4 2026-10-06 P4L03): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Same 5 B: RotA/RotB inlines with cos as a parameter and `Z * c`; a `const s16 *sc` pair pointer with
 *   `Z * sc[1]` (with or without s2); `s16 sc[2]` with `Z * sc[1]`; rx/rz as `int r[2]` (const or non-const
 *   table); `register` on pr or j.  Long-j row (6 B, flag 3C, j*8 38, pr 34, cos 30): u16 pr reused at
 *   function scope for either G3 angle; s2 read above the X/Z reads (77 B, same slots); the head .h read as
 *   a byte offset `j * 8 + 6` or `(j << 3) + 6` (merged under long j); `u16 pr = 0;` initialisers.  Long j
 *   plus int pr with `pr >>= 4`: 9 B (pr 3C, flag 38); with u16 pr: 10 B (pr 3C, lsrs).  Long j plus int pr
 *   reused for the obj+0xFC G3 angle: 18 B (pr 0x48).  `int sc[2]` for s2/cos: 14 B (the array-to-register
 *   web takes 0x3C above flag).  Worse: `pr / 16` (15 B all reads, 656 B rz only), a {s, c} struct copied
 *   from the table (576 B), one cos read as a char* byte offset (495/504 B: the table load is never merged
 *   after CSE0), opt_propagation off (1898 B), opt_common_subs off (1438 B).  Reading (research in the lane
 *   folder): the global table load is merged only by the first CSE, so cos is always numbered before the SR
 *   j*8 web; without SR on j, j*8 is numbered at the j-loop head, before the k-top pr.  The original order
 *   (flag, pr, j*8, cos) needs one of the two moved, and no source form found does that.
 * note (pass 5 2026-10-06 P5L02): residue unchanged at 5 bytes; the body is unchanged.  41 real compiles.
 *   New forms, none better: `int b` reused as the Part byte offset (`b *= sizeof(Part)`) with the cos stored in the
 *   first-rotation c (or s, fx): instructions identical, 7 B, j*8 and pr right but b*0x14 30 above the c web 2C (both
 *   are second webs and rank by def position, so b*0x14 at the k top always ranks above the cos); declaration order
 *   of b and c in that form: same or 593/684 B.  A local struct {int s, c} for s2/cos: 14 B (promoted, cos 3C above
 *   flag).  Function-scope `s16 sn, cs` shared with the object-level G3 rotation, cs reused for the k-loop cos: 5 B
 *   base slots (narrow reuse is transparent); as int: 23 B (decl slot 0x48); a j-body `int n` node index reused for
 *   the cos: 23 B; the function-scope int ox reused: 821 B.  Same 5 B: a `u16 pr2 = pr` (or int) copy for the rz
 *   cos read (value numbering sees through it), a k-loop `const s16 *tab` for all table reads, pose.rot spelled
 *   everywhere, a named s16 c2, the break as a goto, pr first assigned at the object-level G3 angle.  Named jo
 *   (head or k loop): 7 B or 1040 B.  Strength reduction off or long j in the reuse forms: 13 B (J P B C order).
 *   Reading (research in scratchpad wD9r/p5_P5L02): every measured order fits one birth-phase ranking (decl webs and
 *   promoted aggregates, then code-order webs flag/pr/cos with the head j*8 first when not strength reduced, then
 *   strength-reduced j*8, then load-deletion temps, then b*0x14, then second webs of reused ints).  The original
 *   needs j*8 between pr and cos, which no tested source form produces.
 * note (pass 6 2026-10-06 P6L10): residue unchanged at 5 bytes; the body is unchanged.  4 real compiles plus about 25
 *   traced compiler runs (tools in scratchpad wD9r/p6_P6L10).  FX_SinIdx/FX_CosIdx inlines (`T[((idx >> 4) << 1)]`, + 1):
 *   5 B, the parameter is propagated before the first CSE and cos stays a first-run temp.  The b*0x14 split at the first
 *   CSE is caused by any branch between the uses, but only for the b chain (index under a memory-loaded base); the
 *   const-table pr/cos chain crosses the same branches at the first CSE.  Single-use locals for the rz read (pointer,
 *   cos value, second pose.rot read) are propagated back before the first CSE or leave the load read twice.  `long j`
 *   plus `int pr`: 9 B with j*8, cos and b*0x14 correct and only pr/flag swapped; the trace shows that the flag slot
 *   is the CAST(flag) temp and a named int pr outranks every temp, so the original pr must be a temp created between
 *   the flag temp and the k-preheader j*8 temp, where no pr occurrence exists.  `#pragma opt_loop_invariants off`
 *   with s2 above the X/Z reads: 77 B (the head j*8 stops being a CSE candidate).
 * note (pass 6 2026-10-06 P6L02, round 2): residue unchanged at 5 bytes; the body is unchanged.  Traced why j*8 and
 *   b*0x14 are second-run CSE temps: their uses differ at the first CSE (k-loop j*8 rewritten into CAST/MUL temps by the
 *   loop transforms; b uses split by the arg() call) and become equal after copy propagation.  Tried for cos(pr), each
 *   traced: an index local for the rz read only (propagated back before the first CSE, 5 B); an index local for s2 and
 *   rz (508 B, the loads stay different); a cos local (441 B); a const s16 *sc for s2 and rz (508 B).  Both cos reads
 *   are in one block with no call between, so the first CSE always merges them; a store, a call or a struct copy put between the
 *   two rotations (diagnostics) does not split them either.  A CSE run names each temp at the first reuse of the
 *   expression (pr at the s2 read, cos at the rz read), so j*8 between them needs a j*8 reuse inside the rx statement.
 * note (pass 6 2026-10-06 P6L02): residue unchanged at 5 bytes; the body is unchanged.  New method: mwccarm traced
 *   under a debugger (tools in scratchpad wD9r/p6_P6L02).  Measured: spill slots follow the creation order of the
 *   compiler temps ("@N" names, lower N = higher slot).  The temps are made by IRO_CommonSubs, which runs twice here;
 *   each run names its temps in IR program order.  Ours: the (int)pr temp and cos(pr) are made by the first run, j*8
 *   only by the second run (at the j-loop head), b*0x14 later in the second run.  With long j the first run names
 *   j*8 at the head (above pr).  The original order needs cos(pr) to become common only in the second run (its two
 *   reads must differ at the first CSE and become equal through the copy/expression propagation that runs between
 *   the two CSE runs), or j*8 named in the first run between the s2 read and the rz cos read.  No such form found:
 *   a pr2 copy is removed before the first run (5 B), a second pr = pose.rot reloads pose (653 B).  The same 5 B with
 *   dsi 1.1 to 1.6sp2; the hidden opt_* pragmas tested have no effect.
 * note (pass 6 2026-10-06 P6L12): EXACT (c99 and c).  The residue was the declaration-order ranking of named
 *   spill webs, not CSE timing.  Measured with the temp tracer: named locals take spill slots in declaration order,
 *   above all compiler temps.  Three changes together give the original slots (flag 3C, pr 38, j*8 34, cos 30):
 *   (1) `long j` (NitroSDK s32): j*8 becomes a first-run CSE temp at the k preheader, above cos;
 *   (2) the MUSICAL_MCSS_DrawSprite prototype takes the flag as `u8` (the matched callee is EXACT with `u8 mode` as well),
 *   so the u8 flag is passed without a widening cast and keeps its own named web (no CAST(flag) temp);
 *   (3) C89-style function-scope declarations: the k-loop ints (ang, fx, ... rz) before `u8 flag`, then `int pr`.
 *   With int pr and the u8 flag named, declaration order places ang/fx/X, flag, pr in the original order.
 */
void MUSICAL_MCSS_DrawMC(int *p, void (*arg)(unsigned, Input_021F53CC *, Big *))
{
    Pose pose;
    Pose sub;
    Vec_021F56BC pos;
    Mtx44 m3;
    Mtx43 m1;
    Mtx33 m2;
    Mtx44 m4;
    Mtx44 proj;
    Mtx33 m5;
    CB cb;
    Ent *ent;
    TexInfo *attr;
    int i;
    long j;
    char **srcs;
    u8 k;
    char *obj;
    char *ctrl;
    int ox, oy;
    int ang, fx, fz, c, s, X, Z, s2, rx, rz;
    u8 flag;
    int pr;

    REG(0x04000444) = 0;
    REG(0x04000440) = 0;
    REG(0x0400044C) = 0;
    REG(0x04000440) = 3;
    REG(0x04000454) = 0;
    REG(0x04000440) = 2;
    if ((((Bits_021F53CC *)&p[2])->b0) == 0)
        G3i_LookAt_(&d_02148D8C, &d_02148D98, &d_02148DA4, 1, 0);
    else
        G3i_LookAt_(&d_021F8310, &d_021F831C, &d_021F8304, 1, 0);
    func_0207B67C(&d_02148B98, &m1);
    func_02082B60(&m1, &m2);
    MTX_Copy33To44_(&m2, &m3);

    for (i = 0; i < p[0]; i++) {
        if (((char **)p[1])[i] == 0 || ((Bits3 *)(((char **)p[1])[i] + 0xEC))->b2)
            continue;
        REG(0x04000444) = 0;
        obj = ((char **)p[1])[i];
        attr = (TexInfo *)(obj + 0x90);
        ctrl = obj + 0x28;
        srcs = (char **)(obj + 0x68);
        cb.z = 0;
        LoadPose(&pose, ctrl, 0x1000);
        pos.x = *(int *)(obj + 0xC8);
        pos.y = *(int *)(obj + 0xCC);
        pos.z = *(int *)(obj + 0xD0);
        if ((((Bits_021F53CC *)&p[2])->b0) == 0) {
            ox = pose.dx << 8;
            oy = -pose.dz << 8;
        } else {
            proj.m[0] = 0x80000;
            proj.m[1] = 0;
            proj.m[2] = 0;
            proj.m[3] = 0x80000;
            proj.m[4] = 0;
            proj.m[5] = 0x60000;
            proj.m[6] = 0;
            proj.m[7] = (int)0xFFFA0000;
            proj.m[8] = 0;
            proj.m[9] = 0;
            proj.m[10] = (int)0xFFFFF000;
            proj.m[11] = 0x1000;
            proj.m[12] = 0;
            proj.m[13] = 0;
            proj.m[14] = 0;
            proj.m[15] = (int)0xFFFFF000;
            MTX_Copy43To44_(&d_02148B98, &m4);
            func_0207BE14(&m4, &d_02148B54, &m4);
            MUSICAL_MCSS_CalcMatrix((const int *)(&pos), (const int *)(&m4), (u32 *)(&pos), (u32 *)(&cb.w));
            pos.x = func_0207C768(pos.x, cb.w);
            pos.y = func_0207C768(pos.y, cb.w);
            MUSICAL_MCSS_CalcMatrix((const int *)(&pos), (const int *)(&proj), (u32 *)(&pos), (u32 *)(&cb.w));
            ox = RoundF(pose.dx);
            oy = RoundF(-pose.dz);
        }
        pos.z = *(int *)(obj + 0xD0);
        flag = 0;
        if (*(int *)(obj + 0xD4) < 0)
            flag++;
        G3_Translate(pos.x, pos.y, pos.z);
        if ((((Bits_021F53CC *)&p[2])->b0) == 0)
            func_0207D8FC(&m3);
        G3_Translate(ox, oy, 0);
        {
            u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;
            G3_RotZ(-FX_SinCosTable_[(a >> 4) * 2], FX_SinCosTable_[(a >> 4) * 2 + 1]);
        }

        {
            int sy = FxMul(pose.sy, *(int *)(obj + 0xD8));
            int sx = FxMul(pose.sx, *(int *)(obj + 0xD4));
            G3_Scale(sx, sy, 0x1000);
        }
        {
            u16 a = *(u16 *)(obj + 0xFC);
            func_0207AF38(&m5, -FX_SinCosTable_[(a >> 4) * 2], FX_SinCosTable_[(a >> 4) * 2 + 1]);
            MTX_MultVec33(obj + 0x100, &m5, obj + 0x10C);
            VEC_Subtract(obj + 0x100, obj + 0x10C, obj + 0x10C);
            *(int *)(obj + 0x10C) = func_0207C768(*(int *)(obj + 0x10C), *(int *)(obj + 0xD4));
            *(int *)(obj + 0x110) = func_0207C768(*(int *)(obj + 0x110), *(int *)(obj + 0xD8));
        }
        REG(0x0400044C) = 0x1D;
        MUSICAL_MCSS_SetupG3();
        {
            G3_TexImageParam(attr->fmt, GX_TEXGEN_TEXCOORD, attr->s, attr->t, GX_TEXREPEAT_ST, GX_TEXFLIP_ST, attr->pltt0, attr->addr);
        }
        for (j = 0; j < (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].count; j++) {
            char *src;
            src = *srcs + (((*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].h & 0xFF00) >> 8) * 0x5C;
            LoadPose(&sub, src, 0x1000);
            ent = (Ent *)(*(char **)(obj + 0x20) + 4 + sub.id * 0x38);
            if (ent->f20 != 0) {
                if (((Bits_021F53CC *)(obj + 0xEC))->b0)
                    MUSICAL_MCSS_DrawSprite(obj, ent->f18, ent->f1C, ent->f20, ent->f24, ent->f28,
                                  ent->f2C + ent->f24, &sub, (u16 *)(&pose), j, ((Bits_021F53CC *)&p[2])->b0, &cb.z, flag);
                else
                    MUSICAL_MCSS_DrawSprite(obj, ent->f18, ent->f1C, ent->f20, ent->f24, ent->f28,
                                  ent->f2C, &sub, (u16 *)(&pose), j, ((Bits_021F53CC *)&p[2])->b0, &cb.z, flag);
            }
            MUSICAL_MCSS_DrawSprite(obj, ent->f0, ent->f4, ent->f8, ent->fC, ent->f10, ent->f14,
                          &sub, (u16 *)(&pose), j, ((Bits_021F53CC *)&p[2])->b0, &cb.z, flag);
            for (k = 0; k < 8; k++) {
                u8 b = ent->parts[k];

                s64 psx, psy;
                if (b == 0xFF)
                    break;
                pr = pose.rot;
                ang = (u16)(pr + sub.rot);
                fx = (*(Part **)(obj + 0x24))[b].x;
                fz = (*(Part **)(obj + 0x24))[b].z;
                s = FX_SinCosTable_[(ang >> 4) * 2];
                c = FX_SinCosTable_[(ang >> 4) * 2 + 1];
                psx = pose.sx;
                psy = pose.sy;
                rx = FxMul(fx * c - fz * s, FxMul(psx, sub.sx));
                rz = FxMul(fx * s + fz * c, FxMul(psy, sub.sy));
                X = (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].x;
                X += pose.dx;
                Z = (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].z;
                Z += pose.dz;
                s2 = FX_SinCosTable_[(pr >> 4) * 2];
                rx += FxMul(X * FX_SinCosTable_[(pr >> 4) * 2 + 1] - Z * s2, psx);
                rz += FxMul(X * s2 + FX_SinCosTable_[(pr >> 4) * 2 + 1] * Z, psy);
                rx += RoundF(sub.dx);
                rz += RoundF(sub.dz);
                cb.in.a = pos;
                cb.in.a.y = -cb.in.a.y;
                cb.in.b.x = FxMul(rx, *(int *)(obj + 0xD4) / 16);
                cb.in.b.y = FxMul(rz, *(int *)(obj + 0xD8) / 16);
                cb.in.b.z = cb.z;
                cb.in.d = *(Vec_021F56BC *)(obj + 0x100);
                cb.in.e = *(u16 *)(obj + 0xFC);
                cb.in.c = *(Vec_021F56BC *)(obj + 0xD4);
                cb.in.f = (u16)(ang + ((*(Part **)(obj + 0x24))[b].f10 << 11));
                arg((u8)(*(Part **)(obj + 0x24))[b].f4, &cb.in, *(Big **)(obj + 0xF8));
                if ((*(Part **)(obj + 0x24))[b].f4 == 5) {
                    VEC_Set((Vec_021F56BC *)(obj + 0x100), cb.in.b.x, cb.in.b.y, 0);
                }
            }
        }
        REG(0x04000448) = 1;
    }
    REG(0x04000448) = 1;
}



static inline void G3_TexPlttBase(u32 addr, int fmt)
{
    u32 param = (u32)(addr >> (4 - (fmt == 2)));
    *(volatile u32 *)0x040004AC = param;
}



static inline u32 pk(int v)
{
    return (u16)((v << 8) >> 16);
}



static inline void G3_TexCoord(u32 s, u32 t)
{
    *(volatile u32 *)0x04000488 = s | (t << 16);
}



static inline void G3_Vtx(u32 xy, u32 z)
{
    *(volatile u32 *)0x0400048C = xy;
    *(volatile u32 *)0x0400048C = z;
}



/*
 * 2026-10-05 wD5 lane16: EXACT. The record access is written in full at each use
 *   (`(*(struct McssSpriteSet **)(p + 0x6C))->tbl[*pa].ents[a9].x` and `.z`), not through e1/e2 pointer locals.
 *   The CSE of the two full expressions colours pa in r2, so its load can move above the 0x4AC store.
 */
void MUSICAL_MCSS_DrawSprite(char *p, int a1, int a2, int a3, int a4, int a5, int a6, Pose *s, u16 *pa, int a9, int flag, int *pz, u8 mode)
{
    u16 ang;
    int x;
    int y;
    u32 s0;
    u32 s1;
    u32 t0;
    u32 t1;

    if (flag != 0) {
        G3i_OrthoW_(0x60000, 0xFFFA1000, 0xFFF81000, 0x80000, 0x1000, 0x3E8000, 0x1000, 1, 0);
        *(volatile u32 *)0x04000440 = 2;
    }
    *(volatile u32 *)0x04000450 = 0x1D;
    G3_TexPlttBase(*(u32 *)(p + 0xBC), *(int *)(p + 0xB4));
    *(volatile u32 *)0x040004A4 = 0x001F00C0;
    x = (s->dx + (*(struct McssSpriteSet **)(p + 0x6C))->tbl[*pa].ents[a9].x) << 8;
    y = -((*(struct McssSpriteSet **)(p + 0x6C))->tbl[*pa].ents[a9].z + s->dz) << 8;
    if (mode == 0) {
        ang = *(u16 *)(p + 0xFC);
    } else if ((mode & 1) != 0) {
        ang = (u16)(0x10000 - *(u16 *)(p + 0xFC));
    }
    G3_RotZ(-FX_SinCosTable_[(ang >> 4) * 2], FX_SinCosTable_[(ang >> 4) * 2 + 1]);
    G3_Translate(x, y, *pz);
    G3_RotZ(-FX_SinCosTable_[(*(u16 *)((char *)s + 2) >> 4) * 2], FX_SinCosTable_[(*(u16 *)((char *)s + 2) >> 4) * 2 + 1]);
    if (mode == 0) {
        G3_Scale(s->sx, s->sy, 0x1000);
        G3_Translate(a1, a2, 0);
        G3_Scale(a3, a4, 0x1000);
    } else if ((mode & 1) != 0) {
        G3_Scale(-s->sx, s->sy, 0x1000);
        G3_Translate(-a1, a2, 0);
        G3_Scale(a3, a4, 0x1000);
        G3_Translate(-0x100, 0, 0);
        a5 = 0x200000 - a5 - a3;
    }
    *(volatile u32 *)0x04000500 = 1;
    t0 = pk(a6) << 16;
    s0 = pk(a5);
    *(volatile u32 *)0x04000488 = s0 | t0;
    G3_Vtx(0, 0);
    s1 = pk(a5 + a3);
    *(volatile u32 *)0x04000488 = s1 | t0;
    G3_Vtx(0x100, 0);
    t1 = pk(a6 + a4) << 16;
    *(volatile u32 *)0x04000488 = s1 | t1;
    G3_Vtx(0xFF000100, 0);
    *(volatile u32 *)0x04000488 = s0 | t1;
    G3_Vtx(0xFF000000, 0);
    *(volatile u32 *)0x04000504 = 0;
    *(volatile u32 *)0x04000440 = 0;
    *(volatile u32 *)0x04000450 = 0;
    *(volatile u32 *)0x04000440 = 2;
    if (flag == 0) {
        *pz = *pz - 0x100;
    } else {
        *pz = *pz - 0x400;
    }
}


char *MUSICAL_MCSS_LoadMC(char *a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g)
{
    int i;
    for(i=0;i<((McssRenderPool *)a)->count;i++) {
        if(SLOT==0) {
            SLOT=func_02030734((u16)((McssRenderPool *)a)->heap,292,1,d_021F83D4,763);
            *(u32 *)(SLOT+240)=i;
            *(u32 *)(SLOT+244)=((McssRenderPool *)a)->heap;
            *(u32 *)(SLOT+200)=b;
            *(u32 *)(SLOT+204)=c;
            *(u32 *)(SLOT+208)=d;
            *(u16 *)(SLOT+252)=0;
            *(u32 *)(SLOT+212)=4096;
            *(u32 *)(SLOT+216)=4096;
            *(u32 *)(SLOT+220)=4096;
            *(u32 *)(SLOT+248)=f;
            MUSICAL_MCSS_LoadCellBank((u8 *)a,i,(u32 *)e,g);
            break;
        }
    }
    return SLOT;
}


void MUSICAL_MCSS_FreeMC(char *a, char *p)
{
    func_020307B0(((McssMcAnim *)p)->cellBank);
    func_020307B0(((McssMcAnim *)p)->multiCellBank);
    func_020307B0(((McssMcAnim *)p)->animBank);
    func_020307B0(((McssMcAnim *)p)->multiAnimBank);
    func_020307B0(((McssMcAnim *)p)->workArea);
    func_020307B0(((McssMcAnim *)p)->cellTable);
    (*(u32 **)(a+4))[((McssMcAnim *)p)->childIndex] = 0;
    func_020307B0(p);
}



void MUSICAL_MCSS_NoOp7(void *p)
{
    unsigned int v = ((McssRenderPool *)p)->flags;
    ((McssRenderPool *)p)->flags = (v & ~1u) | 1u;
}


/*
 * note: blocker leaf of MUSICAL_MCSS_SetRenderFieldA; following 021F6230 is already matched.
 */
void MUSICAL_MCSS_SetFieldA(char *p,int b) { ((McssRenderPool *)p)->cellVram=b; }


void MUSICAL_MCSS_SetFieldB(u8 *p, int a)
{
    ((McssRenderPool *)p)->animVram = a;
}



void MUSICAL_MCSS_GetFieldA(char *p, int *q)
{
    ((McssMcAnim *)p)->fieldC8 = q[0];
    ((McssMcAnim *)p)->fieldCC = q[1];
    ((McssMcAnim *)p)->fieldD0 = q[2];
}



void MUSICAL_MCSS_GetFieldB(char *p, int *q)
{
    ((McssMcAnim *)p)->fieldD4 = q[0];
    ((McssMcAnim *)p)->fieldD8 = q[1];
    ((McssMcAnim *)p)->fieldDC = q[2];
}



void MUSICAL_MCSS_SetFieldC(char *p, unsigned short v)
{
    ((McssMcAnim *)p)->frame = v;
}


void MUSICAL_MCSS_GetFieldC(u8 *p) { ((Flags *)(p+236))->a=1; }


void MUSICAL_MCSS_GetFieldD(u8 *p) { ((Flags *)(p+236))->a=0; }


void MUSICAL_MCSS_GetFieldE(u8 *p) { ((Flags *)(p+236))->b=1; }


void MUSICAL_MCSS_GetFieldF(char *p) {((McssMcAnim *)p)->flags&=~2u;}


void MUSICAL_MCSS_SetMCAnim(char *p,u32 n) {void *a; a=NNS_G2dGetAnimSequenceByIdx(((McssMcAnim *)p)->animSequenceBank,n);MUSICAL_MCSS_InitMCAnim(p,1);NNS_G2dSetAnimSequenceToMCAnimation(p+40,a);}



u32 MUSICAL_MCSS_GetFieldG(u8 *p) { return (((McssMcAnim *)p)->flags << 29) >> 31; }


void MUSICAL_MCSS_NoOp8(char *p) {((McssMcAnim *)p)->flags|=4u;}


void MUSICAL_MCSS_NoOp9(char *p) {((McssMcAnim *)p)->flags&=~4u;}


void MUSICAL_MCSS_CopyField(Object *a,Object *b)
{
    b->a=a->a; b->b=a->b; b->c=a->c;
    b->b0=a->b0; b->b1=a->b1; b->b2=a->b2;
    b->h=a->h; b->d=a->d; b->e=a->e;
}


/*
 * lever: an unqualified resource pointer keeps constant r2 setup before resource loads.
 * prototype: 6469C receives the sequence in r1 despite its one-argument matched definition.
 * prototype: 48F60/49F34/30734 heap inputs are narrowed immediately before each original call.
 */
void MUSICAL_MCSS_LoadCellBank(u8 *a,int index,u32 *res,u32 mode)
{
    u8 *q=(*(u8 ***)(a+4))[index];
    void **job;
    struct AnimSequence *sequence;
    u8 *table;
    ((McssMcAnim *)q)->flags |= 4;
    NNSi_G2dInitVramHandle((u32 *)(q+144));
    NNSi_G2dInitVramHandleEx((u32 *)(q+180));
    ((McssMcAnim *)q)->cellBank=ARC_UTIL_LoadCellBankFromArchive(res[0],res[3],0,(u32)(q+4),((McssMcAnim *)q)->heapTag);
    ((McssMcAnim *)q)->multiCellBank=ARC_UTIL_LoadMultiCellBankFromArchive(res[0],res[4],1,(u32)(q+20),((McssMcAnim *)q)->heapTag);
    ((McssMcAnim *)q)->animBank=ARC_UTIL_LoadAnimBankFromArchive(res[0],res[5],0,(u32)(q+12),((McssMcAnim *)q)->heapTag);
    ((McssMcAnim *)q)->multiAnimBank=ARC_UTIL_LoadMultiAnimBankFromArchive(res[0],res[6],0,(u32)(q+28),((McssMcAnim *)q)->heapTag);
    sequence=NNS_G2dGetAnimSequenceByIdx(*(struct AnimBank * *)&((McssMcAnim *)q)->animSequenceBank,0);
    MUSICAL_MCSS_InitMCAnim((char *)q,1);
    NNS_G2dSetAnimSequenceToMCAnimation(q+40,sequence);
    table=ARC_TOOL_LoadMember(res[0],res[7],(u16)(((McssMcAnim *)q)->heapTag));
    *(u8 * *)&((McssMcAnim *)q)->cellTable=table;
    *(u8 * *)&((McssMcAnim *)q)->field24=table+4+56* ((McssMultiCellBank *)table)->count;
    job=func_02030734((u16)((McssMcAnim *)q)->heapTag,36,1,d_021F83D4,1104);
    job[2]=q+144;
    job[3]=q+180;
    job[6]=*(u8 * *)&((McssRenderPool *)a)->cellVram+index*16384;
    job[7]=*(u8 * *)&((McssRenderPool *)a)->animVram+index*32;
    job[8]=q;
    job[4]=func_02049DB4(res[0],res[1],1,(u32)job,((McssMcAnim *)q)->heapTag);
    job[5]=func_02049F34(res[0],res[2],(u32)(job+1),(u16)(((McssMcAnim *)q)->heapTag));
    if(res[7]==6548) MCSS_TOOL_DrawSpindaSpots(*(u8 * *)&((McssSpindaRes *)((u8 *)job[0]))->spots,res[8]);
    if(mode==1) func_020056A0((u32)MUSICAL_MCSS_FreeCellBank,(u32)job,0);
    else MUSICAL_MCSS_FreeCellBank(0,job);
}


/*
 * extent: Two zero padding bytes follow the compiled body.
 */
void MUSICAL_MCSS_FreeCellBank(void *a, void **p)
{
    if(p[8]) ((McssMcAnim *)((char *)p[8]))->flags &= ~4u;
    if(p[4]) { NNSi_G2dLoadVramResourceSub(p[0],(u32)p[6],0,p[2]); func_020307B0(p[4]); }
    if(p[1]) { NNSi_G2dLoadVramResourceBySel(p[1],p[7],0,p[3]); func_020307B0(p[5]); }
    func_020307B0(p);
    if(a) func_02030EAC(a);
}


void MUSICAL_MCSS_InitMCAnim(char *p, int kind)
{
    ((McssMcAnim *)p)->workArea=func_02030734((u16)((McssMcAnim *)p)->heapTag,NNS_G2dGetMCWorkAreaSize(*(u32 *)&((McssMcAnim *)p)->cellArg,kind),0,d_021F83D4,1216);
    NNS_G2dInitMCAnimation(p+40,*(char * *)&((McssMcAnim *)p)->workArea,((McssMcAnim *)p)->field14,((McssMcAnim *)p)->cellBankArg,((McssMcAnim *)p)->cellArg,kind);
}


/*
 * volatile: Hardware register stores at listing 021F65F0,021F65F4,021F65FA.
 */
void MUSICAL_MCSS_SetupG3(void) {*(volatile u32 *)0x040004c0=0x4210ffff;*(volatile u32 *)0x040004c4=0x4210;*(volatile u32 *)0x040004a4=0x001f00c0;}


/*
 * extent: 310-byte code; 021F6742 is two zero alignment bytes.
 * lever: a named unsigned 64-bit sum pins carry accumulation before translation.
 * semantics: signed 32-bit products fit s64; u64 additions wrap like ADDS/ADCS.
 */
void MUSICAL_MCSS_CalcMatrix(const int *p, const int *m, u32 *out, u32 *w)
{
    s64 y = p[1];
    s64 x = p[0];
    s64 z = p[2];
    u64 sum;
    sum = (u64)(x * m[0]) + (u64)(y * m[4]) + (u64)(z * m[8]);
    out[0] = (u32)(sum >> 12) + (u32)m[12];
    sum = (u64)(x * m[1]) + (u64)(y * m[5]) + (u64)(z * m[9]);
    out[1] = (u32)(sum >> 12) + (u32)m[13];
    sum = (u64)(x * m[2]) + (u64)(y * m[6]) + (u64)(z * m[10]);
    out[2] = (u32)(sum >> 12) + (u32)m[14];
    sum = (u64)(x * m[3]) + (u64)(y * m[7]) + (u64)(z * m[11]);
    *w = (u32)(sum >> 12) + (u32)m[15];
}


/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
int MUSICAL_MCSS_GetMonValue(void *p) {int r; r=0;if(POKE_TOOL_GetPartyValue(p,170,0)!=1)r=1;return r;}


char *MUSICAL_MCSS_CreateMon(void *a,u16 heap)
{
    char *p;
    int i;
    p=func_02030734(heap,124,1,d_021F83E4,141);
    ((McssMon *)p)->kind=4;
    ((McssMon *)p)->source=a;
    ((McssMon *)p)->field4A=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    ((McssMon *)p)->species=POKE_TOOL_GetPartyValue(a,5,0);
    p[10]=POKE_TOOL_GetPartyValue(a,110,0);
    p[11]=POKE_TOOL_GetPartyValue(a,111,0);
    p[12]=POKE_TOOL_IsShiny(a);
    ((McssMon *)p)->field10=POKE_TOOL_GetPartyValue(a,0,0);
    return p;
}


char *MUSICAL_MCSS_AllocMon(u16 a,u8 b,u8 c,u8 d,u32 e,u16 heap)
{
    int i;
    char *p;
    int j;
    p=func_02030734(heap,124,1,d_021F83E4,165);
    ((McssMon *)p)->kind=4; ((McssMon *)p)->source=0; ((McssMon *)p)->field4A=0;
    for(i=0;i<9;i++) { *(u16 *)(p+20+6*i)=255; *(u16 *)(p+22+6*i)=0; *(u32 *)(p+84+4*i)=0; }
    for(j=0;j<4;j++) *(u16 *)(p+76+2*j)=0;
    ((McssMon *)p)->field78=0;
    ((McssMon *)p)->species=a; p[10]=b; p[11]=c; p[12]=d; ((McssMon *)p)->field10=e;
    return p;
}


void *MUSICAL_MCSS_AllocSmall(u32 heap) {u32 *p;int z;z=0;p=func_02030734(heap,48,0,d_021F83E4,194);p[1]=z;p[2]=z;p[3]=z;p[4]=z;p[5]=z;p[6]=z;p[7]=z;return p;}


void MUSICAL_MCSS_FreeMon(char *p) {if(((McssDistSave *)p)->member0)func_020307B0(((McssDistSave *)p)->member0);if(((McssDistSave *)p)->member1)func_020307B0(((McssDistSave *)p)->member1);if(((McssDistSave *)p)->member2)func_020307B0(((McssDistSave *)p)->member2);if(((McssDistSave *)p)->member3)func_020307B0(((McssDistSave *)p)->member3);func_020307B0(p);}


void MUSICAL_MCSS_LoadDistSave(u8 *p, u32 unused, void *sys, u8 kind, u16 heap)
{
    void *x;
    void *arc;
    u32 c, d, e;
    u8 *q;
    *p = kind;
    if (kind >= 4) {
        x = MUSICAL_DIST_SAVE_Create(sys, heap);
        arc = ARC_TOOL_CreateHandleFromMemory((void *)MUSICAL_DIST_SAVE_GetPayload(x), MUSICAL_DIST_SAVE_GetPayloadSize(x), (u16)((heap & 0x7fff) | 0x8000));
    } else {
        arc = func_020490F4(kind + 0x6f, (u16)((heap & 0x7fff) | 0x8000));
    }
    *(void **)(p + 4) = ARC_UTIL_LoadHandleMemberWithSize(arc, 0, 0, heap, (u32 *)(p + 0x20));
    *(void **)(p + 8) = ARC_UTIL_LoadHandleMemberWithSize(arc, 1, 0, heap, (u32 *)(p + 0x24));
    *(void **)(p + 0xc) = ARC_UTIL_LoadHandleMemberWithSize(arc, 2, 0, heap, (u32 *)(p + 0x28));
    c = ARC_TOOL_GetHandleMemberSize(arc, 4);
    d = ARC_TOOL_GetHandleMemberSize(arc, 3);
    e = ARC_TOOL_GetHandleMemberSize(arc, 5);
    *(u32 *)(p + 0x2c) = c + 0xc + d + e;
    q = func_02030734(heap, *(u32 *)(p + 0x2c), 1, d_021F83E4, 0x104);
    *(u8 **)(p + 0x10) = q;
    *(u8 **)(p + 0x14) = q + 0xc;
    *(u8 **)(p + 0x18) = q + 0xc + c;
    *(u32 *)(p + 0x1c) = d + *(u32 *)(p + 0x18);
    *(u32 *)q = c;
    *(u32 *)(q + 4) = d;
    *(u32 *)(q + 8) = e;
    ARC_TOOL_ReadHandleMember(arc, 4, *(void **)(p + 0x14));
    ARC_TOOL_ReadHandleMember(arc, 3, *(void **)(p + 0x18));
    ARC_TOOL_ReadHandleMember(arc, 5, *(void **)(p + 0x1c));
    ARC_TOOL_DeleteHandle(arc);
    if (kind >= 4) MUSICAL_DIST_SAVE_Delete(x);
}
