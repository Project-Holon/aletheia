/*
 * file:     comm_btl_demo_main.c
 * unit:     yes
 * function: func_021B95A0, func_021B96C0, func_021B9740, func_021B9794, func_021B9830, func_021B9858, func_021B9864, func_021B98A0, func_021B98DC, func_021B98EC, func_021B9A68, func_021B9A84, func_021B9B0C, func_021B9D4C, func_021B9D80, func_021B9E08, func_021B9E28, func_021B9E50, func_021B9E80, func_021B9EB0, func_021B9EE4, func_021BA014, func_021BA034, func_021BA14C, func_021BA1C0, func_021BA1C8, func_021BA200, func_021BA268, func_021BA2E0, func_021BA2F0, func_021BA30C, func_021BA330, func_021BA38C, func_021BA408, func_021BA444, func_021BA480, func_021BA4BC, func_021BA514, func_021BA5A0, func_021BA624, func_021BA650, func_021BA68C, func_021BA6C8, func_021BA710, func_021BA71C, func_021BA750, func_021BA780, func_021BA7B8, func_021BA7D0, func_021BA81C, func_021BA8BC, func_021BA8D4, func_021BA8E8, func_021BA8F4, func_021BA920, func_021BA95C, func_021BA9AC, func_021BA9C0, func_021BA9D0, func_021BAA20, func_021BAA8C, func_021BAABC
 * address:  0x021B95A0
 * region:   ov213
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   complete 0x0204E804 arm
 *   overlayLoad 0x02034AC4 arm
 *   heapCreate 0x0203064C arm
 *   create 0x0203159C arm
 *   clear 0x02082BCC arm
 *   initialize 0x021BAA20 thumb ov213
 *   video 0x021BAB64 thumb ov213
 *   font 0x0201D7EC thumb
 *   messages 0x02045B38 arm
 *   text 0x0201C440 thumb
 *   modeFor 0x021B9E28 thumb ov213
 *   dispatch 0x021B6100 thumb ov067
 *   callbacks 0x021BB02C data ov213 a4
 *   graphics 0x021B9794 thumb ov213
 *   menu 0x021BA780 thumb ov213
 *   cursor 0x021BA6C8 thumb ov213
 *   music 0x0203D34C arm
 *   fade 0x0204E720 arm
 *   ov067_id 0x00000043 data a1
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   UI_SCENE_Delete 0x021B613C thumb ov067
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   COMM_BTL_DEMO_GRAPHIC_Delete 0x021BAC0C thumb ov213
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   overlay_id 0x00000043 data a1
 *   UI_SCENE_Step 0x021B6144 thumb ov067
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   COMM_BTL_DEMO_GRAPHIC_Draw 0x021BAC68 thumb ov213
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021BAF14 0x021BAF14 data a4
 *   UI_SCENE_SetNextScene 0x021B61F8 thumb ov067
 *   func_02048A18 0x02048A18 arm
 *   d_021BB004 0x021BB004 data ov213 a4
 *   getState 0x021B61FC thumb ov067
 *   advance 0x021B6200 thumb ov067
 *   tick 0x021BA444 thumb ov213
 *   code 0x021BA81C thumb ov213
 *   test 0x021B9E50 thumb ov213
 *   select 0x021BA95C thumb ov213
 *   first 0x021B9864 thumb ov213
 *   second 0x021B98A0 thumb ov213
 *   reset 0x021BA480 thumb ov213
 *   busy 0x021BA9D0 thumb ov213
 *   soundFor 0x021B98DC thumb ov213
 *   sound 0x020061E4 thumb
 *   animate 0x021BA8E8 thumb ov213
 *   records 0x021BB0A4 data a4
 *   UI_SCENE_GetPhaseFrame 0x021B61FC thumb ov067
 *   UI_SCENE_AdvancePhaseFrame 0x021B6200 thumb ov067
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   FADE_Start 0x0204E720 arm
 *   d0 0x021BB0D4 data a4
 *   d1 0x021BB0E0 data ov213
 *   d2 0x021BB068 data ov213
 *   d3 0x021BB074 data ov213
 *   d4 0x021BB080 data ov213
 *   d5 0x021BB098 data a4
 *   FADE_IsActive 0x0204E804 arm
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   zero 0x021BB08C data ov213
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02008500 0x02008500 thumb
 *   func_02008550 0x02008550 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_021BA30C 0x021BA30C thumb ov213
 *   func_02008DF0 0x02008DF0 thumb
 *   GFL_NET_GetGameKind 0x0203D5D4 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   COMM_BTL_DEMO_GRAPHIC_GetCamera 0x021BAC94 thumb ov213
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   func_0207D63C 0x0207D63C arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   PARTICLE_InitManager 0x02050B80 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   COMM_BTL_DEMO_GRAPHIC_Draw3d 0x021BAC7C thumb ov213
 *   COMM_BTL_DEMO_GRAPHIC_DrawEnd 0x021BAC88 thumb ov213
 *   PARTICLE_Main 0x02050BE8 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_ReleaseCamera 0x02051758 arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   BUTTON_MAN_GetResourceType 0x02051B04 arm
 *   func_020056BC 0x020056BC thumb
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   d_021BB324 0x021BB324 data a4
 *   d_021BB330 0x021BB330 data a4
 *   d_021BB360 0x021BB360 data a4
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   PARTICLE_DeleteSystem 0x02050DB8 arm
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   G3D_SYSTEM_GetObjectRender 0x02047788 arm
 *   G3D_SYSTEM_GetRenderTexRes 0x02047554 arm
 *   G3D_SYSTEM_GetRenderObj 0x0204755C arm
 *   func_02047250 0x02047250 arm
 *   NNS_G3dReleaseMdlPltt 0x0206A67C arm
 *   NNS_G3dBindMdlPlttEx 0x0206A5B4 arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   d_021BB0F8 0x021BB0F8 data a4
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   d_021BB320 0x021BB320 data a4
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BB1A8 0x021BB1A8 data a2
 */
#include "../../matched/include/Obj06704.h"
#include "../../matched/include/Obj02549.h"
#include "../../matched/include/Obj25687.h"
#include "../../matched/include/Obj25688.h"
#include "../../matched/include/Obj25689.h"
#include "../../matched/include/Obj02260.h"
#include "../../matched/include/Obj01295.h"
#include "../../matched/include/Obj25690.h"
#include "../../matched/include/Obj14692.h"
#include "../../matched/include/Obj25691.h"
#include "../../matched/include/Obj14693.h"
#include "../../matched/include/Obj25692.h"
#include "../../matched/include/Obj00443.h"
#include "../../matched/include/Obj25696.h"
#include "../../matched/include/Obj25698.h"
#include "../../matched/include/Obj25699.h"
#include "../../matched/include/Obj25700.h"
#include "../../matched/include/Obj08419.h"
#include "../../matched/include/Obj14694.h"
#include "../../matched/include/Obj25701.h"
#include "../../matched/include/Obj25702.h"
#include "../../matched/include/Obj25703.h"
#include "../../matched/include/Obj03939.h"
#include "../../matched/include/Obj25704.h"
#include "../../matched/include/Obj25705.h"
#include "../../matched/include/Obj25706.h"
#include "../../matched/include/Obj25707.h"
#include "../../matched/include/Obj25708.h"
#include "../../matched/include/Obj04630.h"
#include "../../matched/include/Obj14695.h"
#include "../../matched/include/Obj14696.h"
#include "../../matched/include/Obj10929.h"
#include "../../matched/include/Obj10931.h"
#include "../../matched/include/Obj04631.h"
#include "../../matched/include/Obj02925.h"
#include "../../matched/include/Obj10930.h"
#include "../../matched/include/Obj25709.h"
#include "../../matched/include/Obj25710.h"
#include "../../matched/include/Obj25711.h"
#include "../../matched/include/Obj02551.h"
#include "../../matched/include/Obj08420.h"
#include "../../matched/include/Obj08421.h"
#include "../../matched/include/Obj10932.h"
#include "../../matched/include/Obj25712.h"

#define REG3D (*(volatile unsigned short *)0x04000060)
struct Rec;
struct PrintSys;
struct S020315D4;
struct S;
struct Obj;
struct C;
struct U16Vec;
struct Sub0200852CObj;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Sub02008C20Obj;
struct Dst648;
struct G3dSys;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Args { u8 pad[0x40]; u32 a40,a44,a48,a4C,a50; };

struct Obj { u16 heap,pad2; struct Args *args; u8 pad8[0x49B4-8]; void *video,*font,*text,*messages,*dispatch; u8 mode,pad49C9[3]; u32 x49CC; };

typedef struct {unsigned a,b,c;} Entry;

typedef struct Context_021B95A0 Context_021B95A0;

struct Resource {u32 f0, f4; u8 *util; u16 index;};

typedef struct Util Util;

struct Sub {u32 a,b;Util *util;u16 index;};

struct Record { int a,b,c; };

struct Table { struct Record a; u32 callback[3]; struct Record b,c; u8 gap[24]; struct Record d; };

struct V {int x,y,z;};

typedef signed short s16_021B95A0;

struct C {void *owner,*parent; u8 kind,index,n,count; void *obj[6]; int step; u8 active; u8 pad[3]; const u8 *types;};

typedef struct {const char *owner;void *a,*b;int c;unsigned char kind,index;char pad12[2];unsigned v14;void *v18;unsigned v1C;char sub[48];int v50;} Context_021BA14C;

struct Context_021B95A0 {int pad0;char *owner;char pad8[0x4834];Context_021BA14C rows[4];char pad498C[0x2C];int c;char pad49BC[12];u8 kind;char pad49C9[15];u8 flag;};

enum Count {CountZero,CountTwo=2,CountFour=4};

typedef struct {int pad0;const void *owner;void *other;u16 a,b;void *one,*two,*objects[3];char pad24[2];u8 kind;} Context;

typedef struct { int f0, f4, f8, fC; } Out;

typedef struct { int f0; u32 f4; int f8, fC, f10, f14, f18; u8 b1c,b1d,b1e; } In;

typedef struct { u32 x,y,z; } VecFx32;

typedef struct { u32 m[9]; } MtxFx33;

struct Arg { VecFx32 pos,v0c; MtxFx33 m18; };

struct Src648 {u32 f00,f04,f08,f0c,f10,f14,f18,f1c;};

typedef short s16_021BA408;

typedef struct { void *resTbl; u16 resCount; void *objTbl; u16 objCount; } Setup;

typedef enum { SHADING1 = 1 } GXShading;

typedef int BOOL;

extern int complete(void);
extern int overlayLoad(int);
extern void heapCreate(u32,u32,u32);
extern void *create(void *,u32,u32);
extern void clear(void *,u32,u32);
extern void initialize(u8 *);
extern void *video(u32,u32);
extern void *font(int,int,int,int,u32);
extern void *messages(u32,u32,u32,u32);
extern void *text(u32);
extern int modeFor(const char *);
extern void *dispatch(u32,const void *,u8,u32,void *);
extern void graphics(int,u16,int);
extern void menu(char *,void *,int);
extern void cursor(char *,void *,int);
extern void music(u32,u32);
extern void fade(u32,int,int,int);
extern void BG_SYS_ResetSlot(u32,u32,u32);
extern void UI_SCENE_Delete(void *);
extern void MSGDATA_Delete(struct Rec *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void GF_FONT_Delete(void *);
extern void func_021BA710(char *),func_021BA7B8(char *),COMM_BTL_DEMO_GRAPHIC_Delete(unsigned char *);
extern void PROCSYS_FreeProcWork(struct S020315D4 *);
extern void func_020306F0(u32);
extern void GF_OVERLAY_Unload(int);
extern void COMM_BTL_DEMO_GRAPHIC_Draw(char *p);
extern int UI_SCENE_Step(struct S *s);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *,unsigned,unsigned,unsigned,unsigned,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void UI_SCENE_SetNextScene(unsigned char *task, int value);
extern u32 func_02048A18(u8 *, int);
extern u32 getState(const u8 *);
extern void advance(u8 *);
extern void tick(char *);
extern void code(u8 *,u32);
extern int test(u32);
extern void select(u8 *,int);
extern void first(u8 *);
extern void second(char *);
extern void reset(char *);
extern int busy(u8 *);
extern int soundFor(int,int);
extern void sound(int);
extern int animate(char *,int,const struct Record *);
extern u32 UI_SCENE_GetPhaseFrame(const unsigned char*);
extern void UI_SCENE_AdvancePhaseFrame(unsigned char*);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void*,u32);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v),CLACT_SetActorBgPriority(void*,u32);
extern void CLACT_ChangeActorAnimSeq(struct Obj *p, u16 v);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02008500(void *,void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PRINTSYS_Print(void *x, s16_021B95A0 y, s16_021B95A0 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
void func_021BA30C();
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern u32 GFL_NET_GetGameKind(void);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v),CLACT_SetActorAutoAnim(void *,unsigned);
extern u32 COMM_BTL_DEMO_GRAPHIC_GetCamera(char *p);
extern void UI_SCENE_LoadActorGfx(Out *out, In *in, int unused, unsigned heap);
extern void UI_SCENE_FreeActorGfx(unsigned int *p);
extern void *UI_SCENE_CreateActor(void *,int,unsigned char,unsigned char,unsigned char,unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v),CLACT_SetActorDrawPriority(void *,unsigned);
extern void func_0207D63C(void *,int,int,int,int),PARTICLE_InitManager(unsigned);
extern void *G3D_UTIL_Create(unsigned,unsigned,unsigned);
extern void G3D_UTIL_Delete(struct Rec *p);
extern void COMM_BTL_DEMO_GRAPHIC_Draw3d(char *p);
extern void COMM_BTL_DEMO_GRAPHIC_DrawEnd(char *p);
extern void PARTICLE_Main(void);
extern void MTX_Identity33_(MtxFx33 *p);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern int PARTICLE_CreateSystemDefault(int a,int b,int c,int d);
extern int PARTICLE_ReleaseCamera(int a);
extern void PARTICLE_InitCamera(struct Dst648 *p,struct Src648 *src,u16 a2,int *a3,int *a4,int *a5,u32 heap);
extern int PARTICLE_LoadArchiveMember(u32 a,u32 b,u32 c);
extern u16 BUTTON_MAN_GetResourceType(void *res);
extern u32 func_020056BC(void);
extern void PARTICLE_SetupSystem(u8 *o,u32 a1,u32 a2,u32 a3);
extern void PARTICLE_KillAllEffects(u8 *);
extern void PARTICLE_DeleteSystem(u8 *);
extern void PARTICLE_ExitManager(void);
extern int PARTICLE_StartEffect(void *,int,int);
extern int G3D_SYSTEM_GetObjectRender(int *),G3D_SYSTEM_GetRenderTexRes(int *),G3D_SYSTEM_GetRenderObj(int *);
extern int func_02047250(char *);
extern void NNS_G3dReleaseMdlPltt(char *);
extern int NNS_G3dBindMdlPlttEx(char *,char *,u32,u32);
extern u16 G3D_UTIL_AddUnit(Util *util, const Setup *setup);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern void G3D_UTIL_RemoveUnit(struct Ctx *,u32);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void G3X_SetFog(BOOL, int, int, int);
extern void G3X_SetClearColor(unsigned short, int, int, int, BOOL);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned, unsigned);
int func_021B95A0(void *manager,int *state,struct Args *args);
int func_021B96C0(struct S020315D4 *owner,int unused,const void *cfg,char *p);
int func_021B9740(int a,int b,int c,char *p);
void func_021B9794(int a,u16 heap,int index);
void func_021B9830(u8 *task, char *p);
int func_021B9858(void *unused, Context_021B95A0 *p);
void func_021B9864(u8 *p);
void func_021B98A0(char *p);
int func_021B98DC(int a, int b);
int func_021B98EC(u8 *task,char *p);
int func_021B9A68(u8 *task,void *p);
int func_021B9A84(int unused,char *p);
int func_021B9B0C(unsigned char *state,unsigned char *p);
int func_021B9D4C(u8 *task,char *p);
int func_021B9D80(void *state,char *p);
int func_021B9E08(void *a,void *b);
int func_021B9E28(const char *p);
int func_021B9E50(u32 x);
int func_021B9E80(u32 x);
int func_021B9EB0(void *p,u32 x);
void func_021B9EE4(struct C *p,void *owner,u8 kind,u8 index,void *a,void *parent,const u8 *types);
void func_021BA014(u8 *p);
void func_021BA034(struct C *p, u32 time);
void func_021BA14C(char *p,unsigned limit);
void func_021BA1C0(char *p);
void func_021BA1C8(char *p,void *list,const u8 *flags,int index);
unsigned func_021BA200(unsigned kind,unsigned index);
void func_021BA268(Context_021BA14C *p,unsigned char kind,unsigned char index,const char *owner,void *a,void *b,int c);
void func_021BA2E0(char *a);
void func_021BA2F0(u8 *p);
void func_021BA330(void *p, int a);
void func_021BA38C(Context_021B95A0 *p);
void func_021BA408(char *p);
void func_021BA444(char *p);
void func_021BA480(char *p);
void func_021BA4BC(void *p,int kind,int variant);
void func_021BA514(char *p);
void func_021BA5A0(Context *p,const void *owner,void *other,u16 a,u16 b,u8 kind);
void func_021BA624(char *p);
void func_021BA650(char *p);
void func_021BA68C(char *p,unsigned i,int kind);
void func_021BA6C8(char *p, void *state, short heap);
void func_021BA710(char *p);
void *func_021BA71C(char *p,int a,int b,unsigned short c);
void *func_021BA750(void *p,int kind,unsigned a);
void func_021BA780(char *p,void *state,short heap);
void func_021BA7B8(char *p);
void func_021BA7D0(unsigned char *p);
void func_021BA81C(u8 *p,unsigned code);
void func_021BA8BC(char *p, int object);
void func_021BA8D4(char *p);
int func_021BA8E8(char *p,int b,int c);
void func_021BA8F4(char *p,int v);
int func_021BA920(int *p,u32 b,u32 c);
void func_021BA95C(unsigned char *p, int index);
void func_021BA9AC(char *p);
void func_021BA9C0(void *a);
int func_021BA9D0(unsigned char *p);
void func_021BAA20(unsigned char *p);
int func_021BAA8C(char *p);
void func_021BAABC(void);
extern const char callbacks[];
extern const char ov067_id[];
extern char overlay_id[];
extern const Entry d_021BAF14[];
extern int d_021BB004[];
extern const struct Table records;
extern const struct V d0,d1,d2,d3,d4,d5;
extern struct V zero;
extern int d_021BB324[],d_021BB330[],d_021BB360[];
extern const Setup d_021BB0F8[];
extern int d_021BB320;
extern const unsigned short d_021BB1A8[][4];














int func_021B95A0(void *manager,int *state,struct Args *args)
{
    struct Obj *p;
    if(*state==1 && complete()==1) return 1;
    overlayLoad((int)ov067_id);
    heapCreate(1,116,0x80000);
    p=create(manager,0x49D8,116);
    clear(p,0,0x49D8);
    p->heap=116;
    p->args=args;
    p->mode=(u8)args->a44;
    p->x49CC=p->args->a40;
    initialize((u8 *)args);
    p->video=video(0,p->heap);
    p->font=font(23,0,0,0,p->heap);
    p->messages=messages(0,2,65,p->heap);
    p->text=text(p->heap);
    p->dispatch=dispatch(p->heap,callbacks,3,modeFor((char *)args),p);
    graphics((int)((char *)p+8),p->heap,p->args->a50);
    menu((char *)p+0x24,p->video,p->heap);
    cursor((char *)p+0xC,p->video,p->heap);
    *(volatile u16 *)0x04000304 |= 0x8000;
    music(0,p->heap);
    fade(3,16,0,1);
    *state=1;
    return 0;
}














int func_021B96C0(struct S020315D4 *owner,int unused,const void *cfg,char *p) {
u16 heap;
BG_SYS_ResetSlot(3,0,0);
if(*(int *)((unsigned)cfg+0x44)==2 || *(int *)((unsigned)cfg+0x44)==4)func_021BA514(p);
UI_SCENE_Delete(((struct Obj06704 *)p)->f49C4);
MSGDATA_Delete(*(void **)((unsigned)p+0x49c0));
PRINTSYS_QUE_Delete(((struct Obj06704 *)p)->f49BC);
GF_FONT_Delete(*(void **)((unsigned)p+0x49b8));
func_021BA710(p+0xc);func_021BA7B8(p+0x24);
COMM_BTL_DEMO_GRAPHIC_Delete(((struct Obj06704 *)p)->f49B4);
heap=*(u16 *)p;PROCSYS_FreeProcWork(owner);func_020306F0(heap);GF_OVERLAY_Unload((int)overlay_id);return 1;
}














int func_021B9740(int a,int b,int c,char *p)
{
    func_021BA7D0((unsigned char *)(p+0x24));
    if(UI_SCENE_Step(((struct Obj06704 *)p)->f49C4)) return 1;
    PRINTSYS_QUE_Main(((struct Obj06704 *)p)->f49BC);
    COMM_BTL_DEMO_GRAPHIC_Draw(((struct Obj06704 *)p)->f49B4);
    (((struct Obj06704 *)p)->f49D4)++;
    BG_SYS_ResetSlot(3,0,((struct Obj06704 *)p)->f49D4/2);
    return 0;
}














/*
 * prototype: 49238 asm body saves entry r0 and forwards it to destructors; retain caller's resource argument.
 */
void func_021B9794(int a,u16 heap,int index)
{
    void *p;
    p=func_020490F4(181,heap);
    func_02049B68(p,d_021BAF14[index].a,0,0,0,heap);
    func_02049658(p,d_021BAF14[index].b,3,0,0,0,heap);
    func_020498F4(p,d_021BAF14[index].c,3,0,0,0,heap);
    func_02049B68(p,4,4,0,0,heap);
    func_02049658(p,3,6,0,0,0,heap);
    func_020498F4(p,5,6,0,0,0,heap);
    ARC_TOOL_DeleteHandle(p);
}














void func_021B9830(u8 *task, char *p) {
    func_021BA408(p);
    func_021BA624(p + 0x498C);
    UI_SCENE_SetNextScene(task,65534);
}














int func_021B9858(void *unused, Context_021B95A0 *p) { func_021BA38C(p); return 1; }














void func_021B9864(u8 *p) {
    void *object;
    int i;
    struct Resource *sub;
    sub = (struct Resource *)(p+0x24);
    object = (void *)func_02048A18(sub->util, sub->index);
    for(i=0;i<2;i++) {
        int state = 1;
        if (*(u32 *)(p+0x4850+i*0x54)) state = 2;
        func_021BA920(object,i+1,state);
    }
}














void func_021B98A0(char *p) {int *object;int i;struct Sub *sub;sub=(struct Sub *)(p+0x24);object=(int *)func_02048A18((u8 *)sub->util,sub->index);for(i=0;i<4;i++){int value=1;if(*(u32 *)(p+0x4850+i*0x54))value=3;func_021BA920(object,i+1,value);}}















int func_021B98DC(int a, int b)
{
    return *(int *)((char *)d_021BB004 + a * 8 + b * 4);
}














int func_021B98EC(u8 *task,char *p)
{
    u32 state;
    struct Record a,b,c,d;
    state=getState(task);
    tick(p);
    switch(state) {
    case 0:
        code((u8 *)p+0x24,13);
        if(test(((struct Obj02549 *)p)->f49C8)) {
            select((u8 *)p+0x24,0);
            first((u8 *)p);
        } else {
            select((u8 *)p+0x24,2);
            second(p);
        }
        reset(p);
        advance(task);
        break;
    case 1:
        if(busy((u8 *)p+0x24)==0) {
            select((u8 *)p+0x24,4);
            if(((struct Obj25687 *)(*(char * *)&((struct Obj02549 *)p)->f4))->f50) code((u8 *)p+0x24,11);
            else code((u8 *)p+0x24,10);
            ((struct Obj02549 *)p)->f49D0=0;
            advance(task);
        }
        break;
    case 2:
        busy((u8 *)p+0x24);
        if(((struct Obj02549 *)p)->f49D0==15) {
            sound(soundFor(1,((struct Obj25688 *)(*(char * *)&((struct Obj02549 *)p)->f4))->f50));
            a=records.a; animate(p+0x24,0,&a);
            b=records.d; animate(p+0x24,1,&b);
            c=records.b; animate(p+0x24,2,&c);
        } else if(((struct Obj02549 *)p)->f49D0==25) {
            d=records.c; animate(p+0x24,3,&d);
        } else if(((struct Obj02549 *)p)->f49D0==160) { fade(12,0,16,-3);
        } else if(((struct Obj02549 *)p)->f49D0==150) { sound(soundFor(3,((struct Obj25689 *)(*(char * *)&((struct Obj02549 *)p)->f4))->f50));
        } else if(((struct Obj02549 *)p)->f49D0==168) {return 1;
        }
        (((struct Obj02549 *)p)->f49D0)++;
        break;
    }
    return 0;
}














int func_021B9A68(u8 *task,void *p) {func_021BA408((char *)p);UI_SCENE_SetNextScene(task,65534);return 1;}












int func_021B9A84(int unused,char *p)
{
    u16 a,b;
    func_021BA38C((Context_021B95A0 *)p);
    if(func_021B9E50(((struct Obj02260 *)p)->f49C8)) {
        a=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4);
        b=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4+16);
    } else {
        a=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4);
        a+=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4+16);
        b=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4+32);
        b+=func_021BAA8C(*(char * *)&((struct Obj02260 *)p)->f4+48);
    }
    func_021BA5A0((Context *)(p+0x498C), p+0xC, p+0x24, a, b, ((struct Obj02260 *)p)->f49C8);
    return 1;
}











int func_021B9B0C(unsigned char *state,unsigned char *p)
{
    int stage,x,y,index;
    struct V v0,v1,v2,v3,v4,v5;
    stage=UI_SCENE_GetPhaseFrame(state);
    func_021BA444((char *)p);func_021BA650((char *)(p+0x498c));
    switch(stage){
    case 0:
        if(func_021B9E50(p[0x49c8]))func_021BA95C(p+0x24,1);
        else func_021BA95C(p+0x24,3);
        func_021BA81C(p+0x24,0xd);
        func_021BA480((char *)p);UI_SCENE_AdvancePhaseFrame((unsigned char *)state);break;
    case 1:
        if(func_021BA9D0(p+0x24)==0){
            if(((struct Obj01295 *)p)->f49CC==2)return 1;
            ((struct Obj01295 *)p)->f49D0=0;
            func_021BA81C(p+0x24,0xc);UI_SCENE_AdvancePhaseFrame(state);
        }break;
    case 2:
        if(((struct Obj01295 *)p)->f49D0==15){
            index=((struct Obj01295 *)p)->f49CC!=0;
            GFL_USE_PlaySeDefaultVolume(func_021B98DC(2,((struct Obj25690 *)(*(unsigned char* *)&((struct Obj01295 *)p)->f4))->f50));
            func_021BA68C((char *)(p+0x498c),index,0);
        }else if(((struct Obj01295 *)p)->f49D0==24){
            index=((struct Obj01295 *)p)->f49CC!=0;
            CLACT_SetActorDrawEnable(*(void**)((u32)p+(u32)index*4+0x499c),0);
        }else if(((struct Obj01295 *)p)->f49D0==45){
            index=((struct Obj01295 *)p)->f49CC!=1;
            func_021BA68C((char *)(p+0x498c),index,1);
        }else if(((struct Obj01295 *)p)->f49D0==54){
            index=((struct Obj01295 *)p)->f49CC!=1;
            CLACT_SetActorDrawEnable(*(void**)((u32)p+(u32)index*4+0x499c),0);
        }else if(((struct Obj01295 *)p)->f49D0==120)FADE_Start(3,0,16,-3);
        else if(((struct Obj01295 *)p)->f49D0==128)return 1;
        if(((struct Obj01295 *)p)->f49D0%180==0){
            if(((struct Obj01295 *)p)->f49CC==1){x=-0x2800;y=0x2000;}
            else{x=0x2800;y=-0x1800;}
            v0=d0;v0.x=x;v0.y=y;func_021BA8E8((char *)(p+0x24),0,(int)(&v0));
            v1=d1;v1.x=x;v1.y=y;func_021BA8E8((char *)(p+0x24),1,(int)(&v1));
            v2=d2;v2.x=x;v2.y=y;func_021BA8E8((char *)(p+0x24),2,(int)(&v2));
            v3=d3;v3.x=x;v3.y=y;func_021BA8E8((char *)(p+0x24),3,(int)(&v3));
            v4=d4;v4.x=x;v4.y=y;func_021BA8E8((char *)(p+0x24),4,(int)(&v4));
            v5=d5;v5.x=x;v5.y=y;func_021BA8E8((char *)(p+0x24),5,(int)(&v5));
        }
        (((struct Obj01295 *)p)->f49D0)++;break;
    }
    return 0;
}











int func_021B9D4C(u8 *task,char *p) {if(((struct Obj14692 *)p)->f49CC==2){GFL_USE_PlaySeDefaultVolume(func_021B98DC(4,((struct Obj25691 *)(*(char * *)&((struct Obj14692 *)p)->f4))->f50));UI_SCENE_SetNextScene(task,2);return 1;}func_021B9830(task,p);return 1;}











int func_021B9D80(void *state,char *p)
{
    int stage;
    stage=UI_SCENE_GetPhaseFrame(state);
    func_021BA444(p);func_021BA650(p+0x498C);
    switch(stage) {
    case 0:
        func_021BA95C((unsigned char *)(p+0x24),5);((struct Obj14693 *)p)->f49D0=0;UI_SCENE_AdvancePhaseFrame(state);break;
    case 1:
        if((((struct Obj14693 *)p)->f49D0)++==30) func_021BA68C(p+0x498C,2,2);
        if(func_021BA9D0((unsigned char *)(p+0x24))==0) {FADE_Start(3,0,16,-3);return 1;}
        break;
    case 2:break;
    }
    return 0;
}










int func_021B9E08(void *a,void *b) {if(FADE_IsActive()==1)return 0;func_021B9830(a,b);return 1;}










int func_021B9E28(const char *p) {switch(((struct Obj25692 *)p)->f44){case 1:case 3:return 0;case 2:case 4:return 1;case 0:default:return 0;}}










int func_021B9E50(u32 x) {switch(x){case 1:return 1;case 2:return 1;case 3:return 0;case 4:return 0;case 0:default:return 1;}}










int func_021B9E80(u32 x) {switch(x){case 1:return 1;case 2:return 0;case 3:return 1;case 4:return 0;case 0:default:return 1;}}








int func_021B9EB0(void *p,u32 x) {if(!p)return 13;switch(x){case 3:return 13;case 0:return 10;case 1:return 11;case 2:return 12;default:return 10;}}







/*
 * lever: negative constant multiplication keeps Thumb shift/negate/add; unary negation is folded back into constant-minus-shift.
 * POKEPARTY_GetCount 0x0201AA18 thumb
 * POKEPARTY_GetMember 0x0201AB28 thumb
 * func_021B9E50 0x021B9E50 thumb ov213
 * func_021B9E80 0x021B9E80 thumb ov213
 * func_021B9EB0 0x021B9EB0 thumb ov213
 * func_021BA71C 0x021BA71C thumb ov213
 * CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
void func_021B9EE4(struct C *p,void *owner,u8 kind,u8 index,void *a,void *parent,const u8 *types)
{
    int i,x,y,frame;
    void *entry;
    p->kind=kind;p->index=index;p->owner=owner;
    p->n=POKEPARTY_GetCount(owner);
    if(func_021B9E50(kind))p->count=6;else p->count=3;
    p->parent=parent;p->step=0;p->types=types;
    for(i=0;i<p->count;i++){
        if(func_021B9E50(kind)){
            x=(s16_021B95A0)((i<<4)+0x88);
            y=(s16_021B95A0)(index==0?0xa8:0x38);
            if(index==0)x*=-1;
        }else{
            switch(index){
            case 0:x=(s16_021B95A0)(i * -16+0x50);y=0x88;break;
            case 1:x=(s16_021B95A0)(i * -16+0x90);y=0xb0;break;
            case 2:x=(s16_021B95A0)((i<<4)+0x80);y=0x30;break;
            case 3:x=(s16_021B95A0)((i<<4)+0xc0);y=0x58;break;
            }
        }
        entry=0;
        if(i<p->n)entry=POKEPARTY_GetMember(owner,i);
        frame=func_021B9EB0(entry,types[i]);
        if(!func_021B9E80(kind)&&frame!=0xd)frame=0xa;
        p->obj[i]=func_021BA71C(a,x,y,(u16)frame);
        if(func_021B9E80(kind))CLACT_SetActorDrawEnable(p->obj[i],0);
        else CLACT_SetActorDrawEnable(p->obj[i],1);
    }
}






void func_021BA014(u8 *p) {int i;for(i=0;i<p[11];i++)CLACT_DeleteActor((struct Obj *)(*(u32 *)(p+12+i*4)));}





void func_021BA034(struct C *p, u32 time)
{
    int i=p->step-time;
    int x,y;
    struct V pos;
    if(i < p->count) {
        if(i==0 && p->index==0) GFL_USE_PlaySeDefaultVolume(func_021B98DC(0,0));
        if(func_021B9E50(p->kind)) {
            if(p->index==0){x=-0x400-(i<<11);y=-0x2500;}
            else if(p->index==1){x=(i<<11)+0x300;y=0x1300;}
        } else {
            if(p->index==0){x=-0x1800-(i<<11);y=-0x1500;}
            else if(p->index==1){x=0x800-(i<<11);y=-0x2800;}
            else if(p->index==2){x=(i<<11)-0x100;y=0x1800;}
            else if(p->index==3){x=(i<<11)+0x1f00;y=0x300;}
        }
        pos=zero; pos.x=x; pos.y=y;
        func_021BA8F4(p->parent,(int)(&pos));
        if(func_021B9E80(p->kind)) CLACT_SetActorDrawEnable(p->obj[i],1);
        else func_021BA1C8((char *)p,p->owner,p->types,p->count-1-i);
    } else {
        for(i=0;i<p->count;i++) CLACT_SetActorBgPriority(p->obj[i],1);
        p->active=0;
    }
}





void func_021BA14C(char *p,unsigned limit)
{
    if(((struct Obj00443 *)p)->f28) {
        switch(((struct Obj00443 *)p)->f8) {
        case 0:break;
        case 1:limit=12;break;
        case 3:
            if(((struct Obj00443 *)p)->f9==0 || ((struct Obj00443 *)p)->f9==2) limit=15;
            else if(((struct Obj00443 *)p)->f9==1 || ((struct Obj00443 *)p)->f9==3) limit=19;
            break;
        case 2:limit=8;break;
        case 4:
            if(((struct Obj00443 *)p)->f9==0 || ((struct Obj00443 *)p)->f9==2) limit=11;
            else if(((struct Obj00443 *)p)->f9==1 || ((struct Obj00443 *)p)->f9==3) limit=15;
            break;
        }
        if(((struct Obj00443 *)p)->f24>=limit) func_021BA034((struct C *)p,limit);
        (((struct Obj00443 *)p)->f24)++;
    }
}





void func_021BA1C0(char *p) {p[0x28]=1;}





void func_021BA1C8(char *p,void *list,const u8 *flags,int index) {void *entry=0;int value;if(index<(int)POKEPARTY_GetCount(list))entry=POKEPARTY_GetMember(((struct Obj25696 *)p)->f0,index);value=func_021B9EB0(entry,flags[index]);CLACT_ChangeActorAnimSeq((struct Obj *)(*(u32 *)(p+12+index*4)),value);}





unsigned func_021BA200(unsigned kind,unsigned index)
{
    int x,y;
    if(func_021B9E50(kind)) {
        if(index==0) {x=4;y=17;}
        else {x=16;y=3;}
    } else {
        switch(index) {
        case 0:x=5;y=13;break;
        case 1:x=13;y=19;break;
        case 2:x=15;y=1;break;
        case 3:x=23;y=7;break;
        }
    }
    return BMP_WIN_Create(1,(unsigned char)x,(unsigned char)y,10,3,1,1);
}





/*
 * extent: 021BA2DE..021BA2E0 is two zero alignment bytes; following021BA2E0 already filed separately.
 * lever: logical owner,a,b,c,zero field order restores stack-load scheduling; const owner and typed destination alone did not.
 */
void func_021BA268(Context_021BA14C *p,unsigned char kind,unsigned char index,const char *owner,void *a,void *b,int c)
{
    void *first,*second;
    int value;
    value=c;first=a;second=b;
    p->owner=owner;p->a=first;p->b=second;
    p->c=value;p->v50=0;
    p->kind=kind;p->index=index;
    func_021B9EE4((struct C *)p->sub,((struct Obj25698 *)owner)->f0,kind,index,a,b,(const unsigned char *)(owner+10));
    p->v18=STRBUF_Create(16,116);
    func_02008500(((struct Obj25699 *)(p->owner))->f4,p->v18);
    p->v14=func_02008550(((struct Obj25700 *)(p->owner))->f4);
    p->v1C=func_021BA200(kind,index);
    if(func_021B9E80(p->kind)==0) func_021BA330(p,p->c);
}






void func_021BA2E0(char *a)
{
    if (*(int *)&((struct Obj08419 *)a)->f50 == 0x2d)
        func_021BA330(a, ((struct Obj08419 *)a)->fC);
}





void func_021BA2F0(u8 *p) {STRBUF_Delete((struct U16Vec *)(((struct Obj14694 *)p)->f18));func_021BA014(p+32);BMP_WIN_Delete((struct Descriptor *)(((struct Obj14694 *)p)->f1C));}





void func_021BA30C(p,limit)
char *p;

unsigned limit;

{func_021BA14C(p+32,limit);if(func_021B9E80(((struct Obj08419 *)p)->f10))func_021BA2E0(p);(((struct Obj08419 *)p)->f50)++;}



/*
 * note:     2026-10-05: the zero is passed in each arm's call of GF_FONT_SetTextColor
 *           (call written per arm), and PRINTSYS_Print takes a fifth argument
 *           (stack word); 8 byte gap closed. EXACT* (trailing alignment).
 */
void func_021BA330(void *p, int a)
{
    int z = 0;
    int q;

    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)(*(int *)((char *)p + 0x1c))), z);
    if (*(int *)((char *)p + 0x14) == 0)
        GF_FONT_SetTextColor(5, 6, z);
    else
        GF_FONT_SetTextColor(3, 4, z);
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)(*(int *)((char *)p + 0x1c))), 1, 1, (void *)(*(int *)((char *)p + 0x18)), (void *)a);
    q = *(int *)((char *)p + 0x1c);
    BMP_WIN_TransferChars((struct Descriptor *)q);
    BMP_WIN_MakeScreen((struct Cfg *)q);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)q));
}


void func_021BA38C(Context_021B95A0 *p)
{
    int i;
    enum Count count;
    if(func_021B9E50(p->kind)) count=CountTwo;
    else count=CountFour;
    for(i=0;i<count;i++)
        func_021BA268(&p->rows[i],p->kind,i,p->owner+i*16,(char *)p+0xC,(char *)p+0x24,p->c);
}




void func_021BA408(char *p){int i;enum Count count;if(func_021B9E50(((struct Obj25701 *)p)->f49C8))count=CountTwo;else count=CountFour;p+=0x483C;for(i=0;i<count;i++)func_021BA2F0((u8 *)(p+i*84));}





void func_021BA444(char *p){int i;enum Count count;if(func_021B9E50(((struct Obj25702 *)p)->f49C8))count=CountTwo;else count=CountFour;p+=0x483C;for(i=0;i<count;i++)func_021BA30C(p+i*84);}





void func_021BA480(char *p){int i;enum Count count;if(func_021B9E50(((struct Obj25703 *)p)->f49C8))count=CountTwo;else count=CountFour;p+=0x485C;for(i=0;i<count;i++)func_021BA1C0(p+i*84);}





void func_021BA4BC(void *p,int kind,int variant)
{
    switch(kind) {
    case 13:
        if(variant==0) func_02008DF0(p,14);
        else if(variant==1) func_02008DF0(p,15);
        break;
    case 37:
        if(variant==0) func_02008DF0(p,38);
        else if(variant==1) func_02008DF0(p,39);
        break;
    case 17:
        if(variant==0) func_02008DF0(p,18);
        else if(variant==1) func_02008DF0(p,19);
        else if(variant==2) func_02008DF0(p,20);
        break;
    }
    func_02008DF0(p,kind);
}





void func_021BA514(char *p)
{
    if(((struct Obj25704 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54) {
        switch((int)GFL_NET_GetGameKind()) {
        case 37:case 12:case 31:func_021BA4BC(((struct Obj25706 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,37,((struct Obj03939 *)p)->f49CC);break;
        case 10:func_021BA4BC(((struct Obj25707 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,17,((struct Obj03939 *)p)->f49CC);break;
        case 20:case 21:case 23:case 24:case 25:case 26:
            func_021BA4BC(((struct Obj25708 *)(*(char * *)&((struct Obj03939 *)p)->f4))->f54,13,((struct Obj03939 *)p)->f49CC);break;
        }
    }
}




/*
 * lever: source kind,a,b emits image a,kind,b stores and both entry copies; source a,kind,b left115 differing bytes.
 * domain: loop index is exactly 0,1,2; each switch arm initializes both coordinates before use.
 */
void func_021BA5A0(Context *p,const void *owner,void *other,u16 a,u16 b,u8 kind)
{
    int i,x,y;
    p->owner=owner;p->other=other;
    p->kind=kind;p->a=a;p->b=b;
    p->one=func_021BA750((void *)owner,0,(u8)p->a);
    p->two=func_021BA750((void *)owner,1,(u8)p->b);
    for(i=0;i<3;i++) {
        switch(i) {
        case 0:x=206;y=152;break;
        case 1:x=50;y=40;break;
        case 2:x=128;y=96;break;
        }
        p->objects[i]=func_021BA71C((void *)owner,x,y,7);
        CLACT_SetActorDrawEnable(p->objects[i],0);
    }
}




void func_021BA624(char *p){int i;for(i=0;i<3;i++)CLACT_DeleteActor(*(void **)((unsigned)p+i*4+24));for(i=0;i<2;i++)CLACT_DeleteActor(*(void **)((unsigned)p+i*4+16));}




void func_021BA650(char *p){func_021B9E50(((struct Obj04630 *)p)->f26);if(((struct Obj04630 *)p)->f24==30){CLACT_SetActorDrawEnable(((struct Obj04630 *)p)->f10,1);CLACT_SetActorAutoAnim(((struct Obj04630 *)p)->f10,1);CLACT_SetActorDrawEnable(((struct Obj04630 *)p)->f14,1);CLACT_SetActorAutoAnim(((struct Obj04630 *)p)->f14,1);}(((struct Obj04630 *)p)->f24)++;}




void func_021BA68C(char *p,unsigned i,int kind){int n;switch(kind){case 0:n=7;break;case 1:n=8;break;case 2:n=9;break;}p+=24;CLACT_SetActorDrawEnable(*(void **)((unsigned)p+i*4),1);CLACT_SetActorAutoAnim(*(void **)((unsigned)p+i*4),1);CLACT_ChangeActorAnimSeq(*(void **)((unsigned)p+i*4),n);}




void func_021BA6C8(char *p, void *state, short heap)
{
    int resource;
    In config;
    ((struct Obj14695 *)p)->f0 = state;
    ((struct Obj14695 *)p)->f4 = heap;
    config.f0=0;
    config.f4=0;
    config.f8=0xB5;
    config.fC=9;
    config.f10=8;
    config.f14=7;
    config.f18=6;
    config.b1c=0;
    config.b1d=0;
    config.b1e=4;
    resource=COMM_BTL_DEMO_GRAPHIC_GetCamera(state);
    UI_SCENE_LoadActorGfx((Out *)(p+8), &config, resource, heap);
}




void func_021BA710(char *p){UI_SCENE_FreeActorGfx((unsigned int *)(p+8));}




void *func_021BA71C(char *p,int a,int b,unsigned short c){return UI_SCENE_CreateActor(p+8,COMM_BTL_DEMO_GRAPHIC_GetCamera(((struct Obj14696 *)p)->f0),a,b,c,((struct Obj14696 *)p)->f4);}




void *func_021BA750(void *p,int kind,unsigned a){int x,y;void *v;if(kind==0){x=206;y=152;}else{x=50;y=40;}v=func_021BA71C(p,x,y,a);CLACT_SetActorDrawEnable(v,0);CLACT_SetActorDrawPriority(v,1);return v;}



void func_021BA780(char *p,void *state,short heap){func_0207D63C((void *)0x04000050,1,31,0,0);((struct Obj10929 *)p)->f0=state;((struct Obj10929 *)p)->f4=heap;((struct Obj10929 *)p)->f8=G3D_UTIL_Create(16,20,heap);PARTICLE_InitManager(heap);}



void func_021BA7B8(char *p){func_021BA9C0(p);func_021BA8D4(p);G3D_UTIL_Delete(((struct Obj10931 *)p)->f8);}



void func_021BA7D0(unsigned char *p)
{
    struct Arg arg;
    void *object;
    COMM_BTL_DEMO_GRAPHIC_Draw3d(((struct Obj04631 *)p)->f0);
    if(((struct Obj04631 *)p)->f10) PARTICLE_Main();
    if(p[15]) {
        arg.pos.x=0; arg.pos.y=0; arg.pos.z=0;
        arg.v0c.x=0x1000; arg.v0c.y=0x1000; arg.v0c.z=0x1000;
        MTX_Identity33_(&arg.m18);
        object=(void *)func_02048A18((u8 *)(*(Util * *)&((struct Obj04631 *)p)->f8),((struct Obj04631 *)p)->fC);
        G3D_SYSTEM_DrawObject(object,&arg);
    }
    COMM_BTL_DEMO_GRAPHIC_DrawEnd(((struct Obj04631 *)p)->f0);
}



void func_021BA81C(u8 *p,unsigned code)
{
    struct Src648 config;
    int resource;
    u32 context;
    if(*(int *)&((struct Obj02925 *)p)->f10) func_021BA8BC((char *)p,*(int *)&((struct Obj02925 *)p)->f10);
    *(int *)&((struct Obj02925 *)p)->f10=PARTICLE_CreateSystemDefault((int)(p+20),0x4800,1,((struct Obj02925 *)p)->f4);
    config.f04=0x3000;
    config.f08=-0x3000;
    config.f00=2;
    config.f0c=-0x4000;
    config.f10=0x4000;
    config.f14=0x1000;
    config.f18=0x400000;
    config.f1c=0;
    PARTICLE_ReleaseCamera(*(int *)&((struct Obj02925 *)p)->f10);
    PARTICLE_InitCamera(*(struct Dst648 * *)&((struct Obj02925 *)p)->f10,&config,0x2000,d_021BB330,d_021BB324,d_021BB360,((struct Obj02925 *)p)->f4);
    resource=PARTICLE_LoadArchiveMember(0xB5,code,((struct Obj02925 *)p)->f4);
    p[0x4814]=BUTTON_MAN_GetResourceType((void *)resource);
    context=func_020056BC();
    PARTICLE_SetupSystem(*(u8 * *)&((struct Obj02925 *)p)->f10,resource,0,context);
}



void func_021BA8BC(char *p, int object) { PARTICLE_KillAllEffects(*(u8 * *)&((struct Obj10930 *)p)->f10); PARTICLE_DeleteSystem(*(u8 * *)&((struct Obj10930 *)p)->f10); *(u32 *)&((struct Obj10930 *)p)->f10=0; }



void func_021BA8D4(char *p) { if(*(u8 * *)&((struct Obj10931 *)p)->f10) PARTICLE_DeleteSystem(*(u8 * *)&((struct Obj10931 *)p)->f10); PARTICLE_ExitManager(); }



int func_021BA8E8(char *p,int b,int c) { return PARTICLE_StartEffect(((struct Obj25709 *)p)->f10,b,c); }



/*
 * The original truncates the second call argument to u16; the extern preserves that width.
 */
void func_021BA8F4(char *p,int v) { int i; for(i=0;i<((struct Obj25710 *)p)->f4814;i++) func_021BA8E8(p,(u16)i,v); }



/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
int func_021BA920(int *p,u32 b,u32 c) { int *q; char *a,*h,*r; q=(int *)G3D_SYSTEM_GetObjectRender(p); a=(char *)G3D_SYSTEM_GetRenderTexRes(q); h=*(char * *)&((struct Obj25711 *)((char *)G3D_SYSTEM_GetRenderObj(q)))->f4; r=(char *)func_02047250(a); NNS_G3dReleaseMdlPltt(h); return NNS_G3dBindMdlPlttEx(h,r,b,c)&1; }



/*
 * width: 477A4 index u16: original narrows at 021BA994-021BA998.
 */
void func_021BA95C(unsigned char *p, int index)
{
    int *object;
    int i, count;
    if (p[15]) func_021BA9AC((char *)p);
    ((struct Obj02551 *)p)->fC=G3D_UTIL_AddUnit(*(Util * *)&((struct Obj02551 *)p)->f8, &d_021BB0F8[index]);
    p[15]=1;
    object=(int *)func_02048A18((u8 *)(*(Util * *)&((struct Obj02551 *)p)->f8), ((struct Obj02551 *)p)->fC);
    count=G3D_SYSTEM_GetObjectAnimeCount(object);
    for(i=0;i<count;i++) G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)object,(u16)i);
}



void func_021BA9AC(char *p) { G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Obj02551 *)p)->f8,((struct Obj02551 *)p)->fC); ((struct Obj02551 *)p)->fF=0; ((struct Obj02551 *)p)->fE=0; }




void func_021BA9C0(void *a)
{
    if (((struct Obj02551 *)a)->fF)
        func_021BA9AC(a);
}



int func_021BA9D0(unsigned char *p)
{
    int result=1;
    int *object;
    int count,i;
    if(p[14]) return 0;
    object=(int *)func_02048A18((u8 *)(*(Util * *)&((struct Obj08420 *)p)->f8), ((struct Obj08420 *)p)->fC);
    count=G3D_SYSTEM_GetObjectAnimeCount(object);
    for(i=0;i<count;i++) {
        result=G3D_SYSTEM_LoopObjectAnimeFrame(object,(u16)i,d_021BB320<<12);
        if(!result) p[14]=1;
    }
    return result;
}



/*
 * extent: 021BAA8A..021BAA8C is two zero alignment bytes, no follower.
 */
void func_021BAA20(unsigned char *p)
{
    int i;
    if(((struct Obj10932 *)p)->f44==1) {
        int j;
        unsigned char *row;
        for(i=0;i<2;i++) {
            row=p+16*i;
            for(j=0;j<(int)POKEPARTY_GetCount(((struct Obj08421 *)row)->f0);j++) row[10+j]=0;
        }
        return;
    }
    if(((struct Obj10932 *)p)->f44==3) {
        unsigned char *row;
        int j;
        for(i=0;i<4;i++) {
            row=p+16*i;
            for(j=0;j<(int)POKEPARTY_GetCount(((struct Obj08421 *)row)->f0);j++) row[10+j]=0;
        }
    }
}



int func_021BAA8C(char *p) { void *q; u8 *flags; int i,n; q=((struct Obj25712 *)p)->f0; n=0; flags=(u8 *)p+10; for(i=0;i<(int)POKEPARTY_GetCount(q);i++) if(flags[i]<=1) n++; return n; }



static inline void Shading(GXShading mode) { REG3D = (unsigned short)((REG3D & ~0x3002) | (mode << 1)); }



static inline void AntiAlias(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x10); else REG3D &= (unsigned short)~0x3010; }



static inline void AlphaTest(BOOL enable, int ref) { if (enable) { REG3D = (unsigned short)((REG3D & ~0x3000) | 4); *(volatile unsigned short *)0x04000340 = ref; } else REG3D &= (unsigned short)~0x3004; }



static inline void AlphaBlend(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 8); else REG3D &= (unsigned short)~0x3008; }



static inline void EdgeMarking(BOOL enable) { if (enable) REG3D = (unsigned short)((REG3D & ~0x3000) | 0x20); else REG3D &= (unsigned short)~0x3020; }



void func_021BAABC(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    *(volatile unsigned short *)0x04000008 = (unsigned short)((*(volatile unsigned short *)0x04000008 & ~3) | 1);
    Shading(SHADING1);
    AntiAlias(0);
    AlphaTest(0, 0);
    AlphaBlend(1);
    EdgeMarking(0);
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7FFF, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xBFFF0000;
    for (i = 0; i < 4; i++) G3D_SYSTEM_SetLight((unsigned char)i, d_021BB1A8[i]);
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
}
