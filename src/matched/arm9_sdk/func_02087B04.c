/*
 * function: OS_GetBootType
 * address:  0x02087B04
 * packet:   pkt_02087B04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087B14    0x02087B14  arm
*/

typedef unsigned short u16;

extern void *OS_GetBootInfo(void);

u16 OS_GetBootType(void)
{
    return *(u16 *)OS_GetBootInfo();
}
