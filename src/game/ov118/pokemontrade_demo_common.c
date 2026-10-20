/*
 * file:     pokemontrade_demo_common.c
 * unit:     yes
 * function: POKETRADE_DEMO_COMMON_StepFade, POKETRADE_DEMO_COMMON_CompareSideMon, POKETRADE_DEMO_COMMON_ShowUnitActor, POKETRADE_DEMO_COMMON_LoadUnitResources, POKETRADE_DEMO_COMMON_ReleaseUnit, POKETRADE_DEMO_COMMON_PassThrough, POKETRADE_DEMO_COMMON_SetFrame, POKETRADE_DEMO_COMMON_SetFinishFlag, POKETRADE_DEMO_COMMON_StepCompareMons, POKETRADE_DEMO_COMMON_StepWaitSync, POKETRADE_DEMO_COMMON_StepStartSlides, POKETRADE_DEMO_COMMON_StepBeginPlayback
 * address:  0x021D4240
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * contiguous: no
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * This original is NON-CONTIGUOUS: pokemontrade_demo_up.c, _down.c and _middle.c
 * lie between its two ranges, so it links as two pieces.  The `symbols:` block
 * below is the name-to-address map for the per-function verify path and for the
 * gamelink run cut, so every function this file defines is listed there.
 *
 * symbols:
 *   POKETRADE_DEMO_COMMON_StepFade  0x021D4240  thumb
 *   POKETRADE_DEMO_COMMON_CompareSideMon  0x021D4290  thumb
 *   POKETRADE_DEMO_COMMON_ShowUnitActor  0x021D434C  thumb
 *   POKETRADE_DEMO_COMMON_LoadUnitResources  0x021D43C8  thumb
 *   POKETRADE_DEMO_COMMON_ReleaseUnit  0x021D4434  thumb
 *   POKETRADE_DEMO_COMMON_PassThrough  0x021D4480  thumb
 *   POKETRADE_DEMO_COMMON_SetFrame  0x021D4484  thumb
 *   POKETRADE_DEMO_COMMON_SetFinishFlag  0x021D4490  thumb
 *   POKETRADE_DEMO_COMMON_StepCompareMons  0x021D449C  thumb
 *   POKETRADE_DEMO_COMMON_StepWaitSync  0x021D4520  thumb
 *   POKETRADE_DEMO_COMMON_StepStartSlides  0x021D4544  thumb
 *   POKETRADE_DEMO_COMMON_StepBeginPlayback  0x021D67F8  thumb
 *   POKETRADE_DEMO_DOWN_SetFrame  0x021D6738  thumb  ov118
 *   POKETRADE_DEMO_DOWN_PassThrough  0x021D6734  thumb  ov118
 *   POKETRADE_DEMO_MIDDLE_StepStartPlayback  0x021D6918  thumb  ov118
 *   d_021D8650     0x021D8650  data
 *   d_021D7CC4     0x021D7CC4  data
 *   d_021D7CD0     0x021D7CD0  data
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   POKETRADE_3D_FadeTexturePalette  0x021E3BB0  thumb  ov119
 *   POKETRADE_3D_RemoveCurrentUnit  0x021E3230  thumb  ov119
 *   POKETRADE_PROC_IsNetSession  0x021D8A24  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   POKETRADE_SAVE_FreeIfSet  0x021DFD24  thumb  ov119
 *   POKETRADE_MCSS_SlideCreate  0x021DFB84  thumb  ov119
 *   MCSS_SetAnimCallback  0x02015F2C  thumb
 *   POKETRADE_MCSS_StopAnimation  0x021DFD0C  thumb  ov119
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   POKETRADE_SAVE_CloseMessageWindow  0x021E106C  thumb  ov119
 *   BG_SYS_LoadPlttEntry  0x02040EBC  arm
 *   POKETRADE_DEMO_UP_StepStartPlayback  0x021D4664  thumb  ov118
 *   d_021D7FB8     0x021D7FB8  data
 *   d_021D7C84     0x021D7C84  data
 *   d_021D7C9C     0x021D7C9C  data
 *   ARC_TOOL_DeleteHandle  0x02049238  arm  arm9
 *   CLACT_RegisterCharacter  0x0204A6C8  arm  arm9
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm  arm9
 *   CLACT_RegisterCellAnim  0x0204AF28  arm  arm9
 *   CLACT_CreateActor  0x0204B294  arm  arm9
 *   CLACT_RestartActorAnim  0x0204B9A0  arm  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   ARC_TOOL_CreateHandle  0x020490F4  arm  arm9
 */
#include "pokemontrade_demo_types.h"

struct Personal;
struct Sub0200852CObj;
struct ClactActor;
struct ClactActor;
struct Entry;
struct Link;
struct McssFade;
#include "../types.h"

/* Parameter block passed to CLACT_CreateActor as its position argument. */
typedef struct {
    u16 charId;
    u16 palId;
    u16 cellId;
    u8  x;
    u8  y;
} ClactCellParam;

#include "../arm9/clact.h"
#include "../arm9/mcss.h"
#include "../arm9/mystatus.h"
#include "../arm9/net_handle.h"
#include "../arm9/poke_personal.h"
#include "../arm9/g2.h"
#include "../ov119/pokemontrade_proc.h"
#include "../arm9/poke_tool.h"
#include "../arm9/arc_tool.h"
extern int CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern int CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
#include "../ov119/pokemontrade_3d.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../ov119/pokemontrade_save.h"
#include "../ov119/pokemontrade_mcss.h"
#include "../arm9/bg_sys.h"
#include "pokemontrade_demo_up.h"
extern void POKETRADE_DEMO_DOWN_SetFrame(u8 *p, u32 v);
extern int POKETRADE_DEMO_DOWN_PassThrough(int a);
#include "pokemontrade_demo_middle.h"
void POKETRADE_DEMO_COMMON_StepFade(s8 *fade);
void POKETRADE_DEMO_COMMON_CompareSideMon(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
void POKETRADE_DEMO_COMMON_ShowUnitActor(void *p);
void POKETRADE_DEMO_COMMON_LoadUnitResources(void *p);
void POKETRADE_DEMO_COMMON_ReleaseUnit(void *p);
int POKETRADE_DEMO_COMMON_PassThrough(int a);
void POKETRADE_DEMO_COMMON_SetFrame(u8 *p, u32 v);
void POKETRADE_DEMO_COMMON_SetFinishFlag(u8 *p);
void POKETRADE_DEMO_COMMON_StepCompareMons(u8 *p);
void POKETRADE_DEMO_COMMON_StepWaitSync(u8 *p);
void POKETRADE_DEMO_COMMON_StepStartSlides(u8 *p);
extern const char d_021D7FB8[];
extern const PokemontradeDemoVec d_021D7C84;
extern const PokemontradeDemoVec d_021D7C9C;
extern const char d_021D8650[];
extern const PokemontradeDemoVec d_021D7CC4;
extern const PokemontradeDemoVec d_021D7CD0;

void POKETRADE_DEMO_COMMON_StepFade(s8 *fade)
{
    s32 brightness;

    if (fade == 0) {
        return;
    }
    if (fade[0] >= fade[1]) {
        fade[1]++;
        brightness = ((fade[3] - fade[2]) << 12) / fade[0];
        brightness = brightness * fade[1] / 4096;
        G2x_SetBlendBrightness_(0x04000050, 0x1E, brightness);
        G2x_SetBlendBrightness_(0x04001050, 0x1F, brightness);
    }
}

void POKETRADE_DEMO_COMMON_CompareSideMon(u8 *work, u8 *outSame, u8 *outFlag, u32 key, int enemy)
{
    int side;
    void *mon;
    u32 monId;
    u32 species;
    u32 form;
    u32 isEgg;
    u32 personal;
    u32 isSpecial;

    if (enemy != 0) {
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            side = 1;
        } else {
            side = 0;
        }
    } else {
        if (POKETRADE_PROC_IsHostSide(work) != 0) {
            side = 0;
        } else {
            side = 1;
        }
    }
    mon = POKETRADE_PROC_GetSideMon(work, side);
    monId = POKE_TOOL_GetPartyValue(mon, 7, 0);
    species = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
    form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    isEgg = POKE_TOOL_GetPartyValue(mon, 0x4C, 0);
    if (isEgg == 0) {
        personal = (u32)POKE_PERSONAL_Create((u16)species, (int)(u16)form, ((PokeTradeDemoWork *)work)->heapId);
        isSpecial = POKE_PERSONAL_GetParam((const struct PersonalData *)(const struct Personal *)personal, 0x10);
        POKE_PERSONAL_Delete((void *)personal);
    }
    if (isEgg != 0) {
        *outFlag = 1;
    } else if (isSpecial != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (monId != MYSTATUS_GetId((const struct MyStatus *)(const struct Sub0200852CObj *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}

void POKETRADE_DEMO_COMMON_ShowUnitActor(void *work)
{
    void *actor = ((PokeTradeAnimWork *)((PokeTradeDemoWork *)work)->animWork)->actor;
    if (actor == 0) {
        ClactCellParam s;
        s.charId = 0x80;
        s.palId = 0x63;
        s.cellId = 0;
        s.x = 0;
        s.y = 0;
        ((PokeTradeAnimWork *)((PokeTradeDemoWork *)work)->animWork)->actor =
            CLACT_CreateActor((void *)((PokeTradeDemoWork *)work)->clactSystem,
                          ((PokeTradeDemoWork *)work)->characterHandle,
                          ((PokeTradeDemoWork *)work)->paletteHandle,
                          ((PokeTradeDemoWork *)work)->cellAnimHandle,
                          (const struct ActorInitParam *)&s, 0, ((PokeTradeDemoWork *)work)->heapId);
        CLACT_SetActorAutoAnim((struct ClactActor *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)work)->animWork)->actor, 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)work)->animWork)->actor, 1);
    } else {
        CLACT_RestartActorAnim((struct ClactActor *)actor);
    }
}

void POKETRADE_DEMO_COMMON_LoadUnitResources(void *work)
{
    void *res = ARC_TOOL_CreateHandle(0x67, ((PokeTradeDemoWork *)work)->heapId);
    ((PokeTradeDemoWork *)work)->characterHandle = CLACT_RegisterCharacter(res, 2, 0, 0, ((PokeTradeDemoWork *)work)->heapId);
    ((PokeTradeDemoWork *)work)->paletteHandle = CLACT_RegisterPaletteEx(res, 3, 0, 0xE0, 0, 1, ((PokeTradeDemoWork *)work)->heapId);
    ((PokeTradeDemoWork *)work)->cellAnimHandle = CLACT_RegisterCellAnim(res, 1, 0, ((PokeTradeDemoWork *)work)->heapId);
    ARC_TOOL_DeleteHandle(res);
    ((PokeTradeAnimWork *)((PokeTradeDemoWork *)work)->animWork)->actor = 0;
}

void POKETRADE_DEMO_COMMON_ReleaseUnit(void *work)
{
    u8 *b = work;

    if (((PokeTradeAnimWork *)((PokeTradeDemoWork *)b)->animWork)->actor != 0)
        CLACT_DeleteActor((struct ClactActor *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)b)->animWork)->actor);
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

int POKETRADE_DEMO_COMMON_PassThrough(int value) { return value; }

void POKETRADE_DEMO_COMMON_SetFrame(u8 *work, u32 frame) { ((PokeTradeDemoWork *)work)->frame = frame; }

void POKETRADE_DEMO_COMMON_SetFinishFlag(u8 *work) { ((PokeTradeDemoWork *)work)->finishFlag = 1; }

void POKETRADE_DEMO_COMMON_StepCompareMons(u8 *work)
{
    POKETRADE_3D_FadeTexturePalette((char *)work);
    if (((PokeTradeDemoWork *)work)->sceneStarted == 1) {
        POKETRADE_DEMO_COMMON_CompareSideMon(work, &((PokeTradeDemoWork *)work)->enemySameMon, &((PokeTradeDemoWork *)work)->enemySpecialMon, ((PokeTradeDemoWork *)work)->enemyMonKey, 1);
        POKETRADE_DEMO_COMMON_CompareSideMon(work, &((PokeTradeDemoWork *)work)->ownSameMon, &((PokeTradeDemoWork *)work)->ownSpecialMon, ((PokeTradeDemoWork *)work)->ownMonKey, 0);
        POKETRADE_3D_RemoveCurrentUnit(work);
        if (POKETRADE_PROC_IsNetSession(work) != 0) {
            GFL_NET_HANDLE_SetTimingSyncRange((GFLNetHandle *)(struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8);
            POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_COMMON_StepWaitSync);
        } else {
            POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_COMMON_StepStartSlides);
        }
    }
}

void POKETRADE_DEMO_COMMON_StepWaitSync(u8 *work)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((GFLNetHandle *)(struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8) != 0) {
        POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_COMMON_StepStartSlides);
    }
}

void POKETRADE_DEMO_COMMON_StepStartSlides(u8 *work)
{
    PokemontradeDemoVec a;
    PokemontradeDemoVec b;

    POKETRADE_DEMO_COMMON_SetFrame(work, 0);
    ((PokeTradeDemoWork *)work)->fade = GFL_HEAP_Alloc(((PokeTradeDemoWork *)work)->heapId, 4, 1, d_021D7FB8, 0xF5);
    ((PokeTradeDemoWork *)work)->fade[0] = POKETRADE_DEMO_COMMON_PassThrough(0xE);
    ((PokeTradeDemoWork *)work)->fade[1] = 0;
    ((PokeTradeDemoWork *)work)->fade[2] = 0;
    ((PokeTradeDemoWork *)work)->fade[3] = -0x10;
    a = d_021D7C84;
    POKETRADE_SAVE_FreeIfSet((u32 *)((PokeTradeDemoWork *)work)->slideOwn);
    ((PokeTradeDemoWork *)work)->slideOwn = POKETRADE_MCSS_SlideCreate((void *)((PokeTradeDemoWork *)work)->mcssObj[0], (void *)POKETRADE_DEMO_COMMON_PassThrough(0x2A), &a, ((PokeTradeDemoWork *)work)->heapId);
    b = d_021D7C9C;
    POKETRADE_SAVE_FreeIfSet((u32 *)((PokeTradeDemoWork *)work)->slidePeer);
    ((PokeTradeDemoWork *)work)->slidePeer = POKETRADE_MCSS_SlideCreate((void *)((PokeTradeDemoWork *)work)->mcssObj[1], (void *)POKETRADE_DEMO_COMMON_PassThrough(0x54), &b, ((PokeTradeDemoWork *)work)->heapId);
    MCSS_SetAnimCallback((McssWork *)(u32)((PokeTradeDemoWork *)work)->mcssObj[0], (u32)work, (u32)(void (*)(void))POKETRADE_MCSS_StopAnimation, 1);
    MCSS_SetPaletteFade((McssWork *)(struct McssFade *)((PokeTradeDemoWork *)work)->mcssObj[1], 0, 0x10, (s8)(POKETRADE_DEMO_COMMON_PassThrough(0xE) / 16), 0);
    POKETRADE_SAVE_CloseMessageWindow((char *)work);
    BG_SYS_LoadPlttEntry(1, 0);
    BG_SYS_LoadPlttEntry(5, 0);
    POKETRADE_DEMO_COMMON_SetFrame(work, 0);
    POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_UP_StepStartPlayback);
}

void POKETRADE_DEMO_COMMON_StepBeginPlayback(u8 *work)
{
    PokemontradeDemoVec a;
    PokemontradeDemoVec b;
    PokeTradeDemoWork *w = (PokeTradeDemoWork *)work;

    POKETRADE_DEMO_DOWN_SetFrame(work, 0);
    w->fade = GFL_HEAP_Alloc(w->heapId, 4, 1, d_021D8650, 0xF5);
    w->fade[0] = POKETRADE_DEMO_DOWN_PassThrough(0xE);
    w->fade[1] = 0;
    w->fade[2] = 0;
    w->fade[3] = -0x10;
    a = d_021D7CC4;
    POKETRADE_SAVE_FreeIfSet((u32 *)w->slideOwn);
    w->slideOwn = POKETRADE_MCSS_SlideCreate((void *)w->mcssObj[0], (void *)POKETRADE_DEMO_DOWN_PassThrough(0x2A), &a, w->heapId);
    b = d_021D7CD0;
    POKETRADE_SAVE_FreeIfSet((u32 *)w->slidePeer);
    w->slidePeer = POKETRADE_MCSS_SlideCreate((void *)w->mcssObj[1], (void *)POKETRADE_DEMO_DOWN_PassThrough(0x54), &b, w->heapId);
    MCSS_SetAnimCallback((McssWork *)(u32)w->mcssObj[0], (u32)work, (u32)(void (*)(void))POKETRADE_MCSS_StopAnimation, 1);
    MCSS_SetPaletteFade((McssWork *)(struct McssFade *)w->mcssObj[1], 0, 0x10, (s8)(POKETRADE_DEMO_DOWN_PassThrough(0xE) / 16), 0);
    POKETRADE_SAVE_CloseMessageWindow((char *)work);
    BG_SYS_LoadPlttEntry(1, 0);
    BG_SYS_LoadPlttEntry(5, 0);
    POKETRADE_DEMO_DOWN_SetFrame(work, 0);
    POKETRADE_PROC_SetStep(work, (int)POKETRADE_DEMO_MIDDLE_StepStartPlayback);
}
