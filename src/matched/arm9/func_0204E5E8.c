/*
 * function: FADE_Create
 * address:  0x0204E5E8
 * packet:   pkt_0204E410
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * fade.c: allocate the 0x20-byte singleton on the caller's heap, publish it at
 * 0x02146A7C, clear it, then hand it to the fade initialiser.
 *
 * The heap id is the u16 parameter (the `lsl #16`/`lsr #16` pair at the top of
 * the function is the zero-extension of a `unsigned short` argument), and it
 * is forwarded to the allocator as its first argument, so the allocator takes
 * (heap, size, align, file, line) exactly as DOUBLE3DDISP_Init's does.  The
 * allocator's result stays in r0 across the store to the global, so the clear
 * call's first argument is that same value, not a fresh load of the global.
 *
 * symbols:
 *   func_02030734   0x02030734  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   FADE_ResetSpeed   0x0204E708  arm
 *   fade_File       0x020A7F8C  data
 *   g_02146A7C      0x02146A7C  data
 */

#include "../include/G_Run0204E720.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  MI_CpuFill8(void *dst, u32 val, u32 size);
extern void  FADE_ResetSpeed(void);
extern const char fade_File[];
extern struct Run0204E720 *g_02146A7C;

void FADE_Create(u32 heap)
{
    g_02146A7C = func_02030734((u16)heap, 0x20, 0, fade_File, 50);

    MI_CpuFill8(g_02146A7C, 0, 0x20);
    FADE_ResetSpeed();
}
