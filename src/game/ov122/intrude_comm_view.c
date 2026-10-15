/*
 * file:     intrude_comm_view.c
 * unit:     yes
 * function: INTRUDE_COMM_VIEW_StoreCallback, INTRUDE_COMM_VIEW_SetCallback, INTRUDE_COMM_VIEW_SetupBackgrounds, INTRUDE_COMM_VIEW_BuildRowList, INTRUDE_COMM_VIEW_RebuildRow, INTRUDE_COMM_VIEW_DeleteRowSlot, INTRUDE_COMM_VIEW_ResetRowSlot, INTRUDE_COMM_VIEW_DeleteRows, INTRUDE_COMM_VIEW_InvokeCallback, INTRUDE_COMM_VIEW_BrightenPalette, INTRUDE_COMM_VIEW_CreateActors, INTRUDE_COMM_VIEW_CreateResources, INTRUDE_COMM_VIEW_InitMenu, INTRUDE_COMM_VIEW_DeleteResources, INTRUDE_COMM_VIEW_CheckExitRequest, INTRUDE_COMM_VIEW_BeginExit, INTRUDE_COMM_VIEW_StartExit, INTRUDE_COMM_VIEW_Noop, INTRUDE_COMM_VIEW_AnimateSelectedRow, INTRUDE_COMM_VIEW_SelectRow, INTRUDE_COMM_VIEW_DrawRowText, INTRUDE_COMM_VIEW_UpdatePeerList, INTRUDE_COMM_VIEW_Update, INTRUDE_COMM_VIEW_InitStatusText, INTRUDE_COMM_VIEW_UpdateActorAnim, INTRUDE_COMM_VIEW_SetFoundPeerMac, INTRUDE_COMM_VIEW_ClearFoundPeerMac, INTRUDE_COMM_VIEW_OnScanResult, INTRUDE_COMM_VIEW_StorePeerRecord, INTRUDE_COMM_VIEW_TickPeerTimers, INTRUDE_COMM_VIEW_SumPeerTimers, INTRUDE_COMM_VIEW_VBlankHandler, INTRUDE_COMM_VIEW_Create, INTRUDE_COMM_VIEW_Main, INTRUDE_COMM_VIEW_Exit
 * address:  0x021D4240
 * region:   ov122
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D5780 0x021D5780 data a4
 *   d_021D57A0 0x021D57A0 data a4
 *   d_021D57C0 0x021D57C0 data a4
 *   d_021D57E0 0x021D57E0 data a4
 *   d_021D5800 0x021D5800 data a4
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204047C 0x0204047C arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_0201F7A8 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   func_02041B6C 0x02041B6C arm
 *   data_021D5708 0x021D5708 data a1
 *   data_021D5704 0x021D5704 data a1
 *   data_021D570C 0x021D570C data a1
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   data_021D5870 0x021D5870 data a2
 *   d_021D575C 0x021D575C data a4
 *   d_021D5890 0x021D5890 data a4
 *   d_021D5720 0x021D5720 data a4
 *   d_021D5718 0x021D5718 data a4
 *   d_021D5728 0x021D5728 data a4
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02040DA8 0x02040DA8 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   func_020403F4 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   NET_WHPIPE_SetNotifyCallback 0x02178118 thumb ov014
 *   func_0204BA00 0x0204BA00 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   INTRUDE_COMM_GetRequestState 0x02158630 thumb ov010
 *   data_021D58E0 0x021D58E0 data a4
 *   INTRUDE_COMM_CountEventPeers 0x02158678 thumb ov010
 *   INTRUDE_COMM_GetRequesterStatus 0x021586C8 thumb ov010
 *   data_021D5714 0x021D5714 data ov122 a4
 *   data_021D5840 0x021D5840 data a4
 *   data_021D5850 0x021D5850 data a4
 *   data_021D5860 0x021D5860 data a4
 *   data_021D5710 0x021D5710 data a4
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   GFL_NET_GetScanResultMac 0x0203CF3C arm
 *   GFL_NET_GetScanResult 0x0203CF10 arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   func_0203EFC8 0x0203EFC8 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0204363C 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   TCBL_Create 0x0203101C arm
 *   func_0207D63C 0x0207D63C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   func_020355D8 0x020355D8 arm
 *   data_021D58B0 0x021D58B0 data a4
 *   data_021D5770 0x021D5770 data a4
 *   data_021D5740 0x021D5740 data a4
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   CLACT_DrawSystem 0x0204A600 arm
 *   GAME_DATA_GetField1A0 0x0201283C thumb
 *   WIH_DWC_PollStatus 0x0201058C thumb
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_02040618 0x02040618 arm
 *   GAMESYSTEM_TryStartAutoComm 0x020121CC thumb
 *   ICA_ANIME_GetUnk330 0x02012204 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   GAME_BEACON_GetNextNewLogIndex  0x02026CA0  thumb  arm9
 *   FIELD_SOUND_SYSTEM_StartRingtone  0x02028A64  thumb  arm9
 *   COMM_PLAYER_SUPPORT_GetRecordFieldPtr  0x0202E930  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   GAME_COMM_GetKind  0x02026454  thumb  arm9
 *   ICA_ANIME_GetField24  0x02012138  thumb  arm9
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb  arm9
 *   WORDSET_Create  0x0201EC74  thumb  arm9
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 */
#include "../../matched/include/Obj01404.h"
#include "../../matched/include/Obj02472.h"
#include "../../matched/include/Obj06456.h"
#include "../../matched/include/Obj00073.h"
#include "../../matched/include/Obj13963.h"
#include "../../matched/include/Obj10431.h"
#include "../../matched/include/Obj13964.h"
#include "../../matched/include/Obj06457.h"
#include "../../matched/include/Obj22930.h"
#include "../../matched/include/Obj05359.h"
#include "../../matched/include/Obj22931.h"
#include "../../matched/include/Obj01405.h"
#include "../../matched/include/Obj00265.h"
#include "../../matched/include/Obj00265.h"
#include "../../matched/include/Obj13965.h"
#include "../../matched/include/Obj22932.h"
#include "../../matched/include/Obj13966.h"
#include "../../matched/include/Obj22933.h"
#include "../../matched/include/Obj00208.h"
#include "../../matched/include/Obj13967.h"
#include "../../matched/include/Obj22934.h"
#include "../../matched/include/Obj22935.h"
#include "../../matched/include/Obj00911.h"
#include "../../matched/include/Obj22936.h"

struct BgTemplate;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
struct Obj;
struct Actor;
struct GfFont;
struct U16Vec;
struct Rec;
struct Ctx;
struct Comm;
struct Cmd;
struct WordSet;
struct BigObj;
struct SoundSys;
struct Strbuf;
struct Obj0203159C;
struct DispConfig;
struct DispVram;
struct Bank;
struct R;
struct Tcbl;
struct IcaAnime;
struct PrintSys;
struct Node;
struct Rec3;
struct S02031140;
struct S020315D4;
struct TaskMenu;
struct TaskMenuState;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Config { u32 w[8]; } Config;

typedef signed short s16;

typedef struct { int f00, f04, f08, f0c; } Row;

typedef struct { char pad00[0xc]; u16 heap; u16 pad0e; void *f10[11]; int pad3c; void *f40; void *f44; int pad48; void *f4C; int pad50; void *f54; char pad58[0x348-0x58]; int f348; } Object_021D4384;

typedef struct { char pad00[0x10]; void *f10[11]; } Object_021D44BC;

typedef int (*Fn)(int,u32 *);

typedef struct { u8 v[3]; } Triple;

typedef struct { u16 f00, f02, f04; u8 f06, f07; } Request;

typedef signed int     s32;

typedef struct Pair { int a, b; } Pair;

typedef struct { u16 f00; char *f04; void (*f08)(void); } Params;

typedef struct { char pad00[0x10]; void *f10[11]; } Object_021D4240;

typedef struct { char f00[8]; u16 f08, f0a; } Entry;

typedef struct { char pad00[0x64]; Entry f64[16]; } Object_021D50DC;

typedef struct { u32 v[4]; } Display;

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
extern void func_0204047C(int, u16);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_0201F7A8(void *, unsigned);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BUTTON_MAN_Delete(void *);
extern void func_02041B6C(u32);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(u32);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern void func_0201DD68(void);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void func_020403F4(u32 i);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int WIPE_SYS_EndCheck(void);
extern unsigned int ICA_ANIME_GetField24(const struct Ctx *p);
extern u32 GAME_COMM_GetKind(void *obj);
extern void WIPE_SYS_Start(void *, u32, u32, u32, u32, u32, u32);
extern void NET_WHPIPE_SetNotifyCallback(u32 callback, u32 value);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern int INTRUDE_COMM_GetRequestState(int a);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern int GAME_BEACON_GetNextNewLogIndex(int *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int INTRUDE_COMM_CountEventPeers(void *p);
extern int INTRUDE_COMM_GetRequesterStatus(int, int);
extern int BUTTON_MAN_UpdateSlots(void *);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void *GFL_NET_GetInitParam(void);
extern void *GFL_NET_GetScanResultMac(u32);
extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);
extern int func_020107FC(void *);
extern u32 GFL_NET_GetScanResult(u32 a);
extern u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(void *);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *);
extern void FIELD_SOUND_SYSTEM_StartRingtone(struct SoundSys *sys);
extern void func_02028A70(struct SoundSys *sys);
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void CLACT_VBlankSystem(void);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, u32);
extern void func_0204363C(u32);
extern void GX_DispOn(void);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void func_0201DD60(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_020056A0(u32, void *, u32);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern int GFL_NET_GetRunState(void);
extern void func_020355D8(u8);
extern void APP_TASKMENU_UpdateMenu(void *);
extern void CLACT_DrawSystem(void);
extern u32 WIH_DWC_PollStatus(void *);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_02040618(u32, u32, u32);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern u32 ICA_ANIME_GetUnk330(const struct Ctx *p);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
extern void TCBL_Destroy(struct S02031140 *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
void INTRUDE_COMM_VIEW_StoreCallback(u32 *p,u32 a);
void INTRUDE_COMM_VIEW_SetCallback(void *p, u32 a, int a2);
void INTRUDE_COMM_VIEW_SetupBackgrounds(void *a0);
void INTRUDE_COMM_VIEW_BuildRowList(int count, int *values, Object_021D4384 *p, Row *rows, const int *xs, const int *ys);
void INTRUDE_COMM_VIEW_RebuildRow(int i, Object_021D44BC *p, Row *row, const int *xs, const int *ys);
void INTRUDE_COMM_VIEW_DeleteRowSlot(u32 i,u32 p);
void INTRUDE_COMM_VIEW_ResetRowSlot(u32 i,u32 p);
void INTRUDE_COMM_VIEW_DeleteRows(char *p);
void INTRUDE_COMM_VIEW_InvokeCallback(int a,int b,u32 *p);
void INTRUDE_COMM_VIEW_BrightenPalette(u16 *p, const u16 *add, int count);
void INTRUDE_COMM_VIEW_CreateActors(char *p);
void INTRUDE_COMM_VIEW_CreateResources(char *p);
void INTRUDE_COMM_VIEW_InitMenu(char *p);
void INTRUDE_COMM_VIEW_DeleteResources(char *p);
void INTRUDE_COMM_VIEW_CheckExitRequest(char *p);
void INTRUDE_COMM_VIEW_BeginExit(char *p);
void INTRUDE_COMM_VIEW_StartExit(char *p);
void INTRUDE_COMM_VIEW_Noop(void);
void INTRUDE_COMM_VIEW_AnimateSelectedRow(char *p);
int INTRUDE_COMM_VIEW_SelectRow(int value, char *p);
void INTRUDE_COMM_VIEW_DrawRowText(int i, int value, int force, int mode, Object_021D4240 *p);
void INTRUDE_COMM_VIEW_UpdatePeerList(char *p);
void INTRUDE_COMM_VIEW_Update(char *p);
void INTRUDE_COMM_VIEW_InitStatusText(char *p);
void INTRUDE_COMM_VIEW_UpdateActorAnim(char *p);
void INTRUDE_COMM_VIEW_SetFoundPeerMac(char *p,u32 n);
void INTRUDE_COMM_VIEW_ClearFoundPeerMac(char *p);
void INTRUDE_COMM_VIEW_OnScanResult(char *p);
void INTRUDE_COMM_VIEW_StorePeerRecord(Object_021D50DC *p, const char *data, int value, int tag);
void INTRUDE_COMM_VIEW_TickPeerTimers(u8 *p);
u32 INTRUDE_COMM_VIEW_SumPeerTimers(u8 *p);
void INTRUDE_COMM_VIEW_VBlankHandler(void);
int INTRUDE_COMM_VIEW_Create(void *owner, void *unused, char *args);
int INTRUDE_COMM_VIEW_Main(void *a, void *b, void *c, char *p);
extern const Config d_021D5780, d_021D57A0, d_021D57C0, d_021D57E0, d_021D5800;
extern const Triple data_021D5708, data_021D5704, data_021D570C;
extern u16 data_021D5870[];
extern const Pair d_021D575C;
extern int d_021D5890[], d_021D5720[], d_021D5718[], d_021D5728[];
extern Row data_021D58E0[];
extern int data_021D5714[], data_021D5710[];
extern Row data_021D5840, data_021D5850, data_021D5860;
extern u32 data_021D58B0[], data_021D5740[];
extern const Display data_021D5770;







void INTRUDE_COMM_VIEW_StoreCallback(u32 *p,u32 a) {*p=a;}







void INTRUDE_COMM_VIEW_SetCallback(void *p, u32 a, int a2) {INTRUDE_COMM_VIEW_StoreCallback(p,a);}







void INTRUDE_COMM_VIEW_SetupBackgrounds(void *a0)
{
    Config a, b, c, d, e;
    a = d_021D5780;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&a), 0);
    func_020414AC(0);
    func_020409B4(0);
    func_0204047C(0, 0);
    func_02040588(0, 1);
    b = d_021D57A0;
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)(&b), 0);
    func_02040588(4, 1);
    func_020409B4(4);
    c = d_021D57C0;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&c), 0);
    BG_SYS_Init(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 32, 32, 17);
    func_020409B4(5);
    func_02040588(5, 1);
    d = d_021D57E0;
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)(&d), 0);
    func_02040588(6, 1);
    func_020409B4(6);
    e = d_021D5800;
    BG_SYS_InitBgLayer(7, (const struct BgTemplate *)(&e), 0);
    func_02040588(7, 1);
    func_020409B4(7);
}







void INTRUDE_COMM_VIEW_BuildRowList(int count, int *values, Object_021D4384 *p, Row *rows, const int *xs, const int *ys)
{
    int i, x, y;
    p->f348 = count;
    func_02049B40(23, 5, 4, 384, 32, p->heap);
    for (i = 0; i < 11; i++) {
        if (p->f10[i]) {
            BMP_WIN_ClearScreen(p->f10[i]);
            func_0201F7A8(p->f10[i], 2);
            BMP_WIN_Delete(p->f10[i]);
        }
        p->f10[i] = 0;
    }
    for (i = 0; i < count; i++) {
        p->f10[i] = (void *)BMP_WIN_Create(7, (u8)rows[i].f00, (u8)rows[i].f04, (u8)rows[i].f08, rows[i].f0c, 13, 0);
        BMP_Clear(BMP_WIN_GetBmp(p->f10[i]), 0);
        func_02045CAC(p->f44, (int)values[i], p->f54);
        if (xs) x = xs[i] - (func_0201D304(p->f54, (u32)p->f4C, 0) >> 1);
        else x = 0;
        if (ys) y = ys[i] - (func_0201D42C(p->f54, p->f4C) >> 1);
        else y = 0;
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(p->f10[i]), x, y, p->f54, p->f4C, 0x39e3);
        BMP_WIN_TransferChars(p->f10[i]);
        BMP_WIN_MakeScreen(p->f10[i]);
    }
    if (p->f40) BUTTON_MAN_Delete(p->f40);
    p->f40 = 0;
    func_02041B6C(7);
}







/*
 * lever: x initialized after construction lets its zero share the outgoing stack argument.
 */
void INTRUDE_COMM_VIEW_RebuildRow(int i, Object_021D44BC *p, Row *row, const int *xs, const int *ys)
{
    int x, y;
    if (p->f10[i]) {
        BMP_WIN_ClearScreen(p->f10[i]);
        func_0201F7A8(p->f10[i], 2);
        BMP_WIN_Delete(p->f10[i]);
        p->f10[i] = 0;
    }
    p->f10[i] = (void *)BMP_WIN_Create(7, (u8)row->f00, (u8)row->f04, (u8)row->f08, row->f0c, 13, 0);
    x = 0;
    BMP_Clear(BMP_WIN_GetBmp(p->f10[i]), 0);
    if (xs) x = xs[i] - (func_0201D304(((struct Obj01404 *)p)->f54, *(u32 *)&((struct Obj01404 *)p)->f4C, 0) >> 1);
    if (ys) y = ys[i] - (func_0201D42C(((struct Obj01404 *)p)->f54, ((struct Obj01404 *)p)->f4C) >> 1);
    else y = 0;
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(p->f10[i]), x, y, ((struct Obj01404 *)p)->f54, ((struct Obj01404 *)p)->f4C, 0x39e3);
    BMP_WIN_TransferChars(p->f10[i]);
    BMP_WIN_MakeScreen(p->f10[i]);
    func_02041B6C(7);
}







void INTRUDE_COMM_VIEW_DeleteRowSlot(u32 i,u32 p) {if(*(void **)(p+0x10+i*4)) {BMP_WIN_ClearScreen(*(void **)(p+0x10+i*4));func_0201F7A8(*(void **)(p+0x10+i*4),2);BMP_WIN_Delete(*(void **)(p+0x10+i*4));}*(void **)(p+0x10+i*4)=0;func_02041B6C(5);}







void INTRUDE_COMM_VIEW_ResetRowSlot(u32 i,u32 p) {if(*(void **)(p+0x10+i*4)) {BMP_WIN_ClearScreen(*(void **)(p+0x10+i*4));func_0201F7A8(*(void **)(p+0x10+i*4),2);BMP_WIN_Delete(*(void **)(p+0x10+i*4));}*(void **)(p+0x10+i*4)=0;func_02041B6C(7);}







/*
 * extent: Two zero padding bytes after the return, next function 021D4630.
 */
void INTRUDE_COMM_VIEW_DeleteRows(char *p)
{
    int i;
    char *q;
    if (((struct Obj02472 *)p)->f40) BUTTON_MAN_Delete(((struct Obj02472 *)p)->f40);
    *(int *)&((struct Obj02472 *)p)->f40 = 0;
    for (i = 0; i < 11; i++) {
        q = p + i * 4;
        if (((struct Obj06456 *)q)->f10) {
            BMP_WIN_ClearScreen(((struct Obj06456 *)q)->f10);
            func_02041B6C(5);
            func_0201F7A8(((struct Obj06456 *)q)->f10, 2);
            BMP_WIN_Delete(((struct Obj06456 *)q)->f10);
        }
        *(int *)&((struct Obj06456 *)q)->f10 = 0;
    }
    ((struct Obj02472 *)p)->f348 = 0;
}







void INTRUDE_COMM_VIEW_InvokeCallback(int a,int b,u32 *p) {if(b==0 && p[1]!=0) {if(((Fn)p[1])(a,p)==0)return;}}







void INTRUDE_COMM_VIEW_BrightenPalette(u16 *p, const u16 *add, int count)
{
    int i, j;
    for (i = 0; i < count; i++) {
        u16 *q = p + i * 16;
        for (j = 0; j < 16; j++) {
            u16 color = q[j];
            u16 r = color & 31;
            u16 g = (color & 0x3e0) >> 5;
            u16 b = (color & 0x7c00) >> 10;
            r += add[j];
            g += add[j];
            b += add[j];
            if (r > 31) r = 31;
            if (g > 31) g = 31;
            if (b > 31) b = 31;
            q[j] = r + (g << 5) + (b << 10);
        }
    }
}







void INTRUDE_COMM_VIEW_CreateActors(char *p)
{
    Triple x = data_021D5708;
    Triple y = data_021D5704;
    Triple z = data_021D570C;
    Request req;
    int i, a, b, c, d, e, f, g;
    i = 0;
    a = 0x37c;
    b = 0x378;
    c = 0x380;
    d = 0x390;
    e = 0x390;
    f = 0x390;
    g = 0x390;
    for (; i < 3; i++) {
        char *q;
        req.f00 = x.v[i]; req.f02 = y.v[i]; req.f04 = z.v[i];
        req.f06 = 1; req.f07 = 2;
        q = p + 4 * i;
        *(void **)(q + d) = CLACT_CreateActor((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, *(u32 *)(p + a), *(u32 *)(p + b), *(u32 *)(p + c), &req, 1, ((struct Obj00073 *)p)->fC);
        CLACT_SetActorAutoAnim(*(void **)(q + e), 0);
        CLACT_SetActorDrawEnable(*(void **)(q + f), 1);
        CLACT_SetActorObjMode(*(void **)(q + g), 1);
    }
    req.f00 = 128; req.f02 = 96; req.f04 = 15; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f39C = CLACT_CreateActor((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    CLACT_SetActorAutoAnim(((struct Obj00073 *)p)->f39C, 1);
    CLACT_SetActorDrawEnable(((struct Obj00073 *)p)->f39C, 1);
    CLACT_SetActorObjMode(((struct Obj00073 *)p)->f39C, 1);
    req.f00 = 128; req.f02 = 96; req.f04 = 18; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f3A0 = CLACT_CreateActor((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    CLACT_SetActorAutoAnim(((struct Obj00073 *)p)->f3A0, 1);
    CLACT_SetActorDrawEnable(((struct Obj00073 *)p)->f3A0, 0);
    CLACT_SetActorObjMode(((struct Obj00073 *)p)->f3A0, 1);
    req.f00 = 128; req.f02 = 96; req.f04 = 25; req.f06 = 0; req.f07 = 2;
    ((struct Obj00073 *)p)->f3A4 = CLACT_CreateActor((void *)*(u32 *)&((struct Obj00073 *)p)->f30C, ((struct Obj00073 *)p)->f37C, ((struct Obj00073 *)p)->f378, ((struct Obj00073 *)p)->f380, &req, 1, ((struct Obj00073 *)p)->fC);
    CLACT_SetActorAutoAnim(((struct Obj00073 *)p)->f3A4, 1);
    CLACT_SetActorDrawEnable(((struct Obj00073 *)p)->f3A4, 0);
    CLACT_SetActorObjMode(((struct Obj00073 *)p)->f3A4, 1);
}







/*
 * ABI: 02049990 argument 5 is u16: original truncates the value at 021D49B4/49D2.
 */
void INTRUDE_COMM_VIEW_CreateResources(char *p)
{
    u32 arc;
    void *resource;
    char *palette;
    ((struct Obj00073 *)p)->f54 = STRBUF_Create(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f58 = STRBUF_Create(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f50 = STRBUF_Create(200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f3C = (void *)BMP_WIN_Create(5, 16, 10, 10, 2, 13, 0);
    ((struct Obj00073 *)p)->f4C = GF_FONT_Create(23, 0, 0, 0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f44 = func_02045B38(0, 2, 23, ((struct Obj00073 *)p)->fC);
    arc = (u32)func_020490F4(29, ((struct Obj00073 *)p)->fC);
    func_02049B68((void *)arc, 0, 0, 0, 0, ((struct Obj00073 *)p)->fC);
    func_02049B68((void *)arc, 1, 4, 0, 0, ((struct Obj00073 *)p)->fC);
    resource = func_02049F78((void *)arc, 1, (u32)&palette, ((struct Obj00073 *)p)->fC);
    MI_CpuCopy8(((struct Obj13963 *)palette)->fC, p + 0x12c, 0xe0);
    MI_CpuCopy8(((struct Obj13963 *)palette)->fC, p + 0x20c, 0xe0);
    INTRUDE_COMM_VIEW_BrightenPalette((u16 *)(p + 0x20c), data_021D5870, 7);
    func_020307B0(resource);
    ((struct Obj00073 *)p)->f60 = func_02049740((void *)arc, 4, 4, 0, 0, ((struct Obj00073 *)p)->fC);
    func_02049990((void *)arc, 9, 4, 0, (u16)(((struct Obj00073 *)p)->f60), 0, 0, ((struct Obj00073 *)p)->fC);
    func_02049990((void *)arc, 15, 6, 0, (u16)(((struct Obj00073 *)p)->f60), 0, 0, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f37C = CLACT_RegisterCharacter((void *)arc, 5, 0, 1, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f378 = CLACT_RegisterPaletteEx((void *)arc, 3, 1, 0, 0, 10, ((struct Obj00073 *)p)->fC);
    *(int *)&((struct Obj00073 *)p)->f380 = CLACT_RegisterCellAnim((void *)arc, 7, 16, ((struct Obj00073 *)p)->fC);
    ARC_TOOL_DeleteHandle(arc);
    ((struct Obj00073 *)p)->f5C = func_0201F5DC((void *)5, 11, 0, ((struct Obj00073 *)p)->fC);
    func_02049B40(23, 5, 4, 384, 32, ((struct Obj00073 *)p)->fC);
    INTRUDE_COMM_VIEW_CreateActors(p);
}







void INTRUDE_COMM_VIEW_InitMenu(char *p)
{
    Pair pair = d_021D575C;
    INTRUDE_COMM_VIEW_BuildRowList(2, (int *)&pair, (Object_021D4384 *)p, (Row *)d_021D5890, (const int *)d_021D5720, (const int *)d_021D5718);
    ((struct Obj10431 *)p)->f40 = BUTTON_MAN_Create((u8 *)d_021D5728, (int)INTRUDE_COMM_VIEW_InvokeCallback, (int)p, ((struct Obj10431 *)p)->fC);
    ((struct Obj10431 *)p)->f4 = INTRUDE_COMM_VIEW_SelectRow;
    INTRUDE_COMM_VIEW_InitStatusText(p);
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_Update, 0x31b);
}







void INTRUDE_COMM_VIEW_DeleteResources(char *p)
{
    unsigned ranges;
    func_0201DD68();
    INTRUDE_COMM_VIEW_DeleteRows(p);
    func_02040DA8(5, 1, 0);
    ranges = ((struct Obj02472 *)p)->f5C;
    BG_SYS_DeleteHalf(5, (u16)ranges, (u16)(ranges >> 16));
    func_020403F4(5);
    func_020403F4(4);
    MSGDATA_Delete(((struct Obj02472 *)p)->f44);
    GF_FONT_Delete(((struct Obj02472 *)p)->f4C);
    STRBUF_Delete(((struct Obj02472 *)p)->f54);
    STRBUF_Delete(((struct Obj02472 *)p)->f50);
    STRBUF_Delete(((struct Obj02472 *)p)->f58);
    BMP_WIN_Delete(((struct Obj02472 *)p)->f3C);
}







void INTRUDE_COMM_VIEW_CheckExitRequest(char *p)
{
    if (WIPE_SYS_EndCheck()) {
        if (((struct Obj13964 *)p)->f8 == 1) {
            if (!GAME_COMM_GetKind((void *)ICA_ANIME_GetField24(((struct Obj13964 *)p)->f354)))
                INTRUDE_COMM_VIEW_SetCallback(p, 0, 0x341);
        } else {
            INTRUDE_COMM_VIEW_SetCallback(p, 0, 0x345);
        }
    }
}







/*
 * evidence: unlabelled ov014 Thumb setter 0x02178118 is filed separately.
 * extent: unit includes tail-call stub 0x021D4BDC and return stub 0x021D4BF0;
 *   two zero padding bytes at 0x021D4BF2 follow the intended code.
 */
void INTRUDE_COMM_VIEW_BeginExit(char *p)
{
    ((struct Obj06457 *)p)->f38C = 1;
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, ((struct Obj06457 *)p)->fC);
    NET_WHPIPE_SetNotifyCallback(0, 0);
    if (((struct Obj06457 *)p)->f8 == 1 && GAME_COMM_GetKind((void *)ICA_ANIME_GetField24(((struct Obj06457 *)p)->f354)))
        GAME_COMM_RequestExitNoCallback((struct Comm *)ICA_ANIME_GetField24(((struct Obj06457 *)p)->f354));
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_CheckExitRequest, 0x35e);
}







void INTRUDE_COMM_VIEW_StartExit(char *p)
{
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_BeginExit, 0x36f);
}







void INTRUDE_COMM_VIEW_Noop(void)
{
}






void INTRUDE_COMM_VIEW_AnimateSelectedRow(char *p)
{
    int i;
    Params args;
    void **base;
    i = ((struct Obj22930 *)p)->f35C;
    args.f00 = 0;
    args.f04 = p;
    args.f08 = (void (*)(void))INTRUDE_COMM_VIEW_StartExit;
    if (i == 3) i = 0;
    else if (i == 4) i = 1;
    base = (void **)(p + 0x390);
    CLACT_SetActorAutoAnim(base[i], 1);
    func_0204BA00(base[i], (const struct Cmd *)(&args));
    CLACT_RestartActorAnim(base[i]);
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_Noop, 0x390);
}






int INTRUDE_COMM_VIEW_SelectRow(int value, char *p)
{
    void *obj;
    obj = (void *)ICA_ANIME_GetField24(((struct Obj05359 *)p)->f354);
    ((struct Obj05359 *)p)->f35C = value;
    switch (value) {
    case 0:
    case 3:
        ((struct Obj22931 *)(*(char * *)&((struct Obj05359 *)p)->f344))->f28 = INTRUDE_COMM_GetRequestState((int)obj);
        ((struct Obj05359 *)p)->f8 = 0;
        GFL_USE_PlaySeDefaultVolume(0x73b);
        INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_AnimateSelectedRow, 0x3c4);
        break;
    case 1:
    case 4:
        ((struct Obj05359 *)p)->f8 = 1;
        GFL_USE_PlaySeDefaultVolume(0x73b);
        INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_AnimateSelectedRow, 0x3cd);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x73c);
        ((struct Obj05359 *)p)->f8 = 2;
        INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_AnimateSelectedRow, 0x3d3);
        break;
    }
    return 1;
}




void INTRUDE_COMM_VIEW_DrawRowText(int i, int value, int force, int mode, Object_021D4240 *p)
{
    if (p->f10[i] && !force) return;
    if (!p->f10[i])
        p->f10[i] = (void *)BMP_WIN_Create((int)7, (u8)data_021D58E0[i].f00, (u8)data_021D58E0[i].f04,
            (u8)data_021D58E0[i].f08, data_021D58E0[i].f0c, (int)13, (int)0);
    BMP_Clear(BMP_WIN_GetBmp(p->f10[i]), 0);
    if (mode) {
        func_02045CAC(((struct Obj01405 *)p)->f44, value, ((struct Obj01405 *)p)->f50);
        func_0201F250(((struct Obj01405 *)p)->f48, ((struct Obj01405 *)p)->f54, ((struct Obj01405 *)p)->f50);
    } else {
        func_02045CAC(((struct Obj01405 *)p)->f44, value, ((struct Obj01405 *)p)->f54);
    }
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(p->f10[i]), 0, 0, ((struct Obj01405 *)p)->f54, ((struct Obj01405 *)p)->f4C, 0x39e3);
    BMP_WIN_TransferChars(p->f10[i]);
    BMP_WIN_MakeScreen(p->f10[i]);
}



/*
 * lever: explicit if/else calls preserve the shared stack home and call ordering.
 * tables: original pool maps y=5714, x=5710, rows=5840/5860, extra=5850.
 */
void INTRUDE_COMM_VIEW_UpdatePeerList(char *p)
{
    int force = 0;
    int scratch = 0;
    int object, mode, count;
    object = ICA_ANIME_GetField24(((struct Obj00265 *)p)->f354);
    mode = INTRUDE_COMM_GetRequestState(object);
    if (!((struct Obj00265 *)p)->f374) {
        scratch = 0;
        if (GAME_BEACON_GetNextNewLogIndex(&scratch) != 30) ((struct Obj00265 *)p)->f374 = 1;
    }
    if (((struct Obj00265 *)p)->f36C != ((struct Obj00265 *)p)->f370) force = 1;
    if (((struct Obj00265 *)p)->f368 != ((struct Obj00265 *)p)->f364) force = 1;
    INTRUDE_COMM_VIEW_DrawRowText(4, 2, 0, 0, (Object_021D4240 *)p);
    INTRUDE_COMM_VIEW_DrawRowText(6, 4, 0, 0, (Object_021D4240 *)p);
    INTRUDE_COMM_VIEW_DrawRowText(8, 12, 0, 0, (Object_021D4240 *)p);
    if (mode == 0) {
        func_0201EFA4(((struct Obj00265 *)p)->f48, 0, ((struct Obj00265 *)p)->f36C, 2, 0, 1);
        INTRUDE_COMM_VIEW_DrawRowText(5, 3, force, 1, (Object_021D4240 *)p);
        if (((struct Obj00265 *)p)->f364 & 32) INTRUDE_COMM_VIEW_DrawRowText(7, 5, force, 1, (Object_021D4240 *)p);
        else INTRUDE_COMM_VIEW_DrawRowText(7, 6, force, 1, (Object_021D4240 *)p);
        if (((struct Obj00265 *)p)->f374) INTRUDE_COMM_VIEW_DrawRowText(9, 5, force, 1, (Object_021D4240 *)p);
        else INTRUDE_COMM_VIEW_DrawRowText(9, 6, force, 1, (Object_021D4240 *)p);
    } else {
        INTRUDE_COMM_VIEW_DeleteRowSlot(5, (u32)p); INTRUDE_COMM_VIEW_DeleteRowSlot(7, (u32)p); INTRUDE_COMM_VIEW_DeleteRowSlot(9, (u32)p);
    }
    if (mode == 2 && ((struct Obj00265 *)p)->f128 != INTRUDE_COMM_CountEventPeers((void *)object)) ((struct Obj00265 *)p)->f124 = 0;
    if (((struct Obj00265 *)p)->f124 != mode) {
        switch (mode) {
        case 0:
            CLACT_SetActorDrawEnable(((struct Obj00265 *)p)->f3A4, 0);
            INTRUDE_COMM_VIEW_ResetRowSlot(10, (u32)p);
            func_02045CAC(((struct Obj00265 *)p)->f44, 0, ((struct Obj00265 *)p)->f54);
            INTRUDE_COMM_VIEW_RebuildRow(0, (Object_021D44BC *)p, &data_021D5840, data_021D5710, data_021D5714);
            break;
        case 1:
            CLACT_SetActorDrawEnable(((struct Obj00265 *)p)->f3A4, 0);
            INTRUDE_COMM_VIEW_ResetRowSlot(10, (u32)p);
            func_02045CAC(((struct Obj00265 *)p)->f44, 15, ((struct Obj00265 *)p)->f54);
            INTRUDE_COMM_VIEW_RebuildRow(0, (Object_021D44BC *)p, &data_021D5860, data_021D5710, data_021D5714);
            break;
        case 2:
            count = INTRUDE_COMM_CountEventPeers((void *)object);
            ((struct Obj00265 *)p)->f128 = count;
            CLACT_SetActorDrawEnable(((struct Obj00265 *)p)->f3A4, 0);
            INTRUDE_COMM_VIEW_ResetRowSlot(10, (u32)p);
            func_0201EFA4(((struct Obj00265 *)p)->f48, 0, count, 1, 0, 1);
            func_02045CAC(((struct Obj00265 *)p)->f44, 16, ((struct Obj00265 *)p)->f50);
            func_0201F250(((struct Obj00265 *)p)->f48, ((struct Obj00265 *)p)->f54, ((struct Obj00265 *)p)->f50);
            INTRUDE_COMM_VIEW_RebuildRow(0, (Object_021D44BC *)p, &data_021D5860, data_021D5710, data_021D5714);
            break;
        case 3:
            func_02045CAC(((struct Obj00265 *)p)->f44, 17, ((struct Obj00265 *)p)->f54);
            INTRUDE_COMM_VIEW_RebuildRow(0, (Object_021D44BC *)p, &data_021D5860, data_021D5710, data_021D5714);
            if (INTRUDE_COMM_GetRequesterStatus(object, *(int *)&((struct Obj00265 *)p)->f54)) {
                INTRUDE_COMM_VIEW_RebuildRow(10, (Object_021D44BC *)p, &data_021D5850, 0, 0);
                CLACT_SetActorDrawEnable(((struct Obj00265 *)p)->f3A4, 1);
            }
            break;
        }
        ((struct Obj00265 *)p)->f124 = mode;
    }
    func_02041B6C(7);
}



void INTRUDE_COMM_VIEW_Update(char *p) {if(WIPE_SYS_EndCheck())BUTTON_MAN_UpdateSlots(((struct Obj00265 *)p)->f40);INTRUDE_COMM_VIEW_UpdateActorAnim(p);INTRUDE_COMM_VIEW_UpdatePeerList(p);}



/*
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 */
void INTRUDE_COMM_VIEW_InitStatusText(char *p) {void *t;t=STRBUF_Create(100,*(u16 *)(p+12));*(void **)(p+0x328)=t;func_02045CAC(*(void **)(p+0x44),9,t);*(u16 *)(p+0x32c)=0x39e3;*(u32 *)(p+0x330)=1;STRBUF_Delete(*(void **)(p+0x328));}



/*
 * extent: zero padding at 0x021D50B2; next function at 0x021D50B4.
 */
void INTRUDE_COMM_VIEW_UpdateActorAnim(char *p)
{
    switch (INTRUDE_COMM_GetRequestState(ICA_ANIME_GetField24(((struct Obj00265 *)p)->f354))) {
    case 0:
    case 1:
        if (CLACT_GetActorAnimSeq(((struct Obj00265 *)p)->f390) == 20) {
            CLACT_SetActorAutoAnim(((struct Obj00265 *)p)->f390, 0);
            CLACT_SetActorAnimSeq(((struct Obj00265 *)p)->f390, 12);
        }
        break;
    case 2:
    case 3:
        if (CLACT_GetActorAnimSeq(((struct Obj00265 *)p)->f390) == 12) {
            CLACT_SetActorAutoAnim(((struct Obj00265 *)p)->f390, 1);
            CLACT_SetActorAnimSeq(((struct Obj00265 *)p)->f390, 20);
        }
        break;
    }
}



void INTRUDE_COMM_VIEW_SetFoundPeerMac(char *p,u32 n) {void *q;GFL_NET_GetInitParam();q=GFL_NET_GetScanResultMac(n);((struct Obj22932 *)(*(char * *)&((struct Obj13965 *)p)->f344))->f10=2;MI_CpuCopy8(q,*(char * *)&((struct Obj13965 *)p)->f344+20,6);}


void INTRUDE_COMM_VIEW_ClearFoundPeerMac(char *p) {u8 buf[6]={0};GFL_NET_GetInitParam();((struct Obj22933 *)(*(char * *)&((struct Obj13966 *)p)->f344))->f10=1;MI_CpuCopy8(buf,*(char * *)&((struct Obj13966 *)p)->f344+20,6);}


void INTRUDE_COMM_VIEW_OnScanResult(char *p)
{
    int index;
    void *record, *text;
    index = func_020107FC((void *)GAME_DATA_GetField1A0(((struct Obj00208 *)p)->f350));
    if (index != -1) {
        record = (void *)GFL_NET_GetScanResult(index);
        text = STRBUF_Create(200, ((struct Obj00208 *)p)->fC);
        STRBUF_SetStringN(text, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(record), 8);
        if (!CLACT_GetActorDrawEnable(((struct Obj00208 *)p)->f3A0)) {
            STRBUF_SetStringN(((struct Obj00208 *)p)->f58, COMM_PLAYER_SUPPORT_GetRecordFieldPtr(record), 8);
            BMP_Clear(BMP_WIN_GetBmp(((struct Obj00208 *)p)->f3C), 0);
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00208 *)p)->f3C), 0, 0, ((struct Obj00208 *)p)->f58, ((struct Obj00208 *)p)->f4C, 0x39e3);
            BMP_WIN_TransferChars(((struct Obj00208 *)p)->f3C);
            BMP_WIN_MakeScreen(((struct Obj00208 *)p)->f3C);
            CLACT_SetActorDrawEnable(((struct Obj00208 *)p)->f3A0, 1);
            func_02041B6C(5);
            INTRUDE_COMM_VIEW_SetFoundPeerMac(p, index);
        }
        STRBUF_Delete(text);
        FIELD_SOUND_SYSTEM_StartRingtone((struct SoundSys *)GAME_DATA_GetBgmInfo(((struct Obj00208 *)p)->f350));
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f39C) == 15)
            CLACT_SetActorAnimSeq(((struct Obj00208 *)p)->f39C, 16);
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f394) == 11) {
            CLACT_SetActorAutoAnim(((struct Obj00208 *)p)->f394, 1);
            CLACT_SetActorAnimSeq(((struct Obj00208 *)p)->f394, 19);
        }
    } else {
        func_02028A70((struct SoundSys *)GAME_DATA_GetBgmInfo(((struct Obj00208 *)p)->f350));
        CLACT_SetActorDrawEnable(((struct Obj00208 *)p)->f3A0, 0);
        BMP_Clear(BMP_WIN_GetBmp(((struct Obj00208 *)p)->f3C), 0);
        BMP_WIN_TransferChars(((struct Obj00208 *)p)->f3C);
        INTRUDE_COMM_VIEW_ClearFoundPeerMac(p);
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f394) == 19) {
            CLACT_SetActorAutoAnim(((struct Obj00208 *)p)->f394, 0);
            CLACT_SetActorAnimSeq(((struct Obj00208 *)p)->f394, 11);
        }
        if (CLACT_GetActorAnimSeq(((struct Obj00208 *)p)->f39C) == 16)
            CLACT_SetActorAnimSeq(((struct Obj00208 *)p)->f39C, 15);
    }
}


/*
 * extent: zero padding at 0x021D530E; next function at 0x021D5310.
 */
void INTRUDE_COMM_VIEW_StorePeerRecord(Object_021D50DC *p, const char *data, int value, int tag)
{
    int i;
    if (value >= 20 && value <= 27) {
        for (i = 0; i < 16; i++) {
            if (p->f64[i].f08 && !func_0203EFC8((const u8 *)p->f64[i].f00, (const u8 *)(data + 4), 6)) {
                p->f64[i].f08 = 600;
                p->f64[i].f0a = tag;
                return;
            }
        }
        for (i = 0; i < 16; i++) {
            if (!p->f64[i].f08) {
                MI_CpuCopy8(data + 4, p->f64[i].f00, 6);
                p->f64[i].f08 = 600;
                p->f64[i].f0a = tag;
                return;
            }
        }
    }
}


void INTRUDE_COMM_VIEW_TickPeerTimers(u8 *p) { int i; for(i=0;i<16;i++) if(*(u16 *)(p+i*12+108)) --*(u16 *)(p+i*12+108); }


u32 INTRUDE_COMM_VIEW_SumPeerTimers(u8 *p) { int i; int sum; sum=0; for(i=0;i<16;i++) if(*(u16 *)(p+i*12+108)) sum+=*(u16 *)(p+i*12+110); return sum; }


/*
 * leaf: root-claimed sole callback witness for INTRUDE_COMM_VIEW_Create.
 */
void INTRUDE_COMM_VIEW_VBlankHandler(void)
{
    CLACT_VBlankSystem();
}


/*
 * volatile: 021D53BA reads hardware DISPCNT, 021D53C0 writes the update.
 * ABI: 0203159C leaves the allocator result in r0 (020315BC/15C0); caller uses it.
 */
int INTRUDE_COMM_VIEW_Create(void *owner, void *unused, char *args)
{
    char *p;
    Display display;
    GFL_HEAP_CreateChildHeap(1, 31, 0x18000);
    p = PROCSYS_AllocProcWork(owner, 0x3a8, 31);
    MI_CpuFill8(p, 0, 0x3a8);
    ((struct Obj00073 *)p)->fC = 31;
    ((struct Obj00073 *)p)->f350 = ((struct Obj13967 *)args)->f4;
    ((struct Obj00073 *)p)->f354 = ((struct Obj13967 *)args)->f0;
    func_0204363C(1);
    *(volatile u32 *)0x04001000 |= 0x10000;
    GX_DispOn();
    BG_SYS_Create(((struct Obj00073 *)p)->fC);
    BMP_WIN_Init(((struct Obj00073 *)p)->fC);
    func_0201DD60();
    BG_SYS_SetVramBanks((const struct DispVram *)data_021D58B0);
    display = data_021D5770;
    func_0203FC28((struct DispConfig *)(&display));
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    CLACT_InitSystem((const struct Cfg *)data_021D5740, (u32)data_021D58B0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f30C = CLACT_CreateUnit(40, 0, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f310 = func_020056A0((u32)INTRUDE_COMM_VIEW_VBlankHandler, p, 0);
    INTRUDE_COMM_VIEW_SetupBackgrounds(p);
    INTRUDE_COMM_VIEW_CreateResources(p);
    ((struct Obj00073 *)p)->f48 = WORDSET_Create(11, 200, ((struct Obj00073 *)p)->fC);
    ((struct Obj00073 *)p)->f31C = TCBL_Create(((struct Obj00073 *)p)->fC, ((struct Obj00073 *)p)->fC, 1, 0);
    ((struct Obj00073 *)p)->f320 = PRINTSYS_QUE_Create((void *)(((struct Obj00073 *)p)->fC));
    ((struct Obj00073 *)p)->f340 = APP_TASKMENU_RES_Create(5, 13, *(u32 *)&((struct Obj00073 *)p)->f4C, ((struct Obj00073 *)p)->f320, ((struct Obj00073 *)p)->fC);
    func_0207D63C((void *)0x04001050, 4, 1, 15, 4);
    WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, ((struct Obj00073 *)p)->fC);
    BG_SYS_SetSubVisiblePlanes(31);
    INTRUDE_COMM_VIEW_SetCallback(p, (u32)INTRUDE_COMM_VIEW_InitMenu, 0x6cb);
    *(char * *)&((struct Obj00073 *)p)->f344 = args;
    GFL_NET_GetInitParam();
    ((struct Obj22934 *)(*(char * *)&((struct Obj00073 *)p)->f344))->f10 = 1;
    ((struct Obj22935 *)(*(char * *)&((struct Obj00073 *)p)->f344))->fC = ((struct Obj00073 *)p)->f350;
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00073 *)p)->fC);
    if (GFL_NET_GetRunState()) NET_WHPIPE_SetNotifyCallback((u32)INTRUDE_COMM_VIEW_StorePeerRecord, (u32)p);
    func_020355D8(1);
    return 1;
}


/*
 * extent: two-byte zero alignment at 021D55FA, then next labelled function.
 */
int INTRUDE_COMM_VIEW_Main(void *a, void *b, void *c, char *p)
{
    int result = 1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)(p);
        result = 0;
    }
    if (((struct Obj00208 *)p)->f324) APP_TASKMENU_UpdateMenu(((struct Obj00208 *)p)->f324);
    if (((struct Obj00208 *)p)->f8 != 1) INTRUDE_COMM_VIEW_OnScanResult(p);
    INTRUDE_COMM_VIEW_TickPeerTimers((unsigned char *)p);
    CLACT_DrawSystem();
    if (GFL_NET_GetRunState()) {
        ((struct Obj00208 *)p)->f368 = ((struct Obj00208 *)p)->f364;
        ((struct Obj00208 *)p)->f364 = WIH_DWC_PollStatus((void *)GAME_DATA_GetField1A0(((struct Obj00208 *)p)->f350));
        ((struct Obj00208 *)p)->f370 = ((struct Obj00208 *)p)->f36C;
        ((struct Obj00208 *)p)->f36C = INTRUDE_COMM_VIEW_SumPeerTimers((u8 *)p);
    }
    TCBL_Main(((struct Obj00208 *)p)->f31C);
    PRINTSYS_QUE_Main(((struct Obj00208 *)p)->f320);
    func_02040618(4, 3, ((struct Obj00208 *)p)->f358);
    ((struct Obj00208 *)p)->f358 = ((struct Obj00208 *)p)->f358 - 1;
    if (WIPE_SYS_EndCheck() && ((struct Obj00208 *)p)->f38C == 0) GAMESYSTEM_TryStartAutoComm(((struct Obj00208 *)p)->f354);
    if (WIPE_SYS_EndCheck() && ICA_ANIME_GetUnk330(((struct Obj00208 *)p)->f354)) {
        ((struct Obj00208 *)p)->f8 = 2;
        result = 1;
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
    }
    return result;
}


/*
 * function: INTRUDE_COMM_VIEW_Exit
 * address: 0x021D55FC
 * extent: intended code ends 021D5704; remaining handed extent is rodata.
 * leaf: callback blocker of INTRUDE_COMM_VIEW_Main.
 */
int INTRUDE_COMM_VIEW_Exit(void *a, void *b, char *out, char *p)
{
    int i;
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) NET_WHPIPE_SetNotifyCallback(0, 0);
    INTRUDE_COMM_VIEW_DeleteResources(p);
    ((struct Obj22936 *)out)->f20 = ((struct Obj00911 *)p)->f8;
    TCBL_Destroy(((struct Obj00911 *)p)->f31C);
    func_020403F4(5);
    PRINTSYS_QUE_Clear(((struct Obj00911 *)p)->f320);
    PRINTSYS_QUE_Delete(((struct Obj00911 *)p)->f320);
    for (i = 0; i < 3; i++) CLACT_DeleteActor(*(void **)(p + i * 4 + 0x390));
    CLACT_DeleteActor(((struct Obj00911 *)p)->f39C);
    CLACT_DeleteActor(((struct Obj00911 *)p)->f3A0);
    CLACT_DeleteActor(((struct Obj00911 *)p)->f3A4);
    CLACT_ReleasePalette((u32)(((struct Obj00911 *)p)->f378));
    CLACT_ReleaseCharacter((u32)(((struct Obj00911 *)p)->f37C));
    CLACT_ReleaseCellAnim((u32)(((struct Obj00911 *)p)->f380));
    func_02030EAC(((struct Obj00911 *)p)->f310);
    CLACT_DeleteUnit(((struct Obj00911 *)p)->f30C);
    CLACT_ExitSystem();
    if (((struct Obj00911 *)p)->f318) PRINTSYS_PrintStreamDelete(((struct Obj00911 *)p)->f318);
    WORDSET_DeleteStrbufED04(((struct Obj00911 *)p)->f48);
    if (((struct Obj00911 *)p)->f324) {
        APP_TASKMENU_CloseMenu(((struct Obj00911 *)p)->f324);
        ((struct Obj00911 *)p)->f324 = 0;
    }
    if (((struct Obj00911 *)p)->f314) BMP_WIN_Delete(((struct Obj00911 *)p)->f314);
    APP_TASKMENU_RES_Delete(((struct Obj00911 *)p)->f340);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    func_020315D4(a);
    func_020306F0(31);
    return 1;
}
