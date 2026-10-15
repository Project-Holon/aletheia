/*
 * function: GFL_HEAP_InitSystemHeapChecked
 * address:  0x02030BA4
 * packet:   pkt_02030BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02030534 0x02030534 arm
 *   OS_Terminate 0x02088234 arm
 */

typedef unsigned int u32;
extern signed int func_02030534(u32 size);
extern void OS_Terminate(void);

void GFL_HEAP_InitSystemHeapChecked(u32 size)
{
    if (func_02030534(size) == 0) {
        OS_Terminate();
    }
}
