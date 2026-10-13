/*
 * unit:     yes
 * function: G3D_LIGHT_ApplySlots
 * address:  0x02048C58
 * packet:   pkt_02048AD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_SetLight  0x02046A94  arm
 *   ARC_TOOL_gArchiveTable     0x02146A68  data
 *
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rgb555 {
    u16 r;
    u16 g;
    u16 b;
};

struct LightSlot {
    struct Rgb555 col;
    u16           unk06;
};

struct LightGlobal {
    u32 unk00;
    u32 unk04;
    u32 unk08;
};

extern struct LightGlobal ARC_TOOL_gArchiveTable;

extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);

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
    *out = slots[i].unk06;
}

void G3D_LIGHT_SetSlotFlags(struct LightSlot *slots, u32 i, u16 *in)
{
    slots[i].unk06 = *in;
}

void ARC_TOOL_SetTable(u32 a, u32 b)
{
    ARC_TOOL_gArchiveTable.unk00 = a;
    ARC_TOOL_gArchiveTable.unk04 = b;
    ARC_TOOL_gArchiveTable.unk08 = 0;
}
