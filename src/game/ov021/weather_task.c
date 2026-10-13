/*
 * file:     weather_task.c
 * unit:     yes
 * function: func_021A1DB4, func_021A1DF8, func_021A1E08, func_021A1FEC, func_021A2050, func_021A20C8, func_021A2108, func_021A2114, func_021A2120, func_021A2130, func_021A213C, func_021A2148, func_021A2154, func_021A2160, func_021A2170, func_021A2180, func_021A2190, func_021A21A0, func_021A21B0, func_021A21B8, func_021A21BC, func_021A21C8, func_021A21E0, func_021A21F8, func_021A2228, func_021A223C, func_021A2248, func_021A2254, func_021A22E0, func_021A231C, func_021A232C, func_021A2390, func_021A23B0, func_021A23D4, func_021A23E8, func_021A23F4, func_021A2400, func_021A240C, func_021A2418, func_021A2424, func_021A244C, func_021A2564, func_021A25BC, func_021A25CC, func_021A25DC, func_021A2604, func_021A2630, func_021A2638, func_021A2640, func_021A2654, func_021A26C4, func_021A26D8, func_021A2724, func_021A273C, func_021A274C, func_021A277C, func_021A27B8, func_021A27F8, func_021A282C, func_021A284C, func_021A2860, func_021A28A0, func_021A28CC, func_021A2924, func_021A2968, func_021A2970, func_021A2978, func_021A2994, func_021A29A8, func_021A29F4, func_021A2A18, func_021A2A68, func_021A2A84, func_021A2AAC, func_021A2AB8, func_021A2B8C, func_021A2BB8, func_021A2BC4, func_021A2BD4, func_021A2C10, func_021A2C24, func_021A2C28, func_021A2C2C, func_021A2C30, func_021A2C6C, func_021A2C98, func_021A2CC8, func_021A2CEC, func_021A2CF8, func_021A2D04, func_021A2D30
 * address:  0x021A1DB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from weather_task.c (lane L141): __FILE__ anchors 021A1DF4 and 021A2920 (d_021DDE80 "weather_task.c"); constructor 021A1DB4 allocates the 0x784-byte task.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   d_021DDE80     0x021DDE80  data  ov021  a4
 *   func_021A0244  0x021A0244  thumb  ov021
 *   func_021A0590  0x021A0590  thumb  ov021
 *   func_021A05D8  0x021A05D8  thumb  ov021
 *   func_021A0618  0x021A0618  thumb  ov021
 *   func_021A065C 0x021A065C thumb ov021
 *   func_0218E188 0x0218E188 thumb ov021
 *   func_021A063C 0x021A063C thumb ov021
 *   func_021A16D4 0x021A16D4 thumb ov021
 *   func_021A16E4 0x021A16E4 thumb ov021
 *   func_021A16E8 0x021A16E8 thumb ov021
 *   func_021A16DC 0x021A16DC thumb ov021
 *   func_021A16E0 0x021A16E0 thumb ov021
 *   func_021A01AC  0x021A01AC  thumb  ov021
 *   func_021A01CC  0x021A01CC  thumb  ov021
 *   func_021A01B4  0x021A01B4  thumb  ov021
 *   func_021A01BC  0x021A01BC  thumb  ov021
 *   func_021A01D8  0x021A01D8  thumb  ov021
 *   func_021A01A4  0x021A01A4  thumb  ov021
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_021A01D4  0x021A01D4  thumb  ov021
 *   func_021A0354  0x021A0354  thumb  ov021
 *   func_021A0380  0x021A0380  thumb  ov021
 *   func_021A0390  0x021A0390  thumb  ov021
 *   func_021A03A4  0x021A03A4  thumb  ov021
 *   func_021A03B8  0x021A03B8  thumb  ov021
 *   func_021A03CC  0x021A03CC  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_0207CF3C  0x0207CF3C  arm
 *   func_0207C768  0x0207C768  arm
 *   g_02148B54  0x02148B54  data
 *   func_0204B53C  0x0204B53C  arm
 *   func_0204B528  0x0204B528  arm
 *   func_02005C64  0x02005C64  thumb
 *   func_02028A7C  0x02028A7C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02028ACC  0x02028ACC  thumb
 *   func_020061F0  0x020061F0  thumb
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_02082BCC  0x02082BCC  arm
 *   data_021D88E8  0x021D88E8  data  a1
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_02082D44  0x02082D44  arm
 *   func_021A1698  0x021A1698  thumb  ov021
 *   func_021A16D8  0x021A16D8  thumb  ov021
 *   d_021EE710     0x021EE710  data  a4
 *   d_021EE710b    0x021EE710  data  a4
 *   func_021A1680  0x021A1680  thumb  ov021
 *   func_0204B294  0x0204B294  arm
 *   func_0204BA20  0x0204BA20  arm
 *   data_021D88E0  0x021D88E0  data  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02028B50  0x02028B50  thumb
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_021A0224  0x021A0224  thumb  ov021
 */
#include "weather_task_types.h"

typedef struct FieldCamera FieldCamera;
typedef struct FieldFog FieldFog;
typedef struct FieldLight FieldLight;
typedef struct FieldSoundSystem FieldSoundSystem;
typedef struct FieldZoneFog FieldZoneFog;
typedef struct Actor Actor;

extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int flag, const char *file, u16 line);
extern int func_021A0244(FieldFog *fog);
extern u32 func_021A0590(FieldLight *light, u32 arcId, u32 memberId, u32 frames);
void func_021A05D8(FieldLight *light);
extern void func_021A0618(FieldLight *light, u32 color, u32 frames, u32 returnFrames);
extern int func_021A065C(FieldLight *light);
int func_0218E188(FieldCamera *camera);
extern void func_021A063C(FieldLight *light, u32 color, u32 frames);
extern void func_021A16D4(Field3dbgBillboard *billboard, u32 value);
extern void func_021A16E4(Field3dbgBillboard *billboard, u32 value);
extern void func_021A16E8(Field3dbgBillboard *billboard, u32 value);
extern void func_021A16DC(Field3dbgBillboard *billboard, u32 value);
extern void func_021A16E0(Field3dbgBillboard *billboard, u32 value);
int func_021A01AC(FieldFog *fog, u32 blendMode);
int func_021A01CC(FieldFog *fog, u32 alpha);
int func_021A01B4(FieldFog *fog, u32 slope);
int func_021A01BC(FieldFog *fog, u32 offset);
void func_021A01D8(FieldFog *fog);
int func_021A01A4(FieldFog *fog, u32 flag);
extern void func_021A01FC(FieldFog *fog, u32 endOffset, u32 endSlope, u32 frames);
extern u32 func_021A01D4(FieldFog *fog);
u8 func_021A0354(FieldZoneFog *zoneFog);
int func_021A0380(FieldZoneFog *zoneFog);
int func_021A0390(FieldZoneFog *zoneFog);
int func_021A03A4(FieldZoneFog *zoneFog);
int func_021A03B8(FieldZoneFog *zoneFog);
int func_021A03CC(FieldZoneFog *zoneFog);
void *func_0218EC2C(FieldCamera *camera);
void func_02048B30(void *camera, VecFx32 *out);
extern void func_02048AE8(void *camera, VecFx32 *out);
extern fx32 func_0207CF3C(const VecFx32 *a, const VecFx32 *b);
extern u32 func_0207C768(u32 a, u32 b);
void func_0204B53C(const Actor *actor, WeatherScreenPos *out);
void func_0204B528(Actor *actor, const WeatherScreenPos *src);
int func_02005C64(void);
void func_02028A7C(FieldSoundSystem *soundSys, u32 seId);
void func_020061E4(u32 seId);
void func_02028ACC(FieldSoundSystem *soundSys, u32 seId, u32 who);
void func_020061F0(u32 seId, u32 who);
extern void func_0204B454(Actor *actor, WeatherScreenPos *out, u16 space);
u32 func_0204B404(Actor *actor, const WeatherScreenPos *pos, u32 space);
void func_02082BCC(void *p, int value, int size);
void func_0204B3DC(Actor *actor, unsigned int enabled);
void *func_020490F4(unsigned int archiveId, unsigned int heapId);
extern void func_02049238(void *archive);
int func_0204A6C8(void *archive, int a, int b, int c, int heapId);
int func_0204AC18(void *archive, int a, int b, int c, int d, int e, int heapId);
s32 func_0204AF28(void *archive, u32 cell, u32 cellAnim, u32 heapId);
void func_0204A8D4(u32 id);
void func_0204ADA4(u32 id);
void func_0204AFD8(u32 id);
void func_02082D44(const void *src, void *dst, int size);
int func_021A1698(Field3dbgBillboard *billboard, void *archive, void *textureDesc, int heapId);
void func_021A16D8(Field3dbgBillboard *billboard, u8 polygonId);
void func_021A1680(Field3dbgBillboard *billboard);
extern Actor *func_0204B294(void *textureBank, unsigned int charResId, unsigned int paletteResId, unsigned int cellResId, const void *position, unsigned short space, unsigned short heapId);
void func_0204BA20(Actor *actor, u32 value);
extern void func_0204B3B4(Actor *actor);
void func_02028B50(FieldSoundSystem *soundSys, int seId);
int func_02006148(u32 seId);
void func_020061F8(int handle);
void func_021A0224(FieldFog *fog, u32 startOffset, u32 endOffset, u32 startSlope, u32 endSlope, u16 frames);


WeatherTaskSys *func_021A1DB4(void *textureBank, FieldCamera *camera, FieldLight *light, FieldFog *fog, FieldZoneFog *zoneFog, WeatherSys *sys, FieldSoundSystem *soundSys, u16 zoneId, u16 heapId);
void func_021A1DF8(WeatherTaskSys *task);
void func_021A1E08(WeatherTaskSys *task, u16 heapId);
void func_021A1FEC(WeatherTaskSys *task, const WeatherKindDef *kind, u8 startMode, u32 updatesParticles, u32 variant, u32 useSoundSys, u32 reserved);
void func_021A2050(WeatherTaskSys *task, u32 updatesParticles, u32 variant);
void func_021A20C8(WeatherTaskSys *task);
int func_021A2108(WeatherTaskSys *task, int arcId, int memberId);
int func_021A2114(WeatherTaskSys *task, int arcId, u32 memberId);
void func_021A2120(WeatherTaskSys *task, int phase);
void func_021A2130(WeatherTaskSys *task, u32 color, u32 frames, u32 returnFrames);
int func_021A213C(WeatherTaskSys *task);
int func_021A2148(WeatherTaskSys *task);
void func_021A2154(WeatherTaskSys *task, u32 color, u32 frames);
void func_021A2160(WeatherTaskSys *task, unsigned int value, int layer);
void func_021A2170(WeatherTaskSys *task, unsigned int value, int layer);
void func_021A2180(WeatherTaskSys *task, unsigned int value, int layer);
void func_021A2190(WeatherTaskSys *task, unsigned int value, int layer);
void func_021A21A0(WeatherTaskSys *task, unsigned int value, int layer);
int func_021A21B0(WeatherTaskSys *task);
void *func_021A21B8(WeatherTaskSys *task);
int func_021A21BC(WeatherTaskSys *task);
WeatherParticle *func_021A21C8(WeatherTaskSys *task, int reserved);
void func_021A21E0(WeatherParticle *particle);
void func_021A21F8(WeatherTaskSys *task, int count, int interval, int targetCount, int targetInterval, int intervalStep, int stepsPerCountChange, int countStep, WeatherSpawnFunc spawn);
void func_021A2228(WeatherTaskSys *task, int targetCount, int targetInterval, int intervalStep, int countStep);
int func_021A223C(WeatherTaskSys *task, int arg);
int func_021A2248(WeatherTaskSys *task, int arg);
void func_021A2254(WeatherTaskSys *task, WeatherSpawnFunc spawn, int iterations, int growEvery, int growBy, u16 heapId);
void func_021A22E0(WeatherTaskSys *task, int slope, int offset, int phase);
void func_021A231C(WeatherTaskSys *task, int phase);
void func_021A232C(WeatherTaskSys *task, u8 slope, int offset, int frames, int mode);
void func_021A2390(WeatherTaskSys *task, int endOffset, int frames, int mode);
int func_021A23B0(WeatherTaskSys *task);
int func_021A23D4(WeatherTaskSys *task);
int func_021A23E8(WeatherTaskSys *task);
int func_021A23F4(WeatherTaskSys *task);
int func_021A2400(WeatherTaskSys *task);
int func_021A240C(WeatherTaskSys *task);
int func_021A2418(WeatherTaskSys *task);
void func_021A2424(WeatherTaskSys *task);
void func_021A244C(WeatherTaskSys *task, s32 *outX, s32 *outY);
void func_021A2564(WeatherTaskSys *task, int dx, int dy);
void func_021A25BC(WeatherTaskSys *task, u16 seId);
void func_021A25CC(WeatherTaskSys *task);
void func_021A25DC(WeatherTaskSys *task, int seId);
void func_021A2604(WeatherTaskSys *task, int seId, int who);
u8 *func_021A2630(WeatherParticle *particle);
Actor *func_021A2638(WeatherParticle *particle);
void func_021A2640(WeatherParticle *particle, WeatherScreenPos *out);
void func_021A2654(WeatherParticle *particle, u16 *src);
int func_021A26C4(WeatherParticle *particle, const WeatherScreenPos *pos);
void func_021A26D8(WeatherTaskSys *task);
int func_021A2724(WeatherTaskSys *task, WeatherKindStageFunc stageFunc, int heapId);
u8 func_021A273C(WeatherTaskSys *task);
WeatherParticle *func_021A274C(WeatherTaskSys *task);
void func_021A277C(WeatherTaskSys *task, WeatherParticle *particle);
void func_021A27B8(WeatherTaskSys *task, WeatherParticle *particle);
void func_021A27F8(WeatherTaskSys *task);
void func_021A282C(WeatherTaskSys *task, int heapId);
void func_021A284C(WeatherTaskSys *task);
void func_021A2860(WeatherTaskSys *task, u16 heapId);
void func_021A28A0(WeatherTaskSys *task);
void func_021A28CC(WeatherTaskSys *task, u16 heapId);
void func_021A2924(WeatherTaskSys *task);
void func_021A2968(WeatherTaskSys *task);
u8 func_021A2970(WeatherTaskSys *task);
void func_021A2978(WeatherResourceSet *resources, const WeatherKindDef *kind, u32 heapId);
void func_021A2994(WeatherResourceSet *resources);
void func_021A29A8(WeatherResourceSet *resources, const WeatherKindDef *kind, int heapId);
void func_021A29F4(WeatherResourceSet *resources);
void func_021A2A18(WeatherResourceSet *resources, int index, Field3dbgBillboard *billboard, const WeatherBillboardInit *init, unsigned short heapId);
void func_021A2A68(WeatherResourceSet *resources, int index, Field3dbgBillboard *billboard);
WeatherSpawner *func_021A2A84(WeatherSpawner *spawner, WeatherTaskSys *owner, u32 interval, u32 count, u32 targetCount, u32 targetInterval, u32 intervalStep, u32 stepsPerCountChange, u32 countStep, WeatherSpawnFunc spawn);
void func_021A2AAC(WeatherSpawner *spawner, int targetCount, int targetInterval, int intervalStep, int countStep);
s32 func_021A2AB8(WeatherSpawner *spawner, u32 arg);
int func_021A2B8C(WeatherSpawner *spawner, int arg);
void func_021A2BB8(WeatherParticle *particle);
int func_021A2BC4(WeatherParticle *particle);
void func_021A2BD4(WeatherParticle *particle, WeatherTaskSys *owner, const WeatherResourceSet *resources, void *textureBank, u16 heapId);
void func_021A2C10(WeatherParticle *particle);
u8 *func_021A2C24(WeatherParticle *particle);
Actor *func_021A2C28(WeatherParticle *particle);
void func_021A2C2C(WeatherSoundState *sound, u32 useSoundSys);
void func_021A2C30(WeatherSoundState *sound, FieldSoundSystem *soundSys, u16 seId);
void func_021A2C6C(WeatherSoundState *sound, FieldSoundSystem *soundSys);
void func_021A2C98(WeatherSoundState *sound, FieldSoundSystem *soundSys);
void func_021A2CC8(WeatherTaskSys *task, u8 slope, u32 offset, int firstStepFrames);
void func_021A2CEC(WeatherTaskSys *task);
u8 func_021A2CF8(WeatherTaskSys *task);
void func_021A2D04(WeatherTaskSys *task);
void func_021A2D30(WeatherViewScale *scale, int distance, int *outWidth, int *outHeight);
extern u8 d_021DDE80[];
extern WeatherViewScale g_02148B54;
extern const u8 data_021D88E8[];
extern unsigned char d_021EE710[12];
extern unsigned char d_021EE710b[12];
extern u32 data_021D88E0[];


/* Constructor: allocates the task and stores the objects it drives. */
WeatherTaskSys *func_021A1DB4(void *textureBank, FieldCamera *camera, FieldLight *light, FieldFog *fog, FieldZoneFog *zoneFog, WeatherSys *sys, FieldSoundSystem *soundSys, u16 zoneId, u16 heapId)
{
    WeatherTaskSys *task;

    task = func_02030734(heapId, sizeof(WeatherTaskSys), 1, (const char *)d_021DDE80, 0x17E);
    task->textureBank = textureBank;
    task->camera = camera;
    task->fog = fog;
    task->light = light;
    task->zoneFog = zoneFog;
    task->sys = sys;
    task->soundSys = soundSys;
    task->zoneId = zoneId;
    return task;
}


void func_021A1DF8(WeatherTaskSys *task)
{
    func_021A20C8(task);
    func_020307B0(task);
}


/* Runs the stage state machine of the task once per frame. */
void func_021A1E08(WeatherTaskSys *task, u16 heapId)
{
    if (func_021A2CF8(task) != 0 && func_021A0244(task->fog) == 0) {
        func_021A2D04(task);
        func_021A2CEC(task);
    }
    switch (task->stage) {
    case WEATHER_STAGE_IDLE:
        break;
    case WEATHER_STAGE_LOAD_ALL:
        func_021A282C(task, heapId);
        func_021A2860(task, heapId);
        func_021A28CC(task, heapId);
        func_021A2968(task);
        task->stage = WEATHER_STAGE_BEGIN;
        break;
    case WEATHER_STAGE_LOAD_RESOURCES:
        func_021A282C(task, heapId);
        task->stage = WEATHER_STAGE_LOAD_BILLBOARDS;
        break;
    case WEATHER_STAGE_LOAD_BILLBOARDS:
        func_021A2860(task, heapId);
        task->stage = WEATHER_STAGE_LOAD_PARTICLES;
        break;
    case WEATHER_STAGE_LOAD_PARTICLES:
        func_021A28CC(task, heapId);
        task->stage = WEATHER_STAGE_BEGIN;
        break;
    case WEATHER_STAGE_BEGIN:
        if (func_021A2724(task, task->kind->begin, heapId) != 0) {
            task->stage = task->updatesParticles != 0 ? WEATHER_STAGE_BEGIN_PARTICLES : WEATHER_STAGE_BEGIN_PLAIN;
        }
        func_021A2C98(&task->sound, task->soundSys);
        func_021A2968(task);
        break;
    case WEATHER_STAGE_BEGIN_PARTICLES:
        if (func_021A2724(task, task->kind->beginParticles, heapId) != 0) {
            task->stage = WEATHER_STAGE_RUN;
        }
        func_021A27F8(task);
        func_021A2C98(&task->sound, task->soundSys);
        break;
    case WEATHER_STAGE_BEGIN_PLAIN:
        if (func_021A2724(task, task->kind->beginPlain, heapId) != 0) {
            task->stage = WEATHER_STAGE_RUN;
        }
        func_021A2C98(&task->sound, task->soundSys);
        break;
    case WEATHER_STAGE_RUN:
        func_021A2724(task, task->kind->run, heapId);
        func_021A27F8(task);
        func_021A2C98(&task->sound, task->soundSys);
        break;
    case WEATHER_STAGE_END_PARTICLES:
        if (func_021A2724(task, task->kind->endParticles, heapId) != 0) {
            task->stage = WEATHER_STAGE_END_FADE;
        }
        func_021A27F8(task);
        func_021A2C98(&task->sound, task->soundSys);
        break;
    case WEATHER_STAGE_END_FADE:
        if (func_021A2724(task, task->kind->endFade, heapId) != 0) {
            task->stage = WEATHER_STAGE_END_FINISH;
        }
        func_021A27F8(task);
        func_021A2C98(&task->sound, task->soundSys);
        break;
    case WEATHER_STAGE_END_FINISH:
        if (func_021A2970(task) != 0) {
            func_021A2724(task, task->kind->endFinish, heapId);
        }
        task->stage = WEATHER_STAGE_RELEASE;
        break;
    case WEATHER_STAGE_RELEASE:
        func_021A2924(task);
        func_021A28A0(task);
        func_021A284C(task);
        func_021A26D8(task);
        task->stage = WEATHER_STAGE_IDLE;
        break;
    }
}


/* Starts a weather kind: stores the kind and picks the first load stage. */
void func_021A1FEC(WeatherTaskSys *task, const WeatherKindDef *kind, u8 startMode, u32 updatesParticles, u32 variant, u32 useSoundSys, u32 reserved)
{
    task->kind = kind;
    task->variant = (u8)variant;
    task->updatesParticles = (u8)updatesParticles;
    task->startMode = startMode;
    if (task->startMode == 0) {
        task->stage = WEATHER_STAGE_LOAD_ALL;
    } else if (task->startMode == 1) {
        task->stage = WEATHER_STAGE_LOAD_RESOURCES;
    }
    func_021A2C2C(&task->sound, useSoundSys);
}


/* Asks the running kind to end, either with its fade (particles) or at once. */
void func_021A2050(WeatherTaskSys *task, u32 updatesParticles, u32 variant)
{
    u32 phase;
    u32 stage;

    phase = func_021A273C(task);
    stage = task->stage;
    if (stage == 0) {
        return;
    }
    if (phase - 4 <= 1) {
        return;
    }
    task->updatesParticles = (u8)updatesParticles;
    task->variant = (u8)variant;
    if (stage <= WEATHER_STAGE_BEGIN) {
        task->stage = WEATHER_STAGE_END_FINISH;
        return;
    }
    if (task->updatesParticles != 0) {
        task->stage = WEATHER_STAGE_END_PARTICLES;
        return;
    }
    task->stage = WEATHER_STAGE_END_FINISH;
}


/* Ends the kind at once and releases everything it loaded. */
void func_021A20C8(WeatherTaskSys *task)
{
    if (task->stage == 0) {
        return;
    }
    if (task->stage <= WEATHER_STAGE_END_FINISH) {
        func_021A2724(task, task->kind->endFinish, 0);
    }
    if (task->stage <= WEATHER_STAGE_RELEASE) {
        func_021A2924(task);
        func_021A28A0(task);
        func_021A284C(task);
    }
    func_021A26D8(task);
}


/* Starts a light change that takes 60 frames. */
int func_021A2108(WeatherTaskSys *task, int arcId, int memberId)
{
    return func_021A0590(task->light, arcId, memberId, 60);
}


/* Sets a light in one frame. */
int func_021A2114(WeatherTaskSys *task, int arcId, u32 memberId)
{
    return func_021A0590(task->light, arcId, memberId, 1);
}


void func_021A2120(WeatherTaskSys *task, int phase)
{
    if (phase == 1)
        func_021A05D8(task->light);
}


void func_021A2130(WeatherTaskSys *task, u32 color, u32 frames, u32 returnFrames)
{
    func_021A0618(task->light, color, frames, returnFrames);
}


int func_021A213C(WeatherTaskSys *task)
{
    return func_021A065C(task->light);
}


int func_021A2148(WeatherTaskSys *task)
{
    return func_0218E188(task->camera);
}


void func_021A2154(WeatherTaskSys *task, u32 color, u32 frames)
{
    func_021A063C(task->light, color, frames);
}


void func_021A2160(WeatherTaskSys *task, unsigned int value, int layer)
{
    func_021A16D4(task->sys->billboards[layer], value);
}


void func_021A2170(WeatherTaskSys *task, unsigned int value, int layer)
{
    func_021A16E4(task->sys->billboards[layer], value);
}


void func_021A2180(WeatherTaskSys *task, unsigned int value, int layer)
{
    func_021A16E8(task->sys->billboards[layer], value);
}


void func_021A2190(WeatherTaskSys *task, unsigned int value, int layer)
{
    func_021A16DC(task->sys->billboards[layer], value);
}


void func_021A21A0(WeatherTaskSys *task, unsigned int value, int layer)
{
    func_021A16E0(task->sys->billboards[layer], value);
}


int func_021A21B0(WeatherTaskSys *task)
{
    return func_021A273C(task);
}


void *func_021A21B8(WeatherTaskSys *task)
{
    return task->workBuffer;
}


int func_021A21BC(WeatherTaskSys *task)
{
    return task->particleCount;
}


/* Takes a free particle slot and links it into the ring. */
WeatherParticle *func_021A21C8(WeatherTaskSys *task, int reserved)
{
    WeatherParticle *particle = func_021A274C(task);

    if (particle != 0)
        func_021A277C(task, particle);
    return particle;
}


void func_021A21E0(WeatherParticle *particle)
{
    if (func_021A2BC4(particle) != 0)
        func_021A27B8(particle->owner, particle);
}


void func_021A21F8(WeatherTaskSys *task, int count, int interval, int targetCount, int targetInterval, int intervalStep, int stepsPerCountChange, int countStep, WeatherSpawnFunc spawn)
{
    func_021A2A84(&task->spawner, task, interval, count, targetCount, targetInterval, intervalStep, stepsPerCountChange, countStep, spawn);
}


void func_021A2228(WeatherTaskSys *task, int targetCount, int targetInterval, int intervalStep, int countStep)
{
    func_021A2AAC(&task->spawner, targetCount, targetInterval, intervalStep, countStep);
}


int func_021A223C(WeatherTaskSys *task, int arg)
{
    return func_021A2AB8(&task->spawner, arg);
}


int func_021A2248(WeatherTaskSys *task, int arg)
{
    return func_021A2B8C(&task->spawner, arg);
}


/* Spawns the particles of a kind and runs them ahead so the screen starts filled. */
void func_021A2254(WeatherTaskSys *task, WeatherSpawnFunc spawn, int iterations, int growEvery, int growBy, u16 heapId)
{
    int j;
    WeatherParticle *cur;
    int steps;
    int i;
    WeatherParticle *next;

    spawn(task, iterations, heapId);
    steps = 0;
    cur = task->particleHead;
    if (cur == 0) {
        return;
    }
    next = cur->next;
    i = 0;
    if (iterations <= 0) {
        return;
    }
    do {
        j = 0;
        if (steps > 0) {
            do {
                task->kind->updateParticle(cur);
                if (func_021A2BC4(cur) == 0) {
                    break;
                }
                j++;
            } while (j < steps);
        }
        cur = next;
        next = cur->next;
        if (i >= growEvery) {
            if (i % growEvery == 0) {
                steps += growBy;
            }
        }
        if (cur == task->particleHead) {
            break;
        }
        i++;
    } while (i < iterations);
}


void func_021A22E0(WeatherTaskSys *task, int slope, int offset, int phase)
{
    if (phase == 1) {
        func_021A01AC(task->fog, 0);
        func_021A01CC(task->fog, 0x1F);
        func_021A01B4(task->fog, slope);
        func_021A01BC(task->fog, offset);
        func_021A01D8(task->fog);
        func_021A01A4(task->fog, 1);
    }
}


void func_021A231C(WeatherTaskSys *task, int phase)
{
    if (phase == 1)
        func_021A01A4(task->fog, 0);
}


/* Changes the fog. Mode 2 first fades the fog out and queues the change for the end of that fade. */
void func_021A232C(WeatherTaskSys *task, u8 slope, int offset, int frames, int mode)
{
    int half;

    if (mode == 1) {
        func_021A01FC(task->fog, offset, slope, frames);
        return;
    }
    if (mode == 2) {
        if (slope == func_021A01D4(task->fog)) {
            func_021A01FC(task->fog, offset, slope, frames);
            return;
        }
        half = frames / 2;
        func_021A01FC(task->fog, 0x7FDF, func_021A01D4(task->fog), half);
        func_021A2CC8(task, slope, offset, half);
    }
}


void func_021A2390(WeatherTaskSys *task, int endOffset, int frames, int mode)
{
    if (mode == 1)
        func_021A01FC(task->fog, endOffset, func_021A01D4(task->fog), frames);
}


/* 1 when the fog is not changing and no change is queued. */
int func_021A23B0(WeatherTaskSys *task)
{
    if (func_021A0244(task->fog) != 0) {
        return 0;
    }
    if (func_021A2CF8(task) == 0) {
        return 1;
    }
    return 0;
}


int func_021A23D4(WeatherTaskSys *task)
{
    if (func_021A0354(task->zoneFog) == 1) {
        return 1;
    }
    return 0;
}


int func_021A23E8(WeatherTaskSys *task)
{
    return func_021A0380(task->zoneFog);
}


int func_021A23F4(WeatherTaskSys *task)
{
    return func_021A0390(task->zoneFog);
}


int func_021A2400(WeatherTaskSys *task)
{
    return func_021A03A4(task->zoneFog);
}


int func_021A240C(WeatherTaskSys *task)
{
    return func_021A03B8(task->zoneFog);
}


int func_021A2418(WeatherTaskSys *task)
{
    return func_021A03CC(task->zoneFog);
}


/* Remembers the camera position for the scroll computation. */
void func_021A2424(WeatherTaskSys *task)
{
    VecFx32 pos;

    if (task->camera != 0) {
        func_02048B30(func_0218EC2C(task->camera), &pos);
        task->lastCameraPos = pos;
    }
}


/*
 * Turns the camera movement since the last call into a scroll in whole
 * pixels. A jump beyond the limits is treated as a warp: no scroll.
 * func_0207C768 is FX_Div, func_0207CF3C VEC_Distance.
 */
void func_021A244C(WeatherTaskSys *task, s32 *outX, s32 *outY)
{
    VecFx32 pos;
    VecFx32 target;
    fx32 width;
    fx32 height;
    fx32 dx;
    fx32 dz;
    fx32 signX;
    fx32 signZ;
    void *camera;

    if (task->camera == 0) {
        *outX = 0;
        *outY = 0;
        return;
    }
    camera = func_0218EC2C(task->camera);
    func_02048B30(camera, &pos);
    func_02048AE8(camera, &target);
    dx = pos.x - task->lastCameraPos.x;
    dz = pos.z - task->lastCameraPos.z;
    if ((dx < 0 ? -dx : dx) > 0x3E8000 || (dz < 0 ? -dz : dz) > 0x64000) {
        task->lastCameraPos = pos;
        *outX = 0;
        *outY = 0;
        return;
    }
    func_021A2D30(&g_02148B54, func_0207CF3C(&pos, &target), &width, &height);
    width = func_0207C768(width, 0x100000);
    height = func_0207C768(height, 0xC0000);
    signX = 0x1000;
    if (dx < 0) {
        signX = -0x1000;
        dx = -dx;
    }
    dx = func_0207C768(dx, width);
    if (signX < 0) {
        dx = 0 - dx;
        dx += 0x1000;
    }
    signZ = 0x1000;
    if (dz < 0) {
        signZ = -0x1000;
        dz = -dz;
    }
    dz = func_0207C768(dz, height);
    if (signZ < 0) {
        dz = 0 - dz;
        dz += 0x1000;
    }
    if (dx + dz != 0) {
        task->lastCameraPos = pos;
    }
    *outX = dx >> 12;
    *outY = dz >> 12;
}


/* Moves every particle by (-dx, -dy) on screen. */
void func_021A2564(WeatherTaskSys *task, int dx, int dy)
{
    WeatherParticle *particle = task->particleHead;
    Actor *actor;
    int y;
    int x;
    WeatherScreenPos pos;

    if (particle != 0) {
        x = (short)dx;
        y = (short)dy;
        do {
            actor = func_021A2C28(particle);
            func_0204B53C(actor, &pos);
            pos.x = pos.x - x;
            pos.y = pos.y - y;
            func_0204B528(actor, &pos);
            particle = particle->next;
        } while (particle != task->particleHead);
    }
}


void func_021A25BC(WeatherTaskSys *task, u16 seId)
{
    func_021A2C30(&task->sound, task->soundSys, seId);
}


void func_021A25CC(WeatherTaskSys *task)
{
    func_021A2C6C(&task->sound, task->soundSys);
}


void func_021A25DC(WeatherTaskSys *task, int seId)
{
    if (func_02005C64() == 0) {
        if (task->sound.useSoundSys != 0)
            func_02028A7C(task->soundSys, seId);
        else
            func_020061E4(seId);
    }
}


void func_021A2604(WeatherTaskSys *task, int seId, int who)
{
    if (func_02005C64() == 0) {
        if (task->sound.useSoundSys != 0)
            func_02028ACC(task->soundSys, seId, who);
        else
            func_020061F0(seId, who);
    }
}


u8 *func_021A2630(WeatherParticle *particle)
{
    return func_021A2C24(particle);
}


Actor *func_021A2638(WeatherParticle *particle)
{
    return func_021A2C28(particle);
}


void func_021A2640(WeatherParticle *particle, WeatherScreenPos *out)
{
    func_0204B454(func_021A2C28(particle), out, 0);
}


/* Sets the particle position, wrapping it into the screen plus a margin. */
void func_021A2654(WeatherParticle *particle, u16 *src)
{
    s16 pos[2];

    pos[0] = src[0];
    pos[1] = src[1];
    if (pos[0] > 320) {
        pos[0] = pos[0] % 320;
    } else if (pos[0] < -64) {
        pos[0] = pos[0] + 320;
    }
    if (pos[1] > 256) {
        s16 *posY;
        posY = &pos[1];
        *posY = *posY % 256;
    } else if (pos[1] < -64) {
        pos[1] = pos[1] + 256;
    }
    func_0204B404(func_021A2C28(particle), (const WeatherScreenPos *)pos, 0);
}


int func_021A26C4(WeatherParticle *particle, const WeatherScreenPos *pos)
{
    return func_0204B404(func_021A2C28(particle), pos, 0);
}


/* Clears the task but keeps the objects it was created with. */
void func_021A26D8(WeatherTaskSys *task)
{
    void *textureBank;
    FieldFog *fog;
    FieldZoneFog *zoneFog;
    FieldLight *light;
    WeatherSys *sys;
    FieldCamera *camera;
    FieldSoundSystem *soundSys;
    unsigned short zoneId;

    textureBank = task->textureBank;
    fog = task->fog;
    camera = task->camera;
    zoneFog = task->zoneFog;
    soundSys = task->soundSys;
    light = task->light;
    zoneId = task->zoneId;
    sys = task->sys;
    func_02082BCC(task, 0, sizeof(WeatherTaskSys));
    task->camera = camera;
    task->textureBank = textureBank;
    task->soundSys = soundSys;
    task->fog = fog;
    task->zoneId = zoneId;
    task->light = light;
    task->sys = sys;
    task->zoneFog = zoneFog;
}


/* Calls a stage function of the kind; a kind without one is done at once. */
int func_021A2724(WeatherTaskSys *task, WeatherKindStageFunc stageFunc, int heapId)
{
    if (stageFunc != 0)
        return stageFunc(task, task->variant, heapId);
    return 1;
}


u8 func_021A273C(WeatherTaskSys *task)
{
    return data_021D88E8[task->stage];
}


WeatherParticle *func_021A274C(WeatherTaskSys *task)
{
    int i;

    for (i = 0; i < WEATHER_PARTICLE_MAX; i++) {
        if (func_021A2BC4(&task->particles[i]) == 0) {
            /* stand-in: the original reuses the task pointer as the base of the particle array; the plain &task->particles[i] changes the register use */
            task = (WeatherTaskSys *)task->particles;
            return (WeatherParticle *)task + i;
        }
    }
    return 0;
}


void func_021A277C(WeatherTaskSys *task, WeatherParticle *particle)
{
    WeatherParticle *tail;

    task->particleCount++;
    if (task->particleHead == 0) {
        task->particleHead = particle;
        particle->next = particle;
        task->particleHead->prev = particle;
        return;
    }
    tail = task->particleHead->prev;
    particle->prev = tail;
    particle->next = tail->next;
    tail->next->prev = particle;
    tail->next = particle;
    func_0204B3DC(particle->actor, 1);
}


void func_021A27B8(WeatherTaskSys *task, WeatherParticle *particle)
{
    task->particleCount--;
    if (task->particleHead == particle) {
        if (particle->next == particle)
            task->particleHead = 0;
        else
            task->particleHead = particle->next;
    }
    particle->next->prev = particle->prev;
    particle->prev->next = particle->next;
    particle->next = 0;
    particle->prev = 0;
    func_0204B3DC(particle->actor, 0);
}


void func_021A27F8(WeatherTaskSys *task)
{
    WeatherParticle *cur = task->particleHead;
    WeatherParticle *next;

    if (cur != 0 && task->kind->updateParticle != 0) {
        next = cur->next;
        do {
            task->kind->updateParticle(cur);
            cur = next;
            next = next->next;
        } while (cur != task->particleHead && task->particleHead != 0);
    }
}


void func_021A282C(WeatherTaskSys *task, int heapId)
{
    func_021A2978(&task->resources, task->kind, heapId);
    func_021A29A8(&task->resources, task->kind, heapId);
}


void func_021A284C(WeatherTaskSys *task)
{
    func_021A29F4(&task->resources);
    func_021A2994(&task->resources);
}


void func_021A2860(WeatherTaskSys *task, u16 heapId)
{
    int i;

    for (i = 0; i < task->kind->billboardCount; i++) {
        func_021A2A18(&task->resources, i, task->sys->billboards[i], &task->kind->billboards[i], heapId);
    }
}


void func_021A28A0(WeatherTaskSys *task)
{
    int i;

    for (i = 0; i < task->kind->billboardCount; i++)
        func_021A2A68(&task->resources, i, task->sys->billboards[i]);
}


/* Allocates the work buffer of the kind and one actor per particle slot. */
void func_021A28CC(WeatherTaskSys *task, u16 heapId)
{
    int i;

    task->workBuffer = func_02030734(heapId, task->kind->workBufferSize, 1, (const char *)&d_021DDE80, 0x874);
    if (task->kind->hasSprites != 0) {
        for (i = 0; i < WEATHER_PARTICLE_MAX; i++) {
            func_021A2BD4(&task->particles[i], task, &task->resources, task->textureBank, heapId);
        }
    }
}


void func_021A2924(WeatherTaskSys *task)
{
    int i;

    if (task->workBuffer != 0) {
        func_020307B0(task->workBuffer);
        task->workBuffer = 0;
    }
    if (task->kind->hasSprites != 0) {
        for (i = 0; i < WEATHER_PARTICLE_MAX; i++) {
            func_021A2C10(&task->particles[i]);
            func_021A2BB8(&task->particles[i]);
        }
    }
    func_021A25CC(task);
}


void func_021A2968(WeatherTaskSys *task)
{
    task->started = 1;
}


u8 func_021A2970(WeatherTaskSys *task)
{
    return task->started;
}


void func_021A2978(WeatherResourceSet *resources, const WeatherKindDef *kind, u32 heapId)
{
    if (kind->hasSprites != 0 || kind->billboardCount != 0)
        resources->archive = func_020490F4(kind->archiveId, heapId);
}


void func_021A2994(WeatherResourceSet *resources)
{
    void *archive = resources->archive;
    if (archive != 0) {
        func_02049238(archive);
        resources->archive = 0;
    }
}


void func_021A29A8(WeatherResourceSet *resources, const WeatherKindDef *kind, int heapId)
{
    if (kind->hasSprites != 0) {
        resources->charResId = func_0204A6C8(resources->archive, kind->charArg, 0, 0, heapId);
        resources->paletteResId = func_0204AC18(resources->archive, kind->paletteArg, 0, 0, 0, 1, heapId);
        resources->cellResId = func_0204AF28(resources->archive, kind->cellArg, kind->cellAnimArg, heapId);
        resources->loaded = 1;
    }
}


void func_021A29F4(WeatherResourceSet *resources)
{
    if (resources->loaded != 0) {
        func_0204A8D4(resources->charResId);
        func_0204ADA4(resources->paletteResId);
        func_0204AFD8(resources->cellResId);
        resources->loaded = 0;
    }
}


/*
 * Note: the original loads the pool word for 0x021EE710 twice (once for the
 * memcpy dst and the 3rd argument, once for the byte-8 test); the second
 * name is an alias at the same address that stops the compiler CSEing them.
 */
void func_021A2A18(WeatherResourceSet *resources, int index, Field3dbgBillboard *billboard, const WeatherBillboardInit *init, unsigned short heapId)
{
    func_02082D44(init, d_021EE710, 12);
    if (d_021EE710b[8] != 0x1f) {
        d_021EE710b[8] = 0x1f;
    }
    func_021A1698(billboard, resources->archive, d_021EE710, heapId);
    func_021A16D4(billboard, 0);
    func_021A16D8(billboard, 0x20);
    resources->billboardReady[index] = 1;
}


void func_021A2A68(WeatherResourceSet *resources, int index, Field3dbgBillboard *billboard)
{
    if (resources->billboardReady[index] != 0) {
        func_021A1680(billboard);
        resources->billboardReady[index] = 0;
    }
}


WeatherSpawner *func_021A2A84(WeatherSpawner *spawner, WeatherTaskSys *owner, u32 interval, u32 count, u32 targetCount, u32 targetInterval, u32 intervalStep, u32 stepsPerCountChange, u32 countStep, WeatherSpawnFunc spawn)
{
    spawner->owner = owner;
    spawner->timer = 0;
    spawner->stepCounter = 0;
    spawner->count = count;
    spawner->targetCount = targetCount;
    spawner->interval = interval;
    spawner->targetInterval = targetInterval;
    spawner->intervalStep = intervalStep;
    spawner->stepsPerCountChange = stepsPerCountChange;
    spawner->countStep = countStep;
    spawner->spawn = spawn;
    return spawner;
}


void func_021A2AAC(WeatherSpawner *spawner, int targetCount, int targetInterval, int intervalStep, int countStep)
{
    spawner->targetCount = targetCount;
    spawner->targetInterval = targetInterval;
    spawner->intervalStep = intervalStep;
    spawner->countStep = countStep;
}


/* One tick of the spawner. Returns 1 when the interval has reached its target. */
s32 func_021A2AB8(WeatherSpawner *spawner, u32 arg)
{
    u32 reached;
    s32 negative;

    reached = 0;
    if (spawner->intervalStep == 0) {
        reached |= 1;
    } else {
        negative = spawner->intervalStep > 0 ? 0 : 1;
        if ((spawner->interval >= spawner->targetInterval && negative == 0) || (spawner->interval <= spawner->targetInterval && negative == 1)) {
            reached |= 1;
            spawner->interval = spawner->targetInterval;
        }
    }
    if (spawner->countStep == 0) {
        reached |= 2;
    } else {
        negative = spawner->countStep > 0 ? 0 : 1;
        if ((spawner->count >= spawner->targetCount && negative == 0) || (spawner->count <= spawner->targetCount && negative == 1)) {
            reached |= 2;
            spawner->count = spawner->targetCount;
        }
    }
    spawner->timer--;
    if (spawner->timer <= 0) {
        spawner->spawn(spawner->owner, spawner->count, arg);
        spawner->timer = spawner->interval;
        if (!(reached & 1)) {
            spawner->interval += spawner->intervalStep;
        }
        if (!(reached & 2)) {
            spawner->stepCounter++;
            if (spawner->stepCounter >= spawner->stepsPerCountChange) {
                spawner->stepCounter = 0;
                spawner->count += (s16)spawner->countStep;
            }
        }
    }
    return (reached & 1) ? 1 : 0;
}


/* One tick of the plain timer use of the spawner. Returns 1 when it fired. */
int func_021A2B8C(WeatherSpawner *spawner, int arg)
{
    spawner->timer--;
    if (spawner->timer <= 0) {
        spawner->spawn(spawner->owner, spawner->count, arg);
        spawner->timer = spawner->interval;
        return 1;
    }
    return 0;
}


void func_021A2BB8(WeatherParticle *particle)
{
    func_02082BCC(particle, 0, sizeof(WeatherParticle));
}


/* A particle is in use while it is linked into the ring. */
int func_021A2BC4(WeatherParticle *particle)
{
    if (particle->prev != 0) {
        return 1;
    }
    return 0;
}


void func_021A2BD4(WeatherParticle *particle, WeatherTaskSys *owner, const WeatherResourceSet *resources, void *textureBank, u16 heapId)
{
    particle->owner = owner;
    particle->actor = func_0204B294(textureBank, resources->charResId, resources->paletteResId, resources->cellResId, data_021D88E0, 0, heapId);
    func_0204B3DC(particle->actor, 0);
    func_0204BA20(particle->actor, 0);
}


void func_021A2C10(WeatherParticle *particle)
{
    Actor *actor = particle->actor;
    if (actor != 0) {
        func_0204B3B4(actor);
        particle->actor = 0;
    }
}


u8 *func_021A2C24(WeatherParticle *particle)
{
    return particle->kindWork;
}


Actor *func_021A2C28(WeatherParticle *particle)
{
    return particle->actor;
}


void func_021A2C2C(WeatherSoundState *sound, u32 useSoundSys)
{
    sound->useSoundSys = useSoundSys;
}


void func_021A2C30(WeatherSoundState *sound, FieldSoundSystem *soundSys, u16 seId)
{
    func_021A2C6C(sound, soundSys);
    if (func_02005C64() == 0) {
        sound->state = 1;
        sound->seId = seId;
        if (sound->useSoundSys != 0)
            func_02028A7C(soundSys, sound->seId);
        else
            func_020061E4(sound->seId);
    } else {
        sound->state = 2;
        sound->seId = seId;
    }
}


void func_021A2C6C(WeatherSoundState *sound, FieldSoundSystem *soundSys)
{
    if (sound->state == 1) {
        sound->state = 0;
        if (sound->useSoundSys != 0)
            func_02028B50(soundSys, sound->seId);
        else
            func_020061F8(func_02006148(sound->seId));
    }
}


/* Starts a sound that was waiting for the sound system to be free. */
void func_021A2C98(WeatherSoundState *sound, FieldSoundSystem *soundSys)
{
    if (sound->state == 2 && func_02005C64() == 0) {
        sound->state = 1;
        if (sound->useSoundSys != 0)
            func_02028A7C(soundSys, sound->seId);
        else
            func_020061E4(sound->seId);
    }
}


/* Queues a fog change that starts once the current fog change is over. */
void func_021A2CC8(WeatherTaskSys *task, u8 slope, u32 offset, int firstStepFrames)
{
    task->fogChangePending = 1;
    task->fogSlope = slope;
    task->fogOffset = offset;
    task->fogFrames = firstStepFrames / 2;
}


void func_021A2CEC(WeatherTaskSys *task)
{
    task->fogChangePending = 0;
}


u8 func_021A2CF8(WeatherTaskSys *task)
{
    return task->fogChangePending;
}


void func_021A2D04(WeatherTaskSys *task)
{
    func_021A0224(task->fog, 0x7FDF, task->fogOffset, task->fogSlope, task->fogSlope, task->fogFrames);
}


void func_021A2D30(WeatherViewScale *scale, int distance, int *outWidth, int *outHeight)
{
    *outHeight = (int)(((long long)(int)func_0207C768(distance, scale->heightRef) * 0x2000 + 0x800) >> 12);
    *outWidth = (int)(((long long)(int)func_0207C768(distance, scale->widthRef) * 0x2000 + 0x800) >> 12);
}
