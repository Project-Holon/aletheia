/*
 * file:     chihou_zukan_award.c
 * unit:     yes
 * function: func_021B95A0, func_021B9748, func_021B97C4, CHIHOU_ZUKAN_AWARD_LoadBgAssets, CHIHOU_ZUKAN_AWARD_Noop, CHIHOU_ZUKAN_AWARD_SetupWindows, CHIHOU_ZUKAN_AWARD_DeleteWindows, CHIHOU_ZUKAN_AWARD_FlushWindows, CHIHOU_ZUKAN_AWARD_SetupTiles, CHIHOU_ZUKAN_AWARD_CreateActor, CHIHOU_ZUKAN_AWARD_DeleteActor, CHIHOU_ZUKAN_AWARD_SetupActorPos, CHIHOU_ZUKAN_AWARD_UpdateActor, CHIHOU_ZUKAN_AWARD_IsActorIdle, CHIHOU_ZUKAN_AWARD_Setup3d
 * address:  0x021B95A0
 * region:   ov221
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
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_Create 0x021B9E78 thumb ov221
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_0204047C 0x0204047C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02012944 0x02012944 thumb
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0207D518 0x0207D518 arm
 *   BG_SYS_ClearSubBgPlanes 0x02043558 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   tbl_021BA148 0x021BA148 data a4
 *   tbl_021BA2C0 0x021BA2C0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_02030EAC 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete 0x021B9F20 thumb ov221
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   d_021BA148 0x021BA148 data a4
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_Update 0x021B9F7C thumb ov221
 *   FADE_IsActive 0x0204E804 arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_020409B4 0x020409B4 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200873C 0x0200873C thumb
 *   CONFIG_GetAppliedFlag 0x020083E4 thumb
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   func_02045B38 0x02045B38 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   BMP_GetWidth 0x020437DC arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   d_021BA174 0x021BA174 data a1
 *   BMP_WIN_Delete 0x020452E8 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02040E78 0x02040E78 arm
 *   BMP_WIN_GetCharOffset 0x02045768 arm
 *   func_02041090 0x02041090 arm
 *   d_021BA2D8 0x021BA2D8 data a1
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CHIHOU_ZUKAN_AWARD_GRAPHIC_GetActor 0x021B9F90 thumb ov221
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021BA140 0x021BA140 data a2
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   func_02040618 0x02040618 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_02040804 0x02040804 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BA200 0x021BA200 data a2
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   GFL_USE_IsBgmFading  0x02005E50  thumb  arm9
 *   GFL_USE_PushBgm  0x02005E64  thumb  arm9
 *   GFL_USE_PopBgm  0x02005E9C  thumb  arm9
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb  arm9
 */
#include "../../matched/include/Obj02557.h"
#include "../../matched/include/Obj02558.h"
#include "../../matched/include/Obj26065.h"
#include "../../matched/include/Obj26066.h"
#include "../../matched/include/Obj08452.h"
#include "../../matched/include/Obj08453.h"
#include "../../matched/include/Obj06724.h"
#include "../../matched/include/Obj01592.h"
#include "../../matched/include/G_Vec2.h"
#include "../../matched/include/Obj02558.h"
#include "../../matched/include/Obj26068.h"
#include "../../matched/include/Obj26069.h"
#include "../../matched/include/Obj26070.h"

#define REG3D (*(volatile unsigned short *)0x04000060)
struct BgTemplate;
struct Obj;
struct Obj0203159C;
struct GfFont;
struct Node;
struct PrintSys;
struct S020315D4;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
struct Actor;
struct PtS;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u32 id;u8 cfg[32];u32 type,enable;} Row;

typedef struct {u32 a,b,c;} Assets;

typedef enum { BG_MODE0=0, BG_MODE1=1 } BGMode;

typedef enum { LAYER_FIRST=0,LAYER_LIMIT=1 } Layer;

typedef short s16;

struct Obj {
    u16 heap; u16 pad2; void **info; u32 pad8;
    void *str; void *bmp; u8 pad14[4];
    void *bank; void *ptr[5]; u32 done[5];
};

typedef signed int     s32;

typedef enum Bool { BOOL_FALSE=0,BOOL_TRUE=1 } Bool;

typedef enum { SHADING1 = 1 } GXShading;

typedef int BOOL;

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void*,int,u32);
extern void *CHIHOU_ZUKAN_AWARD_GRAPHIC_Create(u32,u32);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void*);
extern void func_0204047C(int,u16);
extern void *func_020056A0(u32,void*,u32);
extern char *func_02012944(void*);
extern void BG_SYS_ClearSubPlanes(void),BG_SYS_ClearSubBgPlanes(void),func_0207D518(BGMode);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(u8);
extern void func_02040588(u8,u8);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void*,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void*,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void*);
extern void FADE_Start(u32,int,int,int),func_020409B4(u32),GFL_NET_RestartWithDefaultTimeout(u32,u32),GFL_USE_FadeOutBgm(u32);
extern void func_020403F4(u32 i);
extern void func_02030EAC(struct Node *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete(char *);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int);
extern void CHIHOU_ZUKAN_AWARD_GRAPHIC_Update(char *p);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPlayerParam(void*);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,unsigned short);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32);
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(unsigned char);
extern u32 TOUCHPANEL_GetPointTrg(u32*,u32*);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void func_020409B4(unsigned);
extern void ARC_UTIL_UploadPaletteFromArchive(u32,u32,u32,u32,u32,u32,u16);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void BMP_WIN_Delete(struct Descriptor *);
extern void MSGDATA_Delete(struct Rec *);
extern unsigned PRINTSYS_QUE_IsExistTarget(struct PrintSys *,void *);
extern void *func_02030734(u32,u32,int,const char*,u16);
extern u32 func_020307B0(void *p);
extern void func_02040E78(u32,void*,u32,u32);
extern u16 BMP_WIN_GetCharOffset(struct Descriptor *p);
extern void func_02041090(u32,u32,u32,u32,u8,u8);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern unsigned CHIHOU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p);
extern struct Obj *CLACT_CreateActor(void *,unsigned,unsigned,unsigned,const void *,unsigned short,unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern unsigned func_02040804(unsigned);
extern void BG_SYS_ResetSlot(unsigned,unsigned,unsigned);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void G3X_SetFog(BOOL,int,int,int);
extern void G3X_SetClearColor(unsigned short,int,int,int,BOOL);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);
int func_021B95A0(void *owner,void *unused,void *input);
int func_021B9748(void *owner,void *unused1,void *unused2,char *p);
int func_021B97C4(int unused, int *state, int unused2, unsigned char *p);
void CHIHOU_ZUKAN_AWARD_Task(void);
void CHIHOU_ZUKAN_AWARD_LoadBgAssets(unsigned char *p);
void CHIHOU_ZUKAN_AWARD_Noop(char *p);
void CHIHOU_ZUKAN_AWARD_SetupWindows(struct Obj *p);
void CHIHOU_ZUKAN_AWARD_DeleteWindows(char *p);
void CHIHOU_ZUKAN_AWARD_FlushWindows(unsigned char *p);
int CHIHOU_ZUKAN_AWARD_IsWindowsReady(unsigned char *p);
void CHIHOU_ZUKAN_AWARD_SetupTiles(char *p);
void CHIHOU_ZUKAN_AWARD_CreateActor(unsigned char *p);
void CHIHOU_ZUKAN_AWARD_DeleteActor(char *p);
void CHIHOU_ZUKAN_AWARD_SetupActorPos(char *p);
void CHIHOU_ZUKAN_AWARD_UpdateActor(unsigned char *p);
Bool CHIHOU_ZUKAN_AWARD_IsActorIdle(char *p);
void CHIHOU_ZUKAN_AWARD_Setup3d(void);
extern const Row tbl_021BA148[];
extern Assets tbl_021BA2C0[];
extern const unsigned d_021BA148[][11];
extern const u8 d_021BA174[];
extern char d_021BA2D8[];
extern struct Vec2 d_021BA140;
extern const unsigned short d_021BA200[][4];




int func_021B95A0(void *owner,void *unused,void *input)
{
 char *p,*settings;
 BGMode i;
 int selected,zero;
 const Row *row;
 u32 id;
 u16 heap;
 void *h;
 GFL_HEAP_CreateChildHeap((u32)((void*)1),131,0x30000);
 p=PROCSYS_AllocProcWork(owner,88,131);
 i=BG_MODE0;
 MI_CpuFill8(p,i,88);
 *(u16*)p=131;
 *(void**)(p+4)=input;
 *(void**)(p+8)=CHIHOU_ZUKAN_AWARD_GRAPHIC_Create(1,*(u16*)p);
 *(void**)(p+12)=GF_FONT_Create(23,0,0,0,*(u16*)p);
 *(u32*)(p+16)=PRINTSYS_QUE_Create((void*)*(u16*)p);
 func_0204047C(1,1);func_0204047C(2,0);
 *(void**)(p+20)=func_020056A0((u32)CHIHOU_ZUKAN_AWARD_Task,p,1);
 CHIHOU_ZUKAN_AWARD_LoadBgAssets((u8*)p);CHIHOU_ZUKAN_AWARD_SetupWindows((struct Obj *)p);CHIHOU_ZUKAN_AWARD_SetupTiles(p);CHIHOU_ZUKAN_AWARD_CreateActor((u8*)p);
 settings=func_02012944(*(void**)(*(char**)(p+4)));
 *(volatile u16*)0x04001050=i;
 *(volatile u32*)0x04001000 &= ~0xe000u;
 *(volatile u32*)0x04001000 |= 0x10000;
 BG_SYS_ClearSubPlanes();func_0207D518(i);BG_SYS_ClearSubBgPlanes();
 do {
  row=&tbl_021BA148[i];id=row->id;
  BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)row->cfg,(u8)row->type);func_020414AC(id);func_02040588(id,row->enable);
  i++;
 } while((u32)i<1u);
 BG_SYS_SetSubPlaneVisible(16,1);
 heap=*(u16*)p;
 selected=1;if(*(u8*)(settings+29)!=1) selected=0;
 h=func_020490F4(30,heap);
 zero=0;
 func_02049B68(h,tbl_021BA2C0[selected].a,4,zero,zero,heap);
 func_02049658(h,tbl_021BA2C0[selected].b,4,zero,zero,zero,heap);
 func_020498F4(h,tbl_021BA2C0[selected].c,4,zero,zero,zero,heap);
 ARC_TOOL_DeleteHandle(h);func_020409B4(4);CHIHOU_ZUKAN_AWARD_SetupActorPos((char *)p);
 FADE_Start(3,16,16,0);GFL_NET_RestartWithDefaultTimeout(0,*(u16*)p);
 if(*(int*)(*(char**)(p+4)+4)==0) GFL_USE_FadeOutBgm(6);
 return 1;
}




int func_021B9748(void *owner,void *unused1,void *unused2,char *p)
{
    Layer i=LAYER_FIRST;
    do {
        func_020403F4((unsigned char)d_021BA148[i][0]);
        i++;
    } while((unsigned)i<1);
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    CHIHOU_ZUKAN_AWARD_DeleteActor(p);
    CHIHOU_ZUKAN_AWARD_DeleteWindows(p);
    CHIHOU_ZUKAN_AWARD_Noop(p);
    func_02030EAC(*(struct Node * *)&((struct Obj02557 *)p)->f14);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj02557 *)p)->f10);
    PRINTSYS_QUE_Delete(((struct Obj02557 *)p)->f10);
    GF_FONT_Delete(((struct Obj02557 *)p)->fC);
    CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete(*(char * *)&((struct Obj02557 *)p)->f8);
    func_020315D4((struct S020315D4 *)owner);
    func_020306F0(0x83);
    return 1;
}




int func_021B97C4(int unused, int *state, int unused2, unsigned char *p)
{
 int ready;
 u32 x,y;
 switch(*state) {
 case 0:
  ready=1;
  if(CHIHOU_ZUKAN_AWARD_IsWindowsReady(p)==0) ready=0;
  if(ready && ((struct Obj26065 *)(*(char* *)&((struct Obj02558 *)p)->f4))->f4==0) {
   if(GFL_USE_IsBgmFading()) ready=0;
   else {GFL_USE_SetBgmPlayerParam((void*)1);GFL_USE_PushBgm();GFL_USE_CancelChangeAndPlayBgm(0x524,0xffff);}
  }
  if(ready) {FADE_Start(3,16,0,0);*state=1;}
  break;
 case 1:
  if(!FADE_IsActive()) {if(((struct Obj26066 *)(*(char* *)&((struct Obj02558 *)p)->f4))->f4!=0) *state=4;else *state=2;}
  break;
 case 2: if(CHIHOU_ZUKAN_AWARD_IsActorIdle((char *)p)) *state=3; break;
 case 3:
  if(!GFL_USE_IsBgmPlaying()) {GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);GFL_USE_FadeInBgmFull(6);*state=4;}
  break;
 case 4:
  ready=0;
  if(KEY_GetTrg()&3) {func_020355D8(0);ready=1;}
  else if(TOUCHPANEL_GetPointTrg(&x,&y)) {func_020355D8(1);ready=1;}
  if(ready) {*state=5;FADE_Start(3,0,16,0);}
  break;
 case 5: if(!FADE_IsActive()) *state=6; break;
 case 6: return 1;
 }
 PRINTSYS_QUE_Main(*(void* *)&((struct Obj02558 *)p)->f10);
 CHIHOU_ZUKAN_AWARD_FlushWindows(p);
 if(*state>=1 && *state<=5) CHIHOU_ZUKAN_AWARD_UpdateActor(p);
 CHIHOU_ZUKAN_AWARD_GRAPHIC_Update(*(void* *)&((struct Obj02558 *)p)->f8);
 return 0;
}




void CHIHOU_ZUKAN_AWARD_Task(void) {}




void CHIHOU_ZUKAN_AWARD_LoadBgAssets(unsigned char *p)
{
    void *h=func_020490F4(0xCA,((struct Obj08452 *)p)->f0);
    func_02049B68((void *)((unsigned)h),1,0,0,0x1E0,((struct Obj08452 *)p)->f0);
    func_02049658((void *)((unsigned)h),4,1,0,0,0,((struct Obj08452 *)p)->f0);
    func_020498F4((void *)((unsigned)h),6,1,0,0,0,((struct Obj08452 *)p)->f0);
    ARC_TOOL_DeleteHandle(h);
    func_020409B4(1);
}




void CHIHOU_ZUKAN_AWARD_Noop(char *p){}




void CHIHOU_ZUKAN_AWARD_SetupWindows(struct Obj *p)
{
    u8 i;
    char *msg;
    u32 ws, x, t;
    msg = func_02012944(*p->info);
    p->bank = 0;
    for (i = 0; i < 5; i++) {
        p->ptr[i] = 0;
        p->done[i] = 0;
    }
    p->done[0] = 1;
    p->done[1] = 1;
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 0, 0, 0x1e0, 0x20, p->heap);
    p->bank = func_02045B38(0, 3, 1, p->heap);
    for (i = 0; i < 5; i++) {
        p->ptr[i] = (void *)BMP_WIN_Create(d_021BA174[i*9], d_021BA174[i*9+1], d_021BA174[i*9+2], d_021BA174[i*9+3], d_021BA174[i*9+4], d_021BA174[i*9+5], d_021BA174[i*9+6]);
        BMP_Clear(BMP_WIN_GetBmp(p->ptr[i]), 0);
        BMP_WIN_TransferChars(p->ptr[i]);
    }
    ws = (u32)GF_FONT_Create_EC64(p->heap);
    t = (u32)func_02045EC0(p->bank, 0);
    x = (u32)STRBUF_Create(0x20, p->heap);
    func_0201F02C((struct WordSet *)ws, 0, msg);
    func_0201F250((struct WordSet *)ws, (void *)x, (void *)t);
    PRINTSYS_PrintQueColor(p->bmp, (u32)BMP_WIN_GetBmp(p->ptr[2]), 0, 0, x, (u32)p->str, 0x440);
    STRBUF_Delete((struct U16Vec *)x);
    STRBUF_Delete((struct U16Vec *)t);
    WORDSET_DeleteStrbufED04((struct WordSet *)ws);
    t = (u32)func_02045EC0(p->bank, 1);
    PRINTSYS_PrintQueColor(p->bmp, (u32)BMP_WIN_GetBmp(p->ptr[3]), 0, 0, t, (u32)p->str, 0x440);
    STRBUF_Delete((struct U16Vec *)t);
    t = (u32)func_02045EC0(p->bank, 3);
    PRINTSYS_PrintQueColor(p->bmp, (u32)BMP_WIN_GetBmp(p->ptr[4]), 0, 0, t, (u32)p->str, 0x440);
    STRBUF_Delete((struct U16Vec *)t);
    for (i = 1; i < 5; i++) {
        void *d = p->ptr[i];
        BMP_WIN_TransferChars(d);
        BMP_WIN_MakeScreen(d);
        func_02041B6C(BMP_WIN_GetBgLayer(d));
    }
    CHIHOU_ZUKAN_AWARD_FlushWindows((unsigned char *)p);
}




void CHIHOU_ZUKAN_AWARD_DeleteWindows(char *p){unsigned char i;for(i=0;i<5;i++){struct Descriptor *q=*(struct Descriptor **)((unsigned)p+i*4+28);if(q)BMP_WIN_Delete(q);}if(*(struct Rec * *)&((struct Obj02557 *)p)->f18)MSGDATA_Delete(*(struct Rec * *)&((struct Obj02557 *)p)->f18);}




void CHIHOU_ZUKAN_AWARD_FlushWindows(unsigned char *p)
{
    unsigned char i;
    unsigned char *row;
    struct Descriptor *resource;
    for(i=0;i<5;i++) {
        row=p+4*i;
        if(((struct Obj08453 *)row)->f30==0 && PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj02558 *)p)->f10,BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj08453 *)row)->f1C))==0) {
            resource=*(struct Descriptor * *)&((struct Obj08453 *)row)->f1C;
            BMP_WIN_TransferChars(resource);
            BMP_WIN_MakeScreen((struct Cfg *)resource);
            func_02041B6C(BMP_WIN_GetBgLayer(resource));
            ((struct Obj08453 *)row)->f30=1;
        }
    }
}




int CHIHOU_ZUKAN_AWARD_IsWindowsReady(unsigned char *p)
{
    unsigned char i;
    for(i=0;i<5;i++) if(*(int *)(p+0x30+4*i)==0) return 0;
    return 1;
}




void CHIHOU_ZUKAN_AWARD_SetupTiles(char *p)
{
 u16 *tiles;
 u16 *buf;
 u16 index;
 unsigned long tile;
 u8 x,y;
 buf=func_02030734(((struct Obj06724 *)p)->f0,32,1,d_021BA2D8,0x391);
 index=0;
 buf[0]=0;
 buf[1]=0x256c;
 buf[2]=0x4a74;
 buf[3]=0;
 func_02040E78(2,buf,32,480);
 func_020307B0(buf);
 BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct Obj06724 *)p)->f20),3);
 BMP_WIN_TransferChars(*(void* *)&((struct Obj06724 *)p)->f20);
 tiles=func_02030734(((struct Obj06724 *)p)->f0,1536,1,d_021BA2D8,0x3a2);
 tile=BMP_WIN_GetCharOffset(*(void* *)&((struct Obj06724 *)p)->f20)|0xf000;
 for(y=0;y<24;y++) for(x=0;x<32;x++) {tiles[index]=tile;index++;}
 func_02041090(2,(u32)tiles,0,24,32,24);
 func_020409B4(2);
 func_020307B0(tiles);
}




void CHIHOU_ZUKAN_AWARD_CreateActor(unsigned char *p)
{
    void *h=func_020490F4(0xCA,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f4C=CLACT_RegisterPaletteEx((void *)((unsigned)h),0,0,0,0,2,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f48=CLACT_RegisterCharacter((void *)((unsigned)h),3,0,0,((struct Obj01592 *)p)->f0);
    *(int *)&((struct Obj01592 *)p)->f50=CLACT_RegisterCellAnim((void *)((unsigned)h),8,9,((struct Obj01592 *)p)->f0);
    ARC_TOOL_DeleteHandle(h);
    *(struct Obj * *)&((struct Obj01592 *)p)->f54=CLACT_CreateActor((void *)CHIHOU_ZUKAN_AWARD_GRAPHIC_GetActor(((struct Obj01592 *)p)->f8),((struct Obj01592 *)p)->f48,((struct Obj01592 *)p)->f4C,((struct Obj01592 *)p)->f50,&d_021BA140,0,((struct Obj01592 *)p)->f0);
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01592 *)p)->f54,1);
    CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct Obj01592 *)p)->f54,1);
}





void CHIHOU_ZUKAN_AWARD_DeleteActor(char *p)
{
    CLACT_DeleteActor(((struct Obj02557 *)p)->f54);
    CLACT_ReleaseCellAnim((u32)(((struct Obj02557 *)p)->f50));
    CLACT_ReleaseCharacter((u32)(((struct Obj02557 *)p)->f48));
    CLACT_ReleasePalette((u32)(((struct Obj02557 *)p)->f4C));
}


/*
 * note: final push 2026-10-05 G1L9: EXACT. The table is read through a block-local short pointer, the same form as the twin ov222 021B9D84 (an integer address local also matched)
 *   and both halfwords are read through it; the plain extern field reads gave base r1 / x r2 (4 B off). Earlier DIFF tries
 *   (struct copy, short[2], const, pragmas, byte-offset casts, etc.) are superseded. Also unchanged 4 B this pass: brace
 *   initialiser, inline setter, int y temp, short x/y locals, d[0] array extern, struct pointer local, u16 local struct.
 *   Idiom: a pool word reloaded before every field access (u32 gb = (u32)&d_X, read through a cast) from the wave brief.
 */
void CHIHOU_ZUKAN_AWARD_SetupActorPos(char *p)
{
    if(*(unsigned *)(*(unsigned char **)(p+4)+4)==0) {
        struct Vec2 v;
        short *t;
        func_02040618(1,3,0x40);
        func_02040618(2,3,0x40);
        t=(short *)&d_021BA140;
        v.x=t[0];
        v.y=t[1]-64;
        CLACT_AddActorSurfacePos(*(struct Obj **)(p+0x54),&v,0);
        p[0x44]=0;
    }
}


void CHIHOU_ZUKAN_AWARD_UpdateActor(unsigned char *p)
{
    int amount;
    if(((struct Obj26068 *)(*(unsigned char * *)&((struct Obj02558 *)p)->f4))->f4!=0) return;
    amount=func_02040804(1);
    if(!amount) return;
    if(p[0x44]==0) {
        struct Vec2 pair;
        if(amount>=2) amount=2;
        BG_SYS_ResetSlot(1,5,amount);
        BG_SYS_ResetSlot(2,5,amount);
        CLACT_GetActorSurfacePos((struct Actor *)*(struct Obj * *)&((struct Obj02558 *)p)->f54,(struct PtS *)&pair,0);
        pair.y+=(short)amount;
        CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj02558 *)p)->f54,&pair,0);
        p[0x44]=0;
        return;
    }
    p[0x44]--;
}



Bool CHIHOU_ZUKAN_AWARD_IsActorIdle(char *p){int flag;Bool result;if(((struct Obj26070 *)(*(char * *)&((struct Obj26069 *)p)->f4))->f4)return BOOL_TRUE;flag=1;if(func_02040804(1))flag=0;result=BOOL_FALSE;if(flag)result=BOOL_TRUE;return result;}



static inline void Shading(GXShading mode) { REG3D=(unsigned short)((REG3D & ~0x3002)|(mode<<1)); }



static inline void AntiAlias(BOOL enable) { if(enable) REG3D=(unsigned short)((REG3D & ~0x3000)|0x10); else REG3D &= (unsigned short)~0x3010; }



static inline void AlphaTest(BOOL enable,int ref) { if(enable) { REG3D=(unsigned short)((REG3D & ~0x3000)|4); *(volatile unsigned short *)0x04000340=ref; } else REG3D &= (unsigned short)~0x3004; }



static inline void AlphaBlend(BOOL enable) { if(enable) REG3D=(unsigned short)((REG3D & ~0x3000)|8); else REG3D &= (unsigned short)~0x3008; }



static inline void EdgeMarking(BOOL enable) { if(enable) REG3D=(unsigned short)((REG3D & ~0x3000)|0x20); else REG3D &= (unsigned short)~0x3020; }



void CHIHOU_ZUKAN_AWARD_Setup3d(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1,1);
    *(volatile unsigned short *)0x04000008 = *(volatile unsigned short *)0x04000008 & ~3;
    Shading(SHADING1);
    AntiAlias(0);
    AlphaTest(0,0);
    AlphaBlend(1);
    EdgeMarking(0);
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,0x7FFF,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((unsigned char)i,d_021BA200[i]);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
