/*
 * file:     pokemontrade_ircdemo.c
 * unit:     yes
 * function: POKETRADE_IRCDEMO_StepStartPlayback, POKETRADE_IRCDEMO_PrintMessage, POKETRADE_IRCDEMO_StepMessage, POKETRADE_IRCDEMO_StepEndScene, POKETRADE_IRCDEMO_SetMonSlide, POKETRADE_IRCDEMO_CreateOfferSlide, POKETRADE_IRCDEMO_StepStartCompare, POKETRADE_IRCDEMO_StepSetup, POKETRADE_IRCDEMO_UpdateScene
 * address:  0x021D4664
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   POKETRADE_DEMO_COMMON_StepFade  0x021D4240  thumb  ov117
 *   POKETRADE_DEMO_COMMON_ShowUnitActor  0x021D434C  thumb  ov117
 *   POKETRADE_DEMO_COMMON_LoadUnitResources  0x021D43C8  thumb  ov117
 *   POKETRADE_MCSS_SlideUpdate  0x021DFC68  thumb  ov119
 *   POKETRADE_DEMO_COMMON_PassThrough  0x021D4480  thumb  ov117
 *   POKETRADE_2D_ScheduleMainPlaneVisible  0x021E71F0  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *   POKETRADE_2D_DeleteAllOfferIconActors  0x021E64B8  thumb  ov119
 *   POKETRADE_2D_DeleteAllBoxIcons  0x021E4888  thumb  ov119
 *   POKETRADE_SAVE_DeleteOfferListWindows  0x021E2680  thumb  ov119
 *   POKETRADE_DEMO_COMMON_SetFrame  0x021D4484  thumb  ov117
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
 *   d_021D5220     0x021D5220  data
 *   d_021D53D0     0x021D53D0  data
 *   d_021D5600     0x021D5600  data
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
 *   POKETRADE_DEMO_COMMON_ReleaseUnit  0x021D4434  thumb  ov117
 *   POKETRADE_3D_ExitParticleManager  0x021E3034  thumb  ov119
 *   POKETRADE_3D_FreeParticleResources  0x021E2F2C  thumb  ov119
 *   POKETRADE_SAVE_ResetClactAndBeginEvent  0x021DFDA0  thumb  ov119
 *   MCSS_SetAlpha  0x02015FBC  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   d_021D5200     0x021D5200  data
 *   d_021D52F8     0x021D52F8  data
 *   POKETRADE_DEMO_COMMON_SetFinishFlag  0x021D4490  thumb  ov117
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   POKETRADE_DEMO_COMMON_StepCompareMons  0x021D449C  thumb  ov117
 *   d_021D51DC     0x021D51DC  data
 *   POKETRADE_PROC_DeleteAllResources  0x021DC720  thumb  ov119
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   POKETRADE_2D_InitClactSystemMain  0x021E3E40  thumb  ov119
 *   CLACT_CreateUnit  0x0204B100  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   POKETRADE_2D_SetupSummaryBgs  0x021E5284  thumb  ov119
 *   POKETRADE_3D_AddUnitAndInit  0x021E3208  thumb  ov119
 *   MCSS_GetScale  0x02015C94  thumb
 *   POKETRADE_3D_InitTradeParticleSet  0x021E3070  thumb  ov119
 *   POKETRADE_3D_CreateIcaStreamsEnding  0x021E2EFC  thumb  ov119
 *   POKETRADE_IRCDEMO_UpdateScene  0x021D4CE8  thumb  ov117
 *   d_021D55CC     0x021D55CC  data
 */
#include "../ov118/pokemontrade_demo_types.h"

struct WordSet;
struct MsgBank;
struct McssFade;
struct Bank;
#include "../types.h"

typedef struct {
    u32 v[4];
} Quad;

#include "pokemontrade_demo_common.h"
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
#include "../arm9/clact.h"
#include "../sdk_ioreg.h"
extern void POKETRADE_IRCDEMO_UpdateScene(TradeWork *p);
void POKETRADE_IRCDEMO_StepStartPlayback(TradeWork *p);
void POKETRADE_IRCDEMO_PrintMessage(TradeWork *p);
void POKETRADE_IRCDEMO_StepMessage(TradeWork *p);
void POKETRADE_IRCDEMO_StepEndScene(TradeWork *p);
void POKETRADE_IRCDEMO_SetMonSlide(void *obj, TradeWork *p);
void POKETRADE_IRCDEMO_CreateOfferSlide(TradeWork *p, int idx);
void POKETRADE_IRCDEMO_StepStartCompare(TradeWork *p);
void POKETRADE_IRCDEMO_StepSetup(TradeWork *p);
extern const u8 d_021D5220[];
extern const u8 d_021D53D0[];
extern u8 d_021D5600[];
extern const Quad d_021D5200;
extern const u8 d_021D52F8[];
extern const PokemontradeDemoVec d_021D51DC;
extern const char d_021D55CC[];

void POKETRADE_IRCDEMO_StepStartPlayback(TradeWork *p)
{
    void *mon;
    u32 a;
    u32 b;
    PokemontradeDemoVec monPos;
    PokemontradeDemoVec monPosShared;
    u32 buf;

    POKETRADE_DEMO_COMMON_StepFade(*(s8 * *)&p->fade);
    POKETRADE_MCSS_SlideUpdate((void *)(p->slide[0]), p);
    POKETRADE_MCSS_SlideUpdate((void *)(p->slide[1]), p);
    if (p->waitCounter > POKETRADE_DEMO_COMMON_PassThrough(0x2A)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0);
        POKETRADE_2D_DeleteAllOfferIconActors(p);
        POKETRADE_2D_DeleteAllBoxIcons(p);
        POKETRADE_SAVE_DeleteOfferListWindows(p);
        POKETRADE_DEMO_COMMON_SetFrame(p, 0);
        mon = POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p));
        POKE_TOOL_GetPartyValue(mon, 7, 0);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
            b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
            PM_VOICE_GetPerapVoiceSave((struct SaveBlock **)(&buf));
            PM_VOICE_Play(a, b, 0x40, 0, 0, 0, 0, (void **)(&buf));
        }
        if (p->slide[0] != 0) {
            GFL_HEAP_Free((void *)p->slide[0]);
            p->slide[0] = 0;
        }
        if (p->enemySameMon == 0) {
            MCSS_GetPosition((void *)p->mcssPokemon[0], (u32 *)(&monPos));
            POKETRADE_SAVE_FreeIfSet((u32 *)p->slide[0]);
            if (p->enemySpecialMon != 0) {
                p->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets((void *)p->mcssPokemon[0], 0x14, &monPos, d_021D5600, p->heapId);
            } else {
                p->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets((void *)p->mcssPokemon[0], 0x12, &monPos, (void *)d_021D5220, p->heapId);
            }
            POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)), 1);
            MCSS_SetAnmStopFlag((void *)p->mcssPokemon[2]);
            MCSS_SetVanishFlag((void *)p->mcssPokemon[2]);
        } else {
            MCSS_GetPosition((void *)p->mcssPokemon[0], (u32 *)(&monPosShared));
            POKETRADE_SAVE_FreeIfSet((u32 *)p->slide[0]);
            if (p->enemySpecialMon != 0) {
                p->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets((void *)p->mcssPokemon[0], 0x14, &monPosShared, d_021D5600, p->heapId);
            } else {
                p->slide[0] = POKETRADE_MCSS_SlideCreateWithOffsets((void *)p->mcssPokemon[0], 0x28, &monPosShared, (void *)d_021D53D0, p->heapId);
            }
        }
        POKETRADE_PROC_SetStep(p, POKETRADE_IRCDEMO_StepMessage);
    }
}

void POKETRADE_IRCDEMO_PrintMessage(TradeWork *p)
{
    GFL_NET_RefreshWmIconAtTopRight(0, p->heapId);
    if (p->tradeState == 6) {
        MSGDATA_ReadString((struct MsgBank *)(p->messageBank), 0x98, (void *)(p->messageTemplate));
    } else if (p->tradeState == 8) {
        MSGDATA_ReadString((struct MsgBank *)(p->messageBank), 0x9B, (void *)(p->messageTemplate));
    } else if (p->enemySameMon != 0) {
        MSGDATA_ReadString((struct MsgBank *)(p->messageBank), 0x82, (void *)(p->messageTemplate));
    } else {
        MSGDATA_ReadString((struct MsgBank *)(p->messageBank), 0x81, (void *)(p->messageTemplate));
    }
    WORDSET_SetSlotMonNickname(p->wordSet, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)));
    WORDSET_SetSlotMyStatus(p->wordSet, 1, (void *)(p->playerStatus));
    WORDSET_CopyTaggedText(p->wordSet, (void *)(p->messageText), (void *)(p->messageTemplate));
    BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x18, 0x11);
    POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
    POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x14);
    *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0;
}

void POKETRADE_IRCDEMO_StepMessage(TradeWork *p)
{
    PokemontradeDemoVec v;

    if (p->waitCounter == 10) {
        POKETRADE_IRCDEMO_PrintMessage(p);
    }
    if (p->enemySameMon == 0 && p->waitCounter == 6) {
        MCSS_GetPosition((void *)p->mcssPokemon[0], (u32 *)(&v));
        MCSS_SetPosition((void *)p->mcssPokemon[2], (u32 *)(&v));
        MCSS_ResetVanishFlag((void *)p->mcssPokemon[2]);
        MCSS_SetVanishFlag((void *)p->mcssPokemon[0]);
        MCSS_ResetAnmStopFlag((void *)p->mcssPokemon[2]);
        p->slide[0]->mcss = p->mcssPokemon[2];
    }
    if (p->waitCounter > 0xC8 && POKETRADE_SAVE_IsMessagePrintDone(p) != 0) {
        POKETRADE_SAVE_CloseMessageWindowClear(p);
        if (p->enemySameMon == 0) {
            POKETRADE_3D_DeleteMcssSlot(p, 0);
            p->mcssPokemon[0] = p->mcssPokemon[2];
            p->mcssPokemon[2] = 0;
        }
        if (p->slide[0] != 0) {
            GFL_HEAP_Free((void *)p->slide[0]);
            p->slide[0] = 0;
        }
        POKETRADE_PROC_SetStep(p, POKETRADE_IRCDEMO_StepSetup);
    }
    POKETRADE_MCSS_SlideUpdate((void *)p->slide[0], p);
}

void POKETRADE_IRCDEMO_StepEndScene(TradeWork *p)
{
    POKETRADE_DEMO_COMMON_ReleaseUnit(p);
    POKETRADE_3D_ExitParticleManager(p->particleManager, 6);
    POKETRADE_3D_FreeParticleResources(p->particleManager);
    GFL_HEAP_Free(p->particleManager);
    p->particleManager = 0;
    POKETRADE_PROC_SetStep(p, POKETRADE_SAVE_ResetClactAndBeginEvent);
}

void POKETRADE_IRCDEMO_SetMonSlide(void *obj, TradeWork *p)
{
    PokemontradeDemoVec v;
    MCSS_SetAlpha(obj, 0x1f);
    MCSS_ResetVanishFlag(obj);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xa000;
    MCSS_SetPosition(obj, (u32 *)(&v));
    MCSS_SetAnmStopFlag(obj);
    MCSS_SetScale(obj, (u32 *)&p->particleManager->position);
    MCSS_SetPaletteFade(obj, 0x10, 0x10, 0, 0x7fff);
}

/*
 * Addresses are Black-image addresses.
 * The ((u32 *)(p + 0x844))[i] form is required here: the struct field form
 * (p->mcssPokemon[i]) changes the instruction schedule and is not byte-identical.
 */
void POKETRADE_IRCDEMO_CreateOfferSlide(TradeWork *p, int idx)
{
    void *x;
    u32 buf[3];

    x = POKETRADE_PROC_GetSideMon(p, 1 - POKETRADE_PROC_IsHostSide(p));
    POKE_TOOL_GetPartyValue(x, 7, 0);
    if (POKE_TOOL_GetPartyValue(x, 0x4c, 0) == 0) {
        PM_VOICE_Play(POKE_TOOL_GetPartyValue(x, 0xab, 0), POKE_TOOL_GetPartyValue(x, 0x6f, 0), 0x40, 0, 0, 0, 0, 0);
    }
    if (p->ownSameMon == 0) {
        MCSS_GetPosition(p->mcssPokemon[idx], buf);
        POKETRADE_SAVE_FreeIfSet(p->slide[3]);
        if (p->ownSpecialMon != 0) {
            p->slide[3] = POKETRADE_MCSS_SlideCreateWithOffsets(p->mcssPokemon[idx], 0x14, buf, d_021D5600, p->heapId);
        } else {
            p->slide[3] = POKETRADE_MCSS_SlideCreateWithOffsets(p->mcssPokemon[idx], 0x28, buf, (void *)d_021D53D0, p->heapId);
        }
    } else {
        Quad t = d_021D5200;
        void *obj = p->mcssPokemon[t.v[idx]];
        MCSS_GetPosition(p->mcssPokemon[idx], buf);
        POKETRADE_SAVE_FreeIfSet(p->slide[3]);
        if (p->ownSpecialMon != 0) {
            p->slide[3] = POKETRADE_MCSS_SlideCreateWithOffsets(obj, 0x14, buf, d_021D5600, p->heapId);
        } else {
            p->slide[3] = POKETRADE_MCSS_SlideCreateWithOffsets(obj, 0x12, buf, (void *)d_021D52F8, p->heapId);
        }
    }
}

void POKETRADE_IRCDEMO_StepStartCompare(TradeWork *p)
{
    POKETRADE_DEMO_COMMON_SetFinishFlag(p);
    p->mcssAnimStopped = 1;
    MCSS_SetAnimeIndex((void *)(p->mcssPokemon[0]), 0);
    MCSS_SetAnmStopFlag((void *)(p->mcssPokemon[0]));
    if (p->tradeState == 4) {
        PokemontradeDemoVec v = d_021D51DC;
        MCSS_SetPosition((void *)(p->mcssPokemon[0]), (u32 *)(&v));
    }
    POKETRADE_DEMO_COMMON_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, POKETRADE_DEMO_COMMON_StepCompareMons);
}

void POKETRADE_IRCDEMO_StepSetup(TradeWork *p)
{
    POKETRADE_PROC_DeleteAllResources(p);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain(p);
    p->clactSystem = CLACT_CreateUnit(3, 0, p->heapId);
    p->particleManager = GFL_HEAP_Alloc(p->heapId, sizeof(*p->particleManager), 1, d_021D55CC, 0x65);
    p->particleManager->heap = p->heapId;
    POKETRADE_2D_SetupSummaryBgs(p, 1);
    *(volatile u16 *)REG_DB_BLDCNT_ADDR = 0;
    *(volatile u16 *)REG_BLDCNT_ADDR = 0;
    POKETRADE_3D_AddUnitAndInit(p, 2);
    POKETRADE_3D_AddPokemonMcssPlain(p, 1, 0, POKETRADE_PROC_GetSideMon(p, 1), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, 0), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 3, 1, POKETRADE_PROC_GetSideMon(p, 1), 1);
    MCSS_GetScale((void *)p->mcssPokemon[3], (u32 *)&p->particleManager->scale);
    MCSS_SetVanishFlag((void *)p->mcssPokemon[1]);
    MCSS_SetVanishFlag((void *)p->mcssPokemon[2]);
    MCSS_SetVanishFlag((void *)p->mcssPokemon[3]);
    POKETRADE_3D_InitTradeParticleSet(p->particleManager);
    POKETRADE_3D_CreateIcaStreamsEnding((struct ParticleManager *)p->particleManager);
    POKETRADE_DEMO_COMMON_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, POKETRADE_IRCDEMO_UpdateScene);
}

#include "../arm9/particle.h"
#include "../arm9/wipe.h"
#include "../ov119/pokemontrade_nego.h"

/* IRC demo playback step: palette fades, particle bursts, wipes and MCSS slides. */
void POKETRADE_IRCDEMO_UpdateScene(TradeWork *p)
{
    PokemontradeDemoVec ownVec;
    PokemontradeDemoVec peerVec;
    PokemontradeDemoVec peerScale;
    PokemontradeDemoVec shownPos;

    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(1)) {
        MCSS_SetPaletteFade((struct McssWork *)p->mcssPokemon[0], 8, 8, 0, 0xFFFF);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(2)) {
        MCSS_SetPaletteFade((struct McssWork *)p->mcssPokemon[0], 0x10, 0x10, 0, 0xFFFF);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(3)) {
        POKETRADE_DEMO_COMMON_LoadUnitResources(p);
        POKETRADE_DEMO_COMMON_ShowUnitActor(p);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(4)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x18);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(4)) {
        MCSS_SetVanishFlag((void *)p->mcssPokemon[0]);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(-1)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)p->particleManager->system[0]), 0, 0, p);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x15E)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)p->particleManager->system[1]), 0, 0, p);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0xC8)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)p->particleManager->system[2]), 1, 0, p);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x14)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)p->particleManager->system[3]), 2, 0, p);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x258)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)p->particleManager->system[4]), 2, 0, p);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(-1)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)p->particleManager->system[5]), 3, 0, p);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x256)) {
        POKETRADE_DEMO_COMMON_ShowUnitActor(p);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x82)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, (u32)POKETRADE_DEMO_COMMON_PassThrough(0x14), 1, p->heapId);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0xB4)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, (u32)POKETRADE_DEMO_COMMON_PassThrough(0x19), 1, p->heapId);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0xFA)) {
        MCSS_ResetVanishFlag((void *)p->mcssPokemon[2]);
        ownVec.x = -0x32000;
        ownVec.y = -0x1F4000;
        ownVec.z = 0xA000;
        MCSS_SetPosition((void *)p->mcssPokemon[2], (u32 *)(&ownVec));
        ownVec.x = -0x32000;
        ownVec.y = 0x12C000;
        ownVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)(p->slide[0]));
        p->slide[0] = POKETRADE_MCSS_SlideCreate((void *)p->mcssPokemon[2], POKETRADE_DEMO_COMMON_PassThrough(0x96), &ownVec, p->heapId);
        MCSS_GetScale((void *)p->mcssPokemon[2], (u32 *)(&ownVec));
        ownVec.x = ownVec.x * 2;
        ownVec.y = ownVec.y * 2;
        MCSS_SetScale((void *)p->mcssPokemon[2], (u32 *)(&ownVec));
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0xFB)) {
        MCSS_ResetVanishFlag((void *)p->mcssPokemon[3]);
        peerVec.x = 0x3C000;
        peerVec.y = 0x12C000;
        peerVec.z = -0xA000;
        MCSS_SetPosition((void *)p->mcssPokemon[3], (u32 *)(&peerVec));
        peerVec.x = 0x3C000;
        peerVec.y = -0x172000;
        peerVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)(p->slide[1]));
        p->slide[1] = POKETRADE_MCSS_SlideCreate((void *)p->mcssPokemon[3], POKETRADE_DEMO_COMMON_PassThrough(0x96), &peerVec, p->heapId);
        MCSS_SetScale((void *)p->mcssPokemon[3], (u32 *)&p->particleManager->scale);
        MCSS_GetScale((void *)p->mcssPokemon[3], (u32 *)(&peerVec));
        p->particleManager->position.x = peerVec.x;
        p->particleManager->position.y = peerVec.y;
        p->particleManager->position.z = peerVec.z;
        MCSS_GetScale((void *)p->mcssPokemon[3], (u32 *)(&peerScale));
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0xFC)) {
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x267)) {
        if (p->ownSameMon == 0) {
            POKETRADE_IRCDEMO_SetMonSlide((void *)p->mcssPokemon[3], p);
        } else {
            POKETRADE_IRCDEMO_SetMonSlide((void *)p->mcssPokemon[3], p);
            MCSS_SetVanishFlag((void *)p->mcssPokemon[3]);
            POKETRADE_IRCDEMO_SetMonSlide((void *)p->mcssPokemon[1], p);
        }
        POKETRADE_IRCDEMO_CreateOfferSlide(p, 3);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x268)) {
        MCSS_SetPaletteFade((struct McssWork *)p->mcssPokemon[3], 8, 8, 0, 0x7FFF);
        MCSS_SetPaletteFade((struct McssWork *)p->mcssPokemon[1], 8, 8, 0, 0x7FFF);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x269)) {
        MCSS_SetPaletteFade((struct McssWork *)p->mcssPokemon[3], 0, 0, 0, 0x7FFF);
        MCSS_SetPaletteFade((struct McssWork *)p->mcssPokemon[1], 0, 0, 0, 0x7FFF);
    }
    if (POKETRADE_DEMO_COMMON_PassThrough(0x267) < p->waitCounter && p->ownSameMon != 0 && p->slide[3] != 0
        && p->slide[3]->frame == 9) {
        MCSS_GetPosition((void *)p->mcssPokemon[1], (u32 *)(&shownPos));
        MCSS_SetPosition((void *)p->mcssPokemon[3], (u32 *)(&shownPos));
        MCSS_ResetVanishFlag((void *)p->mcssPokemon[3]);
        MCSS_SetVanishFlag((void *)p->mcssPokemon[1]);
        p->slide[3]->mcss = p->mcssPokemon[3];
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x279)) {
        MCSS_ResetAnmStopFlag((void *)p->mcssPokemon[3]);
    }
    POKETRADE_NEGO_PlaySeByKeyB(p->waitCounter);
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x199)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, (u32)POKETRADE_DEMO_COMMON_PassThrough(0xA), 1, p->heapId);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x1A4)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, (u32)POKETRADE_DEMO_COMMON_PassThrough(0x19), 1, p->heapId);
    }
    if (p->waitCounter == POKETRADE_DEMO_COMMON_PassThrough(0x293)) {
        GFL_HEAP_Free((void *)(p->slide[0]));
        p->slide[0] = 0;
        GFL_HEAP_Free((void *)(p->slide[1]));
        p->slide[1] = 0;
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_PROC_SetStep(p, POKETRADE_IRCDEMO_StepEndScene);
    }
    POKETRADE_MCSS_SlideUpdate((void *)(p->slide[0]), p);
    POKETRADE_MCSS_SlideUpdate((void *)(p->slide[1]), p);
    POKETRADE_MCSS_SlideUpdate((void *)(p->slide[2]), p);
    POKETRADE_MCSS_SlideUpdate(p->slide[3], p);
}
