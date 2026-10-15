/*
 * file:     pokemontrade_demo_up.c
 * unit:     yes
 * function: POKETRADE_DEMO_UP_StepStartPlayback, POKETRADE_DEMO_UP_PrintMessage, POKETRADE_DEMO_UP_StepMessage, POKETRADE_DEMO_UP_StepEndScene, POKETRADE_DEMO_UP_UpdateEmitterA, POKETRADE_DEMO_UP_SetupEmitterA, POKETRADE_DEMO_UP_UpdateEmitterB, POKETRADE_DEMO_UP_SetupEmitterB, POKETRADE_DEMO_UP_StepStartCompare, POKETRADE_DEMO_UP_StepSetup, POKETRADE_DEMO_UP_StepParticleSystems, POKETRADE_DEMO_UP_StepAddUnit, POKETRADE_DEMO_UP_UpdateScene
 * address:  0x021D4664
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
 *   POKETRADE_DEMO_COMMON_StepFade  0x021D4240  thumb  ov118
 *   POKETRADE_MCSS_SlideUpdate  0x021DFC68  thumb  ov119
 *   POKETRADE_DEMO_COMMON_PassThrough  0x021D4480  thumb  ov118
 *   POKETRADE_2D_ScheduleMainPlaneVisible  0x021E71F0  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *   POKETRADE_2D_DeleteAllOfferIconActors  0x021E64B8  thumb  ov119
 *   POKETRADE_2D_DeleteAllBoxIcons  0x021E4888  thumb  ov119
 *   POKETRADE_SAVE_DeleteOfferListWindows  0x021E2680  thumb  ov119
 *   POKETRADE_DEMO_COMMON_SetFrame  0x021D4484  thumb  ov118
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   func_02017E1C  0x02017E1C  thumb
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   func_020307B0  0x020307B0  arm
 *   MCSS_GetPosition  0x02015C30  thumb
 *   POKETRADE_SAVE_FreeIfSet  0x021DFD24  thumb  ov119
 *   POKETRADE_MCSS_SlideCreateWithOffsets  0x021DFBB4  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssPlain  0x021E36C8  thumb  ov119
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   d_021D7D00     0x021D7D00  data
 *   d_021D7DD8     0x021D7DD8  data
 *   d_021D86A0     0x021D86A0  data
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   WORDSET_SetSlotMonSpecies  0x0201EEF4  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   POKETRADE_SAVE_OpenMessageWindowAtPos  0x021E0FF4  thumb  ov119
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   POKETRADE_SAVE_IsMessagePrintDone  0x021E12AC  thumb  ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear  0x021E1098  thumb  ov119
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_DEMO_COMMON_ReleaseUnit  0x021D4434  thumb  ov118
 *   POKETRADE_3D_ExitParticleManager  0x021E3034  thumb  ov119
 *   POKETRADE_3D_FreeParticleResources  0x021E2F2C  thumb  ov119
 *   POKETRADE_SAVE_ResetClactAndBeginEvent  0x021DFDA0  thumb  ov119
 *   BUTTON_MAN_GetUserData 0x02051A34 arm
 *   ICA_ANIME_Get 0x02011610 thumb
 *   BUTTON_MAN_SetEmitterPos 0x02051838 arm
 *   POKETRADE_DEMO_COMMON_SetFinishFlag  0x021D4490  thumb  ov118
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   POKETRADE_DEMO_COMMON_StepCompareMons  0x021D449C  thumb  ov118
 *   d_021D7C90     0x021D7C90  data
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
 *   d_021D7FD4  0x021D7FD4  data
 *   POKETRADE_3D_SetupParticleSystemsHigh  0x021E3004  thumb  ov119
 *   POKETRADE_3D_RemoveCurrentUnit  0x021E3230  thumb  ov119
 *   POKETRADE_DEMO_COMMON_ShowUnitActor  0x021D434C  thumb  ov118
 *   POKETRADE_DEMO_COMMON_LoadUnitResources  0x021D43C8  thumb  ov118
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   PARTICLE_StartEffectWithCallback  0x020515CC  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   POKETRADE_MCSS_SlideCreate  0x021DFB84  thumb  ov119
 *   POKETRADE_NEGO_PlaySeByKeyA  0x021DFA60  thumb  ov119
 *   POKETRADE_MCSS_SlideBegin  0x021DFB4C  thumb  ov119
 *   BUTTON_MAN_SetCallback  0x02051A24  arm  arm9
 *   BUTTON_MAN_SetUserData  0x02051A2C  arm  arm9
 */
#include "pokemontrade_demo_types.h"
#include "pokemontrade_demo_up_shared_types.h"

struct WordSet;

struct MsgBank;

extern void POKETRADE_DEMO_COMMON_StepFade(s8 *fade);

extern void POKETRADE_MCSS_SlideUpdate(void *p, void *a1);

extern int POKETRADE_DEMO_COMMON_PassThrough(int);

extern void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);

extern void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);

extern void POKETRADE_2D_DeleteAllOfferIconActors(void *p);

extern void POKETRADE_2D_DeleteAllBoxIcons(char *p);

extern void POKETRADE_SAVE_DeleteOfferListWindows(char *p);

extern void POKETRADE_DEMO_COMMON_SetFrame(u8 *p, u32 v);

extern int POKETRADE_PROC_IsHostSide(void *);

extern void *POKETRADE_PROC_GetSideMon(void *, int);

extern u32 func_02017E1C(void *, u32, u32);

extern void PM_VOICE_GetPerapVoiceSave(void **out);

extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

extern u32 func_020307B0(void *p);

extern void MCSS_GetPosition(void *p, Vec *out);

extern void POKETRADE_SAVE_FreeIfSet(void *p);

extern void *POKETRADE_MCSS_SlideCreateWithOffsets(void *a0, void *a1, void *a2, void *a3, u16 heapId);

extern void POKETRADE_3D_AddPokemonMcssPlain(void *p, int a, int b, void *mon, int c);

extern void MCSS_SetAnmStopFlag(void *p);

extern void MCSS_SetVanishFlag(void *p);

extern void POKETRADE_PROC_SetStep(void *p, int next);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);

extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern void BG_SYS_SetTileEntry(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int b);

extern void MCSS_SetPosition(void *p, Vec *src);

extern void MCSS_ResetVanishFlag(void *p);

extern void MCSS_ResetAnmStopFlag(void *p);

extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);

extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);

extern void POKETRADE_3D_DeleteMcssSlot(void *p, int a);

extern void POKETRADE_DEMO_COMMON_ReleaseUnit(void *);

extern void POKETRADE_3D_ExitParticleManager(u32 *p, int a1);

extern void POKETRADE_3D_FreeParticleResources(void *);

extern void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p);

extern int BUTTON_MAN_GetUserData(void *p);

extern unsigned int ICA_ANIME_Get(struct IcaAnime *p, struct Rec12 *dst);

extern void BUTTON_MAN_SetEmitterPos(void *, Vec *);

extern u32 func_02051774(void);

extern void BUTTON_MAN_SetUserData(void *p, int v);

extern void BUTTON_MAN_SetCallback(void *p, int v);

extern void POKETRADE_DEMO_COMMON_SetFinishFlag(u8 *p);

extern void MCSS_SetAnimeIndex(void *a, u32 flag);

extern void POKETRADE_DEMO_COMMON_StepCompareMons(u8 *p);

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

extern void POKETRADE_DEMO_COMMON_ShowUnitActor(void *);

extern void POKETRADE_DEMO_COMMON_LoadUnitResources(void *);

extern void MCSS_SetPaletteFade(void *, u32, u32, s32, u32);

extern void MCSS_GetScale(void *, Vec *);

extern void MCSS_SetScale(void *, Vec *);

extern int PARTICLE_StartEffectWithCallback(u32, int, void *, void *);

extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

extern void *POKETRADE_MCSS_SlideCreate(void *, int, Vec *, u32);

extern void POKETRADE_NEGO_PlaySeByKeyA(u32 key);

extern void POKETRADE_MCSS_SlideBegin(void *, int, void *);

void POKETRADE_DEMO_UP_StepStartPlayback(u8 *p);

void POKETRADE_DEMO_UP_PrintMessage(u8 *p);

void POKETRADE_DEMO_UP_StepMessage(u8 *p);

void POKETRADE_DEMO_UP_StepEndScene(void *p);

void POKETRADE_DEMO_UP_UpdateEmitterA(void *obj, int on);

void POKETRADE_DEMO_UP_SetupEmitterA(void *p);

void POKETRADE_DEMO_UP_UpdateEmitterB(void *obj, int on);

void POKETRADE_DEMO_UP_SetupEmitterB(void *p);

void POKETRADE_DEMO_UP_StepStartCompare(u8 *p);

void POKETRADE_DEMO_UP_StepSetup(u8 *p);

void POKETRADE_DEMO_UP_StepParticleSystems(u8 *p);

void POKETRADE_DEMO_UP_StepAddUnit(u8 *p);

void POKETRADE_DEMO_UP_UpdateScene(u8 *p);

extern const u8 d_021D7D00[];

extern const u8 d_021D7DD8[];

extern u8 d_021D86A0[];

extern const Vec d_021D7C90;

extern const char d_021D7FD4[];

#define WORK ((u8 *)((PokeTradeDemoWork *)p)->animWork)

void POKETRADE_DEMO_UP_StepStartPlayback(u8 *p)
{
    void *mon;
    u32 a;
    u32 b;
    Vec v1;
    Vec v2;
    u32 buf;

    POKETRADE_DEMO_COMMON_StepFade(*(s8 * *)&((PokeTradeDemoWork *)p)->fade);
    POKETRADE_MCSS_SlideUpdate(((PokeTradeDemoWork *)p)->slideOwn, p);
    POKETRADE_MCSS_SlideUpdate(((PokeTradeDemoWork *)p)->slidePeer, p);
    if (FRAME > POKETRADE_DEMO_COMMON_PassThrough(0x2A)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0);
        POKETRADE_2D_DeleteAllOfferIconActors(p);
        POKETRADE_2D_DeleteAllBoxIcons((char *)p);
        POKETRADE_SAVE_DeleteOfferListWindows((char *)p);
        POKETRADE_DEMO_COMMON_SetFrame(p, 0);
        mon = POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p));
        func_02017E1C(mon, 7, 0);
        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            a = func_02017E1C(mon, 0xAB, 0);
            b = func_02017E1C(mon, 0x6F, 0);
            PM_VOICE_GetPerapVoiceSave((void **)(&buf));
            PM_VOICE_Play(a, b, 0x40, 0, 0, 0, 0, (u32)(&buf));
        }
        if (SLOT0 != 0) {
            func_020307B0(SLOT0);
            SLOT0 = 0;
        }
        if (((PokeTradeDemoWork *)p)->enemySameMon == 0) {
            MCSS_GetPosition(OBJ(0), &v1);
            POKETRADE_SAVE_FreeIfSet(SLOT0);
            if (((PokeTradeDemoWork *)p)->enemySpecialMon != 0) {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets(OBJ(0), (void *)0x14, &v1, d_021D86A0, HEAP);
            } else {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets(OBJ(0), (void *)0x12, &v1, (void *)d_021D7D00, HEAP);
            }
            POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)), 1);
            MCSS_SetAnmStopFlag(OBJ(2));
            MCSS_SetVanishFlag(OBJ(2));
        } else {
            MCSS_GetPosition(OBJ(0), &v2);
            POKETRADE_SAVE_FreeIfSet(SLOT0);
            if (((PokeTradeDemoWork *)p)->enemySpecialMon != 0) {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets(OBJ(0), (void *)0x14, &v2, d_021D86A0, HEAP);
            } else {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets(OBJ(0), (void *)0x28, &v2, (void *)d_021D7DD8, HEAP);
            }
        }
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_StepMessage);
    }
}

void POKETRADE_DEMO_UP_PrintMessage(u8 *p)
{
    GFL_NET_RestartWithDefaultTimeout(0, ((PokeTradeDemoWork *)p)->heapId);
    if (((PokeTradeDemoWork *)p)->sceneMode == 6) {
        func_02045CAC((struct MsgBank *)(((PokeTradeDemoWork *)p)->msgBank), 0x98, (void *)(((PokeTradeDemoWork *)p)->stringSrc));
    } else if (((PokeTradeDemoWork *)p)->sceneMode == 8) {
        func_02045CAC((struct MsgBank *)(((PokeTradeDemoWork *)p)->msgBank), 0x9B, (void *)(((PokeTradeDemoWork *)p)->stringSrc));
    } else if (((PokeTradeDemoWork *)p)->enemySameMon != 0) {
        func_02045CAC((struct MsgBank *)(((PokeTradeDemoWork *)p)->msgBank), 0x82, (void *)(((PokeTradeDemoWork *)p)->stringSrc));
    } else {
        func_02045CAC((struct MsgBank *)(((PokeTradeDemoWork *)p)->msgBank), 0x81, (void *)(((PokeTradeDemoWork *)p)->stringSrc));
    }
    WORDSET_SetSlotMonSpecies(((PokeTradeDemoWork *)p)->wordSet, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)));
    WORDSET_SetSlotMyStatus((struct WordSet *)(*(u32 *)&((PokeTradeDemoWork *)p)->wordSet), 1, (void *)(((PokeTradeDemoWork *)p)->enemyMonKey));
    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&((PokeTradeDemoWork *)p)->wordSet), (void *)(((PokeTradeDemoWork *)p)->stringDst), (void *)(((PokeTradeDemoWork *)p)->stringSrc));
    BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x18, 0x11);
    POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
    POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}

void POKETRADE_DEMO_UP_StepMessage(u8 *p)
{
    Vec v;

    if (FRAME == 10) {
        POKETRADE_DEMO_UP_PrintMessage(p);
    }
    if (((PokeTradeDemoWork *)p)->enemySameMon == 0 && FRAME == 6) {
        MCSS_GetPosition(OBJ(0), &v);
        MCSS_SetPosition(OBJ(2), &v);
        MCSS_ResetVanishFlag(OBJ(2));
        MCSS_SetVanishFlag(OBJ(0));
        MCSS_ResetAnmStopFlag(OBJ(2));
        *(void **)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && POKETRADE_SAVE_IsMessagePrintDone((char *)p) != 0) {
        POKETRADE_SAVE_CloseMessageWindowClear((char *)p);
        if (((PokeTradeDemoWork *)p)->enemySameMon == 0) {
            POKETRADE_3D_DeleteMcssSlot(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0(SLOT0);
            SLOT0 = 0;
        }
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_StepSetup);
    }
    POKETRADE_MCSS_SlideUpdate(SLOT0, p);
}

void POKETRADE_DEMO_UP_StepEndScene(void *p)
{
    POKETRADE_DEMO_COMMON_ReleaseUnit(p);
    POKETRADE_3D_ExitParticleManager(((PokeTradeDemoWork *)p)->animWork, 6);
    POKETRADE_3D_FreeParticleResources(((PokeTradeDemoWork *)p)->animWork);
    func_020307B0(((PokeTradeDemoWork *)p)->animWork);
    ((PokeTradeDemoWork *)p)->animWork = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_ResetClactAndBeginEvent);
}

void POKETRADE_DEMO_UP_UpdateEmitterA(void *obj, int on) {
 int buf[3]; Vec *v; void *w;
 if (on != 0 && obj != 0) {
 w=(void *)BUTTON_MAN_GetUserData(obj);
 if (((PokeTradeButtonData *)w)->anim->anime!=0) {
 v=(Vec *)buf; v->x=0; v->y=0; v->z=0;
 ICA_ANIME_Get(((PokeTradeButtonData *)w)->anim->anime,(struct Rec12 *)v);
 BUTTON_MAN_SetEmitterPos(obj,v);
 }
 }
}

/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_UP_SetupEmitterA(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)POKETRADE_DEMO_UP_UpdateEmitterA);
}

void POKETRADE_DEMO_UP_UpdateEmitterB(void *obj, int on)
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
            BUTTON_MAN_SetEmitterPos(obj, (Vec *)v);
        }
    }
}

void POKETRADE_DEMO_UP_SetupEmitterB(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)POKETRADE_DEMO_UP_UpdateEmitterB);
}

void POKETRADE_DEMO_UP_StepStartCompare(u8 *p)
{
    POKETRADE_DEMO_COMMON_SetFinishFlag(p);
    ((PokeTradeDemoWork *)p)->sceneStarted = 1;
    MCSS_SetAnimeIndex((void *)(((PokeTradeDemoWork *)p)->mcssObj[0]), 0);
    if (((PokeTradeDemoWork *)p)->sceneMode == 6) {
        Vec v = d_021D7C90;
        MCSS_SetPosition((void *)(((PokeTradeDemoWork *)p)->mcssObj[0]), &v);
    }
    POKETRADE_DEMO_COMMON_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_COMMON_StepCompareMons);
}

void POKETRADE_DEMO_UP_StepSetup(u8 *p)
{
    POKETRADE_PROC_DeleteAllResources(p);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain(p);
    ((PokeTradeDemoWork *)p)->clactSystem = (int)CLACT_CreateUnit(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D7FD4, 0x98);
    *(u16 *)(WORK + 0xBA) = HEAP;
    POKETRADE_2D_SetupSummaryBgs(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    POKETRADE_3D_AddUnitAndInit(p, 3);
    POKETRADE_3D_AddPokemonMcssPlain(p, 1, 0, POKETRADE_PROC_GetSideMon(p, 1), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, 0), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 3, 1, POKETRADE_PROC_GetSideMon(p, 1), 1);
    MCSS_SetVanishFlag(OBJ(1));
    MCSS_SetVanishFlag(OBJ(2));
    MCSS_SetVanishFlag(OBJ(3));
    POKETRADE_3D_InitParticleSystems(WORK);
    POKETRADE_3D_SetupParticleSystemsLow((char *)WORK);
    POKETRADE_3D_CreateIcaStreamsForMode(WORK, 1);
    POKETRADE_DEMO_COMMON_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_StepParticleSystems);
}

void POKETRADE_DEMO_UP_StepParticleSystems(u8 *p)
{
    POKETRADE_3D_SetupParticleSystemsHigh(((PokeTradeDemoWork *)p)->animWork);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_StepAddUnit);
}

#undef WORK

#undef WORK

#define WORK ((u32 *)((PokeTradeDemoWork *)p)->animWork)

/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_UP_StepAddUnit(u8 *p)
{
    POKETRADE_3D_RemoveCurrentUnit(p);
    POKETRADE_3D_AddUnitAndInit(p, 3);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_UpdateScene);
}

void POKETRADE_DEMO_UP_UpdateScene(u8 *p)
{
    Vec v1, v2, v3, v4, v5, v6, v7, v8;

    POKETRADE_NEGO_PlaySeByKeyA(FRAME);
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(1)) {
        MCSS_SetPaletteFade(OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(2)) {
        MCSS_SetPaletteFade(OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(3)) {
        POKETRADE_DEMO_COMMON_LoadUnitResources(p);
        POKETRADE_DEMO_COMMON_ShowUnitActor(p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(4)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x18);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(4)) {
        MCSS_SetVanishFlag(OBJ(0));
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback(WORK[0], 10, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x65)) {
        PARTICLE_StartEffectWithCallback(WORK[1], 1, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback(WORK[2], 2, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback(WORK[8], 2, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0xE)) {
        PARTICLE_StartEffectWithCallback(WORK[3], 3, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x483)) {
        PARTICLE_StartEffectWithCallback(WORK[7], 3, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback(WORK[4], 4, POKETRADE_DEMO_UP_SetupEmitterA, p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x152)) {
        PARTICLE_StartEffectWithCallback(WORK[5], 5, 0, p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x2BC)) {
        PARTICLE_StartEffectWithCallback(WORK[6], 6, POKETRADE_DEMO_UP_SetupEmitterB, p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x47F)) {
        POKETRADE_DEMO_COMMON_ShowUnitActor(p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x10A)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_COMMON_PassThrough(0x14), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x12D) - 2) {
        if (SLOT0 != 0) {
            func_020307B0(SLOT0);
            SLOT0 = 0;
        }
        if (SLOT1 != 0) {
            func_020307B0(SLOT1);
            SLOT1 = 0;
        }
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_StepEndScene);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x14A)) {
        MCSS_ResetVanishFlag(OBJ(2));
        v1.x = -0x32000;
        v1.y = -0x96000;
        v1.z = 0xA000;
        MCSS_SetPosition(OBJ(2), &v1);
        v1.x = -0x32000;
        v1.y = -0x37000;
        v1.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(2), POKETRADE_DEMO_COMMON_PassThrough(0xF), &v1, HEAP);
        MCSS_SetAnmStopFlag(OBJ(2));
        MCSS_GetScale(OBJ(2), &v1);
        v1.x *= 1.2;
        v1.y *= 1.2;
        MCSS_SetScale(OBJ(2), &v1);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x14B)) {
        MCSS_ResetVanishFlag(OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x50000;
        v2.z = -0xA000;
        MCSS_SetPosition(OBJ(3), &v2);
        v2.x = 0x3C000;
        v2.y = 0x5000;
        v2.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(3), POKETRADE_DEMO_COMMON_PassThrough(0xF), &v2, HEAP);
        MCSS_SetAnmStopFlag(OBJ(3));
        MCSS_GetScale(OBJ(3), &v2);
        v2.x *= 1.2;
        v2.y *= 1.2;
        MCSS_SetScale(OBJ(3), &v2);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x154)) {
        v3.x = -0x32000;
        v3.y = -0x37000;
        v3.z = 0xA000;
        POKETRADE_MCSS_SlideBegin(SLOT0, POKETRADE_DEMO_COMMON_PassThrough(0x1C), &v3);
        v3.x = 0x3C000;
        v3.y = 0x5000;
        v3.z = -0xA000;
        POKETRADE_MCSS_SlideBegin(SLOT1, POKETRADE_DEMO_COMMON_PassThrough(0x1C), &v3);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x170)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        v4.x = -0x96000;
        v4.y = -0x37000;
        v4.z = 0;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(2), POKETRADE_DEMO_COMMON_PassThrough(0x2E), &v4, HEAP);
        v4.x = 0x96000;
        v4.y = 0x5000;
        v4.z = 0;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(3), POKETRADE_DEMO_COMMON_PassThrough(0x2E), &v4, HEAP);
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x1B2)) {
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
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(0), POKETRADE_DEMO_COMMON_PassThrough(0x67), &v5, HEAP);
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
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(1), POKETRADE_DEMO_COMMON_PassThrough(0x67), &v6, HEAP);
        MCSS_GetScale(OBJ(1), &v6);
        v6.x *= 1.2;
        v6.y *= 1.2;
        MCSS_SetScale(OBJ(1), &v6);
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x1F8)) {
        POKETRADE_MCSS_SlideBegin(SLOT0, POKETRADE_DEMO_COMMON_PassThrough(0x80), (u8 *)SLOT0 + 0x28);
        POKETRADE_MCSS_SlideBegin(SLOT1, POKETRADE_DEMO_COMMON_PassThrough(0x80), (u8 *)SLOT1 + 0x28);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x27D)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        v7.x = 0x3C000;
        v7.y = 0x64000;
        v7.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(0), POKETRADE_DEMO_COMMON_PassThrough(7), &v7, HEAP);
        v7.x = -0x2D000;
        v7.y = -0xA0000;
        v7.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(1), POKETRADE_DEMO_COMMON_PassThrough(7), &v7, HEAP);
    }
    POKETRADE_DEMO_COMMON_PassThrough(0x48B);
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x48B + 3)) {
        MCSS_ResetVanishFlag(OBJ(3));
        v8.x = 0;
        v8.y = -0x17000;
        v8.z = 0xA000;
        MCSS_SetPosition(OBJ(3), &v8);
        MCSS_SetAnmStopFlag(OBJ(3));
        MCSS_SetPaletteFade(OBJ(3), 0x10, 0x10, 0, 0x7FFF);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x48F)) {
        MCSS_SetPaletteFade(OBJ(3), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x490)) {
        MCSS_SetPaletteFade(OBJ(3), 0, 0, 0, 0x7FFF);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x28B)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_COMMON_PassThrough(0xA), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x2B5)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_COMMON_PassThrough(0x19), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x380)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_COMMON_PassThrough(0x1E), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x3CA)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_COMMON_PassThrough(0x1E), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x4C1)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_StepEndScene);
    }
    POKETRADE_MCSS_SlideUpdate(SLOT0, p);
    POKETRADE_MCSS_SlideUpdate(SLOT1, p);
}
