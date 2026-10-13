/*
 * file:     weather.c
 * unit:     yes
 * function: func_021A19E8, func_021A1AAC, func_021A1AF4, func_021A1B38, func_021A1B50, func_021A1B74, func_021A1BDC, func_021A1BE4, func_021A1BF4, func_021A1BF8, func_021A1C04, func_021A1C1C, func_021A1C34, func_021A1C68, func_021A1D04, func_021A1D78
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
 *   func_0204B100  0x0204B100  arm
 *   func_0204B034  0x0204B034  arm
 *   func_0204B258  0x0204B258  arm
 *   func_021A1DB4  0x021A1DB4  thumb  ov021
 *   func_020056A0  0x020056A0  thumb
 *   d_021DDE74     0x021DDE74  data
 *   d_021D8850     0x021D8850  data
 *   d_021D8840     0x021D8840  data
 *   func_02030734  0x02030734  arm
 *   func_021A15A4  0x021A15A4  thumb  ov021
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204B084  0x0204B084  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_021A15D4  0x021A15D4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   d_021DDE6C     0x021DDE6C  data  ov021  a4
 *   func_021A15F4  0x021A15F4  thumb  ov021
 *   d_021D8868     0x021D8868  data  ov021  a4
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021A1670  0x021A1670  thumb  ov021
 *   func_021A1DF8  0x021A1DF8  thumb  ov021
 *   func_021A1E08  0x021A1E08  thumb  ov021
 *   func_021A1FEC  0x021A1FEC  thumb  ov021
 *   func_021A2050  0x021A2050  thumb  ov021
 *   func_021A20C8  0x021A20C8  thumb  ov021
 *   func_021A21B0  0x021A21B0  thumb  ov021
 */
#include "weather_task_types.h"

struct Bank;
struct TextureList;

extern void func_02030EAC(int taskId);
extern void func_0204B084(struct TextureList *list);
extern u32 func_0204B1CC(struct Bank *bank);
extern int func_021A15D4(Field3dbgBillboard *billboard);
extern u32 func_020307B0(void *p);
extern int func_02034AC4(s32 overlayId);
extern void func_02034A5C(int overlayId);
void func_021A15F4(Field3dbgBillboard *billboard);
void func_021A1670(Field3dbgBillboard *billboard);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern Field3dbgBillboard *func_021A15A4(const Field3dbgBillboardDesc *desc, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct TextureList *func_0204B034(const void *desc, u32 count, u32 heapId);
extern void func_0204B258(struct Bank *bank, struct TextureList *list);
extern struct WeatherTaskSys *func_021A1DB4(struct Bank *bank, u32 obj10, u32 obj14, u32 obj18, u32 obj1C, WeatherSys *sys, u32 weatherParam, u16 zoneId, u16 heapId);
extern int func_020056A0(void (*cb)(int taskId, void *work), void *work, int priority);
WeatherSys *func_021A19E8(u32 obj10, u32 obj14, u32 obj18, u32 obj1C, u32 weatherParam, u16 zoneId, u16 heapId);
void func_021A1AAC(WeatherSys *sys);
void func_021A1AF4(WeatherSys *sys, u16 frames);
void func_021A1B38(WeatherSys *sys);
int func_021A1B50(WeatherSys *sys);
void func_021A1B74(WeatherSys *sys, int weatherId, int fadeParam);
void func_021A1BDC(WeatherSys *sys, u16 weatherId);
int func_021A1BE4(WeatherSys *sys, u16 weatherId);
u16 func_021A1BF4(WeatherSys *sys);
void func_021A1BF8(WeatherSys *sys, u32 overlayId);
void func_021A1C04(WeatherSys *sys);
void func_021A1C1C(int taskId, void *work);
int func_021A1C34(WeatherSys *sys, u16 weatherId);
void func_021A1C68(WeatherSys *sys, int frames);
void func_021A1D04(WeatherSys *sys, int frames);
int func_021A1D78(u16 currentWeatherId, u16 nextWeatherId);
/* Weather task (weather_task.c). */
void func_021A1DF8(struct WeatherTaskSys *task);
void func_021A1E08(struct WeatherTaskSys *task, u16 frames);
void func_021A1FEC(struct WeatherTaskSys *task, u32 weatherParam, u8 isFadeIn, u32 isAnimated, u32 fadeKind, u32 useFade, u32 fadeParam);
void func_021A2050(struct WeatherTaskSys *task, u32 isFadeOut, u32 fadeKind);
void func_021A20C8(struct WeatherTaskSys *task);
int func_021A21B0(struct WeatherTaskSys *task);
extern char d_021DDE74[];
extern Field3dbgBillboardDesc d_021D8850[];
extern u8 d_021D8840[];
extern void (*const d_021DDE6C[])(WeatherSys *sys, int frames);
typedef struct WeatherEntry {
    u32 taskParam;
    u32 overlayId;
} WeatherEntry;

extern const WeatherEntry d_021D8868[];

/*
 * WeatherSys constructor (weather.c): two billboard layers, a texture bank
 * with its texture list, two weather task objects and a per-frame update task.
 * The two loops use separate counters (one shared counter swaps p and the
 * counter between r4 and r5).
 */
WeatherSys *func_021A19E8(u32 obj10, u32 obj14, u32 obj18, u32 obj1C, u32 weatherParam, u16 zoneId, u16 heapId)
{
    int i;
    int j;
    WeatherSys *sys = func_02030734(heapId, sizeof(WeatherSys), 1, d_021DDE74, 0x158);

    for (i = 0; i < 2; i++) {
        sys->billboards[i] = func_021A15A4(&d_021D8850[i], heapId);
    }
    sys->mode = 0;
    sys->phase = 0;
    sys->weatherId = 0xFFFF;
    sys->nextWeatherId = 0xFFFF;
    sys->queuedWeatherId = 0xFFFF;
    sys->loadedOverlayId = -1;
    sys->textureBank = func_0204B100(0x40, 8, heapId);
    sys->textureList = func_0204B034(d_021D8840, 1, heapId);
    func_0204B258(sys->textureBank, sys->textureList);
    for (j = 0; j < 2; j++) {
        sys->tasks[j] = func_021A1DB4(sys->textureBank, obj10, obj14, obj18, obj1C, sys, weatherParam, zoneId, heapId);
    }
    sys->updateTaskId = func_020056A0(func_021A1C1C, sys, 0x40);
    return sys;
}

/* Destroy the update task, both weather tasks, the overlay, the texture bank and list, and the billboards. */
void func_021A1AAC(WeatherSys *sys)
{
    int i;

    func_02030EAC(sys->updateTaskId);
    for (i = 0; i < 2; i++) {
        func_021A1DF8(sys->tasks[i]);
    }
    func_021A1C04(sys);
    func_0204B084(sys->textureList);
    func_0204B1CC(sys->textureBank);
    for (i = 0; i < 2; i++) {
        func_021A15D4(sys->billboards[i]);
    }
    func_020307B0(sys);
}

/* Run the handler of the current transition mode, apply a queued request once idle, update both tasks. */
void func_021A1AF4(WeatherSys *sys, u16 frames)
{
    int i;
    u16 queued;

    d_021DDE6C[sys->mode](sys, frames);
    if (sys->phase == 0) {
        queued = sys->queuedWeatherId;
        if (queued != 0xFFFF) {
            func_021A1BDC(sys, queued);
            sys->queuedWeatherId = 0xFFFF;
        }
    }
    for (i = 0; i < 2; i++) {
        func_021A1E08(sys->tasks[i], frames);
    }
}

/* Draw both billboard layers. */
void func_021A1B38(WeatherSys *sys)
{
    int i;

    if (sys != 0) {
        for (i = 0; i < 2; i++)
            func_021A15F4(sys->billboards[i]);
    }
}

/* 1 while either weather task is still active. */
int func_021A1B50(WeatherSys *sys)
{
    int i;

    if (sys != 0) {
        for (i = 0; i < 2; i++) {
            if (func_021A21B0(sys->tasks[i]) == 1)
                return 1;
        }
    }
    return 0;
}

/* Switch to weatherId at once: stop both tasks, load its overlay and start it on the first task. */
void func_021A1B74(WeatherSys *sys, int weatherId, int fadeParam)
{
    int i;
    u32 taskParam;

    if (weatherId == sys->weatherId && weatherId != 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        func_021A20C8(sys->tasks[i]);
    }
    func_021A1C04(sys);
    sys->phase = 0;
    func_021A1BF8(sys, d_021D8868[weatherId].overlayId);
    taskParam = d_021D8868[weatherId].taskParam;
    func_021A1FEC(sys->tasks[0], taskParam, 0, 0, 1, 1, fadeParam);
    sys->weatherId = weatherId;
    sys->nextWeatherId = 0xFFFF;
}

/*
 * Tail-call thunk: forwards to func_021A1C34 with no argument change.
 */
void func_021A1BDC(WeatherSys *sys, u16 weatherId)
{
    func_021A1C34(sys, weatherId);
}

/* Request a weather change without the fade. */
int func_021A1BE4(WeatherSys *sys, u16 weatherId)
{
    func_021A1C34(sys, weatherId);
    sys->useFade = 0;
    return 0;
}

u16 func_021A1BF4(WeatherSys *sys)
{
    return sys->weatherId;
}

/* Load the overlay of the weather and remember its id. */
void func_021A1BF8(WeatherSys *sys, u32 overlayId)
{
    sys->loadedOverlayId = overlayId;
    func_02034AC4(overlayId);
}

/* Unload the weather overlay if one is loaded. */
void func_021A1C04(WeatherSys *sys)
{
    if (sys->loadedOverlayId != -1) {
        func_02034A5C(sys->loadedOverlayId);
        sys->loadedOverlayId = -1;
    }
}

/* Per-frame task: release the VRAM copy of both billboard textures. */
void func_021A1C1C(int taskId, void *work)
{
    WeatherSys *sys = work;
    int i;

    for (i = 0; i < 2; i++)
        func_021A1670(sys->billboards[i]);
}

/* Start a transition to weatherId, or queue the request while one is running. */
int func_021A1C34(WeatherSys *sys, u16 weatherId)
{
    if (sys->phase != 0) {
        sys->queuedWeatherId = weatherId;
        return 0;
    }
    if (sys->weatherId == weatherId && weatherId != 0)
        return 0;
    sys->nextWeatherId = weatherId;
    sys->useFade = 1;
    sys->mode = func_021A1D78(sys->weatherId, sys->nextWeatherId);
    sys->phase = 1;
    return 1;
}

/* Mode 0 handler (sequential): fade the current weather out, switch overlays, start the next. */
void func_021A1C68(WeatherSys *sys, int frames)
{
    switch (sys->phase) {
    case 0:
        break;
    case 1:
        func_021A2050(sys->tasks[0], 1, 1);
        sys->phase = 2;
        break;
    case 2:
        if (func_021A21B0(sys->tasks[0]) == 0) {
            func_021A1C04(sys);
            sys->phase = 3;
        }
        break;
    case 3:
        func_021A1BF8(sys, d_021D8868[sys->nextWeatherId].overlayId);
        sys->phase = 4;
        break;
    case 4:
        func_021A1FEC(sys->tasks[0], d_021D8868[sys->nextWeatherId].taskParam, 1, 1, 1, sys->useFade, frames);
        sys->useFade = 1;
        sys->weatherId = sys->nextWeatherId;
        sys->nextWeatherId = 0xFFFF;
        sys->phase = 0;
        break;
    }
}

/* Mode 1 handler (crossfade): start the next weather on the spare task, fade out the first, swap the tasks. */
void func_021A1D04(WeatherSys *sys, int frames)
{
    struct WeatherTaskSys *swap;

    switch (sys->phase) {
    case 0:
        break;
    case 1:
        func_021A1FEC(sys->tasks[1], d_021D8868[sys->nextWeatherId].taskParam, 1, 1, 2, sys->useFade, frames);
        func_021A2050(sys->tasks[0], 1, 2);
        sys->phase = 2;
        break;
    case 2:
        if (func_021A21B0(sys->tasks[0]) == 0) {
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
int func_021A1D78(u16 currentWeatherId, u16 nextWeatherId)
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
