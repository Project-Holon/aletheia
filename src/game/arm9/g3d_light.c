/*
 * file:     g3d_light.c
 * unit:     yes
 * function: G3D_LIGHT_CreateSlots, G3D_LIGHT_DeleteSlots, G3D_LIGHT_ApplySlots, G3D_LIGHT_GetDirection, G3D_LIGHT_SetDirection, G3D_LIGHT_GetColor, G3D_LIGHT_SetColor
 * address:  0x02048BC4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from g3d_light.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc      0x02030734  arm
 *   GFL_HEAP_Free   0x020307B0  arm
 *   g3d_light_file  0x020A7ED4  data
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 */
#include "g3d_util_shared_types.h"

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
    u16           color;
};

extern void *GFL_HEAP_Alloc(u16 heapID, u32 size, int clear, const char *file, int line);

extern u32 GFL_HEAP_Free(void *p);

void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);

struct LightSlotValue *G3D_LIGHT_CreateSlots(const struct LightSetDesc *s, u16 heap);

u32 G3D_LIGHT_DeleteSlots(void *p);

void G3D_LIGHT_ApplySlots(struct LightSlot *slots);

void G3D_LIGHT_GetDirection(struct LightSlot *slots, u8 i, struct Rgb555 *out);

void G3D_LIGHT_SetDirection(struct LightSlot *slots, u32 i, struct Rgb555 *in);

void G3D_LIGHT_GetColor(struct LightSlot *slots, u8 i, u16 *out);

void G3D_LIGHT_SetColor(struct LightSlot *slots, u32 i, u16 *in);

extern const char g3d_light_file[];

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

void G3D_LIGHT_GetDirection(struct LightSlot *slots, u8 i, struct Rgb555 *out)
{
    *out = slots[i].col;
}

void G3D_LIGHT_SetDirection(struct LightSlot *slots, u32 i, struct Rgb555 *in)
{
    slots[i].col = *in;
}

void G3D_LIGHT_GetColor(struct LightSlot *slots, u8 i, u16 *out)
{
    *out = slots[i].color;
}

void G3D_LIGHT_SetColor(struct LightSlot *slots, u32 i, u16 *in)
{
    slots[i].color = *in;
}
