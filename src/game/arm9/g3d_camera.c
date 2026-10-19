/*
 * file:     g3d_camera.c
 * unit:     yes
 * function: G3D_CAMERA_Create, G3D_CAMERA_Delete
 * address:  0x02048A24
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from g3d_util.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   g3d_camera_file     0x020A7EC4  data
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
