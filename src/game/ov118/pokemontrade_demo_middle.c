/*
 * file:     pokemontrade_demo_middle.c
 * unit:     yes
 * function: POKETRADE_DEMO_MIDDLE_StepStartPlayback, POKETRADE_DEMO_MIDDLE_PrintMessage, POKETRADE_DEMO_MIDDLE_StepMessage, POKETRADE_DEMO_MIDDLE_StepEndScene, POKETRADE_DEMO_MIDDLE_DeleteSlide, POKETRADE_DEMO_MIDDLE_CreateOfferSlide, POKETRADE_DEMO_MIDDLE_ResetMonSlide, POKETRADE_DEMO_MIDDLE_UpdateEmitterA, POKETRADE_DEMO_MIDDLE_SetupEmitterA, POKETRADE_DEMO_MIDDLE_UpdateEmitterB, POKETRADE_DEMO_MIDDLE_SetupEmitterB, POKETRADE_DEMO_MIDDLE_StepStartCompare, POKETRADE_DEMO_MIDDLE_StepSetup, POKETRADE_DEMO_MIDDLE_StepParticleSystems, POKETRADE_DEMO_MIDDLE_StepAddUnit, POKETRADE_DEMO_MIDDLE_UpdateScene
 * address:  0x021D6918
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   POKETRADE_DEMO_DOWN_StepFade  0x021D64F4  thumb  ov118
 *   POKETRADE_DEMO_DOWN_CreateUnitActor  0x021D6600  thumb  ov118
 *   POKETRADE_DEMO_DOWN_LoadUnitResources  0x021D667C  thumb  ov118
 *   PARTICLE_StartEffectWithCallback  0x020515CC  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   POKETRADE_3D_RemoveCurrentUnit  0x021E3230  thumb  ov119
 *   POKETRADE_NEGO_PlaySeByKeyA  0x021DFA60  thumb  ov119
 *   POKETRADE_MCSS_SlideBegin  0x021DFB4C  thumb  ov119
 *   POKETRADE_MCSS_SlideCreate  0x021DFB84  thumb  ov119
 *   d_021D7CEC     0x021D7CEC  data  a4
 *   POKETRADE_MCSS_SlideUpdate  0x021DFC68  thumb  ov119
 *   POKETRADE_DEMO_DOWN_PassThrough  0x021D6734  thumb  ov118
 *   POKETRADE_2D_ScheduleMainPlaneVisible  0x021E71F0  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *   POKETRADE_2D_DeleteAllOfferIconActors  0x021E64B8  thumb  ov119
 *   POKETRADE_2D_DeleteAllBoxIcons  0x021E4888  thumb  ov119
 *   POKETRADE_SAVE_DeleteOfferListWindows  0x021E2680  thumb  ov119
 *   POKETRADE_DEMO_DOWN_SetFrame  0x021D6738  thumb  ov118
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
 *   d_021D82C0     0x021D82C0  data
 *   d_021D8470     0x021D8470  data
 *   d_021D8880     0x021D8880  data
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
 *   POKETRADE_DEMO_DOWN_ReleaseUnit  0x021D66E8  thumb  ov118
 *   POKETRADE_3D_ExitParticleManager  0x021E3034  thumb  ov119
 *   POKETRADE_3D_FreeParticleResources  0x021E2F2C  thumb  ov119
 *   POKETRADE_SAVE_ResetClactAndBeginEvent  0x021DFDA0  thumb  ov119
 *   d_021D7CDC     0x021D7CDC  data a4
 *   d_021D8398     0x021D8398  data a4
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   PARTICLE_EMITTER_GetUserData  0x02051A34  arm
 *   ICA_ANIME_GetTranslate  0x02011610  thumb
 *   PARTICLE_EMITTER_SetEmitPos  0x02051838  arm
 *   POKETRADE_DEMO_DOWN_SetFinishFlag  0x021D6744  thumb  ov118
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   POKETRADE_DEMO_DOWN_StepStartPlayback  0x021D6750  thumb  ov118
 *   POKETRADE_PROC_DeleteAllResources  0x021DC720  thumb
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   POKETRADE_2D_InitClactSystemMain  0x021E3E40  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   POKETRADE_2D_SetupSummaryBgs  0x021E5284  thumb
 *   POKETRADE_3D_AddPokemonMcss  0x021E35A0  thumb ov119
 *   POKETRADE_3D_InitParticleSystems  0x021E2F34  thumb
 *   POKETRADE_3D_SetupParticleSystemsLow  0x021E2FB0  thumb ov119
 *   POKETRADE_3D_CreateIcaStreamsForMode  0x021E2D70  thumb
 *   d_021D866C  0x021D866C  data
 *   POKETRADE_3D_SetupParticleSystemsHigh  0x021E3004  thumb  ov119
 *   POKETRADE_3D_AddUnitAndInit  0x021E3208  thumb  ov119
 *   POKETRADE_DEMO_MIDDLE_UpdateScene  0x021D7130  thumb  ov118
 *   PARTICLE_EMITTER_SetCallback  0x02051A24  arm  arm9
 *   PARTICLE_EMITTER_SetUserData  0x02051A2C  arm  arm9
 *   PARTICLE_GetCallbackArg  0x02051774  arm  arm9
 *   _dfix                        0x0209C508  arm
 *   _dflt                        0x0209B750  arm
 *   _dmul                        0x0209B2E8  arm
 */
#include "pokemontrade_demo_types.h"
#include "pokemontrade_demo_up_shared_types.h"

struct WordSet;

struct MsgBank;

struct IcaAnime;

struct Rec12;

struct Bank;

struct McssFade;

typedef struct {
    u32 v[4];
} Quad;

typedef struct {
    u32 v[4];
} Tbl;

#include "pokemontrade_demo_down.h"
struct McssSlide;
#include "../ov119/pokemontrade_mcss.h"
#include "../ov119/pokemontrade_2d.h"
#include "../ov119/pokemontrade_save.h"
#include "../ov119/pokemontrade_proc.h"
struct PokemonParam;
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
#include "../arm9/particle.h"
#include "../arm9/ica_anime.h"
#include "../arm9/clact.h"
#include "../sdk_ioreg.h"
struct TradeWork;
extern void POKETRADE_DEMO_MIDDLE_UpdateScene(TradeWork *p);
void POKETRADE_DEMO_MIDDLE_StepStartPlayback(TradeWork *p);
void POKETRADE_DEMO_MIDDLE_PrintMessage(TradeWork *p);
void POKETRADE_DEMO_MIDDLE_StepMessage(TradeWork *p);
void POKETRADE_DEMO_MIDDLE_StepEndScene(TradeWork *p);
void POKETRADE_DEMO_MIDDLE_DeleteSlide(TradeWork *p, int idx);
void POKETRADE_DEMO_MIDDLE_CreateOfferSlide(TradeWork *work, int idx);
void POKETRADE_DEMO_MIDDLE_ResetMonSlide(TradeWork *p, int idx);
void POKETRADE_DEMO_MIDDLE_UpdateEmitterA(void *obj, int on);
void POKETRADE_DEMO_MIDDLE_SetupEmitterA(void *emitter);
void POKETRADE_DEMO_MIDDLE_UpdateEmitterB(void *obj, int on);
void POKETRADE_DEMO_MIDDLE_SetupEmitterB(void *emitter);
void POKETRADE_DEMO_MIDDLE_StepStartCompare(TradeWork *p);
void POKETRADE_DEMO_MIDDLE_StepSetup(TradeWork *p);
void POKETRADE_DEMO_MIDDLE_StepParticleSystems(TradeWork *p);
void POKETRADE_DEMO_MIDDLE_StepAddUnit(TradeWork *p);
extern const u8 d_021D82C0[];
extern const u8 d_021D8470[];
extern u8 d_021D8880[];
extern const Quad d_021D7CDC;
extern const u32 d_021D8398[];
extern const char d_021D866C[];


void POKETRADE_DEMO_MIDDLE_StepStartPlayback(TradeWork *work)
{
    void *mon;
    u32 a;
    u32 b;
    PokemontradeDemoVec differentMonPos;
    PokemontradeDemoVec sameMonPos;
    u32 buf;

    POKETRADE_DEMO_DOWN_StepFade(*(s8 * *)&work->fade);
    POKETRADE_MCSS_SlideUpdate(work->slide[0], work);
    POKETRADE_MCSS_SlideUpdate(work->slide[1], work);
    if (work->waitCounter > POKETRADE_DEMO_DOWN_PassThrough(0x2A)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(work, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(work, 0);
        POKETRADE_2D_DeleteAllOfferIconActors(work);
        POKETRADE_2D_DeleteAllBoxIcons(work);
        POKETRADE_SAVE_DeleteOfferListWindows(work);
        POKETRADE_DEMO_DOWN_SetFrame(work, 0);
        mon = POKETRADE_PROC_GetSideMon(work, POKETRADE_PROC_IsHostSide(work));
        POKE_TOOL_GetPartyValue(mon, 7, 0);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
            b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
            PM_VOICE_GetPerapVoiceSave((struct SaveBlock **)(&buf));
            PM_VOICE_Play(a, b, 0x40, 0, 0, 0, 0, (void **)(&buf));
        }
        if (work->slide[0] != 0) {
            GFL_HEAP_Free((void *)work->slide[0]);
            work->slide[0] = 0;
        }
        if (work->enemySameMon == 0) {
            MCSS_GetPosition((void *)work->mcssPokemon[0], (u32 *)(&differentMonPos));
            POKETRADE_SAVE_FreeIfSet((u32 *)work->slide[0]);
            if (work->enemySpecialMon != 0) {
                work->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets((void *)work->mcssPokemon[0], 0x14, &differentMonPos, d_021D8880, work->heapId);
            } else {
                work->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets((void *)work->mcssPokemon[0], 0x12, &differentMonPos, (void *)d_021D82C0, work->heapId);
            }
            POKETRADE_3D_AddPokemonMcssPlain(work, 2, 0, POKETRADE_PROC_GetSideMon(work, POKETRADE_PROC_IsHostSide(work)), 1);
            MCSS_SetAnmStopFlag((void *)work->mcssPokemon[2]);
            MCSS_SetVanishFlag((void *)work->mcssPokemon[2]);
        } else {
            MCSS_GetPosition((void *)work->mcssPokemon[0], (u32 *)(&sameMonPos));
            POKETRADE_SAVE_FreeIfSet((u32 *)work->slide[0]);
            if (work->enemySpecialMon != 0) {
                work->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets((void *)work->mcssPokemon[0], 0x14, &sameMonPos, d_021D8880, work->heapId);
            } else {
                work->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets((void *)work->mcssPokemon[0], 0x28, &sameMonPos, (void *)d_021D8470, work->heapId);
            }
        }
        POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_MIDDLE_StepMessage);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_MIDDLE_PrintMessage(TradeWork *work)
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


void POKETRADE_DEMO_MIDDLE_StepMessage(TradeWork *work)
{
    PokemontradeDemoVec v;

    if (work->waitCounter == 10) {
        POKETRADE_DEMO_MIDDLE_PrintMessage(work);
    }
    if (work->enemySameMon == 0 && work->waitCounter == 6) {
        MCSS_GetPosition((void *)work->mcssPokemon[0], (u32 *)(&v));
        MCSS_SetPosition((void *)work->mcssPokemon[2], (u32 *)(&v));
        MCSS_ResetVanishFlag((void *)work->mcssPokemon[2]);
        MCSS_SetVanishFlag((void *)work->mcssPokemon[0]);
        MCSS_ResetAnmStopFlag((void *)work->mcssPokemon[2]);
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
            GFL_HEAP_Free((void *)work->slide[0]);
            work->slide[0] = 0;
        }
        POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_MIDDLE_StepSetup);
    }
    POKETRADE_MCSS_SlideUpdate((void *)work->slide[0], work);
}


void POKETRADE_DEMO_MIDDLE_StepEndScene(TradeWork *work)
{
    POKETRADE_DEMO_DOWN_ReleaseUnit(work);
    POKETRADE_3D_ExitParticleManager(work->particleManager, 6);
    POKETRADE_3D_FreeParticleResources(work->particleManager);
    GFL_HEAP_Free(work->particleManager);
    work->particleManager = 0;
    POKETRADE_PROC_SetStep(work, POKETRADE_SAVE_ResetClactAndBeginEvent);
}


void POKETRADE_DEMO_MIDDLE_DeleteSlide(TradeWork *work, int idx)
{
    void *q = work->slide[0];
    if (q != 0) {
        GFL_HEAP_Free(q);
        work->slide[0] = 0;
    }
}


/*
 * Lever: own callee 021DFBB4 takes the table as argument four and u16 heap
 * as argument five. Correct order and a word-aligned three-word output
 * buffer settle the saved registers; nonzero 11F0 arms come first. Bare
 * aligned data hints resolve the contested table through sole-ref/data.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_MIDDLE_CreateOfferSlide(TradeWork *work, int idx)
{
    void *x;
    u32 buf[3];

    x = POKETRADE_PROC_GetSideMon(work, 1 - POKETRADE_PROC_IsHostSide(work));
    POKE_TOOL_GetPartyValue(x, 7, 0);
    if (POKE_TOOL_GetPartyValue(x, 0x4c, 0) == 0) {
        PM_VOICE_Play(POKE_TOOL_GetPartyValue(x, 0xab, 0), POKE_TOOL_GetPartyValue(x, 0x6f, 0),
                      0x40, 0, 0, 0, 0, 0);
    }
    if (work->ownSameMon == 0) {
        MCSS_GetPosition(((void **)&work->mcssPokemon[0])[idx], buf);
        POKETRADE_SAVE_FreeIfSet(work->slide[3]);
        if (work->ownSpecialMon != 0)
            work->slide[3] =
                POKETRADE_MCSS_SlideCreateWithOffsets(((void **)&work->mcssPokemon[0])[idx], 0x14, buf, (void *)d_021D8880, work->heapId);
        else
            work->slide[3] =
                POKETRADE_MCSS_SlideCreateWithOffsets(((void **)&work->mcssPokemon[0])[idx], 0x28, buf, (void *)d_021D8470, work->heapId);
        return;
    } else {
        Quad t;
        void *r6;

        t = d_021D7CDC;
        r6 = ((void **)&work->mcssPokemon[0])[t.v[idx]];
        MCSS_GetPosition(((void **)&work->mcssPokemon[0])[idx], buf);
        POKETRADE_SAVE_FreeIfSet(work->slide[3]);
        if (work->ownSpecialMon != 0)
            work->slide[3] =
                POKETRADE_MCSS_SlideCreateWithOffsets(r6, 0x14, buf, (void *)d_021D8880, work->heapId);
        else
            work->slide[3] =
                POKETRADE_MCSS_SlideCreateWithOffsets(r6, 0x12, buf, (void *)d_021D8398, work->heapId);
    }
}


void POKETRADE_DEMO_MIDDLE_ResetMonSlide(TradeWork *work, int idx)
{
    u32 vec[3];
    MCSS_ResetVanishFlag(((void **)&work->mcssPokemon[0])[idx]);
    vec[0] = 0;
    vec[1] = 0xFFFE9000;
    vec[2] = 0xA000;
    MCSS_SetPosition(((void **)&work->mcssPokemon[0])[idx], vec);
    MCSS_SetAnmStopFlag(((void **)&work->mcssPokemon[0])[idx]);
    MCSS_GetScale(((void **)&work->mcssPokemon[0])[idx], vec);
    vec[0] = ((s32)vec[0] < 0) ? 0xFFFF0000 : 0x10000;
    vec[1] = 0x10000;
    vec[2] = 0x1000;
    MCSS_SetScale(((void **)&work->mcssPokemon[0])[idx], vec);
}


void POKETRADE_DEMO_MIDDLE_UpdateEmitterA(void *obj, int on)
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
            ICA_ANIME_GetTranslate((struct IcaAnime *)(((PokeTradeButtonData *)w)->anim->anime), (struct VecFx32 *)v);
            PARTICLE_EMITTER_SetEmitPos((struct Obj3D *)obj, (const Vec3 *)v);
        }
    }
}


void POKETRADE_DEMO_MIDDLE_SetupEmitterA(void *emitter)
{
    PARTICLE_EMITTER_SetUserData(emitter, PARTICLE_GetCallbackArg());
    PARTICLE_EMITTER_SetCallback(emitter, POKETRADE_DEMO_MIDDLE_UpdateEmitterA);
}


void POKETRADE_DEMO_MIDDLE_UpdateEmitterB(void *obj, int on)
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
            ICA_ANIME_GetTranslate((struct IcaAnime *)(((PokeTradeButtonData *)w)->anim->animeB), (struct VecFx32 *)v);
            PARTICLE_EMITTER_SetEmitPos((struct Obj3D *)obj, (const Vec3 *)v);
        }
    }
}


void POKETRADE_DEMO_MIDDLE_SetupEmitterB(void *emitter)
{
    PARTICLE_EMITTER_SetUserData(emitter, PARTICLE_GetCallbackArg());
    PARTICLE_EMITTER_SetCallback(emitter, POKETRADE_DEMO_MIDDLE_UpdateEmitterB);
}


void POKETRADE_DEMO_MIDDLE_StepStartCompare(TradeWork *work)
{
    void *t;

    POKETRADE_DEMO_DOWN_SetFinishFlag(work);
    work->mcssAnimStopped = 1;
    MCSS_SetAnimeIndex((void *)work->mcssPokemon[0], 0);
    work->peerSceneStarted = 1;
    MCSS_SetAnimeIndex((void *)work->mcssPokemon[1], 0);
    if (POKETRADE_PROC_IsHostSide(work)) {
        t = work->mcssPokemon[0];
        work->mcssPokemon[0] = work->mcssPokemon[1];
        work->mcssPokemon[1] = t;
    }
    POKETRADE_DEMO_DOWN_SetFrame(work, 0);
    POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_DOWN_StepStartPlayback);
}


void POKETRADE_DEMO_MIDDLE_StepSetup(TradeWork *work)
{
    POKETRADE_PROC_DeleteAllResources(work);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain(work);
    work->clactSystem = CLACT_CreateUnit(3, 0, work->heapId);
    work->particleManager = GFL_HEAP_Alloc(work->heapId, sizeof(ParticleManager), 1, d_021D866C, 0x9D);
    work->particleManager->heap = work->heapId;
    POKETRADE_2D_SetupSummaryBgs(work, 0);
    *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0;
    *(volatile u16 *)REG_BLDCNT_ADDR = 0;
    if (POKETRADE_PROC_IsHostSide(work)) {
        POKETRADE_3D_AddPokemonMcss((struct TradeWork *)work, 1, 0, POKETRADE_PROC_GetSideMon(work, 1), 0);
        POKETRADE_3D_AddPokemonMcss((struct TradeWork *)work, 2, 0, POKETRADE_PROC_GetSideMon(work, 0), 0);
        POKETRADE_3D_AddPokemonMcss((struct TradeWork *)work, 3, 1, POKETRADE_PROC_GetSideMon(work, 1), 0);
    } else {
        POKETRADE_3D_AddPokemonMcssPlain(work, 1, 0, POKETRADE_PROC_GetSideMon(work, 1), 0);
        POKETRADE_3D_AddPokemonMcssPlain(work, 2, 0, POKETRADE_PROC_GetSideMon(work, 0), 0);
        POKETRADE_3D_AddPokemonMcssPlain(work, 3, 1, POKETRADE_PROC_GetSideMon(work, 1), 0);
    }
    MCSS_GetScale((void *)work->mcssPokemon[0], (u32 *)&work->particleManager->slotScale[0]);
    MCSS_GetScale((void *)work->mcssPokemon[1], (u32 *)&work->particleManager->slotScale[1]);
    MCSS_GetScale((void *)work->mcssPokemon[2], (u32 *)&work->particleManager->slotScale[2]);
    MCSS_GetScale((void *)work->mcssPokemon[3], (u32 *)&work->particleManager->slotScale[3]);
    MCSS_SetVanishFlag((void *)work->mcssPokemon[1]);
    MCSS_SetVanishFlag((void *)work->mcssPokemon[2]);
    MCSS_SetVanishFlag((void *)work->mcssPokemon[3]);
    POKETRADE_3D_InitParticleSystems(work->particleManager);
    POKETRADE_3D_SetupParticleSystemsLow(work->particleManager);
    POKETRADE_3D_CreateIcaStreamsForMode(work->particleManager, 0);
    POKETRADE_DEMO_DOWN_SetFrame(work, 0);
    POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_MIDDLE_StepParticleSystems);
}


void POKETRADE_DEMO_MIDDLE_StepParticleSystems(TradeWork *work)
{
    POKETRADE_3D_SetupParticleSystemsHigh(work->particleManager);
    POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_MIDDLE_StepAddUnit);
}


void POKETRADE_DEMO_MIDDLE_StepAddUnit(TradeWork *work)
{
    POKETRADE_3D_AddUnitAndInit(work, 3);
    POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_MIDDLE_UpdateScene);
}


#include "../ov119/pokemontrade_nego.h"
#include "../arm9/wipe.h"
extern const Tbl d_021D7CEC;


/* Middle demo playback step: 3D unit swaps, MCSS slides, particles and wipes. */
void POKETRADE_DEMO_MIDDLE_UpdateScene(TradeWork *work)
{
    PokemontradeDemoVec ownVec, peerVec, slideBeginVec, swapVec, leftMonVec, rightMonVec, exitVec;
    Tbl t;
    PokemontradeDemoVec copyPosVec;
    int idx, idx2, idx3, idx4, a, b, b2, a2, k;
    u32 r;

    POKETRADE_NEGO_PlaySeByKeyA(work->waitCounter);
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x12D)) {
        POKETRADE_3D_RemoveCurrentUnit(work);
        POKETRADE_3D_AddUnitAndInit(work, 4);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x2B6)) {
        POKETRADE_3D_RemoveCurrentUnit(work);
        POKETRADE_3D_AddUnitAndInit(work, 5);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(1)) {
        MCSS_SetPaletteFade((struct McssWork *)work->mcssPokemon[0], 8, 8, 0, 0xFFFF);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(2)) {
        MCSS_SetPaletteFade((struct McssWork *)work->mcssPokemon[0], 0x10, 0x10, 0, 0xFFFF);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(3)) {
        POKETRADE_DEMO_DOWN_LoadUnitResources(work);
        POKETRADE_DEMO_DOWN_CreateUnitActor(work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(4)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(work, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(work, 0x18);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(4)) {
        MCSS_SetVanishFlag((void *)work->mcssPokemon[0]);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)(work->particleManager->system[0]), 10, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x65)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)(work->particleManager->system[1]), 1, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)(work->particleManager->system[2]), 2, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)(work->particleManager->system[8]), 2, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0xE)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)(work->particleManager->system[3]), 3, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x483)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)(work->particleManager->system[7]), 3, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)(work->particleManager->system[4]), 4, POKETRADE_DEMO_MIDDLE_SetupEmitterA, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x152)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)(work->particleManager->system[5]), 5, 0, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x2BC)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)(work->particleManager->system[6]), 6, POKETRADE_DEMO_MIDDLE_SetupEmitterB, work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x47F)) {
        POKETRADE_DEMO_DOWN_CreateUnitActor(work);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x10A)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, (u32)POKETRADE_DEMO_DOWN_PassThrough(0x14), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x130)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, (u32)POKETRADE_DEMO_DOWN_PassThrough(0x19), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x149)) {
        POKETRADE_3D_DeleteMcssSlot(work, 0);
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            POKETRADE_3D_AddPokemonMcss((struct TradeWork *)work, 0, 1, POKETRADE_PROC_GetSideMon(work, 0), 0);
        } else {
            POKETRADE_3D_AddPokemonMcssPlain(work, 0, 1, POKETRADE_PROC_GetSideMon(work, 0), 0);
        }
        MCSS_GetScale((void *)work->mcssPokemon[0], (u32 *)&work->particleManager->slotScale[0]);
        MCSS_SetVanishFlag((void *)work->mcssPokemon[0]);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x14A)) {
        idx = 2;
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            idx = 1;
        }
        MCSS_ResetVanishFlag((void *)work->mcssPokemon[idx]);
        ownVec.x = -0x32000;
        ownVec.y = -0x96000;
        ownVec.z = 0xA000;
        MCSS_SetPosition((void *)work->mcssPokemon[idx], (u32 *)(&ownVec));
        ownVec.x = -0x32000;
        ownVec.y = -0x37000;
        ownVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)work->slide[0]);
        work->slide[0] = POKETRADE_MCSS_SlideCreate((void *)work->mcssPokemon[idx], POKETRADE_DEMO_DOWN_PassThrough(0xF), &ownVec, work->heapId);
        MCSS_SetAnmStopFlag((void *)work->mcssPokemon[idx]);
        ownVec.x = work->particleManager->slotScale[idx].x * 1.2;
        ownVec.y = work->particleManager->slotScale[idx].y * 1.2;
        ownVec.z = work->particleManager->slotScale[idx].z;
        MCSS_SetScale((void *)work->mcssPokemon[idx], (u32 *)(&ownVec));
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x14B)) {
        idx2 = 3;
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            idx2 = 0;
        }
        MCSS_ResetVanishFlag((void *)work->mcssPokemon[idx2]);
        peerVec.x = 0x3C000;
        peerVec.y = 0x50000;
        peerVec.z = -0xA000;
        MCSS_SetPosition((void *)work->mcssPokemon[idx2], (u32 *)(&peerVec));
        peerVec.x = 0x3C000;
        peerVec.y = 0x5000;
        peerVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)work->slide[1]);
        work->slide[1] = POKETRADE_MCSS_SlideCreate((void *)work->mcssPokemon[idx2], POKETRADE_DEMO_DOWN_PassThrough(0xF), &peerVec, work->heapId);
        MCSS_SetAnmStopFlag((void *)work->mcssPokemon[idx2]);
        peerVec.x = work->particleManager->slotScale[idx2].x * 1.2;
        peerVec.y = work->particleManager->slotScale[idx2].y * 1.2;
        peerVec.z = work->particleManager->slotScale[idx2].z;
        MCSS_SetScale((void *)work->mcssPokemon[idx2], (u32 *)(&peerVec));
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x154)) {
        slideBeginVec.x = -0x32000;
        slideBeginVec.y = -0x37000;
        slideBeginVec.z = 0xA000;
        POKETRADE_MCSS_SlideBegin((void *)work->slide[0], POKETRADE_DEMO_DOWN_PassThrough(0x1C), &slideBeginVec);
        slideBeginVec.x = 0x3C000;
        slideBeginVec.y = 0x5000;
        slideBeginVec.z = -0xA000;
        POKETRADE_MCSS_SlideBegin((void *)work->slide[1], POKETRADE_DEMO_DOWN_PassThrough(0x1C), &slideBeginVec);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x170)) {
        GFL_HEAP_Free((void *)work->slide[0]);
        work->slide[0] = 0;
        GFL_HEAP_Free((void *)work->slide[1]);
        work->slide[1] = 0;
        a = 2;
        b = 3;
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            b = 0;
        }
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            a = 1;
        }
        swapVec.x = -0x96000;
        swapVec.y = -0x37000;
        swapVec.z = 0;
        POKETRADE_SAVE_FreeIfSet((u32 *)work->slide[0]);
        work->slide[0] = POKETRADE_MCSS_SlideCreate((void *)work->mcssPokemon[a], POKETRADE_DEMO_DOWN_PassThrough(0x2E), &swapVec, work->heapId);
        swapVec.x = 0x96000;
        swapVec.y = 0x5000;
        swapVec.z = 0;
        POKETRADE_SAVE_FreeIfSet((u32 *)work->slide[1]);
        work->slide[1] = POKETRADE_MCSS_SlideCreate((void *)work->mcssPokemon[b], POKETRADE_DEMO_DOWN_PassThrough(0x2E), &swapVec, work->heapId);
        work->slide[0]->wobbleEnabled = 1;
        work->slide[1]->wobbleEnabled = 1;
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x1B2)) {
        idx3 = 0;
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            idx3 = 3;
        }
        GFL_HEAP_Free((void *)work->slide[0]);
        work->slide[0] = 0;
        MCSS_ResetVanishFlag((void *)work->mcssPokemon[idx3]);
        MCSS_SetPaletteFade((struct McssWork *)work->mcssPokemon[idx3], 0, 0, 0, 0x7FFF);
        leftMonVec.x = -0x96000;
        leftMonVec.y = 0x5000;
        leftMonVec.z = -0xA000;
        MCSS_SetPosition((void *)work->mcssPokemon[idx3], (u32 *)(&leftMonVec));
        leftMonVec.x = 0x3C000;
        leftMonVec.y = 0x5000;
        leftMonVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)work->slide[0]);
        work->slide[0] = POKETRADE_MCSS_SlideCreate((void *)work->mcssPokemon[idx3], POKETRADE_DEMO_DOWN_PassThrough(0x67), &leftMonVec, work->heapId);
        leftMonVec.x = work->particleManager->slotScale[idx3].x * 1.2;
        leftMonVec.y = work->particleManager->slotScale[idx3].y * 1.2;
        leftMonVec.z = work->particleManager->slotScale[idx3].z;
        MCSS_SetScale((void *)work->mcssPokemon[idx3], (u32 *)(&leftMonVec));
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x1B2)) {
        idx4 = 1;
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            idx4 = 2;
        }
        GFL_HEAP_Free((void *)work->slide[1]);
        work->slide[1] = 0;
        MCSS_ResetVanishFlag((void *)work->mcssPokemon[idx4]);
        rightMonVec.x = 0x96000;
        rightMonVec.y = -0x37000;
        rightMonVec.z = 0xA000;
        MCSS_SetPosition((void *)work->mcssPokemon[idx4], (u32 *)(&rightMonVec));
        rightMonVec.x = -0x2D000;
        rightMonVec.y = -0x37000;
        rightMonVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)work->slide[1]);
        work->slide[1] = POKETRADE_MCSS_SlideCreate((void *)work->mcssPokemon[idx4], POKETRADE_DEMO_DOWN_PassThrough(0x67), &rightMonVec, work->heapId);
        rightMonVec.x = work->particleManager->slotScale[idx4].x * 1.2;
        rightMonVec.y = work->particleManager->slotScale[idx4].y * 1.2;
        rightMonVec.z = work->particleManager->slotScale[idx4].z;
        MCSS_SetScale((void *)work->mcssPokemon[idx4], (u32 *)(&rightMonVec));
        work->slide[0]->wobbleEnabled = 1;
        work->slide[1]->wobbleEnabled = 1;
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x1F8)) {
        POKETRADE_MCSS_SlideBegin((void *)work->slide[0], POKETRADE_DEMO_DOWN_PassThrough(0x80), (void *)(&work->slide[0]->target));
        POKETRADE_MCSS_SlideBegin((void *)work->slide[1], POKETRADE_DEMO_DOWN_PassThrough(0x80), (void *)(&work->slide[1]->target));
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x27D)) {
        b2 = 1;
        a2 = 0;
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            a2 = 3;
        }
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            b2 = 2;
        }
        POKETRADE_DEMO_MIDDLE_DeleteSlide(work, 0);
        POKETRADE_DEMO_MIDDLE_DeleteSlide(work, 1);
        exitVec.x = 0x3C000;
        exitVec.y = 0x64000;
        exitVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)work->slide[0]);
        work->slide[0] = POKETRADE_MCSS_SlideCreate((void *)work->mcssPokemon[a2], POKETRADE_DEMO_DOWN_PassThrough(7), &exitVec, work->heapId);
        exitVec.x = -0x2D000;
        exitVec.y = -0xA0000;
        exitVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)work->slide[1]);
        work->slide[1] = POKETRADE_MCSS_SlideCreate((void *)work->mcssPokemon[b2], POKETRADE_DEMO_DOWN_PassThrough(7), &exitVec, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x2B5)) {
        MCSS_SetVanishFlag((void *)work->mcssPokemon[0]);
        MCSS_SetVanishFlag((void *)work->mcssPokemon[1]);
        MCSS_SetVanishFlag((void *)work->mcssPokemon[2]);
        MCSS_SetVanishFlag((void *)work->mcssPokemon[3]);
    }
    t = d_021D7CEC;
    k = 3;
    if (POKETRADE_PROC_IsHostSide(work) != 0) {
        k = 0;
    }
    r = t.v[k];
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x48E)) {
        if (work->ownSameMon == 0) {
            POKETRADE_DEMO_MIDDLE_ResetMonSlide(work, k);
            POKETRADE_DEMO_MIDDLE_CreateOfferSlide(work, k);
            MCSS_SetPaletteFade((struct McssWork *)work->mcssPokemon[k], 0x10, 0x10, 0, 0x7FFF);
        } else {
            POKETRADE_DEMO_MIDDLE_ResetMonSlide(work, k);
            MCSS_SetVanishFlag((void *)work->mcssPokemon[k]);
            POKETRADE_DEMO_MIDDLE_ResetMonSlide(work, r);
            POKETRADE_DEMO_MIDDLE_CreateOfferSlide(work, k);
            MCSS_SetPaletteFade((struct McssWork *)work->mcssPokemon[r], 0x10, 0x10, 0, 0x7FFF);
        }
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x48F)) {
        MCSS_SetPaletteFade((struct McssWork *)work->mcssPokemon[k], 8, 8, 0, 0x7FFF);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x490)) {
        MCSS_SetPaletteFade((struct McssWork *)work->mcssPokemon[k], 0, 0, 0, 0x7FFF);
    }
    if (POKETRADE_DEMO_DOWN_PassThrough(0x48E) < work->waitCounter && work->ownSameMon != 0 && work->slide[3] != 0
        && work->slide[3]->frame == 9) {
        MCSS_GetPosition((void *)work->mcssPokemon[r], (u32 *)(&copyPosVec));
        MCSS_SetPosition((void *)work->mcssPokemon[k], (u32 *)(&copyPosVec));
        MCSS_ResetVanishFlag((void *)work->mcssPokemon[k]);
        MCSS_SetVanishFlag((void *)work->mcssPokemon[r]);
        work->slide[3]->mcss = work->mcssPokemon[k];
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x4A0)) {
        MCSS_ResetAnmStopFlag((void *)work->mcssPokemon[k]);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x28B)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, (u32)POKETRADE_DEMO_DOWN_PassThrough(0xA), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x2B8)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, (u32)POKETRADE_DEMO_DOWN_PassThrough(0x19), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x380)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, (u32)POKETRADE_DEMO_DOWN_PassThrough(0x1E), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x3CA)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, (u32)POKETRADE_DEMO_DOWN_PassThrough(0x1E), 1, work->heapId);
    }
    if (work->waitCounter == POKETRADE_DEMO_DOWN_PassThrough(0x4C1)) {
        POKETRADE_DEMO_MIDDLE_DeleteSlide(work, 0);
        POKETRADE_DEMO_MIDDLE_DeleteSlide(work, 1);
        POKETRADE_3D_RemoveCurrentUnit(work);
        POKETRADE_PROC_SetStep(work, POKETRADE_DEMO_MIDDLE_StepEndScene);
    }
    POKETRADE_MCSS_SlideUpdate((void *)work->slide[0], work);
    POKETRADE_MCSS_SlideUpdate((void *)work->slide[1], work);
    POKETRADE_MCSS_SlideUpdate(work->slide[2], work);
    POKETRADE_MCSS_SlideUpdate(work->slide[3], work);
}
