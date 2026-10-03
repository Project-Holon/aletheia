/*
 * unit:     no
 * address:  0x020303D8
 * packet:   pkt_0202FC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020303D8
 *
 * Total size of a heap's arena, in bytes: the shared checked-heap-id
 * preamble (see src/matched/sub_02030428.c), then the arena's end pointer
 * at +0x1c minus the arena base.
 *
 *   u32 sub_020303D8(u32 heapId)
 *
 * The two failure paths reach the same `mov r0, #0` / `pop` differently,
 * and that asymmetry is the shape to reproduce: the out-of-range path
 * branches to it, while the null-arena path simply falls into it because
 * the whole success tail is predicated `ne`. Writing the success case as
 * an `if (arena != 0) { ... return ...; }` that falls through to the label
 * gives exactly that; an `if (arena == 0) goto fail;` guard instead emits
 * a second branch and loses the predication.
 *
 * symbols:
 *   g_EnvModule     0x02146954  data
 *   sub_0202FBAC    0x0202FBAC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020303D8.c \
 *       --func sub_020303D8 --addr 0x020303D8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct EnvEntry {
    void *ptr00;
    u32 field04;
    u32 field08;
    u16 field0c;
    u8  field0e;
};

struct EnvModule {
    struct EnvEntry *entries;
    u8 *ids;
    u16 count;
    u16 field0a;
    u16 field0c;
    u16 error;
};

struct Arena {
    u32 field00[7];
    u32 *end;
};

extern struct EnvModule g_EnvModule;
extern void *sub_0202FBAC(u32 idx);

u32 sub_020303D8(u32 heapId)
{
    struct Arena *arena;

    heapId &= 0x7FFF;
    if (heapId >= g_EnvModule.count) {
        g_EnvModule.error = 1;
        goto fail;
    }
    arena = sub_0202FBAC(heapId);
    if (arena != 0) {
        u32 end = (u32)arena->end;
        g_EnvModule.error = 0;
        return end - (u32)arena;
    }

fail:
    return 0;
}
