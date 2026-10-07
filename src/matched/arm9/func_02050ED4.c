/*
 * function: func_02050ED4
 * address:  0x02050ED4
 * packet:   pkt_02050C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   g_02146A88      0x02146A88  data
 *   func_02050DB8   0x02050DB8  arm
 *   func_020307B0   0x020307B0  arm
 *
 * Teardown of a sixteen-entry table of pointers: every non-null entry is
 * released through func_02050DB8, then the table pointer itself is handed to
 * func_020307B0 and cleared.  The global is re-read from its own slot before
 * every use, which is what the loop's `ldr r0, [r4]` at the top is; the two
 * pool words are the same address, so both `ldr r4, [pc, ...]` load one word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050ED4.c \
 *       --func func_02050ED4 --addr 0x02050ED4 --cc 1.1p1 --arm
 */

#include "../include/G_02146A88.h"

typedef unsigned int u32;

extern struct G_02146A88 *g_02146A88;
typedef unsigned char  u8;
extern void func_02050DB8(u8 *p);
extern u32 func_020307B0(void *p);

void func_02050ED4(void)
{
    int i;

    for (i = 0; i < 16; i++) {
        u32 v = ((u32 *)g_02146A88)[i];

        if (v != 0)
            func_02050DB8((u8 *)v);
    }
    func_020307B0((void *)((u32)((u32 *)g_02146A88)));
    g_02146A88 = 0;
}
