/*
 * function: GFL_HEAP_FatalError
 * address:  0x020306A0
 * packet:   pkt_020306A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   OS_Terminate  0x02088234  arm
 */

extern void OS_Terminate(void);

void GFL_HEAP_FatalError(int n)
{
    switch (n) {
    case 0:
        break;
    case 1:
        OS_Terminate();
        break;
    case 2:
        OS_Terminate();
        break;
    case 3:
        OS_Terminate();
        break;
    case 4:
        OS_Terminate();
        break;
    case 5:
        OS_Terminate();
        break;
    }
}
