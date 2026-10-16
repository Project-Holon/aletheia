/*
 * function: GFL_HEAP_RegisterBlockHeapImpl
 * address:  0x0202FE68
 * packet:   pkt_0202FC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_EnvModule   0x02146954  data
 *   sub_0202FED8  0x0202FED8  arm
 *
 * The sibling of GFL_HEAP_CreateChildHeapImpl: bind an already-built object rather than one
 * resolved out of the module.  0x0202FED8 is called with a null resource and
 * the caller's object in the third slot, the same slot GFL_HEAP_CreateChildHeapImpl fills
 * with the result of 0x02060CA0.
 *
 * On success the entry's +0xE byte is set to 1, which is what pins
 * EnvEntry's size at sixteen bytes: the index scale in
 * `add r1, r2, r1, lsl #4` is the struct stride and 0xE is its last used
 * byte.  On a taken destination slot the module error halfword takes 1, as in
 * GFL_HEAP_CreateChildHeapImpl; a refusal from 0x0202FED8 leaves it alone.
 *
 * Both zero returns share one tail with a call between them, so the exit is
 * an explicit `goto`
 * (docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_RegisterBlockHeapImpl.c \
 *       --func GFL_HEAP_RegisterBlockHeapImpl --addr 0x0202FE68 --cc 1.1p1 --arm
 */

#include "../include/G_EnvModule.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct EnvEntry {
    void *ptr00;
    u32   field04;
    u32   field08;
    u16   field0c;
    u8    field0e;
    u8    pad_0f;
};

extern struct EnvModule g_EnvModule;

extern int sub_0202FED8(u32 a0, u32 a1, u32 a2, u32 a3);

int GFL_HEAP_RegisterBlockHeapImpl(void *bound, u32 param, u32 dst)
{
    u32 idx;

    idx = dst & 0x7fff;
    if (((u8 *)g_EnvModule.ids)[idx] != 0xff) {
        g_EnvModule.error = 1;
        goto fail;
    }

    if (sub_0202FED8(0, idx, (u32)bound, param) == 0) {
        goto fail;
    }

    g_EnvModule.entries[((u8 *)g_EnvModule.ids)[idx]].field0e = 1;
    return 1;

fail:
    return 0;
}
