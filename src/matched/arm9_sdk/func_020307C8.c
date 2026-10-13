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
 *   func_02030238 0x02030238 arm
 *   func_02088234 0x02088234 arm
 */

typedef unsigned int u32;
typedef int s32;
extern u32 func_02030238(void *p, u32 heapId, s32 size);
extern void func_02088234(void);

void func_020307C8(void *p, u32 heapId, s32 size)
{
    if (func_02030238(p, heapId, size) == 0) {
        func_02088234();
    }
}
