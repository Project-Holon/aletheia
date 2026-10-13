/*
 * file:     field_camera.c
 * unit:     yes
 * function: func_0218E018, func_0218E0E4, func_0218E104, func_0218E124, func_0218E138, func_0218E13C, func_0218E160, func_0218E17C, func_0218E188, func_0218E18C, func_0218E260, func_0218E284, func_0218E298, func_0218E2B4, func_0218E358, func_0218E404, func_0218E4B0, func_0218E540, func_0218E58C, func_0218E5A0, func_0218E5B8, func_0218E5D0, func_0218E5EC, func_0218E5F4, func_0218E5FC, func_0218E610, func_0218E674, func_0218E6A4, func_0218E6F0, func_0218E73C, func_0218E764, func_0218E7DC, func_0218EC2C, func_0218EC30, func_0218EC54, func_0218EC5C, func_0218EC60, func_0218EC68, func_0218EC7C, func_0218EC90, func_0218ECB4, func_0218ECC4, func_0218ECD4, func_0218ECE4, func_0218ECF4, func_0218ED04, func_0218ED14, func_0218ED20, func_0218ED2C, func_0218ED34, func_0218ED3C, func_0218ED40, func_0218ED48, func_0218ED50, func_0218ED54, func_0218ED58, func_0218ED5C, func_0218ED64, func_0218ED9C, func_0218EEFC, func_0218EFD4, func_0218F004, func_0218F050, func_0218F05C, func_0218F0A8, func_0218F0D4, func_0218F0E8, func_0218F0F8, func_0218F114, func_0218F134, func_0218F14C, func_0218F18C, func_0218F19C, func_0218F1AC, func_0218F1B4, func_0218F1BC, func_0218F1DC, func_0218F1FC, func_0218F310, func_0218F460, func_0218F780, func_0218F7D0, func_0218F818, func_0218F848, func_0218F878, func_0218F89C, func_0218F900, func_0218F918, func_0218F930, func_0218F9C4, func_0218FA40, func_0218FB1C, func_0218FC80, func_0218FD88, func_0218FDD4, func_0218FDF0, func_0218FE40, func_0218FE50, func_0218FE70
 * address:  0x0218E018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_msgbg.c at 0x0218E018: field_camera.c __FILE__ anchor; the functions before it are called only from field_g3d_mapper.c.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   d_020A1B38     0x020A1B38  data   a2
 *   d_021DDA28     0x021DDA28  data  ov021  a4
 *   func_02048B78  0x02048B78  arm
 *   func_02048B88  0x02048B88  arm
 *   func_0207D184  0x0207D184  arm
 *   d_021DDA0C  0x021DDA0C  data  ov021  a4
 *   d_021DDA00  0x021DDA00  data  ov021  a4
 *   func_02046BE0  0x02046BE0  arm
 *   func_02048B80  0x02048B80  arm
 *   func_02048B94  0x02048B94  arm
 *   tbl_020A1B38   0x020A1B38  data
 *   func_020493D4  0x020493D4  arm
 *   func_0204944C  0x0204944C  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CEE4  0x0207CEE4  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048AFC  0x02048AFC  arm
 *   d_021D3E44  0x021D3E44  data  ov021  a4
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CA68  0x0207CA68  arm
 *   d_021D3E2C     0x021D3E2C  data   ov021  a4
 *   func_02048B20  0x02048B20  arm
 *   func_02048B0C  0x02048B0C  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_02048B30  0x02048B30  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02082D44   0x02082D44  arm
 *   func_0204A380  0x0204A380  arm
 *   d_021DDA18  0x021DDA18  data  ov021  a4
 *   VEC_Subtract     0x0207CA00  arm
 *   VEC_Mag          0x0207CBD0  arm
 *   FX_Modf          0x0207D14C  arm
 *   VEC_Normalize    0x0207CCA4  arm
 *   VEC_CrossProduct 0x0207CAE8  arm
 *   VEC_DotProduct   0x0207CA68  arm
 *   FX_AcosIdx       0x0207D184  arm
 *   d_021D3E38       0x021D3E38  data   a4
 */
#include "field_camera_types.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { s16 x, y, z; } VecS16;

typedef void (*FieldCameraEnterFunc)(FieldCamera *camera);

extern u32 func_02082BCC(void *, int, u32);
extern void *func_02030734(u16, u32, u32, const void *, u32);
extern u32 func_020307B0(void *);
extern void *func_020490F4(u32, u32);
extern void func_02049238(void *);
extern void func_0207C9D0(VecFx32 *, VecFx32 *, VecFx32 *);
extern int func_02048B78(struct G3dCamera *camera);
extern void func_02048B88(struct G3dCamera *camera, unsigned int *out);
extern u16 func_0207D184(int a);
extern void func_02046BE0(u32 a, u32 b);
extern void func_02048B80(struct G3dCamera *camera, u32 v);
extern void func_02048B94(struct G3dCamera *camera, u32 v);
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
extern void func_0204944C(struct ArcFile *, u32, u32, u32, void *);
extern void func_0207CCA4(VecFx32 *, VecFx32 *);
extern void func_0207CEE4(int scale, VecFx32 *dir, VecFx32 *base, VecFx32 *out);
extern void func_02048B44(struct G3dCamera *camera, const VecFx32 *in);
extern void func_02048AFC(struct G3dCamera *camera, const VecFx32 *in);
extern int func_0207CBD0(void *a);
extern int func_0207CFB8(int a, int b);
extern void func_0207CA00(VecFx32 *, VecFx32 *, VecFx32 *);
extern int func_0207CA68(VecFx32 *a, VecFx32 *b);
extern void func_02048B60(struct G3dCamera *camera, const u32 *in);
extern void func_02048B6C(struct G3dCamera *camera, const u32 *in);
extern void func_02048B20(struct G3dCamera *camera, const VecFx32 *in);
extern void func_02048B0C(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048B30(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048AE8(struct G3dCamera *camera, VecFx32 *out);
extern void func_02082D44(void *, void *, int);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern void VEC_Subtract(VecFx32 *a, VecFx32 *b, VecFx32 *o);
extern int VEC_Mag(VecFx32 *a);
extern int FX_Modf(int x, int *ip);
extern void VEC_Normalize(VecFx32 *a, VecFx32 *o);
extern void VEC_CrossProduct(VecFx32 *a, VecFx32 *b, VecFx32 *o);
extern int VEC_DotProduct(VecFx32 *a, VecFx32 *b);
extern u16 FX_AcosIdx(int x);
FieldCamera *func_0218E018(int settingId, int mode, struct G3dCamera *g3dCamera, VecFx32 *targetSrc, u16 heapId);
void func_0218E0E4(FieldCamera *camera);
void func_0218E104(FieldCamera *camera, u32 arg);
void func_0218E124(FieldCamera *camera, u32 mode);
u32 func_0218E138(FieldCamera *camera);
void func_0218E13C(FieldCamera *camera, u32 mode);
int func_0218E160(FieldCamera *camera);
void func_0218E17C(FieldCamera *camera, u32 settingId);
int func_0218E188(FieldCamera *camera);
void func_0218E18C(FieldCamera *camera, const VecFx32 *targetSrc);
void func_0218E260(FieldCamera *camera, FieldCameraSetting *out);
void func_0218E284(FieldCamera *camera);
int func_0218E298(FieldCamera *camera);
void func_0218E2B4(VecFx32 *base, VecFx32 *out, int yaw, int pitch, int distance);
void func_0218E358(FieldCamera *camera);
void func_0218E404(FieldCamera *camera);
void func_0218E4B0(FieldCamera *camera);
void func_0218E540(FieldCamera *camera);
void func_0218E58C(FieldCamera *camera, u32 arg);
void func_0218E5A0(FieldCamera *camera, u32 arg);
void func_0218E5B8(FieldCamera *camera, u32 arg);
void func_0218E5D0(FieldCamera *camera, u32 arg);
void func_0218E5EC(FieldCamera *camera);
void func_0218E5F4(FieldCamera *camera);
void func_0218E5FC(FieldCamera *camera);
void func_0218E610(VecFx32 *vec, u16 *pitch, u16 *yaw, int *distance);
void func_0218E674(FieldCamera *camera, VecFx32 *vec);
void func_0218E6A4(FieldCamera *camera);
void func_0218E6F0(FieldCamera *camera);
void func_0218E73C(FieldCamera *camera);
void func_0218E764(FieldCamera *camera, VecFx32 *targetPos, VecFx32 *eyePos);
void func_0218E7DC(VecFx32 *vec, u16 yaw, u16 pitch, u16 *outYaw, u16 *outPitch);
struct G3dCamera *func_0218EC2C(FieldCamera *camera);
void func_0218EC30(FieldCamera *camera, const VecFx32 *target);
void func_0218EC54(FieldCamera *camera);
const VecFx32 *func_0218EC5C(FieldCamera *camera);
void func_0218EC60(FieldCamera *camera);
void func_0218EC68(FieldCamera *camera, u32 scale, ...);
void func_0218EC7C(FieldCamera *camera, u32 roll, ...);
void func_0218EC90(FieldCamera *camera, const VecFx32 *target);
void func_0218ECB4(FieldCamera *camera, VecFx32 *out);
void func_0218ECC4(FieldCamera *camera, VecFx32 *out);
void func_0218ECD4(FieldCamera *camera, const VecFx32 *shift);
void func_0218ECE4(FieldCamera *camera, VecFx32 *out);
void func_0218ECF4(FieldCamera *camera, const VecFx32 *eye);
void func_0218ED04(FieldCamera *camera, const VecFx32 *shift);
void func_0218ED14(FieldCamera *camera, const VecFx32 *up);
void func_0218ED20(FieldCamera *camera, VecFx32 *out);
u16 func_0218ED2C(FieldCamera *camera);
void func_0218ED34(FieldCamera *camera, u16 pitch);
u16 *func_0218ED3C(FieldCamera *camera);
u16 func_0218ED40(FieldCamera *camera);
void func_0218ED48(FieldCamera *camera, u32 yaw);
u16 *func_0218ED50(FieldCamera *camera);
u32 func_0218ED54(FieldCamera *camera);
void func_0218ED58(FieldCamera *camera, u32 distance);
void func_0218ED5C(VecFx32 *vec, u16 *pitch, u16 *yaw, int *distance);
void func_0218ED64(FieldCamera *camera, u16 fov);
void func_0218ED9C(FieldCameraDelay *delay, VecFx32 *target, VecFx32 *eye, VecFx32 *outTarget, VecFx32 *outEye);
void func_0218EEFC(int count, u32 delayFrames, u32 flags, u32 heapId, FieldCamera *camera);
void func_0218EFD4(FieldCamera *camera);
void func_0218F004(FieldCamera *camera);
void func_0218F050(FieldCameraDelay *delay);
void func_0218F05C(FieldCamera *camera);
void func_0218F0A8(FieldCamera *camera);
void func_0218F0D4(FieldCamera *camera, int unused);
u32 func_0218F0E8(FieldCamera *camera);
int func_0218F0F8(FieldCamera *camera);
void func_0218F114(FieldCamera *camera, FieldCameraAreaSet *set);
void func_0218F134(FieldCamera *camera);
void func_0218F14C(FieldCamera *camera, u32 areaId, u32 heapId);
void func_0218F18C(FieldCamera *camera, VecFx32 *out);
void func_0218F19C(FieldCamera *camera, VecFx32 *out);
void func_0218F1AC(FieldCamera *camera, u32 enabled);
unsigned char func_0218F1B4(FieldCamera *camera);
void func_0218F1BC(FieldCameraArea *area, VecFx32 *point);
void func_0218F1DC(FieldCameraArea *area, VecFx32 *point);
int func_0218F1FC(const FieldCameraArea *area, VecFx32 *in, VecFx32 *out);
int func_0218F310(const FieldCameraArea *area, VecFx32 *in, VecFx32 *out);
int func_0218F460(FieldCameraArea *area, VecFx32 *in, VecFx32 *out);
void func_0218F780(FieldCamera *camera, FieldCameraView *view);
void func_0218F7D0(FieldCamera *camera, FieldCameraView *view);
void func_0218F818(FieldCamera *camera);
void func_0218F848(FieldCamera *camera);
void func_0218F878(FieldCamera *camera);
void func_0218F89C(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames);
void func_0218F900(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames);
void func_0218F918(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames);
void func_0218F930(FieldCamera *camera, VecFx32 *eyeGoal, VecFx32 *targetGoal, FieldCameraMoveChannels *channels, u16 frames);
void func_0218F9C4(FieldCamera *camera, FieldCameraMoveChannels *channels, u16 frames);
void func_0218FA40(FieldCamera *camera, u16 frames);
void func_0218FB1C(FieldCamera *camera);
void func_0218FC80(FieldCamera *camera);
void func_0218FD88(VecFx32 *from, VecFx32 *to, u16 frames, u16 frame, VecFx32 *out);
int func_0218FDD4(int *from, int *to, int frames, int frame);
u16 func_0218FDF0(u16 *from, u16 *to, s32 frames, s32 frame);
void func_0218FE40(FieldCamera *camera);
int func_0218FE50(FieldCamera *camera);
FieldCameraView *func_0218FE70(FieldCamera *camera);
extern s16 d_020A1B38[];
extern const char d_021DDA28[];
extern FieldCameraEnterFunc d_021DDA0C[];
extern FieldCameraEnterFunc d_021DDA00[];
extern s16 tbl_020A1B38[];
extern FieldCameraUpdateFunc d_021D3E44[];
extern VecFx32 d_021D3E2C;
extern s16 FX_SinCosTable_[];
extern FieldCameraAreaFunc d_021DDA18[];
extern VecFx32 d_021D3E38;

/* Creates the camera work: loads setting 'settingId', binds it to targetSrc and sets up the delay log. */
FieldCamera *func_0218E018(int settingId, int mode, struct G3dCamera *g3dCamera, VecFx32 *targetSrc, u16 heapId)
{
    int fovSin;
    FieldCamera *camera = func_02030734(heapId, 0x1b0, 1, d_021DDA28, 0x80);

    camera->settingId = settingId;
    camera->mode = mode;
    camera->g3dCamera = g3dCamera;
    camera->traceEye = 0;
    camera->heapId = heapId;
    camera->eyeRaw.x = 0;
    camera->eyeRaw.y = 0;
    camera->eyeRaw.z = 0;
    camera->targetRaw.x = 0;
    camera->targetRaw.y = 0;
    camera->targetRaw.z = 0;
    camera->lastSetTarget.x = 0;
    camera->lastSetTarget.y = 0;
    camera->lastSetTarget.z = 0;
    camera->eyeShift.x = 0;
    camera->eyeShift.y = 0;
    camera->eyeShift.z = 0;
    camera->yaw = 0;
    camera->pitch = 0;
    camera->distance = 0x78;
    camera->areasEnabled = 1;
    if (func_02048B78(g3dCamera) == 0) {
        func_02048B88(g3dCamera, (unsigned int *)(&fovSin));
        camera->fov = func_0207D184(fovSin);
    }
    camera->settingArc = func_020490F4(0x3c, camera->heapId);
    camera->areaArc = func_020490F4(0x6c, camera->heapId);
    camera->areaId = 0xffff;
    func_0218E18C(camera, targetSrc);
    func_0218EEFC(7, 6, 2, heapId, camera);
    camera->motion.callback = 0;
    return camera;
}

void func_0218E0E4(FieldCamera *camera)
{
    func_02049238(camera->settingArc);
    func_02049238(camera->areaArc);
    func_0218EFD4(camera);
    func_020307B0(camera);
}

/* Per frame: runs the move callback, then the update of the current mode. */
void func_0218E104(FieldCamera *camera, u32 arg)
{
    FieldCameraUpdateFunc callback = camera->motion.callback;
    if (callback != 0)
        callback(camera, camera->motion.callbackArg);
    func_0218E58C(camera, arg);
}

void func_0218E124(FieldCamera *camera, u32 mode)
{
    camera->mode = mode;
    d_021DDA0C[mode](camera);
}

u32 func_0218E138(FieldCamera *camera)
{
    return camera->mode;
}

void func_0218E13C(FieldCamera *camera, u32 mode)
{
    if (camera->mode != mode) {
        d_021DDA00[mode](camera);
        func_0218E124(camera, mode);
    }
}

/* Goes back to mode FIELD_CAMERA_MODE_TRACK_TARGET and reloads the current setting. */
int func_0218E160(FieldCamera *camera)
{
    func_0218E124(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
    func_0218E18C(camera, camera->boundTarget);
    camera->areasEnabled = 1;
    return 1;
}

/* Switches to another camera setting. */
void func_0218E17C(FieldCamera *camera, u32 settingId)
{
    camera->settingId = settingId;
    func_0218E160(camera);
}

int func_0218E188(FieldCamera *camera)
{
    return camera->settingId;
}

/* Loads the current setting record into the camera and the G3D camera. */
void func_0218E18C(FieldCamera *camera, const VecFx32 *targetSrc)
{
    FieldCameraSetting setting;

    func_0218E260(camera, &setting);
    camera->distance = setting.distance << 12;
    camera->pitch = setting.pitch;
    camera->yaw = setting.yaw;
    camera->fov = setting.fov;
    func_0218EC7C(camera, setting.g3dRoll);
    func_0218EC68(camera, setting.g3dScale);
    switch (setting.projection) {
    case 0:
        func_02046BE0(0, 0);
        break;
    case 1:
        func_02046BE0(0, 1);
        break;
    }
    if (func_02048B78(camera->g3dCamera) == 0) {
        func_02048B80(camera->g3dCamera, tbl_020A1B38[(camera->fov >> 4) * 2]);
        func_02048B94(camera->g3dCamera, tbl_020A1B38[(camera->fov >> 4) * 2 + 1]);
    }
    if (setting.hasTarget != 0) {
        camera->boundTarget = targetSrc;
        camera->traceTarget = targetSrc;
        camera->targetRaw = *targetSrc;
        camera->targetShift = setting.vec;
    } else {
        camera->boundTarget = 0;
        camera->traceTarget = 0;
        camera->targetRaw = setting.vec;
        camera->targetShift.x = 0;
        camera->targetShift.y = 0;
        camera->targetShift.z = 0;
    }
}

/* Reads the current setting record out of archive 0x3C. */
void func_0218E260(FieldCamera *camera, FieldCameraSetting *out)
{
    func_020493D4(camera->settingArc, 0);
    func_0204944C(camera->settingArc, 0, sizeof(FieldCameraSetting) * camera->settingId, sizeof(FieldCameraSetting), out);
}

/* Copies the traced target position into the raw target. */
void func_0218E284(FieldCamera *camera)
{
    const VecFx32 *src = camera->traceTarget;
    if (src != 0)
        camera->targetRaw = *src;
}

/* Copies the traced eye position into the raw eye; returns 1 when there is one. */
int func_0218E298(FieldCamera *camera)
{
    const VecFx32 *src = camera->traceEye;
    if (src != 0) {
        camera->eyeRaw = *src;
        return 1;
    }
    return 0;
}

/* Puts out = base + distance * unit(yaw, pitch direction). */
void func_0218E2B4(VecFx32 *base, VecFx32 *out, int yaw, int pitch, int distance)
{
    VecFx32 dir;
    int yawSin, yawCos;
    s16 pitchSin, pitchCos;
    int idx;

    idx = (yaw >> 4) * 2;
    yawSin = d_020A1B38[idx];
    yawCos = d_020A1B38[idx + 1];
    pitchSin = d_020A1B38[(pitch >> 4) * 2];
    pitchCos = d_020A1B38[(pitch >> 4) * 2 + 1];
    if (pitchCos < 0) pitchCos = -pitchCos;
    if (pitchCos < 0x200) pitchCos = 0x200;
    dir.x = (int)(((long long)yawSin * pitchCos + 0x800) >> 12);
    dir.y = pitchSin;
    dir.z = (int)(((long long)yawCos * pitchCos + 0x800) >> 12);
    func_0207CCA4(&dir, &dir);
    func_0207CEE4(distance, &dir, base, &dir);
    *out = dir;
}

/* Target mode solve: raw target -> target (areas) -> raw eye -> eye (areas). */
void func_0218E358(FieldCamera *camera)
{
    int i;

    camera->target = camera->targetRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            func_0218F1BC(&camera->areas[i], &camera->target);
        }
    }
    func_0218E2B4(&camera->target, &camera->eyeRaw, camera->yaw, camera->pitch, camera->distance);
    camera->eye = camera->eyeRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            func_0218F1DC(&camera->areas[i], &camera->eye);
        }
    }
}

/* Eye mode solve: mirror of the target mode solve. */
void func_0218E404(FieldCamera *camera)
{
    int i;

    camera->eye = camera->eyeRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            func_0218F1DC(&camera->areas[i], &camera->eye);
        }
    }
    func_0218E2B4(&camera->eye, &camera->targetRaw, camera->yaw, camera->pitch, camera->distance);
    camera->target = camera->targetRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            func_0218F1BC(&camera->areas[i], &camera->target);
        }
    }
}

/* Free mode solve: both raw points go through the areas unchanged. */
void func_0218E4B0(FieldCamera *camera)
{
    int i;

    camera->eye = camera->eyeRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            func_0218F1DC(&camera->areas[i], &camera->eye);
        }
    }
    camera->target = camera->targetRaw;
    if (camera->areasEnabled != 0) {
        for (i = 0; i < camera->areaCount; i++) {
            func_0218F1BC(&camera->areas[i], &camera->target);
        }
    }
}

/* Sends eye and target (plus their shifts) to the G3D camera and refreshes the view angles. */
void func_0218E540(FieldCamera *camera)
{
    VecFx32 targetWithShift;
    VecFx32 eyeWithShift;

    func_0207C9D0(&camera->target, &camera->targetShift, &targetWithShift);
    func_0207C9D0(&camera->eye, &camera->eyeShift, &eyeWithShift);
    func_02048B44(camera->g3dCamera, &targetWithShift);
    func_02048AFC(camera->g3dCamera, &eyeWithShift);
    func_0218F004(camera);
    func_0218E764(camera, &targetWithShift, &camera->eye);
}

void func_0218E58C(FieldCamera *camera, u32 arg)
{
    d_021D3E44[camera->mode](camera, arg);
}

void func_0218E5A0(FieldCamera *camera, u32 arg)
{
    func_0218E284(camera);
    func_0218E358(camera);
    func_0218E540(camera);
}

void func_0218E5B8(FieldCamera *camera, u32 arg)
{
    func_0218E298(camera);
    func_0218E404(camera);
    func_0218E540(camera);
}

void func_0218E5D0(FieldCamera *camera, u32 arg)
{
    func_0218E284(camera);
    func_0218E298(camera);
    func_0218E4B0(camera);
    func_0218E540(camera);
}

void func_0218E5EC(FieldCamera *camera)
{
    camera->traceEye = 0;
}

void func_0218E5F4(FieldCamera *camera)
{
    camera->traceTarget = 0;
}

void func_0218E5FC(FieldCamera *camera)
{
    camera->pitch = 0;
    camera->yaw = 0;
    camera->distance = 0;
}

/* Converts a vector to pitch and yaw angles plus its length. */
void func_0218E610(VecFx32 *vec, u16 *pitch, u16 *yaw, int *distance)
{
    VecFx32 unit;
    VecFx32 flat;
    u16 angles[2];
    int length;

    length = func_0207CBD0(vec);
    func_0207CCA4(vec, &unit);
    flat.x = unit.x;
    flat.y = 0;
    flat.z = unit.z;
    angles[1] = func_0207CFB8(unit.y, func_0207CBD0(&flat));
    angles[0] = func_0207CFB8(unit.x, unit.z);
    func_0218E7DC(&unit, angles[0], angles[1], angles, &angles[1]);
    *pitch = angles[1];
    *yaw = angles[0];
    *distance = length;
}

/* Takes pitch, yaw and distance from a vector. */
void func_0218E674(FieldCamera *camera, VecFx32 *vec)
{
    struct { u16 yaw, pitch; u32 distance; } result;

    func_0218E610(vec, &result.pitch, &result.yaw, (int *)(&result.distance));
    camera->pitch = result.pitch;
    camera->yaw = result.yaw;
    camera->distance = result.distance;
}

/* Prepares the switch to target mode: reverses the angles from eye mode, else derives them from eye - target. */
void func_0218E6A4(FieldCamera *camera)
{
    VecFx32 dir;

    if (camera->mode == FIELD_CAMERA_MODE_TRACK_EYE) {
        camera->yaw = camera->yaw + 0x8000;
        camera->pitch = camera->pitch + 0x8000;
    } else {
        func_0207CA00(&camera->eyeRaw, &camera->target, &dir);
        func_0218E674(camera, &dir);
    }
}

/* Prepares the switch to eye mode: reverses the angles from target mode, else derives them from target - eye. */
void func_0218E6F0(FieldCamera *camera)
{
    VecFx32 dir;

    if (camera->mode == FIELD_CAMERA_MODE_TRACK_TARGET) {
        camera->yaw = camera->yaw + 0x8000;
        camera->pitch = camera->pitch + 0x8000;
    } else {
        func_0207CA00(&camera->targetRaw, &camera->eye, &dir);
        func_0218E674(camera, &dir);
    }
}

/* Solves the current tracking mode (target or eye). */
void func_0218E73C(FieldCamera *camera)
{
    u32 mode = camera->mode;
    if (mode == FIELD_CAMERA_MODE_TRACK_TARGET) {
        func_0218E284(camera);
        func_0218E358(camera);
    } else if (mode == FIELD_CAMERA_MODE_TRACK_EYE) {
        func_0218E298(camera);
        func_0218E404(camera);
    }
}

/* Derives the view yaw and view pitch from the vector between eye and target. */
void func_0218E764(FieldCamera *camera, VecFx32 *targetPos, VecFx32 *eyePos)
{
    VecFx32 dir;
    VecFx32 up;
    VecFx32 flat;
    int upDot, flatDot;
    int pitch;

    func_0207CA00(eyePos, targetPos, &dir);
    func_0207CCA4(&dir, &dir);
    camera->viewYaw = func_0207CFB8(dir.x, dir.z);
    up = d_021D3E2C;
    upDot = func_0207CA68(&up, &dir);
    flat = dir;
    pitch = 0;
    flat.y = 0;
    func_0207CCA4(&flat, &flat);
    flatDot = func_0207CA68(&flat, &dir);
    if (flatDot != 0) {
        pitch = func_0207CFB8(upDot, flatDot);
    }
    camera->viewPitch = pitch;
}

static inline int FxMulRound(int a, int b)
{
    return (int)(((long long)a * b + 0x800) >> 12);
}

/*
 * Refines two 16-bit angles (yaw, pitch) toward a target vector: builds the unit
 * direction for the current angles and for yaw +/- one degree (0xb6), then nudges each
 * angle by a linear interpolation per quadrant. Writes the results to outYaw/outPitch.
 */
void func_0218E7DC(VecFx32 *vec, u16 yaw, u16 pitch, u16 *outYaw, u16 *outPitch)
{
    VecS16 cur = {0, 0, 0};
    VecS16 minus = {0, 0, 0};
    VecS16 plus = {0, 0, 0};
    int pitchCos;
    int pitchSinMinus, pitchSinPlus;
    int yawIdx, pitchIdx, yawIdxMinus, yawIdxPlus;
    *outYaw = yaw;
    *outPitch = pitch;
    yawIdx = (yaw >> 4) * 2;
    pitchIdx = (pitch >> 4) * 2;
    pitchCos = d_020A1B38[pitchIdx + 1];
    cur.x = FxMulRound(d_020A1B38[yawIdx], pitchCos);
    cur.y = d_020A1B38[pitchIdx];
    cur.z = FxMulRound(d_020A1B38[yawIdx + 1], pitchCos);
    yawIdxMinus = ((yaw - 0xb6) >> 4) * 2;
    minus.x = FxMulRound(d_020A1B38[yawIdxMinus], pitchCos);
    minus.z = FxMulRound(d_020A1B38[yawIdxMinus + 1], pitchCos);
    pitchSinMinus = d_020A1B38[((pitch - 0xb6) >> 4) * 2];
    yawIdxPlus = ((yaw + 0xb6) >> 4) * 2;
    plus.x = FxMulRound(d_020A1B38[yawIdxPlus], pitchCos);
    plus.z = FxMulRound(d_020A1B38[yawIdxPlus + 1], pitchCos);
    pitchSinPlus = d_020A1B38[((pitch + 0xb6) >> 4) * 2];
    if (yaw < 0x4000) {
        if (cur.x < vec->x && cur.z > vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw - (u16)(0xb6 * (vec->x - cur.x) / (minus.x - cur.x));
            } else {
                yaw = yaw - (u16)(0xb6 * (cur.z - vec->z) / (cur.z - minus.z));
            }
        } else if (cur.x > vec->x && cur.z < vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw + (u16)(0xb6 * (cur.x - vec->x) / (cur.x - plus.x));
            } else {
                yaw = yaw + (u16)(0xb6 * (vec->z - cur.z) / (plus.z - cur.z));
            }
        }
    } else if (yaw < 0x8000) {
        if (cur.x > vec->x && cur.z > vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw - (u16)(0xb6 * (cur.x - vec->x) / (cur.x - minus.x));
            } else {
                yaw = yaw - (u16)(0xb6 * (cur.z - vec->z) / (cur.z - minus.z));
            }
        } else if (cur.x < vec->x && cur.z < vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw + (u16)(0xb6 * (vec->x - cur.x) / (plus.x - cur.x));
            } else {
                yaw = yaw + (u16)(0xb6 * (vec->z - cur.z) / (plus.z - cur.z));
            }
        }
    } else if (yaw < 0xC000) {
        if (cur.x > vec->x && cur.z < vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw - (u16)(0xb6 * (cur.x - vec->x) / (cur.x - minus.x));
            } else {
                yaw = yaw - (u16)(0xb6 * (vec->z - cur.z) / (minus.z - cur.z));
            }
        } else if (cur.x < vec->x && cur.z > vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw + (u16)(0xb6 * (vec->x - cur.x) / (plus.x - cur.x));
            } else {
                yaw = yaw + (u16)(0xb6 * (cur.z - vec->z) / (cur.z - plus.z));
            }
        }
    } else {
        if (cur.x < vec->x && cur.z < vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw - (u16)(0xb6 * (vec->x - cur.x) / (minus.x - cur.x));
            } else {
                yaw = yaw - (u16)(0xb6 * (vec->z - cur.z) / (minus.z - cur.z));
            }
        } else if (cur.x > vec->x && cur.z > vec->z) {
            if (ABS(cur.x - vec->x) >= ABS(cur.z - vec->z)) {
                yaw = yaw + (u16)(0xb6 * (cur.x - vec->x) / (cur.x - plus.x));
            } else {
                yaw = yaw + (u16)(0xb6 * (cur.z - vec->z) / (cur.z - plus.z));
            }
        }
    }
    if (pitch < 0x4000) {
        if (cur.y > vec->y) {
            pitch = pitch - (u16)(0xb6 * (cur.y - vec->y) / (cur.y - pitchSinMinus));
        } else if (cur.y < vec->y) {
            pitch = pitch + (u16)(0xb6 * (vec->y - cur.y) / (pitchSinPlus - cur.y));
        }
    } else if (pitch >= 0xC000) {
        if (cur.y > vec->y) {
            pitch = pitch - (u16)(0xb6 * (cur.y - vec->y) / (cur.y - pitchSinMinus));
        } else if (cur.y < vec->y) {
            pitch = pitch + (u16)(0xb6 * (vec->y - cur.y) / (pitchSinPlus - cur.y));
        }
    }
    *outYaw = yaw;
    *outPitch = pitch;
}

struct G3dCamera *func_0218EC2C(FieldCamera *camera)
{
    return camera->g3dCamera;
}

/* Makes the camera follow a position: the target jumps there. */
void func_0218EC30(FieldCamera *camera, const VecFx32 *target)
{
    camera->traceTarget = target;
    camera->lastSetTarget = *target;
    camera->targetRaw = *target;
}

void func_0218EC54(FieldCamera *camera)
{
    camera->traceTarget = 0;
}

const VecFx32 *func_0218EC5C(FieldCamera *camera)
{
    return camera->traceTarget;
}

/* Follows the bound position again. */
void func_0218EC60(FieldCamera *camera)
{
    camera->traceTarget = camera->boundTarget;
}

void func_0218EC68(FieldCamera *camera, u32 scale, ...)
{
    func_02048B60(camera->g3dCamera, &scale);
}

void func_0218EC7C(FieldCamera *camera, u32 roll, ...)
{
    func_02048B6C(camera->g3dCamera, &roll);
}

void func_0218EC90(FieldCamera *camera, const VecFx32 *target)
{
    camera->targetRaw = *target;
    camera->lastSetTarget = *target;
}

void func_0218ECB4(FieldCamera *camera, VecFx32 *out)
{
    *out = camera->targetRaw;
}

void func_0218ECC4(FieldCamera *camera, VecFx32 *out)
{
    *out = camera->targetShift;
}

void func_0218ECD4(FieldCamera *camera, const VecFx32 *shift)
{
    camera->targetShift = *shift;
}

void func_0218ECE4(FieldCamera *camera, VecFx32 *out)
{
    *out = camera->eyeRaw;
}

void func_0218ECF4(FieldCamera *camera, const VecFx32 *eye)
{
    camera->eyeRaw = *eye;
}

void func_0218ED04(FieldCamera *camera, const VecFx32 *shift)
{
    camera->eyeShift = *shift;
}

void func_0218ED14(FieldCamera *camera, const VecFx32 *up)
{
    func_02048B20(camera->g3dCamera, up);
}

void func_0218ED20(FieldCamera *camera, VecFx32 *out)
{
    func_02048B0C(camera->g3dCamera, out);
}

u16 func_0218ED2C(FieldCamera *camera)
{
    return camera->pitch;
}

void func_0218ED34(FieldCamera *camera, u16 pitch)
{
    camera->pitch = pitch;
}

u16 *func_0218ED3C(FieldCamera *camera)
{
    return &camera->viewPitch;
}

u16 func_0218ED40(FieldCamera *camera)
{
    return camera->yaw;
}

void func_0218ED48(FieldCamera *camera, u32 yaw)
{
    camera->yaw = yaw;
}

u16 *func_0218ED50(FieldCamera *camera)
{
    return &camera->viewYaw;
}

u32 func_0218ED54(FieldCamera *camera)
{
    return camera->distance;
}

void func_0218ED58(FieldCamera *camera, u32 distance)
{
    camera->distance = distance;
}

void func_0218ED5C(VecFx32 *vec, u16 *pitch, u16 *yaw, int *distance)
{
    func_0218E610(vec, pitch, yaw, distance);
}

/* Sets the field of view angle and the matching sin and cos in the G3D camera. */
void func_0218ED64(FieldCamera *camera, u16 fov)
{
    camera->fov = fov;
    func_02048B80(camera->g3dCamera, FX_SinCosTable_[(camera->fov >> 4) * 2]);
    func_02048B94(camera->g3dCamera, FX_SinCosTable_[(camera->fov >> 4) * 2 + 1]);
}

/* Pushes a target and an eye into the delay log and reads the delayed pair back. */
void func_0218ED9C(FieldCameraDelay *delay, VecFx32 *target, VecFx32 *eye, VecFx32 *outTarget, VecFx32 *outEye)
{
    int readPos;
    int writePos;

    if (delay == 0) {
        *outTarget = *target;
        *outEye = *eye;
        return;
    }
    if (delay->enabled == 0) {
        *outTarget = *target;
        *outEye = *eye;
        return;
    }
    readPos = delay->readPos;
    writePos = delay->writePos;
    if (delay->draining == 0) {
        delay->targetLog[writePos] = *target;
        delay->eyeLog[writePos] = *eye;
        writePos = (writePos + 1) % delay->count;
    }
    if (delay->filled != 0) {
        *outTarget = delay->targetLog[readPos];
        *outEye = delay->eyeLog[readPos];
    } else {
        *outTarget = delay->targetLog[delay->delayFrames];
        *outEye = delay->eyeLog[delay->delayFrames];
        if (readPos == delay->delayFrames)
            delay->filled = 1;
    }
    if (delay->draining != 0) {
        if (readPos != writePos) {
            readPos = (readPos + 1) % delay->count;
            if (readPos == writePos)
                func_0218F050(delay);
        }
    } else {
        readPos = (readPos + 1) % delay->count;
    }
    delay->readPos = readPos;
    delay->writePos = writePos;
    if (delay->delayX == 0) {
        outTarget->x = target->x;
        outEye->x = eye->x;
    }
    if (delay->delayY == 0) {
        outTarget->y = target->y;
        outEye->y = eye->y;
    }
    if (delay->delayZ == 0) {
        outTarget->z = target->z;
        outEye->z = eye->z;
    }
}

/*
 * Creates the delay log (count entries per log) when the camera follows a
 * position. flags bit 0, 1, 2 delay the x, y, z component.
 */
void func_0218EEFC(int count, u32 delayFrames, u32 flags, u32 heapId, FieldCamera *camera)
{
    if (camera->traceTarget != 0) {
        int i = 0;
        FieldCameraDelay *delay = func_02030734(heapId, sizeof(FieldCameraDelay), 0, d_021DDA28, 0x6aa);
        delay->targetLog = func_02030734(heapId, count * sizeof(VecFx32), 0, d_021DDA28, 0x6ab);
        delay->eyeLog = func_02030734(heapId, count * sizeof(VecFx32), 0, d_021DDA28, 0x6ac);
        for (; i < count; i++) {
            VecFx32 *entry = &delay->targetLog[i];
            entry->x = 0;
            entry->y = 0;
            entry->z = 0;
            entry = &delay->eyeLog[i];
            entry->x = 0;
            entry->y = 0;
            entry->z = 0;
        }
        delay->count = count;
        delay->delayFrames = delayFrames;
        delay->filled = 0;
        delay->readPos = 0;
        delay->writePos = delayFrames;
        delay->delayX = 0;
        delay->delayY = 0;
        delay->delayZ = 0;
        if (flags & 1)
            delay->delayX = 1;
        if (flags & 2)
            delay->delayY = 1;
        if (flags & 4)
            delay->delayZ = 1;
        delay->enabled = 1;
        delay->draining = 0;
        camera->delay = delay;
    }
}

void func_0218EFD4(FieldCamera *camera)
{
    if (camera->delay != 0) {
        func_020307B0(camera->delay->targetLog);
        func_020307B0(camera->delay->eyeLog);
        func_020307B0(camera->delay);
        camera->delay = 0;
    }
}

/* Runs the G3D camera target and eye through the delay log. */
void func_0218F004(FieldCamera *camera)
{
    if (camera->traceTarget != 0) {
        VecFx32 eyeNow;
        VecFx32 targetNow;
        VecFx32 eyeDelayed;
        VecFx32 targetDelayed;

        func_02048B30(camera->g3dCamera, &targetNow);
        func_02048AE8(camera->g3dCamera, &eyeNow);
        func_0218ED9C(camera->delay, &targetNow, &eyeNow, &targetDelayed, &eyeDelayed);
        func_02048B44(camera->g3dCamera, &targetDelayed);
        func_02048AFC(camera->g3dCamera, &eyeDelayed);
    }
}

/* Switches the delay log off. */
void func_0218F050(FieldCameraDelay *delay)
{
    delay->draining = 0;
    delay->enabled = 0;
    delay->filled = 0;
}

/* Clears both logs and restarts the delay. */
void func_0218F05C(FieldCamera *camera)
{
    FieldCameraDelay *delay = camera->delay;
    int i;

    if (delay != 0) {
        for (i = 0; i < delay->count; i++) {
            VecFx32 *entry = &delay->targetLog[i];
            entry->x = 0;
            entry->y = 0;
            entry->z = 0;
            entry = &delay->eyeLog[i];
            entry->x = 0;
            entry->y = 0;
            entry->z = 0;
        }
        delay->readPos = 0;
        delay->writePos = delay->delayFrames;
        delay->filled = 0;
        delay->enabled = 1;
        delay->draining = 0;
    }
}

/* Ends the delay: at once while it is still warming up, else after the log has played out. */
void func_0218F0A8(FieldCamera *camera)
{
    FieldCameraDelay *delay = camera->delay;

    if (delay != 0) {
        if (delay->filled == 0 && delay->writePos == delay->delayFrames && delay->readPos == 0)
            func_0218F050(delay);
        else
            delay->draining = 1;
    }
}

void func_0218F0D4(FieldCamera *camera, int unused)
{
    FieldCameraDelay *delay = camera->delay;

    if (delay != 0) {
        delay->draining = 0;
        delay->enabled = 0;
        delay->filled = 0;
    }
}

u32 func_0218F0E8(FieldCamera *camera)
{
    FieldCameraDelay *delay = camera->delay;

    if (delay == 0)
        return 0;
    return delay->enabled;
}

int func_0218F0F8(FieldCamera *camera)
{
    if (camera->traceTarget == 0)
        return 0;
    if (camera->delay != 0)
        return 1;
    return 0;
}

/* Copies the areas of an area set into the camera. */
void func_0218F114(FieldCamera *camera, FieldCameraAreaSet *set)
{
    func_02082D44(set->areas, camera->areas, sizeof(FieldCameraArea) * set->count);
    camera->areaCount = set->count;
}

void func_0218F134(FieldCamera *camera)
{
    func_02082BCC(camera->areas, 0, sizeof(camera->areas));
    camera->areaCount = 0;
}

/* Loads the area set areaId from archive 0x6C unless it is loaded already. */
void func_0218F14C(FieldCamera *camera, u32 areaId, u32 heapId)
{
    FieldCameraAreaSet *set;

    if (camera->areaId != areaId) {
        set = func_0204A380(camera->areaArc, areaId, 0, (u16)((heapId & 0x7fff) | 0x8000));
        func_0218F114(camera, set);
        func_020307B0(set);
        camera->areaId = areaId;
    }
}

void func_0218F18C(FieldCamera *camera, VecFx32 *out)
{
    *out = camera->target;
}

void func_0218F19C(FieldCamera *camera, VecFx32 *out)
{
    *out = camera->eye;
}

void func_0218F1AC(FieldCamera *camera, u32 enabled)
{
    camera->areasEnabled = enabled;
}

unsigned char func_0218F1B4(FieldCamera *camera)
{
    return camera->areasEnabled;
}

/* Runs an area on a point when the area limits the target. */
void func_0218F1BC(FieldCameraArea *area, VecFx32 *point)
{
    if (area->applyTo == FIELD_CAMERA_AREA_ON_TARGET) {
        FieldCameraAreaFunc func = d_021DDA18[area->shape];
        if (func != 0)
            func(area, point, point);
    }
}

/* Runs an area on a point when the area limits the eye. */
void func_0218F1DC(FieldCameraArea *area, VecFx32 *point)
{
    if (area->applyTo == FIELD_CAMERA_AREA_ON_EYE) {
        FieldCameraAreaFunc func = d_021DDA18[area->shape];
        if (func != 0)
            func(area, point, point);
    }
}

/* Clamps a point into the box (whole units, converted to fx32); returns 1 when it moved. */
int func_0218F1FC(const FieldCameraArea *area, VecFx32 *in, VecFx32 *out)
{
    VecFx32 p;
    int moved;

    p = *in;
    moved = 0;
    out->x = p.x;
    out->z = p.z;
    out->y = p.y;
    if (FX_F32_TO_FX32(area->u.box.minX) > p.x) {
        moved = 1;
        out->x = FX_F32_TO_FX32(area->u.box.minX);
    } else if (area->u.box.maxX * 4096 < p.x) {
        moved = 1;
        out->x = FX_F32_TO_FX32(area->u.box.maxX);
    }
    if (area->u.box.minZ * 4096 > p.z) {
        moved = 1;
        out->z = FX_F32_TO_FX32(area->u.box.minZ);
    } else if (area->u.box.maxZ * 4096 < p.z) {
        moved = 1;
        out->z = FX_F32_TO_FX32(area->u.box.maxZ);
    }
    return moved;
}

/*
 * Clamps a point to a ring sector around the center: radius capped at
 * maxRadius, angle clamped between minAngle and maxAngle; returns 1 when clamped.
 * `const` on area lets the center z load schedule above the flat.y = 0 store
 * (docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md);
 * the table entry read into an s16 local puts it in r0:r1 of _ll_mul, and
 * `clamped = 1` repeated in both inner arms gives the cross-jumped clamp blocks.
 */
int func_0218F310(const FieldCameraArea *area, VecFx32 *in, VecFx32 *out)
{
    VecFx32 ref;
    VecFx32 flat;
    VecFx32 orig;
    VecFx32 center;
    VecFx32 offset;
    VecFx32 cross;
    int radius;
    int clamped;
    u16 angle;
    u16 minAngle, maxAngle;
    int distToMax, distToMin;
    int idx;
    s16 trig;

    ref = d_021D3E38;
    flat = *in;
    orig = *in;
    out->x = in->x;
    out->y = in->y;
    out->z = in->z;
    center.x = area->u.ring.centerX;
    center.y = 0;
    clamped = 0;
    flat.y = 0;
    center.z = area->u.ring.centerZ;
    VEC_Subtract(&flat, &center, &offset);
    radius = VEC_Mag(&offset);
    if (FX_Modf(radius, &radius) > 0) {
        radius += 0x1000;
    }
    VEC_Normalize(&offset, &offset);
    VEC_CrossProduct(&ref, &offset, &cross);
    angle = FX_AcosIdx(VEC_DotProduct(&ref, &offset));
    if (cross.y < 0) {
        angle = 0x10000 - angle;
    }
    if (radius > area->u.ring.maxRadius) {
        radius = area->u.ring.maxRadius;
        clamped = 1;
    }
    minAngle = area->u.ring.minAngle;
    maxAngle = area->u.ring.maxAngle;
    if (maxAngle != minAngle) {
        if (maxAngle > minAngle) {
            if (minAngle < angle && maxAngle >= angle) {
                distToMax = maxAngle - angle;
                if (distToMax < 0) distToMax = -distToMax;
                distToMin = minAngle - angle;
                if (distToMin < 0) distToMin = -distToMin;
                if (distToMin > distToMax) {
                    angle = maxAngle;
                    clamped = 1;
                } else {
                    angle = minAngle;
                    clamped = 1;
                }
            }
        } else if (maxAngle > angle) {
            angle = maxAngle;
            clamped = 1;
        } else if (minAngle < angle) {
            angle = minAngle;
            clamped = 1;
        }
    }
    if (clamped != 0) {
        idx = (angle >> 4) * 2;
        trig = d_020A1B38[idx];
        out->x = center.x + (int)(((long long)trig * radius + 0x800) >> 12);
        trig = d_020A1B38[idx + 1];
        out->z = center.z + (int)(((long long)trig * radius + 0x800) >> 12);
        out->y = orig.y;
    }
    return clamped;
}

/*
 * Pushes a point inside the box (whole units, converted to fx32) out through
 * the nearest side; returns 1 when it moved.
 * Reading p.z directly (no named local) is what puts its CSE slot below the
 * minX temp.
 */
int func_0218F460(FieldCameraArea *area, VecFx32 *in, VecFx32 *out)
{
    VecFx32 p;
    int moved;
    int best;
    int side;

    p = *in;
    moved = 0;
    out->x = p.x;
    out->z = p.z;
    out->y = p.y;
    if (FX_F32_TO_FX32(area->u.box.minX) < p.x && FX_F32_TO_FX32(area->u.box.maxX) > p.x &&
        FX_F32_TO_FX32(area->u.box.minZ) < p.z && FX_F32_TO_FX32(area->u.box.maxZ) > p.z) {
        moved = 1;
        best = out->x - FX_F32_TO_FX32(area->u.box.minX);
        side = 0;
        if (best > FX_F32_TO_FX32(area->u.box.maxX) - out->x) {
            best = FX_F32_TO_FX32(area->u.box.maxX) - out->x;
            side = 1;
        }
        if (best > out->z - FX_F32_TO_FX32(area->u.box.minZ)) {
            best = out->z - FX_F32_TO_FX32(area->u.box.minZ);
            side = 2;
        }
        if (best > FX_F32_TO_FX32(area->u.box.maxZ) - out->z) {
            best = FX_F32_TO_FX32(area->u.box.maxZ) - out->z;
            side = 3;
        }
        switch (side) {
        case 0:
            out->x = FX_F32_TO_FX32(area->u.box.minX);
            break;
        case 1:
            out->x = FX_F32_TO_FX32(area->u.box.maxX);
            break;
        case 2:
            out->z = FX_F32_TO_FX32(area->u.box.minZ);
            break;
        case 3:
            out->z = FX_F32_TO_FX32(area->u.box.maxZ);
            break;
        }
    }
    return moved;
}

/* Takes a snapshot of the camera pose (raw eye and raw target). */
void func_0218F780(FieldCamera *camera, FieldCameraView *view)
{
    view->eye = camera->eyeRaw;
    view->target = camera->targetRaw;
    view->pitch = camera->pitch;
    view->yaw = camera->yaw;
    view->distance = camera->distance;
    view->fov = camera->fov;
    view->shift = camera->targetShift;
}

/* Same as above, but with the target after the areas. */
void func_0218F7D0(FieldCamera *camera, FieldCameraView *view)
{
    view->eye = camera->eyeRaw;
    func_0218F18C(camera, &view->target);
    view->pitch = camera->pitch;
    view->yaw = camera->yaw;
    view->distance = camera->distance;
    view->fov = camera->fov;
    view->shift = camera->targetShift;
}

/* Saves mode and pose (raw target) once, then switches to target mode. */
void func_0218F818(FieldCamera *camera)
{
    if (camera != 0) {
        FieldCameraMotion *motion = &camera->motion;
        if (motion->stateSaved == 0) {
            motion->savedMode = camera->mode;
            func_0218E13C(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
            func_0218F780(camera, &motion->saved);
            motion->stateSaved = 1;
        }
    }
}

/* Same as above, saving the target after the areas. */
void func_0218F848(FieldCamera *camera)
{
    if (camera != 0) {
        FieldCameraMotion *motion = &camera->motion;
        if (motion->stateSaved == 0) {
            motion->savedMode = camera->mode;
            func_0218E13C(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
            func_0218F7D0(camera, &motion->saved);
            motion->stateSaved = 1;
        }
    }
}

/* Restores the mode saved by the two calls above. */
void func_0218F878(FieldCamera *camera)
{
    if (camera != 0) {
        FieldCameraMotion *motion = &camera->motion;
        if (motion->stateSaved != 0) {
            func_0218E13C(camera, motion->savedMode);
            motion->stateSaved = 0;
        }
    }
}

/* Sets up a move to request->goal and arms the per-frame callback. */
void func_0218F89C(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames)
{
    FieldCameraMotion *motion;

    if (camera) {
        motion = &camera->motion;
        func_0218E13C(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
        motion->to = request->goal;
        motion->frame = 0;
        motion->frames = frames;
        motion->channels = request->channels;
        camera->motion.callback = (FieldCameraUpdateFunc)func_0218FB1C;
        motion->callbackArg = 0;
        motion->moving = 1;
    }
}

/* Moves from the current pose (raw target) to request->goal. */
void func_0218F900(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames)
{
    if (camera != 0) {
        func_0218F89C(camera, request, frames);
        func_0218F780(camera, &camera->motion.from);
    }
}

/* Same as above, starting from the target after the areas. */
void func_0218F918(FieldCamera *camera, FieldCameraMoveRequest *request, u16 frames)
{
    if (camera != 0) {
        func_0218F89C(camera, request, frames);
        func_0218F7D0(camera, &camera->motion.from);
    }
}

/* Moves eye and target to the two goals in free mode. */
void func_0218F930(FieldCamera *camera, VecFx32 *eyeGoal, VecFx32 *targetGoal, FieldCameraMoveChannels *channels, u16 frames)
{
    FieldCameraMotion *motion;
    FieldCameraMoveChannels loc;

    if (camera) {
        motion = &camera->motion;
        func_0218E13C(camera, FIELD_CAMERA_MODE_FREE);
        func_0218F780(camera, &motion->from);
        motion->to.eye = *eyeGoal;
        motion->to.target = *targetGoal;
        motion->frame = 0;
        motion->frames = frames;
        loc.target = channels->target;
        loc.pitch = 0;
        loc.fov = channels->fov;
        loc.yaw = 0;
        loc.distance = 0;
        loc.shift = channels->shift;
        motion->channels = loc;
        camera->motion.callback = (FieldCameraUpdateFunc)func_0218FC80;
        motion->callbackArg = 0;
        motion->moving = 1;
    }
}

/* Moves from the current pose back to the pose saved by the push state calls. */
void func_0218F9C4(FieldCamera *camera, FieldCameraMoveChannels *channels, u16 frames)
{
    FieldCameraMotion *motion;

    if (camera) {
        motion = &camera->motion;
        if (motion->stateSaved != 0 && frames != 0) {
            func_0218E13C(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
            func_0218F780(camera, &motion->from);
            motion->to = motion->saved;
            motion->frame = 0;
            motion->frames = frames;
            motion->channels = *channels;
            camera->motion.callback = (FieldCameraUpdateFunc)func_0218FB1C;
            motion->callbackArg = 0;
            motion->moving = 1;
        }
    }
}

/*
 * Moves from the current pose to the pose of the current setting record.
 * The two vector copies into motion->to.target are tail-merged by the
 * compiler (a shared source pointer variable compiles the same).
 */
void func_0218FA40(FieldCamera *camera, u16 frames)
{
    FieldCameraMotion *motion;
    FieldCameraSetting setting;

    if (camera) {
        motion = &camera->motion;
        if (motion->stateSaved != 0 && frames != 0) {
            func_0218E13C(camera, FIELD_CAMERA_MODE_TRACK_TARGET);
            func_0218F780(camera, &motion->from);
            func_0218E260(camera, &setting);
            motion->to.pitch = setting.pitch;
            motion->to.yaw = setting.yaw;
            motion->to.distance = setting.distance << 12;
            motion->to.fov = setting.fov;
            if (setting.hasTarget != 0) {
                motion->to.shift = setting.vec;
                motion->to.target = *camera->boundTarget;
            } else {
                motion->to.shift.x = 0;
                motion->to.shift.y = 0;
                motion->to.shift.z = 0;
                motion->to.target = setting.vec;
            }
            motion->frame = 0;
            motion->frames = frames;
            motion->channels.shift = 1;
            motion->channels.pitch = 1;
            motion->channels.yaw = 1;
            motion->channels.distance = 1;
            motion->channels.fov = 1;
            motion->channels.target = 1;
            camera->motion.callback = (FieldCameraUpdateFunc)func_0218FB1C;
            motion->callbackArg = 0;
            motion->moving = 1;
        }
    }
}

/*
 * Per-frame callback of the moves above: steps the frame counter and
 * interpolates each enabled channel from the start pose toward the goal pose.
 */
void func_0218FB1C(FieldCamera *camera)
{
    FieldCameraMotion *motion;
    FieldCameraView *from;
    FieldCameraView *to;

    motion = &camera->motion;
    if (motion->moving == 0) {
        return;
    }
    (motion->frame)++;
    from = &motion->from;
    to = &motion->to;
    if (motion->channels.pitch != 0) {
        camera->pitch = func_0218FDF0(&from->pitch, &to->pitch,
                                      motion->frames, motion->frame);
    }
    if (motion->channels.yaw != 0) {
        camera->yaw = func_0218FDF0(&from->yaw, &to->yaw,
                                    motion->frames, motion->frame);
    }
    if (motion->channels.target != 0) {
        func_0218FD88(&from->target, &to->target, motion->frames, motion->frame, &camera->targetRaw);
    }
    if (motion->channels.fov != 0) {
        camera->fov = func_0218FDF0(&from->fov, &to->fov,
                                    motion->frames, motion->frame);
        func_02048B80(camera->g3dCamera, d_020A1B38[(camera->fov >> 4) * 2]);
        func_02048B94(camera->g3dCamera, d_020A1B38[(camera->fov >> 4) * 2 + 1]);
    }
    if (motion->channels.distance != 0) {
        camera->distance = func_0218FDD4(&from->distance, &to->distance,
                                         motion->frames, motion->frame);
    }
    if (motion->channels.shift != 0) {
        func_0218FD88(&from->shift, &to->shift, motion->frames, motion->frame, &camera->targetShift);
    }
    if (motion->frame >= motion->frames) {
        motion->moving = 0;
        func_0218FE40(camera);
    }
}

/* Per-frame callback of the free mode move: eye and target, fov and shift channels. */
void func_0218FC80(FieldCamera *camera)
{
    FieldCameraMotion *motion;
    FieldCameraView *from;
    FieldCameraView *to;

    motion = &camera->motion;
    if (motion->moving == 0) {
        return;
    }
    (motion->frame)++;
    from = &motion->from;
    to = &motion->to;
    if (motion->channels.target != 0) {
        func_0218FD88(&from->target, &to->target, motion->frames, motion->frame, &camera->targetRaw);
        func_0218FD88(&from->eye, &to->eye, motion->frames, motion->frame, &camera->eyeRaw);
    }
    if (motion->channels.fov != 0) {
        camera->fov = func_0218FDF0(&from->fov, &to->fov,
                                    motion->frames, motion->frame);
        func_02048B80(camera->g3dCamera, d_020A1B38[(camera->fov >> 4) * 2]);
        func_02048B94(camera->g3dCamera, d_020A1B38[(camera->fov >> 4) * 2 + 1]);
    }
    if (motion->channels.shift != 0) {
        func_0218FD88(&from->shift, &to->shift, motion->frames, motion->frame, &camera->targetShift);
    }
    if (motion->frame >= motion->frames) {
        motion->moving = 0;
        func_0218FE40(camera);
    }
}

/*
 * frames and frame are u16 (the caller passes u16 fields): with int parameters the
 * scheduler hoists the third call's pointer bumps above the store of out->y.
 */
void func_0218FD88(VecFx32 *from, VecFx32 *to, u16 frames, u16 frame, VecFx32 *out)
{
    if (frames == 0)
        *out = *to;
    out->x = func_0218FDD4(&from->x, &to->x, frames, frame);
    out->y = func_0218FDD4(&from->y, &to->y, frames, frame);
    out->z = func_0218FDD4(&from->z, &to->z, frames, frame);
}

/* Linear interpolation from *from to *to after frame of frames steps. */
int func_0218FDD4(int *from, int *to, int frames, int frame)
{
    int start = *from;
    int end = *to;
    int diff;
    if (frames == frame)
        return end;
    diff = end - start;
    return start + diff * frame / frames;
}

/* Same for 16-bit angles, along the shorter way round. */
u16 func_0218FDF0(u16 *from, u16 *to, s32 frames, s32 frame)
{
    u16 start, delta, rem;
    if (frames == 0)
        return *to;
    start = *from;
    delta = *to - start;
    rem = 0x10000 - delta;
    if (delta <= rem)
        return start + (u16)(delta * frame / frames);
    return start - (u16)(rem * frame / frames);
}

void func_0218FE40(FieldCamera *camera)
{
    camera->motion.callback = 0;
    camera->motion.callbackArg = 0;
}

/* 1 while a move callback is armed and the move is running. */
int func_0218FE50(FieldCamera *camera)
{
    FieldCameraMotion *motion = &camera->motion;
    if (camera->motion.callback != 0 && motion->moving != 0)
        return 1;
    return 0;
}

/* Returns the goal pose of the running move. */
FieldCameraView *func_0218FE70(FieldCamera *camera)
{
    return &camera->motion.to;
}
