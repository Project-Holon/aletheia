/*
 * file:     unit_021B6100.c
 * unit:     yes
 * function: func_021B6100, func_021B6174, func_021B6250, func_021B6278, func_021B6348, func_021B6390, func_021B63AC, func_021B6460, func_021B6498, func_021B64C0, func_021B64D0, func_021B6678, func_021B66BC, func_021B6794, func_021B67A4, func_021B6828, func_021B6850, func_021B688C, func_021B68B0, func_021B68C8, func_021B69F8, func_021B6A64, func_021B6AAC, func_021B6B0C, func_021B6B54, func_021B6B6C, func_021B6BA0, func_021B6BCC, func_021B6BF8, func_021B6C84, func_021B6CC0, func_021B6FB4, func_021B6FDC, func_021B70D8, func_021B7128, func_021B71B8, func_021B71C4, func_021B7378, func_021B7438, func_021B7448, func_021B7460, func_021B74D8, func_021B74F8, func_021B7568, func_021B7590, func_021B75B0, func_021B75BC, func_021B75C8, func_021B75D4
 * address:  0x021B6100
 * region:   ov173
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   TCBL_Create 0x0203101C arm
 *   func_021B7ADC 0x021B7ADC thumb ov173
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_021B7B60 0x021B7B60 thumb ov173
 *   func_021B7B8C 0x021B7B8C thumb ov173
 *   func_021B7C00 0x021B7C00 thumb ov173
 *   func_021B8110 0x021B8110 thumb ov173
 *   func_021B815C 0x021B815C thumb ov173
 *   func_021B817C 0x021B817C thumb ov173
 *   CLACT_DrawSystem 0x0204A600 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   d_021B81FC 0x021B81FC data a4
 *   d_021B81EC 0x021B81EC data a4
 *   func_021B7EB0 0x021B7EB0 thumb ov173
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   func_020490F4  0x020490F4  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   func_0204363C  0x0204363C  arm
 *   func_020056A0  0x020056A0  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_021B7A00  0x021B7A00  thumb  ov173
 *   func_021B7C44  0x021B7C44  thumb  ov173
 *   func_021B8040  0x021B8040  thumb  ov173
 *   func_021B7C7C 0x021B7C7C thumb ov173
 *   func_021B7694 0x021B7694 thumb ov173
 *   func_02030EAC 0x02030EAC arm
 *   func_021B7908 0x021B7908 thumb ov173
 *   func_020419E4 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   d_02FE0000 0x02FE0000 data a4
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040588 0x02040588 arm
 *   func_02040B94 0x02040B94 arm
 *   d_021B8280 0x021B8280 data a4
 *   d_021B82F0 0x021B82F0 data a4
 *   d_021B8330 0x021B8330 data a4
 *   d_021B8290 0x021B8290 data a4
 *   d_021B82B0 0x021B82B0 data a4
 *   d_021B82D0 0x021B82D0 data a4
 *   d_021B8310 0x021B8310 data a4
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_021B8420 0x021B8420 data a4
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02028590 0x02028590 thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021B7F50 0x021B7F50 thumb ov173
 *   func_021B80EC 0x021B80EC thumb ov173
 *   func_021B80A4 0x021B80A4 thumb ov173
 *   func_021B80C4 0x021B80C4 thumb ov173
 *   func_021B7F64 0x021B7F64 thumb ov173
 *   func_021B7FD0 0x021B7FD0 thumb ov173
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   func_021B81B0 0x021B81B0 thumb ov173
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   d_021B8228 0x021B8228 data a4
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   func_021B7968 0x021B7968 thumb ov173
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045CAC 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_02017E88 0x02017E88 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021B78CC 0x021B78CC thumb ov173
 *   func_0201EE84 0x0201EE84 thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   WAZA_TOOL_IsAlwaysHit 0x0201C1F4 thumb
 *   func_021B79E0 0x021B79E0 thumb ov173
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   d_021B8350 0x021B8350 data a4
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStreamCallBack 0x0201CD10 thumb
 *   func_020409B4 0x020409B4 arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   KEY_GetCont  0x0203630C  arm  arm9
 */
#include "../../matched/include/Obj06563.h"
#include "../../matched/include/Obj24149.h"
#include "../../matched/include/Obj06564.h"
#include "../../matched/include/Obj00362.h"
#include "../../matched/include/Obj00180.h"
#include "../../matched/include/Obj05449.h"
#include "../../matched/include/G_021B81EC.h"
#include "../../matched/include/Obj24150.h"
#include "../../matched/include/Obj24151.h"
#include "../../matched/include/Obj04557.h"
#include "../../matched/include/Obj06565.h"
#include "../../matched/include/Obj24152.h"
#include "../../matched/include/Obj24153.h"
#include "../../matched/include/Obj24154.h"
#include "../../matched/include/Obj24155.h"
#include "../../matched/include/Obj24156.h"
#include "../../matched/include/Obj14313.h"
#include "../../matched/include/Obj08264.h"
#include "../../matched/include/Obj05450.h"
#include "../../matched/include/Obj24157.h"
#include "../../matched/include/Obj24158.h"
#include "../../matched/include/Obj24159.h"
#include "../../matched/include/Obj10668.h"
#include "../../matched/include/Obj08265.h"
#include "../../matched/include/Obj00837.h"
#include "../../matched/include/Obj24161.h"
#include "../../matched/include/Obj24162.h"
#include "../../matched/include/Obj24164.h"
#include "../../matched/include/Obj00544.h"
#include "../../matched/include/Obj24172.h"
#include "../../matched/include/Obj24173.h"
#include "../../matched/include/Obj10669.h"
#include "../../matched/include/Obj14314.h"
#include "../../matched/include/Obj24174.h"
#include "../../matched/include/Obj03858.h"
#include "../../matched/include/Obj14315.h"
#include "../../matched/include/Obj24177.h"

struct Obj0203159C;
struct GfFont;
struct Tcbl;
struct PrintSys;
struct S02031140;
struct S020315D4;
struct MsgBank;
struct R;
struct TaskMenuState;
struct U16Vec;
struct Node;
struct DispVram;
struct Descriptor;
struct CharBuf;
struct WordSet;
struct Rec;
struct Sound;
struct Ctx;
struct Rec3;
struct TaskMenu;
struct TaskMenuTmpl;
struct StrObj;
struct Cfg;
struct Obj;
struct ScanContext;
struct Slot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u32 id,value;} Row;

typedef enum { FLAGS_OFFSET=0x3ff8, OFFSET_FORCE_UNSIGNED=0xffffffffu } SharedOffset;

struct DispConfig {u32 unk_00,unk_04,unk_08,unk_0c;};

struct BgTemplate {u32 unk_00,unk_04,bufSize,unk_0c;u8 unk_10,unk_11,unk_12,unk_13;u32 unk_14;u8 unk_18,unk_19,unk_1a,unk_1b;u32 unk_1c;};

typedef struct { u32 a,b,c,d,e,f,g; } Entry;

typedef signed int     s32;

typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 a,b,c,d; } Descriptor;

typedef int (*Callback)(u8 *);

typedef struct { Callback a,b; } Pair;

typedef signed short s16;

struct ScanOwner { u8 pad[16]; u16 *table; };

struct ScanContext { struct ScanOwner *owner; };

typedef signed char s8;

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_021B7ADC(unsigned char *p, u32 idx, int unused);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern int func_021B7B60(u8 *p);
extern int func_021B7B8C(char *p);
extern int func_021B7C00(void *);
extern int func_021B8110(u8 *p);
extern int func_021B815C(char *p);
extern int func_021B817C(char *p);
extern void CLACT_DrawSystem(void);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Destroy(struct S02031140 *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_021B7EB0(char *p, int flag);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_0204363C(u32 swap);
extern u32 func_020056A0(void (*cb)(void), void *p, int n);
extern void ARC_TOOL_DeleteHandle(u32 a);
extern void func_021B7A00(char *p, void *arg);
extern void func_021B7C44(u8 *p);
extern void func_021B8040(u8 *p);
extern int func_021B7C7C(int *);
extern void func_021B7694(u8 *p);
extern void func_02030EAC(struct Node *n);
extern void func_021B7908(char *);
extern void func_020419E4(void);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203F8F4(u16);
extern void BMP_WIN_Init(u16);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32,const struct BgTemplate *,u32);
extern void func_020414EC(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void func_020403F4(unsigned int);
extern void func_0203F9B4(void);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049EF4(void *p, u32 a, u32 b, void **out, u16 d);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_020307B0(void *p);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern u32 func_02028590(int,int,int,int);
extern int APP_KEYCURSOR_Delete(int);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 WIPE_SYS_EndCheck(void);
extern u8 func_020260E0(struct Sound *);
extern int func_02025DE8(struct Sound *);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int func_021B7F50(char *);
extern int func_021B80EC(char *,u16);
extern int func_021B80A4(char *,u16);
extern int func_021B80C4(u8 *p, u16 n);
extern void func_021B7F64(char *);
extern void func_021B7FD0(u8 *,int);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_021B81B0(int);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void APP_TASKMENU_UpdateMenu(u32);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void POKE_TOOL_SetPartyValue(void *, u32, u32);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);
extern void func_021B7968(char *);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u32 PRINTSYS_PrintColor(void *, s16, s16, void *, void *, u16);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void *POKE_TOOL_GetBoxParam(void *);
extern u32 func_02017E88(void *,u32,u32);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void func_021B78CC(u8 *p, u16 id, u16 i);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void *BMP_MENUWORK_Create(u32, u32);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 BMP_MENUWORK_Delete(void *p);
extern u32 WAZA_TOOL_GetParam(u16,u32);
extern u32 WAZA_TOOL_IsAlwaysHit(u16);
extern void func_021B79E0(u8 *p, u16 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern unsigned int func_02017E1C(void *, unsigned int, unsigned int);
extern void func_0201F73C(void *, int, int, int);
extern signed char func_02012FFC(void);
extern struct Rec *PRINTSYS_PrintStreamCallBack(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void func_020409B4(u32);
extern void func_0201F7A8(void *desc, u32 kind);
extern int GFL_USE_IsAnySeBusy(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned int, unsigned int);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
int func_021B6100(struct Obj0203159C *obj, int unused, u8 *input);
int func_021B6174(void *unused0,u32 *state,void *unused2,u8 *p);
int func_021B6250(void *p,u32 a,u32 b,char *ctx);
void func_021B6278(u8 *p);
void func_021B6348(u8 *p);
void func_021B6390(int *p);
void func_021B63AC(u8 *p);
void func_021B6460(char *p);
void func_021B6498(void *unused,char *p);
void func_021B64C0(void);
void func_021B64D0(void);
void func_021B6678(void);
void func_021B66BC(u8 *p, u8 *q);
int func_021B6794(int *p);
void func_021B67A4(u8 *p);
void func_021B6828(char *p);
void func_021B6850(char *p);
void func_021B688C(char *p);
int func_021B68B0(int *p);
int func_021B68C8(char *p);
int func_021B69F8(char *p);
int func_021B6A64(u8 *p);
int func_021B6AAC(u8 *p);
int func_021B6B0C(char **p);
int func_021B6B54(int *p);
int func_021B6B6C(char *p);
int func_021B6BA0(char *p);
void func_021B6BCC(char *p);
u32 func_021B6BF8(char *p, int index, u32 font, u16 w, int align, u8 y);
void func_021B6C84(char *p,u32 idx,u32 a,u32 b,u8 c);
void func_021B6CC0(char *p);
u32 func_021B6FB4(struct ScanContext *p);
void func_021B6FDC(char *p,u8 first,u8 row);
void func_021B70D8(char *p);
void func_021B7128(char *p);
void func_021B71B8(char *p);
void func_021B71C4(char *p,int move);
void func_021B7378(char *p, u32 kind);
u16 func_021B7438(char **p);
unsigned short func_021B7448(int *p);
void func_021B7460(char *p, u32 kind);
void func_021B74D8(char *p);
int func_021B74F8(unsigned int state);
u8 func_021B7568(void ***p);
int func_021B7590(u8 *p);
int func_021B75B0(char *p);
int func_021B75C8(char *p);
extern struct G_021B81EC d_021B81EC[];
extern const Row d_021B81FC[];
extern u8 d_02FE0000[];
extern const struct DispConfig d_021B8280;
extern const struct BgTemplate d_021B82F0,d_021B8330,d_021B8290,d_021B82B0,d_021B82D0,d_021B8310;
extern const Entry d_021B8420[];
extern Pair d_021B8228[];
extern const u32 d_021B8350[][11];




int func_021B6100(struct Obj0203159C *obj, int unused, u8 *input)
{
    u8 *p;
    GFL_HEAP_CreateChildHeap(1,79,0x50000);
    p=PROCSYS_AllocProcWork(obj,0x228,79);
    MI_CpuFill8(p,0,0x228);
    *(u8 * *)&((struct Obj06563 *)p)->f0=input;
    ((struct Obj06563 *)p)->f60=(u32)GF_FONT_Create(23,0,0,0,79);
    ((struct Obj06563 *)p)->f64=(u32)TCBL_Create(79,79,32,32);
    func_021B63AC(p);
    func_021B7ADC(p,(u8)(((struct Obj24149 *)(*(u8 * *)&((struct Obj06563 *)p)->f0))->f14),3);
    ((struct Obj06563 *)p)->f1B0=1;
    GFL_NET_RestartWithDefaultTimeout(1,79);
    return 1;
}




/*
 * extent: final 2 bytes are alignment padding
 */
int func_021B6174(void *unused0,u32 *state,void *unused2,u8 *p)
{
    switch(*state) {
    case 0: *state=func_021B68B0((int *)p);break;
    case 1: *state=func_021B68C8((char *)p);break;
    case 2: *state=func_021B69F8((char *)p);break;
    case 3: *state=func_021B6A64(p);break;
    case 4: *state=func_021B6AAC(p);break;
    case 5: *state=func_021B6B0C((char **)p);break;
    case 6: *state=func_021B6B54((int *)p);break;
    case 7: *state=func_021B6B6C((char *)p);break;
    case 8: *state=func_021B6BA0((char *)p);break;
    case 9: return 1;
    case 10: *state=func_021B7B60(p);break;
    case 11: *state=func_021B7B8C((char *)p);return 0;
    case 12: *state=func_021B7C00(p);return 0;
    case 13: *state=func_021B8110(p);break;
    case 14: *state=func_021B815C((char *)p);break;
    case 15: *state=func_021B817C((char *)p);break;
    }
    func_021B6390((int *)p);
    CLACT_DrawSystem();
    TCBL_Main(((struct Obj06564 *)p)->f64);
    PRINTSYS_QUE_Main(((struct Obj06564 *)p)->f218);
    return 0;
}




int func_021B6250(void *p,u32 a,u32 b,char *ctx) { func_021B6460(ctx); TCBL_Destroy(((struct Obj00362 *)ctx)->f64); GF_FONT_Delete(((struct Obj00362 *)ctx)->f60); func_020315D4(p); func_020306F0(79); return 1; }




void func_021B6278(u8 *p)
{
    int i;
    const Row *r;
    u8 *q;
    ((struct Obj00180 *)p)->f218=PRINTSYS_QUE_Create((void *)79);
    ((struct Obj00180 *)p)->f1DC=APP_TASKMENU_RES_Create(4,10,((struct Obj00180 *)p)->f60,((struct Obj00180 *)p)->f218,79);
    for(i=0;i<2;i++) {
        r=&d_021B81FC[i];q=p+i*12;
        ((struct Obj05449 *)q)->f1E4=func_02045EC0(((struct Obj00180 *)p)->f44,r->id);
        ((struct Obj05449 *)q)->f1E8=14819;
        ((struct Obj05449 *)q)->f1EC=r->value;
    }
    for(i=0;i<2;i++) {
        r=&((Row *)d_021B81EC)[i];q=p+i*12;
        ((struct Obj05449 *)q)->f1FC=func_02045EC0(((struct Obj00180 *)p)->f44,r->id);
        ((struct Obj05449 *)q)->f200=14819;
        ((struct Obj05449 *)q)->f204=r->value;
    }
    ((struct Obj00180 *)p)->f220=0;((struct Obj00180 *)p)->f224=0;
}




/*
 * Extent remainder: two zero alignment bytes at 021B638E.
 */
void func_021B6348(u8 *p)
{
    func_021B7EB0((char *)p, 0);
    STRBUF_Delete((struct U16Vec *)(((struct Obj00362 *)p)->f1E4));
    STRBUF_Delete((struct U16Vec *)(((struct Obj00362 *)p)->f1F0));
    STRBUF_Delete((struct U16Vec *)(((struct Obj00362 *)p)->f1FC));
    STRBUF_Delete((struct U16Vec *)(((struct Obj00362 *)p)->f208));
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct Obj00362 *)p)->f1DC));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj00362 *)p)->f218));
}





void func_021B6390(int *p)
{
    if (((struct Obj06564 *)p)->f220) {
        APP_TASKMENU_WIN_Update((u8 *)(((struct Obj06564 *)p)->f220));
        APP_TASKMENU_WIN_Update((u8 *)(((struct Obj06564 *)p)->f224));
    }
}





void func_021B63AC(u8 *p)
{
    u8 *q;

    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    q = func_020490F4(0x7c, 0x4f);
    func_021B64C0();
    func_021B64D0();
    func_021B66BC(p, q);
    func_021B7A00((char *)p, q);
    func_021B6850((char *)p);
    func_021B67A4(p);
    func_021B7128((char *)p);
    func_021B6BCC((char *)p);
    func_021B6CC0((char *)p);
    func_021B7C44(p);
    func_021B8040(p);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x4f);
    func_0204363C(1);
    ((struct Obj00180 *)p)->f68 = (u32)func_020056A0((void (*)(void))func_021B6498, p, 0x10);
    ARC_TOOL_DeleteHandle((u32)q);
    func_021B6278(p);
}




void func_021B6460(char *p) { func_021B6348((u8 *)p); func_021B7C7C((int *)p); func_021B71B8(p); func_021B6828(p); func_021B6794((int *)p); func_021B6678(); func_021B688C(p); func_021B7694((u8 *)p); func_02030EAC(((struct Obj00362 *)p)->f68); }




static inline void setShared(u32 base,SharedOffset off) { *(u32 *)(base+off)|=1; }




void func_021B6498(void *unused,char *p) { func_021B7908(p); func_020419E4(); CLACT_VBlankSystem(); setShared((u32)d_02FE0000,FLAGS_OFFSET); }





void func_021B64C0(void)
{
    BG_SYS_SetVramBanks((void *)0x021B8250);
}




void func_021B64D0(void)
{
    struct DispConfig cfg;
    struct BgTemplate a,b,c,d,e,f;
    func_0203F8F4(79);BMP_WIN_Init(79);
    cfg=d_021B8280;func_0203FC28(&cfg);
    a=d_021B82F0;func_0203FCA0(2,&a,0);func_020414EC(2);
    b=d_021B8330;func_0203FCA0(3,&b,0);func_020414EC(3);
    c=d_021B8290;func_0203FCA0(4,&c,0);func_020414EC(4);
    d=d_021B82B0;func_0203FCA0(6,&d,0);func_020414EC(6);
    e=d_021B82D0;func_0203FCA0(5,&e,0);func_020414EC(5);
    f=d_021B8310;func_0203FCA0(7,&f,0);func_020414EC(7);
    func_02040588(2,1);func_02040588(3,1);func_02040588(4,1);
    func_02040588(5,1);func_02040588(6,1);func_02040588(7,1);
    func_02040B94(2,32,0,79);func_02040B94(4,32,0,79);
    func_02040B94(5,32,0,79);func_02040B94(2,32,0,79);func_02040B94(4,32,0,79);
    *(u16 *)0x04000050=0;*(u16 *)0x04001050=0;
}




/*
 * volatile: 021B66A8 reads and 021B66AE writes hardware halfword.
 */
void func_021B6678(void)
{
    BG_SYS_SetSubPlaneVisible(29, 0);
    func_020403F4(5);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    *(volatile unsigned short *)0x04000304 |= 0x8000;
    func_0203F9B4();
}





void func_021B66BC(u8 *p, u8 *q)
{
    u32 v = 1 << 0xb;
    void *t;

    func_02049658(q, 1, 3, 0, 0, 0, 0x4f);
    func_020498F4(q, 4, 3, 0, v, 0, 0x4f);
    func_02049B68(q, 0, 0, 0, 0, 0x4f);
    func_02049658(q, 1, 7, 0, 0, 0, 0x4f);
    func_020498F4(q, 2, 7, 0, v, 0, 0x4f);
    func_02049B68(q, 0, 4, 0, 0, 0x4f);
    t = func_02049EF4(q, 3, 0, (void **)(p + 0x1c4), 0x4f);
    ((struct Obj00180 *)p)->f1C0 = t;
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, 0x4f);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x4f);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x4f);
    func_0201F5BC(4, 1, 0xd, 0, 0x4f);
}





int func_021B6794(int *p)
{
    return func_020307B0((void *)(((struct Obj24150 *)p)->f1C0));
}




void func_021B67A4(u8 *p)
{
    u32 i;
    u32 h;
    for (i=0;i<16;i++) {
        *(u32 *)(p+i*4+4)=BMP_WIN_Create((u8)d_021B8420[i].a,(u8)d_021B8420[i].b,(u8)d_021B8420[i].c,(u8)d_021B8420[i].d,d_021B8420[i].e,d_021B8420[i].f,(int)1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p+i*4+4))),0);
    }
    h=((struct Obj00180 *)p)->f28;
    BMP_WIN_ClearScreen((struct Descriptor *)h);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    ((struct Obj00180 *)p)->f21C=func_02028590(15,1,1,79);
}




/*
 * extent: 2 zero alignment bytes at 0x021B684E follow the 38-byte function; no follower.
 */
void func_021B6828(char *p) { u32 i; APP_KEYCURSOR_Delete(((struct Obj24151 *)p)->f21C); for(i=0;i<16;i++) BMP_WIN_Delete(*(void **)((u32)p+i*4+4)); BMP_WIN_Exit(); }




void func_021B6850(char *p) { ((struct Obj04557 *)p)->f44=func_02045B38(0,2,204,79); ((struct Obj04557 *)p)->f48=func_0201EC64(79); ((struct Obj04557 *)p)->f4C=STRBUF_Create(256,79); ((struct Obj04557 *)p)->f50=func_02045EC0(((struct Obj04557 *)p)->f44,25); ((struct Obj04557 *)p)->f54=func_02045EC0(((struct Obj04557 *)p)->f44,31); }




void func_021B688C(char *p) { MSGDATA_Delete(((struct Obj06565 *)p)->f44); func_0201ED04(((struct Obj06565 *)p)->f48); STRBUF_Delete(((struct Obj06565 *)p)->f4C); STRBUF_Delete(((struct Obj06565 *)p)->f50); STRBUF_Delete(((struct Obj06565 *)p)->f54); }





int func_021B68B0(int *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((struct Obj24152 *)p)->f1B0;
    return 0;
}




int func_021B68C8(char *p)
{
    u32 v;
    ((struct Obj00362 *)p)->f1CC=func_020260E0(*(struct Sound * *)&((struct Obj00362 *)p)->f1C8);
    v=func_02025DE8(*(struct Sound * *)&((struct Obj00362 *)p)->f1C8);
    switch(v) {
    case 0:case 1:case 2:case 3:
        if(TOUCHPANEL_GetTrg()==0) {
            if(((struct Obj24153 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16+v < ((struct Obj00362 *)p)->f1B8) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                return func_021B817C(p);
            }
        } else {
            if(((struct Obj24154 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16+v < ((struct Obj00362 *)p)->f1B8)
                GFL_USE_PlaySeDefaultVolume(0x54c);
        }
        break;
    case 4:case 5:break;
    case 6:case 8:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if(func_021B7F50(p)) return func_021B80EC(p,14);
        else return func_021B80A4(p,14);
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        func_021B7EB0(p,0);
        return func_021B80A4(p,14);
    case 7:
        if(func_021B7F50(p)) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return func_021B80C4((u8 *)p,15);
        }
        break;
    case -8:
        if(((struct Obj24155 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16!=0) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            --((struct Obj24156 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16;
            func_021B71C4(p,func_021B7438((char **)p));
            func_021B70D8(p);
            func_021B7F64(p);
            func_021B7FD0((u8 *)p,-1);
        }
        break;
    case -4:case -3:case -1:break;
    }
    return 1;
}





int func_021B69F8(char *p)
{
    u32 r = PRINTSYS_PrintStreamGetState(*(void **)(p + 0x6c));
    APP_KEYCURSOR_Update(*(void **)(p + 0x21c), *(void **)(p + 0x6c), *(void **)(p + 0x20));
    if (r == 0) {
        if (KEY_GetCont() & 1)
            PRINTSYS_PrintStreamShortWait(*(void **)(p + 0x6c), 0);
    } else if (r == 2) {
        PRINTSYS_PrintStreamDelete(*(void **)(p + 0x6c));
        return *(int *)(p + 0x1b0);
    } else if (r == 1) {
        if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg()) {
            PRINTSYS_PrintStreamReleasePause(*(void **)(p + 0x6c));
            GFL_USE_PlaySeDefaultVolume(0x547);
        }
    }
    return 2;
}




int func_021B6A64(u8 *p)
{
    Descriptor x;
    x.heap = 79;
    x.count = 2;
    x.items = p + 0x1fc;
    x.zero = 0;
    x.a = 21;
    x.b = 8;
    x.c = 10;
    x.d = 3;
    ((struct Obj14313 *)p)->f1E0 = (unsigned int)APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&x), (void *)(((struct Obj14313 *)p)->f1DC));
    func_021B81B0(1);
    return 4;
}




int func_021B6AAC(u8 *p)
{
    int result=4;
    if (APP_TASKMENU_IsFinish((struct TaskMenu *)(((struct Obj08264 *)p)->f1E0))) {
        if (APP_TASKMENU_GetCursorPos((const u8 *)(((struct Obj08264 *)p)->f1E0)) == 0)
            result=d_021B8228[p[0x1ba]].a(p);
        else
            result=d_021B8228[p[0x1ba]].b(p);
        func_021B81B0(0);
    }
    APP_TASKMENU_UpdateMenu(((struct Obj08264 *)p)->f1E0);
    if (result != 4) APP_TASKMENU_CloseMenu((struct TaskMenu *)(((struct Obj08264 *)p)->f1E0));
    return result;
}




int func_021B6B0C(char **p)
{
    char *q;
    u32 zero;
    q = *p;
    POKE_TOOL_SetPartyValue(((struct Obj05450 *)q)->f0, ((struct Obj05450 *)q)->f1B + 0x36, func_021B7438(p));
    q = *p;
    zero = 0;
    POKE_TOOL_SetPartyValue(((struct Obj05450 *)q)->f0, ((struct Obj05450 *)q)->f1B + 0x3e, 0);
    q = *p;
    POKE_TOOL_SetPartyValue(((struct Obj05450 *)q)->f0, ((struct Obj05450 *)q)->f1B + 0x3a, WAZA_TOOL_GetMaxPP(func_021B7438(p), 0));
    ((struct Obj24157 *)(*p))->f1A = zero;
    return 8;
}





int func_021B6B54(int *p)
{
    func_021B7460((char *)p, 6);
    ((struct Obj24158 *)p)->f1B0 = 5;
    return 2;
}




int func_021B6B6C(char *p)
{
    if (*(u8 *)(*(char **)p + 0x1b) < 4) {
        func_021B7460(p, 10);
        p[0x1ba] = 4;
    } else {
        func_021B7460(p, 7);
        p[0x1ba] = 3;
    }
    *(u32 *)(p + 0x1b0) = 3;
    return 2;
}




int func_021B6BA0(char *p) { WIPE_SYS_Start(0,0,0,0,6,1,79); ((struct Obj24159 *)p)->f1B0=9; return 0; }




void func_021B6BCC(char *p) { int n; n=func_021B7438((char **)p); if(n!=65535) func_021B71C4(p,n); else func_021B71C4(p,-2); func_021B7968(p); }




/*
 * lever: separate u8 width result from u8 coordinate x; otherwise 16 bytes
 *   differ from index/font/x register rotation. Both cases preserve byte
 *   width narrowing and signed division by two before coordinate wrap.
 * domain: all nine direct ov173 calls use align 0..2; sites 021B6CE2=2,
 *   6D00=0,6D36=0,6D90=0,6E24=0,6F88=1,7242=1,728C=1,72B8=0.
 *   At 6DC4 r7 copies zero r4 and stays invariant; at 6F5E r4 becomes 1.
 *   No defined coordinate exists in the original outside this domain.
 * extent: 138 bytes code; +0x8A 00 00 alignment padding, next labelled
 *   function 021B6C84 at +0x8C. No follower or unit.
 */
u32 func_021B6BF8(char *p, int index, u32 font, u16 w, int align, u8 y)
{
    u8 x;
    u8 width;
    switch (align) {
    case 0: x = 0; break;
    case 1:
        width = (u8)func_0201D304(((struct Obj10668 *)p)->f4C, font, 0);
        x = (u8)((u8)(BMP_WIN_GetWidth(*(void **)(p + index * 4 + 4)) * 8) - width);
        break;
    case 2:
        width = (u8)func_0201D304(((struct Obj10668 *)p)->f4C, font, 0);
        x = (u8)(((int)(u8)(BMP_WIN_GetWidth(*(void **)(p + index * 4 + 4)) * 8) - width) / 2);
        break;
    }
    return PRINTSYS_PrintColor(BMP_WIN_GetBmp(*(void **)(p + index * 4 + 4)), x, y, ((struct Obj10668 *)p)->f4C, (void *)font, w);
}







void func_021B6C84(char *p,u32 idx,u32 a,u32 b,u8 c) { void *s; s=func_02045EC0(((struct Obj08265 *)p)->f44,idx); func_0201EFA4(((struct Obj08265 *)p)->f48,0,a,b,c,1); func_0201F250(((struct Obj08265 *)p)->f48,((struct Obj08265 *)p)->f4C,s); STRBUF_Delete(s); }







static inline void flush(void *win)
{
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    func_02041B6C(BMP_WIN_GetBgLayer(win));
}







/*
 * lever: temp,bank,mon declarations restore stack homes; derived wide coord=y+16 restores both narrowing sites and the early coordinate update (existing derived-wide-local idiom).
 * blocker-C: 02045CAC verified EXACT, 344B, prior ov070 header arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
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
 * abi: 6BF8 font widened to u32 because original forwards a full word without truncation; 185F4 bare return preserves the visibly loaded pointer argument and live r0 result.
 */
void func_021B6CC0(char *p)
{
    u32 i;
    u16 move;
    int y;
    int coord;
    void *temp;
    void *bank;
    void *mon;
    func_02045CAC(*(void **)(p+0x44),0x23,*(void **)(p+0x4c));
    func_021B6BF8(p,9,*(u32 *)(p+0x60),0x3c40,2,4);
    func_02045CAC(*(void **)(p+0x44),0x17,*(void **)(p+0x4c));
    func_021B6BF8(p,2,*(u32 *)(p+0x60),0x440,0,0);
    flush(*(void **)(p+0xc));
    func_02045CAC(*(void **)(p+0x44),0x18,*(void **)(p+0x4c));
    func_021B6BF8(p,3,*(u32 *)(p+0x60),0x440,0,0);
    flush(*(void **)(p+0x10));
    temp=STRBUF_Create(256,79);
    func_02045CAC(*(void **)(p+0x44),0x27,temp);
    func_0201EEF4(*(void **)(p+0x48),0,**(void ***)p);
    func_0201F250(*(void **)(p+0x48),*(void **)(p+0x4c),temp);
    func_021B6BF8(p,13,*(u32 *)(p+0x60),0x3c40,0,4);
    flush(*(void **)(p+0x38));
    bank=func_02045B38(0,2,0xcb,79);
    mon=POKE_TOOL_GetBoxParam(**(void ***)p);
    for(i=0;i<4;i++) {
        move=func_02017E88(mon,0x36+i,0);
        if(move==0) CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x124),0);
        else {
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x124),1);
            func_021B78CC((u8 *)p,move,i);
            func_02045CAC(bank,move,*(void **)(p+0x4c));
            y=i*32;
            func_021B6BF8(p,14,*(u32 *)(p+0x60),0x3c40,0,y);
            coord=y+16;
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(*(void **)(p+0x3c)),8,coord,*(void **)(p+0x50),*(void **)(p+0x60),0x440);
            flush(*(void **)(p+0x3c));
            func_0201EFA4(*(void **)(p+0x48),0,func_02017E88(mon,0x3a+i,0),2,1,1);
            func_0201EFA4(*(void **)(p+0x48),1,func_02017E88(mon,0x42+i,0),2,0,1);
            func_0201F250(*(void **)(p+0x48),*(void **)(p+0x4c),*(void **)(p+0x54));
            PRINTSYS_PrintColor(BMP_WIN_GetBmp(*(void **)(p+0x3c)),32,coord,*(void **)(p+0x4c),*(void **)(p+0x60),0x440);
            flush(*(void **)(p+0x3c));
        }
    }
    flush(*(void **)(p+0x3c));
    func_02045CAC(*(void **)(p+0x44),0x25,temp);
    func_0201EE84(*(void **)(p+0x48),0,**(void ***)p);
    func_0201F250(*(void **)(p+0x48),*(void **)(p+0x4c),temp);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(*(void **)(p+0x40)),0,0,*(void **)(p+0x4c),*(void **)(p+0x60),0x440);
    flush(*(void **)(p+0x40));
    func_02045CAC(*(void **)(p+0x44),0x26,temp);
    func_0201EFA4(*(void **)(p+0x48),0,func_02017E88(mon,0x9e,0),3,1,1);
    func_0201F250(*(void **)(p+0x48),*(void **)(p+0x4c),temp);
    func_021B6BF8(p,15,*(u32 *)(p+0x60),0x440,1,16);
    flush(*(void **)(p+0x40));
    MSGDATA_Delete(bank);
    STRBUF_Delete(temp);
}







/*
 * Inline owner/table struct access restores the bound/index register allocation;
 * an extracted table pointer compiled 36 bytes with 18 concrete differences.
 */
u32 func_021B6FB4(struct ScanContext *p) { u32 i;for(i=0;i<256;i++)if(p->owner->table[i]==0xffff)break;return i; }







void func_021B6FDC(char *p,u8 first,u8 row)
{
    int y;
    int index;
    u32 value;
    y=row*24;
    index=first+row;
    if(index>=((struct Obj00837 *)p)->f1B8) return;
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00837 *)p)->f30),0,y,*(void **)(*(char * *)&((struct Obj00837 *)p)->f58+index*8),((struct Obj00837 *)p)->f60,0x3c40);
    flush(((struct Obj00837 *)p)->f30);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00837 *)p)->f30),96,y,((struct Obj00837 *)p)->f50,((struct Obj00837 *)p)->f60,0x440);
    flush(((struct Obj00837 *)p)->f30);
    value=WAZA_TOOL_GetMaxPP(*(u32 *)(*(char * *)&((struct Obj00837 *)p)->f58+index*8+4),0);
    func_0201EFA4(((struct Obj00837 *)p)->f48,0,value,2,1,1);
    func_0201EFA4(((struct Obj00837 *)p)->f48,1,value,2,0,1);
    func_0201F250(((struct Obj00837 *)p)->f48,((struct Obj00837 *)p)->f4C,((struct Obj00837 *)p)->f54);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(((struct Obj00837 *)p)->f30),120,y,((struct Obj00837 *)p)->f4C,((struct Obj00837 *)p)->f60,0x440);
    flush(((struct Obj00837 *)p)->f30);
}







void func_021B70D8(char *p)
{
    u32 i;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00837 *)p)->f30), 0);
    for (i = 0; i < 4; i++)
        func_021B6FDC(p, ((struct Obj24161 *)(*(char * *)&((struct Obj00837 *)p)->f0))->f16, i);
    q = ((struct Obj00837 *)p)->f30;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(BMP_WIN_GetBgLayer(q));
    func_02041B6C(7);
    func_021B7968(p);
}







void func_021B7128(char *p)
{
    u32 i;
    u16 move;
    void *bank;
    ((struct Obj00180 *)p)->f1B8 = func_021B6FB4((struct ScanContext *)p);
    ((struct Obj00180 *)p)->f58 = BMP_MENUWORK_Create(((struct Obj00180 *)p)->f1B8, 0x4f);
    i = 0;
    bank = func_02045B38(0, 2, 0xcb, 0x4f);
    for (; i < ((struct Obj00180 *)p)->f1B8; i++) {
        move = ((u16 *)((struct Obj24162 *)(*(char * *)&((struct Obj00180 *)p)->f0))->f10)[i];
        if (move != 0xffff) {
            BMP_MENUWORK_AddMsgItem(((struct Obj00180 *)p)->f58, (u32)bank, move, move, 0x4f);
        } else {
            BMP_MENUWORK_AddMsgItem(((struct Obj00180 *)p)->f58, *(u32 *)&((struct Obj00180 *)p)->f44, 0x20, -2, 0x4f);
            break;
        }
    }
    MSGDATA_Delete(bank);
    ((struct Obj00180 *)p)->f1BB = 0;
    ((struct Obj00180 *)p)->f1BC = ((struct Obj24164 *)(*(char * *)&((struct Obj00180 *)p)->f0))->f14;
    func_021B70D8(p);
}







void func_021B71B8(char *p)
{
    BMP_MENUWORK_Delete(*(void **)(p + 0x58));
}







static inline void clear(void *win)
{
    BMP_WIN_ClearScreen(win);
    func_02041B6C(BMP_WIN_GetBgLayer(win));
}







/*
 * blocker-C: 02045CAC verified EXACT, 344B, prior ov070 header arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
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
 * abi: 6BF8 font extern widened to u32: the original forwards the full p+0x60 word without narrowing.
 */
void func_021B71C4(char *p,int move)
{
    u32 value;
    void *bank;
    int zero;
    zero=0;
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+0x1c)),0);
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+0x14)),0);
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+0x18)),0);
    CLACT_SetActorDrawEnable(*(void **)(p+0x110),0);
    if(move!=zero-2) {
        value=WAZA_TOOL_GetParam(move,3);
        if(value<=1) func_02045CAC(*(void **)(p+0x44),0x21,*(void **)(p+0x4c));
        else func_021B6C84(p,0x1d,value,3,0);
        func_021B6BF8(p,4,*(u32 *)(p+0x60),0x440,1,0);
        value=WAZA_TOOL_GetParam(move,4);
        if(value==0 || WAZA_TOOL_IsAlwaysHit(move)!=0) func_02045CAC(*(void **)(p+0x44),0x21,*(void **)(p+0x4c));
        else func_021B6C84(p,0x1e,value,3,0);
        func_021B6BF8(p,5,*(u32 *)(p+0x60),0x440,1,0);
        bank=func_02045B38(0,2,0xca,79);
        func_02045CAC(bank,move,*(void **)(p+0x4c));
        func_021B6BF8(p,6,*(u32 *)(p+0x60),0x440,0,0);
        MSGDATA_Delete(bank);
        func_021B79E0((u8 *)p,move);
        CLACT_SetActorDrawEnable(*(void **)(p+0x110),1);
        flush(*(void **)(p+0xc));
        flush(*(void **)(p+0x10));
    } else {
        clear(*(void **)(p+0xc));
        clear(*(void **)(p+0x10));
    }
    flush(*(void **)(p+0x1c));
    flush(*(void **)(p+0x14));
    flush(*(void **)(p+0x18));
}







void func_021B7378(char *p, u32 kind)
{
    void *str;
    switch (kind) {
    case 0: func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0); break;
    case 1: func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 2: func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0); break;
    case 3:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 4:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 5:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7448((int *)p)); break;
    case 6:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 7: func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 8:
        func_0201EEF4(((struct Obj00544 *)p)->f48, 0, **(void ** *)&((struct Obj00544 *)p)->f0);
        func_0201EF34(((struct Obj00544 *)p)->f48, 1, func_021B7438((char **)p)); break;
    case 9: func_0201F02C(((struct Obj00544 *)p)->f48, 2, (void *)(((struct Obj24172 *)(*(char * *)&((struct Obj00544 *)p)->f0))->f4)); break;
    case 10: func_0201EF34(((struct Obj00544 *)p)->f48, 0, func_021B7448((int *)p)); break;
    }
    str = func_02045EC0(((struct Obj00544 *)p)->f44, d_021B8350[((struct Obj24173 *)(*(char * *)&((struct Obj00544 *)p)->f0))->f19][kind]);
    func_0201F250(((struct Obj00544 *)p)->f48, ((struct Obj00544 *)p)->f4C, str);
    STRBUF_Delete(str);
}








u16 func_021B7438(char **p)
{
    char *q = *p;

    return *(u16 *)(*(char * *)&((struct Obj10669 *)q)->f10 + (((struct Obj10669 *)q)->f16 + ((struct Obj10669 *)q)->f14) * 2);
}








unsigned short func_021B7448(int *p)
{
    int *q = *(int * *)&((struct Obj24174 *)p)->f0;

    return func_02017E1C((void *)((struct Obj14314 *)q)->f0, ((struct Obj14314 *)q)->f1B + 0x36, 0);
}







void func_021B7460(char *p, u32 kind)
{
    u32 zero;
    int speed;
    void *q;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj03858 *)p)->f20), 15);
    zero = 0;
    func_0201F73C(((struct Obj03858 *)p)->f20, 0, 1, 13);
    func_021B7378(p, kind);
    speed = func_02012FFC();
    ((struct Obj03858 *)p)->f6C = PRINTSYS_PrintStreamCallBack(*(u32 *)&((struct Obj03858 *)p)->f20, 0, 0, ((struct Obj03858 *)p)->f4C, ((struct Obj03858 *)p)->f60, speed, ((struct Obj03858 *)p)->f64, zero, 0x4f, 0xffff, (u32)func_021B74F8);
    q = ((struct Obj03858 *)p)->f20;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_020409B4(BMP_WIN_GetBgLayer(q));
}







void func_021B74D8(char *p)
{
    u32 x;

    func_0201F7A8((void *)(((struct Obj14315 *)p)->f20), 2);
    x = ((struct Obj14315 *)p)->f20;
    BMP_WIN_ClearScreen((struct Descriptor *)x);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)x));
}






int func_021B74F8(unsigned int state)
{
    switch (state) {
    case 1: return GFL_USE_IsAnySeBusy();
    case 2: return GFL_USE_IsAnySeBusy();
    case 3: GFL_USE_PlaySeDefaultVolume(0x56b); break;
    case 4:
        GFL_USE_SetBgmPlayerParam((void *)1);
        GFL_USE_PushBgm();
        GFL_USE_CancelChangeAndPlayBgm(0x515, 0xffff);
        break;
    case 5:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}






u8 func_021B7568(void ***p) {u8 i;for(i=0;i<4;i++)if(!func_02017E1C(**p,i+54,0))break;return i;}




int func_021B7590(u8 *p) {func_021B7460((char *)p,3);(*(u8 **)p)[27]=func_021B7568((void ***)p);((struct Obj24177 *)p)->f1B0=5;return 2;}




/*
 * Extent runs long: 0x021B75BC is an unlabelled follower leaf, so EXACT*.
 */
int func_021B75B0(char *p)
{
    func_021B74D8(p);
    return 1;
}


int func_021B75BC(u8 **pp) { (*pp)[0x1a] = 1; return 8; }

/*
 * Extent runs long: 0x021B75D4 is an unlabelled follower leaf, so EXACT*.
 */
int func_021B75C8(char *p)
{
    func_021B74D8(p);
    return 1;
}

int func_021B75D4(u8 *p) { *(u32 *)(p + 0x1b0) = 10; return 0; }
