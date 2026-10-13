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
 *   func_02085CBC 0x02085CBC arm
 */
typedef unsigned int   u32;
extern u32 func_02085CBC(void);

int OS_IsRunOnEmulator(void)
{
    return (func_02085CBC() & 0x10000000) ? 1 : 0;
}
