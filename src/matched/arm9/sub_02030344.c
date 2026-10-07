/*
 * unit:     no
 * address:  0x02030344
 * packet:   pkt_0202FC48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_02030344
 *
 * Checked heap-id lookup that hands the arena straight on to sub_02060E6C
 * and returns what that returns; see src/matched/sub_02030428.c for the
 * shared preamble this family has in common.
 *
 *   void *sub_02030344(u32 heapId)
 *
 * The two calls are back to back with no register shuffle between them,
 * which is the nested-call form `sub_02060E6C(sub_0202FBAC(heapId))`
 * rather than a local bound in between; the result is not touched after
 * the second call either, so the function is a plain tail return of it
 * (the `pop` after the `bl` is the one-section-per-function tail form, not
 * a missed tail call).
 *
 * symbols:
 *   g_EnvModule     0x02146954  data
 *   sub_0202FBAC    0x0202FBAC  arm
 *   sub_02060E6C    0x02060E6C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02030344.c \
 *       --func sub_02030344 --addr 0x02030344 --cc 1.1p1 --arm
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
extern int sub_02060E6C(int *p);

void *sub_02030344(u32 heapId)
{
    heapId &= 0x7FFF;
    if (heapId >= g_EnvModule.count) {
        g_EnvModule.error = 1;
        goto fail;
    }
    g_EnvModule.error = 0;
    return (void *)sub_02060E6C(sub_0202FBAC(heapId));

fail:
    return 0;
}
