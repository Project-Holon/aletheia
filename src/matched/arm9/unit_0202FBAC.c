/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202FBAC
 * packet:   pkt_0202FB34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: GFL_HEAP_GetHeap, GFL_HEAP_GetParentHeap, GFL_HEAP_GetBlock, GFL_HEAP_GetAllocCount
 *
 * symbols:
 *   g_EnvModule  0x02146954  data
 *
 * Four accessors on the same resource-set module: a byte table at +4 maps a
 * caller-supplied index to an entry id (0xff meaning "no such resource"),
 * and the entry array at +0 holds sixteen-byte records. All four functions
 * do the same lookup and differ only in which field of the resolved entry
 * they read back: the raw pointer at +0, the word at +4, the word at +8, or
 * the halfword at +0xc. The initialiser two functions later
 * (0x0202FC48, not in this packet's cheap yield) allocates both arrays and
 * fills each entry's +0xc halfword and +0xe byte to zero, which is what
 * pins the record layout used here.
 *
 * 156 bytes, four functions, no gap. 4 of 4 relocations resolve `literal`:
 * g_EnvModule is loaded from the pool at least 32 other places in the ARM9
 * image.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202FBAC.c \
 *       --addr 0x0202FBAC --arm
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
};

extern struct EnvModule g_EnvModule;

void *GFL_HEAP_GetHeap(u32 idx)
{
    u8 id = ((u8 *)g_EnvModule.ids)[idx];
    if (id == 0xff) return 0;
    return g_EnvModule.entries[id].ptr00;
}

u32 GFL_HEAP_GetParentHeap(u32 idx)
{
    u8 id = ((u8 *)g_EnvModule.ids)[idx];
    if (id == 0xff) return 0;
    return g_EnvModule.entries[id].field04;
}

u32 GFL_HEAP_GetBlock(u32 idx)
{
    u8 id = ((u8 *)g_EnvModule.ids)[idx];
    if (id == 0xff) return 0;
    return g_EnvModule.entries[id].field08;
}

u16 GFL_HEAP_GetAllocCount(u32 idx)
{
    u8 id = ((u8 *)g_EnvModule.ids)[idx];
    if (id == 0xff) return 0;
    return g_EnvModule.entries[id].field0c;
}
