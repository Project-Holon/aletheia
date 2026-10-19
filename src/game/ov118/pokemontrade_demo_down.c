/*
 * file:     pokemontrade_demo_down.c
 * unit:     yes
 * function: POKETRADE_DEMO_DOWN_StepSetup, POKETRADE_DEMO_DOWN_StepSetupParticles, POKETRADE_DEMO_DOWN_StepPlaySe, POKETRADE_DEMO_DOWN_UpdateScene, POKETRADE_DEMO_DOWN_StepFade, POKETRADE_DEMO_DOWN_CompareSideMon, POKETRADE_DEMO_DOWN_CreateUnitActor, POKETRADE_DEMO_DOWN_LoadUnitResources, POKETRADE_DEMO_DOWN_ReleaseUnit, POKETRADE_DEMO_DOWN_PassThrough, POKETRADE_DEMO_DOWN_SetFrame, POKETRADE_DEMO_DOWN_SetFinishFlag, POKETRADE_DEMO_DOWN_StepStartPlayback, POKETRADE_DEMO_DOWN_StepWaitSync
 * address:  0x021D5A60
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pokemontrade_demo_up.c, pokemontrade_demo_down.c by tools/splitfile.py.
 *
 * symbols:
 *   POKETRADE_MCSS_SlideUpdate  0x021DFC68  thumb  ov119
 *   POKETRADE_2D_ScheduleMainPlaneVisible  0x021E71F0  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MCSS_GetPosition  0x02015C30  thumb
 *   POKETRADE_SAVE_FreeIfSet  0x021DFD24  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssPlain  0x021E36C8  thumb  ov119
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   POKETRADE_PROC_DeleteAllResources  0x021DC720  thumb
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   POKETRADE_2D_InitClactSystemMain  0x021E3E40  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   POKETRADE_2D_SetupSummaryBgs  0x021E5284  thumb
 *   POKETRADE_3D_AddUnitAndInit  0x021E3208  thumb
 *   POKETRADE_3D_InitParticleSystems  0x021E2F34  thumb
 *   POKETRADE_3D_SetupParticleSystemsLow  0x021E2FB0  thumb ov119
 *   POKETRADE_3D_CreateIcaStreamsForMode  0x021E2D70  thumb
 *   POKETRADE_3D_SetupParticleSystemsHigh  0x021E3004  thumb  ov119
 *   POKETRADE_3D_RemoveCurrentUnit  0x021E3230  thumb  ov119
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   PARTICLE_StartEffectWithCallback  0x020515CC  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   POKETRADE_MCSS_SlideCreate  0x021DFB84  thumb  ov119
 *   POKETRADE_NEGO_PlaySeByKeyA  0x021DFA60  thumb  ov119
 *   POKETRADE_MCSS_SlideBegin  0x021DFB4C  thumb  ov119
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   d_021D82A4  0x021D82A4  data
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   POKETRADE_3D_FadeTexturePalette  0x021E3BB0  thumb  ov119
 *   POKETRADE_PROC_IsNetSession  0x021D8A24  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   POKETRADE_DEMO_COMMON_StepBeginPlayback  0x021D67F8  thumb  ov118
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   ARC_TOOL_CreateHandle  0x020490F4  arm  arm9
 *   POKETRADE_DEMO_UP_CreateUnitActor 0x021D55AC thumb ov118
 *   POKETRADE_DEMO_UP_LoadUnitResources 0x021D5628 thumb ov118
 *   POKETRADE_DEMO_UP_PassThrough 0x021D56E0 thumb ov118
 *   POKETRADE_DEMO_UP_SetFrame 0x021D56E4 thumb ov118
 *   POKETRADE_DEMO_UP_StepReleaseUnit 0x021D56FC thumb ov118
 *   POKETRADE_DEMO_UP_DeleteSlide 0x021D572C thumb ov118
 *   POKETRADE_DEMO_UP_SetMonSlide 0x021D5748 thumb ov118
 *   POKETRADE_DEMO_UP_ResetMonSlide 0x021D5888 thumb ov118
 *   POKETRADE_DEMO_UP_SetupEmitterC 0x021D5930 thumb ov118
 *   POKETRADE_DEMO_UP_SetupEmitterD 0x021D5990 thumb ov118
 *   _dfix                        0x0209C508  arm
 *   _dflt                        0x0209B750  arm
 *   _dmul                        0x0209B2E8  arm
 */
#include "pokemontrade_demo_types.h"
#include "pokemontrade_demo_up_shared_types.h"

extern void POKETRADE_MCSS_SlideUpdate(void *p, void *eventArg);

extern void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);

extern void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);

extern int POKETRADE_PROC_IsHostSide(void *);

extern void *POKETRADE_PROC_GetSideMon(void *, int);
struct PokemonParam;

extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);

extern u32 GFL_HEAP_Free(void *p);
struct McssWork;

extern void MCSS_GetPosition(struct McssWork *work, u32 *out);

extern void POKETRADE_SAVE_FreeIfSet(u32 *p);

extern void POKETRADE_3D_AddPokemonMcssPlain(void *p, int a, int b, void *mon, int c);

extern void MCSS_SetAnmStopFlag(struct McssWork *work);

extern void MCSS_SetVanishFlag(struct McssWork *work);

extern void POKETRADE_PROC_SetStep(void *p, int next);

extern void MCSS_SetPosition(struct McssWork *work, u32 *src);

extern void MCSS_ResetVanishFlag(struct McssWork *work);

extern void MCSS_ResetAnmStopFlag(struct McssWork *work);

extern void POKETRADE_PROC_DeleteAllResources(char *p);

extern void CLACT_ExitSystem(void);

extern void POKETRADE_2D_InitClactSystemMain(char *p);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void POKETRADE_2D_SetupSummaryBgs(char *p, int mode);

extern void POKETRADE_3D_AddUnitAndInit(void *p, int a);
struct ParticleManager;

extern void POKETRADE_3D_InitParticleSystems(struct ParticleManager *p);

extern void POKETRADE_3D_SetupParticleSystemsLow(struct ParticleManager *p);

extern void POKETRADE_3D_CreateIcaStreamsForMode(struct ParticleManager *p, u32 mode);

extern void POKETRADE_3D_SetupParticleSystemsHigh(struct ParticleManager *p);

extern void POKETRADE_3D_RemoveCurrentUnit(void *p);

extern void MCSS_SetPaletteFade(struct McssWork *work, u32 start, u32 end, s32 wait, u32 color);

extern void MCSS_GetScale(struct McssWork *work, u32 *out);

extern void MCSS_SetScale(struct McssWork *work, u32 *src);

extern int PARTICLE_StartEffectWithCallback(u32, int, void *, void *);

extern void WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u16 color, u32 frames, u32 wait, u32 heapId);

extern void *POKETRADE_MCSS_SlideCreate(void *mcss, void *frameCount, void *targetPos, u32 heapId);

extern void POKETRADE_NEGO_PlaySeByKeyA(u32 key);
struct McssSlide;

extern void POKETRADE_MCSS_SlideBegin(struct McssSlide *slide, void *frameCount, void *targetPos);

struct Entry;

struct Link;
struct PersonalData;

extern struct PersonalData *POKE_PERSONAL_Create(u32 a, int b, u32 heap);

extern u32 POKE_PERSONAL_GetParam(struct PersonalData *data, u32 field);

extern void POKE_PERSONAL_Delete(struct PersonalData *data);
struct MyStatus;

extern u32 MYSTATUS_GetId(struct MyStatus *mystatus);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Actor;

extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 enable);

extern void CLACT_SetActorDrawEnable(struct Actor *actor, u32 value);

extern void CLACT_RestartActorAnim(struct Actor *a);

extern void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void ARC_TOOL_DeleteHandle(void *);

extern void CLACT_DeleteActor(struct Actor *actor);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void BG_SYS_SetSubVisiblePlanes(u32 planes);

extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);

extern void POKETRADE_3D_FadeTexturePalette(char *p);

extern int POKETRADE_PROC_IsNetSession(void *p);
struct GFLNetHandle;

extern struct GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct GFLNetHandle *handle, u32 timingLow, u32 timingHigh);

extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct GFLNetHandle *handle, u32 timingLow, u32 timingHigh);

void POKETRADE_DEMO_UP_CreateUnitActor(void *p);

void POKETRADE_DEMO_UP_LoadUnitResources(void *p);

int POKETRADE_DEMO_UP_PassThrough(int a);

void POKETRADE_DEMO_UP_SetFrame(u8 *p, u32 v);

void POKETRADE_DEMO_UP_StepReleaseUnit(void *p);

void POKETRADE_DEMO_UP_DeleteSlide(u8 *p, int idx);

void POKETRADE_DEMO_UP_SetMonSlide(u8 *p, int idx);

void POKETRADE_DEMO_UP_ResetMonSlide(u8 *p, int idx);

void POKETRADE_DEMO_UP_SetupEmitterC(void *p);

void POKETRADE_DEMO_UP_SetupEmitterD(void *p);

void POKETRADE_DEMO_DOWN_StepSetup(u8 *p);

void POKETRADE_DEMO_DOWN_StepSetupParticles(u8 *p);

void POKETRADE_DEMO_DOWN_StepPlaySe(u8 *p);

void POKETRADE_DEMO_DOWN_UpdateScene(u8 *p);

void POKETRADE_DEMO_DOWN_StepFade(s8 *fade);

void POKETRADE_DEMO_DOWN_CompareSideMon(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);

void POKETRADE_DEMO_DOWN_CreateUnitActor(void *p);

void POKETRADE_DEMO_DOWN_LoadUnitResources(void *p);

void POKETRADE_DEMO_DOWN_ReleaseUnit(void *p);

int POKETRADE_DEMO_DOWN_PassThrough(int a);

void POKETRADE_DEMO_DOWN_SetFrame(u8 *p, u32 v);

void POKETRADE_DEMO_DOWN_SetFinishFlag(u8 *p);

void POKETRADE_DEMO_DOWN_StepStartPlayback(u8 *p);

void POKETRADE_DEMO_DOWN_StepWaitSync(u8 *p);

void POKETRADE_DEMO_COMMON_StepBeginPlayback(u8 *p);

extern const char d_021D82A4[];

#define WORK ((u8 *)((PokeTradeDemoWork *)work)->animWork)

void POKETRADE_DEMO_DOWN_StepSetup(u8 *work)
{
    POKETRADE_PROC_DeleteAllResources((char *)work);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain((char *)work);
    ((PokeTradeDemoWork *)work)->clactSystem = (int)CLACT_CreateUnit(3, 0, HEAP);
    ((PokeTradeDemoWork *)work)->animWork = GFL_HEAP_Alloc(HEAP, 0xBC, 1, d_021D82A4, 0xA8);
    *(u16 *)(WORK + 0xBA) = HEAP;
    POKETRADE_2D_SetupSummaryBgs((char *)work, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    POKETRADE_3D_AddUnitAndInit(work, 5);
    POKETRADE_3D_AddPokemonMcssPlain(work, 1, 0, POKETRADE_PROC_GetSideMon(work, 1), 1);
    POKETRADE_3D_AddPokemonMcssPlain(work, 2, 0, POKETRADE_PROC_GetSideMon(work, 0), 1);
    POKETRADE_3D_AddPokemonMcssPlain(work, 3, 1, POKETRADE_PROC_GetSideMon(work, 1), 1);
    MCSS_SetVanishFlag(OBJ(0));
    MCSS_SetVanishFlag(OBJ(1));
    MCSS_SetVanishFlag(OBJ(2));
    MCSS_SetVanishFlag(OBJ(3));
    POKETRADE_3D_InitParticleSystems((struct ParticleManager *)WORK);
    POKETRADE_3D_CreateIcaStreamsForMode((struct ParticleManager *)WORK, 3);
    POKETRADE_3D_SetupParticleSystemsLow((struct ParticleManager *)WORK);
    POKETRADE_DEMO_UP_SetFrame(work, 0x2B5);
    POKETRADE_NEGO_PlaySeByKeyA(((PokeTradeDemoWork *)work)->frame);
    POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_DOWN_StepSetupParticles);
    BG_SYS_SetSubVisiblePlanes(0x18);
}

#undef WORK

#define WORK ((u32 *)((PokeTradeDemoWork *)work)->animWork)

/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_DOWN_StepSetupParticles(u8 *work)
{
    POKETRADE_NEGO_PlaySeByKeyA(((PokeTradeDemoWork *)work)->frame);
    POKETRADE_3D_SetupParticleSystemsHigh(((PokeTradeDemoWork *)work)->animWork);
    POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_DOWN_StepPlaySe);
}

void POKETRADE_DEMO_DOWN_StepPlaySe(u8 *work)
{
    POKETRADE_NEGO_PlaySeByKeyA(((PokeTradeDemoWork *)work)->frame);
    POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_DOWN_UpdateScene);
}

void POKETRADE_DEMO_DOWN_UpdateScene(u8 *work)
{
    Vec ownVec, peerVec, slideBeginVec, swapVec, leftMonVec, rightMonVec, exitVec, copyPosVec;

    POKETRADE_NEGO_PlaySeByKeyA(FRAME);
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(1)) {
        MCSS_SetPaletteFade(OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(2)) {
        MCSS_SetPaletteFade(OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(3)) {
        POKETRADE_DEMO_UP_LoadUnitResources(work);
        POKETRADE_DEMO_UP_CreateUnitActor(work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(4)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(work, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(work, 0x18);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(4)) {
        MCSS_SetVanishFlag(OBJ(0));
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback(WORK[0], 10, 0, work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x65)) {
        PARTICLE_StartEffectWithCallback(WORK[1], 1, 0, work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback(WORK[2], 2, 0, work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback(WORK[8], 2, 0, work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0xE)) {
        PARTICLE_StartEffectWithCallback(WORK[3], 3, 0, work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x483)) {
        PARTICLE_StartEffectWithCallback(WORK[7], 3, 0, work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback(WORK[4], 4, POKETRADE_DEMO_UP_SetupEmitterC, work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x152)) {
        PARTICLE_StartEffectWithCallback(WORK[5], 5, 0, work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x2BC)) {
        PARTICLE_StartEffectWithCallback(WORK[6], 6, POKETRADE_DEMO_UP_SetupEmitterD, work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x47F)) {
        POKETRADE_DEMO_UP_LoadUnitResources(work);
        POKETRADE_DEMO_UP_CreateUnitActor(work);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x10A)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_UP_PassThrough(0x14), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x12D)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_UP_PassThrough(0x19), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x14A)) {
        MCSS_ResetVanishFlag(OBJ(2));
        ownVec.x = -0x32000;
        ownVec.y = -0x96000;
        ownVec.z = 0xA000;
        MCSS_SetPosition(OBJ(2), (u32 *)(&ownVec));
        ownVec.x = -0x32000;
        ownVec.y = -0x37000;
        ownVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate((void *)(OBJ(2)), (void *)(POKETRADE_DEMO_UP_PassThrough(0xF)), &ownVec, HEAP);
        MCSS_SetAnmStopFlag(OBJ(2));
        MCSS_GetScale(OBJ(2), (u32 *)(&ownVec));
        ownVec.x *= 1.2;
        ownVec.y *= 1.2;
        MCSS_SetScale(OBJ(2), (u32 *)(&ownVec));
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x14B)) {
        MCSS_ResetVanishFlag(OBJ(3));
        peerVec.x = 0x3C000;
        peerVec.y = 0x50000;
        peerVec.z = -0xA000;
        MCSS_SetPosition(OBJ(3), (u32 *)(&peerVec));
        peerVec.x = 0x3C000;
        peerVec.y = 0x5000;
        peerVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate((void *)(OBJ(3)), (void *)(POKETRADE_DEMO_UP_PassThrough(0xF)), &peerVec, HEAP);
        MCSS_SetAnmStopFlag(OBJ(3));
        MCSS_GetScale(OBJ(3), (u32 *)(&peerVec));
        peerVec.x *= 1.2;
        peerVec.y *= 1.2;
        MCSS_SetScale(OBJ(3), (u32 *)(&peerVec));
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x154)) {
        slideBeginVec.x = -0x32000;
        slideBeginVec.y = -0x37000;
        slideBeginVec.z = 0xA000;
        POKETRADE_MCSS_SlideBegin(SLOT0, (void *)(POKETRADE_DEMO_UP_PassThrough(0x1C)), &slideBeginVec);
        slideBeginVec.x = 0x3C000;
        slideBeginVec.y = 0x5000;
        slideBeginVec.z = -0xA000;
        POKETRADE_MCSS_SlideBegin(SLOT1, (void *)(POKETRADE_DEMO_UP_PassThrough(0x1C)), &slideBeginVec);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x170)) {
        POKETRADE_DEMO_UP_DeleteSlide(work, 0);
        POKETRADE_DEMO_UP_DeleteSlide(work, 1);
        swapVec.x = -0x96000;
        swapVec.y = -0x37000;
        swapVec.z = 0;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate((void *)(OBJ(2)), (void *)(POKETRADE_DEMO_UP_PassThrough(0x2E)), &swapVec, HEAP);
        swapVec.x = 0x96000;
        swapVec.y = 0x5000;
        swapVec.z = 0;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate((void *)(OBJ(3)), (void *)(POKETRADE_DEMO_UP_PassThrough(0x2E)), &swapVec, HEAP);
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x1B2)) {
        GFL_HEAP_Free(SLOT0);
        SLOT0 = 0;
        MCSS_ResetVanishFlag(OBJ(0));
        MCSS_SetPaletteFade(OBJ(0), 0, 0, 0, 0x7FFF);
        leftMonVec.x = -0x96000;
        leftMonVec.y = 0x5000;
        leftMonVec.z = -0xA000;
        MCSS_SetPosition(OBJ(0), (u32 *)(&leftMonVec));
        leftMonVec.x = 0x3C000;
        leftMonVec.y = 0x5000;
        leftMonVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate((void *)(OBJ(0)), (void *)(POKETRADE_DEMO_UP_PassThrough(0x67)), &leftMonVec, HEAP);
        MCSS_GetScale(OBJ(0), (u32 *)(&leftMonVec));
        leftMonVec.x *= 1.2;
        leftMonVec.y *= 1.2;
        MCSS_SetScale(OBJ(0), (u32 *)(&leftMonVec));
        GFL_HEAP_Free(SLOT1);
        SLOT1 = 0;
        MCSS_ResetVanishFlag(OBJ(1));
        rightMonVec.x = 0x96000;
        rightMonVec.y = -0x37000;
        rightMonVec.z = 0xA000;
        MCSS_SetPosition(OBJ(1), (u32 *)(&rightMonVec));
        rightMonVec.x = -0x2D000;
        rightMonVec.y = -0x37000;
        rightMonVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate((void *)(OBJ(1)), (void *)(POKETRADE_DEMO_UP_PassThrough(0x67)), &rightMonVec, HEAP);
        MCSS_GetScale(OBJ(1), (u32 *)(&rightMonVec));
        rightMonVec.x *= 1.2;
        rightMonVec.y *= 1.2;
        MCSS_SetScale(OBJ(1), (u32 *)(&rightMonVec));
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x1F8)) {
        POKETRADE_MCSS_SlideBegin(SLOT0, (void *)(POKETRADE_DEMO_UP_PassThrough(0x80)), (u8 *)SLOT0 + 0x28);
        POKETRADE_MCSS_SlideBegin(SLOT1, (void *)(POKETRADE_DEMO_UP_PassThrough(0x80)), (u8 *)SLOT1 + 0x28);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x27D)) {
        POKETRADE_DEMO_UP_DeleteSlide(work, 0);
        POKETRADE_DEMO_UP_DeleteSlide(work, 1);
        exitVec.x = 0x3C000;
        exitVec.y = 0x64000;
        exitVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate((void *)(OBJ(0)), (void *)(POKETRADE_DEMO_UP_PassThrough(7)), &exitVec, HEAP);
        exitVec.x = -0x2D000;
        exitVec.y = -0xA0000;
        exitVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate((void *)(OBJ(1)), (void *)(POKETRADE_DEMO_UP_PassThrough(7)), &exitVec, HEAP);
    }
    POKETRADE_DEMO_UP_PassThrough(0x48B);
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x48B + 3)) {
        if (((PokeTradeDemoWork *)work)->ownSameMon == 0) {
            POKETRADE_DEMO_UP_ResetMonSlide(work, 3);
            POKETRADE_DEMO_UP_SetMonSlide(work, 3);
            MCSS_SetPaletteFade(OBJ(3), 0x10, 0x10, 0, 0x7FFF);
        } else {
            POKETRADE_DEMO_UP_ResetMonSlide(work, 3);
            MCSS_SetVanishFlag(OBJ(3));
            POKETRADE_DEMO_UP_ResetMonSlide(work, 1);
            POKETRADE_DEMO_UP_SetMonSlide(work, 3);
            MCSS_SetPaletteFade(OBJ(1), 0x10, 0x10, 0, 0x7FFF);
        }
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x48F)) {
        MCSS_SetPaletteFade(OBJ(3), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x490)) {
        MCSS_SetPaletteFade(OBJ(3), 0, 0, 0, 0x7FFF);
    }
    if (POKETRADE_DEMO_UP_PassThrough(0x48E) < FRAME && ((PokeTradeDemoWork *)work)->ownSameMon != 0 && *(u32 *)&((PokeTradeDemoWork *)work)->slidePtr != 0
        && *(u32 *)(*(u32 *)&((PokeTradeDemoWork *)work)->slidePtr + 8) == 9) {
        MCSS_GetPosition(OBJ(1), (u32 *)(&copyPosVec));
        MCSS_SetPosition(OBJ(3), (u32 *)(&copyPosVec));
        MCSS_ResetVanishFlag(OBJ(3));
        MCSS_SetVanishFlag(OBJ(1));
        *(void **)((PokeTradeDemoWork *)work)->slidePtr = OBJ(3);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x4A0)) {
        MCSS_ResetAnmStopFlag(OBJ(3));
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x28B)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_UP_PassThrough(0xA), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x2B5)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_UP_PassThrough(0x19), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x380)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_UP_PassThrough(0x1E), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x3CA)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_UP_PassThrough(0x1E), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x4C1)) {
        POKETRADE_DEMO_UP_DeleteSlide(work, 0);
        POKETRADE_DEMO_UP_DeleteSlide(work, 1);
        POKETRADE_3D_RemoveCurrentUnit(work);
        POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_UP_StepReleaseUnit);
    }
    POKETRADE_MCSS_SlideUpdate(SLOT0, work);
    POKETRADE_MCSS_SlideUpdate(SLOT1, work);
    POKETRADE_MCSS_SlideUpdate(((PokeTradeDemoWork *)work)->slideExtra, work);
    POKETRADE_MCSS_SlideUpdate(((PokeTradeDemoWork *)work)->slidePtr, work);
}

void POKETRADE_DEMO_DOWN_StepFade(s8 *fade)
{
    s32 value;

    if (fade == 0) {
        return;
    }
    if (fade[0] >= fade[1]) {
        fade[1]++;
        value = ((fade[3] - fade[2]) << 12) / fade[0];
        value = value * fade[1] / 4096;
        G2x_SetBlendBrightness_(0x04000050, 0x1E, value);
        G2x_SetBlendBrightness_(0x04001050, 0x1F, value);
    }
}

void POKETRADE_DEMO_DOWN_CompareSideMon(u8 *work, u8 *outSame, u8 *outFlag, u32 key, int enemy)
{
    int which;
    void *mon;
    u32 id;
    u32 a;
    u32 b;
    u32 egg;
    u32 h;
    u32 flag;

    if (enemy != 0) {
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            which = 1;
        } else {
            which = 0;
        }
    } else {
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            which = 0;
        } else {
            which = 1;
        }
    }
    mon = POKETRADE_PROC_GetSideMon(work, which);
    id = POKE_TOOL_GetPartyValue(mon, 7, 0);
    a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
    b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    egg = POKE_TOOL_GetPartyValue(mon, 0x4C, 0);
    if (egg == 0) {
        h = (u32)POKE_PERSONAL_Create((u16)a, (u16)b, ((PokeTradeDemoWork *)work)->heapId);
        flag = POKE_PERSONAL_GetParam((struct PersonalData *)h, 0x10);
        POKE_PERSONAL_Delete((void *)h);
    }
    if (egg != 0) {
        *outFlag = 1;
    } else if (flag != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (id != MYSTATUS_GetId((struct MyStatus *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}

void POKETRADE_DEMO_DOWN_CreateUnitActor(void *work)
{
    u32 v = (u32)((PokeTradeAnimWork *)((PokeTradeDemoWork *)work)->animWork)->actor;
    if (v == 0) {
        ClactActorPos s;
        s.x = 0x80;
        s.y = 0x63;
        s.animSeq = 0;
        s.drawPriority = 0;
        s.bgPriority = 0;
        ((PokeTradeAnimWork *)((PokeTradeDemoWork *)work)->animWork)->actor =
            (void *)CLACT_CreateActor((void *)((PokeTradeDemoWork *)work)->clactSystem,
                          ((PokeTradeDemoWork *)work)->characterHandle,
                          ((PokeTradeDemoWork *)work)->paletteHandle,
                          ((PokeTradeDemoWork *)work)->cellAnimHandle,
                          &s, 0, ((PokeTradeDemoWork *)work)->heapId);
        CLACT_SetActorAutoAnim((struct Actor *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)work)->animWork)->actor, 1);
        CLACT_SetActorDrawEnable((struct Actor *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)work)->animWork)->actor, 1);
    } else {
        CLACT_RestartActorAnim((struct Actor *)v);
    }
}

void POKETRADE_DEMO_DOWN_LoadUnitResources(void *work)
{
    void *h = ARC_TOOL_CreateHandle(0x67, ((PokeTradeDemoWork *)work)->heapId);
    ((PokeTradeDemoWork *)work)->characterHandle = CLACT_RegisterCharacter(h, 2, 0, 0, ((PokeTradeDemoWork *)work)->heapId);
    ((PokeTradeDemoWork *)work)->paletteHandle = CLACT_RegisterPaletteEx(h, 3, 0, 0xE0, 0, 1, ((PokeTradeDemoWork *)work)->heapId);
    ((PokeTradeDemoWork *)work)->cellAnimHandle = CLACT_RegisterCellAnim(h, 1, 0, ((PokeTradeDemoWork *)work)->heapId);
    ARC_TOOL_DeleteHandle(h);
    ((PokeTradeAnimWork *)((PokeTradeDemoWork *)work)->animWork)->actor = 0;
}

/*
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * POKETRADE_DEMO_DOWN_ReleaseUnit callers' targets; this is the first callee of POKETRADE_DEMO_MIDDLE_StepEndScene.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_DOWN_ReleaseUnit(void *work)
{
    u8 *b = work;

    if (((PokeTradeAnimWork *)((PokeTradeDemoWork *)b)->animWork)->actor != 0)
        CLACT_DeleteActor(((PokeTradeAnimWork *)((PokeTradeDemoWork *)b)->animWork)->actor);
    if (((PokeTradeDemoWork *)b)->characterHandle != 0) {
        CLACT_ReleaseCharacter((u32)((PokeTradeDemoWork *)b)->characterHandle);
        CLACT_ReleasePalette((u32)((PokeTradeDemoWork *)b)->paletteHandle);
        CLACT_ReleaseCellAnim((u32)((PokeTradeDemoWork *)b)->cellAnimHandle);
    }
    ((PokeTradeDemoWork *)b)->characterHandle = 0;
    ((PokeTradeDemoWork *)b)->paletteHandle = 0;
    ((PokeTradeDemoWork *)b)->cellAnimHandle = 0;
    ((PokeTradeAnimWork *)((PokeTradeDemoWork *)b)->animWork)->actor = 0;
}

int POKETRADE_DEMO_DOWN_PassThrough(int value) { return value; }

void POKETRADE_DEMO_DOWN_SetFrame(u8 *work, u32 frame) { ((PokeTradeDemoWork *)work)->frame = frame; }

void POKETRADE_DEMO_DOWN_SetFinishFlag(u8 *work) { ((PokeTradeDemoWork *)work)->finishFlag = 1; }

void POKETRADE_DEMO_DOWN_StepStartPlayback(u8 *work)
{
    POKETRADE_3D_FadeTexturePalette((char *)work);
    if (((PokeTradeDemoWork *)work)->sceneStarted == 1) {
        POKETRADE_DEMO_DOWN_CompareSideMon(work, work + 0x11ED, work + 0x11EF, ((PokeTradeDemoWork *)work)->enemyMonKey, 1);
        POKETRADE_DEMO_DOWN_CompareSideMon(work, work + 0x11EE, work + 0x11F0, ((PokeTradeDemoWork *)work)->ownMonKey, 0);
        POKETRADE_3D_RemoveCurrentUnit(work);
        if (POKETRADE_PROC_IsNetSession(work) != 0) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8);
            POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_DOWN_StepWaitSync);
        } else {
            POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_COMMON_StepBeginPlayback);
        }
    }
}

void POKETRADE_DEMO_DOWN_StepWaitSync(u8 *work)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8) != 0) {
        POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_COMMON_StepBeginPlayback);
    }
}
