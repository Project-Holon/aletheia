/*
 * unit:     yes
 * function: func_02048BC4
 * address:  0x02048BC4
 * packet:   pkt_02048AD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02048BC4_File  0x020A7ED4  data
 *   func_02030734       0x02030734  arm
 *
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct LightSlot {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
};

struct LightRec {
    u8               slot;
    u8               pad01;
    struct LightSlot val;
};

struct LightSet {
    struct LightRec *recs;
    u8               count;
};

extern const char func_02048BC4_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap)
{
    struct LightSlot *out;
    int i;

    out = (struct LightSlot *)func_02030734(heap, 0x20, 1,
                                            func_02048BC4_File, 43);
    for (i = 0; i < s->count; i++) {
        struct LightRec *r = &s->recs[i];
        u32 slot = r->slot;

        out[slot] = r->val;
    }
    return out;
}
