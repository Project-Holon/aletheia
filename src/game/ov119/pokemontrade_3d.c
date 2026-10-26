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
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssFlipped  0x021E36A8  thumb  ov119
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   GFL_HEAP_Free 0x020307B0 arm
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   POKETRADE_3D_UploadCubeTextures 0x021E31FC thumb ov119
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   POKETRADE_3D_RemoveCurrentUnit 0x021E3230 thumb ov119
 *   POKETRADE_3D_Init3DScene 0x021E30EC thumb ov119
 *   POKETRADE_3D_CreateTouchbar 0x021E3C20 thumb ov119
 *   POKETRADE_3D_AddPokemonMcssPlain 0x021E36C8 thumb ov119
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   POKETRADE_3D_Update3DScene 0x021E31B4 thumb ov119
 *   POKETRADE_3D_Delete3DScene 0x021E31BC thumb ov119
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   FX_SinCosTable_    0x020A1B38  data
 *   ICA_ANIME_CreateStream 0x02011510 thumb
 *   ICA_ANIME_SetFrame 0x020115EC thumb
 *   ICA_ANIME_Delete 0x02011558 thumb
 *   PARTICLE_InitManager 0x02050B80 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   gParticleBufferAllocTag 0x021E81C0 data a4
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   OS_WaitInterrupt 0x02087A3C arm
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   PARTICLE_SetupSystemBorrowed 0x02051360 arm
 *   PARTICLE_ExitManager  0x02050ED4  arm
 *   PARTICLE_SetupSystem  0x02051230  arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   gCubeRotation 0x021E7AF4 data a4
 *   gCameraParams 0x020A1EB8 data a2
 *   g3dStateCallbacks 0x021E7AC4 data a4
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   gPokeTrade3dStateTable   0x021E7AC4  data   ov119  a4
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   gG3dUnitTable 0x021E7B3C data a4
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   PARTICLE_DrawAllSystems  0x02051534  arm
 *   PARTICLE_UpdateAllSystems  0x02051574  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb
 *   g3dSceneHandlers  0x021E7AC8  data a4
 *   gAnimeFrameCfg  0x021E8144  data a4
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   MCSS_GetSizeX 0x02015F04 thumb
 *   MCSS_GetOfsX 0x02015F14 thumb
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 *   gSpeciesMcssOffset 0x021E7B9C data a4
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   MCSS_TOOL_AddPokeMcss 0x02017270 thumb
 *   MCSS_TOOL_SetAnimeStopCallback 0x020173B4 thumb
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_SetShadowVanishFlag 0x02015FF0 thumb
 *   gMcssMonOffset 0x021E7B00 data a4
 *   gMcssMonConfig 0x021E7B0C data a4
 *   MCSS_Del  0x02015BA4  thumb
 *   sCubeVtx 0x021E8190 data a2
 *   gCubeNormal 0x021E8178 data a4
 *   gCubeTexCoord 0x021E8168 data a4
 *   GX_BeginLoadTex 0x0207F7A0 arm
 *   DC_FlushRange 0x020862F0 arm
 *   GX_LoadTex 0x0207F7FC arm
 *   GX_EndLoadTex 0x0207F9B4 arm
 *   G3_RotY 0x0207D84C arm
 *   G3_RotX 0x0207D810 arm
 *   G3X_Reset 0x0207DA8C arm
 *   G3i_LookAt_ 0x0207D7C4 arm
 *   POKETRADE_PROC_GetStoredBoxIndex 0x021D8A18 thumb ov119
 *   gLookAtEye 0x021E815C data ov119 a4
 *   gLookAtTarget 0x021E79AC data ov119 a4
 *   gLookAtUp 0x021E8150 data ov119 a4
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuMove 0x02083194 arm
 *   GX_BeginLoadTexPltt 0x0207FA0C arm
 *   GX_LoadTexPltt 0x0207FA40 arm
 *   GX_EndLoadTexPltt 0x0207FADC arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_SetAllButtonsPriority 0x021B6520 thumb ov067
 *   gTouchbarTemplate 0x021E7C0C data a4
 *   POKETRADE_SAVE_Init3DProjection 0x021E2B14 thumb ov119
 *   POKETRADE_SAVE_Free3DLightSet 0x021E2B68 thumb ov119
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fgr                         0x0209BBB0  arm
 *   _fmul                        0x0209C77C  arm
 *   _fsub                        0x0209CB8C  arm
 *   _u32_div_f                   0x0209C2B0  arm
 *   _ll_udiv                     0x0209C00C  arm
 */
#include "pokemontrade_types.h"
#include "../sdk_ioreg_reg.h"

#include "../ov067/touchbar.h"

#include "../arm9/mi_memory.h"

#include "../ov009/dwc_rap.h"

#include "../arm9/g3d_system.h"
struct G3dCamera;

#include "../arm9/g3d_camera.h"


#include "../arm9/arc_tool.h"


#define F32_TO_FX32(f) ((int)(((f) > 0) ? ((f) * 4096.0f + 0.5f) : ((f) * 4096.0f - 0.5f)))


#define REG(a) (*(volatile unsigned long *)(a))

struct G3dSys;

struct Arg;


typedef struct { u32 x, y, z; } Vec3U32;

typedef struct {void (*call)(TradeWork *);u32 other;} Pokemontrade3dCallback;

typedef void (*Fn)(TradeWork *);


typedef struct {
    void (*fn)(TradeWork *p, void *out);
    int unused;
} Handler;

typedef struct {
    int a;
    int b;
    int c;
    int d;
    float x;
    float y;
    float z;
} TransformEntry;


typedef struct { u32 v[4]; } U32Table4;

#include "../types.h"

#include "../sdk_fx.h"

typedef struct { u32 f0, f4; u16 f8, fA, fC, fE, f10, f12; u32 f14, f18, f1C; } Element;

typedef struct { Element e[4]; } ElementTemplate;

typedef struct { void *f0; u32 f4; void *f8; u32 fC, f10, f14; int f18, f1C; } TouchbarConfig;
struct PokemonParam;

#include "../arm9/poke_tool.h"

#include "../arm9/gfl_heap_wrap.h"

struct McssWork;

#include "../arm9/mcss.h"
struct IcaAnime;

#include "../arm9/ica_anime.h"



#include "../arm9/particle.h"

struct ParticleSys;



#include "../arm9/os_system.h"
struct TcbList;

#include "../arm9/gfl_use.h"
#include "../arm9/g3d_util.h"









struct G3dObject;






struct G3dObjectStatus;
struct G3dObject;






struct PersonalData;

#include "../arm9/poke_personal.h"


struct McssSys;




struct McssSys;


#include "../arm9/gx_load3d.h"

#include "../arm9/os_cache.h"



#include "../arm9/g3_util.h"


#include "../arm9/g3x.h"


#include "pokemontrade_proc.h"

#include "../arm9/arc_util.h"







#include "pokemontrade_save.h"


void POKETRADE_3D_CreateIcaStreamsForMode(ParticleManager *p,unsigned mode);

void POKETRADE_3D_DeleteIcaStreams(ParticleManager *p);

void POKETRADE_3D_CreateIcaStreamsEnding(ParticleManager *p);

void POKETRADE_3D_FreeParticleResources(ParticleManager *particles);

void POKETRADE_3D_InitParticleSystems(ParticleManager *p);

void POKETRADE_3D_SetupParticleSystemsLow(ParticleManager *p);

void POKETRADE_3D_SetupParticleSystemsHigh(ParticleManager *p);

void POKETRADE_3D_ExitParticleManager(ParticleManager *p, int unused);

void POKETRADE_3D_InitTradeParticleSet(ParticleManager *p);

void POKETRADE_3D_Init3DScene(TradeWork *p);

void POKETRADE_3D_Update3DScene(TradeWork *p);

void POKETRADE_3D_Delete3DScene(TradeWork *p);

void POKETRADE_3D_UploadCubeTextures(void *p);

void POKETRADE_3D_AddUnitAndInit(TradeWork *p, int a);

void POKETRADE_3D_RemoveCurrentUnit(TradeWork *p);

void POKETRADE_3D_AddUnit(TradeWork *p,int n);

void POKETRADE_3D_RemoveUnit(TradeWork *p);

void POKETRADE_3D_Draw3DScene(TradeWork *p);

void POKETRADE_3D_SetMcssOffsetForSpecies(void *mcss, int *dir, int side, void *mon);

void POKETRADE_3D_AddPokemonMcss(TradeWork *p, int idx, int side, void *mon, int flag);

void POKETRADE_3D_AddPokemonMcssFlipped(void *a, int b, int c, void *d, int e, int f);

void POKETRADE_3D_AddPokemonMcssPlain(void *a, int b, int c, void *d, int e);

void POKETRADE_3D_DeleteMcssSlot(TradeWork *p, int idx);

void POKETRADE_3D_EmitCubeVertex(int n);

void POKETRADE_3D_SetCubeNormal(int n);

void POKETRADE_3D_SetCubeTexCoord(int n);

void POKETRADE_3D_FillTextureCell(unsigned short *p, int x, int y, int colour);

void POKETRADE_3D_FillTexturePage(u16 *p, u8 *src, int k, int unused);

void POKETRADE_3D_FillTextureHeader(u16 *p, u8 *src, int unused);

void POKETRADE_3D_UploadTexturePages(TradeWork *p, int count);

void POKETRADE_3D_SetToonEdgeColors(int a, int b);

void POKETRADE_3D_DrawCubeFace(int z,int index,u16 a,int b);

void POKETRADE_3D_DrawRotatingCube(TradeWork *p);

void POKETRADE_3D_LoadTexturePalette(TradeWork *p);

void POKETRADE_3D_FadeTexturePalette(TradeWork *p);

void POKETRADE_3D_CreateTouchbar(TradeWork *p);

extern short FX_SinCosTable_[];

extern char gParticleBufferAllocTag[];

extern Vec3U32 gCubeRotation;

extern const short gCameraParams[];

extern Pokemontrade3dCallback g3dStateCallbacks[];

extern Fn gPokeTrade3dStateTable[];

extern const G3dUtilSetup gG3dUnitTable[];

extern const Handler g3dSceneHandlers[];

extern PokemontradeCfg gAnimeFrameCfg;

extern TransformEntry gSpeciesMcssOffset[4];

extern const VecFx32 gMcssMonOffset;

extern const U32Table4 gMcssMonConfig;

extern u32 gCubeNormal[];

extern u32 gCubeTexCoord[];

extern const VecFx32 gLookAtEye,gLookAtTarget,gLookAtUp;

extern const ElementTemplate gTouchbarTemplate;

void POKETRADE_3D_CreateIcaStreamsForMode(ParticleManager *p,unsigned mode)
{
    switch(mode) {
    case 0:
        p->icaStream[0]=ICA_ANIME_CreateStream(p->heap,0x67,0x38,10);
        p->icaStream[1]=ICA_ANIME_CreateStream(p->heap,0x67,0x39,10);
        p->icaStream[2]=ICA_ANIME_CreateStream(p->heap,0x67,0x36,10);
        p->icaStream[3]=ICA_ANIME_CreateStream(p->heap,0x67,0x37,10);
        break;
    case 1:
        p->icaStream[0]=ICA_ANIME_CreateStream(p->heap,0x67,0x3f,10);
        p->icaStream[1]=ICA_ANIME_CreateStream(p->heap,0x67,0x3e,10);
        p->icaStream[2]=ICA_ANIME_CreateStream(p->heap,0x67,0x36,10);
        break;
    case 2:
        p->icaStream[0]=ICA_ANIME_CreateStream(p->heap,0x67,0x3d,10);
        p->icaStream[1]=ICA_ANIME_CreateStream(p->heap,0x67,0x3c,10);
        break;
    case 3:
        p->icaStream[0]=ICA_ANIME_CreateStream(p->heap,0x67,0x3b,10);
        p->icaStream[1]=ICA_ANIME_CreateStream(p->heap,0x67,0x3a,10);
        p->icaStream[3]=ICA_ANIME_CreateStream(p->heap,0x67,0x37,10);
        ICA_ANIME_SetFrame(p->icaStream[3],0x2b5000);
        break;
    }
}

/*
 * follower: two-byte zero alignment padding at 0x021E2EFA.
 */
void POKETRADE_3D_DeleteIcaStreams(ParticleManager *p) {
    if (p->icaStream[0]) {ICA_ANIME_Delete(p->icaStream[0]); p->icaStream[0]=0;}
    if (p->icaStream[1]) {ICA_ANIME_Delete(p->icaStream[1]); p->icaStream[1]=0;}
    if (p->icaStream[2]) {ICA_ANIME_Delete(p->icaStream[2]); p->icaStream[2]=0;}
    if (p->icaStream[3]) {ICA_ANIME_Delete(p->icaStream[3]); p->icaStream[3]=0;}
}

/*
 * extent: 46-byte body followed by 2-byte alignment padding.
 */
void POKETRADE_3D_CreateIcaStreamsEnding(ParticleManager *p)
{
    p->icaStream[0]=ICA_ANIME_CreateStream(p->heap,0x68,0xb,10);
    p->icaStream[1]=ICA_ANIME_CreateStream(p->heap,0x68,0xc,10);
}

void POKETRADE_3D_FreeParticleResources(ParticleManager *particles) { POKETRADE_3D_DeleteIcaStreams(particles); }

void POKETRADE_3D_InitParticleSystems(ParticleManager *p) {
    int i,flag;
    PARTICLE_InitManager(p->heap);
    p->archiveMember=0;
    for(i=0;i<9;i++) {
        p->buffer[i]=GFL_HEAP_Alloc(p->heap,0x4800,1,gParticleBufferAllocTag,0x201);
        switch(i) {
        case 0: case 1: case 2: case 5: case 6: case 8: flag=0; break;
        case 3: case 4: case 7: default: flag=1; break;
        }
        p->system[i]=(void *)PARTICLE_CreateSystemDefault(p->buffer[i],0x4800,flag,p->heap);
    }
}

void POKETRADE_3D_SetupParticleSystemsLow(ParticleManager *p) {
    int i;
    p->archiveMember=(void *)PARTICLE_LoadArchiveMember((int)0x67,(int)0x35,(u16)((p->heap&0x7fff)|0x8000));
    for(i=0;i<4;i++) {
        struct TcbList *x;
        OS_WaitInterrupt(1,1);
        x=GFL_USE_GetMainTaskList();
        PARTICLE_SetupSystemBorrowed(p->system[i],p->archiveMember,1,x);
    }
}

void POKETRADE_3D_SetupParticleSystemsHigh(ParticleManager *p)
{
    int i;

    for (i = 4; i < 9; i++) {
        OS_WaitInterrupt(1, 1);
        PARTICLE_SetupSystemBorrowed(p->system[i], p->archiveMember, 1, GFL_USE_GetMainTaskList());
    }
}

/*
 * Teardown: release the +0xb4 pointer and the nine 32-bit slots at
 * +0x24, zeroing each. Target of ov118 POKETRADE_DEMO_MIDDLE_StepEndScene's second call.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_3D_ExitParticleManager(ParticleManager *p, int unused)
{
    int i;

    PARTICLE_ExitManager();
    if (p->archiveMember != 0) {
        GFL_HEAP_Free(p->archiveMember);
        p->archiveMember = 0;
    }
    for (i = 0; i < 9; i++) {
        if (p->buffer[i] != 0) {
            GFL_HEAP_Free(p->buffer[i]);
            p->buffer[i] = 0;
        }
    }
}

void POKETRADE_3D_InitTradeParticleSet(ParticleManager *p)
{
    int i;
    void *buf;
    void *h;
    void **q;

    PARTICLE_InitManager(p->heap);
    for (i = 0; i < 6; i++) {
        q = &p->system[i];
        buf = GFL_HEAP_Alloc(p->heap, 0x4800, 1, gParticleBufferAllocTag, 0x273);
        q[9] = buf;
        *q = (void *)PARTICLE_CreateSystemDefault(buf, 0x4800, 0, p->heap);
    }
    h = (void *)PARTICLE_LoadArchiveMember(0x68, 10, p->heap);
    for (i = 0; i < 6; i++)
        PARTICLE_SetupSystem(p->system[i], h, 1, 0);
}

void POKETRADE_3D_Init3DScene(TradeWork *p)
{
    p->g3dUnitHandle=0xffff;
    p->animIndex=~0u;
    POKETRADE_SAVE_Init3DProjection(0x91);
    p->g3dUtil=G3D_UTIL_Create(20,20,0x91);
    if (!p->subCamera) {
        Vec3U32 a={0,0,0};
        Vec3U32 b={0,0,0};
        Vec3U32 c;
        u16 heap;
        heap=p->heapId;
        c=gCubeRotation;
        p->subCamera=G3D_CAMERA_Create(0,gCameraParams[6],gCameraParams[7],0x1555,0,0x1000,0x400000,0,(VecFx32 *)&a,(VecFx32 *)&c,(VecFx32 *)&b,heap);
    }
    if (p->animIndex!=~0u)
        g3dStateCallbacks[p->animIndex].call(p);
}

void POKETRADE_3D_Update3DScene(TradeWork *p) { POKETRADE_3D_Draw3DScene(p); }

void POKETRADE_3D_Delete3DScene(TradeWork *p) {
    if (p->subCamera) G3D_CAMERA_Delete(p->subCamera);
    G3D_UTIL_Delete(p->g3dUtil);
    if (p->particleManager) {
        POKETRADE_3D_ExitParticleManager(p->particleManager,6);
        POKETRADE_3D_FreeParticleResources(p->particleManager);
        GFL_HEAP_Free(p->particleManager);
        p->particleManager=0;
    }
    POKETRADE_SAVE_Free3DLightSet();
}

void POKETRADE_3D_UploadCubeTextures(void *p) { POKETRADE_3D_UploadTexturePages(p, 0x19); }

void POKETRADE_3D_AddUnitAndInit(TradeWork *p, int a)
{
    POKETRADE_3D_AddUnit(p, a);
    if (p->animIndex != 0xFFFFFFFF) {
        gPokeTrade3dStateTable[p->animIndex * 2](p);
    }
}

void POKETRADE_3D_RemoveCurrentUnit(TradeWork *p)
{
    if (p->animIndex != 0xFFFFFFFF) {
        POKETRADE_3D_RemoveUnit(p);
        p->animIndex = 0xFFFFFFFF;
    }
}

void POKETRADE_3D_AddUnit(TradeWork *p,int n) {
    void *q;
    int i,count;
    if(gG3dUnitTable[n].objCount) p->g3dUnitHandle=G3D_UTIL_AddUnit(p->g3dUtil,&gG3dUnitTable[n]);
    else p->g3dUnitHandle=0xffff;
    if(p->g3dUnitHandle!=0xffff) {
        q=G3D_UTIL_GetObject(p->g3dUtil,p->g3dUnitHandle);
        count=G3D_SYSTEM_GetObjectAnimeCount(q);
        for(i=0;i<count;i++) G3D_SYSTEM_EnableObjectAnime(q,(u16)i);
    }
    p->animIndex=n;
}

void POKETRADE_3D_RemoveUnit(TradeWork *p)
{
    u16 v;

    v = p->g3dUnitHandle;
    if (v != 0xFFFF)
        G3D_UTIL_RemoveUnit(p->g3dUtil, v);
    p->g3dUnitHandle = 0xFFFF;
}

void POKETRADE_3D_Draw3DScene(TradeWork *p)
{
    char buf[0x3C];
    void *q;
    int n;
    int i;
    int idx;

    idx = (p->animIndex);
    if (idx == -1)
        return;
    if (g3dSceneHandlers[idx].fn != 0)
        g3dSceneHandlers[idx].fn(p, buf);
    if (p->g3dUnitHandle != 0xFFFF) {
        q = G3D_UTIL_GetObject(p->g3dUtil, p->g3dUnitHandle);
        n = G3D_SYSTEM_GetObjectAnimeCount(q);
        for (i = 0; i < n; i++)
            G3D_SYSTEM_LoopObjectAnimeFrame(q, (u16)i, gAnimeFrameCfg.amount);
    }
    G3D_SYSTEM_DrawStart();
    G3D_CAMERA_Reset(p->subCamera);
    G3D_SYSTEM_ApplyLookAt();
    if (p->particleManager != 0) {
        PARTICLE_DrawAllSystems();
        PARTICLE_UpdateAllSystems();
    }
    if (p->g3dUnitHandle != 0xFFFF)
        G3D_SYSTEM_DrawObject(G3D_UTIL_GetObject(p->g3dUtil, p->g3dUnitHandle), (struct G3dObjectStatus *)buf);
    if (p->particleManager != 0) {
        if (p->particleManager->icaStream[0] != 0) {
            if (p->particleManager->streamFrame[0] == 0)
                p->particleManager->streamFrame[0] = ICA_ANIME_IncFrameLoop((struct IcaAnime *)(p->particleManager->icaStream[0]), gAnimeFrameCfg.amount);
            if (p->particleManager->streamFrame[1] == 0)
                p->particleManager->streamFrame[1] = ICA_ANIME_IncFrameLoop((struct IcaAnime *)(p->particleManager->icaStream[1]), gAnimeFrameCfg.amount);
        }
        if (p->particleManager->icaStream[3] != 0)
            ICA_ANIME_IncFrameLoop((struct IcaAnime *)(p->particleManager->icaStream[3]), gAnimeFrameCfg.amount);
        if (p->particleManager->icaStream[2] != 0)
            ICA_ANIME_IncFrameLoop((struct IcaAnime *)(p->particleManager->icaStream[2]), gAnimeFrameCfg.amount);
    }
}

/*
 * 2026-10-03 (wave B3): all concrete bytes match. The one open relocation is
 * the call to MCSS_GetSizeX (unlabelled arm9 Thumb leaf). Its witness is
 * filed as src/matched/arm9/MCSS_GetSizeX.c (EXACT); once the integrator
 * seeds 0x02015F04 in layout/function_starts.txt this re-verifies as EXACT.
 * The empty-then if/else on *dir gives the original `bge; b` shape.
 */
void POKETRADE_3D_SetMcssOffsetForSpecies(void *mcss, int *dir, int side, void *mon)
{
    VecFx32 v;
    int flag = 0;
    int a, b, c;
    int found;
    u8 i;
    float f;

    a = POKE_TOOL_GetPartyValue(mon, 5, 0);
    b = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
    c = POKE_TOOL_GetGender(mon);
    if (side == 0)
        flag = 1;
    found = 0;
    for (i = 0; i < 4; i++) {
        if (a == gSpeciesMcssOffset[i].a && b == gSpeciesMcssOffset[i].b
            && (gSpeciesMcssOffset[i].c == 3 || c == gSpeciesMcssOffset[i].c)
            && (gSpeciesMcssOffset[i].d == 2 || flag == gSpeciesMcssOffset[i].d)) {
            v.x = F32_TO_FX32(gSpeciesMcssOffset[i].x);
            if (*dir >= 0)
                v.x = -v.x;
            v.y = F32_TO_FX32(gSpeciesMcssOffset[i].y);
            v.z = F32_TO_FX32(gSpeciesMcssOffset[i].z);
            found = 1;
            break;
        }
    }
    if (!found) {
        MCSS_GetSizeX(mcss);
        c = MCSS_GetOfsX(mcss);
        if (*dir < 0)
            f = 0.33f * (float)c;
        else
            f = 0.33f * (float)-c;
        v.x = F32_TO_FX32(f);
        v.y = 0;
        v.z = 0;
    }
    MCSS_SetOfsPosition(mcss, (u32 *)(&v));
}

void POKETRADE_3D_AddPokemonMcss(TradeWork *p, int idx, int side, void *mon, int flag)
{
    VecFx32 v = gMcssMonOffset;
    U32Table4 t = gMcssMonConfig;
    if (flag) {
        u16 species = POKE_TOOL_GetPartyValue(mon, 5, 0);
        u16 form = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
        void *h = POKE_PERSONAL_Create(species, form, p->heapId);
        u32 r = POKE_PERSONAL_GetParam(h, 0x22);
        POKE_PERSONAL_Delete(h);
        if (r == 0)
            v.x = -v.x;
    }
    if (p->tradeState == 2)
        DWC_RAP_SetVchatTalkLock(1);
    if (side)
        p->mcssPokemon[idx] = MCSS_TOOL_AddPokeMcss(p->mcssSystem, mon, 0, t.v[idx], -0x1C000, 0);
    else
        p->mcssPokemon[idx] = MCSS_TOOL_AddPokeMcss(p->mcssSystem, mon, 1, t.v[idx], -0x1C000, 0);
    if (p->tradeState == 2)
        DWC_RAP_SetVchatTalkLock(0);
    MCSS_TOOL_SetAnimeStopCallback((struct McssWork *)p->mcssPokemon[idx]);
    MCSS_SetScale(p->mcssPokemon[idx], (u32 *)(&v));
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
void POKETRADE_3D_DeleteMcssSlot(TradeWork *p, int idx)
{
    void *v = p->mcssPokemon[idx];

    if (v != 0) {
        MCSS_SetVanishFlag(v);
        MCSS_Del(*(void **)&p->mcssSystem, p->mcssPokemon[idx]);
        p->mcssPokemon[idx] = 0;
    }
}

static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    REG_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    REG_VTX_16 = (u32)(u16)z;
}

/*
 * The cube vertex table (8 corners, x y z each). The values come from the
 * user's own ROM: tools/gendata.py writes build/gen/h16_ov119_021E8190.inc
 * (gitignored).
 */
static fx16 sCubeVtx[24] = {
#include "../../../build/gen/h16_ov119_021E8190.inc"
};

/*
 * The vertex table is a non-const file static: as an extern (or a const
 * static) the allocator keeps n*3 in r1; as a writable file static it keeps
 * n*3 in r4 and the base in r3 like the original.
 */
void POKETRADE_3D_EmitCubeVertex(int n)
{
    G3_Vtx(sCubeVtx[n * 3], sCubeVtx[n * 3 + 1], sCubeVtx[n * 3 + 2]);
}

void POKETRADE_3D_SetCubeNormal(int n)
{
    *(u32 *)0x04000484 = gCubeNormal[n];
}

void POKETRADE_3D_SetCubeTexCoord(int n)
{
    *(u32 *)0x04000488 = gCubeTexCoord[n];
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

void POKETRADE_3D_FillTexturePage(u16 *p, u8 *src, int k, int unused)
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

void POKETRADE_3D_FillTextureHeader(u16 *p, u8 *src, int unused)
{
    int i;

    for (i = 0; i < 6; i++)
        POKETRADE_3D_FillTextureCell(p, i % 2 + 2, i / 2 + 1, src[i]);
}

void POKETRADE_3D_UploadTexturePages(TradeWork *p, int count)
{
    char *v;
    int i;
    GX_BeginLoadTex();
    v = GFL_HEAP_Alloc(p->heapId, 0x200, 1, gParticleBufferAllocTag, 0x510);
    for (i = 0; i < count; i++) {
        MI_CpuFill8(v, 0, 0x200);
        if (i == 0)
            POKETRADE_3D_FillTextureHeader((u16 *)v, p->texHeader, 2);
        else
            POKETRADE_3D_FillTexturePage((u16 *)v, p->texSource, i - 1, 2);
        DC_FlushRange(v, 0x200);
        GX_LoadTex(v, i * 0x200 + 0x3000, 0x200);
    }
    GFL_HEAP_Free(v);
    GX_EndLoadTex();
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
    REG(REG_MTX_PUSH_ADDR)=0;
    REG(REG_MTX_MODE_ADDR)=1;
    G3_RotY(FX_SinCosTable_[(b>>4)*2],FX_SinCosTable_[(b>>4)*2+1]);
    REG(REG_MTX_PUSH_ADDR)=0;
    G3_RotY(FX_SinCosTable_[(a>>4)*2],FX_SinCosTable_[(a>>4)*2+1]);
    REG(REG_MTX_TRANS_ADDR)=0;
    REG(REG_MTX_TRANS_ADDR)=0;
    REG(REG_MTX_TRANS_ADDR)=z;
    G3_RotY(FX_SinCosTable_[(gAnimeFrameCfg.a>>4)*2],FX_SinCosTable_[(gAnimeFrameCfg.a>>4)*2+1]);
    G3_RotX(FX_SinCosTable_[(gAnimeFrameCfg.b>>4)*2],FX_SinCosTable_[(gAnimeFrameCfg.b>>4)*2+1]);
    REG(REG_MTX_SCALE_ADDR)=0x266;
    REG(REG_MTX_SCALE_ADDR)=0x266;
    REG(REG_MTX_SCALE_ADDR)=0x266;
    REG(REG_MTX_MODE_ADDR)=3;
    REG(REG_MTX_IDENTITY_ADDR)=0;
    REG(REG_MTX_MODE_ADDR)=2;
    POKETRADE_3D_SetToonEdgeColors(1,1);
    REG(REG_TEXIMAGE_PARAM_ADDR)=0x4d200000|(((u32)index*512+0x3000)>>3);
    REG(REG_TEXPLTT_BASE_ADDR)=512;
    REG(REG_POLYGON_ATTR_ADDR)=0x1f0041|((u32)index<<24);
    REG(REG_BEGIN_VTXS_ADDR)=1;
    POKETRADE_3D_SetCubeTexCoord(1); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(2);
    POKETRADE_3D_SetCubeTexCoord(0); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(0);
    POKETRADE_3D_SetCubeTexCoord(2); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(4);
    POKETRADE_3D_SetCubeTexCoord(3); POKETRADE_3D_SetCubeNormal(0); POKETRADE_3D_EmitCubeVertex(6);
    REG(REG_END_VTXS_ADDR)=0;
    REG(REG_MTX_POP_ADDR)=1;
    REG(REG_MTX_POP_ADDR)=1;
}

static inline fx32 fraction(int x,int y) { return (fx32)((unsigned long long)((long long)x*65536)/y); }

/*
 * lever: separate x+=48 and remainder assignments restore numerator register setup.
 * volatile: hardware writes 021E3A5C,021E3A60 to 040004C8/040004CC
 */
void POKETRADE_3D_DrawRotatingCube(TradeWork *p)
{
    int i,stage,count,total,base;
    int x;
    unsigned delta;
    u16 angle;
    G3X_Reset();
    G3i_LookAt_(&gLookAtEye,&gLookAtTarget,&gLookAtUp,1,0);
    *(volatile u32 *)REG_LIGHT_VECTOR_ADDR=0x2d8b6127;
    *(volatile u32 *)REG_LIGHT_COLOR_ADDR=0x7fff;
    stage=POKETRADE_PROC_GetStoredBoxIndex(p);
    count=stage+1;
    total=count*160;
    x=p->scrollY;
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
        POKETRADE_3D_DrawCubeFace(gAnimeFrameCfg.c,i,(u16)((i<<16)/count),angle);
    }
}

/* Loaded texture handle; ARC_UTIL_LoadPaletteBlockFromHandle returns its data pointer through an out slot. */
typedef struct {
    unsigned char pad_0[12];
    char *data;               /* 0x0C raw texture bytes */
} IcaTexture;

/* Header at the front of an IcaTexture data block. */
typedef struct {
    unsigned char pad_0[32];
    u16 firstColor;           /* 0x20 first palette entry */
} IcaTextureData;

void POKETRADE_3D_LoadTexturePalette(TradeWork *p)
{
    void *v;
    void *allocation;
    void *descriptor;
    char *data;
    v = ARC_TOOL_CreateHandle(0x74, p->heapId);
    allocation = ARC_UTIL_LoadPaletteBlockFromHandle((void *)v, 0x48, (&descriptor), p->heapId);
    data = ((IcaTexture *)descriptor)->data;
    DC_FlushRange(data + 32, 32);
    MI_CpuMove(data + 32, data + 34, 30);
    ((IcaTextureData *)data)->firstColor = 0x14A5;
    DC_FlushRange(data + 32, 32);
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(data + 32, 0x2000, 32);
    GX_EndLoadTexPltt();
    MI_CpuCopy8(data + 32, p->palettePageA, 32);
    GFL_HEAP_Free(allocation);
    ARC_TOOL_DeleteHandle(v);
}

void POKETRADE_3D_FadeTexturePalette(TradeWork *p)
{
    int i;
    int j;
    int component;
    int shift;
    for (i = 0; i < 16; i++) {
        p->palettePageB[i] = 0;
        for (j = 0; j < 3; j++) {
            shift = j * 5;
            component = (p->palettePageA[i] >> shift) & 31;
            if (component)
                component--;
            p->palettePageB[i] |= (unsigned short)((component & 31) << shift);
        }
    }
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(p->palettePageB, 0x2000, 32);
    GX_EndLoadTexPltt();
}

void POKETRADE_3D_CreateTouchbar(TradeWork *p)
{
    ElementTemplate t = gTouchbarTemplate;
    TouchbarConfig c;
    u16 a, b, d;
    MI_CpuFill8(&c, 0, sizeof(c));
    c.f0 = &t;
    c.f4 = 4;
    c.f8 = p->clactSystem;
    c.fC = 4;
    c.f1C = 1;
    c.f10 = 7;
    c.f14 = 0;
    c.f18 = 2;
    a = p->actorChar;
    t.e[1].f8 = a;
    b = p->actorPalette;
    t.e[1].fA = b;
    d = p->actorCellAnim;
    t.e[1].fC = d;
    t.e[1].fE = 6; t.e[1].f10 = 5; t.e[1].f12 = 4;
    t.e[1].f18 = 0; t.e[1].f1C = 0x54C;
    t.e[2].f8 = a; t.e[2].fA = b; t.e[2].fC = d;
    t.e[2].fE = 9; t.e[2].f10 = 8; t.e[2].f12 = 7;
    t.e[2].f18 = 8; t.e[2].f1C = 0x54C;
    t.e[3].f8 = a; t.e[3].fA = b; t.e[3].fC = d;
    t.e[3].fE = 22; t.e[3].f10 = 21; t.e[3].f12 = 20;
    t.e[3].f18 = 48; t.e[3].f1C = 0x54C;
    (*(void * *)&p->touchbar) = TOUCHBAR_Create((TouchBarParams *)&c, p->heapId);
    TOUCHBAR_SetButtonVisible((*(void * *)&p->touchbar), 9, 0);
    TOUCHBAR_SetButtonVisible((*(void * *)&p->touchbar), 8, 0);
    TOUCHBAR_SetAllButtonsPriority((*(void * *)&p->touchbar), 2);
}
