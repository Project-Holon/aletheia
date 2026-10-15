/*
 * function: OS_IsRunOnEmulator
 * address:  0x02085D24
 * packet:   pkt_02085D24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_GetConsoleType 0x02085CBC arm
 */
typedef unsigned int   u32;
extern u32 OS_GetConsoleType(void);

int OS_IsRunOnEmulator(void)
{
    return (OS_GetConsoleType() & 0x10000000) ? 1 : 0;
}
