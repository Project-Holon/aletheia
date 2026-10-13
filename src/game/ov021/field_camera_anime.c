/*
 * file:     field_camera_anime.c
 * unit:     yes
 * function: func_0218FE78, func_0218FE80, func_0218FE98, func_0218FEA0, func_0218FEA4, func_0218FEC0, func_0218FF00, func_0218FF20, func_0218FF30, func_0218FF48, func_0218FF50, func_0218FF78, func_0218FFE8, func_02190000, func_02190058, func_021900A8, func_021900C4, func_02190110, func_0219014C, func_021901E4, func_021901E8
 * address:  0x0218FE78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_msgbg.c at 0x0218FE78: field_camera_anime.c __FILE__ anchor at 0x0218FF30; 0x0218FE78 forwards to the anime move code (cut position probable, 0x0218FE50 and 0x0218FE70 read the camera object).
 *
 * symbols:
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C84  0x02188C84  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0207CA00  0x0207CA00  arm
 *   d_021DDA38  0x021DDA38  data  ov021  a4
 *   func_02188C58  0x02188C58  thumb
 *   func_02188C5C  0x02188C5C  thumb  ov021
 *   func_021BB260  0x021BB260  thumb  ov021
 *   func_02189A18  0x02189A18  thumb  ov021
 *   func_021AB75C  0x021AB75C  thumb  ov021
 *   func_021C7058  0x021C7058  thumb  ov021
 *   func_021C701C  0x021C701C  thumb  ov021
 *   func_021C6F00  0x021C6F00  thumb  ov021
 *   func_021C7C10  0x021C7C10  thumb  ov021
 *   func_021C7AE4  0x021C7AE4  thumb  ov021
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_0218E138  0x0218E138  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218EC30  0x0218EC30  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ECC4  0x0218ECC4  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 *   func_0218ED34  0x0218ED34  thumb  ov021
 *   func_0218ED48  0x0218ED48  thumb  ov021
 *   func_0218ED58  0x0218ED58  thumb  ov021
 *   func_0218ED5C  0x0218ED5C  thumb  ov021
 *   func_0218F18C  0x0218F18C  thumb  ov021
 *   func_0218F19C  0x0218F19C  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218F1B4  0x0218F1B4  thumb  ov021
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            fx32;

#include "field_camera_types.h"


/* Camera anime work (0x20 bytes, heap tag 0xEE). */
typedef struct FieldCameraAnime {
    FieldMap *fieldMap;             /* 0x00 */
    FieldCamera *camera;            /* 0x04 */
    FieldCameraAnimeData *data;     /* 0x08 */
    u32 isSetUp;                    /* 0x0C */
    u32 savedMode;                  /* 0x10 */
    u32 savedTrace;                 /* 0x14 */
    const VecFx32 *savedTarget;     /* 0x18 */
    u32 targetDetached;             /* 0x1C */
} FieldCameraAnime;

/* field_camera.c */
u32 func_0218E138(FieldCamera *camera);
void func_0218E13C(FieldCamera *camera, u32 mode);
void func_0218EC30(FieldCamera *camera, const VecFx32 *target);
void func_0218EC54(FieldCamera *camera);
const VecFx32 *func_0218EC5C(FieldCamera *camera);
void func_0218EC90(FieldCamera *camera, const VecFx32 *target);
void func_0218ECC4(FieldCamera *camera, VecFx32 *out);
void func_0218ECD4(FieldCamera *camera, const VecFx32 *shift);
void func_0218ED34(FieldCamera *camera, u16 pitch);
void func_0218ED48(FieldCamera *camera, u32 yaw);
void func_0218ED58(FieldCamera *camera, u32 distance);
void func_0218ED5C(VecFx32 *vec, u16 *pitch, u16 *yaw, int *distance);
void func_0218F18C(FieldCamera *camera, VecFx32 *target);
void func_0218F19C(FieldCamera *camera, VecFx32 *pos);
void func_0218F1AC(FieldCamera *camera, u32 trace);
unsigned char func_0218F1B4(FieldCamera *camera);

void func_0218FE78(FieldCamera *camera, FieldCameraParam *param);
FieldCameraAnime *func_0218FE80(FieldMap *fieldMap);
void func_0218FE98(FieldCameraAnime *anime);
void func_0218FEA0(FieldCameraAnime *anime, FieldCameraAnimeData *data);
int func_0218FEA4(FieldCameraAnime *anime);
void func_0218FEC0(FieldCameraAnime *anime);
void func_0218FF00(FieldCameraAnime *anime);
void func_0218FF20(FieldCameraAnime *anime);
FieldCameraAnime *func_0218FF30(u16 heapId);
void func_0218FF48(FieldCameraAnime *anime);
void func_0218FF50(FieldCameraAnime *anime, FieldMap *fieldMap);
u32 func_0218FF78(FieldCameraAnime *anime);
void func_0218FFE8(FieldCameraAnime *anime);
void func_02190000(FieldCameraAnime *anime);
void func_02190058(FieldCamera *camera);
void func_021900A8(FieldCamera *camera);
void func_021900C4(FieldCamera *camera, FieldCameraParam *param);
void func_02190110(FieldCameraAnime *anime);
void func_0219014C(FieldCameraAnime *anime);
FieldCamera *func_021901E4(FieldCameraAnime *anime);
FieldCameraAnimeData *func_021901E8(FieldCameraAnime *anime);

extern u32 func_02188CFC(FieldMap *fieldMap);
extern void func_02082BCC(void *dst, int value, u32 size);
extern u16 func_02188C84(FieldMap *fieldMap);
extern void *func_02030734(u16 heapId, u32 size, u32 flag, const char *file, u32 line);
extern u32 func_020307B0(void *mem);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern FieldCamera *func_02188C58(FieldMap *fieldMap);
extern u32 func_02188C5C(FieldMap *fieldMap);
extern void func_021BB260(u32 obj, u32 enable);
extern u32 func_02189A18(FieldMap *fieldMap);
extern void func_021AB75C(u8 *player, u32 enable);
extern u32 func_021C7058(FieldMap *fieldMap, u32 frames, u32 pitch);
extern u32 func_021C701C(FieldMap *fieldMap, u32 frames, u32 yaw);
extern u32 func_021C6F00(FieldMap *fieldMap, u16 frames, fx32 distance);
extern u32 func_021C7C10(FieldMap *fieldMap, u16 frames, const VecFx32 *start, const VecFx32 *end);
extern u32 func_021C7AE4(FieldMap *fieldMap, u32 frames, const VecFx32 *shift);
extern u32 func_02188D38(FieldMap *fieldMap);
extern void func_021C6DE0(u8 *taskMan, u32 *task, u32 arg);
extern const char d_021DDA38[];

void func_0218FE78(FieldCamera *camera, FieldCameraParam *param)
{
    func_021900C4(camera, param);
}

FieldCameraAnime *func_0218FE80(FieldMap *fieldMap)
{
    FieldCameraAnime *anime = func_0218FF30(func_02188C84(fieldMap));
    func_0218FF50(anime, fieldMap);
    return anime;
}

void func_0218FE98(FieldCameraAnime *anime)
{
    func_0218FF48(anime);
}

void func_0218FEA0(FieldCameraAnime *anime, FieldCameraAnimeData *data)
{
    anime->data = data;
}

int func_0218FEA4(FieldCameraAnime *anime)
{
    func_0218FFE8(anime);
    func_02190058(anime->camera);
    func_021900A8(anime->camera);
    return func_0218FF78(anime);
}

void func_0218FEC0(FieldCameraAnime *anime)
{
    FieldCamera *camera = func_021901E4(anime);
    FieldCameraParam *start = &func_021901E8(anime)->start;
    func_0218ED34(camera, start->pitch);
    func_0218ED48(camera, start->yaw);
    func_0218ED58(camera, start->distance);
    func_0218EC90(camera, &start->target);
    func_0218ECD4(camera, &start->shift);
}

void func_0218FF00(FieldCameraAnime *anime)
{
    if (func_021901E8(anime)->frames == 0) {
        func_02190110(anime);
        return;
    }
    func_0219014C(anime);
}

void func_0218FF20(FieldCameraAnime *anime)
{
    if (anime->isSetUp != 0)
        func_02190000(anime);
}

FieldCameraAnime *func_0218FF30(u16 heapId)
{
    return func_02030734(heapId, sizeof(FieldCameraAnime), 0, d_021DDA38, 0xee);
}

void func_0218FF48(FieldCameraAnime *anime)
{
    func_020307B0(anime);
}

void func_0218FF50(FieldCameraAnime *anime, FieldMap *fieldMap)
{
    func_02082BCC(anime, 0, sizeof(FieldCameraAnime));
    anime->fieldMap = fieldMap;
    anime->camera = func_02188C58(fieldMap);
    anime->data = 0;
    anime->isSetUp = 0;
    anime->savedTrace = 0;
    anime->savedTarget = 0;
    anime->targetDetached = 0;
}

u32 func_0218FF78(FieldCameraAnime *anime)
{
    FieldMap *fieldMap = anime->fieldMap;
    FieldCamera *camera = anime->camera;
    FieldCameraAnimeData *data = func_021901E8(anime);
    if (func_02188CFC(fieldMap) == 1)
        func_021BB260(func_02188C5C(fieldMap), 0);
    if (data->detachTarget != 0) {
        if (func_0218EC5C(anime->camera) != 0) {
            anime->targetDetached = 1;
            anime->savedTarget = func_0218EC5C(camera);
            func_0218EC54(camera);
        }
    }
    if (data->stopTrace != 0) {
        anime->savedTrace = func_0218F1B4(camera);
        func_0218F1AC(camera, 0);
    }
    func_021AB75C((u8 *)func_02189A18(fieldMap), 0);
    anime->isSetUp = 1;
    return anime->isSetUp;
}

void func_0218FFE8(FieldCameraAnime *anime)
{
    FieldCamera *camera = anime->camera;
    anime->savedMode = func_0218E138(camera);
    func_0218E13C(camera, 0);
}

void func_02190000(FieldCameraAnime *anime)
{
    FieldMap *fieldMap = anime->fieldMap;
    FieldCamera *camera = anime->camera;
    FieldCameraAnimeData *data = func_021901E8(anime);
    func_021AB75C((u8 *)func_02189A18(fieldMap), 1);
    if (data->stopTrace != 0)
        func_0218F1AC(camera, anime->savedTrace);
    if (anime->targetDetached != 0)
        func_0218EC30(camera, anime->savedTarget);
    func_0218E13C(camera, anime->savedMode);
    if (func_02188CFC(fieldMap) == 1)
        func_021BB260(func_02188C5C(fieldMap), 1);
}

void func_02190058(FieldCamera *camera)
{
    VecFx32 target, pos, dir;
    fx32 distance;
    u16 pitch, yaw;
    func_0218F19C(camera, &pos);
    func_0218F18C(camera, &target);
    func_0207CA00(&pos, &target, &dir);
    func_0218ED5C(&dir, &pitch, &yaw, &distance);
    func_0218ED58(camera, distance);
    func_0218ED34(camera, pitch);
    func_0218ED48(camera, yaw);
}

void func_021900A8(FieldCamera *camera)
{
    VecFx32 target;
    func_0218F18C(camera, &target);
    func_0218EC90(camera, &target);
}

void func_021900C4(FieldCamera *camera, FieldCameraParam *param)
{
    VecFx32 target;
    VecFx32 pos;
    VecFx32 dir;
    func_0218F19C(camera, &pos);
    func_0218F18C(camera, &target);
    func_0207CA00(&pos, &target, &dir);
    func_0218ED5C(&dir, &param->pitch, &param->yaw, &param->distance);
    func_0218F18C(camera, &param->target);
    func_0218ECC4(camera, &param->shift);
}

void func_02190110(FieldCameraAnime *anime)
{
    FieldCamera *camera = anime->camera;
    FieldCameraParam *end = &func_021901E8(anime)->end;
    func_0218ED34(camera, end->pitch);
    func_0218ED48(camera, end->yaw);
    func_0218ED58(camera, end->distance);
    func_0218EC90(camera, &end->target);
    func_0218ECD4(camera, &end->shift);
}

void func_0219014C(FieldCameraAnime *anime)
{
    FieldMap *fieldMap = anime->fieldMap;
    FieldCameraAnimeData *data = func_021901E8(anime);
    u32 frames = data->frames;
    FieldCameraParam *end = &data->end;
    u32 pitchTask;
    u32 yawTask;
    u32 distanceTask;
    u32 targetTask;
    u32 shiftTask;
    pitchTask = func_021C7058(fieldMap, frames, end->pitch);
    yawTask = func_021C701C(fieldMap, frames, end->yaw);
    distanceTask = func_021C6F00(fieldMap, frames, end->distance);
    targetTask = func_021C7C10(fieldMap, frames, &data->start.target, &end->target);
    shiftTask = func_021C7AE4(fieldMap, frames, &end->shift);
    /* the original reuses the field map variable for the task manager */
    fieldMap = (FieldMap *)func_02188D38(fieldMap);
    func_021C6DE0((u8 *)fieldMap, (u32 *)pitchTask, 0);
    func_021C6DE0((u8 *)fieldMap, (u32 *)yawTask, 0);
    func_021C6DE0((u8 *)fieldMap, (u32 *)distanceTask, 0);
    func_021C6DE0((u8 *)fieldMap, (u32 *)targetTask, 0);
    func_021C6DE0((u8 *)fieldMap, (u32 *)shiftTask, 0);
}

FieldCamera *func_021901E4(FieldCameraAnime *anime)
{
    return anime->camera;
}

FieldCameraAnimeData *func_021901E8(FieldCameraAnime *anime)
{
    return anime->data;
}
