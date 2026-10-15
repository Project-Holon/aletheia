/*
 * file:     wf2dmap_scene.c
 * unit:     yes
 * function: WF2DMAP_SCENE_Create, WF2DMAP_SCENE_Draw, WF2DMAP_SCENE_Delete, WF2DMAP_SCENE_InitBg, WF2DMAP_SCENE_VBlank, WF2DMAP_SCENE_SetSlot, WF2DMAP_SCENE_BuildGrid, WF2DMAP_SCENE_ResetState, WF2DMAP_SCENE_Start, WF2DMAP_SCENE_StepWipeIn, WF2DMAP_SCENE_StepWaitInput, WF2DMAP_SCENE_StepUpdate, WF2DMAP_SCENE_StepAnimate, WF2DMAP_SCENE_Dispatch, WF2DMAP_SCENE_HandleInput, func_021D92E4, func_021D9320, func_021D9348, func_021D93D4, func_021D9490, func_021D9564, func_021D958C, func_021D9760, func_021D97B8, func_021D97CC, func_021D97FC, func_021D9838, func_021D9890, func_021D99F0, func_021D9AB0, func_021D9BEC, func_021D9D44, func_021D9E48, func_021D9E60, func_021D9E98, func_021D9EE8, func_021D9F40, func_021D9FF0, func_021DA004, func_021DA158, func_021DA164, func_021DA1A8, func_021DA320, func_021DA3B8, func_021DA3D0, func_021DA3FC, func_021DA42C, func_021DA454, func_021DA524, func_021DA578, func_021DA610
 * address:  0x021D85C0
 * region:   ov129
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
 *   CODEIN_PARAM_Create 0x0202E4EC thumb
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_020490F4 0x020490F4 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   PALANM_Create 0x02021518 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_020056A0 0x020056A0 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   d_021DA800 0x021DA800 data a4
 *   CLACT_DrawSystem  0x0204A600  arm
 *   func_02030EAC 0x02030EAC arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020403F4 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_02082A7C 0x02082A7C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   d_021DA638 0x021DA638 data a4
 *   d_021DA698 0x021DA698 data a4
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   d_021DA744 0x021DA744 data a4
 *   WIPE_SYS_Start 0x0202208C thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   d_021DA830 0x021DA830 data a4
 *   d_021DA84C 0x021DA84C data a4
 *   d_021DA718 0x021DA718 data a4 ov129
 *   KEY_GetRepeat 0x0203633C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   d_021DA75C 0x021DA75C data a4
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_FormatNumber 0x0201F35C thumb
 *   STRBUF_Append 0x02045AA8 arm
 *   d_021DA798 0x021DA798 data a2
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   d_021DA72C 0x021DA72C data a4 ov129
 *   _u32_div_f 0x0209C2B0 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   func_02049B68 0x02049B68 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   func_02049B40 0x02049B40 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   BMP_OAM_SetPos  0x0202590C  thumb
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_Create 0x02043678 arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_Create 0x020255A0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BMP_Delete 0x020437AC arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../../matched/include/Obj04506.h"
#include "../../matched/include/Obj23114.h"
#include "../../matched/include/Obj01937.h"
#include "../../matched/include/Obj01938.h"
#include "../../matched/include/Obj08136.h"
#include "../../matched/include/Obj10498.h"
#include "../../matched/include/Obj10499.h"
#include "../../matched/include/Obj02843.h"
#include "../../matched/include/Obj00361.h"
#include "../../matched/include/Obj00411.h"
#include "../../matched/include/Obj14053.h"
#include "../../matched/include/Obj06479.h"
#include "../../matched/include/Obj08137.h"
#include "../../matched/include/Obj00912.h"
#include "../../matched/include/Obj14055.h"
#include "../../matched/include/Obj14056.h"
#include "../../matched/include/Obj23117.h"
#include "../../matched/include/Obj14057.h"
#include "../../matched/include/Obj02483.h"
#include "../../matched/include/Obj06480.h"
#include "../../matched/include/Obj10500.h"
#include "../../matched/include/Obj02185.h"
#include "../../matched/include/Obj06481.h"
#include "../../matched/include/Obj00501.h"
#include "../../matched/include/Obj00913.h"
#include "../../matched/include/Obj14058.h"
#include "../../matched/include/Obj14059.h"
#include "../../matched/include/Obj14060.h"
#include "../../matched/include/Obj02186.h"
#include "../../matched/include/Obj04507.h"
#include "../../matched/include/Obj10501.h"
#include "../../matched/include/Obj02187.h"
#include "../../matched/include/Obj03283.h"
#include "../../matched/include/Obj10502.h"
#include "../../matched/include/Obj14061.h"
#include "../../matched/include/Obj08140.h"
#include "../../matched/include/Obj23118.h"
#include "../../matched/include/Obj08141.h"

struct GfFont;
struct Obj02021EE4;
struct PalAnmSlot;
struct Param;
struct Obj0203159C;
struct Node;
struct S020315D4;
struct U16Vec;
struct BgTemplate;
struct DispVram;
struct S02021D50;
struct Ctx;
struct Actor;
struct PtS;
struct Obj;
struct Vec2;
struct Pair;
struct Cfg;
struct Bank;
struct Descriptor;
struct Grid;
struct Bmp;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct StrObj;
struct Sys;
struct CharBuf;
struct WordSet;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct { unsigned words[9]; } Param;



typedef struct { unsigned words[8]; } BgTemplate;

typedef struct { BgTemplate rows[3]; } MainTemplates;

typedef struct { BgTemplate rows[4]; } SubTemplates;

typedef struct { int rows[2][3]; } Table;

typedef signed char s8;



typedef signed int s32;




typedef struct { short x,y; } Pair;

typedef struct { int x,y; } Scale;

typedef unsigned int   u32;

typedef struct { int v[3][5]; } Tbl;

typedef struct { int state, value, flag; struct Obj *handle; char tail[12]; } SceneSlot;

typedef struct  {
    int state, value, flag, handle;
    char tail[12];
}
SlotRecord;

typedef short s16;

typedef struct { s16 a,b,c,d; } Rect;

typedef struct { Rect rows[12]; } Rects;

typedef struct { u8 a,b; } Entry;


typedef struct { int state, value, flag; struct Obj *handle; char tail[12]; } Record;




typedef struct  {
    unsigned words[7];
}
Config;


typedef struct { u16 x,y,frame; u8 speed,flag; } Params;



typedef struct {
    short x;
    short y;
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} L;


typedef struct { short x,y; } PairS16;

typedef struct { u16 x,y; } PairU16;

typedef struct { u16 x,y; } PairU16B;




typedef struct { short x,y,z,w; } Position;


typedef struct { short x,y; } PairS16B;





struct Param { void *bmp; short x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };


extern void GFL_HEAP_CreateChildHeap(unsigned a, unsigned b, unsigned c);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, unsigned size, unsigned heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern struct Param *CODEIN_PARAM_Create(unsigned heap, unsigned a1, unsigned a2, unsigned a3, unsigned *src);
extern unsigned func_020307B0(void *p);
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void *func_020490F4(unsigned id, unsigned heap);
extern void BG_SYS_Create(u16),BMP_WIN_Init(u16);
extern void * PALANM_Create(unsigned);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, unsigned heapId);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, unsigned idx, unsigned size, unsigned heap);
extern void func_0207D63C(void *,int,int,int,int);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned);
extern void CLACT_DrawSystem(void *);
extern void func_02030EAC(struct Node *n);
extern unsigned GF_FONT_Delete(void *ptr);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned,unsigned);
extern void func_020403F4(unsigned);
extern void BG_SYS_Delete(void);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, unsigned idx);
extern unsigned PALANM_Delete(void *a0);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BUTTON_MAN_Delete(void *);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned heap);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_02082A7C(unsigned,void *,unsigned);
extern void BG_SYS_InitBgLayer(unsigned bgId, const struct BgTemplate *tmpl, unsigned type);
extern void BG_SYS_ClearSlot(unsigned);
extern void BMP_SetDisplaySwap(unsigned);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void CLACT_VBlankSystem(void);
extern void WIPE_SYS_Start(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern unsigned WIPE_SYS_EndCheck(void);
extern unsigned KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 KEY_GetRepeat(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_FormatNumber(void *ctx, s32 n, u32 kind, u32 mode, u32 flag);
extern void STRBUF_Append(struct U16Vec *dst, struct U16Vec *src);
extern void *BUTTON_MAN_Create(u8 *,int,int,int);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void BMP_MENUWORK_LoadCharAndPltt(u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void CLACT_DeleteActor(struct Obj *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void BMP_OAM_SetPos(struct Grid *g, short x, short y);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern void BMP_OAM_Delete(struct Grid *);
extern void BMP_OAM_DeleteSys(void *);
extern int CLACT_RegisterPaletteCompressed(void *,u32,u32,u32,u16);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintColor(void *,short,short,void *,void *,u16);
extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);
extern void BMP_OAM_UploadChars(struct Obj *o);
extern void BMP_Delete(struct Obj020437AC *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_Print(void *,short,short,void *,void *);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_020409B4(u32);
int WF2DMAP_SCENE_Create(void *obj,void *unused,const Param *cfg);
int WF2DMAP_SCENE_Draw(int a, int b, int c, int d);
int WF2DMAP_SCENE_Delete(void *a,int b,int c,char *p);
void WF2DMAP_SCENE_InitBg(void);
void WF2DMAP_SCENE_VBlank(int a, char *p);
void WF2DMAP_SCENE_SetSlot(char *p,int v);
void WF2DMAP_SCENE_BuildGrid(char *p);
void WF2DMAP_SCENE_ResetState(char *p, int v);
int WF2DMAP_SCENE_Start(char *p);
int WF2DMAP_SCENE_StepWipeIn(char *p);
int WF2DMAP_SCENE_StepWaitInput(char *p);
int WF2DMAP_SCENE_StepUpdate(char *p);
int WF2DMAP_SCENE_StepAnimate(char *p);
int WF2DMAP_SCENE_Dispatch(char *p);
void WF2DMAP_SCENE_HandleInput(char *p);
int func_021D92E4(u8 *p);
int func_021D9320(u8 *p);
void func_021D9348(char *p);
void func_021D93D4(const SlotRecord *p);
void func_021D9490(char *p);
void func_021D9564(u8 *p,int n);
void func_021D958C(u32 n, int touch, char *p);
void func_021D9760(char *p);
void func_021D97B8(char *p);
int func_021D97CC(u8 *p,int value);
int func_021D97FC(u8 *p,int value);
void func_021D9838(char *p,unsigned a);
void func_021D9890(char *p);
void func_021D99F0(char *p);
void func_021D9AB0(char *p);
void func_021D9BEC(char *p);
void func_021D9D44(char *p);
void func_021D9E48(char *p, int i, int a);
void func_021D9E60(u8 *p,int n);
void func_021D9E98(char *p,int i);
void func_021D9EE8(char *p,int i,int j);
void func_021D9F40(char *p);
void func_021D9FF0(char *p, int a, int b);
void func_021DA004(char *p);
int func_021DA158(int x,int flag);
void func_021DA164(void *p);
void func_021DA1A8(char *p,int animate);
void func_021DA320(char *p);
void func_021DA3B8(char *p);
void func_021DA3D0(u8 *p);
void func_021DA3FC(u8 *p);
void func_021DA42C(u8 *p);
void func_021DA454(u8 *p, int i, int a2, int a3, int a4);
void func_021DA524(void **p,int a,int b,int c,int d,int e,int f,int g,int h);
void func_021DA578(void *p,int a,void *b,u32 c);
void func_021DA610(void *p, int sel, void *b, unsigned int c);
extern const unsigned d_021DA800[];
extern const MainTemplates d_021DA638;
extern const SubTemplates d_021DA698;
extern const Table d_021DA744;
extern const int d_021DA830[], d_021DA84C[];
extern const Tbl d_021DA75C;
extern const Rects d_021DA798;
extern Entry d_021DA72C[];
extern const Config gClActorInitParam;






static inline void GX_SetVisiblePlane(int plane) { *(volatile unsigned *)0x04000000=(*(volatile unsigned *)0x04000000 & ~0x1F00u)|((unsigned)plane<<8); }






static inline void GXS_SetVisiblePlane(int plane) { *(volatile unsigned *)0x04001000=(*(volatile unsigned *)0x04001000 & ~0x1F00u)|((unsigned)plane<<8); }






int WF2DMAP_SCENE_Create(void *obj,void *unused,const Param *cfg)
{
    u8 *p;
    unsigned sizes[3];
    Param *q;
    GFL_HEAP_CreateChildHeap((unsigned)((void *)1),50,0x40000);
    p=PROCSYS_AllocProcWork(obj,0x34C,50);
    MI_CpuFill8(p,0,0x34C);
    if(cfg==0) {
        sizes[0]=4; sizes[1]=4; sizes[2]=4;
        q=(Param *)CODEIN_PARAM_Create(50,0,0,12,sizes);
        *(Param *)(p+0x328)=*q;
        func_020307B0(q);
    } else *(Param *)(p+0x328)=*cfg;
    BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0); GXS_SetVisiblePlane(0);
    *(void **)(p+0x258)=func_020490F4(59,50);
    BG_SYS_Create(50); BMP_WIN_Init(50);
    *(void **)(p+0x290)=PALANM_Create(50);
    *(void **)(p+0x314)=GF_FONT_Create(23,0,0,0,50);
    PALANM_SetAutoTransfer(*(void **)(p+0x290),1);
    PALANM_AllocSlotBuffers(*(void **)(p+0x290),0,512,50);
    WF2DMAP_SCENE_InitBg();
    func_021D9838((char *)p,(unsigned int)d_021DA800); WF2DMAP_SCENE_BuildGrid((char *)p); func_021D9490((char *)p);
    func_0207D63C((void *)0x04000050,0,6,15,7);
    func_0207D63C((void *)0x04001050,0,14,7,8);
    *(void **)(p+0x318)=func_020056A0((unsigned)WF2DMAP_SCENE_VBlank,(unsigned)p,16);
    GFL_NET_RestartWithDefaultTimeout(1,50);
    return 1;
}







/*
 * Addresses are Black-image addresses.
 */
int WF2DMAP_SCENE_Draw(int a, int b, int c, int d)
{
    void *r = (void *)WF2DMAP_SCENE_Dispatch((char *)d);

    CLACT_DrawSystem(r);
    return r != 0;
}






/*
 * The caller supplies the pointer through the legacy argless 02021540 thunk.
 */
int WF2DMAP_SCENE_Delete(void *a,int b,int c,char *p)
{
    func_02030EAC(((struct Obj04506 *)p)->f318);
    GF_FONT_Delete(((struct Obj04506 *)p)->f314);
    func_021D99F0(p);
    BMP_WIN_Exit();
    BG_SYS_SetMainPlaneVisible(1,0); BG_SYS_SetMainPlaneVisible(2,0); BG_SYS_SetMainPlaneVisible(4,0); BG_SYS_SetMainPlaneVisible(8,0);
    BG_SYS_SetSubPlaneVisible(1,0); BG_SYS_SetSubPlaneVisible(2,0); BG_SYS_SetSubPlaneVisible(4,0); BG_SYS_SetSubPlaneVisible(8,0);
    func_020403F4(1); func_020403F4(2); func_020403F4(3); func_020403F4(4);
    func_020403F4(5); func_020403F4(6); func_020403F4(7);
    BG_SYS_Delete();
    PALANM_FreeSlotBuffers(((struct Obj04506 *)p)->f290,0);
    PALANM_Delete(((struct Obj04506 *)p)->f290);
    ARC_TOOL_DeleteHandle(((struct Obj04506 *)p)->f258);
    BUTTON_MAN_Delete(((struct Obj04506 *)p)->f294);
    if(c==0) STRBUF_Delete(((struct Obj04506 *)p)->f348);
    func_020315D4(a);
    GFL_HEAP_DeleteChecked(50);
    return 1;
}






void WF2DMAP_SCENE_InitBg(void)
{
    MainTemplates main;
    SubTemplates sub;
    BG_SYS_ClearMainPlanes();
    BG_SYS_SetVramBanks((const struct DispVram *)d_021DA800);
    func_02082A7C(0,(void *)0x06000000,0x80000);
    func_02082A7C(0,(void *)0x06200000,0x20000);
    func_02082A7C(0,(void *)0x06400000,0x40000);
    func_02082A7C(0,(void *)0x06600000,0x20000);
    main=d_021DA638;
    BG_SYS_InitBgLayer(1,(const struct BgTemplate *)(&main.rows[0]),0);
    BG_SYS_InitBgLayer(2,(const struct BgTemplate *)(&main.rows[1]),0);
    BG_SYS_InitBgLayer(3,(const struct BgTemplate *)(&main.rows[2]),0);
    BG_SYS_ClearSlot(1); BG_SYS_ClearSlot(2); BG_SYS_ClearSlot(3);
    BG_SYS_SetMainPlaneVisible(1,0); BG_SYS_SetMainPlaneVisible(2,1); BG_SYS_SetMainPlaneVisible(4,0); BG_SYS_SetMainPlaneVisible(8,0);
    sub=d_021DA698;
    BG_SYS_InitBgLayer(4,(const struct BgTemplate *)(&sub.rows[0]),0);
    BG_SYS_InitBgLayer(5,(const struct BgTemplate *)(&sub.rows[1]),0);
    BG_SYS_InitBgLayer(6,(const struct BgTemplate *)(&sub.rows[2]),0);
    BG_SYS_InitBgLayer(7,(const struct BgTemplate *)(&sub.rows[3]),0);
    BG_SYS_ClearSlot(4); BG_SYS_ClearSlot(5); BG_SYS_ClearSlot(6); BG_SYS_ClearSlot(7);
    BG_SYS_SetSubPlaneVisible(1,1); BG_SYS_SetSubPlaneVisible(2,1); BG_SYS_SetSubPlaneVisible(4,0); BG_SYS_SetSubPlaneVisible(8,0);
    BMP_SetDisplaySwap(0);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
}







void WF2DMAP_SCENE_VBlank(int a, char *p)
{
    PALANM_TransferPalettes((struct S02021D50 *)(((struct Obj23114 *)p)->f290));
    CLACT_VBlankSystem();
}







/*
 * Extent ends with two bytes of zero alignment padding.
 */
void WF2DMAP_SCENE_SetSlot(char *p,int v)  {
    ((struct Obj01937 *)p)->f244=((struct Obj01937 *)p)->f240;
    ((struct Obj01937 *)p)->f240=v;
    ((struct Obj01937 *)p)->f248=0;
    ((struct Obj01937 *)p)->f24C=0;
    ((struct Obj01937 *)p)->f250=0;
    ((struct Obj01937 *)p)->f254=0;
    if(v)  {
        ((struct Obj01937 *)p)->f248=*(unsigned short *)(p+(v-1)*4+0x21c);
        ((struct Obj01937 *)p)->f24C=*(unsigned short *)(p+(v-1)*4+0x21e);
    }
    if(((struct Obj01937 *)p)->f244)  {
        v=((struct Obj01937 *)p)->f244;
        ((struct Obj01937 *)p)->f250=*(unsigned short *)(p+(v-1)*4+0x21c);
        ((struct Obj01937 *)p)->f254=*(unsigned short *)(p+(v-1)*4+0x21e);
    }
}






/*
 * Lever: copy the table through a second aggregate, retain its indexed read,
 * and initialize i before selecting q. The copy folds into the existing slot.
 */
void WF2DMAP_SCENE_BuildGrid(char *p)
{
    int i,j,n,sum;
    Table t;
    Table copy;
    const int *q;
    ((struct Obj01938 *)p)->f2FC=1;
    ((struct Obj01938 *)p)->f21C=0;
    n=((struct Obj01938 *)p)->f330;
    ((struct Obj01938 *)p)->f21E=n;
    ((struct Obj01938 *)p)->f220=n;
    n+=((struct Obj01938 *)p)->f334;
    ((struct Obj01938 *)p)->f222=n;
    ((struct Obj01938 *)p)->f224=n;
    ((struct Obj01938 *)p)->f226=((struct Obj01938 *)p)->f338+n;
    WF2DMAP_SCENE_SetSlot(p,1);
    for(i=0;i<3;i++) ((struct Obj01938 *)p)->f23C+=*(int *)(p+i*4+0x330);
    t=d_021DA744;
    n=0;
    copy=t;
    if(((struct Obj01938 *)p)->f330!=4) n=1;
    i=0;
    q=copy.rows[n];
    for(;i<3;i++) *(u16 *)(p+i*2+0x214)=copy.rows[n][i];
    *(u16 *)(p+i*2+0x214)=q[i-1];
    sum=0;
    for(i=0;i<2;i++) {
        sum+=*(int *)(p+i*4+0x330);
        *(int *)(p+i*28+0x150)=sum-1;
    }
    i=0;
    n=0;
    do {
        for(j=0;j<*(int *)(p+i*4+0x330);j++) {
            *(int *)(p+n*28+4)=i+1;
            n++;
        }
        i++;
    } while(n<((struct Obj01938 *)p)->f23C);
}







void WF2DMAP_SCENE_ResetState(char *p, int v)
{
    ((struct Obj08136 *)p)->f22C = v;
    ((struct Obj08136 *)p)->f230 = 0;
    ((struct Obj08136 *)p)->f234 = 0;
    ((struct Obj08136 *)p)->f238 = 0;
}






int WF2DMAP_SCENE_Start(char *p)  {
    func_021D9890(p);
    func_021DA164(p);
    func_021D9AB0(p);
    func_021DA1A8(p,0);
    func_021D9BEC(p);
    func_021D9D44(p);
    func_021DA320(p);
    func_021DA3B8(p);
    func_021DA42C((u8 *)p);
    func_021DA524((void **)(p+0x310),((struct Obj10498 *)p)->f328,4,2,19,27,4,((struct Obj10498 *)p)->f314,((struct Obj10498 *)p)->f344);
    WF2DMAP_SCENE_ResetState(p,1);
    WIPE_SYS_Start(0,1,1,0,6,1,50);
    return 0;
}






int WF2DMAP_SCENE_StepWipeIn(char *p)  {
    switch(((struct Obj10499 *)p)->f234)  {
        case 0: WIPE_SYS_Start(0,0,0,0,6,1,50);
        ((struct Obj10499 *)p)->f234+=1;
        break;
        case 1: if(WIPE_SYS_EndCheck()==1) ((struct Obj10499 *)p)->f234+=1;
        break;
        default: return 1;
    }
    return 0;
}






int WF2DMAP_SCENE_StepWaitInput(char *p)  {
    switch(((struct Obj02843 *)p)->f234)  {
        case 0: func_021DA610((void *)(((struct Obj02843 *)p)->f310),((struct Obj02843 *)p)->f328,(void *)(((struct Obj02843 *)p)->f314),((struct Obj02843 *)p)->f344);
        ((struct Obj02843 *)p)->f234+=1;
        break;
        case 1: if((KEY_GetTrg() & 2) || (KEY_GetTrg() & 1) || TOUCHPANEL_GetTrg())  {
            func_021DA578((void *)(((struct Obj02843 *)p)->f310),((struct Obj02843 *)p)->f328,(void *)(((struct Obj02843 *)p)->f314),((struct Obj02843 *)p)->f344);
            WF2DMAP_SCENE_ResetState(p,1);
        }
        break;
    }
    return 0;
}






int WF2DMAP_SCENE_StepUpdate(char *p) {if(((struct Obj00361 *)p)->f234==0){if(WIPE_SYS_EndCheck()==1)((struct Obj00361 *)p)->f234+=1;}else {func_021D9760(p);BUTTON_MAN_UpdateSlots(((struct Obj00361 *)p)->f294);WF2DMAP_SCENE_HandleInput(p);}return 0;}






int WF2DMAP_SCENE_StepAnimate(char *p)
{
    int i,n;
    char *q;
    Scale scale;
    Pair first,second;
    switch(((struct Obj00361 *)p)->f234) {
    case 0:
        func_021D9E48(p,0,0);
        for(i=0;i<((struct Obj00361 *)p)->f23C;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f18) {
                CLACT_GetActorSurfacePos(((struct Obj00411 *)q)->fC,(struct PtS *)&first,0);
                first.x+=((struct Obj00411 *)q)->f14;
                first.y+=((struct Obj00411 *)q)->f16;
                CLACT_AddActorSurfacePos(((struct Obj00411 *)q)->fC,(const struct Vec2 *)(&first),0);
                (((struct Obj00411 *)q)->f18)--;
                if(i>=((struct Obj00361 *)p)->f248 && i<((struct Obj00361 *)p)->f24C) {
                    scale.x=d_021DA830[((struct Obj00411 *)q)->f19];
                    scale.y=scale.x;
                    CLACT_SetActorScale(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                    (((struct Obj00411 *)q)->f19)++;
                }
                if(i>=((struct Obj00361 *)p)->f250 && i<((struct Obj00361 *)p)->f254) {
                    scale.x=d_021DA84C[((struct Obj00411 *)q)->f19];
                    scale.y=scale.x;
                    CLACT_SetActorScale(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                    (((struct Obj00411 *)q)->f19)++;
                }
            }
        }
        for(i=0;i<2;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f168) {
                CLACT_GetActorSurfacePos(((struct Obj00411 *)q)->f15C,(struct PtS *)&second,0);
                second.x+=((struct Obj00411 *)q)->f164;
                second.y+=((struct Obj00411 *)q)->f166;
                CLACT_AddActorSurfacePos(((struct Obj00411 *)q)->f15C,(const struct Vec2 *)(&second),0);
                (((struct Obj00411 *)q)->f168)--;
            }
        }
        if(((struct Obj00361 *)p)->f18==0) {
            for(i=((struct Obj00361 *)p)->f248;i<((struct Obj00361 *)p)->f24C;i++) {
                q=p+i*28;
                CLACT_SetActorAnimSeq(((struct Obj00411 *)q)->fC,func_021DA158(((struct Obj00411 *)q)->f0,((struct Obj00411 *)q)->f8));
            }
            for(i=((struct Obj00361 *)p)->f250;i<((struct Obj00361 *)p)->f254;i++) {
                q=p+i*28;
                CLACT_SetActorAnimSeq(((struct Obj00411 *)q)->fC,func_021DA158(((struct Obj00411 *)q)->f0,((struct Obj00411 *)q)->f8));
            }
            (((struct Obj00361 *)p)->f234)++;
        }
        (((struct Obj00361 *)p)->f238)++;
        break;
    case 1:
        for(i=((struct Obj00361 *)p)->f248;i<((struct Obj00361 *)p)->f24C;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f19!=6) {
                scale.x=d_021DA830[((struct Obj00411 *)q)->f19];
                scale.y=scale.x;
                CLACT_SetActorScale(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                (((struct Obj00411 *)q)->f19)++;
            }
        }
        for(i=((struct Obj00361 *)p)->f250;i<((struct Obj00361 *)p)->f254;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f19!=6) {
                scale.x=d_021DA84C[((struct Obj00411 *)q)->f19];
                scale.y=scale.x;
                CLACT_SetActorScale(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                (((struct Obj00411 *)q)->f19)++;
            }
        }
        (((struct Obj00361 *)p)->f238)++;
        if(((struct Obj00361 *)p)->f238==6) (((struct Obj00361 *)p)->f234)++;
        break;
    default:
        func_021DA320(p);
        if(((struct Obj00361 *)p)->f324==0) n=func_021D97CC((u8 *)p,((struct Obj00361 *)p)->f320);
        else n=func_021D97FC((u8 *)p,((struct Obj00361 *)p)->f320);
        func_021D9E60((u8 *)p,n);
        if(((struct Obj00361 *)p)->f240) func_021D9E48(p,0,1);
        func_021D97B8(p);
        WF2DMAP_SCENE_ResetState(p,1);
        break;
    }
    return 0;
}






extern int (*d_021DA718[])(char *);






int WF2DMAP_SCENE_Dispatch(char *p) { int v; v=d_021DA718[*(u32 *)(p+0x22c)](p); func_021D9F40(p); func_021DA004(p); return v; }







/*
 * 2026-10-05 (wave P2 lane Q4, pengy share, user-approved for this function only): first draft, no twin found.
 * Earlier (824 B): the flag at [sp+4] is a member of a local struct with the table (struct { int flag; Tbl t; } L);
 * rec[idx] reads go through a const SceneSlot pointer; up and left write the store in each arm.
 * 2026-10-05 (wave P2 lane Q4b, 25-compile cap): 836 bytes now, same size as the original, 21 bytes differ, all in
 * the head (first 0x34 bytes). Closed this lane: (b) the L-button block is EXACT: the store of idx - 1 is written in each
 * arm (if (idx == 0) { idx = n; p->188 = idx - 1; } else { p->188 = idx - 1; }); cross-jumping keeps the shared subs/str
 * and leaves the then-arm's b to the next instruction (docs/idioms/an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md).
 * (c) the R-button block is EXACT: idx = p->188; if (idx == p->23C - 1) store 0 else store idx + 1, store in each arm.
 * Remaining residue (a): the original emits movs r0,#0; str r0,[sp,#4] right after the row ldrsh and movs r7,#0xbf late.
 * Here the flag store comes after the final ldr r4 (flag init after cur) or before ldr r6 / row ldrsh (row as a local, flag
 * init between row and col; a pointer to the row gives 18 bytes with the store after muls). scheduling off does not change
 * the head, so the order is IR order, not the scheduler. Pragmas tried this lane with no gain: opt_propagation,
 * opt_dead_assignments, peephole, scheduling (no change), opt_common_subs (836 B but 401 bytes differ),
 * opt_lifetimes (34 differ). Tried and rejected: empty else {}, a wrap helper with (n, cur) parameter order (no change).
 * d_021DA75C has no witness outside the function (the pool word is inside it): give it an overlay token
 * in the integrator step.
 *
 * 2026-10-05 (wave P2 lane Q4c): EXACT. The flag is a plain int local (spilled to [sp+4]), not a struct member:
 * row is read into a local, then flag = 0, then cur = T.v[row][col] (IR order puts the zero store right after the row load).
 * d_021DA75C resolves with the data hint without the ov129 token (data a4).
 */
void WF2DMAP_SCENE_HandleInput(char *p)
{
    Tbl T = d_021DA75C;
    int flag;
    int row;
    int cur;
    int idx, n, k;
    const SceneSlot *r = (const SceneSlot *)p;

    row = *(short *)(p + 0x1BA);
    flag = 0;
    cur = T.v[row][*(short *)(p + 0x1B8)];

    if (*(int *)(p + 0x2FC) == 1 && KEY_GetTrg() != 0) {
        *(int *)(p + 0x2FC) = flag;
        func_021D9E98(p, cur);
        if (cur == 10 || cur == 11) {
            if (*(int *)(p + 0x1A4) == 2) return;
            *(int *)(p + 0x1A4) = 2;
            return;
        }
        if (*(int *)(p + 0x1A4) == 1) return;
        *(int *)(p + 0x1A4) = 1;
        return;
    }
    if (KEY_GetRepeat() & 0x40) {
        int v = *(short *)(p + 0x1BA);
        if (v > 0) *(short *)(p + 0x1BA) = v - 1; else *(short *)(p + 0x1BA) = 2;
        flag = 1;
    } else if (KEY_GetRepeat() & 0x80) {
        *(short *)(p + 0x1BA) += 1;
        *(short *)(p + 0x1BA) %= 3;
        flag = 1;
    } else if (KEY_GetRepeat() & 0x10) {
        if (cur == 10) *(short *)(p + 0x1B8) = 3;
        else if (cur == 11) *(short *)(p + 0x1B8) = 0;
        else {
            *(short *)(p + 0x1B8) += 1;
            *(short *)(p + 0x1B8) %= 5;
        }
        flag = 1;
    } else if (KEY_GetRepeat() & 0x20) {
        if (cur == 10) *(short *)(p + 0x1B8) = 3;
        else if (cur == 11) *(short *)(p + 0x1B8) = 0;
        else {
            int v = *(short *)(p + 0x1B8);
            if (v > 0) *(short *)(p + 0x1B8) = v - 1; else *(short *)(p + 0x1B8) = 4;
        }
        flag = 1;
    } else if (KEY_GetTrg() & 1) {
        if (cur == 10) {
            func_021D93D4((const SlotRecord *)p);
            GFL_USE_PlaySeDefaultVolume(1363);
        } else if (cur == 11) {
            if (func_021D9320((u8 *)p)) {
                func_021D9348(p);
                GFL_USE_PlaySeDefaultVolume(1357);
            } else {
                WF2DMAP_SCENE_ResetState(p, 4);
            }
        } else {
            if (*(int *)(p + 0x240) == 0) return;
            idx = *(int *)(p + 0x188);
            ((SceneSlot *)p)[idx].state = cur + 1;
            func_021D9E48(p, 1, 0);
            func_021D9E48(p, 2, 1);
            func_021D9EE8(p, cur, 2);
            CLACT_SetActorAnimSeq(r[idx].handle, func_021DA158(r[idx].state, r[idx].flag));
            CLACT_SetActorAnimSeq(*(struct Obj **)(p + 0x1CC), 3);
            n = r[idx].value;
            if (idx + 1 == *(int *)(p + 0x23C)) {
                *(int *)(p + 0x31C) = 1;
                *(int *)(p + 0x320) = 0;
                *(short *)(p + 0x1B8) = 3;
                *(short *)(p + 0x1BA) = 2;
                flag = 1;
            } else {
                k = r[idx + 1].value;
                if (n != k) {
                    *(int *)(p + 0x31C) = 1;
                    *(int *)(p + 0x320) = k;
                } else {
                    *(int *)(p + 0x31C) = 2;
                    *(int *)(p + 0x320) = idx + 1;
                }
                GFL_USE_PlaySeDefaultVolume(1356);
            }
        }
    } else if (KEY_GetTrg() & 2) {
        func_021D93D4((const SlotRecord *)p);
        GFL_USE_PlaySeDefaultVolume(1363);
    } else if (KEY_GetRepeat() & 0x200) {
        idx = *(int *)(p + 0x188);
        if (idx == 0) {
            idx = *(int *)(p + 0x23C);
            *(int *)(p + 0x188) = idx - 1;
        } else {
            *(int *)(p + 0x188) = idx - 1;
        }
        idx = *(int *)(p + 0x188);
        if (r[idx].flag == 1) {
            *(int *)(p + 0x31C) = 2;
            *(int *)(p + 0x320) = idx;
        } else {
            *(int *)(p + 0x31C) = 1;
            *(int *)(p + 0x320) = r[idx].value;
            *(int *)(p + 0x324) = 1;
        }
        GFL_USE_PlaySeDefaultVolume(1352);
    } else if (KEY_GetRepeat() & 0x100) {
        idx = *(int *)(p + 0x188);
        if (idx == *(int *)(p + 0x23C) - 1) {
            *(int *)(p + 0x188) = 0;
        } else {
            *(int *)(p + 0x188) = idx + 1;
        }
        idx = *(int *)(p + 0x188);
        if (r[idx].flag == 1) {
            *(int *)(p + 0x31C) = 2;
            *(int *)(p + 0x320) = idx;
        } else {
            *(int *)(p + 0x31C) = 1;
            *(int *)(p + 0x320) = r[idx].value;
        }
        GFL_USE_PlaySeDefaultVolume(1352);
    }
    if (flag == 1) {
        GFL_USE_PlaySeDefaultVolume(1352);
        cur = T.v[*(short *)(p + 0x1BA)][*(short *)(p + 0x1B8)];
        func_021D9E98(p, cur);
        if (cur == 10 || cur == 11) {
            if (*(int *)(p + 0x1A4) == 2) return;
            *(int *)(p + 0x1A4) = 2;
            return;
        }
        if (*(int *)(p + 0x1A4) != 1) *(int *)(p + 0x1A4) = 1;
    }
}






/*
 * Lever: expand v reads while retaining its declaration/assignment, name n*28, and initialise sum before mul.
 * Permuter found this spelling after38 candidates; baseline DIFF30 bytes; intermediate expand-v DIFF5.
 * trailing: Two zero alignment bytes.
 */
int func_021D92E4(u8 *p)
{
  int n;
  int sum;
  u32 mul;
  u32 v;
  int tmp;
  sum = 0;
  mul = 1;
  for (n = (*((int *) (p + 0x23c))) - 1; n > (-1); n--)
  {
    v = *((int *) (p + (n * 28)));
    tmp = n * 28;
    if (*((int *) (p + tmp)))
      sum += ((*((int *) (p + (n * 28)))) - 1) * mul;
    mul *= 10;
  }

  return sum;
}






/*
 * trailing: Two zero alignment bytes.
 */
int func_021D9320(u8 *p) { if(!((struct Obj14053 *)p)->f328) return 1; if(func_021D92E4(p)<=((struct Obj14053 *)p)->f344) return 1; return 0; }






void func_021D9348(char *p)  {
    int i;
    char *q;
    void *v=STRBUF_Create(100,50);
    ((struct Obj08137 *)p)->f1F8=1;
    ((struct Obj08137 *)p)->f210=0;
    for(i=0;i<((struct Obj08137 *)p)->f23C;i++)  {
        q=p+i*28;
        if(((struct Obj06479 *)q)->f0==0)  {
            ((struct Obj06479 *)q)->f0=1;
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj06479 *)q)->fC),func_021DA158(1,((struct Obj06479 *)q)->f8));
        }
        WORDSET_FormatNumber(v,((struct Obj06479 *)q)->f0-1,1,1,1);
        STRBUF_Append((struct U16Vec *)(((struct Obj08137 *)p)->f348),v);
    }
    STRBUF_Delete(v);
    WF2DMAP_SCENE_ResetState(p,3);
}





static inline unsigned clear_record(SlotRecord *q)  {
    q->state=0;
    return func_021DA158(0,q->flag);
}





void func_021D93D4(const SlotRecord *p)  {
    int i, v, next;
    ((struct Obj00912 *)p)->f1DC=1;
    ((struct Obj00912 *)p)->f1F4=0;
    if(((struct Obj00912 *)p)->f240==0)  {
        i=((struct Obj00912 *)p)->f23C-1;
        ((struct Obj00912 *)p)->f188=i;
        next=p[i].value;
        ((struct Obj00912 *)p)->f31C=1;
        ((struct Obj00912 *)p)->f320=next;
        ((struct Obj00912 *)p)->f324=1;
        return;
    }
    i=((struct Obj00912 *)p)->f188;
    CLACT_SetActorAnimSeq((struct Obj *)p[i].handle,clear_record(&((SlotRecord *)p)[i]));
    v=p[i].value;
    if(i>0)  {
        CLACT_SetActorAnimSeq((struct Obj *)p[i-1].handle,func_021DA158(p[i-1].state,p[i-1].flag));
        next=p[i-1].value;
        if(v!=next)  {
            ((struct Obj00912 *)p)->f31C=1;
            ((struct Obj00912 *)p)->f320=next;
            ((struct Obj00912 *)p)->f324=1;
            return;
        }
        ((struct Obj00912 *)p)->f31C=2;
        ((struct Obj00912 *)p)->f320=i-1;
    }
}





void func_021D9490(char *p)
{
    int i;
    Rects t;
    for(i=0;i<12;i++) *(void **)(p+i*28+16)=p+0x298+i*4;
    t=d_021DA798;
    for(;i<24;i++) {
        *(u8 *)(p+i*4+0x298)=t.rows[i-12].b-t.rows[i-12].d;
        *(u8 *)(p+i*4+0x29a)=t.rows[i-12].a-t.rows[i-12].c;
        *(u8 *)(p+i*4+0x299)=t.rows[i-12].b+t.rows[i-12].d;
        *(u8 *)(p+i*4+0x29b)=t.rows[i-12].a+t.rows[i-12].c;
    }
    ((struct Obj14055 *)p)->f2F8=255;
    ((struct Obj14055 *)p)->f294=BUTTON_MAN_Create((u8 *)(p+0x298),(int)func_021D958C,(int)p,50);
}





/*
 * lever: The two-byte table record has byte fields a and b; both pool words reference that record.
 */
void func_021D9564(u8 *p,int n) { if(n>=12 && n<24) { ((struct Obj14056 *)p)->f1B8=d_021DA72C[n-12].a; ((struct Obj14056 *)p)->f1BA=d_021DA72C[n-12].b; } }





void func_021D958C(u32 n, int touch, char *p)
{
    Record *r = (Record *)p;
    int idx, v, k;
    int m;
    if (*(int *)(p + 0x22C) != 1) return;
    if (*(int *)(p + 0x2FC) != 1) *(int *)(p + 0x2FC) = 1;
    if (touch == 0) {
        {
            if (n <= 11) {
                if (r[n].flag == 1) {
                    *(int *)(p + 0x31C) = 2;
                    *(int *)(p + 0x320) = n;
                } else {
                    *(int *)(p + 0x31C) = 1;
                    *(int *)(p + 0x320) = r[n].value;
                }
                GFL_USE_PlaySeDefaultVolume(1352);
            } else if (n == 22) {
                *(short *)(p + 0x1B8) = 0;
                *(short *)(p + 0x1BA) = 2;
                GFL_USE_PlaySeDefaultVolume(1363);
                func_021D93D4((const SlotRecord *)p);
            } else if (n == 23) {
                *(short *)(p + 0x1B8) = 3;
                *(short *)(p + 0x1BA) = 2;
                if (func_021D9320((u8 *)p)) {
                    func_021D9348(p);
                    GFL_USE_PlaySeDefaultVolume(1357);
                } else {
                    WF2DMAP_SCENE_ResetState(p, 4);
                }
            } else if (n >= 12 && n <= 21) {
                if (*(int *)(p + 0x240) == 0) return;
                GFL_USE_PlaySeDefaultVolume(1356);
                idx = *(int *)(p + 0x188);
                r[idx].state = n - 11;
                CLACT_SetActorAnimSeq(r[idx].handle, func_021DA158(r[idx].state, r[idx].flag));
                func_021D9E48(p, 1, 1);
                m = n - 12;
                func_021D9E98(p, m);
                func_021D9E48(p, 1, 0);
                func_021D9E48(p, 2, 1);
                func_021D9EE8(p, m, 2);
                CLACT_SetActorAnimSeq(*(struct Obj **)(p + 0x1CC), 3);
                v = r[idx].value;
                if (idx + 1 == *(int *)(p + 0x23C)) {
                    *(int *)(p + 0x31C) = 1;
                    *(int *)(p + 0x320) = 0;
                    *(int *)(p + 0x324) = 0;
                } else {
                    k = r[idx + 1].value;
                    if (v != k) {
                        *(int *)(p + 0x31C) = 1;
                        *(int *)(p + 0x320) = k;
                        *(int *)(p + 0x324) = 0;
                    } else {
                        *(int *)(p + 0x31C) = 2;
                        *(int *)(p + 0x320) = idx + 1;
                    }
                }
                func_021D9564((u8 *)p, n);
            } else {
                *(short *)(p + 0x1B8) = (n - 12) % 5;
                *(short *)(p + 0x1BA) = (n - 12) / 5;
            }
        }
    }
}




void func_021D9760(char *p)  {
    switch(((struct Obj00361 *)p)->f31C)  {
        case 0: break;
        case 1: WF2DMAP_SCENE_SetSlot(p,((struct Obj00361 *)p)->f320);
        func_021DA164(p);
        func_021DA1A8(p,1);
        WF2DMAP_SCENE_ResetState(p,2);
        ((struct Obj00361 *)p)->f31C=255;
        break;
        case 2: func_021D9E60((u8 *)p,((struct Obj00361 *)p)->f320);
        func_021D97B8(p);
        break;
        case 255: break;
    }
}





void func_021D97B8(char *p)
{
    ((struct Obj00361 *)p)->f31C = 0;
    ((struct Obj00361 *)p)->f320 = 0;
    ((struct Obj00361 *)p)->f324 = 0;
}




int func_021D97CC(u8 *p,int value) { int i; int count; count=((struct Obj23117 *)p)->f23C; for(i=0;i<count;i++) if(value==*(int *)(p+i*28+4)) return i; return 0; }



/*
 * trailing: Two zero alignment bytes.
 * note: 2026-10-05 the count field is read in the loop condition and again at the return (as written by hand); this closed the count/flag register swap.
 */
int func_021D97FC(u8 *p,int value) { int i; int flag=0; for(i=0;i<*(int *)(p+0x23C);i++) { if(value==*(int *)(p+i*28+4)) flag=1; else if(flag==1) return i-1; } return *(int *)(p+0x23C)-1; }



void func_021D9838(char *p,unsigned a)  {
    Config c = gClActorInitParam;
    ((unsigned char *)&c)[8] = 16;
    ((unsigned char *)&c)[9] = 112;
    CLACT_InitSystem((const struct Cfg *)(&c),a,50);
    BG_SYS_SetMainPlaneVisible(16,1);
    ((struct Obj14057 *)p)->f25C=CLACT_CreateUnit(64,0,50);
    CLACT_SetUnitDefaultRenderer(((struct Obj14057 *)p)->f25C);
}



void func_021D9890(char *p)
{
    void *pal=((struct Obj02483 *)p)->f290;
    void *arc=((struct Obj02483 *)p)->f258;
    func_02049658(arc,6,1,0,0,0,50);
    func_020498F4(arc,10,1,0,0,0,50);
    PALANM_LoadArcPaletteToSlot(pal,59,1,50,0,64,0);
    func_02049658(arc,7,5,0,0,0,50);
    func_020498F4(arc,11,5,0,0,0,50);
    func_02049B68(arc,2,4,0,0,50);
    ((struct Obj02483 *)p)->f260=CLACT_RegisterPalette(arc,0,0,0,50);
    ((struct Obj02483 *)p)->f26C=CLACT_RegisterCharacter(arc,5,0,0,50);
    ((struct Obj02483 *)p)->f284=CLACT_RegisterCellAnim(arc,12,15,50);
    ((struct Obj02483 *)p)->f268=CLACT_RegisterPalette(arc,4,0,32,50);
    ((struct Obj02483 *)p)->f274=CLACT_RegisterCharacter(arc,9,0,0,50);
    ((struct Obj02483 *)p)->f28C=CLACT_RegisterCellAnim(arc,14,17,50);
    ((struct Obj02483 *)p)->f264=CLACT_RegisterPalette(arc,3,0,64,50);
    ((struct Obj02483 *)p)->f270=CLACT_RegisterCharacter(arc,8,0,0,50);
    ((struct Obj02483 *)p)->f288=CLACT_RegisterCellAnim(arc,13,16,50);
    BMP_MENUWORK_LoadCharAndPltt(4,1,11,0,50);
    func_02049B40(23,5,4,384,32,50);
}



void func_021D99F0(char *p)  {
    int i;
    char *q;
    for(i=0;i<((struct Obj10500 *)p)->f23C;i++) CLACT_DeleteActor((struct Obj *)(*(int *)(p+i*28+12)));
    for(i=0;i<2;i++)  {
        q=p+i*28;
        CLACT_DeleteActor((struct Obj *)(((struct Obj06480 *)q)->f15C));
        CLACT_DeleteActor((struct Obj *)(((struct Obj06480 *)q)->f1E8));
    }
    for(i=0;i<3;i++) CLACT_DeleteActor((struct Obj *)(*(int *)(p+i*28+0x194)));
    func_021DA3D0((u8 *)p);
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj10500 *)p)->f310));
    for(i=0;i<3;i++)  {
        q=p+i*4;
        CLACT_ReleasePalette(((struct Obj06480 *)q)->f260);
        CLACT_ReleaseCharacter(((struct Obj06480 *)q)->f26C);
        CLACT_ReleaseCellAnim(((struct Obj06480 *)q)->f284);
    }
    CLACT_DeleteUnit((struct Bank *)(((struct Obj10500 *)p)->f25C));
    CLACT_ExitSystem();
}



void func_021D9AB0(char *p)
{
    Params s;
    int j=0;
    int h=((struct Obj02185 *)p)->f25C;
    int i,k=0;
    unsigned q;
    s.x=0; s.y=0; s.frame=0; s.speed=10; s.flag=0;
    for(i=0;i<(int)((unsigned)((struct Obj02185 *)p)->f23C+2);i++) {
        q=(unsigned)p+(unsigned)k*28;
        if(i==(int)((unsigned)k+(unsigned)((struct Obj06481 *)q)->f150+1)) {
            s.x=76+(unsigned)i*8; s.y=24; s.frame=22;
            ((struct Obj06481 *)q)->f15C=(int)CLACT_CreateActor((void *)h,((struct Obj02185 *)p)->f26C,((struct Obj02185 *)p)->f260,((struct Obj02185 *)p)->f284,&s,0,50);
            k++;
        } else {
            s.x=76+(unsigned)i*8; s.y=24;
            q=(unsigned)p+(unsigned)j*28;
            s.frame=func_021DA158(((struct Obj06481 *)q)->f0,((struct Obj06481 *)q)->f8);
            ((struct Obj06481 *)q)->fC=(int)CLACT_CreateActor((void *)h,((struct Obj02185 *)p)->f26C,((struct Obj02185 *)p)->f260,((struct Obj02185 *)p)->f284,&s,0,50);
            j++;
        }
    }
    if(((struct Obj02185 *)p)->f334==0 && ((struct Obj02185 *)p)->f338==0) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02185 *)p)->f15C,0);
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02185 *)p)->f178,0);
    }
}



void func_021D9BEC(char *p)
{
    Params s;
    int h=((struct Obj00501 *)p)->f25C;
    s.x=0; s.y=0; s.frame=0; s.speed=0; s.flag=0;
    ((struct Obj00501 *)p)->f194=(int)CLACT_CreateActor((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    ((struct Obj00501 *)p)->f1B0=(int)CLACT_CreateActor((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    ((struct Obj00501 *)p)->f1CC=(int)CLACT_CreateActor((void *)h,((struct Obj00501 *)p)->f274,((struct Obj00501 *)p)->f268,((struct Obj00501 *)p)->f28C,&s,0,50);
    func_021D9E60((u8 *)p,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00501 *)p)->f194),0);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00501 *)p)->f194,1);
    ((struct Obj00501 *)p)->f1B8=0; ((struct Obj00501 *)p)->f1BA=0;
    ((struct Obj00501 *)p)->f1A4=1;
    func_021D9E98(p,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00501 *)p)->f1B0),((struct Obj00501 *)p)->f1A4);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00501 *)p)->f1B0,1);
    CLACT_SetActorObjMode((struct Actor *)(((struct Obj00501 *)p)->f1B0),1);
    ((struct Obj00501 *)p)->f1D4=0; ((struct Obj00501 *)p)->f1D6=0;
    ((struct Obj00501 *)p)->f1C0=1;
    func_021D9E98(p,0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00501 *)p)->f1CC),((struct Obj00501 *)p)->f1C0);
    CLACT_SetActorObjMode((struct Actor *)(((struct Obj00501 *)p)->f1CC),1);
    CLACT_SetActorAutoAnim((struct Obj *)((struct Obj00501 *)p)->f1CC,1);
    func_021D9E48(p,1,0);
    func_021D9E48(p,2,0);
}




void func_021D9D44(char *p)
{
    L s;
    int h = ((struct Obj00913 *)p)->f25C;
    s.a = 0;
    s.b = 0;
    s.c = 0;
    s.d = 10;
    s.e = 0;
    ((struct Obj00913 *)p)->f1E8 = (int)CLACT_CreateActor((void *)h, ((struct Obj00913 *)p)->f270, ((struct Obj00913 *)p)->f264, ((struct Obj00913 *)p)->f288, &s.a, 0, 0x32);
    ((struct Obj00913 *)p)->f204 = (int)CLACT_CreateActor((void *)h, ((struct Obj00913 *)p)->f270, ((struct Obj00913 *)p)->f264, ((struct Obj00913 *)p)->f288, &s.a, 0, 0x32);
    s.x = (((struct Obj00913 *)p)->f2F2 + ((struct Obj00913 *)p)->f2F3) / 2;
    s.y = (((struct Obj00913 *)p)->f2F0 + ((struct Obj00913 *)p)->f2F1) / 2;
    CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj00913 *)p)->f1E8), (const struct Vec2 *)(&s), 0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00913 *)p)->f1E8), 0);
    s.x = (((struct Obj00913 *)p)->f2F6 + ((struct Obj00913 *)p)->f2F7) / 2;
    s.y = (((struct Obj00913 *)p)->f2F4 + ((struct Obj00913 *)p)->f2F5) / 2;
    CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj00913 *)p)->f204), (const struct Vec2 *)(&s), 0);
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00913 *)p)->f204), 0);
}




void func_021D9E48(char *p, int i, int a)
{
    CLACT_SetActorDrawEnable(*(void **)(p + i * 0x1c + 0x194), a);
}



/*
 * lever: Load actor into a local before the current-index store.
 */
void func_021D9E60(u8 *p,int n) { PairS16 s; void *actor; actor=*(void **)(p+n*28+12); ((struct Obj14058 *)p)->f188=n; CLACT_GetActorSurfacePos(actor,(struct PtS *)&s,0); s.y+=16; CLACT_AddActorSurfacePos(((struct Obj14058 *)p)->f194,(const struct Vec2 *)(&s),0); }



void func_021D9E98(char *p,int i)
{
    PairU16 s;
    unsigned char *q = (unsigned char *)p + (i+12)*4;
    s.x = (q[0x29a] + q[0x29b])/2;
    s.y = (q[0x298] + q[0x299])/2;
    CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj14059 *)p)->f1B0),(const struct Vec2 *)(&s),0);
    CLACT_SetActorAnimFrame((struct Obj *)(((struct Obj14059 *)p)->f1B0),0);
}



void func_021D9EE8(char *p,int i,int j)
{
    PairU16B s;
    unsigned char *q = (unsigned char *)p + (i+12)*4;
    s.x = (q[0x29a] + q[0x29b])/2;
    s.y = (q[0x298] + q[0x299])/2;
    CLACT_AddActorSurfacePos((struct Obj *)(*(int *)((p+0x194)+j*0x1c)),(const struct Vec2 *)(&s),0);
    CLACT_SetActorAnimFrame((struct Obj *)(*(int *)((p+0x194)+j*0x1c)),0);
}



void func_021D9F40(char *p)
{
    int i;
    for(i=1;i<3;i++){
        int a=CLACT_GetActorAnimSeq(*(void **)(p+i*0x1c+0x194));
        if(a==3){
            if(CLACT_IsActorAnimActive(*(void **)(p+i*0x1c+0x194))==0){
                CLACT_SetActorAnimSeq(*(void **)(p+i*0x1c+0x194),*(int *)(p+i*0x1c+0x188));
                if(((struct Obj14060 *)p)->f2FC==1) func_021D9E48(p,1,0);
                else func_021D9E48(p,1,1);
                func_021D9E48(p,2,0);
            }
        }else{
            if(a!=*(int *)(p+i*0x1c+0x188)) CLACT_SetActorAnimSeq(*(void **)(p+i*0x1c+0x194),*(int *)(p+i*0x1c+0x188));
            if(CLACT_GetActorAnimSeq(*(void **)(p+i*0x1c+0x194))!=3){
                if(((struct Obj14060 *)p)->f2FC==1) func_021D9E48(p,1,0);
                else func_021D9E48(p,1,1);
            }
        }
    }
}




void func_021D9FF0(char *p, int a, int b)
{
    if (p != 0)
        BMP_OAM_SetPos((struct Grid *)p, (short)a, (short)b);
}



/*
 * Extent ends with two bytes of zero alignment padding.
 * Lever: declare the 4-byte-stride pointer before the 28-byte-stride pointer.
 */
void func_021DA004(char *p)
{
    int i;
    char *r,*q;
    short x,y;
    for(i=0;i<2;i++) {
        r=p+i*4;
        x=((struct Obj04507 *)r)->f2F2+20;
        y=(((struct Obj04507 *)r)->f2F0+((struct Obj04507 *)r)->f2F1)/2;
        y-=7;
        q=p+i*28;
        switch(((struct Obj02186 *)q)->f1DC) {
        case 0:
            ((struct Obj02186 *)q)->f1F4=0;
            break;
        case 1:
            ((struct Obj02186 *)q)->f1F4+=1;
            if(((struct Obj02186 *)q)->f1F4==1) {
                CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj02186 *)q)->f1E8),1);
                func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
            } else if(((struct Obj02186 *)q)->f1F4==2) {
                CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj02186 *)q)->f1E8),2);
                func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
            } else if(((struct Obj02186 *)q)->f1F4==10) {
                CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj02186 *)q)->f1E8),0);
                func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
                ((struct Obj02186 *)q)->f1DC+=1;
            }
            break;
        default:
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj02186 *)q)->f1E8),0);
            func_021D9FF0(*(char * *)&((struct Obj04507 *)r)->f304,x,y);
            ((struct Obj02186 *)q)->f1DC=0;
            break;
        }
    }
}



int func_021DA158(int x,int flag) { int n; n=0; if(!flag) n=11; return n+x; }




void func_021DA164(void *p)
{
    unsigned char *b = (unsigned char *)p;
    int i;

    for (i = 0; i < ((struct Obj10501 *)b)->f23C; i++)
    {
        if (i >= ((struct Obj10501 *)b)->f248 && i < ((struct Obj10501 *)b)->f24C)
            *(int *)(b + i * 0x1c + 8) = 1;
        else
            *(int *)(b + i * 0x1c + 8) = 0;
    }
}



/*
 * Lever: declare i before y, initialise j after loading y, and keep the equality arm separate.
 */
void func_021DA1A8(char *p,int animate)
{
    Position s;
    int i,j;
    short y=*(short *)((unsigned)p+(unsigned)((struct Obj03283 *)p)->f240*2+0x214);
    unsigned q;
    j=0;
    for(i=0;i<((struct Obj03283 *)p)->f23C;i++) {
        if(i>=((struct Obj03283 *)p)->f248 && i<((struct Obj03283 *)p)->f24C) {
            if(i==((struct Obj03283 *)p)->f248) y+=20;
            else y+=32;
        } else {
            if(i==0) y+=20;
            else y+=8;
        }
        q=(unsigned)p+(unsigned)i*28;
        CLACT_GetActorSurfacePos((struct Actor *)((struct Obj02187 *)q)->fC,(struct PtS *)&s.z,0);
        if(animate==0) {
            s.z=y;
            CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj02187 *)q)->fC),(const struct Vec2 *)(&s.z),0);
        } else {
            ((struct Obj02187 *)q)->f14=(y-s.z)/4;
            ((struct Obj02187 *)q)->f16=0;
            ((struct Obj02187 *)q)->f18=4;
            ((struct Obj02187 *)q)->f19=0;
        }
        q=(unsigned)p+(unsigned)j*28;
        if(i==((struct Obj02187 *)q)->f150 && j!=2) {
            CLACT_GetActorSurfacePos((struct Actor *)((struct Obj02187 *)q)->f15C,(struct PtS *)&s,0);
            if(((struct Obj03283 *)p)->f248==((struct Obj03283 *)p)->f24C) y+=8;
            else {
                if(i>((struct Obj03283 *)p)->f248 && i<((struct Obj03283 *)p)->f24C) y+=20;
                else y+=8;
            }
            if(animate==0) {
                s.x=y;
                CLACT_AddActorSurfacePos((struct Obj *)(((struct Obj02187 *)q)->f15C),(const struct Vec2 *)(&s),0);
            } else {
                ((struct Obj02187 *)q)->f164=(y-s.x)/4;
                ((struct Obj02187 *)q)->f166=0;
                ((struct Obj02187 *)q)->f168=4;
            }
            j++;
        }
    }
}



void func_021DA320(char *p)
{
    int i;
    int x,y;
    PairS16B s;
    for(i=0;i<((struct Obj10502 *)p)->f23C;i++){
        if(i>=((struct Obj10502 *)p)->f248 && i<((struct Obj10502 *)p)->f24C){
            x=16;
            y=16;
        }else{
            x=4;
            y=8;
        }
        CLACT_GetActorSurfacePos(*(void **)(p+i*0x1c+12),(struct PtS *)&s,0);
        (*(u8 **)(p+i*0x1c+16))[0]=s.y-y;
        (*(u8 **)(p+i*0x1c+16))[2]=s.x-x;
        (*(u8 **)(p+i*0x1c+16))[1]=s.y+y;
        (*(u8 **)(p+i*0x1c+16))[3]=s.x+x;
    }
}




void func_021DA3B8(char *p)
{
    void *x = BMP_OAM_CreateSys(0x32, ((struct Obj14061 *)p)->f25C);

    ((struct Obj14061 *)p)->f300 = x;
}



void func_021DA3D0(u8 *p) { CLACT_ReleasePalette(((struct Obj08140 *)p)->f30C); BMP_OAM_Delete(*(struct Grid * *)&((struct Obj08140 *)p)->f304); BMP_OAM_Delete(*(struct Grid * *)&((struct Obj08140 *)p)->f308); BMP_OAM_DeleteSys(((struct Obj08140 *)p)->f300); }



void func_021DA3FC(u8 *p) { void *f; f=func_020490F4(23,50); ((struct Obj23118 *)p)->f30C=CLACT_RegisterPaletteCompressed(f,5,0,128,50); ARC_TOOL_DeleteHandle(f); }



/*
 * prototype: Original calls visibly load r2/r3 and outgoing stack zero; retain those arguments despite the matched callee declaring only two.
 */
void func_021DA42C(u8 *p) { int zero; func_021DA3FC(p); zero=0; func_021DA454(p,0,78,165,zero); func_021DA454(p,1,172,165,zero); }



/*
 * lever: Expand each coordinate base at its read; binding the base to a
 * pointer local swaps r2/r3 and leaves six bytes different.
 */
void func_021DA454(u8 *p, int i, int a2, int a3, int a4)
{
    void *bank,*msg,*bmp;
    struct Param q;
    short y;
    u16 x;
    int zero=0;
    bank=func_02045B38(0,2,25,50);
    msg=func_02045EC0(bank,i+3);
    bmp=BMP_Create(10,2,32,50);
    PRINTSYS_PrintColor(bmp,(80-(int)func_0201D304(msg,*(u32 *)&((struct Obj08141 *)p)->f314,0))/2,0,msg,((struct Obj08141 *)p)->f314,0x3dc0);
    x=(p+(i+22)*4)[0x29a]+20;
    y=((p+(i+22)*4)[0x298]+(p+(i+22)*4)[0x299])/2;
    q.bmp=bmp;
    q.x=x;
    q.y=y-7;
    q.f8=((struct Obj08141 *)p)->f264;
    q.fc=zero;
    q.f10=zero;
    q.f11=zero;
    q.f12=zero;
    q.f14=zero;
    *(void **)(p+0x304+i*4)=BMP_OAM_Create(((struct Obj08141 *)p)->f300,&q);
    BMP_OAM_UploadChars(*(void **)(p+0x304+i*4));
    BMP_Delete(bmp);
    STRBUF_Delete(msg);
    MSGDATA_Delete(bank);
}



/*
 * extent: Two zero alignment bytes at 0x021DA576; next labelled function is 0x021DA578.
 */
void func_021DA524(void **p,int a,int b,int c,int d,int e,int f,int g,int h)
{
    *p=(void *)BMP_WIN_Create((u8)b,(u8)c,(u8)d,(u8)e,f,12,1);
    BMP_MENUWORK_DrawWindow(*p,2,1,11);
    BMP_WIN_MakeScreen(*p);
    func_021DA578(*p,a,(void *)g,h);
}



void func_021DA578(void *p,int a,void *b,u32 c)
{
    void *ws=GF_FONT_Create_EC64(50);
    void *bank=func_02045B38(0,2,25,50);
    void *msg=func_02045EC0(bank,a);
    void *out=STRBUF_Create(88,50);
    WORDSET_SetSlotNumber(ws,0,c,2,2,1);
    WORDSET_CopyTaggedText(ws,out,msg);
    BMP_Clear(BMP_WIN_GetBmp(p),15);
    PRINTSYS_Print(BMP_WIN_GetBmp(p),0,0,out,b);
    STRBUF_Delete(out);
    STRBUF_Delete(msg);
    MSGDATA_Delete(bank);
    WORDSET_DeleteStrbufED04(ws);
    BMP_WIN_TransferChars(p);
    func_020409B4(4);
}


void func_021DA610(void *p, int sel, void *b, unsigned int c)
{
    if (sel == 1) {
        func_021DA578(p, 5, b, c);
        return;
    }
    if (sel == 2)
        func_021DA578(p, 6, b, c);
}
