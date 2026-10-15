/*
 * file:     enceff_screen_tex.c
 * unit:     yes
 * function: ENCEFF_StartScreenTexEffectFlash, ENCEFF_StartScreenTexEffect, ENCEFF_DrawScreenTexEffect, ENCEFF_ScreenTexFlashEventMain, ENCEFF_RequestScreenCapture, ENCEFF_ScreenCaptureTask, ENCEFF_GetScreenTexParam, ENCEFF_ScreenTexEventMain
 * address:  0x021F5260
 * region:   ov075
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Four-state proc; its states 1-3 are ENCEFF_ScreenTexFlashEventMain's states 4-6, and the
 * shape follows ov073's ENCEFF_NameCutInEventMain.
 *
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   G3i_PerspectiveW_  0x0207D704  arm
 *   G3X_Reset  0x0207DA8C  arm
 *   G3i_LookAt_  0x0207D7C4  arm
 *   d_020A1EB8     0x020A1EB8  data  a4
 *   d_021F55F8     0x021F55F8  data  ov075  a4
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm
 *   FIELDMAP_GetDrawMode  0x021899F0  thumb  ov021
 *   GX_GetBankForTex  0x02080C44  arm
 *   func_02080B98  0x02080B98  arm
 *   func_02080294  0x02080294  arm
 *   func_02040588  0x02040588  arm
 *   FIELDMAP_SetDrawMode  0x021899F8  thumb  ov021
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_GetWork  0x021CF560  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   func_0208068C 0x0208068C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 */
#include "../ov021/fieldmap_types.h"
#include "enceff_screen_tex_types.h"

#define REG_G3_TEXIMAGE_PARAM (*(volatile u32 *)0x040004A8)
/*
 * Texture parameter for the captured screen: the count of texture banks in
 * use, as a texture address.
 * lever: enum Bank preserves the cumulative OR tests; u32 folds the final test.
 */
typedef enum { BANK_NONE, BANK_A = 1, BANK_B = 2, BANK_C = 4 } Bank;

extern struct GameEvent *func_020122C0(void *owner, void *arg, GameEventMainFunc main, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void G3i_PerspectiveW_(int a, int b, int c, int d, int e, int f, int g, int h);
extern void G3X_Reset(void);
extern void G3i_LookAt_(VecFx32 *eye, VecFx32 *up, VecFx32 *target, int d, int e);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern struct FieldMap *ICA_ANIME_GetField20(const struct GameSystem *gameSystem);
extern void BG_SYS_SetVisibleLayer(int idx, u16 val);
extern int FIELDMAP_GetDrawMode(struct FieldMap *fieldMap);
extern void FIELDMAP_SetDrawMode(struct FieldMap *fieldMap, int drawMode);
extern u16 GX_GetBankForTex(void);
extern void func_02080B98(void);
extern void func_02080294(u32 bank);
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct EncEff *FIELDMAP_GetEncEff(struct FieldMap *fieldMap);
extern void *ENCEFF_GetWork(struct EncEff *eff);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern void FADE_Start(u32 flags, s32 start, s32 end, s32 step);
extern int FADE_IsActive(void);
extern void func_0208068C(int);
extern void *func_020056A0(u32, u32, u32);
extern void func_02030EAC(void *task);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
struct GameEvent *ENCEFF_StartScreenTexEffectFlash(struct GameSystem *gameSystem, VecFx32 *cameraPos, EncEffScreenTexStartFunc start, EncEffScreenTexDrawFunc draw);
struct GameEvent *ENCEFF_StartScreenTexEffect(struct GameSystem *gameSystem, VecFx32 *cameraPos, EncEffScreenTexStartFunc start, EncEffScreenTexDrawFunc draw);
void ENCEFF_DrawScreenTexEffect(EncEffScreenTexWork *work);
int ENCEFF_ScreenTexFlashEventMain(struct GameEvent *event, int *state, EncEffScreenTexWork *work);
void ENCEFF_RequestScreenCapture(EncEffScreenTexWork *work);
void ENCEFF_ScreenCaptureTask(void *task, int *captureDone);
u32 ENCEFF_GetScreenTexParam(void);
int ENCEFF_ScreenTexEventMain(struct GameEvent *event, int *state, EncEffScreenTexWork *work);
extern const s16 d_020A1EB8[];
extern VecFx32 d_021F55F8;


/* Display capture control and the geometry engine texture parameter port. */
#define REG_DISPCAPCNT (*(volatile u32 *)0x04000064)


/* Starts the effect with two white flashes before the capture. */
struct GameEvent *ENCEFF_StartScreenTexEffectFlash(struct GameSystem *gameSystem, VecFx32 *cameraPos, EncEffScreenTexStartFunc start, EncEffScreenTexDrawFunc draw)
{
    struct GameEvent *event;
    EncEffScreenTexWork *work;

    event = func_020122C0(gameSystem, 0, (GameEventMainFunc)ENCEFF_ScreenTexFlashEventMain, 48);
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, 48);
    work->cameraPos = *cameraPos;
    work->start = start;
    work->draw = draw;
    return event;
}


/* Starts the effect without the flashes. */
struct GameEvent *ENCEFF_StartScreenTexEffect(struct GameSystem *gameSystem, VecFx32 *cameraPos, EncEffScreenTexStartFunc start, EncEffScreenTexDrawFunc draw)
{
    struct GameEvent *event;
    EncEffScreenTexWork *work;

    event = func_020122C0(gameSystem, 0, (GameEventMainFunc)ENCEFF_ScreenTexEventMain, 0x30);
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, 0x30);
    work->cameraPos = *cameraPos;
    work->start = start;
    work->draw = draw;
    return event;
}



static inline void G3_Perspective(int fovySin, int fovyCos, int aspect, int near, int far, void *mtx)
{
    G3i_PerspectiveW_(fovySin, fovyCos, aspect, near, far, 0x1000, 1, (int)mtx);
}



/* Sets the projection and the camera, then draws the captured texture and the effect. */
void ENCEFF_DrawScreenTexEffect(EncEffScreenTexWork *work)
{
    VecFx32 up;

    G3_Perspective(d_020A1EB8[6], d_020A1EB8[7], 0x1555, 0x1000, 0x400000, 0);
    G3X_Reset();
    up = d_021F55F8;
    {
        VecFx32 target = {0, 0, 0};
        VecFx32 eye;

        eye = work->cameraPos;
        G3i_LookAt_(&eye, &up, &target, 1, 0);
    }
    REG_G3_TEXIMAGE_PARAM = ((u16)work->texParam & 0x1FFFFFFF) | 0x5ED00000;
    work->draw(work->effectWork);
}



/*
 * Seven-state event: two white flashes (states 0 to 2), then the same
 * states as ENCEFF_ScreenTexEventMain (its 0 to 3 are states 3 to 6 here).  EXACT* only
 * because the listing extent holds the 2-byte alignment pad at 0x021F549E.
 */
int ENCEFF_ScreenTexFlashEventMain(struct GameEvent *event, int *state, EncEffScreenTexWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u32 texBanks;
    struct GameEvent *child;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    switch (*state) {
    case 0:
        FADE_Start(4, 0, 0x10, 0);
        *state = *state + 1;
    case 1:
        if (FADE_IsActive() == 0) {
            FADE_Start(4, 0x10, 0, 0);
            *state = *state + 1;
        }
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            work->flashCount = work->flashCount + 1;
            if (work->flashCount < 2) {
                FADE_Start(4, 0, 0x10, 0);
                *state = 1;
            } else {
                *state = *state + 1;
            }
        }
        break;
    case 3:
        ENCEFF_RequestScreenCapture(work);
        *state = *state + 1;
        break;
    case 4:
        if (work->captureDone != 0) {
            BG_SYS_SetVisibleLayer(0, 0);
            BG_SYS_SetVisibleLayer(2, 3);
            work->savedDrawMode = FIELDMAP_GetDrawMode(fieldMap);
            texBanks = GX_GetBankForTex();
            work->texBanks = texBanks;
            work->addedTexBank = 0;
            if ((texBanks & 8) == 0) {
                work->texBanks = texBanks | 8;
                work->addedTexBank = 1;
            }
            func_02080B98();
            func_02080294(work->texBanks);
            work->texParam = ENCEFF_GetScreenTexParam();
            *state = *state + 1;
        }
        break;
    case 5:
        func_02040588(2, 1);
        func_02040588(0, 1);
        FIELDMAP_SetDrawMode(fieldMap, 2);
        child = work->start(gameSystem);
        work->effectWork = ENCEFF_GetWork(FIELDMAP_GetEncEff(fieldMap));
        GAME_EVENT_CallEvent(event, child);
        *state = *state + 1;
        break;
    case 6:
        if (work->addedTexBank == 1) {
            work->texBanks &= ~8;
            func_02080294(work->texBanks);
        }
        FIELDMAP_SetDrawMode(fieldMap, work->savedDrawMode);
        return 1;
    }
    return 0;
}


/* Asks for a capture of the screen into LCDC VRAM; the task sets captureDone. */
void ENCEFF_RequestScreenCapture(EncEffScreenTexWork *work)
{
    work->captureDone = 0;
    func_0208068C(8);
    func_020056A0((u32)ENCEFF_ScreenCaptureTask, (u32)&work->captureDone, 0);
}


/* Main task: starts the display capture, then reports it through the flag. */
void ENCEFF_ScreenCaptureTask(void *task, int *captureDone)
{
    REG_DISPCAPCNT = 0x81330010;
    func_02030EAC(task);
    if (captureDone)
        *captureDone = 1;
}


u32 ENCEFF_GetScreenTexParam(void)
{
    Bank banks;
    u32 count;

    banks = GX_GetBankForTex();
    count = 0;
    banks |= 4; if (banks) count += 0x20000;
    banks |= 2; if (banks) count += 0x20000;
    banks |= 1; if (banks) count += 0x20000;
    return 0x20000000 | ((u16)(count >> 3));
}


int ENCEFF_ScreenTexEventMain(struct GameEvent *event, int *state, EncEffScreenTexWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    u32 texBanks;
    struct GameEvent *child;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    switch (*state) {
    case 0:
        ENCEFF_RequestScreenCapture(work);
        *state = *state + 1;
        break;
    case 1:
        if (work->captureDone != 0) {
            BG_SYS_SetVisibleLayer(0, 0);
            BG_SYS_SetVisibleLayer(2, 3);
            work->savedDrawMode = FIELDMAP_GetDrawMode(fieldMap);
            texBanks = GX_GetBankForTex();
            work->texBanks = texBanks;
            work->addedTexBank = 0;
            if ((texBanks & 8) == 0) {
                work->texBanks = texBanks | 8;
                work->addedTexBank = 1;
            }
            func_02080B98();
            func_02080294(work->texBanks);
            work->texParam = ENCEFF_GetScreenTexParam();
            *state = *state + 1;
        }
        break;
    case 2:
        func_02040588(2, 1);
        func_02040588(0, 1);
        FIELDMAP_SetDrawMode(fieldMap, 2);
        child = work->start(gameSystem);
        work->effectWork = ENCEFF_GetWork(FIELDMAP_GetEncEff(fieldMap));
        GAME_EVENT_CallEvent(event, child);
        *state = *state + 1;
        break;
    case 3:
        if (work->addedTexBank == 1) {
            work->texBanks &= ~8;
            func_02080294(work->texBanks);
        }
        FIELDMAP_SetDrawMode(fieldMap, work->savedDrawMode);
        return 1;
    }
    return 0;
}
