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
 *   func_02008530  0x02008530  thumb
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
 *   func_02030734  0x02030734  arm
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
 */
#include "pokemontrade_demo_types.h"

struct Personal;
struct Sub0200852CObj;
struct Obj;
struct Actor;
struct Entry;
struct Link;
struct McssFade;
typedef signed char s8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

/* Parameter block passed to CLACT_CreateActor as its position argument. */
typedef struct {
    u16 charId;
    u16 palId;
    u16 cellId;
    u8  x;
    u8  y;
} ClactCellParam;

typedef short s16;

typedef int s32;

extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern int POKETRADE_PROC_IsHostSide(void *p);
extern void *POKETRADE_PROC_GetSideMon(void *p, int which);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 arg);
extern void *POKE_PERSONAL_Create(unsigned int a, int b, unsigned int heap);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorAutoAnim(struct Obj *, u32);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void POKETRADE_3D_FadeTexturePalette(char *p);
extern void POKETRADE_3D_RemoveCurrentUnit(void *p);
extern int POKETRADE_PROC_IsNetSession(void *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32 lo, u32 hi);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void POKETRADE_SAVE_FreeIfSet(u32 *p);
extern void *POKETRADE_MCSS_SlideCreate(void *a0, void *a1, void *a2, u32 heapId);
extern void MCSS_SetAnimCallback(u32 obj, void *arg, void (*cb)(void), int a);
extern void POKETRADE_MCSS_StopAnimation(char *p);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void POKETRADE_SAVE_CloseMessageWindow(char *p);
extern void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);
extern void POKETRADE_DEMO_UP_StepStartPlayback(u8 *p);
extern void POKETRADE_DEMO_DOWN_SetFrame(u8 *p, u32 v);
extern int POKETRADE_DEMO_DOWN_PassThrough(int a);
extern void POKETRADE_DEMO_MIDDLE_StepStartPlayback(u8 *p);
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
extern const Vec d_021D7C84;
extern const Vec d_021D7C9C;
extern const char d_021D8650[];
extern const Vec d_021D7CC4;
extern const Vec d_021D7CD0;




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




void POKETRADE_DEMO_COMMON_CompareSideMon(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy)
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
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            side = 1;
        } else {
            side = 0;
        }
    } else {
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            side = 0;
        } else {
            side = 1;
        }
    }
    mon = POKETRADE_PROC_GetSideMon(p, side);
    monId = POKE_TOOL_GetPartyValue(mon, 7, 0);
    species = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
    form = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
    isEgg = POKE_TOOL_GetPartyValue(mon, 0x4C, 0);
    if (isEgg == 0) {
        personal = (u32)POKE_PERSONAL_Create((u16)species, (int)(u16)form, ((PokeTradeDemoWork *)p)->heapId);
        isSpecial = POKE_PERSONAL_GetParam((const struct Personal *)personal, 0x10);
        POKE_PERSONAL_Delete((void *)personal);
    }
    if (isEgg != 0) {
        *outFlag = 1;
    } else if (isSpecial != 0) {
        *outFlag = 1;
    } else {
        *outFlag = 0;
    }
    if (monId != func_02008530((const struct Sub0200852CObj *)key)) {
        *outSame = 0;
    } else {
        *outSame = 1;
    }
}




void POKETRADE_DEMO_COMMON_ShowUnitActor(void *p)
{
    void *actor = ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor;
    if (actor == 0) {
        ClactCellParam s;
        s.charId = 0x80;
        s.palId = 0x63;
        s.cellId = 0;
        s.x = 0;
        s.y = 0;
        ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor =
            CLACT_CreateActor((void *)((PokeTradeDemoWork *)p)->clactSystem,
                          ((PokeTradeDemoWork *)p)->characterHandle,
                          ((PokeTradeDemoWork *)p)->paletteHandle,
                          ((PokeTradeDemoWork *)p)->cellAnimHandle,
                          &s, 0, ((PokeTradeDemoWork *)p)->heapId);
        CLACT_SetActorAutoAnim((struct Obj *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor, 1);
        CLACT_SetActorDrawEnable((struct Obj *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor, 1);
    } else {
        CLACT_RestartActorAnim((struct Actor *)actor);
    }
}




void POKETRADE_DEMO_COMMON_LoadUnitResources(void *p)
{
    void *res = func_020490F4(0x67, ((PokeTradeDemoWork *)p)->heapId);
    ((PokeTradeDemoWork *)p)->characterHandle = CLACT_RegisterCharacter(res, 2, 0, 0, ((PokeTradeDemoWork *)p)->heapId);
    ((PokeTradeDemoWork *)p)->paletteHandle = CLACT_RegisterPaletteEx(res, 3, 0, 0xE0, 0, 1, ((PokeTradeDemoWork *)p)->heapId);
    ((PokeTradeDemoWork *)p)->cellAnimHandle = CLACT_RegisterCellAnim(res, 1, 0, ((PokeTradeDemoWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(res);
    ((PokeTradeAnimWork *)((PokeTradeDemoWork *)p)->animWork)->actor = 0;
}




void POKETRADE_DEMO_COMMON_ReleaseUnit(void *p)
{
    u8 *b = p;

    if (((PokeTradeAnimWork *)((PokeTradeDemoWork *)b)->animWork)->actor != 0)
        CLACT_DeleteActor((struct Obj *)((PokeTradeAnimWork *)((PokeTradeDemoWork *)b)->animWork)->actor);
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




int POKETRADE_DEMO_COMMON_PassThrough(int a) { return a; }




void POKETRADE_DEMO_COMMON_SetFrame(u8 *p, u32 v) { ((PokeTradeDemoWork *)p)->frame = v; }




void POKETRADE_DEMO_COMMON_SetFinishFlag(u8 *p) { ((PokeTradeDemoWork *)p)->finishFlag = 1; }




void POKETRADE_DEMO_COMMON_StepCompareMons(u8 *p)
{
    POKETRADE_3D_FadeTexturePalette((char *)p);
    if (((PokeTradeDemoWork *)p)->sceneStarted == 1) {
        POKETRADE_DEMO_COMMON_CompareSideMon(p, &((PokeTradeDemoWork *)p)->enemySameMon, &((PokeTradeDemoWork *)p)->enemySpecialMon, ((PokeTradeDemoWork *)p)->enemyMonKey, 1);
        POKETRADE_DEMO_COMMON_CompareSideMon(p, &((PokeTradeDemoWork *)p)->ownSameMon, &((PokeTradeDemoWork *)p)->ownSpecialMon, ((PokeTradeDemoWork *)p)->ownMonKey, 0);
        POKETRADE_3D_RemoveCurrentUnit(p);
        if (POKETRADE_PROC_IsNetSession(p) != 0) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8);
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_COMMON_StepWaitSync);
        } else {
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_COMMON_StepStartSlides);
        }
    }
}



void POKETRADE_DEMO_COMMON_StepWaitSync(u8 *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 8) != 0) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_COMMON_StepStartSlides);
    }
}



void POKETRADE_DEMO_COMMON_StepStartSlides(u8 *p)
{
    Vec a;
    Vec b;

    POKETRADE_DEMO_COMMON_SetFrame(p, 0);
    ((PokeTradeDemoWork *)p)->fade = func_02030734(((PokeTradeDemoWork *)p)->heapId, 4, 1, d_021D7FB8, 0xF5);
    ((PokeTradeDemoWork *)p)->fade[0] = POKETRADE_DEMO_COMMON_PassThrough(0xE);
    ((PokeTradeDemoWork *)p)->fade[1] = 0;
    ((PokeTradeDemoWork *)p)->fade[2] = 0;
    ((PokeTradeDemoWork *)p)->fade[3] = -0x10;
    a = d_021D7C84;
    POKETRADE_SAVE_FreeIfSet((u32 *)((PokeTradeDemoWork *)p)->slideOwn);
    ((PokeTradeDemoWork *)p)->slideOwn = POKETRADE_MCSS_SlideCreate((void *)((PokeTradeDemoWork *)p)->mcssObj[0], (void *)POKETRADE_DEMO_COMMON_PassThrough(0x2A), &a, ((PokeTradeDemoWork *)p)->heapId);
    b = d_021D7C9C;
    POKETRADE_SAVE_FreeIfSet((u32 *)((PokeTradeDemoWork *)p)->slidePeer);
    ((PokeTradeDemoWork *)p)->slidePeer = POKETRADE_MCSS_SlideCreate((void *)((PokeTradeDemoWork *)p)->mcssObj[1], (void *)POKETRADE_DEMO_COMMON_PassThrough(0x54), &b, ((PokeTradeDemoWork *)p)->heapId);
    MCSS_SetAnimCallback((u32)((PokeTradeDemoWork *)p)->mcssObj[0], p, (void (*)(void))POKETRADE_MCSS_StopAnimation, 1);
    MCSS_SetPaletteFade((struct McssFade *)((PokeTradeDemoWork *)p)->mcssObj[1], 0, 0x10, (s8)(POKETRADE_DEMO_COMMON_PassThrough(0xE) / 16), 0);
    POKETRADE_SAVE_CloseMessageWindow((char *)p);
    BG_SYS_LoadPlttEntry(1, 0);
    BG_SYS_LoadPlttEntry(5, 0);
    POKETRADE_DEMO_COMMON_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_StepStartPlayback);
}




void POKETRADE_DEMO_COMMON_StepBeginPlayback(u8 *p)
{
    Vec a;
    Vec b;
    PokeTradeDemoWork *w = (PokeTradeDemoWork *)p;

    POKETRADE_DEMO_DOWN_SetFrame(p, 0);
    w->fade = func_02030734(w->heapId, 4, 1, d_021D8650, 0xF5);
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
    MCSS_SetAnimCallback((u32)w->mcssObj[0], p, (void (*)(void))POKETRADE_MCSS_StopAnimation, 1);
    MCSS_SetPaletteFade((struct McssFade *)w->mcssObj[1], 0, 0x10, (s8)(POKETRADE_DEMO_DOWN_PassThrough(0xE) / 16), 0);
    POKETRADE_SAVE_CloseMessageWindow((char *)p);
    BG_SYS_LoadPlttEntry(1, 0);
    BG_SYS_LoadPlttEntry(5, 0);
    POKETRADE_DEMO_DOWN_SetFrame(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_StepStartPlayback);
}
