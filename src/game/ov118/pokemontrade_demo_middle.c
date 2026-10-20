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
struct TradeWork;
extern void POKETRADE_DEMO_MIDDLE_UpdateScene(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepStartPlayback(u8 *p);
void POKETRADE_DEMO_MIDDLE_PrintMessage(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepMessage(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepEndScene(void *p);
void POKETRADE_DEMO_MIDDLE_DeleteSlide(void *p, int idx);
void POKETRADE_DEMO_MIDDLE_CreateOfferSlide(void *work, int idx);
void POKETRADE_DEMO_MIDDLE_ResetMonSlide(void *p, int idx);
void POKETRADE_DEMO_MIDDLE_UpdateEmitterA(void *obj, int on);
void POKETRADE_DEMO_MIDDLE_SetupEmitterA(void *p);
void POKETRADE_DEMO_MIDDLE_UpdateEmitterB(void *obj, int on);
void POKETRADE_DEMO_MIDDLE_SetupEmitterB(void *p);
void POKETRADE_DEMO_MIDDLE_StepStartCompare(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepSetup(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepParticleSystems(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepAddUnit(u8 *p);
extern const u8 d_021D82C0[];
extern const u8 d_021D8470[];
extern u8 d_021D8880[];
extern const Quad d_021D7CDC;
extern const u32 d_021D8398[];
extern const char d_021D866C[];

#define WORK (((PokeTradeDemoWork *)work)->animWork)

#define REC(i) (((PokeTradeAnimWork *)WORK)->slotScale[i])

/* Base-first form: mwcc emits p+0x844 then the scaled index, matching the
 * original ((u32 *)((char *)p + 0x844))[i] exactly.  The plain mcssObj[i]
 * member access lets the compiler fold the constant the other way and DIFFs
 * CreateOfferSlide and UpdateScene (verified with gameverify and match.py one). */
#undef OBJ
#define OBJ(i) (((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[i])


void POKETRADE_DEMO_MIDDLE_StepStartPlayback(u8 *work)
{
    void *mon;
    u32 a;
    u32 b;
    PokemontradeDemoVec differentMonPos;
    PokemontradeDemoVec sameMonPos;
    u32 buf;

    POKETRADE_DEMO_DOWN_StepFade(*(s8 * *)&((PokeTradeDemoWork *)work)->fade);
    POKETRADE_MCSS_SlideUpdate(((PokeTradeDemoWork *)work)->slideOwn, (sptr)work);
    POKETRADE_MCSS_SlideUpdate(((PokeTradeDemoWork *)work)->slidePeer, (sptr)work);
    if (FRAME > POKETRADE_DEMO_DOWN_PassThrough(0x2A)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(work, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(work, 0);
        POKETRADE_2D_DeleteAllOfferIconActors(work);
        POKETRADE_2D_DeleteAllBoxIcons((char *)work);
        POKETRADE_SAVE_DeleteOfferListWindows((char *)work);
        POKETRADE_DEMO_DOWN_SetFrame(work, 0);
        mon = POKETRADE_PROC_GetSideMon(work, POKETRADE_PROC_IsHostSide(work));
        POKE_TOOL_GetPartyValue(mon, 7, 0);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
            b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
            PM_VOICE_GetPerapVoiceSave((struct SaveBlock **)(&buf));
            (void **)PM_VOICE_Play(a, b, 0x40, 0, 0, 0, 0, (void **)(&buf));
        }
        if (SLOT0 != 0) {
            GFL_HEAP_Free((void *)SLOT0);
            SLOT0 = 0;
        }
        if (((PokeTradeDemoWork *)work)->enemySameMon == 0) {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&differentMonPos));
            POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
            if (((PokeTradeDemoWork *)work)->enemySpecialMon != 0) {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x14, &differentMonPos, d_021D8880, HEAP);
            } else {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x12, &differentMonPos, (void *)d_021D82C0, HEAP);
            }
            POKETRADE_3D_AddPokemonMcssPlain(work, 2, 0, POKETRADE_PROC_GetSideMon(work, POKETRADE_PROC_IsHostSide(work)), 1);
            MCSS_SetAnmStopFlag((void *)OBJ(2));
            MCSS_SetVanishFlag((void *)OBJ(2));
        } else {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&sameMonPos));
            POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
            if (((PokeTradeDemoWork *)work)->enemySpecialMon != 0) {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x14, &sameMonPos, d_021D8880, HEAP);
            } else {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x28, &sameMonPos, (void *)d_021D8470, HEAP);
            }
        }
        POKETRADE_PROC_SetStep(work, (sptr)POKETRADE_DEMO_MIDDLE_StepMessage);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_MIDDLE_PrintMessage(u8 *work)
{
    GFL_NET_RefreshWmIconAtTopRight(0, ((PokeTradeDemoWork *)work)->heapId);
    if (((PokeTradeDemoWork *)work)->sceneMode == 6) {
        MSGDATA_ReadString((struct MsgBank *)(((PokeTradeDemoWork *)work)->msgBank), 0x98, (void *)(((PokeTradeDemoWork *)work)->stringSrc));
    } else if (((PokeTradeDemoWork *)work)->sceneMode == 8) {
        MSGDATA_ReadString((struct MsgBank *)(((PokeTradeDemoWork *)work)->msgBank), 0x9B, (void *)(((PokeTradeDemoWork *)work)->stringSrc));
    } else if (((PokeTradeDemoWork *)work)->enemySameMon != 0) {
        MSGDATA_ReadString((struct MsgBank *)(((PokeTradeDemoWork *)work)->msgBank), 0x82, (void *)(((PokeTradeDemoWork *)work)->stringSrc));
    } else {
        MSGDATA_ReadString((struct MsgBank *)(((PokeTradeDemoWork *)work)->msgBank), 0x81, (void *)(((PokeTradeDemoWork *)work)->stringSrc));
    }
    WORDSET_SetSlotMonNickname(((PokeTradeDemoWork *)work)->wordSet, 0, POKETRADE_PROC_GetSideMon(work, POKETRADE_PROC_IsHostSide(work)));
    WORDSET_SetSlotMyStatus((struct WordSet *)(*(u32 *)&((PokeTradeDemoWork *)work)->wordSet), 1, (void *)(((PokeTradeDemoWork *)work)->enemyMonKey));
    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&((PokeTradeDemoWork *)work)->wordSet), (void *)(((PokeTradeDemoWork *)work)->stringDst), (void *)(((PokeTradeDemoWork *)work)->stringSrc));
    BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x18, 0x11);
    POKETRADE_SAVE_OpenMessageWindowAtPos(work, 1, 0);
    POKETRADE_2D_ScheduleSubPlaneVisible(work, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}


void POKETRADE_DEMO_MIDDLE_StepMessage(u8 *work)
{
    PokemontradeDemoVec v;

    if (FRAME == 10) {
        POKETRADE_DEMO_MIDDLE_PrintMessage(work);
    }
    if (((PokeTradeDemoWork *)work)->enemySameMon == 0 && FRAME == 6) {
        MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v));
        MCSS_SetPosition((void *)OBJ(2), (u32 *)(&v));
        MCSS_ResetVanishFlag((void *)OBJ(2));
        MCSS_SetVanishFlag((void *)OBJ(0));
        MCSS_ResetAnmStopFlag((void *)OBJ(2));
        *(void **)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && POKETRADE_SAVE_IsMessagePrintDone((char *)work) != 0) {
        POKETRADE_SAVE_CloseMessageWindowClear((char *)work);
        if (((PokeTradeDemoWork *)work)->enemySameMon == 0) {
            POKETRADE_3D_DeleteMcssSlot(work, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            GFL_HEAP_Free((void *)SLOT0);
            SLOT0 = 0;
        }
        POKETRADE_PROC_SetStep(work, (sptr)POKETRADE_DEMO_MIDDLE_StepSetup);
    }
    POKETRADE_MCSS_SlideUpdate((void *)SLOT0, (sptr)work);
}


void POKETRADE_DEMO_MIDDLE_StepEndScene(void *work)
{
    POKETRADE_DEMO_DOWN_ReleaseUnit(work);
    POKETRADE_3D_ExitParticleManager(((PokeTradeDemoWork *)work)->animWork, 6);
    POKETRADE_3D_FreeParticleResources(((PokeTradeDemoWork *)work)->animWork);
    GFL_HEAP_Free(((PokeTradeDemoWork *)work)->animWork);
    ((PokeTradeDemoWork *)work)->animWork = 0;
    POKETRADE_PROC_SetStep(work, (sptr)POKETRADE_SAVE_ResetClactAndBeginEvent);
}


void POKETRADE_DEMO_MIDDLE_DeleteSlide(void *work, int idx)
{
    void *q = ((PokeTradeDemoWork *)work)->slideOwn;
    if (q != 0) {
        GFL_HEAP_Free(q);
        ((PokeTradeDemoWork *)work)->slideOwn = 0;
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
void POKETRADE_DEMO_MIDDLE_CreateOfferSlide(void *work, int idx)
{
    void *x;
    u32 buf[3];

    x = POKETRADE_PROC_GetSideMon(work, 1 - POKETRADE_PROC_IsHostSide(work));
    POKE_TOOL_GetPartyValue(x, 7, 0);
    if (POKE_TOOL_GetPartyValue(x, 0x4c, 0) == 0) {
        PM_VOICE_Play(POKE_TOOL_GetPartyValue(x, 0xab, 0), POKE_TOOL_GetPartyValue(x, 0x6f, 0),
                      0x40, 0, 0, 0, 0, 0);
    }
    if (((PokeTradeDemoWork *)work)->ownSameMon == 0) {
        MCSS_GetPosition(((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[idx], buf);
        POKETRADE_SAVE_FreeIfSet(*(u32 * *)&((PokeTradeDemoWork *)work)->slidePtr);
        if (((PokeTradeDemoWork *)work)->ownSpecialMon != 0)
            *(u32 *)&((PokeTradeDemoWork *)work)->slidePtr =
                (uptr)POKETRADE_MCSS_SlideCreateWithOffsets(((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[idx], (void *)0x14, buf, (void *)d_021D8880, ((PokeTradeDemoWork *)work)->heapId);
        else
            *(u32 *)&((PokeTradeDemoWork *)work)->slidePtr =
                (uptr)POKETRADE_MCSS_SlideCreateWithOffsets(((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[idx], (void *)0x28, buf, (void *)d_021D8470, ((PokeTradeDemoWork *)work)->heapId);
        return;
    } else {
        Quad t;
        uptr r6;

        t = d_021D7CDC;
        r6 = (uptr)((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[t.v[idx]];
        MCSS_GetPosition(((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[idx], buf);
        POKETRADE_SAVE_FreeIfSet(*(u32 * *)&((PokeTradeDemoWork *)work)->slidePtr);
        if (((PokeTradeDemoWork *)work)->ownSpecialMon != 0)
            *(u32 *)&((PokeTradeDemoWork *)work)->slidePtr =
                (uptr)POKETRADE_MCSS_SlideCreateWithOffsets((void *)r6, (void *)0x14, buf, (void *)d_021D8880, ((PokeTradeDemoWork *)work)->heapId);
        else
            *(u32 *)&((PokeTradeDemoWork *)work)->slidePtr =
                (uptr)POKETRADE_MCSS_SlideCreateWithOffsets((void *)r6, (void *)0x12, buf, (void *)d_021D8398, ((PokeTradeDemoWork *)work)->heapId);
    }
}


void POKETRADE_DEMO_MIDDLE_ResetMonSlide(void *work, int idx)
{
    u32 vec[3];
    MCSS_ResetVanishFlag(((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[idx]);
    vec[0] = 0;
    vec[1] = 0xFFFE9000;
    vec[2] = 0xA000;
    MCSS_SetPosition(((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[idx], vec);
    MCSS_SetAnmStopFlag(((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[idx]);
    MCSS_GetScale(((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[idx], vec);
    vec[0] = ((s32)vec[0] < 0) ? 0xFFFF0000 : 0x10000;
    vec[1] = 0x10000;
    vec[2] = 0x1000;
    MCSS_SetScale(((void **)&((PokeTradeDemoWork *)work)->mcssObj[0])[idx], vec);
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
    PARTICLE_EMITTER_SetCallback(emitter, (sptr)POKETRADE_DEMO_MIDDLE_UpdateEmitterA);
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
    PARTICLE_EMITTER_SetCallback(emitter, (sptr)POKETRADE_DEMO_MIDDLE_UpdateEmitterB);
}


void POKETRADE_DEMO_MIDDLE_StepStartCompare(u8 *work)
{
    uptr t;

    POKETRADE_DEMO_DOWN_SetFinishFlag(work);
    ((PokeTradeDemoWork *)work)->sceneStarted = 1;
    MCSS_SetAnimeIndex((void *)OBJ(0), 0);
    ((PokeTradeDemoWork *)work)->peerSceneStarted = 1;
    MCSS_SetAnimeIndex((void *)OBJ(1), 0);
    if (POKETRADE_PROC_IsHostSide(work)) {
        t = (uptr)OBJ(0);
        OBJ(0) = OBJ(1);
        OBJ(1) = (void *)t;
    }
    POKETRADE_DEMO_DOWN_SetFrame(work, 0);
    POKETRADE_PROC_SetStep(work, (sptr)POKETRADE_DEMO_DOWN_StepStartPlayback);
}


void POKETRADE_DEMO_MIDDLE_StepSetup(u8 *work)
{
    POKETRADE_PROC_DeleteAllResources((char *)work);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain((char *)work);
    ((PokeTradeDemoWork *)work)->clactSystem = (sptr)CLACT_CreateUnit(3, 0, HEAP);
    WORK = GFL_HEAP_Alloc(HEAP, 0xBC, 1, d_021D866C, 0x9D);
    ((PokeTradeAnimWork *)WORK)->heapId = HEAP;
    POKETRADE_2D_SetupSummaryBgs((char *)work, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    if (POKETRADE_PROC_IsHostSide(work)) {
        POKETRADE_3D_AddPokemonMcss((struct TradeWork *)work, 1, 0, POKETRADE_PROC_GetSideMon(work, 1), 0);
        POKETRADE_3D_AddPokemonMcss((struct TradeWork *)work, 2, 0, POKETRADE_PROC_GetSideMon(work, 0), 0);
        POKETRADE_3D_AddPokemonMcss((struct TradeWork *)work, 3, 1, POKETRADE_PROC_GetSideMon(work, 1), 0);
    } else {
        POKETRADE_3D_AddPokemonMcssPlain(work, 1, 0, POKETRADE_PROC_GetSideMon(work, 1), 0);
        POKETRADE_3D_AddPokemonMcssPlain(work, 2, 0, POKETRADE_PROC_GetSideMon(work, 0), 0);
        POKETRADE_3D_AddPokemonMcssPlain(work, 3, 1, POKETRADE_PROC_GetSideMon(work, 1), 0);
    }
    MCSS_GetScale((void *)OBJ(0), (u32 *)&((PokeTradeAnimWork *)WORK)->slotScale[0]);
    MCSS_GetScale((void *)OBJ(1), (u32 *)&((PokeTradeAnimWork *)WORK)->slotScale[1]);
    MCSS_GetScale((void *)OBJ(2), (u32 *)&((PokeTradeAnimWork *)WORK)->slotScale[2]);
    MCSS_GetScale((void *)OBJ(3), (u32 *)&((PokeTradeAnimWork *)WORK)->slotScale[3]);
    MCSS_SetVanishFlag((void *)OBJ(1));
    MCSS_SetVanishFlag((void *)OBJ(2));
    MCSS_SetVanishFlag((void *)OBJ(3));
    POKETRADE_3D_InitParticleSystems(WORK);
    POKETRADE_3D_SetupParticleSystemsLow((struct ParticleManager *)WORK);
    POKETRADE_3D_CreateIcaStreamsForMode(WORK, 0);
    POKETRADE_DEMO_DOWN_SetFrame(work, 0);
    POKETRADE_PROC_SetStep(work, (sptr)POKETRADE_DEMO_MIDDLE_StepParticleSystems);
}


void POKETRADE_DEMO_MIDDLE_StepParticleSystems(u8 *work)
{
    POKETRADE_3D_SetupParticleSystemsHigh(((PokeTradeDemoWork *)work)->animWork);
    POKETRADE_PROC_SetStep(work, (sptr)POKETRADE_DEMO_MIDDLE_StepAddUnit);
}


void POKETRADE_DEMO_MIDDLE_StepAddUnit(u8 *work)
{
    POKETRADE_3D_AddUnitAndInit(work, 3);
    POKETRADE_PROC_SetStep(work, (sptr)POKETRADE_DEMO_MIDDLE_UpdateScene);
}


#include "../ov119/pokemontrade_nego.h"
#include "../arm9/wipe.h"
extern const Tbl d_021D7CEC;


/* Middle demo playback step: 3D unit swaps, MCSS slides, particles and wipes. */
void POKETRADE_DEMO_MIDDLE_UpdateScene(u8 *work)
{
    PokemontradeDemoVec ownVec, peerVec, slideBeginVec, swapVec, leftMonVec, rightMonVec, exitVec;
    Tbl t;
    PokemontradeDemoVec copyPosVec;
    int idx, idx2, idx3, idx4, a, b, b2, a2, k;
    u32 r;

    POKETRADE_NEGO_PlaySeByKeyA(FRAME);
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x12D)) {
        POKETRADE_3D_RemoveCurrentUnit(work);
        POKETRADE_3D_AddUnitAndInit(work, 4);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x2B6)) {
        POKETRADE_3D_RemoveCurrentUnit(work);
        POKETRADE_3D_AddUnitAndInit(work, 5);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(1)) {
        MCSS_SetPaletteFade((struct McssWork *)OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(2)) {
        MCSS_SetPaletteFade((struct McssWork *)OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(3)) {
        POKETRADE_DEMO_DOWN_LoadUnitResources(work);
        POKETRADE_DEMO_DOWN_CreateUnitActor(work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(4)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(work, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(work, 0x18);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(4)) {
        MCSS_SetVanishFlag((void *)OBJ(0));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)((PokeTradeAnimWork *)WORK)->particleId[0]), 10, 0, (sptr)work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x65)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)((PokeTradeAnimWork *)WORK)->particleId[1]), 1, 0, (sptr)work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)((PokeTradeAnimWork *)WORK)->particleId[2]), 2, 0, (sptr)work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)((PokeTradeAnimWork *)WORK)->particleId[8]), 2, 0, (sptr)work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0xE)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)((PokeTradeAnimWork *)WORK)->particleId[3]), 3, 0, (sptr)work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x483)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)((PokeTradeAnimWork *)WORK)->particleId[7]), 3, 0, (sptr)work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)((PokeTradeAnimWork *)WORK)->particleId[4]), 4, (void (*)(void *))((sptr)POKETRADE_DEMO_MIDDLE_SetupEmitterA), (sptr)work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x152)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)((PokeTradeAnimWork *)WORK)->particleId[5]), 5, 0, (sptr)work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x2BC)) {
        PARTICLE_StartEffectWithCallback((struct ParticleSys *)((int *)((PokeTradeAnimWork *)WORK)->particleId[6]), 6, (void (*)(void *))((sptr)POKETRADE_DEMO_MIDDLE_SetupEmitterB), (sptr)work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x47F)) {
        POKETRADE_DEMO_DOWN_CreateUnitActor(work);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x10A)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0x14), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x130)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0x19), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x149)) {
        POKETRADE_3D_DeleteMcssSlot(work, 0);
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            POKETRADE_3D_AddPokemonMcss((struct TradeWork *)work, 0, 1, POKETRADE_PROC_GetSideMon(work, 0), 0);
        } else {
            POKETRADE_3D_AddPokemonMcssPlain(work, 0, 1, POKETRADE_PROC_GetSideMon(work, 0), 0);
        }
        MCSS_GetScale((void *)OBJ(0), (u32 *)&((PokeTradeAnimWork *)WORK)->slotScale[0]);
        MCSS_SetVanishFlag((void *)OBJ(0));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x14A)) {
        idx = 2;
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            idx = 1;
        }
        MCSS_ResetVanishFlag((void *)OBJ(idx));
        ownVec.x = -0x32000;
        ownVec.y = -0x96000;
        ownVec.z = 0xA000;
        MCSS_SetPosition((void *)OBJ(idx), (u32 *)(&ownVec));
        ownVec.x = -0x32000;
        ownVec.y = -0x37000;
        ownVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate((void *)OBJ(idx), (void *)POKETRADE_DEMO_DOWN_PassThrough(0xF), &ownVec, HEAP);
        MCSS_SetAnmStopFlag((void *)OBJ(idx));
        ownVec.x = REC(idx).x * 1.2;
        ownVec.y = REC(idx).y * 1.2;
        ownVec.z = REC(idx).z;
        MCSS_SetScale((void *)OBJ(idx), (u32 *)(&ownVec));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x14B)) {
        idx2 = 3;
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            idx2 = 0;
        }
        MCSS_ResetVanishFlag((void *)OBJ(idx2));
        peerVec.x = 0x3C000;
        peerVec.y = 0x50000;
        peerVec.z = -0xA000;
        MCSS_SetPosition((void *)OBJ(idx2), (u32 *)(&peerVec));
        peerVec.x = 0x3C000;
        peerVec.y = 0x5000;
        peerVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate((void *)OBJ(idx2), (void *)POKETRADE_DEMO_DOWN_PassThrough(0xF), &peerVec, HEAP);
        MCSS_SetAnmStopFlag((void *)OBJ(idx2));
        peerVec.x = REC(idx2).x * 1.2;
        peerVec.y = REC(idx2).y * 1.2;
        peerVec.z = REC(idx2).z;
        MCSS_SetScale((void *)OBJ(idx2), (u32 *)(&peerVec));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x154)) {
        slideBeginVec.x = -0x32000;
        slideBeginVec.y = -0x37000;
        slideBeginVec.z = 0xA000;
        POKETRADE_MCSS_SlideBegin((void *)SLOT0, (void *)POKETRADE_DEMO_DOWN_PassThrough(0x1C), &slideBeginVec);
        slideBeginVec.x = 0x3C000;
        slideBeginVec.y = 0x5000;
        slideBeginVec.z = -0xA000;
        POKETRADE_MCSS_SlideBegin((void *)SLOT1, (void *)POKETRADE_DEMO_DOWN_PassThrough(0x1C), &slideBeginVec);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x170)) {
        GFL_HEAP_Free((void *)SLOT0);
        SLOT0 = 0;
        GFL_HEAP_Free((void *)SLOT1);
        SLOT1 = 0;
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
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate((void *)OBJ(a), (void *)POKETRADE_DEMO_DOWN_PassThrough(0x2E), &swapVec, HEAP);
        swapVec.x = 0x96000;
        swapVec.y = 0x5000;
        swapVec.z = 0;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate((void *)OBJ(b), (void *)POKETRADE_DEMO_DOWN_PassThrough(0x2E), &swapVec, HEAP);
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x1B2)) {
        idx3 = 0;
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            idx3 = 3;
        }
        GFL_HEAP_Free((void *)SLOT0);
        SLOT0 = 0;
        MCSS_ResetVanishFlag((void *)OBJ(idx3));
        MCSS_SetPaletteFade((struct McssWork *)OBJ(idx3), 0, 0, 0, 0x7FFF);
        leftMonVec.x = -0x96000;
        leftMonVec.y = 0x5000;
        leftMonVec.z = -0xA000;
        MCSS_SetPosition((void *)OBJ(idx3), (u32 *)(&leftMonVec));
        leftMonVec.x = 0x3C000;
        leftMonVec.y = 0x5000;
        leftMonVec.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate((void *)OBJ(idx3), (void *)POKETRADE_DEMO_DOWN_PassThrough(0x67), &leftMonVec, HEAP);
        leftMonVec.x = REC(idx3).x * 1.2;
        leftMonVec.y = REC(idx3).y * 1.2;
        leftMonVec.z = REC(idx3).z;
        MCSS_SetScale((void *)OBJ(idx3), (u32 *)(&leftMonVec));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x1B2)) {
        idx4 = 1;
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            idx4 = 2;
        }
        GFL_HEAP_Free((void *)SLOT1);
        SLOT1 = 0;
        MCSS_ResetVanishFlag((void *)OBJ(idx4));
        rightMonVec.x = 0x96000;
        rightMonVec.y = -0x37000;
        rightMonVec.z = 0xA000;
        MCSS_SetPosition((void *)OBJ(idx4), (u32 *)(&rightMonVec));
        rightMonVec.x = -0x2D000;
        rightMonVec.y = -0x37000;
        rightMonVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate((void *)OBJ(idx4), (void *)POKETRADE_DEMO_DOWN_PassThrough(0x67), &rightMonVec, HEAP);
        rightMonVec.x = REC(idx4).x * 1.2;
        rightMonVec.y = REC(idx4).y * 1.2;
        rightMonVec.z = REC(idx4).z;
        MCSS_SetScale((void *)OBJ(idx4), (u32 *)(&rightMonVec));
        *(u16 *)((u8 *)SLOT0 + 0x16) = 1;
        *(u16 *)((u8 *)SLOT1 + 0x16) = 1;
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x1F8)) {
        POKETRADE_MCSS_SlideBegin((void *)SLOT0, (void *)POKETRADE_DEMO_DOWN_PassThrough(0x80), (void *)((u8 *)SLOT0 + 0x28));
        POKETRADE_MCSS_SlideBegin((void *)SLOT1, (void *)POKETRADE_DEMO_DOWN_PassThrough(0x80), (void *)((u8 *)SLOT1 + 0x28));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x27D)) {
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
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate((void *)OBJ(a2), (void *)POKETRADE_DEMO_DOWN_PassThrough(7), &exitVec, HEAP);
        exitVec.x = -0x2D000;
        exitVec.y = -0xA0000;
        exitVec.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate((void *)OBJ(b2), (void *)POKETRADE_DEMO_DOWN_PassThrough(7), &exitVec, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x2B5)) {
        MCSS_SetVanishFlag((void *)OBJ(0));
        MCSS_SetVanishFlag((void *)OBJ(1));
        MCSS_SetVanishFlag((void *)OBJ(2));
        MCSS_SetVanishFlag((void *)OBJ(3));
    }
    t = d_021D7CEC;
    k = 3;
    if (POKETRADE_PROC_IsHostSide(work) != 0) {
        k = 0;
    }
    r = t.v[k];
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x48E)) {
        if (((PokeTradeDemoWork *)work)->ownSameMon == 0) {
            POKETRADE_DEMO_MIDDLE_ResetMonSlide(work, k);
            POKETRADE_DEMO_MIDDLE_CreateOfferSlide(work, k);
            MCSS_SetPaletteFade((struct McssWork *)OBJ(k), 0x10, 0x10, 0, 0x7FFF);
        } else {
            POKETRADE_DEMO_MIDDLE_ResetMonSlide(work, k);
            MCSS_SetVanishFlag((void *)OBJ(k));
            POKETRADE_DEMO_MIDDLE_ResetMonSlide(work, r);
            POKETRADE_DEMO_MIDDLE_CreateOfferSlide(work, k);
            MCSS_SetPaletteFade((struct McssWork *)OBJ(r), 0x10, 0x10, 0, 0x7FFF);
        }
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x48F)) {
        MCSS_SetPaletteFade((struct McssWork *)OBJ(k), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x490)) {
        MCSS_SetPaletteFade((struct McssWork *)OBJ(k), 0, 0, 0, 0x7FFF);
    }
    if (POKETRADE_DEMO_DOWN_PassThrough(0x48E) < FRAME && ((PokeTradeDemoWork *)work)->ownSameMon != 0 && ((PokeTradeDemoWork *)work)->slidePtr != 0
        && *(u32 *)((char *)((PokeTradeDemoWork *)work)->slidePtr + 8) == 9) {
        MCSS_GetPosition((void *)OBJ(r), (u32 *)(&copyPosVec));
        MCSS_SetPosition((void *)OBJ(k), (u32 *)(&copyPosVec));
        MCSS_ResetVanishFlag((void *)OBJ(k));
        MCSS_SetVanishFlag((void *)OBJ(r));
        **(u32 **)&((PokeTradeDemoWork *)work)->slidePtr = (uptr)OBJ(k);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x4A0)) {
        MCSS_ResetAnmStopFlag((void *)OBJ(k));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x28B)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0xA), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x2B8)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0x19), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x380)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0x1E), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x3CA)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0x1E), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x4C1)) {
        POKETRADE_DEMO_MIDDLE_DeleteSlide(work, 0);
        POKETRADE_DEMO_MIDDLE_DeleteSlide(work, 1);
        POKETRADE_3D_RemoveCurrentUnit(work);
        POKETRADE_PROC_SetStep(work, (sptr)POKETRADE_DEMO_MIDDLE_StepEndScene);
    }
    POKETRADE_MCSS_SlideUpdate((void *)SLOT0, (sptr)work);
    POKETRADE_MCSS_SlideUpdate((void *)SLOT1, (sptr)work);
    POKETRADE_MCSS_SlideUpdate(((PokeTradeDemoWork *)work)->slideExtra, (sptr)work);
    POKETRADE_MCSS_SlideUpdate(((PokeTradeDemoWork *)work)->slidePtr, (sptr)work);
}
