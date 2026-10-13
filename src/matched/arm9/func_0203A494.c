/*
 * function: GFL_NET_COMMAND_Init
 * address:  0x0203A494
 * packet:   pkt_0203A494
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _pCommandWork     0x021469D8  data
 *   g_020A7AE8     0x020A7AE8  data
 *   g_020A7AF8     0x020A7AF8  data
 *   func_02030734  0x02030734  arm
 *   func_0203A574  0x0203A574  arm
 *
 * Lazy-init wrapper: the 0x22c-byte context at _pCommandWork is allocated on
 * first use with the debug allocator (heap 0, size 0x22c, flags 1, line
 * 0x96), the delegate func_0203A574 is called, arg3 is published at +8 of
 * the state object in g_020A7AE8, and the 8-byte run at +0x220 plus the byte
 * at +0x228 are cleared.
 *
 * The clearing loop reloads _pCommandWork from memory on every iteration
 * (`ldr r1, [r0]` sits inside the back edge), which is what a global
 * POINTER read in a loop body compiles to when nothing in the loop proves it
 * cannot change -- writing `u8 *p = _pCommandWork;` first would hoist the load
 * and change three instructions.  The loop counter is initialised before the
 * `str r5, [r0, #8]` store (`mov r3, #0` at +0x60), and the byte index is
 * added to the reloaded pointer rather than to a running cursor.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_COMMAND_Init.c \
 *       --func GFL_NET_COMMAND_Init --addr 0x0203A494 --cc 1.1p1 --arm
 */

#include "../include/G_Entry.h"
#include "../include/G_BaseTable.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Entry *_pCommandWork;
extern struct BaseTable g_020A7AE8;
extern char  g_020A7AF8[];
typedef unsigned short u16;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_0203A574(u32 a0, u32 a1, u32 a2, u32 a3);

void GFL_NET_COMMAND_Init(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    int i;

    if (((u8 *)_pCommandWork) == 0) {
        _pCommandWork = (struct Entry *)((u8 *)func_02030734(0, 0x22c, 1, g_020A7AF8, 0x96));
    }
    func_0203A574(a0, a1, a2, a3);
    *(u32 *)(((u8 *)&g_020A7AE8) + 8) = a3;
    for (i = 0; i < 8; i++) {
        ((u8 *)_pCommandWork)[0x220 + i] = 0;
    }
    ((u8 *)_pCommandWork)[0x228] = 0;
}
