/*
 * function: SNDi_LockMutex
 * address:  0x02089880
 * packet:   pkt_02089880
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_LockMutex    0x02086028  arm
 *   s_data_02151454  0x02151454  data
 */

extern void OS_LockMutex(void *arg);
extern void *s_data_02151454;

void SNDi_LockMutex(void)
{
    OS_LockMutex(&s_data_02151454);
}
