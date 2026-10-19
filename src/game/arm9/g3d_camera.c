/*
 * file:     g3d_camera.c
 * unit:     yes
 * function: G3D_CAMERA_Create, G3D_CAMERA_Delete, G3D_CAMERA_Reset, G3D_CAMERA_GetEye, G3D_CAMERA_SetEye, G3D_CAMERA_GetCamUp, G3D_CAMERA_SetCamUp, G3D_CAMERA_GetCamTarget, G3D_CAMERA_SetCamTarget, G3D_CAMERA_GetNear, G3D_CAMERA_SetNear, G3D_CAMERA_SetFar, G3D_CAMERA_GetMode, G3D_CAMERA_SetFovySin, G3D_CAMERA_GetFovyCos, G3D_CAMERA_SetFovyCos, G3D_CAMERA_GetNearClipAlt, G3D_CAMERA_SetNearClipAlt, G3D_CAMERA_GetFarClipAlt, G3D_CAMERA_SetFarClipAlt
 * address:  0x02048A24
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from g3d_camera.c, g3d_camera_acc.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   g3d_camera_file     0x020A7EC4  data
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   G3D_SYSTEM_SetLookAt 0x02046B40 arm
 */
#include "g3d_util_shared_types.h"

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

extern void *GFL_HEAP_Alloc(u16 heapID, u32 size, int clear, const char *file, int line);

extern u32 GFL_HEAP_Free(void *p);

u32 *G3D_CAMERA_Create(u32 mode, u32 nearClip, u32 farClip, u32 fieldOfView, u32 aspectRatio, u32 scale, u32 roll, u32 flags, Vec3 *eye, Vec3 *a10, Vec3 *a11, u16 heap);

u32 G3D_CAMERA_Delete(void *ptr);

extern char  g3d_camera_file[];

/*
 * Constructor for a 0x44-byte record: eight words straight from the
 * parameters, then three 12-byte (three-word) aggregates at +0x20, +0x2C and
 * +0x38, each copied with `ldm`/`stm` because a three-word aggregate is above
 * the point where the compiler moves them word by word.  The last parameter
 * is a `u16` heap id -- it arrives at [sp+0x34] and is read with `ldrh`, and
 * it is forwarded widened to the allocator, which is the same
 * GFL_HEAP_Alloc(heap, size, 0, file, line) debug allocator every other site
 * in src/matched/ spells the same way (the pool word is this translation
 * unit's allocation-site string, 0x020A7EC4).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_CAMERA_Create.c \
 *       --func G3D_CAMERA_Create --addr 0x02048A24 --cc 1.1p1 --arm
 */
u32 *G3D_CAMERA_Create(u32 mode, u32 nearClip, u32 farClip, u32 fieldOfView, u32 aspectRatio, u32 scale, u32 roll, u32 flags,
                   Vec3 *eye, Vec3 *target, Vec3 *up, u16 heapID)
{
    u32 *p = (u32 *)GFL_HEAP_Alloc(heapID, 0x44, 0, g3d_camera_file, 0x38);

    p[0] = mode;
    p[1] = nearClip;
    p[2] = farClip;
    p[3] = fieldOfView;
    p[4] = aspectRatio;
    p[5] = scale;
    p[6] = roll;
    p[7] = flags;
    *(Vec3 *)(p + 8) = *eye;
    *(Vec3 *)(p + 11) = *target;
    *(Vec3 *)(p + 14) = *up;
    return p;
}

u32 G3D_CAMERA_Delete(void *camera)
{
    return GFL_HEAP_Free(camera);
}

typedef struct {
    int x;
    int y;
    int z;
} VecFx32;

struct G3dCamera {
    u32     mode;
    u32     nearClip;
    u32     farClip;
    u32     fieldOfView;
    u32     aspectRatio;
    u32     scale;
    u32     roll;
    u32     flags;
    VecFx32 eye;
    VecFx32 target;
    VecFx32 up;
};

void G3D_SYSTEM_SetProjection(const u32 *src);

void G3D_SYSTEM_SetLookAt(u8 *lookAt);

void G3D_CAMERA_Reset(struct G3dCamera *l);

void G3D_CAMERA_GetEye(struct G3dCamera *l, VecFx32 *out);

void G3D_CAMERA_SetEye(struct G3dCamera *l, const VecFx32 *in);

void G3D_CAMERA_GetCamUp(struct G3dCamera *l, VecFx32 *out);

void G3D_CAMERA_SetCamUp(struct G3dCamera *l, const VecFx32 *in);

void G3D_CAMERA_GetCamTarget(struct G3dCamera *l, VecFx32 *out);

void G3D_CAMERA_SetCamTarget(struct G3dCamera *l, const VecFx32 *in);

void G3D_CAMERA_GetNear(struct G3dCamera *l, u32 *out);

void G3D_CAMERA_SetNear(struct G3dCamera *l, const u32 *in);

void G3D_CAMERA_SetFar(struct G3dCamera *l, const u32 *in);

int G3D_CAMERA_GetMode(struct G3dCamera *l);

void G3D_CAMERA_SetFovySin(struct G3dCamera *l, u32 v);

void G3D_CAMERA_GetFovyCos(struct G3dCamera *l, u32 *out);

void G3D_CAMERA_SetFovyCos(struct G3dCamera *l, u32 v);

void G3D_CAMERA_GetNearClipAlt(struct G3dCamera *l, u32 *out);

void G3D_CAMERA_SetNearClipAlt(struct G3dCamera *l, u32 v);

void G3D_CAMERA_GetFarClipAlt(struct G3dCamera *l, u32 *out);

void G3D_CAMERA_SetFarClipAlt(struct G3dCamera *l, u32 v);

/*
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */
void G3D_CAMERA_Reset(struct G3dCamera *camera)
{
    G3D_SYSTEM_SetProjection((const u32 *)camera);
    G3D_SYSTEM_SetLookAt((u8 *)(&camera->eye));
}

void G3D_CAMERA_GetEye(struct G3dCamera *camera, VecFx32 *out)
{
    *out = camera->eye;
}

void G3D_CAMERA_SetEye(struct G3dCamera *camera, const VecFx32 *in)
{
    camera->eye = *in;
}

void G3D_CAMERA_GetCamUp(struct G3dCamera *camera, VecFx32 *out)
{
    *out = camera->target;
}

void G3D_CAMERA_SetCamUp(struct G3dCamera *camera, const VecFx32 *in)
{
    camera->target = *in;
}

void G3D_CAMERA_GetCamTarget(struct G3dCamera *camera, VecFx32 *out)
{
    *out = camera->up;
}

void G3D_CAMERA_SetCamTarget(struct G3dCamera *camera, const VecFx32 *in)
{
    camera->up = *in;
}

void G3D_CAMERA_GetNear(struct G3dCamera *camera, u32 *out)
{
    *out = camera->scale;
}

void G3D_CAMERA_SetNear(struct G3dCamera *camera, const u32 *in)
{
    camera->scale = *in;
}

void G3D_CAMERA_SetFar(struct G3dCamera *camera, const u32 *in)
{
    camera->roll = *in;
}

int G3D_CAMERA_GetMode(struct G3dCamera *camera)
{
    return camera->mode;
}

void G3D_CAMERA_SetFovySin(struct G3dCamera *camera, u32 v)
{
    camera->nearClip = v;
}

void G3D_CAMERA_GetFovyCos(struct G3dCamera *camera, u32 *out)
{
    *out = camera->farClip;
}

void G3D_CAMERA_SetFovyCos(struct G3dCamera *camera, u32 v)
{
    camera->farClip = v;
}

void G3D_CAMERA_GetNearClipAlt(struct G3dCamera *camera, u32 *out)
{
    *out = camera->nearClip;
}

void G3D_CAMERA_SetNearClipAlt(struct G3dCamera *camera, u32 v)
{
    camera->nearClip = v;
}

void G3D_CAMERA_GetFarClipAlt(struct G3dCamera *camera, u32 *out)
{
    *out = camera->farClip;
}

void G3D_CAMERA_SetFarClipAlt(struct G3dCamera *camera, u32 v)
{
    camera->farClip = v;
}
