/*
 * unit:     no
 * address:  0x0203038C
 * packet:   pkt_0202FC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_0203038C
 *
 * Checked heap-id lookup handing the arena to sub_02060E94 with a mode of
 * 4; see src/matched/sub_02030428.c for the shared preamble this family
 * has in common. The same (arena, 4) pair appears in sub_02030958, the
 * out-of-memory reporter, so mode 4 is the heap-layer's own dump mode.
 *
 *   void *sub_0203038C(u32 heapId)
 *
 * symbols:
 *   g_EnvModule     0x02146954  data
 *   sub_0202FBAC    0x0202FBAC  arm
 *   sub_02060E94    0x02060E94  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203038C.c \
 *       --func sub_0203038C --addr 0x0203038C --cc 1.1p1 --arm
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

extern struct EnvModule g_EnvModule;
extern void *sub_0202FBAC(u32 idx);
extern void *sub_02060E94(void *arena, u32 mode);

void *sub_0203038C(u32 heapId)
{
    heapId &= 0x7FFF;
    if (heapId >= g_EnvModule.count) {
        g_EnvModule.error = 1;
        goto fail;
    }
    g_EnvModule.error = 0;
    return sub_02060E94(sub_0202FBAC(heapId), 4);

fail:
    return 0;
}
