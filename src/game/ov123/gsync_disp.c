/*
 * file:     gsync_disp.c
 * unit:     yes
 * function: GSYNC_DISP_GetPokeIconActor, GSYNC_DISP_Init, GSYNC_DISP_Draw, GSYNC_DISP_Exit, GSYNC_DISP_InitBgLayers, GSYNC_DISP_VBlankTask, GSYNC_DISP_LoadResources, GSYNC_DISP_CreateEffectActorDefault, GSYNC_DISP_CreateSlotActor, GSYNC_DISP_SetSlotAnimSeq, GSYNC_DISP_SetSlotAnimCommand, GSYNC_DISP_DeleteSlotActor, GSYNC_DISP_CreateEffectActorAt, GSYNC_DISP_CreateSlotActorAt, GSYNC_DISP_SetMainActorAnimSeq, GSYNC_DISP_DeleteMainActor, GSYNC_DISP_LoadEffectResources, GSYNC_DISP_CreateMonIconActor, GSYNC_DISP_EnableActorAutoAnim, GSYNC_DISP_RestartActorAnim, GSYNC_DISP_PaletteWaveTask, GSYNC_DISP_StartPaletteWave, GSYNC_DISP_SetFadeDirection, GSYNC_DISP_UpdateBlendFade, GSYNC_DISP_UpdateProgressPosition, GSYNC_DISP_SpawnParticleLeft, GSYNC_DISP_HideParticle, GSYNC_DISP_SpawnParticleRight, GSYNC_DISP_UpdateParticle, GSYNC_DISP_UpdateParticles, GSYNC_DISP_SetIconRecord, GSYNC_DISP_SetIconRecordSpecies, GSYNC_DISP_LoadIconResources, GSYNC_DISP_CopyIconPaletteMain, GSYNC_DISP_CopyIconPaletteSub, GSYNC_DISP_CreatePokeIconActor, GSYNC_DISP_CreateBackdropActors
 * address:  0x021D5D8C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from gsync_state.c by tools/splitfile.py.
 *
 * symbols:
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049F78 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0204BA00 0x0204BA00 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207E468 0x0207E468 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_0204363C 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_02030734 0x02030734 arm
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   ov067_id 0x00000043 data
 *   func_02034AC4 0x02034AC4 arm
 *   gGsyncDispAllocSource 0x021DAB68 data a1
 *   gGsyncDispClactParam 0x021DAA9C data a4
 *   gGsyncClactConfig 0x020A1464 data a4
 *   gGsyncDispDisplayConfig 0x021DAA78 data a4
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 *   gGsyncDispBgTemplates 0x021DA758 data a4
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   gGsyncSlotPositions 0x021DAACC data a4
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   gGsyncMonIconX 0x021DA738 data a4
 *   gGsyncMonIconY 0x021DA748 data a4
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   gGsyncPaletteWaveColors 0x021DAA88 data a2
 *   func_02005624 0x02005624 thumb
 *   PMSI_PARAM_MakeSineTable 0x02024230 thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   gGsyncParticlePosLeft 0x021DA730 data a2
 *   gGsyncParticleScaleLeft 0x021DA750 data a4
 *   gGsyncParticlePosRight 0x021DA734 data a2
 *   gGsyncParticleScaleRight 0x021DA740 data a4
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_GetActorScale 0x0204B5C0 arm
 *   func_020056EC 0x020056EC thumb
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   func_02062A98 0x02062A98 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02019D30 0x02019D30 thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   func_020056A0 0x020056A0 thumb
 */
#include "gsync_common_types.h"

struct ArcFile;

struct NitroFileHeader;

extern void BG_SYS_InitBgLayer(u32, const struct BgTemplate *, u32);

extern void func_020409B4(u32);

extern void func_02040588(unsigned char which, unsigned char enable);

extern void BG_SYS_Init(u32, u32, u32, u32);

extern void func_02041300(u32, u32, u32, u32, u8, u8, u8);

extern void CLACT_SetActorAutoAnim(struct ClActor *p, u32 v);

extern struct ClActor *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const struct ActorSpawnPos *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorDrawEnable(struct ClActor *p, u32 v);

extern void CLACT_SetActorObjMode(struct ClActor *actor, u32 value);

extern void *func_020490F4(u32 id, u32 heap);

extern void func_02049B68(void *, u32, u32, u32, u32, u16);

extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);

extern void MI_CpuCopy8(const void *, void *, u32);

extern u32 func_020307B0(void *p);

extern u32 func_02049740(void *, u32, u32, u32, u32, u16);

extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

extern void ARC_TOOL_DeleteHandle(void *);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void func_02040DA8(u32 idx, u32 count, u32 tile);

extern void func_020403F4(u32 i);

extern void func_0204BA00(struct ClActor *a, const struct Cmd *cmd);

extern void CLACT_SetActorAnimSeq(struct ClActor *p, u16 value);

extern void DWCi_ScreenDC_FlushRange(void *, int);

extern void func_0207E468(void *, int, int);

extern void CLACT_VBlankSystem(void);

extern void func_0204363C(u32 swap);

extern void GX_DispOn(void);

extern void BG_SYS_Create(u16 heapId);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void func_0203FC28(struct DispConfig *cfg);

extern void BG_SYS_SetMainVisiblePlanes(u32);

extern void BG_SYS_SetSubVisiblePlanes(u32);

extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void *func_020056A0(void *,void *,int);

extern void *func_02030734(u32,u32,int,const char *,u16);

extern void func_0207D63C(void *,int,int,int,int);

extern void CLACT_DrawSystem(void);

extern void CLACT_DeleteActor(struct ClActor *p);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void func_02030EAC(struct Node *n);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern void BG_SYS_Delete(void);

extern int func_02034AC4(int);

extern void func_02034A5C(int);

extern void GX_LoadBGPltt(const void *, int, int);

extern void CLACT_SetActorAnimFrame(struct ClActor *p, u32 value);

extern void CLACT_SetActorAffineMode(struct ClActor *actor, u32 value);

extern int func_0201BC3C(void);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern u32 POKE_TOOL_GetGraphicIndex(void *mon);

extern int POKE_TOOL_GetIconPalette(void *a0);

extern void CLACT_SetActorPaletteOffset(struct ClActor *o, u32 v, u32 flag);

extern void *func_02005624(u32 a, u32 b, u32 c);

extern void PMSI_PARAM_MakeSineTable(s16 *out, u32 count, u16 step, s32 amp);

extern void CLACT_AddActorSurfacePos(struct ClActor *p, const struct ActorPos *delta, unsigned int which);

extern void CLACT_SetActorScale(struct ClActor *dst, struct ActorScale *src);

extern void CLACT_GetActorSurfacePos(struct ClActor *actor, struct ActorPos *out, u16 space);

extern void CLACT_GetActorScale(const struct ClActor *o, struct ActorScale *p);

extern u32 func_020056EC(u32 range);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);

extern u32 FILE_UTIL_Get(u16, int);

extern s32 func_02062A98(struct NitroFileHeader *file, void **out);

extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);

extern u32 func_02019D30(u32 a, u32 n);

extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);

extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

extern void CLACT_GetActorImageProxy(const char *src, struct ActorImageProxy *dst);

extern void GX_LoadOBJPltt(void *,int,int);

void *GSYNC_DISP_GetPokeIconActor(GsyncDispWork *p);

u8 *GSYNC_DISP_Init(u32 heap);

void GSYNC_DISP_Draw(GsyncDispWork *p);

void GSYNC_DISP_Exit(GsyncDispWork *p);

void GSYNC_DISP_InitBgLayers(GsyncDispWork *p);

void GSYNC_DISP_VBlankTask(void *a, GsyncDispWork *p);

void GSYNC_DISP_LoadResources(GsyncDispWork *p);

void GSYNC_DISP_CreateEffectActorDefault(GsyncDispWork *p);

void GSYNC_DISP_CreateSlotActor(GsyncDispWork *p,unsigned int i);

void GSYNC_DISP_SetSlotAnimSeq(GsyncDispWork *p, int i, u32 v);

void GSYNC_DISP_SetSlotAnimCommand(GsyncDispWork *p, int i, int v);

void GSYNC_DISP_DeleteSlotActor(GsyncDispWork *p, int i);

void GSYNC_DISP_CreateEffectActorAt(GsyncDispWork *p, int x, int y);

void GSYNC_DISP_CreateSlotActorAt(GsyncDispWork *p, unsigned int i);

void GSYNC_DISP_SetMainActorAnimSeq(GsyncDispWork *p);

void GSYNC_DISP_DeleteMainActor(GsyncDispWork *p);

void GSYNC_DISP_LoadEffectResources(GsyncDispWork *p);

void GSYNC_DISP_CreateMonIconActor(GsyncDispWork *p, void *n, int i);

void GSYNC_DISP_EnableActorAutoAnim(GsyncDispWork *p);

void GSYNC_DISP_RestartActorAnim(GsyncDispWork *p);

void GSYNC_DISP_PaletteWaveTask(void *unused, GsyncDispWork *p);

void GSYNC_DISP_StartPaletteWave(GsyncDispWork *p);

void GSYNC_DISP_SetFadeDirection(GsyncDispWork *p,int flag);

void GSYNC_DISP_UpdateBlendFade(GsyncDispWork *p);

void GSYNC_DISP_UpdateProgressPosition(GsyncDispWork *p, int n);

void GSYNC_DISP_SpawnParticleLeft(GsyncDispWork *p, int i);

void GSYNC_DISP_HideParticle(GsyncDispParticle *p);

void GSYNC_DISP_SpawnParticleRight(GsyncDispWork *p, int i);

void GSYNC_DISP_UpdateParticle(GsyncDispParticle *p);

void GSYNC_DISP_UpdateParticles(GsyncDispWork *p);

void GSYNC_DISP_SetIconRecord(GsyncDispWork *p,int i,int a,int b,int c);

void GSYNC_DISP_SetIconRecordSpecies(GsyncDispWork *p, int i, u16 v);

void GSYNC_DISP_LoadIconResources(GsyncDispWork *p);

void GSYNC_DISP_CopyIconPaletteMain(GsyncDispWork *p,int i,void *h);

void GSYNC_DISP_CopyIconPaletteSub(GsyncDispWork *p,int i,void *h);

void GSYNC_DISP_CreatePokeIconActor(GsyncDispWork *p);

void GSYNC_DISP_CreateBackdropActors(GsyncDispWork *p);

extern const char gGsyncDispAllocSource[];

extern char ov067_id[];

extern const u32 gGsyncDispClactParam[];

extern const u32 gGsyncClactConfig[];

extern const u32 gGsyncDispDisplayConfig[];

extern unsigned char ov_id[];

extern const struct BgTemplate gGsyncDispBgTemplates[7];

extern struct GsyncSlotPos gGsyncSlotPositions[];

extern const struct ActorScale gGsyncMonIconX;

extern const struct ActorScale gGsyncMonIconY;

extern const u16 gGsyncPaletteWaveColors[10];

extern const struct ActorPos gGsyncParticlePosLeft;

extern const struct ActorScale gGsyncParticleScaleLeft;

extern const struct ActorPos gGsyncParticlePosRight;

extern const struct ActorScale gGsyncParticleScaleRight;

extern const s16 FX_SinCosTable_[][2];

void *GSYNC_DISP_GetPokeIconActor(GsyncDispWork *p){return p->actors[GSYNC_DISP_ACTOR_EFFECT];}

/*
 * volatile: display register 04001000 read/write at 021D5DCA/021D5DD0.
 */
u8 *GSYNC_DISP_Init(u32 heap)
{
    GsyncDispWork *p;
    p=(GsyncDispWork *) func_02030734(heap,0x4568,1,gGsyncDispAllocSource,0xfe);
    p->heapId=heap;
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0); func_0204363C(1);
    *(volatile u32 *)0x04001000|=0x10000;
    GX_DispOn();
    BG_SYS_Create(p->heapId);
    CLACT_InitSystem((const struct Cfg *)gGsyncClactConfig,(u32)gGsyncDispClactParam,p->heapId);
    p->clactUnit=CLACT_CreateUnit(40,0,p->heapId);
    BG_SYS_SetVramBanks((const struct DispVram *)gGsyncDispClactParam); func_0203FC28((struct DispConfig *)gGsyncDispDisplayConfig);
    GSYNC_DISP_InitBgLayers(p); GSYNC_DISP_LoadResources(p); GSYNC_DISP_CreatePokeIconActor(p); GSYNC_DISP_CreateBackdropActors(p);
    p->vblankTcb=func_020056A0(GSYNC_DISP_VBlankTask,p,0);
    p->progressLine=200;
    BG_SYS_SetSubVisiblePlanes(31); BG_SYS_SetMainVisiblePlanes(27);
    return (u8 *)p;
}

void GSYNC_DISP_Draw(GsyncDispWork *p){(p->frame)++;if(p->frame>=192)p->frame=0;CLACT_DrawSystem();GSYNC_DISP_UpdateBlendFade(p);GSYNC_DISP_UpdateParticles(p);}

void GSYNC_DISP_Exit(GsyncDispWork *p)
{
    int i;
    GSYNC_DISP_DeleteMainActor(p);
    func_020307B0(p->paletteBlock);
    CLACT_DeleteActor(p->pokeIconActor);
    CLACT_DeleteActor(p->backdropActor);
    i=0;
    do { if(p->resources.all[i]) CLACT_ReleasePalette((u32)(p->resources.all[i])); i++; } while(i<6);
    for(;i<13;i++) if(p->resources.all[i]) CLACT_ReleaseCharacter((u32)(p->resources.all[i]));
    for(;i<20;i++) if(p->resources.all[i]) CLACT_ReleaseCellAnim((u32)(p->resources.all[i]));
    if(p->paletteWaveTcb) func_02030EAC(p->paletteWaveTcb);
    func_02030EAC(p->vblankTcb);
    CLACT_DeleteUnit(p->clactUnit);
    CLACT_ExitSystem();
    func_02040DA8(1,1,0); func_02040DA8(6,1,0);
    func_020403F4(5); func_020403F4(4);
    func_02040588(5,0); BG_SYS_Delete(); func_020307B0(p);
    func_02034A5C((int)ov_id);
}

void GSYNC_DISP_InitBgLayers(GsyncDispWork *p)
{
    struct BgTemplate b[7];
    b[6]=gGsyncDispBgTemplates[0]; BG_SYS_InitBgLayer(0, &b[6], 0); func_02040588(0,1); func_020409B4(0);
    b[5]=gGsyncDispBgTemplates[1]; BG_SYS_InitBgLayer(1, &b[5], 0); func_02040588(1,1); func_020409B4(1);
    b[4]=gGsyncDispBgTemplates[2]; BG_SYS_InitBgLayer(3, &b[4], 0); func_02040588(3,1); func_020409B4(3);
    b[3]=gGsyncDispBgTemplates[3]; BG_SYS_InitBgLayer(4, &b[3], 0); func_02040588(4,1); func_020409B4(4);
    b[2]=gGsyncDispBgTemplates[4]; BG_SYS_InitBgLayer(5, &b[2], 0);
    BG_SYS_Init(5,0,1,0); func_02041300(5,0,0,0,32,32,17); func_02040588(5,1); func_020409B4(5);
    b[1]=gGsyncDispBgTemplates[5]; BG_SYS_InitBgLayer(6, &b[1], 0); func_02040588(6,1);
    BG_SYS_Init(6,0,1,0); func_02041300(6,0,0,0,32,32,17); func_020409B4(6);
    b[0]=gGsyncDispBgTemplates[6]; BG_SYS_InitBgLayer(7, &b[0], 0); func_02040588(7,1); func_020409B4(7);
}

void GSYNC_DISP_VBlankTask(void *a, GsyncDispWork *p)
{
    int n;
    u8 *base;
    int off;
    CLACT_VBlankSystem();
    n = p->vblankCounter + 1;
    p->vblankCounter = n;
    if (n % 10 == 1) {
        base = p->paletteData->rawData;
        off = (n / 10 + 2) * 32;
        GX_LoadBGPltt(base + off, 64, 32);
        func_0207E468(base + off, 64, 32);
    }
    if (p->vblankCounter >= 80) p->vblankCounter = 0;
}

void GSYNC_DISP_LoadResources(GsyncDispWork *p)
{
    void *h;
    h=func_020490F4((u32)((void *)143),p->heapId);
    func_02049B68(h,2,4,0,0,p->heapId);
    p->charBase=func_02049740(h,8,4,0,0,p->heapId);
    func_02049990(h,21,4,0,(u16)(p->charBase),0,0,p->heapId);
    func_02049990(h,24,7,0,(u16)(p->paletteBase),0,0,p->heapId);
    p->paletteBlock=func_02049F78(h,2,(u32)(&p->paletteData),p->heapId);
    func_02049B68(h,2,0,0,0,p->heapId);
    p->paletteBase=func_02049740(h,8,0,0,0,p->heapId);
    func_02049990(h,23,0,0,(u16)(p->paletteBase),0,0,p->heapId);
    func_02049990(h,24,1,0,(u16)(p->paletteBase),0,0,p->heapId);
    p->resources.byKind.characters[0]=(void *)CLACT_RegisterCharacter(h,9,0,2,p->heapId);
    p->resources.byKind.palettes[0]=(void *)CLACT_RegisterPaletteEx(h,3,2,96,0,4,p->heapId);
    p->resources.byKind.cellAnims[0]=(void *)CLACT_RegisterCellAnim(h,12,25,p->heapId);
    p->resources.byKind.characters[1]=(void *)CLACT_RegisterCharacter(h,10,0,2,p->heapId);
    p->resources.byKind.palettes[1]=(void *)CLACT_RegisterPaletteEx(h,4,2,224,0,0,p->heapId);
    p->resources.byKind.cellAnims[1]=(void *)CLACT_RegisterCellAnim(h,13,26,p->heapId);
    GSYNC_DISP_LoadEffectResources(p); ARC_TOOL_DeleteHandle(h);
}

void GSYNC_DISP_CreateEffectActorDefault(GsyncDispWork *p){GSYNC_DISP_CreateEffectActorAt(p,133,128);}

void GSYNC_DISP_CreateSlotActor(GsyncDispWork *p,unsigned int i){GSYNC_DISP_CreateSlotActorAt(p,i);}

void GSYNC_DISP_SetSlotAnimSeq(GsyncDispWork *p, int i, u32 v)
{
    CLACT_SetActorAnimSeq(p->actors[i], (u16)v);
}

void GSYNC_DISP_SetSlotAnimCommand(GsyncDispWork *p, int i, int v)
{
    func_0204BA00(p->actors[i], (const struct Cmd *)v);
}

void GSYNC_DISP_DeleteSlotActor(GsyncDispWork *p, int i)
{
    if (p->actors[i]) {
        CLACT_DeleteActor(p->actors[i]);
        p->actors[i] = 0;
    }
}

void GSYNC_DISP_CreateEffectActorAt(GsyncDispWork *p, int x, int y)
{
    struct ActorSpawnPos pt;
    if (p->actors[GSYNC_DISP_ACTOR_EFFECT] == 0) {
        pt.x = x; pt.y = y; pt.z = 0; pt.mode = 0; pt.space = 1;
        p->actors[GSYNC_DISP_ACTOR_EFFECT] = CLACT_CreateActor((void *)p->clactUnit, (u32)p->resources.byKind.characters[1], (u32)p->resources.byKind.palettes[1], (u32)p->resources.byKind.cellAnims[1], &pt, 1, p->heapId);
        CLACT_SetActorAutoAnim(p->actors[GSYNC_DISP_ACTOR_EFFECT], 1);
        CLACT_SetActorDrawEnable(p->actors[GSYNC_DISP_ACTOR_EFFECT], 1);
    }
}

/*
 * lever: indexed p+0x74 array base and non-const table retain the original scheduling.
 */
void GSYNC_DISP_CreateSlotActorAt(GsyncDispWork *p, unsigned int i)
{
    struct ActorSpawnPos pt;
    if (p->actors[i]) CLACT_DeleteActor(p->actors[i]);
    pt.x = gGsyncSlotPositions[i].x; pt.y = gGsyncSlotPositions[i].y;
    pt.z = i; pt.mode = gGsyncSlotPositions[i].mode; pt.space = 1;
    p->actors[i] = CLACT_CreateActor((void *)p->clactUnit, (u32)p->resources.byKind.characters[0], (u32)p->resources.byKind.palettes[0], (u32)p->resources.byKind.cellAnims[0], &pt, 0, p->heapId);
    CLACT_SetActorAnimFrame(p->actors[i],0);
    CLACT_SetActorAutoAnim(p->actors[i],1);
    CLACT_SetActorDrawEnable(p->actors[i],1);
    CLACT_SetActorAffineMode(p->actors[i],2);
}

void GSYNC_DISP_SetMainActorAnimSeq(GsyncDispWork *p)
{
    CLACT_SetActorAnimSeq(p->actors[GSYNC_DISP_ACTOR_MON], 2);
}

void GSYNC_DISP_DeleteMainActor(GsyncDispWork *p){int i;for(i=0;i<16;i++){if(p->actors[i]){CLACT_DeleteActor(p->actors[i]);p->actors[i]=0;}}}

void GSYNC_DISP_LoadEffectResources(GsyncDispWork *p)
{
    void *h;
    h = func_020490F4(7, p->heapId);
    p->resources.byKind.palettes[2] = (void *)CLACT_RegisterPaletteCompressed(h, func_0201BC3C(), 2, 0, p->heapId);
    ARC_TOOL_DeleteHandle(h);
    h = func_020490F4(143, p->heapId);
    p->resources.byKind.cellAnims[2] = (void *)CLACT_RegisterCellAnim(h, 14, 27, p->heapId);
    ARC_TOOL_DeleteHandle(h);
}

void GSYNC_DISP_CreateMonIconActor(GsyncDispWork *p, void *n, int i)
{
    struct ActorScale a = gGsyncMonIconX;
    struct ActorScale b = gGsyncMonIconY;
    struct ActorSpawnPos pt;
    void *h;
    h = func_020490F4(7, p->heapId);
    p->resources.byKind.characters[2] = (void *)CLACT_RegisterCharacter(h,POKE_TOOL_GetGraphicIndex((void *)n),0,2,p->heapId);
    if(i==0) { pt.x=a.y; pt.y=b.y; }
    else { pt.x=a.x; pt.y=b.x; }
    pt.z=0; pt.mode=3; pt.space=1;
    p->actors[GSYNC_DISP_ACTOR_MON] = CLACT_CreateActor((void *)p->clactUnit,(unsigned int)p->resources.byKind.characters[2],(u32)p->resources.byKind.palettes[2],(u32)p->resources.byKind.cellAnims[2],&pt,(u16)i,p->heapId);
    CLACT_SetActorAutoAnim(p->actors[GSYNC_DISP_ACTOR_MON],0);
    CLACT_SetActorDrawEnable(p->actors[GSYNC_DISP_ACTOR_MON],1);
    CLACT_SetActorPaletteOffset(p->actors[GSYNC_DISP_ACTOR_MON],POKE_TOOL_GetIconPalette(n),1);
    ARC_TOOL_DeleteHandle(h);
}

void GSYNC_DISP_EnableActorAutoAnim(GsyncDispWork *p)
{
    CLACT_SetActorAutoAnim(p->actors[GSYNC_DISP_ACTOR_MON], 1);
}

void GSYNC_DISP_RestartActorAnim(GsyncDispWork *p)
{
    CLACT_SetActorAnimSeq(p->actors[GSYNC_DISP_ACTOR_MON], 1);
    CLACT_SetActorAutoAnim(p->actors[GSYNC_DISP_ACTOR_MON], 1);
}

void GSYNC_DISP_PaletteWaveTask(void *unused, GsyncDispWork *p)
{
    int line;
    int idx;
    int d;
    int v;
    idx = p->frame + 1;
    line = *(volatile u16 *)0x04000006;
    idx = (line + idx) % 0xC0;
    if (*(volatile u16 *)0x04000004 & 2) {
        *(volatile u32 *)0x0400001C = p->sineTable[idx] & 0x1FF;
        v = p->progressLine;
        if (v >= 0xC0) {
            GX_LoadBGPltt(gGsyncPaletteWaveColors, 0x142, 2);
            return;
        }
        if (v == 0) {
            GX_LoadBGPltt(&gGsyncPaletteWaveColors[9], 0x142, 2);
            return;
        }
        if (line > 200) {
            GX_LoadBGPltt(gGsyncPaletteWaveColors, 0x142, 2);
            return;
        }
        if (v > line) {
            GX_LoadBGPltt(gGsyncPaletteWaveColors, 0x142, 2);
            return;
        }
        d = line - v;
        if ((u32)d < 10 && d >= 0) {
            GX_LoadBGPltt(&gGsyncPaletteWaveColors[d], 0x142, 2);
            return;
        }
        GX_LoadBGPltt(&gGsyncPaletteWaveColors[9], 0x142, 2);
    }
}

void GSYNC_DISP_StartPaletteWave(GsyncDispWork *p)
{
    void *h;
    h = func_020490F4(143, p->heapId);
    func_02049990(h, 22, 3, 0, (u16)p->paletteBase, 0, 0, p->heapId);
    ARC_TOOL_DeleteHandle(h);
    p->paletteWaveTcb = func_02005624((u32)GSYNC_DISP_PaletteWaveTask, (u32)p, 0);
    PMSI_PARAM_MakeSineTable(p->sineTable, 192, 0x5b0, 0x1800);
}

void GSYNC_DISP_SetFadeDirection(GsyncDispWork *p,int flag){if(flag){p->fadeProgress=0;p->fadeDelta=1;}else{p->fadeProgress=65536;p->fadeDelta=-1;}}

void GSYNC_DISP_UpdateBlendFade(GsyncDispWork *p)
{
    int v;
    if (p->fadeDelta != 0) {
        p->fadeProgress += p->fadeDelta << 10;
        v = p->fadeProgress >> 12;
        func_02040588(3, 1);
        if (v > 10) { p->fadeDelta = 0; return; }
        if (v < 0) { v = 0; func_02040588(3, 0); p->fadeDelta = v; return; }
        func_0207D63C((void *)0x04000050, 8, 55, v, 8);
    }
}

void GSYNC_DISP_UpdateProgressPosition(GsyncDispWork *p, int n)
{
    float x = (float)(1.2 * (double)(float)n);
    int v;
    if (n > 100) v = 0;
    else v = (int)(120.0f - x);
    if (p->progressLine > v) p->progressLine = v;
}

void GSYNC_DISP_SpawnParticleLeft(GsyncDispWork *p, int i)
{
    struct ActorPos pos;
    struct ActorScale pair;
    struct ClActor *h;
    GSYNC_DISP_CopyIconPaletteMain(p,i,p->pokeIconActor);
    h = p->pokeIconActor;
    pos = gGsyncParticlePosLeft; pair = gGsyncParticleScaleLeft;
    CLACT_AddActorSurfacePos(h,(const struct ActorPos *)(&pos),0); CLACT_SetActorScale(h, (struct ActorScale *)&pair);
    CLACT_SetActorAutoAnim(h,0); CLACT_SetActorDrawEnable(h,0);
    CLACT_SetActorObjMode(h,1); CLACT_SetActorAffineMode(h,2);
    p->particles[i].actor = h;
}

void GSYNC_DISP_HideParticle(GsyncDispParticle *p){if(p->actor)CLACT_SetActorDrawEnable(p->actor,0);p->actor=0;}

void GSYNC_DISP_SpawnParticleRight(GsyncDispWork *p, int i)
{
    struct ActorPos pos;
    struct ActorScale pair;
    struct ClActor *h;
    GSYNC_DISP_CopyIconPaletteSub(p,i,p->backdropActor);
    h = p->backdropActor;
    pos = gGsyncParticlePosRight; pair = gGsyncParticleScaleRight;
    CLACT_AddActorSurfacePos(h,(const struct ActorPos *)(&pos),0); CLACT_SetActorScale(h, (struct ActorScale *)&pair);
    CLACT_SetActorAutoAnim(h,0); CLACT_SetActorDrawEnable(h,0);
    CLACT_SetActorObjMode(h,1); CLACT_SetActorAffineMode(h,2);
    p->particles[i].actor = h;
}

/*
 * lever: spelled-out x assignments reuse its already-loaded halfword.
 */
void GSYNC_DISP_UpdateParticle(GsyncDispParticle *p)
{
    struct ActorPos pos;
    struct ActorScale scale;
    int a,b;
    if (p == 0) return;
    a = (s16)(FX_SinCosTable_[p->angleA >> 4][0] * 4) >> 12;
    b = (s16)(FX_SinCosTable_[p->angleB >> 4][0] * 3) >> 12;
    if (p->actor) {
        CLACT_GetActorSurfacePos(p->actor, (struct ActorPos *)&pos, 0);
        pos.x = p->x + a + b;
        pos.y = (p->y + a + b + p->age) >> 2;
        if (p->age % 8 == 0) {
            if (p->x > 128) p->x = p->x - 1;
            else p->x = p->x + 1;
        }
        CLACT_AddActorSurfacePos(p->actor, (const struct ActorPos *)(&pos), 0);
        CLACT_SetActorDrawEnable(p->actor, 1);
        p->age++;
        if (pos.y > 25) {
            CLACT_GetActorScale(p->actor, (struct ActorScale *)&scale);
            scale.x -= 16;
            scale.y -= 16;
            if (scale.x < 0 || scale.y < 0) GSYNC_DISP_HideParticle(p);
            else CLACT_SetActorScale(p->actor, (struct ActorScale *)&scale);
        }
        if (pos.y > 50) GSYNC_DISP_HideParticle(p);
    } else p->finished = 1;
    if (p->finished == 0) {
        p->angleA += (u16)(func_020056EC(12) + 200);
        p->angleB -= (u16)(func_020056EC(12) + 666);
    }
}

/*
 * lever: bind i+20 to n before indexing, sharing its scaled address.
 */
void GSYNC_DISP_UpdateParticles(GsyncDispWork *p)
{
    int active = 0;
    int i,n;
    for (i = 0; i < 20; i++) {
        if (p->particles[i].active && !p->particles[i].finished) {
            GSYNC_DISP_UpdateParticle(&p->particles[i]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 20; i++) {
            n = func_020056EC(20);
            if (!p->particles[n].active && p->particles[n].species) {
                p->particles[n].active = 1;
                p->particles[n].x = func_020056EC(128) + 64;
                p->particles[n].y = 0;
                GSYNC_DISP_SpawnParticleRight(p, n);
                break;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        n = i + 20;
        if (p->particles[n].active && !p->particles[n].finished) {
            GSYNC_DISP_UpdateParticle(&p->particles[n]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 10; i++) {
            n = func_020056EC(10) + 20;
            if (!p->particles[n].active && p->particles[n].species) {
                p->particles[n].active = 1;
                p->particles[n].x = func_020056EC(128) + 64;
                p->particles[n].y = 0;
                GSYNC_DISP_SpawnParticleLeft(p, n);
                return;
            }
        }
    }
}

void GSYNC_DISP_SetIconRecord(GsyncDispWork *p,int i,int a,int b,int c){if(a!=0 && a<=493){p->particles[i].species=a;p->particles[i].formArg=b;if(c>2)c=0;p->particles[i].gender=c;}}

void GSYNC_DISP_SetIconRecordSpecies(GsyncDispWork *p, int i, u16 v)
{
    p->particles[i].species = v;
}

/*
 * lever: declare out2 before out to place out at sp+0x3c, out2 at sp+0x40.
 */
void GSYNC_DISP_LoadIconResources(GsyncDispWork *p)
{
    void *h;
    void *h2;
    void *buf;
    void *buf2;
    u8 *gfxOut;
    u8 *palOut;
    int i,n,species,form,gender;
    u32 value;
    u16 id;
    h = func_020490F4(25, p->heapId);
    for (i = 0; i < 20; i++) {
        species = p->particles[i].species;
        if (species) {
            buf = ARC_TOOL_LoadHandleMember(h,FILE_UTIL_Get(species,2),p->heapId);
            func_02062A98(buf,(void **)(&palOut));
            MI_CpuCopy8(((GsyncPaletteData *)palOut)->rawData,p->iconRecords[i].palette,32);
            func_020307B0(buf);
            buf2 = ARC_TOOL_LoadHandleMember(h,FILE_UTIL_Get(species,1),p->heapId);
            func_02062A4C(buf2,(void **)(&gfxOut));
            MI_CpuCopy8(((GsyncGfxData *)gfxOut)->rawData,p->iconRecords[i].paletteData,512);
            func_020307B0(buf2);
        }
    }
    ARC_TOOL_DeleteHandle(h);
    h2 = func_020490F4(7, p->heapId);
    for (i = 0; i < 10; i++) {
        n = i+20;
        species = p->particles[n].species;
        if (species) {
            gender = p->particles[n].gender;
            form = (int)func_02019D30((u16)species,(u8)(p->particles[n].formArg));
            value = POKE_TOOL_CalcIconPalette(species,form,gender,0);
            id = POKE_TOOL_CalcGraphicIndex(species,form,gender,0);
            buf2 = ARC_TOOL_LoadHandleMember(h2,id,p->heapId);
            func_02062A4C(buf2,(void **)(&gfxOut));
            MI_CpuCopy8(((GsyncGfxData *)gfxOut)->rawData,p->iconRecords[n].paletteData,512);
            func_020307B0(buf2);
            p->iconRecords[n].paletteOffset = value;
        }
    }
    ARC_TOOL_DeleteHandle(h2);
}

void GSYNC_DISP_CopyIconPaletteMain(GsyncDispWork *p,int i,void *h)
{
    struct ActorImageProxy d;
    CLACT_GetActorImageProxy(h,(struct ActorImageProxy *)(&d));
    MI_CpuCopy8(p->iconRecords[i].paletteData,(void *)(d.characterBase+0x6400000),0x200);
    CLACT_SetActorPaletteOffset(h,(u8)(p->iconRecords[i].paletteOffset),1);
}

void GSYNC_DISP_CopyIconPaletteSub(GsyncDispWork *p,int i,void *h)
{
    struct ActorImageProxy d;
    CLACT_GetActorImageProxy(h,(struct ActorImageProxy *)(&d));
    MI_CpuCopy8(p->iconRecords[i].paletteData,(void *)(d.characterBase+0x6400000),0x200);
    DWCi_ScreenDC_FlushRange(p->iconRecords[i].palette,0x20);
    GX_LoadOBJPltt(p->iconRecords[i].palette,0x100,0x20);
}

/*
 * lever: narrow the helper result through a named u16 local before the call.
 */
void GSYNC_DISP_CreatePokeIconActor(GsyncDispWork *p)
{
    struct ActorSpawnPos pt;
    void *h;
    u16 n;
    h=func_020490F4(7,p->heapId);
    n=POKE_TOOL_CalcGraphicIndex(1,0,0,0);
    p->resources.byKind.characters[3]=(void *)CLACT_RegisterCharacter(h,n,0,0,p->heapId);
    pt.x=133; pt.y=128; pt.z=0; pt.mode=3; pt.space=2;
    p->pokeIconActor=CLACT_CreateActor((void *)p->clactUnit,(u32)p->resources.byKind.characters[3],(u32)p->resources.byKind.palettes[2],(u32)p->resources.byKind.cellAnims[2],&pt,0,p->heapId);
    CLACT_SetActorAutoAnim(p->pokeIconActor,0);
    CLACT_SetActorDrawEnable(p->pokeIconActor,0);
    ARC_TOOL_DeleteHandle(h);
}

void GSYNC_DISP_CreateBackdropActors(GsyncDispWork *p)
{
    struct ActorSpawnPos pt;
    void *h;
    h=func_020490F4(25,p->heapId);
    p->resources.byKind.palettes[5]=(void *)CLACT_RegisterPaletteEx(h,FILE_UTIL_Get(1,2),0,256,0,1,p->heapId);
    p->resources.byKind.characters[6]=(void *)CLACT_RegisterCharacter(h,FILE_UTIL_Get(1,1),0,0,p->heapId);
    p->resources.byKind.cellAnims[6]=(void *)CLACT_RegisterCellAnim(h,1,0,p->heapId);
    ARC_TOOL_DeleteHandle(h);
    pt.x=156; pt.y=28; pt.z=0; pt.mode=0; pt.space=2;
    p->backdropActor=CLACT_CreateActor((void *)p->clactUnit,(unsigned int)p->resources.byKind.characters[6],(u32)p->resources.byKind.palettes[5],(u32)p->resources.byKind.cellAnims[6],&pt,0,p->heapId);
    CLACT_SetActorAutoAnim(p->backdropActor,0);
    CLACT_SetActorDrawEnable(p->backdropActor,0);
}
