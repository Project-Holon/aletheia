/*
 * unit:     no
 * address:  0x02030428
 * packet:   pkt_0202FC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030428
 *
 * Checked heap-id lookup: masks the direction flag out of a public heap
 * id, range-checks the index against the manager's heap count, records a
 * result code, and returns the heap's arena pointer.
 *
 *   void *sub_02030428(u32 heapId)
 *
 * This is one of a family of four functions in this unit that open with
 * exactly the same eight-instruction preamble (pool-load the manager, pool
 * load 0x7fff, `ldrh` the count at +8, mask, compare, and on the
 * out-of-range path `movhs r0, #1` / `strhhs r0, [r?, #0xe]` / `bhs`) and
 * differ only in what they do once the id is known good:
 *
 *   0x02030344  -> sub_02060E6C(arena)      returns the arena's first block
 *   0x02030428  -> arena                    (this function)
 *   0x0203046C  -> the heap's record index, 0xffff on failure
 *   0x020304CC  -> a plain 1/0 validity answer (packet pkt_020304CC)
 *
 * The conditional store of result code 1 costs nothing extra because the
 * `movhs r0, #1` that feeds it is also the value the compiler needs; the
 * success path's `error = 0` is a separate `mov r1, #0` because r0 is
 * already committed to the masked id being passed on.
 *
 * symbols:
 *   g_EnvModule     0x02146954  data
 *   sub_0202FBAC    0x0202FBAC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030428.c \
 *       --func sub_02030428 --addr 0x02030428 --cc 1.1p1 --arm
 */

#include "../include/G_EnvModule.h"

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

extern struct EnvModule g_EnvModule;
extern void *sub_0202FBAC(u32 idx);

void *sub_02030428(u32 heapId)
{
    heapId &= 0x7FFF;
    if (heapId >= g_EnvModule.count) {
        g_EnvModule.error = 1;
        goto fail;
    }
    g_EnvModule.error = 0;
    return sub_0202FBAC(heapId);

fail:
    return 0;
}
