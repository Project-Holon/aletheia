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
 *   func_020307B0  0x020307B0  arm
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
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
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
 *   func_02030734  0x02030734  arm
 *   POKETRADE_2D_SetupSummaryBgs  0x021E5284  thumb  ov119
 *   POKETRADE_3D_AddUnitAndInit  0x021E3208  thumb  ov119
 *   MCSS_GetScale  0x02015C94  thumb
 *   POKETRADE_3D_InitTradeParticleSet  0x021E3070  thumb  ov119
 *   POKETRADE_3D_CreateIcaStreamsEnding  0x021E2EFC  thumb  ov119
 *   POKETRADE_IRCDEMO_UpdateScene  0x021D4CE8  thumb  ov117
 *   d_021D55CC     0x021D55CC  data
 */
#include "../ov118/pokemontrade_demo_types.h"

#define FRAME (((PokeTradeDemoWork *)p)->frame)
#define OBJ(i) (((PokeTradeDemoWork *)p)->mcssObj[i])
#define HEAP (((PokeTradeDemoWork *)p)->heapId)
#define SLOT0 (((PokeTradeDemoWork *)p)->slideOwn)
struct WordSet;
struct MsgBank;
struct McssFade;
struct Bank;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef int s32;

typedef struct {
    u32 v[4];
} Quad;

extern void POKETRADE_DEMO_COMMON_StepFade(s8 *fade);
extern void POKETRADE_MCSS_SlideUpdate(void *p, int a1);
extern int POKETRADE_DEMO_COMMON_PassThrough(int);
extern void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);
extern void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);
extern void POKETRADE_2D_DeleteAllOfferIconActors(void *p);
extern void POKETRADE_2D_DeleteAllBoxIcons(char *p);
extern void POKETRADE_SAVE_DeleteOfferListWindows(char *p);
extern void POKETRADE_DEMO_COMMON_SetFrame(u8 *p, u32 v);
extern int POKETRADE_PROC_IsHostSide(void *);
extern void *POKETRADE_PROC_GetSideMon(void *, int);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void PM_VOICE_GetPerapVoiceSave(void **out);
extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 func_020307B0(void *p);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void POKETRADE_SAVE_FreeIfSet(u32 *p);
extern void *POKETRADE_MCSS_SlideCreateWithOffsets(void *a0, void *a1, void *a2, void *a3, u16 heapId);
extern void POKETRADE_3D_AddPokemonMcssPlain(void *p, int a, int b, void *mon, int c);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_SetVanishFlag(void *p);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void BG_SYS_SetTileEntry(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int b);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_ResetVanishFlag(void *p);
extern void MCSS_ResetAnmStopFlag(void *p);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_3D_DeleteMcssSlot(void *p, int a);
extern void POKETRADE_DEMO_COMMON_ReleaseUnit(void *);
extern void POKETRADE_3D_ExitParticleManager(u32 *p, int a1);
extern void POKETRADE_3D_FreeParticleResources(void *);
extern void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p);
extern void MCSS_SetAlpha(char *p, int v);
extern void MCSS_SetScale(void *p, u32 *src);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void POKETRADE_DEMO_COMMON_SetFinishFlag(u8 *p);
extern void MCSS_SetAnimeIndex(void *a, u32 flag);
extern void POKETRADE_DEMO_COMMON_StepCompareMons(u8 *p);
extern void POKETRADE_PROC_DeleteAllResources(char *p);
extern void CLACT_ExitSystem(void);
extern void POKETRADE_2D_InitClactSystemMain(char *p);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void POKETRADE_2D_SetupSummaryBgs(char *p, int mode);
extern void POKETRADE_3D_AddUnitAndInit(void *p, int a);
extern void MCSS_GetScale(void *p, u32 *out);
extern void POKETRADE_3D_InitTradeParticleSet(void *w);
extern void POKETRADE_3D_CreateIcaStreamsEnding(char *p);
extern void POKETRADE_IRCDEMO_UpdateScene(u8 *p);
void POKETRADE_IRCDEMO_StepStartPlayback(u8 *p);
void POKETRADE_IRCDEMO_PrintMessage(u8 *p);
void POKETRADE_IRCDEMO_StepMessage(u8 *p);
void POKETRADE_IRCDEMO_StepEndScene(void *p);
void POKETRADE_IRCDEMO_SetMonSlide(void *obj, void *p);
void POKETRADE_IRCDEMO_CreateOfferSlide(u8 *p, int idx);
void POKETRADE_IRCDEMO_StepStartCompare(u8 *p);
void POKETRADE_IRCDEMO_StepSetup(u8 *p);
extern const u8 d_021D5220[];
extern const u8 d_021D53D0[];
extern u8 d_021D5600[];
extern const Quad d_021D5200;
extern const u8 d_021D52F8[];
extern const Vec d_021D51DC;
extern const char d_021D55CC[];


void POKETRADE_IRCDEMO_StepStartPlayback(u8 *p)
{
    void *mon;
    u32 a;
    u32 b;
    Vec v1;
    Vec v2;
    u32 buf;

    POKETRADE_DEMO_COMMON_StepFade(*(s8 * *)&((PokeTradeDemoWork *)p)->fade);
    POKETRADE_MCSS_SlideUpdate((void *)(((PokeTradeDemoWork *)p)->slideOwn), (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(((PokeTradeDemoWork *)p)->slidePeer), (int)p);
    if (FRAME > POKETRADE_DEMO_COMMON_PassThrough(0x2A)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0);
        POKETRADE_2D_DeleteAllOfferIconActors(p);
        POKETRADE_2D_DeleteAllBoxIcons((char *)p);
        POKETRADE_SAVE_DeleteOfferListWindows((char *)p);
        POKETRADE_DEMO_COMMON_SetFrame(p, 0);
        mon = POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p));
        POKE_TOOL_GetPartyValue(mon, 7, 0);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
            b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
            PM_VOICE_GetPerapVoiceSave((void **)(&buf));
            PM_VOICE_Play(a, b, 0x40, 0, 0, 0, 0, (u32)(&buf));
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        if (((PokeTradeDemoWork *)p)->enemySameMon == 0) {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v1));
            POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
            if (((PokeTradeDemoWork *)p)->enemySpecialMon != 0) {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x14, &v1, d_021D5600, HEAP);
            } else {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x12, &v1, (void *)d_021D5220, HEAP);
            }
            POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)), 1);
            MCSS_SetAnmStopFlag((void *)OBJ(2));
            MCSS_SetVanishFlag((void *)OBJ(2));
        } else {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v2));
            POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
            if (((PokeTradeDemoWork *)p)->enemySpecialMon != 0) {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x14, &v2, d_021D5600, HEAP);
            } else {
                SLOT0 = POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x28, &v2, (void *)d_021D53D0, HEAP);
            }
        }
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_IRCDEMO_StepMessage);
    }
}


void POKETRADE_IRCDEMO_PrintMessage(u8 *p)
{
    GFL_NET_RestartWithDefaultTimeout(0, ((PokeTradeDemoWork *)p)->heapId);
    if (((PokeTradeDemoWork *)p)->sceneMode == 6) {
        MSGDATA_ReadString((struct MsgBank *)(((PokeTradeDemoWork *)p)->msgBank), 0x98, (void *)(((PokeTradeDemoWork *)p)->stringSrc));
    } else if (((PokeTradeDemoWork *)p)->sceneMode == 8) {
        MSGDATA_ReadString((struct MsgBank *)(((PokeTradeDemoWork *)p)->msgBank), 0x9B, (void *)(((PokeTradeDemoWork *)p)->stringSrc));
    } else if (((PokeTradeDemoWork *)p)->enemySameMon != 0) {
        MSGDATA_ReadString((struct MsgBank *)(((PokeTradeDemoWork *)p)->msgBank), 0x82, (void *)(((PokeTradeDemoWork *)p)->stringSrc));
    } else {
        MSGDATA_ReadString((struct MsgBank *)(((PokeTradeDemoWork *)p)->msgBank), 0x81, (void *)(((PokeTradeDemoWork *)p)->stringSrc));
    }
    WORDSET_SetSlotMonSpecies(((PokeTradeDemoWork *)p)->wordSet, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)));
    WORDSET_SetSlotMyStatus((struct WordSet *)(*(u32 *)&((PokeTradeDemoWork *)p)->wordSet), 1, (void *)(((PokeTradeDemoWork *)p)->enemyMonKey));
    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&((PokeTradeDemoWork *)p)->wordSet), (void *)(((PokeTradeDemoWork *)p)->stringDst), (void *)(((PokeTradeDemoWork *)p)->stringSrc));
    BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x18, 0x11);
    POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
    POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}


void POKETRADE_IRCDEMO_StepMessage(u8 *p)
{
    Vec v;

    if (FRAME == 10) {
        POKETRADE_IRCDEMO_PrintMessage(p);
    }
    if (((PokeTradeDemoWork *)p)->enemySameMon == 0 && FRAME == 6) {
        MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v));
        MCSS_SetPosition((void *)OBJ(2), (u32 *)(&v));
        MCSS_ResetVanishFlag((void *)OBJ(2));
        MCSS_SetVanishFlag((void *)OBJ(0));
        MCSS_ResetAnmStopFlag((void *)OBJ(2));
        *(u32 *)SLOT0 = (u32)OBJ(2);
    }
    if (FRAME > 0xC8 && POKETRADE_SAVE_IsMessagePrintDone((char *)p) != 0) {
        POKETRADE_SAVE_CloseMessageWindowClear((char *)p);
        if (((PokeTradeDemoWork *)p)->enemySameMon == 0) {
            POKETRADE_3D_DeleteMcssSlot(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_IRCDEMO_StepSetup);
    }
    POKETRADE_MCSS_SlideUpdate((void *)SLOT0, (int)p);
}


void POKETRADE_IRCDEMO_StepEndScene(void *p)
{
    POKETRADE_DEMO_COMMON_ReleaseUnit(p);
    POKETRADE_3D_ExitParticleManager(((PokeTradeDemoWork *)p)->animWork, 6);
    POKETRADE_3D_FreeParticleResources(((PokeTradeDemoWork *)p)->animWork);
    func_020307B0(((PokeTradeDemoWork *)p)->animWork);
    ((PokeTradeDemoWork *)p)->animWork = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_ResetClactAndBeginEvent);
}


void POKETRADE_IRCDEMO_SetMonSlide(void *obj, void *p)
{
    Vec v;
    MCSS_SetAlpha(obj, 0x1f);
    MCSS_ResetVanishFlag(obj);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xa000;
    MCSS_SetPosition(obj, (u32 *)(&v));
    MCSS_SetAnmStopFlag(obj);
    MCSS_SetScale(obj, (u32 *)&((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->position);
    MCSS_SetPaletteFade(obj, 0x10, 0x10, 0, 0x7fff);
}


/*
 * Addresses are Black-image addresses.
 * The ((u32 *)(p + 0x844))[i] form is required here: the struct field form
 * (p->mcssObj[i]) changes the instruction schedule and is not byte-identical.
 */
void POKETRADE_IRCDEMO_CreateOfferSlide(u8 *p, int idx)
{
    void *x;
    u32 buf[3];

    x = POKETRADE_PROC_GetSideMon(p, 1 - POKETRADE_PROC_IsHostSide(p));
    POKE_TOOL_GetPartyValue(x, 7, 0);
    if (POKE_TOOL_GetPartyValue(x, 0x4c, 0) == 0) {
        PM_VOICE_Play(POKE_TOOL_GetPartyValue(x, 0xab, 0), POKE_TOOL_GetPartyValue(x, 0x6f, 0), 0x40, 0, 0, 0, 0, 0);
    }
    if (((PokeTradeDemoWork *)p)->ownSameMon == 0) {
        MCSS_GetPosition((void *)(((u32 *)(p + 0x844))[idx]), buf);
        POKETRADE_SAVE_FreeIfSet((u32 *)(*(u32 *)&((PokeTradeDemoWork *)p)->slidePtr));
        if (((PokeTradeDemoWork *)p)->ownSpecialMon != 0) {
            *(u32 *)&((PokeTradeDemoWork *)p)->slidePtr = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x14, buf, d_021D5600, ((PokeTradeDemoWork *)p)->heapId);
        } else {
            *(u32 *)&((PokeTradeDemoWork *)p)->slidePtr = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x28, buf, (void *)d_021D53D0, ((PokeTradeDemoWork *)p)->heapId);
        }
    } else {
        Quad t = d_021D5200;
        u32 obj = ((u32 *)(p + 0x844))[t.v[idx]];
        MCSS_GetPosition((void *)(((u32 *)(p + 0x844))[idx]), buf);
        POKETRADE_SAVE_FreeIfSet((u32 *)(*(u32 *)&((PokeTradeDemoWork *)p)->slidePtr));
        if (((PokeTradeDemoWork *)p)->ownSpecialMon != 0) {
            *(u32 *)&((PokeTradeDemoWork *)p)->slidePtr = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)obj, (void *)0x14, buf, d_021D5600, ((PokeTradeDemoWork *)p)->heapId);
        } else {
            *(u32 *)&((PokeTradeDemoWork *)p)->slidePtr = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)obj, (void *)0x12, buf, (void *)d_021D52F8, ((PokeTradeDemoWork *)p)->heapId);
        }
    }
}


void POKETRADE_IRCDEMO_StepStartCompare(u8 *p)
{
    POKETRADE_DEMO_COMMON_SetFinishFlag(p);
    ((PokeTradeDemoWork *)p)->sceneStarted = 1;
    MCSS_SetAnimeIndex((void *)(((PokeTradeDemoWork *)p)->mcssObj[0]), 0);
    MCSS_SetAnmStopFlag((void *)(((PokeTradeDemoWork *)p)->mcssObj[0]));
    if (((PokeTradeDemoWork *)p)->sceneMode == 4) {
        Vec v = d_021D51DC;
        MCSS_SetPosition((void *)(((PokeTradeDemoWork *)p)->mcssObj[0]), (u32 *)(&v));
    }
    POKETRADE_DEMO_COMMON_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_COMMON_StepCompareMons);
}


void POKETRADE_IRCDEMO_StepSetup(u8 *p)
{
    POKETRADE_PROC_DeleteAllResources((char *)p);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain((char *)p);
    ((PokeTradeDemoWork *)p)->clactSystem = (int)CLACT_CreateUnit(3, 0, HEAP);
    ((PokeTradeDemoWork *)p)->animWork = func_02030734(((PokeTradeDemoWork *)p)->heapId, 0xBC, 1, d_021D55CC, 0x65);
    ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->heapId = ((PokeTradeDemoWork *)p)->heapId;
    POKETRADE_2D_SetupSummaryBgs((char *)p, 1);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    POKETRADE_3D_AddUnitAndInit(p, 2);
    POKETRADE_3D_AddPokemonMcssPlain(p, 1, 0, POKETRADE_PROC_GetSideMon(p, 1), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, 0), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 3, 1, POKETRADE_PROC_GetSideMon(p, 1), 1);
    MCSS_GetScale((void *)OBJ(3), (u32 *)&((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->scale);
    MCSS_SetVanishFlag((void *)OBJ(1));
    MCSS_SetVanishFlag((void *)OBJ(2));
    MCSS_SetVanishFlag((void *)OBJ(3));
    POKETRADE_3D_InitTradeParticleSet(((PokeTradeDemoWork *)p)->animWork);
    POKETRADE_3D_CreateIcaStreamsEnding((char *)((PokeTradeDemoWork *)p)->animWork);
    POKETRADE_DEMO_COMMON_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_IRCDEMO_UpdateScene);
}


extern void POKETRADE_DEMO_COMMON_ShowUnitActor(void *);
extern void POKETRADE_DEMO_COMMON_LoadUnitResources(void *);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void *POKETRADE_MCSS_SlideCreate(void *a0, void *a1, void *a2, u32 heapId);
extern void POKETRADE_NEGO_PlaySeByKeyB(int);
extern void POKETRADE_3D_RemoveCurrentUnit(void *);


/* IRC demo playback step: palette fades, particle bursts, wipes and MCSS slides. */
void POKETRADE_IRCDEMO_UpdateScene(u8 *p)
{
    Vec v;
    Vec v2;
    Vec v3;
    Vec v4;

    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(1)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(2)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(0), 0x10, 0x10, 0, 0xFFFF);
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
        MCSS_SetVanishFlag((void *)OBJ(0));
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(-1)) {
        PARTICLE_StartEffectWithCallback((int *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->particleId[0], 0, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x15E)) {
        PARTICLE_StartEffectWithCallback((int *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->particleId[1], 0, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0xC8)) {
        PARTICLE_StartEffectWithCallback((int *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->particleId[2], 1, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x14)) {
        PARTICLE_StartEffectWithCallback((int *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->particleId[3], 2, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x258)) {
        PARTICLE_StartEffectWithCallback((int *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->particleId[4], 2, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(-1)) {
        PARTICLE_StartEffectWithCallback((int *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->particleId[5], 3, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x256)) {
        POKETRADE_DEMO_COMMON_ShowUnitActor(p);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x82)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_COMMON_PassThrough(0x14), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0xB4)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_COMMON_PassThrough(0x19), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0xFA)) {
        MCSS_ResetVanishFlag((void *)OBJ(2));
        v.x = -0x32000;
        v.y = -0x1F4000;
        v.z = 0xA000;
        MCSS_SetPosition((void *)OBJ(2), (u32 *)(&v));
        v.x = -0x32000;
        v.y = 0x12C000;
        v.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)(((PokeTradeDemoWork *)p)->slideOwn));
        ((PokeTradeDemoWork *)p)->slideOwn = POKETRADE_MCSS_SlideCreate((void *)OBJ(2), (void *)POKETRADE_DEMO_COMMON_PassThrough(0x96), &v, HEAP);
        MCSS_GetScale((void *)OBJ(2), (u32 *)(&v));
        v.x = v.x * 2;
        v.y = v.y * 2;
        MCSS_SetScale((void *)OBJ(2), (u32 *)(&v));
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0xFB)) {
        MCSS_ResetVanishFlag((void *)OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x12C000;
        v2.z = -0xA000;
        MCSS_SetPosition((void *)OBJ(3), (u32 *)(&v2));
        v2.x = 0x3C000;
        v2.y = -0x172000;
        v2.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)(((PokeTradeDemoWork *)p)->slidePeer));
        ((PokeTradeDemoWork *)p)->slidePeer = POKETRADE_MCSS_SlideCreate((void *)OBJ(3), (void *)POKETRADE_DEMO_COMMON_PassThrough(0x96), &v2, HEAP);
        MCSS_SetScale((void *)OBJ(3), (u32 *)&((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->scale);
        MCSS_GetScale((void *)OBJ(3), (u32 *)(&v2));
        ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->position.x = v2.x;
        ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->position.y = v2.y;
        ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->position.z = v2.z;
        MCSS_GetScale((void *)OBJ(3), (u32 *)(&v3));
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0xFC)) {
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x267)) {
        if (((PokeTradeDemoWork *)p)->ownSameMon == 0) {
            POKETRADE_IRCDEMO_SetMonSlide((void *)OBJ(3), p);
        } else {
            POKETRADE_IRCDEMO_SetMonSlide((void *)OBJ(3), p);
            MCSS_SetVanishFlag((void *)OBJ(3));
            POKETRADE_IRCDEMO_SetMonSlide((void *)OBJ(1), p);
        }
        POKETRADE_IRCDEMO_CreateOfferSlide(p, 3);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x268)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(3), 8, 8, 0, 0x7FFF);
        MCSS_SetPaletteFade((struct McssFade *)OBJ(1), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x269)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(3), 0, 0, 0, 0x7FFF);
        MCSS_SetPaletteFade((struct McssFade *)OBJ(1), 0, 0, 0, 0x7FFF);
    }
    if (POKETRADE_DEMO_COMMON_PassThrough(0x267) < FRAME && ((PokeTradeDemoWork *)p)->ownSameMon != 0 && *(u32 *)&((PokeTradeDemoWork *)p)->slidePtr != 0
        && *(u32 *)(*(u32 *)&((PokeTradeDemoWork *)p)->slidePtr + 8) == 9) {
        MCSS_GetPosition((void *)OBJ(1), (u32 *)(&v4));
        MCSS_SetPosition((void *)OBJ(3), (u32 *)(&v4));
        MCSS_ResetVanishFlag((void *)OBJ(3));
        MCSS_SetVanishFlag((void *)OBJ(1));
        **(u32 * *)&((PokeTradeDemoWork *)p)->slidePtr = (u32)OBJ(3);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x279)) {
        MCSS_ResetAnmStopFlag((void *)OBJ(3));
    }
    POKETRADE_NEGO_PlaySeByKeyB(FRAME);
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x199)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_COMMON_PassThrough(0xA), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x1A4)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_COMMON_PassThrough(0x19), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_COMMON_PassThrough(0x293)) {
        func_020307B0((void *)(((PokeTradeDemoWork *)p)->slideOwn));
        ((PokeTradeDemoWork *)p)->slideOwn = 0;
        func_020307B0((void *)(((PokeTradeDemoWork *)p)->slidePeer));
        ((PokeTradeDemoWork *)p)->slidePeer = 0;
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_IRCDEMO_StepEndScene);
    }
    POKETRADE_MCSS_SlideUpdate((void *)(((PokeTradeDemoWork *)p)->slideOwn), (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(((PokeTradeDemoWork *)p)->slidePeer), (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(((PokeTradeDemoWork *)p)->slideExtra), (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(*(u32 *)&((PokeTradeDemoWork *)p)->slidePtr), (int)p);
}
