/*
 * file:     beacon_detail_gra.c
 * unit:     yes
 * function: BEACON_DETAIL_GRA_Init, BEACON_DETAIL_GRA_Exit, BEACON_DETAIL_GRA_Main, func_021BBF14, func_021BBF28, func_021BBF60, func_021BBF98, func_021BBFEC, BEACON_DETAIL_GRA_Delete, func_021BC0C8, func_021BC178, func_021BC1E4, func_021BC378, func_021BC398, func_021BC3D4, func_021BC3DC, func_021BC3E4, func_021BC43C, func_021BC454, func_021BC56C, func_021BC5C4, func_021BC614, func_021BC650, func_021BC6B4, func_021BC6D8, func_021BC6FC, func_021BC70C, func_021BC8A8, func_021BC920, BEACON_DETAIL_GRA_Create, func_021BC9D0, func_021BCA24, func_021BCA38, BEACON_DETAIL_GRA_Task, func_021BCA58, func_021BCAB8, func_021BCAF0, func_021BCAF4, func_021BCAFC, func_021BCB70, func_021BCB90, func_021BCB98, func_021BCBA4, func_021BCC10, func_021BCCBC, func_021BCCC4, func_021BCD00, func_021BCD08, func_021BCD60, func_021BCDC0, func_021BCDDC, func_021BCE04, func_021BCE7C, func_021BCE8C, func_021BCEA4, func_021BCED0, func_021BCF08, func_021BD07C, func_021BD0E4, func_021BD13C, func_021BD174, func_021BD448, func_021BD668, BEACON_DETAIL_GRA_Callback, func_021BD6F0, func_021BD6FC, func_021BD73C, func_021BD768, func_021BD7D4, func_021BD854, func_021BD89C, func_021BD8A8, func_021BD948, func_021BDA54, func_021BDAA0, BEACON_DETAIL_GRA_PrintWaitTask
 * address:  0x021BBD80
 * region:   ov216
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ov067_id 0x00000043 data
 *   ov072_id 0x00000048 data
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   GAME_BEACON_ACCESSOR_AllocInfo 0x02165B10 thumb ov010
 *   GAME_DATA_GetItemUseWork 0x02012A54 thumb
 *   BEACON_STATUS_GetLog 0x020275A8 thumb
 *   GAME_BEACON_ACCESSOR_TableGetCount 0x02165B04 thumb ov010
 *   GAME_BEACON_ACCESSOR_TableRingGet 0x02165AC4 thumb ov010
 *   GAME_BEACON_ACCESSOR_IsInfoInvalid 0x02165B5C thumb ov010
 *   GAME_BEACON_ACCESSOR_IsDistributionAction 0x02165C10 thumb ov010
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   TOWNMAP_GRH_LoadTownInfo 0x021BBB24 thumb ov072
 *   TOWNMAP_GRH_FreeTownInfo  0x021BBB34  thumb  ov072
 *   func_020307B0  0x020307B0  arm
 *   TCBL_Create 0x0203101C arm
 *   func_020490F4 0x020490F4 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_Create 0x0201EC74 thumb
 *   func_02045B38 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   func_0207D63C 0x0207D63C arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   d_021BDB4C 0x021BDB4C data a4
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   configA 0x021BDB28 data a2
 *   configB 0x021BDB34 data a2
 *   POKEGRA_OpenTrainerHandle 0x0202DA04 thumb
 *   NNS_G2dGetUnpackedCharacterData 0x02062A00 arm
 *   POKEGRA_RegisterTrainerCgr 0x0202DA48 thumb
 *   POKEGRA_RegisterTrainerPalette 0x0202DA18 thumb
 *   POKEGRA_RegisterTrainerCellAnim 0x0202DA6C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   PMS_DRAW_Create 0x0202DB0C thumb
 *   PMS_DRAW_SetNullColorPalette 0x0202DE5C thumb
 *   PMS_DRAW_SetPrintColor 0x0202DE64 thumb
 *   PMS_DRAW_SetFollowBgScroll 0x0202DE68 thumb
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   sub_0202DBC4  0x0202DBC4  thumb
 *   func_02030734 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   d_021BDDC0 0x021BDDC0 data a1
 *   d_021BDBD8 0x021BDBD8 data a4
 *   func_02030EAC 0x02030EAC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BDBAC 0x021BDBAC data a4
 *   d_021BDC28 0x021BDC28 data a4
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetRendererCulling 0x0204B0F4 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021BDBBC 0x021BDBBC data a4
 *   d_021BDC08 0x021BDC08 data a4
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8   0x02082BCC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   ICA_ANIME_GetUnk330 0x02012204 thumb
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   GAME_BEACON_ACCESSOR_GetPmVersion  0x02165C48  thumb  ov010
 *   d_021BDDA2 0x021BDDA2 data a1
 *   GAME_BEACON_ACCESSOR_GetDetailsType 0x02165DAC thumb ov010
 *   GAME_BEACON_ACCESSOR_GetDetailsMonsNo 0x02165DF0 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetDetailsTrainerNo 0x02165DBC thumb ov010
 *   GAME_BEACON_ACCESSOR_GetZoneId 0x02165D28 thumb ov010
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   func_02045CAC 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   d_021BDD92 0x021BDD92 data a1
 *   d_021BDD8A 0x021BDD8A data a2
 *   BMP_FillRect 0x02043AF4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   sub_0202DCC4 0x0202DCC4 thumb
 *   PMS_DRAW_SetVisible 0x0202DCB0 thumb
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   func_02040618 0x02040618 arm
 *   GAME_BEACON_ACCESSOR_GetFavoriteColorRgb 0x02165CC0 thumb ov010
 *   PALANM_BlendColors 0x02021F64 thumb
 *   GAME_BEACON_ACCESSOR_GetPlayerName 0x02165C34 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond 0x02165C60 thumb ov010
 *   STRBUF_Clear 0x0204581C arm
 *   WORDSET_SetSlotFromMsg38 0x0201F1C8 thumb
 *   GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst 0x02165C78 thumb ov010
 *   WORDSET_SetSlotFromMsg2B 0x0201F198 thumb
 *   GAME_BEACON_ACCESSOR_GetPlayTime 0x02165D10 thumb ov010
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   GAME_BEACON_ACCESSOR_GetNation 0x02165C58 thumb ov010
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   GAME_BEACON_ACCESSOR_GetArea 0x02165C5C thumb ov010
 *   WORDSET_DeleteMsgdataF094 0x0201F094 thumb
 *   GAME_BEACON_ACCESSOR_GetPassCount 0x02165D40 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetThanksCount 0x02165D48 thumb ov010
 *   PMS_DRAW_IsActive 0x0202DCC4 thumb
 *   PMS_DRAW_Clear 0x0202DC9C thumb
 *   GAME_BEACON_ACCESSOR_GetDetailsPms 0x02165C90 thumb ov010
 *   PMS_DRAW_Print 0x0202DC48 thumb
 *   GAME_BEACON_ACCESSOR_GetTrainerAppearance 0x02165CE8 thumb ov010
 *   CURSOR_MOVE_GetTableGroup 0x02025C88 thumb
 *   POKEGRA_LoadTrainerGraphics 0x0202DAA4 thumb
 *   GAME_BEACON_ACCESSOR_GetResearchTeamRank 0x02165CB4 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetTownmapRootZoneId 0x02165D34 thumb ov010
 *   TOWNMAP_GRH_FindRecordIndex 0x021BBB48 thumb ov072
 *   TOWNMAP_GRH_GetTownInfoValue 0x021BBB3C thumb ov072
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   TCBL_DeleteTask 0x02031194 arm
 *   TOUCHBAR_SetAllButtonsEnabled 0x021B64A8 thumb ov067
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TCBL_DeleteTask 0x02031194 arm
 *   d_021BDD88 0x021BDD88 data a1
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   BEACON_DETAIL_GRA_PrintWaitTask 0x021BDAD8 thumb ov216
 *   PMS_DRAW_Delete  0x0202DC08  thumb  arm9
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb  arm9
 *   WORDSET_Callback  0x0201EE60  thumb  arm9
 *   WORDSET_SetSlotPokeData  0x0201F104  thumb  arm9
 *   WORDSET_SetSlotFromMsgBE  0x0201F134  thumb  arm9
 *   WORDSET_SetSlotFromMsg59  0x0201F158  thumb  arm9
 */
#include "../../matched/include/Obj00366.h"
#include "../../matched/include/Obj01437.h"
#include "../../matched/include/Obj03374.h"
#include "../../matched/include/Obj25767.h"
#include "../../matched/include/Obj10942.h"
#include "../../matched/include/Obj05552.h"
#include "../../matched/include/Obj25768.h"
#include "../../matched/include/Obj14715.h"
#include "../../matched/include/Obj01591.h"
#include "../../matched/include/Obj25769.h"
#include "../../matched/include/Obj25770.h"
#include "../../matched/include/Obj10945.h"
#include "../../matched/include/Obj01783.h"
#include "../../matched/include/Obj10946.h"
#include "../../matched/include/Obj25771.h"
#include "../../matched/include/Obj14716.h"
#include "../../matched/include/Obj05553.h"
#include "../../matched/include/Obj14717.h"
#include "../../matched/include/Obj00051.h"
#include "../../matched/include/Obj05554.h"
#include "../../matched/include/Obj14718.h"
#include "../../matched/include/Obj14719.h"
#include "../../matched/include/Obj08428.h"
#include "../../matched/include/Obj10948.h"
#include "../../matched/include/Obj05555.h"
#include "../../matched/include/Obj03943.h"
#include "../../matched/include/Obj25779.h"
#include "../../matched/include/Obj04637.h"
#include "../../matched/include/Obj10949.h"
#include "../../matched/include/Obj14720.h"
#include "../../matched/include/Obj10950.h"
#include "../../matched/include/Obj03375.h"
#include "../../matched/include/Obj02553.h"
#include "../../matched/include/Obj02927.h"
#include "../../matched/include/Obj05556.h"
#include "../../matched/include/Obj00690.h"
#include "../../matched/include/Obj25787.h"
#include "../../matched/include/Obj25788.h"
#include "../../matched/include/Obj25789.h"
#include "../../matched/include/Obj25790.h"
#include "../../matched/include/Obj25791.h"
#include "../../matched/include/Obj25792.h"
#include "../../matched/include/Obj25793.h"
#include "../../matched/include/Obj25794.h"
#include "../../matched/include/Obj25795.h"
#include "../../matched/include/Obj08427.h"
#include "../../matched/include/Obj14721.h"
#include "../../matched/include/Obj25797.h"
#include "../../matched/include/Obj06711.h"
#include "../../matched/include/Obj25799.h"

#define REC1(w, j, i) ((struct Rec *)((char *)(w) + (j) * 0x80 + (i) * 16))
#define HANDLE(p, k) (*(int *)((p) + (k)))
#define ARG(p, k) (*(int *)((p) + (k) + 0xC))
#define CALLS(r) do { void *d = (r)->d; BMP_WIN_TransferChars(d); BMP_WIN_MakeScreen(d); func_020409B4(BMP_WIN_GetBgLayer(d)); } while (0)
struct Obj0203159C;
struct S021BC6B4;
struct S020315D4;
struct Tcbl;
struct PrintSys;
struct Queue;
struct Rec;
struct BigObj;
struct GfFont;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct S02031140;
struct ArcFile;
struct NitroFileHeader;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Obj;
struct PmsDraw;
struct Actor;
struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Ctx;
struct Bits;
struct Vec2;
struct Sub0204A9D0;
struct Bmp;
struct Obj0202DCC4;
struct Obj0202DC98;
struct S;
struct R;
struct TcblNode;
struct S02030FB4;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {unsigned char *f0;unsigned f4;int f8;unsigned fC,f10,f14;int f18,f1c;} A;

typedef struct R R;

typedef struct S S;

typedef struct { unsigned char a,b,c,pad; unsigned short first,second,third; } Config_021BBD80;

typedef signed int     s32;

typedef struct {unsigned char a,b,c,pad;u16 first,second,third;} Config_021BC454;

typedef struct { struct Descriptor *window; struct CharBuf *buffer; struct Descriptor *copy; unsigned char state; } Window_021BBD80;

typedef struct {short x,y,z;unsigned char a,b;} Position;

struct S021BC6B4
{
    char pad[0x264];
    void *slots[2];
};

typedef struct {struct Descriptor *window;struct CharBuf *buffer;struct Descriptor *copy;unsigned char state;} Window_021BC6D8;

struct Entry { unsigned id; char fields[32]; unsigned a,b; };

struct Block { unsigned w[8]; };

struct Object { unsigned char bytes[0x124]; void *menu; };

struct Four_021BCF08 { unsigned short a; unsigned char b, c; };

struct Rec { void *d; int h; int u, v; };

struct Rec32 { void *d; int h; char pad[24]; };

struct Win { struct Rec a[4]; struct Rec32 b; struct Rec32 c; };

struct Four_021BD07C { unsigned short a; unsigned char b,c; };

enum Index { IndexZero=0 };

struct Pair { u16 a,b; };

struct Quad { u16 a,b,c,d; };

struct Rgb555 { u16 r:5,g:5,b:5,pad:1; };

typedef signed short s16;

typedef signed char s8;

typedef void (*TcblFunc)(struct TcblNode *,void *);

typedef struct Work{int arg;u8 *owner;int *counter;} Work;

extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *,int,int);
extern void func_020315D4(struct S020315D4 *);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void func_02034A5C(int);
extern void TCBL_Main(struct Tcbl *);
extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);
extern unsigned PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void FADE_Start(unsigned,int,int,int);
extern int FADE_IsActive(void);
extern int TOUCHBAR_GetPressedButtonIdIfDone(unsigned char *);
extern u8 *GAME_BEACON_ACCESSOR_AllocInfo(u32);
extern u32 GAME_DATA_GetItemUseWork(const struct BigObj *);
extern u32 BEACON_STATUS_GetLog(u32 a);
extern u8 GAME_BEACON_ACCESSOR_TableGetCount(u8 *);
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *,struct Rec *,u16 *,int);
extern int GAME_BEACON_ACCESSOR_IsInfoInvalid(struct Rec *);
extern int GAME_BEACON_ACCESSOR_IsDistributionAction(u8 *);
extern signed char MSG_SPEED_GetWait(void);
extern int TOWNMAP_GRH_LoadTownInfo(int);
extern void TOWNMAP_GRH_FreeTownInfo(void *p);
extern u32 func_020307B0(void *p);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, unsigned int count, unsigned int workSize);
extern void *func_020490F4(u32 id, u32 heap);
extern void GF_FONT_SetTextColor(unsigned,unsigned,unsigned);
extern void *PRINTSYS_QUE_CreateEx(unsigned short,unsigned);
extern struct GfFont *GF_FONT_Create(int,int,int,int,unsigned);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct MsgBank *func_02045B38(unsigned,unsigned,unsigned,unsigned);
extern struct U16Vec *STRBUF_Create(unsigned,unsigned);
extern void STRBUF_Delete(struct U16Vec *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void TCBL_Destroy(struct S02031140 *);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *,u32,u32);
extern int NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *,void **);
extern void func_0207D63C(u32 *,u32,u32,int,int);
extern R *TOUCHBAR_Create(A *,int);
extern void TOUCHBAR_Delete(unsigned char *);
extern void TOUCHBAR_Update(struct S *p);
extern signed int CLACT_RegisterPaletteEx(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned short e, unsigned short f, unsigned short g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern int POKEGRA_OpenTrainerHandle(int a0);
extern int NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *,void **);
extern u32 POKEGRA_RegisterTrainerCgr(u32,u32,u32,u32);
extern s32 POKEGRA_RegisterTrainerPalette(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int POKEGRA_RegisterTrainerCellAnim(int a0, int a1, int a2, unsigned short a3);
extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *,unsigned char);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern unsigned char BMP_WIN_GetBgLayer(struct Descriptor *);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern struct PmsDraw *PMS_DRAW_Create(u32,u32,u32,u32,u8,u8,u16);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *,u8);
extern void PMS_DRAW_SetPrintColor(struct PmsDraw *,u16);
extern void PMS_DRAW_SetFollowBgScroll(struct PmsDraw *,u32);
extern void CLACT_SetActorObjMode(struct Actor *,u32);
extern void PMS_DRAW_Delete(struct Obj *p);
extern int sub_0202DBC4(u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BMP_SetDisplaySwap(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void *func_020056A0(void (*)(void *,void *),void *,int);
extern void func_02030EAC(struct Node *n);
extern void BG_SYS_Create(int);
extern void BMP_WIN_Init(int);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8,u8);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
extern void CLACT_SetRendererCulling(struct Actor *a0, int a1);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void CLACT_DeleteRenderer(void *);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(unsigned char *);
extern u32 KEY_GetTrg(void);
extern unsigned ICA_ANIME_GetUnk330(const struct Ctx *);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void DWCi_ScreenDC_FlushRange(void *,unsigned);
extern void GX_LoadBGPltt(void *,unsigned,unsigned);
extern void func_0207E468(void *,unsigned,unsigned);
extern void GX_LoadOBJPltt(void *,unsigned,unsigned);
extern void func_0207E5D0(void *,unsigned,unsigned);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern unsigned int GAME_BEACON_ACCESSOR_GetPmVersion(void *a0);
extern unsigned GAME_BEACON_ACCESSOR_GetDetailsType(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetDetailsMonsNo(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetZoneId(const struct Bits *);
extern u32 ZONEDATA_GetPlaceNameId(u32 id);
extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);
extern void WORDSET_SetSlotPokeData(struct WordSet *p, u32 i, u32 a);
extern void WORDSET_SetSlotFromMsgBE(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsg59(struct WordSet *p, u32 i, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_02045CAC(struct MsgBank*,u32,void*);
extern void WORDSET_CopyTaggedText(struct WordSet*,void*,void*);
extern void CLACT_TransferCharacter(int,struct Sub0204A9D0*);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u32 sub_0202DCC4(const struct Obj0202DCC4 *, u32);
extern void PMS_DRAW_SetVisible(struct Obj0202DC98 *, int, u32);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void func_02040618(u32,u32,u32);
extern void GAME_BEACON_ACCESSOR_GetFavoriteColorRgb(int a0, int a1);
extern void PALANM_BlendColors(u16 *,u16 *,u32,int,u16);
extern void GAME_BEACON_ACCESSOR_GetPlayerName(struct Rec *,void *);
extern int GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond(int a0);
extern void STRBUF_Clear(struct U16Vec *);
extern void WORDSET_SetSlotFromMsg38(struct WordSet *,u32,u32);
extern int GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst(int a0);
extern void WORDSET_SetSlotFromMsg2B(struct WordSet *,u32,u32);
extern void GAME_BEACON_ACCESSOR_GetPlayTime(const struct S *p, u16 *a, u16 *b);
extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);
extern u8 GAME_BEACON_ACCESSOR_GetNation(const u8 *p);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *,u32,u32);
extern u8 GAME_BEACON_ACCESSOR_GetArea(const u8 *p);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *,u32,u32,u32);
extern u32 GAME_BEACON_ACCESSOR_GetPassCount(const struct S *p);
extern u32 GAME_BEACON_ACCESSOR_GetThanksCount(const struct S *p);
extern u32 PMS_DRAW_IsActive(const struct Obj0202DCC4 *,u32);
extern void PMS_DRAW_Clear(struct Obj0202DC98 *,int,u32);
extern void GAME_BEACON_ACCESSOR_GetDetailsPms(const struct R *p, struct Quad *q);
extern void PMS_DRAW_Print(u32,u32,u32,u32);
extern u8 GAME_BEACON_ACCESSOR_GetTrainerAppearance(struct S *);
extern u32 CURSOR_MOVE_GetTableGroup(u32);
extern void POKEGRA_LoadTrainerGraphics(void *set, u32 id, void *dstA, void *dstB, volatile u16 which);
extern u8 GAME_BEACON_ACCESSOR_GetResearchTeamRank(void *);
extern unsigned short GAME_BEACON_ACCESSOR_GetTownmapRootZoneId(const struct Bits *p);
extern int TOWNMAP_GRH_FindRecordIndex(int,int);
extern u16 TOWNMAP_GRH_GetTownInfoValue(char *,int,int);
extern struct TcblNode *TCBL_AddTask(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void TCBL_DeleteTask(struct TcblNode*);
extern void TOUCHBAR_SetAllButtonsEnabled(u8 *, u32);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern void BEACON_DETAIL_GRA_PrintWaitTask(int,int **);
int BEACON_DETAIL_GRA_Init(struct Obj0203159C *obj,int unused1,void *config);
int BEACON_DETAIL_GRA_Exit(struct S020315D4 *heap,int unused1,int unused2,char *p);
int BEACON_DETAIL_GRA_Main(int unused0,int *state,int unused2,char *p);
int func_021BBF0C(char *p);
int func_021BBF14(char *p);
int func_021BBF28(unsigned char *p);
int func_021BBF60(char *p);
int func_021BBF98(char *p);
void func_021BBFEC(u8 *p);
void BEACON_DETAIL_GRA_Delete(char *p);
void func_021BC0C8(char *p);
void func_021BC178(char *p);
void func_021BC1E4(char *p,u16 heap);
void func_021BC378(char *p);
R *func_021BC398(int manager,int heap);
void func_021BC3D4(unsigned char *p);
void func_021BC3DC(S *p);
void func_021BC3E4(unsigned short *p,int *out,const Config_021BBD80 *cfg,void *handle);
void func_021BC43C(void *unused, char *p);
void func_021BC454(char *p,u32 handle);
void func_021BC56C(char *p);
void func_021BC5C4(Window_021BBD80 *p,unsigned char layer,unsigned char palette,unsigned x,unsigned char y,unsigned char width,unsigned char height);
unsigned func_021BC614(unsigned short *p,void *manager,unsigned *r,short x,short y,unsigned char z,unsigned char a,unsigned char b,unsigned short flag);
void func_021BC650(char *p);
void func_021BC6B4(struct S021BC6B4 *p);
void func_021BC6D8(char *p);
u32 func_021BC6FC(u32 *p);
void func_021BC70C(char *p);
void func_021BC8A8(char *p);
int func_021BC920(u32 *p);
void *BEACON_DETAIL_GRA_Create(int a,int heap);
void func_021BC9D0(unsigned *p);
void func_021BCA24(char *p);
void *func_021BCA38(char *p);
void BEACON_DETAIL_GRA_Task(void *unused, char *p);
void func_021BCA58(void *p,int heap);
void func_021BCAB8(void *p);
void func_021BCAF0(void *p);
void func_021BCAF4(void *a0);
void func_021BCAFC(void **p,void *a,int heap);
void func_021BCB70(char *p);
void func_021BCB90(void *a0);
void func_021BCB98(void *a0);
u32 func_021BCBA0(u32*p);
void func_021BCBA4(unsigned char *p);
int func_021BCC10(unsigned char *p);
void func_021BCCBC(u8*p);
int func_021BCCC4(u8*p);
void func_021BCD00(int a);
void func_021BCD08(void *p,unsigned mode,unsigned a,unsigned b);
void func_021BCD60(unsigned char *p);
int func_021BCDC0(void *a0);
const u8*func_021BCDDC(u32 n);
void func_021BCE04(void *p,void *q);
void func_021BCE7C(void *p, unsigned short value);
void func_021BCE8C(void *a0, short a1, short a2, int a3);
void func_021BCEA4(u8*p, u8 n);
void func_021BCED0(u8*p,u32 n);
void func_021BCF08(char *p);
void func_021BD07C(void *p,void **q,int v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e);
void func_021BD0E4(char *p, u8 index, u32 enable);
void func_021BD13C(u8*p,int a);
void func_021BD174(char *p,void *record,u16 unused,u8 slot);
void func_021BD448(char *p);
void func_021BD668(char *owner, int direction, int *counter);
void BEACON_DETAIL_GRA_Callback(struct TcblNode*task,u8*p);
void func_021BD6F0(char*p);
void func_021BD6FC(char *owner, int *counter);
int func_021BD73C(char *p);
void func_021BD768(struct TcblNode *task, void *data);
void func_021BD7D4(char *owner, u8 index, int position, u8 direction, int *counter);
void func_021BD854(struct TcblNode *task, char *p);
void func_021BD89C(char*p,int a);
void func_021BD8A8(char *owner, int direction, int *counter);
void func_021BD948(struct TcblNode *task,char *work);
void func_021BDA54(char *owner, char *record, u32 b, u16 c, u32 d, u16 f);
void func_021BDAA0(u8 *p,int arg,int *counter);
extern unsigned char ov067_id[],ov072_id[];
extern unsigned char ov072_id[],ov067_id[];
extern const unsigned char d_021BDB4C[];
extern const Config_021BC454 configA,configB;
extern char d_021BDDC0[];
extern unsigned d_021BDBD8[];
extern const unsigned d_021BDBAC[];
extern const struct Entry d_021BDC28[];
extern const unsigned d_021BDBBC[];
extern const struct Block d_021BDC08;
extern const u8 d_021BDDA2[];
extern const u8 d_021BDD92[];
extern const struct Four_021BCF08 d_021BDD8A[];
extern const u8 d_021BDD88[];






int BEACON_DETAIL_GRA_Init(struct Obj0203159C *obj,int unused1,void *config)
{
    char *p;
    func_02034AC4((int)ov067_id);
    func_02034AC4((int)ov072_id);
    GFL_HEAP_CreateChildHeap(1,119,3<<16);
    p=PROCSYS_AllocProcWork(obj,620,119);
    MI_CpuFill8(p,0,620);
    ((struct Obj00366 *)p)->f14=config;
    ((struct Obj00366 *)p)->f0=119;
    ((struct Obj00366 *)p)->f2=0x8077;
    ((struct Obj00366 *)p)->f50=BEACON_DETAIL_GRA_Create(0,((struct Obj00366 *)p)->f0);
    func_021BBFEC((u8 *)p);
    func_021BC0C8(p);
    func_021BC1E4(p,((struct Obj00366 *)p)->f0);
    func_021BC6D8(p);
    func_021BC454(p,(u32)(((struct Obj00366 *)p)->f54));
    func_021BC650(p);
    func_021BC70C(p);
    ((struct Obj00366 *)p)->f124=(void *)func_021BC398((int)(func_021BCA38(((struct Obj00366 *)p)->f50)), ((struct Obj00366 *)p)->f0);
    return 1;
}






int BEACON_DETAIL_GRA_Exit(struct S020315D4 *heap,int unused1,int unused2,char *p)
{
    func_021BC3D4(((struct Obj01437 *)p)->f124);
    func_021BC8A8(p);
    func_021BC6B4((struct S021BC6B4 *)p);
    func_021BC56C(p);
    func_021BC6FC((unsigned *)p);
    func_021BC378(p);
    func_021BC178(p);
    BEACON_DETAIL_GRA_Delete(p);
    func_021BC9D0(*(unsigned * *)&((struct Obj01437 *)p)->f50);
    func_020315D4(heap);
    GFL_HEAP_DeleteChecked(119);
    func_02034A5C((int)ov072_id);
    func_02034A5C((int)ov067_id);
    return 1;
}






int BEACON_DETAIL_GRA_Main(int unused0,int *state,int unused2,char *p)
{
    if (((struct Obj03374 *)p)->f10) return 1;
    if (*state>=2 && *state<=3) func_021BC3DC((S *)(((struct Obj03374 *)p)->f124));
    switch (*state) {
    case 0: *state=func_021BBF28((unsigned char *)p); break;
    case 1: *state=func_021BBF60(p); break;
    case 2: *state=func_021BBF0C(p); break;
    case 3: *state=func_021BBF14(p); break;
    case 4: *state=func_021BBF98(p); break;
    case 5: return 1;
    }
    TCBL_Main(*(struct Tcbl * *)&((struct Obj03374 *)p)->f18);
    PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj03374 *)p)->f12C);
    func_021BC920((unsigned *)p);
    func_021BCA24(*(char * *)&((struct Obj03374 *)p)->f50);
    return 0;
}






/*
 * follower: 021BBF0C pool-and-bx thunk forwarding to 021BCC10.
 */
int func_021BBF0C(char *p)
{
    return func_021BCC10((unsigned char *)p);
}







/*
 * Addresses are Black-image addresses.
 */
int func_021BBF14(char *p)
{
    if (((struct Obj25767 *)p)->fC != 0)
        return 3;
    func_021BCCBC((u8 *)p);
    return 2;
}






int func_021BBF28(unsigned char *p){switch(((struct Obj03374 *)p)->f4){case 0:func_021BCBA4(p);(((struct Obj03374 *)p)->f4)++;break;case 1:if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj03374 *)p)->f12C)){((struct Obj03374 *)p)->f4=0;return 1;}break;}return 0;}






int func_021BBF60(char *p){switch(((struct Obj10942 *)p)->f4){case 0:FADE_Start(3,16,0,0);(((struct Obj10942 *)p)->f4)++;break;case 1:if(FADE_IsActive()==0){((struct Obj10942 *)p)->f4=0;return 2;}break;}return 1;}






int func_021BBF98(char *p)
{
    switch (((struct Obj05552 *)p)->f4) {
    case 0:
        if (((struct Obj25768 *)(*(char * *)&((struct Obj05552 *)p)->f14))->f9==0) {
            func_021BC3DC((S *)(((struct Obj05552 *)p)->f124));
            if (TOUCHBAR_GetPressedButtonIdIfDone(*(unsigned char * *)&((struct Obj05552 *)p)->f124)!=1) break;
        }
        FADE_Start(3,0,16,0);
        (((struct Obj05552 *)p)->f4)++;
        break;
    case 1:
        if (FADE_IsActive()==0) {
            ((struct Obj05552 *)p)->f4=0;
            return 5;
        }
        break;
    }
    return 4;
}






/*
 * Verified EXACT Thumb C copied from parked ov032_func_021F27D4 header:
 * u32 BEACON_STATUS_GetLog(u32 a) { return a; }
 * Singleton TU --suggest-split leaves caller out; no viable partition.
 * Trailing 021BC0B2..021BC0B4 is zero alignment padding.
 * lever: array index uses p[47]++ so byte count advances before the store.
 */
void func_021BBFEC(u8 *p)
{
    int i,count;
    *(u8 **)(p+40)=GAME_BEACON_ACCESSOR_AllocInfo(*(u16 *)p);
    *(u32 *)(p+32)=GAME_DATA_GetItemUseWork(*(const struct BigObj **)(*(u8 **)(p+20)+4));
    *(void **)(p+36)=(void *)BEACON_STATUS_GetLog((u32)(*(void **)(p+32)));
    count=GAME_BEACON_ACCESSOR_TableGetCount(*(u8 **)(p+36));
    p[48]=255;
    for(i=0;i<count;i++){
        GAME_BEACON_ACCESSOR_TableRingGet(*(struct Queue **)(p+36),*(struct Rec **)(p+40),(u16 *)(p+44),i);
        if(GAME_BEACON_ACCESSOR_IsInfoInvalid(*(struct Rec **)(p+40))==0 && GAME_BEACON_ACCESSOR_IsDistributionAction(*(u8 **)(p+40))==0){
            if((*(u8 **)(p+20))[8]==i)p[48]=p[47];
            p[p[47]++ +49]=i;
        }
    }
    if(p[48]==255 || p[48]>=p[47])p[48]=0;
    if(p[47]==0)*(u32 *)(p+16)=1;
    p[79]=MSG_SPEED_GetWait();
    *(int *)(p+28)=TOWNMAP_GRH_LoadTownInfo(*(u16 *)p);
}







void BEACON_DETAIL_GRA_Delete(char *p)
{
    TOWNMAP_GRH_FreeTownInfo((void *)(((struct Obj14715 *)p)->f1C));
    func_020307B0((void *)(((struct Obj14715 *)p)->f28));
}






void func_021BC0C8(char *p)
{
    *(struct Tcbl * *)&((struct Obj00366 *)p)->f18=TCBL_Create(((struct Obj00366 *)p)->f0,((struct Obj00366 *)p)->f0,64,128);
    ((struct Obj00366 *)p)->f54=func_020490F4(173,((struct Obj00366 *)p)->f0);
    GF_FONT_SetTextColor(7,8,15);
    ((struct Obj00366 *)p)->f12C=PRINTSYS_QUE_CreateEx(2048,((struct Obj00366 *)p)->f0);
    *(struct GfFont * *)&((struct Obj00366 *)p)->f128=GF_FONT_Create(23,0,0,0,((struct Obj00366 *)p)->f0);
    *(struct WordSet * *)&((struct Obj00366 *)p)->f138=WORDSET_Create(8,64,((struct Obj00366 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00366 *)p)->f130=func_02045B38(0,2,7,((struct Obj00366 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00366 *)p)->f134=func_02045B38(0,2,231,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f13C=STRBUF_Create(109,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f140=STRBUF_Create(109,((struct Obj00366 *)p)->f0);
    *(struct U16Vec * *)&((struct Obj00366 *)p)->f144=STRBUF_Create(109,((struct Obj00366 *)p)->f0);
}






void func_021BC178(char *p)
{
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01437 *)p)->f144);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01437 *)p)->f140);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01437 *)p)->f13C);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj01437 *)p)->f134);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj01437 *)p)->f130);
    WORDSET_DeleteStrbufED04(*(struct WordSet * *)&((struct Obj01437 *)p)->f138);
    GF_FONT_Delete(((struct Obj01437 *)p)->f128);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01437 *)p)->f12C);
    PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj01437 *)p)->f12C);
    GF_FONT_SetDefaultTextColor();
    TCBL_Destroy(*(struct S02031140 * *)&((struct Obj01437 *)p)->f18);
    ARC_TOOL_DeleteHandle(((struct Obj01437 *)p)->f54);
}






void func_021BC1E4(char *p,u16 heap)
{
    struct ArcFile *arc;
    arc=func_020490F4(85,heap);
    func_02049B68(arc,0,0,0,512,heap);
    func_02049B68(((struct Obj01591 *)p)->f54,28,4,0,512,heap);
    func_02049658(((struct Obj01591 *)p)->f54,30,4,0,0,1,heap);
    func_02049658(((struct Obj01591 *)p)->f54,30,5,0,0,1,heap);
    func_02049658(((struct Obj01591 *)p)->f54,30,7,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,32,4,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,32,5,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,33,7,0,0,1,heap);
    BG_SYS_FillTileMap(5,0,0,32,24,1);
    func_020409B4(5);
    func_02049658(((struct Obj01591 *)p)->f54,31,1,0,0,1,heap);
    func_020498F4(((struct Obj01591 *)p)->f54,34,1,0,2048,1,heap);
    func_02049658(arc,5,2,0,0,0,heap);
    func_020498F4(arc,17,2,0,2048,0,heap);
    func_02049658(arc,7,3,0,0,0,heap);
    func_020498F4(arc,16,3,0,2048,0,heap);
    ((struct Obj01591 *)p)->f120=ARC_TOOL_LoadHandleMember(*(struct ArcFile * *)&((struct Obj01591 *)p)->f54,29,((struct Obj01591 *)p)->f0);
    NNS_G2dGetUnpackedPaletteData(*(struct NitroFileHeader * *)&((struct Obj01591 *)p)->f120,(void **)(p+280));
    ((struct Obj01591 *)p)->f11C=((struct Obj25769 *)(*(char * *)&((struct Obj01591 *)p)->f118))->fC;
    ARC_TOOL_DeleteHandle(arc);
    func_0207D63C((u32 *)0x04000050,2,30,11,5);
    func_0207D63C((u32 *)0x04001050,3,31,13,3);
}







void func_021BC378(char *p)
{
    func_020307B0(((struct Obj25770 *)p)->f120);
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned short *)0x04000050 = 0;
}






R *func_021BC398(int manager,int heap){A a;enum {Zero} zero=Zero;MI_CpuFill8(&a,0,32);a.f0=(unsigned char *)d_021BDB4C;a.f4=3;a.f10=13;a.f14=11;a.f8=manager;a.fC=zero;a.f18=zero;return TOUCHBAR_Create(&a,heap);}






void func_021BC3D4(unsigned char *p){TOUCHBAR_Delete(p);}






void func_021BC3DC(S *p){TOUCHBAR_Update(p);}






void func_021BC3E4(unsigned short *p,int *out,const Config_021BBD80 *cfg,void *handle)
{
    MI_CpuFill8(out,0,12);
    out[0]=CLACT_RegisterPaletteEx(handle,cfg->first,cfg->a,(unsigned short)(cfg->b<<5),0,cfg->c,*p);
    out[1]=CLACT_RegisterCharacter((void *)handle,cfg->second,0,cfg->a,*p);
    out[2]=CLACT_RegisterCellAnim((void *)handle,cfg->third,cfg->third+1,*p);
}







void func_021BC43C(void *unused, char *p)
{
    CLACT_ReleaseCellAnim(((struct Obj10945 *)p)->f8);
    CLACT_ReleaseCharacter(((struct Obj10945 *)p)->f4);
    CLACT_ReleasePalette(((struct Obj10945 *)p)->f0);
}





/*
 * lever: two Config_021BC454 locals preserve separate frame objects; p+i*8+144
 * retains per-iteration base addition, and q=p+i*12 holds the row base.
 * Prototype: 0202DA04's complete legacy body consumes only input0;
 * 0202DA48/0202DA18 leave returned r0 live and this caller stores it.
 */
/*
 * lever: two Config locals preserve separate frame objects; p+i*8+144
 * retains per-iteration base addition, and q=p+i*12 holds the row base.
 * Prototype: 0202DA04's complete legacy body consumes only input0;
 * 0202DA48/0202DA18 leave returned r0 live and this caller stores it.
 */
void func_021BC454(char *p,u32 handle)
{
    Config_021BC454 a,b;
    struct ArcFile *arc;
    int i;
    ((struct Obj01783 *)p)->f58=POKEGRA_OpenTrainerHandle(((struct Obj01783 *)p)->f0);
    a=configA;
    func_021BC3E4((u16 *)p, (int *)(p+92), (const Config_021BBD80 *)&a, (void *)handle);
    b=configB;
    arc=func_020490F4(32,((struct Obj01783 *)p)->f2);
    func_021BC3E4((u16 *)p, (int *)(p+128), (const Config_021BBD80 *)&b, (void *)((u32)arc));
    ((struct Obj01783 *)p)->f114=ARC_TOOL_LoadHandleMember(arc,0,((struct Obj01783 *)p)->f0);
    NNS_G2dGetUnpackedPaletteData(*(struct NitroFileHeader * *)&((struct Obj01783 *)p)->f114,(void **)(p+268));
    ((struct Obj01783 *)p)->f110=((struct Obj25771 *)(*(char * *)&((struct Obj01783 *)p)->f10C))->fC;
    for(i=0;i<16;i++){
        *(void **)(p+i*8+144)=ARC_TOOL_LoadHandleMember(arc,i+49,((struct Obj01783 *)p)->f0);
        NNS_G2dGetUnpackedCharacterData(*(struct NitroFileHeader **)(p+i*8+144),(void **)(p+140+i*8));
    }
    ARC_TOOL_DeleteHandle(arc);
    for(i=0;i<2;i++){
        char *q=p+i*12;
        ((struct Obj10946 *)q)->f6C=POKEGRA_RegisterTrainerCgr(((struct Obj01783 *)p)->f58,i+2,1,((struct Obj01783 *)p)->f0);
        ((struct Obj10946 *)q)->f68=(u32)POKEGRA_RegisterTrainerPalette(((struct Obj01783 *)p)->f58,i+2,1,(u16)((i+8)<<5),((struct Obj01783 *)p)->f0);
        ((struct Obj10946 *)q)->f70=POKEGRA_RegisterTrainerCellAnim(i+2,0,1,((struct Obj01783 *)p)->f0);
    }
}





void func_021BC56C(char *p)
{
    int i;
    for(i=0;i<2;i++) func_021BC43C(p,p+0x68+i*12);
    for(i=0;i<16;i++) func_020307B0(*(void **)(p+0x90+i*8));
    func_020307B0(((struct Obj14716 *)p)->f114);
    func_021BC43C(p,p+0x80);
    func_021BC43C(p,p+0x5c);
    ARC_TOOL_DeleteHandle(((struct Obj14716 *)p)->f58);
}





void func_021BC5C4(Window_021BBD80 *p,unsigned char layer,unsigned char palette,unsigned x,unsigned char y,unsigned char width,unsigned char height)
{
    struct Descriptor *window;
    p->window=(struct Descriptor *)BMP_WIN_Create(layer,x,y,width,height,palette,1);
    p->buffer=BMP_WIN_GetBmp(p->window);
    p->copy=p->window;
    p->state=0;
    BMP_Clear(p->buffer,3);
    window=p->window;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen((struct Cfg *)window);
    func_020409B4(BMP_WIN_GetBgLayer(window));
}





unsigned func_021BC614(unsigned short *p,void *manager,unsigned *r,short x,short y,unsigned char z,unsigned char a,unsigned char b,unsigned short flag){Position pos;pos.x=x;pos.y=y;pos.z=z;pos.b=b;pos.a=a;return (unsigned)CLACT_CreateActor(manager,r[1],r[0],r[2],&pos,flag,*p);}




void func_021BC650(char *p)
{
    void *q=func_021BCA38(((struct Obj00366 *)p)->f50);
    void *a=(void *)func_021BC614((short unsigned int *)p,(void *)q,(unsigned int *)(p+0x80),128,120,0,0,2,0);
    ((struct Obj00366 *)p)->f264=a;
    CLACT_SetActorPaletteOffset(a,0,1);
    ((struct Obj00366 *)p)->f268=(void *)func_021BC614((short unsigned int *)p,(void *)q,(unsigned int *)(p+0x5c),96,120,0,1,2,0);
}





void func_021BC6B4(struct S021BC6B4 *p)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        CLACT_SetActorDrawEnable(p->slots[i], 0);
        CLACT_DeleteActor(p->slots[i]);
    }
}


void func_021BC6D8(char *p){func_021BC5C4((Window_021BBD80 *)((Window_021BC6D8 *)(p+0x148)), 1, 11, 2, 22, 28, 6);}





/*
 * Tail-call getter: loads p[0x52] and tail-calls BMP_WIN_Delete.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021BC6FC(u32 *p)
{
    return BMP_WIN_Delete((struct Descriptor *)p[0x52]);
}




void func_021BC70C(char *p)
{
    void *manager;
    int i,j,layer;
    char *q;
    manager=func_021BCA38(*(void **)(p+80));
    *(struct PmsDraw **)(p+344)=PMS_DRAW_Create((u32)manager,1,*(u32 *)(p+300),*(u32 *)(p+296),10,2,*(u16 *)p);
    PMS_DRAW_SetNullColorPalette(*(struct PmsDraw **)(p+344),4);
    PMS_DRAW_SetPrintColor(*(struct PmsDraw **)(p+344),15812);
    PMS_DRAW_SetFollowBgScroll(*(struct PmsDraw **)(p+344),1);
    for(i=0;i<2;i++){
        layer=i+4;
        q=p+348+i*128;
        q[126]=(u8)layer;
        *(u32 *)(q+112)=BMP_WIN_Create((u8)layer,2,15,28,4,i,1);
        for(j=0;j<4;j++)func_021BC5C4((Window_021BBD80 *)(q+j*16),layer,i,2,j*2+1,19,2);
        func_021BC5C4((Window_021BBD80 *)(q+64),layer,i,2,9,19,2);
        func_021BC5C4((Window_021BBD80 *)(q+80),layer,i,3,11,28,4);
        func_021BC5C4((Window_021BBD80 *)(q+96),layer,i,4,19,27,4);
        *(void **)(q+120)=(void *)func_021BC614((unsigned short *)p,manager,(unsigned *)(p+104+i*12),220,44,0,1,i,1);
        CLACT_SetActorObjMode(*(struct Actor **)(q+120),0);
        CLACT_SetActorDrawEnable(*(void **)(q+120),0);
        *(void **)(q+116)=(void *)func_021BC614((unsigned short *)p,manager,(unsigned *)(p+92),200,80,6,0,i,1);
        CLACT_SetActorObjMode(*(struct Actor **)(q+116),1);
        CLACT_SetActorDrawEnable(*(void **)(q+116),0);
    }
}




void func_021BC8A8(char *p)
{
    int i=0,j;
    char *base=p+0x15c;
    for(;i<2;i++) {
        char *q=base+i*128;
        CLACT_SetActorDrawEnable(((struct Obj05553 *)q)->f78,0); CLACT_DeleteActor(((struct Obj05553 *)q)->f78);
        CLACT_SetActorDrawEnable(((struct Obj05553 *)q)->f74,0); CLACT_DeleteActor(((struct Obj05553 *)q)->f74);
        BMP_WIN_Delete(((struct Obj05553 *)q)->f60);
        for(j=0;j<2;j++) BMP_WIN_Delete(*(void **)(q+0x40+j*16));
        for(j=0;j<4;j++) BMP_WIN_Delete(*(void **)(q+j*16));
        BMP_WIN_Delete(((struct Obj05553 *)q)->f70);
    }
    PMS_DRAW_Delete(((struct Obj01437 *)p)->f158);
}





/*
 * Tail-call getter: loads p[0x56] and tail-calls sub_0202DBC4.
 *
 * Addresses are Black-image addresses.
 */
int func_021BC920(u32 *p)
{
    return sub_0202DBC4(p[0x56]);
}




/*
 * volatile: hardware accesses 0x021BC956-0x021BC96A.
 */
void *BEACON_DETAIL_GRA_Create(int a,int heap)
{
    unsigned *p=func_02030734(heap,16,0,d_021BDDC0,317);
    MI_CpuFill8(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BDBD8);
    BMP_SetDisplaySwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    func_021BCA58(p,heap);
    func_021BCAFC((void **)(p+1),d_021BDBD8,heap);
    p[3]=(unsigned)func_020056A0((void (*)(void *, void *))BEACON_DETAIL_GRA_Task,p,0);
    return p;
}




void func_021BC9D0(unsigned *p)
{
    func_02030EAC((void *)p[3]);
    func_021BCB70((char *)(p+1));
    func_021BCAB8(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p,0,16);
    func_020307B0(p);
}





void func_021BCA24(char *p)
{
    func_021BCB90(p + 4);
    func_021BCAF0(p);
}




void *func_021BCA38(char *p){return (void *)func_021BCBA0((u32 *)(p+4));}





void BEACON_DETAIL_GRA_Task(void *unused, char *p)
{
    func_021BCAF4(p);
    func_021BCB98(p + 4);
}




void func_021BCA58(void *p,int heap)
{
    unsigned i;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BDBAC);
    for(i=0;i<8;i++) {
        const struct Entry *e=&d_021BDC28[i];
        unsigned id=e->id;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)e->fields,(u8)e->a);
        BG_SYS_FreeSlot(id);
        func_02040588(id,e->b);
    }
}




void func_021BCAB8(void *p){unsigned base=(unsigned)d_021BDC28;unsigned i;for(i=0;i<8;i++)func_020403F4((unsigned char)(*(const unsigned *)(base+i*44)));BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}




void func_021BCAF0(void *p) {}



void func_021BCAF4(void *a0){BG_SYS_Update();}



void func_021BCAFC(void **p,void *a,int heap)
{
    struct Block b;
    MI_CpuFill8(p,0,8);
    CLACT_InitSystem((const struct Cfg *)d_021BDBBC,(unsigned int)a,heap);
    p[0]=CLACT_CreateUnit(128,0,heap);
    b=d_021BDC08;
    p[1]=CLACT_CreateRenderer((u8 *)(&b),2,heap);
    CLACT_SetRendererCulling(p[1],1);
    CLACT_SetUnitRenderer(p[0],p[1]);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
}




void func_021BCB70(char *p)
{
    CLACT_DeleteRenderer(((struct Obj14717 *)p)->f4);
    CLACT_DeleteUnit(((struct Obj14717 *)p)->f0);
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 8);
}



void func_021BCB90(void *a0){CLACT_DrawSystem();}



void func_021BCB98(void *a0){CLACT_VBlankSystem();}



u32 func_021BCBA0(u32*p){return *p;}



void func_021BCBA4(unsigned char *p)
{
    func_021BCF08((char *)p);
    GAME_BEACON_ACCESSOR_TableRingGet(((struct Obj00051 *)p)->f24,((struct Obj00051 *)p)->f28,(u16 *)(p+0x2c),*(p+p[0x30]+0x31));
    func_021BD174((char *)p,((struct Obj00051 *)p)->f28,((struct Obj00051 *)p)->f2C,p[0x2e]);
    func_021BD0E4((char *)p,p[0x2e],1);
    func_021BD0E4((char *)p,p[0x2e]^1,0);
    func_021BD448((char *)p); func_021BCD60(p);
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj00051 *)p)->f2);
}



int func_021BCC10(unsigned char *p)
{
    int state=TOUCHBAR_GetPressedButtonIdIfPressing(((struct Obj05554 *)p)->f124);
    unsigned keys=KEY_GetTrg();
    if(ICA_ANIME_GetUnk330((const struct Ctx *)**(void ** *)&((struct Obj05554 *)p)->f14)) { (*(unsigned char **)(p+0x14))[9]=1; return 4; }
    if(state==1) { (*(unsigned char **)(p+0x14))[9]=0; return 4; }
    if(state==3 && p[0x30]) { func_021BD89C((char *)p,1); return 3; }
    if(state==2 && p[0x30]<p[0x2f]-1) { func_021BD89C((char *)p,0); return 3; }
    if(!p[0x260]) return 2;
    if(func_021BCCC4(p) || (keys&1)) { func_021BCD00(1356); func_021BD6F0((char *)p); return 3; }
    return 2;
}



void func_021BCCBC(u8*p){func_021BCD60(p);}



int func_021BCCC4(u8*p){u32 x,y;if(TOUCHPANEL_GetPointTrg(&x,&y)){if((u32)(x-(((struct Obj14718 *)p)->f25C-12))<=24 && (u32)(y-(((struct Obj14718 *)p)->f25E-16))<=32)return 1;}return 0;}



void func_021BCD00(int a){GFL_USE_PlaySeDefaultVolume(a);}



void func_021BCD08(void *p,unsigned mode,unsigned a,unsigned b)
{
    unsigned x=a*2,y=b*2;
    DWCi_ScreenDC_FlushRange(p,y);
    switch(mode) {
    case 0: GX_LoadBGPltt(p,x,y); break;
    case 1: func_0207E468(p,x,y); break;
    case 2: GX_LoadOBJPltt(p,x,y); break;
    case 3: func_0207E5D0(p,x,y); break;
    }
}



void func_021BCD60(unsigned char *p)
{
    TOUCHBAR_SetButtonEnabled(((struct Object *)p)->menu,1,1);
    if(p[0x30]) TOUCHBAR_SetButtonEnabled(((struct Object *)p)->menu,3,1);
    else TOUCHBAR_SetButtonEnabled(((struct Object *)p)->menu,3,0);
    if(p[0x30]<p[0x2f]-1) TOUCHBAR_SetButtonEnabled(((struct Object *)p)->menu,2,1);
    else TOUCHBAR_SetButtonEnabled(((struct Object *)p)->menu,2,0);
}




/*
 * Unblocked by matching GAME_BEACON_ACCESSOR_GetPmVersion (ov010, EXACT): the +0002 call site now
 * attests as `matched`.  ov009 holds ARM code at that address; ov010 is the
 * coherent Thumb leaf, so the correct hint is ov010 (the earlier ov009 hint
 * was wrong).
 *
 * The original selects case 0x15 before 0x14: reversing the two source
 * case labels flips the fall-through to put the default arm last, which is
 * the only shape that reproduces the image's three-exit if-chain.
 *
 * Addresses are Black-image addresses.
 */
int func_021BCDC0(void *a0)
{
    switch (GAME_BEACON_ACCESSOR_GetPmVersion(a0)) {
    case 0x15:
        return 0;
    case 0x14:
        return 1;
    default:
        return 2;
    }
}



const u8*func_021BCDDC(u32 n){u32 i;for(i=0;i<6;i++){if(n==d_021BDDA2[i*3])return d_021BDDA2+i*3;}return d_021BDDA2;}



void func_021BCE04(void *p,void *q)
{
    switch(GAME_BEACON_ACCESSOR_GetDetailsType(p)) {
    case 0: case 1:
        WORDSET_Callback(q,0,GAME_BEACON_ACCESSOR_GetDetailsMonsNo(p)); break;
    case 2: {
        unsigned a=GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(p);
        WORDSET_SetSlotPokeData(q,0,a); WORDSET_SetSlotFromMsgBE(q,1,a); break;
    }
    case 3: case 4: break;
    default: {
        unsigned a=GAME_BEACON_ACCESSOR_GetZoneId(p);
        if(a>=427) a=317;
        WORDSET_SetSlotFromMsg59(q,0,ZONEDATA_GetPlaceNameId(a)); break;
    }
    }
}




void func_021BCE7C(void *p, unsigned short value)
{
    CLACT_SetActorAnimSeq(p, value);
    CLACT_RestartActorAnim(p);
}




void func_021BCE8C(void *a0, short a1, short a2, int a3)
{
    u16 tmp[2];
    tmp[0] = a1;
    tmp[1] = a2;
    CLACT_AddActorSurfacePos(a0, (const struct Vec2 *)tmp, a3);
}



/*
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
 * extern void func_020307B0(void *p);
 * extern void ARC_TOOL_ReadHandle(void *stream, u32 size, void *dest);
 * extern void func_0204960C(void *stream, u32 pos);
 * extern void STRBUF_Clear(void *dest);
 * extern void STRBUF_SetChars(void *dest, const void *src, u16 len);
 * extern void func_02045E04(void *dest, u32 index);
 * extern u8 func_020461B8(const void *file);
 * extern void MSGDATA_LoadBank(struct MsgBank *bank);
 * extern void func_02046180(struct MsgBank *bank);
 *
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *
 *     func_02046180(bank);
 *
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *
 *         func_0204960C(bank->stream, pos + (index * 8 + 4));
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
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *             STRBUF_SetChars(dest, buf, e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 *
 *     func_02045E04(dest, index);
 * }
 */
void func_021BCEA4(u8*p, u8 n){func_02045CAC(*(struct MsgBank**)(p+0x130),n,*(void**)(p+0x13c));WORDSET_CopyTaggedText(*(struct WordSet**)(p+0x138),*(void**)(p+0x140),*(void**)(p+0x13c));}



void func_021BCED0(u8*p,u32 n){CLACT_TransferCharacter(((struct Obj14719 *)p)->f84,*(struct Sub0204A9D0**)((u32)p+n*8+0x8c));func_021BCD08((u8*)*(void* *)&((struct Obj14719 *)p)->f110+(d_021BDD92[n]&15)*32,2,160,16);}




#pragma opt_lifetimes off



#pragma opt_propagation off



/*
 * note: final push 2026-10-05 G5L8. EXACT 372 B (c99 and c). Closed by: opt_propagation off with named locals b, a,
 *   rec and off (b, the row offset i*16 and a set in that order in loop 1 before the j loop), do-while loops (with
 *   propagation off a for loop gets an entry guard), x and j as separate counters, j = 0 set only before loop 3
 *   (set before loop 2 it was loaded from x's slot), record address as off + (u32)&w[j] for the add order.
 */
void func_021BCF08(char *p)
{
    struct Win *w3;
    struct Win *w2;
    struct Win *w;
    int i, j;
    u8 b;
    u16 a;
    struct Rec *rec;
    int off;
    int x;

    i = 0;
    w = (struct Win *)(p + 0x15C);

    do {
        func_02045CAC((struct MsgBank *)HANDLE(p, 0x130), i, (void *)ARG(p, 0x130));
        b = d_021BDD8A[i % 2].b;
        off = i * 16;
        a = d_021BDD8A[i % 2].a;
        j = 0;
        do {
            rec = (struct Rec *)(off + (u32)&w[j]);
            BMP_Clear((struct CharBuf *)rec->h, b);
            func_021BDA54(p, (char *)rec, 0, 0, ARG(p, 0x130), a);
            CALLS(rec);
            j++;
        } while (j < 2);
        i++;
    } while (i < 4);
    func_02045CAC((struct MsgBank *)HANDLE(p, 0x130), 7, (void *)ARG(p, 0x130));
    w2 = (struct Win *)(p + 0x130 + 0x2C);

    x = 0;
    do {
        BMP_Clear((struct CharBuf *)w2[x].b.h, 3);
        func_021BDA54(p, (char *)&w2[x].b, 0, 0, ARG(p, 0x130), 0x3DC3);
        CALLS(&w2[x].b);
        x++;
    } while (x < 2);
    func_02045CAC((struct MsgBank *)HANDLE(p, 0x130), 9, (void *)ARG(p, 0x130));
    w3 = (struct Win *)(p + 0x130 + 0x2C);
    j = 0;
    do {
        BMP_Clear((struct CharBuf *)w3[j].c.h, 3);
        func_021BDA54(p, (char *)&w3[j].c, 0, 0, ARG(p, 0x130), 0x3DC3);
        CALLS(&w3[j].c);
        j++;
    } while (j < 2);
}



#pragma opt_propagation reset



#pragma opt_lifetimes reset



void func_021BD07C(void *p,void **q,int v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e)
{
    void *x;
    BMP_FillRect(q[1],(short)(a*8),0,(unsigned short)(c*8),(unsigned short)(d*8),d_021BDD8A[e].b);
    func_021BDA54(p,(char *)q,b,0,v,d_021BDD8A[e].a);
    x=q[0];
    BMP_WIN_TransferChars(x); BMP_WIN_MakeScreen(x); func_020409B4(BMP_WIN_GetBgLayer(x));
}



void func_021BD0E4(char *p, u8 index, u32 enable)
{
    char *entry;
    entry = p + 0x15c + index * 128;
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj08428 *)entry)->f78, enable);
    if (((struct Obj08428 *)entry)->f7D != 0)
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj08428 *)entry)->f74, enable);
    if (sub_0202DCC4(*(struct Obj0202DCC4 * *)&((struct Obj00051 *)p)->f158, index) != 0)
        PMS_DRAW_SetVisible(*(struct Obj0202DC98 * *)&((struct Obj00051 *)p)->f158, index, enable);
    BG_SYS_SetPlaneVisible(((struct Obj08428 *)entry)->f7E, (u8)enable);
}



/*
 * prototype: 021BCE8C coordinate parameters are signed short: original uses asrs #16 before each call; same-overlay matched caller 021BD448 declares s16.
 */
void func_021BD13C(u8*p,int a){func_02040618(p[0x7e],3,-a);func_021BCE8C(*(void* *)&((struct Obj10948 *)p)->f78,220,a+44,1);func_021BCE8C(*(void* *)&((struct Obj10948 *)p)->f74,200,a+80,1);}



void func_021BD174(char *p,void *record,u16 unused,u8 slot)
{
    struct Pair colors;
    struct Quad data;
    struct Pair counts;
    char *q=(char *)p+0x15c+slot*128;
    u32 subtype;
    u16 value;
    int position;
    int index;
    GAME_BEACON_ACCESSOR_GetFavoriteColorRgb((int)(&colors.a),(int)record);
    PALANM_BlendColors(&colors.a,&colors.b,1,3,0);
    position=slot*16;
    func_021BCD08(&colors,1,(u16)(position+1),2);
    func_021BCD08(*(char * *)&((struct Obj00051 *)p)->f11C+func_021BCDC0(record)*32,1,(u16)(position+10),2);
    GAME_BEACON_ACCESSOR_GetPlayerName(record,((struct Obj00051 *)p)->f13C);
    func_021BD07C((char *)p,(void **)q,*(int *)&((struct Obj00051 *)p)->f13C,6,48,13,2,0);
    subtype=GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond((int)record);
    if(subtype==255) STRBUF_Clear(*(struct U16Vec * *)&((struct Obj00051 *)p)->f140);
    else {WORDSET_SetSlotFromMsg38(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,subtype);func_021BCEA4((u8 *)p,5);}
    func_021BD07C((char *)p,(void **)(q+16),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,1);
    subtype=GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst((int)record);
    if(subtype==255) STRBUF_Clear(*(struct U16Vec * *)&((struct Obj00051 *)p)->f140);
    else {WORDSET_SetSlotFromMsg2B(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,subtype);func_021BCEA4((u8 *)p,4);}
    func_021BD07C((char *)p,(void **)(q+32),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,0);
    GAME_BEACON_ACCESSOR_GetPlayTime(record,&counts.b,&counts.a);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,2,counts.b,3,0,1);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,3,counts.a,2,2,1);
    func_021BCEA4((u8 *)p,6);
    func_021BD07C((char *)p,(void **)(q+48),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,1);
    value=(unsigned)GAME_BEACON_ACCESSOR_GetNation(record);
    WORDSET_SetSlotFromMsgE7(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,value);
    WORDSET_DeleteMsgdataF094(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,value,GAME_BEACON_ACCESSOR_GetArea(record));
    func_021BCEA4((u8 *)p,8);
    func_021BD07C((char *)p,(void **)(q+80),*(int *)&((struct Obj00051 *)p)->f140,0,0,28,4,0);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,GAME_BEACON_ACCESSOR_GetPassCount(record),5,1,1);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,GAME_BEACON_ACCESSOR_GetThanksCount(record),5,1,1);
    func_021BCEA4((u8 *)p,10);
    func_021BD07C((char *)p,(void **)(q+96),*(int *)&((struct Obj00051 *)p)->f140,21,0,6,4,0);
    if(PMS_DRAW_IsActive(*(struct Obj0202DCC4 * *)&((struct Obj00051 *)p)->f158,slot)!=0) PMS_DRAW_Clear(*(struct Obj0202DC98 * *)&((struct Obj00051 *)p)->f158,slot,1);
    GAME_BEACON_ACCESSOR_GetDetailsPms(record,&data);
    PMS_DRAW_Print(*(u32 *)&((struct Obj00051 *)p)->f158,((struct Obj05555 *)q)->f70,(u32)&data,slot);
    ((struct Obj05555 *)q)->f7C=GAME_BEACON_ACCESSOR_GetTrainerAppearance(record);
    index=slot*12;
    POKEGRA_LoadTrainerGraphics(((struct Obj00051 *)p)->f58,CURSOR_MOVE_GetTableGroup(((struct Obj05555 *)q)->f7C),*(void **)((u32)p+0x6c+(u32)index),*(void **)((u32)p+0x68+(u32)index),((struct Obj00051 *)p)->f2);
    subtype=GAME_BEACON_ACCESSOR_GetResearchTeamRank(record);
    if(subtype==0) {CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj05555 *)q)->f74,0);return;}
    func_021BCE7C(((struct Obj05555 *)q)->f74,(u8)(subtype+1));
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj05555 *)q)->f74,1);
}



void func_021BD448(char *p)
{
    const u8 *type;
    u32 value;
    int index,high;
    struct Descriptor *d;
    GAME_BEACON_ACCESSOR_TableRingGet(*(struct Queue * *)&((struct Obj00051 *)p)->f24,*(struct Rec * *)&((struct Obj00051 *)p)->f28,(u16 *)(p+44),*(u8 *)((u32)p+((struct Obj00051 *)p)->f30+49));
    type=func_021BCDDC(GAME_BEACON_ACCESSOR_GetDetailsType(*(const char * *)&((struct Obj00051 *)p)->f28));
    func_021BCED0((u8 *)p,GAME_BEACON_ACCESSOR_GetTrainerAppearance(*(struct S * *)&((struct Obj00051 *)p)->f28));
    value=GAME_BEACON_ACCESSOR_GetZoneId(*(struct Bits * *)&((struct Obj00051 *)p)->f28);
    index=TOWNMAP_GRH_FindRecordIndex(*(int *)&((struct Obj00051 *)p)->f1C,GAME_BEACON_ACCESSOR_GetTownmapRootZoneId((const struct Bits *)(*(const char * *)&((struct Obj00051 *)p)->f28)));
    if(index==0xffff || TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct Obj00051 *)p)->f1C,index,16)!=0xffff || value>=427) {
        ((struct Obj00051 *)p)->f260=0;
        *(volatile s16 *)&((struct Obj00051 *)p)->f25E=0;
        ((struct Obj00051 *)p)->f25C=*(volatile s16 *)&((struct Obj00051 *)p)->f25E;
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00051 *)p)->f264,0);
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00051 *)p)->f268,0);
    } else {
        ((struct Obj00051 *)p)->f260=1;
        ((struct Obj00051 *)p)->f25C=TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct Obj00051 *)p)->f1C,index,2);
        ((struct Obj00051 *)p)->f25E=TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct Obj00051 *)p)->f1C,index,3)-16;
        if(((struct Obj00051 *)p)->f25E<32) ((struct Obj00051 *)p)->f25E=32;
        else if(((struct Obj00051 *)p)->f25E>152) ((struct Obj00051 *)p)->f25E=152;
        if(((struct Obj00051 *)p)->f25C<16) ((struct Obj00051 *)p)->f25C=16;
        else if(((struct Obj00051 *)p)->f25C>240) ((struct Obj00051 *)p)->f25C=240;
        func_021BCE8C(((struct Obj00051 *)p)->f264,((struct Obj00051 *)p)->f25C,((struct Obj00051 *)p)->f25E,0);
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00051 *)p)->f264,1);
        if(type[2]!=0) {
            func_021BCE8C(((struct Obj00051 *)p)->f268,((struct Obj00051 *)p)->f25C-24,((struct Obj00051 *)p)->f25E,0);
            func_021BCE7C(((struct Obj00051 *)p)->f268,(u8)(type[2]-1));
        }
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj00051 *)p)->f268,type[2]!=0);
    }
    BMP_Clear(*(struct CharBuf * *)&((struct Obj00051 *)p)->f14C,15);
    high=(u8)(((struct Obj00051 *)p)->f2C>>8);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,high,2,0,1);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,(u8)((struct Obj00051 *)p)->f2C,2,2,1);
    func_021BCEA4((u8 *)p,(high/12)+13);
    func_021BDA54(p,p+0x148,0,0,*(u32 *)&((struct Obj00051 *)p)->f140,0x1d0f);
    func_021BCE04(((struct Obj00051 *)p)->f28,((struct Obj00051 *)p)->f138);
    func_021BCEA4((u8 *)p,type[1]);
    func_021BDA54(p,p+0x148,0,16,*(u32 *)&((struct Obj00051 *)p)->f140,0x1d0f);
    d=*(struct Descriptor * *)&((struct Obj00051 *)p)->f148;
    BMP_WIN_TransferChars(d);
    BMP_WIN_MakeScreen((struct Cfg *)d);
    func_020409B4(BMP_WIN_GetBgLayer(d));
}



/*
 * lever: the signed byte step derives -8 from live 64 with subs #72; u8 emits movs #248.
 */
void func_021BD668(char *owner, int direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj25779 *)owner)->f18, (void (*)(struct TcblNode *, void *))BEACON_DETAIL_GRA_Callback, 12, 0));
    MI_CpuFill8(work, 0, 12);
    ((struct Obj03943 *)work)->f0 = direction;
    if (((struct Obj03943 *)work)->f0 == 0) {
        ((struct Obj03943 *)work)->f3 = 0;
        ((struct Obj03943 *)work)->f4 = 8;
    } else {
        ((struct Obj03943 *)work)->f3 = 64;
        ((struct Obj03943 *)work)->f4 = -8;
    }
    ((struct Obj03943 *)work)->f1 = 8;
    func_021BCD00(1357);
    *(int * *)&((struct Obj03943 *)work)->f8 = counter;
    ++*counter;
}



void BEACON_DETAIL_GRA_Callback(struct TcblNode*task,u8*p){u32 old=p[2]++;if(old<p[1]){((struct Obj04637 *)p)->f3=((struct Obj04637 *)p)->f3+((struct Obj04637 *)p)->f4;func_02040618(1,3,((struct Obj04637 *)p)->f3);}else{--**(u32* *)&((struct Obj04637 *)p)->f8;TCBL_DeleteTask(task);}}



void func_021BD6F0(char*p){func_021BD6FC(p,(int*)(p+12));}



/*
 * region evidence: ov067 labels 021B64A8; its filed/full body reads the supplied object in r0 and enable in r1.
 */
void func_021BD6FC(char *owner, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj14720 *)owner)->f18, func_021BD768, 16, 0));
    MI_CpuFill8(work, 0, 16);
    *(char * *)&((struct Obj10949 *)work)->f8 = owner;
    ((struct Obj10949 *)work)->f1 = 150;
    TOUCHBAR_SetAllButtonsEnabled(*(u8 * *)&((struct Obj14720 *)owner)->f124, 0);
    *(int * *)&((struct Obj10949 *)work)->fC = counter;
    ++*counter;
}




int func_021BD73C(char *p)
{
    unsigned char c;
    if (TOUCHPANEL_GetTrg() != 0 || (KEY_GetTrg() & 1) != 0)
    {
        ((struct Obj10950 *)p)->f1 = 0;
        return 0;
    }
    c = ((struct Obj10950 *)p)->f1;
    ((struct Obj10950 *)p)->f1 = c - 1;
    if (c != 0)
    {
        return 1;
    }
    return 0;
}



void func_021BD768(struct TcblNode *task, void *data)
{
    char *p = data;
    switch (((struct Obj03375 *)p)->f0) {
    case 0:
        func_021BD668(((struct Obj03375 *)p)->f8, 0, (int *)(p + 4));
        ++((struct Obj03375 *)p)->f0;
        break;
    case 1:
        if (((struct Obj03375 *)p)->f4 == 0)
            ++((struct Obj03375 *)p)->f0;
        break;
    case 2:
        if (func_021BD73C(p) == 0) {
            func_021BD668(((struct Obj03375 *)p)->f8, 1, (int *)(p + 4));
            ++((struct Obj03375 *)p)->f0;
        }
        break;
    case 3:
        if (((struct Obj03375 *)p)->f4 != 0)
            break;
    default:
        --**(int * *)&((struct Obj03375 *)p)->fC;
        TCBL_DeleteTask(task);
        break;
    }
}



/*
 * lever: u8 direction puts the r3 home first; caller 021BD948 supplies ldrb direction in r3.
 */
void func_021BD7D4(char *owner, u8 index, int position, u8 direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj00051 *)owner)->f18, (void (*)(struct TcblNode *, void *))func_021BD854, 24, 0));
    MI_CpuFill8(work, 0, 24);
    *(char * *)&((struct Obj02553 *)work)->fC = owner + 0x15c + index * 128;
    ((struct Obj02553 *)work)->f0 = index;
    ((struct Obj02553 *)work)->f4 = (1 - position) * -192;
    if (direction == 0)
        ((struct Obj02553 *)work)->f6 -= 8;
    else
        ((struct Obj02553 *)work)->f6 += 8;
    ((struct Obj02553 *)work)->f1 = 24;
    func_021BD13C(((struct Obj02553 *)work)->fC, ((struct Obj02553 *)work)->f4);
    if (position != 1)
        func_021BD0E4(owner, ((struct Obj02553 *)work)->f0, 1);
    *(char * *)&((struct Obj02553 *)work)->f10 = owner;
    *(int * *)&((struct Obj02553 *)work)->f14 = counter;
    ++*counter;
}



void func_021BD854(struct TcblNode *task, char *p)
{
    u8 count;
    count = ((struct Obj02927 *)p)->f1;
    ((struct Obj02927 *)p)->f1 = count - 1;
    if (count != 0) {
        ((struct Obj02927 *)p)->f4 += ((struct Obj02927 *)p)->f6;
        func_021BD13C(((struct Obj02927 *)p)->fC, ((struct Obj02927 *)p)->f4);
        return;
    }
    if (((struct Obj02927 *)p)->f4 != 0)
        func_021BD0E4(((struct Obj02927 *)p)->f10, ((struct Obj02927 *)p)->f0, 0);
    --**(int * *)&((struct Obj02927 *)p)->f14;
    TCBL_DeleteTask(task);
}



void func_021BD89C(char*p,int a){func_021BD8A8(p,a,(int*)(p+12));}



void func_021BD8A8(char *owner, int direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj00051 *)owner)->f18, (void (*)(struct TcblNode *, void *))func_021BD948, 24, 0));
    MI_CpuFill8(work, 0, 24);
    ((struct Obj05556 *)work)->f4 = direction;
    if (direction == 0) {
        ((struct Obj05556 *)work)->f3 = ((struct Obj00051 *)owner)->f30 + 1;
        TOUCHBAR_SetButtonEnabled(((struct Obj00051 *)owner)->f124, 3, 0);
    } else {
        ((struct Obj05556 *)work)->f3 = ((struct Obj00051 *)owner)->f30 - 1;
        TOUCHBAR_SetButtonEnabled(((struct Obj00051 *)owner)->f124, 2, 0);
    }
    TOUCHBAR_SetButtonEnabled(((struct Obj00051 *)owner)->f124, 1, 0);
    GAME_BEACON_ACCESSOR_TableRingGet(*(struct Queue * *)&((struct Obj00051 *)owner)->f24, *(struct Rec * *)&((struct Obj00051 *)owner)->f28, (u16 *)(owner + 0x2c), *(u8 *)(owner + 0x31 + ((struct Obj05556 *)work)->f3));
    func_021BD174(owner, ((struct Obj00051 *)owner)->f28, ((struct Obj00051 *)owner)->f2C, ((struct Obj00051 *)owner)->f2E ^ 1);
    *(char * *)&((struct Obj05556 *)work)->f10 = owner;
    *(int * *)&((struct Obj05556 *)work)->f14 = counter;
    ++*counter;
}



/*
 * Lever: explicit case 3 plus default preserves four switch arms; BD7D4 u8 index preserves the original XOR truncation pair, own int index notwithstanding.
 */
void func_021BD948(struct TcblNode *task,char *work)
{
    if(((struct Obj00690 *)work)->f5==0) {
        if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct Obj25787 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f124)!=-1)
            ((struct Obj00690 *)work)->f5=1;
    }
    if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj25788 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f12C)==0) return;
    switch(((struct Obj00690 *)work)->f0) {
    case 0:
        if(((struct Obj00690 *)work)->f5==0) break;
        TOUCHBAR_SetAllButtonsEnabled(*(u8 * *)&((struct Obj25789 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f124,0);
        ++((struct Obj00690 *)work)->f0;
        return;
    case 1:
        func_021BD7D4(*(char * *)&((struct Obj00690 *)work)->f10,((struct Obj25790 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f2E,1,((struct Obj00690 *)work)->f4,(int *)(work+8));
        func_021BD7D4(*(char * *)&((struct Obj00690 *)work)->f10,((struct Obj25791 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f2E^1,d_021BDD88[((struct Obj00690 *)work)->f4],((struct Obj00690 *)work)->f4,(int *)(work+8));
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj25792 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f264,0);
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj25793 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f268,0);
        ++((struct Obj00690 *)work)->f0;
        return;
    case 2:
        if(((struct Obj00690 *)work)->f8!=0) break;
        ((struct Obj25794 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f2E^=1;
        ((struct Obj25795 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f30=((struct Obj00690 *)work)->f3;
        func_021BD448(((struct Obj00690 *)work)->f10);
        ++((struct Obj00690 *)work)->f0;
        return;
    case 3:
    default:
        --**(int * *)&((struct Obj00690 *)work)->f14;
        TCBL_DeleteTask(task);
        break;
    }
}



/*
 * lever: u16 c moves its r3 spill before the handle load and restores call setup; u32 leaves 24 concrete bytes different.
 */
void func_021BDA54(char *owner, char *record, u32 b, u16 c, u32 d, u16 f)
{
    void *handle;
    handle = ((struct Obj14721 *)owner)->f12C;
    PRINTSYS_PrintQueColor(handle, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj08427 *)record)->f8), b, c, d, ((struct Obj14721 *)owner)->f128, f);
    ((struct Obj08427 *)record)->fC = 1;
    func_021BDAA0((u8 *)owner, (int)record, (int *)(owner + 12));
}



void func_021BDAA0(u8 *p,int arg,int *counter)
{
    Work *work;
    work=TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj25797 *)p)->f18,(TcblFunc)BEACON_DETAIL_GRA_PrintWaitTask,12,0));
    MI_CpuFill8(work,0,12);
    work->owner=p;
    work->arg=arg;
    if(counter!=0){work->counter=counter;++*counter;}
}


void BEACON_DETAIL_GRA_PrintWaitTask(int a, int **b)
{
    u8   *s = (u8 *)b[0] + 8;
    int   q = ((struct Obj25799 *)((char *)b[1]))->f12C;

    if (s[4]) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj06711 *)s)->f0))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06711 *)s)->f0);
            s[4] = 0;
        }
    }
    if (s[4] == 0) {
        if (b[2])
            --*(int *)b[2];
        TCBL_DeleteTask((struct TcblNode *)a);
    }
}
