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
 *   func_02047964 0x02047964 arm
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
 *   func_020056BC 0x020056BC thumb
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
 *   func_02048A18 0x02048A18 arm
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
 *   func_0207F7A0 0x0207F7A0 arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207F7FC 0x0207F7FC arm
 *   func_0207F9B4 0x0207F9B4 arm
 *   G3_RotY 0x0207D84C arm
 *   G3_RotX 0x0207D810 arm
 *   G3X_Reset 0x0207DA8C arm
 *   G3i_LookAt_ 0x0207D7C4 arm
 *   POKETRADE_PROC_GetStoredBoxIndex 0x021D8A18 thumb ov119
 *   gLookAtEye 0x021E815C data ov119 a4
 *   gLookAtTarget 0x021E79AC data ov119 a4
 *   gLookAtUp 0x021E8150 data ov119 a4
 *   func_02049F78 0x02049F78 arm
 *   func_02083194 0x02083194 arm
 *   func_0207FA0C 0x0207FA0C arm
 *   func_0207FA40 0x0207FA40 arm
 *   GX_EndLoadTexPltt 0x0207FADC arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_SetAllButtonsPriority 0x021B6520 thumb ov067
 *   gTouchbarTemplate 0x021E7C0C data a4
 *   POKETRADE_SAVE_Init3DProjection 0x021E2B14 thumb ov119
 *   POKETRADE_SAVE_Free3DLightSet 0x021E2B68 thumb ov119
 */
#include "pokemontrade_types.h"

extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);

extern void MI_CpuFill8(void *,int,int);

extern void DWC_RAP_SetVchatTalkLock(int);

extern void func_02047964(void);

extern void G3D_CAMERA_Reset(struct Light *l);

extern void G3D_SYSTEM_ApplyLookAt(void);

extern void *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap);

extern void ARC_TOOL_DeleteHandle(void *);

#define F32_TO_FX32(f) ((int)(((f) > 0) ? ((f) * 4096.0f + 0.5f) : ((f) * 4096.0f - 0.5f)))

#define REG_VTX_16 (*(vu32 *)0x0400048C)

#define REG(a) (*(volatile unsigned long *)(a))

struct G3dSys;

struct Arg;


/*
 * Particle and ICA animation manager owned by TradeWork.particleManager.
 * Allocated and released by the caller; holds nine particle systems with
 * their backing heap blocks, the four ICA animation streams and the shared
 * particle archive member.
 */
typedef struct ParticleManager {
    void *system[9];          /* 0x000 particle systems */
    void *buffer[9];          /* 0x024 heap block backing each system */
    unsigned char pad_48[72]; /* 0x048 */
    void *icaStream[4];       /* 0x090 ICA animation streams */
    unsigned char pad_A0[8];  /* 0x0A0 */
    int streamFrame[2];       /* 0x0A8 loop frame of stream 0 and stream 1 */
    unsigned char pad_B0[4];  /* 0x0B0 */
    void *archiveMember;      /* 0x0B4 shared particle archive member */
    unsigned char pad_B8[2];  /* 0x0B8 */
    u16 heap;                 /* 0x0BA owning heap id */
} ParticleManager;


typedef struct { u32 x, y, z; } Vec3U32;

typedef struct {void (*call)(char *);u32 other;} Callback;

typedef void (*Fn)(void *);

typedef struct { int a, b, c; u16 d, e; } G3dUnitEntry;

typedef struct {
    void (*fn)(char *p, void *out);
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

typedef struct { int x, y, z; } IntVec3;



typedef struct { u32 v[4]; } U32Table4;


typedef short fx16;

typedef volatile u32 vu32;




typedef long fx32;


typedef struct { fx32 a[12]; } MtxFx43;


typedef struct { u32 f0, f4; u16 f8, fA, fC, fE, f10, f12; u32 f14, f18, f1C; } Element;

typedef struct { Element e[4]; } ElementTemplate;

typedef struct { void *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1C; } TouchbarConfig;

extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);

extern u32 GFL_HEAP_Free(void *p);

extern void MI_CpuCopy8(const void *,void *,unsigned);

extern void MCSS_SetVanishFlag(void *);

extern void *ICA_ANIME_CreateStream(u32,u32,u32,u32);

extern void ICA_ANIME_SetFrame(struct IcaAnime *p, int v);

extern void ICA_ANIME_Delete(struct IcaAnime *p);

extern void PARTICLE_InitManager(u32 heap);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);

extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);

extern void OS_WaitInterrupt(int clear, u32 flags);

extern u32 func_020056BC(void);

extern void PARTICLE_SetupSystemBorrowed(void *p, unsigned int a1, unsigned int a2, unsigned int a3);

extern void PARTICLE_ExitManager(void);

extern void PARTICLE_SetupSystem(void *, void *, int, int);

extern void *G3D_UTIL_Create(u16,u16,u16);

extern void *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,Vec3U32 *,Vec3U32 *,Vec3U32 *,u16);

extern unsigned int G3D_CAMERA_Delete(void *ptr);

extern void G3D_UTIL_Delete(struct Rec *p);

extern u16 G3D_UTIL_AddUnit(void *,const G3dUnitEntry *);

extern u32 func_02048A18(u8 *a0, int i);

extern int G3D_SYSTEM_GetObjectAnimeCount(int *p);

extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

extern int PARTICLE_DrawAllSystems(void);

extern int PARTICLE_UpdateAllSystems(void);

extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

extern u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, int v);

extern u8 POKE_TOOL_GetGender(void *p);

extern u16 MCSS_GetSizeX(void *p);

extern short MCSS_GetOfsX(void *p);

extern void MCSS_SetOfsPosition(void *p, u32 *src);

extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);

extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);

extern void POKE_PERSONAL_Delete(void *h);

extern void *MCSS_TOOL_AddPokeMcss(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);

extern int MCSS_TOOL_SetAnimeStopCallback(int a0);

extern void MCSS_SetScale(void *p, u32 *src);

extern void MCSS_SetShadowVanishFlag(char *p, int v);

extern void MCSS_Del(void *sys, void *obj);

extern void func_0207F7A0(void);

extern void DWCi_ScreenDC_FlushRange(void *, int);

extern void func_0207F7FC(void *, int, int);

extern void func_0207F9B4(void);

extern void G3_RotY(fx32,fx32);

extern void G3_RotX(fx32,fx32);

extern void G3X_Reset(void);

extern void G3i_LookAt_(const VecFx32 *,const VecFx32 *,const VecFx32 *,int,MtxFx43 *);

extern u8 POKETRADE_PROC_GetStoredBoxIndex(u8 *);

extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);

extern void func_02083194(const void *, void *, int);

extern void func_0207FA0C(void);

extern void func_0207FA40(const void *, int, int);

extern void GX_EndLoadTexPltt(void);

extern void *TOUCHBAR_Create(TouchbarConfig *, int);

extern void TOUCHBAR_SetAllButtonsPriority(u8 *p, u32 v);

void POKETRADE_SAVE_Init3DProjection(int a);

void POKETRADE_SAVE_Free3DLightSet(void);

void POKETRADE_3D_CreateIcaStreamsForMode(ParticleManager *p,unsigned mode);

void POKETRADE_3D_DeleteIcaStreams(ParticleManager *p);

void POKETRADE_3D_CreateIcaStreamsEnding(ParticleManager *p);

void POKETRADE_3D_FreeParticleResources(ParticleManager *a0);

void POKETRADE_3D_InitParticleSystems(ParticleManager *p);

void POKETRADE_3D_SetupParticleSystemsLow(ParticleManager *p);

void POKETRADE_3D_SetupParticleSystemsHigh(ParticleManager *p);

void POKETRADE_3D_ExitParticleManager(ParticleManager *p, int a1);

void POKETRADE_3D_InitTradeParticleSet(ParticleManager *p);

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

extern short FX_SinCosTable_[];

extern char gParticleBufferAllocTag[];

extern Vec3U32 gCubeRotation;

extern const short gCameraParams[];

extern Callback g3dStateCallbacks[];

extern Fn gPokeTrade3dStateTable[];

extern const G3dUnitEntry gG3dUnitTable[];

extern const Handler g3dSceneHandlers[];

extern Cfg gAnimeFrameCfg;

extern TransformEntry gSpeciesMcssOffset[4];

extern const IntVec3 gMcssMonOffset;

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

void POKETRADE_3D_FreeParticleResources(ParticleManager *a0) { POKETRADE_3D_DeleteIcaStreams(a0); }

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
        p->system[i]=(void *)PARTICLE_CreateSystemDefault((int)p->buffer[i],0x4800,flag,p->heap);
    }
}

void POKETRADE_3D_SetupParticleSystemsLow(ParticleManager *p) {
    int i;
    p->archiveMember=(void *)PARTICLE_LoadArchiveMember((int)0x67,(int)0x35,(u16)((p->heap&0x7fff)|0x8000));
    for(i=0;i<4;i++) {
        int x;
        OS_WaitInterrupt(1,1);
        x=func_020056BC();
        PARTICLE_SetupSystemBorrowed(p->system[i],(unsigned int)p->archiveMember,1,x);
    }
}

void POKETRADE_3D_SetupParticleSystemsHigh(ParticleManager *p)
{
    int i;

    for (i = 4; i < 9; i++) {
        OS_WaitInterrupt(1, 1);
        PARTICLE_SetupSystemBorrowed(p->system[i], (unsigned int)p->archiveMember, 1, func_020056BC());
    }
}

/*
 * Teardown: release the +0xb4 pointer and the nine 32-bit slots at
 * +0x24, zeroing each. Target of func_021D6C78's second call (ov119).
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_3D_ExitParticleManager(ParticleManager *p, int a1)
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
        *q = (void *)PARTICLE_CreateSystemDefault((int)buf, 0x4800, 0, p->heap);
    }
    h = (void *)PARTICLE_LoadArchiveMember(0x68, 10, p->heap);
    for (i = 0; i < 6; i++)
        PARTICLE_SetupSystem(p->system[i], h, 1, 0);
}

void POKETRADE_3D_Init3DScene(char *p)
{
    ((TradeWork *)p)->g3dUnitHandle=0xffff;
    ((TradeWork *)p)->animIndex=~0u;
    POKETRADE_SAVE_Init3DProjection(0x91);
    ((TradeWork *)p)->g3dUtil=G3D_UTIL_Create(20,20,0x91);
    if (!((TradeWork *)p)->subCamera) {
        Vec3U32 a={0,0,0};
        Vec3U32 b={0,0,0};
        Vec3U32 c;
        u16 heap;
        heap=((TradeWork *)p)->heapId;
        c=gCubeRotation;
        ((TradeWork *)p)->subCamera=G3D_CAMERA_Create(0,gCameraParams[6],gCameraParams[7],0x1555,0,0x1000,0x400000,0,&a,&c,&b,heap);
    }
    if (((TradeWork *)p)->animIndex!=~0u)
        g3dStateCallbacks[*(u32 *)(p+0x109c)].call(p);
}

void POKETRADE_3D_Update3DScene(void *p) { POKETRADE_3D_Draw3DScene(p); }

void POKETRADE_3D_Delete3DScene(char *p) {
    if (((TradeWork *)p)->subCamera) G3D_CAMERA_Delete(((TradeWork *)p)->subCamera);
    G3D_UTIL_Delete(((TradeWork *)p)->g3dUtil);
    if (((TradeWork *)p)->particleManager) {
        POKETRADE_3D_ExitParticleManager(((TradeWork *)p)->particleManager,6);
        POKETRADE_3D_FreeParticleResources(((TradeWork *)p)->particleManager);
        GFL_HEAP_Free(((TradeWork *)p)->particleManager);
        ((TradeWork *)p)->particleManager=0;
    }
    POKETRADE_SAVE_Free3DLightSet();
}

void POKETRADE_3D_UploadCubeTextures(void *p) { POKETRADE_3D_UploadTexturePages(p, 0x19); }

void POKETRADE_3D_AddUnitAndInit(void *p, int a)
{
    POKETRADE_3D_AddUnit(p, a);
    if (((TradeWork *)p)->animIndex != 0xFFFFFFFF) {
        gPokeTrade3dStateTable[*(u32 *)((char *)p + 0x109C) * 2](p);
    }
}

void POKETRADE_3D_RemoveCurrentUnit(void *p)
{
    if (((TradeWork *)p)->animIndex != 0xFFFFFFFF) {
        POKETRADE_3D_RemoveUnit(p);
        ((TradeWork *)p)->animIndex = 0xFFFFFFFF;
    }
}

void POKETRADE_3D_AddUnit(char *p,int n) {
    void *q;
    int i,count;
    if(gG3dUnitTable[n].d) ((TradeWork *)p)->g3dUnitHandle=G3D_UTIL_AddUnit(((TradeWork *)p)->g3dUtil,&gG3dUnitTable[n]);
    else ((TradeWork *)p)->g3dUnitHandle=0xffff;
    if(((TradeWork *)p)->g3dUnitHandle!=0xffff) {
        q=(void *)func_02048A18(((TradeWork *)p)->g3dUtil,((TradeWork *)p)->g3dUnitHandle);
        count=G3D_SYSTEM_GetObjectAnimeCount(q);
        for(i=0;i<count;i++) G3D_SYSTEM_EnableObjectAnime(q,(u16)i);
    }
    *(int *)&((TradeWork *)p)->animIndex=n;
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

    idx = (*(int *)&((TradeWork *)p)->animIndex);
    if (idx == -1)
        return;
    if (g3dSceneHandlers[idx].fn != 0)
        g3dSceneHandlers[idx].fn(p, buf);
    if (((TradeWork *)p)->g3dUnitHandle != 0xFFFF) {
        q = (void *)func_02048A18(((TradeWork *)p)->g3dUtil, ((TradeWork *)p)->g3dUnitHandle);
        n = G3D_SYSTEM_GetObjectAnimeCount(q);
        for (i = 0; i < n; i++)
            G3D_SYSTEM_LoopObjectAnimeFrame(q, (u16)i, gAnimeFrameCfg.amount);
    }
    func_02047964();
    G3D_CAMERA_Reset(((TradeWork *)p)->subCamera);
    G3D_SYSTEM_ApplyLookAt();
    if (((TradeWork *)p)->particleManager != 0) {
        PARTICLE_DrawAllSystems();
        PARTICLE_UpdateAllSystems();
    }
    if (((TradeWork *)p)->g3dUnitHandle != 0xFFFF)
        G3D_SYSTEM_DrawObject((void *)func_02048A18(((TradeWork *)p)->g3dUtil, ((TradeWork *)p)->g3dUnitHandle), (struct Arg *)buf);
    if (((TradeWork *)p)->particleManager != 0) {
        if (((TradeWork *)p)->particleManager->icaStream[0] != 0) {
            if (((TradeWork *)p)->particleManager->streamFrame[0] == 0)
                ((TradeWork *)p)->particleManager->streamFrame[0] = ICA_ANIME_IncFrameLoop((struct IcaAnime *)(((TradeWork *)p)->particleManager->icaStream[0]), gAnimeFrameCfg.amount);
            if (((TradeWork *)p)->particleManager->streamFrame[1] == 0)
                ((TradeWork *)p)->particleManager->streamFrame[1] = ICA_ANIME_IncFrameLoop((struct IcaAnime *)(((TradeWork *)p)->particleManager->icaStream[1]), gAnimeFrameCfg.amount);
        }
        if (((TradeWork *)p)->particleManager->icaStream[3] != 0)
            ICA_ANIME_IncFrameLoop((struct IcaAnime *)(((TradeWork *)p)->particleManager->icaStream[3]), gAnimeFrameCfg.amount);
        if (((TradeWork *)p)->particleManager->icaStream[2] != 0)
            ICA_ANIME_IncFrameLoop((struct IcaAnime *)(((TradeWork *)p)->particleManager->icaStream[2]), gAnimeFrameCfg.amount);
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
    IntVec3 v;
    int flag = 0;
    int a, b, c;
    int found;
    u8 i;
    float f;

    a = POKE_TOOL_GetPartyValue(mon, 5, 0);
    b = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
    c = POKE_TOOL_GetGender(mon);
    if (p2 == 0)
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
    MCSS_SetOfsPosition(p0, (u32 *)(&v));
}

void POKETRADE_3D_AddPokemonMcss(TradeWork *p, int idx, int side, void *mon, int flag)
{
    IntVec3 v = gMcssMonOffset;
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
    MCSS_TOOL_SetAnimeStopCallback((int)p->mcssPokemon[idx]);
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
void POKETRADE_3D_DeleteMcssSlot(void *p, int idx)
{
    u32 v = ((u32 *)((char *)p + 0x844))[idx];

    if (v != 0) {
        MCSS_SetVanishFlag((void *)v);
        MCSS_Del((void *)(*(u32 *)&((TradeWork *)p)->mcssSystem), (void *)(((u32 *)((char *)p + 0x844))[idx]));
        ((u32 *)((char *)p + 0x844))[idx] = 0;
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
    v = GFL_HEAP_Alloc(((TradeWork *)p)->heapId, 0x200, 1, gParticleBufferAllocTag, 0x510);
    for (i = 0; i < count; i++) {
        MI_CpuFill8(v, 0, 0x200);
        if (i == 0)
            POKETRADE_3D_FillTextureHeader((u16 *)v, (unsigned char *)(p + 0x5B6), 2);
        else
            POKETRADE_3D_FillTexturePage((u16 *)v, (u8 *)(p + 0x2E6), i - 1, 2);
        DWCi_ScreenDC_FlushRange(v, 0x200);
        func_0207F7FC(v, i * 0x200 + 0x3000, 0x200);
    }
    GFL_HEAP_Free(v);
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
    G3_RotY(FX_SinCosTable_[(b>>4)*2],FX_SinCosTable_[(b>>4)*2+1]);
    REG(0x04000444)=0;
    G3_RotY(FX_SinCosTable_[(a>>4)*2],FX_SinCosTable_[(a>>4)*2+1]);
    REG(0x04000470)=0;
    REG(0x04000470)=0;
    REG(0x04000470)=z;
    G3_RotY(FX_SinCosTable_[(gAnimeFrameCfg.a>>4)*2],FX_SinCosTable_[(gAnimeFrameCfg.a>>4)*2+1]);
    G3_RotX(FX_SinCosTable_[(gAnimeFrameCfg.b>>4)*2],FX_SinCosTable_[(gAnimeFrameCfg.b>>4)*2+1]);
    REG(0x0400046c)=0x266;
    REG(0x0400046c)=0x266;
    REG(0x0400046c)=0x266;
    REG(0x04000440)=3;
    REG(0x04000454)=0;
    REG(0x04000440)=2;
    POKETRADE_3D_SetToonEdgeColors(1,1);
    REG(0x040004a8)=0x4d200000|(((u32)index*512+0x3000)>>3);
    REG(0x040004ac)=512;
    REG(0x040004a4)=0x1f0041|((u32)index<<24);
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
    G3X_Reset();
    G3i_LookAt_(&gLookAtEye,&gLookAtTarget,&gLookAtUp,1,0);
    *(volatile u32 *)0x040004c8=0x2d8b6127;
    *(volatile u32 *)0x040004cc=0x7fff;
    stage=POKETRADE_PROC_GetStoredBoxIndex((u8 *)p);
    count=stage+1;
    total=count*160;
    x=((TradeWork *)p)->scrollY;
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

/* Loaded texture handle; func_02049F78 returns its data pointer through an out slot. */
typedef struct {
    unsigned char pad_0[12];
    char *data;               /* 0x0C raw texture bytes */
} IcaTexture;

/* Header at the front of an IcaTexture data block. */
typedef struct {
    unsigned char pad_0[32];
    u16 firstColor;           /* 0x20 first palette entry */
} IcaTextureData;

void POKETRADE_3D_LoadTexturePalette(char *p)
{
    void *v;
    void *allocation;
    void *descriptor;
    char *data;
    v = ARC_TOOL_CreateHandle(0x74, ((TradeWork *)p)->heapId);
    allocation = func_02049F78(v, 0x48, (u32)(&descriptor), ((TradeWork *)p)->heapId);
    data = ((IcaTexture *)descriptor)->data;
    DWCi_ScreenDC_FlushRange(data + 32, 32);
    func_02083194(data + 32, data + 34, 30);
    ((IcaTextureData *)data)->firstColor = 0x14A5;
    DWCi_ScreenDC_FlushRange(data + 32, 32);
    func_0207FA0C();
    func_0207FA40(data + 32, 0x2000, 32);
    GX_EndLoadTexPltt();
    MI_CpuCopy8(data + 32, p + 0x1134, 32);
    GFL_HEAP_Free(allocation);
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
        ((TradeWork *)q)->colorBitsB = 0;
        for (j = 0; j < 3; j++) {
            shift = j * 5;
            component = (((TradeWork *)q)->colorBitsA >> shift) & 31;
            if (component)
                component--;
            ((TradeWork *)q)->colorBitsB |= (unsigned short)((component & 31) << shift);
        }
    }
    func_0207FA0C();
    func_0207FA40(p + 0x1154, 0x2000, 32);
    GX_EndLoadTexPltt();
}

void POKETRADE_3D_CreateTouchbar(char *p)
{
    ElementTemplate t = gTouchbarTemplate;
    TouchbarConfig c;
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
    a = *(u32 *)&((TradeWork *)p)->actorChar;
    t.e[1].f8 = a;
    b = *(u32 *)&((TradeWork *)p)->actorPalette;
    t.e[1].fA = b;
    d = *(u32 *)&((TradeWork *)p)->actorCellAnim;
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
