/*
 * file:     pokemontrade_demo_down.c
 * unit:     yes
 * function: POKETRADE_DEMO_UP_CompareSideMon, POKETRADE_DEMO_UP_CreateUnitActor, POKETRADE_DEMO_UP_LoadUnitResources, POKETRADE_DEMO_UP_ReleaseUnit, POKETRADE_DEMO_UP_PassThrough, POKETRADE_DEMO_UP_SetFrame, POKETRADE_DEMO_UP_SetFinishFlag, POKETRADE_DEMO_UP_StepReleaseUnit, POKETRADE_DEMO_UP_DeleteSlide, POKETRADE_DEMO_UP_SetMonSlide, POKETRADE_DEMO_UP_ResetMonSlide, POKETRADE_DEMO_UP_UpdateEmitterC, POKETRADE_DEMO_UP_SetupEmitterC, POKETRADE_DEMO_UP_UpdateEmitterD, POKETRADE_DEMO_UP_SetupEmitterD, POKETRADE_DEMO_UP_StepStartDownScene, POKETRADE_DEMO_DOWN_StepSetup, POKETRADE_DEMO_DOWN_StepSetupParticles, POKETRADE_DEMO_DOWN_StepPlaySe, POKETRADE_DEMO_DOWN_UpdateScene, POKETRADE_DEMO_DOWN_StepFade, POKETRADE_DEMO_DOWN_CompareSideMon, POKETRADE_DEMO_DOWN_CreateUnitActor, POKETRADE_DEMO_DOWN_LoadUnitResources, POKETRADE_DEMO_DOWN_ReleaseUnit, POKETRADE_DEMO_DOWN_PassThrough, POKETRADE_DEMO_DOWN_SetFrame, POKETRADE_DEMO_DOWN_SetFinishFlag, POKETRADE_DEMO_DOWN_StepStartPlayback, POKETRADE_DEMO_DOWN_StepWaitSync
 * address:  0x021D54F0
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pokemontrade_demo_up.c by tools/splitfile.py.
 *
 * symbols:
 *   POKETRADE_MCSS_SlideUpdate  0x021DFC68  thumb  ov119
 *   POKETRADE_2D_ScheduleMainPlaneVisible  0x021E71F0  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   func_020307B0  0x020307B0  arm
 *   MCSS_GetPosition  0x02015C30  thumb
 *   POKETRADE_SAVE_FreeIfSet  0x021DFD24  thumb  ov119
 *   POKETRADE_MCSS_SlideCreateWithOffsets  0x021DFBB4  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssPlain  0x021E36C8  thumb  ov119
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   POKETRADE_3D_ExitParticleManager  0x021E3034  thumb  ov119
 *   POKETRADE_3D_FreeParticleResources  0x021E2F2C  thumb  ov119
 *   POKETRADE_SAVE_ResetClactAndBeginEvent  0x021DFDA0  thumb  ov119
 *   BUTTON_MAN_GetUserData 0x02051A34 arm
 *   ICA_ANIME_Get 0x02011610 thumb
 *   BUTTON_MAN_SetEmitterPos 0x02051838 arm
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   POKETRADE_PROC_DeleteAllResources  0x021DC720  thumb
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   POKETRADE_2D_InitClactSystemMain  0x021E3E40  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   func_02030734  0x02030734  arm
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
 *   func_02008530  0x02008530  thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   d_021D7CB4     0x021D7CB4  data
 *   d_021D7FEC     0x021D7FEC  data
 *   d_021D80C4     0x021D80C4  data
 *   d_021D8790     0x021D8790  data
 *   d_021D7CA8     0x021D7CA8  data
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   d_021D82A4  0x021D82A4  data
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   POKETRADE_3D_FadeTexturePalette  0x021E3BB0  thumb  ov119
 *   POKETRADE_PROC_IsNetSession  0x021D8A24  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   MCSS_SetAnimCallback  0x02015F2C  thumb
 *   POKETRADE_MCSS_StopAnimation  0x021DFD0C  thumb  ov119
 *   POKETRADE_SAVE_CloseMessageWindow  0x021E106C  thumb  ov119
 *   BG_SYS_LoadPlttEntry  0x02040EBC  arm
 *   POKETRADE_DEMO_COMMON_StepBeginPlayback  0x021D67F8  thumb  ov118
 *   POKETRADE_DEMO_MIDDLE_StepStartPlayback  0x021D6918  thumb  ov118
 *   d_021D8650     0x021D8650  data
 *   d_021D7CC4     0x021D7CC4  data
 *   d_021D7CD0     0x021D7CD0  data
 *   BUTTON_MAN_SetCallback  0x02051A24  arm  arm9
 *   BUTTON_MAN_SetUserData  0x02051A2C  arm  arm9
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 */
#include "pokemontrade_demo_types.h"
#include "pokemontrade_demo_up_shared_types.h"

#define FADE (((PokeTradeDemoWork *)p)->fade)

struct Personal;

struct Sub0200852CObj;

struct Obj;

struct Actor;

struct Entry;

struct Link;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ClactActorPos;

typedef struct {
    u32 v[4];
} Quad;

extern void POKETRADE_MCSS_SlideUpdate(void *p, void *a1);

extern void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);

extern void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);

extern int POKETRADE_PROC_IsHostSide(void *);

extern void *POKETRADE_PROC_GetSideMon(void *, int);

extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);

extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

extern u32 func_020307B0(void *p);

extern void MCSS_GetPosition(void *p, Vec *out);

extern void POKETRADE_SAVE_FreeIfSet(void *p);

extern void *POKETRADE_MCSS_SlideCreateWithOffsets(void *a0, void *a1, void *a2, void *a3, u16 heapId);

extern void POKETRADE_3D_AddPokemonMcssPlain(void *p, int a, int b, void *mon, int c);

extern void MCSS_SetAnmStopFlag(void *p);

extern void MCSS_SetVanishFlag(void *p);

extern void POKETRADE_PROC_SetStep(void *p, int next);

extern void MCSS_SetPosition(void *p, Vec *src);

extern void MCSS_ResetVanishFlag(void *p);

extern void MCSS_ResetAnmStopFlag(void *p);

extern void POKETRADE_3D_ExitParticleManager(u32 *p, int a1);

extern void POKETRADE_3D_FreeParticleResources(void *);

extern void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p);

extern int BUTTON_MAN_GetUserData(void *p);

extern unsigned int ICA_ANIME_Get(struct IcaAnime *p, struct Rec12 *dst);

extern void BUTTON_MAN_SetEmitterPos(void *, Vec *);

extern u32 func_02051774(void);

extern void BUTTON_MAN_SetUserData(void *p, int v);

extern void BUTTON_MAN_SetCallback(void *p, int v);

extern void MCSS_SetAnimeIndex(void *a, u32 flag);

extern void POKETRADE_PROC_DeleteAllResources(void *p);

extern void CLACT_ExitSystem(void);

extern void POKETRADE_2D_InitClactSystemMain(void *p);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void POKETRADE_2D_SetupSummaryBgs(void *p, int a);

extern void POKETRADE_3D_AddUnitAndInit(void *p, int a);

extern void POKETRADE_3D_InitParticleSystems(void *w);

extern void POKETRADE_3D_SetupParticleSystemsLow(char *p);

extern void POKETRADE_3D_CreateIcaStreamsForMode(void *w, int a);

extern void POKETRADE_3D_SetupParticleSystemsHigh(char *p);

extern void POKETRADE_3D_RemoveCurrentUnit(void *p);

extern void MCSS_SetPaletteFade(void *, u32, u32, s32, u32);

extern void MCSS_GetScale(void *, Vec *);

extern void MCSS_SetScale(void *, Vec *);

extern int PARTICLE_StartEffectWithCallback(u32, int, void *, void *);

extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

extern void *POKETRADE_MCSS_SlideCreate(void *, int, Vec *, u32);

extern void POKETRADE_NEGO_PlaySeByKeyA(u32 key);

extern void POKETRADE_MCSS_SlideBegin(void *, int, void *);

extern void *POKE_PERSONAL_Create(u32 a, int b, u32 heap);

extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);

extern void POKE_PERSONAL_Delete(void *p);

extern u32 func_02008530(const struct Sub0200852CObj *obj);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);

extern void CLACT_SetActorAutoAnim(struct Obj *, u32);

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

extern void CLACT_RestartActorAnim(struct Actor *a);

extern void *func_020490F4(u32 id, u32 heap);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void ARC_TOOL_DeleteHandle(void *);

extern void CLACT_DeleteActor(struct Obj *p);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void BG_SYS_SetSubVisiblePlanes(u32 planes);

extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);

extern void POKETRADE_3D_FadeTexturePalette(char *p);

extern int POKETRADE_PROC_IsNetSession(void *p);

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *h, u32 a, u32 b);

extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, u32 a, u32 b);

extern void MCSS_SetAnimCallback(void *obj, void *arg, void (*cb)(void), int a);

extern void POKETRADE_MCSS_StopAnimation(char *p);

extern void POKETRADE_SAVE_CloseMessageWindow(char *p);

extern void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);

extern void POKETRADE_DEMO_MIDDLE_StepStartPlayback(u8 *p);

void POKETRADE_DEMO_UP_CompareSideMon(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);

void POKETRADE_DEMO_UP_CreateUnitActor(void *p);

void POKETRADE_DEMO_UP_LoadUnitResources(void *p);

void POKETRADE_DEMO_UP_ReleaseUnit(void *p);

int POKETRADE_DEMO_UP_PassThrough(int a);

void POKETRADE_DEMO_UP_SetFrame(u8 *p, u32 v);

void POKETRADE_DEMO_UP_SetFinishFlag(u8 *p);

void POKETRADE_DEMO_UP_StepReleaseUnit(void *p);

void POKETRADE_DEMO_UP_DeleteSlide(u8 *p, int idx);

void POKETRADE_DEMO_UP_SetMonSlide(u8 *p, int idx);

void POKETRADE_DEMO_UP_ResetMonSlide(u8 *p, int idx);

void POKETRADE_DEMO_UP_UpdateEmitterC(void *obj, int on);

void POKETRADE_DEMO_UP_SetupEmitterC(void *p);

void POKETRADE_DEMO_UP_UpdateEmitterD(void *obj, int on);

void POKETRADE_DEMO_UP_SetupEmitterD(void *p);

void POKETRADE_DEMO_UP_StepStartDownScene(u8 *p);

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

extern const Quad d_021D7CB4;

extern const u8 d_021D7FEC[];

extern const u8 d_021D80C4[];

extern u8 d_021D8790[];

extern const Vec d_021D7CA8;

extern const char d_021D82A4[];

extern const char d_021D8650[];

extern const Vec d_021D7CC4;

extern const Vec d_021D7CD0;

void POKETRADE_DEMO_UP_CompareSideMon(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy)
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
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            which = 1;
        } else {
            which = 0;
        }
    } else {
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            which = 0;
        } else {
            which = 1;
        }
    }
    mon = POKETRADE_PROC_GetSideMon(p, which);
    id = POKE_TOOL_GetPartyValue(mon, 7, 0);
    a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
    b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    egg = POKE_TOOL_GetPartyValue(mon, 0x4C, 0);
    if (egg == 0) {
        h = (u32)POKE_PERSONAL_Create((u16)a, (u16)b, ((PokeTradeDemoWork *)p)->heapId);
        flag = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x10);
        POKE_PERSONAL_Delete((void *)h);
    }
    if (egg != 0) {
        *outFlag = 1;
    } else if (flag != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (id != func_02008530((const struct Sub0200852CObj *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}

void POKETRADE_DEMO_UP_CreateUnitActor(void *p)
{
    u32 v = (u32)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor;
    if (v == 0) {
        ClactActorPos s;
        s.x = 0x80;
        s.y = 0x63;
        s.z = 0;
        s.pri = 0;
        s.f7 = 0;
        ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor =
            (void *)CLACT_CreateActor((void *)((PokeTradeDemoWork *)p)->clactSystem,
                          ((PokeTradeDemoWork *)p)->characterHandle,
                          ((PokeTradeDemoWork *)p)->paletteHandle,
                          ((PokeTradeDemoWork *)p)->cellAnimHandle,
                          &s, 0, ((PokeTradeDemoWork *)p)->heapId);
        CLACT_SetActorAutoAnim((struct Obj *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor, 1);
        CLACT_SetActorDrawEnable((struct Obj *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor, 1);
    } else {
        CLACT_RestartActorAnim((struct Actor *)v);
    }
}

void POKETRADE_DEMO_UP_LoadUnitResources(void *p)
{
    void *h = func_020490F4(0x67, ((PokeTradeDemoWork *)p)->heapId);
    ((PokeTradeDemoWork *)p)->characterHandle = CLACT_RegisterCharacter(h, 2, 0, 0, ((PokeTradeDemoWork *)p)->heapId);
    ((PokeTradeDemoWork *)p)->paletteHandle = CLACT_RegisterPaletteEx(h, 3, 0, 0xE0, 0, 1, ((PokeTradeDemoWork *)p)->heapId);
    ((PokeTradeDemoWork *)p)->cellAnimHandle = CLACT_RegisterCellAnim(h, 1, 0, ((PokeTradeDemoWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(h);
    ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor = 0;
}

/*
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * POKETRADE_DEMO_UP_ReleaseUnit callers' targets; this is the first callee of POKETRADE_DEMO_MIDDLE_StepEndScene.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_UP_ReleaseUnit(void *p)
{
    u8 *b = p;

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

int POKETRADE_DEMO_UP_PassThrough(int a) { return a; }

void POKETRADE_DEMO_UP_SetFrame(u8 *p, u32 v) { ((PokeTradeDemoWork *)p)->frame = v; }

void POKETRADE_DEMO_UP_SetFinishFlag(u8 *p) { ((PokeTradeDemoWork *)p)->finishFlag = 1; }

void POKETRADE_DEMO_UP_StepReleaseUnit(void *p)
{
    POKETRADE_DEMO_UP_ReleaseUnit(p);
    POKETRADE_3D_ExitParticleManager(((PokeTradeDemoWork *)p)->animWork, 6);
    POKETRADE_3D_FreeParticleResources(((PokeTradeDemoWork *)p)->animWork);
    func_020307B0(((PokeTradeDemoWork *)p)->animWork);
    ((PokeTradeDemoWork *)p)->animWork = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_ResetClactAndBeginEvent);
}

void POKETRADE_DEMO_UP_DeleteSlide(u8 *p, int idx)
{
    if (((PokeTradeDemoWork *)p)->slideOwn != 0) {
        func_020307B0(((PokeTradeDemoWork *)p)->slideOwn);
        ((PokeTradeDemoWork *)p)->slideOwn = 0;
    }
}

#define WORK ((u8 *)((PokeTradeDemoWork *)p)->animWork)

/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_UP_SetMonSlide(u8 *p, int idx)
{
    void *x;
    Vec buf;

    x = POKETRADE_PROC_GetSideMon(p, 1 - POKETRADE_PROC_IsHostSide(p));
    POKE_TOOL_GetPartyValue(x, 7, 0);
    if (POKE_TOOL_GetPartyValue(x, 0x4c, 0) == 0) {
        PM_VOICE_Play(POKE_TOOL_GetPartyValue(x, 0xab, 0), POKE_TOOL_GetPartyValue(x, 0x6f, 0), 0x40, 0, 0, 0, 0, 0);
    }
    if (((PokeTradeDemoWork *)p)->ownSameMon == 0) {
        MCSS_GetPosition(((void **)(p + 0x844))[idx], &buf);
        POKETRADE_SAVE_FreeIfSet(((PokeTradeDemoWork *)p)->slidePtr);
        if (((PokeTradeDemoWork *)p)->ownSpecialMon != 0) {
            ((PokeTradeDemoWork *)p)->slidePtr = POKETRADE_MCSS_SlideCreateWithOffsets(((void **)(p + 0x844))[idx], (void *)0x14, &buf, d_021D8790, ((PokeTradeDemoWork *)p)->heapId);
        } else {
            ((PokeTradeDemoWork *)p)->slidePtr = POKETRADE_MCSS_SlideCreateWithOffsets(((void **)(p + 0x844))[idx], (void *)0x28, &buf, (void *)d_021D80C4, ((PokeTradeDemoWork *)p)->heapId);
        }
    } else {
        Quad t = d_021D7CB4;
        void *obj = ((PokeTradeDemoWork *)p)->mcssObj[t.v[idx]];
        MCSS_GetPosition(((void **)(p + 0x844))[idx], &buf);
        POKETRADE_SAVE_FreeIfSet(((PokeTradeDemoWork *)p)->slidePtr);
        if (((PokeTradeDemoWork *)p)->ownSpecialMon != 0) {
            ((PokeTradeDemoWork *)p)->slidePtr = POKETRADE_MCSS_SlideCreateWithOffsets(obj, (void *)0x14, &buf, d_021D8790, ((PokeTradeDemoWork *)p)->heapId);
        } else {
            ((PokeTradeDemoWork *)p)->slidePtr = POKETRADE_MCSS_SlideCreateWithOffsets(obj, (void *)0x12, &buf, (void *)d_021D7FEC, ((PokeTradeDemoWork *)p)->heapId);
        }
    }
}

void POKETRADE_DEMO_UP_ResetMonSlide(u8 *p, int idx)
{
    void **obj = ((PokeTradeDemoWork *)p)->mcssObj;
    Vec v;

    MCSS_ResetVanishFlag((void *)obj[idx]);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xA000;
    MCSS_SetPosition((void *)obj[idx], &v);
    MCSS_SetAnmStopFlag((void *)obj[idx]);
    MCSS_GetScale((void *)obj[idx], &v);
    if (v.x < 0) {
        v.x = -0x10000;
    } else {
        v.x = 0x10000;
    }
    v.y = 0x10000;
    v.z = 0x1000;
    MCSS_SetScale((void *)obj[idx], &v);
}

void POKETRADE_DEMO_UP_UpdateEmitterC(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((PokeTradeButtonData *)w)->anim->anime != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_Get(((PokeTradeButtonData *)w)->anim->anime, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}

void POKETRADE_DEMO_UP_SetupEmitterC(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)POKETRADE_DEMO_UP_UpdateEmitterC);
}

void POKETRADE_DEMO_UP_UpdateEmitterD(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((PokeTradeButtonData *)w)->anim->animeB != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_Get(((PokeTradeButtonData *)w)->anim->animeB, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}

void POKETRADE_DEMO_UP_SetupEmitterD(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)POKETRADE_DEMO_UP_UpdateEmitterD);
}

void POKETRADE_DEMO_UP_StepStartDownScene(u8 *p)
{
    POKETRADE_DEMO_UP_SetFinishFlag(p);
    ((PokeTradeDemoWork *)p)->sceneStarted = 1;
    MCSS_SetAnimeIndex((void *)(((PokeTradeDemoWork *)p)->mcssObj[0]), 0);
    MCSS_SetVanishFlag((void *)(((PokeTradeDemoWork *)p)->mcssObj[0]));
    MCSS_SetVanishFlag((void *)(((PokeTradeDemoWork *)p)->mcssObj[1]));
    if (((PokeTradeDemoWork *)p)->sceneMode == 6) {
        Vec v = d_021D7CA8;
        MCSS_SetPosition((void *)(((PokeTradeDemoWork *)p)->mcssObj[0]), &v);
    }
    POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
    POKETRADE_2D_ScheduleSubPlaneVisible(p, 0);
    POKETRADE_DEMO_UP_CompareSideMon(p, p + 0x11ED, p + 0x11EF, ((PokeTradeDemoWork *)p)->enemyMonKey, 1);
    POKETRADE_DEMO_UP_CompareSideMon(p, p + 0x11EE, p + 0x11F0, ((PokeTradeDemoWork *)p)->ownMonKey, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_DOWN_StepSetup);
}

void POKETRADE_DEMO_DOWN_StepSetup(u8 *p)
{
    POKETRADE_PROC_DeleteAllResources(p);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain(p);
    ((PokeTradeDemoWork *)p)->clactSystem = (int)CLACT_CreateUnit(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D82A4, 0xA8);
    *(u16 *)(WORK + 0xBA) = HEAP;
    POKETRADE_2D_SetupSummaryBgs(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    POKETRADE_3D_AddUnitAndInit(p, 5);
    POKETRADE_3D_AddPokemonMcssPlain(p, 1, 0, POKETRADE_PROC_GetSideMon(p, 1), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, 0), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 3, 1, POKETRADE_PROC_GetSideMon(p, 1), 1);
    MCSS_SetVanishFlag(OBJ(0));
    MCSS_SetVanishFlag(OBJ(1));
    MCSS_SetVanishFlag(OBJ(2));
    MCSS_SetVanishFlag(OBJ(3));
    POKETRADE_3D_InitParticleSystems(WORK);
    POKETRADE_3D_CreateIcaStreamsForMode(WORK, 3);
    POKETRADE_3D_SetupParticleSystemsLow((char *)WORK);
    POKETRADE_DEMO_UP_SetFrame(p, 0x2B5);
    POKETRADE_NEGO_PlaySeByKeyA(((PokeTradeDemoWork *)p)->frame);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_DOWN_StepSetupParticles);
    BG_SYS_SetSubVisiblePlanes(0x18);
}

#undef WORK

#undef WORK

#define WORK ((u32 *)((PokeTradeDemoWork *)p)->animWork)

/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_DOWN_StepSetupParticles(u8 *p)
{
    POKETRADE_NEGO_PlaySeByKeyA(((PokeTradeDemoWork *)p)->frame);
    POKETRADE_3D_SetupParticleSystemsHigh(((PokeTradeDemoWork *)p)->animWork);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_DOWN_StepPlaySe);
}

void POKETRADE_DEMO_DOWN_StepPlaySe(u8 *p)
{
    POKETRADE_NEGO_PlaySeByKeyA(((PokeTradeDemoWork *)p)->frame);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_DOWN_UpdateScene);
}

void POKETRADE_DEMO_DOWN_UpdateScene(u8 *p)
{
    Vec v1, v2, v3, v4, v5, v6, v7, v8;

    POKETRADE_NEGO_PlaySeByKeyA(FRAME);
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(1)) {
        MCSS_SetPaletteFade(OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(2)) {
        MCSS_SetPaletteFade(OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(3)) {
        POKETRADE_DEMO_UP_LoadUnitResources(p);
        POKETRADE_DEMO_UP_CreateUnitActor(p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(4)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x18);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(4)) {
        MCSS_SetVanishFlag(OBJ(0));
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback(WORK[0], 10, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x65)) {
        PARTICLE_StartEffectWithCallback(WORK[1], 1, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback(WORK[2], 2, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback(WORK[8], 2, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0xE)) {
        PARTICLE_StartEffectWithCallback(WORK[3], 3, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x483)) {
        PARTICLE_StartEffectWithCallback(WORK[7], 3, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback(WORK[4], 4, POKETRADE_DEMO_UP_SetupEmitterC, p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x152)) {
        PARTICLE_StartEffectWithCallback(WORK[5], 5, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x2BC)) {
        PARTICLE_StartEffectWithCallback(WORK[6], 6, POKETRADE_DEMO_UP_SetupEmitterD, p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x47F)) {
        POKETRADE_DEMO_UP_LoadUnitResources(p);
        POKETRADE_DEMO_UP_CreateUnitActor(p);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x10A)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_UP_PassThrough(0x14), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x12D)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_UP_PassThrough(0x19), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x14A)) {
        MCSS_ResetVanishFlag(OBJ(2));
        v1.x = -0x32000;
        v1.y = -0x96000;
        v1.z = 0xA000;
        MCSS_SetPosition(OBJ(2), &v1);
        v1.x = -0x32000;
        v1.y = -0x37000;
        v1.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(2), POKETRADE_DEMO_UP_PassThrough(0xF), &v1, HEAP);
        MCSS_SetAnmStopFlag(OBJ(2));
        MCSS_GetScale(OBJ(2), &v1);
        v1.x *= 1.2;
        v1.y *= 1.2;
        MCSS_SetScale(OBJ(2), &v1);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x14B)) {
        MCSS_ResetVanishFlag(OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x50000;
        v2.z = -0xA000;
        MCSS_SetPosition(OBJ(3), &v2);
        v2.x = 0x3C000;
        v2.y = 0x5000;
        v2.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(3), POKETRADE_DEMO_UP_PassThrough(0xF), &v2, HEAP);
        MCSS_SetAnmStopFlag(OBJ(3));
        MCSS_GetScale(OBJ(3), &v2);
        v2.x *= 1.2;
        v2.y *= 1.2;
        MCSS_SetScale(OBJ(3), &v2);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x154)) {
        v3.x = -0x32000;
        v3.y = -0x37000;
        v3.z = 0xA000;
        POKETRADE_MCSS_SlideBegin(SLOT0, POKETRADE_DEMO_UP_PassThrough(0x1C), &v3);
        v3.x = 0x3C000;
        v3.y = 0x5000;
        v3.z = -0xA000;
        POKETRADE_MCSS_SlideBegin(SLOT1, POKETRADE_DEMO_UP_PassThrough(0x1C), &v3);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x170)) {
        POKETRADE_DEMO_UP_DeleteSlide(p, 0);
        POKETRADE_DEMO_UP_DeleteSlide(p, 1);
        v4.x = -0x96000;
        v4.y = -0x37000;
        v4.z = 0;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(2), POKETRADE_DEMO_UP_PassThrough(0x2E), &v4, HEAP);
        v4.x = 0x96000;
        v4.y = 0x5000;
        v4.z = 0;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(3), POKETRADE_DEMO_UP_PassThrough(0x2E), &v4, HEAP);
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x1B2)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        MCSS_ResetVanishFlag(OBJ(0));
        MCSS_SetPaletteFade(OBJ(0), 0, 0, 0, 0x7FFF);
        v5.x = -0x96000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        MCSS_SetPosition(OBJ(0), &v5);
        v5.x = 0x3C000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(0), POKETRADE_DEMO_UP_PassThrough(0x67), &v5, HEAP);
        MCSS_GetScale(OBJ(0), &v5);
        v5.x *= 1.2;
        v5.y *= 1.2;
        MCSS_SetScale(OBJ(0), &v5);
        func_020307B0(SLOT1);
        SLOT1 = 0;
        MCSS_ResetVanishFlag(OBJ(1));
        v6.x = 0x96000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        MCSS_SetPosition(OBJ(1), &v6);
        v6.x = -0x2D000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(1), POKETRADE_DEMO_UP_PassThrough(0x67), &v6, HEAP);
        MCSS_GetScale(OBJ(1), &v6);
        v6.x *= 1.2;
        v6.y *= 1.2;
        MCSS_SetScale(OBJ(1), &v6);
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x1F8)) {
        POKETRADE_MCSS_SlideBegin(SLOT0, POKETRADE_DEMO_UP_PassThrough(0x80), (u8 *)SLOT0 + 0x28);
        POKETRADE_MCSS_SlideBegin(SLOT1, POKETRADE_DEMO_UP_PassThrough(0x80), (u8 *)SLOT1 + 0x28);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x27D)) {
        POKETRADE_DEMO_UP_DeleteSlide(p, 0);
        POKETRADE_DEMO_UP_DeleteSlide(p, 1);
        v7.x = 0x3C000;
        v7.y = 0x64000;
        v7.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(0), POKETRADE_DEMO_UP_PassThrough(7), &v7, HEAP);
        v7.x = -0x2D000;
        v7.y = -0xA0000;
        v7.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(1), POKETRADE_DEMO_UP_PassThrough(7), &v7, HEAP);
    }
    POKETRADE_DEMO_UP_PassThrough(0x48B);
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x48B + 3)) {
        if (((PokeTradeDemoWork *)p)->ownSameMon == 0) {
            POKETRADE_DEMO_UP_ResetMonSlide(p, 3);
            POKETRADE_DEMO_UP_SetMonSlide(p, 3);
            MCSS_SetPaletteFade(OBJ(3), 0x10, 0x10, 0, 0x7FFF);
        } else {
            POKETRADE_DEMO_UP_ResetMonSlide(p, 3);
            MCSS_SetVanishFlag(OBJ(3));
            POKETRADE_DEMO_UP_ResetMonSlide(p, 1);
            POKETRADE_DEMO_UP_SetMonSlide(p, 3);
            MCSS_SetPaletteFade(OBJ(1), 0x10, 0x10, 0, 0x7FFF);
        }
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x48F)) {
        MCSS_SetPaletteFade(OBJ(3), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == POKETRADE_DEMO_UP_PassThrough(0x490)) {
        MCSS_SetPaletteFade(OBJ(3), 0, 0, 0, 0x7FFF);
    }
    if (POKETRADE_DEMO_UP_PassThrough(0x48E) < FRAME && ((PokeTradeDemoWork *)p)->ownSameMon != 0 && *(u32 *)&((PokeTradeDemoWork *)p)->slidePtr != 0
        && *(u32 *)(*(u32 *)&((PokeTradeDemoWork *)p)->slidePtr + 8) == 9) {
        MCSS_GetPosition(OBJ(1), &v8);
        MCSS_SetPosition(OBJ(3), &v8);
        MCSS_ResetVanishFlag(OBJ(3));
        MCSS_SetVanishFlag(OBJ(1));
        *(void **)((PokeTradeDemoWork *)p)->slidePtr = OBJ(3);
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
        POKETRADE_DEMO_UP_DeleteSlide(p, 0);
        POKETRADE_DEMO_UP_DeleteSlide(p, 1);
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_StepReleaseUnit);
    }
    POKETRADE_MCSS_SlideUpdate(SLOT0, p);
    POKETRADE_MCSS_SlideUpdate(SLOT1, p);
    POKETRADE_MCSS_SlideUpdate(((PokeTradeDemoWork *)p)->slideExtra, p);
    POKETRADE_MCSS_SlideUpdate(((PokeTradeDemoWork *)p)->slidePtr, p);
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

void POKETRADE_DEMO_DOWN_CompareSideMon(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy)
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
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            which = 1;
        } else {
            which = 0;
        }
    } else {
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            which = 0;
        } else {
            which = 1;
        }
    }
    mon = POKETRADE_PROC_GetSideMon(p, which);
    id = POKE_TOOL_GetPartyValue(mon, 7, 0);
    a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
    b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    egg = POKE_TOOL_GetPartyValue(mon, 0x4C, 0);
    if (egg == 0) {
        h = (u32)POKE_PERSONAL_Create((u16)a, (u16)b, ((PokeTradeDemoWork *)p)->heapId);
        flag = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x10);
        POKE_PERSONAL_Delete((void *)h);
    }
    if (egg != 0) {
        *outFlag = 1;
    } else if (flag != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (id != func_02008530((const struct Sub0200852CObj *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}

void POKETRADE_DEMO_DOWN_CreateUnitActor(void *p)
{
    u32 v = (u32)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor;
    if (v == 0) {
        ClactActorPos s;
        s.x = 0x80;
        s.y = 0x63;
        s.z = 0;
        s.pri = 0;
        s.f7 = 0;
        ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor =
            (void *)CLACT_CreateActor((void *)((PokeTradeDemoWork *)p)->clactSystem,
                          ((PokeTradeDemoWork *)p)->characterHandle,
                          ((PokeTradeDemoWork *)p)->paletteHandle,
                          ((PokeTradeDemoWork *)p)->cellAnimHandle,
                          &s, 0, ((PokeTradeDemoWork *)p)->heapId);
        CLACT_SetActorAutoAnim((struct Obj *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor, 1);
        CLACT_SetActorDrawEnable((struct Obj *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor, 1);
    } else {
        CLACT_RestartActorAnim((struct Actor *)v);
    }
}

void POKETRADE_DEMO_DOWN_LoadUnitResources(void *p)
{
    void *h = func_020490F4(0x67, ((PokeTradeDemoWork *)p)->heapId);
    ((PokeTradeDemoWork *)p)->characterHandle = CLACT_RegisterCharacter(h, 2, 0, 0, ((PokeTradeDemoWork *)p)->heapId);
    ((PokeTradeDemoWork *)p)->paletteHandle = CLACT_RegisterPaletteEx(h, 3, 0, 0xE0, 0, 1, ((PokeTradeDemoWork *)p)->heapId);
    ((PokeTradeDemoWork *)p)->cellAnimHandle = CLACT_RegisterCellAnim(h, 1, 0, ((PokeTradeDemoWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(h);
    ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor = 0;
}

/*
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * POKETRADE_DEMO_DOWN_ReleaseUnit callers' targets; this is the first callee of POKETRADE_DEMO_MIDDLE_StepEndScene.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_DOWN_ReleaseUnit(void *p)
{
    u8 *b = p;

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

int POKETRADE_DEMO_DOWN_PassThrough(int a) { return a; }

void POKETRADE_DEMO_DOWN_SetFrame(u8 *p, u32 v) { ((PokeTradeDemoWork *)p)->frame = v; }

void POKETRADE_DEMO_DOWN_SetFinishFlag(u8 *p) { ((PokeTradeDemoWork *)p)->finishFlag = 1; }

void POKETRADE_DEMO_DOWN_StepStartPlayback(u8 *p)
{
    POKETRADE_3D_FadeTexturePalette((char *)p);
    if (((PokeTradeDemoWork *)p)->sceneStarted == 1) {
        POKETRADE_DEMO_DOWN_CompareSideMon(p, p + 0x11ED, p + 0x11EF, ((PokeTradeDemoWork *)p)->enemyMonKey, 1);
        POKETRADE_DEMO_DOWN_CompareSideMon(p, p + 0x11EE, p + 0x11F0, ((PokeTradeDemoWork *)p)->ownMonKey, 0);
        POKETRADE_3D_RemoveCurrentUnit(p);
        if (POKETRADE_PROC_IsNetSession(p) != 0) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8);
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_DOWN_StepWaitSync);
        } else {
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_COMMON_StepBeginPlayback);
        }
    }
}

void POKETRADE_DEMO_DOWN_StepWaitSync(u8 *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8) != 0) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_COMMON_StepBeginPlayback);
    }
}
