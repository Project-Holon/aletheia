/*
 * file:     unit_021B95A0.c
 * unit:     yes
 * function: func_021B95A0, func_021B95D4, func_021B95E8, func_021B95F8, func_021B9630, func_021B96B0, func_021B96C8, func_021B974C, func_021B97BC, func_021B98F4, func_021B9908, func_021B99CC, func_021B99F8, func_021B9A80, func_021B9AD4, func_021B9AF8, func_021B9B10, func_021B9B1C, func_021B9B6C, func_021B9B98, func_021B9C30, func_021B9C58, func_021B9C80, func_021B9CC8, func_021B9D04, func_021B9D20, func_021B9D34, func_021B9DB0, func_021B9DCC, func_021B9DDC, func_021B9E14, func_021B9F1C, func_021B9F40, func_021B9F9C, func_021B9FD8, func_021BA000, func_021BA028, func_021BA0AC, func_021BA128, func_021BA2A8, func_021BA2AC, func_021BA2D8, func_021BA318, func_021BA354, func_021BA390, func_021BA4AC, func_021BA558, func_021BA594, func_021BA5E8, func_021BA6F0, func_021BA83C, func_021BAA00, func_021BAA54, func_021BAAC0, func_021BAAD0, func_021BAAE0
 * address:  0x021B95A0
 * region:   ov181
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
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   d_021BAB70 0x021BAB70 data a4
 *   func_02034AC4  0x02034AC4  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0207D534  0x0207D534  arm
 *   GFL_USE_PlayFanfare  0x02005DAC  thumb
 *   ov067_id       0x00000043  data
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   overlay_id 0x00000043 data a1
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   d_021BABD0 0x021BABD0 data a4
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   d_021BABFC     0x021BABFC  data  a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   BUTTON_MAN_RotScaleMtx22 0x02051E74 arm
 *   sub_02040860 0x02040860 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021BAC74 0x021BAC74 data a4
 *   d_021BACC4 0x021BACC4 data a4
 *   d_021BAC84 0x021BAC84 data a4
 *   d_021BACA4 0x021BACA4 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02040EBC  0x02040EBC  arm
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 *   func_020419E4 0x020419E4 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02045B38 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_Create 0x02043678 arm
 *   BMP_Delete 0x020437AC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Blit 0x020439A0 arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   func_020307B0  0x020307B0  arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   func_02048AD0 0x02048AD0 arm
 *   func_0204044C 0x0204044C arm
 *   func_0207D658 0x0207D658 arm
 *   d_021BAB50 0x021BAB50 data a4
 *   d_021BAB38 0x021BAB38 data a4
 *   d_021BAC68 0x021BAC68 data a4
 *   d_021BACE4 0x021BACE4 data a4
 *   d_021BACF0 0x021BACF0 data a4
 *   d_020A1E38 0x020A1E38 data a2
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   func_02048C4C 0x02048C4C arm
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_02043658 0x02043658 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   func_02047964 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   d_021BAC2C 0x021BAC2C data a4
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02048AE8 0x02048AE8 arm
 *   func_02048B30 0x02048B30 arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   KEY_GetCont 0x0203630C arm
 *   BMP_GetPixels 0x020437D4 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201D304 0x0201D304 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   d_021BAB40 0x021BAB40 data a2
 *   func_0207D63C 0x0207D63C arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02040860 0x02040860 arm
 */
#include "../../matched/include/Obj24498.h"
#include "../../matched/include/Obj14406.h"
#include "../../matched/include/Obj24499.h"
#include "../../matched/include/Obj00682.h"
#include "../../matched/include/Obj01003.h"
#include "../../matched/include/Obj24500.h"
#include "../../matched/include/Obj03327.h"
#include "../../matched/include/Obj24501.h"
#include "../../matched/include/Obj08302.h"
#include "../../matched/include/Obj24502.h"
#include "../../matched/include/Obj14407.h"
#include "../../matched/include/Obj14408.h"
#include "../../matched/include/Obj24503.h"
#include "../../matched/include/Obj24504.h"
#include "../../matched/include/Obj14409.h"
#include "../../matched/include/Obj24505.h"
#include "../../matched/include/Obj06587.h"
#include "../../matched/include/Obj03877.h"
#include "../../matched/include/Obj06588.h"
#include "../../matched/include/Obj14410.h"
#include "../../matched/include/Obj10722.h"
#include "../../matched/include/Obj08304.h"
#include "../../matched/include/Obj14411.h"
#include "../../matched/include/Obj24507.h"
#include "../../matched/include/Obj24508.h"
#include "../../matched/include/Obj04570.h"
#include "../../matched/include/Obj01071.h"
#include "../../matched/include/Obj06590.h"
#include "../../matched/include/Obj14412.h"
#include "../../matched/include/Obj08305.h"
#include "../../matched/include/Obj01274.h"
#include "../../matched/include/Obj00784.h"
#include "../../matched/include/Obj06591.h"
#include "../../matched/include/Obj06592.h"
#include "../../matched/include/Obj10725.h"
#include "../../matched/include/Obj14414.h"
#include "../../matched/include/Obj24511.h"
#include "../../matched/include/Obj24512.h"
#include "../../matched/include/Obj24513.h"
#include "../../matched/include/Obj14415.h"

#define STATE(p) (*(int *)((p) + 0x2EC))
#define ENTRIES(p) (*(Entry **)((p) + 0x2D4))
#define IDX(p) (*(unsigned char *)((p) + 0x2BA))
struct Obj0203159C;
struct S020315D4;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Mtx22;
struct Node;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct Rec;
struct Bmp;
struct Obj020437AC;
struct Descriptor;
struct Cfg;
struct Util;
struct Setup;
struct LightSet;
struct LightSlot;
struct Light;
struct G3dSys;
struct Ctx;
struct Arg;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021B95A0;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed short s16_021B97BC;

typedef int (*Command)(char *,char *);

typedef struct { unsigned words[4]; } Small;

typedef struct { unsigned words[8]; } Big;

typedef struct { unsigned text; unsigned short tag; unsigned char kind, pad7; unsigned pad8, padC; } Entry;

typedef signed char s8;

typedef signed short s16;

typedef struct { u32 x,y,z; } Vec3;

typedef struct { int x, y, z; } Vec;

struct Bmp { void *pixels; u16 width, height, depth, kind; };

struct CharBuf { u8 *pixels; u16 width, height, tileSize; };

struct Mtx22 { int m[4]; };

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern int func_02034AC4(s32 handle);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void func_0204363C(u32 swap);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void GFL_USE_PlayFanfare(void *arg);
extern u32 WIPE_SYS_EndCheck(void);
extern int GFL_USE_IsBgmFading(void),GFL_USE_IsBgmPlaying(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void BG_SYS_SetMainVisiblePlanes(u32),BG_SYS_SetSubVisiblePlanes(u32),GF_OVERLAY_Unload(int);
extern int GFL_USE_IsBgmPlaying(void);
extern void GFL_USE_FadeOutBgm(u32);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203F8F4(unsigned short);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BUTTON_MAN_RotScaleMtx22(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void sub_02040860(unsigned, unsigned, unsigned, unsigned);
extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);
extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned),BG_SYS_SetSubPlaneVisible(unsigned,unsigned),func_020403F4(unsigned),func_0203F9B4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_TOOL_DeleteHandle(u8 *p);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_021B9DDC(char *),func_020419E4(void);
extern void *func_020056A0(void *,void *,int);
extern void func_02030EAC(struct Node *n);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_Delete(struct Obj020437AC *);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Blit(struct Bmp *,struct Bmp *,unsigned,unsigned,int,int,unsigned,unsigned,unsigned);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern u32 func_020307B0(void *p);
extern void BMP_WIN_Init(unsigned short);
extern unsigned BMP_WIN_Create(unsigned, unsigned, unsigned, unsigned, unsigned char, unsigned char, unsigned char);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(unsigned);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
extern struct Util *G3D_UTIL_Create(u16,u16,u16);
extern u16 G3D_UTIL_AddUnit(struct Util *,const struct Setup *);
extern u32 func_02048A18(u8 *,int);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern struct LightSlot *func_02048BC4(const struct LightSet *,u32);
extern void func_02048C58(struct LightSlot *);
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,Vec3 *,Vec3 *,Vec3 *,u16);
extern void func_02048AD0(struct Light *);
extern void func_0204044C(u32);
extern void func_0207D658(u32,int,int);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void func_02048C4C(void *);
extern void G3D_UTIL_RemoveUnit(struct Ctx *,unsigned);
extern void G3D_UTIL_Delete(struct Rec *);
extern void G3D_SYSTEM_Exit(void);
extern unsigned func_02043658(void);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern void func_02047964(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern void G3D_SYSTEM_DrawEnd(void);
extern void func_02048AE8(struct Light *, Vec *);
extern void func_02048B30(struct Light *, Vec *);
extern void func_02048AFC(struct Light *, const Vec *);
extern void func_02048B44(struct Light *, const Vec *);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern u32 KEY_GetCont(void);
extern void *BMP_GetPixels(const struct Bmp *);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintColor(void *, short, short, void *, void *, unsigned short);
extern void func_0207D63C(unsigned, int, int, int, int);
extern void BMP_Clear(struct CharBuf *, u8);
extern void func_02040860(unsigned, unsigned, unsigned, unsigned);
int func_021B95A0(struct Obj0203159C *p,int unused,u32 v);
int func_021B95D4(int a0, int a1, int a2, int a3);
int func_021B95E8(void *p);
int func_021B95F8(char *p);
int func_021B9630(u8 *p);
int func_021B96B0(char *p);
int func_021B96C8(char *p);
int func_021B974C(char *p);
int func_021B97BC(char *p);
void func_021B98F4(void);
void func_021B9908(void);
void func_021B99CC(void);
void func_021B99F8(void);
void func_021B9A80(void *unused, int mode);
void func_021B9AD4(void *task,char *p);
void func_021B9AF8(char *p);
void func_021B9B10(char *p);
void func_021B9B1C(char *p);
void func_021B9B6C(char *p);
void func_021B9B98(char *p);
void func_021B9C30(char *p);
void func_021B9C58(char *p,void *s,unsigned i);
void func_021B9C80(char *p);
void func_021B9CC8(char *p);
void func_021B9D04(char *p);
void func_021B9D20(char *p);
void func_021B9D34(char *p);
void func_021B9DB0(char *p);
void func_021B9DCC(char *p, u32 v);
void func_021B9DDC(char *p);
void func_021B9E14(char *p);
void func_021B9F1C(char *p);
void func_021B9F40(char *p);
void func_021B9F9C(u8 *p);
void func_021B9FD8(u8 *p,int a,int b);
void func_021BA000(u8 *p);
void func_021BA028(Vec *out, const Vec *base, const Vec *target, unsigned duration);
void func_021BA0AC(Vec *out, const Vec *base, const Vec *velocity, unsigned step);
void func_021BA128(char *p);
void func_021BA2A8(u8 *p,u32 a);
int func_021BA2AC(u8 *p, int a);
void func_021BA2D8(char *p);
void func_021BA318(u8 *p);
void func_021BA354(u8 *p,u8 *out,u32 n);
void func_021BA390(char *p);
void func_021BA4AC(char *p, unsigned char *q, void *s, int y);
void func_021BA558(char *p,u8 *q);
void func_021BA594(char *p, unsigned char *q);
int func_021BA5E8(char *p);
int func_021BA6F0(char *p);
int func_021BA83C(char *p);
int func_021BAA00(char *p, unsigned char *q);
int func_021BAA54(char *p, unsigned char *q);
int func_021BAA84(char *p, unsigned char *q);
int func_021BAA98(char *p);
int func_021BAAA4(char *p);
int func_021BAAB0(char *p);
int func_021BAABC(void);
int func_021BAAC0(void);
int func_021BAAD0(void);
int func_021BAAE0(u8 *p,u8 *q);
extern u8 ov067_id[];
extern char overlay_id[];
extern const Command d_021BABD0[];
extern int  d_021BABFC[];
extern const Small d_021BAC74;
extern const Big d_021BACC4, d_021BAC84, d_021BACA4;
extern unsigned SDK_AUTOLOAD_MAIN_TWL_START[];
extern const struct Setup d_021BAB50;
extern const struct LightSet d_021BAB38;
extern const Vec3 d_021BAC68;
extern Vec3 d_021BACE4,d_021BACF0;
extern const u8 d_020A1E38[];
extern const unsigned d_021BAC2C[];
extern const unsigned short d_021BAB40[];



int func_021B95A0(struct Obj0203159C *p,int unused,u32 v) { u8 *q; GFL_HEAP_CreateChildHeap(1,142,0x125000); q=PROCSYS_AllocProcWork(p,756,142); MI_CpuFill8(q,0,756); ((struct Obj24498 *)q)->f0=v; return 1; }




int func_021B95D4(int a0, int a1, int a2, int a3)
{
    return func_021B95F8((char *)a3) == 0;
}




int func_021B95E8(void *p)
{
    func_020315D4(p);
    func_020306F0(0x8e);
    return 1;
}



extern int (*const d_021BAB70[])(char *);



int func_021B95F8(char *p){func_021BA318((unsigned char *)p);((struct Obj14406 *)p)->f2E8=d_021BAB70[*(unsigned *)(p+0x2e8)](p);if(((struct Obj14406 *)p)->f2E8==5)return 0;func_021B9C80(p);func_021B9F40(p);return 1;}




int func_021B9630(u8 *p)
{
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(1);
    func_0207D534((void *)0x0400006c, -0x10);
    func_0207D534((void *)0x0400106c, -0x10);
    func_021B98F4();
    func_021B9908();
    func_021B99F8();
    func_021B9B1C((char *)p);
    func_021B9D34((char *)p);
    func_021B9E14((char *)p);
    func_021B9D04((char *)p);
    func_021B9AF8((char *)p);
    GFL_USE_PlayFanfare((void *)0x3f8);
    return 3;
}




int func_021B96B0(char *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return ((struct Obj24499 *)p)->f2F0;
    return 1;
}



int func_021B96C8(char *p) {
if(GFL_USE_IsBgmFading()==1)return 2;
if(GFL_USE_IsBgmPlaying()==1)GFL_USE_CancelChangeAndStopBgm();
func_021B9B10(p);func_021B9D20(p);func_021B9F1C(p);func_021B9DB0(p);func_021B9B6C(p);func_021B99CC();
func_0207D534((volatile u16 *)0x0400006c,-16);func_0207D534((volatile u16 *)0x0400106c,-16);
*(volatile u16 *)0x04000050=0;*(volatile u16 *)0x04001050=0;
BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);GF_OVERLAY_Unload((int)overlay_id);return 5;
}



#define COUNT(p) (*(unsigned *)((p) + 0x2E4))



int func_021B974C(char *p)
{
    switch (STATE(p)) {
    case 0:
        if (COUNT(p) >= 41) {
            COUNT(p) = 0;
            STATE(p)++;
        } else if (((struct Obj00682 *)p)->f2D2 == 1) {
            COUNT(p) += 4;
        } else {
            COUNT(p)++;
        }
        break;
    case 1:
        if (func_021BA83C(p) == 0)
            STATE(p)++;
        break;
    case 2:
        COUNT(p) = 0;
        STATE(p) = 0;
        return 4;
    }
    return 3;
}



int func_021B97BC(char *p) {
    char *row;
    if(((struct Obj01003 *)p)->f2EC==0) {
        for(;;) {
            row=*(char * *)&((struct Obj01003 *)p)->f2D4+((struct Obj01003 *)p)->f2D8*16;
            if(((struct Obj01003 *)p)->f2D8==*(u32 *)((u32)p+((struct Obj01003 *)p)->f2BB*8+0xbc)) {
                func_021B9CC8(p);
                (((struct Obj01003 *)p)->f2BB)++;
                *(u16 *)&((struct Obj01003 *)p)->f2DA=((struct Obj24500 *)row)->f4;
                ((struct Obj01003 *)p)->f2EC=1;
                ((struct Obj01003 *)p)->f2D8+=2;
                break;
            }
            if(d_021BABD0[*(u8 *)(row+6)](p,row)==1) {
                (((struct Obj01003 *)p)->f2D8)++;
                break;
            }
            (((struct Obj01003 *)p)->f2D8)++;
        }
    }
    switch(((struct Obj01003 *)p)->f2EC) {
    case 1:
        if(((struct Obj01003 *)p)->f2DA<=0) {
            ((struct Obj01003 *)p)->f2DA=0; ((struct Obj01003 *)p)->f2EC=0;
        } else if(((struct Obj01003 *)p)->f2D2==1) ((struct Obj01003 *)p)->f2DA-=4;
        else (((struct Obj01003 *)p)->f2DA)--;
        break;
    case 2: if(func_021BA5E8(p)==0) ((struct Obj01003 *)p)->f2EC=0; break;
    case 3: if(func_021BA6F0(p)==0) ((struct Obj01003 *)p)->f2EC=0; break;
    case 5:
        if(GFL_USE_IsBgmPlaying()==1) GFL_USE_FadeOutBgm(64);
        return func_021BA2AC((u8 *)p,2);
    }
    func_021BA390(p);
    return 4;
}




void func_021B98F4(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BABFC);
}



void func_021B9908(void)
{
    Small a;
    Big b, c;
    Small d;
    Big e;
    func_0203F8F4(0x8E);
    a = d_021BAC74;
    func_0203FC28((struct DispConfig *)(&a));
    b = d_021BACC4;
    func_0203FCA0(1, (const struct BgTemplate *)(&b), 0);
    c = d_021BAC84;
    func_0203FCA0(3, (const struct BgTemplate *)(&c), 2);
    BUTTON_MAN_RotScaleMtx22((struct Mtx22 *)(&d), 0, (const void *)0x9000, (const void *)0x9000, 0);
    sub_02040860(3, (unsigned)&d, 0x80, 0x60);
    e = d_021BACA4;
    func_0203FCA0(5, (const struct BgTemplate *)(&e), 0);
    BG_SYS_SetMainPlaneVisible(2, 1);
    BG_SYS_SetSubPlaneVisible(2, 1);
}



/*
 * Tail: two zero alignment bytes at 0x021B99F6.
 */
void func_021B99CC(void){BG_SYS_SetMainPlaneVisible(2,0);BG_SYS_SetSubPlaneVisible(2,0);func_020403F4(5);func_020403F4(3);func_020403F4(1);func_0203F9B4();}




void func_021B99F8(void)
{
    u8 *p = func_020490F4(0x1a, 0x808e);
    func_02049658(p, 0, 3, 0, 0, 1, 0x8e);
    func_020498F4(p, 1, 3, 0, 0, 1, 0x8e);
    ARC_TOOL_DeleteHandle(p);
    p = func_020490F4(0xdc, 0x808e);
    func_02049B68(p, 0xc, 0, 0x1e0, 0x20, 0x8e);
    func_02049B68(p, 0xc, 4, 0x1e0, 0x20, 0x8e);
    ARC_TOOL_DeleteHandle(p);
    func_02040EBC(1, 0);
    func_02040EBC(5, 0);
}



void func_021B9A80(void *unused, int mode)
{
    unsigned char *h;
    if (mode == 1) {
        h = func_020490F4(0x1A, 0x808E);
        func_02049B68(h, 2, 0, 0, 0, 0x8E);
    } else {
        h = func_020490F4(0xDC, 0x808E);
        func_02049B68(h, 0xC, 0, 0x1E0, 0x20, 0x8E);
    }
    ARC_TOOL_DeleteHandle(h);
    func_02040EBC(1, 0);
}



/*
 * volatile: SDK OS_SetIrqCheckFlag read-modify-write at 0x02FE3FF8.
 */
void func_021B9AD4(void *task,char *p){func_021B9DDC(p);func_020419E4();*(volatile unsigned *)((unsigned)SDK_AUTOLOAD_MAIN_TWL_START+0x3ff8) |=1;}



void func_021B9AF8(char *p){((struct Obj03327 *)p)->f4=func_020056A0(func_021B9AD4,p,0);}



void func_021B9B10(char *p){func_02030EAC(((struct Obj24501 *)p)->f4);}



/*
 * Padding: two zero bytes at 0x021B9B6A, then the next function.
 */
void func_021B9B1C(char *p)
{
    ((struct Obj03327 *)p)->fB0 = func_02045B38(0, 2, 0xB1, 0x8E);
    ((struct Obj03327 *)p)->fB4 = STRBUF_Create(0x80, 0x8E);
    ((struct Obj03327 *)p)->fA8 = GF_FONT_Create(0x17, 0, 1, 0, 0x8E);
    ((struct Obj03327 *)p)->fAC = GF_FONT_Create(0x17, 2, 1, 0, 0x8E);
}



void func_021B9B6C(char *p){GF_FONT_Delete(((struct Obj08302 *)p)->fAC);GF_FONT_Delete(((struct Obj08302 *)p)->fA8);STRBUF_Delete(((struct Obj08302 *)p)->fB4);MSGDATA_Delete(((struct Obj08302 *)p)->fB0);}



#undef COUNT


#undef COUNT

#undef COUNT
#define COUNT(p) (*(unsigned short *)((p) + 0x2B8))



void func_021B9B98(char *p)
{
    unsigned short i;
    int found = 0;
    for (i = 0; ; i++) {
        Entry *e = &ENTRIES(p)[i];
        if (found == 0) {
            if (e->kind == 7)
                found = 1;
        } else {
            if (e->kind == 5)
                break;
            if (e->kind == 0 && e->text != 0xFFFF && ((Entry *)((unsigned)ENTRIES(p) + (i + 1) * 16))->tag == 0 &&
                ((Entry *)((unsigned)ENTRIES(p) + (i + 1) * 16))->kind == 0 && ((Entry *)((unsigned)ENTRIES(p) + (i + 1) * 16))->text != 0xFFFF) {
                *(void **)(p + COUNT(p) * 8 + 0xB8) = BMP_Create(0x20, 2, 0x20, 0x8E);
                *(int *)(p + COUNT(p) * 8 + 0xBC) = i;
                COUNT(p)++;
                if (COUNT(p) == 0x40)
                    break;
                i++;
            }
        }
    }
}



void func_021B9C30(char *p){unsigned i;for(i=0;i<((struct Obj24502 *)p)->f2B8;i++)BMP_Delete(*(struct Obj020437AC **)((unsigned)p+i*8+0xb8));}



void func_021B9C58(char *p,void *s,unsigned i){unsigned char *q=*(unsigned char * *)&((struct Obj14407 *)p)->f2D4+i*16;if(q[9]==0)func_021BA4AC(p,q,s,0);else func_021BA4AC(p,q,s,2);}



void func_021B9C80(char *p)
{
    if (IDX(p) < ((struct Obj14407 *)p)->f2B8) {
        func_021B9C58(p, *(void **)(p + IDX(p) * 8 + 0xB8), *(int *)(p + IDX(p) * 8 + 0xBC));
        func_021B9C58(p, *(void **)(p + IDX(p) * 8 + 0xB8), *(int *)(p + IDX(p) * 8 + 0xBC) + 1);
        IDX(p)++;
    }
}



void func_021B9CC8(char *p){struct Bmp *s=BMP_WIN_GetBmp(((struct Obj14408 *)p)->f2C4);BMP_Blit(*(struct Bmp **)((unsigned)p+((struct Obj14408 *)p)->f2BB*8+0xb8),s,0,0,0,192,256,16,0);}




void func_021B9D04(char *p)
{
    ((struct Obj24503 *)p)->f2D4 = (int)ARC_TOOL_LoadMember(0xdc, 1, 0x8e);
    func_021B9B98(p);
}




void func_021B9D20(char *p)
{
    func_021B9C30(p);
    func_020307B0((void *)(((struct Obj24504 *)p)->f2D4));
}



/*
 * Padding: two zero bytes at 0x021B9DAE, then the next function.
 */
void func_021B9D34(char *p)
{
    unsigned h;
    BMP_WIN_Init(0x8E);
    ((struct Obj03327 *)p)->f2BC = BMP_WIN_Create(1, 0, 0, 0x20, 0x19, 0xF, 1);
    ((struct Obj03327 *)p)->f2C4 = BMP_WIN_Create(5, 0, 0, 0x20, 0x1C, 0xF, 1);
    h = ((struct Obj03327 *)p)->f2BC;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)h));
    h = ((struct Obj03327 *)p)->f2C4;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)h));
}



void func_021B9DB0(char *p){BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj14409 *)p)->f2BC);BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj14409 *)p)->f2C4);BMP_WIN_Exit();}




void func_021B9DCC(char *p, u32 v)
{
    ((struct Obj24505 *)p)->f2CC |= (u8)v;
}



/*
 * Tail: two zero alignment bytes at 0x021B9E12.
 */
void func_021B9DDC(char *p){if(((struct Obj06587 *)p)->f2CC&1)BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06587 *)p)->f2BC);if(((struct Obj06587 *)p)->f2CC&2)BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06587 *)p)->f2C4);((struct Obj06587 *)p)->f2CC=0;}



static inline void AntiAlias(int enable) {
    u32 tmp=*(volatile u16 *)0x04000060 & ~0x3000;
    if(enable) tmp|=0x10;
    else tmp&=~0x10;
    *(volatile u16 *)0x04000060=(u16)tmp;
}



void func_021B9E14(char *p) {
    Vec3 v;
    u32 i;
    G3D_SYSTEM_Init(0,2,0,2,4096,142,0);
    *(struct Util **)(p+8)=G3D_UTIL_Create(3,1,142);
    *(u16 *)(p+0x18)=G3D_UTIL_AddUnit(*(struct Util **)(p+8),&d_021BAB50);
    *(u32 *)(p+0x20)=func_02048A18(*(u8 **)(p+8),*(u16 *)(p+0x18));
    *(u32 *)(p+0x24)=G3D_SYSTEM_GetObjectAnimeCount(*(int **)(p+0x20));
    for(i=0;i<*(u32 *)(p+0x24);i++) G3D_SYSTEM_EnableObjectAnime(*(struct G3dSys **)(p+0x20),(u16)i);
    *(struct LightSlot **)(p+0x10)=func_02048BC4(&d_021BAB38,142);
    func_02048C58(*(struct LightSlot **)(p+0x10));
    v=d_021BAC68;
    *(u32 **)(p+0xc)=G3D_CAMERA_Create(0,*(s16 *)(d_020A1E38+0x8c),*(s16 *)(d_020A1E38+0x8e),0x1555,
        0,4096,0x400000,0,&d_021BACE4,&v,&d_021BACF0,142);
    func_02048AD0(*(struct Light **)(p+0xc));
    AntiAlias(1);
    func_0204044C(2);
    func_021B9F9C((u8 *)(p+0x28));
    BG_SYS_SetMainPlaneVisible(1,0);
    func_0207D658(0x04000050,1,-16);
}




/*
 * Verified scratch blocker.c with one --arm (no --region), fixed flags: EXACT, 12 bytes.
 * extern void func_020307B0(void *);
 * void func_02048C4C(void *p) { func_020307B0(p); }
 * Blocker symbols: func_020307B0 0x020307B0 arm.
 */
void func_021B9F1C(char *p){G3D_CAMERA_Delete(*(void **)(p+12));func_02048C4C(*(void **)(p+16));G3D_UTIL_RemoveUnit(*(struct Ctx **)(p+8),*(unsigned short *)(p+24));G3D_UTIL_Delete(*(struct Rec **)(p+8));G3D_SYSTEM_Exit();}




void func_021B9F40(char *p)
{
    unsigned i;
    if (**(int * *)&((struct Obj03877 *)p)->f0 != 1 && (func_02043658() & 1)) {
        func_021BA2D8(p);
        func_021BA128(p);
        for (i = 0; i < ((struct Obj03877 *)p)->f24; i++)
            G3D_SYSTEM_LoopObjectAnimeFrame(((struct Obj03877 *)p)->f20, (unsigned short)i, 0x1000);
        func_02047964();
        G3D_SYSTEM_ApplyLookAt();
        G3D_SYSTEM_DrawObject(((struct Obj03877 *)p)->f20, (struct Arg *)d_021BAC2C);
        G3D_SYSTEM_DrawEnd();
    }
}




void func_021B9F9C(u8 *p){u32 i;*(const void * *)&((struct Obj06588 *)p)->f0=&d_021BACE4;((struct Obj06588 *)p)->f74=7;((struct Obj06588 *)p)->f78=0;((struct Obj06588 *)p)->f76=0;((struct Obj06588 *)p)->f7C=0;for(i=0;i<16;i++){u8 *q=p+i*4;((struct Obj14410 *)q)->f34=65535;((struct Obj14410 *)q)->f36=0;}}




void func_021B9FD8(u8 *p,int a,int b){u32 i;for(i=0;i<16;i++){u8 *q=p+i*4;if(((struct Obj10722 *)q)->f34==65535){((struct Obj10722 *)q)->f34=a;((struct Obj10722 *)q)->f36=b;return;}}}




void func_021BA000(u8 *p){u32 i;for(i=0;i<15;i++){u8 *q=p+i*4;((struct Obj08304 *)q)->f34=((struct Obj08304 *)q)->f38;((struct Obj08304 *)q)->f36=((struct Obj08304 *)q)->f3A;}((struct Obj14411 *)p)->f70=65535;((struct Obj14411 *)p)->f72=0;}




void func_021BA028(Vec *out, const Vec *base, const Vec *target, unsigned duration)
{
    Vec v;
    int b, a, diff;
    b = target->x;
    a = base->x;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.x = ((unsigned)diff << 8) / duration;
    if (a > b) v.x *= -1;
    b = target->y;
    a = base->y;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.y = ((unsigned)diff << 8) / duration;
    if (a > b) v.y *= -1;
    b = target->z;
    a = base->z;
    diff = a - b;
    if (diff < 0) diff = -diff;
    v.z = ((unsigned)diff << 8) / duration;
    if (a > b) v.z *= -1;
    *out = v;
}




void func_021BA0AC(Vec *out, const Vec *base, const Vec *velocity, unsigned step)
{
    Vec v = *base;
    unsigned n;
    n = ((unsigned)(velocity->x < 0 ? -velocity->x : velocity->x) * step) >> 8;
    if (velocity->x > 0) v.x += n; else v.x -= n;
    n = ((unsigned)(velocity->y < 0 ? -velocity->y : velocity->y) * step) >> 8;
    if (velocity->y > 0) v.y += n; else v.y -= n;
    n = ((unsigned)(velocity->z < 0 ? -velocity->z : velocity->z) * step) >> 8;
    if (velocity->z > 0) v.z += n; else v.z -= n;
    *out = v;
}




void func_021BA128(char *p)
{
    Vec a, b, c, d, e;
    char *q;
    q = p + 0x28;
    if (*(int *)(q + 0x7c) == 0) return;
    if (*(u16 *)(q + 0x78) == 0) {
        *(u16 *)(q + 0x7a) = *(u16 *)(q + 0x36);
        func_02048AE8(*(struct Light **)(p + 0xc), &a);
        func_021BA028(&b, &a, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24), *(u16 *)(q + 0x7a));
        *(Vec *)(q + 0x1c) = b;
        func_02048B30(*(struct Light **)(p + 0xc), &a);
        func_021BA028(&c, &a, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24 + 12), *(u16 *)(q + 0x7a));
        *(Vec *)(q + 0x28) = c;
    }
    if (*(u16 *)(q + 0x78) >= *(u16 *)(q + 0x7a)) {
        *(Vec *)(q + 4) = *(Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24);
        *(Vec *)(q + 0x10) = *(Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24 + 12);
        *(u16 *)(q + 0x76) = *(u16 *)(q + 0x34);
        *(u16 *)(q + 0x78) = 0;
        func_021BA000((u8 *)q);
        if (*(u16 *)(q + 0x34) == 0xffff) func_021BA2A8((u8 *)q, 0);
    } else {
        func_021BA0AC(&d, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x76) * 24), (Vec *)(q + 0x1c), *(u16 *)(q + 0x78));
        *(Vec *)(q + 4) = d;
        func_021BA0AC(&e, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x76) * 24 + 12), (Vec *)(q + 0x28), *(u16 *)(q + 0x78));
        *(Vec *)(q + 0x10) = e;
        if (*(unsigned char *)(p + 0x2d2) == 1) *(u16 *)(q + 0x78) += 4;
        else ++*(u16 *)(q + 0x78);
    }
    func_02048AFC(*(struct Light **)(p + 0xc), (Vec *)(q + 4));
    func_02048B44(*(struct Light **)(p + 0xc), (Vec *)(q + 0x10));
    func_02048AD0(*(struct Light **)(p + 0xc));
}




void func_021BA2A8(u8 *p,u32 a){((struct Obj24507 *)p)->f7C=a;}




int func_021BA2AC(u8 *p, int a){WIPE_SYS_Start(0,0,0,0,6,1,142);((struct Obj24508 *)p)->f2F0=a;return 1;}




void func_021BA2D8(char *p)
{
    int v = ((struct Obj03877 *)p)->f1C;
    if (v <= 0x10000) {
        ((struct Obj03877 *)p)->f1C = v + (((struct Obj03877 *)p)->f2D2 == 1 ? 0x400 : 0x100);
        func_0207D658(0x04000050, 1, *(volatile int *)&((struct Obj03877 *)p)->f1C / 0x1000 - 0x10);
    }
}



void func_021BA318(u8 *p){if(**(int **)p){enum {K=0x2d1} k=K;if(p[k]==0)p[k+1]=(KEY_GetCont()&3)?1:0;p[0x2d1]=(p[0x2d1]+1)&3;}}



void func_021BA354(u8 *p,u8 *out,u32 n){u32 i;if(out){for(i=0;i<n;i++)*(u32 *)(out+(8-n)*4+i*4)=*(u32 *)(p+i*4);}for(i=0;i<8-n;i++)*(u32 *)(p+i*4)=*(u32 *)(p+n*4+i*4);}



/*
 * extent: two zero alignment bytes at 021BA4AA, then labelled 021BA4AC.
 */
void func_021BA390(char *p)
{
    char *a, *b;
    unsigned n;
    u16 i, j, k, l, m, o;
    unsigned x, y;
    if (((struct Obj04570 *)p)->f2E0 == 0) return;
    ((struct Obj04570 *)p)->f2DC += 0x1000;
    if (((struct Obj04570 *)p)->f2DC < 0x1000) return;
    ((struct Obj04570 *)p)->f2DC -= 0x1000;
    n = 1;
    if (((struct Obj04570 *)p)->f2D2) n = 4;
    a = BMP_GetPixels(BMP_WIN_GetBmp(((struct Obj04570 *)p)->f2BC));
    b = BMP_GetPixels(BMP_WIN_GetBmp(((struct Obj04570 *)p)->f2C4));
    x = 0;
    for (i = 0; i < 32; i++, x += 32) func_021BA354((u8 *)(a + x), 0, n);
    for (j = 1; j < 25; j++) {
        x = j * 1024;
        y = (j - 1) * 1024;
        for (k = 0; k < 32; k++, x += 32, y += 32) func_021BA354((u8 *)(a + x), (u8 *)(a + y), n);
    }
    x = 0;
    y = 0x6000;
    for (l = 0; l < 32; l++, x += 32, y += 32) func_021BA354((u8 *)(b + x), (u8 *)(a + y), n);
    for (m = 1; m < 28; m++) {
        x = m * 1024;
        y = (m - 1) * 1024;
        for (o = 0; o < 32; o++, x += 32, y += 32) func_021BA354((u8 *)(b + x), (u8 *)(b + y), n);
    }
    func_021B9DCC(p, 3);
}



void func_021BA4AC(char *p, unsigned char *q, void *s, int y)
{
    int x;
    unsigned w;
    func_02045CAC(((struct Obj06590 *)p)->fB0, ((struct Obj01071 *)q)->f0, ((struct Obj06590 *)p)->fB4);
    if (((struct Obj01071 *)q)->fA == 0) {
        x = ((struct Obj01071 *)q)->fC + ((struct Obj01071 *)q)->fE;
    } else if (((struct Obj01071 *)q)->fA == 1) {
        w = func_0201D304(((struct Obj06590 *)p)->fB4, (u32)(*(void **)(p + q[9] * 4 + 0xa8)), 0);
        x = ((struct Obj01071 *)q)->fC + ((struct Obj01071 *)q)->fE - w;
    } else if (((struct Obj01071 *)q)->fA == 2) {
        w = func_0201D304(((struct Obj06590 *)p)->fB4, (u32)(*(void **)(p + q[9] * 4 + 0xa8)), 0);
        x = ((struct Obj01071 *)q)->fC + ((struct Obj01071 *)q)->fE - w / 2;
    }
    PRINTSYS_PrintColor(s, x, y, ((struct Obj06590 *)p)->fB4, *(void **)(p + q[9] * 4 + 0xa8), d_021BAB40[q[8]]);
}



void func_021BA558(char *p,u8 *q){if(q[9]==0)func_021BA4AC(p,q,BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj14412 *)p)->f2C4),192);else func_021BA4AC(p,q,BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj14412 *)p)->f2C4),194);}



void func_021BA594(char *p, unsigned char *q)
{
    void *s;
    int y;
    if (((struct Obj01071 *)q)->f4 < 0x100) {
        s = BMP_WIN_GetBmp(((struct Obj08305 *)p)->f2BC);
        y = ((struct Obj01071 *)q)->f4;
        ((struct Obj08305 *)p)->f2CF |= 1;
    } else {
        s = BMP_WIN_GetBmp(((struct Obj08305 *)p)->f2C4);
        y = ((struct Obj01071 *)q)->f4 - 0x100;
        ((struct Obj08305 *)p)->f2CF |= 2;
    }
    func_021BA4AC(p, q, s, y);
}



/*
 * volatile: display registers 04000052 and 04001052 are hardware.
 */
int func_021BA5E8(char *p)
{
    int a, b;
    switch (((struct Obj01274 *)p)->f2CE) {
    case 0:
        if (((struct Obj01274 *)p)->f2CF & 1) func_0207D63C(0x04000050, 2, 0x21, 0, 16);
        if (((struct Obj01274 *)p)->f2CF & 2) func_0207D63C(0x04001050, 2, 0x21, 0, 16);
        ((struct Obj01274 *)p)->f2CC = ((struct Obj01274 *)p)->f2CF;
        ++((struct Obj01274 *)p)->f2CE;
        break;
    case 1:
        if (((struct Obj01274 *)p)->f2D2 == 1) ((struct Obj01274 *)p)->f2D0 += 16;
        else ((struct Obj01274 *)p)->f2D0 += 4;
        a = ((struct Obj01274 *)p)->f2D0;
        if (a > 16) { a = 16; b = 0; }
        else b = 16 - a;
        if (((struct Obj01274 *)p)->f2CF & 1) *(volatile u16 *)0x04000052 = a | (b << 8);
        if (((struct Obj01274 *)p)->f2CF & 2) *(volatile u16 *)0x04001052 = a | (b << 8);
        if (((struct Obj01274 *)p)->f2D0 >= 16) {
            if (((struct Obj01274 *)p)->f2CF & 1) *(volatile u16 *)0x04000050 = 0;
            if (((struct Obj01274 *)p)->f2CF & 2) *(volatile u16 *)0x04001050 = 0;
            *(u8 *)&((struct Obj01274 *)p)->f2D0 = 0;
            ((struct Obj01274 *)p)->f2CE = 0;
            return 0;
        }
        break;
    }
    return 1;
}



int func_021BA6F0(char *p)
{
    int a, b;
    switch (((struct Obj00784 *)p)->f2CE) {
    case 0:
        if (((struct Obj00784 *)p)->f2CF & 1) func_0207D63C(0x04000050, 2, 0x21, 16, 0);
        if (((struct Obj00784 *)p)->f2CF & 2) func_0207D63C(0x04001050, 2, 0x21, 16, 0);
        ++((struct Obj00784 *)p)->f2CE;
    case 1:
        if (((struct Obj00784 *)p)->f2D2 == 1) ((struct Obj00784 *)p)->f2D0 += 16;
        else ((struct Obj00784 *)p)->f2D0 += 4;
        b = ((struct Obj00784 *)p)->f2D0;
        if (b > 16) { a = 0; b = 16; }
        else a = 16 - b;
        if (((struct Obj00784 *)p)->f2CF & 1) *(volatile u16 *)0x04000052 = a | (b << 8);
        if (((struct Obj00784 *)p)->f2CF & 2) *(volatile u16 *)0x04001052 = a | (b << 8);
        if (((struct Obj00784 *)p)->f2D0 >= 16) {
            if (((struct Obj00784 *)p)->f2CF & 1) BMP_Clear(BMP_WIN_GetBmp(((struct Obj00784 *)p)->f2BC), 0);
            if (((struct Obj00784 *)p)->f2CF & 2) BMP_Clear(BMP_WIN_GetBmp(((struct Obj00784 *)p)->f2C4), 0);
            ((struct Obj00784 *)p)->f2CC = ((struct Obj00784 *)p)->f2CF;
            *(u8 *)&((struct Obj00784 *)p)->f2D0 = 0;
            ++((struct Obj00784 *)p)->f2CE;
        }
        break;
    case 2:
        if (((struct Obj00784 *)p)->f2CF & 1) *(volatile u16 *)0x04000050 = 0;
        if (((struct Obj00784 *)p)->f2CF & 2) *(volatile u16 *)0x04001050 = 0;
        ((struct Obj00784 *)p)->f2CF = 0;
        ((struct Obj00784 *)p)->f2CE = 0;
        return 0;
    }
    return 1;
}



/*
 * volatile: display register stores at 04000050 and 04000052.
 */
int func_021BA83C(char *p)
{
    struct Mtx22 matrix;
    int v;
    unsigned scale;
    switch (((struct Obj00682 *)p)->f2CE) {
    case 0:
        func_021B9A80(p, 1);
        func_0207D63C(0x04000050, 8, 0x20, 0, 16);
        BG_SYS_SetMainPlaneVisible(8, 1);
        func_0207D534((void *)0x0400006c, 0);
        func_0207D534((void *)0x0400106c, 0);
        *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
        ++((struct Obj00682 *)p)->f2CE;
        break;
    case 1:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2D0 += 8;
        else ((struct Obj00682 *)p)->f2D0 += 2;
        v = ((struct Obj00682 *)p)->f2D0;
        if (v >= 16) {
            *(volatile u16 *)0x04000052 = 16;
            BUTTON_MAN_RotScaleMtx22(&matrix, 0, (const void *)0x1000, (const void *)0x1000, 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
            *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
            *(u16 *)&((struct Obj00682 *)p)->f2DA = 0xa6;
            ++((struct Obj00682 *)p)->f2CE;
        } else {
            *(volatile u16 *)0x04000052 = v | ((16 - v) << 8);
            scale = 8 - ((struct Obj00682 *)p)->f2D0 / 2;
            BUTTON_MAN_RotScaleMtx22(&matrix, 0, (const void *)(scale << 12), (const void *)(scale << 12), 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
        }
        break;
    case 2:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2DA -= 4;
        else --((struct Obj00682 *)p)->f2DA;
        if (((struct Obj00682 *)p)->f2DA <= 0) {
            ((struct Obj00682 *)p)->f2DA = 0;
            ++((struct Obj00682 *)p)->f2CE;
        }
        break;
    case 3:
        if (((struct Obj00682 *)p)->f2D2 == 1) ((struct Obj00682 *)p)->f2D0 += 8;
        else ((struct Obj00682 *)p)->f2D0 += 2;
        v = ((struct Obj00682 *)p)->f2D0;
        if (v >= 16) {
            *(volatile u16 *)0x04000050 = 0;
            BG_SYS_SetMainPlaneVisible(8, 0);
            BUTTON_MAN_RotScaleMtx22(&matrix, 0, (const void *)0x1000, (const void *)0x1000, 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
            func_021B9A80(p, 0);
            *(u8 *)&((struct Obj00682 *)p)->f2D0 = 0;
            ((struct Obj00682 *)p)->f2CE = 0;
            return 0;
        } else {
            *(volatile u16 *)0x04000052 = (16 - v) | (v << 8);
            scale = ((struct Obj00682 *)p)->f2D0 / 2 + 1;
            BUTTON_MAN_RotScaleMtx22(&matrix, 0, (const void *)(scale << 12), (const void *)(scale << 12), 0);
            func_02040860(3, (unsigned)&matrix, 0x80, 0x60);
        }
        break;
    }
    return 1;
}



int func_021BAA00(char *p, unsigned char *q)
{
    if (((struct Obj06592 *)q)->f0 == 0xffff) {
        ((struct Obj06591 *)p)->f2DA = ((struct Obj06592 *)q)->f4;
        ((struct Obj06591 *)p)->f2EC = 1;
        return 1;
    }
    if (((struct Obj06591 *)p)->f2DA == 0)
        ((struct Obj06591 *)p)->f2DA = ((struct Obj06592 *)q)->f4;
    func_021BA558(p, q);
    if (q[0x16] != 0 || ((struct Obj06592 *)q)->f14 != 0) {
        ((struct Obj06591 *)p)->f2EC = 1;
        return 1;
    }
    return 0;
}



int func_021BAA54(char *p, unsigned char *q)
{
    if (((struct Obj10725 *)p)->f2EC == 0) {
        ((struct Obj10725 *)p)->f2CD = q[7];
        ((struct Obj10725 *)p)->f2EC = 2;
    }
    func_021BA594(p, q);
    if (q[0x16] != 1)
        return 1;
    return 0;
}



int func_021BAA84(char *p, unsigned char *q)
{
    ((struct Obj14414 *)p)->f2CD = q[7];
    ((struct Obj14414 *)p)->f2EC = 3;
    return 1;
}



int func_021BAA98(char *p)
{
    ((struct Obj24511 *)p)->f2E0 = 1;
    return 0;
}



int func_021BAAA4(char *p)
{
    ((struct Obj24512 *)p)->f2E0 = 0;
    return 0;
}



int func_021BAAB0(char *p)
{
    ((struct Obj24513 *)p)->f2EC = 5;
    return 1;
}



int func_021BAABC(void)
{
    return 1;
}




int func_021BAAC0(void)
{
    BG_SYS_SetMainPlaneVisible(1, 1);
    return 1;
}




int func_021BAAD0(void)
{
    BG_SYS_SetMainPlaneVisible(1, 0);
    return 1;
}



int func_021BAAE0(u8 *p,u8 *q){u8 *s=(u8 *)((u32)p+0x28);func_021B9FD8(s,q[7],((struct Obj14415 *)q)->f4);func_021BA2A8(s,1);return 1;}
