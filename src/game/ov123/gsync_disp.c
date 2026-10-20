/*
 * file:     gsync_disp.c
 * unit:     yes
 * function: GSYNC_DISP_Init, GSYNC_DISP_Draw, GSYNC_DISP_Exit, GSYNC_DISP_InitBgLayers, GSYNC_DISP_VBlankTask, GSYNC_DISP_LoadResources, GSYNC_DISP_CreateEffectActorDefault, GSYNC_DISP_CreateSlotActor, GSYNC_DISP_SetSlotAnimSeq, GSYNC_DISP_SetSlotAnimCommand, GSYNC_DISP_DeleteSlotActor, GSYNC_DISP_CreateEffectActorAt, GSYNC_DISP_CreateSlotActorAt, GSYNC_DISP_SetMainActorAnimSeq, GSYNC_DISP_DeleteMainActor, GSYNC_DISP_LoadEffectResources, GSYNC_DISP_CreateMonIconActor, GSYNC_DISP_EnableActorAutoAnim, GSYNC_DISP_RestartActorAnim, GSYNC_DISP_PaletteWaveTask, GSYNC_DISP_StartPaletteWave, GSYNC_DISP_SetFadeDirection, GSYNC_DISP_UpdateBlendFade, GSYNC_DISP_UpdateProgressPosition, GSYNC_DISP_SpawnParticleLeft, GSYNC_DISP_HideParticle, GSYNC_DISP_SpawnParticleRight, GSYNC_DISP_UpdateParticle, GSYNC_DISP_UpdateParticles, GSYNC_DISP_SetIconRecord, GSYNC_DISP_SetIconRecordSpecies, GSYNC_DISP_LoadIconResources, GSYNC_DISP_CopyIconPaletteMain, GSYNC_DISP_CopyIconPaletteSub, GSYNC_DISP_CreatePokeIconActor, GSYNC_DISP_CreateBackdropActors
 * address:  0x021D5D94
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from gsync_download.c, gsync_disp.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   DC_FlushRange 0x020862F0 arm
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   GX_DispOn 0x0207D46C arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   ov067_id 0x00000043 data
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   gGsyncDispAllocSource 0x021DAB68 data a1
 *   gGsyncDispClactParam 0x021DAA9C data a4
 *   gGsyncClactConfig 0x020A1464 data a4
 *   gGsyncDispDisplayConfig 0x021DAA78 data a4
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ov_id 0x00000043 data
 *   gGsyncDispBgTemplates 0x021DA758 data a4
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   gGsyncSlotPositions 0x021DAACC data a4
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   gGsyncMonIconX 0x021DA738 data a4
 *   gGsyncMonIconY 0x021DA748 data a4
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   gGsyncPaletteWaveColors 0x021DAA88 data a2
 *   GFL_USE_AddHBlankTask 0x02005624 thumb
 *   FX_MakeSineTable 0x02024230 thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   gGsyncParticlePosLeft 0x021DA730 data a2
 *   gGsyncParticleScaleLeft 0x021DA750 data a4
 *   gGsyncParticlePosRight 0x021DA734 data a2
 *   gGsyncParticleScaleRight 0x021DA740 data a4
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_GetActorScale 0x0204B5C0 arm
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   NNS_G2dGetUnpackedCharacterDataEx 0x02062A4C arm
 *   POKE_TOOL_NormalizeForm 0x02019D30 thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   _dmul                        0x0209B2E8  arm
 *   _f2d                         0x0209BD38  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "../ov114/dwci_nd_types.h"
#include "../sdk_ioreg.h"
#include "gsync_common_types.h"

#include "../arm9/gfl_heap_wrap.h"


struct ArcFile;

struct NitroFileHeader;

#include "../arm9/bg_sys.h"




struct ClactActor;

#include "../arm9/clact.h"


struct ClactActor;


#include "../arm9/arc_tool.h"

#include "../arm9/arc_util.h"


#include "../arm9/mi_memory.h"











#include "../arm9/os_cache.h"

#include "../arm9/gx_load2d.h"



#include "../arm9/gx.h"





struct DispVramCfg;
struct SysInit;



#include "../arm9/gfl_use.h"

#include "../arm9/g2.h"





struct TcbTask;

#include "../arm9/tcb_list.h"




#include "../arm9/gf_overlay.h"





#include "../arm9/poke_tool_ext.h"

struct BoxPokemon;





#include "../arm9/pmsi_param.h"

struct Pair32;




struct ArcHandle;


#ifdef __MWERKS__
#define FILE_UTIL_Get FILE_UTIL_Get_hdr
#endif
#include "../arm9/file_util.h"
#ifdef __MWERKS__
#undef FILE_UTIL_Get
u32 FILE_UTIL_Get(u16, int);
#endif

#include "../arm9/nns_g2d_anim_bank.h"


#include "../arm9/poke_tool.h"


struct ImageProxy;



u8 *GSYNC_DISP_Init(u32 heap);

void GSYNC_DISP_Draw(GsyncDispWork *disp);

void GSYNC_DISP_Exit(GsyncDispWork *disp);

void GSYNC_DISP_InitBgLayers(GsyncDispWork *disp);

void GSYNC_DISP_VBlankTask(void *unused, GsyncDispWork *disp);

void GSYNC_DISP_LoadResources(GsyncDispWork *disp);

void GSYNC_DISP_CreateEffectActorDefault(GsyncDispWork *disp);

void GSYNC_DISP_CreateSlotActor(GsyncDispWork *disp,unsigned int slotIndex);

void GSYNC_DISP_SetSlotAnimSeq(GsyncDispWork *disp, int slotIndex, u32 animSeq);

void GSYNC_DISP_SetSlotAnimCommand(GsyncDispWork *disp, int slotIndex, int command);

void GSYNC_DISP_DeleteSlotActor(GsyncDispWork *disp, int slotIndex);

void GSYNC_DISP_CreateEffectActorAt(GsyncDispWork *disp, int posX, int posY);

void GSYNC_DISP_CreateSlotActorAt(GsyncDispWork *disp, unsigned int slotIndex);

void GSYNC_DISP_SetMainActorAnimSeq(GsyncDispWork *disp);

void GSYNC_DISP_DeleteMainActor(GsyncDispWork *disp);

void GSYNC_DISP_LoadEffectResources(GsyncDispWork *disp);

void GSYNC_DISP_CreateMonIconActor(GsyncDispWork *disp, void *mon, int slotIndex);

void GSYNC_DISP_EnableActorAutoAnim(GsyncDispWork *disp);

void GSYNC_DISP_RestartActorAnim(GsyncDispWork *disp);

void GSYNC_DISP_PaletteWaveTask(void *unused, GsyncDispWork *disp);

void GSYNC_DISP_StartPaletteWave(GsyncDispWork *disp);

void GSYNC_DISP_SetFadeDirection(GsyncDispWork *disp,int flag);

void GSYNC_DISP_UpdateBlendFade(GsyncDispWork *disp);

void GSYNC_DISP_UpdateProgressPosition(GsyncDispWork *disp, int progress);

void GSYNC_DISP_SpawnParticleLeft(GsyncDispWork *disp, int slotIndex);

void GSYNC_DISP_HideParticle(GsyncDispParticle *particle);

void GSYNC_DISP_SpawnParticleRight(GsyncDispWork *disp, int slotIndex);

void GSYNC_DISP_UpdateParticle(GsyncDispParticle *particle);

void GSYNC_DISP_UpdateParticles(GsyncDispWork *disp);

void GSYNC_DISP_SetIconRecord(GsyncDispWork *disp,int slotIndex,int species,int form,int gender);

void GSYNC_DISP_SetIconRecordSpecies(GsyncDispWork *disp, int slotIndex, u16 species);

void GSYNC_DISP_LoadIconResources(GsyncDispWork *disp);

void GSYNC_DISP_CopyIconPaletteMain(GsyncDispWork *disp,int slotIndex,void *actor);

void GSYNC_DISP_CopyIconPaletteSub(GsyncDispWork *disp,int slotIndex,void *actor);

void GSYNC_DISP_CreatePokeIconActor(GsyncDispWork *disp);

void GSYNC_DISP_CreateBackdropActors(GsyncDispWork *disp);

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

extern const struct GsyncCommonActorPos gGsyncParticlePosLeft;

extern const struct ActorScale gGsyncParticleScaleLeft;

extern const struct GsyncCommonActorPos gGsyncParticlePosRight;

extern const struct ActorScale gGsyncParticleScaleRight;

extern const s16 FX_SinCosTable_[][2];

/*
 * volatile: display register 04001000 read/write at 021D5DCA/021D5DD0.
 */
u8 *GSYNC_DISP_Init(u32 heap)
{
    GsyncDispWork *disp;
    disp=(GsyncDispWork *) GFL_HEAP_Alloc(heap,0x4568,1,gGsyncDispAllocSource,0xfe);
    disp->heapId=heap;
    GF_OVERLAY_Load((sptr)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0); BG_SYS_SetSubVisiblePlanes(0); BG_SYS_SetLcdSwap(1);
    *(volatile u32 *)0x04001000|=0x10000;
    GX_DispOn();
    BG_SYS_Create(disp->heapId);
    CLACT_InitSystem((const struct ClactSysInit *)gGsyncClactConfig,(const struct DispVramCfg *)gGsyncDispClactParam,disp->heapId);
    disp->clactUnit=CLACT_CreateUnit(40,0,disp->heapId);
    BG_SYS_SetVramBanks((const struct DispVram *)gGsyncDispClactParam); BG_SYS_SetGraphicsMode((struct DispConfig *)gGsyncDispDisplayConfig);
    GSYNC_DISP_InitBgLayers(disp); GSYNC_DISP_LoadResources(disp); GSYNC_DISP_CreatePokeIconActor(disp); GSYNC_DISP_CreateBackdropActors(disp);
    disp->vblankTcb=GFL_USE_AddMainTask((void (*)(struct TcbTask *, void *))GSYNC_DISP_VBlankTask,(void *)disp,0);
    disp->progressLine=200;
    BG_SYS_SetSubVisiblePlanes(31); BG_SYS_SetMainVisiblePlanes(27);
    return (u8 *)disp;
}

void GSYNC_DISP_Draw(GsyncDispWork *disp){(disp->frame)++;if(disp->frame>=192)disp->frame=0;CLACT_DrawSystem();GSYNC_DISP_UpdateBlendFade(disp);GSYNC_DISP_UpdateParticles(disp);}

void GSYNC_DISP_Exit(GsyncDispWork *disp)
{
    int resourceIndex;
    GSYNC_DISP_DeleteMainActor(disp);
    GFL_HEAP_Free((void *)disp->paletteBlock);
    CLACT_DeleteActor((struct ClactActor *)disp->pokeIconActor);
    CLACT_DeleteActor((struct ClactActor *)disp->backdropActor);
    resourceIndex=0;
    do { if(disp->resources.all[resourceIndex]) CLACT_ReleasePalette((uptr)(disp->resources.all[resourceIndex])); resourceIndex++; } while(resourceIndex<6);
    for(;resourceIndex<13;resourceIndex++) if(disp->resources.all[resourceIndex]) CLACT_ReleaseCharacter((uptr)(disp->resources.all[resourceIndex]));
    for(;resourceIndex<20;resourceIndex++) if(disp->resources.all[resourceIndex]) CLACT_ReleaseCellAnim((uptr)(disp->resources.all[resourceIndex]));
    if(disp->paletteWaveTcb) TCB_DeleteTask((struct TcbTask *)disp->paletteWaveTcb);
    TCB_DeleteTask((struct TcbTask *)disp->vblankTcb);
    CLACT_DeleteUnit((struct Unit *)disp->clactUnit);
    CLACT_ExitSystem();
    BG_SYS_FreeTiles(1,1,0); BG_SYS_FreeTiles(6,1,0);
    BG_SYS_FreeLayerBuf(5); BG_SYS_FreeLayerBuf(4);
    BG_SYS_SetPlaneVisible(5,0); BG_SYS_Delete(); GFL_HEAP_Free(disp);
    GF_OVERLAY_Unload((sptr)ov_id);
}

void GSYNC_DISP_InitBgLayers(GsyncDispWork *disp)
{
    struct BgTemplate bgTemplates[7];
    bgTemplates[6]=gGsyncDispBgTemplates[0]; BG_SYS_InitBgLayer(0, &bgTemplates[6], 0); BG_SYS_SetPlaneVisible(0,1); BG_SYS_PushTile(0);
    bgTemplates[5]=gGsyncDispBgTemplates[1]; BG_SYS_InitBgLayer(1, &bgTemplates[5], 0); BG_SYS_SetPlaneVisible(1,1); BG_SYS_PushTile(1);
    bgTemplates[4]=gGsyncDispBgTemplates[2]; BG_SYS_InitBgLayer(3, &bgTemplates[4], 0); BG_SYS_SetPlaneVisible(3,1); BG_SYS_PushTile(3);
    bgTemplates[3]=gGsyncDispBgTemplates[3]; BG_SYS_InitBgLayer(4, &bgTemplates[3], 0); BG_SYS_SetPlaneVisible(4,1); BG_SYS_PushTile(4);
    bgTemplates[2]=gGsyncDispBgTemplates[4]; BG_SYS_InitBgLayer(5, &bgTemplates[2], 0);
    BG_SYS_Init(5,0,1,0); BG_SYS_SetTileEntry(5,0,0,0,32,32,17); BG_SYS_SetPlaneVisible(5,1); BG_SYS_PushTile(5);
    bgTemplates[1]=gGsyncDispBgTemplates[5]; BG_SYS_InitBgLayer(6, &bgTemplates[1], 0); BG_SYS_SetPlaneVisible(6,1);
    BG_SYS_Init(6,0,1,0); BG_SYS_SetTileEntry(6,0,0,0,32,32,17); BG_SYS_PushTile(6);
    bgTemplates[0]=gGsyncDispBgTemplates[6]; BG_SYS_InitBgLayer(7, &bgTemplates[0], 0); BG_SYS_SetPlaneVisible(7,1); BG_SYS_PushTile(7);
}

void GSYNC_DISP_VBlankTask(void *unused, GsyncDispWork *disp)
{
    int frameCounter;
    u8 *base;
    int off;
    CLACT_VBlankSystem();
    frameCounter = disp->vblankCounter + 1;
    disp->vblankCounter = frameCounter;
    if (frameCounter % 10 == 1) {
        base = disp->paletteData->rawData;
        off = (frameCounter / 10 + 2) * 32;
        GX_LoadBGPltt(base + off, 64, 32);
        GXS_LoadBGPltt(base + off, 64, 32);
    }
    if (disp->vblankCounter >= 80) disp->vblankCounter = 0;
}

void GSYNC_DISP_LoadResources(GsyncDispWork *disp)
{
    void *archiveHandle;
    archiveHandle=ARC_TOOL_CreateHandle((uptr)((void *)143),disp->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archiveHandle,2,4,0,0,disp->heapId);
    disp->charBase=ARC_UTIL_RegisterObjCharFromHandle(archiveHandle,8,4,0,0,disp->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(archiveHandle,21,4,0,(u16)(disp->charBase),0,0,disp->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(archiveHandle,24,7,0,(u16)(disp->paletteBase),0,0,disp->heapId);
    disp->paletteBlock=ARC_UTIL_LoadPaletteBlockFromHandle((void *)archiveHandle,2,(&disp->paletteData),disp->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archiveHandle,2,0,0,0,disp->heapId);
    disp->paletteBase=ARC_UTIL_RegisterObjCharFromHandle(archiveHandle,8,0,0,0,disp->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(archiveHandle,23,0,0,(u16)(disp->paletteBase),0,0,disp->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(archiveHandle,24,1,0,(u16)(disp->paletteBase),0,0,disp->heapId);
    disp->resources.byKind.characters[0]=(void *)CLACT_RegisterCharacter(archiveHandle,9,0,2,disp->heapId);
    disp->resources.byKind.palettes[0]=(void *)CLACT_RegisterPaletteEx(archiveHandle,3,2,96,0,4,disp->heapId);
    disp->resources.byKind.cellAnims[0]=(void *)CLACT_RegisterCellAnim(archiveHandle,12,25,disp->heapId);
    disp->resources.byKind.characters[1]=(void *)CLACT_RegisterCharacter(archiveHandle,10,0,2,disp->heapId);
    disp->resources.byKind.palettes[1]=(void *)CLACT_RegisterPaletteEx(archiveHandle,4,2,224,0,0,disp->heapId);
    disp->resources.byKind.cellAnims[1]=(void *)CLACT_RegisterCellAnim(archiveHandle,13,26,disp->heapId);
    GSYNC_DISP_LoadEffectResources(disp); ARC_TOOL_DeleteHandle(archiveHandle);
}

void GSYNC_DISP_CreateEffectActorDefault(GsyncDispWork *disp){GSYNC_DISP_CreateEffectActorAt(disp,133,128);}

void GSYNC_DISP_CreateSlotActor(GsyncDispWork *disp,unsigned int slotIndex){GSYNC_DISP_CreateSlotActorAt(disp,slotIndex);}

void GSYNC_DISP_SetSlotAnimSeq(GsyncDispWork *disp, int slotIndex, u32 animSeq)
{
    CLACT_SetActorAnimSeq((struct ClactActor *)disp->actors[slotIndex], (u16)animSeq);
}

void GSYNC_DISP_SetSlotAnimCommand(GsyncDispWork *disp, int slotIndex, int command)
{
    CLACT_ApplyActorAnimCommand((struct ClactActor *)disp->actors[slotIndex], (const struct ClactAnimCommand *)command);
}

void GSYNC_DISP_DeleteSlotActor(GsyncDispWork *disp, int slotIndex)
{
    if (disp->actors[slotIndex]) {
        CLACT_DeleteActor((struct ClactActor *)disp->actors[slotIndex]);
        disp->actors[slotIndex] = 0;
    }
}

void GSYNC_DISP_CreateEffectActorAt(GsyncDispWork *disp, int posX, int posY)
{
    struct GsyncCommonActorSpawnPos pt;
    if (disp->actors[GSYNC_DISP_ACTOR_EFFECT] == 0) {
        pt.x = posX; pt.y = posY; pt.z = 0; pt.mode = 0; pt.space = 1;
        disp->actors[GSYNC_DISP_ACTOR_EFFECT] = CLACT_CreateActor((void *)disp->clactUnit, (uptr)disp->resources.byKind.characters[1], (uptr)disp->resources.byKind.palettes[1], (uptr)disp->resources.byKind.cellAnims[1], (const struct ActorInitParam *)&pt, 1, disp->heapId);
        CLACT_SetActorAutoAnim((struct ClactActor *)disp->actors[GSYNC_DISP_ACTOR_EFFECT], 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)disp->actors[GSYNC_DISP_ACTOR_EFFECT], 1);
    }
}

/*
 * lever: indexed p+0x74 array base and non-const table retain the original scheduling.
 */
void GSYNC_DISP_CreateSlotActorAt(GsyncDispWork *disp, unsigned int slotIndex)
{
    struct GsyncCommonActorSpawnPos pt;
    if (disp->actors[slotIndex]) CLACT_DeleteActor((struct ClactActor *)disp->actors[slotIndex]);
    pt.x = gGsyncSlotPositions[slotIndex].x; pt.y = gGsyncSlotPositions[slotIndex].y;
    pt.z = slotIndex; pt.mode = gGsyncSlotPositions[slotIndex].mode; pt.space = 1;
    disp->actors[slotIndex] = CLACT_CreateActor((void *)disp->clactUnit, (uptr)disp->resources.byKind.characters[0], (uptr)disp->resources.byKind.palettes[0], (uptr)disp->resources.byKind.cellAnims[0], (const struct ActorInitParam *)&pt, 0, disp->heapId);
    CLACT_SetActorAnimFrame((struct ClactActor *)disp->actors[slotIndex],0);
    CLACT_SetActorAutoAnim((struct ClactActor *)disp->actors[slotIndex],1);
    CLACT_SetActorDrawEnable((struct ClactActor *)disp->actors[slotIndex],1);
    CLACT_SetActorAffineMode((struct ClactActor *)disp->actors[slotIndex],2);
}

void GSYNC_DISP_SetMainActorAnimSeq(GsyncDispWork *disp)
{
    CLACT_SetActorAnimSeq((struct ClactActor *)disp->actors[GSYNC_DISP_ACTOR_MON], 2);
}

void GSYNC_DISP_DeleteMainActor(GsyncDispWork *disp){int slotIndex;for(slotIndex=0;slotIndex<16;slotIndex++){if(disp->actors[slotIndex]){CLACT_DeleteActor((struct ClactActor *)disp->actors[slotIndex]);disp->actors[slotIndex]=0;}}}

void GSYNC_DISP_LoadEffectResources(GsyncDispWork *disp)
{
    void *archiveHandle;
    archiveHandle = ARC_TOOL_CreateHandle(7, disp->heapId);
    disp->resources.byKind.palettes[2] = (void *)CLACT_RegisterPaletteCompressed(archiveHandle, POKE_TOOL_GetIconPaletteArcId(), 2, 0, disp->heapId);
    ARC_TOOL_DeleteHandle(archiveHandle);
    archiveHandle = ARC_TOOL_CreateHandle(143, disp->heapId);
    disp->resources.byKind.cellAnims[2] = (void *)CLACT_RegisterCellAnim(archiveHandle, 14, 27, disp->heapId);
    ARC_TOOL_DeleteHandle(archiveHandle);
}

void GSYNC_DISP_CreateMonIconActor(GsyncDispWork *disp, void *mon, int slotIndex)
{
    struct ActorScale iconScaleX = gGsyncMonIconX;
    struct ActorScale iconScaleY = gGsyncMonIconY;
    struct GsyncCommonActorSpawnPos pt;
    void *archiveHandle;
    archiveHandle = ARC_TOOL_CreateHandle(7, disp->heapId);
    disp->resources.byKind.characters[2] = (void *)CLACT_RegisterCharacter(archiveHandle,POKE_TOOL_GetGraphicIndex((void *)mon),0,2,disp->heapId);
    if(slotIndex==0) { pt.x=iconScaleX.y; pt.y=iconScaleY.y; }
    else { pt.x=iconScaleX.x; pt.y=iconScaleY.x; }
    pt.z=0; pt.mode=3; pt.space=1;
    disp->actors[GSYNC_DISP_ACTOR_MON] = CLACT_CreateActor((void *)disp->clactUnit,(uptr)disp->resources.byKind.characters[2],(uptr)disp->resources.byKind.palettes[2],(uptr)disp->resources.byKind.cellAnims[2],(const struct ActorInitParam *)&pt,(u16)slotIndex,disp->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)disp->actors[GSYNC_DISP_ACTOR_MON],0);
    CLACT_SetActorDrawEnable((struct ClactActor *)disp->actors[GSYNC_DISP_ACTOR_MON],1);
    CLACT_SetActorPaletteOffset((struct ClactActor *)disp->actors[GSYNC_DISP_ACTOR_MON],POKE_TOOL_GetIconPalette((struct BoxPokemon *)mon),1);
    ARC_TOOL_DeleteHandle(archiveHandle);
}

void GSYNC_DISP_EnableActorAutoAnim(GsyncDispWork *disp)
{
    CLACT_SetActorAutoAnim((struct ClactActor *)disp->actors[GSYNC_DISP_ACTOR_MON], 1);
}

void GSYNC_DISP_RestartActorAnim(GsyncDispWork *disp)
{
    CLACT_SetActorAnimSeq((struct ClactActor *)disp->actors[GSYNC_DISP_ACTOR_MON], 1);
    CLACT_SetActorAutoAnim((struct ClactActor *)disp->actors[GSYNC_DISP_ACTOR_MON], 1);
}

void GSYNC_DISP_PaletteWaveTask(void *unused, GsyncDispWork *disp)
{
    int line;
    int idx;
    int colorOffset;
    int progressLine;
    idx = disp->frame + 1;
    line = *(volatile u16 *)REG_VCOUNT_ADDR;
    idx = (line + idx) % 0xC0;
    if (*(volatile u16 *)REG_DISPSTAT_ADDR & 2) {
        *(volatile u32 *)0x0400001C = disp->sineTable[idx] & 0x1FF;
        progressLine = disp->progressLine;
        if (progressLine >= 0xC0) {
            GX_LoadBGPltt((void *)gGsyncPaletteWaveColors, 0x142, 2);
            return;
        }
        if (progressLine == 0) {
            GX_LoadBGPltt((void *)(&gGsyncPaletteWaveColors[9]), 0x142, 2);
            return;
        }
        if (line > 200) {
            GX_LoadBGPltt((void *)gGsyncPaletteWaveColors, 0x142, 2);
            return;
        }
        if (progressLine > line) {
            GX_LoadBGPltt((void *)gGsyncPaletteWaveColors, 0x142, 2);
            return;
        }
        colorOffset = line - progressLine;
        if ((u32)colorOffset < 10 && colorOffset >= 0) {
            GX_LoadBGPltt((void *)(&gGsyncPaletteWaveColors[colorOffset]), 0x142, 2);
            return;
        }
        GX_LoadBGPltt((void *)(&gGsyncPaletteWaveColors[9]), 0x142, 2);
    }
}

void GSYNC_DISP_StartPaletteWave(GsyncDispWork *disp)
{
    void *archiveHandle;
    archiveHandle = ARC_TOOL_CreateHandle(143, disp->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(archiveHandle, 22, 3, 0, (u16)disp->paletteBase, 0, 0, disp->heapId);
    ARC_TOOL_DeleteHandle(archiveHandle);
    disp->paletteWaveTcb = GFL_USE_AddHBlankTask((void (*)(struct TcbTask *, void *))((uptr)GSYNC_DISP_PaletteWaveTask), (void *)((uptr)disp), 0);
    FX_MakeSineTable(disp->sineTable, 192, 0x5b0, 0x1800);
}

void GSYNC_DISP_SetFadeDirection(GsyncDispWork *disp,int flag){if(flag){disp->fadeProgress=0;disp->fadeDelta=1;}else{disp->fadeProgress=65536;disp->fadeDelta=-1;}}

void GSYNC_DISP_UpdateBlendFade(GsyncDispWork *disp)
{
    int fadeValue;
    if (disp->fadeDelta != 0) {
        disp->fadeProgress += disp->fadeDelta << 10;
        fadeValue = disp->fadeProgress >> 12;
        BG_SYS_SetPlaneVisible(3, 1);
        if (fadeValue > 10) { disp->fadeDelta = 0; return; }
        if (fadeValue < 0) { fadeValue = 0; BG_SYS_SetPlaneVisible(3, 0); disp->fadeDelta = fadeValue; return; }
        G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR, 8, 55, fadeValue, 8);
    }
}

void GSYNC_DISP_UpdateProgressPosition(GsyncDispWork *disp, int progress)
{
    float scaledProgress = (float)(1.2 * (double)(float)progress);
    int position;
    if (progress > 100) position = 0;
    else position = (int)(120.0f - scaledProgress);
    if (disp->progressLine > position) disp->progressLine = position;
}

void GSYNC_DISP_SpawnParticleLeft(GsyncDispWork *disp, int slotIndex)
{
    struct GsyncCommonActorPos pos;
    struct ActorScale pair;
    struct ClactActor *actor;
    GSYNC_DISP_CopyIconPaletteMain(disp,slotIndex,disp->pokeIconActor);
    actor = disp->pokeIconActor;
    pos = gGsyncParticlePosLeft; pair = gGsyncParticleScaleLeft;
    CLACT_AddActorSurfacePos((struct ClactActor *)actor,(const struct ClactVec2 *)((const struct GsyncCommonActorPos *)(&pos)),0); CLACT_SetActorScale((struct ClactActor *)actor, (struct Pair32 *)&pair);
    CLACT_SetActorAutoAnim((struct ClactActor *)actor,0); CLACT_SetActorDrawEnable((struct ClactActor *)actor,0);
    CLACT_SetActorObjMode((struct ClactActor *)actor,1); CLACT_SetActorAffineMode((struct ClactActor *)actor,2);
    disp->particles[slotIndex].actor = actor;
}

void GSYNC_DISP_HideParticle(GsyncDispParticle *particle){if(particle->actor)CLACT_SetActorDrawEnable((struct ClactActor *)particle->actor,0);particle->actor=0;}

void GSYNC_DISP_SpawnParticleRight(GsyncDispWork *disp, int slotIndex)
{
    struct GsyncCommonActorPos pos;
    struct ActorScale pair;
    struct ClactActor *actor;
    GSYNC_DISP_CopyIconPaletteSub(disp,slotIndex,disp->backdropActor);
    actor = disp->backdropActor;
    pos = gGsyncParticlePosRight; pair = gGsyncParticleScaleRight;
    CLACT_AddActorSurfacePos((struct ClactActor *)actor,(const struct ClactVec2 *)((const struct GsyncCommonActorPos *)(&pos)),0); CLACT_SetActorScale((struct ClactActor *)actor, (struct Pair32 *)&pair);
    CLACT_SetActorAutoAnim((struct ClactActor *)actor,0); CLACT_SetActorDrawEnable((struct ClactActor *)actor,0);
    CLACT_SetActorObjMode((struct ClactActor *)actor,1); CLACT_SetActorAffineMode((struct ClactActor *)actor,2);
    disp->particles[slotIndex].actor = actor;
}

/*
 * lever: spelled-out x assignments reuse its already-loaded halfword.
 */
void GSYNC_DISP_UpdateParticle(GsyncDispParticle *particle)
{
    struct GsyncCommonActorPos pos;
    struct ActorScale scale;
    int sinA,sinB;
    if (particle == 0) return;
    sinA = (s16)(FX_SinCosTable_[particle->angleA >> 4][0] * 4) >> 12;
    sinB = (s16)(FX_SinCosTable_[particle->angleB >> 4][0] * 3) >> 12;
    if (particle->actor) {
        CLACT_GetActorSurfacePos((struct ClactActor *)particle->actor, (struct ClactVec2 *)&pos, 0);
        pos.x = particle->x + sinA + sinB;
        pos.y = (particle->y + sinA + sinB + particle->age) >> 2;
        if (particle->age % 8 == 0) {
            if (particle->x > 128) particle->x = particle->x - 1;
            else particle->x = particle->x + 1;
        }
        CLACT_AddActorSurfacePos((struct ClactActor *)particle->actor, (const struct ClactVec2 *)((const struct GsyncCommonActorPos *)(&pos)), 0);
        CLACT_SetActorDrawEnable((struct ClactActor *)particle->actor, 1);
        particle->age++;
        if (pos.y > 25) {
            CLACT_GetActorScale((const struct ClactActor *)particle->actor, (struct Pair32 *)&scale);
            scale.x -= 16;
            scale.y -= 16;
            if (scale.x < 0 || scale.y < 0) GSYNC_DISP_HideParticle(particle);
            else CLACT_SetActorScale((struct ClactActor *)particle->actor, (struct Pair32 *)&scale);
        }
        if (pos.y > 50) GSYNC_DISP_HideParticle(particle);
    } else particle->finished = 1;
    if (particle->finished == 0) {
        particle->angleA += (u16)(GFL_USE_GetRandom(12) + 200);
        particle->angleB -= (u16)(GFL_USE_GetRandom(12) + 666);
    }
}

/*
 * lever: bind i+20 to n before indexing, sharing its scaled address.
 */
void GSYNC_DISP_UpdateParticles(GsyncDispWork *disp)
{
    int active = 0;
    int slotIndex,particleIndex;
    for (slotIndex = 0; slotIndex < 20; slotIndex++) {
        if (disp->particles[slotIndex].active && !disp->particles[slotIndex].finished) {
            GSYNC_DISP_UpdateParticle(&disp->particles[slotIndex]);
            active = 1;
        }
    }
    if (active == 0) {
        for (slotIndex = 0; slotIndex < 20; slotIndex++) {
            particleIndex = GFL_USE_GetRandom(20);
            if (!disp->particles[particleIndex].active && disp->particles[particleIndex].species) {
                disp->particles[particleIndex].active = 1;
                disp->particles[particleIndex].x = GFL_USE_GetRandom(128) + 64;
                disp->particles[particleIndex].y = 0;
                GSYNC_DISP_SpawnParticleRight(disp, particleIndex);
                break;
            }
        }
    }
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        particleIndex = slotIndex + 20;
        if (disp->particles[particleIndex].active && !disp->particles[particleIndex].finished) {
            GSYNC_DISP_UpdateParticle(&disp->particles[particleIndex]);
            active = 1;
        }
    }
    if (active == 0) {
        for (slotIndex = 0; slotIndex < 10; slotIndex++) {
            particleIndex = GFL_USE_GetRandom(10) + 20;
            if (!disp->particles[particleIndex].active && disp->particles[particleIndex].species) {
                disp->particles[particleIndex].active = 1;
                disp->particles[particleIndex].x = GFL_USE_GetRandom(128) + 64;
                disp->particles[particleIndex].y = 0;
                GSYNC_DISP_SpawnParticleLeft(disp, particleIndex);
                return;
            }
        }
    }
}

void GSYNC_DISP_SetIconRecord(GsyncDispWork *disp,int slotIndex,int species,int form,int gender){if(species!=0 && species<=493){disp->particles[slotIndex].species=species;disp->particles[slotIndex].formArg=form;if(gender>2)gender=0;disp->particles[slotIndex].gender=gender;}}

void GSYNC_DISP_SetIconRecordSpecies(GsyncDispWork *disp, int slotIndex, u16 species)
{
    disp->particles[slotIndex].species = species;
}

/*
 * lever: declare out2 before out to place out at sp+0x3c, out2 at sp+0x40.
 */
void GSYNC_DISP_LoadIconResources(GsyncDispWork *disp)
{
    void *archiveHandle;
    void *paletteArchiveHandle;
    void *buf;
    void *buf2;
    u8 *gfxOut;
    u8 *palOut;
    int slotIndex,particleIndex,species,form,gender;
    u32 value;
    u16 id;
    archiveHandle = ARC_TOOL_CreateHandle(25, disp->heapId);
    for (slotIndex = 0; slotIndex < 20; slotIndex++) {
        species = disp->particles[slotIndex].species;
        if (species) {
            buf = ARC_TOOL_LoadHandleMember(archiveHandle,FILE_UTIL_Get(species,2),disp->heapId);
            NNS_G2dGetUnpackedPaletteData(buf,(void **)(&palOut));
            MI_CpuCopy8(((GsyncPaletteData *)palOut)->rawData,disp->iconRecords[slotIndex].palette,32);
            GFL_HEAP_Free(buf);
            buf2 = ARC_TOOL_LoadHandleMember(archiveHandle,FILE_UTIL_Get(species,1),disp->heapId);
            NNS_G2dGetUnpackedCharacterDataEx(buf2,(void **)(&gfxOut));
            MI_CpuCopy8(((GsyncGfxData *)gfxOut)->rawData,disp->iconRecords[slotIndex].paletteData,512);
            GFL_HEAP_Free(buf2);
        }
    }
    ARC_TOOL_DeleteHandle(archiveHandle);
    paletteArchiveHandle = ARC_TOOL_CreateHandle(7, disp->heapId);
    for (slotIndex = 0; slotIndex < 10; slotIndex++) {
        particleIndex = slotIndex+20;
        species = disp->particles[particleIndex].species;
        if (species) {
            gender = disp->particles[particleIndex].gender;
            form = (int)POKE_TOOL_NormalizeForm((u16)species,(u8)(disp->particles[particleIndex].formArg));
            value = POKE_TOOL_CalcIconPalette(species,form,gender,0);
            id = POKE_TOOL_CalcGraphicIndex(species,form,gender,0);
            buf2 = ARC_TOOL_LoadHandleMember(paletteArchiveHandle,id,disp->heapId);
            NNS_G2dGetUnpackedCharacterDataEx(buf2,(void **)(&gfxOut));
            MI_CpuCopy8(((GsyncGfxData *)gfxOut)->rawData,disp->iconRecords[particleIndex].paletteData,512);
            GFL_HEAP_Free(buf2);
            disp->iconRecords[particleIndex].paletteOffset = value;
        }
    }
    ARC_TOOL_DeleteHandle(paletteArchiveHandle);
}

void GSYNC_DISP_CopyIconPaletteMain(GsyncDispWork *disp,int slotIndex,void *actor)
{
    struct ActorImageProxy imageProxy;
    CLACT_GetActorImageProxy(actor,(struct ImageProxy *)(&imageProxy));
    MI_CpuCopy8(disp->iconRecords[slotIndex].paletteData,(void *)(imageProxy.characterBase+0x6400000),0x200);
    CLACT_SetActorPaletteOffset(actor,(u8)(disp->iconRecords[slotIndex].paletteOffset),1);
}

void GSYNC_DISP_CopyIconPaletteSub(GsyncDispWork *disp,int slotIndex,void *actor)
{
    struct ActorImageProxy imageProxy;
    CLACT_GetActorImageProxy(actor,(struct ImageProxy *)(&imageProxy));
    MI_CpuCopy8(disp->iconRecords[slotIndex].paletteData,(void *)(imageProxy.characterBase+0x6400000),0x200);
    DC_FlushRange(disp->iconRecords[slotIndex].palette,0x20);
    GX_LoadOBJPltt(disp->iconRecords[slotIndex].palette,0x100,0x20);
}

/*
 * lever: narrow the helper result through a named u16 local before the call.
 */
void GSYNC_DISP_CreatePokeIconActor(GsyncDispWork *disp)
{
    struct GsyncCommonActorSpawnPos pt;
    void *archiveHandle;
    u16 graphicIndex;
    archiveHandle=ARC_TOOL_CreateHandle(7,disp->heapId);
    graphicIndex=POKE_TOOL_CalcGraphicIndex(1,0,0,0);
    disp->resources.byKind.characters[3]=(void *)CLACT_RegisterCharacter(archiveHandle,graphicIndex,0,0,disp->heapId);
    pt.x=133; pt.y=128; pt.z=0; pt.mode=3; pt.space=2;
    disp->pokeIconActor=CLACT_CreateActor((void *)disp->clactUnit,(uptr)disp->resources.byKind.characters[3],(uptr)disp->resources.byKind.palettes[2],(uptr)disp->resources.byKind.cellAnims[2],(const struct ActorInitParam *)&pt,0,disp->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)disp->pokeIconActor,0);
    CLACT_SetActorDrawEnable((struct ClactActor *)disp->pokeIconActor,0);
    ARC_TOOL_DeleteHandle(archiveHandle);
}

void GSYNC_DISP_CreateBackdropActors(GsyncDispWork *disp)
{
    struct GsyncCommonActorSpawnPos pt;
    void *archiveHandle;
    archiveHandle=ARC_TOOL_CreateHandle(25,disp->heapId);
    disp->resources.byKind.palettes[5]=(void *)CLACT_RegisterPaletteEx(archiveHandle,FILE_UTIL_Get(1,2),0,256,0,1,disp->heapId);
    disp->resources.byKind.characters[6]=(void *)CLACT_RegisterCharacter(archiveHandle,FILE_UTIL_Get(1,1),0,0,disp->heapId);
    disp->resources.byKind.cellAnims[6]=(void *)CLACT_RegisterCellAnim(archiveHandle,1,0,disp->heapId);
    ARC_TOOL_DeleteHandle(archiveHandle);
    pt.x=156; pt.y=28; pt.z=0; pt.mode=0; pt.space=2;
    disp->backdropActor=CLACT_CreateActor((void *)disp->clactUnit,(uptr)disp->resources.byKind.characters[6],(uptr)disp->resources.byKind.palettes[5],(uptr)disp->resources.byKind.cellAnims[6],(const struct ActorInitParam *)&pt,0,disp->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)disp->backdropActor,0);
    CLACT_SetActorDrawEnable((struct ClactActor *)disp->backdropActor,0);
}
