/*
 * function: func_020307C8
 * address:  0x020307C8
 * packet:   pkt_020307C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_InitAllocator 0x02030238 arm
 *   func_02088234 0x02088234 arm
 */

typedef unsigned int u32;
typedef int s32;
extern u32 GFL_HEAP_InitAllocator(void *p, u32 heapId, s32 size);
extern void func_02088234(void);

void func_020307C8(void *p, u32 heapId, s32 size)
{
    if (GFL_HEAP_InitAllocator(p, heapId, size) == 0) {
        func_02088234();
    }
}
