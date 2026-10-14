/*
 * file:     zukan_list.c
 * unit:     yes
 * function: ZUKAN_LIST_ProcInit, ZUKAN_LIST_ProcMain, ZUKAN_LIST_ProcExit, ZUKAN_LIST_StartVBlankTask, ZUKAN_LIST_StopVBlankTask, ZUKAN_LIST_VBlankTask, ZUKAN_LIST_StartHBlankTask, ZUKAN_LIST_StopHBlankTask, ZUKAN_LIST_HBlankTask, ZUKAN_LIST_SetVramBanks, ZUKAN_LIST_GetVramBankConfig, ZUKAN_LIST_InitBgSystem, ZUKAN_LIST_ExitBgSystem, ZUKAN_LIST_LoadBgGraphics, ZUKAN_LIST_InitPaletteAnim, ZUKAN_LIST_ExitPaletteAnim, ZUKAN_LIST_RequestFade, ZUKAN_LIST_SetSubScreenBlendAlpha, ZUKAN_LIST_EnableSubWindows, ZUKAN_LIST_DisableSubWindows, ZUKAN_LIST_CreateFontAndPrinter, ZUKAN_LIST_DeleteFontAndPrinter, ZUKAN_LIST_LoadFormTable, ZUKAN_LIST_FreeFormTable, ZUKAN_LIST_MoveScrollBarActorsIn, ZUKAN_LIST_StartActorMoveFrames, ZUKAN_LIST_UpdateActorMove, ZUKAN_LIST_CreateFrameList, ZUKAN_LIST_DeleteFrameList, ZUKAN_LIST_FrameListMoveCallback, ZUKAN_LIST_FrameListSelectCallback, ZUKAN_LIST_ScrollByDelta, ZUKAN_LIST_RunState, ZUKAN_LIST_StateInit, ZUKAN_LIST_StateExit, ZUKAN_LIST_StateWaitFade, ZUKAN_LIST_StateFadeIn, ZUKAN_LIST_StateMain, ZUKAN_LIST_StateScroll, ZUKAN_LIST_StateScrollWait, ZUKAN_LIST_StateCursorFlash, ZUKAN_LIST_StateFadeOut, ZUKAN_LIST_ResetPaletteSlots, ZUKAN_LIST_StartButtonAnim, ZUKAN_LIST_IsSpeciesEntryValid, ZUKAN_LIST_StoreLastViewedSpecies, ZUKAN_LIST_StateSelectSpecies, ZUKAN_LIST_ToggleSaveFlag15, ZUKAN_LIST_CreateWindows, ZUKAN_LIST_DeleteWindows, ZUKAN_LIST_FlushWindows, ZUKAN_LIST_PrintTouchbarLabel, ZUKAN_LIST_PrintTouchbarLabelClone, ZUKAN_LIST_MakeWindowScreens, ZUKAN_LIST_ClearWindow, ZUKAN_LIST_DrawHeaderRegional, ZUKAN_LIST_DrawHeaderCounts, ZUKAN_LIST_DrawHeaderNational, ZUKAN_LIST_PrintListRow, ZUKAN_LIST_InitActors, ZUKAN_LIST_ExitActors, ZUKAN_LIST_UpdateActors, ZUKAN_LIST_SetActorAnim, ZUKAN_LIST_StartActorAnim, ZUKAN_LIST_GetActorAnimSeq, ZUKAN_LIST_IsActorAnimActive, ZUKAN_LIST_SetActorVisible, ZUKAN_LIST_GetActorVisible, ZUKAN_LIST_SetActorObjMode, ZUKAN_LIST_AddActorPos, ZUKAN_LIST_GetActorPos, ZUKAN_LIST_InitActorSystem, ZUKAN_LIST_LoadActorResources, ZUKAN_LIST_ReleaseActorResources, ZUKAN_LIST_CreateActors, ZUKAN_LIST_DeleteActor, ZUKAN_LIST_DeleteActorUnit, ZUKAN_LIST_LoadSpeciesIcon, ZUKAN_LIST_UpdateSpeciesActors, ZUKAN_LIST_TransferSpeciesGraphics, ZUKAN_LIST_IsActorHidden, ZUKAN_LIST_ShowSpeciesActor, ZUKAN_LIST_ScrollActorsBy, ZUKAN_LIST_HideAllActors, ZUKAN_LIST_ShowAllActors, ZUKAN_LIST_MoveCursorActor, ZUKAN_LIST_UpdateScrollBarActor, ZUKAN_LIST_UpdateArrowActors, ZUKAN_LIST_HandleTouchInput
 * address:  0x021BC240
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_list.c, ov209_func_021BE658.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020419E4 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_02005624 0x02005624 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_021BE7D4 0x021BE7D4 data a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   data_021BE804 0x021BE804 data a4
 *   data_021BE894 0x021BE894 data a4
 *   data_021BE874 0x021BE874 data a4
 *   data_021BE814 0x021BE814 data a4
 *   data_021BE8F4 0x021BE8F4 data a4
 *   data_021BE8B4 0x021BE8B4 data a4
 *   data_021BE854 0x021BE854 data a4
 *   data_021BE8D4 0x021BE8D4 data a4
 *   data_021BE834 0x021BE834 data a4
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027628 0x02027628 thumb
 *   func_02027624 0x02027624 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02049740 0x02049740 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02049B40 0x02049B40 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_020056BC 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02041EE4 0x02041EE4 arm
 *   ZUKAN_SAVE_GetLastViewedSpecies 0x0200CA8C thumb
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Clone 0x02045874 arm
 *   data_021BE7AC 0x021BE7AC data a4
 *   data_020A7370 0x020A7370 data a4
 *   FRAME_LIST_Delete 0x021B796C thumb ov067
 *   FRAME_LIST_GetItemValue 0x021B9398 thumb ov067
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   d_021BE96C 0x021BE96C data a4
 *   func_021C93E4 0x021C93E4 thumb ov212
 *   ov067_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_0207D534 0x0207D534 arm
 *   func_0204363C 0x0204363C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_02034A5C 0x02034A5C arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   FRAME_LIST_Update 0x021B7AB0 thumb ov067
 *   ZUKAN_LIST_HandleTouchInput 0x021BE658 thumb ov209
 *   FRAME_LIST_GetSelectedIndex 0x021B93A4 thumb ov067
 *   func_021B93D4 0x021B93D4 thumb ov067
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_SAVE_SetViewMode 0x0200CA5C thumb
 *   FRAME_LIST_SetRowPalette 0x021B9280 thumb ov067
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   ZUKAN_SAVE_SetLastViewedSpecies 0x0200CA78 thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   GAME_DATA_SetSaveFlag 0x02012BE0 thumb
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_021BE990 0x021BE990 data a1
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   func_0201F250 0x0201F250 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   BMP_WIN_GetDispHeight 0x02045750 arm
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02049DF4 0x02049DF4 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   ZUKAN_SAVE_CountSeenNational 0x0200D0CC thumb
 *   ZUKAN_SAVE_CountCaughtNational 0x0200CF28 thumb
 *   ZUKAN_SAVE_CountSeenRegional 0x0200D0F8 thumb
 *   ZUKAN_SAVE_CountCaughtRegional 0x0200CF54 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   FRAME_LIST_GetPrinter 0x021B9394 thumb ov067
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_GetActorAutoAnim 0x0204B944 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   d_021BE9D4 0x021BE9D4 data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_021C940C 0x021C940C thumb ov212
 *   CLACT_SetActorVisible 0x0204BA20 arm
 *   ZUKAN_SAVE_GetDexObtained 0x0200CA54 thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 *   d_021BE9F0 0x021BE9F0 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   d_021BE9BC 0x021BE9BC data a4
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   ZUKAN_SAVE_GetViewGenderAndForm 0x0200CC40 thumb
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   ZUKAN_SAVE_GetSpindaPersonality 0x0200D288 thumb
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   CLACT_SetActorFlip 0x0204B604 arm
 *   d_021BE9A4 0x021BE9A4 data a4
 *   func_02049E74 0x02049E74 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   CLACT_TransferCharacterPart 0x0204AA94 arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   FRAME_LIST_ClampToScrollBar 0x021B8AE4 thumb ov067
 *   FRAME_LIST_CanScrollDown 0x021B93C0 thumb ov067
 *   FRAME_LIST_HideCursor   0x021B941C  thumb
 *   func_021B940C   0x021B940C  thumb ov133
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   the name); it is a member function of the EXACT game_unit
 */
#include "../../matched/include/Obj00123.h"
#include "../../matched/include/Obj25533.h"
#include "../../matched/include/Obj25534.h"
#include "../../matched/include/Obj25535.h"
#include "../../matched/include/Obj25536.h"
#include "../../matched/include/Obj00088.h"
#include "../../matched/include/Obj02924.h"
#include "../../matched/include/Obj14667.h"
#include "../../matched/include/Obj08408.h"
#include "../../matched/include/Obj25546.h"
#include "../../matched/include/Obj14668.h"
#include "../../matched/include/Obj01435.h"
#include "../../matched/include/Obj25555.h"
#include "../../matched/include/Obj25556.h"
#include "../../matched/include/Obj10912.h"
#include "../../matched/include/Obj08409.h"
#include "../../matched/include/Obj25560.h"
#include "../../matched/include/Obj25561.h"
#include "../../matched/include/Obj25562.h"
#include "../../matched/include/Obj25563.h"
#include "../../matched/include/Obj25564.h"
#include "../../matched/include/Obj25565.h"
#include "../../matched/include/Obj25566.h"
#include "../../matched/include/Obj25567.h"
#include "../../matched/include/Obj04617.h"
#include "../../matched/include/Obj25570.h"
#include "../../matched/include/Obj25571.h"
#include "../../matched/include/Obj25572.h"
#include "../../matched/include/Obj25573.h"
#include "../../matched/include/Obj25575.h"
#include "../../matched/include/Obj08410.h"
#include "../../matched/include/Obj25576.h"
#include "../../matched/include/Obj25577.h"
#include "../../matched/include/Obj25578.h"
#include "../../matched/include/Obj25579.h"
#include "../../matched/include/Obj08411.h"
#include "../../matched/include/Obj08412.h"

struct Obj0203159C;

struct S020315D4;

struct Node;

struct S02021D50;

struct DispVram;

struct DispConfig;

struct PalAnmSlot;

struct GfFont;

struct MsgBank;

struct U16Vec;

struct WordSet;

struct PrintSys;

struct Rec;

struct Blk37;

struct S;

struct Tmpl;

struct Context_021BCBE0;

struct Descriptor;

struct Cfg;

struct Bmp;

struct R_021BD3E0;

struct Actor;

struct Obj;

struct Vec2;

struct Bank;

struct Personal;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Display {u32 w[4];};

struct BgTemplate {u32 w[8];};

typedef signed int s32;

typedef short s16_021BC8B4;

typedef short s16_021BC91C;

struct Template {u8 head[20];u16 count,pad16;u8 index,pad19;u16 start;u32 p1c,p20;void *p24;};

struct Inputs {u32 p0;void *save;u16 pad8,count;u16 *ids;};

struct Context_021BC388 {struct Inputs *in;u8 pad4[0xc2c-4];void *list;u32 padc30;u32 visible;};

typedef struct S S;

struct Input {u32 a;void *save;u32 b,c,state;};

struct Context_021BCBE0 {struct Input *in;u8 pad4[0x10];u32 state;u8 pad18[0x48-0x18];int ps;u8 pad4c[0xc24-0x4c];u16 flags;u8 padc26[6];void *list;};

struct Timer { unsigned short low : 1; unsigned short high : 15; };

struct Bits {u16 low:1;u16 high:15;};

typedef struct WordSet WordSet;

typedef signed short s16;

typedef struct PtS {s16 x,y;} PtS;

typedef struct TemplateB {u32 w[7];} TemplateB;

struct R_021BD3E0 { u8 pad[0xB64]; int a[0x24]; int b[6]; int c[6]; };

typedef struct Template_021BDC08 { u32 w0, w4, w8, wC, w10; u16 h14, h16; } Template_021BDC08;

typedef struct Template_021BDD7C { u32 w0,w4,w8,wC,w10; u16 h14,h16; } Template_021BDD7C;

typedef struct Flags { u16 side:1; u16 rest:15; } Flags;

struct R_021BE010 { u16 f0; u16 f2; u32 f4; u32 f8; u32 fC; u32 f10; u16 f14; u16 f16; };

struct Out { char pad[20]; void *f14; };

enum Position { POSITION_ZERO=0 };

extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,unsigned,unsigned);

extern void MI_CpuFill8(void *,int,int);

extern void func_020315D4(struct S020315D4 *p);

extern void func_020306F0(unsigned int heap);

extern void *func_020056A0(unsigned,unsigned,unsigned);

extern void func_02030EAC(struct Node *);

extern void func_020419E4(void),CLACT_VBlankSystem(void);

extern void PALANM_TransferPalettes(struct S02021D50 *);

extern void *func_02005624(unsigned,unsigned,unsigned);

extern void BG_SYS_SetVramBanks(const struct DispVram *);

extern void func_0203F8F4(u16);

extern void func_0203FC28(struct DispConfig *cfg);

extern void func_0203FCA0(u32,const struct BgTemplate *,u32);

extern void func_020414EC(u32);

extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);

extern void func_02041B6C(u32);

extern void BG_SYS_SetMainPlaneVisible(u32,u32);

extern void BG_SYS_SetSubPlaneVisible(u32,u32);

extern void func_020403F4(u32 i);

extern void func_0203F9B4(void);

extern void *func_020490F4(u32 id, u32 heap);

extern void func_02049B68(void *,u32,u32,u32,u32,u16);

extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);

extern void ARC_TOOL_DeleteHandle(void *);

extern u32 func_020275E4(void);

extern u32 func_02027628(void);

extern u32 func_02027624(void);

extern u32 func_0202762C(void);

extern u32 func_02049740(void *,u32,u32,u32,u32,u16);

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern void func_02049B40(u32,u32,u32,u32,u32,u16);

extern void *PALANM_Create(u32);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,unsigned);

extern void PALANM_Delete(struct PalAnmSlot *);

extern u32 func_020056BC(void);

extern int PALANM_RequestFade(void *, u16, u16, short, u8, u8, u16, void *);

extern void func_0207D63C(void *,unsigned,unsigned,unsigned,unsigned);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct WordSet *func_0201EC64(u32 heap);

extern u32 PRINTSYS_QUE_Create(void *);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_Delete(struct U16Vec *);

extern void PRINTSYS_QUE_Delete(struct PrintSys *);

extern void func_0201ED04(struct WordSet *);

extern void GF_FONT_Delete(void *);

extern void MSGDATA_Delete(struct Rec *);

extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);

extern u32 func_020307B0(void *p);

extern void func_02041EE4(u32, u32, u32);

extern u16 ZUKAN_SAVE_GetLastViewedSpecies(struct Blk37 *p);

extern struct S *FRAME_LIST_Create(struct Tmpl *tmpl, u32 heap);

extern void FRAME_LIST_CopyMapToBuffer(u8 *p, u32 a, u32 b, u32 c, u32 index);

extern void FRAME_LIST_LoadPalettes(u8 *p, u8 *a, u32 b, u32 c, u32 d);

extern void FRAME_LIST_AddItem(char *ctx, unsigned first, unsigned second);

extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *p, u16 id);

extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);

extern void FRAME_LIST_Delete(struct S *);

extern u32 FRAME_LIST_GetItemValue(char *p, int index);

extern int FRAME_LIST_GetScrollPos(char *);

extern int FRAME_LIST_GetCursor(char *);

extern void ZUKAN_LIST_UpdateActors(char *),ZUKAN_LIST_FlushWindows(const struct Context_021BCBE0 *),func_021C93E4(u32,u32,u8 *);

extern void BG_SYS_SetMainVisiblePlanes(u32);

extern void BG_SYS_SetSubVisiblePlanes(u32);

extern void func_0207D534(volatile u16 *reg, int brightness);

extern int func_02034AC4(int);

extern void func_0204363C(u32);

extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);

extern u32 PALANM_GetFadeRequestBits(const char *);

extern void func_02034A5C(int);

extern int FRAME_LIST_UpdateInit(struct S *p);

extern int FRAME_LIST_Update(struct S *p);

extern int ZUKAN_LIST_HandleTouchInput(void *ctx_);

extern int FRAME_LIST_GetSelectedIndex(char *p);

extern void func_021B93D4(struct S *s, int v);

extern u8 func_020355C4(void);

extern void func_020355D8(u8);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p);

extern void ZUKAN_SAVE_SetViewMode(struct Blk37 *p, u32 v);

extern void FRAME_LIST_SetRowPalette(u8 *p, int a, u32 b);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, unsigned, unsigned, unsigned);

extern void ZUKAN_SAVE_SetLastViewedSpecies(void *,u16);

extern int GAME_DATA_CheckSaveFlag(int, int);

extern void GAME_DATA_SetSaveFlag(void *, unsigned, unsigned);

extern void BMP_WIN_Init(unsigned short);

extern unsigned BMP_WIN_Create(unsigned, unsigned, unsigned, unsigned, u8, u8, u8);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_WIN_Exit(void);

extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);

extern void func_0201F250(struct WordSet *, void *, void *);

extern void BMP_WIN_MakeScreen(struct Cfg *);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);

extern u8 BMP_WIN_GetDispWidth(struct Descriptor *p);

extern u8 BMP_WIN_GetDispHeight(struct Descriptor *p);

extern u8 BMP_WIN_GetPosX(struct Descriptor *p);

extern u8 BMP_WIN_GetPosY(struct Descriptor *p);

extern void *BMP_GetPixels(const struct Bmp *bmp);

extern void *func_02049EF4(void *, u32, u32, void **, u16);

extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);

extern u16 ZUKAN_SAVE_CountSeenNational(struct Blk37 *p);

extern u16 ZUKAN_SAVE_CountCaughtNational(struct Blk37 *p);

extern u16 ZUKAN_SAVE_CountSeenRegional(struct Blk37 *p, u32 heap);

extern u16 ZUKAN_SAVE_CountCaughtRegional(struct Blk37 *p, u32 heap);

extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern unsigned FRAME_LIST_GetPrinter(char *);

extern void CLACT_ExitSystem(void);

extern u32 CLACT_GetActorAutoAnim(struct Actor *);

extern void CLACT_AddActorAnimFrame(struct Obj *,u32);

extern void CLACT_DrawSystem(void);

extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned int);

extern u16 CLACT_GetActorAnimSeq(struct Obj *p);

extern u32 CLACT_IsActorAnimActive(struct Actor *);

extern void CLACT_SetActorDrawEnable(struct Obj *,u32);

extern u32 CLACT_GetActorDrawEnable(struct Obj *);

extern void CLACT_SetActorObjMode(struct Actor *,u32);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern void CLACT_GetActorSurfacePos(struct Actor *,PtS *,unsigned int);

extern void CLACT_InitSystem(const struct Cfg *,u32,u32);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern u32 POKE_TOOL_CalcGraphicIndex(u32, u32, u32, u32);

extern int func_0201BC3C(void);

extern int func_0201BC40(void);

extern int func_0201BC78(void);

extern int func_0201BCB4(void);

extern int func_0201BCEC(void);

extern u32 func_02027614(void);

extern u32 func_02027618(void);

extern u32 func_0202761C(u32);

extern u32 func_02027620(u32);

extern void CLACT_ReleaseCharacter(unsigned);

extern void CLACT_ReleasePalette(unsigned);

extern void CLACT_ReleaseCellAnim(unsigned);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern struct Obj *func_021C940C(u32 bank, const u8 *t, u16 heap);

extern void CLACT_SetActorVisible(struct Actor *a, u32 v);

extern u32 ZUKAN_SAVE_GetDexObtained(struct Blk37 *p);

extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);

extern void CLACT_DeleteActor(struct Obj *);

extern void CLACT_DeleteUnit(struct Bank *);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern void ZUKAN_SAVE_GetViewGenderAndForm(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);

extern int POKEGRA_OpenHandle(int a0);

extern u32 ZUKAN_SAVE_GetSpindaPersonality(struct Blk37 *p, u32 which);

extern u32 POKEGRA_RegisterCgr(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern int POKEGRA_RegisterPalette(int,int,int,int,int,int,int,int,u16,u16);

extern u32 POKEGRA_RegisterCellAnim(u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern void *POKE_PERSONAL_Create(u32,int,u32);

extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);

extern void POKE_PERSONAL_Delete(void *);

extern void CLACT_SetActorFlip(struct Actor *actor, u32 which, u32 set);

extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern u16 CLACT_GetActorCharacterIndex(u8 *);

extern void CLACT_TransferCharacterPart(int,void *,unsigned,int,int);

extern unsigned POKE_TOOL_CalcIconPalette(unsigned,unsigned,unsigned,unsigned);

extern void CLACT_SetActorPaletteOffset(struct Obj *,unsigned,unsigned);

extern int FRAME_LIST_ClampToScrollBar(struct S *s, unsigned int v);

extern int FRAME_LIST_CanScrollDown(char *);

int ZUKAN_LIST_ProcInit(struct Obj0203159C *p,int unused,unsigned v);

int ZUKAN_LIST_ProcMain(int a, int b, int c, int d);

int ZUKAN_LIST_ProcExit(void *p);

void ZUKAN_LIST_StartVBlankTask(char *p);

void ZUKAN_LIST_StopVBlankTask(char *p);

void ZUKAN_LIST_VBlankTask(void *unused,char *p);

void ZUKAN_LIST_StartHBlankTask(char *p);

void ZUKAN_LIST_StopHBlankTask(char *p);

void ZUKAN_LIST_HBlankTask(void);

void ZUKAN_LIST_SetVramBanks(void);

void *ZUKAN_LIST_GetVramBankConfig(void);

void ZUKAN_LIST_InitBgSystem(void);

void ZUKAN_LIST_ExitBgSystem(void);

void ZUKAN_LIST_LoadBgGraphics(void);

void ZUKAN_LIST_InitPaletteAnim(char *p);

void ZUKAN_LIST_ExitPaletteAnim(char *p);

void ZUKAN_LIST_RequestFade(char *p, u8 a, u8 b);

void ZUKAN_LIST_SetSubScreenBlendAlpha(void);

void ZUKAN_LIST_EnableSubWindows(void);

void ZUKAN_LIST_DisableSubWindows(void);

void ZUKAN_LIST_CreateFontAndPrinter(char *p);

void ZUKAN_LIST_DeleteFontAndPrinter(char *p);

void ZUKAN_LIST_LoadFormTable(char *p);

void ZUKAN_LIST_FreeFormTable(char *p);

void ZUKAN_LIST_MoveScrollBarActorsIn(char *p);

void ZUKAN_LIST_StartActorMoveFrames(char *a, int b);

int ZUKAN_LIST_UpdateActorMove(char *p);

void ZUKAN_LIST_CreateFrameList(struct Context_021BC388 *p);

void ZUKAN_LIST_DeleteFrameList(char *p);

void ZUKAN_LIST_FrameListMoveCallback(char *p, int index, int a, u16 b, int c);

void ZUKAN_LIST_FrameListSelectCallback(char *p, int index);

void ZUKAN_LIST_ScrollByDelta(char *p,int delta);

int ZUKAN_LIST_RunState(char *p);

int ZUKAN_LIST_StateInit(char *p);

int ZUKAN_LIST_StateExit(char *p);

int ZUKAN_LIST_StateWaitFade(char *p);

int ZUKAN_LIST_StateFadeIn(char *p);

int ZUKAN_LIST_StateMain(struct Context_021BCBE0 *p);

int ZUKAN_LIST_StateScroll(char *p);

int ZUKAN_LIST_StateScrollWait(char *p);

int ZUKAN_LIST_StateCursorFlash(char *p);

int ZUKAN_LIST_StateFadeOut(char *p);

void ZUKAN_LIST_ResetPaletteSlots(char *p);

int ZUKAN_LIST_StartButtonAnim(char *p,int a,int b,int c);

int ZUKAN_LIST_IsSpeciesEntryValid(char *p,int i);

void ZUKAN_LIST_StoreLastViewedSpecies(char *p,int i);

int ZUKAN_LIST_StateSelectSpecies(char *a, int arg);

void ZUKAN_LIST_ToggleSaveFlag15(char *p);

void ZUKAN_LIST_CreateWindows(char *p);

void ZUKAN_LIST_DeleteWindows(char *p);

void ZUKAN_LIST_FlushWindows(const struct Context_021BCBE0 *p);

void ZUKAN_LIST_PrintTouchbarLabel(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode);

void ZUKAN_LIST_PrintTouchbarLabelClone(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode);

void ZUKAN_LIST_MakeWindowScreens(void **p);

void ZUKAN_LIST_ClearWindow(u8 *p, u32 idx);

void ZUKAN_LIST_DrawHeaderRegional(char *p);

void ZUKAN_LIST_DrawHeaderCounts(char *p);

void ZUKAN_LIST_DrawHeaderNational(char *p);

void ZUKAN_LIST_PrintListRow(char *p, unsigned char *dest, unsigned text0, unsigned index);

void ZUKAN_LIST_InitActors(char *p);

void ZUKAN_LIST_ExitActors(char *a);

void ZUKAN_LIST_UpdateActors(char *p);

void ZUKAN_LIST_SetActorAnim(char *p, int idx, int v);

void ZUKAN_LIST_StartActorAnim(char *p,int idx,int value);

int ZUKAN_LIST_GetActorAnimSeq(char *a, int b);

u32 ZUKAN_LIST_IsActorAnimActive(char *p,u32 idx);

void ZUKAN_LIST_SetActorVisible(char *p,u32 idx,u32 value);

u32 ZUKAN_LIST_GetActorVisible(char *p,u32 idx);

void ZUKAN_LIST_SetActorObjMode(char *p,u32 idx,u32 flag);

void ZUKAN_LIST_AddActorPos(char *p, int idx, short a, short b, unsigned short c);

void ZUKAN_LIST_GetActorPos(char *p,u32 idx,s16 *x,s16 *y,u16 space);

void ZUKAN_LIST_InitActorSystem(char *p);

void ZUKAN_LIST_LoadActorResources(struct R_021BD3E0 *p);

void ZUKAN_LIST_ReleaseActorResources(char *p);

void ZUKAN_LIST_CreateActors(char *p);

void ZUKAN_LIST_DeleteActor(char *p,u32 idx);

void ZUKAN_LIST_DeleteActorUnit(char *p);

void ZUKAN_LIST_LoadSpeciesIcon(char *p,u16 species);

void ZUKAN_LIST_UpdateSpeciesActors(char *p);

void ZUKAN_LIST_TransferSpeciesGraphics(char *p, int index, unsigned species, u16 form, u16 half, int mode);

int ZUKAN_LIST_IsActorHidden(int p, int t);

void ZUKAN_LIST_ShowSpeciesActor(char *p,u16 species,enum Position pos,int mode);

void ZUKAN_LIST_ScrollActorsBy(char *p, int delta);

void ZUKAN_LIST_HideAllActors(char *p);

void ZUKAN_LIST_ShowAllActors(char *p);

void ZUKAN_LIST_MoveCursorActor(char *p,int index);

void ZUKAN_LIST_UpdateScrollBarActor(char *p);

void ZUKAN_LIST_UpdateArrowActors(char *p,int flag);

extern const struct DispVram d_021BE7D4;

extern const struct Display data_021BE804;

extern const struct BgTemplate data_021BE894,data_021BE874,data_021BE814,data_021BE8F4,data_021BE8B4,data_021BE854,data_021BE8D4,data_021BE834;

extern const struct Template data_021BE7AC;

extern void *data_020A7370;

extern const char ov067_id[];

extern const u8 d_021BE990[][6];

extern const TemplateB d_021BE9D4;

extern const Template_021BDC08 d_021BE9F0[10];

extern const Template_021BDD7C d_021BE9BC;

extern const struct R_021BE010 d_021BE9A4;

int ZUKAN_LIST_ProcInit(struct Obj0203159C *p,int unused,unsigned v){unsigned *q;GFL_HEAP_CreateChildHeap(1,107,0x60000);q=PROCSYS_AllocProcWork(p,0xc44,107);MI_CpuFill8(q,0,0xc44);*q=v;return 1;}

int ZUKAN_LIST_ProcMain(int a, int b, int c, int d)
{
    if (ZUKAN_LIST_RunState((char *)d) == 0)
        return 1;
    return 0;
}

int ZUKAN_LIST_ProcExit(void *p)
{
    func_020315D4(p);
    func_020306F0(0x6b);
    return 1;
}

void ZUKAN_LIST_StartVBlankTask(char *p){((struct Obj00123 *)p)->f4=func_020056A0((unsigned)ZUKAN_LIST_VBlankTask,(unsigned)p,0);}

void ZUKAN_LIST_StopVBlankTask(char *p){func_02030EAC(*(struct Node * *)&((struct Obj25533 *)p)->f4);}

/*
 * lever: enum-typed DTCM base preserves the base-first two-pool address; constant addition folds and enum offset reverses pool/register roles.
 * volatile: hardware interrupt check flag at 02FE3FF8 read and written by 021BC2D4/021BC2D8.
 */
void ZUKAN_LIST_VBlankTask(void *unused,char *p){enum Base { DTCM_BASE=0x02fe0000 } base;func_020419E4();CLACT_VBlankSystem();PALANM_TransferPalettes(*(struct S02021D50 * *)&((struct Obj25534 *)p)->fC);base=DTCM_BASE;*(volatile unsigned *)&((struct Obj25535 *)base)->f3FF8|=1;}

void ZUKAN_LIST_StartHBlankTask(char *p){((struct Obj00123 *)p)->f8=func_02005624((unsigned)ZUKAN_LIST_HBlankTask,(unsigned)p,0);}

void ZUKAN_LIST_StopHBlankTask(char *p)
{
    func_02030EAC(((struct Obj25536 *)p)->f8);
}

/*
 * volatile: VCOUNT read at 021BC30A; BLDALPHA writes at 021BC314, 021BC320, 021BC32C, 021BC338, 021BC344, 021BC34A
 */
void ZUKAN_LIST_HBlankTask(void)
{
    int v = *(volatile u16 *)0x04000006;
    if (v >= 168) {
        *(volatile u16 *)0x04001052 = 0x050B;
        return;
    }
    if (v >= 144) {
        *(volatile u16 *)0x04001052 = 0x060A;
        return;
    }
    if (v >= 120) {
        *(volatile u16 *)0x04001052 = 0x0709;
        return;
    }
    if (v >= 96) {
        *(volatile u16 *)0x04001052 = 0x0808;
        return;
    }
    if (v >= 72) {
        *(volatile u16 *)0x04001052 = 0x0A06;
        return;
    }
    *(volatile u16 *)0x04001052 = 0x0C04;
}

void ZUKAN_LIST_SetVramBanks(void){BG_SYS_SetVramBanks(&d_021BE7D4);}

void *ZUKAN_LIST_GetVramBankConfig(void){return (void *)&d_021BE7D4;}

void ZUKAN_LIST_InitBgSystem(void)
{
    struct Display display;
    struct BgTemplate b0,b1,b2,b3,b4,b5,b6,b7;
    func_0203F8F4(107);
    display=data_021BE804;func_0203FC28((struct DispConfig *)(&display));
    b0=data_021BE894;func_0203FCA0(0,&b0,0);
    func_020414EC(0);func_02040B94(0,32,0,107);func_02041B6C(0);
    b1=data_021BE874;func_0203FCA0(1,&b1,0);
    b2=data_021BE814;func_0203FCA0(2,&b2,0);
    func_020414EC(2);func_02041B6C(2);
    b3=data_021BE8F4;func_0203FCA0(3,&b3,0);
    b4=data_021BE8B4;func_0203FCA0(4,&b4,0);
    func_020414EC(4);func_02040B94(4,32,0,107);func_02041B6C(4);
    b5=data_021BE854;func_0203FCA0(5,&b5,0);
    b6=data_021BE8D4;func_0203FCA0(6,&b6,0);
    func_020414EC(6);func_02041B6C(6);
    b7=data_021BE834;func_0203FCA0(7,&b7,0);
    BG_SYS_SetMainPlaneVisible(15,1);BG_SYS_SetSubPlaneVisible(15,1);
}

void ZUKAN_LIST_ExitBgSystem(void)
{
    BG_SYS_SetMainPlaneVisible(0xf, 0);
    BG_SYS_SetSubPlaneVisible(0xf, 0);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}

void ZUKAN_LIST_LoadBgGraphics(void)
{
    void *arc;
    arc=func_020490F4(159,107);
    func_02049B68(arc,48,0,0,128,107);
    func_02049B68(arc,49,4,0,160,107);
    func_02049658(arc,58,2,0,0,0,107);
    func_02049658(arc,56,3,0,0,0,107);
    func_02049658(arc,59,6,0,0,0,107);
    func_02049658(arc,57,7,0,0,0,107);
    func_020498F4(arc,62,3,0,0,0,107);
    func_020498F4(arc,69,5,0,0,0,107);
    func_020498F4(arc,63,7,0,0,0,107);
    ARC_TOOL_DeleteHandle(arc);
    arc=func_020490F4(func_020275E4(),107);
    func_02049740(arc,func_02027628(),1,0,0,107);
    func_02049B68(arc,func_02027624(),0,448,32,107);
    func_020498F4(arc,func_0202762C(),1,0,0,0,107);
    func_020413B0(1,0,21,32,3,14);
    func_02041B6C(1);
    ARC_TOOL_DeleteHandle(arc);
    func_02049B40(23,5,0,480,32,107);
    func_02049B40(23,5,4,480,32,107);
}

void ZUKAN_LIST_InitPaletteAnim(char *p)
{
    ((struct Obj00123 *)p)->fC = PALANM_Create(0x6B);
    PALANM_AllocSlotBuffers(((struct Obj00123 *)p)->fC, 0, 0x200, 0x6B);
    PALANM_AllocSlotBuffers(((struct Obj00123 *)p)->fC, 1, 0x200, 0x6B);
    PALANM_AllocSlotBuffers(((struct Obj00123 *)p)->fC, 2, 0x200, 0x6B);
    PALANM_AllocSlotBuffers(((struct Obj00123 *)p)->fC, 3, 0x200, 0x6B);
}

void ZUKAN_LIST_ExitPaletteAnim(char *p){PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,0);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,1);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,2);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,3);PALANM_Delete(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC);}

void ZUKAN_LIST_RequestFade(char *p, u8 a, u8 b)
{
    void *ctx;
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(((struct Obj00088 *)p)->fC, 1, 0xBFFF, -14, a, b, 0, ctx);
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(((struct Obj00088 *)p)->fC, 2, 0xFFEF, -14, a, b, 0, ctx);
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(((struct Obj00088 *)p)->fC, 4, 0xF878, -14, a, b, 0, ctx);
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(((struct Obj00088 *)p)->fC, 8, 0xBFFF, -14, a, b, 0, ctx);
}

void ZUKAN_LIST_SetSubScreenBlendAlpha(void){func_0207D63C((void *)0x04001050,4,8,6,10);}

static inline void obj(int wnd, int effect)
{
    u32 tmp = (*(volatile u16 *)0x0400104A & ~0x3F00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    *(volatile u16 *)0x0400104A = (u16)tmp;
}

static inline void outside(int wnd, int effect)
{
    u32 tmp = (*(volatile u16 *)0x0400104A & ~0x3F) | (u32)wnd;
    if (effect) tmp |= 0x20;
    *(volatile u16 *)0x0400104A = (u16)tmp;
}

/*
 * volatile: WINOUT reads/writes at 021BC7D4..021BC7F2; DISPCNT read/write at 021BC7F8..021BC802
 */
void ZUKAN_LIST_EnableSubWindows(void)
{
    obj(27, 1);
    outside(31, 1);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0xE000) | 0x8000;
}

void ZUKAN_LIST_DisableSubWindows(void)
{
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
}

void ZUKAN_LIST_CreateFontAndPrinter(char *p)
{
    ((struct Obj00123 *)p)->f3C = func_02045B38(0, 2, 0x114, 0x6B);
    ((struct Obj00123 *)p)->f38 = GF_FONT_Create(0x17, 0, 0, 0, 0x6B);
    ((struct Obj00123 *)p)->f40 = func_0201EC64(0x6B);
    ((struct Obj00123 *)p)->f48 = PRINTSYS_QUE_Create((void *)0x6B);
    ((struct Obj00123 *)p)->f44 = STRBUF_Create(0x80, 0x6B);
}

void ZUKAN_LIST_DeleteFontAndPrinter(char *p){STRBUF_Delete(*(struct U16Vec * *)&((struct Obj00088 *)p)->f44);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj00088 *)p)->f48);func_0201ED04(*(struct WordSet * *)&((struct Obj00088 *)p)->f40);GF_FONT_Delete(((struct Obj00088 *)p)->f38);MSGDATA_Delete(*(struct Rec * *)&((struct Obj00088 *)p)->f3C);}

void ZUKAN_LIST_LoadFormTable(char *p) { ((struct Obj00123 *)p)->fC38=POKE_PERSONAL_LoadFormTable(107,0); }

void ZUKAN_LIST_FreeFormTable(char *p) { func_020307B0(((struct Obj00088 *)p)->fC38); }

void ZUKAN_LIST_MoveScrollBarActorsIn(char *p)
{
    unsigned i;
    s16_021BC8B4 pair[2];
    func_02041EE4(5, 3, 48);
    func_02041EE4(1, 3, -48);
    for (i = 3; i <= 9; i++) {
        ZUKAN_LIST_GetActorPos(p, i, &pair[1], &pair[0], 0);
        pair[0] += 48;
        ZUKAN_LIST_AddActorPos(p, i, pair[1], pair[0], 0);
    }
}

void ZUKAN_LIST_StartActorMoveFrames(char *a, int b)
{
    ((struct Obj00088 *)a)->fC40 = 0x30;
    *(unsigned short *)&((struct Obj00088 *)a)->fC42 = b;
}

int ZUKAN_LIST_UpdateActorMove(char *p)
{
    unsigned i;
    s16_021BC91C pair[2];
    int d;
    if (((struct Obj00088 *)p)->fC40 == 0) return 0;
    func_02041EE4(5, 4, ((struct Obj00088 *)p)->fC42);
    func_02041EE4(1, 5, ((struct Obj00088 *)p)->fC42);
    for (i = 3; i <= 9; i++) {
        ZUKAN_LIST_GetActorPos(p, i, &pair[1], &pair[0], 0);
        pair[0] += ((struct Obj00088 *)p)->fC42;
        ZUKAN_LIST_AddActorPos(p, i, pair[1], pair[0], 0);
    }
    d = ((struct Obj00088 *)p)->fC42;
    if (d < 0) d = -d;
    ((struct Obj00088 *)p)->fC40 -= d;
    return 1;
}

/*
 * ov067 is loaded by the same overlay's 021BCC94/021BCD48 path.
 */
void ZUKAN_LIST_CreateFrameList(struct Context_021BC388 *p)
{
    struct Template tmpl;
    void *arc,*str;
    u32 species,i;
    arc=func_020490F4(159,0x806b);
    species=ZUKAN_SAVE_GetLastViewedSpecies((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->save);
    tmpl=data_021BE7AC;
    tmpl.count=649;tmpl.p24=p;
    for(i=0;i<(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count;i++){
        if(species==(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]){
            if(i>(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count-7){
                tmpl.index=i-((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count-7);
                tmpl.start=i-tmpl.index;
            }else if(i<7){tmpl.index=i;}
            else{tmpl.start=i;}
            break;
        }
    }
    p->list=FRAME_LIST_Create((struct Tmpl *)(&tmpl),107);
    if(p->in->count<7)p->visible=p->in->count;else p->visible=7;
    FRAME_LIST_CopyMapToBuffer(p->list,(u32)arc,66,0,0);
    FRAME_LIST_CopyMapToBuffer(p->list,(u32)arc,67,0,1);
    FRAME_LIST_CopyMapToBuffer(p->list,(u32)arc,68,0,2);
    FRAME_LIST_LoadPalettes(p->list,arc,48,2,3);
    ARC_TOOL_DeleteHandle(arc);
    for(i=0;i<(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->count;i++){
        if(ZUKAN_SAVE_IsCaught((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->save,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i])==1){
            str=func_02045EC0(data_020A7370,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
            *(void **)((u32)p+i*4+0x4c)=STRBUF_Clone(str,107);
            STRBUF_Delete(str);
            FRAME_LIST_AddItem(p->list,0,0x20000000|(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
        }else if(ZUKAN_SAVE_IsSeen((*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->save,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i])==1){
            str=func_02045EC0(data_020A7370,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
            *(void **)((u32)p+i*4+0x4c)=STRBUF_Clone(str,107);
            STRBUF_Delete(str);
            FRAME_LIST_AddItem(p->list,1,0x10000000|(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
        }else{
            *(void **)((u32)p+i*4+0x4c)=func_02045EC0(((struct Obj00123 *)p)->f3C,7);
            FRAME_LIST_AddItem(p->list,2,(*(struct Inputs * *)&((struct Obj00123 *)p)->f0)->ids[i]);
        }
    }
}

void ZUKAN_LIST_DeleteFrameList(char *p) { u32 i;FRAME_LIST_Delete(*(struct S * *)&((struct Obj00088 *)p)->fC2C);for(i=0;i<649;i++){struct U16Vec *q=*(struct U16Vec **)((u32)p+i*4+76);if(q)STRBUF_Delete(q);} }

void ZUKAN_LIST_FrameListMoveCallback(char *p, int index, int a, u16 b, int c)
{
    u32 v;
    u32 low;
    v = FRAME_LIST_GetItemValue(((struct Obj02924 *)p)->fC2C, index);
    low = v & 0x0FFFFFFF;
    ZUKAN_LIST_PrintListRow(p, (unsigned char *)a, *(u32 *)(p + index * 4 + 0x4C), low);
    if ((v & 0xF0000000) >> 28) ZUKAN_LIST_ShowSpeciesActor(p, low, b, c);
}

void ZUKAN_LIST_FrameListSelectCallback(char *p, int index)
{
    u32 v;
    v = FRAME_LIST_GetItemValue(((struct Obj14667 *)p)->fC2C, index);
    if ((v & 0xF0000000) >> 28) ZUKAN_LIST_LoadSpeciesIcon(p, v & 0x0FFFFFFF);
    else ZUKAN_LIST_LoadSpeciesIcon(p, 0);
    ZUKAN_LIST_MoveCursorActor(p, index - FRAME_LIST_GetScrollPos(*(char * *)&((struct Obj14667 *)p)->fC2C));
}

void ZUKAN_LIST_ScrollByDelta(char *p,int delta) { ZUKAN_LIST_ScrollActorsBy(p,(signed char)-delta);ZUKAN_LIST_MoveCursorActor(p,FRAME_LIST_GetCursor(*(char * *)&((struct Obj00088 *)p)->fC2C));ZUKAN_LIST_UpdateArrowActors(p,1); }

extern int (*const d_021BE96C[])(char *);

int ZUKAN_LIST_RunState(char *p) { ((struct Obj08408 *)p)->f10=(*(int (**)(char *))((u32)d_021BE96C+*(u32 *)(p+16)*4))(p);if(((struct Obj08408 *)p)->f10==9)return 0;ZUKAN_LIST_UpdateActors(p);ZUKAN_LIST_FlushWindows((const struct Context_021BCBE0 *)p);func_021C93E4(3,7,(u8 *)p+0xc3c);return 1; }

/*
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCCB0, 021BCCB2
 */
int ZUKAN_LIST_StateInit(char *p)
{
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_0204363C(0);
    ZUKAN_LIST_InitPaletteAnim(p);
    ZUKAN_LIST_SetVramBanks();
    ZUKAN_LIST_InitBgSystem();
    ZUKAN_LIST_LoadBgGraphics();
    ZUKAN_LIST_CreateFontAndPrinter(p);
    ZUKAN_LIST_CreateWindows(p);
    ZUKAN_LIST_InitActors(p);
    ZUKAN_LIST_LoadFormTable(p);
    ZUKAN_LIST_CreateFrameList((struct Context_021BC388 *)((struct Context_021BCBE0 *)p));
    if (((struct Obj25546 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f8 == 0) ZUKAN_LIST_DrawHeaderCounts(p);
    else ZUKAN_LIST_DrawHeaderNational(p);
    GFL_NET_RestartWithDefaultTimeout(1, 0x6B);
    ZUKAN_LIST_SetSubScreenBlendAlpha();
    ZUKAN_LIST_EnableSubWindows();
    ZUKAN_LIST_MoveScrollBarActorsIn(p);
    ZUKAN_LIST_StartVBlankTask(p);
    ZUKAN_LIST_StartHBlankTask(p);
    return 3;
}

/*
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCDB6, 021BCDBA
 */
int ZUKAN_LIST_StateExit(char *p)
{
    if (ZUKAN_LIST_UpdateActorMove(p) == 1 || PALANM_GetFadeRequestBits(*(char * *)&((struct Obj00088 *)p)->fC) != 0) return 1;
    ZUKAN_LIST_StopHBlankTask(p);
    ZUKAN_LIST_StopVBlankTask(p);
    ZUKAN_LIST_DisableSubWindows();
    ZUKAN_LIST_DeleteFrameList(p);
    ZUKAN_LIST_FreeFormTable(p);
    ZUKAN_LIST_ExitActors(p);
    ZUKAN_LIST_DeleteWindows(p);
    ZUKAN_LIST_DeleteFontAndPrinter(p);
    ZUKAN_LIST_ExitBgSystem();
    ZUKAN_LIST_ExitPaletteAnim(p);
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02034A5C((int)ov067_id);
    return 9;
}

int ZUKAN_LIST_StateWaitFade(char *p) { if(PALANM_GetFadeRequestBits(*(char * *)&((struct Obj14668 *)p)->fC)==0)return ((struct Obj14668 *)p)->f1C;return 2; }

/*
 * note: int step schedules the p copy before movs r6,16; enum step swaps those instructions (DIFF4).
 */
int ZUKAN_LIST_StateFadeIn(char *p)
{
    int step;
    switch (((struct Obj00088 *)p)->fC30) {
    case 0:
        if (FRAME_LIST_UpdateInit(*(S * *)&((struct Obj00088 *)p)->fC2C) == 0) {
            ZUKAN_LIST_UpdateArrowActors(p, 0);
            ZUKAN_LIST_UpdateScrollBarActor(p);
            ZUKAN_LIST_HideAllActors(p);
            ZUKAN_LIST_ResetPaletteSlots(p);
            (((struct Obj00088 *)p)->fC30)++;
        }
        break;
    case 1:
        if (PALANM_GetFadeRequestBits(*(char * *)&((struct Obj00088 *)p)->fC) == 0) {
            func_0207D534((unsigned short *)0x0400006c, 0);
            func_0207D534((unsigned short *)0x0400106c, 0);
            ZUKAN_LIST_RequestFade(p, step = 16, 0);
            step -= 24;
            ZUKAN_LIST_StartActorMoveFrames(p, step);
            (((struct Obj00088 *)p)->fC30)++;
        }
        break;
    case 2:
        if (ZUKAN_LIST_UpdateActorMove(p) == 0 && PALANM_GetFadeRequestBits(*(char * *)&((struct Obj00088 *)p)->fC) == 0) {
            ((struct Obj00088 *)p)->fC30 = 0;
            return 4;
        }
        break;
    }
    return 3;
}

/*
 * ov067 region follows the paired loader path 021BCC94/021BCD48.
 * 021B93D4's value is full width here: original subtract feeds r1 without narrowing.
 */
int ZUKAN_LIST_StateMain(struct Context_021BCBE0 *p)
{
    int result=4;
    int selected;
    u32 action;
    u8 old;
    switch(FRAME_LIST_Update(p->list)){
    case -12: break;
    case -11:case -10:case -9:case -8:
        ZUKAN_LIST_UpdateArrowActors((char *)p,0);break;
    case -7:
        ZUKAN_LIST_StartActorAnim((char *)p,7,12);
        p->flags=(p->flags&~0xfffe)|14;p->state=0;result=5;break;
    case -6:
        ZUKAN_LIST_StartActorAnim((char *)p,6,13);
        p->flags=(p->flags&~0xfffe)|12;p->state=0;result=5;break;
    case -5:return ZUKAN_LIST_StartButtonAnim((char *)p,7,12,4);
    case -4:return ZUKAN_LIST_StartButtonAnim((char *)p,6,13,4);
    case -3:case -2:
        ZUKAN_LIST_ShowAllActors((char *)p);
        p->flags=(p->flags&~0xfffe)|120;p->state=1;result=5;break;
    case -1:
        old=func_020355C4();
        action=ZUKAN_LIST_HandleTouchInput(p);
        switch(action){
        case 0:
            selected=FRAME_LIST_GetSelectedIndex(p->list);
            if(ZUKAN_LIST_IsSpeciesEntryValid((char *)p,selected)==1){GFL_USE_PlaySeDefaultVolume(1356);return ZUKAN_LIST_StateSelectSpecies((char *)p,selected);}
            func_020355D8(old);break;
        case 1:case 2:case 3:case 4:case 5:case 6:case 7:
            selected=action+FRAME_LIST_GetScrollPos(p->list)-1;
            if(ZUKAN_LIST_IsSpeciesEntryValid((char *)p,selected)==1){
                GFL_USE_PlaySeDefaultVolume(1356);func_021B93D4(p->list,action-1);return ZUKAN_LIST_StateSelectSpecies((char *)p,selected);
            }break;
        case 8:
            GFL_USE_PlaySeDefaultVolume(1356);p->in->state=4;
            ZUKAN_LIST_StoreLastViewedSpecies((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return ZUKAN_LIST_StartButtonAnim((char *)p,9,4,8);
        case 9:
            GFL_USE_PlaySeDefaultVolume(1356);
            if(ZUKAN_SAVE_GetViewMode(p->in->save)==1)ZUKAN_SAVE_SetViewMode(p->in->save,0);else ZUKAN_SAVE_SetViewMode(p->in->save,1);
            p->in->state=2;
            ZUKAN_LIST_StoreLastViewedSpecies((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return ZUKAN_LIST_StartButtonAnim((char *)p,8,5,8);
        case 10:GFL_USE_PlaySeDefaultVolume(1606);ZUKAN_LIST_ToggleSaveFlag15((char *)p);break;
        case 11:
            GFL_USE_PlaySeDefaultVolume(1366);p->in->state=1;
            ZUKAN_LIST_StoreLastViewedSpecies((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return ZUKAN_LIST_StartButtonAnim((char *)p,4,8,8);
        case 12:
            GFL_USE_PlaySeDefaultVolume(1361);p->in->state=0;
            ZUKAN_LIST_StoreLastViewedSpecies((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return ZUKAN_LIST_StartButtonAnim((char *)p,3,9,8);
        case 13:
            GFL_USE_PlaySeDefaultVolume(1361);p->in->state=0;
            ZUKAN_LIST_StoreLastViewedSpecies((char *)p,FRAME_LIST_GetSelectedIndex(p->list));return ZUKAN_LIST_StartButtonAnim((char *)p,3,9,8);
        }
        break;
    default:
        selected=FRAME_LIST_GetSelectedIndex(p->list);ZUKAN_LIST_UpdateArrowActors((char *)p,0);
        if(ZUKAN_LIST_IsSpeciesEntryValid((char *)p,selected)==1){GFL_USE_PlaySeDefaultVolume(1356);return ZUKAN_LIST_StateSelectSpecies((char *)p,selected);}
        break;
    }
    ZUKAN_LIST_UpdateScrollBarActor((char *)p);ZUKAN_LIST_HideAllActors((char *)p);return result;
}

int ZUKAN_LIST_StateScroll(char *p)
{
    switch (*(int *)&((struct Obj00088 *)p)->f14) {
    case 0:
        if (FRAME_LIST_Update((struct S *)(*(char * *)&((struct Obj00088 *)p)->fC2C)) == -1) (*(int *)&((struct Obj00088 *)p)->f14)++;
        break;
    case 1:
        if (((struct Timer *)(p + 0xc24))->high == 60 || ZUKAN_LIST_IsActorAnimActive(p, ((struct Timer *)(p + 0xc24))->high) == 0) {
            *(int *)&((struct Obj00088 *)p)->f14 = 0;
            ZUKAN_LIST_UpdateArrowActors(p, 0);
            return 4;
        }
        break;
    }
    return 5;
}

int ZUKAN_LIST_StateScrollWait(char *p) { if(ZUKAN_LIST_IsActorAnimActive(p,((struct Bits *)(p+0xc24))->high)==0){ZUKAN_LIST_UpdateArrowActors(p,0);return ((struct Obj00088 *)p)->f18;}return 6; }

/*
 * note: repeated decrement in each arm cross-jumps through branch stubs; explicit shared goto costs DIFF81/156.
 */
int ZUKAN_LIST_StateCursorFlash(char *p)
{
    switch (((struct Obj01435 *)p)->fC26) {
    case 0:
    case 2:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            FRAME_LIST_SetRowPalette((u8 *)(*(char * *)&((struct Obj01435 *)p)->fC2C), (unsigned short)FRAME_LIST_GetCursor(*(char * *)&((struct Obj01435 *)p)->fC2C), 1);
            ((struct Obj01435 *)p)->fC27 = 4;
            (((struct Obj01435 *)p)->fC26)++;
        } else (((struct Obj01435 *)p)->fC27)--;
        break;
    case 1:
    case 3:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            FRAME_LIST_SetRowPalette((u8 *)(*(char * *)&((struct Obj01435 *)p)->fC2C), (unsigned short)FRAME_LIST_GetCursor(*(char * *)&((struct Obj01435 *)p)->fC2C), 2);
            func_02041B6C(2);
            ((struct Obj01435 *)p)->fC27 = 4;
            (((struct Obj01435 *)p)->fC26)++;
        } else (((struct Obj01435 *)p)->fC27)--;
        break;
    case 4:
        if (((struct Obj01435 *)p)->fC27 == 0) {
            ((struct Obj01435 *)p)->fC26 = 0;
            return 8;
        }
        (((struct Obj01435 *)p)->fC27)--;
        break;
    }
    return 7;
}

int ZUKAN_LIST_StateFadeOut(char *p) { ZUKAN_LIST_RequestFade(p,0,16);ZUKAN_LIST_StartActorMoveFrames(p,8);return 1; }

void ZUKAN_LIST_ResetPaletteSlots(char *p)
{
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 1, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 2, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC, 3, 0, 512);
    ZUKAN_LIST_RequestFade(p, 16, 16);
}

int ZUKAN_LIST_StartButtonAnim(char *p,int a,int b,int c) { ZUKAN_LIST_StartActorAnim(p,a,b);((struct Bits *)(p+0xc24))->high=(u16)a;((struct Obj25555 *)p)->f18=c;return 6; }

int ZUKAN_LIST_IsSpeciesEntryValid(char *p,int i) { if((FRAME_LIST_GetItemValue(*(char * *)&((struct Obj00088 *)p)->fC2C,i)&0xf0000000u)>>28)return 1;return 0; }

void ZUKAN_LIST_StoreLastViewedSpecies(char *p,int i) { if(ZUKAN_LIST_IsSpeciesEntryValid(p,i)==1)ZUKAN_SAVE_SetLastViewedSpecies(((struct Obj25556 *)(*(char * *)&((struct Obj00088 *)p)->f0))->f4,FRAME_LIST_GetItemValue(*(char * *)&((struct Obj00088 *)p)->fC2C,i)); }

int ZUKAN_LIST_StateSelectSpecies(char *a, int arg)
{
    ZUKAN_LIST_StoreLastViewedSpecies(a, arg);
    *(int *)(*(int *)&((struct Obj00088 *)a)->f0 + 0x10) = 3;
    return 7;
}

/*
 * extent: 021BD396 two-byte alignment padding before 021BD398.
 */
void ZUKAN_LIST_ToggleSaveFlag15(char *p)
{
    if (GAME_DATA_CheckSaveFlag(**(int * *)&((struct Obj10912 *)p)->f0, 15) == 1) {
        GAME_DATA_SetSaveFlag(**(void ** *)&((struct Obj10912 *)p)->f0, 15, 0);
        ZUKAN_LIST_StartActorAnim(p, 5, 6);
    } else {
        GAME_DATA_SetSaveFlag(**(void ** *)&((struct Obj10912 *)p)->f0, 15, 1);
        ZUKAN_LIST_StartActorAnim(p, 5, 7);
    }
}

void ZUKAN_LIST_CreateWindows(char *p)
{
    unsigned i;
    BMP_WIN_Init(107);
    for (i = 0; i < 3; i++)
        *(unsigned *)(p + i * 8 + 32) = BMP_WIN_Create(d_021BE990[i][0], d_021BE990[i][1], d_021BE990[i][2], d_021BE990[i][3], d_021BE990[i][4], d_021BE990[i][5], 1);
    ZUKAN_LIST_DrawHeaderRegional(p);
}

void ZUKAN_LIST_DeleteWindows(char *p) { u32 i;for(i=0;i<3;i++)BMP_WIN_Delete(*(struct Descriptor **)((u32)p+i*8+32));BMP_WIN_Exit(); }

/*
 * extent: 021BD43E..021BD440 is two zero alignment bytes before matched D440.
 * lever: first types search hoisted the initialized full-word ps load before entry arithmetic.
 * checks: 1 own C4E4, C6C4, 45770, 45334 bodies prove 1/2/1/1 arity; 2 ov0679344 and ov208C0740 confirm full-word handles; 3 carried two compiles exhausted; 4 carried two order/extraction probes exhausted; 5 fresh idioms/neighbours read, no stack object. Wave32 I4 pointer ps unchanged5; types search9 candidates exact after ps hoist, all inputs and call/store order preserved.
 */
void ZUKAN_LIST_FlushWindows(const struct Context_021BCBE0 *p)
{
    int ps;
    long i;
    char *entry;
    PRINTSYS_QUE_Main((struct PrintSys *)p->ps);
    for (i = 0; i < 3u; i++) {
        ps = p->ps;
        entry = (char *)p + i * 8;
        if (((struct Obj08409 *)entry)->f24) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)ps, BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj08409 *)entry)->f20)) == 0) {
                BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj08409 *)entry)->f20);
                ((struct Obj08409 *)entry)->f24 = 0;
            }
        }
    }
}

/*
 * extent: 021BD486 two-byte alignment padding before 021BD488.
 */
void ZUKAN_LIST_PrintTouchbarLabel(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode)
{
    void *text;
    text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00123 *)p)->f3C, msg);
    TOUCHBAR_PrintAligned((unsigned char *)(p + 32 + index * 8), (void *)(((struct Obj00123 *)p)->f48), x, y, (unsigned)text, *(unsigned *)&((struct Obj00123 *)p)->f38, color, mode);
    STRBUF_Delete(text);
}

/*
 * extent: 021BD4DA two-byte alignment padding before existing labelled 021BD4DC.
 */
void ZUKAN_LIST_PrintTouchbarLabelClone(char *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode)
{
    void *text;
    text = func_02045EC0(*(struct MsgBank * *)&((struct Obj00123 *)p)->f3C, msg);
    func_0201F250(*(struct WordSet * *)&((struct Obj00123 *)p)->f40, ((struct Obj00123 *)p)->f44, text);
    TOUCHBAR_PrintAligned((unsigned char *)(p + 32 + index * 8), (void *)(((struct Obj00123 *)p)->f48), x, y, *(unsigned *)&((struct Obj00123 *)p)->f44, *(unsigned *)&((struct Obj00123 *)p)->f38, color, mode);
    STRBUF_Delete(text);
}

void ZUKAN_LIST_MakeWindowScreens(void **p) {BMP_WIN_MakeScreen(*p);func_02041B6C(BMP_WIN_GetBgLayer(*p));}

void ZUKAN_LIST_ClearWindow(u8 *p, u32 idx)
{
    void *o2;
    void *o1;
    void *t2;
    u8 *gfx;
    void *t1;
    u8 *dst;
    u16 j;
    u8 *row;
    int y;
    int h;
    u8 w;
    int x;
    u8 *map;
    struct Descriptor **ent = (struct Descriptor **)(p + 0x20);
    void *arc;
    u16 i;

    w = BMP_WIN_GetDispWidth(*(struct Descriptor **)((u8 *)ent + idx * 8));
    h = BMP_WIN_GetDispHeight(*(struct Descriptor **)((u8 *)ent + idx * 8));
    x = BMP_WIN_GetPosX(*(struct Descriptor **)((u8 *)ent + idx * 8));
    y = BMP_WIN_GetPosY(*(struct Descriptor **)((u8 *)ent + idx * 8));
    dst = BMP_GetPixels(BMP_WIN_GetBmp(*(struct Descriptor **)((u8 *)ent + idx * 8)));
    arc = func_020490F4(0x9F, 0x6B);
    t1 = func_02049EF4(arc, 0x45, 0, &o1, 0x806B);
    map = (u8 *)o1 + 0xC;
    t2 = func_02049DF4(arc, 0x39, 0, (u32)(&o2), 0x806B);
    gfx = *(u8 **)((u8 *)o2 + 0x14);
    ARC_TOOL_DeleteHandle(arc);
    if (h > 0) {
        row = map + x * 2;
        j = 0;
        do {
            for (i = 0; i < w; i++) {
                u16 c = *(u16 *)(row + (y + j) * 64 + i * 2);
                MIi_CpuCopy32(gfx + (c & 0x3FF) * 32, dst + (i + j * w) * 32, 0x20);
            }
            j++;
        } while (j < h);
    }
    func_020307B0(t2);
    func_020307B0(t1);
}

void ZUKAN_LIST_DrawHeaderRegional(char *p)
{
    ZUKAN_LIST_ClearWindow((u8 *)p, 0);
    if (ZUKAN_SAVE_GetViewMode(((struct Obj25560 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4) == 1)
        ZUKAN_LIST_PrintTouchbarLabel(p, 0, 1, 0, 4, 0x39e0, 0);
    else
        ZUKAN_LIST_PrintTouchbarLabel(p, 0, 0, 0, 4, 0x39e0, 0);
    ZUKAN_LIST_MakeWindowScreens((void **)(p + 32));
}

void ZUKAN_LIST_DrawHeaderCounts(char *p)
{
    unsigned a, b;
    if (ZUKAN_SAVE_GetViewMode(((struct Obj25561 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4) == 1) {
        a = ZUKAN_SAVE_CountSeenNational(((struct Obj25562 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4);
        b = ZUKAN_SAVE_CountCaughtNational(((struct Obj25563 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4);
    } else {
        a = ZUKAN_SAVE_CountSeenRegional(((struct Obj25564 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4, 0x806b);
        b = ZUKAN_SAVE_CountCaughtRegional(((struct Obj25565 *)(*(char * *)&((struct Obj00123 *)p)->f0))->f4, 0x806b);
    }
    ZUKAN_LIST_ClearWindow((u8 *)p, 1);
    ZUKAN_LIST_ClearWindow((u8 *)p, 2);
    ZUKAN_LIST_PrintTouchbarLabel(p, 1, 2, 0x48, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet * *)&((struct Obj00123 *)p)->f40, 0, a, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 1, 5, 0x68, 4, 0x31a0, 1);
    ZUKAN_LIST_PrintTouchbarLabel(p, 2, 3, 0x58, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet * *)&((struct Obj00123 *)p)->f40, 0, b, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 2, 5, 0x78, 4, 0x31a0, 1);
    ZUKAN_LIST_MakeWindowScreens((void **)(p + 0x28));
    ZUKAN_LIST_MakeWindowScreens((void **)(p + 0x30));
}

void ZUKAN_LIST_DrawHeaderNational(char *p)
{
    ZUKAN_LIST_ClearWindow((u8 *)p, 2);
    ZUKAN_LIST_PrintTouchbarLabel(p, 2, 4, 88, 4, 0x31a0, 1);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj00123 *)p)->f40, 0, ((struct Obj25566 *)(*(char * *)&((struct Obj00123 *)p)->f0))->fA, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 2, 5, 120, 4, 0x31a0, 1);
    ZUKAN_LIST_MakeWindowScreens((void **)(p + 48));
}

void ZUKAN_LIST_PrintListRow(char *p, unsigned char *dest, unsigned text0, unsigned index)
{
    unsigned ps;
    void *text;
    ps = FRAME_LIST_GetPrinter(*(char * *)&((struct Obj02924 *)p)->fC2C);
    if (ZUKAN_SAVE_GetViewMode(*(struct Blk37 * *)&((struct Obj25567 *)(*(char * *)&((struct Obj02924 *)p)->f0))->f4) == 0)
        index = (*(u16 **)(p + 0xc38))[index];
    text = func_02045EC0(*(struct MsgBank * *)&((struct Obj02924 *)p)->f3C, 8);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj02924 *)p)->f40, 0, index, 3, 2, 1);
    func_0201F250(*(struct WordSet * *)&((struct Obj02924 *)p)->f40, ((struct Obj02924 *)p)->f44, text);
    STRBUF_Delete(text);
    TOUCHBAR_PrintAligned(dest, (void *)ps, 0, 4, *(unsigned *)&((struct Obj02924 *)p)->f44, ((struct Obj02924 *)p)->f38, 0x39e0, 0);
    TOUCHBAR_PrintAligned(dest, (void *)ps, 28, 4, text0, ((struct Obj02924 *)p)->f38, 0x39e0, 0);
}

void ZUKAN_LIST_InitActors(char *p) {ZUKAN_LIST_InitActorSystem(p);ZUKAN_LIST_LoadActorResources((struct R_021BD3E0 *)p);ZUKAN_LIST_CreateActors(p);ZUKAN_LIST_UpdateSpeciesActors(p);BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);}

void ZUKAN_LIST_ExitActors(char *a)
{
    ZUKAN_LIST_DeleteActorUnit(a);
    ZUKAN_LIST_ReleaseActorResources(a);
    CLACT_ExitSystem();
}

void ZUKAN_LIST_UpdateActors(char *p) {u32 i;for(i=0;i<60;i++) {if(*(void **)(p+i*4+0xa74)) {if(CLACT_GetActorAutoAnim(*(struct Actor **)(p+i*4+0xa74))!=1) CLACT_AddActorAnimFrame(*(struct Obj **)(p+i*4+0xa74),0x1000);}}CLACT_DrawSystem();}

void ZUKAN_LIST_SetActorAnim(char *p, int idx, int v)
{
    CLACT_SetActorAnimFrame(*(void **)(p + 0xa74 + idx * 4), 0);
    CLACT_SetActorAnimSeq(*(void **)(p + 0xa74 + idx * 4), (unsigned short)v);
}

void ZUKAN_LIST_StartActorAnim(char *p,int idx,int value) {ZUKAN_LIST_SetActorAnim(p,idx,value);CLACT_SetActorAutoAnim((struct Obj *)*(struct Actor **)(p+idx*4+0xa74),1);}

int ZUKAN_LIST_GetActorAnimSeq(char *a, int b)
{
    return CLACT_GetActorAnimSeq((struct Obj *)(*(int *)(a + b * 4 + 0xa74)));
}

u32 ZUKAN_LIST_IsActorAnimActive(char *p,u32 idx) {return CLACT_IsActorAnimActive(*(struct Actor **)(p+idx*4+0xa74));}

void ZUKAN_LIST_SetActorVisible(char *p,u32 idx,u32 value) {struct Obj *o;o=*(struct Obj **)(p+idx*4+0xa74);if(o) CLACT_SetActorDrawEnable(o,value);}

u32 ZUKAN_LIST_GetActorVisible(char *p,u32 idx) {return CLACT_GetActorDrawEnable(*(struct Obj **)(p+idx*4+0xa74));}

void ZUKAN_LIST_SetActorObjMode(char *p,u32 idx,u32 flag) {if(flag==1) CLACT_SetActorObjMode(*(struct Actor **)(p+idx*4+0xa74),1);else CLACT_SetActorObjMode(*(struct Actor **)(p+idx*4+0xa74),0);}

void ZUKAN_LIST_AddActorPos(char *p, int idx, short a, short b, unsigned short c)
{
    unsigned short buf[2];
    buf[0] = a;
    buf[1] = b;
    CLACT_AddActorSurfacePos(*(void **)(p + idx * 4 + 0xa74), (const struct Vec2 *)buf, c);
}

/*
 * prototype: outgoing space argument is loaded by ldrh at 021BD966; callee extern uses u16 for the observed bits.
 */
void ZUKAN_LIST_GetActorPos(char *p,u32 idx,s16 *x,s16 *y,u16 space) {PtS point;CLACT_GetActorSurfacePos(*(struct Actor **)(p+idx*4+0xa74),&point,space);*x=point.x;*y=point.y;}

void ZUKAN_LIST_InitActorSystem(char *p) {TemplateB t;t=d_021BE9D4;CLACT_InitSystem((const struct Cfg *)&t,(u32)ZUKAN_LIST_GetVramBankConfig(),107);}

void ZUKAN_LIST_LoadActorResources(struct R_021BD3E0 *p)
{
    int h, h2, h3;
    u32 i;
    u32 k;
    u32 a;
    int *arr;
    int *pb;
    int *pc;

    for (k = 0; k < 0x24; k++) p->a[k] = -1;
    for (k = 0; k < 6; k++) p->b[k] = -1;
    for (k = 0; k < 6; k++) p->c[k] = -1;

    h = (int)func_020490F4(0x9f, 0x806B);
    p->a[0x23] = CLACT_RegisterCharacter((void *)h, 0x37, 0, 0, 0x6b);
    p->b[5] = CLACT_RegisterPalette((void *)h, 0x33, 0, 0, 0x6b);
    p->c[5] = CLACT_RegisterCellAnim((void *)h, 0x3d, 0x47, 0x6b);
    ARC_TOOL_DeleteHandle((void *)h);

    h2 = (int)func_020490F4(7, 0x806B);
    arr = p->a;
    pb = &p->b[0];
    pc = &p->c[0];
    for (i = 0; i < 0x10; i++)
        arr[i] = CLACT_RegisterCharacter((void *)h2, POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0), 0, 0, 0x6b);
    *pb = CLACT_RegisterPaletteCompressed((void *)h2, func_0201BC3C(), 0, 0x80, 0x6b);
    a = func_0201BC40();
    *pc = CLACT_RegisterCellAnim((void *)h2, a, func_0201BCB4(), 0x6b);

    arr = &p->a[0x10];
    pb = &p->b[1];
    pc = &p->c[1];
    for (i = 0; i < 0x10; i++)
        arr[i] = CLACT_RegisterCharacter((void *)h2, POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0), 0, 1, 0x6b);
    *pb = CLACT_RegisterPaletteCompressed((void *)h2, func_0201BC3C(), 1, 0, 0x6b);
    a = func_0201BC78();
    *pc = CLACT_RegisterCellAnim((void *)h2, a, func_0201BCEC(), 0x6b);
    ARC_TOOL_DeleteHandle((void *)h2);

    h3 = (int)func_020490F4(func_020275E4(), 0x806B);
    p->a[0x22] = CLACT_RegisterCharacter((void *)h3, func_02027618(), 0, 0, 0x6b);
    p->b[4] = CLACT_RegisterPalette((void *)h3, func_02027614(), 0, 0xe0, 0x6b);
    a = func_0202761C(2);
    p->c[4] = CLACT_RegisterCellAnim((void *)h3, a, func_02027620(2), 0x6b);
    ARC_TOOL_DeleteHandle((void *)h3);
}

void ZUKAN_LIST_ReleaseActorResources(char *p)
{
    unsigned i;
    for(i=0;i<36;i++)if(*(unsigned *)(p+i*4+0xb64)!=-1)CLACT_ReleaseCharacter(*(unsigned *)(p+i*4+0xb64));
    for(i=0;i<6;i++)if(*(unsigned *)(p+i*4+0xbf4)!=-1)CLACT_ReleasePalette(*(unsigned *)(p+i*4+0xbf4));
    for(i=0;i<6;i++)if(*(unsigned *)(p+i*4+0xc0c)!=-1)CLACT_ReleaseCellAnim(*(unsigned *)(p+i*4+0xc0c));
}

void ZUKAN_LIST_CreateActors(char *p)
{
    unsigned i;
    Template_021BDC08 t;
    ((struct Obj04617 *)p)->fA70 = CLACT_CreateUnit(60, 0, 0x6b);
    for (i = 0; i < 60; i++)
        *(unsigned *)(p + i * 4 + 0xa74) = 0;
    for (i = 0; i <= 9; i++) {
        t = d_021BE9F0[i];
        t.w8 = *(u32 *)(p + t.w8 * 4 + 0xb64);
        t.wC = *(u32 *)(p + t.wC * 4 + 0xbf4);
        t.w10 = *(u32 *)(p + t.w10 * 4 + 0xc0c);
        *(void **)(p + i * 4 + 0xa74) = func_021C940C((u32)(((struct Obj04617 *)p)->fA70), (const u8 *)(&t), 0x6b);
        CLACT_SetActorVisible(*(void **)(p + i * 4 + 0xa74), 0);
    }
    if (((struct Obj25570 *)(*(char * *)&((struct Obj04617 *)p)->f0))->fA <= 7) {
        ZUKAN_LIST_SetActorVisible(p, 0, 0);
        ZUKAN_LIST_SetActorVisible(p, 1, 0);
    }
    if (ZUKAN_SAVE_GetDexObtained(((struct Obj25571 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f4) == 0)
        ZUKAN_LIST_SetActorVisible(p, 9, 0);
    if (ZUKAN_SAVE_IsNationalDexEnabled(((struct Obj25572 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f4) == 0)
        ZUKAN_LIST_SetActorVisible(p, 8, 0);
    if (((struct Obj25573 *)(*(char * *)&((struct Obj04617 *)p)->f0))->f8 == 1) {
        ZUKAN_LIST_SetActorVisible(p, 8, 0);
        ZUKAN_LIST_SetActorVisible(p, 5, 0);
    } else if (GAME_DATA_CheckSaveFlag(**(int * *)&((struct Obj04617 *)p)->f0, 15) == 1)
        ZUKAN_LIST_StartActorAnim(p, 5, 7);
}

void ZUKAN_LIST_DeleteActor(char *p,u32 idx) {char *base;u32 offset;offset=idx*4;base=p+0xa74;if(*(struct Obj **)(base+offset)) {CLACT_DeleteActor(*(struct Obj **)(base+offset));*(struct Obj **)(base+offset)=0;}}

void ZUKAN_LIST_DeleteActorUnit(char *p) {u32 i;for(i=0;i<60;i++) ZUKAN_LIST_DeleteActor(p,i);CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25575 *)p)->fA70);}

void ZUKAN_LIST_LoadSpeciesIcon(char *p,u16 species)
{
    Template_021BDD7C t;
    unsigned out1,outForm,out2;
    unsigned other,index,base;
    void *personal;
    t=d_021BE9BC;
    if (((Flags *)(p+0xc24))->side==0) {
        other=59; index=58; base=0x160;
    } else {
        other=58; index=59;
        t.w8=33; t.wC=3; t.w10=3;
        base=0x180;
    }
    if (*(unsigned *)(p+0xa74+index*4)!=0) {
        ZUKAN_LIST_DeleteActor(p,index);
        if (*(unsigned *)(p+t.w8*4+0xb64)!=(unsigned)-1)
            CLACT_ReleaseCharacter(*(unsigned *)(p+t.w8*4+0xb64));
        if (*(unsigned *)(p+t.wC*4+0xbf4)!=(unsigned)-1)
            CLACT_ReleasePalette(*(unsigned *)(p+t.wC*4+0xbf4));
        if (*(unsigned *)(p+t.w10*4+0xc0c)!=(unsigned)-1)
            CLACT_ReleaseCellAnim(*(unsigned *)(p+t.w10*4+0xc0c));
    }
    if (species==0) {
        void *arc;
        arc=func_020490F4(0x9f,0x806b);
        *(unsigned *)(p+t.w8*4+0xb64)=CLACT_RegisterCharacter(arc,0x36,0,0,0x6b);
        *(unsigned *)(p+t.wC*4+0xbf4)=CLACT_RegisterPaletteEx(arc,0x32,0,(u16)base,0,1,0x6b);
        *(unsigned *)(p+t.w10*4+0xc0c)=CLACT_RegisterCellAnim(arc,0x3c,0x46,0x6b);
        ARC_TOOL_DeleteHandle(arc);
        ZUKAN_LIST_SetActorVisible(p,2,0);
    } else {
        void *arc;
        unsigned personality;
        ZUKAN_SAVE_GetViewGenderAndForm(*(u8 * *)&((struct Obj25576 *)(*(char * *)&((struct Obj08410 *)p)->f0))->f4,species,&out1,&out2,&outForm,0x806b);
        arc=(void *)POKEGRA_OpenHandle(0x806b);
        personality=species==0x147?ZUKAN_SAVE_GetSpindaPersonality(((struct Obj25577 *)(*(char * *)&((struct Obj08410 *)p)->f0))->f4,0):0;
        *(unsigned *)(p+t.w8*4+0xb64)=POKEGRA_RegisterCgr((u32)arc,species,outForm,out1,out2,0,0,personality,0,0x6b);
        *(unsigned *)(p+t.wC*4+0xbf4)=POKEGRA_RegisterPalette((int)arc,species,outForm,out1,out2,0,0,0,base,0x6b);
        *(unsigned *)(p+t.w10*4+0xc0c)=POKEGRA_RegisterCellAnim(species,outForm,out1,out2,0,0,2,0,0x6b);
        ARC_TOOL_DeleteHandle(arc);
        ZUKAN_LIST_SetActorVisible(p,2,1);
    }
    t.w8=*(unsigned *)(p+t.w8*4+0xb64);
    t.wC=*(unsigned *)(p+t.wC*4+0xbf4);
    t.w10=*(unsigned *)(p+t.w10*4+0xc0c);
    *(void **)(p+0xa74+index*4)=func_021C940C((u32)(((struct Obj08410 *)p)->fA70),(const u8 *)(&t),0x6b);
    CLACT_SetActorVisible(*(void **)(p+0xa74+index*4),0);
    personal=POKE_PERSONAL_Create(species,(u16)outForm,0x806b);
    if (species!=0 && POKE_PERSONAL_GetParam(personal,0x22)==0)
        CLACT_SetActorFlip(*(void **)(p+0xa74+index*4),1,1);
    POKE_PERSONAL_Delete(personal);
    ZUKAN_LIST_SetActorVisible(p,other,0);
    PALANM_CopyHwPaletteToSlot(((struct Obj08410 *)p)->fC,2,(u16)((base>>5)<<4),0x20);
    ((Flags *)(p+0xc24))->side^=1;
}

void ZUKAN_LIST_UpdateSpeciesActors(char *p) {
    struct R_021BE010 a;
    struct R_021BE010 b;
    u32 *pb;
    u32 i;
    u32 j;
    u32 k;
    a = d_021BE9A4;
    b = d_021BE9A4;
    b.fC = *(u32 *)(p + 0xBF4);
    b.f10 = *(u32 *)(p + 0xC0C);
    for (i = 0; i < 16; i++) {
        b.f2 = i * 0x18 + 8;
        b.f8 = *(u32 *)(p + i * 4 + 0xB64);
        *(u32 *)(p + i * 4 + 0xA9C) = (u32)func_021C940C(*(u32 *)(p + 0xA70), (const u8 *)(&b), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)(p + i * 4 + 0xA9C)), 0);
    }
    b = a;
    b.fC = *(u32 *)(p + 0xBF8);
    b.f10 = *(u32 *)(p + 0xC10);
    for (j = 0; j < 16; j++) {
        b.f2 = j * 0x18 + 0x20;
        b.f8 = *(u32 *)(p + j * 4 + 0xBA4);
        b.f16 = 1;
        *(u32 *)(p + j * 4 + 0xADC) = (u32)func_021C940C(*(u32 *)(p + 0xA70), (const u8 *)(&b), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)(p + j * 4 + 0xADC)), 0);
        ZUKAN_LIST_SetActorObjMode(p, j + 0x1a, 1);
        pb = (u32 *)(p + 0xA70);
        *(u32 *)(p + j * 4 + 0xB1C) = (u32)func_021C940C(*pb, (const u8 *)(&b), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)(p + j * 4 + 0xB1C)), 0);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + j * 4 + 0xB1C)), 2);
    }
    for (k = 0; k < 16; k++) ZUKAN_LIST_SetActorVisible(p, k + 0xa, 0);
    for (i = 0; i < 16; i++) {
        ZUKAN_LIST_SetActorVisible(p, i + 0x1a, 0);
        ZUKAN_LIST_SetActorVisible(p, i + 0x2a, 0);
    }
}

void ZUKAN_LIST_TransferSpeciesGraphics(char *p, int index, unsigned species, u16 form, u16 half, int mode)
{
    void *owner;
    void *data;
    struct Out *out;
    struct Obj **slot;
    unsigned saved;
    owner=func_020490F4(7,0x806b);
    saved=half;
    data=func_02049E74((void *)((unsigned)owner),POKE_TOOL_CalcGraphicIndex(species,form,saved,0),0,(unsigned)&out,0x806b);
    if (mode==1) {
        slot=(struct Obj **)(p+0xa74+index*4);
        CLACT_TransferCharacterPart(CLACT_GetActorCharacterIndex((u8 *)*slot),out->f14,1024,0,0);
    } else {
        slot=(struct Obj **)(p+0xa74+index*4);
        CLACT_TransferCharacterPart(CLACT_GetActorCharacterIndex((u8 *)*slot),out->f14,1024,0,1);
    }
    func_020307B0(data);
    ARC_TOOL_DeleteHandle(owner);
    CLACT_SetActorPaletteOffset(*slot,POKE_TOOL_CalcIconPalette(species,form,saved,0),1);
}

int ZUKAN_LIST_IsActorHidden(int p, int t)
{
    unsigned int i;

    if (t == 1) {
        for (i = 0xa; i < 0x1a; i++) {
            if (ZUKAN_LIST_GetActorVisible((char *)p, i) == 0) {
                return i;
            }
        }
    } else {
        for (i = 0x1a; i < 0x2a; i++) {
            if (ZUKAN_LIST_GetActorVisible((char *)p, i) == 0) {
                return i;
            }
        }
    }
    return 0;
}

/*
 * Enum position preserves the full-width update and repeated signed-halfword argument conversions.
 */
void ZUKAN_LIST_ShowSpeciesActor(char *p,u16 species,enum Position pos,int mode)
{
    unsigned out1,outForm,out2;
    int index;
    ZUKAN_SAVE_GetViewGenderAndForm(*(u8 * *)&((struct Obj25579 *)(*(char * *)&((struct Obj25578 *)p)->f0))->f4,species,&out1,&out2,&outForm,0x806b);
    index=ZUKAN_LIST_IsActorHidden((int)p,mode);
    ZUKAN_LIST_TransferSpeciesGraphics(p,index,species,outForm,out1,mode);
    ZUKAN_LIST_SetActorVisible(p,index,1);
    ZUKAN_LIST_StartActorAnim(p,index,0);
    if (mode==1) {
        pos+=8;
        ZUKAN_LIST_AddActorPos(p,index,112,pos,0);
        return;
    }
    pos+=8;
    ZUKAN_LIST_AddActorPos(p,index,112,pos,1);
    ZUKAN_LIST_AddActorPos(p,index+16,112,pos,1);
    index+=16;
    ZUKAN_LIST_SetActorVisible(p,index,1);
}

void ZUKAN_LIST_ScrollActorsBy(char *p, int delta)
{
    unsigned i;
    short pos[2];
    for (i = 10; i < 26; i++) {
        if (ZUKAN_LIST_GetActorVisible((char *)p, i) != 0) {
            ZUKAN_LIST_GetActorPos(p, i, &pos[1], &pos[0], 0);
            ZUKAN_LIST_AddActorPos(p, (unsigned)i, (short)pos[1], (short)(pos[0] + delta), 0);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200)
                ZUKAN_LIST_SetActorVisible(p, i, 0);
        }
    }
    for (i = 26; i < 42; i++) {
        if (ZUKAN_LIST_GetActorVisible((char *)p, i) != 0) {
            ZUKAN_LIST_GetActorPos(p, i, &pos[1], &pos[0], 1);
            ZUKAN_LIST_AddActorPos(p, (unsigned)i, (short)pos[1], (short)(pos[0] + delta), 1);
            ZUKAN_LIST_AddActorPos(p, (unsigned)(i + 16), (short)pos[1], (short)(pos[0] + delta), 1);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200) {
                ZUKAN_LIST_SetActorVisible(p, i, 0);
                ZUKAN_LIST_SetActorVisible(p, i + 16, 0);
            }
        }
    }
}

void ZUKAN_LIST_HideAllActors(char *p)
{
    unsigned i;
    ((struct Obj08411 *)p)->fC28=0;
    ((struct Obj08411 *)p)->fC2A=0;
    for(i=10;i<26;i++)if(ZUKAN_LIST_GetActorVisible((char *)((int)p),i))((struct Obj08411 *)p)->fC28|=(u16)(1<<(i-10));
    for(i=26;i<42;i++)if(ZUKAN_LIST_GetActorVisible((char *)((int)p),i))((struct Obj08411 *)p)->fC2A|=(u16)(1<<(i-26));
}

void ZUKAN_LIST_ShowAllActors(char *p)
{
    unsigned i;
    for(i=10;i<26;i++)if(((struct Obj08412 *)p)->fC28&(1<<(i-10)))ZUKAN_LIST_SetActorVisible(p,i,0);
    for(i=26;i<42;i++)if(((struct Obj08412 *)p)->fC2A&(1<<(i-26))){ZUKAN_LIST_SetActorVisible(p,i,0);ZUKAN_LIST_SetActorVisible(p,i+16,0);}
    ((struct Obj08412 *)p)->fC28=0;
    ((struct Obj08412 *)p)->fC2A=0;
}

/*
 * Row expression assigned back to index keeps the entry register; 021BE586 is two zero alignment bytes.
 */
void ZUKAN_LIST_MoveCursorActor(char *p,int index)
{
    unsigned i;
    short pos[2];
    index=index*24+8;
    for(i=10;i<26;i++){
        if(ZUKAN_LIST_GetActorVisible((char *)p,i)==0)ZUKAN_LIST_StartActorAnim(p,i,0);
        else{
            ZUKAN_LIST_GetActorPos(p,i,&pos[1],&pos[0],0);
            if(index==pos[0]){if(ZUKAN_LIST_GetActorAnimSeq(p,i)!=1)ZUKAN_LIST_StartActorAnim(p,i,1);}
            else ZUKAN_LIST_StartActorAnim(p,i,0);
        }
    }
}

void ZUKAN_LIST_UpdateScrollBarActor(char *p)
{
    short pos[2];
    unsigned value;
    ZUKAN_LIST_GetActorPos(p,0,&pos[1],&pos[0],0);
    value=FRAME_LIST_ClampToScrollBar(*(struct S * *)&((struct Obj00088 *)p)->fC2C,pos[0]);
    if(value<12)value=12;else if(value>156)value=156;
    ZUKAN_LIST_AddActorPos(p,0,(short)252,(short)value,0);
}

void ZUKAN_LIST_UpdateArrowActors(char *p,int flag)
{
    int n=FRAME_LIST_GetCursor(*(char * *)&((struct Obj00088 *)p)->fC2C);
    if (ZUKAN_LIST_GetActorAnimSeq(p,7)!=12 || flag==0) {
        if (FRAME_LIST_GetScrollPos(*(char * *)&((struct Obj00088 *)p)->fC2C)==0 && n==0)
            ZUKAN_LIST_StartActorAnim(p,7,18);
        else ZUKAN_LIST_StartActorAnim(p,7,4);
    }
    if (ZUKAN_LIST_GetActorAnimSeq(p,6)!=13 || flag==0) {
        if (FRAME_LIST_CanScrollDown(*(char * *)&((struct Obj00088 *)p)->fC2C)==0 && n==((struct Obj00088 *)p)->fC34-1) {
            ZUKAN_LIST_StartActorAnim(p,6,19);
            return;
        }
        else ZUKAN_LIST_StartActorAnim(p,6,5);
    }
}

extern int TOUCHPANEL_HitTrg(const void *p);

extern u32 KEY_GetTrg(void);

extern void FRAME_LIST_HideCursor(u32);

extern int func_021B940C(u8 *p);

int ZUKAN_LIST_HandleTouchInput(void *ctx_)
{
    u8 *ctx = (u8 *)ctx_;
    int v = TOUCHPANEL_HitTrg((void *)0x021BEAE0);

    if (v != -1) {
        if (v == 8) {
            if (ZUKAN_SAVE_GetDexObtained((struct Blk37 *)(*(u32 *)(*(u32 *)ctx + 4))) == 0)
                return -1;
        }
        if (v == 9) {
            if (ZUKAN_SAVE_IsNationalDexEnabled((struct Blk37 *)(*(u32 *)(*(u32 *)ctx + 4))) == 0)
                return -1;
            if (*(u16 *)(*(u32 *)ctx + 8) == 1)
                return -1;
        }
        if (v == 0xa) {
            if (*(u16 *)(*(u32 *)ctx + 8) == 1)
                return -1;
            if (func_020355C4() == 0) {
                func_020355D8(1);
                FRAME_LIST_HideCursor(*(u32 *)(ctx + 0xC2C));
            }
        }
        func_020355D8(1);
        return v;
    } else {
        if (KEY_GetTrg() & 2) {
            func_020355D8(0);
            return 0xc;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 0xb;
        }
        if (KEY_GetTrg() & 8) {
            if (ZUKAN_SAVE_GetDexObtained((struct Blk37 *)(*(u32 *)(*(u32 *)ctx + 4))) == 1) {
                func_020355D8(0);
                return 8;
            }
        }
        if (KEY_GetTrg() & 4) {
            if (ZUKAN_SAVE_IsNationalDexEnabled((struct Blk37 *)(*(u32 *)(*(u32 *)ctx + 4))) == 0)
                return -1;
            if (*(u16 *)(*(u32 *)ctx + 8) == 1)
                return -1;
            func_020355D8(0);
            return 9;
        }
        if (KEY_GetTrg() & 0x800) {
            if (*(u16 *)(*(u32 *)ctx + 8) == 1)
                return -1;
            if (func_020355C4() == 1) {
                func_020355D8(0);
                func_021B940C((u8 *)(*(u32 *)(ctx + 0xC2C)));
            } else {
                func_020355D8(0);
            }
            return 0xa;
        }
        return v;
    }
}
