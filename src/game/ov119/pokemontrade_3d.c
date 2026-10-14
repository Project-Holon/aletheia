/*
 * file:     pokemontrade_3d.c
 * unit:     yes
 * function: POKETRADE_3D_CreateIcaStreamsForMode, POKETRADE_3D_DeleteIcaStreams, POKETRADE_3D_CreateIcaStreamsEnding, POKETRADE_3D_FreeParticleResources, POKETRADE_3D_InitParticleSystems, POKETRADE_3D_SetupParticleSystemsLow, POKETRADE_3D_SetupParticleSystemsHigh, POKETRADE_3D_ExitParticleManager, POKETRADE_3D_InitTradeParticleSet, POKETRADE_3D_Init3DScene, POKETRADE_3D_Update3DScene, POKETRADE_3D_Delete3DScene, POKETRADE_3D_UploadCubeTextures, POKETRADE_3D_AddUnitAndInit, POKETRADE_3D_RemoveCurrentUnit, POKETRADE_3D_AddUnit, POKETRADE_3D_RemoveUnit, POKETRADE_3D_Draw3DScene, POKETRADE_3D_SetMcssOffsetForSpecies, POKETRADE_3D_AddPokemonMcss, POKETRADE_3D_AddPokemonMcssFlipped, POKETRADE_3D_AddPokemonMcssPlain, POKETRADE_3D_DeleteMcssSlot, POKETRADE_3D_EmitCubeVertex, POKETRADE_3D_SetCubeNormal, POKETRADE_3D_SetCubeTexCoord, POKETRADE_3D_FillTextureCell, POKETRADE_3D_FillTexturePage, POKETRADE_3D_FillTextureHeader, POKETRADE_3D_UploadTexturePages, POKETRADE_3D_SetToonEdgeColors, POKETRADE_3D_DrawCubeFace, POKETRADE_3D_DrawRotatingCube, POKETRADE_3D_LoadTexturePalette, POKETRADE_3D_FadeTexturePalette, POKETRADE_3D_CreateTouchbar
 * address:  0x021E2D70
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pokemontrade_proc.c, pokemontrade_3d.c by tools/splitfile.py.
 *
 * symbols:
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   MI_CpuFill8 0x02082BCC arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02017E1C 0x02017E1C thumb
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssFlipped  0x021E36A8  thumb  ov119
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   POKETRADE_3D_UploadCubeTextures 0x021E31FC thumb ov119
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   func_02030734 0x02030734 arm
 *   POKETRADE_3D_RemoveCurrentUnit 0x021E3230 thumb ov119
 *   POKETRADE_3D_Init3DScene 0x021E30EC thumb ov119
 *   POKETRADE_3D_CreateTouchbar 0x021E3C20 thumb ov119
 *   POKETRADE_3D_AddPokemonMcssPlain 0x021E36C8 thumb ov119
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   POKETRADE_3D_Update3DScene 0x021E31B4 thumb ov119
 *   POKETRADE_3D_Delete3DScene 0x021E31BC thumb ov119
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   FX_SinCosTable_    0x020A1B38  data
 *   ICA_ANIME_CreateStream 0x02011510 thumb
 *   func_020115EC 0x020115EC thumb
 *   ICA_ANIME_Delete 0x02011558 thumb
 *   PARTICLE_InitManager 0x02050B80 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   d_021E81C0 0x021E81C0 data a4
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   func_02087A3C 0x02087A3C arm
 *   func_020056BC 0x020056BC thumb
 *   PARTICLE_SetupSystemBorrowed 0x02051360 arm
 *   PARTICLE_ExitManager  0x02050ED4  arm
 *   PARTICLE_SetupSystem  0x02051230  arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   d_021E7AF4 0x021E7AF4 data a4
 *   d_020A1EB8 0x020A1EB8 data a2
 *   d_021E7AC4 0x021E7AC4 data a4
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   tbl_021E7AC4   0x021E7AC4  data   ov119  a4
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   d_021E7B3C 0x021E7B3C data a4
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   PARTICLE_DrawAllSystems  0x02051534  arm
 *   PARTICLE_UpdateAllSystems  0x02051574  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb
 *   d_021E7AC8  0x021E7AC8  data a4
 *   d_021E8144  0x021E8144  data a4
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   MCSS_GetSizeX 0x02015F04 thumb
 *   MCSS_GetOfsX 0x02015F14 thumb
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 *   d_021E7B9C 0x021E7B9C data a4
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   MCSS_TOOL_AddPokeMcss 0x02017270 thumb
 *   MCSS_TOOL_SetAnimeStopCallback 0x020173B4 thumb
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_SetShadowVanishFlag 0x02015FF0 thumb
 *   data_021E7B00 0x021E7B00 data a4
 *   data_021E7B0C 0x021E7B0C data a4
 *   MCSS_Del  0x02015BA4  thumb
 *   d_021E8190 0x021E8190 data a2
 *   d_021E8178 0x021E8178 data a4
 *   d_021E8168 0x021E8168 data a4
 *   func_0207F7A0 0x0207F7A0 arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207F7FC 0x0207F7FC arm
 *   func_0207F9B4 0x0207F9B4 arm
 *   func_0207D84C 0x0207D84C arm
 *   func_0207D810 0x0207D810 arm
 *   func_0207DA8C 0x0207DA8C arm
 *   func_0207D7C4 0x0207D7C4 arm
 *   func_021D8A18 0x021D8A18 thumb ov119
 *   d_021E815C 0x021E815C data ov119 a4
 *   d_021E79AC 0x021E79AC data ov119 a4
 *   d_021E8150 0x021E8150 data ov119 a4
 *   func_02049F78 0x02049F78 arm
 *   func_02083194 0x02083194 arm
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_SetAllButtonsPriority 0x021B6520 thumb ov067
 *   d_021E7C0C 0x021E7C0C data a4
 *   POKETRADE_SAVE_Init3DProjection 0x021E2B14 thumb ov119
 *   POKETRADE_SAVE_Free3DLightSet 0x021E2B68 thumb ov119
 */
#include "pokemontrade_types.h"
#include "../../matched/include/Obj00673.h"
#include "../../matched/include/Obj02173.h"
#include "../../matched/include/Obj08067.h"
#include "../../matched/include/Obj04480.h"
#include "../../matched/include/Obj08068.h"
#include "../../matched/include/Obj13911.h"
#include "../../matched/include/Obj22795.h"
#include "../../matched/include/Obj22796.h"

extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);

extern void MI_CpuFill8(void *,int,int);

extern void DWC_RAP_SetVchatTalkLock(int);

extern void func_02047964(void);

extern void func_02048AD0(struct Light *l);

extern void G3D_SYSTEM_ApplyLookAt(void);

extern void *func_020490F4(unsigned int id, unsigned int heap);

extern void ARC_TOOL_DeleteHandle(void *);

#define F32_TO_FX32(f) ((int)(((f) > 0) ? ((f) * 4096.0f + 0.5f) : ((f) * 4096.0f - 0.5f)))

#define REG_VTX_16 (*(vu32 *)0x0400048C)

#define REG(a) (*(volatile unsigned long *)(a))

struct G3dSys;

struct Arg;

typedef signed int     s32_021E2D70;

typedef struct {
    void *a[9];         /* 0x000 */
    void *b[6];         /* 0x024 */
    u16 pad3C[0x3F];    /* 0x03C */
    u16 heap;           /* 0x0BA */
} TradeParticleSet;

typedef short s16_021E3004;

typedef struct {u32_021DEA24 x,y,z;} Vec_021E3004;

typedef struct {void (*call)(char *);u32_021DEA24 other;} Callback;

typedef void (*Fn)(void *);

typedef struct {int a,b,c; u16 d,e;} Entry_021E324C;

typedef struct {
    void (*fn)(char *p, void *out);
    int unused;
} Handler;

typedef struct {
    char pad00[0x90];
    int *a90;           /* 0x090 */
    int *a94;           /* 0x094 */
    int *a98;           /* 0x098 */
    int *a9C;           /* 0x09C */
    int pada0[2];       /* 0x0A0 */
    int aA8;            /* 0x0A8 */
    int aAC;            /* 0x0AC */
} Sub_021E3004;

typedef signed int     s32_021E3208;

typedef struct {
    int a;
    int b;
    int c;
    int d;
    float x;
    float y;
    float z;
} Entry_021E33FC;

typedef struct {
    int x;
    int y;
    int z;
} Vec_021E33FC;

typedef signed short   s16_021E33FC;

typedef struct { int x, y, z; } Vec_021E35A0;

typedef struct { u32_021DEA24 v[4]; } Table_021E3004;

typedef short s16_021E3700;

typedef s16_021E3700 fx16;

typedef volatile u32_021DEA24 vu32;

typedef unsigned long u32_021E38D8;

typedef long fx32_021E38D8;

typedef unsigned long u32_021E3A40;

typedef long fx32;

typedef struct { fx32 x,y,z; } VecFx32_021E3A40;

typedef struct { fx32 a[12]; } MtxFx43;

typedef unsigned int   u32_021E3B2C;

typedef struct { u32 f0, f4; u16 f8, fA, fC, fE, f10, f12; u32 f14, f18, f1C; } Element;

typedef struct { Element e[4]; } Template_021E3A40;

typedef struct { void *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1C; } Config_021E3A40;

extern u32_021DEF1C func_02017E1C(void *,u32_021DEF1C,u32_021DEF1C);

extern u32_021DEF1C func_020307B0(void *p);

extern void MI_CpuCopy8(const void *,void *,unsigned);

extern void MCSS_SetVanishFlag(void *);

extern void *ICA_ANIME_CreateStream(u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24);

extern void func_020115EC(struct IcaAnime *p, s32_021E2D70 v);

extern void ICA_ANIME_Delete(struct IcaAnime *p);

extern void PARTICLE_InitManager(u32_021DEA24 heap);

extern void *func_02030734(u32_021DEA24 heapId, u32_021DEA24 size, int clear, const char *site, u16 tag);

extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);

extern int PARTICLE_LoadArchiveMember(u32_021DEA24 a, u32_021DEA24 b, u32_021DEA24 c);

extern void func_02087A3C(int clear, u32_021DEA24 flags);

extern u32_021DEA24 func_020056BC(void);

extern void PARTICLE_SetupSystemBorrowed(void *p, unsigned int a1, unsigned int a2, unsigned int a3);

extern void PARTICLE_ExitManager(void);

extern void PARTICLE_SetupSystem(void *, void *, int, int);

extern void *G3D_UTIL_Create(u16,u16,u16);

extern void *G3D_CAMERA_Create(u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,u32_021DEA24,Vec_021E3004 *,Vec_021E3004 *,Vec_021E3004 *,u16);

extern unsigned int G3D_CAMERA_Delete(void *ptr);

extern void G3D_UTIL_Delete(struct Rec *p);

extern u16 G3D_UTIL_AddUnit(void *,const Entry_021E324C *);

extern u32_021DEA24 func_02048A18(u8 *a0, int i);

extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);

extern u32_021DEA24 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32_021DEA24 idx);

extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32_021DEA24 i);

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

extern int PARTICLE_DrawAllSystems(void);

extern int PARTICLE_UpdateAllSystems(void);

extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

extern u32_021DEA24 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32_021E3208 v);

extern u8 POKE_TOOL_GetGender(void *p);

extern u16 MCSS_GetSizeX(void *p);

extern s16_021E33FC MCSS_GetOfsX(void *p);

extern void MCSS_SetOfsPosition(void *p, u32_021DEA24 *src);

extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);

extern u32_021DEA24 POKE_PERSONAL_GetParam(const struct Personal *p, u32_021DEA24 field);

extern void POKE_PERSONAL_Delete(void *h);

extern void *MCSS_TOOL_AddPokeMcss(void *a0, void *a1, u32_021DEA24 a2, u32_021DEA24 a3, u32_021DEA24 a4, u32_021DEA24 a5);

extern int MCSS_TOOL_SetAnimeStopCallback(int a0);

extern void MCSS_SetScale(void *p, u32_021DEA24 *src);

extern void MCSS_SetShadowVanishFlag(char *p, int v);

extern void MCSS_Del(void *sys, void *obj);

extern void func_0207F7A0(void);

extern void DWCi_ScreenDC_FlushRange(void *, int);

extern void func_0207F7FC(void *, int, int);

extern void func_0207F9B4(void);

extern void func_0207D84C(fx32_021E38D8,fx32_021E38D8);

extern void func_0207D810(fx32_021E38D8,fx32_021E38D8);

extern void func_0207DA8C(void);

extern void func_0207D7C4(const VecFx32_021E3A40 *,const VecFx32_021E3A40 *,const VecFx32_021E3A40 *,int,MtxFx43 *);

extern u8 func_021D8A18(u8 *);

extern void *func_02049F78(void *a0, u32_021E3B2C a1, u32_021E3B2C a2, u32_021E3B2C a3);

extern void func_02083194(const void *, void *, int);

extern void func_0207FA0C(void);

extern void func_0207FA40(const void *, int, int);

extern void func_0207FADC(void);

extern void *TOUCHBAR_Create(Config_021E3A40 *, int);

extern void TOUCHBAR_SetAllButtonsPriority(u8 *p, u32 v);

void POKETRADE_SAVE_Init3DProjection(int a);

void POKETRADE_SAVE_Free3DLightSet(void);

void POKETRADE_3D_CreateIcaStreamsForMode(char *p,unsigned mode);

void POKETRADE_3D_DeleteIcaStreams(char *p);

void POKETRADE_3D_CreateIcaStreamsEnding(char *p);

void POKETRADE_3D_FreeParticleResources(void *a0);

void POKETRADE_3D_InitParticleSystems(char *p);

void POKETRADE_3D_SetupParticleSystemsLow(char *p);

void POKETRADE_3D_SetupParticleSystemsHigh(char *p);

void POKETRADE_3D_ExitParticleManager(u32_021DEA24 *p, int a1);

void POKETRADE_3D_InitTradeParticleSet(TradeParticleSet *p);

void POKETRADE_3D_Init3DScene(char *p);

void POKETRADE_3D_Update3DScene(void *p);

void POKETRADE_3D_Delete3DScene(char *p);

void POKETRADE_3D_UploadCubeTextures(void *p);

void POKETRADE_3D_AddUnitAndInit(void *p, int a);

void POKETRADE_3D_RemoveCurrentUnit(void *p);

void POKETRADE_3D_AddUnit(char *p,int n);

void POKETRADE_3D_RemoveUnit(char *p);

void POKETRADE_3D_Draw3DScene(char *p);

void POKETRADE_3D_SetMcssOffsetForSpecies(void *p0, int *dir, int p2, void *mon);

void POKETRADE_3D_AddPokemonMcss(TradeWork *p, int idx, int side, void *mon, int flag);

void POKETRADE_3D_AddPokemonMcssFlipped(void *a, int b, int c, void *d, int e, int f);

void POKETRADE_3D_AddPokemonMcssPlain(void *a, int b, int c, void *d, int e);

void POKETRADE_3D_DeleteMcssSlot(void *p, int idx);

void POKETRADE_3D_EmitCubeVertex(int n);

void POKETRADE_3D_SetCubeNormal(int n);

void POKETRADE_3D_SetCubeTexCoord(int n);

void POKETRADE_3D_FillTextureCell(unsigned short *p, int x, int y, int colour);

void POKETRADE_3D_FillTexturePage(u16 *p, u8 *src, int k, int a3);

void POKETRADE_3D_FillTextureHeader(u16 *p, u8 *src, int a2);

void POKETRADE_3D_UploadTexturePages(char *p, int count);

void POKETRADE_3D_SetToonEdgeColors(int a, int b);

void POKETRADE_3D_DrawCubeFace(int z,int index,u16 a,int b);

void POKETRADE_3D_DrawRotatingCube(const u8 *p);

void POKETRADE_3D_LoadTexturePalette(char *p);

void POKETRADE_3D_FadeTexturePalette(char *p);

void POKETRADE_3D_CreateTouchbar(char *p);

extern s16_021DFBF0 FX_SinCosTable_[];

extern char d_021E81C0[];

extern Vec_021E3004 d_021E7AF4;

extern const s16_021E3004 d_020A1EB8[];

extern Callback d_021E7AC4[];

extern Fn tbl_021E7AC4[];

extern const Entry_021E324C d_021E7B3C[];

extern const Handler d_021E7AC8[];

extern Cfg d_021E8144;

extern Entry_021E33FC d_021E7B9C[4];

extern const Vec_021E35A0 data_021E7B00;

extern const Table_021E3004 data_021E7B0C;

extern u32_021DEA24 d_021E8178[];

extern u32_021DEA24 d_021E8168[];

extern const VecFx32_021E3A40 d_021E815C,d_021E79AC,d_021E8150;

extern const Template_021E3A40 d_021E7C0C;

void POKETRADE_3D_CreateIcaStreamsForMode(char *p,unsigned mode)
{
    switch(mode) {
    case 0:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x38,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x39,10);
        ((struct Obj00673 *)p)->f98=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x36,10);
        ((struct Obj00673 *)p)->f9C=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x37,10);
        break;
    case 1:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3f,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3e,10);
        ((struct Obj00673 *)p)->f98=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x36,10);
        break;
    case 2:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3d,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3c,10);
        break;
    case 3:
        ((struct Obj00673 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3b,10);
        ((struct Obj00673 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x3a,10);
        ((struct Obj00673 *)p)->f9C=ICA_ANIME_CreateStream(((struct Obj00673 *)p)->fBA,0x67,0x37,10);
        func_020115EC(((struct Obj00673 *)p)->f9C,0x2b5000);
        break;
    }
}

/*
 * follower: two-byte zero alignment padding at 0x021E2EFA.
 */
void POKETRADE_3D_DeleteIcaStreams(char *p) {
    if (((struct Obj02173 *)p)->f90) {ICA_ANIME_Delete(((struct Obj02173 *)p)->f90); ((struct Obj02173 *)p)->f90=0;}
    if (((struct Obj02173 *)p)->f94) {ICA_ANIME_Delete(((struct Obj02173 *)p)->f94); ((struct Obj02173 *)p)->f94=0;}
    if (((struct Obj02173 *)p)->f98) {ICA_ANIME_Delete(((struct Obj02173 *)p)->f98); ((struct Obj02173 *)p)->f98=0;}
    if (((struct Obj02173 *)p)->f9C) {ICA_ANIME_Delete(((struct Obj02173 *)p)->f9C); ((struct Obj02173 *)p)->f9C=0;}
}

/*
 * extent: 46-byte body followed by 2-byte alignment padding.
 */
void POKETRADE_3D_CreateIcaStreamsEnding(char *p)
{
    ((struct Obj08067 *)p)->f90=ICA_ANIME_CreateStream(((struct Obj08067 *)p)->fBA,0x68,0xb,10);
    ((struct Obj08067 *)p)->f94=ICA_ANIME_CreateStream(((struct Obj08067 *)p)->fBA,0x68,0xc,10);
}

void POKETRADE_3D_FreeParticleResources(void *a0) { POKETRADE_3D_DeleteIcaStreams(a0); }

void POKETRADE_3D_InitParticleSystems(char *p) {
    int i,flag;
    PARTICLE_InitManager(((struct Obj04480 *)p)->fBA);
    ((struct Obj04480 *)p)->fB4=0;
    for(i=0;i<9;i++) {
        ((void **)p)[9+i]=func_02030734(((struct Obj04480 *)p)->fBA,0x4800,1,d_021E81C0,0x201);
        switch(i) {
        case 0: case 1: case 2: case 5: case 6: case 8: flag=0; break;
        case 3: case 4: case 7: default: flag=1; break;
        }
        ((void **)p)[i]=(void *)PARTICLE_CreateSystemDefault((int)(((void **)p)[9+i]),0x4800,flag,((struct Obj04480 *)p)->fBA);
    }
}

void POKETRADE_3D_SetupParticleSystemsLow(char *p) {
    int i;
    ((struct Obj08068 *)p)->fB4=(void *)PARTICLE_LoadArchiveMember((int)0x67,(int)0x35,(u16)((((struct Obj08068 *)p)->fBA&0x7fff)|0x8000));
    for(i=0;i<4;i++) {
        int x;
        func_02087A3C(1,1);
        x=func_020056BC();
        PARTICLE_SetupSystemBorrowed(((void **)p)[i],(unsigned int)(((struct Obj08068 *)p)->fB4),1,x);
    }
}

void POKETRADE_3D_SetupParticleSystemsHigh(char *p)
{
    int i;

    for (i = 4; i < 9; i++) {
        func_02087A3C(1, 1);
        PARTICLE_SetupSystemBorrowed(((void **)p)[i], (unsigned int)(((struct Obj13911 *)p)->fB4), 1, func_020056BC());
    }
}

/*
 * Teardown: release the +0xb4 pointer and the nine 32-bit slots at
 * +0x24, zeroing each. Target of func_021D6C78's second call (ov119).
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_3D_ExitParticleManager(u32_021DEA24 *p, int a1)
{
    int i;

    PARTICLE_ExitManager();
    if (p[0x2d] != 0) {
        func_020307B0((void *)p[0x2d]);
        p[0x2d] = 0;
    }
    for (i = 0; i < 9; i++) {
        if (p[9 + i] != 0) {
            func_020307B0((void *)p[9 + i]);
            p[9 + i] = 0;
        }
    }
}

void POKETRADE_3D_InitTradeParticleSet(TradeParticleSet *p)
{
    int i;
    void *buf;
    void *h;
    void **q;

    PARTICLE_InitManager(p->heap);
    for (i = 0; i < 6; i++) {
        q = &p->a[i];
        buf = func_02030734(p->heap, 0x4800, 1, d_021E81C0, 0x273);
        q[9] = buf;
        *q = (void *)PARTICLE_CreateSystemDefault((int)buf, 0x4800, 0, p->heap);
    }
    h = (void *)PARTICLE_LoadArchiveMember(0x68, 10, p->heap);
    for (i = 0; i < 6; i++)
        PARTICLE_SetupSystem(p->a[i], h, 1, 0);
}

void POKETRADE_3D_Init3DScene(char *p)
{
    ((TradeWork *)p)->g3dUnitHandle=0xffff;
    ((TradeWork *)p)->f109C=~0u;
    POKETRADE_SAVE_Init3DProjection(0x91);
    ((TradeWork *)p)->g3dUtil=G3D_UTIL_Create(20,20,0x91);
    if (!((TradeWork *)p)->subCamera) {
        Vec_021E3004 a={0,0,0};
        Vec_021E3004 b={0,0,0};
        Vec_021E3004 c;
        u16 heap;
        heap=((TradeWork *)p)->heapId;
        c=d_021E7AF4;
        ((TradeWork *)p)->subCamera=G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,&a,&c,&b,heap);
    }
    if (((TradeWork *)p)->f109C!=~0u)
        d_021E7AC4[*(u32_021DEA24 *)(p+0x109c)].call(p);
}

void POKETRADE_3D_Update3DScene(void *p) { POKETRADE_3D_Draw3DScene(p); }

void POKETRADE_3D_Delete3DScene(char *p) {
    if (((TradeWork *)p)->subCamera) G3D_CAMERA_Delete(((TradeWork *)p)->subCamera);
    G3D_UTIL_Delete(((TradeWork *)p)->g3dUtil);
    if (((TradeWork *)p)->fC) {
        POKETRADE_3D_ExitParticleManager(((TradeWork *)p)->fC,6);
        POKETRADE_3D_FreeParticleResources(((TradeWork *)p)->fC);
        func_020307B0(((TradeWork *)p)->fC);
        ((TradeWork *)p)->fC=0;
    }
    POKETRADE_SAVE_Free3DLightSet();
}

void POKETRADE_3D_UploadCubeTextures(void *p) { POKETRADE_3D_UploadTexturePages(p, 0x19); }

void POKETRADE_3D_AddUnitAndInit(void *p, int a)
{
    POKETRADE_3D_AddUnit(p, a);
    if (((TradeWork *)p)->f109C != 0xFFFFFFFF) {
        tbl_021E7AC4[*(u32_021DEA24 *)((char *)p + 0x109C) * 2](p);
    }
}

void POKETRADE_3D_RemoveCurrentUnit(void *p)
{
    if (((TradeWork *)p)->f109C != 0xFFFFFFFF) {
        POKETRADE_3D_RemoveUnit(p);
        ((TradeWork *)p)->f109C = 0xFFFFFFFF;
    }
}

void POKETRADE_3D_AddUnit(char *p,int n) {
    void *q;
    int i,count;
    if(d_021E7B3C[n].d) ((TradeWork *)p)->g3dUnitHandle=G3D_UTIL_AddUnit(((TradeWork *)p)->g3dUtil,&d_021E7B3C[n]);
    else ((TradeWork *)p)->g3dUnitHandle=0xffff;
    if(((TradeWork *)p)->g3dUnitHandle!=0xffff) {
        q=(void *)func_02048A18(((TradeWork *)p)->g3dUtil,((TradeWork *)p)->g3dUnitHandle);
        count=G3D_SYSTEM_GetObjectAnimeCount(q);
        for(i=0;i<count;i++) G3D_SYSTEM_EnableObjectAnime(q,(u16)i);
    }
    *(int *)&((TradeWork *)p)->f109C=n;
}

void POKETRADE_3D_RemoveUnit(char *p)
{
    u16 v;

    v = ((TradeWork *)p)->g3dUnitHandle;
    if (v != 0xFFFF)
        G3D_UTIL_RemoveUnit(((TradeWork *)p)->g3dUtil, v);
    ((TradeWork *)p)->g3dUnitHandle = 0xFFFF;
}

void POKETRADE_3D_Draw3DScene(char *p)
{
    char buf[0x3C];
    void *q;
    int n;
    int i;
    int idx;

    idx = (*(int *)&((TradeWork *)p)->f109C);
    if (idx == -1)
        return;
    if (d_021E7AC8[idx].fn != 0)
        d_021E7AC8[idx].fn(p, buf);
    if (((TradeWork *)p)->g3dUnitHandle != 0xFFFF) {
        q = (void *)func_02048A18(((TradeWork *)p)->g3dUtil, ((TradeWork *)p)->g3dUnitHandle);
        n = G3D_SYSTEM_GetObjectAnimeCount(q);
        for (i = 0; i < n; i++)
            G3D_SYSTEM_LoopObjectAnimeFrame(q, (u16)i, d_021E8144.amount);
    }
    func_02047964();
    func_02048AD0(((TradeWork *)p)->subCamera);
    G3D_SYSTEM_ApplyLookAt();
    if (((TradeWork *)p)->fC != 0) {
        PARTICLE_DrawAllSystems();
        PARTICLE_UpdateAllSystems();
    }
    if (((TradeWork *)p)->g3dUnitHandle != 0xFFFF)
        G3D_SYSTEM_DrawObject((void *)func_02048A18(((TradeWork *)p)->g3dUtil, ((TradeWork *)p)->g3dUnitHandle), (struct Arg *)buf);
    if (*(Sub_021E3004 * *)&((TradeWork *)p)->fC != 0) {
        if ((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a90 != 0) {
            if ((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->aA8 == 0)
                (*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->aA8 = ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a90), d_021E8144.amount);
            if ((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->aAC == 0)
                (*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->aAC = ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a94), d_021E8144.amount);
        }
        if ((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a9C != 0)
            ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a9C), d_021E8144.amount);
        if ((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a98 != 0)
            ICA_ANIME_IncFrameLoop((struct IcaAnime *)((*(Sub_021E3004 * *)&((TradeWork *)p)->fC)->a98), d_021E8144.amount);
    }
}

/*
 * 2026-10-03 (wave B3): all concrete bytes match. The one open relocation is
 * the call to MCSS_GetSizeX (unlabelled arm9 Thumb leaf). Its witness is
 * filed as src/matched/arm9/MCSS_GetSizeX.c (EXACT); once the integrator
 * seeds 0x02015F04 in layout/function_starts.txt this re-verifies as EXACT.
 * The empty-then if/else on *dir gives the original `bge; b` shape.
 */
void POKETRADE_3D_SetMcssOffsetForSpecies(void *p0, int *dir, int p2, void *mon)
{
    Vec_021E33FC v;
    int flag = 0;
    int a, b, c;
    int found;
    u8 i;
    float f;

    a = func_02017E1C(mon, 5, 0);
    b = func_02017E1C(mon, 0x6f, 0);
    c = POKE_TOOL_GetGender(mon);
    if (p2 == 0)
        flag = 1;
    found = 0;
    for (i = 0; i < 4; i++) {
        if (a == d_021E7B9C[i].a && b == d_021E7B9C[i].b
            && (d_021E7B9C[i].c == 3 || c == d_021E7B9C[i].c)
            && (d_021E7B9C[i].d == 2 || flag == d_021E7B9C[i].d)) {
            v.x = F32_TO_FX32(d_021E7B9C[i].x);
            if (*dir >= 0)
                v.x = -v.x;
            v.y = F32_TO_FX32(d_021E7B9C[i].y);
            v.z = F32_TO_FX32(d_021E7B9C[i].z);
            found = 1;
            break;
        }
    }
    if (!found) {
        MCSS_GetSizeX(p0);
        c = MCSS_GetOfsX(p0);
        if (*dir < 0)
            f = 0.33f * (float)c;
        else
            f = 0.33f * (float)-c;
        v.x = F32_TO_FX32(f);
        v.y = 0;
        v.z = 0;
    }
    MCSS_SetOfsPosition(p0, (u32_021DEA24 *)(&v));
}

void POKETRADE_3D_AddPokemonMcss(TradeWork *p, int idx, int side, void *mon, int flag)
{
    Vec_021E35A0 v = data_021E7B00;
    Table_021E3004 t = data_021E7B0C;
    if (flag) {
        u16 species = func_02017E1C(mon, 5, 0);
        u16 form = func_02017E1C(mon, 0x6f, 0);
        void *h = POKE_PERSONAL_Create(species, form, p->heapId);
        u32_021DEA24 r = POKE_PERSONAL_GetParam(h, 0x22);
        POKE_PERSONAL_Delete(h);
        if (r == 0)
            v.x = -v.x;
    }
    if (p->f118C == 2)
        DWC_RAP_SetVchatTalkLock(1);
    if (side)
        p->mcssPokemon[idx] = MCSS_TOOL_AddPokeMcss(p->mcssSystem, mon, 0, t.v[idx], -0x1C000, 0);
    else
        p->mcssPokemon[idx] = MCSS_TOOL_AddPokeMcss(p->mcssSystem, mon, 1, t.v[idx], -0x1C000, 0);
    if (p->f118C == 2)
        DWC_RAP_SetVchatTalkLock(0);
    MCSS_TOOL_SetAnimeStopCallback((int)p->mcssPokemon[idx]);
    MCSS_SetScale(p->mcssPokemon[idx], (u32_021DEA24 *)(&v));
    MCSS_SetShadowVanishFlag(p->mcssPokemon[idx], 1);
    POKETRADE_3D_SetMcssOffsetForSpecies(p->mcssPokemon[idx], (int *)(&v), side, mon);
}

void POKETRADE_3D_AddPokemonMcssFlipped(void *a, int b, int c, void *d, int e, int f)
{
    if (f != 0 && c == 0) {
        c = 1;
        e = 0;
    }
    POKETRADE_3D_AddPokemonMcss(a, b, c, d, e);
}

void POKETRADE_3D_AddPokemonMcssPlain(void *a, int b, int c, void *d, int e)
{
    POKETRADE_3D_AddPokemonMcss(a, b, c, d, e);
}

/*
 * Teardown of one slot of the 0x844 vector: releases it through
 * MCSS_SetVanishFlag, hands (the shared 0x840 handle, the slot value) to
 * MCSS_Del, then clears the slot.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_3D_DeleteMcssSlot(void *p, int idx)
{
    u32_021DEA24 v = ((u32_021DEA24 *)((char *)p + 0x844))[idx];

    if (v != 0) {
        MCSS_SetVanishFlag((void *)v);
        MCSS_Del((void *)(*(u32_021DEA24 *)&((TradeWork *)p)->mcssSystem), (void *)(((u32_021DEA24 *)((char *)p + 0x844))[idx]));
        ((u32_021DEA24 *)((char *)p + 0x844))[idx] = 0;
    }
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32_021DEA24)(u16)x | ((u32_021DEA24)(u16)y << 16);
    REG_VTX_16 = (u32_021DEA24)(u16)z;
}

/*
 * The cube vertex table (8 corners, x y z each). The values come from the
 * user's own ROM: tools/gendata.py writes build/gen/h16_ov119_021E8190.inc
 * (gitignored).
 */
static fx16 d_021E8190[24] = {
#include "../../../build/gen/h16_ov119_021E8190.inc"
};

/*
 * The vertex table is a non-const file static: as an extern (or a const
 * static) the allocator keeps n*3 in r1; as a writable file static it keeps
 * n*3 in r4 and the base in r3 like the original.
 */
void POKETRADE_3D_EmitCubeVertex(int n)
{
    G3_Vtx(d_021E8190[n * 3], d_021E8190[n * 3 + 1], d_021E8190[n * 3 + 2]);
}

void POKETRADE_3D_SetCubeNormal(int n)
{
    *(u32_021DEA24 *)0x04000484 = d_021E8178[n];
}

void POKETRADE_3D_SetCubeTexCoord(int n)
{
    *(u32_021DEA24 *)0x04000488 = d_021E8168[n];
}

/*
 * extent: 126-byte body followed by two zero padding bytes at 0x021E37D6.
 */
void POKETRADE_3D_FillTextureCell(unsigned short *p, int x, int y, int colour)
{
    int end;
    int col;
    int row;
    int start;
    int index;
    int shift;
    start = x * 5 + 2;
    row = y * 6 + 3;
    end = row + 3;
    for (; row < end; row++) {
        for (col = start; col < start + 3; col++) {
            index = col + row * 32;
            shift = (index % 4) * 4;
            p[index / 4] &= (unsigned short)~(15 << shift);
            p[index / 4] |= (unsigned short)(colour << shift);
        }
    }
}

void POKETRADE_3D_FillTexturePage(u16 *p, u8 *src, int k, int a3)
{
    u8 *row;
    int i;
    int j;

    i = 0;
    row = src + k * 30;
    for (; i < 5; i++) {
        for (j = 0; j < 6; j++)
            POKETRADE_3D_FillTextureCell(p, j, i, row[i * 6 + j]);
    }
}

void POKETRADE_3D_FillTextureHeader(u16 *p, u8 *src, int a2)
{
    int i;

    for (i = 0; i < 6; i++)
        POKETRADE_3D_FillTextureCell(p, i % 2 + 2, i / 2 + 1, src[i]);
}

void POKETRADE_3D_UploadTexturePages(char *p, int count)
{
    char *v;
    int i;
    func_0207F7A0();
    v = func_02030734(((TradeWork *)p)->heapId, 0x200, 1, d_021E81C0, 0x510);
    for (i = 0; i < count; i++) {
        MI_CpuFill8(v, 0, 0x200);
        if (i == 0)
            POKETRADE_3D_FillTextureHeader((u16 *)v, (unsigned char *)(p + 0x5B6), 2);
        else
            POKETRADE_3D_FillTexturePage((u16 *)v, (u8 *)(p + 0x2E6), i - 1, 2);
        DWCi_ScreenDC_FlushRange(v, 0x200);
        func_0207F7FC(v, i * 0x200 + 0x3000, 0x200);
    }
    func_020307B0(v);
    func_0207F9B4();
    POKETRADE_3D_LoadTexturePalette(p);
}

/*
 * Program the two register bits selected by the two flags.
 */
void POKETRADE_3D_SetToonEdgeColors(int a, int b)
{
    *(volatile unsigned int *)0x040004c0 = 0x6b5a5ef7 | ((a != 0) << 15);
    *(volatile unsigned int *)0x040004c4 = 0x00007fff | ((b != 0) << 15);
}

/*
 * lever: u16 third argument places its spill before hardware writes; caller supplies u16.
 * volatile: hardware command stores 021E391C..021E3A22, 04000440..04000504
 */
void POKETRADE_3D_DrawCubeFace(int z,int index,u16 a,int b)
{
    REG(0x04000444)=0;
    REG(0x04000440)=1;
    func_0207D84C(FX_SinCosTable_[(b>>4)*2],FX_SinCosTable_[(b>>4)*2+1]);
    REG(0x04000444)=0;
    func_0207D84C(FX_SinCosTable_[(a>>4)*2],FX_SinCosTable_[(a>>4)*2+1]);
    REG(0x04000470)=0;
    REG(0x04000470)=0;
    REG(0x04000470)=z;
    func_0207D84C(FX_SinCosTable_[(d_021E8144.a>>4)*2],FX_SinCosTable_[(d_021E8144.a>>4)*2+1]);
    func_0207D810(FX_SinCosTable_[(d_021E8144.b>>4)*2],FX_SinCosTable_[(d_021E8144.b>>4)*2+1]);
    REG(0x0400046c)=0x266;
    REG(0x0400046c)=0x266;
    REG(0x0400046c)=0x266;
    REG(0x04000440)=3;
    REG(0x04000454)=0;
    REG(0x04000440)=2;
    POKETRADE_3D_SetToonEdgeColors(1,1);
    REG(0x040004a8)=0x4d200000|(((u32_021E38D8)index*512+0x3000)>>3);
    REG(0x040004ac)=512;
    REG(0x040004a4)=0x1f0041|((u32_021E38D8)index<<24);
    REG(0x04000500)=1;
    POKETRADE_3D_SetCubeTexCoord(1); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(2);
    POKETRADE_3D_SetCubeTexCoord(0); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(0);
    POKETRADE_3D_SetCubeTexCoord(2); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(4);
    POKETRADE_3D_SetCubeTexCoord(3); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(6);
    REG(0x04000504)=0;
    REG(0x04000448)=1;
    REG(0x04000448)=1;
}

static inline fx32 fraction(int x,int y) { return (fx32)(((long long)x*65536)/y); }

/*
 * lever: separate x+=48 and remainder assignments restore numerator register setup.
 * volatile: hardware writes 021E3A5C,021E3A60 to 040004C8/040004CC
 */
void POKETRADE_3D_DrawRotatingCube(const u8 *p)
{
    int i,stage,count,total,base;
    int x;
    unsigned delta;
    u16 angle;
    func_0207DA8C();
    func_0207D7C4(&d_021E815C,&d_021E79AC,&d_021E8150,1,0);
    *(volatile u32_021E3A40 *)0x040004c8=0x2d8b6127;
    *(volatile u32_021E3A40 *)0x040004cc=0x7fff;
    stage=func_021D8A18((u8 *)p);
    count=stage+1;
    total=count*160;
    x=((TradeWork *)p)->f107E;
    if(x<96) {
        if(x<48) x=x*112/48;
        else x=x+64;
    } else x=x+64;
    base=stage*160;
    if(x>base) {
        delta=x-base;
        if(delta<80) x=base+delta*112U/80U;
        else x=base+(delta-80U)*48U/80U+112;
    }
    x=x+48;
    x=x%total;
    x=fraction(x,total);
    for(i=0;i<count;i++) {
        angle=0x10000-x;
        POKETRADE_3D_DrawCubeFace(d_021E8144.c,i,(u16)((i<<16)/count),angle);
    }
}

void POKETRADE_3D_LoadTexturePalette(char *p)
{
    void *v;
    void *allocation;
    void *descriptor;
    char *data;
    v = func_020490F4(0x74, ((TradeWork *)p)->heapId);
    allocation = func_02049F78(v, 0x48, (u32_021E3B2C)(&descriptor), ((TradeWork *)p)->heapId);
    data = *(char * *)&((struct Obj22795 *)descriptor)->fC;
    DWCi_ScreenDC_FlushRange(data + 32, 32);
    func_02083194(data + 32, data + 34, 30);
    ((struct Obj22796 *)data)->f20 = 0x14A5;
    DWCi_ScreenDC_FlushRange(data + 32, 32);
    func_0207FA0C();
    func_0207FA40(data + 32, 0x2000, 32);
    func_0207FADC();
    MI_CpuCopy8(data + 32, p + 0x1134, 32);
    func_020307B0(allocation);
    ARC_TOOL_DeleteHandle(v);
}

void POKETRADE_3D_FadeTexturePalette(char *p)
{
    int i;
    int j;
    int component;
    int shift;
    char *q;
    for (i = 0; i < 16; i++) {
        q = p + i * 2;
        ((TradeWork *)q)->f1154 = 0;
        for (j = 0; j < 3; j++) {
            shift = j * 5;
            component = (((TradeWork *)q)->f1134 >> shift) & 31;
            if (component)
                component--;
            ((TradeWork *)q)->f1154 |= (unsigned short)((component & 31) << shift);
        }
    }
    func_0207FA0C();
    func_0207FA40(p + 0x1154, 0x2000, 32);
    func_0207FADC();
}

void POKETRADE_3D_CreateTouchbar(char *p)
{
    Template_021E3A40 t = d_021E7C0C;
    Config_021E3A40 c;
    u16 a, b, d;
    MI_CpuFill8(&c, 0, 32);
    c.f0 = &t;
    c.f4 = 4;
    c.f8 = ((TradeWork *)p)->clactSystem;
    c.fC = 4;
    c.f1C = 1;
    c.f10 = 7;
    c.f14 = 0;
    c.f18 = 2;
    a = *(u32 *)&((TradeWork *)p)->f894;
    t.e[1].f8 = a;
    b = *(u32 *)&((TradeWork *)p)->f880;
    t.e[1].fA = b;
    d = *(u32 *)&((TradeWork *)p)->f8B0;
    t.e[1].fC = d;
    t.e[1].fE = 6; t.e[1].f10 = 5; t.e[1].f12 = 4;
    t.e[1].f18 = 0; t.e[1].f1C = 0x54C;
    t.e[2].f8 = a; t.e[2].fA = b; t.e[2].fC = d;
    t.e[2].fE = 9; t.e[2].f10 = 8; t.e[2].f12 = 7;
    t.e[2].f18 = 8; t.e[2].f1C = 0x54C;
    t.e[3].f8 = a; t.e[3].fA = b; t.e[3].fC = d;
    t.e[3].fE = 22; t.e[3].f10 = 21; t.e[3].f12 = 20;
    t.e[3].f18 = 48; t.e[3].f1C = 0x54C;
    (*(void * *)&((TradeWork *)p)->touchbar) = TOUCHBAR_Create(&c, ((TradeWork *)p)->heapId);
    TOUCHBAR_SetButtonVisible((*(void * *)&((TradeWork *)p)->touchbar), 9, 0);
    TOUCHBAR_SetButtonVisible((*(void * *)&((TradeWork *)p)->touchbar), 8, 0);
    TOUCHBAR_SetAllButtonsPriority((*(void * *)&((TradeWork *)p)->touchbar), 2);
}
