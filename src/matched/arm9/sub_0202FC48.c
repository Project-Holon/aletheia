/*
 * function: GFL_HEAP_InitManager
 * address:  0x0202FC48
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
 *   sub_02060C5C  0x02060C5C  arm
 *   sub_02086788  0x02086788  arm
 *
 * The module initialiser named by src/matched/unit_0202FBAC.c: it allocates
 * both arrays g_EnvModule reads and fills the header at +8.  The entry array
 * is sized count+0x18, so the first `count` slots are the caller's resources
 * and the remaining 0x18 are spares the binders in this file hand out.  The
 * id table is at least as long as the entry array, the caller's own request
 * being clamped up to it, and every byte starts at 0xff (free).
 *
 * The clearing loop reloads g_EnvModule.entries before every field store,
 * which is what writing each store through the global rather than through a
 * cached cursor produces: the stores may alias the pointer itself.
 *
 * count and idCount are u16, and that is not decoration: it is the whole
 * difference between this and the 376-byte near miss recorded in
 * docs/notes/GFL_HEAP_InitManager.c.txt.  With u32 parameters the allocator keeps the
 * constant zero live from the clearing loop to the last call and needs seven
 * callee-saved registers, which loses the `mov sb, r4` in the final loop's
 * preheader.  With count u16 the zero's live range ends at the clearing loop,
 * total takes sb and the preheader re-materialises the zero off the r4 that
 * `error = 0` has just left at zero: 380 bytes, byte for byte.  The caller
 * GFL_HEAP_Init truncates both arguments with an lsl/lsr #16 pair before the
 * call, which is where the u16 comes from.  idCount's own type is not what
 * decides it ((u16)total below makes the truncation explicit either way);
 * count's is: u32 count with u16 idCount still lands at 376.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_HEAP_InitManager.c \
 *       --func GFL_HEAP_InitManager --addr 0x0202FC48 --cc 1.1p1 --arm
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

struct EnvRes {
    u32 size;
    u32 unk_04;
};

extern struct EnvModule g_EnvModule;

extern void *sub_02086788(u32 heap, u32 size, u32 align);
extern void *sub_02060C5C(void *mem, u32 size, u32 mode);

int GFL_HEAP_InitManager(const struct EnvRes *res, u16 count, u16 idCount, u32 extra)
{
    u32   total;
    u32   i;
    void *mem;
    u32   slot;

    total = count + 0x18;
    if (idCount < total) {
        idCount = (u16)total;
    }

    if (extra != 0) {
        while ((extra & 3) != 0) {
            extra++;
        }
        sub_02086788(0, extra, 4);
    }

    g_EnvModule.entries = sub_02086788(0, total * 16, 4);
    for (slot = 0; slot < total; slot++) {
        g_EnvModule.entries[slot].ptr00 = 0;
        g_EnvModule.entries[slot].field04 = 0;
        g_EnvModule.entries[slot].field08 = 0;
        g_EnvModule.entries[slot].field0c = 0;
        g_EnvModule.entries[slot].field0e = 0;
    }

    g_EnvModule.ids = sub_02086788(0, idCount, 4);
    for (i = 0; i < idCount; i++) {
        ((u8 *)g_EnvModule.ids)[i] = 0xff;
    }

    g_EnvModule.count = idCount;
    g_EnvModule.resCount = count;
    g_EnvModule.entryCount = total;
    g_EnvModule.error = 0;

    for (i = 0; i < count; i++) {
        mem = sub_02086788(0, res[i].size, 4);
        if (mem != 0) {
            g_EnvModule.entries[i].ptr00 = sub_02060C5C(mem, res[i].size, 0);
            ((u8 *)g_EnvModule.ids)[i] = i;
        } else {
            g_EnvModule.error = i;
            return 0;
        }
    }
    return 1;
}
