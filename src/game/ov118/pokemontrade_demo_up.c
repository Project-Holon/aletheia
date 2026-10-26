/*
 * file:     pokemontrade_demo_up.c
 * unit:     yes
 * function: POKETRADE_DEMO_UP_StepStartPlayback, POKETRADE_DEMO_UP_PrintMessage, POKETRADE_DEMO_UP_StepMessage, POKETRADE_DEMO_UP_StepEndScene, POKETRADE_DEMO_UP_UpdateEmitterA, POKETRADE_DEMO_UP_SetupEmitterA, POKETRADE_DEMO_UP_UpdateEmitterB, POKETRADE_DEMO_UP_SetupEmitterB, POKETRADE_DEMO_UP_StepStartCompare, POKETRADE_DEMO_UP_StepSetup, POKETRADE_DEMO_UP_StepParticleSystems, POKETRADE_DEMO_UP_StepAddUnit, POKETRADE_DEMO_UP_UpdateScene, POKETRADE_DEMO_UP_CompareSideMon, POKETRADE_DEMO_UP_CreateUnitActor, POKETRADE_DEMO_UP_LoadUnitResources, POKETRADE_DEMO_UP_ReleaseUnit, POKETRADE_DEMO_UP_PassThrough, POKETRADE_DEMO_UP_SetFrame, POKETRADE_DEMO_UP_SetFinishFlag, POKETRADE_DEMO_UP_StepReleaseUnit, POKETRADE_DEMO_UP_DeleteSlide, POKETRADE_DEMO_UP_SetMonSlide, POKETRADE_DEMO_UP_ResetMonSlide, POKETRADE_DEMO_UP_UpdateEmitterC, POKETRADE_DEMO_UP_SetupEmitterC, POKETRADE_DEMO_UP_UpdateEmitterD, POKETRADE_DEMO_UP_SetupEmitterD, POKETRADE_DEMO_UP_StepStartDownScene
 * address:  0x021D4664
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
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
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
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotMonNickname  0x0201EEF4  thumb
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
 *   PARTICLE_EMITTER_GetUserData 0x02051A34 arm
 *   ICA_ANIME_GetTranslate 0x02011610 thumb
 *   PARTICLE_EMITTER_SetEmitPos 0x02051838 arm
 *   POKETRADE_DEMO_COMMON_SetFinishFlag  0x021D4490  thumb  ov118
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   POKETRADE_DEMO_COMMON_StepCompareMons  0x021D449C  thumb  ov118
 *   d_021D7C90     0x021D7C90  data
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
 *   PARTICLE_EMITTER_SetCallback  0x02051A24  arm  arm9
 *   PARTICLE_EMITTER_SetUserData  0x02051A2C  arm  arm9
 *   PARTICLE_GetCallbackArg  0x02051774  arm  arm9
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   d_021D7CB4     0x021D7CB4  data
 *   d_021D7FEC     0x021D7FEC  data
 *   d_021D80C4     0x021D80C4  data
 *   d_021D8790     0x021D8790  data
 *   d_021D7CA8     0x021D7CA8  data
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   ARC_TOOL_CreateHandle  0x020490F4  arm  arm9
 *   POKETRADE_DEMO_DOWN_StepSetup 0x021D5A60 thumb ov118
 *   _dfix                        0x0209C508  arm
 *   _dflt                        0x0209B750  arm
 *   _dmul                        0x0209B2E8  arm
 */
#include "pokemontrade_demo_types.h"
#include "pokemontrade_demo_up_shared_types.h"

struct WordSet;

struct MsgBank;

#include "pokemontrade_demo_common.h"
struct McssSlide;

#include "../ov119/pokemontrade_mcss.h"


#include "../ov119/pokemontrade_2d.h"


#include "../ov119/pokemontrade_save.h"


#include "../ov119/pokemontrade_proc.h"

struct PokemonParam;

#include "../arm9/clact.h"
#include "../arm9/ica_anime.h"
#include "../arm9/particle.h"
#include "../arm9/poke_tool.h"
struct SaveBlock;

#include "../arm9/pm_voice.h"


#include "../arm9/gfl_heap_wrap.h"
struct McssWork;

#include "../arm9/mcss.h"


#include "../ov119/pokemontrade_3d.h"


#include "../arm9/net.h"
struct Strbuf;

#include "../arm9/msgdata.h"

#include "../arm9/wordset.h"


#include "../arm9/bg_sys.h"


struct ParticleManager;


struct Obj3D;




#include "../arm9/wipe.h"


#include "../ov119/pokemontrade_nego.h"
#include "../sdk_ioreg.h"


void POKETRADE_DEMO_UP_StepStartPlayback(TradeWork *p);

void POKETRADE_DEMO_UP_PrintMessage(TradeWork *p);

void POKETRADE_DEMO_UP_StepMessage(TradeWork *p);

void POKETRADE_DEMO_UP_StepEndScene(TradeWork *p);

void POKETRADE_DEMO_UP_UpdateEmitterA(void *obj, int on);

void POKETRADE_DEMO_UP_SetupEmitterA(void *emitter);

void POKETRADE_DEMO_UP_UpdateEmitterB(void *obj, int on);

void POKETRADE_DEMO_UP_SetupEmitterB(void *emitter);

void POKETRADE_DEMO_UP_StepStartCompare(TradeWork *p);

void POKETRADE_DEMO_UP_StepSetup(TradeWork *p);

void POKETRADE_DEMO_UP_StepParticleSystems(TradeWork *p);

void POKETRADE_DEMO_UP_StepAddUnit(TradeWork *p);

void POKETRADE_DEMO_UP_UpdateScene(TradeWork *p);

extern const u8 d_021D7D00[];

extern const u8 d_021D7DD8[];

extern u8 d_021D86A0[];

extern const PokemontradeDemoVec d_021D7C90;

extern const char d_021D7FD4[];


void POKETRADE_DEMO_UP_StepStartPlayback(TradeWork *work)
{
    void *mon;
    u32 a;
    u32 b;
    PokemontradeDemoVec differentMonPos;
    PokemontradeDemoVec sameMonPos;
    u32 buf;

    POKETRADE_DEMO_COMMON_StepFade(*(s8 * *)&work->fade);
    POKETRADE_MCSS_SlideUpdate(work->slide[0], work);
    POKETRADE_MCSS_SlideUpdate(work->slide[1], work);
    if (work->waitCounter > POKETRADE_DEMO_COMMON_PassThrough(0x2A)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(work, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(work, 0);
        POKETRADE_2D_DeleteAllOfferIconActors(work);
        POKETRADE_2D_DeleteAllBoxIcons(work);
        POKETRADE_SAVE_DeleteOfferListWindows(work);
        POKETRADE_DEMO_COMMON_SetFrame(work, 0);
        mon = POKETRADE_PROC_GetSideMon(work, POKETRADE_PROC_IsHostSide(work));
        POKE_TOOL_GetPartyValue(mon, 7, 0);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
            b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
            PM_VOICE_GetPerapVoiceSave((struct SaveBlock **)(&buf));
            PM_VOICE_Play(a, b, 0x40, 0, 0, 0, 0, (void **)(&buf));
        }
        if (work->slide[0] != 0) {
            GFL_HEAP_Free(work->slide[0]);
            work->slide[0] = 0;
        }
        if (work->enemySameMon == 0) {
            MCSS_GetPosition(work->mcssPokemon[0], (u32 *)(&differentMonPos));
            POKETRADE_SAVE_FreeIfSet(work->slide[0]);
            if (work->enemySpecialMon != 0) {
                work->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets(work->mcssPokemon[0], 0x14, &differentMonPos, d_021D86A0, work->heapId);
            } else {
                work->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets(work->mcssPokemon[0], 0x12, &differentMonPos, (void *)d_021D7D00, work->heapId);
            }
            POKETRADE_3D_AddPokemonMcssPlain(work, 2, 0, POKETRADE_PROC_GetSideMon(work, POKETRADE_PROC_IsHostSide(work)), 1);
            MCSS_SetAnmStopFlag(work->mcssPokemon[2]);
            MCSS_SetVanishFlag(work->mcssPokemon[2]);
        } else {
            MCSS_GetPosition(work->mcssPokemon[0], (u32 *)(&sameMonPos));
            POKETRADE_SAVE_FreeIfSet(work->slide[0]);
            if (work->enemySpecialMon != 0) {
                work->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets(work->mcssPokemon[0], 0x14, &sameMonPos, d_021D86A0, work->heapId);
            } else {
                work->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets(work->mcssPokemon[0], 0x28, &sameMonPos, (void *)d_021D7DD8, work->heapId);
            }
        }
        POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_UP_StepMessage);
    }
}

void POKETRADE_DEMO_UP_PrintMessage(TradeWork *work)
{
    GFL_NET_RefreshWmIconAtTopRight(0, work->heapId);
    if (work->tradeState == 6) {
        MSGDATA_ReadString((struct MsgBank *)(work->messageBank), 0x98, (void *)(work->messageTemplate));
    } else if (work->tradeState == 8) {
        MSGDATA_ReadString((struct MsgBank *)(work->messageBank), 0x9B, (void *)(work->messageTemplate));
    } else if (work->enemySameMon != 0) {
        MSGDATA_ReadString((struct MsgBank *)(work->messageBank), 0x82, (void *)(work->messageTemplate));
    } else {
        MSGDATA_ReadString((struct MsgBank *)(work->messageBank), 0x81, (void *)(work->messageTemplate));
    }
    WORDSET_SetSlotMonNickname(work->wordSet, 0, POKETRADE_PROC_GetSideMon(work, POKETRADE_PROC_IsHostSide(work)));
    WORDSET_SetSlotMyStatus(work->wordSet, 1, (void *)(work->playerStatus));
    WORDSET_CopyTaggedText(work->wordSet, (void *)(work->messageText), (void *)(work->messageTemplate));
    BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x18, 0x11);
    POKETRADE_SAVE_OpenMessageWindowAtPos(work, 1, 0);
    POKETRADE_2D_ScheduleSubPlaneVisible(work, 0x14);
    *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0;
}

void POKETRADE_DEMO_UP_StepMessage(TradeWork *work)
{
    PokemontradeDemoVec v;

    if (work->waitCounter == 10) {
        POKETRADE_DEMO_UP_PrintMessage(work);
    }
    if (work->enemySameMon == 0 && work->waitCounter == 6) {
        MCSS_GetPosition(work->mcssPokemon[0], (u32 *)(&v));
        MCSS_SetPosition(work->mcssPokemon[2], (u32 *)(&v));
        MCSS_ResetVanishFlag(work->mcssPokemon[2]);
        MCSS_SetVanishFlag(work->mcssPokemon[0]);
        MCSS_ResetAnmStopFlag(work->mcssPokemon[2]);
        *(void **)work->slide[0] = work->mcssPokemon[2];
    }
    if (work->waitCounter > 0xC8 && POKETRADE_SAVE_IsMessagePrintDone(work) != 0) {
        POKETRADE_SAVE_CloseMessageWindowClear(work);
        if (work->enemySameMon == 0) {
            POKETRADE_3D_DeleteMcssSlot(work, 0);
            work->mcssPokemon[0] = work->mcssPokemon[2];
            work->mcssPokemon[2] = 0;
        }
        if (work->slide[0] != 0) {
            GFL_HEAP_Free(work->slide[0]);
            work->slide[0] = 0;
        }
        POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_UP_StepSetup);
    }
    POKETRADE_MCSS_SlideUpdate(work->slide[0], work);
}

void POKETRADE_DEMO_UP_StepEndScene(TradeWork *work)
{
    POKETRADE_DEMO_COMMON_ReleaseUnit(work);
    POKETRADE_3D_ExitParticleManager(work->particleManager, 6);
    POKETRADE_3D_FreeParticleResources(work->particleManager);
    GFL_HEAP_Free(work->particleManager);
    work->particleManager = 0;
    POKETRADE_PROC_SetStep(work, POKETRADE_SAVE_ResetClactAndBeginEvent);
}

void POKETRADE_DEMO_UP_UpdateEmitterA(void *obj, int on) {
 int buf[3]; PokemontradeDemoVec *v; void *w;
 if (on != 0 && obj != 0) {
 w=(void *)PARTICLE_EMITTER_GetUserData(obj);
 if (((PokeTradeButtonData *)w)->anim->anime!=0) {
 v=(PokemontradeDemoVec *)buf; v->x=0; v->y=0; v->z=0;
 ICA_ANIME_GetTranslate(((PokeTradeButtonData *)w)->anim->anime,(struct VecFx32 *)(struct Rec12 *)v);
 PARTICLE_EMITTER_SetEmitPos(obj,(const Vec3 *)v);
 }
 }
}

/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_UP_SetupEmitterA(void *emitter)
{
    PARTICLE_EMITTER_SetUserData(emitter, PARTICLE_GetCallbackArg());
    PARTICLE_EMITTER_SetCallback(emitter, POKETRADE_DEMO_UP_UpdateEmitterA);
}

void POKETRADE_DEMO_UP_UpdateEmitterB(void *obj, int on)
{
    s32 buf[3];
    PokemontradeDemoVec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)PARTICLE_EMITTER_GetUserData(obj);
        if (((PokeTradeButtonData *)w)->anim->animeB != 0) {
            v = (PokemontradeDemoVec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_GetTranslate(((PokeTradeButtonData *)w)->anim->animeB, (struct VecFx32 *)(struct Rec12 *)v);
            PARTICLE_EMITTER_SetEmitPos(obj, (const Vec3 *)(PokemontradeDemoVec *)v);
        }
    }
}

void POKETRADE_DEMO_UP_SetupEmitterB(void *emitter)
{
    PARTICLE_EMITTER_SetUserData(emitter, PARTICLE_GetCallbackArg());
    PARTICLE_EMITTER_SetCallback(emitter, POKETRADE_DEMO_UP_UpdateEmitterB);
}

void POKETRADE_DEMO_UP_StepStartCompare(TradeWork *work)
{
    POKETRADE_DEMO_COMMON_SetFinishFlag(work);
    work->mcssAnimStopped = 1;
    MCSS_SetAnimeIndex((void *)(work->mcssPokemon[0]), 0);
    if (work->tradeState == 6) {
        PokemontradeDemoVec v = d_021D7C90;
        MCSS_SetPosition((void *)(work->mcssPokemon[0]), (u32 *)(&v));
    }
    POKETRADE_DEMO_COMMON_SetFrame(work, 0);
    POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_COMMON_StepCompareMons);
}

void POKETRADE_DEMO_UP_StepSetup(TradeWork *work)
{
    POKETRADE_PROC_DeleteAllResources(work);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain(work);
    work->clactSystem = CLACT_CreateUnit(3, 0, work->heapId);
    work->particleManager = GFL_HEAP_Alloc(work->heapId, sizeof(ParticleManager), 1, d_021D7FD4, 0x98);
    work->particleManager->heap = work->heapId;
    POKETRADE_2D_SetupSummaryBgs(work, 0);
    *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0;
    *(volatile u16 *)REG_BLDCNT_ADDR = 0;
    POKETRADE_3D_AddUnitAndInit(work, 3);
    POKETRADE_3D_AddPokemonMcssPlain(work, 1, 0, POKETRADE_PROC_GetSideMon(work, 1), 1);
    POKETRADE_3D_AddPokemonMcssPlain(work, 2, 0, POKETRADE_PROC_GetSideMon(work, 0), 1);
    POKETRADE_3D_AddPokemonMcssPlain(work, 3, 1, POKETRADE_PROC_GetSideMon(work, 1), 1);
    MCSS_SetVanishFlag(work->mcssPokemon[1]);
    MCSS_SetVanishFlag(work->mcssPokemon[2]);
    MCSS_SetVanishFlag(work->mcssPokemon[3]);
    POKETRADE_3D_InitParticleSystems(work->particleManager);
    POKETRADE_3D_SetupParticleSystemsLow(work->particleManager);
    POKETRADE_3D_CreateIcaStreamsForMode(work->particleManager, 1);
    POKETRADE_DEMO_COMMON_SetFrame(work, 0);
    POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_UP_StepParticleSystems);
}

void POKETRADE_DEMO_UP_StepParticleSystems(TradeWork *work)
{
    POKETRADE_3D_SetupParticleSystemsHigh(work->particleManager);
    POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_UP_StepAddUnit);
}


/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_UP_StepAddUnit(TradeWork *work)
{
    POKETRADE_3D_RemoveCurrentUnit(work);
    POKETRADE_3D_AddUnitAndInit(work, 3);
    POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_UP_UpdateScene);
}

void POKETRADE_DEMO_UP_UpdateScene(TradeWork *work)
{
    PokemontradeDemoVec ownVec, peerVec, slideBeginVec, swapVec, leftMonVec, rightMonVec, exitVec, copyPosVec;

    POKETRADE_NEGO_PlaySeByKeyA(work->waitCounter);
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(1)) {
        MCSS_SetPaletteFade(work->mcssPokemon[0], 8, 8, 0, 0xFFFF);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(2)) {
        MCSS_SetPaletteFade(work->mcssPokemon[0], 0x10, 0x10, 0, 0xFFFF);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(3)) {
        POKETRADE_DEMO_COMMON_LoadUnitResources(work);
        POKETRADE_DEMO_COMMON_ShowUnitActor(work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(4)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(work, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(work, 0x18);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(4)) {
        MCSS_SetVanishFlag(work->mcssPokemon[0]);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)work->particleManager->system[0], 10, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x65)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)work->particleManager->system[1], 1, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)work->particleManager->system[2], 2, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)work->particleManager->system[8], 2, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0xE)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)work->particleManager->system[3], 3, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x483)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)work->particleManager->system[7], 3, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)work->particleManager->system[4], 4, POKETRADE_DEMO_UP_SetupEmitterA, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x152)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)work->particleManager->system[5], 5, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x2BC)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)work->particleManager->system[6], 6, POKETRADE_DEMO_UP_SetupEmitterB, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x47F)) {
        POKETRADE_DEMO_COMMON_ShowUnitActor(work);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x10A)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, (u32)POKETRADE_DEMO_COMMON_PassThrough(0x14), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x12D) - 2) {
        if (work->slide[0] != 0) {
            GFL_HEAP_Free(work->slide[0]);
            work->slide[0] = 0;
        }
        if (work->slide[1] != 0) {
            GFL_HEAP_Free(work->slide[1]);
            work->slide[1] = 0;
        }
        POKETRADE_3D_RemoveCurrentUnit(work);
        POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_UP_StepEndScene);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x14A)) {
        MCSS_ResetVanishFlag(work->mcssPokemon[2]);
        ownVec.x = -0x32000;
        ownVec.y = -0x96000;
        ownVec.z = 0xA000;
        MCSS_SetPosition(work->mcssPokemon[2], (u32 *)(&ownVec));
        ownVec.x = -0x32000;
        ownVec.y = -0x37000;
        ownVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(work->slide[0]);
        work->slide[0] = POKETRADE_MCSS_SlideCreate((void *)(work->mcssPokemon[2]), (POKETRADE_DEMO_COMMON_PassThrough(0xF)), &ownVec, work->heapId);
        MCSS_SetAnmStopFlag(work->mcssPokemon[2]);
        MCSS_GetScale(work->mcssPokemon[2], (u32 *)(&ownVec));
        ownVec.x *= 1.2;
        ownVec.y *= 1.2;
        MCSS_SetScale(work->mcssPokemon[2], (u32 *)(&ownVec));
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x14B)) {
        MCSS_ResetVanishFlag(work->mcssPokemon[3]);
        peerVec.x = 0x3C000;
        peerVec.y = 0x50000;
        peerVec.z = -0xA000;
        MCSS_SetPosition(work->mcssPokemon[3], (u32 *)(&peerVec));
        peerVec.x = 0x3C000;
        peerVec.y = 0x5000;
        peerVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(work->slide[1]);
        work->slide[1] = POKETRADE_MCSS_SlideCreate((void *)(work->mcssPokemon[3]), (POKETRADE_DEMO_COMMON_PassThrough(0xF)), &peerVec, work->heapId);
        MCSS_SetAnmStopFlag(work->mcssPokemon[3]);
        MCSS_GetScale(work->mcssPokemon[3], (u32 *)(&peerVec));
        peerVec.x *= 1.2;
        peerVec.y *= 1.2;
        MCSS_SetScale(work->mcssPokemon[3], (u32 *)(&peerVec));
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x154)) {
        slideBeginVec.x = -0x32000;
        slideBeginVec.y = -0x37000;
        slideBeginVec.z = 0xA000;
        POKETRADE_MCSS_SlideBegin(work->slide[0], (POKETRADE_DEMO_COMMON_PassThrough(0x1C)), &slideBeginVec);
        slideBeginVec.x = 0x3C000;
        slideBeginVec.y = 0x5000;
        slideBeginVec.z = -0xA000;
        POKETRADE_MCSS_SlideBegin(work->slide[1], (POKETRADE_DEMO_COMMON_PassThrough(0x1C)), &slideBeginVec);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x170)) {
        GFL_HEAP_Free(work->slide[0]);
        work->slide[0] = 0;
        GFL_HEAP_Free(work->slide[1]);
        work->slide[1] = 0;
        swapVec.x = -0x96000;
        swapVec.y = -0x37000;
        swapVec.z = 0;
        POKETRADE_SAVE_FreeIfSet(work->slide[0]);
        work->slide[0] = POKETRADE_MCSS_SlideCreate((void *)(work->mcssPokemon[2]), (POKETRADE_DEMO_COMMON_PassThrough(0x2E)), &swapVec, work->heapId);
        swapVec.x = 0x96000;
        swapVec.y = 0x5000;
        swapVec.z = 0;
        POKETRADE_SAVE_FreeIfSet(work->slide[1]);
        work->slide[1] = POKETRADE_MCSS_SlideCreate((void *)(work->mcssPokemon[3]), (POKETRADE_DEMO_COMMON_PassThrough(0x2E)), &swapVec, work->heapId);
        work->slide[0]->wobbleEnabled = 1;
        work->slide[1]->wobbleEnabled = 1;
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x1B2)) {
        GFL_HEAP_Free(work->slide[0]);
        work->slide[0] = 0;
        MCSS_ResetVanishFlag(work->mcssPokemon[0]);
        MCSS_SetPaletteFade(work->mcssPokemon[0], 0, 0, 0, 0x7FFF);
        leftMonVec.x = -0x96000;
        leftMonVec.y = 0x5000;
        leftMonVec.z = -0xA000;
        MCSS_SetPosition(work->mcssPokemon[0], (u32 *)(&leftMonVec));
        leftMonVec.x = 0x3C000;
        leftMonVec.y = 0x5000;
        leftMonVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(work->slide[0]);
        work->slide[0] = POKETRADE_MCSS_SlideCreate((void *)(work->mcssPokemon[0]), (POKETRADE_DEMO_COMMON_PassThrough(0x67)), &leftMonVec, work->heapId);
        MCSS_GetScale(work->mcssPokemon[0], (u32 *)(&leftMonVec));
        leftMonVec.x *= 1.2;
        leftMonVec.y *= 1.2;
        MCSS_SetScale(work->mcssPokemon[0], (u32 *)(&leftMonVec));
        GFL_HEAP_Free(work->slide[1]);
        work->slide[1] = 0;
        MCSS_ResetVanishFlag(work->mcssPokemon[1]);
        rightMonVec.x = 0x96000;
        rightMonVec.y = -0x37000;
        rightMonVec.z = 0xA000;
        MCSS_SetPosition(work->mcssPokemon[1], (u32 *)(&rightMonVec));
        rightMonVec.x = -0x2D000;
        rightMonVec.y = -0x37000;
        rightMonVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(work->slide[1]);
        work->slide[1] = POKETRADE_MCSS_SlideCreate((void *)(work->mcssPokemon[1]), (POKETRADE_DEMO_COMMON_PassThrough(0x67)), &rightMonVec, work->heapId);
        MCSS_GetScale(work->mcssPokemon[1], (u32 *)(&rightMonVec));
        rightMonVec.x *= 1.2;
        rightMonVec.y *= 1.2;
        MCSS_SetScale(work->mcssPokemon[1], (u32 *)(&rightMonVec));
        work->slide[0]->wobbleEnabled = 1;
        work->slide[1]->wobbleEnabled = 1;
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x1F8)) {
        POKETRADE_MCSS_SlideBegin(work->slide[0], (POKETRADE_DEMO_COMMON_PassThrough(0x80)), &work->slide[0]->target);
        POKETRADE_MCSS_SlideBegin(work->slide[1], (POKETRADE_DEMO_COMMON_PassThrough(0x80)), &work->slide[1]->target);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x27D)) {
        GFL_HEAP_Free(work->slide[0]);
        work->slide[0] = 0;
        GFL_HEAP_Free(work->slide[1]);
        work->slide[1] = 0;
        exitVec.x = 0x3C000;
        exitVec.y = 0x64000;
        exitVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(work->slide[0]);
        work->slide[0] = POKETRADE_MCSS_SlideCreate((void *)(work->mcssPokemon[0]), (POKETRADE_DEMO_COMMON_PassThrough(7)), &exitVec, work->heapId);
        exitVec.x = -0x2D000;
        exitVec.y = -0xA0000;
        exitVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(work->slide[1]);
        work->slide[1] = POKETRADE_MCSS_SlideCreate((void *)(work->mcssPokemon[1]), (POKETRADE_DEMO_COMMON_PassThrough(7)), &exitVec, work->heapId);
    }
    POKETRADE_DEMO_COMMON_PassThrough(0x48B);
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x48B + 3)) {
        MCSS_ResetVanishFlag(work->mcssPokemon[3]);
        copyPosVec.x = 0;
        copyPosVec.y = -0x17000;
        copyPosVec.z = 0xA000;
        MCSS_SetPosition(work->mcssPokemon[3], (u32 *)(&copyPosVec));
        MCSS_SetAnmStopFlag(work->mcssPokemon[3]);
        MCSS_SetPaletteFade(work->mcssPokemon[3], 0x10, 0x10, 0, 0x7FFF);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x48F)) {
        MCSS_SetPaletteFade(work->mcssPokemon[3], 8, 8, 0, 0x7FFF);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x490)) {
        MCSS_SetPaletteFade(work->mcssPokemon[3], 0, 0, 0, 0x7FFF);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x28B)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, (u32)POKETRADE_DEMO_COMMON_PassThrough(0xA), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x2B5)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, (u32)POKETRADE_DEMO_COMMON_PassThrough(0x19), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x380)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, (u32)POKETRADE_DEMO_COMMON_PassThrough(0x1E), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x3CA)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, (u32)POKETRADE_DEMO_COMMON_PassThrough(0x1E), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x4C1)) {
        GFL_HEAP_Free(work->slide[0]);
        work->slide[0] = 0;
        GFL_HEAP_Free(work->slide[1]);
        work->slide[1] = 0;
        POKETRADE_3D_RemoveCurrentUnit(work);
        POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_UP_StepEndScene);
    }
    POKETRADE_MCSS_SlideUpdate(work->slide[0], work);
    POKETRADE_MCSS_SlideUpdate(work->slide[1], work);
}

typedef struct {
    u32 v[4];
} Quad;
struct PersonalData;

#include "../arm9/poke_personal.h"


struct MyStatus;

#include "../arm9/mystatus.h"

struct ClactActor;


#include "../arm9/arc_tool.h"








void POKETRADE_DEMO_UP_CompareSideMon(TradeWork *p, u8 *outSame, u8 *outFlag, struct MyStatus *key, int enemy);

void POKETRADE_DEMO_UP_CreateUnitActor(TradeWork *p);

void POKETRADE_DEMO_UP_LoadUnitResources(TradeWork *p);

void POKETRADE_DEMO_UP_ReleaseUnit(TradeWork *p);

int POKETRADE_DEMO_UP_PassThrough(int a);

void POKETRADE_DEMO_UP_SetFrame(TradeWork *p, u32 v);

void POKETRADE_DEMO_UP_SetFinishFlag(TradeWork *p);

void POKETRADE_DEMO_UP_StepReleaseUnit(TradeWork *p);

void POKETRADE_DEMO_UP_DeleteSlide(TradeWork *p, int idx);

void POKETRADE_DEMO_UP_SetMonSlide(TradeWork *p, int idx);

void POKETRADE_DEMO_UP_ResetMonSlide(TradeWork *p, int idx);

void POKETRADE_DEMO_UP_UpdateEmitterC(void *obj, int on);

void POKETRADE_DEMO_UP_SetupEmitterC(void *emitter);

void POKETRADE_DEMO_UP_UpdateEmitterD(void *obj, int on);

void POKETRADE_DEMO_UP_SetupEmitterD(void *emitter);

void POKETRADE_DEMO_UP_StepStartDownScene(TradeWork *p);

#include "pokemontrade_demo_down.h"

extern const Quad d_021D7CB4;

extern const u8 d_021D7FEC[];

extern const u8 d_021D80C4[];

extern u8 d_021D8790[];

extern const PokemontradeDemoVec d_021D7CA8;

void POKETRADE_DEMO_UP_CompareSideMon(TradeWork *work, u8 *outSame, u8 *outFlag, struct MyStatus *key, int enemy)
{
    int which;
    void *mon;
    u32 id;
    u32 a;
    u32 b;
    u32 egg;
    struct PersonalData *h;
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
        h = POKE_PERSONAL_Create((u16)a, (u16)b, work->heapId);
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

void POKETRADE_DEMO_UP_CreateUnitActor(TradeWork *work)
{
    struct ClactActor *v = work->particleManager->actor;
    if (v == 0) {
        ClactActorPos s;
        s.x = 0x80;
        s.y = 0x63;
        s.animSeq = 0;
        s.drawPriority = 0;
        s.bgPriority = 0;
        work->particleManager->actor =
            (void *)CLACT_CreateActor(work->clactSystem,
                          work->cellAnimB,
                          work->paletteSpare,
                          work->cellAnimSpare,
                          (const struct ActorInitParam *)&s, 0, work->heapId);
        CLACT_SetActorAutoAnim((struct ClactActor *)work->particleManager->actor, 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->particleManager->actor, 1);
    } else {
        CLACT_RestartActorAnim((struct ClactActor *)v);
    }
}

void POKETRADE_DEMO_UP_LoadUnitResources(TradeWork *work)
{
    void *h = ARC_TOOL_CreateHandle(0x67, work->heapId);
    work->cellAnimB = CLACT_RegisterCharacter(h, 2, 0, 0, work->heapId);
    work->paletteSpare = CLACT_RegisterPaletteEx(h, 3, 0, 0xE0, 0, 1, work->heapId);
    work->cellAnimSpare = CLACT_RegisterCellAnim(h, 1, 0, work->heapId);
    ARC_TOOL_DeleteHandle(h);
    work->particleManager->actor = 0;
}

/*
 * Teardown of the three sub-buffers at +0x8a8/+0x88c/+0x8bc (their base
 * 0x8a8 is the single pool word) plus the +0xb0 pointer hung off the +0xc
 * record; every slot clears to zero. Non-SDK deps are the matched ov118
 * POKETRADE_DEMO_UP_ReleaseUnit callers' targets; this is the first callee of POKETRADE_DEMO_MIDDLE_StepEndScene.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_UP_ReleaseUnit(TradeWork *work)
{
    TradeWork *b = work;

    if (b->particleManager->actor != 0)
        CLACT_DeleteActor(b->particleManager->actor);
    if (b->cellAnimB != 0) {
        CLACT_ReleaseCharacter((u32)b->cellAnimB);
        CLACT_ReleasePalette((u32)b->paletteSpare);
        CLACT_ReleaseCellAnim((u32)b->cellAnimSpare);
    }
    b->cellAnimB = 0;
    b->paletteSpare = 0;
    b->cellAnimSpare = 0;
    b->particleManager->actor = 0;
}

int POKETRADE_DEMO_UP_PassThrough(int value) { return value; }

void POKETRADE_DEMO_UP_SetFrame(TradeWork *work, u32 frame) { work->waitCounter = frame; }

void POKETRADE_DEMO_UP_SetFinishFlag(TradeWork *work) { work->repeatCounter = 1; }

void POKETRADE_DEMO_UP_StepReleaseUnit(TradeWork *work)
{
    POKETRADE_DEMO_UP_ReleaseUnit(work);
    POKETRADE_3D_ExitParticleManager(work->particleManager, 6);
    POKETRADE_3D_FreeParticleResources(work->particleManager);
    GFL_HEAP_Free(work->particleManager);
    work->particleManager = 0;
    POKETRADE_PROC_SetStep(work, POKETRADE_SAVE_ResetClactAndBeginEvent);
}

void POKETRADE_DEMO_UP_DeleteSlide(TradeWork *work, int idx)
{
    if (work->slide[0] != 0) {
        GFL_HEAP_Free(work->slide[0]);
        work->slide[0] = 0;
    }
}

/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_UP_SetMonSlide(TradeWork *work, int idx)
{
    void *x;
    PokemontradeDemoVec buf;

    x = POKETRADE_PROC_GetSideMon(work, 1 - POKETRADE_PROC_IsHostSide(work));
    POKE_TOOL_GetPartyValue(x, 7, 0);
    if (POKE_TOOL_GetPartyValue(x, 0x4c, 0) == 0) {
        PM_VOICE_Play(POKE_TOOL_GetPartyValue(x, 0xab, 0), POKE_TOOL_GetPartyValue(x, 0x6f, 0), 0x40, 0, 0, 0, 0, 0);
    }
    if (work->ownSameMon == 0) {
        MCSS_GetPosition(work->mcssPokemon[idx], (u32 *)(&buf));
        POKETRADE_SAVE_FreeIfSet(work->slide[3]);
        if (work->ownSpecialMon != 0) {
            work->slide[3] = POKETRADE_MCSS_SlideCreateWithOffsets(work->mcssPokemon[idx], 0x14, &buf, d_021D8790, work->heapId);
        } else {
            work->slide[3] = POKETRADE_MCSS_SlideCreateWithOffsets(work->mcssPokemon[idx], 0x28, &buf, (void *)d_021D80C4, work->heapId);
        }
    } else {
        Quad t = d_021D7CB4;
        void *obj = work->mcssPokemon[t.v[idx]];
        MCSS_GetPosition(work->mcssPokemon[idx], (u32 *)(&buf));
        POKETRADE_SAVE_FreeIfSet(work->slide[3]);
        if (work->ownSpecialMon != 0) {
            work->slide[3] = POKETRADE_MCSS_SlideCreateWithOffsets(obj, 0x14, &buf, d_021D8790, work->heapId);
        } else {
            work->slide[3] = POKETRADE_MCSS_SlideCreateWithOffsets(obj, 0x12, &buf, (void *)d_021D7FEC, work->heapId);
        }
    }
}

void POKETRADE_DEMO_UP_ResetMonSlide(TradeWork *work, int idx)
{
    void **obj = work->mcssPokemon;
    PokemontradeDemoVec v;

    MCSS_ResetVanishFlag((void *)obj[idx]);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xA000;
    MCSS_SetPosition((void *)obj[idx], (u32 *)(&v));
    MCSS_SetAnmStopFlag((void *)obj[idx]);
    MCSS_GetScale((void *)obj[idx], (u32 *)(&v));
    if (v.x < 0) {
        v.x = -0x10000;
    } else {
        v.x = 0x10000;
    }
    v.y = 0x10000;
    v.z = 0x1000;
    MCSS_SetScale((void *)obj[idx], (u32 *)(&v));
}

void POKETRADE_DEMO_UP_UpdateEmitterC(void *obj, int on)
{
    s32 buf[3];
    PokemontradeDemoVec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)PARTICLE_EMITTER_GetUserData(obj);
        if (((PokeTradeButtonData *)w)->anim->anime != 0) {
            v = (PokemontradeDemoVec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_GetTranslate(((PokeTradeButtonData *)w)->anim->anime, (struct VecFx32 *)(struct Rec12 *)v);
            PARTICLE_EMITTER_SetEmitPos(obj, (const Vec3 *)v);
        }
    }
}

void POKETRADE_DEMO_UP_SetupEmitterC(void *emitter)
{
    PARTICLE_EMITTER_SetUserData(emitter, PARTICLE_GetCallbackArg());
    PARTICLE_EMITTER_SetCallback(emitter, POKETRADE_DEMO_UP_UpdateEmitterC);
}

void POKETRADE_DEMO_UP_UpdateEmitterD(void *obj, int on)
{
    s32 buf[3];
    PokemontradeDemoVec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)PARTICLE_EMITTER_GetUserData(obj);
        if (((PokeTradeButtonData *)w)->anim->animeB != 0) {
            v = (PokemontradeDemoVec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_GetTranslate(((PokeTradeButtonData *)w)->anim->animeB, (struct VecFx32 *)(struct Rec12 *)v);
            PARTICLE_EMITTER_SetEmitPos(obj, (const Vec3 *)v);
        }
    }
}

void POKETRADE_DEMO_UP_SetupEmitterD(void *emitter)
{
    PARTICLE_EMITTER_SetUserData(emitter, PARTICLE_GetCallbackArg());
    PARTICLE_EMITTER_SetCallback(emitter, POKETRADE_DEMO_UP_UpdateEmitterD);
}

void POKETRADE_DEMO_UP_StepStartDownScene(TradeWork *work)
{
    POKETRADE_DEMO_UP_SetFinishFlag(work);
    work->mcssAnimStopped = 1;
    MCSS_SetAnimeIndex((void *)(work->mcssPokemon[0]), 0);
    MCSS_SetVanishFlag((void *)(work->mcssPokemon[0]));
    MCSS_SetVanishFlag((void *)(work->mcssPokemon[1]));
    if (work->tradeState == 6) {
        PokemontradeDemoVec v = d_021D7CA8;
        MCSS_SetPosition((void *)(work->mcssPokemon[0]), (u32 *)(&v));
    }
    POKETRADE_2D_ScheduleMainPlaneVisible(work, 0x11);
    POKETRADE_2D_ScheduleSubPlaneVisible(work, 0);
    POKETRADE_DEMO_UP_CompareSideMon(work, &work->enemySameMon, &work->enemySpecialMon, (struct MyStatus *)work->playerStatus, 1);
    POKETRADE_DEMO_UP_CompareSideMon(work, &work->ownSameMon, &work->ownSpecialMon, (struct MyStatus *)work->trainerRecord, 0);
    POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_DOWN_StepSetup);
}
