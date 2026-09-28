/*
 * unit:     yes
 * function: func_02048C58
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
 *   func_02046A94  0x02046A94  arm
 *   g_02146A68     0x02146A68  data
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

extern struct LightGlobal g_02146A68;

extern void func_02046A94(u8 slot, struct LightSlot *s);

void func_02048C58(struct LightSlot *slots)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_02046A94(i, &slots[i]);
    }
}

void func_02048C80(struct LightSlot *slots, u32 i, struct Rgb555 *out)
{
    *out = slots[i].col;
}

void func_02048CA4(struct LightSlot *slots, u32 i, struct Rgb555 *in)
{
    slots[i].col = *in;
}

void func_02048CCC(struct LightSlot *slots, u32 i, u16 *out)
{
    *out = slots[i].unk06;
}

void func_02048CDC(struct LightSlot *slots, u32 i, u16 *in)
{
    slots[i].unk06 = *in;
}

void func_02048CEC(u32 a, u32 b)
{
    g_02146A68.unk00 = a;
    g_02146A68.unk04 = b;
    g_02146A68.unk08 = 0;
}
