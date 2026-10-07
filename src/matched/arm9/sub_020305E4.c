/*
 * unit:     no
 * address:  0x020305E4
 * packet:   pkt_02030534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: sub_020305E4
 *
 * symbols:
 *   g_EnvHeapModule  0x02146964  data
 *   OS_FreeToHeap    0x020869E8  arm
 *
 * Frees the id table of a second module-like global, 0x10 bytes after
 * g_EnvModule (0x02146954, see src/matched/unit_0202FBAC.c), through
 * TwlSDK's OS_FreeToHeap on heap 4 (the same heap id sub_02030534, a few
 * bytes earlier in this packet, allocates from with OS_AllocFromArenaLo).
 * The idx argument is loaded into r2 but never used by the call: OS_Free
 * ToHeap only reads its first two arguments, and the leftover third
 * register is exactly the shape
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md
 * describes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020305E4.c \
 *       --func sub_020305E4 --addr 0x020305E4 --cc 1.1p1
 */

#include "../include/G_EnvHeapModule.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern struct EnvHeapModule g_EnvHeapModule;
extern int OS_FreeToHeap(u32 heapId, void *ptr, u32 idx);

int sub_020305E4(u32 idx)
{
    OS_FreeToHeap(4, g_EnvHeapModule.heapHandle, idx);
    return 1;
}
