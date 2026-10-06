/*
 * function: OS_GetROMHeaderEULAVersion
 * address:  0x02087E40
 * packet:   pkt_02087E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 */

typedef unsigned char u8;
typedef volatile unsigned char vu8;

extern int OS_IsRunOnTwl(void);

u8 OS_GetROMHeaderEULAVersion(void)
{
    if (OS_IsRunOnTwl()) {
        return *(vu8 *)0x02FFE20E;
    }
    return 0;
}
