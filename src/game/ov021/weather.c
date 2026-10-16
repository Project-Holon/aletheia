/*
 * file:     weather.c
 * unit:     yes
 * function: WEATHER_Create, WEATHER_Delete, WEATHER_Update, WEATHER_Draw, WEATHER_IsTaskActive, WEATHER_SetImmediate, WEATHER_RequestChange, WEATHER_RequestChangeNoFade, WEATHER_GetWeatherId, WEATHER_LoadOverlay, WEATHER_UnloadOverlay, WEATHER_ReleaseBillboardVramTask, WEATHER_StartTransition, WEATHER_UpdateSequential, WEATHER_UpdateCrossfade, WEATHER_GetTransitionMode
 * address:  0x021A19E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Head of weather.c (constructor, from field_3dbg.c) merged with the tail (from weather_task.c).
 *
 * symbols:
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   WEATHER_TASK_Create  0x021A1DB4  thumb  ov021
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   g_WeatherSourceName     0x021DDE74  data
 *   gWeatherBillboardDescs     0x021D8850  data
 *   gWeatherSurfaceInits     0x021D8840  data
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FIELD_3DBG_CreateBillboard  0x021A15A4  thumb  ov021
 *   TCB_DeleteTask  0x02030EAC  arm
 *   CLACT_DeleteRenderer  0x0204B084  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   FIELD_3DBG_DeleteBillboard  0x021A15D4  thumb  ov021
 *   GFL_HEAP_Free  0x020307B0  arm
 *   gWeatherTransitionHandlers     0x021DDE6C  data  ov021  a4
 *   FIELD_3DBG_DrawBillboard  0x021A15F4  thumb  ov021
 *   gWeatherTable     0x021D8868  data  ov021  a4
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   FIELD_3DBG_ReleaseBillboardTextureVram  0x021A1670  thumb  ov021
 *   WEATHER_TASK_Delete  0x021A1DF8  thumb  ov021
 *   WEATHER_TASK_Update  0x021A1E08  thumb  ov021
 *   WEATHER_TASK_Start  0x021A1FEC  thumb  ov021
 *   WEATHER_TASK_RequestEnd  0x021A2050  thumb  ov021
 *   WEATHER_TASK_ForceEnd  0x021A20C8  thumb  ov021
 *   WEATHER_TASK_GetPhase  0x021A21B0  thumb  ov021
 */
#include "weather_task_types.h"

struct Bank;
struct TextureList;

extern void TCB_DeleteTask(int taskId);
extern void CLACT_DeleteRenderer(struct TextureList *list);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern int FIELD_3DBG_DeleteBillboard(Field3dbgBillboard *billboard);
extern u32 GFL_HEAP_Free(void *p);
extern int GF_OVERLAY_Load(s32 overlayId);
extern void GF_OVERLAY_Unload(int overlayId);
void FIELD_3DBG_DrawBillboard(Field3dbgBillboard *billboard);
void FIELD_3DBG_ReleaseBillboardTextureVram(Field3dbgBillboard *billboard);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern Field3dbgBillboard *FIELD_3DBG_CreateBillboard(const Field3dbgBillboardDesc *desc, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct TextureList *CLACT_CreateRenderer(const void *desc, u32 count, u32 heapId);
extern void CLACT_SetUnitRenderer(struct Bank *bank, struct TextureList *list);
extern struct WeatherTaskSys *WEATHER_TASK_Create(struct Bank *bank, u32 obj10, u32 obj14, u32 obj18, u32 obj1C, WeatherSys *sys, u32 weatherParam, u16 zoneId, u16 heapId);
extern int GFL_USE_AddMainTask(void (*cb)(int taskId, void *work), void *work, int priority);
WeatherSys *WEATHER_Create(u32 obj10, u32 obj14, u32 obj18, u32 obj1C, u32 weatherParam, u16 zoneId, u16 heapId);
void WEATHER_Delete(WeatherSys *sys);
void WEATHER_Update(WeatherSys *sys, u16 frames);
void WEATHER_Draw(WeatherSys *sys);
int WEATHER_IsTaskActive(WeatherSys *sys);
void WEATHER_SetImmediate(WeatherSys *sys, int weatherId, int fadeParam);
void WEATHER_RequestChange(WeatherSys *sys, u16 weatherId);
int WEATHER_RequestChangeNoFade(WeatherSys *sys, u16 weatherId);
u16 WEATHER_GetWeatherId(WeatherSys *sys);
void WEATHER_LoadOverlay(WeatherSys *sys, u32 overlayId);
void WEATHER_UnloadOverlay(WeatherSys *sys);
void WEATHER_ReleaseBillboardVramTask(int taskId, void *work);
int WEATHER_StartTransition(WeatherSys *sys, u16 weatherId);
void WEATHER_UpdateSequential(WeatherSys *sys, int frames);
void WEATHER_UpdateCrossfade(WeatherSys *sys, int frames);
int WEATHER_GetTransitionMode(u16 currentWeatherId, u16 nextWeatherId);
/* Weather task (weather_task.c). */
void WEATHER_TASK_Delete(struct WeatherTaskSys *task);
void WEATHER_TASK_Update(struct WeatherTaskSys *task, u16 frames);
void WEATHER_TASK_Start(struct WeatherTaskSys *task, u32 weatherParam, u8 isFadeIn, u32 isAnimated, u32 fadeKind, u32 useFade, u32 fadeParam);
void WEATHER_TASK_RequestEnd(struct WeatherTaskSys *task, u32 isFadeOut, u32 fadeKind);
void WEATHER_TASK_ForceEnd(struct WeatherTaskSys *task);
int WEATHER_TASK_GetPhase(struct WeatherTaskSys *task);
extern char g_WeatherSourceName[];
extern Field3dbgBillboardDesc gWeatherBillboardDescs[];
extern u8 gWeatherSurfaceInits[];
extern void (*const gWeatherTransitionHandlers[])(WeatherSys *sys, int frames);
typedef struct WeatherEntry {
    u32 taskParam;
    u32 overlayId;
} WeatherEntry;

extern const WeatherEntry gWeatherTable[];

/*
 * WeatherSys constructor (weather.c): two billboard layers, a texture bank
 * with its texture list, two weather task objects and a per-frame update task.
 * The two loops use separate counters (one shared counter swaps p and the
 * counter between r4 and r5).
 */
WeatherSys *WEATHER_Create(u32 obj10, u32 obj14, u32 obj18, u32 obj1C, u32 weatherParam, u16 zoneId, u16 heapId)
{
    int i;
    int j;
    WeatherSys *sys = GFL_HEAP_Alloc(heapId, sizeof(WeatherSys), 1, g_WeatherSourceName, 0x158);

    for (i = 0; i < 2; i++) {
        sys->billboards[i] = FIELD_3DBG_CreateBillboard(&gWeatherBillboardDescs[i], heapId);
    }
    sys->mode = 0;
    sys->phase = 0;
    sys->weatherId = 0xFFFF;
    sys->nextWeatherId = 0xFFFF;
    sys->queuedWeatherId = 0xFFFF;
    sys->loadedOverlayId = -1;
    sys->textureBank = CLACT_CreateUnit(0x40, 8, heapId);
    sys->textureList = CLACT_CreateRenderer(gWeatherSurfaceInits, 1, heapId);
    CLACT_SetUnitRenderer(sys->textureBank, sys->textureList);
    for (j = 0; j < 2; j++) {
        sys->tasks[j] = WEATHER_TASK_Create(sys->textureBank, obj10, obj14, obj18, obj1C, sys, weatherParam, zoneId, heapId);
    }
    sys->updateTaskId = GFL_USE_AddMainTask(WEATHER_ReleaseBillboardVramTask, sys, 0x40);
    return sys;
}

/* Destroy the update task, both weather tasks, the overlay, the texture bank and list, and the billboards. */
void WEATHER_Delete(WeatherSys *sys)
{
    int i;

    TCB_DeleteTask(sys->updateTaskId);
    for (i = 0; i < 2; i++) {
        WEATHER_TASK_Delete(sys->tasks[i]);
    }
    WEATHER_UnloadOverlay(sys);
    CLACT_DeleteRenderer(sys->textureList);
    CLACT_DeleteUnit(sys->textureBank);
    for (i = 0; i < 2; i++) {
        FIELD_3DBG_DeleteBillboard(sys->billboards[i]);
    }
    GFL_HEAP_Free(sys);
}

/* Run the handler of the current transition mode, apply a queued request once idle, update both tasks. */
void WEATHER_Update(WeatherSys *sys, u16 frames)
{
    int i;
    u16 queued;

    gWeatherTransitionHandlers[sys->mode](sys, frames);
    if (sys->phase == 0) {
        queued = sys->queuedWeatherId;
        if (queued != 0xFFFF) {
            WEATHER_RequestChange(sys, queued);
            sys->queuedWeatherId = 0xFFFF;
        }
    }
    for (i = 0; i < 2; i++) {
        WEATHER_TASK_Update(sys->tasks[i], frames);
    }
}

/* Draw both billboard layers. */
void WEATHER_Draw(WeatherSys *sys)
{
    int i;

    if (sys != 0) {
        for (i = 0; i < 2; i++)
            FIELD_3DBG_DrawBillboard(sys->billboards[i]);
    }
}

/* 1 while either weather task is still active. */
int WEATHER_IsTaskActive(WeatherSys *sys)
{
    int i;

    if (sys != 0) {
        for (i = 0; i < 2; i++) {
            if (WEATHER_TASK_GetPhase(sys->tasks[i]) == 1)
                return 1;
        }
    }
    return 0;
}

/* Switch to weatherId at once: stop both tasks, load its overlay and start it on the first task. */
void WEATHER_SetImmediate(WeatherSys *sys, int weatherId, int fadeParam)
{
    int i;
    u32 taskParam;

    if (weatherId == sys->weatherId && weatherId != 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        WEATHER_TASK_ForceEnd(sys->tasks[i]);
    }
    WEATHER_UnloadOverlay(sys);
    sys->phase = 0;
    WEATHER_LoadOverlay(sys, gWeatherTable[weatherId].overlayId);
    taskParam = gWeatherTable[weatherId].taskParam;
    WEATHER_TASK_Start(sys->tasks[0], taskParam, 0, 0, 1, 1, fadeParam);
    sys->weatherId = weatherId;
    sys->nextWeatherId = 0xFFFF;
}

/*
 * Tail-call thunk: forwards to WEATHER_StartTransition with no argument change.
 */
void WEATHER_RequestChange(WeatherSys *sys, u16 weatherId)
{
    WEATHER_StartTransition(sys, weatherId);
}

/* Request a weather change without the fade. */
int WEATHER_RequestChangeNoFade(WeatherSys *sys, u16 weatherId)
{
    WEATHER_StartTransition(sys, weatherId);
    sys->useFade = 0;
    return 0;
}

u16 WEATHER_GetWeatherId(WeatherSys *sys)
{
    return sys->weatherId;
}

/* Load the overlay of the weather and remember its id. */
void WEATHER_LoadOverlay(WeatherSys *sys, u32 overlayId)
{
    sys->loadedOverlayId = overlayId;
    GF_OVERLAY_Load(overlayId);
}

/* Unload the weather overlay if one is loaded. */
void WEATHER_UnloadOverlay(WeatherSys *sys)
{
    if (sys->loadedOverlayId != -1) {
        GF_OVERLAY_Unload(sys->loadedOverlayId);
        sys->loadedOverlayId = -1;
    }
}

/* Per-frame task: release the VRAM copy of both billboard textures. */
void WEATHER_ReleaseBillboardVramTask(int taskId, void *work)
{
    WeatherSys *sys = work;
    int i;

    for (i = 0; i < 2; i++)
        FIELD_3DBG_ReleaseBillboardTextureVram(sys->billboards[i]);
}

/* Start a transition to weatherId, or queue the request while one is running. */
int WEATHER_StartTransition(WeatherSys *sys, u16 weatherId)
{
    if (sys->phase != 0) {
        sys->queuedWeatherId = weatherId;
        return 0;
    }
    if (sys->weatherId == weatherId && weatherId != 0)
        return 0;
    sys->nextWeatherId = weatherId;
    sys->useFade = 1;
    sys->mode = WEATHER_GetTransitionMode(sys->weatherId, sys->nextWeatherId);
    sys->phase = 1;
    return 1;
}

/* Mode 0 handler (sequential): fade the current weather out, switch overlays, start the next. */
void WEATHER_UpdateSequential(WeatherSys *sys, int frames)
{
    switch (sys->phase) {
    case 0:
        break;
    case 1:
        WEATHER_TASK_RequestEnd(sys->tasks[0], 1, 1);
        sys->phase = 2;
        break;
    case 2:
        if (WEATHER_TASK_GetPhase(sys->tasks[0]) == 0) {
            WEATHER_UnloadOverlay(sys);
            sys->phase = 3;
        }
        break;
    case 3:
        WEATHER_LoadOverlay(sys, gWeatherTable[sys->nextWeatherId].overlayId);
        sys->phase = 4;
        break;
    case 4:
        WEATHER_TASK_Start(sys->tasks[0], gWeatherTable[sys->nextWeatherId].taskParam, 1, 1, 1, sys->useFade, frames);
        sys->useFade = 1;
        sys->weatherId = sys->nextWeatherId;
        sys->nextWeatherId = 0xFFFF;
        sys->phase = 0;
        break;
    }
}

/* Mode 1 handler (crossfade): start the next weather on the spare task, fade out the first, swap the tasks. */
void WEATHER_UpdateCrossfade(WeatherSys *sys, int frames)
{
    struct WeatherTaskSys *swap;

    switch (sys->phase) {
    case 0:
        break;
    case 1:
        WEATHER_TASK_Start(sys->tasks[1], gWeatherTable[sys->nextWeatherId].taskParam, 1, 1, 2, sys->useFade, frames);
        WEATHER_TASK_RequestEnd(sys->tasks[0], 1, 2);
        sys->phase = 2;
        break;
    case 2:
        if (WEATHER_TASK_GetPhase(sys->tasks[0]) == 0) {
            swap = sys->tasks[0];
            sys->tasks[0] = sys->tasks[1];
            sys->tasks[1] = swap;
            sys->weatherId = sys->nextWeatherId;
            sys->nextWeatherId = 0xFFFF;
            sys->useFade = 1;
            sys->phase = 0;
        }
        break;
    }
}

/* Transition mode for a weather pair: 1 (crossfade) between weather 1 and 4/5 and between 4 and 5, else 0. */
int WEATHER_GetTransitionMode(u16 currentWeatherId, u16 nextWeatherId)
{
    int mode = 0;

    switch (currentWeatherId) {
    case 1:
        if ((u16)(nextWeatherId + 0xFFFC) <= 1)
            mode = 1;
        break;
    case 4:
        if (nextWeatherId == 1 || nextWeatherId == 5)
            mode = 1;
        break;
    case 5:
        if (nextWeatherId == 4 || nextWeatherId == 1)
            mode = 1;
        break;
    }
    return mode;
}
