/*
 * file:     demo3d_graphic.c
 * unit:     yes
 * function: func_021BDDD8, func_021BDE98, func_021BDF00, func_021BDF18, func_021BDF24, func_021BDF30, func_021BDF3C, func_021BDF74, func_021BDF88, func_021BDFA8, func_021BDFC0, func_021BE02C, func_021BE078, func_021BE07C, func_021BE084, func_021BE0C4, func_021BE0E0, func_021BE0E8, func_021BE0F0, func_021BE0F4, func_021BE12C, func_021BE13C, func_021BE148, func_021BE158, func_021BE160, func_021BE4B4, func_021BE508, func_021BE538, func_021BE620, func_021BE62C, func_021BE638, func_021BE63C, func_021BE79C, func_021BE7A8, func_021BE7BC, func_021BE7D8, func_021BE7F0, func_021BE85C, func_021BE874, func_021BE8F4, func_021BE920, func_021BE938, func_021BE948, func_021BE990
 * address:  0x021BDDD8
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021C3CCC 0x021C3CCC data a1
 *   d_021BFBC4 0x021BFBC4 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02048CDC 0x02048CDC arm
 *   func_02048C58 0x02048C58 arm
 *   VEC_Fx16Normalize 0x0207CDB8 arm
 *   func_02048CA4 0x02048CA4 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   d_021BFB50 0x021BFB50 data a4
 *   d_021BFC24 0x021BFC24 data a4
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   func_02048BC4 0x02048BC4 arm
 *   func_021BDD40 0x021BDD40 thumb ov203
 *   d_021BFB48 0x021BFB48 data a4
 *   func_02048C4C 0x02048C4C arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_02047964 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   DOUBLE3DDISP_Delete 0x0204EA64 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   TIMEZONE_GetTimeZoneOfHour 0x020113F0 thumb
 *   FX_Div 0x0207C768 arm
 *   _ll_mul 0x0209C054 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_GetNearClipAlt 0x02048B9C arm
 *   G3D_CAMERA_GetFarClipAlt 0x02048BB0 arm
 *   func_0204E8C0 0x0204E8C0 arm
 *   func_02005654 0x02005654 thumb
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   _ffltu 0x0209BE04 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_020115EC 0x020115EC thumb
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   func_021BF7C0 0x021BF7C0 thumb ov203
 *   _s32_div_f 0x0209C0A4 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   d_021C3CE0 0x021C3CE0 data a1
 *   d_021BFCE0 0x021BFCE0 data a4
 *   d_021BFCD4 0x021BFCD4 data a4
 *   d_021BFCEC 0x021BFCEC data a4
 *   func_021BF810 0x021BF810 thumb ov203
 *   func_0200566C 0x0200566C thumb
 *   func_0204EA0C 0x0204EA0C arm
 *   ICA_ANIME_Delete 0x02011558 thumb
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   DOUBLE3DDISP_GetField04 0x0204EA38 arm
 *   G3D_CAMERA_SetNearClipAlt 0x02048BA8 arm
 *   G3D_CAMERA_SetFarClipAlt 0x02048BBC arm
 *   ICA_ANIME_GetFrame 0x0201160C thumb
 *   func_021BF858 0x021BF858 thumb
 *   ICA_ANIME_IncFrameNoLoop 0x020115C0 thumb
 *   ICA_ANIME_SetCameraStatus 0x02011B8C thumb
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   func_02048AD0 0x02048AD0 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   DOUBLE3DDISP_SetField08 0x0204EA4C arm
 *   ICA_ANIME_GetFrameNum 0x02011608 thumb
 *   func_0201493C 0x0201493C thumb
 *   func_0207DCF8 0x0207DCF8 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetFogTable 0x0207DD10 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3X_SetDisp1DotDepth 0x0207DE88 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021C185C  0x021C185C  data
 *   d_021C186C 0x021C186C data a4
 *   d_021C3CF0 0x021C3CF0 data a1
 *   d_021C0348 0x021C0348 data a4
 *   d_021C1868 0x021C1868 data a4
 *   d_021C1860  0x021C1860  data
 *   ICA_ANIME_CreateStream  0x02011510  thumb  arm9
 */
#include "../../matched/include/Obj08374.h"
#include "../../matched/include/Obj10861.h"
#include "../../matched/include/Obj25309.h"
#include "../../matched/include/Obj25310.h"
#include "../../matched/include/Obj25311.h"
#include "../../matched/include/Obj14586.h"
#include "../../matched/include/Obj25312.h"
#include "../../matched/include/Obj25313.h"
#include "../../matched/include/Obj03354.h"
#include "../../matched/include/Obj25315.h"
#include "../../matched/include/Obj25316.h"
#include "../../matched/include/Obj25317.h"
#include "../../matched/include/Obj14588.h"
#include "../../matched/include/Obj25319.h"
#include "../../matched/include/Obj14590.h"
#include "../../matched/include/Obj08376.h"
#include "../../matched/include/Obj08377.h"
#include "../../matched/include/Obj25320.h"
#include "../../matched/include/Obj10863.h"

#define DISP (*(volatile u16 *)0x04000060)
struct DispVram;
struct Node;
struct LightSlot;
struct Rgb555;
struct BgTemplate;
struct DispConfig;
struct Cfg;
struct Bank;
struct Owner;
struct TcblNode;
struct LightSet;
struct Config;
struct Context;
struct Obj;
struct G3dSys;
struct Light;
struct Record;
struct IcaAnime;
struct AnmCtl;
struct Ctx;
struct Rec;
struct Arg;
struct Obj11245;
struct Obj11244;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

struct Block {int tag;struct LightSlot *slots;};

struct Obj {int a,b;struct Block block;};

typedef struct Descriptor { unsigned layer; unsigned config[8]; unsigned type, enable; } Descriptor;

struct Config { u8 pad[0xd],hour,minute; u8 second:7,spare:1; };

typedef signed short s16_021BE02C;

typedef short s16_021BE13C;

typedef long long s64;

typedef int fx32;

typedef struct { fx32 x, y, z; } VecFx32;

struct Cfg {
    u32 f0, f4, f8;
    u8 fc, fd, fe;
    u8 sec : 7, bit7 : 1;
};

struct Cam {
    u8 pad0[8];
    fx32 f8, fc, f10, f14, f18, f1c;
};

struct Ctx {
    u32 owner, id, f8, fc, f10, f14; void *f18; u32 f1c;
    void *f20;
    u32 f24, f28, f2c;
    u32 z30[6];
    u8 mtx[0x24];
    u32 f6c;
    u16 *f70;
    struct Cam *f74;
    u32 f78, f7c;
    u8 b80, b81, b82, b83, b84, b85;
};

typedef signed int     s32;

struct Context { void *owner; u32 a4,a8,ac,a10,step; struct IcaAnime *anime; u8 *table; void *light; u32 a24,a28,count; u8 args[0x3c]; void *events; u16 *indices; struct Record *record; };

typedef int BOOL;

typedef enum { FOG_BLEND_0,FOG_BLEND_1 } GXFogBlend;

typedef enum { FOG_SLOPE_0,FOG_SLOPE_10=10 } GXFogSlope;

struct Record {
    u16 a0,a2,id;
    u16 b0:1,b1:1,blend:1,anti:1,fog:1,edge:1,mode1:1,mode2:1,test:1,ref:5,padbits:2;
    u8 pad08[0x1c];
    int depthoffset;
    u16 clear,alpha;
    u16 polygon:15,polybit:1;
    u16 depth,fogcolor;
    u8 fogalpha,slope;
    u16 offset:15,mode:1;
    u8 fogtable[8];
    u16 edgecolors[8];
};

typedef struct Entry { int x; unsigned short id, pad; int flag; } Entry;

typedef struct Pair { const unsigned short *ids; unsigned count; } Pair;

typedef struct Group { const Pair *pairs; unsigned count; } Group;

typedef struct Selector { const Group *groups; unsigned short count, selector; } Selector;

typedef struct Row { const Selector *selectors; unsigned words[4]; } Row;

typedef struct {
    u16 b0 : 1;
    u16 rest : 15;
} bf_021BE920;

typedef struct Flags { unsigned short doubled:1; unsigned short rest:15; } Flags;

extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void MI_CpuFill8(void *, unsigned, unsigned);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0204363C(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void *func_020056A0(unsigned, unsigned, unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_02048CDC(struct LightSlot *,unsigned,unsigned short *);
extern void func_02048C58(struct LightSlot *);
extern void VEC_Fx16Normalize(int, void *);
extern void func_02048CA4(struct LightSlot *slots, u32 i, struct Rgb555 *in);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void func_0203FC28(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void BG_SYS_Init(unsigned, unsigned, unsigned, unsigned);
extern void func_02040DA8(unsigned, unsigned, unsigned);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void func_020419E4(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(int);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u16 fifoSize, s16_021BE02C heap, void (*setup)(void));
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_021BDD40(void);
extern int func_02048C4C(int);
extern void G3D_SYSTEM_Exit(int);
extern void func_02047964(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawEnd(void);
extern void DOUBLE3DDISP_Delete(void);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern int TIMEZONE_GetTimeZoneOfHour(int row, int col);
extern fx32 FX_Div(fx32, fx32);
extern void *G3D_CAMERA_Create(int, int, int, int, int, int, int, int, VecFx32 *, VecFx32 *, VecFx32 *, int);
extern void G3D_CAMERA_GetNearClipAlt(struct Light *l, u32 *out);
extern void G3D_CAMERA_GetFarClipAlt(struct Light *l, u32 *out);
extern void func_0204E8C0(u32);
extern int func_02005654(int a, int b);
extern void MTX_Identity33_(void *);
extern int _ffltu(u32);
extern int _fadd(int, int);
extern int _fsub(int, int);
extern int _ffix(int);
extern void func_020115EC(struct IcaAnime *p, signed int v);
extern u32 G3D_UTIL_Create(u16, u16, u32);
extern u16 G3D_UTIL_AddUnit(u32, void *);
extern u32 func_02048A18(u8 *a0, int i);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
extern u32 func_021BF7C0(struct Ctx *, u32);
extern void func_021BF810(char *p);
extern void func_0200566C(void);
extern int func_0204EA0C(void);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
extern void G3D_UTIL_Delete(struct Rec *p);
extern u32 DOUBLE3DDISP_GetField04(void);
extern void G3D_CAMERA_SetNearClipAlt(struct Light *,u32);
extern void G3D_CAMERA_SetFarClipAlt(struct Light *,u32);
extern u32 ICA_ANIME_GetFrame(struct Obj11245 *p);
extern void func_021BF858(void *,int,int);
extern u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *,int);
extern void ICA_ANIME_SetCameraStatus(void *,void *);
extern u32 G3D_UTIL_GetObject(u8 *,int);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *,int,int);
extern void func_02048AD0(struct Light *);
extern void G3D_SYSTEM_DrawObject(void *,struct Arg *);
extern void DOUBLE3DDISP_SetField08(void);
extern u32 ICA_ANIME_GetFrameNum(struct Obj11244 *p);
extern void func_0201493C(u32,u32,u32,u32,u32,u16 *,u16);
extern void func_0207DCF8(const u16 *);
extern void G3X_SetFog(BOOL,GXFogBlend,GXFogSlope,int);
extern void G3X_SetFogTable(const u32 *);
extern void G3X_SetClearColor(u16,int,int,int,BOOL);
extern void G3X_SetDisp1DotDepth(int);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
extern void *ICA_ANIME_CreateStream(u32 heap, u32 a1, u32 a2, u32 a3);
void *func_021BDDD8(unsigned swap, void *config, u8 heap);
void func_021BDE98(char *ctx);
void func_021BDF00(u8 *p);
void func_021BDF18(char *p);
void func_021BDF24(char *p);
int func_021BDF30(char *p);
void func_021BDF3C(struct Obj *obj, unsigned short *a, int a2);
void func_021BDF74(char *p,unsigned i,unsigned short val);
void func_021BDF88(char *p, int a, int b);
void func_021BDFA8(u32 a, u8 *p);
void func_021BDFC0(void *ctx, unsigned heap);
void func_021BE02C(void *ctx);
void func_021BE078(void *a0);
void func_021BE07C(void *a0);
void func_021BE084(unsigned char *p, int a, int b);
void func_021BE0C4(char *a);
void func_021BE0E0(void *a0);
void func_021BE0E8(u8 *a0);
int func_021BE0F0(void *p);
void func_021BE0F4(unsigned char *p, u8 heap);
void func_021BE12C(int *p);
void func_021BE13C(void *a);
void func_021BE148(void *p);
void func_021BE150(void);
void func_021BE158(void *p);
struct Ctx *func_021BE160(void *owner, struct Cfg *cfg, u16 heap);
void func_021BE4B4(char *ctx, int b, int c, u32 d);
void func_021BE508(char *p,struct Light *q);
int func_021BE538(const struct Context *ctx, u32 frames);
int func_021BE620(char *p);
u32 func_021BE62C(char *p);
void func_021BE638(char *p,int a);
void func_021BE63C(struct Context *ctx,struct Config *cfg,const struct Record *record,u16 heap);
unsigned func_021BE79C(unsigned x);
u32 func_021BE7A8(u32 id);
void *func_021BE7BC(u32 a, u32 b, u32 c);
u8 func_021BE7D8(unsigned x);
void *func_021BE7F0(unsigned heap);
void func_021BE85C(char *a);
void func_021BE874(char *ctx, const char *config, u8 type);
void * func_021BE8F4(char *p,u8 *q);
u32 func_021BE920(u32 a);
int func_021BE938(void *a);
void func_021BE948(void *ctx, int mode, unsigned char *width, unsigned char *height);
u32 func_021BE990(u32 id);
extern const char d_021C3CCC[];
extern const unsigned char d_021BFBC4[][48];
extern const Descriptor d_021BFC24[];
extern const unsigned d_021BFB50[];
extern const struct LightSet d_021BFB48;
extern const char d_021C3CE0[];
extern const s16_021BE13C FX_SinCosTable_[];
extern VecFx32 d_021BFCE0;
extern VecFx32 d_021BFCD4;
extern VecFx32 d_021BFCEC;
extern u8 d_021C185C[];
extern char d_021C186C[];
extern const char d_021C3CF0[];
extern unsigned d_021C0348[];
extern const Row d_021C1868[];
extern u8 d_021C1860[];



/*
 * volatile: 04000050/04001050 hardware stores DE06/DE0C; 04000000/04001000 rereads DE10/DE1A.
 */
void *func_021BDDD8(unsigned swap, void *config, u8 heap)
{
    unsigned char *ctx = func_02030734(heap, 24, 0, d_021C3CCC, 0x15a);
    MI_CpuFill8(ctx, 0, 24);
    ((struct Obj08374 *)ctx)->f14 = func_021BE938(config);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BFBC4[((struct Obj08374 *)ctx)->f14]);
    func_0204363C(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    if (((struct Obj08374 *)ctx)->f14 == 0) {
        func_021BDFC0(ctx, heap);
        func_021BE084(ctx + 4, (int)d_021BFBC4, heap);
        ((struct Obj08374 *)ctx)->f10 = func_020056A0((unsigned)func_021BDFA8, (unsigned)ctx, 0);
    }
    func_021BE0F4(ctx + 8, heap);
    return ctx;
}



void func_021BDE98(char *ctx)
{
    if (((struct Obj10861 *)ctx)->f14 == 0) func_02030EAC(((struct Obj10861 *)ctx)->f10);
    func_021BE12C((int *)(ctx + 8));
    if (((struct Obj10861 *)ctx)->f14 == 0) {
        func_021BE0C4(ctx + 4);
        func_021BE02C(ctx);
    }
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    MI_CpuFill8(ctx, 0, 24);
    func_020307B0(ctx);
}




/*
 * Addresses are Black-image addresses.
 */
void func_021BDF00(u8 *p)
{
    if (((struct Obj25309 *)p)->f14 == 0) {
        func_021BE0E0(p + 4);
        func_021BE078(p);
    }
}



void func_021BDF18(char *p){func_021BE13C(p+8);}



void func_021BDF24(char *p){func_021BE148(p+8);}



int func_021BDF30(char *p){return func_021BE0F0(p+4);}



void func_021BDF3C(struct Obj *obj, unsigned short *a, int a2){struct Block *p=&obj->block;func_02048CDC(p->slots,0,a);func_02048CDC(p->slots,1,a+1);func_02048CDC(p->slots,2,a+2);func_02048CDC(p->slots,3,a+3);func_02048C58(p->slots);}



void func_021BDF74(char *p,unsigned i,unsigned short val){func_02048CDC(*(struct LightSlot **)(p+12),i,&val);}




void func_021BDF88(char *p, int a, int b)
{
    int buf[2];
    VEC_Fx16Normalize(b, buf);
    func_02048CA4(((struct Obj25310 *)p)->fC, a, (struct Rgb555 *)buf);
}




void func_021BDFA8(u32 a, u8 *p)
{
    if (((struct Obj25311 *)p)->f14 == 0) {
        func_021BE07C(p);
        func_021BE0E8(p + 4);
    }
}


void func_021BDFC0(void *ctx, unsigned heap)
{
    unsigned i = 0;
    const Descriptor *descriptor;
    unsigned layer;
    MI_CpuFill8(ctx, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_021BFB50);
    for (; i < 4; i++) {
        descriptor = &d_021BFC24[i];
        layer = descriptor->layer;
        BG_SYS_InitBgLayer((unsigned char)layer, (const struct BgTemplate *)descriptor->config, (unsigned char)descriptor->type);
        func_020414AC(layer);
        func_02040588(layer, descriptor->enable);
    }
    BG_SYS_Init(1, 0, 1, 0);
}








void func_021BE02C(void *ctx)
{
    unsigned i = 0;
    unsigned layer;
    func_02040DA8(1, 1, 0);
    for (; i < 4; i++) {
        layer = d_021BFC24[i].layer;
        func_02040588((unsigned char)layer, 0);
        func_020403F4((unsigned char)layer);
    }
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(ctx, 0, 4);
}









void func_021BE078(void *a0){}









void func_021BE07C(void *a0){func_020419E4();}










void func_021BE084(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021BFB60, a, b);
    ((struct Obj14586 *)p)->f0 = CLACT_CreateUnit(0x20, 0, b);
    CLACT_SetUnitDefaultRenderer(((struct Obj14586 *)p)->f0);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}









void func_021BE0C4(char *a)
{
    CLACT_ExitSystem(CLACT_DeleteUnit((struct Bank *)(((struct Obj25312 *)a)->f0)));
    MI_CpuFill8(a, 0, 4);
}








void func_021BE0E0(void *a0){CLACT_DrawSystem();}








void func_021BE0E8(u8 *a0) { CLACT_VBlankSystem(); }









int func_021BE0F0(void *p){return ((struct Obj25313 *)p)->f0;}








/*
 * lever: twin of ov204_func_021BE03C.c (3D setup, texSize 2, plttSize 4,
 * light set 0x021BFB48); u8 heap parameter.
 */
void func_021BE0F4(unsigned char *p, u8 heap)
{
    G3D_SYSTEM_Init(0, 2, 0, 4, 0, heap, func_021BDD40);
    *(struct LightSlot **)(p + 4) = func_02048BC4(&d_021BFB48, heap);
    func_02048C58(*(struct LightSlot **)(p + 4));
}









void func_021BE12C(int *p)
{
    G3D_SYSTEM_Exit(func_02048C4C(p[1]));
}








void func_021BE13C(void *a)
{
    func_02047964();
    G3D_SYSTEM_ApplyLookAt();
}







void func_021BE148(void *p){G3D_SYSTEM_DrawEnd();}







/*
 * leaf: solely blocks assigned 021BDF24; parent cleared ownership.
 * extent: three 8-byte wrappers; ends at peer-owned 021BE160, which is excluded.
 */
void func_021BE150(void){DOUBLE3DDISP_Delete();}







void func_021BE158(void *p){G3D_CAMERA_Delete(p);}








static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}








/*
 * 2026-10-05 (integrator): the angle divisor is the plain literal 360 and the alloc size the literal 0x88; mwcc derives 0x168 from the live 0x88 itself (`adds r7,#0xE0`), so the earlier `sz` local was not needed. EXACT in c99 and c.
 * note: 2026-10-05 wave P2 lane Q3 (pengy share, user-approved). Levers: heap is a u16
 *   parameter (entry spill of r2 first, raw reload at every use); cam written as
 *   `cam = ctx->f74 = func_021BE7A8(...)` (store to ctx first, then the local slot sp+0x24);
 *   cnt is a signed int (ble guard); ortho bounds as in ov088 021B9C2C (FX_Mul/FX_Div,
 *   top = FX_Div(t, c), bottom = -FX_Div(t, c)). The angle divisor is written sz + 0xE0:
 *   the original keeps 0x88 live in r7 (alloc size) and derives 0x168 from it with
 *   adds #0xE0; flagged for the integrator as an odd but listing-forced form.
 */
struct Ctx *func_021BE160(void *owner, struct Cfg *cfg, u16 heap)
{
    struct Ctx *ctx;

    int ang, right, d, w, top, t, s, j, near, mid, far, bottom;
    struct Cam *cam;
    int c, q;
    int i, k, n, r;
    int left;
    int cnt;
    void *e;
    u32 h;

    ctx = func_02030734(heap, 0x88, 1, d_021C3CE0, 0x79);
    ctx->owner = (u32)owner;
    ctx->id = cfg->f4;
    ctx->f78 = ctx->id;
    ctx->b80 = cfg->fc;
    ctx->f7c = cfg->f8;
    ctx->b81 = TIMEZONE_GetTimeZoneOfHour((u8)cfg->sec, (u8)cfg->fd);
    ctx->b82 = cfg->bit7;
    ctx->b83 = cfg->fd;
    ctx->b84 = cfg->fe;
    ctx->b85 = cfg->sec;
    cam = ctx->f74 = (struct Cam *)func_021BE7A8(ctx->id);
    q = (((cam->fc >> 12) / 2) << 16) / 360;
    c = FX_SinCosTable_[(q >> 4) * 2 + 1];
    far = cam->f1c;
    mid = cam->f18;
    near = cam->f14;
    q = (((cam->f8 >> 12) / 2) << 16) / 360;
    s = FX_SinCosTable_[(q >> 4) * 2];
    t = FX_Mul(near, s);
    top = FX_Div(t, c);
    bottom = -FX_Div(t, c);
    w = FX_Mul(near, 0x1555);
    d = 0x1000;
    right = FX_Div(FX_Mul(FX_Div(w, d), s), c);
    left = -FX_Div(FX_Mul(FX_Div(w, d), s), c);
    ctx->f20 = G3D_CAMERA_Create(1, top, bottom, left, right, near, mid, far,
                             &d_021BFCE0, &d_021BFCD4, &d_021BFCEC, heap);
    G3D_CAMERA_GetNearClipAlt(ctx->f20, &ctx->f24);
    G3D_CAMERA_GetFarClipAlt(ctx->f20, &ctx->f28);
    func_021BE63C((struct Context *)ctx, (struct Config *)cfg, (const struct Record *)ctx->f74, heap);
    ctx->f14 = func_021BE920(ctx->id);
    ctx->f10 = func_021BE938((void *)ctx->id);
    if (ctx->f10) {
        func_0204E8C0(heap);
        func_02005654((int)func_021BE150, 0);
    }
    ctx->z30[0] = 0;
    ctx->z30[1] = 0;
    ctx->z30[2] = 0;
    ctx->z30[3] = 0x1000;
    ctx->z30[4] = 0x1000;
    ctx->z30[5] = 0x1000;
    MTX_Identity33_(ctx->mtx);
    ctx->f2c = func_021BE7D8(ctx->id);
    ctx->f70 = func_02030734(heap, ctx->f2c * 2, 1, d_021C3CE0, 0xB7);
    ctx->f18 = func_021BE7BC(ctx->id, heap, 10);
    if (ctx->f7c)
        r = _fadd(0x3f000000, _ffltu(ctx->f7c << 12));
    else
        r = _fsub(_ffltu(ctx->f7c << 12), 0x3f000000);
    func_020115EC((struct IcaAnime *)ctx->f18, _ffix(r));
    n = ctx->f2c * 6;
    ctx->f1c = G3D_UTIL_Create((u16)n, (u16)n, heap);
    e = func_021BE7F0(heap);
    for (i = 0; i < ctx->f2c; i++) {
        func_021BE874(e, (const char *)(&ctx->f78), i);
        ctx->f70[i] = G3D_UTIL_AddUnit(ctx->f1c, e);
    }
    func_021BE85C(e);
    for (j = 0; j < ctx->f2c; j++) {
        h = func_02048A18((u8 *)ctx->f1c, (u16)ctx->f70[j]);
        cnt = G3D_SYSTEM_GetObjectAnimeCount((int *)h);
        for (k = 0; k < cnt; k++) {
            if (ctx->f7c)
                r = _fadd(0x3f000000, _ffltu(ctx->f7c << 12));
            else
                r = _fsub(_ffltu(ctx->f7c << 12), 0x3f000000);
            ang = _ffix(r);
            G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)h, (u16)k);
            G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)h, k, &ang);
        }
    }
    ctx->f6c = func_021BF7C0(ctx, heap);
    return ctx;
}







void func_021BE4B4(char *ctx, int b, int c, u32 d)
{
    unsigned i;
    func_021BF810(((struct Obj03354 *)ctx)->f6C);
    func_021BE158(((struct Obj03354 *)ctx)->f20);
    if (((struct Obj03354 *)ctx)->f10) {
        func_0200566C();
        func_0204EA0C();
    }
    ICA_ANIME_Delete(((struct Obj03354 *)ctx)->f18);
    for (i = 0; i < ((struct Obj03354 *)ctx)->f2C; i++) {
        G3D_UTIL_RemoveUnit(((struct Obj03354 *)ctx)->f1C, (*(unsigned short **)(ctx + 0x70))[i]);
    }
    G3D_UTIL_Delete(((struct Obj03354 *)ctx)->f1C);
    func_020307B0(((struct Obj03354 *)ctx)->f70);
    func_020307B0(ctx);
}







/*
 * extent: 46-byte body plus two-byte alignment at 0x021BE536.
 * blocked: ARM9 0x02048BA8 and 0x02048BBC; existing matched unit_02048AD0.c contains their bodies but omits both from function:.
 * spelling: loads repeated in explicit branch arms reproduce cmp-before-base-load; shared-base and offset ternary differ.
 *   0x02048BA8 ARM EXACT, dsi/1.1p1 -O4,p, verified without --region:
 *   void G3D_CAMERA_SetNearClipAlt(struct Light *p,u32 v) { *(u32 *)((char *)p+4)=v; }
 *   0x02048BBC ARM EXACT, dsi/1.1p1 -O4,p, verified without --region:
 *   void G3D_CAMERA_SetFarClipAlt(struct Light *p,u32 v) { *(u32 *)((char *)p+8)=v; }
 */
void func_021BE508(char *p,struct Light *q)
{
    int x;
    if(DOUBLE3DDISP_GetField04()==0)x=*(short *)(*(char **)(p+0x74)+0x20);
    else x=*(short *)(*(char **)(p+0x74)+0x22);
    G3D_CAMERA_SetNearClipAlt(q,x+*(u32 *)(p+0x24));
    G3D_CAMERA_SetFarClipAlt(q,x+*(u32 *)(p+0x28));
}






int func_021BE538(const struct Context *ctx, u32 frames)
{
    u32 done;
    long advance = 0;
    unsigned long time = ICA_ANIME_GetFrame((struct Obj11245 *)ctx->anime);
    u32 i;
    for(i=0;i<frames+1;i++) {
        if(ctx->a8 == 0) func_021BF858(ctx->events,time+advance,i);
        else func_021BF858(ctx->events,-4096,i);
        advance += ctx->step;
    }
    done = ICA_ANIME_IncFrameNoLoop(ctx->anime,advance);
    ICA_ANIME_SetCameraStatus(ctx->light,ctx->anime);
    for(i=0;i<ctx->count;i++) {
        void *obj=(void *)G3D_UTIL_GetObject(ctx->table,ctx->indices[i]);
        int j, count=G3D_SYSTEM_GetObjectAnimeCount(obj);
        for(j=0;j<count;j++) G3D_SYSTEM_LoopObjectAnimeFrame(obj,(u16)j,advance);
    }
    if(ctx->a10 != 0) func_021BE508((char *)ctx,ctx->light);
    func_02048AD0(ctx->light);
    func_021BDF18(ctx->owner);
    for(i=0;i<ctx->count;i++) {
        G3D_SYSTEM_DrawObject((void *)G3D_UTIL_GetObject(ctx->table,ctx->indices[i]),(struct Arg *)ctx->args);
    }
    func_021BDF24(ctx->owner);
    if(ctx->a10 != 0) DOUBLE3DDISP_SetField08();
    return done;
}






int func_021BE620(char *p) { return ICA_ANIME_GetFrame(((struct Obj25315 *)p)->f18); }






u32 func_021BE62C(char *p) { return ICA_ANIME_GetFrameNum(((struct Obj25316 *)p)->f18); }





void func_021BE638(char *p,int a) { ((struct Obj25317 *)p)->f8=a; }



static inline void Anti(BOOL enable) {
    if(enable) DISP=(u16)((DISP & ~0x3000)|16);
    else DISP &= (u16)~0x3010;
}



static inline void Test(BOOL enable,int ref) {
    if(enable) { DISP=(u16)((DISP & ~0x3000)|4); *(volatile u16 *)0x04000340=(u16)ref; }
    else DISP &= (u16)~0x3004;
}



static inline void Blend(BOOL enable) {
    if(enable) DISP=(u16)((DISP & ~0x3000)|8);
    else DISP &= (u16)~0x3008;
}



static inline void Edge(BOOL enable) {
    if(enable) DISP=(u16)((DISP & ~0x3000)|32);
    else DISP &= (u16)~0x3020;
}



/*
 * The original reserves 20 bytes for colors at sp+0x2c and 32 for fogtable
 * at sp+0x0c. Keeping cfg mutable moves the colors address before record's
 * parameter copy; const record preserves the later clear-color loads.
 * volatile: 0x04000060, 0x04000340, 0x04000358
 */
void func_021BE63C(struct Context *ctx,struct Config *cfg,const struct Record *record,u16 heap)
{
    u16 colors[10];
    u32 fogtable[8];
    u32 i;
    func_0201493C(record->id,cfg->hour,cfg->minute,0,cfg->second,colors,heap);
    func_021BDF3C(ctx->owner,colors,0);
    Anti(record->anti);
    Test(record->test,ctx->record->ref);
    Blend(record->blend);
    Edge(record->edge);
    if(record->edge) func_0207DCF8(record->edgecolors);
    G3X_SetFog(record->fog,(GXFogBlend)record->mode,(GXFogSlope)record->slope,record->offset);
    if(record->fog) {
        *(volatile u32 *)0x04000358=record->fogcolor|(record->fogalpha<<16);
        for(i=0;i<8;i++) fogtable[i]=record->fogtable[i];
        G3X_SetFogTable(fogtable);
    }
    G3X_SetClearColor(record->clear,record->alpha,record->depth,record->polygon,record->fog);
    G3X_SetDisp1DotDepth(record->depthoffset);
    G3D_SYSTEM_SetSwapBuffersMode(record->mode1,record->mode2);
}




unsigned func_021BE79C(unsigned x) { if(x==0||x>=19)x=0;return x; }





u32 func_021BE7A8(u32 id)
{
    return *(u32 *)(d_021C185C + func_021BE79C(id) * 0x14);
}





void *func_021BE7BC(u32 a, u32 b, u32 c)
{
    u16 *t = (u16 *)func_021BE7A8(a);

    return ICA_ANIME_CreateStream(b, 0xa0, *t, c);
}




u8 func_021BE7D8(unsigned x) { return *(u32 *)(d_021C186C+func_021BE79C(x)*20); }




void *func_021BE7F0(unsigned heap)
{
    char *ctx;
    Entry *entries;
    char *extra;
    int i;
    ctx = func_02030734(heap, 16, 1, d_021C3CF0, 0xab);
    entries = func_02030734(heap, 72, 1, d_021C3CF0, 0xac);
    extra = func_02030734(heap, 16, 1, d_021C3CF0, 0xad);
    for (i = 0; i < 6; i++) {
        entries[i].x = 160;
        entries[i].flag = 0;
    }
    ((struct Obj25319 *)extra)->f8 = d_021C0348;
    *(Entry * *)&((struct Obj14588 *)ctx)->f0 = entries;
    *(char * *)&((struct Obj14588 *)ctx)->f8 = extra;
    return ctx;
}





void func_021BE85C(char *a)
{
    func_020307B0((void *)((struct Obj14590 *)a)->f8);
    func_020307B0((void *)((struct Obj14590 *)a)->f0);
    func_020307B0(a);
}




void func_021BE874(char *ctx, const char *config, u8 type)
{
    Entry *entries = *(Entry * *)&((struct Obj08376 *)ctx)->f0;
    char *extra = *(char * *)&((struct Obj08376 *)ctx)->f8;
    unsigned choice = 0;
    const Group *group;
    int i;
    const Pair *pair;
    group = func_021BE8F4((char *)(&d_021C1868[*(unsigned *)config].selectors[type]), (u8 *)config);
    if (group->count > 1) choice = *(const unsigned char *)&((struct Obj08377 *)config)->f9;
    if (choice >= group->count) choice = 0;
    pair = &group->pairs[choice];
    ((struct Obj08376 *)ctx)->f4 = pair->count;
    for (i = 0; i < 6; i++) {
        if (i < pair->count) entries[i].id = pair->ids[i];
        else entries[i].id = 0;
    }
    ((struct Obj08376 *)ctx)->fC = 1;
    ((struct Obj25320 *)extra)->fC = pair->count - 1;
}





void * func_021BE8F4(char *p,u8 *q) { int x=0;switch(((struct Obj10863 *)p)->f6){case 1:x=q[10];break;case 2:x=q[8];break;case 3:x=q[13];break;}if(x>=((struct Obj10863 *)p)->f4)x=0;return (void *)(((struct Obj10863 *)p)->f0+x*8); }





/*
 * The width-1 bitfield must sit at bit 0 (`b0:1`), not bit 15: the original
 * extracts with the equal shift pair `lsls #0x1f / lsrs #0x1f`, so it is the
 * low bit of the halfword at +6 that is shifted by 0x1000.
 * Addresses are Black-image addresses.
 */
u32 func_021BE920(u32 a)
{
    bf_021BE920 *p = (bf_021BE920 *)(func_021BE7A8(a) + 6);

    return 0x1000 >> p->b0;
}





int func_021BE938(void *a)
{
    unsigned int v = *(unsigned short *)(func_021BE7A8((u32)a) + 6);
    return (v << 30) >> 31;
}




void func_021BE948(void *ctx, int mode, unsigned char *width, unsigned char *height)
{
    unsigned char *record = (unsigned char *)func_021BE7A8((u32)ctx);
    if (mode == 0) {
        *width = record[0x4e];
        *height = record[0x4f] * (((Flags *)(record + 6))->doubled + 1);
    } else {
        *width = record[0x50];
        *height = record[0x51] * (((Flags *)(record + 6))->doubled + 1);
    }
}





/*
 * closed: dropping the contested ov203 token lets the function's own region
 * pick the object; the +0010 ABS32 resolves as sole-ref/data and the file is
 * EXACT.  See docs/idioms/omitting-an-overlay-hint-can-attest-where-naming-it-cannot.md.
 * Addresses are Black-image addresses.
 */
u32 func_021BE990(u32 id)
{
    return *(u32 *)(d_021C1860 + func_021BE79C(id) * 0x14);
}
