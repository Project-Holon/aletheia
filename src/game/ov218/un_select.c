/*
 * file:     un_select.c
 * unit:     yes
 * function: func_021B95A0, func_021B95D0, func_021B9674, func_021B96CC, func_021B9820, func_021B9888, func_021B9890, func_021B9898, func_021B9914, func_021B991C, func_021B9924, func_021B9944, func_021B9964, func_021B9A80, func_021B9AD0, func_021B9AE4, func_021B9B78, func_021B9C00, func_021B9C74, func_021B9C80, func_021B9C84, func_021B9C88, func_021B9C8C, func_021B9CDC, func_021B9D10, func_021B9D48, func_021B9E28, func_021B9E48, func_021B9F98, func_021B9FD4, func_021B9FD8, func_021BA0B0, func_021BA138, func_021BA1A0, func_021BA1C0, func_021BA208, func_021BA21C, func_021BA290, func_021BA2EC, func_021BA328, func_021BA4B4, func_021BA4D4, func_021BA4FC, func_021BA554, func_021BA61C, func_021BA680, func_021BA6BC, func_021BA6E8, func_021BA720, func_021BA75C, func_021BA780, func_021BA7A4
 * address:  0x021B95A0
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   func_02030EAC 0x02030EAC arm
 *   UI_SCENE_Delete 0x021B613C thumb ov067
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   func_021BA8F0 0x021BA8F0 thumb ov218
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov067_id 0x00000043 data a1
 *   UI_SCENE_Step 0x021B6144 thumb ov067
 *   func_021BA94C 0x021BA94C thumb ov218
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049DF4 0x02049DF4 arm
 *   func_02040B1C 0x02040B1C arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_SetAllButtonsBgPriority 0x021B64F8 thumb ov067
 *   TOUCHBAR_SetButtonSound 0x021B6568 thumb ov067
 *   d_021BAC20 0x021BAC20 data a4
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   BRIGHTNESS_ChangeReset 0x02023F98 thumb
 *   BRIGHTNESS_ChangeRequest 0x02023EF4 thumb
 *   d_021BB088 0x021BB088 data ov218 a4
 *   func_02030734 0x02030734 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   TCBL_Create 0x0203101C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02045CAC 0x02045CAC arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   func_0201D2C8 0x0201D2C8 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   FRAME_LIST_GetItemValue 0x021B9398 thumb ov067
 *   FRAME_LIST_GetPrinter 0x021B9394 thumb ov067
 *   func_021B9AE4 0x021B9AE4 thumb ov218
 *   FRAME_LIST_GetScrollBarTop 0x021B8AB8 thumb ov067
 *   FRAME_LIST_GetSelectedIndex 0x021B93A4 thumb ov067
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   d_021BB060 0x021BB060 data ov218 a4
 *   template_021BB060 0x021BB060 data ov218 a4
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   FRAME_LIST_Delete 0x021B796C thumb ov067
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_0207D534 0x0207D534 arm
 *   func_021BA848 0x021BA848 thumb ov218
 *   d_021BAB20 0x021BAB20 data a4
 *   UI_SCENE_Create 0x021B6100 thumb ov067
 *   func_021BA960 0x021BA960 thumb ov218
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_02005624 0x02005624 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   FRAME_LIST_Update 0x021B7AB0 thumb ov067
 *   FRAME_LIST_SetRowPalette 0x021B9280 thumb ov067
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   UI_SCENE_GetPhaseFrame 0x021B61FC thumb ov067
 *   UI_SCENE_AdvancePhaseFrame 0x021B6200 thumb ov067
 *   func_021B9B78 0x021B9B78 thumb ov218
 *   func_021B9C00 0x021B9C00 thumb ov218
 *   BRIGHTNESS_IsFinished 0x02024004 thumb
 *   func_0201F048 0x0201F048 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   d_021BABC8 0x021BABC8 data ov218 a4
 *   d_021BAB68 0x021BAB68 data a4
 *   d_021BAB98 0x021BAB98 data ov218 a4
 *   d_021BABB0 0x021BABB0 data ov218 a4
 *   d_021BAB80 0x021BAB80 data ov218 a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BAED8 0x021BAED8 data a2
 */
#include "../../matched/include/Obj26039.h"
#include "../../matched/include/Obj01983.h"
#include "../../matched/include/Obj10971.h"
#include "../../matched/include/Obj02264.h"
#include "../../matched/include/Obj14771.h"
#include "../../matched/include/Obj02265.h"
#include "../../matched/include/Obj05563.h"
#include "../../matched/include/Obj26040.h"
#include "../../matched/include/Obj26041.h"
#include "../../matched/include/Obj26042.h"
#include "../../matched/include/Obj26043.h"
#include "../../matched/include/Obj03959.h"
#include "../../matched/include/Obj02556.h"
#include "../../matched/include/G_Template.h"
#include "../../matched/include/Obj14772.h"
#include "../../matched/include/Obj00243.h"
#include "../../matched/include/Obj02931.h"
#include "../../matched/include/Obj04644.h"
#include "../../matched/include/Obj26046.h"
#include "../../matched/include/Obj26047.h"
#include "../../matched/include/Obj26048.h"
#include "../../matched/include/G_Config.h"
#include "../../matched/include/Obj08448.h"
#include "../../matched/include/Obj14773.h"

struct Node;
struct TaskMenuState;
struct S020315D4;
struct S;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct Tcbl;
struct WordSet;
struct Rec3;
struct Rec;
struct PrintSys;
struct S02031140;
struct StrObj;
struct Tmpl;
struct Obj0203159C;
struct R;
struct Obj;
struct Actor;
struct PtS;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct S S;

typedef struct { u8 *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1c; } A;

typedef struct { u32 words[24]; } Table;

typedef struct R R;

struct Item { void *text; u16 color; u16 padding; u32 value; };

struct TaskMenuTmpl { u32 heapId; u8 count; u8 pad05[3]; const void *unk08; u32 unk0c; u8 pad10[2]; u8 unk12, unk13; };

typedef struct Obj Obj;

typedef struct Template Template;

typedef signed int     s32;

typedef struct Config Config;

typedef struct Pair_021BA290 {short x,y;} Pair_021BA290;

struct Row0 {char pad[0x294];void *item;};

struct Row1 {char pad[0x2b0];void *item;};

typedef struct Pair_021BA61C { short x, y; } Pair_021BA61C;

typedef struct Row { char pad[0x244]; void *item; char gap[0x94]; unsigned id; } Row;

typedef struct PtS{s16 x,y;} PtS;

typedef enum { FogMode0 = 0 } FogMode;

typedef enum { FogSlope0 = 0 } FogSlope;

extern int FRAME_LIST_UpdateInit(struct S *p);
extern void FADE_Start(unsigned int, int, int, int);
extern int FADE_IsActive(void);
extern void func_02030EAC(struct Node *);
extern void UI_SCENE_Delete(void *);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void func_021BA8F0(char *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int);
extern int UI_SCENE_Step(struct S *);
extern void func_021BA94C(char *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
extern void MI_CpuFill8(void *, u32, u32);
extern R *TOUCHBAR_Create(A *, int);
extern void TOUCHBAR_SetAllButtonsBgPriority(u8 *, u32);
extern void TOUCHBAR_SetButtonSound(unsigned char *p, unsigned int id, int v);
extern void TOUCHBAR_Delete(u8 *);
extern void TOUCHBAR_Update(struct S *p);
extern void *func_02045EC0(struct MsgBank *, u32);
extern void STRBUF_Delete(struct U16Vec *);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *, void *);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *);
extern void APP_TASKMENU_UpdateMenu(Obj *);
extern void BRIGHTNESS_ChangeReset(u32 mask);
extern int BRIGHTNESS_ChangeRequest(int a, int b, int c, int d, int e);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_Print(void *,short,short,void *,void *);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern unsigned int GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Main(struct Tcbl *p);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern u32 func_0201D2C8(struct StrObj *s);
extern signed char func_02012FFC(void);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void func_0201F73C(void *, int, int, int);
extern unsigned int PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *, int);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int);
void func_021B9AE4();
void func_021B9B78(char *p, u32 id);
int func_021B9C00(char *p);
extern void func_0201F7A8(void *,u32);
extern u32 FRAME_LIST_GetItemValue(char *p, int index);
extern unsigned FRAME_LIST_GetPrinter(char *p);
extern int FRAME_LIST_GetScrollBarTop(u8 *);
extern int FRAME_LIST_GetSelectedIndex(char *);
extern int FRAME_LIST_GetCursor(char *);
extern struct S *FRAME_LIST_Create(struct Tmpl *tmpl, u32 heap);
extern void FRAME_LIST_CopyMapToBuffer(u8 *p, u32 a, u32 b, u32 c, u32 index);
extern void FRAME_LIST_LoadPalettes(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void FRAME_LIST_AddItem(char *ctx, unsigned first, unsigned second);
extern void FRAME_LIST_Delete(struct S *);
extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern char *func_021BA848(unsigned swap, unsigned heap);
extern void *UI_SCENE_Create(u32,void *,u8,u16,void *);
extern u32 func_021BA960(char *p);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_0207D63C(u32 *,u32,u32,u32,u32);
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern int FRAME_LIST_Update(struct S *p);
extern void FRAME_LIST_SetRowPalette(u8 *p, int a, u32 b);
extern void UI_SCENE_SetNextScene(unsigned char *,int);
extern int TOUCHBAR_GetPressedButtonIdIfDone(unsigned char *);
extern unsigned UI_SCENE_GetPhaseFrame(const unsigned char *p);
extern void UI_SCENE_AdvancePhaseFrame(u8 *a);
extern int BRIGHTNESS_IsFinished(int a);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern unsigned char APP_TASKMENU_GetCursorPos(const unsigned char *);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 CLACT_CreateActor(u32,u32,u32,u32,u32,u16,u16);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u32 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct PtS *delta, u32 which);
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void G3X_SetFog(int, FogMode, FogSlope, int);
extern void G3X_SetClearColor(unsigned short, int, int, int, int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned, unsigned);
int func_021B95A0(void *owner,int *state,char *input,u8 *p);
int func_021B95D0(struct S020315D4 *ctx, int *state, void *unused, char *p);
int func_021B9674(void *ctx, int *state, void *unused, char *p);
void func_021B96CC(u8 *p, u16 heap);
R *func_021B9820(int heap, int id);
void func_021B9888(u8 *p);
void func_021B9890(S *p);
struct TaskMenu *func_021B9898(void *arg, struct MsgBank *bank, u32 heap);
void func_021B9914(struct TaskMenu *p);
void func_021B991C(Obj *p);
int func_021B9924(void);
void func_021B9944(void);
void *func_021B9964(u16 heap);
void func_021B9A80(char *p);
void func_021B9AD0(char *p);
void func_021B9C74(u8 *p);
void *func_021B9C80(u8 *p);
void *func_021B9C84(u8 *p);
u32 func_021B9C88(char *p);
void func_021B9C8C(u8 *p, u32 a, u32 b, u8 *c, u32 d);
void func_021B9CDC(u8 *p);
void func_021B9D10(u8 *p,int delta);
void func_021B9D48(char *p);
void func_021B9E28(char *p);
char *func_021B9E48(void *owner,char *input);
void func_021B9F98(u8 *p, int mode);
int func_021B9FD4(void);
int func_021B9FD8(unsigned char *task,char *p);
int func_021BA0AC(void);
u32 func_021BA0B0(u8 *a, u8 *b);
int func_021BA138(unsigned char *task, char *ctx);
int func_021BA1A0(void);
int func_021BA1C0(unsigned char *task, char *ctx);
int func_021BA208(void *unused, char *p);
int func_021BA21C(unsigned char *task, char *ctx);
void func_021BA238(void);
void func_021BA290(char *ctx);
void func_021BA2EC(char *p);
void func_021BA328(char *p);
void func_021BA4B4(char *p);
struct Obj *func_021BA4D4(u32 owner,char *p);
void func_021BA4FC(char *ctx);
void func_021BA554(const char *p,int delta);
void func_021BA61C(char *ctx);
void func_021BA680(char *p,int v);
void func_021BA6BC(char *p,int y);
void func_021BA6E8(u32 p, int sel, u32 y);
int func_021BA720(u32 base,u32 i,u32 space,int y);
int func_021BA75C(char *p, int v);
unsigned int func_021BA780(int v);
void func_021BA7A4(void);
extern char ov067_id[];
extern const Table d_021BAC20;
extern char d_021BB088[];
extern struct Template d_021BB060;
extern struct Template template_021BB060;
extern int tbl_021BAC80[];
extern char d_021BAB20[];
extern struct Config d_021BAB68;
extern const Config d_021BABC8, d_021BAB98, d_021BABB0, d_021BAB80;
extern const unsigned short d_021BAED8[];





int func_021B95A0(void *owner,int *state,char *input,u8 *p)
{
    switch(*state){
    case 0:func_021B9E48(owner,input);++*state;break;
    case 1:if(FRAME_LIST_UpdateInit(*(S * *)&((struct Obj26039 *)p)->f2C)==0)return 1;break;
    }
    return 0;
}





int func_021B95D0(struct S020315D4 *ctx, int *state, void *unused, char *p)
{
    switch (*state) {
    case 0:
        FADE_Start(3, 0, 16, 1);
        ++*state;
        break;
    case 1:
        if (FADE_IsActive() != 1)
            ++*state;
        break;
    case 2: {
        u16 heap;
        func_02030EAC(*(struct Node * *)&((struct Obj01983 *)p)->f23C);
        *(volatile u16 *)0x04000050 = 0;
        *(volatile u16 *)0x04001050 = 0;
        func_021B9E28(p);
        UI_SCENE_Delete(((struct Obj01983 *)p)->f24);
        func_021B9A80(*(char * *)&((struct Obj01983 *)p)->f28);
        func_021BA4B4(p);
        func_021BA2EC(p);
        APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct Obj01983 *)p)->f18);
        func_021B9888(((struct Obj01983 *)p)->f8);
        func_021BA8F0(*(char * *)&((struct Obj01983 *)p)->f4);
        heap = ((struct Obj01983 *)p)->f0;
        func_020315D4(ctx);
        func_020306F0(heap);
        func_02034A5C((int)ov067_id);
        return 1;
    }
    }
    return 0;
}





int func_021B9674(void *ctx, int *state, void *unused, char *p)
{
    int result = 0;
    switch (*state) {
    case 0:
        FADE_Start(3, 16, 0, 1);
        ++*state;
        break;
    case 1:
        if (FADE_IsActive() == 0)
            ++*state;
        break;
    case 2:
        if (UI_SCENE_Step(*(struct S * *)&((struct Obj10971 *)p)->f24) != 0)
            result = 1;
        break;
    }
    func_021B9AD0(*(char * *)&((struct Obj10971 *)p)->f28);
    func_021BA94C(*(char * *)&((struct Obj10971 *)p)->f4);
    return result != 0;
}





void func_021B96CC(u8 *p, u16 heap)
{
    void *h;
    void *w2;
    void *w1;
    u8 *o2;
    u8 *o1;
    int a;
    int i;
    h = func_020490F4(0xc1, heap);
    func_02049B68(h, 1, 0, 0, 0xe0, heap);
    func_02049B68(h, 1, 4, 0, 0xe0, heap);
    func_02049658(h, 0xc, 4, 0, 0x200, 0, heap);
    func_020498F4(h, 6, 7, 0, 0, 0, heap);
    func_020498F4(h, 0xd, 4, 0, 0, 0, heap);
    w1 = func_02049DF4(h, 0, 0, (u32)((void **)&o1), heap);
    func_020498F4(h, 5, 3, 0, 0, 0, heap);
    w2 = func_02049DF4(h, 0, 0, (u32)((void **)&o2), heap);
    func_02049658(h, 2, 2, 0, 0, 0, heap);
    func_02049658(h, 2, 6, 0, 0, 0, heap);
    for (i = 0; i < 0x82; i++) {
        u8 *buf;
        a = 0x81 - i;
        buf = (i < 0x32) ? *(u8 **)(o1 + 0x14) : *(u8 **)(o2 + 0x14);
        if (*(u32 *)(p + 0x34 + i * 4) == 0) {
            u32 col = (u8)((u8)((3 - a % 4) * 2) * 4);
            u32 off = col + (((u8)(a / 4) << 5) + 0x20);
            buf[off] = 0xff;
            buf[off + 1] = 0xff;
            buf[off + 2] = 0xff;
            buf[off + 3] = 0xff;
            buf[off + 4] = 0xff;
            buf[off + 5] = 0xff;
            buf[off + 6] = 0xff;
            buf[off + 7] = 0xff;
        }
    }
    func_02040B1C(7, *(void **)(o1 + 0x14), *(u32 *)(o1 + 0x10), 0);
    func_020307B0(w1);
    func_02040B1C(3, *(void **)(o2 + 0x14), *(u32 *)(o2 + 0x10), 0);
    func_020307B0(w2);
    ARC_TOOL_DeleteHandle(h);
}





R *func_021B9820(int heap, int id)
{
    Table table = d_021BAC20;
    A config;
    R *p;
    MI_CpuFill8(&config, 0, sizeof(config));
    config.f0 = (u8 *)&table;
    config.f4 = 3;
    config.f8 = heap;
    config.fC = 1;
    config.f10 = 13;
    config.f14 = 0;
    config.f18 = 0;
    p = TOUCHBAR_Create(&config, id);
    TOUCHBAR_SetAllButtonsBgPriority((u8 *)p, 1);
    TOUCHBAR_SetButtonSound((unsigned char *)p, 4, 0);
    TOUCHBAR_SetButtonSound((unsigned char *)p, 5, 0);
    return p;
}





void func_021B9888(u8 *p)
{
    TOUCHBAR_Delete(p);
}





void func_021B9890(S *p)
{
    TOUCHBAR_Update(p);
}





struct TaskMenu *func_021B9898(void *arg, struct MsgBank *bank, u32 heap)
{
    struct TaskMenuTmpl config;
    struct Item items[2];
    struct TaskMenu *menu;
    u32 i;
    for (i = 0; i < 2; i++) {
        items[i].text = func_02045EC0(bank, i + 235);
        items[i].color = 0x39e3;
        items[i].value = 0;
    }
    config.heapId = heap;
    config.count = 2;
    config.unk08 = items;
    config.unk0c = 1;
    config.pad10[0] = 32;
    config.pad10[1] = 18;
    config.unk12 = 13;
    config.unk13 = 3;
    menu = APP_TASKMENU_OpenMenu(&config, arg);
    for (i = 0; i < 2; i++)
        STRBUF_Delete((struct U16Vec *)items[i].text);
    return menu;
}





void func_021B9914(struct TaskMenu *p)
{
    APP_TASKMENU_CloseMenu(p);
}





void func_021B991C(Obj *p)
{
    APP_TASKMENU_UpdateMenu(p);
}






/*
 * Initialises one record: enable flag 1 through 0x02023F98, then issue the
 * five-argument setup 0x02023EF4(8, -8, 0, 0x3c, 1) and return its result.
 * Blocker target of func_021BA0B0.
 *
 * Addresses are Black-image addresses.
 */
int func_021B9924(void)
{
    BRIGHTNESS_ChangeReset(1);
    return BRIGHTNESS_ChangeRequest(8, -8, 0, 0x3c, 1);
}




void func_021B9944(void)
{
    BRIGHTNESS_ChangeReset(1);
    BRIGHTNESS_ChangeRequest((int)((void *)8), 0, -8, 60, 1);
}




void *func_021B9964(u16 heap)
{
    char *p;
    void *window;
    p=func_02030734(heap,0x234,1,d_021BB088,0x3cc);
    *(u16 *)p=heap;
    func_02049B40(23,5,0,0x1c0,32,heap);
    func_0201F5BC(0,1,15,0,heap);
    *(void **)(p+0x14)=func_0201EC64(heap);
    *(void **)(p+8)=func_02045B38(0,2,229,heap);
    *(void **)(p+0x10)=(void *)PRINTSYS_QUE_Create((void *)heap);
    *(void **)(p+0xc)=GF_FONT_Create(23,0,0,0,heap);
    *(void **)(p+0x18)=STRBUF_Create(1600,heap);
    *(void **)(p+0x1c)=STRBUF_Create(1600,heap);
    *(void **)(p+4)=TCBL_Create(heap,heap,1,0);
    *(void **)(p+0x24)=(void *)BMP_WIN_Create(0,1,19,30,4,14,1);
    window=*(void **)(p+0x28)=(void *)BMP_WIN_Create(4,1,1,30,2,6,1);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    GF_FONT_SetTextColor(1,2,15);
    func_02045CAC(*(void **)(p+8),233,*(void **)(p+0x18));
    PRINTSYS_Print(BMP_WIN_GetBmp(window),4,0,*(void **)(p+0x18),*(void **)(p+0xc));
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
    return p;
}



void func_021B9A80(char *p)
{
    if (*(struct Rec3 * *)&((struct Obj02264 *)p)->f20 != 0) {
        PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj02264 *)p)->f20);
        *(struct Rec3 * *)&((struct Obj02264 *)p)->f20 = 0;
    }
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj02264 *)p)->f28);
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj02264 *)p)->f24);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj02264 *)p)->f18);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj02264 *)p)->f1C);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj02264 *)p)->f8);
    PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj02264 *)p)->f10);
    GF_FONT_Delete(((struct Obj02264 *)p)->fC);
    TCBL_Destroy(*(struct S02031140 * *)&((struct Obj02264 *)p)->f4);
    func_0201ED04(*(struct WordSet * *)&((struct Obj02264 *)p)->f14);
    func_020307B0(p);
}




void func_021B9AD0(char *p)
{
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj14771 *)p)->f10));
    TCBL_Main((struct Tcbl *)(((struct Obj14771 *)p)->f4));
}



void func_021B9AE4(p, a, b, cd)
    u8 *p;

 u8 *a;

 void *b;

 unsigned long long cd;

{
    u32 c = (u32)cd; u32 d = (u32)(cd >> 32);
    u32 r = 12;
    u32 t = 0x83 - d;
    func_02045CAC(*(void **)(p + 8), (t == 2) ? 0xF0 : 0xED, *(void **)(p + 0x18));
    func_0201EFA4(*(void **)(p + 0x14), 2, t, 3, 0, 1);
    func_0201F250(*(void **)(p + 0x14), *(void **)(p + 0x1C), *(void **)(p + 0x18));
    TOUCHBAR_PrintAligned(a, b, 0, 12, *(u32 *)(p + 0x1C), c, 0x39E0, 0);
    p += 0x2C;
    if (func_0201D2C8((struct StrObj *)(*(u32 *)(p + d * 4))) > 1) r = 4;
    TOUCHBAR_PrintAligned(a, b, 0x1E, r, *(u32 *)(p + d * 4), c, 0x39E0, 0);
}


void func_021B9B78(char *p, u32 id)
{
    int value = func_02012FFC();
    struct Descriptor *obj = *(struct Descriptor * *)&((struct Obj02265 *)p)->f24;
    BMP_Clear(BMP_WIN_GetBmp(obj), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    func_02045CAC(*(struct MsgBank * *)&((struct Obj02265 *)p)->f8, id, ((struct Obj02265 *)p)->f18);
    func_0201F250(*(struct WordSet * *)&((struct Obj02265 *)p)->f14, ((struct Obj02265 *)p)->f1C, ((struct Obj02265 *)p)->f18);
    ((struct Obj02265 *)p)->f20 = PRINTSYS_PrintStream((u32)obj, 4, 0, *(u32 *)&((struct Obj02265 *)p)->f1C, ((struct Obj02265 *)p)->fC, value, ((struct Obj02265 *)p)->f4, 65535, ((struct Obj02265 *)p)->f0, 15);
    func_0201F73C(((struct Obj02265 *)p)->f24, 2, 1, 15);
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen((struct Cfg *)obj);
    func_02041B6C(BMP_WIN_GetBgLayer(obj));
}


int func_021B9C00(char *p)
{
    if (((struct Obj05563 *)p)->f20 != 0) {
        switch (PRINTSYS_PrintStreamGetState(((struct Obj05563 *)p)->f20)) {
        case 2:
            PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj05563 *)p)->f20);
            ((struct Obj05563 *)p)->f20 = 0;
            return 1;
        case 1:
            if (KEY_GetTrg() == 1 || KEY_GetTrg() == 2 || TOUCHPANEL_GetTrg() != 0) {
                PRINTSYS_PrintStreamReleasePause(((struct Obj05563 *)p)->f20);
                GFL_USE_PlaySeDefaultVolume(1356);
            }
            break;
        case 0:
            if (((unsigned int)KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0)
                PRINTSYS_PrintStreamShortWait(*(struct Rec * *)&((struct Obj05563 *)p)->f20, 0);
            break;
        }
        return 0;
    }
    return 0;
}





void func_021B9C74(u8 *p)
{
    func_0201F7A8(((struct Obj26040 *)p)->f24,1);
}





void *func_021B9C80(u8 *p)
{
    return ((struct Obj26041 *)p)->fC;
}





void *func_021B9C84(u8 *p)
{
    return ((struct Obj26042 *)p)->f10;
}






/*
 * Unlabelled leaf in ov218, printed as a .word run right before the next
 * function at 0x021B9C8C; four-byte word getter.  Blocker target of
 * func_021BA0B0 (pkt_021BA0B0), whose ov218 hint then covers it.
 */
u32 func_021B9C88(char *p)
{
    return ((struct Obj26043 *)p)->f8;
}





void func_021B9C8C(u8 *p, u32 a, u32 b, u8 *c, u32 d)
{
    u32 t;
    func_021BA4FC((char *)p);
    FRAME_LIST_GetItemValue((char *)(*(u8 **)(p + 0x2C)), a);
    t = FRAME_LIST_GetPrinter((char *)(*(u8 **)(p + 0x2C)));
    func_021B9AE4(*(u8 **)(p + 0x28), b, t, func_021B9C80(*(u8 **)(p + 0x28)), a);
    if (func_021BA75C((char *)p, a)) {
        func_021BA6E8((u32)p, d, (u32)(c + 0x14));
    }
}





void func_021B9CDC(u8 *p)
{
    int selected;
    s16 y;
    y=FRAME_LIST_GetScrollBarTop(*(u8 * *)&((struct Obj03959 *)p)->f2C);
    func_021BA680((char *)p,y);
    selected=FRAME_LIST_GetSelectedIndex(*(char * *)&((struct Obj03959 *)p)->f2C);
    func_021BA6BC((char *)p,(int)(((u32)selected-(u32)FRAME_LIST_GetCursor(*(char * *)&((struct Obj03959 *)p)->f2C))*2+92));
}





void func_021B9D10(u8 *p,int delta)
{
    int selected;
    s16 y;
    func_021BA554((const char *)p,(int)(0u-(u32)delta));
    y=FRAME_LIST_GetScrollBarTop(*(u8 * *)&((struct Obj03959 *)p)->f2C);
    func_021BA680((char *)p,y);
    selected=FRAME_LIST_GetSelectedIndex(*(char * *)&((struct Obj03959 *)p)->f2C);
    func_021BA6BC((char *)p,(int)(((u32)selected-(u32)FRAME_LIST_GetCursor(*(char * *)&((struct Obj03959 *)p)->f2C))*2+92));
}





void func_021B9D48(char *p)
{
    int i,value;
    u32 offset;
    int disabled;
    void *archive,*bank;
    d_021BB060.owner=p;
    value=**(u8 * *)&((struct Obj02556 *)p)->f20;
    if(value<=1)value=2;
    for(i=0;i<130;i++) {
        if(131-i==value) {
            if(i>126) {
                d_021BB060.page=i-126;
                d_021BB060.start=i-d_021BB060.page;
            } else d_021BB060.start=i;
        }
    }
    ((struct Obj02556 *)p)->f2C=FRAME_LIST_Create((struct Tmpl *)(&template_021BB060),((struct Obj02556 *)p)->f0);
    archive=func_020490F4(193,((struct Obj02556 *)p)->f0);
    FRAME_LIST_CopyMapToBuffer(((struct Obj02556 *)p)->f2C,(u32)archive,3,0,0);
    FRAME_LIST_CopyMapToBuffer(((struct Obj02556 *)p)->f2C,(u32)archive,4,0,1);
    FRAME_LIST_LoadPalettes(((struct Obj02556 *)p)->f2C,archive,1,2,3);
    ARC_TOOL_DeleteHandle(archive);
    bank=func_02045B38(0,2,229,((struct Obj02556 *)p)->f0);
    for(i=0;i<130;i++) {
        offset=i*4;
        disabled=1;
        if(*(u32 *)(p+0x34+offset)==1)disabled=0;
        FRAME_LIST_AddItem(((struct Obj02556 *)p)->f2C,disabled,i);
        if(disabled==0)
            *(void **)(*(char * *)&((struct Obj02556 *)p)->f28+0x2c+offset)=func_02045EC0(bank,*(int *)((char *)tbl_021BAC80+offset));
        else
            *(void **)(*(char * *)&((struct Obj02556 *)p)->f28+0x2c+offset)=func_02045EC0(bank,238);
    }
    MSGDATA_Delete(bank);
}





void func_021B9E28(char *p){int i;for(i=0;i<130;i++)STRBUF_Delete(*(struct U16Vec **)(((struct Obj14772 *)p)->f28+i*4+0x2c));FRAME_LIST_Delete(*(struct S * *)&((struct Obj14772 *)p)->f2C);}





char *func_021B9E48(void *owner,char *input)
{
    char *p;
    int i,value;
    u32 a,b;
    func_02034AC4((int)ov067_id);
    GFL_HEAP_CreateChildHeap(1,122,0x30000);
    p=PROCSYS_AllocProcWork(owner,0x330,122);
    MI_CpuFill8(p,0,0x330);
    ((struct Obj00243 *)p)->f0=122;
    *(char * *)&((struct Obj00243 *)p)->f20=input;
    for(i=0;i<130;i++) {
        if(*(u8 *)(input+0x2f+tbl_021BAC80[i]))*(u32 *)(p+0x34+i*4)=1;
        else *(u32 *)(p+0x34+i*4)=0;
    }
    for(i=0;i<20;i++) {
        value=*(u16 *)(input+8+i*2);
        if(value!=0)value=func_021BA780(value);
        else value=65535;
        *(int *)(p+0x2dc+i*4)=value;
    }
    func_0207D534((u16 *)0x0400006c,-16);
    func_0207D534((u16 *)0x0400106c,-16);
    ((struct Obj00243 *)p)->f4=func_021BA848(0,((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f24=UI_SCENE_Create(((struct Obj00243 *)p)->f0,d_021BAB20,3,0,p);
    func_021B96CC((u8 *)p,((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f28=func_021B9964(((struct Obj00243 *)p)->f0);
    ((struct Obj00243 *)p)->f8=func_021B9820(func_021BA960(((struct Obj00243 *)p)->f4),((struct Obj00243 *)p)->f0);
    a=(u32)func_021B9C80(((struct Obj00243 *)p)->f28);
    b=(u32)func_021B9C84(((struct Obj00243 *)p)->f28);
    ((struct Obj00243 *)p)->f18=APP_TASKMENU_RES_Create(1,11,a,b,((struct Obj00243 *)p)->f0);
    func_021BA290(p);
    func_021B9D48(p);
    func_021BA328(p);
    func_021BA61C(p);
    func_0207D63C((u32 *)0x04001050,4,8,6,10);
    ((struct Obj00243 *)p)->f23C=func_02005624((u32)func_021BA238,(u32)p,0);
    GFL_NET_RestartWithDefaultTimeout(1,((struct Obj00243 *)p)->f0);
    return p;
}





void func_021B9F98(u8 *p, int mode)
{
    switch (mode) {
    case 0: {
        int idx = *(int *)(p + 0x30);
        *(u8 *)(*(u8 **)(p + 0x20) + 1) = 0x83 - idx;
        *(u16 *)(*(u8 **)(p + 0x20) + 2) = tbl_021BAC80[idx];
        *(u32 *)(*(u8 **)(p + 0x20) + 4) = 1;
        break;
    }
    case 1:
        *(u8 *)(*(u8 **)(p + 0x20) + 1) = 0;
        *(u16 *)(*(u8 **)(p + 0x20) + 2) = 0;
        *(u32 *)(*(u8 **)(p + 0x20) + 4) = 0;
        break;
    }
}





int func_021B9FD4(void) { return 1; }





int func_021B9FD8(unsigned char *task,char *p)
{
    int active=0;
    int selected;
    ((struct Obj02931 *)p)->f32C=0;
    if(KEY_GetTrg()&0x200)active=1;
    else if(KEY_GetTrg()&0x100)active=1;
    if(active) ((struct Obj02931 *)p)->f32C=1;
    if((u32)FRAME_LIST_Update(((struct Obj02931 *)p)->f2C)<4){
        selected=FRAME_LIST_GetSelectedIndex(*(char * *)&((struct Obj02931 *)p)->f2C);
        if(*(u32 *)((u32)p+0x34+(u32)selected*4)==1){
            ((struct Obj02931 *)p)->f30=selected;
            FRAME_LIST_SetRowPalette(((struct Obj02931 *)p)->f2C,(unsigned short)FRAME_LIST_GetCursor(*(char * *)&((struct Obj02931 *)p)->f2C),3);
            GFL_USE_PlaySeDefaultVolume(1356);
            UI_SCENE_SetNextScene(task,**(unsigned char * *)&((struct Obj02931 *)p)->f20==131-selected ? 2 : 1);
            return 1;
        }
    }
    func_021B9890(((struct Obj02931 *)p)->f8);
    switch(TOUCHBAR_GetPressedButtonIdIfDone(*(unsigned char * *)&((struct Obj02931 *)p)->f8)){
    case -1:case 0:case 2:case 3:case 4:case 5:break;
    case 1:
        func_021B9F98((u8 *)p,1);
        UI_SCENE_SetNextScene(task,65534);
        return 1;
    }
    return 0;
}





int func_021BA0AC(void) { return 1; }





u32 func_021BA0B0(u8 *a, u8 *b)
{
    switch (UI_SCENE_GetPhaseFrame(a)) {
    case 0:
        func_021B9924();
    tail:
        UI_SCENE_AdvancePhaseFrame(a);
        break;
    case 1:
        if (FADE_IsActive() == 1) break;
        if (BRIGHTNESS_IsFinished(1) == 0) break;
        func_0201F048((struct WordSet *)(*(u32 *)(*(u8 **)(b + 0x28) + 0x14)), 0, tbl_021BAC80[*(int *)(b + 0x30)]);
        func_021B9B78((char *)(*(u8 **)(b + 0x28)), 0xEA);
        goto tail;
    case 2:
        if (func_021B9C00((char *)(*(u8 **)(b + 0x28))) == 0) break;
        goto tail;
    case 3:
        *(u32 *)(b + 0x1C) = (u32)func_021B9898((void *)(*(u32 *)(b + 0x18)), (struct MsgBank *)func_021B9C88((char *)(*(u8 **)(b + 0x28))), *(u16 *)b);
        return 1;
    }
    return 0;
}





int func_021BA138(unsigned char *task, char *ctx)
{
    func_021B991C(((struct Obj04644 *)ctx)->f1C);
    if (APP_TASKMENU_IsFinish(((struct Obj04644 *)ctx)->f1C) != 0) {
        switch (APP_TASKMENU_GetCursorPos(((struct Obj04644 *)ctx)->f1C)) {
        case 0:
            func_021B9F98((u8 *)ctx, 0);
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            UI_SCENE_SetNextScene(task, 65534);
            break;
        case 1:
            func_021B9944();
            func_021B9C74(((struct Obj04644 *)ctx)->f28);
            func_021B9914(((struct Obj04644 *)ctx)->f1C);
            UI_SCENE_SetNextScene(task, 0);
            break;
        }
        return 1;
    }
    return 0;
}





int func_021BA1A0(void){if(FADE_IsActive()==1 || BRIGHTNESS_IsFinished(1)==0)return 0;return 1;}





int func_021BA1C0(unsigned char *task, char *ctx)
{
    switch (UI_SCENE_GetPhaseFrame(task)) {
    case 0:
        func_021B9924();
advance:
        UI_SCENE_AdvancePhaseFrame(task);
        break;
    case 1:
        if (FADE_IsActive() == 1)
            break;
        if (BRIGHTNESS_IsFinished(1) == 0)
            break;
        func_021B9B78(((struct Obj26046 *)ctx)->f28, 0xef);
        goto advance;
    case 2:
        return 1;
    }
    return 0;
}






int func_021BA208(void *unused, char *p)
{
    return func_021B9C00((char *)(((struct Obj26047 *)p)->f28)) != 0;
}





int func_021BA21C(unsigned char *task, char *ctx)
{
    func_021B9944();
    func_021B9C74(((struct Obj26048 *)ctx)->f28);
    UI_SCENE_SetNextScene(task, 0);
    return 1;
}





void func_021BA238(void)
{
    int count = *(volatile unsigned short *)0x04000006;
    if (count >= 152)
        *(volatile unsigned short *)0x04001052 = 0x050b;
    else if (count >= 112)
        *(volatile unsigned short *)0x04001052 = 0x060a;
    else if (count >= 72)
        *(volatile unsigned short *)0x04001052 = 0x0709;
    else if (count >= 32)
        *(volatile unsigned short *)0x04001052 = 0x0808;
    else
        *(volatile unsigned short *)0x04001052 = 0x0a06;
}





void func_021BA290(char *ctx)
{
    unsigned short heap = ((struct Obj00243 *)ctx)->f0;
    void *archive;
    *(int *)&((struct Obj00243 *)ctx)->f2D0 = -1;
    *(int *)&((struct Obj00243 *)ctx)->f2D4 = -1;
    *(int *)&((struct Obj00243 *)ctx)->f2D8 = -1;
    archive = func_020490F4(193, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D0 = CLACT_RegisterCharacter((void *)((unsigned)archive), 10, 0, 2, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D4 = CLACT_RegisterPalette((void *)archive, 11, 2, 96, heap);
    *(int *)&((struct Obj00243 *)ctx)->f2D8 = CLACT_RegisterCellAnim((void *)((unsigned)archive), 9, 8, heap);
    ARC_TOOL_DeleteHandle(archive);
}





void func_021BA2EC(char *p){if(((struct Obj01983 *)p)->f2D0!=-1)CLACT_ReleaseCharacter(((struct Obj01983 *)p)->f2D0);if(((struct Obj01983 *)p)->f2D4!=-1)CLACT_ReleasePalette(((struct Obj01983 *)p)->f2D4);if(((struct Obj01983 *)p)->f2D8!=-1)CLACT_ReleaseCellAnim(((struct Obj01983 *)p)->f2D8);}





void func_021BA328(char *p)
{
    Config a,b,c,d,e;
    void *manager,*item;
    int i,j;
    manager=(void *)func_021BA960(((struct Obj00243 *)p)->f4);
    for(j=0;j<36;j++)*(u32 *)(p+0x240+j*4)=0;
    a=d_021BABC8;
    a.c=((struct Obj00243 *)p)->f2D0;a.d=((struct Obj00243 *)p)->f2D4;a.e=((struct Obj00243 *)p)->f2D8;
    ((struct Obj00243 *)p)->f240=func_021BA4D4((u32)manager,(char *)(&a));
    b=d_021BAB68;
    b.c=((struct Obj00243 *)p)->f2D0;b.d=((struct Obj00243 *)p)->f2D4;b.e=((struct Obj00243 *)p)->f2D8;
    for(i=0;i<20;i++)*(void **)(p+0x244+i*4)=func_021BA4D4((u32)manager,(char *)(&b));
    c=d_021BAB98;
    c.c=((struct Obj00243 *)p)->f2D0;c.d=((struct Obj00243 *)p)->f2D4;c.e=((struct Obj00243 *)p)->f2D8;
    for(j=0;j<7;j++) {
        item=func_021BA4D4((u32)manager,(char *)(&c));
        CLACT_SetActorDrawEnable(item,0);
        *(void **)(p+0x294+j*4)=item;
    }
    d=d_021BABB0;
    d.c=((struct Obj00243 *)p)->f2D0;d.d=((struct Obj00243 *)p)->f2D4;d.e=((struct Obj00243 *)p)->f2D8;
    for(i=0;i<7;i++) {
        item=func_021BA4D4((u32)manager,(char *)(&d));
        CLACT_SetActorObjMode(item,1);
        CLACT_SetActorDrawEnable(item,0);
        *(void **)(p+0x2b0+i*4)=item;
    }
    e=d_021BAB80;
    e.c=((struct Obj00243 *)p)->f2D0;e.d=((struct Obj00243 *)p)->f2D4;e.e=((struct Obj00243 *)p)->f2D8;
    ((struct Obj00243 *)p)->f2CC=func_021BA4D4((u32)manager,(char *)(&e));
}






void func_021BA4B4(char *p)
{
    int i;
    for (i = 0; i < 0x24; i++)
    {
        void *q = *(void **)(p + 0x240 + i * 4);
        if (q != 0)
        {
            CLACT_DeleteActor(q);
        }
    }
}





struct Obj *func_021BA4D4(u32 owner,char *p){struct Obj *r;r=(struct Obj *)CLACT_CreateActor(owner,((struct Obj08448 *)p)->f8,((struct Obj08448 *)p)->fC,((struct Obj08448 *)p)->f10,(u32)p,((struct Obj08448 *)p)->f16,122);CLACT_SetActorAutoAnim(r,1);return r;}





void func_021BA4FC(char *ctx)
{
    int i;
    void *item;
    if (((struct Obj14773 *)ctx)->f32C != 0) {
        ((struct Obj14773 *)ctx)->f32C = 0;
        for (i = 0; i < 7; i++) {
            item = *(void **)(ctx + 0x294 + i * 4);
            if (CLACT_GetActorDrawEnable(item) != 0)
                CLACT_SetActorDrawEnable(item, 0);
        }
        for (i = 0; i < 7; i++) {
            item = *(void **)(ctx + 0x2b0 + i * 4);
            if (CLACT_GetActorDrawEnable(item) != 0)
                CLACT_SetActorDrawEnable(item, 0);
        }
    }
}





static inline void scroll(const char *p,short delta,int space,Pair_021BA290 *pos)
{
    void *item;
    long i;
    int value;
    for(i=0;i<7;i++){
        if(space==0)item=((struct Row0 *)(p+i*4))->item;
        else item=((struct Row1 *)(p+i*4))->item;
        if(CLACT_GetActorDrawEnable(item)){
            CLACT_GetActorSurfacePos(item,(struct PtS *)pos,space);
            pos->y+=delta;
            value=pos->y;
            CLACT_AddActorSurfacePos(item,(const struct PtS *)pos,space);
            if(space==0){
                if(value<=-20 || value>=220)CLACT_SetActorDrawEnable(item,0);
            }else{
                if(value<=-28 || value>=212)CLACT_SetActorDrawEnable(item,0);
            }
        }
    }
}





static inline void scrollSecond(const char *p,short delta,int space,Pair_021BA290 *pos)
{
    long i;
    void *item;
    int value;
    for(i=0;i<7;i++){
        if(space==0)item=((struct Row0 *)(p+i*4))->item;
        else item=((struct Row1 *)(p+i*4))->item;
        if(CLACT_GetActorDrawEnable(item)){
            CLACT_GetActorSurfacePos(item,(struct PtS *)pos,space);
            pos->y+=delta;
            value=pos->y;
            CLACT_AddActorSurfacePos(item,(const struct PtS *)pos,space);
            if(space==0){
                if(value<=-20 || value>=220)CLACT_SetActorDrawEnable(item,0);
            }else{
                if(value<=-28 || value>=212)CLACT_SetActorDrawEnable(item,0);
            }
        }
    }
}





/*
 * checks: 1 actor accessor/unit bodies fix return and three-argument position calls; 2 ov218 A61C confirms Pair_021BA290 ABI, no two-loop twin; 3 long index and const p each unchanged; 4 inline short-parameter helper reproduces both raw-parameter recasts, shared Pair_021BA290 fixes frame; 5 full idiom listing and A61C/other ov218 callers reread.
 * Two manual scheduling variants used; once-only permuter 300/jobs1/types unchanged, emitted baseline agrees at DIFF 200/200 with 9 concrete bytes.
 * single-lever: separate inline helpers use item-before-index in the first loop and index-before-item in the second; shared helper order swaps one loop's r4/r5 pair (9 bytes out).
 */
void func_021BA554(const char *p,int delta)
{
    Pair_021BA290 pos;
    scroll(p,delta,0,&pos);
    scrollSecond(p,delta,1,&pos);
}




/*
 * single-lever: row base retains ctx+i*4; fields at 244/2DC reproduce rematerialized id offset instead of hoisting a second array base.
 */
void func_021BA61C(char *ctx)
{
    int i;
    void *item;
    Pair_021BA61C pos;
    Row *row;
    for (i = 0; i < 20; i++) {
        row = (Row *)(ctx + i * 4);
        item = row->item;
        if (row->id == 65535) {
            CLACT_SetActorDrawEnable(item, 0);
        } else {
            CLACT_GetActorSurfacePos(item, (struct PtS *)&pos, 65535);
            pos.y = row->id * 2 + 92;
            CLACT_AddActorSurfacePos(item, (const struct PtS *)(&pos), 65535);
        }
    }
}





/*
 * extent: 2 zero alignment bytes at 021BA6BA.
 */
void func_021BA680(char *p,int v){PtS pos;s16 y;void *o;o=((struct Obj03959 *)p)->f2CC;y=(s16)v;if(y<16)y=16;else if(y>152)y=152;CLACT_GetActorSurfacePos(o,&pos,0);pos.y=y;CLACT_AddActorSurfacePos(o,&pos,0);}






void func_021BA6BC(char *p,int y){PtS pos;void *o=((struct Obj03959 *)p)->f240;CLACT_GetActorSurfacePos(o,&pos,65535);pos.y=y;CLACT_AddActorSurfacePos(o,&pos,65535);}






void func_021BA6E8(u32 p, int sel, u32 y)
{
    u32 base;
    u32 space;
    int i;
    int n;
    if (sel) {
        space = 0;
        base = p + 0x294;
        n = 7;
    } else {
        space = 1;
        base = p + 0x2B0;
        n = 7;
    }
    for (i = 0; i < n; i++) {
        if (func_021BA720(base, i, space, y)) break;
    }
}





int func_021BA720(u32 base,u32 i,u32 space,int y){PtS pos;int r;void *o;o=*(void **)(base+i*4);r=0;if(CLACT_GetActorDrawEnable(o)==0){CLACT_SetActorDrawEnable(o,1);r=1;CLACT_GetActorSurfacePos(o,&pos,space);pos.y=y;CLACT_AddActorSurfacePos(o,&pos,space);}return r;}





int func_021BA75C(char *p, int v)
{
    int i;
    for (i = 0; i < 0x14; i++)
    {
        if (v == *(int *)(p + 0x2dc + i * 4))
        {
            return 1;
        }
    }
    return 0;
}






unsigned int func_021BA780(int v)
{
    int i;
    for (i = 0; i < 0x82; i++)
    {
        if (v == tbl_021BAC80[i])
        {
            break;
        }
    }
    if (i >= 0x82)
    {
        return 0xffff;
    }
    return i;
}





void func_021BA7A4(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile unsigned short *)0x04000008 = *(volatile unsigned short *)0x04000008 & ~3;
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~(2 | 0x3000)) | 2;
    *(volatile unsigned short *)0x04000060 &= ~(0x10 | 0x3000);
    *(volatile unsigned short *)0x04000060 &= ~(4 | 0x3000);
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~0x3000) | 8;
    *(volatile unsigned short *)0x04000060 &= ~(0x20 | 0x3000);
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        G3D_SYSTEM_SetLight((unsigned char)i, &d_021BAED8[i * 4]);
    G3D_SYSTEM_SetSwapBuffersMode(0, 0);
}
