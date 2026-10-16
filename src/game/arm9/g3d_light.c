/*
 * file:     g3d_light.c
 * unit:     yes
 * function: G3D_CAMERA_Reset, G3D_CAMERA_GetEye, G3D_CAMERA_SetEye, G3D_CAMERA_GetTarget, G3D_CAMERA_SetTarget, G3D_CAMERA_GetUp, G3D_CAMERA_SetUp, G3D_CAMERA_GetScale, G3D_CAMERA_SetScale, G3D_CAMERA_SetRoll, G3D_CAMERA_GetMode, G3D_CAMERA_SetNearClip, G3D_CAMERA_GetFarClip, G3D_CAMERA_SetFarClip, G3D_CAMERA_GetNearClipAlt, G3D_CAMERA_SetNearClipAlt, G3D_CAMERA_GetFarClipAlt, G3D_CAMERA_SetFarClipAlt, G3D_LIGHT_CreateSlots, G3D_LIGHT_DeleteSlots, G3D_LIGHT_ApplySlots, G3D_LIGHT_GetSlotColor, G3D_LIGHT_SetSlotColor, G3D_LIGHT_GetSlotFlags, G3D_LIGHT_SetSlotFlags, ARC_TOOL_SetTable
 * address:  0x02048AD0
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
 *   g3d_light_file  0x020A7ED4  data
 *   ARC_TOOL_gArchiveTable     0x02146A68  data
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetLookAt 0x02046B40 arm
 */
#include "g3d_util_shared_types.h"
#include "g3d_light_shared_types.h"

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

struct LightSlotValue {
    u16 red;
    u16 green;
    u16 blue;
    u16 flags;
};

struct LightSlotDesc {
    u8               slot;
    u8               pad01;
    struct LightSlotValue val;
};

struct LightSetDesc {
    struct LightSlotDesc *recs;
    u8               count;
};

struct Rgb555 {
    u16 r;
    u16 g;
    u16 b;
};

struct LightSlot {
    struct Rgb555 col;
    u16           flags;
};

extern void *GFL_HEAP_Alloc(u16 heapID, u32 size, int clear, const char *file, int line);

extern u32 GFL_HEAP_Free(void *p);

void G3D_SYSTEM_SetProjection(const u32 *src);

void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);

void G3D_SYSTEM_SetLookAt(u8 *a0);

void G3D_CAMERA_Reset(struct G3dCamera *l);

void G3D_CAMERA_GetEye(struct G3dCamera *l, VecFx32 *out);

void G3D_CAMERA_SetEye(struct G3dCamera *l, const VecFx32 *in);

void G3D_CAMERA_GetTarget(struct G3dCamera *l, VecFx32 *out);

void G3D_CAMERA_SetTarget(struct G3dCamera *l, const VecFx32 *in);

void G3D_CAMERA_GetUp(struct G3dCamera *l, VecFx32 *out);

void G3D_CAMERA_SetUp(struct G3dCamera *l, const VecFx32 *in);

void G3D_CAMERA_GetScale(struct G3dCamera *l, u32 *out);

void G3D_CAMERA_SetScale(struct G3dCamera *l, const u32 *in);

void G3D_CAMERA_SetRoll(struct G3dCamera *l, const u32 *in);

int G3D_CAMERA_GetMode(struct G3dCamera *l);

void G3D_CAMERA_SetNearClip(struct G3dCamera *l, u32 v);

void G3D_CAMERA_GetFarClip(struct G3dCamera *l, u32 *out);

void G3D_CAMERA_SetFarClip(struct G3dCamera *l, u32 v);

void G3D_CAMERA_GetNearClipAlt(struct G3dCamera *l, u32 *out);

void G3D_CAMERA_SetNearClipAlt(struct G3dCamera *l, u32 v);

void G3D_CAMERA_GetFarClipAlt(struct G3dCamera *l, u32 *out);

void G3D_CAMERA_SetFarClipAlt(struct G3dCamera *l, u32 v);

struct LightSlotValue *G3D_LIGHT_CreateSlots(const struct LightSetDesc *s, u16 heap);

u32 G3D_LIGHT_DeleteSlots(void *p);

void G3D_LIGHT_ApplySlots(struct LightSlot *slots);

void G3D_LIGHT_GetSlotColor(struct LightSlot *slots, u8 i, struct Rgb555 *out);

void G3D_LIGHT_SetSlotColor(struct LightSlot *slots, u32 i, struct Rgb555 *in);

void G3D_LIGHT_GetSlotFlags(struct LightSlot *slots, u8 i, u16 *out);

void G3D_LIGHT_SetSlotFlags(struct LightSlot *slots, u32 i, u16 *in);

void ARC_TOOL_SetTable(u32 a, u32 b);

extern const char g3d_light_file[];

extern struct ArcTableInfo ARC_TOOL_gArchiveTable;

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

void G3D_CAMERA_GetTarget(struct G3dCamera *camera, VecFx32 *out)
{
    *out = camera->target;
}

void G3D_CAMERA_SetTarget(struct G3dCamera *camera, const VecFx32 *in)
{
    camera->target = *in;
}

void G3D_CAMERA_GetUp(struct G3dCamera *camera, VecFx32 *out)
{
    *out = camera->up;
}

void G3D_CAMERA_SetUp(struct G3dCamera *camera, const VecFx32 *in)
{
    camera->up = *in;
}

void G3D_CAMERA_GetScale(struct G3dCamera *camera, u32 *out)
{
    *out = camera->scale;
}

void G3D_CAMERA_SetScale(struct G3dCamera *camera, const u32 *in)
{
    camera->scale = *in;
}

void G3D_CAMERA_SetRoll(struct G3dCamera *camera, const u32 *in)
{
    camera->roll = *in;
}

int G3D_CAMERA_GetMode(struct G3dCamera *camera)
{
    return camera->mode;
}

void G3D_CAMERA_SetNearClip(struct G3dCamera *camera, u32 v)
{
    camera->nearClip = v;
}

void G3D_CAMERA_GetFarClip(struct G3dCamera *camera, u32 *out)
{
    *out = camera->farClip;
}

void G3D_CAMERA_SetFarClip(struct G3dCamera *camera, u32 v)
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

/*
 * g3d_light.c's light-set builder, 0x02048BC4-0x02048C48 plus its one pool
 * word.  It allocates a 0x20-byte table of four eight-byte slots through the
 * debug allocator at 0x02030734 (file 0x020A7ED4, which spells "g3d_light.c",
 * line 43) and scatters a packed ten-byte record array into it: each record
 * names its destination slot in its first byte and carries four halfwords.
 *
 * The record stride is a `mov r2, #0xa` and a `mul`, not a shift chain, so
 * the record really is ten bytes wide and the index really is an `int`.
 *
 * The loop bound is an unsigned char compared signed (`ble` on the rotation
 * test, `blt` on the back edge), which is the plain `int i; i < s->count`
 * shape after integer promotion, not an unsigned loop.
 *
 * The header pointer is `const`, and that is the whole difference between
 * this file and a sixteen-byte-longer near miss: both `s->recs` and
 * `s->count` are still reloaded on every iteration, but with `const` the
 * closing test's `ldrb r3, [r4, #4]` schedules at the *top* of the body,
 * above the halfword stores, which costs one more callee-saved register and
 * turns the five-register push into the six-register one that carries the
 * outgoing fifth argument without a `sub sp, sp, #4`.  See
 * docs/idioms/const-hoists-the-loop-test-load-above-the-body-stores.md.
 *
 * The next thing in the image after this function's pool is the eight-byte
 * ARM long-branch veneer at 0x02048C4C, so no unit may run past 0x02048C4C
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048BC4.c \
 *       --addr 0x02048BC4 --cc 1.1p1 --arm
 */
struct LightSlotValue *G3D_LIGHT_CreateSlots(const struct LightSetDesc *set, u16 heapID)
{
    struct LightSlotValue *slots;
    int i;

    slots = (struct LightSlotValue *)GFL_HEAP_Alloc(heapID, 0x20, 1,
                                            g3d_light_file, 43);
    for (i = 0; i < set->count; i++) {
        struct LightSlotDesc *desc = &set->recs[i];
        u32 slot = desc->slot;

        slots[slot] = desc->val;
    }
    return slots;
}

u32 G3D_LIGHT_DeleteSlots(void *slots)
{
    return GFL_HEAP_Free(slots);
}

/*
 * g3d_light.c's tail, 0x02048C58-0x02048D00: the four-slot upload loop and
 * the per-slot colour accessors over the same eight-byte slot the builder at
 * 0x02048BC4 fills, three halfwords of colour and one spare.
 *
 *   0x02048C58  push all four slots through 0x02046A94; the `and r0, #0xff`
 *               on the loop counter is the callee's `u8` first parameter,
 *               not a narrow counter (the counter itself increments and
 *               compares as a plain `int`)
 *   0x02048C80  read slot i's colour out, 0x02048CA4 writes it
 *   0x02048CCC  read slot i's spare halfword out, 0x02048CDC writes it
 *   0x02048CEC  seed the three-word global at 0x02146A68 from two arguments
 *               and a zero
 *
 * 0x02048CA4 pushes {r3, lr} and calls nothing: lr is spilled purely as a
 * scratch register for the third halfword of the copy.  Its source pointer
 * must not be `const`: with `const` mwcc proves the two halfword stores
 * cannot reach the source and hoists all three loads ahead of them, which is
 * thirteen bytes wrong; without it the third load stays after the first two
 * stores, in source order.
 *
 * The six-byte colour moves are aggregate assignments of the nested struct,
 * which is why the loads pair up ahead of the stores rather than
 * interleaving one field at a time
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md, halfword form).
 *
 * The unit starts at 0x02048C58 and not earlier because 0x02048C4C holds an
 * ARM long-branch veneer that no `tu` range may span.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048C58.c \
 *       --addr 0x02048C58 --cc 1.1p1 --arm
 */
void G3D_LIGHT_ApplySlots(struct LightSlot *slots)
{
    int i;

    for (i = 0; i < 4; i++) {
        G3D_SYSTEM_SetLight((u8)i, (const u16 *)(&slots[i]));
    }
}

void G3D_LIGHT_GetSlotColor(struct LightSlot *slots, u8 i, struct Rgb555 *out)
{
    *out = slots[i].col;
}

void G3D_LIGHT_SetSlotColor(struct LightSlot *slots, u32 i, struct Rgb555 *in)
{
    slots[i].col = *in;
}

void G3D_LIGHT_GetSlotFlags(struct LightSlot *slots, u8 i, u16 *out)
{
    *out = slots[i].flags;
}

void G3D_LIGHT_SetSlotFlags(struct LightSlot *slots, u32 i, u16 *in)
{
    slots[i].flags = *in;
}

void ARC_TOOL_SetTable(u32 entries, u32 count)
{
    ARC_TOOL_gArchiveTable.entries = (u32 *)entries;
    ARC_TOOL_gArchiveTable.count = count;
    ARC_TOOL_gArchiveTable.useRecords = 0;
}
